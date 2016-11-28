

#ifndef DRIVEWITHJOYSTICK_H
#define DRIVEWITHJOYSTICK_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <fstream>
#include <iostream>
/**
 *
 *
 * @author ExampleAuthor
 */
class DriveWithJoystick: public Command {
public:
	DriveWithJoystick();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
