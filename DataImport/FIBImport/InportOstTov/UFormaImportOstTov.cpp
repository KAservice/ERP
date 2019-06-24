//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//----------------------------------------------------------------------------
#include "UFormaImportOstTov.h"
#include "UDataModuleMain.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxPC"
#pragma link "cxSSheet"
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
#pragma link "cxGridBandedTableView"
#pragma link "cxCalc"
#pragma link "cxCheckBox"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma link "cxGroupBox"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

extern TDataModuleMain * glDM;
//---------------------------------------------------------------------------
__fastcall TFormaImportOstTov::TFormaImportOstTov(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportOstTov::FormCreate(TObject *Sender)
{

FileNamecxButtonEdit->Text="";
InfBase->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportOstTov::FormClose(TObject *Sender,
      TCloseAction &Action)
{
InfBase->Active=false;
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaImportOstTov::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaImportOstTov::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportOstTov::FileNamecxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
  if (OpenDialog1->Execute())
  {
    //NewSheet(OpenDialog->FileName);
	try {
		FileNamecxButtonEdit->Text=OpenDialog1->FileName;
		cxSpreadSheet1->LoadFromFile(OpenDialog1->FileName);
		cxSpreadSheet1->R1C1ReferenceStyle=true;
		}
	catch (Exception &err)
	  {
        Application->ShowException(&err);
		//ActiveMDIChild->Close();
	  }
  }	
}

//---------------------------------------------------------------------------
void TFormaImportOstTov::UpdateSetup(void)
{

}
//----------------------------------------------------------------------------
void TFormaImportOstTov::SaveSetup(void)
{

}
//----------------------------------------------------------------------------


void __fastcall TFormaImportOstTov::cxButtonImportClick(TObject *Sender)
{
if (StartStringcxSpinEdit->Text=="" ||
			StartStringcxSpinEdit->Text=="0")
	{
	ShowMessage("Необходимо задать настройки импорта!");
	return;
	}


int number_string_excel=StrToInt(StartStringcxSpinEdit->Text);
int number_con_string_excel=StrToInt(ConStringcxSpinEdit->Text);

//наименование
int num_name_nom=StrToInt(NameNomcxSpinEdit->Text);
AnsiString name_nom="";

int num_ostatok=StrToInt(OstatokcxSpinEdit->Text);
AnsiString ostatok="";

int num_name_ed=StrToInt(NameEdcxSpinEdit->Text);
AnsiString name_ed="";

int num_sebest=StrToInt(SebestcxSpinEdit->Text);
AnsiString sebest="";

TcxSSCellObject *cell;
bool error=false;


DocAll->Close();
Doc->Close();
DocT->Close();

DocAll->Open();
Doc->Open();
DocT->Open();

InfBase->First();
InfBase->MoveBy(NameInfBasecxLookupComboBox->ItemIndex);

DocAll->Insert();
DocAllTDOC->AsString="OSN";
DocAllPOSDOC->AsDateTime=Now();
DocAllIDUSERDOC->AsInt64=glDM->UserDataSetID_USER->AsInt64;
if(InfBaseID_SINFBASE_OBMEN->AsInt64!=0)
	{
	DocAllIDBASE_GALLDOC->AsInt64=InfBaseID_SINFBASE_OBMEN->AsInt64;
	}
DocAll->Post();

Doc->Insert();
DocIDDOCOSN->AsInt64=DocAllIDDOC->AsInt64;
if(DocAllIDBASE_GALLDOC->AsInt64!=0)
	{
	DocIDBASE_DOSN->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
	}
Doc->Post();

while(number_string_excel<=number_con_string_excel)
	{
	try
		{

		//наименование
		if (num_name_nom!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_nom-1,number_string_excel-1);
			name_nom=Trim(cell->Text);
			delete cell;
			}
		else {name_nom="";}


		if (num_ostatok!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_ostatok-1,number_string_excel-1);
			ostatok=Trim(cell->Text);
			delete cell;
			}
		else {ostatok="";}


		if (num_name_ed!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_ed-1,number_string_excel-1);
			name_ed=Trim(cell->Text);
			delete cell;
			}
		else {name_ed="";}

		if (num_sebest!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_sebest-1,number_string_excel-1);
			sebest=Trim(cell->Text);
			delete cell;
			}
		else {sebest="";}


		__int64 id_nom=0;
		__int64 id_bas_ed=0;
		if (name_nom!="")
			{
			QueryNom->Close();
			QueryNom->ParamByName("PARAM_NAME")->AsString=name_nom;
			QueryNom->ExecQuery();
			id_nom=QueryNom->FieldByName("IDNOM")->AsInt64;
			id_bas_ed=QueryNom->FieldByName("IDBASEDNOM")->AsInt64;
			QueryNom->Close();
			}

		__int64 id_ed=0;
		double kf=0;
		if (name_ed!="")
			{
			QueryEd->Close();
			QueryEd->ParamByName("PARAM_NAME")->AsString=name_nom;
            QueryEd->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
			QueryEd->ExecQuery();
			id_ed=QueryEd->FieldByName("IDED")->AsInt64;
			kf=QueryEd->FieldByName("KFED")->AsFloat;
			QueryEd->Close();
			}

			
		if(id_nom!=0)
			{
			DocT->Insert();
			DocTIDDOCOSNT->AsInt64=DocAllIDDOC->AsInt64;
			if(DocAllIDBASE_GALLDOC->AsInt64!=0)
				{
				DocTIDBASE_DOSNT->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
				}
			DocTIDNOMOSNT->AsInt64=id_nom;
			if (id_ed!=0)
				{
				DocTIDEDOSNT->AsInt64=id_ed;
				try {DocTKFOSNT->AsFloat=kf;} catch(...){}
				}
			else
				{
				if (id_bas_ed!=0)
					{
					DocTIDEDOSNT->AsInt64=id_bas_ed;
					}
                DocTKFOSNT->AsFloat=1;
				}

			try {DocTKOLOSNT->AsFloat=StrToFloat(ostatok);} catch(...){}

			if (sebest!="")
				{
				try {DocTPRICEOSNT->AsFloat=StrToFloat(sebest)/DocTKOLOSNT->AsFloat;} catch(...){}
				try {DocTSUMOSNT->AsFloat=StrToFloat(sebest);} catch(...){}
				}

			DocT->Post();
			}
		else
			{
			ShowMessage("Не найден товар "+name_nom);
			}



	}
catch(Exception &exception)
	{
	error=true;
	ShowMessage("Ошибка в строке:"+IntToStr(number_string_excel)+" "+exception.Message);
	}
	number_string_excel++;
	}




			try
				{
				TrUpdate->Commit();
				}
			catch(Exception &exception)
				{
				TrUpdate->Rollback();
				ShowMessage("Ошибка в строке:"+IntToStr(number_string_excel)+" "+exception.Message);
				}

DocAll->Active=false;
Doc->Active=false;
DocT->Active=false;

}
//-------------------------------------------------------------------------


