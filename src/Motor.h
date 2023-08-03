/*
  Motor.h - Library for working with the Cytron SPG30E-30K.
  Created by Vinay Lanka, January 27, 2021.
*/
#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor {
  public:
    //Constructor - Pin1 and Pin2 are the Motor output / en_a and en_b are the encoder inputs
    Motor(int Pin1, int Pin2, int pwmPin, int en_a, int en_b);
    //Spin the motor with a percentage value
    void rotate(int value);
    //Motor Outputs - Pin1 is one direction and Pin2 is the other
    int Pin1;
    int Pin2;
    int pwmPin;
    //Encoder Inputs
    int en_a;
    int en_b;
};

Motor::Motor(int Pin1, int Pin2, int pwmPin, int en_a, int en_b) {
  pinMode(Pin1,OUTPUT);
  pinMode(Pin2,OUTPUT);
  pinMode(pwmPin,OUTPUT);
  pinMode(en_a,INPUT_PULLDOWN);
  pinMode(en_b,INPUT_PULLDOWN);
  Motor::Pin1 = Pin1;
  Motor::Pin2 = Pin2;
  Motor::pwmPin = pwmPin;
  Motor::en_a = en_a;
  Motor::en_b = en_b;
}

void Motor::rotate(int value) {
  if(value>0){
    //Max Voltage with 16V battery with 12V required
    //(12/16)*255 ~=190
//    Serial.println("called");
//    Serial.println(Pin1);
    int out = map(value, 0, 100, 0, 255);
    digitalWrite(Pin1,HIGH);
    digitalWrite(Pin2,LOW);
    analogWrite(pwmPin,out);

  }else if (value<0)
  {
    //Max Voltage with 16V battery with 12V required
    //(12/16)*255 ~=190
    int out = map(value, 0, -100, 0, 255);
    // analogWrite(Pin1,0);
    // analogWrite(Pin2,out);
    digitalWrite(Pin1,LOW);
    digitalWrite(Pin2,HIGH);
    analogWrite(pwmPin,out);
  }else //brake
  {
    digitalWrite(Pin1,LOW);
    digitalWrite(Pin2,LOW);
    analogWrite(pwmPin,0);    
  }
}
#endif