//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSetValueGenerator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormaSetValueGenerator *FormaSetValueGenerator;
//---------------------------------------------------------------------------
__fastcall TFormaSetValueGenerator::TFormaSetValueGenerator(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
