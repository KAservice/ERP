//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <oleauto.hpp>
#include <SysUtils.hpp>
#pragma hdrstop


extern "C" char * __declspec (dllexport) GetTextError(void);
extern "C" bool __declspec (dllexport) Connect(int number_port,   //����,  1,2,3,
												int baud_rate);//�������� 57600,9600 � ��.
extern "C" void __declspec (dllexport) Disconnect(void); 
extern "C" bool __declspec (dllexport) ShowString1(char* str, 	//������,
													int size_font,    //������ ������ 1,2,3,4
													int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int alignment   //������������,  0 ���� 1 ����� 2 �����
													);
extern "C" bool __declspec (dllexport) ShowString2(char* str, 	//������,
													int size_font,    //������ ������ 1,2,3,4
													int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int alignment  //������������,  0 ���� 1 ����� 2 �����
													);
extern "C" bool __declspec (dllexport) ShowText(char* str, 	//������,
													int size_font,    //������ ������ 1,2,3,4
													int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int alignment,    //������������,  0 ���� 1 ����� 2 �����
													bool word_wrap); //������ �� ������

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
        TextError="�� ������� ������� ������ ������� AddIn.Line45 !";
		return result;
        }


Display.OlePropertySet("BaudRate",GetNumberBaudRate(baud_rate));
Display.OlePropertySet("PortNumber",number_port);
//Display.OlePropertySet("Model",1);
Display.OlePropertySet("DeviceEnabled",true );

if (Display.OlePropertyGet("ResultCode")!=0)
	{
	TextError="������ �������: "+Display.OlePropertyGet("ResultDescription");
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
				TextError="������ �������: "+Display.OlePropertyGet("ResultDescription");
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
bool ShowString1(char* str, 	//������,
													int size_font,    //������ ������ 1,2,3,4
													int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int alignment   //������������,  0 ���� 1 ����� 2 �����
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
				TextError="������ �������: "+Display.OlePropertyGet("ResultDescription");
				//ConnectFR=false;
				result=false;
				}

return result;
}
//----------------------------------------------------------------------------
bool  ShowString2(char* str, 	//������,
													int size_font,    //������ ������ 1,2,3,4
													int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int alignment  //������������,  0 ���� 1 ����� 2 �����
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
				TextError="������ �������: "+Display.OlePropertyGet("ResultDescription");
				//ConnectFR=false;
				result=false;
				}

return result;

}
//----------------------------------------------------------------------------
bool  ShowText(char* str, 	//������,
													int size_font,    //������ ������ 1,2,3,4
													int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int alignment,    //������������,  0 ���� 1 ����� 2 �����
													bool word_wrap) //������ �� ������
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
				TextError="������ �������: "+Display.OlePropertyGet("ResultDescription");
				//ConnectFR=false;
				result=false;
				}

return result;
}
//----------------------------------------------------------------------------
//��������� ������ Str ����� ��������� Symbol �� Len
String DopStrL(String Str, String Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//---------------------------------------------------------------------------
//��������� ������ Str ������ ��������� Symbol �� Len
String DopStrR(String Str, String Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Str+Symbol;
        }
return Str;
}
//--------------------------------------------------------------------------