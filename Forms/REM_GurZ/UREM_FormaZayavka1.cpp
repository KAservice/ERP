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
int TREM_FormaZayavka1::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									)
{



return -1;
}
//---------------------------------------------------------------------------