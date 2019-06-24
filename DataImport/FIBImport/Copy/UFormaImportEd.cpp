//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//----------------------------------------------------------------------------
#include "UFormaImportEd.h"
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
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaImportEd::TFormaImportEd(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportEd::FormCreate(TObject *Sender)
{

FileNamecxButtonEdit->Text="";

}
//---------------------------------------------------------------------------
void __fastcall TFormaImportEd::FormClose(TObject *Sender,
      TCloseAction &Action)
{

Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaImportEd::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaImportEd::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportEd::FileNamecxButtonEditPropertiesButtonClick(
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
void TFormaImportEd::UpdateSetup(void)
{

}
//----------------------------------------------------------------------------
void TFormaImportEd::SaveSetup(void)
{

}
//----------------------------------------------------------------------------


void __fastcall TFormaImportEd::cxButtonImportClick(TObject *Sender)
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

//код единицы
int num_code_ed=StrToInt(CodeEdcxSpinEdit->Text);
AnsiString code_ed="";

//наименование  удиницы
int num_name_ed=StrToInt(NameEdcxSpinEdit->Text);
AnsiString name_ed="";

//тип штрихкода
int num_type_sh=StrToInt(TypeShEdcxSpinEdit->Text);
AnsiString type_sh="";

//штрихкод
int num_sh=StrToInt(ShEdcxSpinEdit->Text);
AnsiString sh="";

//КФ1
int num_kf1=StrToInt(KF1EdcxSpinEdit->Text);
AnsiString kf1="";

//КФ2
int num_kf2=StrToInt(KF2EdcxSpinEdit->Text);
AnsiString kf2="";

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

		//код единицы
		if (num_code_ed!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_code_ed-1,number_string_excel-1);
			code_ed=Trim(cell->Text);
			delete cell;
			}
		else {code_ed="";}

		//наименование единицы
		if (num_name_ed!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_ed-1,number_string_excel-1);
			name_ed=Trim(cell->Text);
			delete cell;
			}
		else {name_ed="";}

		//тип штрихкода
		if (num_type_sh!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_type_sh-1,number_string_excel-1);
			type_sh=Trim(cell->Text);
			delete cell;
			}
		else {type_sh="";}

		//штрихкод
		if (num_sh!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_sh-1,number_string_excel-1);
			sh=Trim(cell->Text);
			delete cell;
			}
		else {sh="";}

		//КФ1
		if (num_kf1!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_kf1-1,number_string_excel-1);
			kf1=Trim(cell->Text);
			delete cell;
			}
		else {kf1="1";}

		//КФ2
		if (num_kf2!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_kf2-1,number_string_excel-1);
			kf2=Trim(cell->Text);
			delete cell;
			}
		else {kf2="1";}

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
			
		//вставляем единицу
		if(id_nom!=0)
			{
			DataSetEd->Close();
			DataSetEd->Active=true;
			DataSetEd->Insert();
			DataSetEdNAMEED->AsString=name_ed;
			DataSetEdIDNOMED->AsInt64=id_nom;

			//КОД единицы
			if (code_ed=="")
				{
				QueryCodeEd->Close();
				QueryCodeEd->ExecQuery();
				code_ed=QueryCodeEd->FieldByName("CODE")->AsString;
				QueryCodeEd->Close();
				}
		   if (code_ed!="")
				{
				DataSetEdCODE_SED->AsInteger=StrToInt(code_ed);
				}

			//тип штрихкода
			if (type_sh=="")
				{
				DataSetEdTSHED->AsInteger=0;
				}
			else
				{
				DataSetEdTSHED->AsInteger=StrToInt(type_sh);
				}

			//штрихкод
			if (sh=="")
				{  // генерируем новый штрихкод типа 0
				DataSetEdSHED->AsString=GetNewBarCode(IntToStr(DataSetEdCODE_SED->AsInteger), DataSetEdTSHED->AsInteger);
				}
			else
				{
				DataSetEdSHED->AsString=sh;
				}

			//КФ1
			if (kf1=="")
				{
				}
			else
				{
				DataSetEdKFED->AsFloat=StrToFloat(kf1);
				}

			//КФ1
			if (kf2=="")
				{
				if (DataSetEdKFED->AsFloat!=0)
					{
					DataSetEdKF2_SED->AsFloat=1/DataSetEdKFED->AsFloat;
					}
				}
			else
				{
				DataSetEdKF2_SED->AsFloat=StrToFloat(kf2);
				}

			try
				{
				DataSetEd->Post();
				TrUpdate->Commit();
				}
			catch(Exception &exception)
				{
				TrUpdate->Rollback();
				ShowMessage("Ошибка в строке:"+IntToStr(number_string_excel)+" "+exception.Message);
				}
			DataSetEd->Active=false;
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
AnsiString TFormaImportEd::AddEAN13(AnsiString cod)
{
AnsiString ShCod="";

if (cod.Length()!=12)
        {
		return ShCod=cod+"-";
        }

//длина Cod 12 символов обязательно

double Ch=0;
double NeCh=0;
double E13=0;

for (int i=1;i<7;i++)
        {
		Ch=Ch+(int)StrToFloat(cod[2*i]);
        NeCh=NeCh+(int)StrToFloat(cod[2*i-1]);
        }

Ch=Ch*3;
E13=((Ch+NeCh)/10)-(floor((Ch+NeCh)/10));
E13=10-floor(E13*10);
if (E13==10){E13=0;}

ShCod=cod+IntToStr((int)E13);
return ShCod;
}
//----------------------------------------------------------------------------
AnsiString TFormaImportEd::GetNewBarCode(AnsiString code, int type_bar_code)
{
AnsiString result="";

AnsiString sh=code;
sh=DopStrL(sh,"0",5);

//обычный локальный шк, поиск по шк единицы
if (type_bar_code==0)
	{
	sh="2000000"+sh;
	}

result=AddEAN13(sh);

return result;
}
//----------------------------------------------------------------------------
//дополнить строку Str слева символами Symbol до Len
String TFormaImportEd::DopStrL(String Str, String Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//-----------------------------------------------------------------------------
