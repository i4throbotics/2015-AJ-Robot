

#ifndef RAISETOTELIFT_H
#define RAISETOTELIFT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class RaiseToteLift: public Command {
public:
	RaiseToteLift();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
