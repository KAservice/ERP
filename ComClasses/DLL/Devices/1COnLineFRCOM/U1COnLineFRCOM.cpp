//---------------------------------------------------------------------------


#pragma hdrstop

#include "U1COnLineFRCOM.h"
#include <math.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)




//-------------------------------------------------------------------
T1COnLineFRCOM::T1COnLineFRCOM()
{
COUNT_IN_PARAMETER = 20;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
UseJournalRibbon=true;
UseReceiptRibbon=true;
OpenNoFiscalDoc=false;

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
kasListXmlDocument = new TStringList;

InParameter=new TkasVariant[COUNT_IN_PARAMETER];
VariantResult=new TkasVariant;

Electronically=false;
flTypeDocument=0;
}
//-----------------------------------------------------------------------------
T1COnLineFRCOM::~T1COnLineFRCOM()
{
delete kasListDocumentPackage;
delete kasListCheckPackage;
delete kasListGoodsPackage;
delete kasListXmlDocument;



for(int i=0;i<COUNT_IN_PARAMETER;i++)
	{
	if (InParameter[i].type == 2)
		{
		delete(&InParameter[i].string_value);
		}
	}

delete InParameter;


delete VariantResult;
//ObjectVC->kanRelease();
}
//---------------------------------------------------------------------------
int T1COnLineFRCOM::Init()
{
if (InterfaceMainObject>0)
	{
	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

InterfaceGlobalCom->kanCreateObject(ProgId_Object1CVnCompCOM,IID_IObject1CVnCompCOM, (void**)&ObjectVC);
UnicodeString m=Modul;
ObjectVC->ProgIdCOMObject=m.c_str();
ObjectVC->InitVC();


return -1;
}
//----------------------------------------------------------------------------
int T1COnLineFRCOM::Done()
{
ObjectVC->DoneVC();
ObjectVC->kanRelease();
return -1;
}

//---------------------------------------------------------------------------
bool T1COnLineFRCOM::GetError(void)
{
bool result=false;

long	num_metod=0;
ObjectVC->FindMethod(L"ПолучитьОшибку", &num_metod);
long	kol_parameter_metoda=0;
ObjectVC->GetNParams(num_metod, &kol_parameter_metoda);    //количество параметров метода 1
bool fl_return_value=0;
ObjectVC->HasRetVal(num_metod, &fl_return_value);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.


	TkasVariant * in_parameter_err=new TkasVariant;
	for(int i = 0; i < kol_parameter_metoda; i++)
		{
		InitKasVariant(&in_parameter_err[i]);
		}
	TkasVariant * variant_result_err=new TkasVariant;
	InitKasVariant(variant_result_err);


if (fl_return_value==true)
	{
	if (ObjectVC->CallAsFunc(num_metod,variant_result_err,  in_parameter_err, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода ПолучитьОшибку";
		result=false;
		}
	}
else
	{
	if (ObjectVC->CallAsProc(num_metod,in_parameter_err, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода ПолучитьОшибку";
		result=false;
		}
	}


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

bool  T1COnLineFRCOM::Connect(int number_port,
				UnicodeString baud_rate,
				UnicodeString password)
{
bool result=true;
TextError="";
TextErrorNoConnect="";


///////////////////Подключение
if (result==true)
	{
	ConnectFR=true;
	long num_metod=0;
	ObjectVC->FindMethod(L"Подключить", &num_metod);
	long kol_parameter_metoda=0;
	ObjectVC->GetNParams(num_metod, &kol_parameter_metoda);    //количество параметров метода

	bool fl_return_value=0;
	ObjectVC->HasRetVal(num_metod, &fl_return_value);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
	for(int i = 0; i < kol_parameter_metoda; i++)
		{
		InitKasVariant(&in_parameter[i]);
		}

	TkasVariant * variant_result=new TkasVariant;
	InitKasVariant(variant_result);

if (fl_return_value==true)
	{
	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода подключения";
		TextErrorNoConnect="Ошибка при выполнении метода подключения";
		result=false;
		}
	}
else
	{
	if (ObjectVC->CallAsProc(num_metod,in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода подключения";
		TextErrorNoConnect="Ошибка при выполнении метода подключения";
		result=false;
		}
	}


//	//метод выполнен без ошибок
//	//возможна ошибка в устройстве

	if (variant_result->type==4 && variant_result->bool_value==false && result==true)
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


if (result==true)
	{
	long num_metod=0;
	ObjectVC->FindMethod(L"ПолучитьШиринуСтроки", &num_metod);
	long kol_parameter_metoda=0;
	ObjectVC->GetNParams(num_metod, &kol_parameter_metoda);    //количество параметров метода

	bool fl_return_value=0;
	ObjectVC->HasRetVal(num_metod, &fl_return_value);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
	for(int i = 0; i < kol_parameter_metoda; i++)
		{
		InitKasVariant(&in_parameter[i]);
		}

	TkasVariant * variant_result=new TkasVariant;
	InitKasVariant(variant_result);

	in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2; in_parameter[0].len_string=wcslen(in_parameter[0].string_value);

if (fl_return_value==true)
	{
	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода подключения";
		TextErrorNoConnect="Ошибка при выполнении метода подключения";
		result=false;
		}
	}
else
	{
	if (ObjectVC->CallAsProc(num_metod,in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода подключения";
		TextErrorNoConnect="Ошибка при выполнении метода подключения";
		result=false;
		}
	}


//	//метод выполнен без ошибок
//	//возможна ошибка в устройстве

	if (variant_result->type==4 && variant_result->bool_value==false && result==true)
		{   //произошла ошибка в устройстве
		ConnectFR=false;
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		ConnectFR=false;
		result=false;
		}

	LineLength=0;

	if (in_parameter[1].type==1)
		{
		LineLength=in_parameter[1].int_value;
		if (LineLength > 0)
			{
			KolSymbolSize1=LineLength;
			KolSymbolSize1Girn=LineLength;
			KolSymbolSize2=LineLength;
			KolSymbolSize2Girn=LineLength;
			KolSymbolSize3=LineLength;
			KolSymbolSize3Girn=LineLength;
			KolSymbolSize4=LineLength;
			KolSymbolSize4Girn=LineLength;
			}
		}

	delete in_parameter;
	delete variant_result;

	}


return result;
}
//--------------------------------------------------------------------------

bool  T1COnLineFRCOM::Disconnect(void)
{
bool result=true;


///////////////////Подключение
if (result==true)
	{
	ConnectFR=true;
	long num_metod=0;
	ObjectVC->FindMethod(L"Отключить", &num_metod);
	long kol_parameter_metoda=0;
	ObjectVC->GetNParams(num_metod, &kol_parameter_metoda);    //количество параметров метода

	bool fl_return_value=0;
	ObjectVC->HasRetVal(num_metod, &fl_return_value);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
	for(int i = 0; i < kol_parameter_metoda; i++)
		{
		InitKasVariant(&in_parameter[i]);
		}

	TkasVariant * variant_result=new TkasVariant;
	InitKasVariant(variant_result);

	in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2; in_parameter[0].len_string=wcslen(in_parameter[0].string_value);

if (fl_return_value==true)
	{
	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода подключения";
		TextErrorNoConnect="Ошибка при выполнении метода подключения";
		result=false;
		}
	}
else
	{
	if (ObjectVC->CallAsProc(num_metod,in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода подключения";
		TextErrorNoConnect="Ошибка при выполнении метода подключения";
		result=false;
		}
	}
//	//метод выполнен без ошибок
//	//возможна ошибка в устройстве

	if (variant_result->type==4 && variant_result->bool_value==false && result==true)
		{   //произошла ошибка в устройстве
		ConnectFR=false;
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		ConnectFR=false;
		result=false;
		}


	delete in_parameter;
	delete variant_result;

	}

return result;
}
//---------------------------------------------------------------------------

bool  T1COnLineFRCOM::GetSostKKM(void)
{
bool result=true;



return result;
}
//---------------------------------------------------------------------------
bool  T1COnLineFRCOM::ProvVosmPrintCheck(void)
{
bool result=true;

return result;

}
//----------------------------------------------------------------------------
bool   T1COnLineFRCOM::OpenNoFiscalCheck(void)
{
bool result=true;

		switch (flTypeDocument)
				{
				case  1:                           //нефискальный чек
						{
						kasListDocumentPackage->Clear();
						kasListDocumentPackage->Add("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
						kasListDocumentPackage->Add("<Document>");
						kasListDocumentPackage->Add("<Positions>");
						break;
						}
				case  2:                           //фискальный чек    например хотим напечатать заголовок фискального чека
						{
						kasListDocumentPackage->Clear();
						break;
						}


				}

return result;
}
//---------------------------------------------------------------------------
bool   T1COnLineFRCOM::CloseNoFiscalCheck(void)
{
bool result=true;


if(flTypeDocument==2) //фискальный чек    например хотим напечатать заголовок фискального чека
	{
	return result;
	}

kasListDocumentPackage->Add("</Positions>");
kasListDocumentPackage->Add("</Document>");


//ShowMessage(kasListDocumentPackage->Text);

if (kasListDocumentPackage->Count <= 5)
	{
	return result;
	}

///////////////////Подключение
if (result==true)
	{
	long num_metod=0;
	ObjectVC->FindMethod(L"НапечататьТекстовыйДокумент", &num_metod);
	long kol_parameter_metoda=0;
	ObjectVC->GetNParams(num_metod, &kol_parameter_metoda);    //количество параметров метода

	bool fl_return_value=0;
	ObjectVC->HasRetVal(num_metod, &fl_return_value);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
	for(int i = 0; i < kol_parameter_metoda; i++)
		{
		InitKasVariant(&in_parameter[i]);
		}

	TkasVariant * variant_result=new TkasVariant;
	InitKasVariant(variant_result);

	in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2; in_parameter[0].len_string=wcslen(in_parameter[0].string_value);
	in_parameter[1].string_value=kasListDocumentPackage->GetText(); 	in_parameter[1].type=2; in_parameter[1].len_string=wcslen(in_parameter[1].string_value);



if (fl_return_value==true)
	{
	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="НапечататьТекстовыйДокумент";
		//result=false;
		}
	}
else
	{
	if (ObjectVC->CallAsProc(num_metod,in_parameter, kol_parameter_metoda)==false)
		{
		TextError="НапечататьТекстовыйДокумент";
		//result=false;
		}
	}
//	//метод выполнен без ошибок
//	//возможна ошибка в устройстве
	if (in_parameter->type==2) {IDDevice=in_parameter->string_value;}

	if (variant_result->type==4 && variant_result->bool_value==false  && result==true)
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
bool  T1COnLineFRCOM::PrintString(UnicodeString str,
												int size_font,       //1234
												int style,           //1-жирный 0 обычный   2 курсив 3 жирный курсив
												int alignment,       //0 лево 1 центр 2 право
												bool ch_lenta,       //на чековой ленте
												bool kontr_lenta,    //на контрольной ленте
												bool word_wrap)
{
bool result=true;



if (Trim(str) == "") str=" ";          //иначе при печати пустых строчек ошибка
UnicodeString s=str;

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
		UnicodeString print_str=strings->Strings[i];
		if (PrintString(print_str,size_font,style,alignment,ch_lenta,kontr_lenta, false)==true)
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
						if(s.Length()>KolSymbolSize1) s=s.SetLength(KolSymbolSize1);
                        switch ( alignment)
                                {
								case  0:      //лево
                                        {

                                        break;
                                        }
								case  1:    //центр
                                        {
										if (s.Length()>=KolSymbolSize1)
                                                {

												}
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize1-((KolSymbolSize1-s.Length())/2));

												}

                                        break;
                                        }
                                case  2:   //право
										{
										if (s.Length()>=KolSymbolSize1)
                                                {

                                                }
										else
                                                {
												s=DopStrL(s, " ", KolSymbolSize1);

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

                                                }
										else
                                                {

                                                }
                                        break;
										}
                                case  1:    //центр
                                        {
										if (s.Length()>=KolSymbolSize2)
                                                {

                                                }
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize2-((KolSymbolSize2-s.Length())/2));

                                                }

                                        break;
                                        }
								case  2:   //право
                                        {
										if (s.Length()>=KolSymbolSize2)
                                                {

												}
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize2);

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

                                                }
										else
                                                {

                                                }
                                        break;
										}
                                case  1:    //центр
                                        {
										if (s.Length()>=KolSymbolSize3)
                                                {

												}
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize3-((KolSymbolSize3-s.Length())/2));

                                                }

                                        break;
                                        }
								case  2:   //право
                                        {
										if (s.Length()>=KolSymbolSize3)
                                                {

												}
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize3);

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

												}
                                        else
                                                {

                                                }
										break;
                                        }
                                case  1:    //центр
                                        {
										if (s.Length()>=KolSymbolSize4)
												{

                                                }
                                        else
												{
												s=DopStrL(s, " ", KolSymbolSize4-((KolSymbolSize4-s.Length())/2));

                                                }

                                        break;
										}
                                case  2:   //право
                                        {
										if (s.Length()>=KolSymbolSize4)
                                                {

                                                }
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize4);

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





		switch (flTypeDocument)
				{
				case  1:                           //нефискальный чек
						{
						kasListDocumentPackage->Add("<TextString Text=\""+FormatForXML(s)+"\"/>");
						break;
						}
				case  2:                           //фискальный чек    например хотим напечатать заголовок фискального чека
						{
						TextString=s;
						TypeFiscalString=2;
						AddFiscalString();
						break;
						}


				}

return result;

}
//---------------------------------------------------------------------------
bool  T1COnLineFRCOM::PrintLine(void)
{
bool result=true;

UnicodeString s="-";
s=DopStrL(s, "-", KolSymbolSize1);


try
	{
	result=PrintString(s,
												1,       //1234
												0,           //1-жирный 0 обычный   2 курсив 3 жирный курсив
												0,       //0 лево 1 центр 2 право
												1,       //на чековой ленте
												0,    //на контрольной ленте
												0);
	}
catch (Exception &E)
		{
		TextError=E.Message;
		result=false;
		}

return result;

}
//---------------------------------------------------------------------------


bool  T1COnLineFRCOM::PrintFiscalCheck(double sum,
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

if (operation==0)//продажа
	{
	PaymentType=1;
	}

if (operation==1)//возврат продажи
	{
	PaymentType=2;
	}

CreateHeaderFiscalCheck();
kasListCheckPackage->Add(Trim(kasListGoodsPackage->Text));
CreateFooterFiscalCheck();


ShowMessage(kasListCheckPackage->Text);

result=PrintFiscalCheckSale(sum,
													department,
													oplata_nal,
														oplata_bank_card,
														oplata_plat_card,
														oplata_credit_card,
														0);





return result;
}
//---------------------------------------------------------------------------
bool  T1COnLineFRCOM::PrintFiscalCheckSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation)    //0 продажа 1 возврат
{
bool result=true;

long num_metod=0;
ObjectVC->FindMethod(L"СформироватьЧек", &num_metod);
long kol_parameter_metoda=0;
ObjectVC->GetNParams(num_metod, &kol_parameter_metoda);    //количество параметров метода

bool fl_return_value=0;
ObjectVC->HasRetVal(num_metod, &fl_return_value);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}


UnicodeString s="";

//	//ИДУстройства (DeviceID)
	in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2;in_parameter[0].len_string=wcslen(in_parameter[0].string_value);
//
//	//Кассир (CashierName) STRING [IN] ФИО уполномоченного лица для проведения операции
	s=CashierName;
	in_parameter[1].string_value=s.c_str(); 	in_parameter[1].type=2; in_parameter[1].len_string=wcslen(in_parameter[1].string_value);
//	//Электронно (Electronically) BOOL (IN) Формирование чека в только электроном виде. Печать чека не осуществляется.
	in_parameter[2].bool_value=Electronically; 	in_parameter[2].type=4;
//	//ДанныеЧека (CheckPackage) XML таблица  STRING [IN] XML структура - описание чека.
	in_parameter[3].string_value=kasListCheckPackage->GetText(); 	in_parameter[3].type=2; in_parameter[3].len_string=wcslen(in_parameter[3].string_value);

TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

if (fl_return_value==true)
	{
	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода СформироватьЧек";
		TextErrorNoConnect="Ошибка при выполнении метода СформироватьЧек";
		result=false;
		}
	}
else
	{
	if (ObjectVC->CallAsProc(num_metod,in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода СформироватьЧек";
		TextErrorNoConnect="Ошибка при выполнении метода СформироватьЧек";
		result=false;
		}
	}
////метод выполнен без ошибок
////возможна ошибка в устройстве
//
//
if (variant_result->type==4 && variant_result->bool_value==false)
		{   //произошла ошибка в устройстве
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		result=false;
		}
//
//	//НомерЧека (CheckNumber)  LONG [OUT] Номер фискального чека возвращаемый ФН
	if (in_parameter[4].type==1)  {NumberCheck=in_parameter[4].int_value;}
//	//НомерСмены (SessionNumber)  LONG [OUT] Номер открытой смены
	if (in_parameter[5].type==1)  {NumberKL=in_parameter[5].int_value;}
//	//ФискальныйПризнак (FiscalSign) STRING [OUT] Фискальный признак
	if (in_parameter[6].type==2)  {FiscalSign=in_parameter[6].string_value;}
//	//AddressSiteInspections (АдресСайтаПроверки) STRING [OUT] Адрес сайта проверки
	if (in_parameter[7].type==2)  {AddressSiteInspections=in_parameter[7].string_value;}


delete in_parameter;
delete variant_result;

return result;

}
//---------------------------------------------------------------------------
bool T1COnLineFRCOM::PrintFiscalCheckReturnSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation)    //0 продажа 1 возврат
{ //не надо этой функции, печть все равно через печать чека продажи
bool result=false;

return result;

}
//---------------------------------------------------------------------------
bool  T1COnLineFRCOM::PrintNoFiscalCheck(double sum,
								int department,
								double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
								int operation)    //0 продажа 1 возврат
{
bool result=false;


OpenNoFiscalCheck();
PrintString("Нефискальный чек напечатан",
								1,       //1234
								0,            //1-жирный 0 обычный
								0,      //0 лево 1 центр 2 право
								1,       //на чековой ленте
								0,   //на контрольной ленте
								0);

CloseNoFiscalCheck();

return result;

}
//---------------------------------------------------------------------------
bool  T1COnLineFRCOM::PrintXReport(void)
{
bool result=true;
TextError="";

///////////////////Подключение
if (result==true)
	{
	ConnectFR=true;
	long num_metod=0;
	ObjectVC->FindMethod(L"ОтчетОТекущемСостоянииРасчетов", &num_metod);
	long kol_parameter_metoda=0;
	ObjectVC->GetNParams(num_metod, &kol_parameter_metoda);    //количество параметров метода

	bool fl_return_value=0;
	ObjectVC->HasRetVal(num_metod, &fl_return_value);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
	for(int i = 0; i < kol_parameter_metoda; i++)
		{
		InitKasVariant(&in_parameter[i]);
		}

	TkasVariant * variant_result=new TkasVariant;
	InitKasVariant(variant_result);

	//	//ИДУстройства (DeviceID)
	in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2;in_parameter[0].len_string=wcslen(in_parameter[0].string_value);

if (fl_return_value==true)
	{
	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода НапечататьОтчетБезГашения";
		result=false;
		}
	}
else
	{
	if (ObjectVC->CallAsProc(num_metod,in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода НапечататьОтчетБезГашения";
		result=false;
		}
	}


//	//метод выполнен без ошибок
//	//возможна ошибка в устройстве

	if (variant_result->type==4 && variant_result->bool_value==false && result==true)
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


return result;

}
//---------------------------------------------------------------------------
bool T1COnLineFRCOM::PrintZReport(void)
{
bool result=false;



return result;

}
//---------------------------------------------------------------------------
bool  T1COnLineFRCOM::PrintPoOtdelamReport(void)
{
bool result=false;

return result;
}
//---------------------------------------------------------------------------

bool  T1COnLineFRCOM::Cut(int TypeCut)
{
bool result=true ;


return result;

}
//---------------------------------------------------------------------------

bool  T1COnLineFRCOM::Vnesenie(double sum)
{
bool result=false;

return result;

}
//---------------------------------------------------------------------------
bool  T1COnLineFRCOM::Snatie(double sum)
{
bool result=false;


return result;

}
//---------------------------------------------------------------------------
//дополнить строку Str слева символами Symbol до Len
UnicodeString T1COnLineFRCOM::DopStrL(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//---------------------------------------------------------------------------
//дополнить строку Str справа символами Symbol до Len
UnicodeString T1COnLineFRCOM::DopStrR(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Str+Symbol;
        }
return Str;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
TTime  T1COnLineFRCOM::GetTime(void)
{
TTime result=0;

return result;

}
//-----------------------------------------------------------------------------
TDate T1COnLineFRCOM::GetDate(void)
{
TDate result=0;

return result;

}
//--------------------------------------------------------------------------
bool  T1COnLineFRCOM::SetTime(TTime time)
{
bool result=false;


return result;
}
//-----------------------------------------------------------------------------
bool  T1COnLineFRCOM::SetDate(TDate date)
{
bool result=false;


return result;
}
//-----------------------------------------------------------------------------
void T1COnLineFRCOM::OpenDrawer(void)
{

}
//-----------------------------------------------------------------------------
int T1COnLineFRCOM::CompareDoubleValue(double v1, double v2, int pogr)
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
void T1COnLineFRCOM::InitKasVariant(TkasVariant * kv)
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
UnicodeString T1COnLineFRCOM::FormatForXML(UnicodeString str)
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
UnicodeString T1COnLineFRCOM::ReplaceCommaToPixel(UnicodeString str)
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
bool T1COnLineFRCOM::OpenShift(void)
{
bool result=true;
TextError="";



long num_metod=0;
ObjectVC->FindMethod(L"ОткрытьСмену", &num_metod);
long kol_parameter_metoda=0;
ObjectVC->GetNParams(num_metod, &kol_parameter_metoda);    //количество параметров метода

bool fl_return_value=false;
ObjectVC->HasRetVal(num_metod, &fl_return_value);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}


//// 1 входной параметр

in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2;in_parameter[0].len_string=wcslen(in_parameter[0].string_value);


TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

if (fl_return_value==true)
	{
	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода ОткрытьСмену";
		//result=false;
		}
	}
else
	{
	if (ObjectVC->CallAsProc(num_metod,in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода ОткрытьСмену";
		//result=false;
		}
	}

////метод выполнен без ошибок
////возможна ошибка в устройстве

	if (variant_result->type==4 && variant_result->bool_value==false && result==true)
		{   //произошла ошибка в устройстве
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		result=false;
		}

delete in_parameter;
delete variant_result;


return result;

}
//-----------------------------------------------------------------------------
bool T1COnLineFRCOM::CloseShift(void)
{
bool result=true;
TextError="";



long num_metod=0;
ObjectVC->FindMethod(L"ЗакрытьСмену", &num_metod);
long kol_parameter_metoda=0;
ObjectVC->GetNParams(num_metod, &kol_parameter_metoda);    //количество параметров метода

bool fl_return_value=false;
ObjectVC->HasRetVal(num_metod, &fl_return_value);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}


//// 1 входной параметр

in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2;in_parameter[0].len_string=wcslen(in_parameter[0].string_value);


TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

if (fl_return_value==true)
	{
	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода ЗакрытьСмену";
		//result=false;
		}
	}
else
	{
	if (ObjectVC->CallAsProc(num_metod,in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода ЗакрытьСмену";
		//result=false;
		}
	}

////метод выполнен без ошибок
////возможна ошибка в устройстве

	if (variant_result->type==4 && variant_result->bool_value==false && result==true)
		{   //произошла ошибка в устройстве
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		result=false;
		}

delete in_parameter;
delete variant_result;


return result;

}
//-----------------------------------------------------------------------------
bool T1COnLineFRCOM::InitDocument(int type_doc)
{
bool result=true;

flTypeDocument=type_doc;

PaymentType=0;
//*******************************************************
TaxVariant=0;        //!!!!!!!!!!!!!!!!!!!!!! ОБЯЗЯТЕЛЬНО ИСПРАВИТЬ!!!!!!!!!!!!!!!!!!!!!! ОБЯЗАТЕЛЬНЫЙ ПАРАМЕТР ЧЕКА
//*******************************************************
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
kasListXmlDocument->Clear();

for(int i = 0; i < 20; i++)
	{
	InitKasVariant(&InParameter[i]);
	}


InitKasVariant(VariantResult);

return result;
}
//-----------------------------------------------------------------------------
bool T1COnLineFRCOM::CreateHeaderFiscalCheck(void)
{
bool result=true;


kasListCheckPackage->Clear();
kasListCheckPackage->Add("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
kasListCheckPackage->Add("<CheckPackage>");

UnicodeString s="";
s=s+"<Parameters ";
s=s+" PaymentType=\""+IntToStr(PaymentType)+"\"";
s=s+" TaxVariant=\""+IntToStr(TaxVariant)+"\"";
if (CustomerEmail!="") {s=s+" CustomerEmail=\""+CustomerEmail+"\"";}
if (CustomerPhone!="") {s=s+" CustomerPhone=\""+CustomerPhone+"\"";}
s=s+" />";

kasListCheckPackage->Add(Trim(s));

kasListCheckPackage->Add("<Positions>");


//ShowMessage(kasListCheckPackage->Text);

return result;
}
//-----------------------------------------------------------------------------
bool T1COnLineFRCOM::CreateFooterFiscalCheck(void)
{
bool result=true;



kasListCheckPackage->Add("</Positions>");

UnicodeString s="";
s=s+"<Payments ";
s=s+" Cash=\""+ReplaceCommaToPixel(FloatToStrF(Cash,ffFixed,15,2))+"\"";
s=s+" CashLessType1=\""+ReplaceCommaToPixel(FloatToStrF(CashLessType1,ffFixed,15,2))+"\"";
s=s+" CashLessType2=\""+ReplaceCommaToPixel(FloatToStrF(CashLessType2,ffFixed,15,2))+"\"";
s=s+" CashLessType3=\""+ReplaceCommaToPixel(FloatToStrF(CashLessType3,ffFixed,15,2))+"\"";
s=s+" />";
kasListCheckPackage->Add(Trim(s));

kasListCheckPackage->Add("</CheckPackage>");


//ShowMessage(kasListCheckPackage->Text);

return result;
}
//-----------------------------------------------------------------------------
bool T1COnLineFRCOM::AddFiscalString(void)
{
bool result=true;
UnicodeString s="";

if (flTypeDocument==2)
	{
	if (TypeFiscalString==1)       //1-фиск строка 2- текстовая строка 3-штрих код
		{
		s="<FiscalString ";
		if (Department==0) {Department=1;}
		s=s+" Department=\""+IntToStr(Department)+"\"";
		s=s+" Name=\""+FormatForXML(NameNom)+"\"";
		s=s+" Quantity=\""+ReplaceCommaToPixel(FloatToStrF(Quantity,ffFixed,15,3))+"\"";
		s=s+" Price=\""+ReplaceCommaToPixel(FloatToStrF(Price,ffFixed,15,2))+"\"";
		s=s+" Amount=\""+ReplaceCommaToPixel(FloatToStrF(Amount,ffFixed,15,2))+"\"";
		s=s+" Tax=\""+ConverIntegerTaxToString(Tax)+"\"";
		s=s+" />";
		}


	if (TypeFiscalString==2)       //1-фиск строка 2- текстовая строка 3-штрих код
		{
		s="<TextString ";
		s=s+" Text=\""+FormatForXML(TextString)+"\"";
		s=s+" />";
		}

	if (TypeFiscalString==3)       //1-фиск строка 2- текстовая строка 3-штрих код
		{
		s="<Barcode ";
		s=s+" BarcodeType=\""+BarcodeType+"\"";
		s=s+" Barcode=\""+Barcode+"\"";
		s=s+" />";
		}

    kasListGoodsPackage->Add(Trim(s));
	}


if (flTypeDocument==1)
	{
		s=s+IntToStr(Department);
		s=s+" "+NameNom;
		s=s+" "+ReplaceCommaToPixel(FloatToStrF(Quantity,ffFixed,15,3));
		s=s+" "+ReplaceCommaToPixel(FloatToStrF(Price,ffFixed,15,2));
		s=s+" "+ReplaceCommaToPixel(FloatToStrF(Amount,ffFixed,15,2));
		s=s+" "+ConverIntegerTaxToString(Tax);

		PrintString(s,
								1,       //1234
								0,            //1-жирный 0 обычный
								0,      //0 лево 1 центр 2 право
								1,       //на чековой ленте
								0,   //на контрольной ленте
								true);

	}




//ShowMessage(kasListGoodsPackage->Text);
return result;
}
//-------------------------------------------------------------------------------
UnicodeString T1COnLineFRCOM::ConverIntegerTaxToString(int tax)
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
UnicodeString T1COnLineFRCOM::GetParameters(void)
{
UnicodeString result="";
TextError="";


//
//long kol_metod=0;
//ObjectVC->GetNMethods(&kol_metod);
//
//TStringList *l=new TStringList();
//
//for (long i=0; i<kol_metod;i++)
//	{
//	wchar_t * name_metod=L"";
//	ObjectVC->GetMethodName(i,1,name_metod);
//
//	 l->Add(UnicodeString( name_metod));
//	}
//
//
//
//
//ShowMessage(l->Text);
//
//delete l;


long num_metod=0;
ObjectVC->FindMethod(L"ПолучитьПараметры",&num_metod);
long kol_parameter_metoda=0;
ObjectVC->GetNParams(num_metod, &kol_parameter_metoda);    //количество параметров метода

bool fl_return_value=0;
ObjectVC->HasRetVal(num_metod, &fl_return_value);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}

TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

if (fl_return_value==true)
	{
	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода ПолучитьПараметры";
		//result=false;
		}
	}
else
	{
	if (ObjectVC->CallAsProc(num_metod,in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода ПолучитьПараметры";
		//result=false;
		}
	}




////метод выполнен без ошибок
////возможна ошибка в устройстве


	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //произошла ошибка в устройстве
		//result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		//result=false;
		}

		if (in_parameter[0].type==2)
			{
			result=UnicodeString(in_parameter[0].string_value);
			delete [] in_parameter[0].string_value;
			}

////ShowMessage(UnicodeString(in_parameter[0].string_value));

delete in_parameter;
delete variant_result;


return result;
}
//-------------------------------------------------------------------------
bool T1COnLineFRCOM::SetParameter(UnicodeString name_parameter, UnicodeString value_parameter)
{
bool result=true;


return result;
}
//--------------------------------------------------------------------------
UnicodeString T1COnLineFRCOM::GetAdditionalActions(void)
{
UnicodeString result="";
TextError="";

//int num_metod=ObjectVC->FindMethod(L"ПолучитьДополнительныеДействия");
//int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //количество параметров метода
//
////bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.
//
//TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
//for(int i = 0; i < kol_parameter_metoda; i++)
//	{
//	InitKasVariant(&in_parameter[i]);
//	}
//
//TkasVariant * variant_result=new TkasVariant;
//InitKasVariant(variant_result);
//
//if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
//	{
//	TextError="Ошибка при выполнении метода печати Закрытия смены";
//	//result=false;
//	}
////метод выполнен без ошибок
////возможна ошибка в устройстве
//
//
//	if (variant_result->type==4 && variant_result->bool_value==false)
//		{   //произошла ошибка в устройстве
//		//result=false;
//		}
//
//	 if (GetError()==true)   //есть ошибка
//		{
//		//result=false;
//		}
//
//		if (in_parameter[0].type==2)
//			{
//			result=UnicodeString(in_parameter[0].string_value);
//			}
//
////ShowMessage(UnicodeString(in_parameter[0].string_value));
//delete in_parameter;
//delete variant_result;


return result;
}
//-------------------------------------------------------------------------
bool T1COnLineFRCOM::DoAdditionalAction(UnicodeString name_action)
{
bool result=true;


return result;
}
//-----------------------------------------------------------------------
UnicodeString T1COnLineFRCOM::GetMetodsList(void)
{
UnicodeString result="";

long kol_metod=0;
ObjectVC->GetNMethods(&kol_metod);

TStringList *l=new TStringList();
l->Clear() ;

for (long i=0; i<kol_metod;i++)
	{
	wchar_t * name_metod=L"";
	ObjectVC->GetMethodName(i,1,name_metod);
	int number_metod=i;
	l->Add(IntToStr(number_metod)+" "+UnicodeString( name_metod));
	delete name_metod;
	}

for (long i=0; i<kol_metod;i++)
	{
	wchar_t * name_metod=L"";
	ObjectVC->GetMethodName(i,0,name_metod);
	int number_metod=i;
	l->Add(IntToStr(number_metod)+" "+UnicodeString( name_metod));
	delete name_metod;
	}

result=l->Text;
delete l;
return result;
}
//------------------------------------------------------------------------

bool T1COnLineFRCOM::GetParameter(UnicodeString name_parameter, TkasVariant * value_parameter)
{
bool result=true;



return result;
}
//-----------------------------------------------------------------------
bool T1COnLineFRCOM::SetParameter(UnicodeString name_parameter, TkasVariant * value_parameter)
{
bool result=true;




	long num_metod=0;
	ObjectVC->FindMethod(L"УстановитьПараметр", &num_metod);   //16
	long kol_parameter_metoda=0;
	ObjectVC->GetNParams(num_metod, &kol_parameter_metoda);    //количество параметров метода   2

	bool fl_return_value=0;
	ObjectVC->HasRetVal(num_metod, &fl_return_value);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
	for(int i = 0; i < kol_parameter_metoda; i++)
		{InitKasVariant(&in_parameter[i]);}

	TkasVariant * variant_result=new TkasVariant;
	InitKasVariant(variant_result);

	in_parameter[0].string_value=name_parameter.c_str(); 	in_parameter[0].type=2; in_parameter[0].len_string=wcslen(in_parameter[0].string_value);
	in_parameter[1]=*value_parameter;

	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода установки параметра";
		//TextErrorNoConnect="Ошибка при выполнении метода установки параметра";
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

return result;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------
//******************************************************************
//*******************************************************************
//--------------------------------------------------------------------
//---------------------------------------------------------------
//******************************************************************
//*******************************************************************
//--------------------------------------------------------------------
bool T1COnLineFRCOM::RunCommand(UnicodeString command_name, UnicodeString xml_doc, int type_doc)
					//если type = 0 то не используем xml_doc, а используем сформированный построчно файл
{
bool result=true;

//ShowMessage(kasListXmlDocument->Text);

long num_metod=0;
ObjectVC->FindMethod(command_name.c_str(), &num_metod);
long kol_parameter_metoda=0;
ObjectVC->GetNParams(num_metod, &kol_parameter_metoda);    //количество параметров метода

bool fl_return_value=0;
ObjectVC->HasRetVal(num_metod, &fl_return_value);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.


TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}


UnicodeString s="";

	for(int i=0;i<kol_parameter_metoda;i++)
		{
		 in_parameter[i] = InParameter[i];
		}


TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

		UnicodeString V="Выполняем функцию: "+command_name+"\n";
	//	V=V+xml_doc+"\n";
	//	V=V+kasListXmlDocument->Text+"\n";
		V=V+"Количество параметров: "+IntToStr((int)kol_parameter_metoda)+"\n";

		UnicodeString par="";
		for(int i=0; i < COUNT_IN_PARAMETER; i++)
		{
		 par=par+" №"+IntToStr(i)+" значение: " + kasVariantToStr(&InParameter[i]) + "\n";
		}
        V=V+par;


		UnicodeString Z="Выполнить?";
		if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
				{

                }
        else
				{
				result = false;
				delete in_parameter;
				delete variant_result;
				return result;
				}



if (fl_return_value==true)
	{
	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода: "+command_name;
		TextErrorNoConnect="Ошибка при выполнении метода: "+command_name;
		result=false;
		}
	}
else
	{
	if (ObjectVC->CallAsProc(num_metod,in_parameter, kol_parameter_metoda)==false)
		{
		TextError="Ошибка при выполнении метода : "+command_name;
		TextErrorNoConnect="Ошибка при выполнении метода: "+command_name;
		result=false;
		}
	}


VariantResult = variant_result;
////метод выполнен без ошибок
////возможна ошибка в устройстве
//
//
if (variant_result->type==4 && variant_result->bool_value==false)
		{   //произошла ошибка в устройстве
		result=false;
		}

	 if (GetError()==true)   //есть ошибка
		{
		result=false;
		}
//



delete in_parameter;
delete variant_result;



return result;

}
//------------------------------------------------------------------
UnicodeString T1COnLineFRCOM::ReturnXmlResultLastMethod(void)
{
UnicodeString result="";


return result;
}
//----------------------------------------------------------------------

bool T1COnLineFRCOM::SetStringParameter(UnicodeString param_name, int number, UnicodeString value)
{
bool result=true;

int length = wcslen(value.c_str());
wchar_t * wchar_t_for_kas_variant = new wchar_t[length + 1];
wcscpy(wchar_t_for_kas_variant,value.c_str());

InParameter[number].string_value=wchar_t_for_kas_variant; InParameter[number].type=2;InParameter[number].len_string=wcslen(InParameter[number].string_value);

return result;
}
//------------------------------------------------------------------
UnicodeString T1COnLineFRCOM::GetStringParameter(UnicodeString param_name, int number)
{
UnicodeString result="";


	if (InParameter[number].type==2)  {result=InParameter[number].string_value;}


return result;


}
//-----------------------------------------------------------------------

bool T1COnLineFRCOM::SetIntegerParameter(UnicodeString param_name, int number, int value)
{
bool result=true;


	InParameter[number].int_value=value; InParameter[number].type=1;

return result;

}
//------------------------------------------------------------------
int T1COnLineFRCOM::GetIntegerParameter(UnicodeString param_name, int number)
{

int result=0;


	if (InParameter[number].type==1)  {result=InParameter[number].int_value;}


return result;

}
//-----------------------------------------------------------------------

bool T1COnLineFRCOM::SetDoubleParameter(UnicodeString param_name, int number, double value)
{
bool result=true;


	InParameter[number].dbl_value=value; InParameter[number].type=3;

return result;

}
//------------------------------------------------------------------
double T1COnLineFRCOM::GetDoubleParameter(UnicodeString param_name, int number)
{

double result=true;
if (InParameter[number].type==3)  {result=InParameter[number].dbl_value;}

return result;

}
//-----------------------------------------------------------------------

bool T1COnLineFRCOM::SetBooleanParameter(UnicodeString param_name, int number, bool value)
{

bool result=true;
	InParameter[number].bool_value=value; InParameter[number].type=4;

return result;
}
//------------------------------------------------------------------
bool T1COnLineFRCOM::GetBooleanParameter(UnicodeString param_name, int number)
{

bool result=true;
 if (InParameter[number].type==4)  {result=InParameter[number].bool_value;}

return result;
}
//-----------------------------------------------------------------------

bool T1COnLineFRCOM::SetDateTimeParameter(UnicodeString param_name, int number, TDateTime value)
{

bool result=true;


return result;
}
//------------------------------------------------------------------
TDateTime T1COnLineFRCOM::GetDateTimeParameter(UnicodeString param_name, int number)
{


TDateTime result=0;


return result;
}
//-----------------------------------------------------------------------
bool T1COnLineFRCOM::SetXmlParameter(UnicodeString param_name, int number, UnicodeString xml_value, int type_source_xml)
{
bool result=true;

if (type_source_xml == 1)
	{
	InParameter[number].string_value=xml_value.c_str(); InParameter[number].type=2;InParameter[number].len_string=wcslen(InParameter[number].string_value);
	}

if (type_source_xml == 2)
	{
	InParameter[number].string_value=kasListXmlDocument->GetText(); InParameter[number].type=2;InParameter[number].len_string=wcslen(InParameter[number].string_value);
	}

//ShowMessage(InParameter[number].string_value);

return result;
}
//--------------------------------------------------------------------------
UnicodeString T1COnLineFRCOM::GetXmlParameter(UnicodeString param_name, int number, int type_source_xml)
{
UnicodeString result="";



return result;

}
//--------------------------------------------------------------------------
bool T1COnLineFRCOM::SetIdDeviceParameter(UnicodeString param_name, int number, UnicodeString id_device, int type_source_id_device)
{
bool result=true;

if (type_source_id_device == 1)
	{
	InParameter[number].string_value=id_device.c_str(); InParameter[number].type=2;InParameter[number].len_string=wcslen(InParameter[number].string_value);
	}

if (type_source_id_device == 2)
	{
	InParameter[number].string_value=IDDevice.c_str(); InParameter[number].type=2;InParameter[number].len_string=wcslen(InParameter[number].string_value);
	}

return result;
}
//--------------------------------------------------------------------------
UnicodeString T1COnLineFRCOM::GetIDDeviceParameter(UnicodeString param_name, int number, int type_source_id_device)
{
UnicodeString result="";



return result;
}
//--------------------------------------------------------------------------
	//формирование xml файла
void T1COnLineFRCOM::AddStringXml(UnicodeString str_xml)    //просто готовая строка
{
kasListXmlDocument->Add(str_xml);
}
//-------------------------------------------------------------------------
void T1COnLineFRCOM::AddAttribyteXml(UnicodeString attribyte, UnicodeString value, int type_value) //0, 1 дробный, 2 строка //тип для форматирования, например для удаления запятых в числах

{
UnicodeString s = "";

		s=" "+attribyte+"=\"";

		if (type_value == 0)
			{
			s = s + value+"\"" ;

			}

		if (type_value == 1)   //дробный
			{
			s = s + FormatForXML(ReplaceCommaToPixel(value))+"\"" ;

			}
		if (type_value == 2)   //строка
			{
			s = s + FormatForXML(value)+"\"" ;

			}


kasListXmlDocument->Add(s);
}
//------------------------------------------------------------------------------
void T1COnLineFRCOM::AddElementXml(UnicodeString element, UnicodeString value, int type_value)
{

}
//----------------------------------------------------------------------------

void T1COnLineFRCOM::AddStringForPrintXml(UnicodeString element, UnicodeString attribyte, UnicodeString value,
								int size_font,  //1234
								int style,    //1-жирный 0 обычный   2 курсив 3 жирный курсив
								int alignment,  //0 лево 1 центр 2 право
								bool word_wrap)   //строка xml для печати будет формироваться
{
//bool result=true;



if (Trim(value) == "") value=" ";          //иначе при печати пустых строчек ошибка
UnicodeString s=value;

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
		UnicodeString print_str=strings->Strings[i];
		AddStringForPrintXml(element, attribyte, print_str,
								size_font,
								style,
								alignment,
								false);

		}
	delete strings;
	return;

	}

// ***************************************************************************

try
	{


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

                                        break;
                                        }
								case  1:    //центр
                                        {
										if (s.Length()>=KolSymbolSize1)
                                                {

												}
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize1-((KolSymbolSize1-s.Length())/2));

												}

                                        break;
                                        }
                                case  2:   //право
										{
										if (s.Length()>=KolSymbolSize1)
                                                {

                                                }
										else
                                                {
												s=DopStrL(s, " ", KolSymbolSize1);

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

                                                }
										else
                                                {

                                                }
                                        break;
										}
                                case  1:    //центр
                                        {
										if (s.Length()>=KolSymbolSize2)
                                                {

                                                }
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize2-((KolSymbolSize2-s.Length())/2));

                                                }

                                        break;
                                        }
								case  2:   //право
                                        {
										if (s.Length()>=KolSymbolSize2)
                                                {

												}
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize2);

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

                                                }
										else
                                                {

                                                }
                                        break;
										}
                                case  1:    //центр
                                        {
										if (s.Length()>=KolSymbolSize3)
                                                {

												}
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize3-((KolSymbolSize3-s.Length())/2));

                                                }

                                        break;
                                        }
								case  2:   //право
                                        {
										if (s.Length()>=KolSymbolSize3)
                                                {

												}
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize3);

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

												}
                                        else
                                                {

                                                }
										break;
                                        }
                                case  1:    //центр
                                        {
										if (s.Length()>=KolSymbolSize4)
												{

                                                }
                                        else
												{
												s=DopStrL(s, " ", KolSymbolSize4-((KolSymbolSize4-s.Length())/2));

                                                }

                                        break;
										}
                                case  2:   //право
                                        {
										if (s.Length()>=KolSymbolSize4)
                                                {

                                                }
                                        else
                                                {
												s=DopStrL(s, " ", KolSymbolSize4);

                                                }

                                        break;
                                        }


                                }
                        break;
                        }


                }

 //	result=true;
	}
catch (Exception &E)
		{
		TextError=E.Message;
		//result=false;
		}



kasListXmlDocument->Add("<"+element+" " +attribyte+"=\""+FormatForXML(s)+"\"/>");




}
//------------------------------------------------------------------------------
UnicodeString T1COnLineFRCOM::kasVariantToStr(TkasVariant *kas_variant_value)
{
UnicodeString result="";

// 0 не задан 1 int, 2 строка, 3 double, 4 логическое,5 дата, 6 время, 7 датаВремя

switch (kas_variant_value->type)
{
	case  1:
		{
		 result = IntToStr(kas_variant_value->int_value);
		 break;
		}
	case  2:
		{
		 result = kas_variant_value->string_value;
		 break;
		}

	case  3:
		{
		 result = FloatToStr(kas_variant_value->dbl_value);
		 break;
		}

	case  4:
		{
		if (kas_variant_value->bool_value == true)
			{
			result = "true";
			}

		if (kas_variant_value->bool_value == false)
			{
			result = "false";
			}

		 break;
		}
}

return result;
}
//----------------------------------------------------------------------------
