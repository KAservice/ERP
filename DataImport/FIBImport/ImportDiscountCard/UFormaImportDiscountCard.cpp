//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//----------------------------------------------------------------------------
#include "UFormaImportDiscountCard.h"
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
__fastcall TFormaImportDiscountCard::TFormaImportDiscountCard(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportDiscountCard::FormCreate(TObject *Sender)
{

FileNamecxButtonEdit->Text="";

}
//---------------------------------------------------------------------------
void __fastcall TFormaImportDiscountCard::FormClose(TObject *Sender,
      TCloseAction &Action)
{

Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaImportDiscountCard::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaImportDiscountCard::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportDiscountCard::FileNamecxButtonEditPropertiesButtonClick(
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
void TFormaImportDiscountCard::UpdateSetup(void)
{

}
//----------------------------------------------------------------------------
void TFormaImportDiscountCard::SaveSetup(void)
{

}
//----------------------------------------------------------------------------


void __fastcall TFormaImportDiscountCard::cxButtonImportClick(TObject *Sender)
{
if (StartStringcxSpinEdit->Text=="" ||
			StartStringcxSpinEdit->Text=="0")
	{
	ShowMessage("Необходимо задать настройки импорта!");
	return;
	}


int number_string_excel=StrToInt(StartStringcxSpinEdit->Text);
int number_con_string_excel=StrToInt(ConStringcxSpinEdit->Text);

//наименование  клиента
int num_name_klient=StrToInt(NameKlientcxSpinEdit->Text);
AnsiString name_klient="";

//код
int num_code_card=StrToInt(CodeCardcxSpinEdit->Text);
AnsiString code_card="";

//наименование
int num_name_card=StrToInt(NameCardcxSpinEdit->Text);
AnsiString name_card="";

//тип
int num_type_card=StrToInt(TypeCardcxSpinEdit->Text);
AnsiString type_card="";

//штрихкод
int num_sh=StrToInt(ShCardcxSpinEdit->Text);
AnsiString sh="";


int num_procent=StrToInt(ProcentcxSpinEdit->Text);
AnsiString procent="";



TcxSSCellObject *cell;
bool error=false;

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

		//код единицы
		if (num_code_card!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_code_card-1,number_string_excel-1);
			code_card=Trim(cell->Text);
			delete cell;
			}
		else {code_card="";}

		//наименование
		if (num_name_card!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_card-1,number_string_excel-1);
			name_card=Trim(cell->Text);
			delete cell;
			}
		else {name_card="";}

		//тип штрихкода
		if (num_type_card!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_type_card-1,number_string_excel-1);
			type_card=Trim(cell->Text);
			delete cell;
			}
		else {type_card="";}

		//штрихкод
		if (num_sh!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_sh-1,number_string_excel-1);
			sh=Trim(cell->Text);
			delete cell;
			}
		else {sh="";}

		//КФ1
		if (num_procent!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_procent-1,number_string_excel-1);
			procent=Trim(cell->Text);
			delete cell;
			}
		else {procent="0";}


		__int64 id_klient=0;
		if (name_klient!="")
			{
			QueryKlient->Close();
			QueryKlient->ParamByName("PARAM_NAME")->AsString=name_klient;
			QueryKlient->ExecQuery();
			id_klient=QueryKlient->FieldByName("IDKLIENT")->AsInt64;
			QueryKlient->Close();
			}

		//вставляем единицу
		if(id_klient!=0)
			{
			DataSet->Close();
			DataSet->Active=true;
			DataSet->Insert();
			DataSetNAME_SDISCOUNT_CARD->AsString=name_card;
			DataSetIDKLIENT_SDISCOUNT_CARD->AsInt64=id_klient;
			DataSetACT_SDISCOUNT_CARD->AsInteger=1;

			//КОД единицы
			if (code_card=="")
				{
				QueryCodeCard->Close();
				QueryCodeCard->ExecQuery();
				code_card=QueryCodeCard->FieldByName("CODE")->AsString;
				QueryCodeCard->Close();
				}
		   if (code_card!="")
				{
				DataSetCODE_SDISCOUNT_CARD->AsInteger=StrToInt(code_card);
				}

			//тип штрихкода
			if (type_card=="")
				{
				DataSetTYPE_SDISCOUNT_CARD->AsInteger=1; //фиксированная
				}
			else
				{
				DataSetTYPE_SDISCOUNT_CARD->AsInteger=StrToInt(type_card);
				}

			//штрихкод
			if (sh=="")
				{  // генерируем новый штрихкод типа 0
				DataSetSHCODE_SDISCOUNT_CARD->AsString=GetNewBarCode(IntToStr(DataSetCODE_SDISCOUNT_CARD->AsInteger), 0);
				}
			else
				{
				DataSetSHCODE_SDISCOUNT_CARD->AsString=sh;
				}

			if (procent=="")
				{
				}
			else
				{
				try {DataSetPRSK_SDISCOUNT_CARD->AsFloat=StrToFloat(procent);;} catch(...){}
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
AnsiString TFormaImportDiscountCard::AddEAN13(AnsiString cod)
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
AnsiString TFormaImportDiscountCard::GetNewBarCode(AnsiString code, int type_bar_code)
{
AnsiString result="";

AnsiString sh=code;
sh=DopStrL(sh,"0",5);

//обычный локальный шк, поиск по шк единицы

sh="2100000"+sh;


result=AddEAN13(sh);

return result;
}
//----------------------------------------------------------------------------
//дополнить строку Str слева символами Symbol до Len
String TFormaImportDiscountCard::DopStrL(String Str, String Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//-----------------------------------------------------------------------------
