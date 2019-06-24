//---------------------------------------------------------------------------


#pragma hdrstop

#include "UCardReader.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//-------------------------------------------------------------------
TCardReader::TCardReader()
{

Modul="";

}
//-----------------------------------------------------------------------------
TCardReader::~TCardReader()
{
if (dllIn) FreeLibrary(dllIn);

}
//-----------------------------------------------------------------------------
bool TCardReader::Init()
{
bool result=false;
//Modul="scaner.dll";

dllIn=LoadLibrary(Modul.c_str());
if(dllIn)
        {
        //ShowMessage("Библиотека загружена");
		DllConnect=(DllConnectType*)GetProcAddress(dllIn,"_Connect");
		DllDisconnect=(DllDisconnectType*)GetProcAddress(dllIn,"_Disconnect");
		DllGetTextError=(DllGetTextErrorType*)GetProcAddress(dllIn,"_GetTextError");

		DllReadTrack1=(DllReadTrack1Type*)GetProcAddress(dllIn,"_ReadTrack1");
		DllReadTrack2=(DllReadTrack2Type*)GetProcAddress(dllIn,"_ReadTrack2");
		DllReadTrack3=(DllReadTrack3Type*)GetProcAddress(dllIn,"_ReadTrack3");



		DllSetLp=(DllSetLpType*)GetProcAddress(dllIn,"_SetLp");

		if (DllSetLp>0)
			{
			DllSetLp(ReadTrackEvent);
			}

        result=true;
        }
else
	   {
        return result;
	   }


return result;
}
//----------------------------------------------------------------------------
void  __fastcall TCardReader::ReadTrackEvent(void)
{
//читаем ШК из DLL и передаем в зарегистрированные обработчики
Track1=DllReadTrack1();
Track2=DllReadTrack2();
Track2=DllReadTrack2();
try {if(ReadTrackExternalEvent) ReadTrackExternalEvent();  } catch(...){}

}

//---------------------------------------------------------------------------
bool  TCardReader::Connect(UnicodeString port,UnicodeString baud_rate)
{        //число не факт
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
void TCardReader::Disconnect(void)
{

if (DllDisconnect==0)
	{
	TextError="Ошибка при получении адреса функции: DllDisconnect";
	return ;
	}

DllDisconnect();


}
//---------------------------------------------------------------------------
UnicodeString TCardReader::GetTextError(void)
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