



#include "Chassis.h"
#include "../RobotMap.h"
#include "../Commands/DriveWithJoystick.h"

Chassis::Chassis() : Subsystem("Chassis") {
	frontLeft = RobotMap::chassisfrontLeft;
	backLeft = RobotMap::chassisbackLeft;
	frontRight = RobotMap::chassisfrontRight;
	backRight = RobotMap::chassisbackRight;
	chassisDrive = RobotMap::chassischassisDrive;
	leftServo = RobotMap::chassisleftServo;
	rightServo = RobotMap::chassisrightServo;
	leftEncoder = RobotMap::chassisleftEncoder;
	rightEncoder = RobotMap::chassisrightEncoder;
	gyro = RobotMap::chassisgyro;

	gyro->Reset();
	/**leftServo->Set(1.0);//low gear
	rightServo->Set(1.0);//low gear**/
	rightEncoder->Reset();
	leftEncoder->Reset();
	Angle=PI/2;
	XPos=0;
	YPos=0;
	IsChassisNormal=true;
	GyroMedian=0;
}
    
void Chassis::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveWithJoystick());

}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Chassis::ArcadeDrive(Joystick* stick, bool normal){
	if(normal){
	chassisDrive->ArcadeDrive(0.85*stick->GetY(), 0.85*stick->GetX());
	}
	else{
		chassisDrive->ArcadeDrive(-0.85*stick->GetY(), 0.85*stick->GetX());
	}
}
void Chassis::SetLeftServo(float state){
	//leftServo->Set(state);
}
void Chassis::SetRightServo(float state){
	//rightServo->Set(state);
}

int Chassis::GetLeftEncoder(){
	return -leftEncoder->Get();
}
int Chassis::GetRightEncoder(){
	return rightEncoder->Get();
}
int Chassis::GetAbsRightEncoder(){
	return abs(rightEncoder->Get());
}
int Chassis::GetAbsLeftEncoder(){
	return abs(leftEncoder->Get());
}
void Chassis::ResetLeftEncoder(){
	leftEncoder->Reset();
}
void Chassis::ResetRightEncoder(){
	rightEncoder->Reset();
}
void Chassis::Set(double leftspeed, double rightspeed){
	chassisDrive->SetLeftRightMotorOutputs(leftspeed, rightspeed);
}
double Chassis::PID(double errorsimple, double errorsum, double errorchange){
	return (Robot::oi->GetKp()*errorsimple)+(Robot::oi->GetKi()*errorsum)+(Robot::oi->GetKd()*errorchange);
}

void Chassis::SetArcadeDrive(double speed, double curve){
	chassisDrive->ArcadeDrive(speed, curve, false);
}
double Chassis::GetAngle(){
	return Angle;
}
void Chassis::SetAngle(double angle){
	Angle=angle;
}
double Chassis::GetXPos(){
	return XPos;
}
void Chassis::SetXPos(double xpos){
	XPos=xpos;
}
double Chassis::GetYPos(){
	return YPos;
}
void Chassis::SetYPos(double ypos){
	YPos=ypos;
}
double Chassis::GetGyroRate(){
	return gyro->GetRate()-0.0346;
}
double Chassis::GetGyroRotateAngle(){
	double rawangle=fmod((gyro->GetAngle()*-PI/180)*Robot::oi->GetAngle_Correction() +(PI/2), 2*PI);
	if(rawangle<0){
		return rawangle+ (PI*2);
	}
	return rawangle;
}
double Chassis::GetGyroAngle(){
	return fmod((gyro->GetAngle()*-PI/180)*Robot::oi->GetAngle_Correction() +(PI/2), 2*PI);
}
void Chassis::ResetGyro(){
	gyro->Reset();
}
bool Chassis::GetIsChassisNormal(){
	return IsChassisNormal;
}
void Chassis::SetIsChassisNormal(bool state){
	IsChassisNormal=state;
}
void Chassis::SetIsHighGear(bool state){
	IsHighGear=state;
}
bool Chassis::GetIsHighGear(){
	return IsHighGear;
}
void Chassis::SetGyroMedian(double median){
	GyroMedian=median;
}
double Chassis::GetGyroMedian(){
	return GyroMedian;
}
