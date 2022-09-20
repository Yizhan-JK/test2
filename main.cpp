#include "../include/main.h"
#include "../include/autonomous.h"

void leftBtn(){

}
void centerBtn(){

}
void rightBtn(){

}
void initialize() {
	pros::lcd::initialize();

	screenPrintString(2, 2, "z");
  FrontLeft.set_brake_mode(MOTOR_BRAKE_COAST);
  FrontRight.set_brake_mode(MOTOR_BRAKE_COAST);
  BackLeft.set_brake_mode(MOTOR_BRAKE_COAST);
  BackRight.set_brake_mode(MOTOR_BRAKE_COAST);
  Intake.set_brake_mode(MOTOR_BRAKE_COAST);
  FlywheelL.set_brake_mode(MOTOR_BRAKE_COAST);
  FlywheelR.set_brake_mode(MOTOR_BRAKE_COAST);
  flywheelMovement();
	//autonSelect();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  switch(count){
    case 0:
      leftAuton();
      break;
    case 1:
      rightAuton();
      break;
    case 2:
      soloAWP();
      break;
  }
}
using namespace pros;
void opcontrol() {
  while (true) {
		double power = master.get_analog(ANALOG_LEFT_Y);
		double turn = master.get_analog(ANALOG_LEFT_X);
		driverControl(100 * power + turn, 100 * power - turn);
    pros::delay(2);
  }
  /*
  while (true) {
    int power = master.get_analog(ANALOG_LEFT_Y);
    int turn = master.get_analog(ANALOG_RIGHT_X);
    int left = power + turn;
    int right = power - turn;
    FrontRight.move_velocity(right);
    FrontLeft.move_velocity(left);
	BackRight.move_velocity(right);
    BackLeft.move_velocity(left);

    pros::delay(2);
  }
  */
}
