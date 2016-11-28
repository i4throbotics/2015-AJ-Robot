#include "BinLift.h"
#include "../RobotMap.h"
#include "../Commands/BinLiftManual.h"
BinLift::BinLift() :Subsystem("BinLift")
{
	liftMotor= RobotMap::binLiftMotor;
	liftEncoder= RobotMap::binLiftLiftEncoder;
}

void BinLift::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new BinLiftManual());

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void BinLift::SetSpeed(double speed){
	liftMotor->Set(speed*-0.5);
}
int BinLift::GetEncoder(){
	return liftEncoder->Get();
}
