/*
#define pin1 2
#define pin2 6
#define pin3 7
#define pin4 8

#define MAX_AILERON 15
#define MAX_ELEVATOR 15
#define MAX_RUDDER 15
#define MAX_THROTTLE 100

#define MIN_AILERON -15
#define MIN_ELEVATOR -15
#define MIN_RUDDER -15

#define MAX_PWM1 2020
#define DEF_PWM1 1480
#define MIN_PWM1 1056

#define MAX_PWM2 1802
#define DEF_PWM2 1509
#define MIN_PWM2 1070

#define MAX_PWM3 1822
#define DEF_PWM3 1460
#define MIN_PWM3 1108

#define MAX_PWM4 2054
#define MIN_PWM4 1214

void controls_setup(){
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);

  calculate_PWM();
}

void calculate_PWM()
{
  MAX1 = (MAX_PWM1 - DEF_PWM1);
  MIN1 = (MIN_PWM1 - DEF_PWM1);

  MAX2 = (MAX_PWM2 - MIN_PWM2);
  MIN2 = (DEF_PWM2 - MIN_PWM2);
  
  MAX3 = (MAX_PWM3 - MIN_PWM3);
  MIN3 = (DEF_PWM3 - MIN_PWM3);

  MAX4 = (MAX_PWM4 - MIN_PWM4);  
}

double calculate_Degrees(int PWM, int MAXPWM, int MAXANGLE)
{
  return ((MAXANGLE * ((PWM * 100) / MAXPWM)) / 100);
}

double calculate_Throttle(int PWM, int MAXPWM)
{
  return ((PWM * 100) / MAXPWM);
}

void controls_loop(){

  valor_pwm1 = (pulseIn(pin1, HIGH)) - DEF_PWM1; 
  valor_pwm2 = (pulseIn(pin2, HIGH)) - DEF_PWM2;
  valor_pwm3 = (pulseIn(pin3, HIGH)) - DEF_PWM3;
  valor_pwm4 = (pulseIn(pin4, HIGH)) - MIN_PWM4;

  if (valor_pwm1 >= 0)
  {
    valor_graus1 = calculate_Degrees(valor_pwm1, MAX1, MAX_AILERON);
  }
  else
  {
    valor_graus1 = calculate_Degrees(valor_pwm1, MIN1, MIN_AILERON);
  }

  
  if (valor_pwm2 >= 0)
  {
    valor_graus2 = calculate_Degrees(valor_pwm2, MAX2, MAX_ELEVATOR);
  }
  else
  {
    valor_graus2 = calculate_Degrees(valor_pwm2, MIN2, MIN_ELEVATOR);
  }

  
  if (valor_pwm3 >= 0)
  {
    valor_graus3 = calculate_Degrees(valor_pwm3, MAX3, MAX_RUDDER);
  }
  else
  {
    valor_graus3 = calculate_Degrees(valor_pwm3, MIN3, MIN_RUDDER);
  }


  if (valor_pwm4 >= 0)
  {
    valor_graus4 = calculate_Throttle(valor_pwm4, MAX4);
  }
 
}
*/
