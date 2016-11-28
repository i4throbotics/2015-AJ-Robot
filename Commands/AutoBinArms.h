#ifndef AutoBinArms_H
#define AutoBinArms_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoBinArms: public CommandGroup
{
public:
	AutoBinArms(bool fulldist, bool step);
};

#endif
