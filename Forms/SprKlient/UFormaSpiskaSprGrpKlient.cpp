//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprGrpKlient.h"
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
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprGrpKlient::TFormaSpiskaSprGrpKlient(TComponent* Owner)
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
void __fastcall TFormaSpiskaSprGrpKlient::FormCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
bool TFormaSpiskaSprGrpKlient::Init(void)
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

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpKlient.1",IID_IDMSprGrpKlient, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);


//DBGrid1->DataSource=DM->DataSourceTable;
DM->OpenTable();
UpdateDerevo();
Vibor=false;


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
int TFormaSpiskaSprGrpKlient::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprGrpKlient::FormClose(TObject *Sender,
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

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaSpiskaSprGrpKlient::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
DM->OpenTable();
return -1;
}

//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprGrpKlient::ToolButtonNewClick(TObject *Sender)
{
//OpenFormNewElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprGrpKlient::ToolButtonDeleteClick(TObject *Sender)
{
//DeleteElement();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprGrpKlient::FormResize(TObject *Sender)
{
//        int TecSumWidth=DBGrid1->Width;
//        int  SumWidth=432;
//        DBGrid1->Columns->Items[0]->Width=69*TecSumWidth/SumWidth;
//        DBGrid1->Columns->Items[1]->Width=318*TecSumWidth/SumWidth;
       // DBGrid1->Columns->Items[2]->Width=182*TecSumWidth/SumWidth;

}

//---------------------------------------------------------------------------
  //---------------------------------------------------------------------------
//
void TFormaSpiskaSprGrpKlient::UpdateDerevo()
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
DM->OpenTable();
cxTreeView1->Items->Clear();
__int64 *lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"Контрагенты",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DM->Table->First();
while (! DM->Table->Eof)
        {
		__int64 IDGrp=glStrToInt64(DM->TableGRPKL->AsString);
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=glStrToInt64(DM->TableIDGRPKL->AsString);
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
						 DM->TableNAMEGRPKL->AsString, lpIDGrp);
                         break;
                       }

                }
        DM->Table->Next();
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
//------------------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprGrpKlient::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprKlient");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprGrpKlient::cxTreeView1DblClick(TObject *Sender)
{
if (Vibor==true)
        {
		if (cxTreeView1->Selected!=NULL)
                {
                IdGrp=*(__int64*)cxTreeView1->Selected->Data;
                DM->OpenElement(IdGrp);
				TypeEvent=1;
                Close();
                }
        }
else
        {
        //OpenFormElement();
        }	
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprGrpKlient::cxTreeView1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
        {
		if (cxTreeView1->Selected!=NULL)
                {
                IdGrp=*(__int64*)cxTreeView1->Selected->Data;
                DM->OpenElement(IdGrp);
				TypeEvent=1;
                Close();
                }
        }
else
        {
        //OpenFormElement();
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprGrpKlient::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

