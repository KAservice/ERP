

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
                                                int style,           //1-������ 0 �������   2 ������ 3 ������ ������
                                                int alignment,       //0 ���� 1 ����� 2 �����
                                                bool ch_lenta,       //�� ������� �����
												bool kontr_lenta,    //�� ����������� �����
												bool word_wrap);

extern "C" bool __declspec (dllexport) PrintLine(void);


extern "C" bool __declspec (dllexport) PrintFiscalCheck(double sum,
                                                        int department,
                                                        double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
                                                        int operation);    //0 ������� 1 �������

bool  PrintFiscalCheckSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation);    //0 ������� 1 �������
bool  PrintFiscalCheckReturnSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation);    //0 ������� 1 �������


extern "C" bool __declspec (dllexport) PrintNoFiscalCheck(double sum,
                                int department,
                                double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
                                int operation);    //0 ������� 1 �������

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
//		TextError="�� ������� ������� ������ ����������� ������������ !";
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
	        TextError="�� �������� CLSID";
	        //return ;
        }
        else
                {
                //ShowMessage("�������� CKSID");
                }
//------------------------------------------------------------

        hr = CoGetClassObject( clsid, CLSCTX_INPROC, NULL,IID_IClassFactory, (void**) &pCF );
        if ( FAILED( hr ))
        {
        TextError="�� ����������� � ��������";
        }
        else
                {
                //ShowMessage("����������� � ��������");
                }

//------------------------------------------------------

        hr = pCF->CreateInstance( NULL, IID_IUnknown, (void**) &pUnk );
        pCF->Release();
        if ( FAILED( hr ))
        {
	TextError="�� ������� ���������";
        }
        else
                {
                //ShowMessage("������� ���������");
                 }

//--------------------------------------------------
        Merc = NULL;


        hr = pUnk->QueryInterface( IID_IMercuryFPrt7, (void**) &Merc);
        pUnk->Release();


        if ( FAILED( hr ))
			{
			TextError="�� ������� ������� ���������";
			}
		else
                {
                //ShowMessage("������� ������� ���������");
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
        TextError="�� ������� ������������ � ��! ������: "+E.Message;
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
		//ShowMessage("������� ������ �������� "+Merc->CheckDevStatus(13));
	   //	int i=0;
	   //ShowMessage("������ ��������: "+IntToStr(Merc->CheckEcrStatus(MERC_DS_OPENED_COVER))) ;
	   //	ShowMessage("������� �����: "+IntToStr(Merc->CheckEcrStatus(MERC_DS_RECEIPT_OUT))) ;
	   //	ShowMessage(IntToHex(Merc->EcrStatus

		switch (Merc->DevStatus)
        {
		case MERC_DS_OPENED_COVER :      //���� ������ ���������� �������
                {
				ShowMessage("������� ������ ��������! MERC_DS_OPENED_COVER");
                result=false;
                return result;
                }

        case MERC_DS_PRINTER_ERROR :      //���� ������ ���������� �������
                {
                ShowMessage("������ ��������! MERC_DS_PRINTER_ERROR");
                result=false;
                return result;
                }

        case MERC_DS_MECHANICAL_ERROR :      //���� ������ ���������� �������
                {
                ShowMessage("������  �������� ��������! MERC_DS_MECHANICAL_ERROR");
                result=false;
                return result;
                }

        case MERC_DS_CUTTER_ERROR :      //���� ������ ���������� �������
                {
                ShowMessage("������  ���������! MERC_DS_CUTTER_ERROR");
                result=false;
                return result;
                }

        case MERC_DS_FATAL_ERROR :      //���� ������ ���������� �������
                {
                ShowMessage("����������� ������ ��������! MERC_DS_FATAL_ERROR");
                result=false;
                return result;
                }

        case MERC_DS_OVERHEATING :      //���� ������ ���������� �������
                {
                ShowMessage("�������� ���������� �������! MERC_DS_OVERHEATING ");
                result=false;
                return result;
                }

        case MERC_DS_JOURNAL_OUT :      //���� ������ ���������� �������
                {
                ShowMessage("��� ����������� �����! MERC_DS_JOURNAL_OUT");
                result=false;
                return result;
                }

        case MERC_DS_RECEIPT_OUT :      //���� ������ ���������� �������
                {
                ShowMessage("��� ������� �����! MERC_DS_RECEIPT_OUT");
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
AnsiString num="�������� MS-K ";
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
                                                int style,           //1-������ 0 �������   2 ������ 3 ������ ������
                                                int alignment,       //0 ���� 1 ����� 2 �����
												bool ch_lenta,       //�� ������� �����
												bool kontr_lenta,    //�� ����������� �����
												bool word_wrap)
{
bool result=false;
AnsiString s=AnsiString(str);

int kol_symbol=0;

//������� �� ������
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
								case  0:      //����
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
                                case  1:    //�����
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
                                case  2:   //�����
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
                                case  0:      //����
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
                                case  1:    //�����
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
                                case  2:   //�����
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
                                case  0:      //����
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
                                case  1:    //�����
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
                                case  2:   //�����
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
                                case  0:      //����
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
                                case  1:    //�����
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
                                case  2:   //�����
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
						int operation)    //0 ������� 1 �������
{
bool result=false;
if (operation==0) // ��������� ��� �� �������
		{
		result=PrintFiscalCheckSale(sum,
									 department,
									 oplata_nal,
									 oplata_bank_card,
									 oplata_plat_card,
									 oplata_credit_card,
									 operation);    //0 ������� 1 �������
		}
else
		{
		result=PrintFiscalCheckReturnSale(sum,
									 department,
									 oplata_nal,
									 oplata_bank_card,
									 oplata_plat_card,
									 oplata_credit_card,
									 operation);    //0 ������� 1 �������
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
														int operation)    //0 ������� 1 �������
{
bool result=false;
HRESULT hr;
NoPrint=false;


if (ConnectFR==false){return result;}

double sum_opl=oplata_nal+oplata_bank_card+oplata_plat_card+oplata_credit_card;
if (CompareDoubleValue(sum_opl, sum, 3) == -1)
        {
		TextError="����� ������ ������ ����� ����!";
        return result;
        }

//�������� ������� �� �����
if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
        {
        try
                {
				hr=Merc->OpenDay(1, WideString("������ ").c_bstr(), false, Merc->Protocol);
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
	// ������� ������������ ����������
	int IV = 0;
//    MSK->AddCustom("�����:", 0, 0, IV); IV++;

	 Variant vopl1=oplata_nal ;
	 Variant vopl4=oplata_bank_card+oplata_plat_card+oplata_credit_card;
	// ��������� ����
	hr=Merc->AddTotal(0, 0, IV, 0); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}


	// ��������� ���������� �� ������
	hr=Merc->AddPay(
	  mptCashCard,      // - ������: �������� + ��������� �����
	  vopl1,             // - ����� ������ ���������
	  vopl4,               // - ����� ������ �� �������
	  WideString(" ").c_bstr(),               // - �������������� ���������� �� ������ - ������������ ��� ���������������
						//   ������
	  0,
	  0,
	  IV,
	   0); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}


	// ��������� ����� �����
	hr=Merc->AddChange(0, 0, IV++, 0);
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

	// ��������� ������ ���������
	hr=Merc->AddHeaderLine(1, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
//    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(4, 0, 0, IV); IV++;

    // ��������� �������
	// - ������������ ������, ��� �������������� ��������
	Variant vSumCheck=sum;

	hr=Merc->AddItem(
	  mitItem,          // - ������ ��� �����
	  vSumCheck,              // - ���� ������
	  false,            // - ����� �� �������� �����
	  1,                // - ����� ������
	  0,              // - ��� ������
	  0,                // - ������������
      1, 0,             // - ���������� = 2 (��� ������ ����� ���������� �����)
	  0,                // - ������ ��������� ������
      WideString(" ").c_bstr(),            // - ������� ���������
	  0,                // - �����
	  0,                // - �������� �� ���������
	  IV,               // - �������� �� �����������
	  0                 // - ������������
	); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

    // ��������� ����� ��� � ����� ��������� (�� ����� ������)
	hr=Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ��������� ���
	hr=Merc->AddTaxPayerNumber(0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ��������� ���� / ����� � ����� ���� (�� ����� ������)
	hr=Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	// ��������� ���������� �� ���������
	hr=Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

	// ��������� ��������
	hr=Merc->CloseFiscalDoc();
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}


	OpenDrawer();
	result=true;
  }
  catch(Exception &E)            //Exception &E
  {
	// � ������ ������ �������� �������� ��������
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
														int operation)    //0 ������� 1 �������
{
bool result=false;
HRESULT hr;


//�������� ������� �� �����
if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
        {
        try
                {
				hr=Merc->OpenDay(1, WideString("������ ").c_bstr(), false, Merc->Protocol);
				if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
				}
        catch(...)
                {
                result=false;
				return result;
                }
		}


  // ��������� ��� �� �������
  hr=Merc->OpenFiscalDoc(motRefund);
  if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
  try
  {
    // ������� ������������ ����������
	int IV = 0;
     Variant vopl1=oplata_nal ;
	 Variant vopl4=oplata_bank_card+oplata_plat_card+oplata_credit_card;

	// ��������� ���������� �� ������
//	hr=Merc->AddPay(
//	  mptCashCard,      // - ������: �������� + ��������� �����
//	  vopl1,             // - ����� ������ ���������
//	  vopl4,               // - ����� ������ �� �������
//	  WideString(" ").c_bstr(),               // - �������������� ���������� �� ������ - ������������ ��� ���������������
//						//   ������
//	  0,
//	  0,
//	  IV,
//	   0); IV++;
//	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}


	// ��������� ����� �����
//	hr=Merc->AddChange(0, 0, IV++, 0);
//	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

	// ��������� ������ ���������
	hr=Merc->AddHeaderLine(1, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}



	// ��������� ����� ��� � ����� ��������� (�� ����� ������)
	hr=Merc->AddSerialNumber(0, 0, IV); Merc->AddDocNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ��������� ���
	hr=Merc->AddTaxPayerNumber(0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	// ��������� ���� / ����� � ����� ���� (�� ����� ������)
	hr=Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ��������� ���������� �� ���������
	hr=Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ��������� �������
	// - ������������ ������, ��� �������������� ��������
   //	Merc->AddCustom("�����-�� �����", 0, 0, IV); IV++;

	Variant vSumCheck=sum;
	hr=Merc->AddItem(
	  mitItem,          // - ������ ��� �����
	  vSumCheck,              // - ���� ������
	  false,            // - ����� �� �������� �����
	  1,                // - ����� ������
	  0,              // - ��� ������
	  0,                // - ������������
      1, 0,             // - ���������� = 2 (��� ������ ����� ���������� �����)
	  0,                // - ������ ��������� ������
      WideString(" ").c_bstr(),            // - ������� ���������
	  0,                // - �����
	  0,                // - �������� �� ���������
	  IV,               // - �������� �� �����������
	  0                 // - ������������
	); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	// ��������� ����
	hr=Merc->AddTotal(0, 0, IV++, 0);
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	// ��������� ��������
	hr=Merc->CloseFiscalDoc();
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	
	OpenDrawer();
	result=true;
  }
  catch(Exception &E)            //Exception &E
  {
  // � ������ ������ �������� �������� ��������
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
                                int operation)    //0 ������� 1 �������
{
bool result=false;

try
	{
	NoPrint=false;

	if (ConnectFR==false){return result;}

	double sum_opl=oplata_nal+oplata_bank_card+oplata_plat_card+oplata_credit_card;

	if (CompareDoubleValue(sum_opl, sum, 3) == -1)
        {
        TextError="����� ������ ������ ����� ����!";
        return result;
        }

	Merc->PrintNonFiscal(WideString("------------------------------------\r\n").c_bstr(), true,true);
	Merc->PrintNonFiscal(WideString("������� ��� ���������!\r\n").c_bstr(), true,true);


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
	//�������� ������� �� �����
	if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
		{
		Merc->OpenDay(1, WideString("������ ").c_bstr(), false, Merc->Protocol);
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
		//�������� ������� �� �����
		if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
			{
				Merc->OpenDay(1, WideString("������ ").c_bstr(), false, Merc->Protocol);
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
		//�������� ������� �� �����
		if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
			{
				Merc->OpenDay(1, WideString("������ ").c_bstr(), false, Merc->Protocol);
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

        //�������� ������� �� �����
       // if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
       //         {
       //         Merc->OpenDay(1, WideString("������ ").c_bstr(), false, Merc->Protocol);
       //         }



	hr=Merc->OpenFiscalDoc(motCashIn);
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ������� ������������ ����������
    int IV = 0;

//     Variant vopl1=opl1;
//     Variant vopl4=opl4;
    // ��������� ����
	hr=Merc->AddTotal(MERC_PROPF_DOUBLE_HEIGHT, 0, IV, 0); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}


    // ��������� ������ ���������
	hr=Merc->AddHeaderLine(1, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
//    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(4, 0, 0, IV); IV++;

    // ��������� �������
    // - ������������ ������, ��� �������������� ��������
    Variant vSumCheck=sum;

	hr=Merc->AddItem(
      mitItem,          // - ������ ��� �����
      vSumCheck,              // - ���� ������
      false,            // - ����� �� �������� �����
      1,                // - ����� ������
      0,              // - ��� ������
      0,                // - ������������
      1, 0,             // - ���������� = 2 (��� ������ ����� ���������� �����)
      0,                // - ������ ��������� ������
      WideString(" ").c_bstr(),            // - ������� ���������
      0,                // - �����
      0,                // - �������� �� ���������
      IV,               // - �������� �� �����������
      0                 // - ������������
    ); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ��������� ����� ��� � ����� ��������� (�� ����� ������)
	hr=Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ��������� ���
	hr=Merc->AddTaxPayerNumber(0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ��������� ���� / ����� � ����� ���� (�� ����� ������)
	hr=Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ��������� ���������� �� ���������
	hr=Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

    // ��������� ��������
	hr=Merc->CloseFiscalDoc();
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	result=true;
	OpenDrawer();
  }
  catch(Exception &E)            //Exception &E
  {
	// � ������ ������ �������� �������� ��������
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
        //�������� ������� �� �����
        //if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
        //        {
        //        Merc->OpenDay(1, WideString("������").c_bstr(), false, Merc->Protocol);
        //        }
	hr=Merc->OpenFiscalDoc(motCashOut);
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ������� ������������ ����������
    int IV = 0;

//     Variant vopl1=opl1;
//     Variant vopl4=opl4;
    // ��������� ����
	hr=Merc->AddTotal(MERC_PROPF_DOUBLE_HEIGHT, 0, IV, 0); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}


    // ��������� ������ ���������
	hr=Merc->AddHeaderLine(1, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
//    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
//    MSK->AddHeaderLine(4, 0, 0, IV); IV++;

    // ��������� �������
    // - ������������ ������, ��� �������������� ��������
    Variant vSumCheck=sum;

	hr=Merc->AddItem(
      mitItem,          // - ������ ��� �����
      vSumCheck,              // - ���� ������
      false,            // - ����� �� �������� �����
      1,                // - ����� ������
      0,              // - ��� ������
      0,                // - ������������
      1, 0,             // - ���������� = 2 (��� ������ ����� ���������� �����)
      0,                // - ������ ��������� ������
      WideString(" ").c_bstr(),            // - ������� ���������
      0,                // - �����
      0,                // - �������� �� ���������
      IV,               // - �������� �� �����������
      0                 // - ������������
    ); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ��������� ����� ��� � ����� ��������� (�� ����� ������)
	hr=Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ��������� ���
	hr=Merc->AddTaxPayerNumber(0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ��������� ���� / ����� � ����� ���� (�� ����� ������)
	hr=Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
    // ��������� ���������� �� ���������
	hr=Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

    // ��������� ��������
	hr=Merc->CloseFiscalDoc();
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	result=true;
	OpenDrawer();
  }
  catch(Exception &E)            //Exception &E
  {
	// � ������ ������ �������� �������� ��������
	Merc->CancelFiscalDoc(false);
	result=false;
	TextError=E.Message;
  }
        }


return result;

}
//---------------------------------------------------------------------------
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
