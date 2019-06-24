//---------------------------------------------------------------------------


#pragma hdrstop

#include "UPrintAnyLabel.h"
#include "UDMSprNom.h"
#include "UDMSprEd.h"
#include "UDMSprFirm.h"
#include "ULabelPrinter.h"
#include "UDMSprOborud.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//-------------------------------------------------------------------
TPrintAnyLabel::TPrintAnyLabel()
{


}
//-----------------------------------------------------------------------------
TPrintAnyLabel::~TPrintAnyLabel()
{


}
//----------------------------------------------------------------------------
void TPrintAnyLabel::PrintLabel(void)
{
if (TypeLabel=="58x30_1")
	{
	PrintLabel58x30_1();
	}
}
//----------------------------------------------------------------------------
void TPrintAnyLabel::PrintLabel58x30_1(void)
{
TLabelPrinter *prn=new TLabelPrinter();
TDMSprNom * nom=new TDMSprNom(Application);
TDMSprEd *ed=new TDMSprEd(Application);

TDMSprFirm * spr_firm=new TDMSprFirm(Application);
spr_firm->OpenElement(IdFirm);

TDMSprOborud * spr_oborud=new TDMSprOborud(Application);
spr_oborud->OpenElement(IdOborud);
try
	{
	nom->OpenElement(IdNom);
	ed->OpenElement(nom->ElementIDBASEDNOM->AsInt64);

	//получим настройки принтера
	prn->Modul=spr_oborud->ElementMODUL_SOBORUD->AsString;
	if (prn->Init()==false) throw Exception(prn->TextError);

	for (int i=0;i<KolLabel;i++)
		{
		prn->Connect(0, 0);
		prn->SetSetup(30,55);
		prn->PrintString(spr_firm->ElementNAMEFIRM->AsString.c_str(),1,0,0,"Arial",true);
		prn->PrintBarCode(ed->ElementSHED->AsString.c_str(),
								10,  //отступ слева
								1,  //тип штрих кода
								2,  //размер шрифта штрих кода,  пункты
								30); //высота    мм
		prn->PrintString(nom->ElementNAMENOM->AsString.c_str(),1,0,0,"Arial",true);
		prn->PrintString(FloatToStr(Price).c_str(),1,0,0,"Arial",true);
		prn->Disconnect();
		}
	}
catch (Exception &exception)
	{
	ShowMessage("Ошибка при печати этикеток: "+prn->TextError+" "+exception.Message);
	}

delete spr_oborud;
delete spr_firm;
delete ed;
delete nom;
delete prn;
}
//----------------------------------------------------------
