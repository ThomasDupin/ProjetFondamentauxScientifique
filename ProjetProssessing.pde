//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;
int i = 0;
void setup() {
  udSerial = new Serial(this, Serial.list()[0], 9600);
  output = createWriter ("Battements.csv");
}

  void draw() {
    if (udSerial.available() > 0) {
      String SenVal = udSerial.readStringUntil('$');
      if (SenVal != null) {
        output.println(SenVal);
        i++;
        if ( i >15){
          output.flush();
          output.close();
           exit(); 
          
      }
    }
  }
  } 

  void keyPressed(){
    output.flush();
    output.close();
    exit(); 
  }
