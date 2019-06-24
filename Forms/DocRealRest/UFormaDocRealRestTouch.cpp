//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaDocRealRestTouch.h"
#include "UDMSprARM.h"
#include "UFiskReg.h"
#include "UDMSprUser.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern TDMSprARM *glARM;
extern bool FrOK;
extern TDMSprUser * glUser;
extern int glIdTypePrice;

//----------- фискальный регистратор -----
extern TFiskReg  *glFR;
extern bool glFRConnect;
//---------------------------------------------------------------------------
__fastcall TFormaDocRealRestTouch::TFormaDocRealRestTouch(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRealRestTouch::FormCreate(TObject *Sender)
{
EditRekvisit=NO;
DM= new TDMDocRealRest(Application);
Prosmotr=false;    //только просмотр
Vibor=false;       //для выбора
IdDoc=0;           //идентификатор текущей записи

SumDocDBText->DataSource=DM->DataSourceDocAll;
OutReady=false;

}
//--------------------------------------------------------------------------
void TFormaDocRealRestTouch::UpdateForm(void)
{
//LabelFirm->Caption="Фирма: "+DM->FirmaNAMEFIRM->AsString;
//LabelSklad->Caption="Склад: "+DM->SkladNAMESKLAD->AsString;
//LabelKlient->Caption="Контрагент: "+DM->KlientNAMEKLIENT->AsString;
//LabelNameDoc->Caption="Акт реализации №"+DM->DocAllNUMDOC->AsString+" от "+DM->DocAllPOSDOC->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRealRestTouch::ButtonCloseClick(TObject *Sender)
{
OutReady=false;
Close();

}
//---------------------------------------------------------------------------
void __fastcall TFormaDocRealRestTouch::FormClose(TObject *Sender,
      TCloseAction &Action)
{
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
delete DM;
Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRestTouch::ButtonSaveClick(TObject *Sender)
{
DM->SaveDoc();
}
//---------------------------------------------------------------------------



void __fastcall TFormaDocRealRestTouch::EndEdit(TObject *Sender)
{


EditRekvisit=NO;
IdDochForm=NULL;

}

//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRestTouch::ButtonOKClick(TObject *Sender)
{
if (DM->SaveDoc()==true)
	{
        OutReady=true;
        if (DM->DvRegDoc()==true)
                {
                Close();
				}
		else
				{
				ShowMessage("Не удалось провести документ! Ошибка:"+DM->TextError);
				}
	}
else
	{
	ShowMessage("Не удалось записать документ! Ошибка:"+DM->TextError);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaDocRealRestTouch::FormResize(TObject *Sender)
{
int TecSumWidth=DBGrid1->Width;
int SumWidth=728;
DBGrid1->Columns->Items[0]->Width=34*TecSumWidth/SumWidth;
DBGrid1->Columns->Items[1]->Width=292*TecSumWidth/SumWidth;
DBGrid1->Columns->Items[2]->Width=52*TecSumWidth/SumWidth;
DBGrid1->Columns->Items[3]->Width=81*TecSumWidth/SumWidth;
DBGrid1->Columns->Items[4]->Width=65*TecSumWidth/SumWidth;
DBGrid1->Columns->Items[5]->Width=77*TecSumWidth/SumWidth;
DBGrid1->Columns->Items[6]->Width=83*TecSumWidth/SumWidth;
}

//--------------------------------------------------------------------------
void __fastcall TFormaDocRealRestTouch::ButtonPrintClick(TObject *Sender)
{

if (DM->SaveDoc()==true)
        {
        OutReady=true;
        }
else
        {
        return;
        }

if (PrintDocFR()==true)
        {

        }
else
        {
        String V="Не удалось напечатать Акт реализации!";
        String Z="Ошибка!";
        Application->MessageBox(V.c_str(),Z.c_str(),MB_OK);
        }
}

//---------------------------------------------------------------------------
bool TFormaDocRealRestTouch::PrintDocFR(void)
{
bool result=false;
if(glFRConnect==false) return result;
String StrPr="";
if (glARM->GetParameter("STR_ZAG_1")!="")
        {
		glFR->PrintString(glARM->GetParameter("STR_ZAG_1"),1,0,0,true,true);
        }

if (glARM->GetParameter("STR_ZAG_2")!="")
        {
		glFR->PrintString(glARM->GetParameter("STR_ZAG_2"),1,0,0,true,true);
        }

if (glARM->GetParameter("STR_ZAG_3")!="")
        {
		glFR->PrintString(glARM->GetParameter("STR_ZAG_3"),1,0,0,true,true);
        }

glFR->PrintString(" ",1,0,0,true,true);
StrPr="        АКТ реализации №"+DM->DocAllNUMDOC->AsString;

glFR->PrintString(StrPr,1,0,0,true,true);
glFR->PrintString("    от "+DM->DocAllPOSDOC->AsString,1,0,0,true,true);

glFR->PrintString(" ",1,0,0,true,true);
glFR->PrintString(DM->DocPRIM_REALREST->AsString,1,0,0,true,true);


glFR->PrintString(" ",1,0,0,true,true);
glFR->PrintString("Покупатель:",1,0,0,true,true);
glFR->PrintString(DM->DocAllNAMEKLIENT->AsString,1,0,0,true,true);


DM->DocT->First();
while(!DM->DocT->Eof)
        {

		if (glFR->PrintString(DM->DocTKRNAMENOM->AsString,1,0,0,true,true)==true){result=true;}else{result=false;}
        StrPr=" ";
        StrPr=FloatToStrF(DM->DocTPRICE_REALRESTT->AsFloat,ffFixed,15,2)
                +" x "+FloatToStr(DM->DocTKOL_REALRESTT->AsFloat)+" "
                +DM->DocTNAMEED->AsString+" = "
                +FloatToStrF(DM->DocTSUM_REALRESTT->AsFloat,ffFixed,15,2);
		if(glFR->PrintString(StrPr,1,0,2,true,true)==true) {result=true;}else {result=false;}
        DM->DocT->Next();
        }

glFR->PrintLine();
glFR->PrintString(" ",1,0,0,true,true);

StrPr="Всего: "+FloatToStrF(DM->DocAllSUMDOC->AsFloat,ffCurrency,10,2);
glFR->PrintString(StrPr,3,0,2,true,true);


glFR->PrintString(" ",1,0,0,true,true);
glFR->PrintString(" ",1,0,0,true,true);


glFR->PrintString("Кассир: ",1,0,0,true,true);
StrPr=glUser->ElementFNAME_USER->AsString;
glFR->PrintString(StrPr,1,0,0,true,true);
glFR->PrintString(" ",1,0,0,true,true);
glFR->PrintString(" ",1,0,0,true,true);
glFR->PrintString("           _________________ ",1,0,0,true,true);

glFR->PrintString(" ",1,0,0,true,true);
glFR->PrintString(" ",1,0,0,true,true);
glFR->PrintString("Покупатель _________________ ",1,0,0,true,true);

for(int i=0;i<7;i++)
        {
        glFR->PrintString(" ",1,0,0,true,true);
        }


if (glFR->Cut(1)==true)
        {
        result=true;
        }


return result;



}
//---------------------------------------------------------------------------
