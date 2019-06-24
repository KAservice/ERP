//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//----------------------------------------------------------------------------
#include "UFormaImportOstVs.h"
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
__fastcall TFormaImportOstVs::TFormaImportOstVs(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportOstVs::FormCreate(TObject *Sender)
{

FileNamecxButtonEdit->Text="";
InfBase->Active=true;

}
//---------------------------------------------------------------------------
void __fastcall TFormaImportOstVs::FormClose(TObject *Sender,
      TCloseAction &Action)
{
InfBase->Active=false;
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaImportOstVs::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaImportOstVs::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportOstVs::FileNamecxButtonEditPropertiesButtonClick(
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
void TFormaImportOstVs::UpdateSetup(void)
{

}
//----------------------------------------------------------------------------
void TFormaImportOstVs::SaveSetup(void)
{

}
//----------------------------------------------------------------------------


void __fastcall TFormaImportOstVs::cxButtonImportClick(TObject *Sender)
{
if (StartStringcxSpinEdit->Text=="" ||
			StartStringcxSpinEdit->Text=="0")
	{
	ShowMessage("Необходимо задать настройки импорта!");
	return;
	}


int number_string_excel=StrToInt(StartStringcxSpinEdit->Text);
int number_con_string_excel=StrToInt(ConStringcxSpinEdit->Text);

int num_name_klient=StrToInt(NameKlientcxSpinEdit->Text);
AnsiString name_klient="";

int num_prihod=StrToInt(PrihodcxSpinEdit->Text);
AnsiString prihod="";

int num_rashod=StrToInt(RashodcxSpinEdit->Text);
AnsiString rashod="";

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
DocAllTDOC->AsString="KORRVS";
DocAllPOSDOC->AsDateTime=Now();
DocAllIDUSERDOC->AsInt64=glDM->UserDataSetID_USER->AsInt64;
if (InfBaseID_SINFBASE_OBMEN->AsInt64!=0)
	{
	DocAllIDBASE_GALLDOC->AsInt64=InfBaseID_SINFBASE_OBMEN->AsInt64;
	}
DocAll->Post();

Doc->Insert();
DocIDDOC_DKORRVS->AsInt64=DocAllIDDOC->AsInt64;
if(DocAllIDBASE_GALLDOC->AsInt64!=0)
	{
	DocIDBASE_DKORRVS->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
	}
Doc->Post();

while(number_string_excel<=number_con_string_excel)
	{
	try
		{

		//наименование
		if (num_name_klient!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_klient-1,number_string_excel-1);
			name_klient=Trim(cell->Text);
			delete cell;
			}
		else {name_klient="";}


		if (num_prihod!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_prihod-1,number_string_excel-1);
			prihod=Trim(cell->Text);
			delete cell;
			}
		else {prihod="";}


		if (num_rashod!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_rashod-1,number_string_excel-1);
			rashod=Trim(cell->Text);
			delete cell;
			}
		else {rashod="";}



		__int64 id_klient=0;
		if (name_klient!="")
			{
			QueryKlient->Close();
			QueryKlient->ParamByName("PARAM_NAME")->AsString=name_klient;
			QueryKlient->ExecQuery();
			id_klient=QueryKlient->FieldByName("IDKLIENT")->AsInt64;
			QueryKlient->Close();
			}


		if(id_klient!=0)
			{
			DocT->Insert();
			DocTIDDOC_DKORRVST->AsInt64=DocAllIDDOC->AsInt64;
			if(DocAllIDBASE_GALLDOC->AsInt64!=0)
				{
				DocTIDBASE_DKORRVST->AsInt64=DocAllIDBASE_GALLDOC->AsInt64;
				}
			DocTIDKLIENT_DKORRVST->AsInt64=id_klient;
			try {DocTPRIHOD_DKORRVST->AsFloat=StrToFloat(prihod);} catch(...){}
			try {DocTRASHOD_DKORRVST->AsFloat=StrToFloat(rashod);} catch(...){}

			DocT->Post();
			}
		else
			{
			ShowMessage("Не найден клиент "+name_klient);
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


