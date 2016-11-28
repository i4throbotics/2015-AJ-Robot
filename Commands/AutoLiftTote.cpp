#include "AutoLiftTote.h"

AutoLiftTote::AutoLiftTote(int desired)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::toteLift);
	m_desired=desired;
}

// Called just before this Command runs the first time
void AutoLiftTote::Initialize()
{
Robot::toteLift->LiftUp();
}

// Called repeatedly when this Command is scheduled to run
void AutoLiftTote::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutoLiftTote::IsFinished()
{

	return Robot::toteLift->GetLiftEncoder()>=m_desired;
}

// Called once after isFinished returns true
void AutoLiftTote::End()
{
Robot::toteLift->LiftStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLiftTote::Interrupted()
{
	Robot::toteLift->LiftStop();
}
