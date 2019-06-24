//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaKKTOperation.h"
#include "IDMSprOborud.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IAsyncExternalEvent.h"
#include "IDevices.h"
#include "IkasDMSpr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxCalendar"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "cxTimeEdit"
#pragma link "cxGraphics"
#pragma link "cxGroupBox"
#pragma link "cxPC"
#pragma link "cxCalc"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma resource "*.dfm"



//---------------------------------------------------------------------------
__fastcall TFormaKKTOperation::TFormaKKTOperation(TComponent* Owner)
	: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;
}
//---------------------------------------------------------------------------
bool TFormaKKTOperation::Init(void)
{
bool result=false;
if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();

	}

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;



InterfaceGlobalCom->kanCreateObject("Oberon.DMViborOborud.1",IID_IDMViborOborud,
												 (void**)&DMViborFR);
DMViborFR->Init(InterfaceMainObject,InterfaceImpl);


DMViborFR->OpenTable(glStrToInt64(DM_Connection->ARMInfoID_SARM->AsString),"fr");
cxComboBoxFR->Properties->Items->Clear();
cxComboBoxFR->Properties->Items->Add("Не задан");
DMViborFR->Table->First();
while (!DMViborFR->Table->Eof)
		{
		cxComboBoxFR->Properties->Items->Add(DMViborFR->TableNAME_OBORUD->AsString);
		DMViborFR->Table->Next();
		}

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaKKTOperation::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaKKTOperation::cxButtonGetTekPCTimeClick(TObject *Sender)
{
cxTimeEdit->Time=Time();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaKKTOperation::cxButtonGetTekPCDateClick(TObject *Sender)
{
cxDateEdit->Date=Date();
}
//---------------------------------------------------------------------------
void __fastcall TFormaKKTOperation::cxButtonSetTimeKKMClick(TObject *Sender)
{

DMViborFR->Table->First();
DMViborFR->Table->MoveBy(cxComboBoxFR->ItemIndex-1);


IDMSprOborud * DMSprOborud;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
												 (void**)&DMSprOborud);
DMSprOborud->Init(InterfaceMainObject,0);
DMSprOborud->OpenElement(glStrToInt64(DMViborFR->TableID_OBORUD->AsString));

	if (glStrToInt64(DMSprOborud->ElementID_OBORUD->AsString) > 0)
		{
		IFiskReg *fr;
		AnsiString prog_id=DMSprOborud->GetParameter("ProgId");
		InterfaceGlobalCom->kanCreateObject(prog_id.c_str(),IID_IFiskReg,
													(void**)&fr);
		fr->Init(InterfaceMainObject,InterfaceImpl);

		fr->Modul=DMSprOborud->ElementMODUL_SOBORUD->AsString;
		fr->Number=1;
		//fr->InitDevice();
		int number_port=StrToInt(DMSprOborud->ElementCOMNAME_OBORUD->AsString);
		AnsiString baud_rate=DMSprOborud->ElementBAUDRATE_OBORUD->AsString;

		AnsiString password=DMSprOborud->GetParameter("password");
		if(fr->Connect(number_port, baud_rate, password)==true)
			{}
		else
			{
			ShowMessage("Ошибка при подключении фискального регистратора: "+fr->TextError);
			return;
			}

		if (fr->SetTime(cxTimeEdit->Time)==true)
			{

			}
		else
			{
            ShowMessage("Ошибка установки времени: "+fr->TextError);
			}

		fr->Disconnect();
		fr->kanRelease();
		}
	else
		{
		ShowMessage("На данном рабочем месте нет подключенных фискальных регистраторов! ");
		}

DMSprOborud->kanRelease();


}

//---------------------------------------------------------------------------
void __fastcall TFormaKKTOperation::cxButtonGetTimeFRClick(TObject *Sender)
{
DMViborFR->Table->First();
DMViborFR->Table->MoveBy(cxComboBoxFR->ItemIndex-1);

IDMSprOborud * DMSprOborud;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
												 (void**)&DMSprOborud);
DMSprOborud->Init(InterfaceMainObject,0);
DMSprOborud->OpenElement(glStrToInt64(DMViborFR->TableID_OBORUD->AsString));
	if (glStrToInt64(DMSprOborud->ElementID_OBORUD->AsString) > 0)
		{
		IFiskReg *fr;
		AnsiString prog_id=DMSprOborud->GetParameter("ProgId");
		InterfaceGlobalCom->kanCreateObject(prog_id.c_str(),IID_IFiskReg,
													(void**)&fr);
		fr->Init(InterfaceMainObject,InterfaceImpl);

		fr->Modul=DMSprOborud->ElementMODUL_SOBORUD->AsString;
		fr->Number=1;
		//fr->InitDevice();
		int number_port=StrToInt(DMSprOborud->ElementCOMNAME_OBORUD->AsString);
		AnsiString baud_rate=DMSprOborud->ElementBAUDRATE_OBORUD->AsString;

		AnsiString password=DMSprOborud->GetParameter("password");
		if(fr->Connect(number_port, baud_rate, password)==true)
			{}
		else
			{
			ShowMessage("Ошибка при подключении фискального регистратора: "+fr->TextError);
			return;
			}

		ShowMessage(fr->GetTime());

		fr->Disconnect();
		fr->kanRelease();
		}
	else
		{
		ShowMessage("На данном рабочем месте нет подключенных фискальных регистраторов! ");
		}

DMSprOborud->kanRelease();
}
//---------------------------------------------------------------------------
void __fastcall TFormaKKTOperation::cxButtonSetDateKKMClick(TObject *Sender)
{
DMViborFR->Table->First();
DMViborFR->Table->MoveBy(cxComboBoxFR->ItemIndex-1);

IDMSprOborud * DMSprOborud;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
												 (void**)&DMSprOborud);
DMSprOborud->Init(InterfaceMainObject,0);
DMSprOborud->OpenElement(glStrToInt64(DMViborFR->TableID_OBORUD->AsString));

	if (glStrToInt64(DMSprOborud->ElementID_OBORUD->AsString)>0)
		{
		IFiskReg *fr;
		AnsiString prog_id=DMSprOborud->GetParameter("ProgId");
		InterfaceGlobalCom->kanCreateObject(prog_id.c_str(),IID_IFiskReg,
													(void**)&fr);
		fr->Init(InterfaceMainObject,InterfaceImpl);

		fr->Modul=DMSprOborud->ElementMODUL_SOBORUD->AsString;
		fr->Number=1;
		//fr->InitDevice();
		int number_port=StrToInt(DMSprOborud->ElementCOMNAME_OBORUD->AsString);
		AnsiString baud_rate=DMSprOborud->ElementBAUDRATE_OBORUD->AsString;

		AnsiString password=DMSprOborud->GetParameter("password");
		if(fr->Connect(number_port, baud_rate, password)==true)
			{}
		else
			{
			ShowMessage("Ошибка при подключении фискального регистратора: "+fr->TextError);
			return;
			}

		if (fr->SetDate(cxDateEdit->Date)==true)
			{

			}
		else
			{
			ShowMessage("Ошибка установки даты: "+fr->TextError);
			}

		fr->Disconnect();
		fr->kanRelease();
		}
	else
		{
		ShowMessage("На данном рабочем месте нет подключенных фискальных регистраторов! ");
		}
DMSprOborud->kanRelease();
}
//---------------------------------------------------------------------------
void __fastcall TFormaKKTOperation::cxButtonGetDateFRClick(TObject *Sender)
{
DMViborFR->Table->First();
DMViborFR->Table->MoveBy(cxComboBoxFR->ItemIndex-1);

IDMSprOborud * DMSprOborud;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
												 (void**)&DMSprOborud);
DMSprOborud->Init(InterfaceMainObject,0);
DMSprOborud->OpenElement(glStrToInt64(DMViborFR->TableID_OBORUD->AsString));

	if (glStrToInt64(DMSprOborud->ElementID_OBORUD->AsString)>0)
		{
		IFiskReg *fr;
		AnsiString prog_id=DMSprOborud->GetParameter("ProgId");
		InterfaceGlobalCom->kanCreateObject(prog_id.c_str(),IID_IFiskReg,
													(void**)&fr);
		fr->Init(InterfaceMainObject,InterfaceImpl);

		fr->Modul=DMSprOborud->ElementMODUL_SOBORUD->AsString;
		fr->Number=1;
		//fr->InitDevice();
		int number_port=StrToInt(DMSprOborud->ElementCOMNAME_OBORUD->AsString);
		AnsiString baud_rate=DMSprOborud->ElementBAUDRATE_OBORUD->AsString;

		AnsiString password=DMSprOborud->GetParameter("password");
		if(fr->Connect(number_port, baud_rate, password)==true)
			{}
		else
			{
			ShowMessage("Ошибка при подключении фискального регистратора: "+fr->TextError);
			return;
			}

		ShowMessage(fr->GetDate());

		fr->Disconnect();
		fr->kanRelease();
		}
	else
		{
		ShowMessage("На данном рабочем месте нет подключенных фискальных регистраторов! ");
		}
DMSprOborud->kanRelease();
}
//---------------------------------------------------------------------------
void __fastcall TFormaKKTOperation::cxButtonXReportClick(TObject *Sender)
{
IFiskReg *fr=0;
fr=ConnectFR();
if (fr==0)
	{
	return;
	}


IDMSprOborud * DMSprOborud;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
												 (void**)&DMSprOborud);
DMSprOborud->Init(InterfaceMainObject,0);
DMSprOborud->OpenElement(glStrToInt64(DMViborFR->TableID_OBORUD->AsString));

fr->OpenNoFiscalCheck();
if (DMSprOborud->GetParameter("STR_ZAG_1")!="")
		{
		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_1"),1,0,0,true,false,false);
		}

if (DMSprOborud->GetParameter("STR_ZAG_2")!="")
		{
		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_2"),1,0,0,true,false,false);
		}

if (DMSprOborud->GetParameter("STR_ZAG_3")!="")
		{
		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_3"),1,0,0,true,false,false);
		}
fr->CloseNoFiscalCheck();


		if (fr->PrintXReport()==true)
			{

			}
		else
			{
			ShowMessage("Ошибка: "+fr->TextError);
			}


DisconnectFR(fr);
fr->kanRelease();
DMSprOborud->kanRelease();

}
//---------------------------------------------------------------------------
void __fastcall TFormaKKTOperation::cxButtonZReportClick(TObject *Sender)
{
IFiskReg *fr=0;
fr=ConnectFR();
if (fr==0)
	{
	return;
	}


IDMSprOborud * DMSprOborud;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
												 (void**)&DMSprOborud);
DMSprOborud->Init(InterfaceMainObject,0);
DMSprOborud->OpenElement(glStrToInt64(DMViborFR->TableID_OBORUD->AsString));

fr->OpenNoFiscalCheck();
if (DMSprOborud->GetParameter("STR_ZAG_1")!="")
		{
		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_1"),1,0,0,true,false,false);
		}

if (DMSprOborud->GetParameter("STR_ZAG_2")!="")
		{
		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_2"),1,0,0,true,false,false);
		}

if (DMSprOborud->GetParameter("STR_ZAG_3")!="")
		{
		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_3"),1,0,0,true,false,false);
		}
fr->CloseNoFiscalCheck();


		if (fr->PrintZReport()==true)
			{

			}
		else
			{
			ShowMessage("Ошибка: "+fr->TextError);
			}


DisconnectFR(fr);
fr->kanRelease();
DMSprOborud->kanRelease();
}
//---------------------------------------------------------------------------
void __fastcall TFormaKKTOperation::cxButtonCloseClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaKKTOperation::cxButtonSaleClick(TObject *Sender)
{

IFiskReg *fr=0;
fr=ConnectFR();
if (fr==0)
	{
	return;
	}

IDMSprOborud * DMSprOborud;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
												 (void**)&DMSprOborud);
DMSprOborud->Init(InterfaceMainObject,0);
DMSprOborud->OpenElement(glStrToInt64(DMViborFR->TableID_OBORUD->AsString));

		 try
			{
			fr->InitDocument(2);
			fr->OpenNoFiscalCheck();
			if (DMSprOborud->GetParameter("STR_ZAG_1")!="")
					{
					fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_1"),1,0,0,true,false,false);
					}

			if (DMSprOborud->GetParameter("STR_ZAG_2")!="")
					{
					fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_2"),1,0,0,true,false,false);
					}

			if (DMSprOborud->GetParameter("STR_ZAG_3")!="")
					{
					fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_3"),1,0,0,true,false,false);
					}
			fr->CloseNoFiscalCheck();


			TcxGridViewData * AViewData=cxGrid1TableView1->ViewData;



			double sum_check=0;

			for(int i=0;i<AViewData->RowCount;i++)
				{
				int department=AViewData->Records[i]->Values[cxGrid1TableView1Department->Index];
				UnicodeString name_nom=AViewData->Records[i]->Values[cxGrid1TableView1NameTovar->Index];
				double kol=AViewData->Records[i]->Values[cxGrid1TableView1Kol->Index];
				double price=AViewData->Records[i]->Values[cxGrid1TableView1Price->Index];
				double sum=AViewData->Records[i]->Values[cxGrid1TableView1Sum->Index];
				sum_check=sum_check+sum;

				fr->TypeFiscalString=1;   //1-фиск строка 2- текстовая строка 3-штрих код
				fr->NameNom=name_nom;
				fr->Quantity=kol;
				fr->Price=price;
				fr->Amount=sum;
				fr->Department=department;
				fr->Tax=1;  //без ндс

				if (fr->AddFiscalString()==false)
					{
					throw Exception(fr->TextError);
					}
				}


					int type_check=0;
					if (RadioButtonSale->Checked==true)       //продажа
						{
						type_check=0;
						fr->PaymentType=1;
						}

					if (RadioButtonReturnSale->Checked==true)       //продажа
						{
						type_check=1;
						fr->PaymentType=2;
						}

				fr->Cash=StrToFloat(OplataNalcxCalcEdit->Text);    										//CashLessType1 Нет decimal Сумма электронной оплаты первого типа
				fr->CashLessType1=StrToFloat(OplataPlatCardcxCalcEdit->Text);

				if (DMSprOborud->GetParameter("PrintFiscalCheck")=="1")
					{ 		//0 продажа 1 возврат
							int department=1;
							if(fr->PrintFiscalCheck(sum_check,  //сумма продажи
													department,                            //отдел
													StrToFloat(OplataNalcxCalcEdit->Text),       //наличные
													StrToFloat(OplataPlatCardcxCalcEdit->Text),     //банковская карта
													0,     //платежная карта
													0,	   //кредит
													type_check)==true)
								{
								}
							else
								{
								ShowMessage("Ошибка! "+fr->TextError);
								}


					}
				else
					{
							int department=1;
							//0 продажа 1 возврат
							if(fr->PrintNoFiscalCheck(sum_check,  //сумма продажи
													department,                            //отдел
													StrToFloat(OplataNalcxCalcEdit->Text),       //наличные
													StrToFloat(OplataPlatCardcxCalcEdit->Text),     //банковская карта
													0,     //платежная карта
													0,	   //кредит
													type_check)==true)
								{
								}
							else
								{
								ShowMessage("Ошибка! "+fr->TextError);
								}

					}

			}
		catch(Exception &exception)
			{
			ShowMessage("Ошибка! "+exception.Message);
			}




DisconnectFR(fr);
fr->kanRelease();
DMSprOborud->kanRelease();

}
//---------------------------------------------------------------------------

void __fastcall TFormaKKTOperation::cxButtonReturnSaleClick(TObject *Sender)
{
//DMViborFR->Table->First();
//DMViborFR->Table->MoveBy(cxComboBoxFR->ItemIndex-1);
//
//IDMSprOborud * DMSprOborud;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
//												 (void**)&DMSprOborud);
//DMSprOborud->Init(InterfaceMainObject,0);
//DMSprOborud->OpenElement(glStrToInt64(DMViborFR->TableID_OBORUD->AsString));
//
//	if (glStrToInt64(DMSprOborud->ElementID_OBORUD->AsString)>0)
//		{
//		IFiskReg *fr;
//		AnsiString prog_id=DMSprOborud->GetParameter("ProgId");
//		InterfaceGlobalCom->kanCreateObject(prog_id.c_str(),IID_IFiskReg,
//													(void**)&fr);
//		fr->Init(InterfaceMainObject,InterfaceImpl);
//
//		fr->Modul=DMSprOborud->ElementMODUL_SOBORUD->AsString;
//		fr->Number=1;
//		//fr->InitDevice();
//		int number_port=StrToInt(DMSprOborud->ElementCOMNAME_OBORUD->AsString);
//		AnsiString baud_rate=DMSprOborud->ElementBAUDRATE_OBORUD->AsString;
//
//		AnsiString password=DMSprOborud->GetParameter("password");
//		if(fr->Connect(number_port, baud_rate, password)==true)
//			{}
//		else
//			{
//			ShowMessage("Ошибка при подключении фискального регистратора: "+fr->TextError);
//			return;
//			}
//
//fr->OpenNoFiscalCheck();
//if (DMSprOborud->GetParameter("STR_ZAG_1")!="")
//		{
//		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_1"),1,0,0,true,false,false);
//		}
//
//if (DMSprOborud->GetParameter("STR_ZAG_2")!="")
//		{
//		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_2"),1,0,0,true,false,false);
//		}
//
//if (DMSprOborud->GetParameter("STR_ZAG_3")!="")
//		{
//		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_3"),1,0,0,true,false,false);
//		}
//fr->CloseNoFiscalCheck();
//
//		 try
//		 	{
//				if (DMSprOborud->GetParameter("UCH")=="YES")
//					{
//							int department=StrToInt(DepartmentcxSpinEdit->Text);
//							//0 продажа 1 возврат
//							if(fr->PrintNoFiscalCheck(StrToFloat(SummacxCalcEdit->Text),  //сумма продажи
//													department,                            //отдел
//													StrToFloat(OplataNalcxCalcEdit->Text),       //наличные
//													StrToFloat(OplataPlatCardcxCalcEdit->Text),     //банковская карта
//													0,     //платежная карта
//													0,	   //кредит
//													1)==true)
//								{}
//							else {}
//
//					}
//				else
//					{
//							//0 продажа 1 возврат
//							int department=StrToInt(DepartmentcxSpinEdit->Text);
//							//0 продажа 1 возврат
//							if(fr->PrintFiscalCheck(StrToFloat(SummacxCalcEdit->Text),  //сумма продажи
//													department,                            //отдел
//													StrToFloat(OplataNalcxCalcEdit->Text),       //наличные
//													StrToFloat(OplataPlatCardcxCalcEdit->Text),     //банковская карта
//													0,     //платежная карта
//													0,	   //кредит
//													1)==true)
//								{}
//							else {}
//
//					}
//
//			}
//		catch(Exception &exception)
//			{
//			ShowMessage("Ошибка! "+exception.Message);
//			}
//
//
//		fr->Disconnect();
//		fr->kanRelease();
//		}
//	else
//		{
//		ShowMessage("На данном рабочем месте нет подключенных фискальных регистраторов! ");
//		}
//DMSprOborud->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TFormaKKTOperation::cxButtonOpenShiftClick(TObject *Sender)
{

IFiskReg *fr=0;
fr=ConnectFR();
if (fr==0)
	{
	return;
	}


IDMSprOborud * DMSprOborud;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
												 (void**)&DMSprOborud);
DMSprOborud->Init(InterfaceMainObject,0);
DMSprOborud->OpenElement(glStrToInt64(DMViborFR->TableID_OBORUD->AsString));
fr->InitDocument(1);
fr->OpenNoFiscalCheck();
if (DMSprOborud->GetParameter("STR_ZAG_1")!="")
		{
		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_1"),1,0,0,true,false,false);
		}

if (DMSprOborud->GetParameter("STR_ZAG_2")!="")
		{
		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_2"),1,0,0,true,false,false);
		}

if (DMSprOborud->GetParameter("STR_ZAG_3")!="")
		{
		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_3"),1,0,0,true,false,false);
		}
fr->CloseNoFiscalCheck();


		if (fr->OpenShift()==true)
			{

			}
		else
			{
			ShowMessage("Ошибка: "+fr->TextError);
			}


DisconnectFR(fr);
fr->kanRelease();
DMSprOborud->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TFormaKKTOperation::cxButtonCloseShiftClick(TObject *Sender)
{
IFiskReg *fr=0;
fr=ConnectFR();
if (fr==0)
	{
	return;
	}


IDMSprOborud * DMSprOborud;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
												 (void**)&DMSprOborud);
DMSprOborud->Init(InterfaceMainObject,0);
DMSprOborud->OpenElement(glStrToInt64(DMViborFR->TableID_OBORUD->AsString));

fr->InitDocument(1);
fr->OpenNoFiscalCheck();
if (DMSprOborud->GetParameter("STR_ZAG_1")!="")
		{
		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_1"),1,0,0,true,false,false);
		}

if (DMSprOborud->GetParameter("STR_ZAG_2")!="")
		{
		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_2"),1,0,0,true,false,false);
		}

if (DMSprOborud->GetParameter("STR_ZAG_3")!="")
		{
		fr->PrintString(DMSprOborud->GetParameter("STR_ZAG_3"),1,0,0,true,false,false);
		}
fr->CloseNoFiscalCheck();


		if (fr->CloseShift()==true)
			{

			}
		else
			{
			ShowMessage("Ошибка: "+fr->TextError);
			}


DisconnectFR(fr);
fr->kanRelease();
DMSprOborud->kanRelease();
}
//---------------------------------------------------------------------------
IFiskReg * TFormaKKTOperation::ConnectFR(void)
{
IFiskReg * fr=0;
DMViborFR->Table->First();
DMViborFR->Table->MoveBy(cxComboBoxFR->ItemIndex-1);

IDMSprOborud * DMSprOborud;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprOborud.1",IID_IDMSprOborud,
												 (void**)&DMSprOborud);

DMSprOborud->Init(InterfaceMainObject,0);
DMSprOborud->OpenElement(glStrToInt64(DMViborFR->TableID_OBORUD->AsString));

IkasDMSpr * oborud_param;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprOborudParam,IID_IkasDMSpr,
												 (void**)&oborud_param);
oborud_param->Init(InterfaceMainObject,0);
oborud_param->IdOwner=glStrToInt64(DMSprOborud->ElementID_OBORUD->AsString);
oborud_param->OpenTable(0);


	if (glStrToInt64(DMSprOborud->ElementID_OBORUD->AsString)>0)
		{

		AnsiString prog_id=DMSprOborud->ElementPROGID_SOBORUD->AsString;
		InterfaceGlobalCom->kanCreateObject(prog_id.c_str(),IID_IFiskReg,
													(void**)&fr);
		fr->Modul=DMSprOborud->ElementMODUL_SOBORUD->AsString;
		fr->Init(InterfaceMainObject,InterfaceImpl);
		fr->Number=1;



		//установим параметры подключения
		oborud_param->First(0);
		while(!oborud_param->GetEof(0))
			{
			TkasVariant * kv=new TkasVariant;
			if (oborud_param->GetValueFieldAsBool("ON_CONNECT_SOBORUD_PAR", 0)==true &&
							oborud_param->GetValueFieldAsBool("BEFORE_CONNECT_SOBORUD_PAR", 0)==true)
				{ //устанавливаем данный параметр
				int type_value=oborud_param->GetValueFieldAsInt("TYPE_PARAMETER_SOBORUD_PAR", 0);
				if (type_value == 1) //int
					{
					kv->type=1; kv->int_value=oborud_param->GetValueFieldAsInt("VALUE_SOBORUD_PAR", 0);
					}
				if (type_value == 2) //string
					{
					kv->type=2; kv->string_value=oborud_param->GetValueFieldAsString("VALUE_SOBORUD_PAR", 0).c_str(); kv->len_string=wcslen(kv->string_value);
					}
				if (type_value == 4) //booulean
					{
					kv->type=4; kv->bool_value=oborud_param->GetValueFieldAsBool("VALUE_SOBORUD_PAR", 0);
					}

				if (fr->SetParameter(oborud_param->GetValueFieldAsString("NAME_SOBORUD_PAR", 0), kv) == false)
					{
                    ShowMessage("Ошибка при установке параметра подключения");
					}
				}
			oborud_param->Next(0);
			delete kv;
			}
		//fr->InitDevice();
		int number_port=StrToInt(DMSprOborud->ElementCOMNAME_OBORUD->AsString);
		AnsiString baud_rate=DMSprOborud->ElementBAUDRATE_OBORUD->AsString;

		AnsiString password=DMSprOborud->GetParameter("password");
		if(fr->Connect(number_port, baud_rate, password)==true)
			{}
		else
			{
			ShowMessage("Ошибка при подключении фискального регистратора: "+fr->TextError);
			if (fr > 0) fr->kanRelease();
			fr=0;
			}


		}
	else
		{
		ShowMessage("На данном рабочем месте нет подключенных фискальных регистраторов! ");
			if (fr > 0) fr->kanRelease();
			fr=0;
		}

DMSprOborud->kanRelease();
oborud_param->kanRelease();

return fr;
}
//----------------------------------------------------------------------------
bool TFormaKKTOperation::DisconnectFR(IFiskReg * fr)
{
bool result=true;

if (fr > 0)
	{
	fr->Disconnect();
	fr->Done();
	}

return result;
}
//-----------------------------------------------------------------------
