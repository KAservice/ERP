//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UFormaInputText.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaInputText::TFormaInputText(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormaInputText::FormCreate(TObject *Sender)
{
InputTextEdit->Text="";
TypeEvent=0;
}
//---------------------------------------------------------------------------
bool TFormaInputText::Init(void)
{
bool result=false;



result=true;

return result;
}
//--------------------------------------------------------------------------
int TFormaInputText::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void TFormaInputText::UpdateForm(void)
{
NameLabel->Caption=TextMessage;


}
//---------------------------------------------------------------------------
void __fastcall TFormaInputText::FormClose(TObject *Sender,
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

Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormaInputText::InputTextEditKeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_ESCAPE)
		{
		TypeEvent=0;
		InputText="";
		Close();
		}

if (Key==VK_RETURN)
		{
		TypeEvent=1;
		InputText=InputTextEdit->Text;
		Close();
		}	
}
//---------------------------------------------------------------------------

