

#ifndef PRINTDATA_H
#define PRINTDATA_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <fstream>
#include <iostream>
#include <string>
/**
 *
 *
 * @author ExampleAuthor
 */
class PrintData: public Command {
private:
	std::ofstream fout;

public:
	PrintData();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
