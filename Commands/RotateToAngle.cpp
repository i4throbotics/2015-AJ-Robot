

#include "RotateToAngle.h"

RotateToAngle::RotateToAngle(double angle, bool left, double speed) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::chassis);

	desiredangle=angle;
	turnLeft=left;
	rotatespeed=speed;
	/**for(int i=0; i<5; i++){
			gyrorates.push_back(0.0);
		}**/
}

// Called just before this Command runs the first time
void RotateToAngle::Initialize() {
	desiredangle=desiredangle*(PI/180);
	Robot::chassis->ResetGyro();
	if(turnLeft){
			crossed2pi=desiredangle>(PI/2);
	}
	else{
		crossed2pi=desiredangle<(PI/2);
	}

	lastleftencoder=Robot::chassis->GetLeftEncoder();
	lastrightencoder=Robot::chassis->GetRightEncoder();
	xpos=Robot::chassis->GetXPos();
	ypos=Robot::chassis->GetYPos();
	lastangle=(PI/2);
	/**for(int i=0; i<gyrorates.size(); i++){
		gyrorates[i]=0;
	}**/
	lasttime=0.0;
	currentangle=Robot::chassis->GetGyroRotateAngle();
	lastangle=Robot::chassis->GetGyroRotateAngle();
}

// Called repeatedly when this Command is scheduled to run
void RotateToAngle::Execute() {
	currenttime=time.Get();
	currentangle=Robot::chassis->GetGyroRotateAngle();
	/**double gyrorate=Robot::chassis->GetGyroRate()*(-PI/180)*Robot::oi->GetAngle_Correction();
	gyrorates.erase(gyrorates.begin());
	gyrorates.push_back(gyrorate);
	std::vector<double> sortedgyrorates=gyrorates;
	std::nth_element(sortedgyrorates.begin(),sortedgyrorates.begin()+(sortedgyrorates.size()/2), sortedgyrorates.begin()+sortedgyrorates.size());
	gyrorate= sortedgyrorates[sortedgyrorates.size()/2];
	Robot::chassis->SetGyroMedian(gyrorate);**/

	/**currentangle+=gyrorate*(currenttime-lasttime);
	currentangle=fmod(currentangle, 2*PI);**/


	if(currentangle<0){
		currentangle=(currentangle+(2*PI));
	}
	Robot::chassis->SetAngle(currentangle);
	if(turnLeft){
		Robot::chassis->SetArcadeDrive(0, -rotatespeed);
		crossed2pi= crossed2pi || Robot::chassis->GetGyroRotateAngle()>PI && currentangle<PI;
	}
	else{
		Robot::chassis->SetArcadeDrive(0, rotatespeed);
		crossed2pi= crossed2pi || lastangle<PI && currentangle>PI;
	}


	double currentleftencoder = Robot::chassis->GetLeftEncoder();
	double currentrightencoder = Robot::chassis->GetRightEncoder();
	double leftencoderchange = currentleftencoder - lastleftencoder;
	double rightencoderchange = currentrightencoder - lastrightencoder;
	lastleftencoder = currentleftencoder;
	lastrightencoder = currentrightencoder;
	double leftdistance = Robot::oi->GetLeftCircumference()
			* leftencoderchange/Robot::oi->GetEncoder_CPR();
	double rightdistance = Robot::oi->GetRightCircumference()
			* rightencoderchange/Robot::oi->GetEncoder_CPR();
	double centerdistance = (leftdistance + rightdistance) / 2;
	xpos = xpos + (centerdistance * cos(lastangle));
	ypos = ypos + (centerdistance * sin(lastangle));



	lastangle=currentangle;
	lasttime=currenttime;
}

// Make this return true when this Command no longer needs to run execute()
bool RotateToAngle::IsFinished() {
	if(crossed2pi){
		if(turnLeft){
			return Robot::chassis->GetGyroRotateAngle()>=desiredangle;
		}
		else{
			return Robot::chassis->GetGyroRotateAngle()<=desiredangle;
		}
	}
	return false;
}

// Called once after isFinished returns true
void RotateToAngle::End() {
	Robot::chassis->SetArcadeDrive(0, 0);
	double currentleftencoder = Robot::chassis->GetLeftEncoder();
	double currentrightencoder = Robot::chassis->GetRightEncoder();
	double leftencoderchange = currentleftencoder - lastleftencoder;
	double rightencoderchange = currentrightencoder - lastrightencoder;
	lastleftencoder = currentleftencoder;
	lastrightencoder = currentrightencoder;
	double leftdistance = Robot::oi->GetLeftCircumference()
			* leftencoderchange/Robot::oi->GetEncoder_CPR();
	double rightdistance = Robot::oi->GetRightCircumference()
			* rightencoderchange/Robot::oi->GetEncoder_CPR();
	double centerdistance = (leftdistance + rightdistance) / 2;
	xpos = xpos + (centerdistance * cos(lastangle));
	ypos = ypos + (centerdistance * sin(lastangle));
	Robot::chassis->SetAngle(Robot::chassis->GetGyroAngle());
	Robot::chassis->SetXPos(xpos);
	Robot::chassis->SetYPos(ypos);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateToAngle::Interrupted() {
	Robot::chassis->SetArcadeDrive(0, 0);
	double currentleftencoder = Robot::chassis->GetLeftEncoder();
	double currentrightencoder = Robot::chassis->GetRightEncoder();
	double leftencoderchange = currentleftencoder - lastleftencoder;
	double rightencoderchange = currentrightencoder - lastrightencoder;
	lastleftencoder = currentleftencoder;
	lastrightencoder = currentrightencoder;
	double leftdistance = Robot::oi->GetLeftCircumference()
			* leftencoderchange/Robot::oi->GetEncoder_CPR();
	double rightdistance = Robot::oi->GetRightCircumference()
			* rightencoderchange/Robot::oi->GetEncoder_CPR();
	double centerdistance = (leftdistance + rightdistance) / 2;
	xpos = xpos + (centerdistance * cos(lastangle));
	ypos = ypos + (centerdistance * sin(lastangle));
	Robot::chassis->SetAngle(Robot::chassis->GetGyroAngle());
	Robot::chassis->SetXPos(xpos);
	Robot::chassis->SetYPos(ypos);
}
