using namespace vex;
vex::brain Brain;
vex::motor LeftMotor (vex::PORT1, vex::gearSetting::ratio18_1,false); 
vex::motor RightMotor (vex::PORT10, vex::gearSetting::ratio18_1,false);
vex::motor ClawMotor (vex::PORT3, vex::gearSetting::ratio18_1,true); 
vex::motor armMotor (vex::PORT8, vex::gearSetting::ratio18_1,true);
