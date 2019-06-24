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
                                                int style,           //1-������ 0 �������   2 ������ 3 ������ ������
                                                int alignment,       //0 ���� 1 ����� 2 �����
                                                bool ch_lenta,       //�� ������� �����
												bool kontr_lenta,    //�� ����������� �����
												bool word_wrap);

extern "C" bool __declspec (dllexport) PrintLine(void);


extern "C" bool __declspec (dllexport) PrintFiscalCheck(double sum,
                                                        int department,
                                                        double oplata_nal,
                                                        double oplata_plat_card,
                                                        int operation);    //0 ������� 1 �������

extern "C" bool __declspec (dllexport) PrintNoFiscalCheck(double sum,
                                int department,
                                double oplata_nal,
                                double oplata_plat_card,
                                int operation);    //0 ������� 1 �������

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
		TextError="�� ������� ������� ������ ����������� ������������ !";
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
		ShowMessage("�� ������� ������������ � ��! ErrMessage: "+FR.OlePropertyGet("ErrMessage"));
	   //	ShowMessage("�� ������� ������������ � ��! Exception "+E.Message);
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
				TextError="������ ����������� ������������: "+FR.OlePropertyGet("ErrMessage");
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
//        ShowMessage("������� ����������!");     
//
//        if (Merc->ErrCodeEx!= 0)
//                {
//				ShowMessage("����� ������ ������. ���� ������!");
//                result=false;
//                TextError="�� ������� ������������ � ��! ������: "+WideCharToString(Merc->ErrMessage) ;
//                //ShowMessage(TextError);
//                }
//        else
//                {
//                //ShowMessage("������ ���");
//                result=true;
//				ConnectFR=true;
//				ShowMessage("����� ������ ������. ������ ���!");
//                }

//
//		}
//
//catch (Exception &E)
//        {
//		result=false;
//        TextError="�� ������� ������������ � ��! ������: "+E.Message;
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
//		//ShowMessage("������� ������ �������� "+Merc->CheckDevStatus(13));
//	   //	int i=0;
//	   ShowMessage("������ ��������: "+IntToStr(Merc->CheckEcrStatus(MERC_DS_OPENED_COVER))) ;
//		ShowMessage("������� �����: "+IntToStr(Merc->CheckEcrStatus(MERC_DS_RECEIPT_OUT))) ;
//	   //	ShowMessage(IntToHex(Merc->EcrStatus
//
//		switch (Merc->DevStatus)
//		{
//		case MERC_DS_OPENED_COVER :      //���� ������ ���������� �������
//				{
//				ShowMessage("������� ������ ��������! MERC_DS_OPENED_COVER");
//				result=false;
//                return result;
//				}
//
//		case MERC_DS_PRINTER_ERROR :      //���� ������ ���������� �������
//                {
//				ShowMessage("������ ��������! MERC_DS_PRINTER_ERROR");
//                result=false;
//				return result;
//                }
//
//        case MERC_DS_MECHANICAL_ERROR :      //���� ������ ���������� �������
//				{
//                ShowMessage("������  �������� ��������! MERC_DS_MECHANICAL_ERROR");
//				result=false;
//                return result;
//				}
//
//		case MERC_DS_CUTTER_ERROR :      //���� ������ ���������� �������
//                {
//				ShowMessage("������  ���������! MERC_DS_CUTTER_ERROR");
//                result=false;
//				return result;
//                }
//
//        case MERC_DS_FATAL_ERROR :      //���� ������ ���������� �������
//				{
//                ShowMessage("����������� ������ ��������! MERC_DS_FATAL_ERROR");
//				result=false;
//                return result;
//				}
//
//		case MERC_DS_OVERHEATING :      //���� ������ ���������� �������
//                {
//				ShowMessage("�������� ���������� �������! MERC_DS_OVERHEATING ");
//                result=false;
//				return result;
//                }
//
//        case MERC_DS_JOURNAL_OUT :      //���� ������ ���������� �������
//				{
//                ShowMessage("��� ����������� �����! MERC_DS_JOURNAL_OUT");
//				result=false;
//                return result;
//				}
//
//		case MERC_DS_RECEIPT_OUT :      //���� ������ ���������� �������
//                {
//				ShowMessage("��� ������� �����! MERC_DS_RECEIPT_OUT");
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
//AnsiString num="�������� MS-K ";
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
												int style,           //1-������ 0 �������   2 ������ 3 ������ ������
												int alignment,       //0 ���� 1 ����� 2 �����
												bool ch_lenta,       //�� ������� �����
												bool kontr_lenta,    //�� ����������� �����
												bool word_wrap)
{
bool result=false;
AnsiString s=AnsiString(str);

//int kol_symbol=0;

//������� �� ������
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
//								case  0:      //����
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
//                                case  1:    //�����
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
//                                case  2:   //�����
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
//                                case  0:      //����
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
//								case  1:    //�����
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
//                                case  2:   //�����
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
//                                case  0:      //����
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
//								case  1:    //�����
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
//                                case  2:   //�����
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
//                                case  0:      //����
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
//                                case  1:    //�����
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
//								case  2:   //�����
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
						int operation)    //0 ������� 1 �������
{
bool result=false;

NoPrint=false;


//if (ConnectFR==false){return result;}
//if ((oplata_nal+oplata_plat_card)<sum)
//		{
//        TextError="����� ������ ������ ����� ����!";
//		return result;
//        }
//
////�������� ������� �� �����
//if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
//        {
//		try
//                {
//				Merc->OpenDay(1, WideString("������ ").c_bstr(), false, Merc->Protocol);
//                }
//		catch(...)
//                {
//				result=false;
//                return result;
//				}
//        }
//
//if (operation==0) // ��������� ��� �� �������
//		{
//        Merc->OpenFiscalDoc(motSale);
//		}//����� ������ ���� �������
//else
//		{
//        Merc->OpenFiscalDoc(motRefund);
//		}
//
//  try
//  {
//	// ������� ������������ ����������
//    int IV = 0;
////    MSK->AddCustom("�����:", 0, 0, IV); IV++;
//
//	 Variant vopl1=oplata_nal ;
//     Variant vopl4=oplata_plat_card  ;
//	// ��������� ����
//    Merc->AddTotal(0, 0, IV, 0); IV++;
//
//
//	// ��������� ���������� �� ������
//    Merc->AddPay(
//	  mptCashCard,      // - ������: �������� + ��������� �����
//      vopl1,             // - ����� ������ ���������
//	  vopl4,               // - ����� ������ �� �������
//      WideString(" ").c_bstr(),               // - �������������� ���������� �� ������ - ������������ ��� ���������������
//						//   ������
//      0,
//	  0,
//      IV,
//	   0); IV++;
//
//
//
//	// ��������� ����� �����
//    Merc->AddChange(0, 0, IV++, 0);
//
//    
//	// ��������� ������ ���������
//    Merc->AddHeaderLine(1, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(4, 0, 0, IV); IV++;
//
//	// ��������� �������
//    // - ������������ ������, ��� �������������� ��������
//	Variant vSumCheck=sum;
//
//	Merc->AddItem(
//      mitItem,          // - ������ ��� �����
//	  vSumCheck,              // - ���� ������
//      false,            // - ����� �� �������� �����
//	  1,                // - ����� ������
//      0,              // - ��� ������
//	  0,                // - ������������
//      1, 0,             // - ���������� = 2 (��� ������ ����� ���������� �����)
//	  0,                // - ������ ��������� ������
//      WideString(" ").c_bstr(),            // - ������� ���������
//	  0,                // - �����
//      0,                // - �������� �� ���������
//	  IV,               // - �������� �� �����������
//      0                 // - ������������
//	); IV++;
//
//	// ��������� ����� ��� � ����� ��������� (�� ����� ������)
//    Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
//	// ��������� ���
//    Merc->AddTaxPayerNumber(0, 0, IV); IV++;
//	// ��������� ���� / ����� � ����� ���� (�� ����� ������)
//	Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
//	// ��������� ���������� �� ���������
//	Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;
//
//
//	// ��������� ��������
//	Merc->CloseFiscalDoc();
//	result=true;
//  }
//  catch(Exception &E)            //Exception &E
//  {
//	// � ������ ������ �������� �������� ��������
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
								int operation)    //0 ������� 1 �������
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
//		TextError="����� ������ ������ ����� ����!";
//		return result;
//		}
//
//	Merc->PrintNonFiscal(WideString("------------------------------------\r\n").c_bstr(), true,true);
//	Merc->PrintNonFiscal(WideString("������� ��� ���������!\r\n").c_bstr(), true,true);
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
//	//�������� ������� �� �����
//	if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
//		{
//		Merc->OpenDay(1, WideString("������ ").c_bstr(), false, Merc->Protocol);
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
//		//�������� ������� �� �����
//		if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
//			{
//				Merc->OpenDay(1, WideString("������ ").c_bstr(), false, Merc->Protocol);
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
//		//�������� ������� �� �����
//		if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
//			{
//				Merc->OpenDay(1, WideString("������ ").c_bstr(), false, Merc->Protocol);
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
//        //�������� ������� �� �����
//       // if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
//	   //         {
//       //         Merc->OpenDay(1, WideString("������ ").c_bstr(), false, Merc->Protocol);
//       //         }
//
//
//
//	Merc->OpenFiscalDoc(motCashIn);
//    // ������� ������������ ����������
//    int IV = 0;
//
////     Variant vopl1=opl1;
////     Variant vopl4=opl4;
//	// ��������� ����
//    Merc->AddTotal(MERC_PROPF_DOUBLE_HEIGHT, 0, IV, 0); IV++;
//
//
//
//    // ��������� ������ ���������
//	Merc->AddHeaderLine(1, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(4, 0, 0, IV); IV++;
//
//    // ��������� �������
//	// - ������������ ������, ��� �������������� ��������
//    Variant vSumCheck=sum;
//
//	Merc->AddItem(
//      mitItem,          // - ������ ��� �����
//      vSumCheck,              // - ���� ������
//	  false,            // - ����� �� �������� �����
//      1,                // - ����� ������
//      0,              // - ��� ������
//	  0,                // - ������������
//      1, 0,             // - ���������� = 2 (��� ������ ����� ���������� �����)
//      0,                // - ������ ��������� ������
//	  WideString(" ").c_bstr(),            // - ������� ���������
//      0,                // - �����
//      0,                // - �������� �� ���������
//	  IV,               // - �������� �� �����������
//      0                 // - ������������
//    ); IV++;
//
//    // ��������� ����� ��� � ����� ��������� (�� ����� ������)
//	Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
//    // ��������� ���
//	Merc->AddTaxPayerNumber(0, 0, IV); IV++;
//	// ��������� ���� / ����� � ����� ���� (�� ����� ������)
//	Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
//	// ��������� ���������� �� ���������
//	Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;
//
//
//	// ��������� ��������
//	Merc->CloseFiscalDoc();
//	result=true;
//  }
//  catch(Exception &E)            //Exception &E
//  {
//	// � ������ ������ �������� �������� ��������
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
//        //�������� ������� �� �����
//		//if (Merc->CheckEcrStatus(MERC_S_DAY_OPENED)<0)
//        //        {
//        //        Merc->OpenDay(1, WideString("������").c_bstr(), false, Merc->Protocol);
//        //        }
//	Merc->OpenFiscalDoc(motCashOut);
//
//    // ������� ������������ ����������
//    int IV = 0;
//
////     Variant vopl1=opl1;
////     Variant vopl4=opl4;
//    // ��������� ����
//	Merc->AddTotal(MERC_PROPF_DOUBLE_HEIGHT, 0, IV, 0); IV++;
//
//
//
//	// ��������� ������ ���������
//    Merc->AddHeaderLine(1, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(2, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(3, 0, 0, IV); IV++;
////    MSK->AddHeaderLine(4, 0, 0, IV); IV++;
//
//    // ��������� �������
//    // - ������������ ������, ��� �������������� ��������
//	Variant vSumCheck=sum;
//
//    Merc->AddItem(
//      mitItem,          // - ������ ��� �����
//	  vSumCheck,              // - ���� ������
//      false,            // - ����� �� �������� �����
//      1,                // - ����� ������
//      0,              // - ��� ������
//	  0,                // - ������������
//      1, 0,             // - ���������� = 2 (��� ������ ����� ���������� �����)
//      0,                // - ������ ��������� ������
//      WideString(" ").c_bstr(),            // - ������� ���������
//	  0,                // - �����
//      0,                // - �������� �� ���������
//      IV,               // - �������� �� �����������
//      0                 // - ������������
//	); IV++;
//
//    // ��������� ����� ��� � ����� ��������� (�� ����� ������)
//    Merc->AddSerialNumber(0, 0, IV);  Merc->AddDocNumber(0, 31, IV); IV++;
//	// ��������� ���
//    Merc->AddTaxPayerNumber(0, 0, IV); IV++;
//	// ��������� ���� / ����� � ����� ���� (�� ����� ������)
//	Merc->AddDateTime(0, 0, IV); Merc->AddReceiptNumber(0, 31, IV); IV++;
//    // ��������� ���������� �� ���������
//	Merc->AddOperInfo(moiNumberName, 0, 0, IV); IV++;
//
//
//	// ��������� ��������
//	Merc->CloseFiscalDoc();
//	result=true;
//  }
//  catch(...)            //Exception &E
//  {
//	// � ������ ������ �������� �������� ��������
//	Merc->CancelFiscalDoc(false);
//	result=false;
//	throw;
//  }
//		}


return result;

}
//---------------------------------------------------------------------------
//��������� ������ Str ����� ��������� Symbol �� Len
String DopStrL(String Str, String Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//---------------------------------------------------------------------------
//��������� ������ Str ������ ��������� Symbol �� Len
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