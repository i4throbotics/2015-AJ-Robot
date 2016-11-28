

#include "LiftTote.h"
#include "../RobotMap.h"

LiftTote::LiftTote() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::toteLift);
}

// Called just before this Command runs the first time
void LiftTote::Initialize() {
	Robot::toteLift->LiftUp();
	if(!Robot::toteLift->GetWasLiftManual()){
		if(Robot::toteLift->GetLiftPosition()==0){
			desired= Robot::oi->GetTote_1_Encoder_Height();
			Robot::toteLift->SetLiftPosition(1);
		}
		else if(Robot::toteLift->GetLiftPosition()==1){
			desired = Robot::oi->GetTote_2_Encoder_Height();
			Robot::toteLift->SetLiftPosition(2);
		}
		else {
			desired =Robot::oi->GetTote_3_Encoder_Height();
			Robot::toteLift->SetLiftPosition(3);
		}


	}
	else{
		if(Robot::toteLift->GetLiftEncoder()<0){
			desired=0;
			Robot::toteLift->SetLiftPosition(0);
		}
		else if(Robot::toteLift->GetLiftEncoder()<Robot::oi->GetTote_1_Encoder_Height()-10){
			desired=Robot::oi->GetTote_1_Encoder_Height();
			Robot::toteLift->SetLiftPosition(1);
		}
		else if(Robot::toteLift->GetLiftEncoder()<Robot::oi->GetTote_2_Encoder_Height()-10){
			desired=Robot::oi->GetTote_2_Encoder_Height();
			Robot::toteLift->SetLiftPosition(2);
		}
		else {
				desired=Robot::oi->GetTote_3_Encoder_Height();
				Robot::toteLift->SetLiftPosition(3);
			}
	}
	Robot::toteLift->SetWasLiftManual(false);

}

// Called repeatedly when this Command is scheduled to run
void LiftTote::Execute() {
	Robot::toteLift->LiftUp();
}

// Make this return true when this Command no longer needs to run execute()
bool LiftTote::IsFinished() {
	if(Robot::toteLift->GetLiftEncoder()>= Robot::oi->GetTote_3_Encoder_Height()){
		return true;
	}

	return Robot::toteLift->GetLiftEncoder() >= desired;
}

// Called once after isFinished returns true
void LiftTote::End() {
	Robot::toteLift->LiftStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftTote::Interrupted() {
}
