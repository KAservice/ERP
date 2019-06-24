//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//----------------------------------------------------------------------------
#include "UFormaImportGrpKlient.h"
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
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaImportGrpKlient::TFormaImportGrpKlient(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportGrpKlient::FormCreate(TObject *Sender)
{

FileNamecxButtonEdit->Text="";

}
//---------------------------------------------------------------------------
void __fastcall TFormaImportGrpKlient::FormClose(TObject *Sender,
      TCloseAction &Action)
{

Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaImportGrpKlient::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaImportGrpKlient::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportGrpKlient::FileNamecxButtonEditPropertiesButtonClick(
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
void TFormaImportGrpKlient::UpdateSetup(void)
{

}
//----------------------------------------------------------------------------
void TFormaImportGrpKlient::SaveSetup(void)
{

}
//----------------------------------------------------------------------------


void __fastcall TFormaImportGrpKlient::cxButtonImportClick(TObject *Sender)
{
if (StartStringcxSpinEdit->Text=="" ||
			StartStringcxSpinEdit->Text=="0")
	{
	ShowMessage("Необходимо задать настройки импорта!");
	return;
	}


int number_string_excel=StrToInt(StartStringcxSpinEdit->Text);
int number_con_string_excel=StrToInt(ConStringcxSpinEdit->Text);

int number_string_table=0;
//группа
int num_name_grp=StrToInt(NameGrpcxSpinEdit->Text);
AnsiString name_grp="";
//родительская группа
int num_name_owner_grp=StrToInt(NameOwnerGrpcxSpinEdit->Text);
AnsiString name_owner_grp="";


TcxSSCellObject *cell;
bool error=false;

while(number_string_excel<=number_con_string_excel)
	{
try
	{
	//родительская группа
	if (num_name_owner_grp!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_owner_grp-1,number_string_excel-1);
		name_owner_grp=Trim(cell->Text);
		delete cell;
		}
	else {name_owner_grp="";}

	//группа номенклатуры
	if (num_name_grp!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_grp-1,number_string_excel-1);
		name_grp=Trim(cell->Text);
		delete cell;
		}
	else {name_grp="";}

	//попытаемся найти такой товар в базе
	//вставляем группу в базу
	if(name_grp!="")
		{
		DataSetGrp->Close();
		DataSetGrp->Active=true;
		DataSetGrp->Insert();
		DataSetGrpNAMEGRPKL->AsString=name_grp;

		if (name_owner_grp=="")
			{//корневая группа
			}
		else
			{
			QueryOwnerGrp->Close();
			QueryOwnerGrp->ParamByName("PARAM_NAME")->AsString=name_owner_grp;
			QueryOwnerGrp->ExecQuery();
			if (QueryOwnerGrp->FieldByName("IDGRPKL")->AsInt64!=0)
				{
				DataSetGrpGRPKL->AsInt64=QueryOwnerGrp->FieldByName("IDGRPKL")->AsInt64;
				}
			}
		try
			{
			DataSetGrp->Post();
			TrUpdate->Commit();
			}
		catch(Exception &exception)
			{
			TrUpdate->Rollback();
			ShowMessage("Ошибка в строке:"+IntToStr(number_string_excel)+" "+exception.Message);
			}
		DataSetGrp->Active=false;
		QueryOwnerGrp->Close();
		}


	number_string_table++;
	number_string_excel++;
	}
catch(Exception &exception)
	{
	error=true;
	LabelError->Caption="Ошибка в строке:"+IntToStr(number_string_excel)+" "+exception.Message;
	}

    }


}
//-------------------------------------------------------------------------


