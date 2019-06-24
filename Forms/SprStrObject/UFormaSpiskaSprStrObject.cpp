//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprStrObject.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprStrObject::TFormaSpiskaSprStrObject(TComponent* Owner)
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

bool TFormaSpiskaSprStrObject::Init(void)
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
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprStrObject.1",IID_IDMSprStrObject, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);
IdGrp=0;
AllElement=false;
DMGrp->OpenTable();
Vibor=false;
UpdateDerevo();

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
int TFormaSpiskaSprStrObject::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprStrObject::FormClose(TObject *Sender,
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
DMGrp->kanRelease();

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void TFormaSpiskaSprStrObject::UpdateDerevo()
{
String NameUsel="";
//очистим память от предыдущего дерева
if (TreeView1->Items->Count>0)
		{
		for (__int64 i=0;i<TreeView1->Items->Item[0]->Count;i++)
                {
				delete (__int64*)TreeView1->Items->Item[i]->Data;
                }
        }

//
DMGrp->OpenTable();
TreeView1->Items->Clear();
__int64 *lpIDGrp=new __int64;
*lpIDGrp=0;

TreeView1->Items->AddObject(NULL,"Ресторан",lpIDGrp);

TreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=DMGrp->TableIDGRP_STROB->AsInt64;
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
        for (int i=0;i<TreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)TreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=DMGrp->TableID_STROB->AsInt64;
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
                         NameUsel=DMGrp->TableNAME_STROB->AsString;
                               // +" (Код:"+IntToStr(DMGrp->TableCODE_STROB->AsInteger)+")";
                         TreeView1->Items->AddChildObjectFirst(TreeView1->Items->Item[i],
                         NameUsel, lpIDGrp);
                         break;
                       }

                }
        DMGrp->Table->Next();
        }
//TreeView1->AlphaSort(true);

for (int i=0;i<TreeView1->Items->Count;i++)
        {
		__int64 IDData=*(__int64*)TreeView1->Items->Item[i]->Data;
                if (IdGrp==IDData)
                        {
                        TreeView1->Selected=TreeView1->Items->Item[i];
                        break;
                        }
        }
}
//---------------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprStrObject::ToolButtonNewGrpClick(TObject *Sender)
{
OpenFormNewGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprStrObject::ToolButtonEdiGrpClick(TObject *Sender)
{
OpenFormGrpElement();
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprStrObject::ToolButtonDeleteGrpClick(
      TObject *Sender)
{
DeleteGrpElement();
UpdateDerevo();
}
//---------------------------------------------------------------------------
//--------------------------------------------------------------------------
void TFormaSpiskaSprStrObject::OpenFormGrpElement()
{
if (FormaGrpElementa==0)
        {
        if (TreeView1->Selected!=NULL)
                {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprStrObject.1",IID_IFormaElementaSprStrObject, (void**)&FormaGrpElementa);
		FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->DM->OpenElement(*(__int64*)TreeView1->Selected->Data);
		FormaGrpElementa->NumberProcVibor=1;
                }
        }
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprStrObject::OpenFormNewGrpElement()
{


if (FormaGrpElementa==0)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprStrObject.1",IID_IFormaElementaSprStrObject, (void**)&FormaGrpElementa);
		FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);

        if (TreeView1->Selected!=NULL)
                {
				IdGrp=*(__int64*)TreeView1->Selected->Data;
                FormaGrpElementa->DM->NewElement(IdGrp);
                }
        else
                {
                FormaGrpElementa->DM->NewElement(0);
                }
		FormaGrpElementa->NumberProcVibor=1;
        }
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprStrObject::DeleteGrpElement()
{

        if (TreeView1->Selected!=NULL)
                {
                DMGrp->DeleteElement(*(__int64*)TreeView1->Selected->Data);
                UpdateDerevo();
                }

}
//-------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprStrObject::TreeView1CustomDrawItem(
      TCustomTreeView *Sender, TTreeNode *Node, TCustomDrawState State,
      bool &DefaultDraw)
{
if (TreeView1->Selected==Node)
        {
        TreeView1->Canvas->Font->Color=clRed;
        }        
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprStrObject::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprStrOb");	
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprStrObject::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprStrObject::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==1)
		{
		IdGrp=FormaGrpElementa->DM->ElementID_STROB->AsInt64;
		UpdateDerevo();
		FormaGrpElementa=0;
		}
return -1;
}
//-----------------------------------------------------------------------------
