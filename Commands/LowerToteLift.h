

#ifndef LOWERTOTELIFT_H
#define LOWERTOTELIFT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class LowerToteLift: public Command {
public:
	LowerToteLift();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
