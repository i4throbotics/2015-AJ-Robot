#include "BinLiftManual.h"

BinLiftManual::BinLiftManual()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::binLift);
}

// Called just before this Command runs the first time
void BinLiftManual::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BinLiftManual::Execute()
{
	double speed= (Robot::oi->getxboxstick()->GetRawAxis(3)-Robot::oi->getxboxstick()->GetZ());
		if(fabs(speed)>0.1){
			Robot::binLift->SetSpeed(speed);
		}
		else{
			Robot::binLift->SetSpeed(0.1);
		}
}

// Make this return true when this Command no longer needs to run execute()
bool BinLiftManual::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BinLiftManual::End()
{
	Robot::binLift->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BinLiftManual::Interrupted()
{
	Robot::binLift->SetSpeed(0);
}
