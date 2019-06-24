//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UREM_FormaElementaSprProducerModelInfBlock.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxButtonEdit"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxImageComboBox"
#pragma link "cxLookAndFeels"
#pragma link "cxDBRichEdit"
#pragma link "cxMemo"
#pragma link "cxRichEdit"
#pragma link "cxSpinEdit"
#pragma link "cxCheckBox"
#pragma link "cxCalendar"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaElementaSprProducerModelInfBlock::TREM_FormaElementaSprProducerModelInfBlock(TComponent* Owner)
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
bool TREM_FormaElementaSprProducerModelInfBlock::Init(void)
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


InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMSprProducerModelInfBlock,IID_IREM_DMSprProducerModelInfBlock,
											 (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

NameInfBlockcxDBButtonEdit->DataBinding->DataSource=DM->DataSourceElement;
IsmcxDBDateEdit->DataBinding->DataSource=DM->DataSourceElement;






//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//----------------------------------------------------------------------------
int TREM_FormaElementaSprProducerModelInfBlock::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TREM_FormaElementaSprProducerModelInfBlock::UpdateForm(void)
{

}
//---------------------------------------------------------------------------
void __fastcall TREM_FormaElementaSprProducerModelInfBlock::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprInfBlock)FormaSpiskaSprInfBlock->kanRelease();


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





void __fastcall TREM_FormaElementaSprProducerModelInfBlock::ActionCloseExecute(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprProducerModelInfBlock::ActionOKExecute(TObject *Sender)
{

if (DM->SaveElement()==true)
		{
		TypeEvent=1;
		Close();

		}
else
	{
	ShowMessage("Ошибка при записи элемента справочника: "+DM->TextError);
	}
}
//---------------------------------------------------------------------------
int TREM_FormaElementaSprProducerModelInfBlock::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

		if (number_procedure_end==ER_ViborInfBlock)
				{
				if (type_event==1)
					{
					EndViborInfBlock();
					}
				FormaSpiskaSprInfBlock=0;
				}



FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}
//-----------------------------------------------------------------------------

void TREM_FormaElementaSprProducerModelInfBlock::OpenFormaSpiskaSprInfBlock(void)
{
if (FormaSpiskaSprInfBlock==0)
		{
		InterfaceGlobalCom->kanCreateObject(ProgId_ART_FormaSpiskaSprInfBlock,IID_IART_FormaSpiskaSprInfBlock,
														(void**)&FormaSpiskaSprInfBlock);
		FormaSpiskaSprInfBlock->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprInfBlock->Vibor=true;
		FormaSpiskaSprInfBlock->NumberProcVibor=ER_ViborInfBlock;
		FormaSpiskaSprInfBlock->IdElement=glStrToInt64(DM->ElementIDIB_REM_SPRMODEL_INF->AsString);
		FormaSpiskaSprInfBlock->UpdateForm();
		}


}
//-----------------------------------------------------------------------------
void TREM_FormaElementaSprProducerModelInfBlock::EndViborInfBlock(void)
{
DM->Element->Edit();
DM->ElementIDIB_REM_SPRMODEL_INF->AsString=
						FormaSpiskaSprInfBlock->DM->TableID_ART_IB->AsString;
DM->ElementNAME_ART_IB->AsString=
					FormaSpiskaSprInfBlock->DM->TableNAME_ART_IB->AsString;
DM->Element->Post();


}
//-----------------------------------------------------------------------------

void __fastcall TREM_FormaElementaSprProducerModelInfBlock::NamePropcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormaSpiskaSprInfBlock();
}
//---------------------------------------------------------------------------


