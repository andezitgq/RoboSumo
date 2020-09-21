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

bool GoSide(){
  
}

void setup() {
  Serial.begin(9600);
  
  byte modeButton = A5,
       modeLed1 = 7,
       modeLed2 = 8,
       modeLed3 = 12,
       modeLed4 = A4;
  
  pinMode(modeLed1, OUTPUT);
  pinMode(modeLed2, OUTPUT);
  pinMode(modeLed3, OUTPUT);
  pinMode(modeLed4, OUTPUT);
  pinMode(modeButton, INPUT_PULLUP);

  byte i = 1;
  while(digitalRead(modeButton) == HIGH){
      switch(i){
        case 1:
          digitalWrite(modeLed1, 1);
          digitalWrite(modeLed2, 0);
          digitalWrite(modeLed3, 0);
          digitalWrite(modeLed4, 0);
          break;
            
        case 2:
          digitalWrite(modeLed1, 0);
          digitalWrite(modeLed2, 1);
          digitalWrite(modeLed3, 0);
          digitalWrite(modeLed4, 0); 
          break;
            
        case 3:
          digitalWrite(modeLed1, 0);
          digitalWrite(modeLed2, 0);
          digitalWrite(modeLed3, 1);
          digitalWrite(modeLed4, 0);
          break;
          
        case 4:
          digitalWrite(modeLed1, 0);
          digitalWrite(modeLed2, 0);
          digitalWrite(modeLed3, 0);
          digitalWrite(modeLed4, 1);
          break;
       }
       
       i++;
       if(i > 4){
         i = 1;
       }
       
       delay(500);
  }
  Mode = i - 1;
}

void loop() {
  rb.SensorDump();
  /*switch(Mode){
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
            rb.SetSpeed(map(rb.GetEnemyFrontL(), 0, 1024, 0, 255), 'R');
            rb.SetSpeed(map(rb.GetEnemyFrontR(), 0, 1024, 0, 255), 'L');
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
      
    case 0:
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
  }*/
}
