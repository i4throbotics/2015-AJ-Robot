#ifndef SetEncoderOffset_H
#define SetEncoderOffset_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class SetEncoderOffset: public Command
{
private:
	int m_offset;
public:
	SetEncoderOffset(int offset);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
