

#ifndef LIFTTOTE_H
#define LIFTTOTE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class LiftTote: public Command {
private:
	int desired;
public:
	LiftTote();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
