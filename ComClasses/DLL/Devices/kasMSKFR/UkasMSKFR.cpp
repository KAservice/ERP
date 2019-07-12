//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UkasMSKFR.h"
#include <math.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)




//-------------------------------------------------------------------
TkasMSKFR::TkasMSKFR()
{
InterfaceMainObject=0;
InterfaceOwnerObject=0;
bool UseJournalRibbon=true;
bool UseReceiptRibbon=true;
bool OpenNoFiscalDoc=false;

Modul="";
ConnectFR=false;
TextErrorNoConnect="��� �� ����������!";

KolSymbolSize1=40;
KolSymbolSize1Girn=40;
KolSymbolSize2=40;
KolSymbolSize2Girn=40;
KolSymbolSize3=14;
KolSymbolSize3Girn=14;
KolSymbolSize4=14;
KolSymbolSize4Girn=14;
}
//-----------------------------------------------------------------------------
TkasMSKFR::~TkasMSKFR()
{
//FreeLibrary(dllIn);
}
//---------------------------------------------------------------------------
int TkasMSKFR::Init()
{


return -1;
}
//----------------------------------------------------------------------------
int TkasMSKFR::Done()
{

return -1;
}

//---------------------------------------------------------------------------


bool  TkasMSKFR::Connect(int number_port,
				UnicodeString baud_rate,
				UnicodeString password)
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
		UnicodeString prog_id=L"Incotex.MercuryFPrtCOM";

		HRESULT hr = ::CLSIDFromProgID(prog_id.c_str(), &clsid );

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

		UnicodeString pass1="";
		if (password=="")
			{
			pass1="0000";
			}
		else
			{
			pass1=password;
			}

		Merc->Password=SysAllocString(password.c_str());


		if(Merc->Open()==0)
			{
			result=true;
			ConnectFR=true;
			}
		else
			{
			result=false;
			ConnectFR=false;
			TextError="������:"+FloatToStr(Merc->ErrCode) +" "+ FloatToStr(Merc->ErrCodeEx)+UnicodeString(Merc->ErrMessage);
			}
		}

catch (Exception &E)
        {
		result=false;
        TextError=TextError+"�� ������� ������������ � ��! ������: "+E.Message;
        ConnectFR=false;
        }
return result;
}
//--------------------------------------------------------------------------

bool  TkasMSKFR::Disconnect(void)
{
bool result=false;
try
	{
	Merc->Close(true);
	ConnectFR=false;
	CoUninitialize();
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

bool  TkasMSKFR::GetSostKKM(void)
{
bool result=false;
HRESULT hr;
	//ShowMessage("bool  TkasMSKFR::GetSostKKM(void) ");
try
	{
	//ShowMessage("hr=Merc->QueryLastDocInfo(); ");
	hr=Merc->QueryLastDocInfo();
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	//ShowMessage("�������� hr=Merc->QueryLastDocInfo(); ");
	if (Merc->ErrCode==0)
		{
		result=true;
		}
	else
		{
		TextError=Merc->ErrMessage;
		result=false;
		}

	 //	ShowMessage("hr=Merc->QueryResourceInfo(false);");
	hr=Merc->QueryResourceInfo(false);
	 //	ShowMessage(" ��������� hr=Merc->QueryResourceInfo(false); ");
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

	//ShowMessage("��������� ����");
	NumberCheck=Merc->LastRecNumber;
	NumberKL=Merc->LastDayClosing+1;
	SerialNumberKKM=Merc->SerialNumber;
	RegNumberKKM=Merc->QueryRegNumber();
	ModelKKM="�������� MS-K ";
	//ShowMessage("���������� ��������� ����");
	result=true;
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}

//ShowMessage("��������� bool  TkasMSKFR::GetSostKKM(void) ");
return result;
}
//---------------------------------------------------------------------------
bool  TkasMSKFR::ProvVosmPrintCheck(void)
{
bool result=true;
try
	{
	if (GetSostKKM()==true)
		{

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
//----------------------------------------------------------------------------
bool   TkasMSKFR::OpenNoFiscalCheck(void)
{
bool result=false;
HRESULT hr;

UnicodeString str=L"";
BSTR bstr_str=SysAllocString(str.c_str());

try
	{

	hr=Merc->PrintNonFiscal(bstr_str, true,false);
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
	result=true;
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}

SysFreeString(bstr_str);
return result;
}
//---------------------------------------------------------------------------
bool   TkasMSKFR::CloseNoFiscalCheck(void)
{
bool result=true;
HRESULT hr;
TextError="";

UnicodeString str=L"";
BSTR bstr_str=SysAllocString(str.c_str());

try
	{
	hr=Merc->PrintNonFiscal(bstr_str, false,true);
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

SysFreeString(bstr_str);
return result;

}
//---------------------------------------------------------------------------
bool  TkasMSKFR::PrintString(UnicodeString str,
                                                int size_font,       //1234
                                                int style,           //1-������ 0 �������   2 ������ 3 ������ ������
                                                int alignment,       //0 ���� 1 ����� 2 �����
												bool ch_lenta,       //�� ������� �����
												bool kontr_lenta,    //�� ����������� �����
												bool word_wrap)
{
bool result=false;


if (ConnectFR==false){return result;}


if (Trim(str) == "") str=" ";          //����� ��� ������ ������ ������� ������
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
						{kol_symbol=KolSymbolSize1;break;}
				case  2:
						{kol_symbol=KolSymbolSize2;break;}
				case  3:
						{kol_symbol=KolSymbolSize3;break;}
				case  4:
						{kol_symbol=KolSymbolSize4;break;}
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




	UnicodeString str_print="";

        switch ( size_font)
				{
                case  1:
						{
						s=" "+s;
						if(s.Length()>KolSymbolSize1) s=s.SetLength(KolSymbolSize1);
                        switch ( alignment)
                                {
								case  0:      //����
                                        {
										if (s.Length()>=KolSymbolSize1)
												{
												str_print=L"\\1b\\21\\8"+s;
												//Merc->PrintNonFiscal(SysAllocString(str_print.c_str()), false,false);
                                                }
                                        else
												{
												str_print=L"\\1b\\21\\8"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(SysAllocString(str_print.c_str()), false,false);
                                                }
                                        break;
                                        }
								case  1:    //�����
                                        {
										if (s.Length()>=KolSymbolSize1)
												{
												str_print=L"\\1b\\21\\8"+s;
												//Merc->PrintNonFiscal(WideString("\\1b\\21\\8"+s).c_bstr(), false,false);
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
												}
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize1-((KolSymbolSize1-s.Length())/2));
												str_print=L"\\1b\\21\\8"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
												//Merc->PrintNonFiscal(WideString("\\1b\\21\\8"+s+"\\0d\\0a").c_bstr(), false,false);
                                                }

                                        break;
                                        }
                                case  2:   //�����
                                        {
										if (s.Length()>=KolSymbolSize1)
												{
												str_print=L"\\1b\\21\\8"+s;
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
												}
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize1);
												str_print=L"\\1b\\21\\8"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }

                                        break;
                                        }


                                }
                        break;
                        }
                case  2:
						{
						s=" "+s;
						if(s.Length()>KolSymbolSize2) s=s.SetLength(KolSymbolSize2);
						switch ( alignment)
                                {
                                case  0:      //����
                                        {
										if (s.Length()>=KolSymbolSize2)
												{
												str_print=L"\\1b\\21\\8"+s;
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }
                                        else
												{
												str_print=L"\\1b\\21\\8"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }
                                        break;
                                        }
                                case  1:    //�����
                                        {
										if (s.Length()>=KolSymbolSize2)
												{
												str_print=L"\\1b\\21\\8"+s;
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize2-((KolSymbolSize2-s.Length())/2));
												str_print=L"\\1b\\21\\8"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }

                                        break;
                                        }
                                case  2:   //�����
                                        {
										if (s.Length()>=KolSymbolSize2)
												{
												str_print=L"\\1b\\21\\8"+s;
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize2);
												str_print=L"\\1b\\21\\8"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }

                                        break;
                                        }


                                }
                        break;
                        }
                case  3:
						{
						if(s.Length()>KolSymbolSize3) s=s.SetLength(KolSymbolSize3);
                        switch ( alignment)
                                {
                                case  0:      //����
                                        {
										if (s.Length()>=KolSymbolSize3)
												{
												str_print=L"\\1b\\21\\30"+s+"\\0d\\0a";
											   //	Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }
										else
												{
												str_print=L"\\1b\\21\\30"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }
                                        break;
                                        }
                                case  1:    //�����
                                        {
										if (s.Length()>=KolSymbolSize3)
												{
												str_print=L"\\1b\\21\\30"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }
                                        else
												{
												s=DopStrL(s, " ", KolSymbolSize3-((KolSymbolSize3-s.Length())/2));
												str_print=L"\\1b\\21\\30"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }

                                        break;
                                        }
                                case  2:   //�����
                                        {
										if (s.Length()>=KolSymbolSize3)
												{
												str_print=L"\\1b\\21\\30"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize3);
												str_print=L"\\1b\\21\\30"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }

                                        break;
                                        }


                                }

                        break;
                        }
                case  4:
						{
						if(s.Length()>KolSymbolSize4) s=s.SetLength(KolSymbolSize4);
                        switch ( alignment)
                                {
                                case  0:      //����
                                        {
										if (s.Length()>=KolSymbolSize4)
												{
												str_print=L"\\1b\\21\\30"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }
                                        else
												{
												str_print=L"\\1b\\21\\30"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }
                                        break;
                                        }
                                case  1:    //�����
                                        {
										if (s.Length()>=KolSymbolSize4)
												{
												str_print=L"\\1b\\21\\30"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize4-((KolSymbolSize4-s.Length())/2));
												str_print=L"\\1b\\21\\30"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }

                                        break;
                                        }
                                case  2:   //�����
                                        {
										if (s.Length()>=KolSymbolSize4)
												{
												str_print=L"\\1b\\21\\30"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize4);
												str_print=L"\\1b\\21\\30"+s+"\\0d\\0a";
												//Merc->PrintNonFiscal(str_print.c_str(), false,false);
                                                }

                                        break;
                                        }


								}
                        break;
						}
			}




try
	{
	BSTR bstr_str=SysAllocString(str_print.c_str());
	Merc->PrintNonFiscal(bstr_str, false,false);
	SysFreeString(bstr_str);
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
bool  TkasMSKFR::PrintLine(void)
{
bool result=false;

try
	{
	UnicodeString str=L"\\1b\\21\\----------------------------------------\\0d\\0a";
	BSTR bstr_str=SysAllocString(str.c_str());
	Merc->PrintNonFiscal(bstr_str, false,false);
    SysFreeString(bstr_str);
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


bool  TkasMSKFR::PrintFiscalCheck(double sum,
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
bool  TkasMSKFR::PrintFiscalCheckSale(double sum,
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
				UnicodeString str=L"������ ";
				BSTR bstr_str=SysAllocString(str.c_str());
				hr=Merc->OpenDay(1, bstr_str, false, Merc->Protocol);
				if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
				SysFreeString(bstr_str);
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

	BSTR bstr_str=SysAllocString(L"");

	hr=Merc->AddItem(
	  mitItem,          // - ������ ��� �����
	  vSumCheck,              // - ���� ������
	  false,            // - ����� �� �������� �����
	  1,                // - ����� ������
	  0,              // - ��� ������
	  0,                // - ������������
      1, 0,             // - ���������� = 2 (��� ������ ����� ���������� �����)
	  0,                // - ������ ��������� ������
	  bstr_str,            // - ������� ���������
	  0,                // - �����
	  0,                // - �������� �� ���������
	  IV,               // - �������� �� �����������
	  0                 // - ������������
	); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

	SysFreeString(bstr_str);

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
bool  TkasMSKFR::PrintFiscalCheckReturnSale(double sum,
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
				UnicodeString str=L"������ ";
				BSTR bstr_str=SysAllocString(str.c_str());
				hr=Merc->OpenDay(1, bstr_str, false, Merc->Protocol);
				if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
				SysFreeString(bstr_str);
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
	BSTR bstr_str=SysAllocString(L"");

	hr=Merc->AddItem(
	  mitItem,          // - ������ ��� �����
	  vSumCheck,              // - ���� ������
	  false,            // - ����� �� �������� �����
	  1,                // - ����� ������
	  0,              // - ��� ������
	  0,                // - ������������
      1, 0,             // - ���������� = 2 (��� ������ ����� ���������� �����)
	  0,                // - ������ ��������� ������
	  bstr_str,            // - ������� ���������
	  0,                // - �����
	  0,                // - �������� �� ���������
	  IV,               // - �������� �� �����������
	  0                 // - ������������
	); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

	SysFreeString(bstr_str);


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
bool  TkasMSKFR::PrintNoFiscalCheck(double sum,
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

	UnicodeString str=L"------------------------------------\r\n";
	BSTR bstr_str=SysAllocString(str.c_str());
	Merc->PrintNonFiscal(bstr_str, true,true);
	SysFreeString(bstr_str);

	str="������� ��� ���������!\r\n";
	bstr_str=SysAllocString(str.c_str());
	Merc->PrintNonFiscal(bstr_str, true,true);
	SysFreeString(bstr_str);

	str=L"";
	bstr_str=SysAllocString(str.c_str());
	for(int i=0;i<20;i++)
        {
        Merc->PrintNonFiscal(bstr_str, true,true);
		}

	SysFreeString(bstr_str);

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
bool  TkasMSKFR::PrintXReport(void)
{
bool result=false;
HRESULT hr;
NoPrint=false;
try
	{
	//�������� ������� �� �����
	if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
		{
		UnicodeString str=L"������ ";
		BSTR bstr_str=SysAllocString(str.c_str());
		Merc->OpenDay(1, bstr_str, false, Merc->Protocol);
		SysFreeString(bstr_str);
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
bool TkasMSKFR::PrintZReport(void)
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
			UnicodeString str=L"������ ";
			BSTR bstr_str=SysAllocString(str.c_str());
				Merc->OpenDay(1, bstr_str, false, Merc->Protocol);
				SysFreeString(bstr_str);
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
bool  TkasMSKFR::PrintPoOtdelamReport(void)
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
			UnicodeString str=L"������ ";
			BSTR bstr_str=SysAllocString(str.c_str());
				Merc->OpenDay(1, bstr_str, false, Merc->Protocol);
				SysFreeString(bstr_str);
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

bool  TkasMSKFR::Cut(int TypeCut)
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

bool  TkasMSKFR::Vnesenie(double sum)
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
bool  TkasMSKFR::Snatie(double sum)
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
UnicodeString TkasMSKFR::DopStrL(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//---------------------------------------------------------------------------
//��������� ������ Str ������ ��������� Symbol �� Len
UnicodeString TkasMSKFR::DopStrR(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Str+Symbol;
        }
return Str;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
TTime  TkasMSKFR::GetTime(void)
{
TTime result=0;
try
	{
	result=Merc->QueryEcrDateTime();
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=0;
		}
return result;

}
//-----------------------------------------------------------------------------
TDate  TkasMSKFR::GetDate(void)
{
TDate result=0;
try
	{
	result=Merc->QueryEcrDateTime();
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=0;
		}
return result;

}
//--------------------------------------------------------------------------
bool  TkasMSKFR::SetTime(TTime time)
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
bool  TkasMSKFR::SetDate(TDate date)
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
void TkasMSKFR::OpenDrawer(void)
{
HRESULT hr;
hr=Merc->ExternalPulse(1,10,10,1);
if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}
}
//-----------------------------------------------------------------------------
int TkasMSKFR::CompareDoubleValue(double v1, double v2, int pogr)
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















   //����� ������� ��� ������ � ��-���� �������
bool TkasMSKFR::OpenShift(void)
{

return true;
}
//----------------------------------------------------------------------------
bool TkasMSKFR::CloseShift(void)
{

return true;
}
//----------------------------------------------------------------------------
bool TkasMSKFR::InitDocument(int type_doc)
{

return true;
}
//----------------------------------------------------------------------------
bool TkasMSKFR::CreateHeaderFiscalCheck(void)
{

return true;
}
//----------------------------------------------------------------------------
bool TkasMSKFR::CreateFooterFiscalCheck(void)
{

return true;
}
//----------------------------------------------------------------------------
bool TkasMSKFR::AddFiscalString(void)
{
bool result=true;

		if (PrintString(NameNom,1,0,0,true,false, false)==false)
			{
			throw Exception(TextError);
			}

				double Quantity;

	//Price �� double ���� ������� ������ ��� ����� ������/�������
	double Price;

	//Amount �� double �������� ����� �� ������� ���� (� ������ ���� ������/�������)
	double Amount;

	double skidka=0;
	double procent=(Price*Quantity-Amount)/(Price*Quantity/100);
	skidka=Price*Quantity - Amount;

		if (skidka > 0.001)
			{  //�� �������
			UnicodeString StrPr="";
			StrPr=FloatToStrF(Price,ffFixed,15,2)
				+" x "+FloatToStr(Quantity)+" ="
				+FloatToStrF(Price*Quantity,ffFixed,15,2);
			if(PrintString(StrPr,1,0,2,true,false, false)==false)
				{
				throw Exception(TextError);
				}

			StrPr="-"+FloatToStrF(procent,ffFixed,15,2)+" % "
				+FloatToStrF(skidka,ffFixed,15,2)+
				" = "+FloatToStrF(Amount,ffFixed,15,2);

			if(PrintString(StrPr,1,0,2,true,false, false)==false)
				{
				throw Exception(TextError);
				}
			}
		else
			{//��� ������

			UnicodeString StrPr="";
			StrPr=FloatToStrF(Price,ffFixed,15,2)
				+" x "+FloatToStrF(Quantity,ffFixed,15,3)+" ="
				+FloatToStrF(Amount,ffFixed,15,2);

			if(PrintString(StrPr,1,0,2,true,false, false)==false)
				{
				throw Exception(TextError);
				}
			}
return result;
}
//----------------------------------------------------------------------------
UnicodeString TkasMSKFR::GetParameters(void)
{
UnicodeString result="";
return result;
}
//-------------------------------------------------------------------------
bool TkasMSKFR::SetParameter(UnicodeString name_parameter, UnicodeString value_parameter)
{

bool result=true;
return result;

}
//------------------------------------------------------------------------------


UnicodeString TkasMSKFR::GetAdditionalActions(void)
{
UnicodeString result="";
return result;
}
//------------------------------------------------------------------------
bool TkasMSKFR::DoAdditionalAction(UnicodeString name_action)
{
bool result=true;
return result;
}
//-------------------------------------------------------------------------
UnicodeString TkasMSKFR::GetMetodsList(void)
{
UnicodeString result="";

return result;
}
//------------------------------------------------------------------------

bool TkasMSKFR::GetParameter(UnicodeString name_parameter, TkasVariant * value_parameter)
{
bool result=true;


return result;
}
//--------------------------------------------------------------------------
bool TkasMSKFR::SetParameter(UnicodeString name_parameter, TkasVariant * value_parameter)
{
bool result=true;


return result;
}
//--------------------------------------------------------------------------



//--------------------------------------------------------------------
//*******************************************************************
//--------------------------------------------------------------------
bool TkasMSKFR::RunCommand(UnicodeString command_name, UnicodeString xml_doc, int type_doc)
					//���� type = 0 �� �� ���������� xml_doc, � ���������� �������������� ��������� ����
{
bool result=true;


return result;

}
//------------------------------------------------------------------
UnicodeString TkasMSKFR::ReturnXmlResultLastMethod(void)
{
UnicodeString result="";


return result;
}
//----------------------------------------------------------------------

bool TkasMSKFR::SetStringParameter(UnicodeString param_name, int number, UnicodeString value)
{
bool result=true;


return result;
}
//------------------------------------------------------------------
UnicodeString TkasMSKFR::GetStringParameter(UnicodeString param_name, int number)
{
UnicodeString result="";


return result;


}
//-----------------------------------------------------------------------

bool TkasMSKFR::SetIntegerParameter(UnicodeString param_name, int number, int value)
{
bool result=true;


return result;

}
//------------------------------------------------------------------
int TkasMSKFR::GetIntegerParameter(UnicodeString param_name, int number)
{

int result=0;


return result;

}
//-----------------------------------------------------------------------

bool TkasMSKFR::SetDoubleParameter(UnicodeString param_name, int number, double value)
{
bool result=true;


return result;

}
//------------------------------------------------------------------
double TkasMSKFR::GetDoubleParameter(UnicodeString param_name, int number)
{

double result=true;


return result;

}
//-----------------------------------------------------------------------

bool TkasMSKFR::SetBooleanParameter(UnicodeString param_name, int number, bool value)
{

bool result=true;


return result;
}
//------------------------------------------------------------------
bool TkasMSKFR::GetBooleanParameter(UnicodeString param_name, int number)
{

bool result=true;


return result;
}
//-----------------------------------------------------------------------

bool TkasMSKFR::SetDateTimeParameter(UnicodeString param_name, int number, TDateTime value)
{

bool result=true;


return result;
}
//------------------------------------------------------------------
TDateTime TkasMSKFR::GetDateTimeParameter(UnicodeString param_name, int number)
{


TDateTime result=0;


return result;
}
//-----------------------------------------------------------------------
	//������������ xml �����
void TkasMSKFR::AddStringXml(UnicodeString str_xml)    //������ ������� ������
 {

}
//-------------------------------------------------------------------------
void TkasMSKFR::AddAttribyteXml(UnicodeString attribyte, UnicodeString value, int type_value)  //��� ��� ��������������, �������� ��� �������� ������� � ������

{

}
//------------------------------------------------------------------------------
void TkasMSKFR::AddElementXml(UnicodeString element, UnicodeString value, int type_value)
{

}
//----------------------------------------------------------------------------

void TkasMSKFR::AddStringForPrintXml(UnicodeString element, UnicodeString attribyte, UnicodeString value,
								int size_font, int girn, int alignment, bool word_wrap)   //������ xml ��� ������ ����� �������������
{


}
//------------------------------------------------------------------------------
