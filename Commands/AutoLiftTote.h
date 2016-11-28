

#ifndef AUTOLIFTTOTE_H
#define AUTOLIFTTOTE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutoLiftTote: public Command {
private:
	int m_desired;
public:
	AutoLiftTote(int desired);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
