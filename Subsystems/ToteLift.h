

#ifndef TOTELIFT_H
#define TOTELIFT_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ToteLift: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	bool WasLiftManual;
	int LiftPosition;
	bool IsBoardUp;
	bool FinishedAutoLifting;
	int NumberOfFlips;
	int EncoderOffset;
public:
	SpeedController* liftMotor;
	Compressor* toteBoardCompressor;
	DoubleSolenoid* leftSolenoid;
	DoubleSolenoid* rightSolenoid;
	Encoder* liftEncoder;

	ToteLift();
	void InitDefaultCommand();
;

	void ToteBoardUp();
	void ToteBoardDown();
	void ToteBoardStop();

	bool GetIsBoardUp();
	void SetIsBoardUp(bool state);

	int GetLiftEncoder();
	void SetEncoderOffset(int offset);

	void ResetLiftEncoder();
	void LiftUp();
	void LiftDown();
	void LiftStop();


	void ManualMoveLift(Joystick *stick);
	bool GetWasLiftManual();
	void SetWasLiftManual(bool state);

	void SetLiftPosition(int position);
	int GetLiftPosition();

	void SetFinishedAutoLifting(bool state);
	bool GetFinishedAutoLifting();

	int GetNumberOfFlips();
	void SetNumberOfFlips(int num);
};

#endif
