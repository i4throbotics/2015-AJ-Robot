

#include "DropTote.h"
#include "../RobotMap.h"

DropTote::DropTote() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::toteLift);
}

// Called just before this Command runs the first time
void DropTote::Initialize() {
	Robot::toteLift->LiftDown();
	Robot::toteLift->SetWasLiftManual(false);
	if(!Robot::toteLift->GetWasLiftManual()){
		if(Robot::toteLift->GetLiftPosition()==3){
			desired= Robot::oi->GetTote_2_Encoder_Height();
			Robot::toteLift->SetLiftPosition(2);
		}
		else if(Robot::toteLift->GetLiftPosition()==2){
			desired = Robot::oi->GetTote_1_Encoder_Height();
			Robot::toteLift->SetLiftPosition(1);
		}
		else {
			desired =0;
			Robot::toteLift->SetLiftPosition(0);
		}


	}
	else{
		if(Robot::toteLift->GetLiftEncoder()>Robot::oi->GetTote_3_Encoder_Height()){
			desired=Robot::oi->GetTote_3_Encoder_Height();
			Robot::toteLift->SetLiftPosition(3);
		}
		else if(Robot::toteLift->GetLiftEncoder()>Robot::oi->GetTote_2_Encoder_Height()+10){
			desired=Robot::oi->GetTote_2_Encoder_Height();
			Robot::toteLift->SetLiftPosition(2);
		}
		else if(Robot::toteLift->GetLiftEncoder()>Robot::oi->GetTote_1_Encoder_Height()+10){
			desired=Robot::oi->GetTote_1_Encoder_Height();
			Robot::toteLift->SetLiftPosition(1);
		}
		else{
			desired=0;
			Robot::toteLift->SetLiftPosition(0);
		}
	}

}

// Called repeatedly when this Command is scheduled to run
void DropTote::Execute() {
	Robot::toteLift->LiftDown();
}

// Make this return true when this Command no longer needs to run execute()
bool DropTote::IsFinished() {
	if(Robot::toteLift->GetLiftEncoder()<=0){
		return true;
	}
	return Robot::toteLift->GetLiftEncoder() <= desired;
}

// Called once after isFinished returns true
void DropTote::End() {
	Robot::toteLift->LiftStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DropTote::Interrupted() {
}
