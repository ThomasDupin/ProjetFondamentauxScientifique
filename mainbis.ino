#include "param.h"
#include "coeur.h"


int x;
void setup() {
 Serial.begin(9600);
 for (int i =2; i<=13; i++){
     pinMode(i,OUTPUT);
 }
}

void loop() {
       switch(mode){
        case 1:
          ledAllumeRythmeBattementsCoeur();
          break;
        case 2:
          x = 3;
          uneLedSurXallume(x);
          break;
        case 3:
          ledChenille();
          break;
        case 4:
          ledChenille2();
          break;
  }
}
/*
 UserChoice(){
  do{
    long Poul=BPM();
    int t = random(0,10);
    digitalWrite(Led[i],i);
    delay(Poul);
    digitalWrite(Led[i],0);
  }while(1);
}
*/

  
