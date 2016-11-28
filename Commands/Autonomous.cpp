#include "Autonomous.h"
#include "../RobotMap.h"
#include "PrintData.h"
#include "AutoTote.h"
#include "AutoVoid.h"
#include "PIDDriveStraight.h"
#include "RotateToAngle.h"
#include "AutoBinArms.h"
Autonomous::Autonomous(int selection)
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
	AddParallel(new PrintData());
	if(selection==TOTE_1_AUTOSTEP)
		AddSequential(new AutoTote(true));
	else if(selection==TOTE_1_AUTONOSTEP)
		AddSequential(new AutoTote(false));
	else if(selection==DEADBOT)
		AddSequential(new AutoVoid());
	else if(selection==AUTO_BINS_LANDFILL_STEP)
		AddSequential(new AutoBinArms(false, true));
	else if(selection==AUTO_BINS_LANDFILL_NOSTEP)
		AddSequential(new AutoBinArms(false, false));
	else if(selection==AUTO_BINS_ZONE_STEP)
		AddSequential(new AutoBinArms(true, true));
	else if(selection==AUTO_BINS_ZONE_NOSTEP)
		AddSequential(new AutoBinArms(true, false));
	else if(selection==AUTO_DRIVE_ONLY){
		AddSequential(new PIDDriveStraight(0, 72, -0.8));
		AddSequential(new RotateToAngle(180, true, 0.6));

	}
}
