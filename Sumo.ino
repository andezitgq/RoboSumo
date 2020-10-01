#include "Sumo.h"

Robot rb;
wchar_t MIN_BL,
        MIN_BR,
        MIN_FL,
        MIN_FR;

wchar_t MAX_BL,
        MAX_BR,
        MAX_FL,
        MAX_FR;

bool GoFloor(){
  if(rb.GetFloorBL() <= MAX_BL - 150){
    rb.SetSpeed(100, 'L');
    rb.SetSpeed(0, 'R');
    return true;
  }
  
  if(rb.GetFloorBR() <= MAX_BR - 250){
    rb.SetSpeed(100, 'R');
    rb.SetSpeed(0, 'L');
    return true;
  }
  
  if(rb.GetFloorFL() <= MAX_FL - 200){
    rb.SetSpeed(-100, 'L');
    rb.SetSpeed(0, 'R');
    return true;
  }
  
  if(rb.GetFloorFR() <= MAX_FR - 200){
    rb.SetSpeed(-100, 'R');
    rb.SetSpeed(0, 'L');
    return true;
  }
  
  return false;
}

/*bool GoSide(){
  if(rb.GetEnemySideL() <= FS_MIN && rb.GetEnemySideR() > 0){
    rb.SetSpeed(100, 'L');
    rb.SetSpeed(0, 'R');
    return true;
  }

  if(rb.GetEnemySideR() <= FS_MIN && rb.GetEnemySideR() > 0){
    rb.SetSpeed(0, 'L');
    rb.SetSpeed(100, 'R');
    return true;
  }
  
  return false;
}
*/
void setup() {
  Serial.begin(9600);
  MAX_BL = rb.GetFloorBL();
  MAX_BR = rb.GetFloorBR();
  MAX_FL = rb.GetFloorFL();
  MAX_FR = rb.GetFloorFR();
  //delay(5000);
}

void loop() {
  rb.SensorDump();
      /*if((rb.GetEnemyFrontL() <= FS_MIN && rb.GetEnemyFrontL() > 0) || (rb.GetEnemyFrontR() <= FS_MIN && rb.GetEnemyFrontR() > 0)){
        if(rb.GetEnemyFrontL() != rb.GetEnemyFrontR()){
          
          if(!GoFloor()){
            if(!GoSide()){
              signed short int _acc = rb.GetEnemyFrontL() - rb.GetEnemyFrontR();
              rb.SetSpeed(-_acc, 'L');
              rb.SetSpeed(_acc, 'R');
            }
          }
            
        } else {
          
          if(!GoFloor()){
            if(!GoSide()){
              rb.SetSpeed(100, 'R');
              rb.SetSpeed(100, 'L');
            }
          }
          
        }
      } else {
        if(!GoFloor()){
          if(!GoSide()){
            rb.SetSpeed(0, 'R');
            rb.SetSpeed(0, 'L');
          }
        }
      }*/
      /*for(unsigned short int i = 0; i <= 50; i++){
        rb.SetSpeed(255, 'R');
        rb.SetSpeed(255, 'R');
        delay(50);
        rb.SetSpeed(-255, 'R');
        rb.SetSpeed(-255, 'R');
        delay(50);
      }*/
      /*while(!GoFloor()){
          rb.SetSpeed(255, 'R');
          rb.SetSpeed(255, 'L');
      }

      while(!GoFloor()){
          rb.SetSpeed(0, 'R');
          rb.SetSpeed(-255, 'L');
      }

      while(!GoFloor()){
          rb.SetSpeed(255, 'R');
          rb.SetSpeed(255, 'L');
      }

      while(!GoFloor()){
          rb.SetSpeed(-255, 'R');
          rb.SetSpeed(0, 'L');
      }*/
}
