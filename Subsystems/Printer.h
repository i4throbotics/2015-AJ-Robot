

#ifndef PRINTER_H
#define PRINTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <fstream>
#include <iostream>
#include <string>

/**
 *
 *
 * @author ExampleAuthor
 */
class Printer: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::ifstream fin;
	bool RunPrintData;
	std::ofstream fout;
public:

	Printer();
	void InitDefaultCommand();
	bool GetRunPrintData();
	void Print(double time);
	void CloseFile();
	void OpenFile();
};

#endif
