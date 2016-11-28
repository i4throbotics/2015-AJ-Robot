#ifndef BinArms_H
#define BinArms_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BinArms: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DoubleSolenoid* leftSolenoid;
	DoubleSolenoid* rightSolenoid;
	bool AreArmsUp;
public:
	BinArms();
	void InitDefaultCommand();
	void BinArmsUp();
	void BinArmsDown();
	void SetAreArmsUp(bool state);
	bool GetAreArmsUp();
};

#endif
