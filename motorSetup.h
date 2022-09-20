#include "../include/main.h"


using namespace pros;

const double ticksPerDeg = 900/360;
//200*4.125*pi/60 * sqrt(2), = 60
const double robotSpeed = 43.196 * sqrt(2);
const double rotationSpeed = 200;

extern Controller master;
extern Motor FrontLeft;
extern Motor FrontRight;
extern Motor BackLeft;
extern Motor BackRight;

extern Motor Intake

extern Motor FlywheelLeft;
extern Motor FlywheelRight;

//Ports
const int FLPort = 1;
const int FRPort = 4;
const int BLPort = 16;
const int BRPort = 20;

const int ITPort = 10; //

const int FWLPort = 11: 
const int FWRPort = 12;//

Controller master (E_CONTROLLER_MASTER);

Motor FrontLeft(FLPort, true);
Motor FrontRight(FRPort);
Motor BackLeft(BLPort, true);
Motor BackRight(BRPort);

Motor Intake(ITPort);

Motor FlywheelL(FWLPort);
Motor FlywheelR(FWRPort, true);

/*ADIEncoder yWheel('C', 'D', true);
ADIEncoder xWheel('A', 'B', false);


//Calibrate the sensors
void calibrateSensors(){
  xWheel.reset();
  yWheel.reset();
  inertial.reset();

  int timeInit = millis();

  inertial.reset();
  while(inertial.is_calibrating()){
    lcd::print(1, "Calibrating");
    delay(10);
  }
  delay(2000);
  lcd::print(1, "Calibration took %f", millis() - timeInit);

