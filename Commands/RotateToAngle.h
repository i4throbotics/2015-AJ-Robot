

#ifndef ROTATETOANGLE_H
#define ROTATETOANGLE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <string>
#include <vector>
#include <algorithm>
/**
 *
 *
 * @author ExampleAuthor
 */
class RotateToAngle: public Command {
private:
	bool turnLeft;
	double desiredangle;
	double lastleftencoder;
	double lastrightencoder;
	double xpos;
	double ypos;
	double angle;
	double crossed2pi;
	double lastangle;
	double rotatespeed;

	double currentangle;
	std::vector<double> gyrorates;
	Timer time;
	double currenttime;
	double lasttime;
public:
	RotateToAngle(double angle, bool left, double speed);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
