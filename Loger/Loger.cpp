#include "stdafx.h"
#include "Loger.h"

/**
Constructor of the class. Create the file in the given path + time now + class to log.

@param path The path where we want the file Ex: C:\logs.
@param clas The name of the class we are logging.
*/
Loger::Loger(String^ path, String^ clas) {
	if (!File::Exists(path))
	{
		try
		{
			// Create the file.
			fs = File::CreateText(path + DateTime::Now.ToString("dd-MMMM-yyTHH_mm_ss") + "[" + clas + "]" + ".log");
			//Tittle of the file. Just info.
			fs->WriteLine(L"## Log create on " + DateTime::Now.ToString("R") + " for class " + clas);
			fs->WriteLine();
			fs->WriteLine();
			//We force the buffer to be written and clean it.
			fs->Flush();
		}
		catch (Exception^ e)
		{
			Console::WriteLine(e->ToString());
		}
	}
}

/**
Destructor of the class.

*/
Loger::~Loger() {
	if (fs)
		fs->Close();
	delete (IDisposable^)fs;
}

/**
Logging function that actually write data to the file.

@param data The data we want to we written.
*/
void Loger::log(String ^ data)
{
	try
	{
		fs->WriteLine("[" + DateTime::Now.ToString("HH:mm:ss") + "]  " + data);
		fs->Flush();
	}
	catch (Exception^ e)
	{
		Console::WriteLine(e->GetBaseException()->ToString());
	}
}

void Loger::close()
{
	fs->Flush();
	fs->Close();
}