

#include "RaiseToteLift.h"

RaiseToteLift::RaiseToteLift() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::toteLift);
}

// Called just before this Command runs the first time
void RaiseToteLift::Initialize() {
	Robot::toteLift->LiftUp();
	Robot::toteLift->SetWasLiftManual(true);
}

// Called repeatedly when this Command is scheduled to run
void RaiseToteLift::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool RaiseToteLift::IsFinished() {
	return Robot::toteLift->GetLiftEncoder()>= Robot::oi->GetTote_3_Encoder_Height();
}

// Called once after isFinished returns true
void RaiseToteLift::End() {
	Robot::toteLift->LiftStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseToteLift::Interrupted() {
	Robot::toteLift->LiftStop();
}
