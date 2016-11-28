

#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/DropAllTotes.h"
#include "Commands/DropTote.h"
#include "Commands/LiftTote.h"
#include "Commands/LowerToteLift.h"
#include "Commands/PIDDriveStraight.h"
#include "Commands/RaiseToteLift.h"
#include "Commands/RotateToAngle.h"
#include "Commands/ToggleToteBoard.h"
#include "Commands/RotateToAngle.h"
#include "Commands/FlipChassis.h"
#include "Commands/AutoTote.h"
#include "Commands/AutoVoid.h"
#include "Commands/ToggleBinArms.h"
OI::OI() {
	fin.open("/home/lvuser/RoboJoe3.0Preferences.txt");
		std::string inputstring;

		fin>>inputstring>>LeftCircumference
		>>inputstring>>RightCircumference
		>>inputstring>>Encoder_CPR
		>>inputstring>>Turning_Diameter
		>>inputstring>>Pincers_Time
		>>inputstring>>Angle_Correction
		>>inputstring>>Tote_1_Encoder_Height
		>>inputstring>>Tote_2_Encoder_Height
		>>inputstring>>Tote_3_Encoder_Height
		>>inputstring>>Kp
		>>inputstring>>Ki
		>>inputstring>>Kd
		>>inputstring>>RunPrintData
		;
		fin.close();

autofin.open("/home/lvuser/AutonomousPreferences.txt");
		autofin>>inputstring>>Drive1_XDistance
		>>inputstring>>Drive1_YDistance
		>>inputstring>>Drive1_Speed
		>>inputstring>>Drive2_XDistance
		>>inputstring>>Drive2_YDistance
		>>inputstring>>Drive2_Speed
		>>inputstring>>Drive3_XDistance
		>>inputstring>>Drive3_YDistance
		>>inputstring>>Drive3_Speed
		>>inputstring>>Rotate1_Angle
		>>inputstring>>Rotate1_Left
		>>inputstring>>Rotate1_Speed
		>>inputstring>>Drive4_XDistance
		>>inputstring>>Drive4_YDistance
		>>inputstring>>Drive4_Speed
		>>inputstring>>Rotate2_Angle
		>>inputstring>>Rotate2_Left
		>>inputstring>>Rotate2_Speed
		>>inputstring>>Drive5_XDistance
		>>inputstring>>Drive5_YDistance
		>>inputstring>>Drive5_Speed
		;

autofin.close();

	// Process operator interface input here.


	xboxstick = new Joystick(0);
	
	start = new JoystickButton(xboxstick, 8);
	start->WhenPressed(new ToggleToteBoard());
	/**
	leftBumper = new JoystickButton(xboxstick, 5);
	rightBumper = new JoystickButton(xboxstick, 6);
	joystickbutton= new JoystickButton(xboxstick, 9);**/
	back = new JoystickButton(xboxstick, 7);
	back->WhenPressed(new ToggleBinArms(false));
	y = new JoystickButton(xboxstick, 4);
	y->WhileHeld(new RaiseToteLift());
	x = new JoystickButton(xboxstick, 3);
	x->WhileHeld(new LowerToteLift());
	a = new JoystickButton(xboxstick, 1);
	a->WhenPressed(new DropTote());
	b = new JoystickButton(xboxstick, 2);
	b->WhenPressed(new LiftTote());

		SmartDashboard::PutData("Lift", new LiftTote());
		SmartDashboard::PutData("Drop", new DropTote());
		SmartDashboard::PutData("Toggle TB", new ToggleToteBoard());
		SmartDashboard::PutData("Make Stack", new DropAllTotes());
		SmartDashboard::PutData("TL Up", new RaiseToteLift());
		SmartDashboard::PutData("TL Down", new LowerToteLift());
		SmartDashboard::PutData("Flip Chassis", new FlipChassis());



}


Joystick* OI::getxboxstick() {
	return xboxstick;
}


double OI::GetLeftCircumference(){
	return LeftCircumference;
}
double OI::GetRightCircumference(){
	return RightCircumference;
}
double OI::GetEncoder_CPR(){
	return Encoder_CPR;
}
double OI::GetTurning_Diameter(){
	return Turning_Diameter;
}
double OI::GetPincers_Time(){
	return Pincers_Time;
}
double OI::GetAngle_Correction(){
	return Angle_Correction;
}
double OI::GetTote_1_Encoder_Height(){
	return Tote_1_Encoder_Height;
}
double OI::GetTote_2_Encoder_Height(){
	return Tote_2_Encoder_Height;
}
double OI::GetTote_3_Encoder_Height(){
	return Tote_3_Encoder_Height;
}
double OI::GetKp(){
	return Kp;
}
double OI::GetKi(){
	return Ki;
}
double OI::GetKd(){
	return Kd;
}

bool OI::GetRunPrintData(){
	return RunPrintData;
}
double OI::GetDrive1_XDistance(){
	return Drive1_XDistance;
}
double OI::GetDrive1_YDistance(){
	return Drive1_YDistance;
}
double OI::GetDrive1_Speed(){
	return Drive1_Speed;
}
double OI::GetDrive2_XDistance(){
	return Drive2_XDistance;
}
double OI::GetDrive2_YDistance(){
	return Drive2_YDistance;
}
double OI::GetDrive2_Speed(){
	return Drive2_Speed;
}
double OI::GetDrive3_XDistance(){
	return Drive3_XDistance;
}
double OI::GetDrive3_YDistance(){
	return Drive3_YDistance;
}
double OI::GetDrive3_Speed(){
	return Drive3_Speed;
}
double OI::GetRotate1_Angle(){
	return Rotate1_Angle;
}
bool OI::GetRotate1_Left(){
	return Rotate1_Left;
}
double OI::GetRotate1_Speed(){
	return Rotate1_Speed;
}
double OI::GetDrive4_XDistance(){
	return Drive4_XDistance;
}
double OI::GetDrive4_YDistance(){
	return Drive4_YDistance;
}
double OI::GetDrive4_Speed(){
	return Drive4_Speed;
}
double OI::GetRotate2_Angle(){
	return Rotate2_Angle;
}
bool OI::GetRotate2_Left(){
	return Rotate2_Left;
}
double OI::GetRotate2_Speed(){
	return Rotate2_Speed;
}
double OI::GetDrive5_XDistance(){
	return Drive5_XDistance;
}
double OI::GetDrive5_YDistance(){
	return Drive5_YDistance;
}
double OI::GetDrive5_Speed(){
	return Drive5_Speed;
}


