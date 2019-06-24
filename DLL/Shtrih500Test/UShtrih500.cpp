//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <oleauto.hpp>
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
int GetNumberPort(char * port);

Variant  Prn;
AnsiString TextError;

String DopStrL(String Str, String Symbol, int Len);
String DopStrR(String Str, String Symbol, int Len);


#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
		return 1;
}
//---------------------------------------------------------------------------

bool Connect(char * com_name, char * baud_rate)
{
bool result=false;

return result;
}
//-----------------------------------------------------------------------------
void Disconnect(void)
{


        


}
//-----------------------------------------------------------------------------
bool OpenNoFiscalDoc(void)
{
bool result=true;

return result;
}
//-----------------------------------------------------------------------------
bool CloseNoFiscalDoc(void)
{
bool result=true;

return result;
}
//-----------------------------------------------------------------------------
bool PrintString(char * str,
				int alignment,
				int style,
				int size_font,
				bool word_wrap)
{

//*************************************************************************
return true;
}
//-----------------------------------------------------------------------------

bool PrintLine(void)
{


return true;
}
//------------------------------------------------------------------------------
int GetNumberBaudRate(char * br)
{
int result=1;

return result;
}
//------------------------------------------------------------------------------
int GetNumberPort(char * port)
{
int result=0;
AnsiString p=AnsiString(port);
if (p.Length()==4)
        {
        result=StrToInt(p[4]);
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
