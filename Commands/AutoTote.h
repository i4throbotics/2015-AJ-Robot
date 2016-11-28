#ifndef AutoTote_H
#define AutoTote_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoTote: public CommandGroup
{
public:
	AutoTote(bool overstep);
/**	virtual void Execute();
	virtual void Initialize();
	virtual void Interrupted();**/
};

#endif
