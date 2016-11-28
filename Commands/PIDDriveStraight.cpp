
#include "PIDDriveStraight.h"
#include "../RobotMap.h"
#include <cmath>
PIDDriveStraight::PIDDriveStraight(double xdistance, double ydistance, double speed) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::chassis);

	m_xdistance=xdistance;
	m_ydistance=ydistance;
	m_speed=-speed;
	for(int i=0; i<5; i++){
		gyrorates.push_back(0.0);
	}
}

// Called just before this Command runs the first time
void PIDDriveStraight::Initialize() {
	xpos = 0;
	ypos = 0;
	angle=PI/2;
	Robot::chassis->ResetLeftEncoder();
	Robot::chassis->ResetRightEncoder();
	angleoffset=Robot::chassis->GetGyroAngle()-(PI/2);
	time.Start();
	timeb.Start();
	lasttime=0;
	lastleftencoder = Robot::chassis->GetAbsLeftEncoder();
	lastrightencoder = Robot::chassis->GetAbsRightEncoder();

	desiredangle = atan2(m_ydistance-ypos, m_xdistance-xpos);
	if(desiredangle<0){
		desiredangle=(PI*2)+desiredangle;
	}

	errorsimple = 0;
	errorsum = 0;
	errorchange = 0;
	turnrate = -(desiredangle-angle)/ (PI / 2);
	Robot::chassis->Set(0.0, 0.0);
	for(int i=0; i<gyrorates.size(); i++){
		gyrorates[i]=0;
	}
}

// Called repeatedly when this Command is scheduled to run
void PIDDriveStraight::Execute() {
		double currentleftencoder = Robot::chassis->GetAbsLeftEncoder();
		double currentrightencoder = Robot::chassis->GetAbsRightEncoder();
		double leftencoderchange = currentleftencoder - lastleftencoder;
		double rightencoderchange = currentrightencoder - lastrightencoder;
		double currenttime=time.Get();
		lastleftencoder = currentleftencoder;
		lastrightencoder = currentrightencoder;

		double leftdistance = Robot::oi->GetLeftCircumference()
				* leftencoderchange/Robot::oi->GetEncoder_CPR();
		double rightdistance = Robot::oi->GetRightCircumference()
				* rightencoderchange/Robot::oi->GetEncoder_CPR();
		double centerdistance = (leftdistance + rightdistance) / 2;
		xpos = xpos + (centerdistance * cos(angle));
		ypos = ypos + (centerdistance * sin(angle));


		double gyrorate=Robot::chassis->GetGyroRate()*(-PI/180)*Robot::oi->GetAngle_Correction();
		gyrorates.erase(gyrorates.begin());
		gyrorates.push_back(gyrorate);
		std::vector<double> sortedgyrorates=gyrorates;
		std::nth_element(sortedgyrorates.begin(),sortedgyrorates.begin()+(sortedgyrorates.size()/2), sortedgyrorates.begin()+sortedgyrorates.size());
		gyrorate= sortedgyrorates[sortedgyrorates.size()/2];

		Robot::chassis->SetGyroMedian(gyrorate);
		angle+=gyrorate*(currenttime-lasttime);
		angle=fmod(angle, 2*PI);
		//angle=(PI/2);
		Robot::chassis->SetAngle(angle);

		desiredangle = atan2(m_ydistance - ypos, m_xdistance - xpos);
		if(desiredangle<0){
			desiredangle=(PI*2)+desiredangle;
		}

		errorsimple = desiredangle - angle;
		errorsum = errorsum
				+ (errorsimple * (currenttime-lasttime));
		errorchange = (errorsimple - olderror)
				/ (currenttime-lasttime);

		olderror = errorsimple;
		lasttime=currenttime;

		turnrate = -Robot::chassis->PID(errorsimple, errorsum, errorchange)
				/ (PI / 2);

	Robot::chassis->SetArcadeDrive(m_speed,
			turnrate);
}

// Make this return true when this Command no longer needs to run execute()
bool PIDDriveStraight::IsFinished() {
	double distancefromgoal = sqrt((xpos - m_xdistance) * (xpos - m_xdistance)
								+ (ypos - m_ydistance) * (ypos - m_ydistance));
	return distancefromgoal <= 12;
}

// Called once after isFinished returns true
void PIDDriveStraight::End() {
	Robot::chassis->Set(0.0, 0.0);


	//last calculation
	double currentleftencoder = Robot::chassis->GetAbsLeftEncoder();
	double currentrightencoder = Robot::chassis->GetAbsRightEncoder();
	double leftencoderchange = currentleftencoder - lastleftencoder;
	double rightencoderchange = currentrightencoder - lastrightencoder;
	lastleftencoder = currentleftencoder;
	lastrightencoder = currentrightencoder;
	double leftdistance = Robot::oi->GetLeftCircumference()
			* leftencoderchange/Robot::oi->GetEncoder_CPR();
	double rightdistance = Robot::oi->GetRightCircumference()
			* rightencoderchange/Robot::oi->GetEncoder_CPR();
	double centerdistance = (leftdistance + rightdistance) / 2;
	xpos = xpos + (centerdistance * cos(angle));
	ypos = ypos + (centerdistance * sin(angle));
	//angle = angle + ((rightdistance - leftdistance) / TURNING_DIAMETER);
	angle=Robot::chassis->GetGyroAngle()-angleoffset;
	Robot::chassis->SetAngle(angle);
	Robot::chassis->SetXPos(xpos);
	Robot::chassis->SetYPos(ypos);
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDDriveStraight::Interrupted() {
	Robot::chassis->Set(0.0, 0.0);

	//last calculation
	double currentleftencoder = Robot::chassis->GetAbsLeftEncoder();
	double currentrightencoder = Robot::chassis->GetAbsRightEncoder();
	double leftencoderchange = currentleftencoder - lastleftencoder;
	double rightencoderchange = currentrightencoder - lastrightencoder;
	lastleftencoder = currentleftencoder;
	lastrightencoder = currentrightencoder;
	double leftdistance = Robot::oi->GetLeftCircumference()
			* leftencoderchange/Robot::oi->GetEncoder_CPR();
	double rightdistance = Robot::oi->GetRightCircumference()
			* rightencoderchange/Robot::oi->GetEncoder_CPR();
	double centerdistance = (leftdistance + rightdistance) / 2;
	xpos = xpos + (centerdistance * cos(angle));
	ypos = ypos + (centerdistance * sin(angle));
	//angle = angle + ((rightdistance - leftdistance) / TURNING_DIAMETER);
	angle=Robot::chassis->GetGyroAngle()-angleoffset;
	Robot::chassis->SetAngle(angle);
	Robot::chassis->SetXPos(xpos);
	Robot::chassis->SetYPos(ypos);
}
