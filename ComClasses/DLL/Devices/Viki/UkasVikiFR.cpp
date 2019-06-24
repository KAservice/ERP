//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkasVikiFR.h"
#include <math.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)




//-------------------------------------------------------------------
TkasVikiFR::TkasVikiFR()
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


kasListDocumentPackage = new TStringList;
kasListCheckPackage = new TStringList;
kasListGoodsPackage = new TStringList;
}
//-----------------------------------------------------------------------------
TkasVikiFR::~TkasVikiFR()
{
delete kasListDocumentPackage;
delete kasListCheckPackage;
delete kasListGoodsPackage;
//ObjectVC->kanRelease();
}
//---------------------------------------------------------------------------
int TkasVikiFR::Init()
{
if (InterfaceMainObject>0)
	{
	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

InterfaceGlobalCom->kanCreateObject(ProgId_Object1CVnComp,IID_IObject1CVnComp, (void**)&ObjectVC);
ObjectVC->NameDllVnComp=Modul;
ObjectVC->InitVC();


return -1;
}
//----------------------------------------------------------------------------
int TkasVikiFR::Done()
{
ObjectVC->DoneVC();
ObjectVC->kanRelease();
return -1;
}

//---------------------------------------------------------------------------
bool TkasVikiFR::GetError(void)
{
bool result=false;

int	num_metod=ObjectVC->FindMethod(L"ПолучитьОшибку");
int	kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //количество параметров метода 1

	TkasVariant * in_parameter_err=new TkasVariant;
	for(int i = 0; i < kol_parameter_metoda; i++)
		{
		InitKasVariant(&in_parameter_err[i]);
		}
	TkasVariant * variant_result_err=new TkasVariant;
	InitKasVariant(variant_result_err);


	ObjectVC->CallAsFunc(num_metod,variant_result_err,in_parameter_err, 1);

	if (variant_result_err->type==1 && variant_result_err->int_value!=0)  //здесь код ошибки не боол
		{
		result=true;
		if (in_parameter_err[0].type==2)
			{
			TextError=TextError+" Код ошибки:"+IntToStr(variant_result_err->int_value)+" "+UnicodeString(in_parameter_err[0].string_value);
			}
		}
	else
		{
		result=false;
		}

	delete in_parameter_err;
	delete variant_result_err;

return result;
}
//---------------------------------------------------------------------------

bool  TkasVikiFR::Connect(int number_port,
				UnicodeString baud_rate,
				UnicodeString password)
{
bool result=true;
TextError="";
TextErrorNoConnect="";

//int num_prop=ObjectVC->FindProp(L"Включен");
//TkasVariant * in_variant=new TkasVariant;
//InitKasVariant(in_variant);
//in_variant->bool_value=true; 	in_variant->type=4;
//ObjectVC->SetPropVal(num_prop,in_variant);
//
//num_prop=ObjectVC->FindProp(L"Включен");
//	TkasVariant * variant_result=new TkasVariant;
//	InitKasVariant(variant_result);
//
//ObjectVC->GetPropVal(num_prop,variant_result);
//delete variant_result;
//
//
//num_prop=ObjectVC->FindProp(L"ЕстьТаймер");
//InitKasVariant(in_variant);
//in_variant->bool_value=true; 	in_variant->type=4;
//ObjectVC->SetPropVal(num_prop,in_variant);
//
//delete in_variant;






////////////////Установим порт ////////////////////////////////////////
if (result==true)
	{
	int num_metod=ObjectVC->FindMethod(L"УстановитьПараметр");   //16
	int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //количество параметров метода   2

	//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda]; for(int i = 0; i < kol_parameter_metoda; i++){InitKasVariant(&in_parameter[i]);}
	TkasVariant * variant_result=new TkasVariant; InitKasVariant(variant_result);

	UnicodeString s="";

	s=L"Port";
	in_parameter[0].string_value=s.c_str(); 	in_parameter[0].type=2; in_parameter[0].len_string=wcslen(in_parameter[0].string_value);

	if (number_port<10) {s="COM"+IntToStr(number_port);}	else { s="\\.\COM"+IntToStr(number_port);}
	in_parameter[1].string_value=s.c_str(); 	in_parameter[1].type=2; in_parameter[1].len_string=wcslen(in_parameter[1].string_value);

	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода установки параметра";
		TextErrorNoConnect="Ошибка при выполнении метода установки параметра";
		result=false;
		}
	//метод выполнен без ошибок
	//возможна ошибка в устройстве

	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //произошла ошибка в устройстве
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		result=false;
		}

	s="";
	delete in_parameter;
	delete variant_result;
	}


////////////////Установим скорость ////////////////////////////////////////
if (result==true)
	{
	int num_metod=ObjectVC->FindMethod(L"УстановитьПараметр");   //16
	int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //количество параметров метода   2

	//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda]; for(int i = 0; i < kol_parameter_metoda; i++){InitKasVariant(&in_parameter[i]);}
	TkasVariant * variant_result=new TkasVariant; InitKasVariant(variant_result);

	in_parameter[0].string_value=L"Speed"; 	in_parameter[0].type=2;in_parameter[0].len_string=wcslen(in_parameter[0].string_value);
	in_parameter[1].int_value=StrToInt(baud_rate); 	in_parameter[1].type=1;

	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода установки параметра";
		TextErrorNoConnect="Ошибка при выполнении метода установки параметра";
		result=false;
		}
	//метод выполнен без ошибок
	//возможна ошибка в устройстве

	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //произошла ошибка в устройстве
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		result=false;
		}

	delete in_parameter;
	delete variant_result;
	}




/////////////////Подключение
if (result==true)
	{
	ConnectFR=true;
	int num_metod=ObjectVC->FindMethod(L"Подключить");
	int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //количество параметров метода

	//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
	for(int i = 0; i < kol_parameter_metoda; i++)
		{
		InitKasVariant(&in_parameter[i]);
		}

	TkasVariant * variant_result=new TkasVariant;
	InitKasVariant(variant_result);

	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода подключения";
		TextErrorNoConnect="Ошибка при выполнении метода подключения";
		result=false;
		}
	//метод выполнен без ошибок
	//возможна ошибка в устройстве
	if (in_parameter->type==2) {IDDevice=in_parameter->string_value;}

	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //произошла ошибка в устройстве
		ConnectFR=false;
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		ConnectFR=false;
		result=false;
		}

	if (in_parameter[0].type==2)
		{
		IDDevice=in_parameter[0].string_value;
		}

	delete in_parameter;
	delete variant_result;

	}





return result;
}
//--------------------------------------------------------------------------

bool  TkasVikiFR::Disconnect(void)
{
bool result=true;


/////////////////Подключение
if (result==true)
	{
	int num_metod=ObjectVC->FindMethod(L"Отключить");
	int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //количество параметров метода

	//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
	for(int i = 0; i < kol_parameter_metoda; i++)
		{
		InitKasVariant(&in_parameter[i]);
		}

	TkasVariant * variant_result=new TkasVariant;
	InitKasVariant(variant_result);

	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода Отключить";
		result=false;
		}
	//метод выполнен без ошибок
	//возможна ошибка в устройстве
	if (in_parameter->type==2) {IDDevice=in_parameter->string_value;}

	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //произошла ошибка в устройстве
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		result=false;
		}

	if (in_parameter[0].type==2)
		{
		IDDevice=in_parameter[0].string_value;
		}

	delete in_parameter;
	delete variant_result;

	}

return result;
}
//---------------------------------------------------------------------------

bool  TkasVikiFR::GetSostKKM(void)
{
bool result=true;



return result;
}
//---------------------------------------------------------------------------
bool  TkasVikiFR::ProvVosmPrintCheck(void)
{
bool result=true;

return result;

}
//----------------------------------------------------------------------------
bool   TkasVikiFR::OpenNoFiscalCheck(void)
{
bool result=true;
kasListDocumentPackage->Clear();
kasListDocumentPackage->Add("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
kasListDocumentPackage->Add("<Document>");
kasListDocumentPackage->Add("<Positions>");
return result;
}
//---------------------------------------------------------------------------
bool   TkasVikiFR::CloseNoFiscalCheck(void)
{
bool result=true;


kasListDocumentPackage->Add("</Positions>");
kasListDocumentPackage->Add("</Document>");


ShowMessage(kasListDocumentPackage->Text);



/////////////////Подключение
if (result==true)
	{
	int num_metod=ObjectVC->FindMethod(L"НапечататьТекстовыйДокумент");
	int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //количество параметров метода

	//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
	for(int i = 0; i < kol_parameter_metoda; i++)
		{
		InitKasVariant(&in_parameter[i]);
		}

	TkasVariant * variant_result=new TkasVariant;
	InitKasVariant(variant_result);

	in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2; in_parameter[0].len_string=wcslen(in_parameter[0].string_value);
	in_parameter[1].string_value=kasListDocumentPackage->GetText(); 	in_parameter[1].type=2; in_parameter[1].len_string=wcslen(in_parameter[1].string_value);



	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода НапечататьТекстовыйДокумент";
		result=false;
		}
	//метод выполнен без ошибок
	//возможна ошибка в устройстве
	if (in_parameter->type==2) {IDDevice=in_parameter->string_value;}

	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //произошла ошибка в устройстве
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		result=false;
		}

	if (in_parameter[0].type==2)
		{
		IDDevice=in_parameter[0].string_value;
		}

	delete in_parameter;
	delete variant_result;

	}


return result;

}
//---------------------------------------------------------------------------
bool  TkasVikiFR::PrintString(UnicodeString str,
												int size_font,       //1234
												int style,           //1-жирный 0 обычный   2 курсив 3 жирный курсив
												int alignment,       //0 лево 1 центр 2 право
												bool ch_lenta,       //на чековой ленте
												bool kontr_lenta,    //на контрольной ленте
												bool word_wrap)
{
bool result=true;

kasListDocumentPackage->Add("<TextString Text=\""+FormatForXML(str)+"\"/>");
//kasListDocumentPackage->Add("<TextString Text=\"Дисконтная карта: 00002345\"/>");
//kasListDocumentPackage->Add("<Barcode BarcodeType=\"QR\" Barcode=\"2000021262157\"/>");

return result;

}
//---------------------------------------------------------------------------
bool  TkasVikiFR::PrintLine(void)
{
bool result=true;

return result;

}
//---------------------------------------------------------------------------


bool  TkasVikiFR::PrintFiscalCheck(double sum,
						int department,
						double oplata_nal,
						double oplata_bank_card,
						double oplata_plat_card,
						double oplata_credit_card,
						int operation)    //0 продажа 1 возврат
{
bool result=false;

	Cash=oplata_nal;
	CashLessType1=oplata_bank_card;
	CashLessType2=oplata_plat_card;
	CashLessType3=oplata_credit_card ;



CreateHeaderFiscalCheck();
kasListCheckPackage->Add(kasListGoodsPackage->Text);
CreateFooterFiscalCheck();


ShowMessage(kasListCheckPackage->Text);

result=PrintFiscalCheckSale(0,
													0,
													0,
														0,
														0,
														0,
														0);





return result;
}
//---------------------------------------------------------------------------
bool  TkasVikiFR::PrintFiscalCheckSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation)    //0 продажа 1 возврат
{
bool result=true;

int num_metod=ObjectVC->FindMethod(L"СформироватьЧек");
int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //количество параметров метода

//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}


UnicodeString s="";

	//ИДУстройства (DeviceID)
	in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2;

	//Кассир (CashierName) STRING [IN] ФИО уполномоченного лица для проведения операции
	s=L"Каликин АН";
	in_parameter[1].string_value=s.c_str(); 	in_parameter[1].type=2; in_parameter[1].len_string=wcslen(in_parameter[1].string_value);
	//Электронно (Electronically) BOOL (IN) Формирование чека в только электроном виде. Печать чека не осуществляется.
	in_parameter[2].bool_value=0; 	in_parameter[2].type=4;
	//ДанныеЧека (CheckPackage) XML таблица  STRING [IN] XML структура - описание чека.
	in_parameter[3].string_value=kasListCheckPackage->GetText(); 	in_parameter[3].type=2; in_parameter[3].len_string=wcslen(in_parameter[3].string_value);
	//НомерЧека (CheckNumber)  LONG [OUT] Номер фискального чека возвращаемый ФН
	//НомерСмены (SessionNumber)  LONG [OUT] Номер открытой смены
	//ФискальныйПризнак (FiscalSign) STRING [OUT] Фискальный признак
	//AddressSiteInspections (АдресСайтаПроверки) STRING [OUT] Адрес сайта проверки



TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
	{
	TextError="Ошибка при выполнении метода печати Х отчета";
	TextErrorNoConnect="Ошибка при выполнении метода печати Х отчета";
	result=false;
	}
//метод выполнен без ошибок
//возможна ошибка в устройстве


	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //произошла ошибка в устройстве
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		result=false;
		}

//ShowMessage(UnicodeString(in_parameter[0].string_value));
delete in_parameter;
delete variant_result;

return result;

}
//---------------------------------------------------------------------------
bool TkasVikiFR::PrintFiscalCheckReturnSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation)    //0 продажа 1 возврат
{
bool result=false;

return result;

}
//---------------------------------------------------------------------------
bool  TkasVikiFR::PrintNoFiscalCheck(double sum,
								int department,
								double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
								int operation)    //0 продажа 1 возврат
{
bool result=false;


return result;

}
//---------------------------------------------------------------------------
bool  TkasVikiFR::PrintXReport(void)
{
bool result=true;
TextError="";
TextErrorNoConnect="";

//int kol_metod=ObjectVC->GetNMethods();
//UnicodeString s="";
//for(int i = 0; i < kol_metod; i++)
//	{
//	int kol_par=ObjectVC->GetNParams(i);
//	s=s+"Метод "+IntToStr(i)+" "+UnicodeString(ObjectVC->GetMethodName(i,1))+" "+IntToStr(kol_par)+"\n";
//	}
//
//ShowMessage(s);



int num_metod=ObjectVC->FindMethod(L"ОтчетОТекущемСостоянииРасчетов");
int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //количество параметров метода

//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}


// 1 входной параметр

in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2;


TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
	{
	TextError="Ошибка при выполнении метода печати Х отчета";
	result=false;
	}
//метод выполнен без ошибок
//возможна ошибка в устройстве


	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //произошла ошибка в устройстве
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		result=false;
		}

//ShowMessage(UnicodeString(in_parameter[0].string_value));
delete in_parameter;
delete variant_result;


return result;

}
//---------------------------------------------------------------------------
bool TkasVikiFR::PrintZReport(void)
{
bool result=false;



return result;

}
//---------------------------------------------------------------------------
bool  TkasVikiFR::PrintPoOtdelamReport(void)
{
bool result=false;

return result;
}
//---------------------------------------------------------------------------

bool  TkasVikiFR::Cut(int TypeCut)
{
bool result=true ;


return result;

}
//---------------------------------------------------------------------------

bool  TkasVikiFR::Vnesenie(double sum)
{
bool result=false;

return result;

}
//---------------------------------------------------------------------------
bool  TkasVikiFR::Snatie(double sum)
{
bool result=false;


return result;

}
//---------------------------------------------------------------------------
//дополнить строку Str слева символами Symbol до Len
UnicodeString TkasVikiFR::DopStrL(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//---------------------------------------------------------------------------
//дополнить строку Str справа символами Symbol до Len
UnicodeString TkasVikiFR::DopStrR(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Str+Symbol;
        }
return Str;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
TTime  TkasVikiFR::GetTime(void)
{
TTime result=0;

return result;

}
//-----------------------------------------------------------------------------
TDate TkasVikiFR::GetDate(void)
{
TDate result=0;

return result;

}
//--------------------------------------------------------------------------
bool  TkasVikiFR::SetTime(TTime time)
{
bool result=false;


return result;
}
//-----------------------------------------------------------------------------
bool  TkasVikiFR::SetDate(TDate date)
{
bool result=false;


return result;
}
//-----------------------------------------------------------------------------
void TkasVikiFR::OpenDrawer(void)
{

}
//-----------------------------------------------------------------------------
int TkasVikiFR::CompareDoubleValue(double v1, double v2, int pogr)
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
void TkasVikiFR::InitKasVariant(TkasVariant * kv)
{
kv->type=0;
kv->int_value=0;
kv->string_value=L"";
kv->dbl_value=0;
kv->bool_value=0;
kv->day=0;
kv->month=0;
kv->year=0;
kv->hour=0;
kv->min=0;
kv->sec=0;
kv->len_string=0;
}
//--------------------------------------------------------------------------
//-----------------------------------------------------------------------------
UnicodeString TkasVikiFR::FormatForXML(UnicodeString str)
{
UnicodeString s=str;
UnicodeString S1=s;
UnicodeString S2="&";
UnicodeString S3="&amp;";

int i0=0,i=S1.Pos(S2);
while(i)
		{
		S1=S1.SubString(1,i+i0-1)+S3+
				S1.SubString(i+i0+S2.Length(),255);
		i0+=i-1+S3.Length();
		i=S1.SubString(i0+1,255).Pos(S2);
		}


S2=">";
S3="&gt;";

i0=0,i=S1.Pos(S2);
while(i)
		{
        S1=S1.SubString(1,i+i0-1)+S3+
                S1.SubString(i+i0+S2.Length(),255);
        i0+=i-1+S3.Length();
		i=S1.SubString(i0+1,255).Pos(S2);
        }

S2="<";
S3="&lt;";

i0=0,i=S1.Pos(S2);
while(i)
        {
        S1=S1.SubString(1,i+i0-1)+S3+
                S1.SubString(i+i0+S2.Length(),255);
        i0+=i-1+S3.Length();
		i=S1.SubString(i0+1,255).Pos(S2);
        }

S2="\"";
S3="&quot;";

i0=0,i=S1.Pos(S2);
while(i)
        {
        S1=S1.SubString(1,i+i0-1)+S3+
                S1.SubString(i+i0+S2.Length(),255);
        i0+=i-1+S3.Length();
		i=S1.SubString(i0+1,255).Pos(S2);
        }

S2="\'";
S3="&apos;";

i0=0,i=S1.Pos(S2);
while(i)
        {
        S1=S1.SubString(1,i+i0-1)+S3+
                S1.SubString(i+i0+S2.Length(),255);
        i0+=i-1+S3.Length();
		i=S1.SubString(i0+1,255).Pos(S2);
        }


return S1;
}
//---------------------------------------------------------------------------
UnicodeString TkasVikiFR::ReplaceCommaToPixel(UnicodeString str)
{
UnicodeString s=str;
UnicodeString S1=s;
UnicodeString S2=",";
UnicodeString S3=".";

int i0=0,i=S1.Pos(S2);
while(i)
		{
		S1=S1.SubString(1,i+i0-1)+S3+
				S1.SubString(i+i0+S2.Length(),255);
		i0+=i-1+S3.Length();
		i=S1.SubString(i0+1,255).Pos(S2);
		}

return S1;
}
//--------------------------------------------------------------------------

		   //!!!!!!!!!!!!!!!IFiskRegOnLine  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
bool TkasVikiFR::OpenShift(void)
{
bool result=true;
TextError="";

//int kol_metod=ObjectVC->GetNMethods();
//UnicodeString s="";
//for(int i = 0; i < kol_metod; i++)
//	{
//	int kol_par=ObjectVC->GetNParams(i);
//	s=s+"Метод "+IntToStr(i)+" "+UnicodeString(ObjectVC->GetMethodName(i,1))+" "+IntToStr(kol_par)+"\n";
//	}
//
//ShowMessage(s);



int num_metod=ObjectVC->FindMethod(L"ОткрытьСмену");
int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //количество параметров метода

//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}


// 1 входной параметр

in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2;


TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
	{
	TextError="Ошибка при выполнении метода Открытия смены";
	result=false;
	}
//метод выполнен без ошибок
//возможна ошибка в устройстве


	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //произошла ошибка в устройстве
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		result=false;
		}

//ShowMessage(UnicodeString(in_parameter[0].string_value));
delete in_parameter;
delete variant_result;


return result;

}
//-----------------------------------------------------------------------------
bool TkasVikiFR::CloseShift(void)
{
bool result=true;
TextError="";

//int kol_metod=ObjectVC->GetNMethods();
//UnicodeString s="";
//for(int i = 0; i < kol_metod; i++)
//	{
//	int kol_par=ObjectVC->GetNParams(i);
//	s=s+"Метод "+IntToStr(i)+" "+UnicodeString(ObjectVC->GetMethodName(i,1))+" "+IntToStr(kol_par)+"\n";
//	}
//
//ShowMessage(s);



int num_metod=ObjectVC->FindMethod(L"ЗакрытьСмену");
int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //количество параметров метода

//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}


// 4 параметра

in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2;


TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
	{
	TextError="Ошибка при выполнении метода печати Закрытия смены";
	result=false;
	}
//метод выполнен без ошибок
//возможна ошибка в устройстве


	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //произошла ошибка в устройстве
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		result=false;
		}

//ShowMessage(UnicodeString(in_parameter[0].string_value));
delete in_parameter;
delete variant_result;


return result;

}
//-----------------------------------------------------------------------------
bool TkasVikiFR::InitCheck(void)
{
bool result=true;

PaymentType=0;
TaxVariant=0;
CustomerEmail="";
CustomerPhone="";
AgentCompensation=0;
AgentPhone="";
SubagentPhone="";
ReceivePaymentsOperatorPhone="";
MoneyTransferOperatorPhone="";
BankAgentPhone="";
BankSubagentPhone="";
BankAgentOperation="";
BankSubagentOperation="";
BankAgentCompensation=0;
MoneyTransferOperatorName="";
MoneyTransferOperatorAddress="";
MoneyTransferOperatorVATIN="";
TypeFiscalString=0;
NameNom="";
Quantity=0;
Price=0;
Amount=0;
Department=0;
Tax=0;
TextString="";
BarcodeType="";
Barcode="";
Cash=0;
CashLessType1=0;
CashLessType2=0;
CashLessType3=0;

kasListDocumentPackage->Clear();
kasListCheckPackage->Clear();
kasListGoodsPackage->Clear();

return result;
}
//-----------------------------------------------------------------------------
bool TkasVikiFR::CreateHeaderFiscalCheck(void)
{
bool result=true;


kasListCheckPackage->Clear();
kasListCheckPackage->Add("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
kasListCheckPackage->Add("<CheckPackage>");

UnicodeString s="";
s=s+"<Parameters ";
s=s+"PaymentType=\""+IntToStr(PaymentType)+"\"";
s=s+"TaxVariant=\""+IntToStr(TaxVariant)+"\"";
if (CustomerEmail!="") {s=s+"CustomerEmail=\""+CustomerEmail+"\"";}
if (CustomerPhone!="") {s=s+"CustomerEmail=\""+CustomerPhone+"\"";}
s=s+" />";

kasListCheckPackage->Add(s);

kasListCheckPackage->Add("<Positions>");



return result;
}
//-----------------------------------------------------------------------------
bool TkasVikiFR::CreateFooterFiscalCheck(void)
{
bool result=true;



kasListCheckPackage->Add("</Positions>");

UnicodeString s="";
s=s+"<Payments ";
s=s+"Cash=\""+ReplaceCommaToPixel(FloatToStrF(Cash,ffFixed,15,2))+"\"";
s=s+"CashLessType1=\""+ReplaceCommaToPixel(FloatToStrF(CashLessType1,ffFixed,15,2))+"\"";
s=s+"CashLessType2=\""+ReplaceCommaToPixel(FloatToStrF(CashLessType2,ffFixed,15,2))+"\"";
s=s+"CashLessType3=\""+ReplaceCommaToPixel(FloatToStrF(CashLessType3,ffFixed,15,2))+"\"";
s=s+" />";
kasListCheckPackage->Add(s);

kasListCheckPackage->Add("</CheckPackage>");




return result;
}
//-----------------------------------------------------------------------------
bool TkasVikiFR::AddFiscalString(void)
{
bool result=true;
UnicodeString s="";
if (TypeFiscalString==1)       //1-фиск строка 2- текстовая строка 3-штрих код
	{
	s="<FiscalString ";
	s=s+"Department=\""+IntToStr(Department)+"\"";
	s=s+"Name=\""+NameNom+"\"";
	s=s+"Quantity=\""+ReplaceCommaToPixel(FloatToStrF(Quantity,ffFixed,15,3))+"\"";
	s=s+"Price=\""+ReplaceCommaToPixel(FloatToStrF(Price,ffFixed,15,2))+"\"";
	s=s+"Amount=\""+ReplaceCommaToPixel(FloatToStrF(Amount,ffFixed,15,2))+"\"";
	s=s+"Tax=\""+ConverIntegerTaxToString(Tax)+"\"";
	s=s+" />";
	}


if (TypeFiscalString==2)       //1-фиск строка 2- текстовая строка 3-штрих код
	{
	s="<TextString ";
	s=s+"Text=\""+TextString+"\"";
	s=s+" />";
	}

if (TypeFiscalString==3)       //1-фиск строка 2- текстовая строка 3-штрих код
	{
	s="<Barcode ";
	s=s+"BarcodeType=\""+BarcodeType+"\"";
	s=s+"Barcode=\""+Barcode+"\"";
	s=s+" />";
	}


kasListGoodsPackage->Add(s);
return result;
}
//-------------------------------------------------------------------------------
UnicodeString TkasVikiFR::ConverIntegerTaxToString(int tax)
{
UnicodeString result="";
				  //	"18" - НДС 18
					  //	"10" - НДС 10
					  //	"0" - НДС 0
					  //	"none" - БЕЗ НДС


						//case 0:    //не задан
						//case 1:    //без ндс
						//case 2:    //0%
						//case 3:    //10%
						//case 4:    //18%

switch (tax)
	{
	case 0:    //не задан
		{
		result="none";
		}break;
	case 1:    //без ндс
		{
		result="none";
		}break;

	case 2:    //0%
		{
		result="0";
		}break;
	case 3:    //10%
		{
		result="10";
		}break;
	case 4:    //18%
		{
		result="18";
		}break;
	}

return result;

}
//-----------------------------------------------------------------------------
