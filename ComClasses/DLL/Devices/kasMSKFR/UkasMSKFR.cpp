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
TextErrorNoConnect="ККМ не подключена!";

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
		UnicodeString prog_id=L"Incotex.MercuryFPrtCOM";

		HRESULT hr = ::CLSIDFromProgID(prog_id.c_str(), &clsid );

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
			TextError="Ошибка:"+FloatToStr(Merc->ErrCode) +" "+ FloatToStr(Merc->ErrCodeEx)+UnicodeString(Merc->ErrMessage);
			}
		}

catch (Exception &E)
        {
		result=false;
        TextError=TextError+"Не удалось подключиться к ФР! Ошибка: "+E.Message;
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
	//ShowMessage("выолнили hr=Merc->QueryLastDocInfo(); ");
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
	 //	ShowMessage(" выполнили hr=Merc->QueryResourceInfo(false); ");
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

	//ShowMessage("Параметры чека");
	NumberCheck=Merc->LastRecNumber;
	NumberKL=Merc->LastDayClosing+1;
	SerialNumberKKM=Merc->SerialNumber;
	RegNumberKKM=Merc->QueryRegNumber();
	ModelKKM="Меркурий MS-K ";
	//ShowMessage("Установили параметры чека");
	result=true;
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}

//ShowMessage("выполнили bool  TkasMSKFR::GetSostKKM(void) ");
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
                                                int style,           //1-жирный 0 обычный   2 курсив 3 жирный курсив
                                                int alignment,       //0 лево 1 центр 2 право
												bool ch_lenta,       //на чековой ленте
												bool kontr_lenta,    //на контрольной ленте
												bool word_wrap)
{
bool result=false;


if (ConnectFR==false){return result;}


if (Trim(str) == "") str=" ";          //иначе при печати пустых строчек ошибка
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
								case  0:      //лево
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
								case  1:    //центр
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
                                case  2:   //право
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
                                case  0:      //лево
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
                                case  1:    //центр
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
                                case  2:   //право
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
                                case  0:      //лево
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
                                case  1:    //центр
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
                                case  2:   //право
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
                                case  0:      //лево
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
                                case  1:    //центр
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
                                case  2:   //право
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
bool  TkasMSKFR::PrintFiscalCheckSale(double sum,
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
				UnicodeString str=L"Кассир ";
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

	BSTR bstr_str=SysAllocString(L"");

	hr=Merc->AddItem(
	  mitItem,          // - услуга или товар
	  vSumCheck,              // - цена товара
	  false,            // - товар не является тарой
	  1,                // - номер отдела
	  0,              // - код товара
	  0,                // - игнорируется
      1, 0,             // - количество = 2 (нет знаков после десятичной точки)
	  0,                // - индекс налоговой группы
	  bstr_str,            // - единица измерения
	  0,                // - флаги
	  0,                // - смещение по вертикали
	  IV,               // - смещение по горизонтали
	  0                 // - игнорируется
	); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

	SysFreeString(bstr_str);

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
bool  TkasMSKFR::PrintFiscalCheckReturnSale(double sum,
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
				UnicodeString str=L"Кассир ";
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
	BSTR bstr_str=SysAllocString(L"");

	hr=Merc->AddItem(
	  mitItem,          // - услуга или товар
	  vSumCheck,              // - цена товара
	  false,            // - товар не является тарой
	  1,                // - номер отдела
	  0,              // - код товара
	  0,                // - игнорируется
      1, 0,             // - количество = 2 (нет знаков после десятичной точки)
	  0,                // - индекс налоговой группы
	  bstr_str,            // - единица измерения
	  0,                // - флаги
	  0,                // - смещение по вертикали
	  IV,               // - смещение по горизонтали
	  0                 // - игнорируется
	); IV++;
	if ( FAILED( hr )) {throw Exception(Merc->ErrMessage);}

	SysFreeString(bstr_str);


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
bool  TkasMSKFR::PrintNoFiscalCheck(double sum,
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

	UnicodeString str=L"------------------------------------\r\n";
	BSTR bstr_str=SysAllocString(str.c_str());
	Merc->PrintNonFiscal(bstr_str, true,true);
	SysFreeString(bstr_str);

	str="Учебный чек напечатан!\r\n";
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
	//проверим открыта ли смена
	if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
		{
		UnicodeString str=L"Кассир ";
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
		//проверим открыта ли смена
		if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
			{
			UnicodeString str=L"Кассир ";
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
		//проверим открыта ли смена
		if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
			{
			UnicodeString str=L"Кассир ";
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
bool  TkasMSKFR::Snatie(double sum)
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
UnicodeString TkasMSKFR::DopStrL(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//---------------------------------------------------------------------------
//дополнить строку Str справа символами Symbol до Len
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















   //новые функции для работы с он-лайн кассами
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

	//Price Да double Цена единицы товара без учета скидок/наценок
	double Price;

	//Amount Да double Конечная сумма по позиции чека (с учетом всех скидок/наценок)
	double Amount;

	double skidka=0;
	double procent=(Price*Quantity-Amount)/(Price*Quantity/100);
	skidka=Price*Quantity - Amount;

		if (skidka > 0.001)
			{  //со скидкой
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
			{//без скидки

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
					//если type = 0 то не используем xml_doc, а используем сформированный построчно файл
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
	//формирование xml файла
void TkasMSKFR::AddStringXml(UnicodeString str_xml)    //просто готовая строка
 {

}
//-------------------------------------------------------------------------
void TkasMSKFR::AddAttribyteXml(UnicodeString attribyte, UnicodeString value, int type_value)  //тип для форматирования, например для удаления запятых в числах

{

}
//------------------------------------------------------------------------------
void TkasMSKFR::AddElementXml(UnicodeString element, UnicodeString value, int type_value)
{

}
//----------------------------------------------------------------------------

void TkasMSKFR::AddStringForPrintXml(UnicodeString element, UnicodeString attribyte, UnicodeString value,
								int size_font, int girn, int alignment, bool word_wrap)   //строка xml для печати будет формироваться
{


}
//------------------------------------------------------------------------------
