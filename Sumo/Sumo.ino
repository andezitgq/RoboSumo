#include "Sumo.h"

byte Mode = 1;

Robot rb;

bool GoFloor(){
  if(rb.GetFloorBL() == false){
    rb.SetSpeed(50, 'L');
    rb.SetSpeed(0, 'R');
    return true;
  }
  
  if(rb.GetFloorBR() == false){
    rb.SetSpeed(50, 'R');
    rb.SetSpeed(0, 'L');
    return true;
  }
  
  if(rb.GetFloorFL() == false){
    rb.SetSpeed(-50, 'L');
    rb.SetSpeed(0, 'R');
    return true;
  }
  
  if(rb.GetFloorFR() == false){
    rb.SetSpeed(-50, 'R');
    rb.SetSpeed(0, 'L');
    return true;
  }
  
  return false;
}

bool GoSide(){
  
}

void setup() {
  Serial.begin(9600);
}

void loop() {
      if((rb.GetEnemyFrontL() <= FS_MIN && rb.GetEnemyFrontL() > 0) || (rb.GetEnemyFrontR() <= FS_MIN && rb.GetEnemyFrontR() > 0)){
        if(rb.GetEnemyFrontL() < rb.GetEnemyFrontR()){
          
          if(!GoFloor())
            rb.SetSpeed(25, 'L');
            
        } else if(rb.GetEnemyFrontL() > rb.GetEnemyFrontR()){
          
          if(!GoFloor())
            rb.SetSpeed(25, 'R');
            
        } else {
          
          if(!GoFloor()){
            rb.SetSpeed(map(rb.GetEnemyFrontL(), 100, 0, 0, 255), 'R');
            rb.SetSpeed(map(rb.GetEnemyFrontR(), 100, 0, 0, 255), 'L');
          } 
          
        }
      } else {
        if(!GoFloor())
          rb.SetSpeed(50, 'R');
          rb.SetSpeed(0, 'L');
      }
}
