

#include "DropAllTotes.h"

DropAllTotes::DropAllTotes() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::toteLift);

}

// Called just before this Command runs the first time
void DropAllTotes::Initialize() {
	Robot::toteLift->LiftDown();
	Robot::toteLift->SetLiftPosition(0);
	Robot::toteLift->SetWasLiftManual(true);
	
}

// Called repeatedly when this Command is scheduled to run
void DropAllTotes::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool DropAllTotes::IsFinished() {
	if (Robot::toteLift->GetLiftEncoder()<= 0){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void DropAllTotes::End() {
	Robot::toteLift->LiftStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DropAllTotes::Interrupted() {
	Robot::toteLift->LiftStop();
}
