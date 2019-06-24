//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <oleauto.hpp>
#include <SysUtils.hpp>
#pragma hdrstop


extern "C" WideString __declspec (dllexport) GetTextError(void);
extern "C" bool __declspec (dllexport) Connect(int number_port,   //����,  1,2,3,
												int baud_rate);//�������� 57600,9600 � ��.
extern "C" void __declspec (dllexport) Disconnect(void); 
extern "C" bool __declspec (dllexport) ShowString1(WideString str, 	//������,
													int size_font,    //������ ������ 1,2,3,4
													int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int alignment   //������������,  0 ���� 1 ����� 2 �����
													);
extern "C" bool __declspec (dllexport) ShowString2(WideString str, 	//������,
													int size_font,    //������ ������ 1,2,3,4
													int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int alignment  //������������,  0 ���� 1 ����� 2 �����
													);
extern "C" bool __declspec (dllexport) ShowText(WideString str, 	//������,
													int size_font,    //������ ������ 1,2,3,4
													int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int alignment,    //������������,  0 ���� 1 ����� 2 �����
													bool word_wrap); //������ �� ������

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
		TextError="�� ������� ������� ������ ������� DrvTablo.DisplPI !";
		return result;
        }


Display.OlePropertySet("BaudRate",baud_rate);
Display.OlePropertySet("PortNumber",number_port);
//����� �������� ������ �� 4 ������
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
bool ShowString1(WideString str, 	//������,
													int size_font,    //������ ������ 1,2,3,4
													int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int alignment   //������������,  0 ���� 1 ����� 2 �����
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
bool  ShowString2(WideString str, 	//������,
													int size_font,    //������ ������ 1,2,3,4
													int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int alignment  //������������,  0 ���� 1 ����� 2 �����
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
bool  ShowText(WideString str, 	//������,
													int size_font,    //������ ������ 1,2,3,4
													int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int alignment,    //������������,  0 ���� 1 ����� 2 �����
													bool word_wrap) //������ �� ������
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
//��������� ������ Str ����� ��������� Symbol �� Len
UnicodeString DopStrL(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//---------------------------------------------------------------------------
//��������� ������ Str ������ ��������� Symbol �� Len
UnicodeString DopStrR(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Str+Symbol;
        }
return Str;
}
//--------------------------------------------------------------------------
