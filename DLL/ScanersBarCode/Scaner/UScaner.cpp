//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <UTComPort.h>
#pragma hdrstop
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------

#pragma argsused



typedef __fastcall void (__closure * TEventReadShType)( void);


extern "C" bool __declspec (dllexport) Connect(WideString com_name, WideString baud_rate);
extern "C" void __declspec (dllexport) Disconnect(void);
extern "C" WideString __declspec (dllexport) GetTextError(void);
extern "C" void __declspec (dllexport) SetLp(TEventReadShType  event);
extern "C" WideString __declspec (dllexport) ReadShtrihCod(void);

TComPort *ComPort;
TEventReadShType  ExternalEvent;

void __fastcall ReadShtrihCodEvent(void);
WideString ReadShtrihCod(void);

//----------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
        return 1;
}
//---------------------------------------------------------------------------
bool Connect(WideString com_name, WideString baud_rate)
{
bool result=false;
ComPort=new TComPort(true); //создадим поток
AnsiString num=com_name;
ComPort->OpenPort(StrToInt(num), AnsiString(baud_rate).c_str());
ComPort->Resume();
result=true;
return result;
}
//-----------------------------------------------------------------------------
void Disconnect(void)
{
ComPort->ClosePort();
ComPort->Terminate();
delete ComPort;
}
//-----------------------------------------------------------------------------
WideString GetTextError(void)
{
WideString result=ComPort->TextError.c_str();

return result;
}
//-----------------------------------------------------------------------------
void SetLp(TEventReadShType  event)
{
ExternalEvent=event;
}
//-----------------------------------------------------------------------------
WideString ReadShtrihCod(void)
{

AnsiString res="";
AnsiString s=AnsiString(ComPort->InPaket);
res=s;
WideString result=res;

return result;
}
//-----------------------------------------------------------------------------
void __fastcall ReadShtrihCodEvent(void)
{

if (ExternalEvent) (ExternalEvent)();

}
//------------------------------------------------------------------------------