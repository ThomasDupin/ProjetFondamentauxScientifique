#include "coeur.h"
#include <Arduino.h>
unsigned long Temp;
int BPM(){
  Temp = millis();
  int Potar = analogRead(A0);
  int Poul;
  Poul= map(Potar, 0, 1023, 273, 1200);
  long BPM = map(Poul, 273, 1200, 220, 50);
  String X = String(BPM);
  String T = String(Temp);
  Serial.print(String(X+";"+T+"$\n"));
  return Poul;
}
void ledAllumeRythmeBattementsCoeur(){
  int Poul = BPM();
    for (int j=2; j<=13 ; j++){
      digitalWrite(j, HIGH);
    }
    delay (Poul);
    for (int j=2; j<=13; j++){
      digitalWrite(j, LOW);
    }
    delay(Poul);
}

void uneLedSurXallume(int x){
  long Poul = BPM();
    for (int j=2; j<=13; j+=x ){
      digitalWrite(j, HIGH);
      delay(Poul);
      digitalWrite(j, LOW);
      delay(Poul);
    }
}

void ledChenille(){
  long Poul = BPM();
    for (int j=2; j<=13 ; j++){
      digitalWrite(j, HIGH);
      delay(Poul);
      digitalWrite(j, LOW);
      delay(Poul);
    }
}
void ledChenille2(){
  long Poul = BPM();
    for (int j=2; j<=13 ; j++){
      digitalWrite(j, HIGH);
      if((j+1 && j+2) < 14){
        digitalWrite(j+1, HIGH);
        digitalWrite(j+2, HIGH);
      }
      delay(Poul);
      digitalWrite(j, LOW);
      if((j+1 && j+2) < 14){
        digitalWrite(j+1, LOW);
        digitalWrite(j+2, LOW);
      }
      delay(Poul);
    }
}
