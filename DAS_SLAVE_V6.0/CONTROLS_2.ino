// Estes são os pinos digitais para leitura PWM. Apesar de haver a descrição de qual superfície deve ser concetada
// em cada pino da placa DAS 2022, podem ocorrer alterações. Logo, converse com o piloto para saber quais canais
// do receptor secundário (sinal replicado em outro receptor) serão utilizados e quais superfícies serão conectadas
// a eles. Por exemplo: 
// > Canal 1: Profundor
// > Canal 2: Aileron
// > Canal 3: Leme
// > Canal 4: Flap
// A saída PWM destes canais serão conectadas nos pinos abaixo:
#define pin1 2   //   (Pino PD2 - Silk: Aileron 1) - Canal 3 (Leme)
#define pin2 6   //   (Pino PD6 - Silk: Profundor) - Canal 2 (Profundor)
#define pin3 7   //   (Pino PD7 - Silk: Leme)      - Canal 1 (Aileron 1)
#define pin4 8   //   (Pino PB0 - Silk: Flap)      - Canal 4 (Aileron 2)

// DEFLEXÕES MÁXIMAS //
// Estes valores de deflexão das superfícies de comando são definidos pela área de estabilidade e controle:
#define MAX_AILERON   25
#define MAX_ELEVATOR  25
#define MAX_RUDDER    30
// A deflexão do Flap é definida por aerodinamica 
#define MAX_FLAP      30

// As superfícies de controle podem ser defletidas simetrica ou assimentricamente, como os exêmplos:
  // Elevator (Profundor): +25º / -25º (simétrico)
  // Aileron:              +25º / -15º (assimétrico)
  // Leme (Rudder):        +30º / -30º (simétrico)
  // Flap:                 +30º /   0º (somente para baixo)
  // Observação: Positivo para baixo e Negativo para cima

// Pode ocorrer do leme ser dimensionado para não defletir simetricamente, logo criou-se essas variáveis para o caso
// de não haver deflexão simetrica em alguma das superfícies de comando.
//#define ZERO_AILERON   15
//#define ZERO_ELEVATOR  0
//#define ZERO_RUDDER    0
//#define ZERO_FLAP      0

// PWMs MÁXIMOS OBTIDOS PELA SAÍDA DO RECEPTOR //
// Antes do voo, o piloto irá definir os valores dos sinais PWM que sairão dos receptores presentes na aeronave
// e enviarão os sinais aos servos. Durante este prossedimento, ele irá verificar qual valor de PWM resultará em
// uma deflexão de superficies visualmente. Após esta definição, verifique quais serão os valores PWM com:
// > Mache em posição nula
// > Manche na posição que gera o PWM máximo

// Aileron
#define MAX_PWM1  1942.00
#define ZERO_PWM1 1380.00
// Profundor
#define MAX_PWM2  2076.00
#define ZERO_PWM2 1556.00
// Leme
#define MAX_PWM3  2148.00
#define ZERO_PWM3 1506.00
// Flap
#define MAX_PWM4  2096.00
#define ZERO_PWM4 1471.00

// Declaração de variáveis de calculo
int MAX1,     MAX2,     MAX3,     MAX4;
int DEF1 = 0, DEF2 = 0, DEF3 = 0, DEF4 = 0;
int MIN1,     MIN2,     MIN3,     MIN4;

int    valor_pwm1,   valor_pwm2,   valor_pwm3,   valor_pwm4;
int8_t valor_graus1, valor_graus2, valor_graus3, valor_graus4;
float  DEG_MAX1,     DEG_MAX2,     DEG_MAX3,     DEG_MAX4;
float  CONV1,        CONV2,        CONV3,        CONV4;

void controls_setup(){
  Serial.begin (115200);
  // CONFIGURAÇÃO COMUNICAÇÃO I2C
  i2c_transmission_setup();
  // CONFIGURAÇÃO PINOS PARA ENTRADA
  pinMode (pin1,INPUT);
  pinMode (pin2,INPUT);
  pinMode (pin3,INPUT);
  pinMode (pin4,INPUT);
  // CALCULO PWM //
  MAX1 = (MAX_PWM1 - ZERO_PWM1);
  CONV1 = MAX1/MAX_ELEVATOR;
  MAX2 = (MAX_PWM2 - ZERO_PWM2);
  CONV2 = MAX2/MAX_RUDDER;
  MAX3 = (MAX_PWM3 - ZERO_PWM3);
  CONV3 = MAX3/MAX_AILERON;
  MAX4 = (MAX_PWM4 - ZERO_PWM4);
  CONV4 = MAX4/MAX_FLAP;
  // PRINT
//  Serial.print ("CANAL 1  ");  Serial.print ("CANAL 2  ");  Serial.print ("CANAL 3  "); 

}

void controls_loop(){
  valor_pwm1 = (pulseIn(pin1, HIGH));
  valor_pwm2 = (pulseIn(pin2, HIGH));
  valor_pwm3 = (pulseIn(pin3, HIGH));
  valor_pwm4 = (pulseIn(pin4, HIGH)); 
  // Aileron
  if (valor_pwm1 <= 0) 
  {
    valor_graus1 = 0;
  }
  else
  {
    valor_graus1 = (valor_pwm1-ZERO_PWM1)/CONV1;
  }
  
  // Profundor
  if (valor_pwm2 <= 0) 
  {
    valor_graus2 = 0;
  }
  else
  {
    valor_graus2 = (valor_pwm2-ZERO_PWM2)/CONV2;
  }
//
   // Leme
  if (valor_pwm3 <= 0) 
  {
    valor_graus3 = 0;
  }
  else
  {
    valor_graus3 = (valor_pwm3-ZERO_PWM3)/CONV3;
  }

  // Flap
  if (valor_pwm4 <= 0) 
  {
    valor_graus4 = 0;
  }
  else
  {
    valor_graus4 = (valor_pwm4-ZERO_PWM4)/CONV4;
  }
//  Serial.print   ("   ");        Serial.print (valor_pwm1);  Serial.print ("       ");
//  Serial.print   (valor_graus1); Serial.print ("        "); 
//  Serial.print   (valor_pwm2);   Serial.print ("        "); 
//  Serial.print   (valor_graus2); Serial.println ("        ");  
//  Serial.print   (valor_pwm3);   Serial.print ("        "); 
//  Serial.print   (valor_graus3); Serial.print ("        ");
//  Serial.print   (valor_pwm4);   Serial.print ("        ");
//  Serial.println (valor_graus4);
  
}
