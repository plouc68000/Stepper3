/*
 * Stepper3.h - modified stepper.h with half step for 28BJY-48
 *
 * 
 *
 * The sequence of control signals for 4 control wires is as follows:
 *
 * Step C0 C1 C2 C3
 *    1  0  0  1  0
 *    2  0  1  0  0
 *    3  0  0  0  1
 *    4  1  0  0  0
 *
 *
 */

// ensure this library description is only included once
#ifndef Stepper3_h
#define Stepper3_h

// library interface description
class Stepper3 {
  public:
    // constructors:
    Stepper3(int number_of_steps, int motor_pin_1, int motor_pin_2);
    Stepper3(int number_of_steps, int motor_pin_1, int motor_pin_2,
                                 int motor_pin_3, int motor_pin_4);
    Stepper3(int number_of_steps, int motor_pin_1, int motor_pin_2,
                                 int motor_pin_3, int motor_pin_4,
                                 int motor_pin_5);

    // speed setter method:
    void setSpeed(long whatSpeed);

    // mover method:
    void step(int number_of_steps);

    int version(void);

  private:
    void stepMotor(int this_step);

    int direction;            // Direction of rotation
    unsigned long step_delay; // delay between steps, in ms, based on speed
    int number_of_steps;      // total number of steps this motor can take
    int pin_count;            // how many pins are in use.
    int step_number;          // which step the motor is on

    // motor pin numbers:
    int motor_pin_1;
    int motor_pin_2;
    int motor_pin_3;
    int motor_pin_4;
    int motor_pin_5;          // Only 5 phase motor

    unsigned long last_step_time; // time stamp in us of when the last step was taken
};

#endif

