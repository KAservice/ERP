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
	   TextError="������ �������� ����������: "+Modul+"!";
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

bool TDisplayPok::Connect(int port,   //����,  1,2,3,
							int baud_rate)//�������� 57600,9600 � ��.
{
bool result=false;

if (DllConnect==0)
	{
	TextError="������ ��� ��������� ������ �������: DllConnect";
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
	TextError="������ ��� ��������� ������ �������: DllDisconnect";
	return ;
	}
if (DllDisconnect>0) DllDisconnect();
}
//---------------------------------------------------------------------------
bool TDisplayPok::ShowString1(UnicodeString str, 	//������,
							int size_font,    //������ ������ 1,2,3,4
							int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
							int alignment    //������������,  0 ���� 1 ����� 2 �����
							) 
{
bool result=false;

if (DllShowString1==0)
	{
	TextError="������ ��� ��������� ������ �������: DllShowString1";
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
bool TDisplayPok::ShowString2(UnicodeString str, 	//������,
							int size_font,    //������ ������ 1,2,3,4
							int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
							int alignment    //������������,  0 ���� 1 ����� 2 �����
							) 
{
bool result=false;

if (DllShowString2==0)
	{
	TextError="������ ��� ��������� ������ �������: DllShowString2";
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
bool TDisplayPok::ShowText(UnicodeString str, 	//������,
							int size_font,    //������ ������ 1,2,3,4
							int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
							int alignment,    //������������,  0 ���� 1 ����� 2 �����
							bool word_wrap)   //������� �� ������
{
bool result=false;

if (DllShowText==0)
	{
	TextError="������ ��� ��������� ������ �������: DllShowText";
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
