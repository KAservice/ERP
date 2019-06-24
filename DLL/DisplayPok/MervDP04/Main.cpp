//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <oleauto.hpp>
#include <SysUtils.hpp>
#pragma hdrstop


extern "C" WideString __declspec (dllexport) GetTextError(void);
extern "C" bool __declspec (dllexport) Connect(int number_port,   //порт,  1,2,3,
												int baud_rate);//скорость 57600,9600 и др.
extern "C" void __declspec (dllexport) Disconnect(void); 
extern "C" bool __declspec (dllexport) ShowString1(WideString str, 	//строка,
													int size_font,    //размер шрифта 1,2,3,4
													int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int alignment   //выравнивание,  0 лево 1 центр 2 право
													);
extern "C" bool __declspec (dllexport) ShowString2(WideString str, 	//строка,
													int size_font,    //размер шрифта 1,2,3,4
													int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int alignment  //выравнивание,  0 лево 1 центр 2 право
													);
extern "C" bool __declspec (dllexport) ShowText(WideString str, 	//строка,
													int size_font,    //размер шрифта 1,2,3,4
													int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int alignment,    //выравнивание,  0 лево 1 центр 2 право
													bool word_wrap); //пернос по словам

Variant  Display;
UnicodeString TextError;
int GetNumberBaudRate(int br);
UnicodeString DispalayString1="";
UnicodeString DispalayString2="";
UnicodeString DopStrL(UnicodeString Str, UnicodeString Symbol, int Len);
UnicodeString DopStrR(UnicodeString Str, UnicodeString Symbol, int Len);
//---------------------------------------------------------------------------

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//---------------------------------------------------------------------------
WideString  GetTextError(void)
{
WideString result="";
result=TextError;
return result;
}
//-----------------------------------------------------------------------------
bool  Connect(int number_port,
				int baud_rate)
{
bool result=false;

try
        {
		Display = Variant::CreateObject("DrvTablo.DisplPI");
        }
catch (...)
        {
		TextError="Не удалось создать объект дисплея DrvTablo.DisplPI !";
		return result;
        }


Display.OlePropertySet("BaudRate",baud_rate);
Display.OlePropertySet("PortNumber",number_port);
//может работать только до 4 портов
Display.OlePropertySet("Protocol",0);
Display.OlePropertySet("Cursor",1);
Display.OleProcedure("InitialDispl");
Display.OleProcedure("ClearDispl");

result=true;
return result;
}
//-------------------------------------------------------------------------
int GetNumberBaudRate(int br)
{
int number=0;

if (br==2400) {number=4;}
if (br==4800) {number=5;}
if (br==9600) {number=7;}
if (br==19200) {number=10;}
return number;
}
//--------------------------------------------------------------------------

void  Disconnect(void)
{
//Display.Clear();
//Display.OlePropertySet("DeviceEnabled",false);
}
//---------------------------------------------------------------------------
bool ShowString1(WideString str, 	//строка,
													int size_font,    //размер шрифта 1,2,3,4
													int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int alignment   //выравнивание,  0 лево 1 центр 2 право
													)
{
bool result=false;
AnsiString s=str;
if (s.Length()>=26)
	{
	s=s.SetLength(26);
	}
else
	{
	s=DopStrR(s, " ",26);
	}
Display.OleProcedure("EnterStr",s.c_str(),1,0);  //

result=true;
return result;
}
//----------------------------------------------------------------------------
bool  ShowString2(WideString str, 	//строка,
													int size_font,    //размер шрифта 1,2,3,4
													int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int alignment  //выравнивание,  0 лево 1 центр 2 право
													)
{
bool result=false;
AnsiString s=str;
if (s.Length()>=26)
	{
	s=s.SetLength(26);
	}
else
	{
	s=DopStrR(s, " ",26);
	}
Display.OleProcedure("EnterStr",s.c_str(),2,0);    //
result=true;
return result;

}
//----------------------------------------------------------------------------
bool  ShowText(WideString str, 	//строка,
													int size_font,    //размер шрифта 1,2,3,4
													int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int alignment,    //выравнивание,  0 лево 1 центр 2 право
													bool word_wrap) //пернос по словам
{
bool result=false;
AnsiString s=str;
if (s.Length()>=26)
	{
	s=s.SetLength(26);
	}
else
	{
	s=DopStrR(s, " ",26);
	}
Display.OleProcedure("EnterStr",s.c_str(),1,0);  //
result=true;
return result;
}
//----------------------------------------------------------------------------
//дополнить строку Str слева символами Symbol до Len
UnicodeString DopStrL(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//---------------------------------------------------------------------------
//дополнить строку Str справа символами Symbol до Len
UnicodeString DopStrR(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Str+Symbol;
        }
return Str;
}
//--------------------------------------------------------------------------
