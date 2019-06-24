//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UScaner.h"
#pragma package(smart_init)
//-------------------------------------------------------------------
TScaner::TScaner()
{
ConnectScaner=false;
Modul="";
InterfaceAsyncMainObject=0;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
}
//-----------------------------------------------------------------------------
TScaner::~TScaner()
{
if (InterfaceAsyncMainObject)
	{
	InterfaceAsyncMainObject->kanRelease();
	}

if (dllIn) FreeLibrary(dllIn);

}
//-----------------------------------------------------------------------------
int TScaner::Init()
{
//������� ��������� ���� �������� ������� �������

if(InterfaceMainObject)
	{
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&InterfaceAsyncMainObject);
	}


return -1;
}
//----------------------------------------------------------------------------
int TScaner::Done()
{


return -1;
}
//----------------------------------------------------------------------------
bool TScaner::InitDevice()
{
bool result=false;
//Modul="scaner.dll";

dllIn=LoadLibrary(Modul.c_str());
if(dllIn)
        {
        //ShowMessage("���������� ���������");
		DllConnect=(DllConnectType*)GetProcAddress(dllIn,"_Connect");
		DllReadShtrihCod=(DllReadShtrihCodType*)GetProcAddress(dllIn,"_ReadShtrihCod");
		DllDisconnect=(DllDisconnectType*)GetProcAddress(dllIn,"_Disconnect");
		DllGetTextError=(DllGetTextErrorType*)GetProcAddress(dllIn,"_GetTextError");
		DllSetLp=(DllSetLpType*)GetProcAddress(dllIn,"_SetLp");

		if (DllSetLp>0)
			{
			DllSetLp(ReadShtrihCodEvent);
			}
        
        ConnectScaner=true;
        result=true;
        }
else
       {
        ConnectScaner=false;
        return result;
        }


return result;
}
//----------------------------------------------------------------------------
void  __fastcall TScaner::ReadShtrihCodEvent(void)
{
//������ �� �� DLL � �������� � ������������������ �����������
UnicodeString sh=ReadShtrihCod();
AnsiString ansi_sh=sh;
if (InterfaceAsyncMainObject)
	{
	InterfaceAsyncMainObject->AsyncExternalEvent("scaner","",ansi_sh.c_str()) ;
	}
}
//----------------------------------------------------------------------------

UnicodeString TScaner::ReadShtrihCod(void)  //������ �� �� DLL
{
UnicodeString result="";

if (DllReadShtrihCod==0)
	{
	TextError="������ ��� ��������� ������ �������: DllReadShtrihCod";
	return result;
	}

result=DllReadShtrihCod();

return result;

}
//---------------------------------------------------------------------------
bool  TScaner::Connect(UnicodeString port,UnicodeString baud_rate)
{
bool result=false;

if (DllConnect==0)
	{
	TextError="������ ��� ��������� ������ �������: DllConnect";
	return result;
	}

result=DllConnect(port,baud_rate);

return result;

}
//----------------------------------------------------------------------------
void TScaner::Disconnect(void)
{

if (DllDisconnect==0)
	{
	TextError="������ ��� ��������� ������ �������: DllDisconnect";
	return ;
	}

DllDisconnect();


}
//---------------------------------------------------------------------------
UnicodeString TScaner::GetTextError(void)
{
UnicodeString result="";

if (DllGetTextError==0)
	{
	TextError="������ ��� ��������� ������ �������: DllGetTextError";
	return result;
	}

result=DllGetTextError();

return result;
}
//---------------------------------------------------------------------------
