#include <Wire.h>
#include "Adafruit_VL6180X.h"


// LIDAR ToF Sensor
Adafruit_VL6180X lidar = Adafruit_VL6180X();

const int ChA = 16;
const int ChB = 12;
int ChAState = 0;
int ChBState = 0;
int prev_ChA = 0;
int prev_ChB = 0;
long dist = 0; // send an integer incrementing distance value. Set millimetres in laptop code. 

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);

  while (!Serial) {
    delay(1);
  }
  Serial.println("Rotary Encoder");
  Serial.println("Searching for Sensor");
  if (! lidar.begin()) {
    Serial.println("Failed to find sensor");
    while (1);
  }
  Serial.println("Sensor found.");

  pinMode(ChA, INPUT);
  pinMode(ChB, INPUT);
}

void handleSerial() {
    while (Serial.available()>0){
      char rst = Serial.read();
      if (rst == 'R'){
        Serial.println("Resetting Distance");
        dist = 0;
      }
    }
}

void loop() {
    handleSerial();
  
    ChAState = digitalRead(ChA);
    uint8_t range = 0;
  // put your main code here, to run repeatedly:
    if (ChAState!=prev_ChA) {
      
      if (digitalRead(ChB)!=ChAState){
        // Forward
        dist++;
        }
        else{
        // Backwards
        dist--;     
        }
        range = lidar.readRange();
        uint8_t status = lidar.readRangeStatus();
      
    
        if (status == VL6180X_ERROR_NONE){
          Serial.print(dist);
          Serial.print(",");
          Serial.println(range);
        }

    
    }
  //  delayMicroseconds(1); 
    prev_ChA = digitalRead(ChA);
    prev_ChB = digitalRead(ChB);

}
