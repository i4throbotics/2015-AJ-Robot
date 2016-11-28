#include "AutoBinArms.h"
#include "ToggleBinArms.h"
#include "PIDDriveStraight.h"
#include "RotateToAngle.h"
AutoBinArms::AutoBinArms(bool fulldist, bool step)
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	AddSequential(new ToggleBinArms(true));
	if(step){
		AddSequential(new PIDDriveStraight(0, 49, 1.0));
	}
	else{

		AddSequential(new PIDDriveStraight(0, 44, 1.0));
	}
	if(fulldist){
		AddSequential(new PIDDriveStraight(0, 72, 0.75));
		//AddSequential(new ToggleBinArms(true));
		if(step){
			//AddSequential(new RotateToAngle(359, false, 0.5));
		}
		else{
			//AddSequential(new RotateToAngle(180, true, 0.5));
		}
	}
	/**else{
		AddSequential(new ToggleBinArms(false));
	}**/

}
