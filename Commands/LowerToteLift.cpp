

#include "LowerToteLift.h"

LowerToteLift::LowerToteLift() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::toteLift);

}

// Called just before this Command runs the first time
void LowerToteLift::Initialize() {
	Robot::toteLift->LiftDown();
	Robot::toteLift->SetWasLiftManual(true);
}

// Called repeatedly when this Command is scheduled to run
void LowerToteLift::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool LowerToteLift::IsFinished() {
	return false;//Robot::toteLift->GetLiftEncoder()<=0;
}

// Called once after isFinished returns true
void LowerToteLift::End() {
	Robot::toteLift->LiftStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerToteLift::Interrupted() {
	Robot::toteLift->LiftStop();
}
