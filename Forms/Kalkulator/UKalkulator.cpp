//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UKalkulator.h"
#include "UDM.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TKalkulator::TKalkulator(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
InterfaceGlobalCom=0;
TypeEvent=0;
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::FormCreate(TObject *Sender)
{
Tablo->Text="";
TypeEvent=0;
}
//---------------------------------------------------------------------------
bool TKalkulator::Init(void)
{
bool result=false;
if (InterfaceMainObject>0)
	{

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}
return result;
}
//----------------------------------------------------------------------------
int TKalkulator::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::FormClose(TObject *Sender,
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
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::knOKClick(TObject *Sender)
{
TypeEvent=1;
Result=StrToFloat(Tablo->Text);
Close();
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::knCClick(TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn1Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"1";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn2Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"2";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn3Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"3";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn4Click(TObject *Sender)
{
 Tablo->Text=Tablo->Text+"4";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn5Click(TObject *Sender)
{
 Tablo->Text=Tablo->Text+"5";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn6Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"6";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn7Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"7";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn8Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"8";        
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn9Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"9";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::kn0Click(TObject *Sender)
{
Tablo->Text=Tablo->Text+"0";
}
//---------------------------------------------------------------------------
void __fastcall TKalkulator::knCommaClick(TObject *Sender)
{
Tablo->Text=Tablo->Text+",";
}
//---------------------------------------------------------------------------
int TKalkulator::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

return -1;
}
