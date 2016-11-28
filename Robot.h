

#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


#include "Subsystems/Chassis.h"
#include "Subsystems/ToteLift.h"
#include "Subsystems/Printer.h"
#include "Subsystems/BinLift.h"
#include "Subsystems/BinArms.h"


#include "OI.h"
#include <iostream>

class Robot : public IterativeRobot {
private:
	std::ofstream fout;
	Timer time;
	IMAQdxSession session;
		Image *frame;
		IMAQdxError imaqError;
public:
	Command *autonomousCommand;
	SendableChooser *autoChooser;
	static OI *oi;
	LiveWindow *lw;
	static Chassis* chassis;
	static ToteLift* toteLift;
	static Printer* printer;
	static BinLift* binLift;
	static BinArms* binArms;


	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
