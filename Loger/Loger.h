#ifndef Loger_HEADER
#define Loger_HEADER

using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Text;

ref class Loger
{
public:
	Loger(String^ path, String^ clas);	//Constructor of the class
	~Loger();	//Destructor of the class
	void log(String^ data);	//Function that saves data to the log file
	void close();	//Close the file

private:
	StreamWriter^ fs;	//Log file
};
#endif

