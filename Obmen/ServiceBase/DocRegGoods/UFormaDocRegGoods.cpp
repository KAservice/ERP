//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UFormaDocRegGoods.h"
#include "UDataModuleMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxTextEdit"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxLookupEdit"
#pragma link "cxMaskEdit"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaDocRegGoods::TFormaDocRegGoods(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRegGoods::FormCreate(TObject *Sender)
{
BaseList->Active=true;
FirmList->Active=true;
SkladList->Active=true;
NameServercxTextEdit->Text="localhost";
FilecxTextEdit->Text="K:\\Base.fdb";
NameUsercxTextEdit->Text="SYSDBA";
PasswordUsercxTextEdit->Text="masterkey";
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRegGoods::FormClose(TObject *Sender, TCloseAction &Action)

{
Action=caFree;
}
//--------------------------------------------------------------------------------
void __fastcall TFormaDocRegGoods::cxButtonViborFileClick(TObject *Sender)
{
if(OpenDialog1->Execute())
		{
		FilecxTextEdit->Text=OpenDialog1->FileName;
		}
}
//----------------------------------------------------------------------------
bool TFormaDocRegGoods::ConnectBaseSource(void)
{
bool result=false;
try
		{
		DataBaseSource->Connected=false;
		DataBaseSource->DBName=NameServercxTextEdit->Text+":"+FilecxTextEdit->Text;
		DataBaseSource->DBParams->Clear();
		DataBaseSource->DBParams->Add(" user_name="+NameUsercxTextEdit->Text);
		DataBaseSource->DBParams->Add(" lc_ctype=UTF8");
		DataBaseSource->DBParams->Add(" password="+PasswordUsercxTextEdit->Text);
		DataBaseSource->Connected=true;
		result=true;
        }
catch (Exception &exception)
		{
		ShowMessage("Ошибка при подключении к базе: "+exception.Message);
		result=false;
		DataBaseSource->Connected=false;
        }

return result;



}
//---------------------------------------------------------------------------
bool TFormaDocRegGoods::CreateDocRegGoods(void)
{
bool result=false;
if (ConnectBaseSource()==false)
	{
	ShowMessage("Ошибка при подключении к базе-источнику!");
	return result;
	}

	BaseList->First();
	BaseList->MoveBy(NameBasecxLookupComboBox->ItemIndex);

	FirmList->First();
	FirmList->MoveBy(NameFirmcxLookupComboBox->ItemIndex);

	SkladList->First();
	SkladList->MoveBy(NameSkladcxLookupComboBox->ItemIndex);

	DocRegGoodsSource->Active=false;
	DocRegGoodsSource->ParamByName("PARAM_IDFIRM")->AsString=
				FirmListIDFIRM->AsString;
	DocRegGoodsSource->ParamByName("PARAM_IDSKLAD")->AsString=
				SkladListIDSKLAD->AsString;
    DocRegGoodsSource->Active=true;

try
	{
	DocAll->Active=false;
	Doc_RegGoods->Active=false;
	DocT_RegGoods->Active=false;

	DocAll->Active=true;
	Doc_RegGoods->Active=true;
	DocT_RegGoods->Active=true;

	DocAll->Append();
	DocAllNUMDOC->AsInteger=1;
	DocAllPOSDOC->AsDateTime=Now();
	DocAllTDOC->AsString="RG_GOODS";
	DocAllIDBASE_GALLDOC->AsString=BaseListID_SINFBASE_OBMEN->AsString;
	DocAllIDFIRMDOC->AsString=FirmListIDFIRM->AsString;
    DocAllIDSKLDOC->AsString=SkladListIDSKLAD->AsString;
	DocAll->Post();

	Doc_RegGoods->Append();
    Doc_RegGoodsIDBASE_DRG_GOODS->AsString=DocAllIDBASE_GALLDOC->AsString;
	Doc_RegGoodsIDDOC_DRG_GOODS->AsString=DocAllIDDOC->AsString;
	Doc_RegGoods->Post();

	DocRegGoodsSource->First();
	while(!DocRegGoodsSource->Eof)
		{
		DocT_RegGoods->Append();
		DocT_RegGoodsIDBASE_DRG_GOODST->AsString=DocRegGoodsSourceIDBASE_RGGOODS->AsString;
		DocT_RegGoodsIDDOC_DRG_GOODST->AsString=DocAllIDDOC->AsString;
		DocT_RegGoodsIDFIRM_DRG_GOODST->AsString=DocRegGoodsSourceIDFIRM_RGGOODS->AsString;
		DocT_RegGoodsIDSKLAD_DRG_GOODST->AsString=DocRegGoodsSourceIDSKLAD_RGGOODS->AsString;
		DocT_RegGoodsIDNOM_DRG_GOODST->AsString=DocRegGoodsSourceIDNOM_RGGOODS->AsString;
		DocT_RegGoodsTDV_DRG_GOODST->AsInteger=1;
		DocT_RegGoodsRPRICE_DRG_GOODST->AsFloat=DocRegGoodsSourceRPRICE_RGGOODS->AsFloat;
		DocT_RegGoodsKOL_DRG_GOODST->AsFloat=DocRegGoodsSourceKOL_RGGOODS->AsFloat;
		DocT_RegGoods->Post();
		DocRegGoodsSource->Next();
		}

	DocAll->ApplyUpdToBase();
	Doc_RegGoods->ApplyUpdToBase();
	DocT_RegGoods->ApplyUpdToBase();
	IBTrUpdate->Commit();
	DocAll->CommitUpdToCach();
	Doc_RegGoods->CommitUpdToCach();
	DocT_RegGoods->CommitUpdToCach();
	result=true;
	}
catch(Exception &exception)
	{
	IBTrUpdate->Rollback();
	result=false;
	ShowMessage("Ошибка при создании документа: "+exception.Message);
	}


ShowMessage ("Документ Движения регистра Остатки товаров сформирован!");
return result;


}
//-----------------------------------------------------------------------------
void __fastcall TFormaDocRegGoods::Button1Click(TObject *Sender)
{
CreateDocRegGoods();
}
//---------------------------------------------------------------------------

