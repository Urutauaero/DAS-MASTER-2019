// Versão oficial de 2019 do DAS - Não o modifique!!!! se for testar faça em cópia
/*
    SISTEMA DE AQUISIÇÃO DE DADOS - DAS 2019 - MASTER
    URUTAU AERODESIGN - MANAUS, 02/06/2019
    
    WALDISMAR DE OLIVEIRA SAMPAIO FILHO
    JACOBUS LAURENS DE JAGER
*/

#define dasVersion "v3.0.0"
#define versionName "Versão alpha"

#define DEBUG

#pragma GCC optimize ("-Ofast")
#include <Wire.h>

#define baudrate 115200

void MotionSystem_setup();
void heading_setup();
void hp_setup();
void telemetria_setup();
void vcas_setup();

float xv, yv, zv;
float heading;
float headingDegrees;

void get_data();
void serial_write();
void SD_write();

// ###########################################################################
// VARIÁVEIS GLOBAIS #########################################################
// ###########################################################################

String GyroX, GyroY, GyroZ;
String AccelX, AccelY, AccelZ;

String data_string, IDV_string;

int16_t gpsDay = 0, gpsMonth = 0, gpsYear = 0;
int16_t gpsHour = 0, gpsMinute = 0, gpsSecond = 0;

byte data_string_serial[45];

int rps;
int altint;
int wow, rpm, control_1, control_2, control_3, control_4;
int sonarDistance;
int teste1, teste2;

float hp, pbmp, vcas, PVcas;
float longfloat, latfloat, altfloat;
float maghead;
float gForceX, gForceY, gForceZ;
float gyroXrate, gyroYrate, gyroZrate;

long magheadint;
long gyroXrateint;
long gyroYrateint;
double gForceXint;
double gForceYint;
double gForceZint;

uint32_t latuint, longuint;

uint16_t servo1uint, servo2uint, servo3uint, servo4uint;

uint32_t tempo;
double temp;

int i = 0, j = 0;

//RTC ###################################################################################

#include <DS3231.h>


DS3231 rtc();
Time t;
//time DateTime;

unsigned long h, m, s;
unsigned long cs;

unsigned long saux, aux, tempaux;
bool primeiro_ciclo = true;

void temporizador_rtc()
{
  if (primeiro_ciclo == true)
  {
    primeiro_ciclo = false;
    tempaux = millis() + 1000;

    while (aux < tempaux)
    {
      t = rtc.getTime();
      s = t.sec;

      if(s == saux)
      {
        if (millis() - aux >= 100 && cs < 9)
        {
          cs = cs + 1;
          aux = millis();
        }
      }
      else
      {
        cs = 0;
        aux = millis();
      }
      saux = t.sec;
    }
  }
}
//###########################################################################################3


void setup(){
  Serial.begin(baudrate);
  Wire.begin();

  Serial.println("\n\nBEGIN: rtc.begin --------------\n");
  rtc.begin();

  Serial.println("\n\nCALLING: MotionSystem_setup --------------\n");
  MotionSystem_setup();

  Serial.println("\n\nCALLING: heading_setup --------------\n");
  heading_setup();

  Serial.println("\n\nCALLING: hp_setup --------------\n");
  hp_setup();

  Serial.println("\n\nCALLING: vcas_setup --------------\n");
  vcas_setup();
  
  Serial.println("\n\nCALLING: telemetria_setup --------------\n");
  telemetria_setup();
  temporizador_rtc();  
}

void loop(){
  
  t = rtc.getTime();
  s = t.sec;

  if (s == saux)
  {
    if(millis() - aux >= 100 && cs < 9)
    {
      cs++;
      aux = millis();

      get_data();
      serial_write();
      SD_write();
    }
  }
  else
  {
    cs = 0; 
    aux = millis();

    get_data();
    serial_write();
    SD_write();
  }

  saux = t.sec;
}
