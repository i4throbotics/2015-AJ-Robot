

#ifndef CHASSIS_H
#define CHASSIS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Chassis: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	double Angle;
	double XPos;
	double YPos;
	bool IsChassisNormal;
	bool IsHighGear;
	double GyroMedian;
public:
	SpeedController* frontLeft;
	SpeedController* backLeft;
	SpeedController* frontRight;
	SpeedController* backRight;
	RobotDrive* chassisDrive;
	Servo* leftServo;
	Servo* rightServo;
	Encoder* leftEncoder;
	Encoder* rightEncoder;
	Gyro* gyro;

	Chassis();
	void InitDefaultCommand();
	void ArcadeDrive(Joystick* stick, bool normal);
	void SetLeftServo(float state);
	void SetRightServo(float state);
	int GetLeftEncoder();
	int GetRightEncoder();
	void ResetLeftEncoder();
	void ResetRightEncoder();
	void Set(double leftspeed, double rightspeed);
	double PID(double errorsimple, double errorsum, double errorchange);
	void SetArcadeDrive(double speed, double curve);
	double GetAngle();
	void SetAngle(double angle);
	double GetYPos();
	void SetYPos(double ypos);
	double GetXPos();
	void SetXPos(double xpos);
	double GetGyroRate();
	double GetGyroAngle();
	double GetGyroRotateAngle();
	void ResetGyro();
	int GetAbsRightEncoder();
	int GetAbsLeftEncoder();
	bool GetIsChassisNormal();
	void SetIsChassisNormal(bool state);
	bool GetIsHighGear();
	void SetIsHighGear(bool state);

	void SetGyroMedian(double median);
	double GetGyroMedian();
};

#endif
