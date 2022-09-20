#include "../include/main.h"
#include "../include/functions.h"
/*
std::shared_ptr<ChassisController> driveAuton = ChassisControllerBuilder()
    .withMotors({FL_MOTOR,BL_MOTOR,ML_MOTOR},{FR_MOTOR,BR_MOTOR,MR_MOTOR})
    .withGains(
    {0.0021, 0.0, 0.0001}, //distance gains
    {0.0027,0.0, 0.0001} //turn gains
    )
    .withMaxVelocity(200)
    .withDerivativeFilters(
      std::make_unique<AverageFilter<3>>()
    )
    // Green gearset, 4 in wheel diam, 11.5 in wheel track
    .withDimensions(AbstractMotor::gearset::green, {{4.88_in, 14.5_in}, imev5GreenTPR})
    .withOdometry()
    .buildOdometry();

std::shared_ptr<AsyncMotionProfileController> profileController =
AsyncMotionProfileControllerBuilder()
.withLimits({
  1.7, // Maximum linear velocity of the Chassis in m/s
    2.0, // Maximum linear acceleration of the Chassis in m/s/s
    10.0 // Maximum linear jerk of the Chassis in m/s/s/s)
  })
  .withOutput(driveAuton)
  .buildMotionProfileController();*/
/*
void leftAuton(){
    profileController -> generatePath({
        
    );
}

void rightAuton(){
    profileController -> generatePath({
        
    );
}

void soloAWP(){
    profileController -> generatePath({

    );
}
*/
void disabledAuton(){

}

void pop(){

}

void skills(){

}
