#include "AutoVoid.h"

AutoVoid::AutoVoid()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void AutoVoid::Initialize()
{
	Robot::printer->OpenFile();
}

// Called repeatedly when this Command is scheduled to run
void AutoVoid::Execute()
{
	Robot::printer->Print(TimeSinceInitialized());

}

// Make this return true when this Command no longer needs to run execute()
bool AutoVoid::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoVoid::End()
{
	Robot::printer->CloseFile();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoVoid::Interrupted()
{
	Robot::printer->CloseFile();

}
