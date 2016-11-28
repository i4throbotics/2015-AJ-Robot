

#include "PrintData.h"

PrintData::PrintData() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::printer);

}

// Called just before this Command runs the first time
void PrintData::Initialize() {
	Robot::printer->OpenFile();
}

// Called repeatedly when this Command is scheduled to run
void PrintData::Execute() {
	Robot::printer->Print(TimeSinceInitialized());
	if(Robot::chassis->GetIsChassisNormal()){
				SmartDashboard::PutString("Chassis Front", "FRONT: TOTES");
			}
			else{
				SmartDashboard::PutString("Chassis Front", "FRONT: BINS");
			}

			if(Robot::chassis->GetIsHighGear()){
				SmartDashboard::PutString("Chassis Gear", "FAST");
			}
			else{
				SmartDashboard::PutString("Chassis Gear", "SLOW");
			}
			SmartDashboard::PutNumber("Flip Toggled", Robot::toteLift->GetNumberOfFlips());
			SmartDashboard::PutNumber("Tote Lift Encoder", Robot::toteLift->GetLiftEncoder());
			SmartDashboard::PutNumber("Chassis Right Encoder",Robot::chassis->GetRightEncoder());
			SmartDashboard::PutNumber("Chassis Left Encoder", Robot::chassis->GetLeftEncoder());
			SmartDashboard::PutNumber("Gyro Rate", RobotMap::chassisgyro->GetRate());
			SmartDashboard::PutNumber("Gyro Angle", RobotMap::chassisgyro->GetAngle());
			SmartDashboard::PutNumber("Bin Lift Encoder", Robot::binLift->GetEncoder());
}

// Make this return true when this Command no longer needs to run execute()
bool PrintData::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PrintData::End() {
	Robot::printer->CloseFile();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrintData::Interrupted() {
	Robot::printer->CloseFile();
}
