#include <Arduino.h>
#include <NewPing.h>

#define FS_MIN 50
#define FS_MAX 400

NewPing pinFrontSensorL(7, 7, FS_MAX);
NewPing pinFrontSensorR(A1, A1, FS_MAX);
NewPing pinSideSensorL(5, 5, FS_MAX);
NewPing pinSideSensorR(2, 2, FS_MAX);

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
  Robot(){
    pinFloorSensor_BR = A3;
    pinFloorSensor_BL = A4;
    pinFloorSensor_FR = A2;
    pinFloorSensor_FL = A5;

    pinMotorLM = 11;
    pinMotorLP = 6;
    pinMotorRM = 10;
    pinMotorRP = 9;
    
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

  wchar_t GetFloorBL() {
    return analogRead(pinFloorSensor_BL);
  }

  wchar_t GetFloorBR() {
    return analogRead(pinFloorSensor_BR);
  }

  wchar_t GetFloorFL() {
    return analogRead(pinFloorSensor_FL);
  }

  wchar_t GetFloorFR() {
    return analogRead(pinFloorSensor_FR);
  }

  void SensorDump(){
    Serial.print("Floor_BR: " + String(analogRead(pinFloorSensor_BR)) +
                " | Floor_BL: " + String(analogRead(pinFloorSensor_BL)) +
                " | Floor_FR: " + String(analogRead(pinFloorSensor_FR)) +
                " | Floor_FL: " + String(analogRead(pinFloorSensor_FL)) +
                " | FrontL: " + String(pinFrontSensorL.ping_cm()));
    delay(150);
    Serial.print(" | FrontR: " + String(pinFrontSensorR.ping_cm()));
    delay(150);
    Serial.print(" | SideL: " + String(pinSideSensorL.ping_cm()));
    delay(150);
    Serial.println(" | SideR: " + String(pinSideSensorR.ping_cm()));
    delay(150);
  }

};
