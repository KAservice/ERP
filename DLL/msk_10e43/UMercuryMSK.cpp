

#include <vcl.h>
#include <windows.h>
#include <oleauto.hpp>
#include <math.h>
//---------------------------------------------------------------------------
//#include <Classes.hpp>
//#include <Controls.hpp>
//#include <StdCtrls.hpp>
//#include <Forms.hpp>

#include "MercFPrtX_TLB.h"


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

#pragma argsused
extern "C" WideString __declspec (dllexport) GetTextError(void);

extern "C" bool __declspec (dllexport) Connect(int number_port,
												WideString baud_rate,
												WideString password);
extern "C" void __declspec (dllexport) Disconnect(void);

extern "C" bool __declspec (dllexport) GetSostKKM(void);
extern "C" bool __declspec (dllexport) ProvVosmPrintCheck(void);
extern "C" int __declspec (dllexport) GetNumberCheck(void);
extern "C" int __declspec (dllexport) GetNumberKL(void);
extern "C" WideString __declspec (dllexport) GetSerialNumberKKM(void);
extern "C" WideString __declspec (dllexport) GetRegNumberKKM(void);
extern "C" WideString __declspec (dllexport) GetModelKKM(void);

extern "C" bool __declspec (dllexport)  OpenNoFiscalCheck(void);
extern "C" bool __declspec (dllexport)  CloseNoFiscalCheck(void);
extern "C" bool __declspec (dllexport) PrintString(WideString str,
                                                int size_font,       //1234
                                                int style,           //1-жирный 0 обычный   2 курсив 3 жирный курсив
                                                int alignment,       //0 лево 1 центр 2 право
                                                bool ch_lenta,       //на чековой ленте
												bool kontr_lenta,    //на контрольной ленте
												bool word_wrap);

extern "C" bool __declspec (dllexport) PrintLine(void);


extern "C" bool __declspec (dllexport) PrintFiscalCheck(double sum,
                                                        int department,
                                                        double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
                                                        int operation);    //0 продажа 1 возврат

bool  PrintFiscalCheckSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation);    //0 продажа 1 возврат
bool  PrintFiscalCheckReturnSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation);    //0 продажа 1 возврат


extern "C" bool __declspec (dllexport) PrintNoFiscalCheck(double sum,
                                int department,
                                double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
                                int operation);    //0 продажа 1 возврат

extern "C" bool __declspec (dllexport) PrintXReport(void);
extern "C" bool __declspec (dllexport) PrintZReport(void);
extern "C" bool __declspec (dllexport) PrintPoOtdelamReport(void);

extern "C" bool __declspec (dllexport) Cut(int TypeCut);

extern "C" bool __declspec (dllexport) Vnesenie(double sum);
extern "C" bool __declspec (dllexport) Snatie(double sum);

extern "C" WideString __declspec (dllexport) GetTimeKKM(void);
extern "C" WideString __declspec (dllexport) GetDateKKM(void);
extern "C" bool __declspec (dllexport) SetTimeKKM(WideString time);
extern "C" bool __declspec (dllexport) SetDateKKM(WideString date);

UnicodeString TextError;

bool ConnectFR=false;
bool NoPrint;
bool UseJournalRibbon=true;
bool UseReceiptRibbon=true;
bool OpenNoFiscalDoc=false;

IMercuryFPrt *Merc;
Variant  FR;
UnicodeString DopStrL(UnicodeString Str, UnicodeString Symbol, int Len);
UnicodeString DopStrR(UnicodeString Str, UnicodeString Symbol, int Len);
void OpenDrawer(void);
int CompareDoubleValue(double v1, double v2, int pogr);
//------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------


bool  Connect(int number_port,
				WideString baud_rate,
				WideString password)
{

//try
//        {
//		FR = Variant::CreateObject("Incotex.MercuryFPrtCOM");
//        }
//catch (...)
//        {
//		TextError="Не удалось создать объект фискального регистратора !";
//        //ConnectFR=false;
//        }


bool result=false;
NoPrint=false;
UseJournalRibbon=true;
UseReceiptRibbon=true;
OpenNoFiscalDoc=false;

        CLSID clsid;
        IClassFactory* pCF;
        IUnknown* pUnk;

        
        CoInitialize(0);

        HRESULT hr = ::CLSIDFromProgID( L"Incotex.MercuryFPrtCOM", &clsid );

        if ( FAILED( hr ))
        {
	        TextError="Не Получили CLSID";
	        //return ;
        }
        else
                {
                //ShowMessage("Получили CKSID");
                }
//------------------------------------------------------------

        hr = CoGetClassObject( clsid, CLSCTX_INPROC, NULL,IID_IClassFactory, (void**) &pCF );
        if ( FAILED( hr ))
        {
        TextError="Не Соединились с объектом";
        }
        else
                {
                //ShowMessage("Соединились с объектом");
                }

//------------------------------------------------------

        hr = pCF->CreateInstance( NULL, IID_IUnknown, (void**) &pUnk );
        pCF->Release();
        if ( FAILED( hr ))
        {
	TextError="Не Создали интерфейс";
        }
        else
                {
                //ShowMessage("Создали интерфейс");
                 }

//--------------------------------------------------
        Merc = NULL;


        hr = pUnk->QueryInterface( IID_IMercuryFPrt7, (void**) &Merc);
        pUnk->Release();


        if ( FAILED( hr ))
			{
			TextError="Не Создали рабочий интерфейс";
			}
		else
                {
                //ShowMessage("Создали рабочий интерфейс");
                }

try
        {
        Merc->PortNum=number_port;
		Merc->BaudRate=StrToInt(baud_rate);
        Merc->ExternalTimeout=30000;
        Merc->InternalTimeout=500;
        AnsiString pass=password;
		Merc->Password=WideString("0000").c_bstr();

		if (Merc->Open()==0)
			{
			result=true;
			ConnectFR=true;
			}
		else
			{
			result=false;
			ConnectFR=false;
			}
		}

catch (Exception &E)
        {
		result=false;
        TextError="Не удалось подключиться к ФР! Ошибка: "+E.Message;
        ConnectFR=false;
        }
return result;
}
//--------------------------------------------------------------------------

void  Disconnect(void)
{
try
	{
	Merc->Close(true);
	ConnectFR=false;
	CoUninitialize();
	}
catch (Exception &E)
		{
		TextError=E.Message;
		}
}
//---------------------------------------------------------------------------

bool  GetSostKKM(void)
{
bool result=false;
HRESULT hr;
try
	{
	hr=Merc->QueryLastDocInfo();
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

	if (Merc->ErrCode==0)
		{
		result=true;
		}
	else
		{
		TextError=Merc->ErrMessage;
		result=false;
		}


	hr=Merc->QueryResourceInfo(false);
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	result=true;
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------
bool  ProvVosmPrintCheck(void)
{
bool result=true;
try
	{
	if (GetSostKKM()==true)
		{
		//ShowMessage("Открыта крышка принтера "+Merc->CheckDevStatus(13));
	   //	int i=0;
	   //ShowMessage("Крышка принтера: "+IntToStr(Merc->CheckEcrStatus(MERC_DS_OPENED_COVER))) ;
	   //	ShowMessage("Чековая лента: "+IntToStr(Merc->CheckEcrStatus(MERC_DS_RECEIPT_OUT))) ;
	   //	ShowMessage(IntToHex(Merc->EcrStatus

		switch (Merc->DevStatus)
        {
		case MERC_DS_OPENED_COVER :      //идет печать предыдущей команды
                {
				ShowMessage("Открыта крышка принтера! MERC_DS_OPENED_COVER");
                result=false;
                return result;
                }

        case MERC_DS_PRINTER_ERROR :      //идет печать предыдущей команды
                {
                ShowMessage("Ошибка принтера! MERC_DS_PRINTER_ERROR");
                result=false;
                return result;
                }

        case MERC_DS_MECHANICAL_ERROR :      //идет печать предыдущей команды
                {
                ShowMessage("Ошибка  механики принтера! MERC_DS_MECHANICAL_ERROR");
                result=false;
                return result;
                }

        case MERC_DS_CUTTER_ERROR :      //идет печать предыдущей команды
                {
                ShowMessage("Ошибка  отрезчика! MERC_DS_CUTTER_ERROR");
                result=false;
                return result;
                }

        case MERC_DS_FATAL_ERROR :      //идет печать предыдущей команды
                {
                ShowMessage("Критическая ошибка принтера! MERC_DS_FATAL_ERROR");
                result=false;
                return result;
                }

        case MERC_DS_OVERHEATING :      //идет печать предыдущей команды
                {
                ShowMessage("Перегрев печатающей головки! MERC_DS_OVERHEATING ");
                result=false;
                return result;
                }

        case MERC_DS_JOURNAL_OUT :      //идет печать предыдущей команды
                {
                ShowMessage("Нет контрольной ленты! MERC_DS_JOURNAL_OUT");
                result=false;
                return result;
                }

        case MERC_DS_RECEIPT_OUT :      //идет печать предыдущей команды
                {
                ShowMessage("Нет чековой ленты! MERC_DS_RECEIPT_OUT");
                result=false;
                return result;
                } 

        default :
                {


                } break;

        }


	if (Merc->DocStatus!=mdsClosed)
		{
		Merc->CancelFiscalDoc(false);
		}

		result=true;
		}
	else
		{
		result=false;
		}
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}

return result;

}
//---------------------------------------------------------------------------
int GetNumberCheck(void)
{
int result=0;
try
	{
	result=Merc->LastRecNumber;
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=0;
		}
return result;

}
//---------------------------------------------------------------------------
int  GetNumberKL(void)
{
int result=0;

try
	{
	result=Merc->LastDayClosing+1;
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=0;
		}

return result;

}
//---------------------------------------------------------------------------
WideString  GetSerialNumberKKM(void)
{
WideString result="";
AnsiString num="";

try
	{
	num=Merc->SerialNumber;
	num=num+" ";
	result=num;
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result="";
		}
return result;

}
//---------------------------------------------------------------------------
WideString  GetRegNumberKKM(void)
{
WideString result="";
AnsiString num="";
try
	{
	num=Merc->QueryRegNumber();
	num=num+" ";
	result=num;
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result="";
		}
return result;

}
//---------------------------------------------------------------------------
WideString  GetModelKKM(void)
{
WideString result="";
AnsiString num="Меркурий MS-K ";
result=num;

return result;

}
//----------------------------------------------------------------------------
bool   OpenNoFiscalCheck(void)
{
bool result=false;
HRESULT hr;
try
	{
	hr=Merc->PrintNonFiscal(WideString("").c_bstr(), true,false);
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	result=true;
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}
return result;
}
//---------------------------------------------------------------------------
bool   CloseNoFiscalCheck(void)
{
bool result=true;
HRESULT hr;
TextError="";
try
	{
	hr=Merc->PrintNonFiscal(WideString("").c_bstr(), false,true);
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	if (Merc->ErrCode==0)
		{
		result=true;
		}
	else
		{
		TextError=Merc->ErrMessage;
		result=false;
		}
	//OpenDrawer();
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}
return result;

}
//---------------------------------------------------------------------------
bool  PrintString(WideString str,
                                                int size_font,       //1234
                                                int style,           //1-жирный 0 обычный   2 курсив 3 жирный курсив
                                                int alignment,       //0 лево 1 центр 2 право
												bool ch_lenta,       //на чековой ленте
												bool kontr_lenta,    //на контрольной ленте
												bool word_wrap)
{
bool result=false;
AnsiString s=AnsiString(str);

int kol_symbol=0;

//перенос по словам
//*********************************************************************

if (word_wrap==true)
	{
	TStringList * strings=new TStringList();
		switch (size_font)
				{
				case  1:
						{kol_symbol=40;break;}
				case  2:
						{kol_symbol=40;break;}
				case  3:
						{kol_symbol=14;break;}
				case  4:    
						{kol_symbol=14;break;}
				}

	s=WrapText(s,kol_symbol);
	strings->Text=s;

	for (int i=0;i<strings->Count;i++)
		{
		AnsiString print_str=strings->Strings[i];
		if (PrintString(print_str.c_str(),size_font,style,alignment,ch_lenta,kontr_lenta, false)==true)
			{
			result=true;
			}
		else
			{
			result=false;
			}
		}
	delete strings;
	return result;

	}

// ***************************************************************************

try
	{
	if (ConnectFR==false){return result;}

        switch ( size_font)
                {
                case  1:
						{
						s=" "+s;
						if(s.Length()>40) s=s.SetLength(40);
                        switch ( alignment)
                                {
								case  0:      //лево
                                        {
										if (s.Length()>=40)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        break;
                                        }
                                case  1:    //центр
                                        {
                                        if (s.Length()>=40)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 40-((40-s.Length())/2));
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
                                        if (s.Length()>=40)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 40);
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }


                                }
                        break;
                        }
                case  2:
						{
						s=" "+s;
						if(s.Length()>40) s=s.SetLength(40);
                        switch ( alignment)
                                {
                                case  0:      //лево
                                        {
                                        if (s.Length()>=40)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        break;
                                        }
                                case  1:    //центр
                                        {
                                        if (s.Length()>=40)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 40-((40-s.Length())/2));
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
                                        if (s.Length()>=40)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 40);
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }


                                }
                        break;
                        }
                case  3:
						{
						if(s.Length()>14) s=s.SetLength(14);
                        switch ( alignment)
                                {
                                case  0:      //лево
                                        {
                                        if (s.Length()>=14)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        break;
                                        }
                                case  1:    //центр
                                        {
                                        if (s.Length()>=14)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 14-((14-s.Length())/2));
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
                                        if (s.Length()>=14)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 14);
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }


                                }

                        break;
                        }
                case  4:
						{
						if(s.Length()>14) s=s.SetLength(14);
                        switch ( alignment)
                                {
                                case  0:      //лево
                                        {
                                        if (s.Length()>=14)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        break;
                                        }
                                case  1:    //центр
                                        {
                                        if (s.Length()>=14)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 14-((14-s.Length())/2));
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
                                        if (s.Length()>=14)
                                                {
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }
                                        else
                                                {
                                                s=DopStrL(s, " ", 14);
                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }


                                }
                        break;
                        }


                }
        
	result=true;
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}

return result;

}
//---------------------------------------------------------------------------
bool  PrintLine(void)
{
bool result=false;

try
	{
	Merc->PrintNonFiscal(WideString("\\1b\\21\\----------------------------------------\\0d\\0a").c_bstr(), false,false);
	result=true;
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}
return result;

}
//---------------------------------------------------------------------------


bool  PrintFiscalCheck(double sum,
						int department,
						double oplata_nal,
						double oplata_bank_card,
						double oplata_plat_card,
						double oplata_credit_card,
						int operation)    //0 продажа 1 возврат
{
bool result=false;
if (operation==0) // Составной чек на продажу
		{
		result=PrintFiscalCheckSale(sum,
									 department,
									 oplata_nal,
									 oplata_bank_card,
									 oplata_plat_card,
									 oplata_credit_card,
									 operation);    //0 продажа 1 возврат
		}
else
		{
		result=PrintFiscalCheckReturnSale(sum,
									 department,
									 oplata_nal,
									 oplata_bank_card,
									 oplata_plat_card,
									 oplata_credit_card,
									 operation);    //0 продажа 1 возврат
		}

return result;
}
//---------------------------------------------------------------------------
bool  PrintFiscalCheckSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation)    //0 продажа 1 возврат
{
bool result=false;
HRESULT hr;
NoPrint=false;


if (ConnectFR==false){return result;}

double sum_opl=oplata_nal+oplata_bank_card+oplata_plat_card+oplata_credit_card;
if (CompareDoubleValue(sum_opl, sum, 3) == -1)
        {
		TextError="Сумма оплаты меньше суммы чека!";
        return result;
        }

//проверим открыта ли смена
if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
        {
        try
                {
				hr=Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
				if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
				}
        catch(...)
                {
                result=false;
				return result;
                }
		}


hr=Merc->OpenFiscalDoc(motSale);
if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}


  try
  {
	// Счетчик вертикальной координаты
	int IV = 0;
//    MSK->AddCustom("ВСЕГО:", 0, 0, IV); IV++;

	 Variant vopl1=oplata_nal ;
	 Variant vopl4=oplata_bank_card+oplata_plat_card+oplata_credit_card;
	// Добавляем итог
	hr=Merc->AddTotal(0, 0, IV, 0); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}


	// Добавляем информацию об оплате
	hr=Merc->AddPay(
	  mptCashCard,      // - оплата: наличные + платежная карта
	  vopl1,             // - сумма оплаты наличными
	  vopl4,               // - сумма оплаты по безналу
	  WideString(" ").c_bstr(),               // - дополнительная информация по оплате - игнорируется для комбинированной
						//   оплаты
	  0,
	  0,
	  IV,
	   0); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}


	// Добавляем сумму сдачи
	hr=Merc->AddChange(0, 0, IV++, 0);
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

	// Добавляем строки заголовка
	hr=Merc->AddHeaderLine(1, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
//    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(4, 0, 0, IV); IV++;

    // Добавляем позицию
	// - наименование товара, как дополнительный реквизит
	Variant vSumCheck=sum;

	hr=Merc->AddItem(
	  mitItem,          // - услуга или товар
	  vSumCheck,              // - цена товара
	  false,            // - товар не является тарой
	  1,                // - номер отдела
	  0,              // - код товара
	  0,                // - игнорируется
      1, 0,             // - количество = 2 (нет знаков после десятичной точки)
	  0,                // - индекс налоговой группы
      WideString(" ").c_bstr(),            // - единица измерения
	  0,                // - флаги
	  0,                // - смещение по вертикали
	  IV,               // - смещение по горизонтали
	  0                 // - игнорируется
	); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

    // Добавляем номер ККМ и номер документа (на одной строке)
	hr=Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Добавляем ИНН
	hr=Merc->AddTaxPayerNumber(0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Добавляем дату / время и номер чека (на одной строке)
	hr=Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	// Добавляем информацию об операторе
	hr=Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

	// Закрываем документ
	hr=Merc->CloseFiscalDoc();
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}


	OpenDrawer();
	result=true;
  }
  catch(Exception &E)            //Exception &E
  {
	// В случае ошибки отменяем открытый документ
	Merc->CancelFiscalDoc(false);
	TextError=E.Message;
	result=false;
  }


return result;

}
//---------------------------------------------------------------------------
bool  PrintFiscalCheckReturnSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation)    //0 продажа 1 возврат
{
bool result=false;
HRESULT hr;


//проверим открыта ли смена
if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
        {
        try
                {
				hr=Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
				if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
				}
        catch(...)
                {
                result=false;
				return result;
                }
		}


  // Составной чек на возврат
  hr=Merc->OpenFiscalDoc(motRefund);
  if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
  try
  {
    // Счетчик вертикальной координаты
	int IV = 0;
     Variant vopl1=oplata_nal ;
	 Variant vopl4=oplata_bank_card+oplata_plat_card+oplata_credit_card;

	// Добавляем информацию об оплате
//	hr=Merc->AddPay(
//	  mptCashCard,      // - оплата: наличные + платежная карта
//	  vopl1,             // - сумма оплаты наличными
//	  vopl4,               // - сумма оплаты по безналу
//	  WideString(" ").c_bstr(),               // - дополнительная информация по оплате - игнорируется для комбинированной
//						//   оплаты
//	  0,
//	  0,
//	  IV,
//	   0); IV++;
//	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}


	// Добавляем сумму сдачи
//	hr=Merc->AddChange(0, 0, IV++, 0);
//	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

	// Добавляем строки заголовка
	hr=Merc->AddHeaderLine(1, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}



	// Добавляем номер ККМ и номер документа (на одной строке)
	hr=Merc->AddSerialNumber(0, 0, IV); Merc->AddDocNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Добавляем ИНН
	hr=Merc->AddTaxPayerNumber(0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	// Добавляем дату / время и номер чека (на одной строке)
	hr=Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Добавляем информацию об операторе
	hr=Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Добавляем позицию
	// - наименование товара, как дополнительный реквизит
   //	Merc->AddCustom("Какой-то товар", 0, 0, IV); IV++;

	Variant vSumCheck=sum;
	hr=Merc->AddItem(
	  mitItem,          // - услуга или товар
	  vSumCheck,              // - цена товара
	  false,            // - товар не является тарой
	  1,                // - номер отдела
	  0,              // - код товара
	  0,                // - игнорируется
      1, 0,             // - количество = 2 (нет знаков после десятичной точки)
	  0,                // - индекс налоговой группы
      WideString(" ").c_bstr(),            // - единица измерения
	  0,                // - флаги
	  0,                // - смещение по вертикали
	  IV,               // - смещение по горизонтали
	  0                 // - игнорируется
	); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	// Добавляем итог
	hr=Merc->AddTotal(0, 0, IV++, 0);
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	// Закрываем документ
	hr=Merc->CloseFiscalDoc();
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	
	OpenDrawer();
	result=true;
  }
  catch(Exception &E)            //Exception &E
  {
  // В случае ошибки отменяем открытый документ
  Merc->CancelFiscalDoc(false);
  TextError=E.Message;
  result=false;
  }

return result;

}
//---------------------------------------------------------------------------
bool  PrintNoFiscalCheck(double sum,
                                int department,
                                double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
                                int operation)    //0 продажа 1 возврат
{
bool result=false;

try
	{
	NoPrint=false;

	if (ConnectFR==false){return result;}

	double sum_opl=oplata_nal+oplata_bank_card+oplata_plat_card+oplata_credit_card;

	if (CompareDoubleValue(sum_opl, sum, 3) == -1)
        {
        TextError="Сумма оплаты меньше суммы чека!";
        return result;
        }

	Merc->PrintNonFiscal(WideString("------------------------------------\r\n").c_bstr(), true,true);
	Merc->PrintNonFiscal(WideString("Учебный чек напечатан!\r\n").c_bstr(), true,true);


	for(int i=0;i<20;i++)
        {
        Merc->PrintNonFiscal(WideString(" \r\n").c_bstr(), true,true);
        }
	result=true;
	OpenDrawer();
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}
return result;

}
//---------------------------------------------------------------------------
bool  PrintXReport(void)
{
bool result=false;
HRESULT hr;
NoPrint=false;
try
	{
	//проверим открыта ли смена
	if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
		{
		Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
		}
		hr=Merc->XReport(1);
		if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
		result=true;
		OpenDrawer();
	 }
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}

return result;

}
//---------------------------------------------------------------------------
bool PrintZReport(void)
{
bool result=false;
HRESULT hr;
NoPrint=false;

try
	{
	if (ConnectFR==true)
		{
		//проверим открыта ли смена
		if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
			{
				Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
			}

			hr=Merc->ZReport(MERC_REPF_NO_ZEROES && MERC_REPF_ACCUMULATE_DEP);
			if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
			result=true;
			OpenDrawer();
		}
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}


return result;

}
//---------------------------------------------------------------------------
bool  PrintPoOtdelamReport(void)
{
bool result=false;
NoPrint=false;
HRESULT hr;
try
	{
	if (ConnectFR==true)
		{
		//проверим открыта ли смена
		if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
			{
				Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
			}

			hr=Merc->XReportByDep(-1,MERC_REPF_NO_ZEROES && MERC_REPF_ACCUMULATE_DEP);
			if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
			result=true;
			OpenDrawer();
		}

	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}
return result; 
}
//---------------------------------------------------------------------------

bool  Cut(int TypeCut)
{
bool result=true ;
HRESULT hr;

try
	{
	if (ConnectFR==true)
		{
		hr=Merc->FeedAndCut(1,true);
		if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
		result=true;
		}
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}

return result;

}
//---------------------------------------------------------------------------

bool  Vnesenie(double sum)
{
bool result=false;
HRESULT hr;
if (ConnectFR==true)
        {



  try
  {

        //проверим открыта ли смена
       // if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
       //         {
       //         Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
       //         }



	hr=Merc->OpenFiscalDoc(motCashIn);
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Счетчик вертикальной координаты
    int IV = 0;

//     Variant vopl1=opl1;
//     Variant vopl4=opl4;
    // Добавляем итог
	hr=Merc->AddTotal(MERC_PROPF_DOUBLE_HEIGHT, 0, IV, 0); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}


    // Добавляем строки заголовка
	hr=Merc->AddHeaderLine(1, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
//    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(4, 0, 0, IV); IV++;

    // Добавляем позицию
    // - наименование товара, как дополнительный реквизит
    Variant vSumCheck=sum;

	hr=Merc->AddItem(
      mitItem,          // - услуга или товар
      vSumCheck,              // - цена товара
      false,            // - товар не является тарой
      1,                // - номер отдела
      0,              // - код товара
      0,                // - игнорируется
      1, 0,             // - количество = 2 (нет знаков после десятичной точки)
      0,                // - индекс налоговой группы
      WideString(" ").c_bstr(),            // - единица измерения
      0,                // - флаги
      0,                // - смещение по вертикали
      IV,               // - смещение по горизонтали
      0                 // - игнорируется
    ); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Добавляем номер ККМ и номер документа (на одной строке)
	hr=Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Добавляем ИНН
	hr=Merc->AddTaxPayerNumber(0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Добавляем дату / время и номер чека (на одной строке)
	hr=Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Добавляем информацию об операторе
	hr=Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

    // Закрываем документ
	hr=Merc->CloseFiscalDoc();
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	result=true;
	OpenDrawer();
  }
  catch(Exception &E)            //Exception &E
  {
	// В случае ошибки отменяем открытый документ
	Merc->CancelFiscalDoc(false);
	result=false;
	TextError=E.Message;
  }
		}
return result;

}
//---------------------------------------------------------------------------
bool  Snatie(double sum)
{
bool result=false;
HRESULT hr;
if (ConnectFR==true)
        {



  try
  {
        //проверим открыта ли смена
        //if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
        //        {
        //        Merc->OpenDay(1, WideString("Кассир").c_bstr(), false, Merc->Protocol);
        //        }
	hr=Merc->OpenFiscalDoc(motCashOut);
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Счетчик вертикальной координаты
    int IV = 0;

//     Variant vopl1=opl1;
//     Variant vopl4=opl4;
    // Добавляем итог
	hr=Merc->AddTotal(MERC_PROPF_DOUBLE_HEIGHT, 0, IV, 0); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}


    // Добавляем строки заголовка
	hr=Merc->AddHeaderLine(1, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
//    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(4, 0, 0, IV); IV++;

    // Добавляем позицию
    // - наименование товара, как дополнительный реквизит
    Variant vSumCheck=sum;

	hr=Merc->AddItem(
      mitItem,          // - услуга или товар
      vSumCheck,              // - цена товара
      false,            // - товар не является тарой
      1,                // - номер отдела
      0,              // - код товара
      0,                // - игнорируется
      1, 0,             // - количество = 2 (нет знаков после десятичной точки)
      0,                // - индекс налоговой группы
      WideString(" ").c_bstr(),            // - единица измерения
      0,                // - флаги
      0,                // - смещение по вертикали
      IV,               // - смещение по горизонтали
      0                 // - игнорируется
    ); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Добавляем номер ККМ и номер документа (на одной строке)
	hr=Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Добавляем ИНН
	hr=Merc->AddTaxPayerNumber(0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Добавляем дату / время и номер чека (на одной строке)
	hr=Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // Добавляем информацию об операторе
	hr=Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

    // Закрываем документ
	hr=Merc->CloseFiscalDoc();
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	result=true;
	OpenDrawer();
  }
  catch(Exception &E)            //Exception &E
  {
	// В случае ошибки отменяем открытый документ
	Merc->CancelFiscalDoc(false);
	result=false;
	TextError=E.Message;
  }
        }


return result;

}
//---------------------------------------------------------------------------
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
//--------------------------------------------------------------------------
WideString  GetTimeKKM(void)
{
WideString result="";
try
	{
	AnsiString time=TimeToStr(Merc->QueryEcrDateTime())+" ";
	result=time;
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result="";
		}
return result;

}
//-----------------------------------------------------------------------------
WideString  GetDateKKM(void)
{
WideString result="";
try
	{
	AnsiString date=DateToStr(Merc->QueryEcrDateTime())+" ";
	result=date;
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result="";
		}
return result;

}
//--------------------------------------------------------------------------
bool  SetTimeKKM(WideString time)
{
bool result=false;
HRESULT hr;

try
	{
	if (ConnectFR==true)
		{
		hr=Merc->SynchronizeEcrDateTime();
		if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
		result=true;
		}
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}


return result;
}
//-----------------------------------------------------------------------------
bool  SetDateKKM(WideString date)
{
bool result=false;
HRESULT hr;

try
	{
	if (ConnectFR==true)
		{
		hr=Merc->SynchronizeEcrDateTime();
		if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
		result=true;
		}
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}

return result;
}
//-----------------------------------------------------------------------------
void OpenDrawer(void)
{
HRESULT hr;
hr=Merc->ExternalPulse(1,10,10,1);
if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
}
//-----------------------------------------------------------------------------
int CompareDoubleValue(double v1, double v2, int pogr)
{
int result=0;

if (fabs(v1-v2) < pow(0.1,pogr))
	{
	result=0;
	}
else
	{
	 if (v1 > v2)
		{
		result=1;
		}
	 else
		{
        result=-1;
		}

	}


return result;
}
//---------------------------------------------------------------------------
