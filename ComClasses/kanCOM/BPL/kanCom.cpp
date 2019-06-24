//---------------------------------------------------------------------------

#include <basepch.h>
#pragma hdrstop


#include "GlobalInterface.h"
#include "UkanComClassFactory.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Package source.
//---------------------------------------------------------------------------

extern "C" bool __declspec (dllexport) kanGetInterfaceCom(int id_class, int id_interface, void ** ppv);

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
	return 1;
}
//---------------------------------------------------------------------------
bool kanGetInterfaceCom(int id_class, int id_interface, void ** ppv)
{
bool result=true;

TkanComClassFactory * ob=new TkanComClassFactory();
IkanCom * i_com;
i_com=ob;
*ppv=i_com;

return result;
}
//----------------------------------------------------------------------------