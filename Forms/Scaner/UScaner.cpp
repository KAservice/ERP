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

}
//-----------------------------------------------------------------------------
TScaner::~TScaner()
{
if (dllIn) FreeLibrary(dllIn);

}
//-----------------------------------------------------------------------------
bool TScaner::Init()
{
bool result=false;
//Modul="scaner.dll";

dllIn=LoadLibrary(Modul.c_str());
if(dllIn)
        {
        //ShowMessage("Библиотека загружена");
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
//читаем ШК из DLL и передаем в зарегистрированные обработчики
UnicodeString sh=ReadShtrihCod();
try {if(ReadSh) ReadSh(Number,sh);  } catch(...){}

}
//----------------------------------------------------------------------------

UnicodeString TScaner::ReadShtrihCod(void)  //читает ШК из DLL
{
UnicodeString result="";

if (DllReadShtrihCod==0)
	{
	TextError="Ошибка при получении адреса функции: DllReadShtrihCod";
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
	TextError="Ошибка при получении адреса функции: DllConnect";
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
	TextError="Ошибка при получении адреса функции: DllDisconnect";
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
	TextError="Ошибка при получении адреса функции: DllGetTextError";
	return result;
	}

result=DllGetTextError();

return result;
}
//---------------------------------------------------------------------------
