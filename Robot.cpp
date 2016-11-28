

#include "Robot.h"
#include "Commands/Autonomous.h"

Chassis* Robot::chassis = 0;
ToteLift* Robot::toteLift = 0;
OI* Robot::oi = 0;
Printer* Robot::printer=0;
BinLift* Robot::binLift=0;
BinArms* Robot::binArms=0;


void Robot::RobotInit() {
	RobotMap::init();
	chassis = new Chassis();
	toteLift = new ToteLift();
	printer= new Printer();
	binLift=new BinLift();
	binArms=new BinArms();

	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();

	// instantiate the command used for the autonomous period
	autoChooser=new SendableChooser();
	autoChooser->AddDefault("1 Tote (No Step)", new Autonomous(TOTE_1_AUTONOSTEP));
	autoChooser->AddDefault("1 Tote (With Step)", new Autonomous(TOTE_1_AUTOSTEP));
	//autoChooser->AddObject("1 Bin (With Step)", new Autonomous(BIN_1_AUTOSTEP));
	//autoChooser->AddObject("1 Bin (No Step)", new Autonomous(BIN_1_AUTONOSTEP));
	//autoChooser->AddObject("Adjacent Tote and Bin", new Autonomous(ADJACENT_TB));
	//autoChooser->AddObject("NonAdjacent Tote and Bin", new Autonomous(NONADJACENT_TB));
	//autoChooser->AddObject("2 Bins (Diagonal)", new Autonomous(BIN_2_AUTO));
	//autoChooser->AddObject("2 Bins (U-Shaped Driving)", new Autonomous(BIN_2_AUTO_B));
	autoChooser->AddObject("LandFill Bins (No Drive, With Step)", new Autonomous(AUTO_BINS_LANDFILL_STEP));
	autoChooser->AddObject("LandFill Bins (No Drive, No Step)", new Autonomous(AUTO_BINS_LANDFILL_NOSTEP));
	autoChooser->AddObject("LandFill Bins (Drive Back, With Step)", new Autonomous(AUTO_BINS_ZONE_STEP));
	autoChooser->AddObject("LandFill Bins (Drive Back, No Step)", new Autonomous(AUTO_BINS_ZONE_NOSTEP));

	autoChooser->AddObject("DeadBot", new Autonomous(DEADBOT));
	autoChooser->AddObject("Drive Back", new Autonomous(AUTO_DRIVE_ONLY));
	SmartDashboard::PutData("Auto Program:", autoChooser);

	/**frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		//the camera name (ex "cam0") can be found through the roborio web interface
		imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
		if(imaqError != IMAQdxErrorSuccess) {
			DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
		}
		imaqError = IMAQdxConfigureGrab(session);
		if(imaqError != IMAQdxErrorSuccess) {
			DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
		}
		time.Start();
**/
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

	Robot::printer->CloseFile();
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommand = (Command*) autoChooser->GetSelected();
	//autonomousCommand= new AutoTote_O(130);
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	//fout.close();
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	/**if(time.HasPeriodPassed(0.067)){
		IMAQdxStartAcquisition(session);
			IMAQdxGrab(session, frame, false, NULL);
				if(imaqError != IMAQdxErrorSuccess) {
						DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
					} else {
						imaqResample(frame, frame, 320, 200,InterpolationMethod::IMAQ_ZERO_ORDER,{});

						CameraServer::GetInstance()->SetImage(frame);
					}
				IMAQdxStopAcquisition(session);
		}**/

}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

