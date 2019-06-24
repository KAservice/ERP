//---------------------------------------------------------------------------


#pragma hdrstop

#include "U1COnLineFR.h"
#include <math.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)




//-------------------------------------------------------------------
T1COnLineFR::T1COnLineFR()
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


kasListDocumentPackage = new TStringList;
kasListCheckPackage = new TStringList;
kasListGoodsPackage = new TStringList;

Electronically=false;
}
//-----------------------------------------------------------------------------
T1COnLineFR::~T1COnLineFR()
{
delete kasListDocumentPackage;
delete kasListCheckPackage;
delete kasListGoodsPackage;
//ObjectVC->kanRelease();
}
//---------------------------------------------------------------------------
int T1COnLineFR::Init()
{
if (InterfaceMainObject>0)
	{
	//������� ��������� COM ������� ��� �������� ����� ��������
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

InterfaceGlobalCom->kanCreateObject(ProgId_Object1CVnComp,IID_IObject1CVnComp, (void**)&ObjectVC);
ObjectVC->NameDllVnComp=Modul.c_str();
ObjectVC->InitVC();


return -1;
}
//----------------------------------------------------------------------------
int T1COnLineFR::Done()
{
ObjectVC->DoneVC();
ObjectVC->kanRelease();
return -1;
}

//---------------------------------------------------------------------------
bool T1COnLineFR::GetError(void)
{
bool result=false;

int	num_metod=ObjectVC->FindMethod(L"��������������");
int	kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //���������� ���������� ������ 1

	TkasVariant * in_parameter_err=new TkasVariant;
	for(int i = 0; i < kol_parameter_metoda; i++)
		{
		InitKasVariant(&in_parameter_err[i]);
		}
	TkasVariant * variant_result_err=new TkasVariant;
	InitKasVariant(variant_result_err);


	ObjectVC->CallAsFunc(num_metod,variant_result_err,in_parameter_err, 1);

	if (variant_result_err->type==1 && variant_result_err->int_value!=0)  //����� ��� ������ �� ����
		{
		result=true;
		if (in_parameter_err[0].type==2)
			{
			TextError=TextError+" ��� ������:"+IntToStr(variant_result_err->int_value)+" "+UnicodeString(in_parameter_err[0].string_value);
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

bool  T1COnLineFR::Connect(int number_port,
				UnicodeString baud_rate,
				UnicodeString password)
{
bool result=true;
TextError="";
TextErrorNoConnect="";

////////////////��������� ���� ////////////////////////////////////////
if (result==true)
	{
	int num_metod=ObjectVC->FindMethod(L"������������������");   //16
	int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //���������� ���������� ������   2

	//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///������������ ���� ������� � ������ � ���������� ������� lMethodNum ������������� ��������: true ��� ������� � ������������ ��������� � false � ��������� ������.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda]; for(int i = 0; i < kol_parameter_metoda; i++){InitKasVariant(&in_parameter[i]);}
	TkasVariant * variant_result=new TkasVariant; InitKasVariant(variant_result);

	UnicodeString s="";

	s=L"Port";
	in_parameter[0].string_value=s.c_str(); 	in_parameter[0].type=2; in_parameter[0].len_string=wcslen(in_parameter[0].string_value);

	if (number_port<10) {s="COM"+IntToStr(number_port);}	else { s="\\.\COM"+IntToStr(number_port);}
	in_parameter[1].string_value=s.c_str(); 	in_parameter[1].type=2; in_parameter[1].len_string=wcslen(in_parameter[1].string_value);

	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="������ ��� ���������� ������ ��������� ���������";
		TextErrorNoConnect="������ ��� ���������� ������ ��������� ���������";
		result=false;
		}
	//����� �������� ��� ������
	//�������� ������ � ����������

	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //��������� ������ � ����������
		result=false;
		}

	 if (GetError()==true)   //���� ������
		{
		result=false;
		}

	s="";
	delete in_parameter;
	delete variant_result;
	}


////////////////��������� �������� ////////////////////////////////////////
if (result==true)
	{
	int num_metod=ObjectVC->FindMethod(L"������������������");   //16
	int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //���������� ���������� ������   2

	//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///������������ ���� ������� � ������ � ���������� ������� lMethodNum ������������� ��������: true ��� ������� � ������������ ��������� � false � ��������� ������.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda]; for(int i = 0; i < kol_parameter_metoda; i++){InitKasVariant(&in_parameter[i]);}
	TkasVariant * variant_result=new TkasVariant; InitKasVariant(variant_result);

	in_parameter[0].string_value=L"Speed"; 	in_parameter[0].type=2;in_parameter[0].len_string=wcslen(in_parameter[0].string_value);
	in_parameter[1].int_value=StrToInt(baud_rate); 	in_parameter[1].type=1;

	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="������ ��� ���������� ������ ��������� ���������";
		TextErrorNoConnect="������ ��� ���������� ������ ��������� ���������";
		result=false;
		}
	//����� �������� ��� ������
	//�������� ������ � ����������

	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //��������� ������ � ����������
		result=false;
		}

	 if (GetError()==true)   //���� ������
		{
		result=false;
		}

	delete in_parameter;
	delete variant_result;
	}




/////////////////�����������
if (result==true)
	{
	ConnectFR=true;
	int num_metod=ObjectVC->FindMethod(L"����������");
	int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //���������� ���������� ������

	//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///������������ ���� ������� � ������ � ���������� ������� lMethodNum ������������� ��������: true ��� ������� � ������������ ��������� � false � ��������� ������.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
	for(int i = 0; i < kol_parameter_metoda; i++)
		{
		InitKasVariant(&in_parameter[i]);
		}

	TkasVariant * variant_result=new TkasVariant;
	InitKasVariant(variant_result);

	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="������ ��� ���������� ������ �����������";
		TextErrorNoConnect="������ ��� ���������� ������ �����������";
		result=false;
		}
	//����� �������� ��� ������
	//�������� ������ � ����������

	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //��������� ������ � ����������
		ConnectFR=false;
		result=false;
		}

	 if (GetError()==true)   //���� ������
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


/////////////////�����������
if (result==true)
	{
	ConnectFR=true;
	int num_metod=ObjectVC->FindMethod(L"��������������������");
	int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //���������� ���������� ������

	//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///������������ ���� ������� � ������ � ���������� ������� lMethodNum ������������� ��������: true ��� ������� � ������������ ��������� � false � ��������� ������.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
	for(int i = 0; i < kol_parameter_metoda; i++)
		{
		InitKasVariant(&in_parameter[i]);
		}

	TkasVariant * variant_result=new TkasVariant;
	InitKasVariant(variant_result);

	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="������ ��� ���������� ������ �����������";
		TextErrorNoConnect="������ ��� ���������� ������ �����������";
		result=false;
		}
	//����� �������� ��� ������
	//�������� ������ � ����������

	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //��������� ������ � ����������
		ConnectFR=false;
		result=false;
		}

	 if (GetError()==true)   //���� ������
		{
		ConnectFR=false;
		result=false;
		}

	LineLength=0;

	if (in_parameter[1].type==1)
		{
		LineLength=in_parameter[1].int_value;
		KolSymbolSize1=LineLength;
		KolSymbolSize1Girn=LineLength;
		KolSymbolSize2=LineLength;
		KolSymbolSize2Girn=LineLength;
		KolSymbolSize3=LineLength;
		KolSymbolSize3Girn=LineLength;
		KolSymbolSize4=LineLength;
		KolSymbolSize4Girn=LineLength;
		}

	delete in_parameter;
	delete variant_result;

	}


return result;
}
//--------------------------------------------------------------------------

bool  T1COnLineFR::Disconnect(void)
{
bool result=true;


/////////////////�����������
if (result==true)
	{
	int num_metod=ObjectVC->FindMethod(L"���������");
	int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //���������� ���������� ������

	//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///������������ ���� ������� � ������ � ���������� ������� lMethodNum ������������� ��������: true ��� ������� � ������������ ��������� � false � ��������� ������.

	TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
	for(int i = 0; i < kol_parameter_metoda; i++)
		{
		InitKasVariant(&in_parameter[i]);
		}

	TkasVariant * variant_result=new TkasVariant;
	InitKasVariant(variant_result);

	if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
		{
		TextError="������ ��� ���������� ������ ���������";
		result=false;
		}
	//����� �������� ��� ������
	//�������� ������ � ����������
	if (in_parameter->type==2) {IDDevice=in_parameter->string_value;}

	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //��������� ������ � ����������
		result=false;
		}

	 if (GetError()==true)   //���� ������
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

bool  T1COnLineFR::GetSostKKM(void)
{
bool result=true;



return result;
}
//---------------------------------------------------------------------------
bool  T1COnLineFR::ProvVosmPrintCheck(void)
{
bool result=true;

return result;

}
//----------------------------------------------------------------------------
bool   T1COnLineFR::OpenNoFiscalCheck(void)
{
bool result=true;
kasListDocumentPackage->Clear();
kasListDocumentPackage->Add("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
kasListDocumentPackage->Add("<Document>");
kasListDocumentPackage->Add("<Positions>");
return result;
}
//---------------------------------------------------------------------------
bool   T1COnLineFR::CloseNoFiscalCheck(void)
{
bool result=true;


kasListDocumentPackage->Add("</Positions>");
kasListDocumentPackage->Add("</Document>");


ShowMessage(kasListDocumentPackage->Text);



/////////////////�����������
if (result==true)
	{
	int num_metod=ObjectVC->FindMethod(L"���������������������������");
	int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //���������� ���������� ������

	//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///������������ ���� ������� � ������ � ���������� ������� lMethodNum ������������� ��������: true ��� ������� � ������������ ��������� � false � ��������� ������.

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
		TextError="������ ��� ���������� ������ ���������������������������";
		result=false;
		}
	//����� �������� ��� ������
	//�������� ������ � ����������
	if (in_parameter->type==2) {IDDevice=in_parameter->string_value;}

	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //��������� ������ � ����������
		result=false;
		}

	 if (GetError()==true)   //���� ������
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
bool  T1COnLineFR::PrintString(UnicodeString str,
												int size_font,       //1234
												int style,           //1-������ 0 �������   2 ������ 3 ������ ������
												int alignment,       //0 ���� 1 ����� 2 �����
												bool ch_lenta,       //�� ������� �����
												bool kontr_lenta,    //�� ����������� �����
												bool word_wrap)
{
bool result=true;



if (Trim(str) == "") str=" ";          //����� ��� ������ ������ ������� ������
UnicodeString s=str;

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
								case  0:      //����
                                        {

                                        break;
                                        }
								case  1:    //�����
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
                                case  2:   //�����
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
                                case  0:      //����
                                        {
										if (s.Length()>=KolSymbolSize2)
                                                {

                                                }
                                        else
                                                {

                                                }
                                        break;
                                        }
                                case  1:    //�����
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
                                case  2:   //�����
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
                                case  0:      //����
                                        {
										if (s.Length()>=KolSymbolSize3)
                                                {

                                                }
                                        else
                                                {

                                                }
                                        break;
                                        }
                                case  1:    //�����
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
                                case  2:   //�����
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
                                case  0:      //����
                                        {
										if (s.Length()>=KolSymbolSize4)
                                                {

                                                }
                                        else
                                                {

                                                }
                                        break;
                                        }
                                case  1:    //�����
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
                                case  2:   //�����
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


kasListDocumentPackage->Add("<TextString Text=\""+FormatForXML(s)+"\"/>");


//kasListDocumentPackage->Add("<TextString Text=\"���������� �����: 00002345\"/>");
//kasListDocumentPackage->Add("<Barcode BarcodeType=\"QR\" Barcode=\"2000021262157\"/>");

return result;

}
//---------------------------------------------------------------------------
bool  T1COnLineFR::PrintLine(void)
{
bool result=true;

UnicodeString s="-";
s=DopStrL(s, "-", KolSymbolSize1);


try
	{
	result=PrintString(s,
												1,       //1234
												0,           //1-������ 0 �������   2 ������ 3 ������ ������
												0,       //0 ���� 1 ����� 2 �����
												1,       //�� ������� �����
												0,    //�� ����������� �����
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


bool  T1COnLineFR::PrintFiscalCheck(double sum,
						int department,
						double oplata_nal,
						double oplata_bank_card,
						double oplata_plat_card,
						double oplata_credit_card,
						int operation)    //0 ������� 1 �������
{
bool result=false;

	Cash=oplata_nal;
	CashLessType1=oplata_bank_card;
	CashLessType2=oplata_plat_card;
	CashLessType3=oplata_credit_card ;

if (operation==0)//�������
	{
	PaymentType=1;
	}

if (operation==1)//������� �������
	{
	PaymentType=2;
	}

CreateHeaderFiscalCheck();
kasListCheckPackage->Add(kasListGoodsPackage->Text);
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
bool  T1COnLineFR::PrintFiscalCheckSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation)    //0 ������� 1 �������
{
bool result=true;

int num_metod=ObjectVC->FindMethod(L"���������������");
int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //���������� ���������� ������

//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///������������ ���� ������� � ������ � ���������� ������� lMethodNum ������������� ��������: true ��� ������� � ������������ ��������� � false � ��������� ������.

TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}


UnicodeString s="";

	//������������ (DeviceID)
	in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2;

	//������ (CashierName) STRING [IN] ��� ��������������� ���� ��� ���������� ��������
	s=CashierName;
	in_parameter[1].string_value=s.c_str(); 	in_parameter[1].type=2; in_parameter[1].len_string=wcslen(in_parameter[1].string_value);
	//���������� (Electronically) BOOL (IN) ������������ ���� � ������ ���������� ����. ������ ���� �� ��������������.
	in_parameter[2].bool_value=Electronically; 	in_parameter[2].type=4;
	//���������� (CheckPackage) XML �������  STRING [IN] XML ��������� - �������� ����.
	in_parameter[3].string_value=kasListCheckPackage->GetText(); 	in_parameter[3].type=2; in_parameter[3].len_string=wcslen(in_parameter[3].string_value);




TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
	{
	TextError="������ ��� ���������� ������ ������ � ������";
	TextErrorNoConnect="������ ��� ���������� ������ ������ � ������";
	result=false;
	}
//����� �������� ��� ������
//�������� ������ � ����������


	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //��������� ������ � ����������
		result=false;
		}

	 if (GetError()==true)   //���� ������
		{
		result=false;
		}

	//��������� (CheckNumber)  LONG [OUT] ����� ����������� ���� ������������ ��
	if (in_parameter[4].type==1)  {NumberCheck=in_parameter[4].int_value;}
	//���������� (SessionNumber)  LONG [OUT] ����� �������� �����
	if (in_parameter[5].type==1)  {NumberKL=in_parameter[5].int_value;}
	//����������������� (FiscalSign) STRING [OUT] ���������� �������
	if (in_parameter[6].type==2)  {FiscalSign=in_parameter[6].string_value;}
	//AddressSiteInspections (������������������) STRING [OUT] ����� ����� ��������
	if (in_parameter[7].type==2)  {AddressSiteInspections=in_parameter[7].string_value;}


delete in_parameter;
delete variant_result;

return result;

}
//---------------------------------------------------------------------------
bool T1COnLineFR::PrintFiscalCheckReturnSale(double sum,
														int department,
														double oplata_nal,
														double oplata_bank_card,
														double oplata_plat_card,
														double oplata_credit_card,
														int operation)    //0 ������� 1 �������
{ //�� ���� ���� �������, ����� ��� ����� ����� ������ ���� �������
bool result=false;

return result;

}
//---------------------------------------------------------------------------
bool  T1COnLineFR::PrintNoFiscalCheck(double sum,
								int department,
								double oplata_nal,
								double oplata_bank_card,
								double oplata_plat_card,
								double oplata_credit_card,
								int operation)    //0 ������� 1 �������
{
bool result=false;


OpenNoFiscalCheck();
PrintString("������������ ��� ���������",
								1,       //1234
								0,            //1-������ 0 �������
								0,      //0 ���� 1 ����� 2 �����
								1,       //�� ������� �����
								0,   //�� ����������� �����
								0);

CloseNoFiscalCheck();

return result;

}
//---------------------------------------------------------------------------
bool  T1COnLineFR::PrintXReport(void)
{
bool result=true;
TextError="";
TextErrorNoConnect="";

//int kol_metod=ObjectVC->GetNMethods();
//UnicodeString s="";
//for(int i = 0; i < kol_metod; i++)
//	{
//	int kol_par=ObjectVC->GetNParams(i);
//	s=s+"����� "+IntToStr(i)+" "+UnicodeString(ObjectVC->GetMethodName(i,1))+" "+IntToStr(kol_par)+"\n";
//	}
//
//ShowMessage(s);



int num_metod=ObjectVC->FindMethod(L"������������������������������");
int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //���������� ���������� ������

//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///������������ ���� ������� � ������ � ���������� ������� lMethodNum ������������� ��������: true ��� ������� � ������������ ��������� � false � ��������� ������.

TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}


// 1 ������� ��������

in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2;


TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
	{
	TextError="������ ��� ���������� ������ ������ � ������";
	result=false;
	}
//����� �������� ��� ������
//�������� ������ � ����������


	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //��������� ������ � ����������
		result=false;
		}

	 if (GetError()==true)   //���� ������
		{
		result=false;
		}

//ShowMessage(UnicodeString(in_parameter[0].string_value));
delete in_parameter;
delete variant_result;


return result;

}
//---------------------------------------------------------------------------
bool T1COnLineFR::PrintZReport(void)
{
bool result=false;



return result;

}
//---------------------------------------------------------------------------
bool  T1COnLineFR::PrintPoOtdelamReport(void)
{
bool result=false;

return result;
}
//---------------------------------------------------------------------------

bool  T1COnLineFR::Cut(int TypeCut)
{
bool result=true ;


return result;

}
//---------------------------------------------------------------------------

bool  T1COnLineFR::Vnesenie(double sum)
{
bool result=false;

return result;

}
//---------------------------------------------------------------------------
bool  T1COnLineFR::Snatie(double sum)
{
bool result=false;


return result;

}
//---------------------------------------------------------------------------
//��������� ������ Str ����� ��������� Symbol �� Len
UnicodeString T1COnLineFR::DopStrL(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//---------------------------------------------------------------------------
//��������� ������ Str ������ ��������� Symbol �� Len
UnicodeString T1COnLineFR::DopStrR(UnicodeString Str, UnicodeString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Str+Symbol;
        }
return Str;
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
TTime  T1COnLineFR::GetTime(void)
{
TTime result=0;

return result;

}
//-----------------------------------------------------------------------------
TDate T1COnLineFR::GetDate(void)
{
TDate result=0;

return result;

}
//--------------------------------------------------------------------------
bool  T1COnLineFR::SetTime(TTime time)
{
bool result=false;


return result;
}
//-----------------------------------------------------------------------------
bool  T1COnLineFR::SetDate(TDate date)
{
bool result=false;


return result;
}
//-----------------------------------------------------------------------------
void T1COnLineFR::OpenDrawer(void)
{

}
//-----------------------------------------------------------------------------
int T1COnLineFR::CompareDoubleValue(double v1, double v2, int pogr)
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
void T1COnLineFR::InitKasVariant(TkasVariant * kv)
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
UnicodeString T1COnLineFR::FormatForXML(UnicodeString str)
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
UnicodeString T1COnLineFR::ReplaceCommaToPixel(UnicodeString str)
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
bool T1COnLineFR::OpenShift(void)
{
bool result=true;
TextError="";

//int kol_metod=ObjectVC->GetNMethods();
//UnicodeString s="";
//for(int i = 0; i < kol_metod; i++)
//	{
//	int kol_par=ObjectVC->GetNParams(i);
//	s=s+"����� "+IntToStr(i)+" "+UnicodeString(ObjectVC->GetMethodName(i,1))+" "+IntToStr(kol_par)+"\n";
//	}
//
//ShowMessage(s);



int num_metod=ObjectVC->FindMethod(L"������������");
int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //���������� ���������� ������

//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///������������ ���� ������� � ������ � ���������� ������� lMethodNum ������������� ��������: true ��� ������� � ������������ ��������� � false � ��������� ������.

TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}


// 1 ������� ��������

in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2;


TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
	{
	TextError="������ ��� ���������� ������ �������� �����";
	result=false;
	}
//����� �������� ��� ������
//�������� ������ � ����������


	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //��������� ������ � ����������
		result=false;
		}

	 if (GetError()==true)   //���� ������
		{
		result=false;
		}

//ShowMessage(UnicodeString(in_parameter[0].string_value));
delete in_parameter;
delete variant_result;


return result;

}
//-----------------------------------------------------------------------------
bool T1COnLineFR::CloseShift(void)
{
bool result=true;
TextError="";

//int kol_metod=ObjectVC->GetNMethods();
//UnicodeString s="";
//for(int i = 0; i < kol_metod; i++)
//	{
//	int kol_par=ObjectVC->GetNParams(i);
//	s=s+"����� "+IntToStr(i)+" "+UnicodeString(ObjectVC->GetMethodName(i,1))+" "+IntToStr(kol_par)+"\n";
//	}
//
//ShowMessage(s);



int num_metod=ObjectVC->FindMethod(L"������������");
int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //���������� ���������� ������

//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///������������ ���� ������� � ������ � ���������� ������� lMethodNum ������������� ��������: true ��� ������� � ������������ ��������� � false � ��������� ������.

TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}


// 4 ���������

in_parameter[0].string_value=IDDevice.c_str(); 	in_parameter[0].type=2;


TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
	{
	TextError="������ ��� ���������� ������ ������ �������� �����";
	result=false;
	}
//����� �������� ��� ������
//�������� ������ � ����������


	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //��������� ������ � ����������
		result=false;
		}

	 if (GetError()==true)   //���� ������
		{
		result=false;
		}

//ShowMessage(UnicodeString(in_parameter[0].string_value));
delete in_parameter;
delete variant_result;


return result;

}
//-----------------------------------------------------------------------------
bool T1COnLineFR::InitCheck(void)
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
bool T1COnLineFR::CreateHeaderFiscalCheck(void)
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
bool T1COnLineFR::CreateFooterFiscalCheck(void)
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
bool T1COnLineFR::AddFiscalString(void)
{
bool result=true;
UnicodeString s="";
if (TypeFiscalString==1)       //1-���� ������ 2- ��������� ������ 3-����� ���
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


if (TypeFiscalString==2)       //1-���� ������ 2- ��������� ������ 3-����� ���
	{
	s="<TextString ";
	s=s+"Text=\""+TextString+"\"";
	s=s+" />";
	}

if (TypeFiscalString==3)       //1-���� ������ 2- ��������� ������ 3-����� ���
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
UnicodeString T1COnLineFR::ConverIntegerTaxToString(int tax)
{
UnicodeString result="";
				  //	"18" - ��� 18
					  //	"10" - ��� 10
					  //	"0" - ��� 0
					  //	"none" - ��� ���


						//case 0:    //�� �����
						//case 1:    //��� ���
						//case 2:    //0%
						//case 3:    //10%
						//case 4:    //18%

switch (tax)
	{
	case 0:    //�� �����
		{
		result="none";
		}break;
	case 1:    //��� ���
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
UnicodeString T1COnLineFR::GetParameters(void)
{
UnicodeString result="";
TextError="";

int num_metod=ObjectVC->FindMethod(L"�����������������");
int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //���������� ���������� ������

//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///������������ ���� ������� � ������ � ���������� ������� lMethodNum ������������� ��������: true ��� ������� � ������������ ��������� � false � ��������� ������.

TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}

TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
	{
	TextError="������ ��� ���������� ������ ������ �������� �����";
	//result=false;
	}
//����� �������� ��� ������
//�������� ������ � ����������


	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //��������� ������ � ����������
		//result=false;
		}

	 if (GetError()==true)   //���� ������
		{
		//result=false;
		}

		if (in_parameter[0].type==2)
			{
			result=UnicodeString(in_parameter[0].string_value);
			}

//ShowMessage(UnicodeString(in_parameter[0].string_value));
delete in_parameter;
delete variant_result;


return result;
}
//-------------------------------------------------------------------------
bool T1COnLineFR::SetParameter(UnicodeString name_parameter, UnicodeString value_parameter)
{
bool result=true;


return result;
}
//--------------------------------------------------------------------------
UnicodeString T1COnLineFR::GetAdditionalActions(void)
{
UnicodeString result="";
TextError="";

int num_metod=ObjectVC->FindMethod(L"������������������������������");
int kol_parameter_metoda=ObjectVC->GetNParams(num_metod);    //���������� ���������� ������

//bool fl_return_value=ObjectVC->HasRetVal(num_metod);  ///������������ ���� ������� � ������ � ���������� ������� lMethodNum ������������� ��������: true ��� ������� � ������������ ��������� � false � ��������� ������.

TkasVariant * in_parameter=new TkasVariant[kol_parameter_metoda];
for(int i = 0; i < kol_parameter_metoda; i++)
	{
	InitKasVariant(&in_parameter[i]);
	}

TkasVariant * variant_result=new TkasVariant;
InitKasVariant(variant_result);

if (ObjectVC->CallAsFunc(num_metod,variant_result,  in_parameter, kol_parameter_metoda)==false)
	{
	TextError="������ ��� ���������� ������ ������ �������� �����";
	//result=false;
	}
//����� �������� ��� ������
//�������� ������ � ����������


	if (variant_result->type==4 && variant_result->bool_value==false)
		{   //��������� ������ � ����������
		//result=false;
		}

	 if (GetError()==true)   //���� ������
		{
		//result=false;
		}

		if (in_parameter[0].type==2)
			{
			result=UnicodeString(in_parameter[0].string_value);
			}

//ShowMessage(UnicodeString(in_parameter[0].string_value));
delete in_parameter;
delete variant_result;


return result;
}
//-------------------------------------------------------------------------
bool T1COnLineFR::DoAdditionalAction(UnicodeString name_action)
{
bool result=true;


return result;
}
//-----------------------------------------------------------------------
