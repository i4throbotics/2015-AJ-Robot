#include "AutoTote.h"
#include "../RobotMap.h"
#include "ToggleToteBoard.h"
#include "PIDDriveStraight.h"
#include "AutoLiftTote.h"
#include "RotateToAngle.h"
AutoTote::AutoTote(bool overstep)
{
	double distance;
	if(overstep)
		distance=130;
	else
		distance=125;
	//NORMAL 1 TOTE AUTO
	AddSequential(new AutoLiftTote(NORMAL_AUTO_TOTE));//lift tote
	AddSequential(new PIDDriveStraight(0, 18, 0.5));//drive forward to clear
	AddSequential(new RotateToAngle(268, true, 0.5));//turn around (to prevent tote falling off when going over step) (not to 270 because cannnot go over step straight)
	AddSequential(new PIDDriveStraight(0, distance, 0.5));//drive to auto zone
	if(overstep)
		AddSequential(new RotateToAngle(180, true, 0.5));//rotate to be contained in zone
	else
		AddSequential(new RotateToAngle(359, false, 0.5));


		//AddParallel(new Command1());
		//AddSequential(new Command2());
}

/**void AutoTote::Initialize(){
	Robot::printer->OpenFile();
}
void AutoTote::Execute(){
		Robot::printer->Print(TimeSinceInitialized());
}
void AutoTote::Interrupted(){
	Robot::printer->CloseFile();
}**/
