
#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <iostream>
#include <fstream>
#include <iostream>
class OI {
private:
	Joystick* xboxstick;
	JoystickButton* start;
	JoystickButton* leftBumper;
	JoystickButton* rightBumper;
	JoystickButton* y;
	JoystickButton* x;
	JoystickButton* back;

	JoystickButton* a;
	JoystickButton* b;
	JoystickButton* joystickbutton;
	JoystickButton* joystickbutton2;


	double LeftCircumference;
	double RightCircumference;
	double Encoder_CPR;
	double Turning_Diameter;
	double Pincers_Time;
	double Angle_Correction;
	double Tote_1_Encoder_Height;
	double Tote_2_Encoder_Height;
	double Tote_3_Encoder_Height;
	double Kp;
	double Ki;
	double Kd;
	bool RunPrintData;


	double Drive1_XDistance;
	double Drive1_YDistance;
	double Drive1_Speed;
	double Drive2_XDistance;
	double Drive2_YDistance;
	double Drive2_Speed;
	double Drive3_XDistance;
	double Drive3_YDistance;
	double Drive3_Speed;
	double Rotate1_Angle;
	bool Rotate1_Left;
	double Rotate1_Speed;
	double Drive4_XDistance;
	double Drive4_YDistance;
	double Drive4_Speed;
	double Rotate2_Angle;
	bool Rotate2_Left;
	double Rotate2_Speed;
	double Drive5_XDistance;
	double Drive5_YDistance;
	double Drive5_Speed;
	std::ifstream fin;
	std::ifstream autofin;
public:
	OI();
 
	Joystick* getxboxstick();

	double GetLeftCircumference();
	double GetRightCircumference();
	double GetEncoder_CPR();
	double GetTurning_Diameter();
	double GetPincers_Time();
	double GetAngle_Correction();
	double GetTote_1_Encoder_Height();
	double GetTote_2_Encoder_Height();
	double GetTote_3_Encoder_Height();
	double GetKp();
	double GetKi();
	double GetKd();
	bool GetRunPrintData();

	double GetDrive1_XDistance();
	double GetDrive1_YDistance();
	double GetDrive1_Speed();
	double GetDrive2_XDistance();
	double GetDrive2_YDistance();
	double GetDrive2_Speed();
	double GetDrive3_XDistance();
	double GetDrive3_YDistance();
	double GetDrive3_Speed();
	double GetRotate1_Angle();
	bool GetRotate1_Left();
	double GetRotate1_Speed();
	double GetDrive4_XDistance();
	double GetDrive4_YDistance();
	double GetDrive4_Speed();
	double GetRotate2_Angle();
	bool GetRotate2_Left();
	double GetRotate2_Speed();
	double GetDrive5_XDistance();
	double GetDrive5_YDistance();
	double GetDrive5_Speed();

};

#endif
