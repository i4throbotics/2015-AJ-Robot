#ifndef TOGGLEBINARMS_H
#define TOGGLEBINARMS_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ToggleBinArms: public Command {
private:
	bool m_auto;
public:
	ToggleBinArms(bool auton);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
