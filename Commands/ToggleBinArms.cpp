#include "ToggleBinArms.h"

ToggleBinArms::ToggleBinArms(bool auton)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::binArms);
	m_auto=auton;
}

// Called just before this Command runs the first time
void ToggleBinArms::Initialize()
{

	if(Robot::binArms->GetAreArmsUp()){
			Robot::binArms->BinArmsDown();
			Robot::binArms->SetAreArmsUp(false);
		}
		else{
			Robot::binArms->BinArmsUp();
			Robot::binArms->SetAreArmsUp(true);
		}
	SetTimeout(1.5);
}

// Called repeatedly when this Command is scheduled to run
void ToggleBinArms::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleBinArms::IsFinished()
{
	if(m_auto)
		return IsTimedOut();
	else
		return true;
}

// Called once after isFinished returns true
void ToggleBinArms::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleBinArms::Interrupted()
{

}
