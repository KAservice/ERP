//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaDocRealRest.h"
#include "UDMSprPrice.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocRealRest::TFormaDocRealRest(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRealRest::FormCreate(TObject *Sender)
{
EditRekvisit=NO;
DM= new TDMDocRealRest(Application);
Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи


NumDoc->DataSource=DM->DataSourceDocAll;
PrimChk->DataSource=DM->DataSourceDoc;
SumDocDBText->DataSource=DM->DataSourceDocAll;
NameBaseDBText->DataSource=DM->DataSourceDocAll;
DBTextFNameUser->DataSource=DM->DataSourceDocAll;
DBGrid1->DataSource=DM->DataSourceDocT;

EditFirm->Text="";
EditSklad->Text="";
EditKlient->Text="";

ActionOperation=aoNO;

DMSprTypePrice=new TDMSprTypePrice(Application);
DMSprTypePrice->OpenTable();
TypePriceComboBox->Items->Clear();
TypePriceComboBox->Items->Add("Не задан");
DMSprTypePrice->Table->First();
while (!DMSprTypePrice->Table->Eof)
        {
        TypePriceComboBox->Items->Add(DMSprTypePrice->TableNAME_TPRICE->AsString);
        DMSprTypePrice->Table->Next();
		}
}
//--------------------------------------------------------------------------
void TFormaDocRealRest::UpdateForm(void)
{
DateDoc->DateTime=DM->DocAllPOSDOC->AsDateTime;
Prosmotr=DM->Prosmotr;
if (Prosmotr==true)
        {
        ProsmotrLabel->Visible=true;
        }
else
        {
        ProsmotrLabel->Visible=false;
		}
		
TypePriceComboBox->ItemIndex=DMSprTypePrice->GetIndexTypePricePoId(DM->DocIDTPRICE_REALREST->AsInt64);

EditFirm->Text=DM->DocAllNAMEFIRM->AsString;
EditSklad->Text=DM->DocAllNAMESKLAD->AsString;
EditKlient->Text=DM->DocAllNAMEKLIENT->AsString;

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRealRest::ButtonCloseClick(TObject *Sender)
{

Close();

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRealRest::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(SpisokFirm)SpisokFirm->Close();
if(SpisokSklad)SpisokSklad->Close();
if(SpisokKlient)SpisokKlient->Close();
if(SpisokNom)SpisokNom->Close();
if(SpisokEd)SpisokEd->Close();
if(FormaSpiskaSprInfBase)FormaSpiskaSprInfBase->Close();


try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRest::ButtonSaveClick(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{

		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRest::ToolButtonInsertClick(TObject *Sender)
{
if(Prosmotr==true) return;
ActionOperation=aoAddNewString;
OpenFormSpiskaSprNom();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRealRest::ToolButtonDeleteClick(TObject *Sender)
{
if(Prosmotr==true) return;
DM->DeleteStringDoc();

}

//---------------------------------------------------------------------------
void TFormaDocRealRest::OpenFormSpiskaSprEd(void)
{
if(Prosmotr==true) return;
if (IdDochForm==NULL)
        {

        SpisokEd=new TFormaSpiskaSprEd(Application);
        if (!SpisokEd) return;
        SpisokEd->IdRodForm=Handle;
        SpisokEd->Vibor=true;
        IdDochForm=SpisokEd->Handle;
        EditRekvisit=ViborEdinica;
		SpisokEd->DM->OpenTable(DM->DocTIDNOM_REALRESTT->AsInt64);
        SpisokEd->FOnCloseForm=EndEdit;
        SpisokEd->Show();

        }
}
//-----------------------------------------------------------------------------
void TFormaDocRealRest::OpenFormSpiskaSprNom(void)
{
if(Prosmotr==true) return;
if (IdDochForm==NULL)
        {
        SpisokNom=new TFormaSpiskaSprNom(Application);
        if (!SpisokNom) return;
        SpisokNom->IdRodForm=Handle;
        SpisokNom->Vibor=true;
        IdDochForm=SpisokNom->Handle;
        EditRekvisit=ViborTovar;
		SpisokNom->DM->IdTypePrice=DM->DocIDTPRICE_REALREST->AsInt64;
        SpisokNom->SpisokTypePrice->ItemIndex=SpisokNom->DM->GetIndexTypePrice()-1;
		SpisokNom->IdNom=DM->DocTIDNOM_REALRESTT->AsInt64;
        SpisokNom->UpdateForm();
        SpisokNom->FOnCloseForm=EndEdit;
        SpisokNom->Show();
        }

}

//---------------------------------------------------------------------------
void __fastcall TFormaDocRealRest::EndEdit(TObject *Sender)
{
if (EditRekvisit==ViborTovar)
        {
        if(Prosmotr==true) return;
        if (SpisokNom->OutReady==true)
                {
                if (ActionOperation==aoAddNewString)
                        {
                        DM->AddDocNewString();
                        }                
                DM->DocT->Edit();
				DM->DocTIDNOM_REALRESTT->AsString=SpisokNom->DM->ElementIDNOM->AsString;
                DM->DocTNAMENOM->AsString=SpisokNom->DM->ElementNAMENOM->AsString;
                DM->DocTTNOM->AsInteger=SpisokNom->DM->ElementTNOM->AsInteger;
                DM->DocTKOL_REALRESTT->AsFloat=1;

				DM->DocTIDED_REALRESTT->AsInt64=glStrToInt64(SpisokNom->DM->ElementIDOSNEDNOM->AsString);
                DM->DocTNAMEED->AsString=SpisokNom->DM->OsnEdNAMEED->AsString;
                DM->DocTKF_REALRESTT->AsFloat=SpisokNom->DM->OsnEdKFED->AsFloat;



                DM->DocTZNACH_PRICE->AsFloat=SpisokNom->DM->ElementZNACH_PRICE->AsFloat;
                DM->DocTPRICE_REALRESTT->AsFloat=DM->DocTZNACH_PRICE->AsFloat
                                                *DM->DocTKF_REALRESTT->AsFloat;

                DM->DocT->Post();
                }
        SpisokNom=0;
        }

if (EditRekvisit==ViborEdinica)
        {
        if(Prosmotr==true) return;
        if (SpisokEd->OutReady==true)
                {
                DM->DocT->Edit();
				DM->DocTIDED_REALRESTT->AsInt64=SpisokEd->DM->ElementIDED->AsInt64;
                DM->DocTNAMEED->AsString=SpisokEd->DM->ElementNAMEED->AsString;
				DM->DocTKF_REALRESTT->AsFloat=SpisokEd->DM->ElementKFED->AsFloat;
                
                DM->DocTPRICE_REALRESTT->AsFloat=DM->DocTZNACH_PRICE->AsFloat
                                                *DM->DocTKF_REALRESTT->AsFloat;

                DM->DocT->Post();
                }
        SpisokEd=0;
        }

if (EditRekvisit==ViborFirm)
        {
        if(Prosmotr==true) return;
        if (SpisokFirm->OutReady==true)
                {
                DM->DocAll->Edit();
				DM->DocAllIDFIRMDOC->AsInt64=SpisokFirm->DM->ElementIDFIRM->AsInt64;
                EditFirm->Text=SpisokFirm->DM->ElementNAMEFIRM->AsString;
                DM->DocAll->Post();
                }
        SpisokFirm=0;
        }

if (EditRekvisit==ViborSklad)
        {
        if(Prosmotr==true) return;
        if (SpisokSklad->OutReady==true)
                {
                DM->DocAll->Edit();
				DM->DocAllIDSKLDOC->AsInt64=SpisokSklad->DM->ElementIDSKLAD->AsInt64;
                EditSklad->Text=SpisokSklad->DM->ElementNAMESKLAD->AsString;
                DM->DocAll->Post();
                }
        SpisokSklad=0;
        }

if (EditRekvisit==ViborKlient)
        {
        if(Prosmotr==true) return;
        if (SpisokKlient->OutReady==true)
                {
                DM->DocAll->Edit();
				DM->DocAllIDKLDOC->AsInt64=SpisokKlient->DM->ElementIDKLIENT->AsInt64;
                EditKlient->Text=SpisokKlient->DM->ElementNAMEKLIENT->AsString;
                DM->DocAll->Post();
                }
        SpisokKlient=0;
        }

if (EditRekvisit==ViborInfBase)
        {
        if (FormaSpiskaSprInfBase->OutReady==true)
                {
                DM->DocAll->Edit();
				DM->DocAllIDBASE_GALLDOC->AsInt64=FormaSpiskaSprInfBase->DM->TableID_SINFBASE_OBMEN->AsInt64;
                DM->DocAllNAME_SINFBASE_OBMEN->AsString=FormaSpiskaSprInfBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                DM->DocAll->Post();
                }
        FormaSpiskaSprInfBase=0;
        }
ActionOperation=aoNO;
EditRekvisit=NO;
IdDochForm=NULL;

}

//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRest::DateDocChange(TObject *Sender)
{
if(Prosmotr==true) return;
DM->DocAll->Edit();
DM->DocAllPOSDOC->AsDateTime=DateDoc->DateTime;
DM->DocAll->Post();
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRealRest::DBGrid1EditButtonClick(TObject *Sender)
{
if(Prosmotr==true) return;
if (DBGrid1->SelectedField->DisplayName=="NAMENOM")
        {
        OpenFormSpiskaSprNom();
        EditRekvisit=ViborTovar;
        }

if (DBGrid1->SelectedField->DisplayName=="NAMEED")
        {
        OpenFormSpiskaSprEd();
        EditRekvisit=ViborEdinica;
        }
}
//---------------------------------------------------------------------------




void __fastcall TFormaDocRealRest::ButtonProvClick(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{

				}
		else
			{
			ShowMessage("Ошибка при проведении документа: "+DM->TextError);
			}
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRest::ButtonOKClick(TObject *Sender)
{
if(Prosmotr==true) return;
if (DM->SaveDoc()==true)
		{
		if (DM->DvRegDoc()==true)
				{
				Close();
				}
		else
			{
			ShowMessage("Ошибка при проведении документа: "+DM->TextError);
			}
		}
else
	{
	ShowMessage("Ошибка при записи документа: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRest::FormResize(TObject *Sender)
{
int TecSumWidth=DBGrid1->Width;
int SumWidth=728;
DBGrid1->Columns->Items[0]->Width=34*TecSumWidth/SumWidth;
DBGrid1->Columns->Items[1]->Width=292*TecSumWidth/SumWidth;
DBGrid1->Columns->Items[2]->Width=52*TecSumWidth/SumWidth;
DBGrid1->Columns->Items[3]->Width=81*TecSumWidth/SumWidth;
DBGrid1->Columns->Items[4]->Width=65*TecSumWidth/SumWidth;
DBGrid1->Columns->Items[5]->Width=77*TecSumWidth/SumWidth;
DBGrid1->Columns->Items[6]->Width=83*TecSumWidth/SumWidth;
}
//---------------------------------------------------------------------------
void TFormaDocRealRest::OpenFormSpiskaSprFirm(void)
{
if(Prosmotr==true) return;
if (IdDochForm==NULL)
        {
        SpisokFirm=new TFormaSpiskaSprFirm(Application);
        if (!SpisokFirm) return;
        SpisokFirm->IdRodForm=Handle;
        SpisokFirm->Vibor=true;
        IdDochForm=SpisokFirm->Handle;
        EditRekvisit=ViborFirm;
        SpisokFirm->FOnCloseForm=EndEdit;
        SpisokFirm->Show();
        }

}
//---------------------------------------------------------------------------
void TFormaDocRealRest::OpenFormSpiskaSprSklad(void)
{
if(Prosmotr==true) return;
if (IdDochForm==NULL)
        {
        SpisokSklad=new TFormaSpiskaSprSklad(Application);
        if (!SpisokSklad) return;
        SpisokSklad->IdRodForm=Handle;
        SpisokSklad->Vibor=true;
        IdDochForm=SpisokSklad->Handle;
        EditRekvisit=ViborSklad;
        SpisokSklad->FOnCloseForm=EndEdit;
        SpisokSklad->Show();
        }

}
//--------------------------------------------------------------------------
void TFormaDocRealRest::OpenFormSpiskaSprKlient(void)
{
if(Prosmotr==true) return;
        SpisokKlient=new TFormaSpiskaSprKlient(Application);
        if (!SpisokKlient) return;
        SpisokKlient->IdRodForm=Handle;
        SpisokKlient->Vibor=true;
        IdDochForm=SpisokKlient->Handle;
        EditRekvisit=ViborKlient;
        SpisokKlient->FOnCloseForm=EndEdit;
        SpisokKlient->Show();

}

//--------------------------------------------------------------------------
void __fastcall TFormaDocRealRest::ButtonEditFirmClick(TObject *Sender)
{
OpenFormSpiskaSprFirm();          
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRest::ButtonEditSkladClick(TObject *Sender)
{
OpenFormSpiskaSprSklad();
}
//---------------------------------------------------------------------------


void __fastcall TFormaDocRealRest::ButtonEditKlientClick(TObject *Sender)
{
OpenFormSpiskaSprKlient();
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocRealRest::ButtonPrintDocClick(TObject *Sender)
{
OpenPrintForm();
}
//---------------------------------------------------------------------------
void TFormaDocRealRest::OpenPrintForm(void)
{
TSheetEditor  *PrintForm=new TSheetEditor(Application);
if (!PrintForm) return;

numRow=1;
numCol=1;
porNumStr=1;


//шапка
PrintForm->SS->BeginUpdate();
OutputZagolovokReport(PrintForm);

//таблица

DM->DocT->First();
while(!DM->DocT->Eof)
        {

        OutputString(PrintForm);numRow++; porNumStr++;

        DM->DocT->Next();
        }

OutputPodavalReport(PrintForm);
PrintForm->SS->EndUpdate();
PrintForm->Show();
}
//---------------------------------------------------------------------------
void TFormaDocRealRest::OutputZagolovokReport(TSheetEditor *prForm)
{
prForm->SS->DefaultStyle->Font->Size=10;
prForm->SS->DefaultStyle->Font->Name="Arial";
prForm->SS->RowsAutoHeight=true;
        TcxSSHeader *cHeader;

        cHeader = prForm->SS->ActiveSheet->Cols;
        cHeader->Size[0] = 10;
        cHeader->Size[1] = 10;
        cHeader->Size[2] = 40;
        cHeader->Size[3] = 300;
        cHeader->Size[4] = 60;
        cHeader->Size[5] = 80;
        cHeader->Size[6] = 60;
        cHeader->Size[7] = 70;
		cHeader->Size[8] = 80;


TcxSSCellObject *cell;
numRow=1;
numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text=DM->FirmaFNAMEFIRM->AsString
        +" ИНН "+DM->FirmaINNFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Адрес: "+DM->FirmaPADRFIRM->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Склад: "+DM->SkladNAMESKLAD->AsString;
delete cell;
numRow++; numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(3, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Акт реализации №"+DM->DocAllNUMDOC->AsString+" от "
                +DateToStr(DM->DocAllPOSDOC->AsDateTime);
delete cell;
numRow++; numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Покупатель: "+DM->KlientFNAME->AsString;
delete cell;
numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Адрес: "+DM->KlientADRKLIENT->AsString;
delete cell;
numRow++; numRow++;

//заголовок таблицы
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="№";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Text="Наименование";
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Кол-во";
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Единица";
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="К";
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Цена";
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text="Сумма";
delete cell;
numCol++;

numRow++;
}
//------------------------------------------------------------------------------
void TFormaDocRealRest::OutputString(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numCol=2;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=IntToStr(porNumStr);
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=DM->DocTNAMENOM->AsString;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=DM->DocTKOL_REALRESTT->AsString;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=DM->DocTNAMEED->AsString;
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=FloatToStrF(DM->DocTKF_REALRESTT->AsFloat,ffFixed,10,3);
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=FloatToStrF(DM->DocTPRICE_REALRESTT->AsFloat,ffFixed,10,2);
delete cell;
numCol++;

cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Borders->Edges [eLeft]->Style=lsThin;
cell->Style->Borders->Edges [eRight]->Style=lsThin;
cell->Style->Borders->Edges [eTop]->Style=lsThin;
cell->Style->Borders->Edges [eBottom]->Style=lsThin;
cell->Text=FloatToStrF(DM->DocTSUM_REALRESTT->AsFloat,ffFixed,10,2);
delete cell;
numCol++;

}


//------------------------------------------------------------------------------
void TFormaDocRealRest::OutputPodavalReport(TSheetEditor *prForm)
{
TcxSSCellObject *cell;
numRow++;
numCol=2;
cell = prForm->SS->ActiveSheet->GetCellObject(numCol, numRow);
cell->Style->Font->Size = 16;
cell->Style->Font->Style = TFontStyles() << fsBold;
cell->Text="Всего: "+FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffFixed,10,2);
delete cell;
numRow++;numRow++;

cell = prForm->SS->ActiveSheet->GetCellObject(2, numRow);
cell->Text="Продавец  __________________________ ";
delete cell;

cell = prForm->SS->ActiveSheet->GetCellObject(5, numRow);
cell->Text="Покупатель __________________________ ";
delete cell;


}
//---------------------------------------------------------------

void __fastcall TFormaDocRealRest::BitBtnDateTimeClick(TObject *Sender)
{
if(DateDoc->Kind==dtkTime)
        {
        DateDoc->Kind=dtkDate;
        }
else
        {
        DateDoc->Kind=dtkTime;
        }
}
//---------------------------------------------------------------------------

void TFormaDocRealRest::OpenFormSpiskaSprInfBase(void)
{
if (Prosmotr==true) return;
if (DM->DocAllIDBASE_GALLDOC->ReadOnly==true) return;
if (IdDochForm==NULL)
        {
        FormaSpiskaSprInfBase=new TFormaSpiskaSprInfBase(Application);
        if (!FormaSpiskaSprInfBase) return;
        FormaSpiskaSprInfBase->FOnCloseForm=EndEdit;
        FormaSpiskaSprInfBase->IdRodForm=Handle;
        FormaSpiskaSprInfBase->Vibor=true;
        IdDochForm=FormaSpiskaSprInfBase->Handle;
        EditRekvisit=ViborInfBase;
        FormaSpiskaSprInfBase->DM->OpenTable();
        FormaSpiskaSprInfBase->Show();
        }
}
//---------------------------------------------------------------------
void __fastcall TFormaDocRealRest::ViborBaseButtonClick(TObject *Sender)
{
OpenFormSpiskaSprInfBase();        
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRest::TypePriceComboBoxChange(TObject *Sender)
{
 if (Prosmotr==true)
        {
        UpdateForm();
         return;
        }

 if ( TypePriceComboBox->ItemIndex!=0)
		{
        DMSprTypePrice->Table->First();
		DMSprTypePrice->Table->MoveBy(TypePriceComboBox->ItemIndex-1);
		DM->Doc->Edit();
		DM->DocIDTPRICE_REALREST->AsInt64=DMSprTypePrice->TableID_TPRICE->AsInt64;
		DM->Doc->Post();
		}
else
	{
	ShowMessage("Тип цен должен быть задан обязательно!");
	UpdateForm();
	return;
	}

//проверим есть ли строки
if(DM->DocT->RecordCount>0)
        {
        String V="В табличной части документа есть строки. Пересчитать цены?";
        String Z="Пересчитать цены?";
        if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
                {
                TDMSprPrice * DMSprPrice=new TDMSprPrice(Application);
                DM->DocT->First();
                while(!DM->DocT->Eof)
                        {
                        DM->DocT->Edit();
						DMSprPrice->FindElement( DM->DocIDTPRICE_REALREST->AsInt64,
											 DM->DocTIDNOM_REALRESTT->AsInt64);
						DM->DocTPRICE_REALRESTT->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat*
                                                        DM->DocTKF_REALRESTT->AsFloat;
                        DM->DocT->Post();
                        DM->DocT->Next();
                        }
                delete DMSprPrice;
                }
        }	
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRest::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("Doc/DocRealRest");
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRest::DBGrid1TitleClick(TColumn *Column)
{
	TStringList *s=new TStringList();
	s->Add(Column->FieldName);
	bool  b[1]={true};
	DM->DocT->DoSortEx(s, b,100);
	delete s;	
}
//---------------------------------------------------------------------------

