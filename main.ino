O#include "time.h"
#include "TimeLib.h"


#include "cardio.h"

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
 /* float x =analogRead(A0);
  String myx = String(x);

  unsigned long y= second();
  String myy=String(y);
//Serial.println(Actual_pulse());


Serial.print(String (myx + ";" + myy + "&"));*/
Serial.print(analogRead(A0));
}
