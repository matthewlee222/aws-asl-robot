#include <SPI.h>
#include <WiFiNINA.h>


#include "arduino_secrets.h" 

#include <Servo.h>

Servo thumb;
Servo index;
Servo middle;
Servo ring;
Servo pinky;

String x;


void setup() {
  
  // put your setup code here, to run once:
  thumb.attach(8); //servo 1
  index.attach(9); //servo 2
  middle.attach(10); //servo 3
  ring.attach(11); //servo 4
  pinky.attach(12); //servo 5

  Serial.begin(9600);      // initialize serial communication
  
}


void loop() {

  while (!Serial.available());
  x = Serial.readString();
  Serial.println(x);

        if (x == "A") {

          //Case A
          index.write(0);
          middle.write(0);
          ring.write(0);
          pinky.write(0);
          thumb.write(90);

        }

        if (x == "B") {

          //Case B
          pinky.write(160);
          index.write(160);
          middle.write(160);
          ring.write(160);
          thumb.write(180);

        }

        if (x == "C") {

          //Case C
          pinky.write(100);
          index.write(100);
          middle.write(100);
          ring.write(100);
          thumb.write(90);

          //Wrist rotation
          
        }

        if (x == "D") {

          //Case D
          pinky.write(60);
          index.write(160);
          middle.write(60);
          ring.write(60);
          thumb.write(180);

          //Wrist rotation
          
        }

        if (x == "E") {

          //Case E
          pinky.write(20);
          index.write(20);
          middle.write(20);
          ring.write(20);
          thumb.write(180);
          
        }

        if (x == "F") {

          //Case F
          pinky.write(160);
          index.write(0);
          middle.write(160);
          ring.write(160);
          thumb.write(180);
          
        }

        if (x == "G") {

          //Case G
          index.write(160);
          middle.write(0);
          ring.write(0);
          pinky.write(0);
          thumb.write(90);
          
        }

        if (x == "H") {

          //Case H
          index.write(160);
          middle.write(160);
          ring.write(0);
          pinky.write(0);
          thumb.write(90);

        }

        if (x == "I") {

          //Case I
          pinky.write(160);
          index.write(0);
          middle.write(0);
          ring.write(0);
          thumb.write(180);

        }

        if (x == "J") {

          //Case J
          pinky.write(160);
          index.write(0);
          middle.write(0);
          ring.write(0);
          thumb.write(180);

          //rotation
        }

        if (x == "K") {

          //Case K
          index.write(160);
          middle.write(160);
          ring.write(0);
          pinky.write(0);
          thumb.write(160);
          
        }

        if (x == "L") {
          //Case L
          pinky.write(0);
          index.write(170);
          middle.write(0);
          ring.write(0);
          thumb.write(0);
          
        }

        if (x == "M") {

          //Case M
          thumb.write(180);
          pinky.write(10);
          index.write(30);
          middle.write(30);
          ring.write(30);
          
        }

        if (x == "N") {
          
          //Case N
          thumb.write(160);
          pinky.write(0);
          index.write(10);
          middle.write(10);
          ring.write(0);
          
        }

        if (x == "O") {

          //Case O
          pinky.write(60);
          index.write(60);
          middle.write(60);
          ring.write(60);
          thumb.write(180);

          //Wrist rotation
          
        }

        if (x == "P") {
          
          //Case P
          index.write(160);
          middle.write(120);
          ring.write(0);
          pinky.write(0);
          thumb.write(90);

          
        }

        if (x == "Q") {

          //Case Q
          index.write(140);
          middle.write(0);
          ring.write(0);
          pinky.write(0);
          thumb.write(90);

        }

        if (x == "R") {
          //Case R
          pinky.write(0);
          index.write(160);
          middle.write(180);
          ring.write(0);
          thumb.write(180);
          
        }

        if (x == "S") {

          //Case S
          pinky.write(0);
          index.write(0);
          middle.write(0);
          ring.write(0);
          thumb.write(180);
          
        }

        if (x == "T") {

          //Case T
          thumb.write(140);
          pinky.write(0);
          index.write(10);
          middle.write(0);
          ring.write(0);
         
        }

        if (x == "U") {

          //Case U
          pinky.write(0);
          index.write(180);
          middle.write(180);
          ring.write(0);
          thumb.write(180);
          
        }

        if (x == "V") {

          //Case V
          pinky.write(0);
          index.write(180);
          middle.write(130);
          ring.write(0);
          thumb.write(180);
          
        }

        if (x == "W") {

          //Case W
          pinky.write(0);
          index.write(160);
          middle.write(160);
          ring.write(160);
          thumb.write(180);

        }

        if (x == "X") {

          //Case X
          pinky.write(60);
          index.write(120);
          middle.write(60);
          ring.write(60);
          thumb.write(160);
          
        }

        if (x == "Y") {

          //Case Y
          index.write(0);
          middle.write(0);
          ring.write(0);
          pinky.write(160);
          thumb.write(0);
          
        }

        if (x == "Z") {

          //Case S
          pinky.write(0);
          index.write(160);
          middle.write(0);
          ring.write(0);
          thumb.write(180);

          //wrist rotation? 
        }

        
      }

