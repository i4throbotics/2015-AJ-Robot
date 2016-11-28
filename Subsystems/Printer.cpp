



#include "Printer.h"
#include "../RobotMap.h"
#include "../Commands/PrintData.h"

Printer::Printer() : Subsystem("Printer") {
	fin.open("/home/lvuser/RoboJoe3.0Preferences.txt");
			std::string inputstring;

			fin>>inputstring>>inputstring
			>>inputstring>>inputstring
			>>inputstring>>inputstring
			>>inputstring>>inputstring
			>>inputstring>>inputstring
			>>inputstring>>inputstring
			>>inputstring>>inputstring
			>>inputstring>>inputstring
			>>inputstring>>inputstring
			>>inputstring>>inputstring
			>>inputstring>>inputstring
			>>inputstring>>inputstring
			>>inputstring>>RunPrintData
			;
	fin.close();

}

void Printer::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
		SetDefaultCommand(new PrintData());

}


// Put methods for controlling this subsystem
// here. Call these from Commands.

bool Printer::GetRunPrintData(){
	return RunPrintData;
}
void Printer::Print(double time){
	if(RunPrintData){
	fout<<time
				<<" "<<Robot::chassis->GetLeftEncoder()
				<<" "<<Robot::chassis->GetRightEncoder()
				<<" "<<Robot::chassis->GetGyroRotateAngle()//gyro_rotate_angle****
				<<" "<<Robot::chassis->GetGyroAngle()//gyro_normal_angle
				<<" "<<Robot::chassis->gyro->GetAngle()//gyro_raw_angle
				<<" "<<Robot::chassis->gyro->GetRate()//gyro_rate
				<<" "<<Robot::chassis->GetAngle()//gyro_calculated_angle***
				<<" "<<Robot::chassis->GetGyroMedian()//Gyro_median
				<<" "<<Robot::chassis->GetIsChassisNormal()
				<<" "<<Robot::chassis->GetIsHighGear()
				<<" "<<Robot::toteLift->GetLiftEncoder()
				<<" "<<Robot::toteLift->GetIsBoardUp()
				<<std::endl;
	}
}
void Printer::CloseFile(){
	if(RunPrintData && fout.is_open()){
	fout.close();
	}

}
void Printer::OpenFile(){
	if(RunPrintData){
		//open fout @ correct file

		int filenumber=0;
		std::string filename;
		do{
			filename="/home/lvuser/SensorDataFiles/LATest3SensorData"+std::to_string(filenumber);
			filenumber++;
		}while(std::ifstream(filename.c_str()));
		fout.open(filename.c_str());
		SmartDashboard::PutString("printing data", filename.c_str());
		fout<<"#time Left_Chassis_Encoder Right_Chassis_Encoder Gyro_Rotate_Angle Gyro_Normal_Angle Gyro_Raw_Angle Gyro_Rate Gyro_Calculated_Angle Gyro_Median Chassis_Normal High_Gear Tote_Flip_Encoder Tote_Flip_Up "<<std::endl;

	}
}
