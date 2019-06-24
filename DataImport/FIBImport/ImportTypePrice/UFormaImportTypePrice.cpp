//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//----------------------------------------------------------------------------
#include "UFormaImportTypePrice.h"
#include "UDataModuleMain.h"
#include "math.h"
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
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaImportTypePrice::TFormaImportTypePrice(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportTypePrice::FormCreate(TObject *Sender)
{

FileNamecxButtonEdit->Text="";

}
//---------------------------------------------------------------------------
void __fastcall TFormaImportTypePrice::FormClose(TObject *Sender,
      TCloseAction &Action)
{

Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaImportTypePrice::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaImportTypePrice::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportTypePrice::FileNamecxButtonEditPropertiesButtonClick(
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
void TFormaImportTypePrice::UpdateSetup(void)
{

}
//----------------------------------------------------------------------------
void TFormaImportTypePrice::SaveSetup(void)
{

}
//----------------------------------------------------------------------------


void __fastcall TFormaImportTypePrice::cxButtonImportClick(TObject *Sender)
{
if (StartStringcxSpinEdit->Text=="" ||
			StartStringcxSpinEdit->Text=="0")
	{
	ShowMessage("Необходимо задать настройки импорта!");
	return;
	}


int number_string_excel=StrToInt(StartStringcxSpinEdit->Text);
int number_con_string_excel=StrToInt(ConStringcxSpinEdit->Text);

//наименование  типа цен
int num_name_type_price=StrToInt(NameTypePricecxSpinEdit->Text);
AnsiString name_type_price="";



TcxSSCellObject *cell;
bool error=false;

while(number_string_excel<=number_con_string_excel)
	{
	try
		{
		//наименование номенклатуры
		if (num_name_type_price!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_type_price-1,number_string_excel-1);
			name_type_price=Trim(cell->Text);
			delete cell;
			}
		else {name_type_price="";}


		//найдем тип цен
		__int64 id_type_price=0;
		if (name_type_price!="")
			{
			QueryTypePrice->Close();
			QueryTypePrice->ParamByName("PARAM_NAME")->AsString=name_type_price;
			QueryTypePrice->ExecQuery();
			id_type_price=QueryTypePrice->FieldByName("ID_TPRICE")->AsInt64;
			QueryTypePrice->Close();
			}
			
		//вставляем тип цен
		if(id_type_price==0)
			{
			DataSet->Close();
			DataSet->Active=true;
			DataSet->Insert();
			DataSetNAME_TPRICE->AsString=name_type_price;


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
			}


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

