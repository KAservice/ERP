//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//----------------------------------------------------------------------------
#include "UFormaImportNom.h"
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
__fastcall TFormaImportNom::TFormaImportNom(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportNom::FormCreate(TObject *Sender)
{

FileNamecxButtonEdit->Text="";

}
//---------------------------------------------------------------------------
void __fastcall TFormaImportNom::FormClose(TObject *Sender,
      TCloseAction &Action)
{

Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaImportNom::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaImportNom::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportNom::FileNamecxButtonEditPropertiesButtonClick(
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
void TFormaImportNom::UpdateSetup(void)
{

}
//----------------------------------------------------------------------------
void TFormaImportNom::SaveSetup(void)
{

}
//----------------------------------------------------------------------------


void __fastcall TFormaImportNom::cxButtonImportClick(TObject *Sender)
{
if (StartStringcxSpinEdit->Text=="" ||
			StartStringcxSpinEdit->Text=="0")
	{
	ShowMessage("���������� ������ ��������� �������!");
	return;
	}


int number_string_excel=StrToInt(StartStringcxSpinEdit->Text);
int number_con_string_excel=StrToInt(ConStringcxSpinEdit->Text);

//������������ ������
int num_name_grp=StrToInt(NameOwnerGrpcxSpinEdit->Text);
AnsiString name_grp="";
//��� ������������
int num_type_nom=StrToInt(TypeNomcxSpinEdit->Text);
int type_nom=0;
//���
int num_code_nom=StrToInt(CodecxSpinEdit->Text);
AnsiString code_nom="";
//�������
int num_artikul_nom=StrToInt(ArtikulcxSpinEdit->Text);
AnsiString artikul_nom="";
//������������
int num_name_nom=StrToInt(NameNomcxSpinEdit->Text);
AnsiString name_nom="";
//��. ������������
int num_krname_nom=StrToInt(KrNameNomcxSpinEdit->Text);
AnsiString krname_nom="";
//������ ������������
int num_full_name_nom=StrToInt(FullNameNomcxSpinEdit->Text);
AnsiString full_name_nom="";
//���. ����������
int num_descr=StrToInt(DescrcxSpinEdit->Text);
AnsiString descr="";

//������
int num_country=StrToInt(CountrycxSpinEdit->Text);
AnsiString country="";

TcxSSCellObject *cell;
bool error=false;

while(number_string_excel<=number_con_string_excel)
	{
	try
		{
		//������������ ������
		if (num_name_grp!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_grp-1,number_string_excel-1);
			name_grp=Trim(cell->Text);
			delete cell;
			}
		else {name_grp="";}

		//������������ ������������
		if (num_name_nom!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_nom-1,number_string_excel-1);
			name_nom=Trim(cell->Text);
			delete cell;
			}
		else {name_nom="";}

		//��� ������������
		if (num_code_nom!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_code_nom-1,number_string_excel-1);
			code_nom=Trim(cell->Text);
			delete cell;
			}
		else {code_nom="";}

		//��� ������������
		if (num_type_nom!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_type_nom-1,number_string_excel-1);
			type_nom=StrToInt(Trim(cell->Text));
			delete cell;
			}
		else {type_nom=0;}

		//������� ������������
		if (num_artikul_nom!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_artikul_nom-1,number_string_excel-1);
			artikul_nom=Trim(cell->Text);
			delete cell;
			}
		else {artikul_nom="";}

		//������� ������������
		if (num_krname_nom!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_krname_nom-1,number_string_excel-1);
			krname_nom=Trim(cell->Text);
			delete cell;
			}
		else {krname_nom="";}

		//������ ������������
		if (num_full_name_nom!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_full_name_nom-1,number_string_excel-1);
			full_name_nom=Trim(cell->Text);
			delete cell;
			}
		else {full_name_nom="";}

		//��������
		if (num_descr!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_descr-1,number_string_excel-1);
			descr=Trim(cell->Text);
			delete cell;
			}
		else {descr="";}

		//������
		if (num_country!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_country-1,number_string_excel-1);
			country=Trim(cell->Text);
			delete cell;
			}
		else {country="";}

		//������ ������ ������������
		__int64 id_grp=0;
		if (name_grp!="")
			{
			QueryOwnerGrp->Close();
			QueryOwnerGrp->ParamByName("PARAM_NAME")->AsString=name_grp;
			QueryOwnerGrp->ExecQuery();
			id_grp=QueryOwnerGrp->FieldByName("IDGN")->AsInt64;
			QueryOwnerGrp->Close();
			}
			
        //��������� ������������
		if(name_nom!="")
			{
			DataSetNom->Close();
			DataSetNom->Active=true;
			DataSetNom->Insert();
			DataSetNomNAMENOM->AsString=name_nom;

			//��� ������������
            DataSetNomTNOM->AsInteger=type_nom;

			//��� ������������
			if (code_nom=="")
				{
				QueryCodeNom->Close();
				QueryCodeNom->ExecQuery();
				code_nom=QueryCodeNom->FieldByName("CODE")->AsString;
				QueryCodeNom->Close();
				}
		   if (code_nom!="")
				{
				DataSetNomCODENOM->AsInteger=StrToInt(code_nom);
				}

            //������
			if (id_grp==0)
				{//�������� ������
				}
			else
				{
				DataSetNomIDGRPNOM->AsInt64=id_grp;
				}

			//�������
			if (artikul_nom=="")
				{
				}
			else
				{
				DataSetNomARTNOM->AsString=artikul_nom;
				}
			//������� ������������
			if (krname_nom=="")
				{
				DataSetNomKRNAMENOM->AsString=name_nom;
				}
			else
				{
				DataSetNomKRNAMENOM->AsString=krname_nom;
				}
			//������ ������������
			if (full_name_nom=="")
				{
				DataSetNomFNAMENOM->AsString=name_nom;
				}
			else
				{
				DataSetNomFNAMENOM->AsString=full_name_nom;
				}

			//��������
			if (descr!="")
				{
				DataSetNomDESCR_SNOM->AsString=descr;
				}

			//�������
			if (country!="")
				{
				//���� ������ � ����������� �����
				DataSetCountry->Active=false;
				DataSetCountry->ParamByName("PARAM_NAME")->AsString=country;
				DataSetCountry->Active=true;
				if (DataSetCountryID_SCOUNTRY->AsInt64==0)
					{ //�������
					try
						{
						DataSetCountry->Append();
						DataSetCountryNAME_SCOUNTRY->AsString=country;
						DataSetCountry->Post();
						DataSetNomIDCOUNTRYNOM->AsInt64=DataSetCountryID_SCOUNTRY->AsInt64;
						TransCountry->Commit();
						}
					catch(Exception &exception)
						{
						TransCountry->Rollback();
						ShowMessage("������ ��� ������� ������, ������:"+IntToStr(number_string_excel)+" "+exception.Message);
						}
					}
				else
					{
					DataSetNomIDCOUNTRYNOM->AsInt64=DataSetCountryID_SCOUNTRY->AsInt64;
					} 

				}




			try
				{
				DataSetNom->Post();
				TrUpdate->Commit();
				}
			catch(Exception &exception)
				{
				TrUpdate->Rollback();
				ShowMessage("������ � ������:"+IntToStr(number_string_excel)+" "+exception.Message);
				}
			DataSetNom->Active=false;
			}



	}
catch(Exception &exception)
	{
	error=true;
	LabelError->Caption="������ � ������:"+IntToStr(number_string_excel)+" "+exception.Message;
	}
    number_string_excel++;
    }

}
//-------------------------------------------------------------------------


