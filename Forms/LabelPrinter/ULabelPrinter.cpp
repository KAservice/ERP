//---------------------------------------------------------------------------


#pragma hdrstop

#include "ULabelPrinter.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//-------------------------------------------------------------------
TLabelPrinter::TLabelPrinter()
{

}
//-----------------------------------------------------------------------------
TLabelPrinter::~TLabelPrinter()
{
FreeLibrary(dllIn); 
}
//---------------------------------------------------------------------------
bool TLabelPrinter::Init()
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

		DllSetSetup=(DllSetSetupType*)GetProcAddress(dllIn,"_SetSetup");

		DllPrintString=(DllPrintStringType*)GetProcAddress(dllIn,"_PrintString");
		DllPrintBarCode=(DllPrintBarCodeType*)GetProcAddress(dllIn,"_PrintBarCode");
		DllPrintLine=(DllPrintLineType*)GetProcAddress(dllIn,"_PrintLine");

		DllOpenDoc=(DllOpenDocType*)GetProcAddress(dllIn,"_OpenDoc");
		DllCloseDoc=(DllCloseDocType*)GetProcAddress(dllIn,"_CloseDoc");

		DllGetSostPrinter=(DllGetSostPrinterType*)GetProcAddress(dllIn,"_GetSostPrinter");
        DllProvVosmPrint=(DllProvVosmPrintType*)GetProcAddress(dllIn,"_ProvVosmPrint"); 

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

bool TLabelPrinter::Connect(int port,   //����,  1,2,3,
							int baud_rate)//�������� 57600,9600 � ��.
{
bool result=false;
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
void TLabelPrinter::Disconnect(void)
{
DllDisconnect();
}
//---------------------------------------------------------------------------
//��������� �������� � ��������
void TLabelPrinter::SetSetup(int height_label, int width_label)  //������ ��������
{
AnsiString parameter="HeightLabel="+IntToStr(height_label)+";";
parameter=parameter+"WidthLabel="+IntToStr(width_label)+";";
DllSetSetup(parameter.c_str());
}
//---------------------------------------------------------------------------
bool TLabelPrinter::PrintString(char* str, 	//������,
							int size_font,    //������ ������ 1,2,3,4
							int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
							int alignment,    //������������,  0 ���� 1 ����� 2 �����
							AnsiString name_font,
							bool word_wrap) //������ �� ������
{
bool result=false;

	if (DllPrintString(str, size_font, style_font, alignment, name_font.c_str() ,word_wrap)==true)
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
bool TLabelPrinter::PrintBarCode(char* bar_code,
								int otstup,  //������ �����
								int type_barcode,  //��� ����� ����
								int size_font_bar_code,  //������ ������ ����� ����
								int height_bar_code) //������
{
bool result=false;

try
	{
	if (DllPrintBarCode(bar_code,
						otstup,
						type_barcode,
						size_font_bar_code,
						height_bar_code	)==true)
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
	}
catch (Exception &exception)
	{
	TextError=exception.Message;
	}
return result;
}
//---------------------------------------------------------------------------
bool TLabelPrinter::PrintLine(void)
{
bool result=false;

	if (DllPrintLine()==true)
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
bool TLabelPrinter::OpenDoc(void)
{
bool result=false;

	if (DllOpenDoc()==true)
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
bool TLabelPrinter::CloseDocType(void)
{
bool result=false;

	if (DllCloseDoc()==true)
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
bool TLabelPrinter::GetSostPrinter(void)
{
bool result=false;

	if (DllGetSostPrinter()==true)
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
bool TLabelPrinter::ProvVosmPrint(void)
{
bool result=false;

	if (DllProvVosmPrint()==true)
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
