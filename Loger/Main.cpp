#include "stdafx.h"
#include "Loger.h"

int main(array<System::String ^> ^args)
{
		Loger^ log = gcnew Loger("E:\\","claseA");
		log->log("safsafsfasa \t sdfjksdfksb k");
		delete log;
		return 0;
	
}
