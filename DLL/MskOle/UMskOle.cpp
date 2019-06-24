//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#pragma argsused



extern "C" char * __declspec (dllexport) GetTextError(void);

extern "C" bool __declspec (dllexport) Connect(int number_port,
                                                char* baud_rate,
                                                char* password);
extern "C" void __declspec (dllexport) Disconnect(void);

extern "C" bool __declspec (dllexport) GetSostKKM(void);
extern "C" bool __declspec (dllexport) ProvVosmPrintCheck(void);
extern "C" int __declspec (dllexport) GetNumberCheck(void);
extern "C" int __declspec (dllexport) GetNumberKL(void);
extern "C" char* __declspec (dllexport) GetSerialNumberKKM(void);
extern "C" char* __declspec (dllexport) GetRegNumberKKM(void);
extern "C" char* __declspec (dllexport) GetModelKKM(void);

extern "C" bool __declspec (dllexport)  OpenNoFiscalCheck(void);
extern "C" bool __declspec (dllexport)  CloseNoFiscalCheck(void);
extern "C" bool __declspec (dllexport) PrintString(char* str,
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
                                                        double oplata_plat_card,
                                                        int operation);    //0 продажа 1 возврат

extern "C" bool __declspec (dllexport) PrintNoFiscalCheck(double sum,
                                int department,
                                double oplata_nal,
                                double oplata_plat_card,
                                int operation);    //0 продажа 1 возврат

extern "C" bool __declspec (dllexport) PrintXReport(void);
extern "C" bool __declspec (dllexport) PrintZReport(void);
extern "C" bool __declspec (dllexport) PrintPoOtdelamReport(void);

extern "C" bool __declspec (dllexport) Cut(int TypeCut);

extern "C" bool __declspec (dllexport) Vnesenie(double sum);
extern "C" bool __declspec (dllexport) Snatie(double sum);

extern "C" char* __declspec (dllexport) GetTimeKKM(void);
extern "C" char* __declspec (dllexport) GetDateKKM(void);
extern "C" bool __declspec (dllexport) SetTimeKKM(char * time);
extern "C" bool __declspec (dllexport) SetDateKKM(char * date);

AnsiString TextError;

bool ConnectFR=false;
bool NoPrint;
bool UseJournalRibbon=true;
bool UseReceiptRibbon=true;
bool OpenNoFiscalDoc=false;

Variant  FR;
String DopStrL(String Str, String Symbol, int Len);
String DopStrR(String Str, String Symbol, int Len);




int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}
//---------------------------------------------------------------------------
char *  GetTextError(void)
{
char * result="";
result=TextError.c_str();
return result;
}
//----------------------------------------------------------------------------
bool  Connect(int number_port,
				char* baud_rate,
				char* password)
{

bool result=false;
//NoPrint=false;
//UseJournalRibbon=true;
//UseReceiptRibbon=true;
//OpenNoFiscalDoc=false;


try
        {
		FR = Variant::CreateObject("AddIn.MercuryFPrt1C");
        }
catch (...)
		{
		TextError="Не удалось создать объект фискального регистратора !";
		//ConnectFR=false;
		}

FR.OlePropertySet("Password","0000");
FR.OlePropertySet("BaudRate",StrToInt(baud_rate));
FR.OlePropertySet("PortNum",number_port);


try
	{
	FR.OleProcedure("Open");
	}
catch (...)
		{
		result=false;
		ShowMessage("Не удалось подключиться к ФР! ErrMessage: "+FR.OlePropertyGet("ErrMessage"));
	   //	ShowMessage("Не удалось подключиться к ФР! Exception "+E.Message);
		ConnectFR=false;
		}

		if(FR.OlePropertyGet("ErrCode")==0)
				{
				ConnectFR=true;
				result=true;
				NoPrint=false;
				}
		else
				{
				TextError="Ошибка фискального регистратора: "+FR.OlePropertyGet("ErrMessage");
				ConnectFR=false;
				result=false;
				}


//
//bool result=false;
//NoPrint=false;
//UseJournalRibbon=true;
//UseReceiptRibbon=true;
//OpenNoFiscalDoc=false;

//
//try
//		{
//		Merc->PortNum=number_port;
//		Merc->BaudRate=StrToInt(baud_rate);
//		Merc->ExternalTimeout=30000;
//		Merc->InternalTimeout=500;
//		AnsiString pass=password;
//		//Merc->Password=WideString("0000").c_bstr();
//
//		if (Merc->Open()==0)
//			{
//			result=true;
//			ConnectFR=true;
//			}
//		else
//			{
//			result=false;
//			ConnectFR=false;
//			}

//
//      //  Merc->OpenDay(1, WideString("0000").c_bstr(), false, Merc->Protocol);
//        ShowMessage("Открыли соединение!");     
//
//        if (Merc->ErrCodeEx!= 0)
//                {
//				ShowMessage("После метода ошибки. Есть ошибки!");
//                result=false;
//                TextError="Не удалось подключиться к ФР! Ошибка: "+WideCharToString(Merc->ErrMessage) ;
//                //ShowMessage(TextError);
//                }
//        else
//                {
//                //ShowMessage("Ошибок нет");
//                result=true;
//				ConnectFR=true;
//				ShowMessage("После метода ошибки. Ошибок нет!");
//                }

//
//		}
//
//catch (Exception &E)
//        {
//		result=false;
//        TextError="Не удалось подключиться к ФР! Ошибка: "+E.Message;
//        ConnectFR=false;
//        }
return result;
}
//--------------------------------------------------------------------------

void  Disconnect(void)
{
try
	{
//	Merc->Close(true);
//	ConnectFR=false;
//	CoUninitialize();
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
try
	{
//		Merc->QueryLastDocInfo();
//
//	if (Merc->ErrCode==0)
//		{
//		result=true;
//		}
//	else
//		{
//		TextError=Merc->ErrMessage;
//		result=false;
//		}
//
//
//		Merc->QueryResourceInfo(false);
//		result=true;
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
//try
//	{
//	if (GetSostKKM()==true)
//		{
//		//ShowMessage("Открыта крышка принтера "+Merc->CheckDevStatus(13));
//	   //	int i=0;
//	   ShowMessage("Крышка принтера: "+IntToStr(Merc->CheckEcrStatus(MERC_DS_OPENED_COVER))) ;
//		ShowMessage("Чековая лента: "+IntToStr(Merc->CheckEcrStatus(MERC_DS_RECEIPT_OUT))) ;
//	   //	ShowMessage(IntToHex(Merc->EcrStatus
//
//		switch (Merc->DevStatus)
//		{
//		case MERC_DS_OPENED_COVER :      //идет печать предыдущей команды
//				{
//				ShowMessage("Открыта крышка принтера! MERC_DS_OPENED_COVER");
//				result=false;
//                return result;
//				}
//
//		case MERC_DS_PRINTER_ERROR :      //идет печать предыдущей команды
//                {
//				ShowMessage("Ошибка принтера! MERC_DS_PRINTER_ERROR");
//                result=false;
//				return result;
//                }
//
//        case MERC_DS_MECHANICAL_ERROR :      //идет печать предыдущей команды
//				{
//                ShowMessage("Ошибка  механики принтера! MERC_DS_MECHANICAL_ERROR");
//				result=false;
//                return result;
//				}
//
//		case MERC_DS_CUTTER_ERROR :      //идет печать предыдущей команды
//                {
//				ShowMessage("Ошибка  отрезчика! MERC_DS_CUTTER_ERROR");
//                result=false;
//				return result;
//                }
//
//        case MERC_DS_FATAL_ERROR :      //идет печать предыдущей команды
//				{
//                ShowMessage("Критическая ошибка принтера! MERC_DS_FATAL_ERROR");
//				result=false;
//                return result;
//				}
//
//		case MERC_DS_OVERHEATING :      //идет печать предыдущей команды
//                {
//				ShowMessage("Перегрев печатающей головки! MERC_DS_OVERHEATING ");
//                result=false;
//				return result;
//                }
//
//        case MERC_DS_JOURNAL_OUT :      //идет печать предыдущей команды
//				{
//                ShowMessage("Нет контрольной ленты! MERC_DS_JOURNAL_OUT");
//				result=false;
//                return result;
//				}
//
//		case MERC_DS_RECEIPT_OUT :      //идет печать предыдущей команды
//                {
//				ShowMessage("Нет чековой ленты! MERC_DS_RECEIPT_OUT");
//                result=false;
//				return result;
//                } 
//
//        default :
//				{
//
//
//                } break;
//
//		}
//
//
//	if (Merc->DocStatus!=mdsClosed)
//		{
//		Merc->CancelFiscalDoc(false);
//		}
//
//		result=true;
//		}
//	else
//		{
//		result=false;
//		}
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result=false;
//		}

return result;

}
//---------------------------------------------------------------------------
int GetNumberCheck(void)
{
int result=0;
//try
//	{
//	result=Merc->LastRecNumber;
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result=0;
//		}
return result;

}
//---------------------------------------------------------------------------
int  GetNumberKL(void)
{
int result=0;

//try
//	{
//	result=Merc->LastDayClosing+1;
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result=0;
//		}

return result;

}
//---------------------------------------------------------------------------
char*  GetSerialNumberKKM(void)
{
char* result="";
AnsiString num="";

//try
//	{
//	num=Merc->SerialNumber;
//	num=num+" ";
//	result=num.c_str();
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result="";
//		}
return result;

}
//---------------------------------------------------------------------------
char*  GetRegNumberKKM(void)
{
char* result="";
AnsiString num="";
//try
//	{
//	num=Merc->QueryRegNumber();
//	num=num+" ";
//	result=num.c_str();
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result="";
//		}
return result;

}
//---------------------------------------------------------------------------
char*  GetModelKKM(void)
{
char* result="";
//AnsiString num="Меркурий MS-K ";
//result=num.c_str();

return result;

}
//----------------------------------------------------------------------------
bool   OpenNoFiscalCheck(void)
{
bool result=false;
//try
//	{
//	Merc->PrintNonFiscal(WideString("").c_bstr(), true,false);
//	result=true;
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result=false;
//		}
return result;
}
//---------------------------------------------------------------------------
bool   CloseNoFiscalCheck(void)
{
bool result=true;
TextError="";
//try
//	{
//	Merc->PrintNonFiscal(WideString("").c_bstr(), false,true);
//	if (Merc->ErrCode==0)
//		{
//		result=true;
//		}
//	else
//		{
//		TextError=Merc->ErrMessage;
//		result=false;
//		}
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result=false;
//		}
return result;

}
//---------------------------------------------------------------------------
bool  PrintString(char* str,
												int size_font,       //1234
												int style,           //1-жирный 0 обычный   2 курсив 3 жирный курсив
												int alignment,       //0 лево 1 центр 2 право
												bool ch_lenta,       //на чековой ленте
												bool kontr_lenta,    //на контрольной ленте
												bool word_wrap)
{
bool result=false;
AnsiString s=AnsiString(str);

//int kol_symbol=0;

//перенос по словам
//*********************************************************************
//
//if (word_wrap==true)
//	{
//	TStringList * strings=new TStringList();
//		switch (size_font)
//				{
//				case  1:
//						{kol_symbol=40;break;}
//				case  2:
//						{kol_symbol=40;break;}
//				case  3:
//						{kol_symbol=14;break;}
//				case  4:
//						{kol_symbol=14;break;}
//				}
//
//	s=WrapText(s,kol_symbol);
//	strings->Text=s;
//
//	for (int i=0;i<strings->Count;i++)
//		{
//		AnsiString print_str=strings->Strings[i];
//		if (PrintString(print_str.c_str(),size_font,style,alignment,ch_lenta,kontr_lenta, false)==true)
//			{
//			result=true;
//			}
//		else
//			{
//			result=false;
//			}
//		}
//	delete strings;
//	return result;
//
//	}
//
//// ***************************************************************************
//
//try
//	{
//	if (ConnectFR==false){return result;}
//
//        switch ( size_font)
//				{
//                case  1:
//						{
//						s=" "+s;
//						if(s.Length()>40) s=s.SetLength(40);
//						switch ( alignment)
//                                {
//								case  0:      //лево
//                                        {
//										if (s.Length()>=40)
//												{
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
//                                                }
//                                        else
//                                                {
//												Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
//                                                }
//                                        break;
//                                        }
//                                case  1:    //центр
//										{
//                                        if (s.Length()>=40)
//                                                {
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
//                                                }
//										else
//                                                {
//                                                s=DopStrL(s, " ", 40-((40-s.Length())/2));
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
//                                                }
//
//                                        break;
//                                        }
//                                case  2:   //право
//                                        {
//										if (s.Length()>=40)
//                                                {
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
//                                                }
//                                        else
//												{
//                                                s=DopStrL(s, " ", 40);
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
//                                                }
//
//										break;
//                                        }
//
//
//                                }
//						break;
//                        }
//                case  2:
//						{
//						s=" "+s;
//						if(s.Length()>40) s=s.SetLength(40);
//                        switch ( alignment)
//                                {
//                                case  0:      //лево
//                                        {
//										if (s.Length()>=40)
//                                                {
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
//                                                }
//                                        else
//												{
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
//                                                }
//                                        break;
//                                        }
//								case  1:    //центр
//                                        {
//                                        if (s.Length()>=40)
//                                                {
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
//												}
//                                        else
//                                                {
//                                                s=DopStrL(s, " ", 40-((40-s.Length())/2));
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
//												}
//
//                                        break;
//                                        }
//                                case  2:   //право
//										{
//                                        if (s.Length()>=40)
//                                                {
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s).c_bstr(), false,false);
//                                                }
//										else
//                                                {
//                                                s=DopStrL(s, " ", 40);
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\1"+s+"\\0d\\0a").c_bstr(), false,false);
//                                                }
//
//                                        break;
//                                        }
//
//
//								}
//                        break;
//                        }
//                case  3:
//						{
//						if(s.Length()>14) s=s.SetLength(14);
//                        switch ( alignment)
//                                {
//                                case  0:      //лево
//                                        {
//										if (s.Length()>=14)
//                                                {
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
//                                                }
//                                        else
//												{
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
//                                                }
//                                        break;
//                                        }
//								case  1:    //центр
//                                        {
//                                        if (s.Length()>=14)
//                                                {
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
//												}
//                                        else
//                                                {
//                                                s=DopStrL(s, " ", 14-((14-s.Length())/2));
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
//												}
//
//                                        break;
//                                        }
//                                case  2:   //право
//										{
//                                        if (s.Length()>=14)
//                                                {
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
//                                                }
//										else
//                                                {
//                                                s=DopStrL(s, " ", 14);
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
//                                                }
//
//                                        break;
//                                        }
//
//
//								}
//
//                        break;
//                        }
//                case  4:
//						{
//						if(s.Length()>14) s=s.SetLength(14);
//                        switch ( alignment)
//                                {
//                                case  0:      //лево
//										{
//                                        if (s.Length()>=14)
//                                                {
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
//                                                }
//										else
//                                                {
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
//                                                }
//                                        break;
//										}
//                                case  1:    //центр
//                                        {
//                                        if (s.Length()>=14)
//                                                {
//												Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
//                                                }
//                                        else
//                                                {
//                                                s=DopStrL(s, " ", 14-((14-s.Length())/2));
//												Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
//                                                }
//
//                                        break;
//                                        }
//								case  2:   //право
//                                        {
//                                        if (s.Length()>=14)
//                                                {
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
//												}
//                                        else
//                                                {
//                                                s=DopStrL(s, " ", 14);
//                                                Merc->PrintNonFiscal(WideString("\\1b\\21\\30"+s+"\\0d\\0a").c_bstr(), false,false);
//												}
//
//                                        break;
//										}
//
//
//								}
//						break;
//						}
//
//
//				}
//
//	result=true;
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result=false;
//		}

return result;

}
//---------------------------------------------------------------------------
bool  PrintLine(void)
{
bool result=false;
//
//try
//	{
//	Merc->PrintNonFiscal(WideString("\\1b\\21\\----------------------------------------\\0d\\0a").c_bstr(), false,false);
//	result=true;
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result=false;
//		}
return result;

}
//---------------------------------------------------------------------------


bool  PrintFiscalCheck(double sum,
						int department,
						double oplata_nal,
						double oplata_plat_card,
						int operation)    //0 продажа 1 возврат
{
bool result=false;

NoPrint=false;


//if (ConnectFR==false){return result;}
//if ((oplata_nal+oplata_plat_card)<sum)
//		{
//        TextError="Сумма оплаты меньше суммы чека!";
//		return result;
//        }
//
////проверим открыта ли смена
//if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
//        {
//		try
//                {
//				Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
//                }
//		catch(...)
//                {
//				result=false;
//                return result;
//				}
//        }
//
//if (operation==0) // Составной чек на продажу
//		{
//        Merc->OpenFiscalDoc(motSale);
//		}//конец печати чека продажи
//else
//		{
//        Merc->OpenFiscalDoc(motRefund);
//		}
//
//  try
//  {
//	// Счетчик вертикальной координаты
//    int IV = 0;
////    MSK->AddCustom("ВСЕГО:", 0, 0, IV); IV++;
//
//	 Variant vopl1=oplata_nal ;
//     Variant vopl4=oplata_plat_card  ;
//	// Добавляем итог
//    Merc->AddTotal(0, 0, IV, 0); IV++;
//
//
//	// Добавляем информацию об оплате
//    Merc->AddPay(
//	  mptCashCard,      // - оплата: наличные + платежная карта
//      vopl1,             // - сумма оплаты наличными
//	  vopl4,               // - сумма оплаты по безналу
//      WideString(" ").c_bstr(),               // - дополнительная информация по оплате - игнорируется для комбинированной
//						//   оплаты
//      0,
//	  0,
//      IV,
//	   0); IV++;
//
//
//
//	// Добавляем сумму сдачи
//    Merc->AddChange(0, 0, IV++, 0);
//
//    
//	// Добавляем строки заголовка
//    Merc->AddHeaderLine(1, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(4, 0, 0, IV); IV++;
//
//	// Добавляем позицию
//    // - наименование товара, как дополнительный реквизит
//	Variant vSumCheck=sum;
//
//	Merc->AddItem(
//      mitItem,          // - услуга или товар
//	  vSumCheck,              // - цена товара
//      false,            // - товар не является тарой
//	  1,                // - номер отдела
//      0,              // - код товара
//	  0,                // - игнорируется
//      1, 0,             // - количество = 2 (нет знаков после десятичной точки)
//	  0,                // - индекс налоговой группы
//      WideString(" ").c_bstr(),            // - единица измерения
//	  0,                // - флаги
//      0,                // - смещение по вертикали
//	  IV,               // - смещение по горизонтали
//      0                 // - игнорируется
//	); IV++;
//
//	// Добавляем номер ККМ и номер документа (на одной строке)
//    Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
//	// Добавляем ИНН
//    Merc->AddTaxPayerNumber(0, 0, IV); IV++;
//	// Добавляем дату / время и номер чека (на одной строке)
//	Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
//	// Добавляем информацию об операторе
//	Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;
//
//
//	// Закрываем документ
//	Merc->CloseFiscalDoc();
//	result=true;
//  }
//  catch(Exception &E)            //Exception &E
//  {
//	// В случае ошибки отменяем открытый документ
//	Merc->CancelFiscalDoc(false);
//	TextError=E.Message;
//	result=false;
//  }


return result;

}
//---------------------------------------------------------------------------
bool  PrintNoFiscalCheck(double sum,
								int department,
								double oplata_nal,
								double oplata_plat_card,
								int operation)    //0 продажа 1 возврат
{
bool result=false;
//try
//	{
//	NoPrint=false;
//
//	if (ConnectFR==false){return result;}
//
//	if ((oplata_nal+oplata_plat_card)<sum)
//		{
//		TextError="Сумма оплаты меньше суммы чека!";
//		return result;
//		}
//
//	Merc->PrintNonFiscal(WideString("------------------------------------\r\n").c_bstr(), true,true);
//	Merc->PrintNonFiscal(WideString("Учебный чек напечатан!\r\n").c_bstr(), true,true);
//
//
//	for(int i=0;i<20;i++)
//		{
//		Merc->PrintNonFiscal(WideString(" \r\n").c_bstr(), true,true);
//		}
//	result=true;
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result=false;
//		}
return result;

}
//---------------------------------------------------------------------------
bool  PrintXReport(void)
{
bool result=false;

NoPrint=false;
//try
//	{
//	//проверим открыта ли смена
//	if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
//		{
//		Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
//		}
//		Merc->XReport(1);
//		result=true;
//	 }
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result=false;
//		}

return result;

}
//---------------------------------------------------------------------------
bool PrintZReport(void)
{
bool result=false;
NoPrint=false;
//
//try
//	{
//	if (ConnectFR==true)
//		{
//		//проверим открыта ли смена
//		if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
//			{
//				Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
//			}
//
//			Merc->ZReport(MERC_REPF_NO_ZEROES && MERC_REPF_ACCUMULATE_DEP);
//			result=true;
//		}
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result=false;
//		}


return result;

}
//---------------------------------------------------------------------------
bool  PrintPoOtdelamReport(void)
{
bool result=false;
//NoPrint=false;
//
//try
//	{
//	if (ConnectFR==true)
//		{
//		//проверим открыта ли смена
//		if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
//			{
//				Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
//			}
//
//			Merc->XReportByDep(-1,MERC_REPF_NO_ZEROES && MERC_REPF_ACCUMULATE_DEP);
//			result=true;
//		}
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result=false;
//		}
return result;
}
//---------------------------------------------------------------------------

bool  Cut(int TypeCut)
{
bool result=true ;


//try
//	{
//	if (ConnectFR==true)
//		{
//		Merc->FeedAndCut(1,true);
//		result=true;
//		}
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result=false;
//		}

return result;

}
//---------------------------------------------------------------------------

bool  Vnesenie(double sum)
{
bool result=false;

//if (ConnectFR==true)
//		{
//
//
//
//  try
//  {
//
//        //проверим открыта ли смена
//       // if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
//	   //         {
//       //         Merc->OpenDay(1, WideString("Кассир ").c_bstr(), false, Merc->Protocol);
//       //         }
//
//
//
//	Merc->OpenFiscalDoc(motCashIn);
//    // Счетчик вертикальной координаты
//    int IV = 0;
//
////     Variant vopl1=opl1;
////     Variant vopl4=opl4;
//	// Добавляем итог
//    Merc->AddTotal(MERC_PROPF_DOUBLE_HEIGHT, 0, IV, 0); IV++;
//
//
//
//    // Добавляем строки заголовка
//	Merc->AddHeaderLine(1, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(4, 0, 0, IV); IV++;
//
//    // Добавляем позицию
//	// - наименование товара, как дополнительный реквизит
//    Variant vSumCheck=sum;
//
//	Merc->AddItem(
//      mitItem,          // - услуга или товар
//      vSumCheck,              // - цена товара
//	  false,            // - товар не является тарой
//      1,                // - номер отдела
//      0,              // - код товара
//	  0,                // - игнорируется
//      1, 0,             // - количество = 2 (нет знаков после десятичной точки)
//      0,                // - индекс налоговой группы
//	  WideString(" ").c_bstr(),            // - единица измерения
//      0,                // - флаги
//      0,                // - смещение по вертикали
//	  IV,               // - смещение по горизонтали
//      0                 // - игнорируется
//    ); IV++;
//
//    // Добавляем номер ККМ и номер документа (на одной строке)
//	Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
//    // Добавляем ИНН
//	Merc->AddTaxPayerNumber(0, 0, IV); IV++;
//	// Добавляем дату / время и номер чека (на одной строке)
//	Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
//	// Добавляем информацию об операторе
//	Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;
//
//
//	// Закрываем документ
//	Merc->CloseFiscalDoc();
//	result=true;
//  }
//  catch(Exception &E)            //Exception &E
//  {
//	// В случае ошибки отменяем открытый документ
//	Merc->CancelFiscalDoc(false);
//	result=false;
//	TextError=E.Message;
//  }
//		}
return result;

}
//---------------------------------------------------------------------------
bool  Snatie(double sum)
{
bool result=false;

//if (ConnectFR==true)
//		{
//
//
//
//  try
//  {
//        //проверим открыта ли смена
//		//if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
//        //        {
//        //        Merc->OpenDay(1, WideString("Кассир").c_bstr(), false, Merc->Protocol);
//        //        }
//	Merc->OpenFiscalDoc(motCashOut);
//
//    // Счетчик вертикальной координаты
//    int IV = 0;
//
////     Variant vopl1=opl1;
////     Variant vopl4=opl4;
//    // Добавляем итог
//	Merc->AddTotal(MERC_PROPF_DOUBLE_HEIGHT, 0, IV, 0); IV++;
//
//
//
//	// Добавляем строки заголовка
//    Merc->AddHeaderLine(1, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(4, 0, 0, IV); IV++;
//
//    // Добавляем позицию
//    // - наименование товара, как дополнительный реквизит
//	Variant vSumCheck=sum;
//
//    Merc->AddItem(
//      mitItem,          // - услуга или товар
//	  vSumCheck,              // - цена товара
//      false,            // - товар не является тарой
//      1,                // - номер отдела
//      0,              // - код товара
//	  0,                // - игнорируется
//      1, 0,             // - количество = 2 (нет знаков после десятичной точки)
//      0,                // - индекс налоговой группы
//      WideString(" ").c_bstr(),            // - единица измерения
//	  0,                // - флаги
//      0,                // - смещение по вертикали
//      IV,               // - смещение по горизонтали
//      0                 // - игнорируется
//	); IV++;
//
//    // Добавляем номер ККМ и номер документа (на одной строке)
//    Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
//	// Добавляем ИНН
//    Merc->AddTaxPayerNumber(0, 0, IV); IV++;
//	// Добавляем дату / время и номер чека (на одной строке)
//	Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
//    // Добавляем информацию об операторе
//	Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;
//
//
//	// Закрываем документ
//	Merc->CloseFiscalDoc();
//	result=true;
//  }
//  catch(...)            //Exception &E
//  {
//	// В случае ошибки отменяем открытый документ
//	Merc->CancelFiscalDoc(false);
//	result=false;
//	throw;
//  }
//		}


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
//--------------------------------------------------------------------------
char*  GetTimeKKM(void)
{
char* result="";
//try
//	{
//	AnsiString time=TimeToStr(Merc->QueryEcrDateTime())+" ";
//	result=time.c_str();
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result="";
//		}
return result;

}
//-----------------------------------------------------------------------------
char*  GetDateKKM(void)
{
char* result="";
//try
//	{
//	AnsiString date=DateToStr(Merc->QueryEcrDateTime())+" ";
//	result=date.c_str();
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result="";
//		}
return result;

}
//--------------------------------------------------------------------------
bool  SetTimeKKM(char * time)
{
bool result=false;


//try
//	{
//	if (ConnectFR==true)
//		{
//		Merc->SynchronizeEcrDateTime();
//		result=true;
//		}
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result=false;
//		}


return result;
}
//-----------------------------------------------------------------------------
bool  SetDateKKM(char * date)
{
bool result=false;


//try
//	{
//	if (ConnectFR==true)
//		{
//		Merc->SynchronizeEcrDateTime();
//		result=true;
//		}
//	}
//catch (Exception &E)
//		{
//		TextError=E.Message;
//		result=false;
//		}

return result;
}
//-----------------------------------------------------------------------------