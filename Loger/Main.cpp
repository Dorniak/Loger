#include "stdafx.h"
#include "Loger.h"

int main(array<System::String ^> ^args)
{
	Loger^ log = gcnew Loger("E:\\", "claseA");
	array<Byte>^ bytes1 = gcnew array<Byte>(900000);
	Random^ rnd1 = gcnew Random();
	rnd1->NextBytes(bytes1);
	for (int i = 0; i < 900000; i++)
	{
		log->log(bytes1[i].ToString());
	}
	log->close();
	delete log;
	return 0;
}
