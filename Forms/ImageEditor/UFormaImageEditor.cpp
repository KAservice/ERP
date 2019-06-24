//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaImageEditor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxImage"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaImageEditor::TFormaImageEditor(TComponent* Owner)
	: TForm(Owner)
{

FunctionDeleteImpl=0;
flDeleteImpl=true;

TypeEvent=0;

}
//---------------------------------------------------------------------------
void __fastcall TFormaImageEditor::FormCreate(TObject *Sender)
{
Vibor=false;
TypeEvent=0;
}
//---------------------------------------------------------------------------
//-----------------------------------------------------------------------
bool TFormaImageEditor::Init(void)
{
bool result=false;




result=true;
return result;
}
//---------------------------------------------------------------------------
int TFormaImageEditor::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaImageEditor::FormClose(TObject *Sender, TCloseAction &Action)

{



Action=caFree;


if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
//из этой формы открыта другая для выбора
//обработка события выбора в другой форме (которая была открыта из этой для выбора чего-то)
int TFormaImageEditor::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект (форму в которой производится выбор)
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

return 1;
}
//--------------------------------------------------------------------------
void TFormaImageEditor::LoadFromFile(UnicodeString file_name)
{

cxImage1->Picture->LoadFromFile(file_name);
}
//---------------------------------------------------------------------------
