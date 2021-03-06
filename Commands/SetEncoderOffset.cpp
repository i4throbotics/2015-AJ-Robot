#include "SetEncoderOffset.h"

SetEncoderOffset::SetEncoderOffset(int offset)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	m_offset=offset;
}

// Called just before this Command runs the first time
void SetEncoderOffset::Initialize()
{

	Robot::toteLift->SetEncoderOffset(m_offset);
}

// Called repeatedly when this Command is scheduled to run
void SetEncoderOffset::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetEncoderOffset::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetEncoderOffset::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetEncoderOffset::Interrupted()
{

}
