
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"



SpeedController* RobotMap::chassisfrontLeft = NULL;
SpeedController* RobotMap::chassisbackLeft = NULL;
SpeedController* RobotMap::chassisfrontRight = NULL;
SpeedController* RobotMap::chassisbackRight = NULL;
RobotDrive* RobotMap::chassischassisDrive = NULL;
Servo* RobotMap::chassisleftServo = NULL;
Servo* RobotMap::chassisrightServo = NULL;
Encoder* RobotMap::chassisleftEncoder = NULL;
Encoder* RobotMap::chassisrightEncoder = NULL;
Gyro* RobotMap::chassisgyro = NULL;



SpeedController* RobotMap::toteLiftliftMotor = NULL;
Compressor* RobotMap::toteLifttoteBoardCompressor = NULL;
DoubleSolenoid* RobotMap::toteLiftleftSolenoid = NULL;
DoubleSolenoid* RobotMap::toteLiftrightSolenoid = NULL;
Encoder* RobotMap::toteLiftliftEncoder = NULL;


CANTalon* RobotMap::binLiftMotor= NULL;
Encoder* RobotMap::binLiftLiftEncoder= NULL;

DoubleSolenoid* RobotMap::binArmsleftSolenoid = NULL;
DoubleSolenoid* RobotMap::binArmsrightSolenoid = NULL;
void RobotMap::init() {


	LiveWindow* lw = LiveWindow::GetInstance();

	chassisfrontLeft = new Talon(0);
	lw->AddActuator("Chassis", "frontLeft", (Talon*) chassisfrontLeft);
	
	chassisbackLeft = new Talon(1);
	lw->AddActuator("Chassis", "backLeft", (Talon*) chassisbackLeft);
	
	chassisfrontRight = new Talon(2);
	lw->AddActuator("Chassis", "frontRight", (Talon*) chassisfrontRight);
	
	chassisbackRight = new Talon(3);
	lw->AddActuator("Chassis", "backRight", (Talon*) chassisbackRight);
	
	chassischassisDrive = new RobotDrive(chassisfrontLeft, chassisbackLeft,
              chassisfrontRight, chassisbackRight);
	
	chassischassisDrive->SetSafetyEnabled(true);
        chassischassisDrive->SetExpiration(0.1);
        chassischassisDrive->SetSensitivity(0.5);
        chassischassisDrive->SetMaxOutput(1.0);

	chassisleftServo = new Servo(4);
	lw->AddActuator("Chassis", "leftServo", chassisleftServo);
	
	chassisrightServo = new Servo(5);
	lw->AddActuator("Chassis", "rightServo", chassisrightServo);
	
	chassisleftEncoder = new Encoder(0, 1, false, Encoder::k4X);
	lw->AddSensor("Chassis", "leftEncoder", chassisleftEncoder);
	chassisleftEncoder->SetDistancePerPulse(1.0);
        chassisleftEncoder->SetPIDSourceParameter(Encoder::kRate);
	chassisrightEncoder = new Encoder(2, 3, false, Encoder::k4X);
	lw->AddSensor("Chassis", "rightEncoder", chassisrightEncoder);
	chassisrightEncoder->SetDistancePerPulse(1.0);
        chassisrightEncoder->SetPIDSourceParameter(Encoder::kRate);
	chassisgyro = new Gyro(1);
	lw->AddSensor("Chassis", "gyro", chassisgyro);
	chassisgyro->SetSensitivity(0.007);
	
	toteLiftliftMotor = new TalonSRX(8);
	lw->AddActuator("ToteLift", "liftMotor", (TalonSRX*) toteLiftliftMotor);
	
	toteLifttoteBoardCompressor = new Compressor(7);
	
	
	toteLiftleftSolenoid = new DoubleSolenoid(7, 0, 1);      
	lw->AddActuator("ToteLift", "leftSolenoid", toteLiftleftSolenoid);
	
	toteLiftrightSolenoid = new DoubleSolenoid(7, 2, 3);      
	lw->AddActuator("ToteLift", "rightSolenoid", toteLiftrightSolenoid);
	
	toteLiftliftEncoder = new Encoder(6, 7, false, Encoder::k4X);
	lw->AddSensor("ToteLift", "liftEncoder", toteLiftliftEncoder);
	toteLiftliftEncoder->SetDistancePerPulse(1.0);
        toteLiftliftEncoder->SetPIDSourceParameter(Encoder::kRate);



	binLiftMotor = new CANTalon(2);
	binLiftLiftEncoder=new Encoder(4, 5, true, Encoder::k4X);

	binArmsleftSolenoid = new DoubleSolenoid(7, 4, 5);

		binArmsrightSolenoid = new DoubleSolenoid(7, 6, 7);


}
