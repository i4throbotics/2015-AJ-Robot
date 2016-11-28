

#ifndef PIDDRIVESTRAIGHT_H
#define PIDDRIVESTRAIGHT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/**
 *
 *
 * @author ExampleAuthor
 */
class PIDDriveStraight: public Command {
private:
	double ratio;
	int lastleftencoder;
	int lastrightencoder;
	std::ofstream fout;
	std::ofstream foutb;
	double angle; //radians
	Timer time;
	Timer timeb;
	double xpos;
	double ypos;
	double desiredangle;
	double errorsimple;
	double errorsum;
	double errorchange;
	double olderror;
	double turnrate;
	double drivedistance;
	double m_xdistance;
	double m_ydistance;
	double m_speed;
	double leftspeed;
	double rightspeed;
	double encoderangle;
	double accelerometerangle;
	double filteredangle;
	double forwardaccel;
	double horizontalaccel;
	double gyroangle;
	double lasttime;
	double angleoffset;

	std::vector<double> gyrorates;
public:
	PIDDriveStraight(double xdistance, double ydistance, double speed);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
