
//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "UFormaReportCF.h"
#include "UFormaReportImpl.h"


//---------------------------------------------------------------------------


extern "C" int __declspec (dllexport) kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv);
extern "C" int __declspec (dllexport) kanSendApplication(TApplication * app);
extern "C" int __declspec (dllexport) kanRegisterServer(IkanCom * icom);
extern "C" int __declspec (dllexport) kanUnregisterServer(IkanCom * icom);
extern "C" int __declspec (dllexport) kanCanUnloadNow(void);
extern "C" void __declspec (dllexport) kanInit(void);
extern "C" void __declspec (dllexport) kanDone(void);
//---------------------------------------------------------------------------
int NumObject=0;
TApplication * glApp=0;
TApplication * dllApp=0;




#pragma argsused
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{

	return 1;
}
//-----------------------------------------------------------------------------
int kanSendApplication(TApplication * app)
{
int result=0;
if (app!=0)
	{
	glApp=app;
	dllApp=Application;
	Application=glApp;
	}
return result;
}
//---------------------------------------------------------------------------
void kanInit(void)
{


}
//---------------------------------------------------------------------------
void kanDone(void)
{

 if (dllApp!=0) Application=dllApp;
}

//---------------------------------------------------------------------------
int kanCanUnloadNow(void)
{
int result=0;

if (NumObject==0)
	{
	result= -1;
	}

return result;
}
//-----------------------------------------------------------------------------
int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)
{
int result=0;
if (id_class==CLSID_TFormaReportImpl)
	{
	TFormaReportCF * ob=new TFormaReportCF();
	result=ob->kanQueryInterface(id_interface, ppv);
	if (result!=-1)
		{
		delete ob;
		}
	}
else
	{
	result=0;
	*ppv=NULL;
	}


return result;
}
//----------------------------------------------------------------------------

int kanRegisterServer(IkanCom * icom)
{
int result=0;

if (icom->kanAddClass(CLSID_TFormaReportImpl,"Kas.ReportAlkDeklVologda.1","RepAlcDeclVologda.dll")!=-1)
	{
	ShowMessage("Error! Falid register class - Kas.ReportAlkDeklVologda.1 !");
	}

return result;
}
//-----------------------------------------------------------------------------
int kanUnregisterServer(IkanCom * icom)
{
int result=0;

return result;
}
//-----------------------------------------------------------------------------




































////---------------------------------------------------------------------------
//#define MESSAGE_END_DLL WM_USER+1
//#include <vcl.h>
//#include <windows.h>
//#pragma hdrstop
////---------------------------------------------------------------------------
//#include "UFormaReport.h"
//#include "inifiles.hpp"
////---------------------------------------------------------------------------
//#include "FIBDatabase.hpp"
//#include "FIBDataSet.hpp"
//#include "pFIBDatabase.hpp"
//#include "pFIBDataSet.hpp"
//#pragma argsused
////---------------------------------------------------------------------------
//typedef __fastcall void (__closure * TEventEndType)( void);//тип завершения работы с библиотекой
//
//extern "C" bool __declspec (dllexport) InitPlugin(HANDLE app_handle,
//													Ibase::TISC_DB_HANDLE db_handle,
//													HANDLE handle_form_ext_module);
//extern "C" void __declspec (dllexport) DonePlugin(void);
//extern "C" char * __declspec (dllexport) GetTextError(void);
//
//TEventEndType  ExternalEventEnd;  //конец работы с библиотекой
//void  EventCloseFormDialog(void);
//
//HANDLE DllHandle;   //
//HANDLE HandleFormExtReport;
//
//AnsiString TextError;
//
//int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
//{
//	return 1;
//}
////---------------------------------------------------------------------------
//char * GetTextError(void)
//{
//char * result="";
//result=TextError.c_str();
//return result;
//}
////---------------------------------------------------------------------------
//bool  InitPlugin(HANDLE  app_handle,
//					TISC_DB_HANDLE db_handle,
//					HANDLE  handle_form_ext_module)
//{
//bool result=false;
//DllHandle=  Application->Handle;
//Application->Handle = app_handle;
//HandleFormExtReport=handle_form_ext_module;
//
//TFormaReport* form=new TFormaReport(Application);
//try
//	{
//	form->pFIBDatabase1->Handle=(TISC_DB_HANDLE) db_handle;
//	result=true;
//	}
//catch (Exception & exception)
//		{
//		TextError="Ошибка при установке Handle Database: "+exception.Message;
//		result=false;
//		}
//
//if (result==true)
//	{
//	form->FOnCloseForm=EventCloseFormDialog;
//	form->UpdateForm();
//	form->Show();
//	}
//else
//	{
//	delete form;
//	}
//return result;
//}
////-----------------------------------------------------------------------------
//void DonePlugin(void)
//{
//Application->Handle =  DllHandle;
//}
////-----------------------------------------------------------------------------
//void  EventCloseFormDialog(void)
//{
////сообщаем приложению о завершении работы
////о необходимости выгрузить библиотеку
//
//PostMessage(HandleFormExtReport,MESSAGE_END_DLL,0,0);
//
//
//}
////-----------------------------------------------------------------------------
