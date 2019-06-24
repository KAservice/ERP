//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <oleauto.hpp>
#include <SysUtils.hpp>
#include <math.h>
#pragma hdrstop

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
extern "C" bool __declspec (dllexport) PrintString(char* string,
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
//bool UseJournalRibbon=true;
bool UseReceiptRibbon=true;
bool OpenNoFiscalDoc=false;

Variant  FR;
int GetNumberBaudRate(char * br);
int EndPrint(void);

String DopStrL(String Str, String Symbol, int Len);
String DopStrR(String Str, String Symbol, int Len);
int CompareDoubleValue(double v1, double v2, int pogr);
//------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------


bool  Connect(int number_port,
                char* baud_rate,
                char* password)
{

bool result=false;
NoPrint=false;
//UseJournalRibbon=true;
UseReceiptRibbon=true;
OpenNoFiscalDoc=false;


try
        {
        FR = Variant::CreateObject("AddIn.DrvFR");
        }
catch (...)
        {
        TextError="Не удалось создать объект фискального регистратора !";
        ConnectFR=false;
        }

FR.OlePropertySet("Password",30);
FR.OlePropertySet("BaudRate",GetNumberBaudRate(baud_rate) );

        FR.OlePropertySet("ComNumber",number_port);

        FR.OleProcedure("Connect");
        if(FR.OlePropertyGet("ResultCode")==0)
                {
                ConnectFR=true;
                result=true;
                NoPrint=false;
                }
        else
                {
                TextError="Ошибка фискального регистратора: "+FR.OlePropertyGet("ResultCodeDescription");
                ConnectFR=false;
                result=false;
                }

return result;
}
//--------------------------------------------------------------------------

void  Disconnect(void)
{

if (ConnectFR==true)
		{
		FR.OleProcedure("Disconnect");
        }
}
//---------------------------------------------------------------------------

bool  GetSostKKM(void)
{
bool result=true;

FR.OleProcedure("GetECRStatus");
if(FR.OlePropertyGet("ResultCode")==0)
	{
	result=true;
	}
else
	{
	TextError="Ошибка фискального регистратора: "+FR.OlePropertyGet("ResultCodeDescription");
	ConnectFR=false;
	result=false;
	}

return result;
}
//---------------------------------------------------------------------------
bool  ProvVosmPrintCheck(void)
{
bool result=true;

GetSostKKM();
NoPrint=false;


if (FR.OlePropertyGet("ReceiptRibbonIsPresent")==0)
        {
        TextError="Нет рулона чековой ленты!";
        result=false;
        return result;
        }

//if (FR.OlePropertyGet("JournalRibbonIsPresent")==0 )
//		{
//		TextError="Нет рулона контрольной ленты!";
//		result=false;
//		return result;
//		}

//if (FR.OlePropertyGet("JournalRibbonOpticalSensor")==0 )
//		{
//		TextError="Необходимо правильно заправить контрольную ленту!";
//		result=false;
//		return result;
//		}

if (FR.OlePropertyGet("ReceiptRibbonOpticalSensor")==0)
        {
        TextError="Необходимо правильно заправить чековую ленту!";
        result=false;
        return result;
        }

//if (FR.OlePropertyGet("JournalRibbonLever")==0)
//		{
//		TextError="Необходимо прижать термоголовку контрольной ленты!";
//		result=false;
//		return result;
//		}

if (FR.OlePropertyGet("ReceiptRibbonLever")==0)
        {
        TextError="Необходимо прижать термоголовку чековой ленты!";
        result=false;
        return result;
        }

if (FR.OlePropertyGet("IsPrinterLeftSensorFailure")==1)
        {
        TextError="Отказ левого датчика печатающего механизма!";
        result=false;
        return result;
        }

if (FR.OlePropertyGet("IsPrinterRightSensorFailure")==1)
        {
        TextError="Отказ правого датчика печатающего механизма!";
        result=false;
        return result;
        }



if (FR.OlePropertyGet("ECRMode")==1)
        {
        TextError="Выдача данных!";
        result=false;
        return result;
        }

if (FR.OlePropertyGet("ECRMode")==3)
        {
        TextError="Прошло более 24 часов от начала смены.Необходимо вывести отчет с гашением!";
        result=false;
        return result;
        }

if (FR.OlePropertyGet("ECRMode")==5)
        {
        TextError="Необходимо ввести пароль налогового инспектора!";
        result=false;
        return result;
        }

if (FR.OlePropertyGet("ECRMode")==6)
        {
        TextError="Необходимо подтвердить ввод даты с использованием тестовой утилиты!";
        result=false;
        return result;
        }

if (FR.OlePropertyGet("ECRMode")==8)
        {
        TextError="Не закрыт предыдущий чек. Он будет отменен!!";

        FR.OleProcedure("SysAdminCancelCheck");

        result=false;
        return result;
        }

if (FR.OlePropertyGet("ECRMode")==10)
        {
        TextError="Идет тестовый прогон. Ввод чека невозможен.!";
        result=false;
        return result;
        }

if (FR.OlePropertyGet("ECRMode")==11)
        {
        TextError="Идет печать фискального отчета!";
        result=false;
        return result;
        }

if (FR.OlePropertyGet("ECRMode")==12)
        {
        TextError="Идет печать отчета по ЭКЛЗ!";
        result=false;
        return result;
        }

result=true;


return result;

}
//---------------------------------------------------------------------------
int GetNumberCheck(void)
{
int result=0;

result=FR.OlePropertyGet("OpenDocumentNumber");

return result;

}
//---------------------------------------------------------------------------
int  GetNumberKL(void)
{
int result=0;

result=FR.OlePropertyGet("SessionNumber");

return result;

}
//---------------------------------------------------------------------------
char*  GetSerialNumberKKM(void)
{
char* result="";
FR.OleProcedure("GetLongSerialNumberAndLongRNM");
AnsiString num=FR.OlePropertyGet("SerialNumber");
result=num.c_str();

return result;

}
//---------------------------------------------------------------------------
char*  GetRegNumberKKM(void)
{
char* result="";
FR.OleProcedure("GetLongSerialNumberAndLongRNM");
AnsiString num=FR.OlePropertyGet("RNM");
result=num.c_str();

return result;

}
//---------------------------------------------------------------------------
char*  GetModelKKM(void)
{
char* result="";
AnsiString num="Штрих-Комбо-ФР-К";
result=num.c_str();

return result;

}
//---------------------------------------------------------------------------
bool   OpenNoFiscalCheck(void)
{
bool result=true;

return result;
}
//---------------------------------------------------------------------------
bool   CloseNoFiscalCheck(void)
{
bool result=true;

return result;

}
//---------------------------------------------------------------------------
bool  PrintString(char* string,
												int size_font,       //1234
												int style,           //1-жирный 0 обычный   2 курсив 3 жирный курсив
												int alignment,       //0 лево 1 центр 2 право
												bool ch_lenta,       //на чековой ленте
												bool kontr_lenta,   //на контрольной ленте
												bool word_wrap)   //перенос по словам
{
bool result=false;
AnsiString s=AnsiString(string);

if (ConnectFR==false){return result;}

//FR.OlePropertySet("UseJournalRibbon",kontr_lenta);
FR.OlePropertySet("UseReceiptRibbon",ch_lenta);

int kol_symbol=0;

//перенос по словам
//*********************************************************************

if (word_wrap==true)
	{
		TStringList * strings=new TStringList();
		switch (size_font)
				{
				case  1:      //36
						{kol_symbol=48;break;}
				case  2:         //36
						{kol_symbol=48;break;}
				case  3:   //18
						{kol_symbol=25;break;}
				case  4:    //18
						{kol_symbol=24;break;}
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


		switch ( size_font)
				{
				case  1:
						{
						if(s.Length()>48) s=s.SetLength(48);
                        switch ( alignment)
                                {
								case  0:      //лево
                                        {
										if (s.Length()>=48)
                                                {
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}
												}
										else
												{
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}
												}
                                        break;
                                        }
                                case  1:    //центр
                                        {
										if (s.Length()>=48)
                                                {
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", 48-((48-s.Length())/2));
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
										if (s.Length()>=48)
												{
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", 48);
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}
                                                }

                                        break;
                                        }


                                }
                        break;
                        }
                case  2:
						{
						if(s.Length()>48) s=s.SetLength(48);
                        switch ( alignment)
                                {
                                case  0:      //лево
                                        {
										if (s.Length()>=48)
                                                {
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}
                                                }
                                        else
                                                {
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}
												}
                                        break;
                                        }
                                case  1:    //центр
                                        {
										if (s.Length()>=48)
												{
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", 48-((48-s.Length())/2));
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
										if (s.Length()>=48)
                                                {
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", 48);
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}
                                                }

                                        break;
                                        }


                                }
                        break;
                        }
                case  3:
						{
						if(s.Length()>24) s=s.SetLength(24);
                        switch ( alignment)
                                {
                                case  0:      //лево
                                        {
										if (s.Length()>=24)
												{
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintWideString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintWideString");}
												}
                                        else
                                                {
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintWideString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintWideString");}
                                                }
                                        break;
                                        }
                                case  1:    //центр
                                        {
										if (s.Length()>=24)
                                                {
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintWideString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintWideString");}
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", 24-((24-s.Length())/2));
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintWideString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintWideString");}
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
										if (s.Length()>=24)
                                                {
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintWideString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintWideString");}
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", 24);
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintWideString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintWideString");}
                                                }

                                        break;
                                        }


                                }

                        break;
                        }
                case  4:
						{
						if(s.Length()>24) s=s.SetLength(24);
                        switch ( alignment)
                                {
                                case  0:      //лево
                                        {
										if (s.Length()>=24)
                                                {
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintWideString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintWideString");}
                                                }
                                        else
                                                {
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintWideString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintWideString");}
												}
                                        break;
                                        }
                                case  1:    //центр
                                        {
										if (s.Length()>=24)
                                                {
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintWideString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintWideString");}
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", 24-((24-s.Length())/2));
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintWideString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintWideString");}
                                                }

                                        break;
                                        }
                                case  2:   //право
                                        {
										if (s.Length()>=24)
                                                {
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintWideString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintWideString");}
                                                }
                                        else
                                                {
												s=DopStrL(s, " ", 24);
												FR.OlePropertySet("StringForPrinting",s.c_str());
												if (NoPrint==false) {FR.OleProcedure("PrintWideString");}
												while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintWideString");}
                                                }

                                        break;
                                        }


                                }
                        break;
                        }


				}

//---------------------------------------------------------------------
if (NoPrint==false)
        {
        result=true;
        }
else
        {
        result=false;
        TextError=FR.OlePropertyGet("ResultCodeDescription");
        }

return result;

}
//---------------------------------------------------------------------------
bool  PrintLine(void)
{
bool result=false;


if (ConnectFR==false){return result;}

//FR.OlePropertySet("UseJournalRibbon",true);
FR.OlePropertySet("UseReceiptRibbon",true);

FR.OlePropertySet("StringForPrinting","------------------------------------------------");
if (NoPrint==false) {FR.OleProcedure("PrintString");}
while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}

if (NoPrint==false)
        {
        result=true;
        }
else
        {
        result=false;
        TextError=FR.OlePropertyGet("ResultCodeDescription");
		}
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


if (ConnectFR==false){return result;}

if (CompareDoubleValue(oplata_nal+oplata_plat_card, sum, 3) == -1)
        {
		TextError="Сумма оплаты меньше суммы чека!";
        return result;
		}

FR.OlePropertySet("StringForPrinting","");
FR.OlePropertySet("Price",sum);
FR.OlePropertySet("Department",department);
FR.OlePropertySet("Quantity",1);

if (operation==0)    //продажа
        {
		FR.OleProcedure("Sale");
		if(FR.OlePropertyGet("ResultCode")!=0)
			{
			TextError="Ошибка фискального регистратора: "+FR.OlePropertyGet("ResultCodeDescription");
			}
        }

if (operation==1)   //возврат
        {
		FR.OleProcedure("ReturnSale");
		if(FR.OlePropertyGet("ResultCode")!=0)
			{
			TextError="Ошибка фискального регистратора: "+FR.OlePropertyGet("ResultCodeDescription");
			}
        }
        
//закроем чек
FR.OlePropertySet("Summ1",oplata_nal);
FR.OlePropertySet("Summ4",oplata_plat_card);

FR.OlePropertySet("StringForPrinting","------------------------------------------------");
FR.OleProcedure("CloseCheck");
		if(FR.OlePropertyGet("ResultCode")!=0)
			{
			TextError="Ошибка фискального регистратора: "+FR.OlePropertyGet("ResultCodeDescription");
			}

if (NoPrint==false)
        {
        result=true;
        }
else
        {
        result=false;
        }

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

NoPrint=false;

if (ConnectFR==false){return result;}


if (CompareDoubleValue(oplata_nal+oplata_plat_card, sum, 3) == -1)
        {
		TextError="Сумма оплаты меньше суммы чека!";
        return result;
		}

FR.OlePropertySet("StringForPrinting","------------------------------------------------");
if (NoPrint==false) {FR.OleProcedure("PrintString");}
while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}


FR.OlePropertySet("StringForPrinting","Учебный чек напечатан!");

if (NoPrint==false) {FR.OleProcedure("PrintString");}
while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}

for(int i=0;i<5;i++)
        {
        FR.OlePropertySet("StringForPrinting"," ");
        if (NoPrint==false) {FR.OleProcedure("PrintString");}
        while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("PrintString");}
        }

FR.OlePropertySet("CutType",1);
if (NoPrint==false) {FR.OleProcedure("CutCheck");}
while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("CutCheck");}

if (NoPrint==false)
        {
        result=true;
        }
else
        {
        result=false;
        TextError=FR.OlePropertyGet("ResultCodeDescription");
		}

return result;

}
//---------------------------------------------------------------------------
bool  PrintXReport(void)
{
bool result=false;

NoPrint=false;
if (ConnectFR==false)  return result;
FR.OleProcedure("PrintReportWithoutCleaning");
		if(FR.OlePropertyGet("ResultCode")!=0)
			{
			TextError="Ошибка фискального регистратора: "+FR.OlePropertyGet("ResultCodeDescription");
			}
result=true;
return result;

}
//---------------------------------------------------------------------------
bool PrintZReport(void)
{
bool result=false; 

NoPrint=false;
if (ConnectFR==false)  return result;
FR.OleProcedure("PrintReportWithCleaning");
		if(FR.OlePropertyGet("ResultCode")!=0)
			{
			TextError="Ошибка фискального регистратора: "+FR.OlePropertyGet("ResultCodeDescription");
			}
result=true;

return result;

}
//---------------------------------------------------------------------------
bool  PrintPoOtdelamReport(void)
{
bool result=false;
if (ConnectFR==false)  return result;
FR.OleProcedure("PrintDepartmentReport");
		if(FR.OlePropertyGet("ResultCode")!=0)
			{
			TextError="Ошибка фискального регистратора: "+FR.OlePropertyGet("ResultCodeDescription");
			}
result=true;
return result;

}
//---------------------------------------------------------------------------

bool  Cut(int TypeCut)
{
bool result=false;
if (ConnectFR==false)  return result;
FR.OlePropertySet("CutType",TypeCut);
if (NoPrint==false) {FR.OleProcedure("CutCheck");}
while(EndPrint()!=0 && NoPrint==false){FR.OleProcedure("CutCheck");}

result=true;
return result;

}
//---------------------------------------------------------------------------

bool  Vnesenie(double sum)
{
bool result=false;

if (ConnectFR==false) return result;

FR.OlePropertySet("Summ1",sum);
FR.OleProcedure("CashIncome");
		if(FR.OlePropertyGet("ResultCode")!=0)
			{
			TextError="Ошибка фискального регистратора: "+FR.OlePropertyGet("ResultCodeDescription");
			}
		else
			{
			 result=true;
			}
return result;

}
//---------------------------------------------------------------------------
bool  Snatie(double sum)
{
bool result=false;
if (ConnectFR==false) return result;

FR.OlePropertySet("Summ1",sum);
FR.OleProcedure("CashOutcome");
		if(FR.OlePropertyGet("ResultCode")!=0)
			{
			TextError="Ошибка фискального регистратора: "+FR.OlePropertyGet("ResultCodeDescription");
			}
		else
			{
			 result=true;
			}

return result;

}
//---------------------------------------------------------------------------
int GetNumberBaudRate(char * br)
{
int result=1;
AnsiString baud=br;
if (baud=="115200")
        {
         result=6;
        }
return result;
}
//----------------------------------------------------------------------------
int EndPrint(void)
{
int result=0;
if (NoPrint==true) return result;
int numError=FR.OlePropertyGet("ResultCode");
if(numError==0) return result;

switch (numError)
        {

        case 80 :      //идет печать предыдущей команды
                {
                result=1;

                } break;

        case 114 :        //нет бумаги
                {
                result=1;
                NoPrint=true;
                TextError="Проверьте состояние печатающего устройства ! Ошибка фискального регистратора: "
                                +FR.OlePropertyGet("ResultCodeDescription");
                }break;

        case 88 :        //продолжение печати
                {
                FR.OleProcedure("ContinuePrint");
                }break;
        default :
                {
                result=2;
                NoPrint=true;
                TextError="Ошибка фискального регистратора: "
                                +FR.OlePropertyGet("ResultCodeDescription");

                } break;

        }
return result;

}
//----------------------------------------------------------------------------
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
char*  GetTimeKKM(void)
{
char* result="";
FR.OleProcedure("GetECRStatus");
AnsiString time=FR.OlePropertyGet("Time");
result=time.c_str();

return result;

}
//-----------------------------------------------------------------------------
char*  GetDateKKM(void)
{
char* result="";
FR.OleProcedure("GetECRStatus");
AnsiString date=FR.OlePropertyGet("Date");
result=date.c_str();

return result;

}
//--------------------------------------------------------------------------
bool  SetTimeKKM(char * time)
{
bool result=false;

FR.OlePropertySet("Password",30);
FR.OlePropertySet("Time",time);

		FR.OleProcedure("SetTime");
		if(FR.OlePropertyGet("ResultCode")==0)
				{
				result=true;
				}
		else
				{
				TextError="Ошибка фискального регистратора: "+FR.OlePropertyGet("ResultCodeDescription");
				result=false;
				}

return result;
}
//-----------------------------------------------------------------------------
bool  SetDateKKM(char * date)
{
bool result=false;

FR.OlePropertySet("Password",30);
FR.OlePropertySet("Date",date);

		FR.OleProcedure("SetDate");
		if(FR.OlePropertyGet("ResultCode")==0)
				{
				result=true;
				}
		else
				{
				TextError="Ошибка фискального регистратора: "+FR.OlePropertyGet("ResultCodeDescription");
				result=false;
				}

		FR.OleProcedure("ConfirmDate");
		if(FR.OlePropertyGet("ResultCode")==0)
				{
				result=true;
				}
		else
				{
				TextError="Ошибка фискального регистратора: "+FR.OlePropertyGet("ResultCodeDescription");
				result=false;
				}

return result;
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
