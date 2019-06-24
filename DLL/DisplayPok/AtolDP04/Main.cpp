//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <oleauto.hpp>
#include <SysUtils.hpp>
#pragma hdrstop


extern "C" char * __declspec (dllexport) GetTextError(void);
extern "C" bool __declspec (dllexport) Connect(int number_port,   //порт,  1,2,3,
												int baud_rate);//скорость 57600,9600 и др.
extern "C" void __declspec (dllexport) Disconnect(void); 
extern "C" bool __declspec (dllexport) ShowString1(char* str, 	//строка,
													int size_font,    //размер шрифта 1,2,3,4
													int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int alignment   //выравнивание,  0 лево 1 центр 2 право
													);
extern "C" bool __declspec (dllexport) ShowString2(char* str, 	//строка,
													int size_font,    //размер шрифта 1,2,3,4
													int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int alignment  //выравнивание,  0 лево 1 центр 2 право
													);
extern "C" bool __declspec (dllexport) ShowText(char* str, 	//строка,
													int size_font,    //размер шрифта 1,2,3,4
													int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int alignment,    //выравнивание,  0 лево 1 центр 2 право
													bool word_wrap); //пернос по словам

Variant  Display;
AnsiString TextError;
int GetNumberBaudRate(int br);
AnsiString DispalayString1="";
AnsiString DispalayString2="";
String DopStrL(String Str, String Symbol, int Len);
String DopStrR(String Str, String Symbol, int Len);
//---------------------------------------------------------------------------

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//---------------------------------------------------------------------------
char *  GetTextError(void)
{
char * result="";
result=TextError.c_str();
return result;
}
//-----------------------------------------------------------------------------
bool  Connect(int number_port,
				int baud_rate)
{
bool result=false;

try
        {
		Display = Variant::CreateObject("AddIn.Line45");
        }
catch (...)
        {
        TextError="Не удалось создать объект дисплея AddIn.Line45 !";
		return result;
        }


Display.OlePropertySet("BaudRate",GetNumberBaudRate(baud_rate));
Display.OlePropertySet("PortNumber",number_port);
//Display.OlePropertySet("Model",1);
Display.OlePropertySet("DeviceEnabled",true );

if (Display.OlePropertyGet("ResultCode")!=0)
	{
	TextError="Ошибка дисплея: "+Display.OlePropertyGet("ResultDescription");
	result=false;
	return result;
	}

Display.OleProcedure("Clear");
		if(Display.OlePropertyGet("ResultCode")==0)
				{
				result=true;
                }
        else
				{
				TextError="Ошибка дисплея: "+Display.OlePropertyGet("ResultDescription");
				result=false;
				}
Display.OleProcedure("CreateWindow",0, 0, 2, 20, 2, 20);

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
Display.OleProcedure("DestroyWindow");
Display.OlePropertySet("DeviceEnabled",false);
}
//---------------------------------------------------------------------------
bool ShowString1(char* str, 	//строка,
													int size_font,    //размер шрифта 1,2,3,4
													int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int alignment   //выравнивание,  0 лево 1 центр 2 право
													)
{
bool result=false;
//Display.OlePropertySet("CursorRow",1);
//Display.OlePropertySet("CursorColumn",1);
//Display.OlePropertySet("CursorUpdate", true);

Display.OleProcedure("Clear");

AnsiString s=str;
if (s.Length()>=20)
	{
	s=s.SetLength(20);
	}
else
	{
    s=DopStrR(s, " ",20);
	}

DispalayString1=s;
		Display.OleProcedure("DisplayText",(DispalayString1+DispalayString2).c_str(),0);
		if(Display.OlePropertyGet("ResultCode")==0)
				{
				result=true;
				}
		else
				{
				TextError="Ошибка дисплея: "+Display.OlePropertyGet("ResultDescription");
				//ConnectFR=false;
				result=false;
				}

return result;
}
//----------------------------------------------------------------------------
bool  ShowString2(char* str, 	//строка,
													int size_font,    //размер шрифта 1,2,3,4
													int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int alignment  //выравнивание,  0 лево 1 центр 2 право
													)
{
bool result=false;
//Display.OlePropertySet("CursorRow",1);
//Display.OlePropertySet("CursorColumn",1);
//Display.OlePropertySet("CursorUpdate", true);

Display.OleProcedure("Clear");

AnsiString s=str;
if (s.Length()>=20)
	{
	s=s.SetLength(20);
	}
else
	{
    s=DopStrR(s, " ",20);
	}
DispalayString2=s;
		Display.OleProcedure("DisplayText",(DispalayString1+DispalayString2).c_str(),0);
		if(Display.OlePropertyGet("ResultCode")==0)
				{
				result=true;
				}
		else
				{
				TextError="Ошибка дисплея: "+Display.OlePropertyGet("ResultDescription");
				//ConnectFR=false;
				result=false;
				}

return result;

}
//----------------------------------------------------------------------------
bool  ShowText(char* str, 	//строка,
													int size_font,    //размер шрифта 1,2,3,4
													int style_font,    // стиль, 0 обычный, 1 курсив, 2 жирный, 3 жирный курсив
													int alignment,    //выравнивание,  0 лево 1 центр 2 право
													bool word_wrap) //пернос по словам
{
bool result=false;
//Display.OlePropertySet("CursorRow",1);
//Display.OlePropertySet("CursorColumn",1);
//Display.OlePropertySet("CursorUpdate", true);

AnsiString s=str;
		Display.OleProcedure("DisplayText",s.c_str(),0);
		if(Display.OlePropertyGet("ResultCode")==0)
				{
				result=true;
				}
		else
				{
				TextError="Ошибка дисплея: "+Display.OlePropertyGet("ResultDescription");
				//ConnectFR=false;
				result=false;
				}

return result;
}
//----------------------------------------------------------------------------
//дополнить строку Str слева символами Symbol до Len
String DopStrL(String Str, String Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//---------------------------------------------------------------------------
//дополнить строку Str справа символами Symbol до Len
String DopStrR(String Str, String Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Str+Symbol;
        }
return Str;
}
//--------------------------------------------------------------------------