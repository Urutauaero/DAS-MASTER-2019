//GPS
uint32_t latuint, longuint;

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define fusoHorario 4

static const int RXPin = 5, TXPin = 4;
static const uint32_t GPSBaud = 9600  ;

uint16_t gpsHour, Hour;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void gps_setup()
{
  ss.begin(GPSBaud);
}

void gps_loop()
{
  if (ss.available() > 0)
  {
    if (gps.encode(ss.read()))
    {
      getInfo();
    }
  }

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
  }
}

void getInfo()
{
  if (gps.location.isValid())
  {
    latfloat = gps.location.lat();
    longfloat = gps.location.lng();
    altfloat = gps.altitude.meters();

    latint = (latfloat * 1000000);
    longint = (longfloat * 1000000);
    altint = (altfloat * 100);

    latuint = latint;
    latArray[0] = (latuint >> 24) & 0xFF;
    latArray[1] = (latuint >> 16) & 0xFF;
    latArray[2] = (latuint >> 8) & 0xFF;
    latArray[3] = latuint & 0xFF;
  
    longuint = longint;
    longArray[0] = (longuint >> 24) & 0xFF;
    longArray[1] = (longuint >> 16) & 0xFF;
    longArray[2] = (longuint >> 8) & 0xFF;
    longArray[3] = longuint & 0xFF;
  
    altArray[0] = (altint >> 8) & 0xFF;
    altArray[1] = altint  & 0xFF;
  }
  

  if (gps.date.isValid())
  {
    dia = gps.date.day();
    mes = gps.date.month();
    ano = gps.date.year();

    /*
    diaArray[0] = (dia >> 8) & 0xFF;
    diaArray[1] = dia & 0xFF;

    mesArray[0] = (mes >> 8) & 0xFF;
    mesArray[1] = mes & 0xFF;

    anoArray[0] = (ano >> 8) & 0xFF;
    anoArray[1] = ano & 0xFF;
    */
  }

  
  if (gps.time.isValid())
  {
    gpsHour = int(gps.time.hour());
    
    if ((gpsHour >= 0) && (gpsHour < 4))
      Hour = (gpsHour + 24);
    else
      Hour = gpsHour;
    
    hora = (Hour - fusoHorario);
    minuto = gps.time.minute();
    segundo = gps.time.second();

    tempo = (hora * 3600) + (minuto * 60) + segundo;

    tempoArray[0] = (tempo >> 24);
    tempoArray[1] = (tempo >> 16);
    tempoArray[2] = (tempo >> 8);
    tempoArray[3] = tempo;

    /*
    horasArray[0] = (hora >> 8) & 0xFF;
    horasArray[1] = hora & 0xFF;

    minutosArray[0] = (minuto >> 8) & 0xFF;
    minutosArray[1] = minuto & 0xFF;

    segundosArray[0] = (segundo >> 8) & 0xFF;
    segundosArray[1] = segundo & 0xFF;

    */
  }

  

}
