

#ifndef DROPALLTOTES_H
#define DROPALLTOTES_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DropAllTotes: public Command {
public:
	DropAllTotes();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
