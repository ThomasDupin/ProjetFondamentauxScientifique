#include "Cardio.h"
#include "Arduino.h"


int Actual_pulse()
{
  int previousValue = 0;
  long previousTime = 0;
  int ActualValue, Treshold;
  long DetectionTime;

  ActualValue = analogRead(0);
  Treshold = 100;

  if (ActualValue > Treshold)
  {
    if (previousValue <= Treshold)
    {
      DetectionTime = millis();
      if (DetectionTime > (previousValue + 200))
      {
      /*Serial.println( (1000.0 * 60.0) / (DetectionTime- previousTime),0);
        previousTime = previousValue;*/
      }
    }
  }

  previousValue = ActualValue;
}
