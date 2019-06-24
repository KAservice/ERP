//---------------------------------------------------------------------------
#define MESSAGE_END_DLL WM_USER+1
#include <vcl.h>
#include <windows.h>
#pragma hdrstop

//---------------------------------------------------------------------------
#include "UFormaGur.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#pragma argsused
//---------------------------------------------------------------------------
typedef __fastcall void (__closure * TEventEndType)( void);//тип завершения работы с библиотекой

extern "C" bool __declspec (dllexport) InitPlugin(HANDLE app_handle,
													Ibase::TISC_DB_HANDLE db_handle,
													HANDLE handle_form_ext_module);
extern "C" void __declspec (dllexport) DonePlugin(void);
extern "C" char * __declspec (dllexport) GetTextError(void);

TEventEndType  ExternalEventEnd;  //конец работы с библиотекой
void  EventCloseFormDialog(void);

HANDLE DllHandle;   //
HANDLE HandleFormExtReport;

AnsiString TextError;

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//---------------------------------------------------------------------------
char * GetTextError(void)
{
char * result="";
result=TextError.c_str();
return result;
}
//---------------------------------------------------------------------------
bool  InitPlugin(HANDLE  app_handle,
					TISC_DB_HANDLE db_handle,
					HANDLE  handle_form_ext_module)
{
bool result=false;
DllHandle=  Application->Handle;
Application->Handle = app_handle;
HandleFormExtReport=handle_form_ext_module;

TFormaGur* form=new TFormaGur(Application);
try
	{
	form->pFIBDatabase1->Handle=(TISC_DB_HANDLE) db_handle;
	result=true;
	}
catch (Exception & exception)
		{
		TextError="Ошибка при установке Handle Database: "+exception.Message;
		result=false;
		}

if (result==true)
	{
	form->FOnCloseForm=EventCloseFormDialog;
	form->Show();
	}
else
	{
    delete form;
	}
return result;
}
//-----------------------------------------------------------------------------
void DonePlugin(void)
{
Application->Handle =  DllHandle;
}
//-----------------------------------------------------------------------------
void  EventCloseFormDialog(void)
{
//сообщаем приложению о завершении работы
//о необходимости выгрузить библиотеку

PostMessage(HandleFormExtReport,MESSAGE_END_DLL,0,0);


}
//-----------------------------------------------------------------------------