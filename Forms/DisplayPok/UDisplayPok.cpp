//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDisplayPok.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//-------------------------------------------------------------------
TDisplayPok::TDisplayPok()
{

}
//-----------------------------------------------------------------------------
TDisplayPok::~TDisplayPok()
{
FreeLibrary(dllIn); 
}
//---------------------------------------------------------------------------
bool TDisplayPok::Init()
{
bool result=false;
TextError="";
try
	{
	dllIn=LoadLibrary(Modul.c_str());
	if(dllIn)
        {
        DllGetTextError=(DllGetTextErrorType*)GetProcAddress(dllIn,"_GetTextError");
        DllConnect=(DllConnectType*)GetProcAddress(dllIn,"_Connect");
		DllDisconnect=(DllDisconnectType*)GetProcAddress(dllIn,"_Disconnect");

		DllShowString1=(DllShowString1Type*)GetProcAddress(dllIn,"_ShowString1");
		DllShowString2=(DllShowString2Type*)GetProcAddress(dllIn,"_ShowString2");
		DllShowText=(DllShowTextType*)GetProcAddress(dllIn,"_ShowText");

        result=true;
        }
	else
	   {
	   TextError="ошибка загрузки библиотеки: "+Modul+"!";
	   return result;
	   }
   }
catch (Exception &exception)
		{
		result=false;
		Error=true;
		TextError=TextError+exception.Message;
		}
return result;
}
//---------------------------------------------------------------------------

bool TDisplayPok::Connect(int port,   //порт,  1,2,3,
							int baud_rate)//скорость 57600,9600 и др.
{
bool result=false;

if (DllConnect==0)
	{
	TextError="Ошибка при получении адреса функции: DllConnect";
	return result;
	}

try
	{
	if (DllConnect(port,baud_rate)==true)
		{
		result=true;Error=false;
		TextError="";
		}
	else
		{
		result=false;Error=true;
		TextError=DllGetTextError();
		}
	}
catch (Exception &exception)
	{
	result=false;Error=true;
	TextError=exception.Message;
	}
return result;
}
//---------------------------------------------------------------------------
void TDisplayPok::Disconnect(void)
{
if (DllDisconnect==0)
	{
	TextError="Ошибка при получении адреса функции: DllDisconnect";
	return ;
	}
if (DllDisconnect>0) DllDisconnect();
}
//---------------------------------------------------------------------------
bool TDisplayPok::ShowString1(UnicodeString str, 	//строка,
							int size_font,    //размер шрифта 1,2,3,4
							int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
							int alignment    //выравнивание,  0 лево 1 центр 2 право
							) 
{
bool result=false;

if (DllShowString1==0)
	{
	TextError="Ошибка при получении адреса функции: DllShowString1";
	return result;
	}

	if (DllShowString1(str, size_font, style_font, alignment)==true)
		{
		result=true;Error=false;
		TextError="";
		}
	else
		{
		result=false;Error=true;
		TextError=DllGetTextError();
		throw Exception(TextError);
		}

return result;
}
//---------------------------------------------------------------------------
bool TDisplayPok::ShowString2(UnicodeString str, 	//строка,
							int size_font,    //размер шрифта 1,2,3,4
							int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
							int alignment    //выравнивание,  0 лево 1 центр 2 право
							) 
{
bool result=false;

if (DllShowString2==0)
	{
	TextError="Ошибка при получении адреса функции: DllShowString2";
	return result;
	}

	if (DllShowString2(str, size_font, style_font, alignment)==true)
		{
		result=true;Error=false;
		TextError="";
		}
	else
		{
		result=false;Error=true;
		TextError=DllGetTextError();
		throw Exception(TextError);
		}

return result;
}
//---------------------------------------------------------------------------
bool TDisplayPok::ShowText(UnicodeString str, 	//строка,
							int size_font,    //размер шрифта 1,2,3,4
							int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
							int alignment,    //выравнивание,  0 лево 1 центр 2 право
							bool word_wrap)   //перенос по словам
{
bool result=false;

if (DllShowText==0)
	{
	TextError="Ошибка при получении адреса функции: DllShowText";
	return result;
	}

	if (DllShowText(str, size_font, style_font, alignment, word_wrap)==true)
		{
		result=true;Error=false;
		TextError="";
		}
	else
		{
		result=false;Error=true;
		TextError=DllGetTextError();
		throw Exception(TextError);
		}

return result;
}
//---------------------------------------------------------------------------
