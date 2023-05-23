/*
    SISTEMA DE AQUISIÇÃO DE DADOS - DAS 2019 - SLAVE (MICROCONTROLADOR AUXILIAR)
    URUTAU AERODESIGN - MANAUS, 02/06/2019
    
    WALDISMAR DE OLIVEIRA SAMPAIO FILHO
    JACOBUS LAURENS DE JAGER
*/

#define dasVersion "v3.0.0"
#define baudrate 115200


//#################################################################################
// VARIÁVEIS GLOBAIS
//#################################################################################

int sonarPing;
uint8_t wow;
uint16_t rps, rpm;

int8_t valor_pwm1, valor_graus1;
int8_t valor_pwm2, valor_graus2;
int8_t valor_pwm3, valor_graus3;
int8_t valor_pwm4, valor_graus4;

int MAX1, MAX2, MAX3, MAX4;
int DEF1 = 0, DEF2 = 0, DEF3 = 0, DEF4 = 0;
int MIN1, MIN2, MIN3, MIN4;

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
int altint;

int teste1 = 90, teste2 = 254;

double loop_temp_aux, print_temp_aux;

//###################################################################################


#define refresh_period 50 //milissegundos

void setup()
{
  pinMode(7, OUTPUT);  //estabelecendo fonte e gnd 
  pinMode(4, OUTPUT);

  digitalWrite(7, 1);
  digitalWrite(4, 0);
  Serial.begin(baudrate);
  Serial.println("DAS - Medusa");

  i2c_transmission_setup();

  //controls_setup();
  //gps_setup(); mod minha
}

void loop()
{
  if (millis() - loop_temp_aux >= refresh_period)
  {
   // loop_temp_aux = millis();
    wow_loop();
   /// rps_loop();  modificações minha
  }
  //gps_loop(); mod minha
  //controls_loop();
  print_loop(); // Apenas para debugging
}
