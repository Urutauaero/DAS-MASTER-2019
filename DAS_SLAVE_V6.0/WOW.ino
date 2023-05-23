//WOW

#include <NewPing.h>

#define TRIGGER_PIN 6 //9
#define ECHO_PIN 5    //10

#define WOW_HEIGHT 1  //20

NewPing sonar(TRIGGER_PIN, ECHO_PIN);

unsigned int pingSpeed = 50;
unsigned int pingTimer = 0;

void echoCheck()
{
  if (sonar.check_timer())
  {
    sonarPing = (sonar.ping_result / US_ROUNDTRIP_CM);
    
    if (sonarPing > WOW_HEIGHT)
    {
      wow = 1; // O peso NÃO ESTÁ nas rodas - Em voo
    }
    else
    {
      wow = 0; // O peso ESTÁ nas rodas - Em solo
    }
  }
}

void wow_loop()
{  
  if (millis() >= pingTimer)
  {
    pingTimer += pingSpeed;
    sonar.ping_timer(echoCheck);
  }
}
