//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_FormaZayavka1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TREM_FormaZayavka1::TREM_FormaZayavka1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
 bool TREM_FormaZayavka1::Init(void)
{
bool result=false;

result=true;

return result;
}
//--------------------------------------------------------------------------
int TREM_FormaZayavka1::Done(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TREM_FormaZayavka1::UpdateForm(void)
{
//

}

//---------------------------------------------------------------------------
int TREM_FormaZayavka1::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{



return -1;
}
//---------------------------------------------------------------------------