
#ifndef FLIPCHASSIS_H
#define FLIPCHASSIS_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class FlipChassis: public Command {
public:
	FlipChassis();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
