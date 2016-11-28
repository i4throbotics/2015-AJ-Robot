

#ifndef TOGGLETOTEBOARD_H
#define TOGGLETOTEBOARD_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ToggleToteBoard: public Command {
public:
	ToggleToteBoard();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
