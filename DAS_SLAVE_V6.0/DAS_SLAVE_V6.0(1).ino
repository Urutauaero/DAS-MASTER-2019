/*
    SISTEMA DE AQUISIÇÃO DE DADOS - DAS 2019 - SLAVE (MICROCONTROLADOR AUXILIAR)
    URUTAU AERODESIGN - MANAUS, 02/06/2019
    
    WALDISMAR DE OLIVEIRA SAMPAIO FILHO
    JACOBUS LAURENS DE JAGER
*/

/* Observações:
 *  1) O Código não desempenhará bem se não houver conexão entre o DAS e o receptor (18/09/2022)
 */
#define dasVersion "v3.0.0"
#define baudrate 115200

//#################################################################################
// VARIÁVEIS GLOBAIS
//#################################################################################

int      sonarPing;
uint8_t  wow;
uint16_t rps, rpm;

byte rpsArray[2];

byte diaArray[2], mesArray[2], anoArray[2];

byte horasArray[2], minutosArray[2], segundosArray[2], tempoArray[4];

byte latArray[4], longArray[4], altArray[2];

float latfloat, longfloat, altfloat;

uint16_t dia, mes, ano;
uint32_t hora, minuto, segundo;
uint32_t tempo;

int32_t latint;
int32_t longint;
int     altint;

int teste1 = 90, teste2 = 254;

double loop_temp_aux, print_temp_aux;

//###################################################################################


#define refresh_period 50 //milissegundos

void setup()
{
  Serial.begin(baudrate);
  Serial.println("DAS - Medusa");
  // Setups
  i2c_transmission_setup();
  controls_setup();
  gps_setup();
}

void loop()
{
  if (millis() - loop_temp_aux >= refresh_period)
  {
    loop_temp_aux = millis();
    wow_loop();
    rps_loop();
  }
  gps_loop();
  controls_loop();
  print_loop(); // Para debugging
}
