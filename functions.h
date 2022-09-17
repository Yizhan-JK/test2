
#include "motorSetup.h"


//Useful Constants
const double wheelCircumfrence = 2.75 * M_PI;

int count = 0;
std::string autons[3] = {"leftAuton", "rightAuton", "soloAWP"};
int size = 3;

void autonSelect(){
  master.clear();
  pros::delay(200);
  while(true){
    master.clear();
    pros::delay(100);
    screenPrintString(2, 1, autons[count]);
    pros::delay(100);
    if(master.get_digital(DIGITAL_RIGHT)){
      count = (count + 1) % size;
    }
    else if(master.get_digital(DIGITAL_LEFT)){
      count = (count - 1) % size;
    }
    else if(master.get_digital(DIGITAL_A)){
      pros::delay(100);
      if(master.get_digital(DIGITAL_A)){

        break;
      }
    }
  }
  master.rumble("AA");
}

/*
//For debugging things
void printOnScreen(){
	//lcd::print(1, "Velocity FL: %f", FrontLeft.get_actual_velocity());
	//lcd::print(2, "Target Velocity FL: %f", drive.wheelTL);
  lcd::print(0, "Inertial Reading: %f", inertial.get_rotation());
  lcd::print(1, "Y Wheel Reading: %f", ((double) yWheel.get_value()));
  lcd::print(2, "X Wheel Reading: %f", ((double) xWheel.get_value()));
}

void driverControl(double power, double turn){
  //Calculates speed of wheels for driver control

	FrontLeft.move_velocity(l);
	FrontRight.move_velocity(r);
	BackLeft.move_velocity(l);
	BackRight.move_velocity(r);
}
*/


void stopDrive(bool hold = false){
  //Shortcut to stop the drive quickly
  if(hold){
    FrontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    FrontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    BackLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    BackRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  }
  FrontLeft.move_velocity(0);
	FrontRight.move_velocity(0);
	BackLeft.move_velocity(0);
	BackRight.move_velocity(0);
  delay(100);
  FrontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  FrontRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  BackLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  BackRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

void intakeMovement(){
  if(master.get_digital(DIGITAL_X)){ //
    IntakeController->setTarget(100);
  }
  else if (master.get_digital(DIGITAL_B)){ //
    IntakeController->setTarget(-100);
  }
  else {
    IntakeController->setTarget(0);
  }
}

void flywheelMovement(){
  if(master.get_digital(DIGITAL_LEFT)){
    FlywheelLController->setTarget(70);
    FlywheelRController->setTarget(70);
  }
  else if (master.get_digital(DIGITAL_RIGHT)){
    FlywheelLController->setTarget(-70);
    FlywheelRController->setTarget(-70);
  }
  else {
    FlywheelLController->setTarget(0);
    FlywheelRController->setTarget(0);
  }
}
/*int percent = 50;
void flywheelMovement(){
  if(master.get_digital(DIGITAL_LEFT)){
    FlywheelLController->setTarget(percent);
    FlywheelRController->setTarget(percent);
    master.clear();
    screenPrintString(2, 1, "Percent: " + percent);
  }
  if (master.get_digital(DIGITAL_UP && percent <= 100)){
      FLywheelLController->setTarget(percent + 10);
      FlywheelRController->setTarget(percent + 10);
      percent += 10;
      master.clear();
      screenPrintString(2, 1, "Percent: " + percent);
    }
  if (master.get_digital(DIGITAL_DOWN && percent >= 10)){
      FLywheelLController->setTarget(percent - 10);
      FlywheelRController->setTarget(percent - 10);
      percent -= 10;
      master.clear();
      screenPrintString(2, 1, "Percent: " + percent);
    }
  else if (master.get_digital(DIGITAL_RIGHT)){
    master.clear();
    FlywheelLController->setTarget(-70);
    FlywheelRController->setTarget(-70);
  }
  else {
    FlywheelLController->setTarget(0);
    FlywheelRController->setTarget(0);
  }
}*/