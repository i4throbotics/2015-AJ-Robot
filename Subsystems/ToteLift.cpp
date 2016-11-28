



#include "ToteLift.h"
#include "../RobotMap.h"

ToteLift::ToteLift() : Subsystem("ToteLift") {
	liftMotor = RobotMap::toteLiftliftMotor;
	toteBoardCompressor = RobotMap::toteLifttoteBoardCompressor;
	leftSolenoid = RobotMap::toteLiftleftSolenoid;
	rightSolenoid = RobotMap::toteLiftrightSolenoid;
	liftEncoder = RobotMap::toteLiftliftEncoder;

	liftEncoder->Reset();
	WasLiftManual=false;
	LiftPosition=0;
	IsBoardUp=true;
	FinishedAutoLifting=false;
	NumberOfFlips=0;
	EncoderOffset=0;
}
    
void ToteLift::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void ToteLift::ToteBoardUp(){
	leftSolenoid->Set(DoubleSolenoid::kForward);
	rightSolenoid->Set(DoubleSolenoid::kForward);
}
void ToteLift::ToteBoardDown(){
	leftSolenoid->Set(DoubleSolenoid::kReverse);
	rightSolenoid->Set(DoubleSolenoid::kReverse);
}
void ToteLift::ToteBoardStop(){
	leftSolenoid->Set(DoubleSolenoid::kOff);
	rightSolenoid->Set(DoubleSolenoid::kOff);
}

bool ToteLift::GetIsBoardUp(){
	return IsBoardUp;
}
void ToteLift::SetIsBoardUp(bool state){
	IsBoardUp=state;
}
int ToteLift::GetLiftEncoder(){
	return liftEncoder->Get()+EncoderOffset;
}
void ToteLift::ResetLiftEncoder(){
	liftEncoder->Reset();
}
void ToteLift::LiftUp(){
	liftMotor->Set(0.8);
}

void ToteLift::LiftDown(){
	liftMotor->Set(-0.57);
}

void ToteLift::LiftStop(){
	liftMotor->Set(0.0);
}



void ToteLift::ManualMoveLift(Joystick *stick) {
	//liftMotor->Set(-stick->GetRawAxis(3));
}
bool ToteLift::GetWasLiftManual(){
	return WasLiftManual;
}
void ToteLift::SetWasLiftManual(bool state){
	WasLiftManual=state;
}
void ToteLift::SetLiftPosition(int position){
	LiftPosition=position;
}
int ToteLift::GetLiftPosition(){
	return LiftPosition;
}
void ToteLift::SetFinishedAutoLifting(bool state){
	FinishedAutoLifting=state;
}
bool ToteLift::GetFinishedAutoLifting(){
	return FinishedAutoLifting;
}
int ToteLift::GetNumberOfFlips(){
	return NumberOfFlips;
}
void ToteLift::SetNumberOfFlips(int num){
	NumberOfFlips=num;
}

void ToteLift::SetEncoderOffset(int offset){
	EncoderOffset=offset;
}
