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
//�� ���� ����� ������� ������ ��� ������
//��������� ������� ������ � ������ ����� (������� ���� ������� �� ���� ��� ������ ����-��)
int TFormaImageEditor::ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������ (����� � ������� ������������ �����)
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
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
