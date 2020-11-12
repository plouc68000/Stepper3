/* Tested 4/11/2020 JLG  Clock Project make 1 rpm per min
 *  Same as Stepper1.ino, but half step 4096 steps !!!
 *  
 *  uneclock en bois complete
 *  http://www.trainelectronics.com/Arduino/Clock_stepper_hands/index.htm
 *  
 *  Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board and Arduino UNO. 
 *  https://www.makerguides.com/28byj-48-stepper-motor-arduino-tutorial/
 */

// Include the Arduino Stepper.h library:
#include <Stepper3.h>

// Define number of steps per rotation:
const int stepsPerRevolution = 4096;

// Wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver

// Create stepper object called 'myStepper', note the pin order:
Stepper3 myStepper = Stepper3(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Set the speed to 1 rpm:
  myStepper.setSpeed(1); // une revolution par seconde, aiguille des secondes
}

void loop() {
  
  // Step one revolution in the clock direction:
  // motor 2 was turning other direction 
  myStepper.step(stepsPerRevolution); // code bloquant sur 1 tour
  
}
