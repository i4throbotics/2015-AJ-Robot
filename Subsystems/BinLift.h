#ifndef BINLIFT_H
#define BINLIFT_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BinLift: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* liftMotor;
	Encoder* liftEncoder;
public:
	BinLift();
	void InitDefaultCommand();
	void SetSpeed(double speed);
	int GetEncoder();
};

#endif
