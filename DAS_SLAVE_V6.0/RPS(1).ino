// RPS

// CORREÇÕES CRÍTICAS PRECISAM SER FEITAS !!!!!!

uint16_t counter = 0;
uint32_t last_millis = 0;

#define interrupt_in 3
#define magnets 2
#define period 1000

// RPS Interruption Routine

void rps_ISR()
{
  counter++;
}

//RPS loop executed in main loop

void rps_loop()
{  
  if (millis() - last_millis >= period)
  {
    detachInterrupt(digitalPinToInterrupt(interrupt_in));
    rps = counter / magnets;
    rpm = rps * 60;
    
    rpsArray[0] = rps >> 8;
    rpsArray[1] = rps;

    counter = 0;
    last_millis = millis();
    attachInterrupt(digitalPinToInterrupt(interrupt_in), rps_ISR, FALLING);
  }
}
