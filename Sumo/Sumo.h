#include <Arduino.h>
#include <NewPing.h>

NewPing pinFrontSensorL(A0, A0, 400);
NewPing pinFrontSensorR(A1, A1, 400);
NewPing pinSideSensorL(A2, A2, 400);
NewPing pinSideSensorR(A3, A3, 400);

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
  
public:
  byte Mode;

  Robot(){
    pinFloorSensor_BR = 3;
    pinFloorSensor_BL = 2;
    pinFloorSensor_FR = 5;
    pinFloorSensor_FL = 4;

    pinMotorLM = 9;
    pinMotorLP = 10;
    pinMotorRM = 6;
    pinMotorRP = 11;
    
    pinMode(pinFloorSensor_BR, INPUT);
    pinMode(pinFloorSensor_BL, INPUT);
    pinMode(pinFloorSensor_FR, INPUT);
    pinMode(pinFloorSensor_FL, INPUT);

    pinMode(pinMotorLM, OUTPUT);
    pinMode(pinMotorLP, OUTPUT);
    pinMode(pinMotorRM, OUTPUT);
    pinMode(pinMotorRP, OUTPUT);
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
    return pinFrontSensorL.ping_cm();
  }

  wchar_t GetEnemyFrontR() {
    return pinFrontSensorR.ping_cm();
  }

  wchar_t GetEnemySideL(){
    return pinSideSensorR.ping_cm();
  }

  wchar_t GetEnemySideR(){
    return pinSideSensorR.ping_cm();
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
                " | FrontL: " + String(pinFrontSensorL.ping_cm()) +
                " | FrontR: " + String(pinFrontSensorR.ping_cm()) +
                " | SideL: " + String(pinSideSensorL.ping_cm()) +
                " | SideR: " + String(pinSideSensorR.ping_cm()));
  }

};
