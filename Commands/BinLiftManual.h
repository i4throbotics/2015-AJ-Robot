#ifndef BinLiftManual_H
#define BinLiftManual_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class BinLiftManual: public Command
{
public:
	BinLiftManual();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif
