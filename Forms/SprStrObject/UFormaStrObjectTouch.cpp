//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "UFormaStrObjectTouch.h"
#include "IDMSprKKM.h"
#include "IDMRegZak.h"
#include "IDMSprUser.h"
#include "IDMSprARM.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaStrObjectTouch::TFormaStrObjectTouch(TComponent* Owner)
        : TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;
}
//---------------------------------------------------------------------------
bool TFormaStrObjectTouch::Init(void)
{
bool result=false;

if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}

IBTr->DefaultDatabase=DM_Connection->pFIBData;
SpisokGrpOb->Database=DM_Connection->pFIBData;
SpisokOb->Database=DM_Connection->pFIBData;
SpisokZak->Database=DM_Connection->pFIBData;

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprStrObject.1",IID_IDMSprStrObject, (void**)&DMGrpObject);
DMGrpObject->Init(InterfaceMainObject,InterfaceImpl);



InterfaceGlobalCom->kanCreateObject("Oberon.DMRegZak.1",IID_IDMRegZak, (void**)&RegZak);
RegZak->Init(InterfaceMainObject,InterfaceImpl);


OpenSpisokGrpObject();
OpenSpisokObject();
OpenSpisokZak();


//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}
//---------------------------------------------------------------------------
int TFormaStrObjectTouch::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaStrObjectTouch::FormClose(TObject *Sender, TCloseAction &Action)
{
if(FormaZakOf)FormaZakOf->kanRelease();

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

SpisokOb->Active=false;
SpisokGrpOb->Active=false;
SpisokZak->Active=false;
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::Button1Click(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------

int TFormaStrObjectTouch::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==EditRekvisitZakaz)
        {
        OpenSpisokObject();
        OpenSpisokZak();
        FormaZakOf=0;
        }



EditRekvisit=NO;
return -1;
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::BitBtnExitClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
void TFormaStrObjectTouch::OpenSpisokGrpObject(void)
{
SpisokGrpOb->Active=false;
SpisokGrpOb->Active=true;
SpisokGrpOb->First();

 if(SpisokGrpOb->Eof!=true){g1->Visible=true;g1->Caption=SpisokGrpObNAME_STROB->AsString;}else{g1->Visible=false;}
 SpisokGrpOb->Next();
 if(SpisokGrpOb->Eof!=true){g2->Visible=true;g2->Caption=SpisokGrpObNAME_STROB->AsString;}else{g2->Visible=false;}
 SpisokGrpOb->Next();
  if(SpisokGrpOb->Eof!=true){g3->Visible=true;g3->Caption=SpisokGrpObNAME_STROB->AsString;}else{g3->Visible=false;}
 SpisokGrpOb->Next();
  if(SpisokGrpOb->Eof!=true){g4->Visible=true;g4->Caption=SpisokGrpObNAME_STROB->AsString;}else{g4->Visible=false;}
 SpisokGrpOb->Next();
  if(SpisokGrpOb->Eof!=true){g5->Visible=true;g5->Caption=SpisokGrpObNAME_STROB->AsString;}else{g5->Visible=false;}
 SpisokGrpOb->Next();
  if(SpisokGrpOb->Eof!=true){g6->Visible=true;g6->Caption=SpisokGrpObNAME_STROB->AsString;}else{g6->Visible=false;}
 SpisokGrpOb->Next();
  if(SpisokGrpOb->Eof!=true){g7->Visible=true;g7->Caption=SpisokGrpObNAME_STROB->AsString;}else{g7->Visible=false;}
 SpisokGrpOb->Next();
  if(SpisokGrpOb->Eof!=true){g8->Visible=true;g8->Caption=SpisokGrpObNAME_STROB->AsString;}else{g8->Visible=false;}
 SpisokGrpOb->Next();
  if(SpisokGrpOb->Eof!=true){g9->Visible=true;g9->Caption=SpisokGrpObNAME_STROB->AsString;}else{g9->Visible=false;}
 SpisokGrpOb->Next();
  if(SpisokGrpOb->Eof!=true){g10->Visible=true;g10->Caption=SpisokGrpObNAME_STROB->AsString;}else{g10->Visible=false;}
}
//---------------------------------------------------------------------------
void TFormaStrObjectTouch::OpenSpisokObject(void)
{
SpisokOb->Active=false;
SpisokOb->ParamByName("IDGRP")->AsInteger=IdGrp;
SpisokOb->Active=true;

SpisokOb->First();
if(SpisokOb->Eof!=true)
        {
        o1->Visible=true;
        o1->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o1->Font->Color=clRed;}
        else {o1->Font->Color=clDefault;}
        }
else{o1->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o2->Visible=true;
        o2->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o2->Font->Color=clRed;}
        else {o2->Font->Color=clDefault;}
        }
else{o2->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o3->Visible=true;
        o3->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o3->Font->Color=clRed;}
        else {o3->Font->Color=clDefault;}
        }
else{o3->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o4->Visible=true;
        o4->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o4->Font->Color=clRed;}
        else {o4->Font->Color=clDefault;}
        }
else{o4->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o5->Visible=true;
        o5->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o5->Font->Color=clRed;}
        else {o5->Font->Color=clDefault;}
        }
else{o5->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o6->Visible=true;
        o6->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o6->Font->Color=clRed;}
        else {o6->Font->Color=clDefault;}
        }
else{o6->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o7->Visible=true;
        o7->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o7->Font->Color=clRed;}
        else {o7->Font->Color=clDefault;}
        }
else{o7->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o8->Visible=true;
        o8->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o8->Font->Color=clRed;}
        else {o8->Font->Color=clDefault;}
        }
else{o8->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o9->Visible=true;
        o9->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o9->Font->Color=clRed;}
        else {o9->Font->Color=clDefault;}
        }
else{o9->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {o10->Visible=true;
        o10->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o10->Font->Color=clRed;}
        else {o10->Font->Color=clDefault;}
        }
else{o10->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o11->Visible=true;
        o11->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o11->Font->Color=clRed;}
        else {o11->Font->Color=clDefault;}
        }
else{o11->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o12->Visible=true;
        o12->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o12->Font->Color=clRed;}
        else {o12->Font->Color=clDefault;}
        }
else{o12->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o13->Visible=true;
        o13->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o13->Font->Color=clRed;}
        else {o13->Font->Color=clDefault;}
        }
else{o13->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o14->Visible=true;
        o14->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o14->Font->Color=clRed;}
        else {o14->Font->Color=clDefault;}
        }
else{o14->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o15->Visible=true;
        o15->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o15->Font->Color=clRed;}
        else {o15->Font->Color=clDefault;}
        }
else{o15->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o16->Visible=true;
        o16->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o16->Font->Color=clRed;}
        else {o16->Font->Color=clDefault;}
        }
else{o16->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o17->Visible=true;
        o17->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o17->Font->Color=clRed;}
        else {o17->Font->Color=clDefault;}
        }
else{o17->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o18->Visible=true;
        o18->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o18->Font->Color=clRed;}
        else {o18->Font->Color=clDefault;}
        }
else{o18->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o19->Visible=true;
        o19->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o19->Font->Color=clRed;}
        else {o19->Font->Color=clDefault;}
        }
else{o19->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o20->Visible=true;
        o20->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o20->Font->Color=clRed;}
        else {o20->Font->Color=clDefault;}
        }
else{o20->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o21->Visible=true;
        o21->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o21->Font->Color=clRed;}
        else {o21->Font->Color=clDefault;}
        }
else{o21->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o22->Visible=true;
        o22->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o22->Font->Color=clRed;}
        else {o22->Font->Color=clDefault;}
        }
else{o22->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o23->Visible=true;
        o23->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o23->Font->Color=clRed;}
        else {o23->Font->Color=clDefault;}
        }
else{o23->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o24->Visible=true;
        o24->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o24->Font->Color=clRed;}
        else {o24->Font->Color=clDefault;}
        }
else{o24->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o25->Visible=true;
        o25->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o25->Font->Color=clRed;}
        else {o25->Font->Color=clDefault;}
        }
else{o25->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o26->Visible=true;
        o26->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o26->Font->Color=clRed;}
        else {o26->Font->Color=clDefault;}
        }
else{o26->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o27->Visible=true;
        o27->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o27->Font->Color=clRed;}
        else {o27->Font->Color=clDefault;}
        }
else{o27->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {o28->Visible=true;
        o28->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o28->Font->Color=clRed;}
        else {o28->Font->Color=clDefault;}
        }
else{o28->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o29->Visible=true;
        o29->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o29->Font->Color=clRed;}
        else {o29->Font->Color=clDefault;}
        }
else{o29->Visible=false;}

SpisokOb->Next();
if(SpisokOb->Eof!=true)
        {
        o30->Visible=true;
        o30->Caption=SpisokObNAME_STROB->AsString;
        if ( PolKolZakazov(SpisokObID_STROB->AsInteger)>0){o30->Font->Color=clRed;}
        else {o30->Font->Color=clDefault;}
        }
else{o30->Visible=false;}
}
//-----------------------------------------------------------------------------
void TFormaStrObjectTouch::OpenSpisokZak(void)
{
SpisokZak->Active=false;
SpisokZak->ParamByName("IDOBJECT")->AsInteger=IdObject;
SpisokZak->Active=true;

SpisokZak->First();
if(SpisokZak->Eof!=true)
        {
        z1->Caption="Сумма: "+FloatToStr(SpisokZakSUM_ZAK->AsFloat);
        z1->Font->Color=clRed;
        }
else{z1->Caption="Новый";z1->Font->Color=clDefault;}

SpisokZak->Next();
if(SpisokZak->Eof!=true)
        {
        z2->Caption="Сумма: "+FloatToStr(SpisokZakSUM_ZAK->AsFloat);
        z2->Font->Color=clRed;
        }
else{z2->Caption="Новый";z2->Font->Color=clDefault;}

SpisokZak->Next();
if(SpisokZak->Eof!=true)
        {
        z3->Caption="Сумма: "+FloatToStr(SpisokZakSUM_ZAK->AsFloat);
        z3->Font->Color=clRed;
        }
else{z3->Caption="Новый";z3->Font->Color=clDefault;}

SpisokZak->Next();
if(SpisokZak->Eof!=true)
        {
        z4->Caption="Сумма: "+FloatToStr(SpisokZakSUM_ZAK->AsFloat);
        z4->Font->Color=clRed;
        }
else{z4->Caption="Новый";z4->Font->Color=clDefault;}

SpisokZak->Next();
if(SpisokZak->Eof!=true)
        {
        z5->Caption="Сумма: "+FloatToStr(SpisokZakSUM_ZAK->AsFloat);
        z5->Font->Color=clRed;
        }
else{z5->Caption="Новый";z5->Font->Color=clDefault;}

SpisokZak->Next();
if(SpisokZak->Eof!=true)
        {
        z6->Caption="Сумма: "+FloatToStr(SpisokZakSUM_ZAK->AsFloat);
        z6->Font->Color=clRed;
        }
else{z6->Caption="Новый";z6->Font->Color=clDefault;}

SpisokZak->Next();
if(SpisokZak->Eof!=true)
        {
        z7->Caption="Сумма: "+FloatToStr(SpisokZakSUM_ZAK->AsFloat);
        z7->Font->Color=clRed;
        }
else{z7->Caption="Новый";z7->Font->Color=clDefault;}

SpisokZak->Next();
if(SpisokZak->Eof!=true)
        {
        z8->Caption="Сумма: "+FloatToStr(SpisokZakSUM_ZAK->AsFloat);
        z8->Font->Color=clRed;
        }
else{z8->Caption="Новый";z8->Font->Color=clDefault;}

SpisokZak->Next();
if(SpisokZak->Eof!=true)
        {
        z9->Caption="Сумма: "+FloatToStr(SpisokZakSUM_ZAK->AsFloat);
        z9->Font->Color=clRed;
        }
else{z9->Caption="Новый";z9->Font->Color=clDefault;}

SpisokZak->Next();
if(SpisokZak->Eof!=true)
        {
        z10->Caption="Сумма: "+FloatToStr(SpisokZakSUM_ZAK->AsFloat);
        z10->Font->Color=clRed;
        }
else{z10->Caption="Новый";z10->Font->Color=clDefault;}
}
//------------------------------------------------------------------------------------------------
int TFormaStrObjectTouch::PolKolZakazov(int IdOb)
{
SpisokZak->Active=false;
SpisokZak->ParamByName("IDOBJECT")->AsInteger=IdOb;
SpisokZak->Active=true;
return SpisokZak->RecordCount;
}
//-------------------------------------------------------------------------
void TFormaStrObjectTouch::OpenFormNewZakaz(void)
{

if (FormaZakOf==NULL)
       {
       if (IdObject>0)
				{
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaZakazOf.1",IID_IFormaZakazOf,
													(void**)&FormaZakOf);
				FormaZakOf->Init(InterfaceMainObject,InterfaceImpl);
				FormaZakOf->NumberProcVibor=EditRekvisitZakaz;
				FormaZakOf->DM->IdTypePrice=glStrToInt64(DM_Connection->ARMInfoIDTPRICEPOD->AsString);
                FormaZakOf->DM->NewDoc(IdObject);
                FormaZakOf->DM->Doc->Edit();
				FormaZakOf->DM->DocIDUSER_ZAK->AsString=DM_Connection->UserInfoID_USER->AsString;
				FormaZakOf->DM->DocIDTYPEPRICE_ZAK->AsString=DM_Connection->ARMInfoIDTPRICEPOD->AsString;
				FormaZakOf->DM->DocNAME_USER->AsString=DM_Connection->UserInfoNAME_USER->AsString;
                FormaZakOf->DM->Doc->Post();
				FormaZakOf->NameObjectZakaza=SpisokObNAME_STROB->AsString;
				FormaZakOf->ObnovitForm();
				FormaZakOf->OpenZakaz();
                }
        }
}

//--------------------------------------------------------------------------
void TFormaStrObjectTouch::OpenFormZakaz(void)
{
if (FormaZakOf==NULL)
        {
        if(IdZakaz!=0)
                {
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaZakazOf.1",IID_IFormaZakazOf,
													(void**)&FormaZakOf);
				FormaZakOf->Init(InterfaceMainObject,InterfaceImpl);
				FormaZakOf->NumberProcVibor=EditRekvisitZakaz;
				FormaZakOf->DM->IdTypePrice=FormaZakOf->DM->DocIDTYPEPRICE_ZAK->AsInteger;
                FormaZakOf->DM->OpenDoc(IdZakaz);
                FormaZakOf->ObnovitForm();
				FormaZakOf->NameObjectZakaza=SpisokObNAME_STROB->AsString;
				FormaZakOf->OpenZakaz();



				if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=
											glStrToInt64(FormaZakOf->DM->DocIDUSER_ZAK->AsString))
                        {
                        FormaZakOf->Prosmotr=true;
						}

                //но администратору разрешим
				if (DM_Connection->UserInfoNAME_USER->AsString=="SYSDBA")
                        {
                        FormaZakOf->Prosmotr=false;
						}
				FormaZakOf->UpdateForm();
                }
         }
}
//--------------------------------------------------------------------------
void TFormaStrObjectTouch::OpenVibZakaz(int Num)
{
SpisokZak->First();
SpisokZak->MoveBy(Num-1);
if(SpisokZak->Eof!=true)
        {
        IdZakaz=SpisokZakID_ZAK->AsInteger;
        OpenFormZakaz();
        }
else
        {
        OpenFormNewZakaz();
        }
}
//---------------------------------------------------------------------------
void TFormaStrObjectTouch::OpenVibGrpObject(int Num)
{
SpisokGrpOb->First();
SpisokGrpOb->MoveBy(Num-1);
if(SpisokGrpOb->Eof!=true)
        {
        IdGrp=SpisokGrpObID_STROB->AsInteger;
        }
else
        {
         IdGrp=0;
        }
OpenSpisokObject();
}
//---------------------------------------------------------------------------
void TFormaStrObjectTouch::OpenZakazVibObject(int Num)
{
SpisokOb->First();
SpisokOb->MoveBy(Num-1);
if(SpisokOb->Eof!=true)
        {
        IdObject=SpisokObID_STROB->AsInteger;
        }
else
        {
        IdObject=0;
        }
OpenSpisokZak();
}
//----------------------------------------------------------------------------
void TFormaStrObjectTouch::ClearButtonObject(void)
{
o1->Down=false;o2->Down=false;o3->Down=false;o4->Down=false;o5->Down=false;
o6->Down=false;o7->Down=false;o8->Down=false;o9->Down=false;o10->Down=false;
o11->Down=false;o12->Down=false;o13->Down=false;o14->Down=false;o15->Down=false;
o16->Down=false;o17->Down=false;o18->Down=false;o19->Down=false;o20->Down=false;
o21->Down=false;o22->Down=false;o23->Down=false;o24->Down=false;o25->Down=false;
o26->Down=false;o27->Down=false;o28->Down=false;o29->Down=false;o30->Down=false;

IdObject=0;
OpenSpisokZak();
}
//-----------------------------------------------------------------------------
//*****************************************************************************
//----------------------------------------------------------------------------
void __fastcall TFormaStrObjectTouch::g1Click(TObject *Sender)
{
OpenVibGrpObject(1);
ClearButtonObject();
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::g2Click(TObject *Sender)
{
OpenVibGrpObject(2);
ClearButtonObject();
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::g3Click(TObject *Sender)
{
OpenVibGrpObject(3);
ClearButtonObject();
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::g4Click(TObject *Sender)
{
OpenVibGrpObject(4);
ClearButtonObject();
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::g5Click(TObject *Sender)
{
OpenVibGrpObject(5);
ClearButtonObject();
}
//---------------------------------------------------------------------------
void __fastcall TFormaStrObjectTouch::g6Click(TObject *Sender)
{
OpenVibGrpObject(6);
ClearButtonObject();
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::g7Click(TObject *Sender)
{
OpenVibGrpObject(7);
ClearButtonObject();
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::g8Click(TObject *Sender)
{
OpenVibGrpObject(8);
ClearButtonObject();
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::g9Click(TObject *Sender)
{
OpenVibGrpObject(9);
ClearButtonObject();
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::g10Click(TObject *Sender)
{
OpenVibGrpObject(10);
ClearButtonObject();
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o1Click(TObject *Sender)
{
OpenZakazVibObject(1);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o2Click(TObject *Sender)
{
OpenZakazVibObject(2);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o3Click(TObject *Sender)
{
OpenZakazVibObject(3);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o4Click(TObject *Sender)
{
 OpenZakazVibObject(4);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o5Click(TObject *Sender)
{
OpenZakazVibObject(5);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o6Click(TObject *Sender)
{
OpenZakazVibObject(6);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o7Click(TObject *Sender)
{
OpenZakazVibObject(7);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o8Click(TObject *Sender)
{
 OpenZakazVibObject(8);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o9Click(TObject *Sender)
{
OpenZakazVibObject(9);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o10Click(TObject *Sender)
{
OpenZakazVibObject(10);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o11Click(TObject *Sender)
{
OpenZakazVibObject(11);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o12Click(TObject *Sender)
{
 OpenZakazVibObject(12);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o13Click(TObject *Sender)
{
OpenZakazVibObject(13);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o14Click(TObject *Sender)
{
 OpenZakazVibObject(14);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o15Click(TObject *Sender)
{
 OpenZakazVibObject(15);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o16Click(TObject *Sender)
{
OpenZakazVibObject(16);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o17Click(TObject *Sender)
{
OpenZakazVibObject(17);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o18Click(TObject *Sender)
{
OpenZakazVibObject(18);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o19Click(TObject *Sender)
{
OpenZakazVibObject(19);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o20Click(TObject *Sender)
{
OpenZakazVibObject(20);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o21Click(TObject *Sender)
{
 OpenZakazVibObject(21);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o22Click(TObject *Sender)
{
OpenZakazVibObject(22);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o23Click(TObject *Sender)
{
OpenZakazVibObject(23);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o24Click(TObject *Sender)
{
 OpenZakazVibObject(24);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o25Click(TObject *Sender)
{
OpenZakazVibObject(25);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o26Click(TObject *Sender)
{
 OpenZakazVibObject(26);
}
//---------------------------------------------------------------------------
void __fastcall TFormaStrObjectTouch::o27Click(TObject *Sender)
{
 OpenZakazVibObject(27);
}
//---------------------------------------------------------------------------
void __fastcall TFormaStrObjectTouch::o28Click(TObject *Sender)
{
 OpenZakazVibObject(28);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o29Click(TObject *Sender)
{
 OpenZakazVibObject(29);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::o30Click(TObject *Sender)
{
 OpenZakazVibObject(30);
}
//---------------------------------------------------------------------------


void __fastcall TFormaStrObjectTouch::z1Click(TObject *Sender)
{
OpenVibZakaz(1);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::z2Click(TObject *Sender)
{
OpenVibZakaz(2);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::z3Click(TObject *Sender)
{
OpenVibZakaz(3);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::z4Click(TObject *Sender)
{
OpenVibZakaz(4);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::z5Click(TObject *Sender)
{
OpenVibZakaz(5);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::z6Click(TObject *Sender)
{
OpenVibZakaz(6);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::z7Click(TObject *Sender)
{
OpenVibZakaz(7);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::z8Click(TObject *Sender)
{
OpenVibZakaz(8);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::z9Click(TObject *Sender)
{
OpenVibZakaz(9);
}
//---------------------------------------------------------------------------

void __fastcall TFormaStrObjectTouch::z10Click(TObject *Sender)
{
OpenVibZakaz(10);   
}
//---------------------------------------------------------------------------

