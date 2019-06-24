//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaViborBVNom.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "UDM.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxTextEdit"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxTreeView"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaViborBVNom::TFormaViborBVNom(TComponent* Owner)
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
bool TFormaViborBVNom::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprBVNom.1",IID_IDMSprBVNom,
												 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpBVNom.1",IID_IDMSprGrpBVNom,
												 (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;

IdGrp=0;
IdPod=0;
AllElement=false;

Vibor=false;
Prosmotr=false;
LabelNameGrp->Caption="Номенклатура\\...";
EditPodr->Text="";

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaViborBVNom::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaViborBVNom::UpdateForm(void)
{

DM->OpenTable(IdPod,IdGrp,AllElement);
DMGrp->OpenTable(IdPod);
UpdateDerevo(IdPod);
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborBVNom::FormClose(TObject *Sender,
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

DM->kanRelease();
DMGrp->kanRelease();
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaViborBVNom::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

return -1;
}

//------------------------------------------------------------------------
void TFormaViborBVNom::UpdateDerevo(int Pod)
{
IdPod=Pod;
//очистим память от предыдущего дерева
if (cxTreeView1->Items->Count>0)
        {
		for (int i=0;i<cxTreeView1->Items->Item[0]->Count;i++)
                {
				delete (__int64*)cxTreeView1->Items->Item[i]->Data;
                }
        }

//
DMGrp->OpenTable(Pod);
cxTreeView1->Items->Clear();
__int64 *lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"Номенклатура",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGr=glStrToInt64(DMGrp->TableIDGRP_GBVNOM->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGr==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DMGrp->TableID_GBVNOM->AsString);
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
                         DMGrp->TableNAME_GBVNOM->AsString, lpIDGrp);
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
void __fastcall TFormaViborBVNom::ToolButtonAllClick(TObject *Sender)
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
DM->OpenTable(IdPod,IdGrp,AllElement);
}
//---------------------------------------------------------------------------


void __fastcall TFormaViborBVNom::ButtonCloseClick(TObject *Sender)
{
TypeEvent=0;
DM->CancelIsmen();
Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormaViborBVNom::cxGrid1DBTableView1DblClick(TObject *Sender)
{
if (Vibor==true)
        {
		ViborIdNom=glStrToInt64(DM->TableIDNOM_BVNOM->AsString);
		TypeEvent=1;
        Close();
        }
else
        {
        }	
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborBVNom::cxGrid1DBTableView1KeyPress(TObject *Sender,
      char &Key)
{
if(Key==VK_RETURN)
		{
if (Vibor==true)
		{
		ViborIdNom=glStrToInt64(DM->TableIDNOM_BVNOM->AsString);
		TypeEvent=1;
		Close();
		}
else
		{
		}
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborBVNom::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
        {
        if(AllElement!=true)
                {
                LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
                }
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
        DM->OpenTable(IdPod,IdGrp,AllElement);
        }	
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborBVNom::cxTreeView1KeyPress(TObject *Sender,
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
		DM->OpenTable(IdPod,IdGrp,AllElement);
		}
		}	
}
//---------------------------------------------------------------------------


void __fastcall TFormaViborBVNom::OpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprBVNomVibor");
}
//---------------------------------------------------------------------------

void __fastcall TFormaViborBVNom::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

