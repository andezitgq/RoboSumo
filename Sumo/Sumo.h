#include <Arduino.h>
#include <NewPing.h>

#define FS_MIN 10
#define FS_MAX 400

NewPing pinFrontSensorL(7, 7, FS_MAX);
NewPing pinFrontSensorR(A1, A1, FS_MAX);
NewPing pinSideSensorL(A2, A2, FS_MAX);
NewPing pinSideSensorR(A3, A3, FS_MAX);

class Robot {
  
private:
  byte pinFloorSensor_BL,
       pinFloorSensor_BR,
       pinFloorSensor_FL,
       pinFloorSensor_FR,
       
       pinMotorLM,
       pinMotorLP,
       pinMotorRM,
       pinMotorRP;
  
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
    }
    
    if(_motor == 'R') {
        if(_speed > 0){
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
    Serial.print("Floor_BR: " + String(digitalRead(pinFloorSensor_BR)) +
                " | Floor_BL: " + String(digitalRead(pinFloorSensor_BL)) +
                " | Floor_FR: " + String(digitalRead(pinFloorSensor_FR)) +
                " | Floor_FL: " + String(digitalRead(pinFloorSensor_FL)) +
                " | FrontL: " + String(pinFrontSensorL.ping_cm()));
    delay(500);
    Serial.println(
                " | FrontR: " + String(pinFrontSensorR.ping_cm()) +
                " | SideL: " + String(pinSideSensorL.ping_cm()) +
                " | SideR: " + String(pinSideSensorR.ping_cm()));
  }

};
