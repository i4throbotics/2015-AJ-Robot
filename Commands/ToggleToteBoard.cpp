

#include "ToggleToteBoard.h"

ToggleToteBoard::ToggleToteBoard() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	//Requires(Robot::toteLift);

}

// Called just before this Command runs the first time
void ToggleToteBoard::Initialize() {
	if(Robot::toteLift->GetIsBoardUp()){
		Robot::toteLift->ToteBoardDown();
		Robot::toteLift->SetIsBoardUp(false);
	}
	else{
		Robot::toteLift->ToteBoardUp();
		Robot::toteLift->SetIsBoardUp(true);
	}
	Robot::toteLift->SetNumberOfFlips(Robot::toteLift->GetNumberOfFlips()+1);
}

// Called repeatedly when this Command is scheduled to run
void ToggleToteBoard::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleToteBoard::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleToteBoard::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleToteBoard::Interrupted() {
}
