#include "Sumo.h"

#define FS_MIN 0
#define FS_MAX 0

byte Mode = 1;

Robot rb;

bool GoFloor(){
  if(rb.GetFloorBL()){
    rb.SetSpeed(50, 'L');
    return true;
  }
  
  if(rb.GetFloorBR()){
    rb.SetSpeed(50, 'R');
    return true;
  }
  
  if(rb.GetFloorFL()){
    rb.SetSpeed(-50, 'L');
    return true;
  }
  
  if(rb.GetFloorFR()){
    rb.SetSpeed(-50, 'R');
    return true;
  }
  
  return false;
}

void setup() {
  Serial.begin(9600);
  //setting Mode
}

void loop() {
  switch(Mode){
    case 1:
      //Mode "Front"
      if(rb.GetEnemyFrontL() <= FS_MIN || rb.GetEnemyFrontR() <= FS_MIN){
        if(rb.GetEnemyFrontL() > rb.GetEnemyFrontR()){
          
          if(!GoFloor)
            rb.SetSpeed(50, 'L');
            
        } else if(rb.GetEnemyFrontL() > rb.GetEnemyFrontR()){
          
          if(!GoFloor)
            rb.SetSpeed(50, 'R');
            
        } else {
          
          if(!GoFloor){
            rb.SetSpeed(100, 'R');
            rb.SetSpeed(100, 'L');
          }
          
        }
      } else {
        if(!GoFloor)
          rb.SetSpeed(50, 'R');
      }
      
      break;
      
    case 2:
      //Mode "Back"
      break;
      
    case 3:
      //Mode "Side"
      break;
      
    case 4:
      //Mode "Auto"
      while(!GoFloor){
        rb.SetSpeed(100, 'R');
        rb.SetSpeed(100, 'L');
      }
      
      while(!GoFloor){
        rb.SetSpeed(100, 'R');
        rb.SetSpeed(50, 'L');
      }
      
      break;
  }
}

