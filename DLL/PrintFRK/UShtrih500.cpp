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
try
        {
        Prn=Variant::CreateObject("AddIn.DrvFR");
        }
catch (...)
        {
        TextError="Не удалось создать объект кухонного принтера !";
        return  result;
        }

		//Prn.OlePropertySet("ConnectionType",0) ;
		Prn.OlePropertySet("Password",30);
		Prn.OlePropertySet("ComNumber",com_name);
        Prn.OlePropertySet("BaudRate",GetNumberBaudRate(baud_rate)) ;

        Prn.OleProcedure("Connect");
        if(Prn.OlePropertyGet("ResultCode")!=0)
                {
                TextError=Prn.OlePropertyGet("ResultCodeDescription");
                return  result;
				}
		else
			{
			Prn.OleProcedure("Beep");
            result=true;
			}

return result;
}
//-----------------------------------------------------------------------------
void Disconnect(void)
{

        Prn.OleProcedure("Disconnect");
        if(Prn.OlePropertyGet("ResultCode")!=0)
                {
                TextError=Prn.OlePropertyGet("ResultCodeDescription");
                }
        


}
//-----------------------------------------------------------------------------
bool PrintString(char * str,
                int alignment,
                int style,
				int size_font,
				bool word_wrap)
{
bool result=false;
if (size_font==0) {size_font=1;}
//***********************************************************************
//              Prn.OlePropertySet("StringForPrinting",str);
//				Prn.OleProcedure("PrintString");
//				if(Prn.OlePropertyGet("ResultCode")!=0)
//						{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
//				else {result=true;}
///************************************************************************
AnsiString s=AnsiString(str);
int kol_symbol=0;

//перенос по словам
//*********************************************************************

Prn.OlePropertySet("UseJournalRibbon",false);
Prn.OlePropertySet("UseReceiptRibbon",true);


if (word_wrap==true)
	{
		switch (size_font)
				{
				case  1:      //32
						{kol_symbol=32;break;}
				case  2:         //32
						{kol_symbol=32;break;}
				case  3:   //18
						{kol_symbol=16;break;}
				case  4:    //18
						{kol_symbol=16;break;}
				}

	AnsiString s1="";
	while(s.Length()>0)
		{
			int pos=s.AnsiPos(' ');
			if (pos==0)
				{
				s=s1+s;
				break;
				}
			else
				{
				if (s1.Length()+pos<=kol_symbol)
					{
					s1=s1+s.SubString(1,pos);
					s=s.SubString(pos+1,s.Length());
					}
				else
					{
					//печатаем строку
					PrintString(s1.c_str(),alignment, style, size_font, false);
					s1="";
					}
				}
			
		}
	}

// ***************************************************************************


		switch ( size_font)
				{
				case  1:
						{
						if(s.Length()>32) s=s.SetLength(32);
                        switch ( alignment)
                                {
								case  0:      //лево
										{
										if (s.Length()>=32)
												{
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
												}
										else
												{
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
												}
                                        break;
                                        }
                                case  1:    //центр
										{
										if (s.Length()>=32)
                                                {
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", 32-((32-s.Length())/2));
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
												}

                                        break;
                                        }
                                case  2:   //право
                                        {
										if (s.Length()>=32)
												{
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", 32);
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }

                                        break;
                                        }


                                }
                        break;
                        }
                case  2:
						{
						if(s.Length()>32) s=s.SetLength(32);
                        switch ( alignment)
                                {
                                case  0:      //лево
                                        {
										if (s.Length()>=32)
                                                {
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }
                                        else
                                                {
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
												}
                                        break;
                                        }
                                case  1:    //центр
                                        {
										if (s.Length()>=32)
												{
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", 32-((32-s.Length())/2));
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
										if (s.Length()>=32)
                                                {
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }
										else
                                                {
												s=DopStrL(s, " ", 32);
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }

                                        break;
                                        }


                                }
                        break;
                        }
                case  3:
						{
						if(s.Length()>16) s=s.SetLength(16);
                        switch ( alignment)
                                {
                                case  0:      //лево
                                        {
										if (s.Length()>=16)
												{
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintWideString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
												}
                                        else
                                                {
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintWideString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }
                                        break;
                                        }
                                case  1:    //центр
                                        {
										if (s.Length()>=16)
                                                {
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintWideString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", 16-((16-s.Length())/2));
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintWideString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
										if (s.Length()>=16)
                                                {
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintWideString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", 16);
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintWideString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }

                                        break;
                                        }


                                }

                        break;
                        }
                case  4:
						{
						if(s.Length()>16) s=s.SetLength(16);
                        switch ( alignment)
                                {
                                case  0:      //лево
                                        {
										if (s.Length()>=16)
                                                {
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintWideString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }
                                        else
                                                {
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintWideString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
												}
                                        break;
                                        }
                                case  1:    //центр
                                        {
										if (s.Length()>=16)
                                                {
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintWideString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", 16-((16-s.Length())/2));
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintWideString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
										if (s.Length()>=16)
                                                {
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintWideString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }
                                        else
                                                {
												Prn.OlePropertySet("StringForPrinting",s.c_str());
												Prn.OleProcedure("PrintWideString");
												if(Prn.OlePropertyGet("ResultCode")!=0)
													{TextError=Prn.OlePropertyGet("ResultCodeDescription");}
												else {result=true;}
                                                }

                                        break;
                                        }


                                }
                        break;
                        }


				}


//*************************************************************************
return result;
}
//-----------------------------------------------------------------------------

bool PrintLine(void)
{
bool result=false;

                Prn.OlePropertySet("StringForPrinting","-------------------------------------");
                Prn.OleProcedure("PrintString");

                if(Prn.OlePropertyGet("ResultCode")!=0)
                        {
                        TextError=Prn.OlePropertyGet("ResultCodeDescription");

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
else
	{
    result=StrToInt(p);
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
