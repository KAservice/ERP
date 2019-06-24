//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormIndicator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormIndicator::TFormIndicator(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFormIndicator::Start(void)
{
ProgressBar1->Max=Max;
ProgressBar1->Step=Step;

}
//-------------------------------------------------------
void TFormIndicator::StepIt(void)
{
ProgressBar1->StepIt();

}
//------------------------------------------------------