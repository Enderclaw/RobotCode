vex::brain Brain;
vex::motor LeftDrive = vex::motor(vex::PORT1, vex::gearSetting::ratio18_1);
vex::motor LeftLift = vex::motor(vex::PORT2, vex::gearSetting::ratio18_1);
vex::motor LeftFly = vex::motor(vex::PORT3, vex::gearSetting::ratio18_1);
vex::motor BallIntake = vex::motor(vex::PORT4, vex::gearSetting::ratio18_1);
vex::motor RightFly = vex::motor(vex::PORT8, vex::gearSetting::ratio18_1, true);
vex::motor RightLift = vex::motor(vex::PORT9, vex::gearSetting::ratio18_1, true);
vex::motor RightDrive = vex::motor(vex::PORT10, vex::gearSetting::ratio18_1, true);
vex::controller Controller1;
