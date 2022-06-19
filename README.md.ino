#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial BTS(4,3); // RX | TX
Servo servo1; //creating an object for the servo library

void setup() {
  BTS.begin(9600);
  Serial.begin(9600);
  servo1.attach(6);//attaching servo to pin 6

}
void loop(){
  //Checking if character is avaliavle in the Bluetooth port
    if(BTS.available()>0){
      //checking if we are getting the slider tag 'S'
      if(BTS.read()=='c'){
      //extracting the position from the message  
      int pos=BTS.parseInt(SKIP_ALL); //SKIP_ALL: all characters other than digits or a minus sign are ignored when scanning the stream for an integer.
      Serial.println(180);//printing the position for debuging
      servo1.write(180); //commanding the servo to the particular position
      }
    if(BTS.read()=='o'){
      //extracting the position from the message  
      int pos=BTS.parseInt(SKIP_ALL); //SKIP_ALL: all characters other than digits or a minus sign are ignored when scanning the stream for an integer.
      Serial.println(90);//printing the position for debuging
      servo1.write(90); //commanding the servo to the particular position
      }}  
}
   
