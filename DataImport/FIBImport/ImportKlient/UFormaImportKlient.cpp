//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//----------------------------------------------------------------------------
#include "UFormaImportKlient.h"
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
__fastcall TFormaImportKlient::TFormaImportKlient(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportKlient::FormCreate(TObject *Sender)
{

FileNamecxButtonEdit->Text="";

}
//---------------------------------------------------------------------------
void __fastcall TFormaImportKlient::FormClose(TObject *Sender,
      TCloseAction &Action)
{

Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaImportKlient::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaImportKlient::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportKlient::FileNamecxButtonEditPropertiesButtonClick(
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
void TFormaImportKlient::UpdateSetup(void)
{

}
//----------------------------------------------------------------------------
void TFormaImportKlient::SaveSetup(void)
{

}
//----------------------------------------------------------------------------


void __fastcall TFormaImportKlient::cxButtonImportClick(TObject *Sender)
{
if (StartStringcxSpinEdit->Text=="" ||
			StartStringcxSpinEdit->Text=="0")
	{
	ShowMessage("Необходимо задать настройки импорта!");
	return;
	}


int number_string_excel=StrToInt(StartStringcxSpinEdit->Text);
int number_con_string_excel=StrToInt(ConStringcxSpinEdit->Text);

//родительская группа
int num_name_grp=StrToInt(NameOwnerGrpcxSpinEdit->Text);
AnsiString name_grp="";
//наименование
int num_name_klient=StrToInt(NameKlientcxSpinEdit->Text);
AnsiString name_klient="";


int num_kr_name=StrToInt(KrNamecxSpinEdit->Text);
AnsiString kr_name="";

int num_full_name_klient=StrToInt(FullNamecxSpinEdit->Text);
AnsiString full_name_klient="";

int num_adr=StrToInt(AdrcxSpinEdit->Text);
AnsiString adr="";

int num_inn=StrToInt(INNcxSpinEdit->Text);
AnsiString inn="";

int num_kpp=StrToInt(KPPcxSpinEdit->Text);
AnsiString kpp="";

int num_phone=StrToInt(PhonecxSpinEdit->Text);
AnsiString phone="";

int num_email=StrToInt(EmailcxSpinEdit->Text);
AnsiString email="";

int num_descr=StrToInt(DescrcxSpinEdit->Text);
AnsiString descr="";


TcxSSCellObject *cell;
bool error=false;

while(number_string_excel<=number_con_string_excel)
	{
	try
		{
		//родительская группа
		if (num_name_grp!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_grp-1,number_string_excel-1);
			name_grp=Trim(cell->Text);
			delete cell;
			}
		else {name_grp="";}

		//наименование
		if (num_name_klient!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_klient-1,number_string_excel-1);
			name_klient=Trim(cell->Text);
			delete cell;
			}
		else {name_klient="";}


		if (num_full_name_klient!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_full_name_klient-1,number_string_excel-1);
			full_name_klient=Trim(cell->Text);
			delete cell;
			}
		else {full_name_klient="";}

		if (num_kr_name!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_kr_name-1,number_string_excel-1);
			kr_name=Trim(cell->Text);
			delete cell;
			}
		else {kr_name="";}


		if (num_adr!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_adr-1,number_string_excel-1);
			adr=Trim(cell->Text);
			delete cell;
			}
		else {adr="";}


		if (num_inn!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_inn-1,number_string_excel-1);
			inn=Trim(cell->Text);
			delete cell;
			}
		else {inn="";}

		if (num_kpp!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_kpp-1,number_string_excel-1);
			kpp=Trim(cell->Text);
			delete cell;
			}
		else {kpp="";}

		if (num_phone!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_phone-1,number_string_excel-1);
			phone=Trim(cell->Text);
			delete cell;
			}
		else {phone="";}

		if (num_email!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_email-1,number_string_excel-1);
			email=Trim(cell->Text);
			delete cell;
			}
		else {email="";}

		if (num_descr!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_descr-1,number_string_excel-1);
			descr=Trim(cell->Text);
			delete cell;
			}
		else {descr="";}


		__int64 id_grp=0;
		if (name_grp!="")
			{
			QueryOwnerGrp->Close();
			QueryOwnerGrp->ParamByName("PARAM_NAME")->AsString=name_grp;
			QueryOwnerGrp->ExecQuery();
			id_grp=QueryOwnerGrp->FieldByName("IDGRPKL")->AsInt64;
			QueryOwnerGrp->Close();
			}


			
		if(name_klient!="")
			{
			DataSet->Close();
			DataSet->Active=true;
			DataSet->Insert();
			if (id_grp!=0)
				{
                DataSetIDGRPKLIENT->AsInt64=id_grp;
				}


			DataSetNAMEKLIENT->AsString=name_klient;
            

			if (full_name_klient=="")
				{
				DataSetFNAME->AsString=name_klient;
				}
			else
				{
				DataSetFNAME->AsString=full_name_klient;
				}

			if (kr_name=="")
				{
				DataSetKRNAME_SKLIENT->AsString=kr_name;
				}
			else
				{
				DataSetKRNAME_SKLIENT->AsString=kr_name;
				}

				DataSetADRKLIENT->AsString=adr;
				DataSetINNKLIENT->AsString=inn;
				DataSetKPPKLIENT->AsString=kpp;
				DataSetTELKLIENT->AsString=phone;
				DataSetEMAIL_SKLIENT->AsString=email;
				DataSetDESCR_SKLIENT->AsString=descr;

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


