

#ifndef AUTOVOID_H
#define AUTOVOID_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <fstream>
#include <iostream>
/**
 *
 *
 * @author ExampleAuthor
 */
class AutoVoid: public Command {
public:
	AutoVoid();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
