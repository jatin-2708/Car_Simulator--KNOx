#include <Joystick.h>

Joystick_ Joystick;

// Variable
int steeringwheel = A0;
int brake = A2; 
int accelerator = A1;

int steeringwheelValue = 0;
int curr_steeringwheelValue;
int prev_steeringwheelValue=0;
int steeringwheelValuebyte1 = 0;
int steeringwheelValuebyte2 = 0;

int brakeValue = 0;
int curr_brakeValue;
int prev_brakeValue=0;
int brakeValuebyte=0;

int acceleratorValue = 0;
int acceleratorValuebyte = 0;
int curr_acceleratorValue;
int prev_acceleratorValue=0;



// init joystick libary
void setup() {
  Joystick.begin();
}

void loop() {
  
  // Steeringwheel
  curr_steeringwheelValue = analogRead(steeringwheel);
  steeringwheelValue=0.2*curr_steeringwheelValue + 0.8*prev_steeringwheelValue;
  
  int new_steeringwheelValue=map(steeringwheelValue,80,505,0,127);
  int new_steeringwheelValue1=map(steeringwheelValue,506,900,128,255);
  if (steeringwheelValue < 505)
  {
    if (new_steeringwheelValue < 0)
    {
      new_steeringwheelValue = 0;
    }
    if (new_steeringwheelValue > 127)
    {
      new_steeringwheelValue = 127;
    }
    Joystick.setXAxis(new_steeringwheelValue);
  }
  else {
    if (new_steeringwheelValue1 < 128)
    {
      new_steeringwheelValue1 = 128;
    }
    if (new_steeringwheelValue1 > 255)
    {
      new_steeringwheelValue1 = 255;
    }
    Joystick.setXAxis(new_steeringwheelValue1);
  }
  
  prev_steeringwheelValue=curr_steeringwheelValue;
  delay(10); 

  // Brake
  curr_brakeValue = analogRead(brake);
  brakeValue=0.2*curr_brakeValue + 0.8*prev_brakeValue;
  
 
  int new_brakeValue=map(brakeValue,300,920,0,255);
  Joystick.setThrottle(new_brakeValue);
  prev_brakeValue=curr_brakeValue;
  delay(10); 

  // accelerator
  curr_acceleratorValue = analogRead(accelerator);
  acceleratorValue=0.2*curr_acceleratorValue + 0.8*prev_acceleratorValue;
  
  int new_acceleratorValue=map(acceleratorValue,300,1024,0,255);

   
  Joystick.setZAxis(new_acceleratorValue);
  prev_acceleratorValue=curr_acceleratorValue;
  Joystick.setYAxis(0);
  

  delay(10); 
}