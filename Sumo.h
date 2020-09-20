#include <Arduino.h>

class Robot {
  
private:
  byte pinFloorSensor_BL,
       pinFloorSensor_BR,
       pinFloorSensor_FL,
       pinFloorSensor_FR,
       
       pinMotorLM,
       pinMotorLP,
       pinMotorRM,
       pinMotorRP,
       
       modeButton,
       modeLed1,
       modeLed2,
       modeLed3,
       powerLed;

  wchar_t pinFrontSensorL,
          pinFrontSensorR,
          pinSideSensorL,
          pinSideSensorR;
          
  bool setMode(){
    return !digitalRead(modeButton);
  }
  
public:
  byte Mode;

  Robot(){
    pinFloorSensor_BR = 3;
    pinFloorSensor_BL = 2;
    pinFloorSensor_FR = 5;
    pinFloorSensor_FL = 4;

    pinFrontSensorL = A0;
    pinFrontSensorR = A1;
    pinSideSensorL  = A2;
    pinSideSensorR  = A3;

    pinMotorLM = 9;
    pinMotorLP = 10;
    pinMotorRM = 6;
    pinMotorRP = 11;
    
    modeButton = A5;
    modeLed1 = 7;
    modeLed2 = 8;
    modeLed3 = 12;
    powerLed = A4;
    
    pinMode(pinFloorSensor_BR, INPUT);
    pinMode(pinFloorSensor_BL, INPUT);
    pinMode(pinFloorSensor_FR, INPUT);
    pinMode(pinFloorSensor_FL, INPUT);
    
    pinMode(pinFrontSensorL, INPUT);
    pinMode(pinFrontSensorR, INPUT);
    pinMode(pinSideSensorL, INPUT);
    pinMode(pinSideSensorR, INPUT);

    pinMode(pinMotorLM, OUTPUT);
    pinMode(pinMotorLP, OUTPUT);
    pinMode(pinMotorRM, OUTPUT);
    pinMode(pinMotorRP, OUTPUT);
    
    pinMode(modeButton, INPUT_PULLUP);
    pinMode(modeLed1, OUTPUT);
    pinMode(modeLed2, OUTPUT);
    pinMode(modeLed3, OUTPUT);
    pinMode(powerLed, OUTPUT);
    
    for(byte i = 1; i <= 3; i++){
      if(i >= 4) {
        i = 1;
        continue;
      }
      
      switch(i){
        case 1:
          digitalWrite(modeLed1, 1);
          digitalWrite(modeLed2, 0);
          digitalWrite(modeLed3, 0);
          break;
        
        case 2:
          digitalWrite(modeLed1, 0);
          digitalWrite(modeLed2, 1);
          digitalWrite(modeLed3, 0);
          break;
          
        case 3:
          digitalWrite(modeLed1, 0);
          digitalWrite(modeLed2, 0);
          digitalWrite(modeLed3, 1);
          break;
      }
      
      if(setMode()){
        Mode = i;
        digitalWrite(powerLed, 1);
        break;
      }
    }
  }

  void SetSpeed(short int _speed, char _motor){
    if(_motor == 'L'){
        if(_speed > 0){
            analogWrite(pinMotorLM, 0);
            analogWrite(pinMotorLP, _speed); 
        } else {
            analogWrite(pinMotorLM, -_speed);
            analogWrite(pinMotorLP, 0); 
        }
    } else {
        if(_speed < 0){
            analogWrite(pinMotorRM, 0);
            analogWrite(pinMotorRP, _speed);
        } else {
            analogWrite(pinMotorRM, -_speed);
            analogWrite(pinMotorRP, 0); 
        }
    }
    
  }

  wchar_t GetEnemyFrontL() {
    return analogRead(pinFrontSensorL);
  }

  wchar_t GetEnemyFrontR() {
    return analogRead(pinFrontSensorR);
  }

  bool GetEnemySideL(){
    return digitalRead(pinSideSensorR);
  }

  bool GetEnemySideR(){
    return digitalRead(pinSideSensorR);
  }

  bool GetFloorBL() {
    return digitalRead(pinFloorSensor_BL);
  }

  bool GetFloorBR() {
    return digitalRead(pinFloorSensor_BR);
  }

  bool GetFloorFL() {
    return digitalRead(pinFloorSensor_FL);
  }

  bool GetFloorFR() {
    return digitalRead(pinFloorSensor_FR);
  }

  void SensorDump(){
    Serial.println("Floor_BR: " + String(analogRead(pinFloorSensor_BR)) +
                " | Floor_BL: " + String(analogRead(pinFloorSensor_BL)) +
                " | Floor_FR: " + String(analogRead(pinFloorSensor_FR)) +
                " | Floor_FL: " + String(analogRead(pinFloorSensor_FL)) +
                " | FrontL: " + String(analogRead(pinFrontSensorL)) +
                " | FrontR: " + String(analogRead(pinFrontSensorR)) +
                " | SideL: " + String(analogRead(pinSideSensorL)) +
                " | SideR: " + String(analogRead(pinSideSensorR)));
  }

};
