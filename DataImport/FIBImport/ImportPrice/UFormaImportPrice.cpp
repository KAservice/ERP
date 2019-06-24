//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//----------------------------------------------------------------------------
#include "UFormaImportPrice.h"
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
__fastcall TFormaImportPrice::TFormaImportPrice(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportPrice::FormCreate(TObject *Sender)
{

FileNamecxButtonEdit->Text="";

}
//---------------------------------------------------------------------------
void __fastcall TFormaImportPrice::FormClose(TObject *Sender,
      TCloseAction &Action)
{

Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaImportPrice::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaImportPrice::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportPrice::FileNamecxButtonEditPropertiesButtonClick(
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
void TFormaImportPrice::UpdateSetup(void)
{

}
//----------------------------------------------------------------------------
void TFormaImportPrice::SaveSetup(void)
{

}
//----------------------------------------------------------------------------


void __fastcall TFormaImportPrice::cxButtonImportClick(TObject *Sender)
{
if (StartStringcxSpinEdit->Text=="" ||
			StartStringcxSpinEdit->Text=="0")
	{
	ShowMessage("Необходимо задать настройки импорта!");
	return;
	}


int number_string_excel=StrToInt(StartStringcxSpinEdit->Text);
int number_con_string_excel=StrToInt(ConStringcxSpinEdit->Text);

//наименование  номенклатуры
int num_name_nom=StrToInt(NameNomcxSpinEdit->Text);
AnsiString name_nom="";


int num_name_type_price=StrToInt(NameTypePricecxSpinEdit->Text);
AnsiString name_type_price="";

//наименование  удиницы
int num_name_ed=StrToInt(NameEdcxSpinEdit->Text);
AnsiString name_ed="";


int num_price=StrToInt(PricecxSpinEdit->Text);
AnsiString price="";


TcxSSCellObject *cell;
bool error=false;

while(number_string_excel<=number_con_string_excel)
	{
	try
		{
		//наименование номенклатуры
		if (num_name_nom!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_nom-1,number_string_excel-1);
			name_nom=Trim(cell->Text);
			delete cell;
			}
		else {name_nom="";}

		if (num_name_type_price!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_type_price-1,number_string_excel-1);
			name_type_price=Trim(cell->Text);
			delete cell;
			}
		else {name_type_price="";}

		//наименование единицы
		if (num_name_ed!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_ed-1,number_string_excel-1);
			name_ed=Trim(cell->Text);
			delete cell;
			}
		else {name_ed="";}


		if (num_price!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_price-1,number_string_excel-1);
			price=Trim(cell->Text);
			delete cell;
			}
		else {price="";}



		//найдем номенклатуру
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

		__int64	id_type_price=0;
		if (name_type_price!="")
			{
			QueryTypePrice->Close();
			QueryTypePrice->ParamByName("PARAM_NAME")->AsString=name_type_price;
			QueryTypePrice->ExecQuery();
			id_type_price=QueryTypePrice->FieldByName("ID_TPRICE")->AsInt64;
			QueryTypePrice->Close();
			}

		__int64	id_ed=0;
		if (name_ed!="")
			{
			QueryEd->Close();
			QueryEd->ParamByName("PARAM_NAME")->AsString=name_ed;
			QueryEd->ExecQuery();
			id_ed=QueryEd->FieldByName("IDED")->AsInt64;
			QueryEd->Close();
			}

		//вставляем цену	
		if(id_nom!=0 && id_type_price!=0)
			{
			DataSet->Close();
			DataSet->Active=true;
			DataSet->Insert();
			DataSetIDNOM_PRICE->AsInt64=id_nom;
			DataSetIDTYPE_PRICE->AsInt64=id_type_price;

			try {DataSetZNACH_PRICE->AsFloat=StrToFloat(price);} catch(...){}

			if (id_ed==0)
				{
				if (id_bas_ed!=0)
					{
					DataSetIDED_SPRICE->AsInt64=id_bas_ed;
					}
				}
			else
				{
				DataSetIDED_SPRICE->AsInt64=id_ed;
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

