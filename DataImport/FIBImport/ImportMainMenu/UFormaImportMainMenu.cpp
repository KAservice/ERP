//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//----------------------------------------------------------------------------
#include "UFormaImportMainMenu.h"
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
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma link "cxLabel"
#pragma link "cxImageComboBox"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaImportMainMenu::TFormaImportMainMenu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportMainMenu::FormCreate(TObject *Sender)
{

FileNamecxButtonEdit->Text="";
SpisokGrpUser->Active=true;

}
//---------------------------------------------------------------------------
void __fastcall TFormaImportMainMenu::FormClose(TObject *Sender,
      TCloseAction &Action)
{
SpisokGrpUser->Active=false;
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaImportMainMenu::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaImportMainMenu::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportMainMenu::FileNamecxButtonEditPropertiesButtonClick(
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
void TFormaImportMainMenu::UpdateSetup(void)
{

}
//----------------------------------------------------------------------------
void TFormaImportMainMenu::SaveSetup(void)
{

}
//----------------------------------------------------------------------------


void __fastcall TFormaImportMainMenu::cxButtonImportClick(TObject *Sender)
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

int num_name_grp=StrToInt(NameGrpcxSpinEdit->Text);
AnsiString name_grp="";

int num_name_menu=StrToInt(NameMenucxSpinEdit->Text);
AnsiString name_menu="";

int num_num_module=StrToInt(NumModulecxSpinEdit->Text);
AnsiString num_module="";

TcxSSCellObject *cell;
bool error=false;

while(number_string_excel<=number_con_string_excel)
	{
try
	{
	//родительская группа
	if (num_name_menu!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_menu-1,number_string_excel-1);
		name_menu=Trim(cell->Text);
		delete cell;
		}
	else {name_menu="";}

	if (num_name_grp!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_grp-1,number_string_excel-1);
		name_grp=Trim(cell->Text);
		delete cell;
		}
	else {name_grp="";}

	if (num_num_module!=0)
		{
		cell = cxSpreadSheet1->Sheet->GetCellObject(num_num_module-1,number_string_excel-1);
		num_module=Trim(cell->Text);
		delete cell;
		}
	else {num_module="";}

	//попытаемся найти такой товар в базе
	//вставляем группу в базу
	if(name_grp!="")
		{
		DataSet->Close();
		DataSet->Active=true;
		DataSet->Insert();
		DataSetNAME_INTERF_MAINMENU->AsString=name_menu;
		DataSetMODUL_INTERF_MAINMENU->AsInteger=StrToInt(num_module);
		DataSetAPPLICATION_INTERF_MAINMENU->AsInteger=ApplicationcxImageComboBox->EditValue;
		DataSetIDGRPUSER_INTERF_MAINMENU->AsInt64=NameGrpcxLookupComboBox->EditValue;

		if (name_grp=="")
			{//корневая группа
			}
		else
			{
			QueryOwnerGrp->Close();
			QueryOwnerGrp->ParamByName("PARAM_NAME")->AsString=name_grp;
			QueryOwnerGrp->ExecQuery();
			if (QueryOwnerGrp->FieldByName("ID_INTERF_MAINMENU_GRP")->AsInt64!=0)
				{
				DataSetIDGRP_INTERF_MAINMENU->AsInt64=QueryOwnerGrp->FieldByName("ID_INTERF_MAINMENU_GRP")->AsInt64;
				}
			}
		try
			{
			DataSet->Post();
			TrUpdate->Commit();
			}
		catch(Exception &exception)
			{
			TrUpdate->Rollback();
			ShowMessage("Ошибка в строке:"+IntToStr(number_string_excel)+" "+exception.Message);
			}
		DataSet->Active=false;
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


