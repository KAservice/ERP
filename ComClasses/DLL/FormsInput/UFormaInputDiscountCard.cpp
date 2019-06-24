//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "IAsyncExternalEvent.h"
#include "UFormaInputDiscountCard.h"
#include "UDM.h"
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
__fastcall TFormaInputDiscountCard::TFormaInputDiscountCard(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormaInputDiscountCard::FormCreate(TObject *Sender)
{
InputTextEdit->Text="";
TypeEvent=0;
}
//---------------------------------------------------------------------------
bool TFormaInputDiscountCard::Init(void)
{
bool result=false;

//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
		interf->kanRelease();
		}

	}

result=true;

return result;
}
//--------------------------------------------------------------------------
int TFormaInputDiscountCard::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaInputDiscountCard::FormClose(TObject *Sender,
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

void __fastcall TFormaInputDiscountCard::InputTextEditKeyPress(TObject *Sender,
      char &Key)
{
if (Key==VK_ESCAPE)
		{
		TypeEvent=0;
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

void __fastcall TFormaInputDiscountCard::FormActivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(InterfaceImpl);
		}
	interf->kanRelease();
	}

}
//---------------------------------------------------------------------------
void __fastcall TFormaInputDiscountCard::FormDeactivate(TObject *Sender)
{
//зарегистрируем свой IAsyncExternalEvent в главном модуле для получения событий
if(InterfaceMainObject)
	{
	IAsyncExternalEvent * interf=0;
	InterfaceMainObject->kanQueryInterface(IID_IAsyncExternalEvent,(void**)&interf);
	if (interf)
		{
		interf->SetInterfaceForAsyncExternalEvent(0);
		}
	interf->kanRelease();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaInputDiscountCard::ReadShtrihCodEvent(int number, UnicodeString sh)
{
UnicodeString s=sh;

UnicodeString barcode_for_poisk="";

for (int i=1;i<=s.Length();i++)
	{
	if (s[i]=='0' ||  s[i]=='1' || s[i]=='2' ||	 s[i]=='3' || s[i]=='4' ||
	   s[i]=='5' || s[i]=='6' ||  s[i]=='7' ||  s[i]=='8' || s[i]=='9' )
		{
		barcode_for_poisk=barcode_for_poisk+s[i];
		}
	else
		{
		if (barcode_for_poisk.Length()!=0)
			{
            break;
			}
		}
	}


InputTextEdit->Text=barcode_for_poisk;
}
//---------------------------------------------------------------


