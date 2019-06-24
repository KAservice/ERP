//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------




extern "C" bool __declspec (dllexport) PrintString(char * str,    //1234
												   int alignment, //0 лево 1 центр 2 право
												   int style,     //1-жирный 0 обычный   2 курсив 3 жирный курсив
												   int size_font,
												   bool word_wrap );

extern "C" bool __declspec (dllexport) OpenNoFiscalDoc(void);
extern "C" bool __declspec (dllexport) CloseNoFiscalDoc(void);

extern "C" bool __declspec (dllexport) PrintLine(void);
extern "C" bool __declspec (dllexport) Connect(char * com_name, char * baud_rate);
extern "C" void __declspec (dllexport) Disconnect(void);

extern "C" char * __declspec (dllexport) GetTextError(void);

//1234 0,1-обычный, 3-жирный 2-курсив 4 - жирн курсив
//0,1 лево, 2 центр, 3 право

int GetNumberBaudRate(char * br);

Variant  Prn;
AnsiString TextError;


#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//---------------------------------------------------------------------------

bool Connect(char * com_name, char * baud_rate)
{
bool result=false;
try
        {
		Prn=Variant::CreateObject("AddIn.RcpPrn51");
		result=true;
		}
catch (...)
		{
        TextError="Не удалось создать объект кухонного принтера !";
        return  result;
        }



		//Prn.OlePropertySet("ConnectionType",0) ;
		Prn.OlePropertySet("PortNumber",com_name) ;
		Prn.OlePropertySet("BaudRate",GetNumberBaudRate(baud_rate)) ;
        Prn.OlePropertySet("Model",11) ;

		Prn.OlePropertySet("DeviceEnabled",true) ;

		if(Prn.OlePropertyGet("ResultCode")!=0)
                {
				TextError=Prn.OlePropertyGet("ResultDescription");
				return  result;
				}
		else
			{
			//Prn.OleProcedure("Beep");
            result=true;
			}

return result;
}
//-----------------------------------------------------------------------------
void Disconnect(void)
{

//        Prn.OleProcedure("Disconnect");
//		if(Prn.OlePropertyGet("ResultCode")!=0)
//				{
//				TextError=Prn.OlePropertyGet("ResultCodeDescription");
//				}
        
Prn.OlePropertySet("DeviceEnabled",false) ;

}
//-----------------------------------------------------------------------------
bool PrintString(char * str,
				int alignment,   //012
				int style,       //0123
				int size_font,   //1234
				bool word_wrap)  //01
{
bool result=false;

//выравнивание
//	Printer.Alignment = 1;

//стиль
//	Printer.FontDblHeight = 0;
//	Printer.FontDblWidth = 0;
//	Printer.FontBold = 0;

	Prn.OlePropertySet("Caption",str);
	Prn.OleProcedure("AddText");



	if(Prn.OlePropertyGet("ResultCode")!=0)
		{
		TextError=Prn.OlePropertyGet("ResultDescription");
		result=false;
		}
	else
		{
		result=true;
		}

return result;
}
//-----------------------------------------------------------------------------

bool PrintLine(void)
{
bool result=false;

int kol_symbol=0;
kol_symbol=Prn.OlePropertyGet("CapCharCount");
AnsiString s="";



	for (int i = 1; i<kol_symbol; i++)
    	{
		s=s+"-";
		}

	Prn.OlePropertySet("Caption",s.c_str());
	Prn.OleProcedure("AddText");
	if(Prn.OlePropertyGet("ResultCode")!=0)
		{
		TextError=Prn.OlePropertyGet("ResultDescription");
		}
	else
		{
		result=true;
		}

return result;
}
//-----------------------------------------------------------------------------
bool OpenNoFiscalDoc(void)
{
bool result=false;
ShowMessage("Start print");


		Prn.OleProcedure("ResetPrintSettings");

		if(Prn.OlePropertyGet("ResultCode")!=0)
				{
				TextError=Prn.OlePropertyGet("ResultDescription");
				//return  result;
				}
		else
			{
			//result=true;
			}



Prn.OleProcedure("ClearTask");
if(Prn.OlePropertyGet("ResultCode")!=0)
	{
	TextError=Prn.OlePropertyGet("ResultDescription");
	result=false;
	}
else
	{
	result=true;
	}


return result;
}
//-----------------------------------------------------------------------------
bool CloseNoFiscalDoc(void)
{
bool result=false;
ShowMessage("End print");

//Prn.OlePropertySet("Copies",1);

Prn.OleProcedure("PrintTask");
if(Prn.OlePropertyGet("ResultCode")!=0)
	{
	TextError=Prn.OlePropertyGet("ResultDescription");
	result=false;
	}
else
	{
	result=true;
	}
return result;
}
//------------------------------------------------------------------------------
int GetNumberBaudRate(char * br)
{
int result=0;
AnsiString baud=AnsiString(br);

if (baud=="4800")
	{
	result=5;
	}

if (baud=="9600")
	{
	result=7;
	}

if (baud=="19200")
	{
	result=10;
	}

if (baud=="38400")
	{
	result=12;
	}

if (baud=="57600")
	{
	result=14;
	}
return result;
}

//------------------------------------------------------------------------------
char *  GetTextError(void)
{
char * result="";
result=TextError.c_str();
return result;
}
//---------------------------------------------------------------------------