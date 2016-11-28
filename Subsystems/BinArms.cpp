#include "BinArms.h"
#include "../RobotMap.h"

BinArms::BinArms() :
		Subsystem("BinArms")
{
	leftSolenoid = RobotMap::binArmsleftSolenoid;
	rightSolenoid = RobotMap::binArmsrightSolenoid;

	AreArmsUp=true;
}

void BinArms::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void BinArms::BinArmsUp(){
	leftSolenoid->Set(DoubleSolenoid::kForward);
	rightSolenoid->Set(DoubleSolenoid::kForward);
}
void BinArms::BinArmsDown(){
	leftSolenoid->Set(DoubleSolenoid::kReverse);
	rightSolenoid->Set(DoubleSolenoid::kReverse);
}

bool BinArms::GetAreArmsUp(){
	return AreArmsUp;
}
void BinArms::SetAreArmsUp(bool state){
	AreArmsUp=state;
}
