//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaInputCode.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaInputCode::TFormaInputCode(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormaInputCode::FormCreate(TObject *Sender)
{
CodeEdit->Text="";
KolEdit->Text="1";
        
}
//---------------------------------------------------------------------------
bool TFormaInputCode::Init(void)
{
bool result=false;



result=true;

return result;
}
//--------------------------------------------------------------------------
int TFormaInputCode::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaInputCode::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (Vibor==true)
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
		}

		Action=caFree;
		if (flDeleteImpl==true)
			{
			if (FunctionDeleteImpl) FunctionDeleteImpl();
			}
}
//---------------------------------------------------------------------------
void __fastcall TFormaInputCode::CodeEditKeyPress(TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
		{
		KolEdit->SetFocus();
		}

if (Key==VK_ESCAPE)
		{
		TypeEvent=0;
		Close();
		}
	
}
//---------------------------------------------------------------------------

void __fastcall TFormaInputCode::KolEditKeyPress(TObject *Sender, char &Key)
{
if (Key==VK_RETURN)
		{
		TypeEvent=1;
		Code=StrToInt(CodeEdit->Text);
		Kol=StrToFloat(KolEdit->Text);
		Close();
		}

if (Key==VK_ESCAPE)
		{
		TypeEvent=0;
		Close();
		}	
}
//---------------------------------------------------------------------------

