

#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#define PI 3.14159265

#define TOTE_1_AUTOSTEP 0
#define TOTE_1_AUTONOSTEP 1
#define DEADBOT 2
#define AUTO_DRIVE_ONLY 3
#define AUTO_BINS_LANDFILL_STEP 4
#define AUTO_BINS_LANDFILL_NOSTEP 5
#define AUTO_BINS_ZONE_STEP 6
#define AUTO_BINS_ZONE_NOSTEP 7

#define NORMAL_AUTO_TOTE 420
#define LOW_BIN 1250

#define PINCERS_TIME 5//seconds

#define LEFT_TALON_DEVICE_ID 2
#define RIGHT_TALON_DEVICE_ID 3
#include "WPILib.h"



/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	static SpeedController* chassisfrontLeft;
	static SpeedController* chassisbackLeft;
	static SpeedController* chassisfrontRight;
	static SpeedController* chassisbackRight;
	static RobotDrive* chassischassisDrive;
	static Servo* chassisleftServo;
	static Servo* chassisrightServo;
	static Encoder* chassisleftEncoder;
	static Encoder* chassisrightEncoder;
	static Gyro* chassisgyro;


	static SpeedController* toteLiftliftMotor;
	static Compressor* toteLifttoteBoardCompressor;
	static DoubleSolenoid* toteLiftleftSolenoid;
	static DoubleSolenoid* toteLiftrightSolenoid;
	static Encoder* toteLiftliftEncoder;


	static CANTalon* binLiftMotor;
	static Encoder* binLiftLiftEncoder;

	static DoubleSolenoid* binArmsleftSolenoid;
	static DoubleSolenoid* binArmsrightSolenoid;
	static void init();
};
#endif
