# Car Simulator Controlled via Arduino

## Project Overview

### Title
Car Simulator Controlled via Arduino

### Description
This project creates a realistic car simulator using physical controls interfaced with an Arduino Micro. The user can control the car's acceleration, braking, and steering using linear and rotary potentiometers.

### Objective
To provide an immersive driving experience by integrating physical control elements with a computer-based car simulation.

## Hardware Components

### List of Components
- Arduino Micro: The central microcontroller for handling input from the potentiometers.
- Linear Potentiometers: Used to control acceleration and brake inputs.
- Rotary Potentiometer: Used to control steering.
- Wiring and Breadboards: For connecting components.

## Schematics

### Software Components
- Arduino IDE: Version 2.3.2
- Joystick Library: Version 2.0, available at Arduino Joystick Library.

## Installation and Setup

### Hardware Setup
1. Connect the linear potentiometers to the analog inputs of the Arduino.
2. Connect the rotary potentiometer to another analog input.
3. Ensure all grounds and power lines are correctly wired.

### Software Setup
1. Install the Arduino IDE from [here](https://www.arduino.cc/en/software).
2. Install the Joystick library via the Library Manager in the Arduino IDE.
3. Upload the provided code to the Arduino.

## Main Code

```cpp
#include <Joystick.h>

Joystick_ Joystick;

// Variable
int steeringwheel = A0;
int brake = A3; 
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

void setup() {
  Joystick.begin();
}

void loop() {
  
  // Steeringwheel
  curr_steeringwheelValue = analogRead(steeringwheel);
  steeringwheelValue=0.2*curr_steeringwheelValue + 0.8*prev_steeringwheelValue;
  
  int new_steeringwheelValue=map(steeringwheelValue,180,500,0,127);
  int new_steeringwheelValue1=map(steeringwheelValue,501,960,128,255);
  if (steeringwheelValue < 500)
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
  
 
  int new_brakeValue=map(brakeValue,460,900,0,255);
  Joystick.setThrottle(new_brakeValue);
  prev_brakeValue=curr_brakeValue;
  delay(10); 

  // Accelerator
  curr_acceleratorValue = analogRead(accelerator);
  acceleratorValue=0.2*curr_acceleratorValue + 0.8*prev_acceleratorValue;
  
  int new_acceleratorValue=map(acceleratorValue,775,47,0,255);

   
  Joystick.setZAxis(new_acceleratorValue);
  prev_acceleratorValue=curr_acceleratorValue;
  Joystick.setYAxis(0);
  
  delay(10); 
}
```
## Summary

The code continuously reads analog inputs from the potentiometers, smooths these inputs, maps them to appropriate joystick ranges, and updates the virtual joystick. This allows the potentiometers to control the steering, braking, and acceleration in a car simulator.

### Testing and Calibration

After running the code into the Arduino and ensuring proper hardware connections, calibrate the joystick through the Control Panel Wizard. After that, use the Arduino as a Game Controller for any Game.

In the game, choose Game Controller as the Arduino board Joystick and configure its settings. Your Simulator is now ready.

