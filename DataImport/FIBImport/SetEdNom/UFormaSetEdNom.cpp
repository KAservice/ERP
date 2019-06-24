//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//----------------------------------------------------------------------------
#include "UFormaSetEdNom.h"
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
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaSetEdNom::TFormaSetEdNom(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaSetEdNom::FormCreate(TObject *Sender)
{

FileNamecxButtonEdit->Text="";

}
//---------------------------------------------------------------------------
void __fastcall TFormaSetEdNom::FormClose(TObject *Sender,
      TCloseAction &Action)
{

Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaSetEdNom::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaSetEdNom::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaSetEdNom::FileNamecxButtonEditPropertiesButtonClick(
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
void TFormaSetEdNom::UpdateSetup(void)
{

}
//----------------------------------------------------------------------------
void TFormaSetEdNom::SaveSetup(void)
{

}
//----------------------------------------------------------------------------


void __fastcall TFormaSetEdNom::cxButtonImportClick(TObject *Sender)
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
//наименование  базовой единицы
int num_bas_ed=StrToInt(BasEdcxSpinEdit->Text);
AnsiString name_bas_ed="";

//наименование  основной единицы
int num_osn_ed=StrToInt(OsnEdcxSpinEdit->Text);
AnsiString name_osn_ed="";

//наименование  физической единицы
int num_fis_ed=StrToInt(FisEdcxSpinEdit->Text);
AnsiString name_fis_ed="";

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

		//базовая единица

		if (num_bas_ed!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_bas_ed-1,number_string_excel-1);
			name_bas_ed=Trim(cell->Text);
			delete cell;
			}
		else {name_bas_ed="";}

		//основная единица
		if (num_osn_ed!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_osn_ed-1,number_string_excel-1);
			name_osn_ed=Trim(cell->Text);
			delete cell;
			}
		else {name_osn_ed="";}

		//физическая единица
		if (num_fis_ed!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_fis_ed-1,number_string_excel-1);
			name_fis_ed=Trim(cell->Text);
			delete cell;
			}
		else {name_fis_ed="";}


		//найдем номенклатуру
		__int64 id_nom=0;
		if (name_nom!="")
			{
			QueryNom->Close();
			QueryNom->ParamByName("PARAM_NAME")->AsString=name_nom;
			QueryNom->ExecQuery();
			id_nom=QueryNom->FieldByName("IDNOM")->AsInt64;
			QueryNom->Close();
			}


        //вставляем единицы
		if(id_nom!=0)
			{
			__int64 id_bas_ed=0;
			__int64 id_osn_ed=0;
			__int64 id_fis_ed=0;

			//ищем базовую единицу
			if (name_bas_ed=="")
				{  //ищем хоть какую


				}
			else
				{
				QueryEd->Close();
				QueryEd->ParamByName("PARAM_NAME")->AsString=name_bas_ed;
				QueryEd->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
				QueryEd->ExecQuery();
				id_bas_ed=QueryEd->FieldByName("IDED")->AsInt64;
				QueryNom->Close();
				}

			if (id_bas_ed!=0)
				{
				DataSetNom->Close();
				DataSetNom->ParamByName("PARAM_ID")->AsInt64=id_nom;
				DataSetNom->Active=true;
				DataSetNom->Edit();

				DataSetNomIDBASEDNOM->AsInt64=id_bas_ed;

				//ищем основную единицу
				if (name_osn_ed!="")
					{
					QueryEd->Close();
					QueryEd->ParamByName("PARAM_NAME")->AsString=name_osn_ed;
					QueryEd->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
					QueryEd->ExecQuery();
					id_osn_ed=QueryEd->FieldByName("IDED")->AsInt64;
					QueryNom->Close();
					}
					
				if (id_osn_ed==0)
					{
					DataSetNomIDOSNEDNOM->AsInt64=id_bas_ed;
					}
				else
					{
                    DataSetNomIDOSNEDNOM->AsInt64=id_osn_ed;
					}

				//ищем физическую единицу
				if (name_fis_ed!="")
					{
					QueryEd->Close();
					QueryEd->ParamByName("PARAM_NAME")->AsString=name_fis_ed;
					QueryEd->ParamByName("PARAM_IDNOM")->AsInt64=id_nom;
					QueryEd->ExecQuery();
					id_fis_ed=QueryEd->FieldByName("IDED")->AsInt64;
					QueryNom->Close();
					}
					
				if (id_fis_ed==0)
					{
					//DataSetNomIDOSNEDNOM->AsInt64=id_bas_ed;
					}
				else
					{
					DataSetNomIDFISED_SNOM->AsInt64=id_fis_ed;
					}



				try
					{
					DataSetNom->Post();
					TrUpdate->Commit();
					}
				catch(Exception &exception)
					{
					TrUpdate->Rollback();
					ShowMessage("Ошибка в строке:"+IntToStr(number_string_excel)+" "+exception.Message);
					}
				DataSetNom->Active=false;
				}
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


