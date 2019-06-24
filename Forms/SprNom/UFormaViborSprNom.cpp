//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaViborSprNom.h"
#include "IDMSprARM.h"
#include "IDMUserSetup.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxTreeView"
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
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaViborSprNom::TFormaViborSprNom(TComponent* Owner)
		: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------
bool TFormaViborSprNom::Init(void)
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



InterfaceGlobalCom->kanCreateObject("Oberon.DMSprNom.1",IID_IDMSprNom,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpNom.1",IID_IDMSprGrpNom,
												 (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
IdGrp=0;
AllElement=false;
Vibor=false;
TypeEvent=0;


DM->SpTPrice->Active=true;

SpisokTypePrice->Properties->Items->Clear();
DM->SpTPrice->First();
while (!DM->SpTPrice->Eof)
		{
		SpisokTypePrice->Properties->Items->Add(DM->SpTPriceNAME_TPRICE->AsString);
		DM->SpTPrice->Next();
        }

LabelNameGrp->Caption="Номенклатура\\...";
HintLabel->Caption="";

FlagOstatok=false;

LabelFirma->Caption="";
LabelSklad->Caption="";

LoadFormSetup();


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TFormaViborSprNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaViborSprNom::UpdateForm(void)
{
SpisokTypePrice->ItemIndex=DM->GetIndexTypePrice()-1;
DM->IdFirm=glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString);
DM->IdSklad=glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString);
DM->CheckOst=FlagOstatok;
DM->OpenTable(IdGrp,AllElement);
DMGrp->OpenTable();
UpdateDerevo();
if (FlagOstatok==true)
        {
		cxGrid1DBTableView1SUMKOL->Visible=true;
		LabelFirma->Caption="Фирма: "+DM_Connection->ARMInfoNAMEFIRM->AsString;
        LabelSklad->Caption="Склад: "+DM_Connection->ARMInfoNAMESKLAD->AsString;
        }
else
        {
        cxGrid1DBTableView1SUMKOL->Visible=false;
        LabelFirma->Caption="";
        LabelSklad->Caption="";
        }

FormResize(this);
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborSprNom::FormClose(TObject *Sender,
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
		i_callback->kanRelease();
		}
	}

DM->kanRelease();
DMGrp->kanRelease();
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

int  TFormaViborSprNom::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==1)//==ViborGrp)
		{
		UpdateDerevo();
		}

if(number_procedure_end==2)//==ViborElement)
		{
		DM->OpenTable(IdGrp,AllElement);
		}
return -1;
}
//--------------------------------------------------------------------------

void TFormaViborSprNom::UpdateDerevo()
{

//очистим память от предыдущего дерева
if (cxTreeView1->Items->Count>0)
        {
		for (int i=0;i<cxTreeView1->Items->Item[0]->Count;i++)
                {
				delete (__int64*)cxTreeView1->Items->Item[i]->Data;
                }
        }

//
DMGrp->OpenTable();
cxTreeView1->Items->Clear();
__int64 *lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"Номенклатура",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=DMGrp->TableIDGRPGN->AsInteger;
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
                        break;
                        }
        }
}
//---------------------------------------------------------------------------------
void __fastcall TFormaViborSprNom::ToolButtonAllClick(TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
        }
else
        {
        AllElement=true ;
        LabelNameGrp->Caption="Все элементы...";
        }
IdGrp=*(__int64*)cxTreeView1->Selected->Data;
DM->OpenTable(IdGrp,AllElement);        
}
//---------------------------------------------------------------------------


void __fastcall TFormaViborSprNom::TreeView1CustomDrawItem(
      TCustomTreeView *Sender, TTreeNode *Node, TCustomDrawState State,
      bool &DefaultDraw)
{
if (cxTreeView1->Selected==Node)
        {
		cxTreeView1->Canvas->Font->Color=clRed;
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborSprNom::FormResize(TObject *Sender)
{
		int TecSumWidth=cxGrid1->ClientWidth;
SpisokTypePrice->Left=cxGrid1->Left+TecSumWidth-SpisokTypePrice->Width;
}
//---------------------------------------------------------------------------




void __fastcall TFormaViborSprNom::ToolButtonOstClick(TObject *Sender)
{
if (ToolButtonOst->Down==true)  // без чеков
        {
        FlagOstatok=true;
        }
else
        {
        FlagOstatok=false;
        }

UpdateForm();
}
//---------------------------------------------------------------------------


void __fastcall TFormaViborSprNom::cxButtonCloseClick(TObject *Sender)
{
TypeEvent=0;
Close(); 	
}
//---------------------------------------------------------------------------


void __fastcall TFormaViborSprNom::cxTreeView1KeyPress(TObject *Sender,
      char &Key)
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
		DM->OpenTable(IdGrp,AllElement);
		}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborSprNom::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
		{
		TypeEvent=1;
		DM->OpenElement(glStrToInt64(DM->TableIDNOM->AsString));
		Close();
		}
else
		{

		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborSprNom::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if(Key==VK_RETURN)
		{
        if (Vibor==true)
                {
				TypeEvent=1;
				DM->OpenElement(glStrToInt64(DM->TableIDNOM->AsString));
                Close();
				}
		}

}
//---------------------------------------------------------------------------

void __fastcall TFormaViborSprNom::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
        {
        if(AllElement!=true)
                {
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
        IdGrp=*(__int64*)cxTreeView1->Selected->Data;
        DM->OpenTable(IdGrp,AllElement);
		}
}
//---------------------------------------------------------------------------
void TFormaViborSprNom::SaveFormSetup(void)
{
IDMUserSetup * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
												 (void**)&dm);
dm->Init(InterfaceMainObject,InterfaceImpl);

dm->SaveSetupBool("FormaViborSprNom","FlagOstatok",FlagOstatok);
dm->SaveSetupBool("FormaViborSprNom","AllElement",AllElement);

//dm->SaveSetupInt("FormaSpiskaSprNom","IndexTypePrice", SpisokTypePrice->ItemIndex);
//dm->SaveSetupInt64("FormaSpiskaSprNom","IdFirm",IdFirm);
//dm->SaveSetup("FormaSpiskaSprNom","NameFirm",NameFirm);
//dm->SaveSetupInt64("FormaSpiskaSprNom","IdSklad",IdSklad);
//dm->SaveSetup("FormaSpiskaSprNom","NameSklad",NameSklad);
//
//dm->SaveSetupBool("FormaSpiskaSprNom","OnlyChange",OnlyChange);
//dm->SaveSetupBool("FormaSpiskaSprNom","OnlyOstatok",OnlyOstatok);
//dm->SaveSetupBool("FormaSpiskaSprNom","PriceSklad",PriceSklad);



dm->kanRelease();
}
//---------------------------------------------------------------------------
void TFormaViborSprNom::LoadFormSetup(void)
{
//NoUpdateForm=true;

IDMUserSetup * dm;
InterfaceGlobalCom->kanCreateObject("Oberon.DMUserSetup.1",IID_IDMUserSetup,
												 (void**)&dm);
dm->Init(InterfaceMainObject,InterfaceImpl);


//DM->SpTPrice->First();
//DM->SpTPrice->MoveBy(SpisokTypePrice->ItemIndex);
//DM->IdTypePrice=DM->SpTPriceID_TPRICE->AsInt64;
//IdTypePrice=DM->SpTPriceID_TPRICE->AsInt64;


FlagOstatok=dm->LoadSetupBool("FormaViborSprNom","FlagOstatok");
ToolButtonOst->Down=FlagOstatok;

AllElement=dm->LoadSetupBool("FormaViborSprNom","AllElement");
ToolButtonAll->Down=AllElement;


//SpisokTypePrice->ItemIndex=dm->LoadSetupInt("FormaSpiskaSprNom","IndexTypePrice");
//
//IdFirm=dm->LoadSetupInt64("FormaSpiskaSprNom","IdFirm");
//NameFirm=dm->LoadSetup("FormaSpiskaSprNom","NameFirm");
//IdSklad=dm->LoadSetupInt64("FormaSpiskaSprNom","IdSklad");
//NameSklad=dm->LoadSetup("FormaSpiskaSprNom","NameSklad");
//
//
//
//
//
//OnlyChange=dm->LoadSetupBool("FormaSpiskaSprNom","OnlyChange");
//ToolButtonCheckOnlyChange->Down=OnlyChange;
//
//OnlyOstatok=dm->LoadSetupBool("FormaSpiskaSprNom","OnlyOstatok");
//ToolButtonOnlyOstatok->Down=OnlyOstatok;
//
//PriceSklad=dm->LoadSetupBool("FormaSpiskaSprNom","PriceSklad");
//ToolButtonPriceSklad->Down=PriceSklad;


dm->kanRelease();

//NoUpdateForm=false;
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborSprNom::saveSetupFormToolButtonClick(TObject *Sender)
{
SaveFormSetup();
}
//---------------------------------------------------------------------------

