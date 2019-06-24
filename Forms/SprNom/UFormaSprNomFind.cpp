//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSprNomFind.h"
#include "IDMQueryRead.h"

#include "IDMUserSetup.h"
#include "IDMSprPrice.h"
#include "IDMRegGoods.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxTreeView"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxLookAndFeels"
#pragma link "cxLabel"
#pragma link "cxMemo"
#pragma link "cxDBLookupComboBox"
#pragma link "cxDBLookupEdit"
#pragma link "cxLookupEdit"
#pragma resource "*.dfm"



//---------------------------------------------------------------------------
__fastcall TFormaSprNomFind::TFormaSprNomFind(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;
}
//---------------------------------------------------------------------------
bool TFormaSprNomFind::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();

	}

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpNom.1",IID_IDMSprGrpNom, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject(ProgId_DMSprNomFind,IID_IDMSprNomFind, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprFirm.1",IID_IDMSprFirm, (void**)&DMSprFirm);
DMSprFirm->Init(InterfaceMainObject,InterfaceImpl);
DMSprFirm->OpenTable();

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprSklad.1",IID_IDMSprSklad, (void**)&DMSprSklad);
DMSprSklad->Init(InterfaceMainObject,InterfaceImpl);
DMSprSklad->OpenTable();

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

TypePricecxLookupComboBox->Properties->ListSource=DM->DataSourceTPrice;
NameFirmcxLookupComboBox->Properties->ListSource=DMSprFirm->DataSourceTable;
NameSkladcxLookupComboBox->Properties->ListSource=DMSprSklad->DataSourceTable;

IdGrp=0;
AllElement=false;
Vibor=false;



LabelNameGrp->Caption="Номенклатура\\...";


NoUpdateForm=false;
LoadFormSetup();


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;


UpdateForm();

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaSprNomFind::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TFormaSprNomFind::FormClose(TObject *Sender,
      TCloseAction &Action)
{

//получим ICallBack для передачи события в вызывающую форму
if(InterfaceOwnerObject)
	{
	IkanCallBack * i_callback=0;
	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
	if (i_callback)
		{
		i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
		}
	i_callback->kanRelease();
	}

DMSprSklad->kanRelease();
DMSprFirm->kanRelease();
DM->kanRelease();
DMGrp->kanRelease();


Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//-------------------------------------------------------------------------------
void TFormaSprNomFind::UpdateForm(void)
{
cxTextEditWord->Text=NameNom;
cxMemoIshodNom->Text=NameNom;
DMGrp->OpenTable();
UpdateDerevo();

}
//---------------------------------------------------------------------------
void TFormaSprNomFind::UpdateDerevo()
{

//очистим память от предыдущего дерева
if (cxTreeView1->Items->Count>0)
        {
		for (__int64 i=0;i<cxTreeView1->Items->Item[0]->Count;i++)
                {
				delete (__int64*)cxTreeView1->Items->Item[i]->Data;
                }
        }

//
DMGrp->OpenTable();
cxTreeView1->Items->Clear();
__int64 * lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"Номенклатура",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=glStrToInt64(DMGrp->TableIDGRPGN->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableIDGN->AsString);
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
                         DMGrp->Table->FieldByName("NAMEGN")->AsString, lpIDGrp);
                         break;
                       }

                }
        DMGrp->Table->Next();
        }
cxTreeView1->AlphaSort(true);


for (int i=0;i<cxTreeView1->Items->Count;i++)
        {
		__int64 IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                if (IdGrp==IDData)
                        {
						cxTreeView1->Selected=cxTreeView1->Items->Item[i];
                        if(AllElement!=true)
                                {
								LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
                                }
                        break;
                        }
		}

}
//----------------------------------------------------------------------------
int TFormaSprNomFind::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==1)//ViborGrp)
		{
		UpdateDerevo();
		}

if(number_procedure_end==2)//ViborElement)
		{
		cxGrid1->SetFocus();
		}


return -1;
}

//--------------------------------------------------------------------------

void __fastcall TFormaSprNomFind::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		}
}
//---------------------------------------------------------------------------


void __fastcall TFormaSprNomFind::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
		{
		TypeEvent=1;
		Close();
		}
else
		{
		IdNom=glStrToInt64(DM->TableIDNOM->AsString);
		//OpenFormElement();
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSprNomFind::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_RETURN)
		{
		if (Vibor==true)
				{
				TypeEvent=1;
				Close();
				}
		else
				{
				//OpenFormElement();
				}
		}	
}
//---------------------------------------------------------------------------




void __fastcall TFormaSprNomFind::cxTreeView1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if(Key==VK_RETURN)
	{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		}
		}
}

//--------------------------------------------------------------------------

void TFormaSprNomFind::SaveFormSetup(void)
{
IDMUserSetup * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
													(void**)&dm);

dm->Init(InterfaceMainObject,InterfaceImpl);

//dm->SaveSetupInt("FormaSpiskaSprNom","IndexTypePrice", SpisokTypePrice->ItemIndex);
//dm->SaveSetupInt64("FormaSpiskaSprNom","IdFirm",IdFirm);
//dm->SaveSetup("FormaSpiskaSprNom","NameFirm",NameFirm);
//dm->SaveSetupInt64("FormaSpiskaSprNom","IdSklad",IdSklad);
//dm->SaveSetup("FormaSpiskaSprNom","NameSklad",NameSklad);
//dm->SaveSetupBool("FormaSpiskaSprNom","FlagOstatok",FlagOstatok);
//dm->SaveSetupBool("FormaSpiskaSprNom","OnlyChange",OnlyChange);
//dm->SaveSetupBool("FormaSpiskaSprNom","OnlyOstatok",OnlyOstatok);
//dm->SaveSetupBool("FormaSpiskaSprNom","PriceSklad",PriceSklad);

dm->SaveSetupBool("FormaSpiskaSprNom","AllElement",AllElement);

dm->kanRelease();
}
//---------------------------------------------------------------------------
void TFormaSprNomFind::LoadFormSetup(void)
{
NoUpdateForm=true;

IDMUserSetup * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
													(void**)&dm);
dm->Init(InterfaceMainObject,InterfaceImpl);

//SpisokTypePrice->ItemIndex=dm->LoadSetupInt("FormaSpiskaSprNom","IndexTypePrice");


//DM->SpTPrice->First();
//DM->SpTPrice->MoveBy(SpisokTypePrice->ItemIndex);
//DM->IdTypePrice=DM->SpTPriceID_TPRICE->AsInt64;
//IdTypePrice=DM->SpTPriceID_TPRICE->AsInt64;

//IdFirm=dm->LoadSetupInt64("FormaSpiskaSprNom","IdFirm");
//NameFirm=dm->LoadSetup("FormaSpiskaSprNom","NameFirm");
//IdSklad=dm->LoadSetupInt64("FormaSpiskaSprNom","IdSklad");
//NameSklad=dm->LoadSetup("FormaSpiskaSprNom","NameSklad");



//FlagOstatok=dm->LoadSetupBool("FormaSpiskaSprNom","FlagOstatok");
//ToolButtonOst->Down=FlagOstatok;
//
//OnlyChange=dm->LoadSetupBool("FormaSpiskaSprNom","OnlyChange");
//ToolButtonCheckOnlyChange->Down=OnlyChange;
//
//OnlyOstatok=dm->LoadSetupBool("FormaSpiskaSprNom","OnlyOstatok");
//ToolButtonOnlyOstatok->Down=OnlyOstatok;
//
//PriceSklad=dm->LoadSetupBool("FormaSpiskaSprNom","PriceSklad");
//ToolButtonPriceSklad->Down=PriceSklad;

AllElement=dm->LoadSetupBool("FormaSpiskaSprNom","AllElement");

dm->kanRelease();

NoUpdateForm=false;
}
//----------------------------------------------------------------------------
void __fastcall TFormaSprNomFind::ToolButtonSaveSetupClick(TObject *Sender)
{
SaveFormSetup();	
}
//---------------------------------------------------------------------------




void __fastcall TFormaSprNomFind::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSprNomFind::cxButtonFindClick(TObject *Sender)
{
UnicodeString text_query="    select snom.idnom,   \
			snom.namenom,                          \
			snom.codenom,                          \
			snom.artnom,                           \
			snom.idbasednom,                       \
			snom.tnom,                             \
			snom.idgrpnom,                         \
			sed.nameed,                            \
			sed.shed,                              \
			sgrpnom.namegn,                        \
			0.00 as znach_price,                   \
			0.00 AS SUMKOL,                         \
            0.00 AS REM_OST                         \
from snom                                          \
left outer join sed on snom.idbasednom=sed.ided    \
left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn ";

text_query=text_query+" where upper(snom.namenom) like upper('%"+
						   cxTextEditWord->Text+"%')";

if (IdGrp>0)
	{
	text_query=text_query+" and snom.idgrpnom="+IntToStr(IdGrp);
	}						   																						 \
text_query=text_query+" order by snom.namenom";

DM->SetTextQuery(text_query);
DM->OpenTableResult();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSprNomFind::cxButtonGetPriceClick(TObject *Sender)
{
DM->DataSourceTable->Enabled=false;

IDMSprPrice * DMSprPrice;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprPrice.1",IID_IDMSprPrice,
													(void**)&DMSprPrice);
DMSprPrice->Init(InterfaceMainObject,InterfaceImpl);


__int64 id_type_price=0;
if (TypePricecxLookupComboBox->EditValue.IsNull()==true)
	{
	}
else
	{
	id_type_price=TypePricecxLookupComboBox->EditValue;
	}

DM->Table->First();

while (!DM->Table->Eof)
	{
	DM->Table->Edit();

	DMSprPrice->FindElement(id_type_price,
						glStrToInt64(DM->TableIDNOM->AsString));
	DM->TableZNACH_PRICE->AsFloat=DMSprPrice->ElementZNACH_PRICE->AsFloat;
	DM->Table->Post();
	DM->Table->Next();
	}

DMSprPrice->kanRelease();
DM->DataSourceTable->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSprNomFind::cxButtonGetOstatkiClick(TObject *Sender)
{
DM->DataSourceTable->Enabled=false;

IDMRegGoods * reg;
InterfaceGlobalCom->kanCreateObject("Oberon.DMRegGoods.1",IID_IDMRegGoods,
													(void**)&reg);
reg->Init(InterfaceMainObject,InterfaceImpl);


__int64 id_firm=0;
if (NameFirmcxLookupComboBox->EditValue.IsNull()==true)
	{
	}
else
	{
	id_firm=NameFirmcxLookupComboBox->EditValue;
	}

__int64 id_sklad=0;
if (NameSkladcxLookupComboBox->EditValue.IsNull()==true)
	{
	}
else
	{
	id_sklad=NameSkladcxLookupComboBox->EditValue;
	}

DM->Table->First();
while (!DM->Table->Eof)
	{
	DM->Table->Edit();
	DM->TableSUMKOL->AsFloat=reg->GetOstatok(id_firm, id_sklad,glStrToInt64(DM->TableIDNOM->AsString));
	DM->Table->Post();
	DM->Table->Next();
	}

reg->kanRelease();
DM->DataSourceTable->Enabled=true;
}
//---------------------------------------------------------------------------



void __fastcall TFormaSprNomFind::cxButtonOstPoServClick(TObject *Sender)
{
DM->DataSourceTable->Enabled=false;

__int64 id_firm=0;
if (NameFirmcxLookupComboBox->EditValue.IsNull()==true)
	{
	}
else
	{
	id_firm=NameFirmcxLookupComboBox->EditValue;
	}

__int64 id_sklad=0;
if (NameSkladcxLookupComboBox->EditValue.IsNull()==true)
	{
	}
else
	{
	id_sklad=NameSkladcxLookupComboBox->EditValue;
	}

IDMQueryRead * DMQueryRead;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryRead.1",IID_IDMQueryRead,
													(void**)&DMQueryRead);
DMQueryRead->Init(InterfaceMainObject,0);
DMQueryRead->pFIBQ->Close();
DMQueryRead->pFIBQ->SQL->Clear();
DMQueryRead->pFIBQ->SQL->Add("select  sum(rem_rggoods.kol_rem_rggoods) as ost");
DMQueryRead->pFIBQ->SQL->Add(" from rem_rggoods");
DMQueryRead->pFIBQ->SQL->Add(" where rem_rggoods.idnom_rem_rggoods=:PARAM_IDNOM");

if (id_firm > 0)
	{
	DMQueryRead->pFIBQ->SQL->Add(" and rem_rggoods.idfirm_rem_rggoods=:PARAM_IDFIRM");
	}

if (id_sklad > 0)
	{
	DMQueryRead->pFIBQ->SQL->Add(" and rem_rggoods.idsklad_rem_rggoods=:PARAM_IDSKLAD");
	}

if (id_firm > 0)
	{
	DMQueryRead->pFIBQ->ParamByName("PARAM_IDFIRM")->AsString=id_firm;
	}

if (id_sklad > 0)
	{
	DMQueryRead->pFIBQ->ParamByName("PARAM_IDSKLAD")->AsString=id_sklad;
	}


DM->Table->First();
while (!DM->Table->Eof)
	{
	DM->Table->Edit();
	DMQueryRead->pFIBQ->Close();
	DMQueryRead->pFIBQ->ParamByName("PARAM_IDNOM")->AsString=glStrToInt64(DM->TableIDNOM->AsString);
	DMQueryRead->pFIBQ->ExecQuery();
	DM->TableREM_OST->AsFloat=DMQueryRead->pFIBQ->FieldByName("OST")->AsFloat;
	DM->Table->Post();
	DM->Table->Next();
	}


DMQueryRead->pFIBQ->Close();
DMQueryRead->kanRelease();

DM->DataSourceTable->Enabled=true;

}
//---------------------------------------------------------------------------

