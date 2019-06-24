//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSpiskaSprBVNomTouch.h"
#include "IDMSprARM.h"
#include "IDMRegOstNom.h"
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
__fastcall TFormaSpiskaSprBVNomTouch::TFormaSpiskaSprBVNomTouch(TComponent* Owner)
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
bool TFormaSpiskaSprBVNomTouch::Init(void)
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
Grp->Database=DM_Connection->pFIBData;
El->Database=DM_Connection->pFIBData;


Kol=1;
IdPod=glStrToInt64(DM_Connection->ARMInfoIDPODR_SARM->AsString);
IdGrp=0;
OpenNameGrp();
OpenNameElement();

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
int TFormaSpiskaSprBVNomTouch::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBVNomTouch::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(FormaSpiskaSprEdTouch)FormaSpiskaSprEdTouch->kanRelease();

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
Grp->Active=false;
El->Active=false;
Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaSpiskaSprBVNomTouch::BitBtnCloseClick(
      TObject *Sender)
{
TypeEvent=0;
Close();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprBVNomTouch::UpdateButtonGRP(TSpeedButton * but)
{
        but->Visible=true;
        but->Caption="";
        TRect R;
        char Buff[255];
        but->Glyph->Canvas->Font->Color=clNavy;
        but->Glyph->Canvas->Font->Style=TFontStyles()<<fsBold;
        but->Glyph->Width  = but->Width - 6;
        but->Glyph->Height = but->Height - 6;
        R = Bounds(0, 0, but->Glyph->Width,0);
        StrPCopy(Buff, GrpNAME_GBVNOM->AsString);
        DrawText(but->Glyph->Canvas->Handle,Buff,StrLen(Buff),&R,DT_CENTER | DT_WORDBREAK | DT_CALCRECT);
        OffsetRect(R,(but->Glyph->Width - R.Right)/2 ,
          (but->Glyph->Height - R.Bottom)/2);
        DrawText(but->Glyph->Canvas->Handle,Buff,StrLen(Buff),&R, DT_CENTER | DT_WORDBREAK);
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprBVNomTouch::UpdateButtonEl(TBitBtn * but)
{
        but->Visible=true;
        but->Caption="";
        TRect R;
        char Buff[255];
        if (GetColor()==true)
                {
                but->Glyph->Canvas->Font->Color=clNavy;
                }
        else
                {
                but->Glyph->Canvas->Font->Color=clRed;
                }

        but->Glyph->Canvas->Font->Style=TFontStyles()<<fsBold;
        but->Glyph->Width  = but->Width - 6;
        but->Glyph->Height = but->Height - 6;
        R = Bounds(0, 0, but->Glyph->Width,0);
        but->Glyph->Canvas->FillRect(Rect(0,0,but->Width,but->Height));
        StrPCopy(Buff,ElKRNAMENOM->AsString);
        DrawText(but->Glyph->Canvas->Handle,Buff,StrLen(Buff),&R,DT_CENTER | DT_WORDBREAK | DT_CALCRECT);
        OffsetRect(R,(but->Glyph->Width - R.Right)/2 ,
          (but->Glyph->Height - R.Bottom)/2);
        DrawText(but->Glyph->Canvas->Handle,Buff,StrLen(Buff),&R, DT_CENTER | DT_WORDBREAK);
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprBVNomTouch::OpenNameGrp(void)
{
 Grp->Active=false;
 Grp->ParamByName("IDPOD")->AsString=IdPod;
 Grp->Active=true;
 Grp->First();

 if(Grp->Eof!=true)
        {
        g1->Visible=true;
        UpdateButtonGRP(g1);
        }
 else{g1->Visible=false;}
 Grp->Next();

 if(Grp->Eof!=true)
        {
        g2->Visible=true;
        UpdateButtonGRP(g2);
        }
 else
        {
        g2->Visible=false;
        }

 Grp->Next();
 if(Grp->Eof!=true)
        {
        g3->Visible=true;
        UpdateButtonGRP(g3);

        }
 else{g3->Visible=false;}

 Grp->Next();
 if(Grp->Eof!=true)
        {
        g4->Visible=true;
        UpdateButtonGRP(g4);
        }
 else{g4->Visible=false;}

 Grp->Next();
 if(Grp->Eof!=true){g5->Visible=true;UpdateButtonGRP(g5);}else{g5->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g6->Visible=true;UpdateButtonGRP(g6);}else{g6->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g7->Visible=true;UpdateButtonGRP(g7);}else{g7->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g8->Visible=true;UpdateButtonGRP(g8);}else{g8->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g9->Visible=true;UpdateButtonGRP(g9);}else{g9->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g10->Visible=true;UpdateButtonGRP(g10);} else{g10->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g11->Visible=true;UpdateButtonGRP(g11);} else{g11->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g12->Visible=true;UpdateButtonGRP(g12);} else{g12->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g13->Visible=true;UpdateButtonGRP(g13);} else{g13->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g14->Visible=true;UpdateButtonGRP(g14);} else{g14->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g15->Visible=true;UpdateButtonGRP(g15);} else{g15->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g16->Visible=true;UpdateButtonGRP(g16);}  else{g16->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g17->Visible=true;UpdateButtonGRP(g17);} else{g17->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g18->Visible=true;UpdateButtonGRP(g18);}else{g18->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g19->Visible=true;UpdateButtonGRP(g19);}else{g19->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g20->Visible=true;UpdateButtonGRP(g20);}else{g20->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g21->Visible=true;UpdateButtonGRP(g21);}else{g21->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g22->Visible=true;UpdateButtonGRP(g22);}else{g22->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g23->Visible=true;UpdateButtonGRP(g23);}else{g23->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g24->Visible=true;UpdateButtonGRP(g24);}else{g24->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g25->Visible=true;UpdateButtonGRP(g25);}else{g25->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g26->Visible=true;UpdateButtonGRP(g26);}else{g26->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g27->Visible=true;UpdateButtonGRP(g27);}else{g27->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g28->Visible=true;UpdateButtonGRP(g28);}else{g28->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g29->Visible=true;UpdateButtonGRP(g29);}else{g29->Visible=false;}
 Grp->Next();
 if(Grp->Eof!=true){g30->Visible=true;UpdateButtonGRP(g30);}else{g30->Visible=false;}
}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprBVNomTouch::OpenNameElement(void)
{
El->Active=false;
El->ParamByName("IDGRP")->AsString=IdGrp;
El->ParamByName("IDPOD")->AsString=IdPod;
El->Active=true;
El->First();

if(El->Eof!=true)
        {
        UpdateButtonEl(b1) ;
        }
else{b1->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        b2->Visible=true;
        b2->Caption=ElKRNAMENOM->AsString;
        UpdateButtonEl(b2);
        }
else{b2->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        b3->Visible=true;
        b3->Caption=ElKRNAMENOM->AsString;
        UpdateButtonEl(b3);
        }
else{b3->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
       // b4->Visible=true;
       // b4->Caption=ElKRNAMENOM->AsString;
        UpdateButtonEl(b4) ;
        }
else{b4->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
       // b5->Visible=true;
       // b5->Caption=ElKRNAMENOM->AsString;
       UpdateButtonEl(b5) ;
        }
else{b5->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        //b6->Visible=true;
        //b6->Caption=ElKRNAMENOM->AsString;
        UpdateButtonEl(b6) ;
        }
else{b6->Visible=false;}

El->Next();
if(El->Eof!=true)
        {

        UpdateButtonEl(b7) ;
        }
else{b7->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b8) ;
        }
else{b8->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b9) ;
        }
else{b9->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b10) ;
        }
else{b10->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b11) ;
        }
else{b11->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b12) ;
        }
else{b12->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b13) ;
        }
else{b13->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b14) ;
        }
else{b14->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b15) ;
        }
else{b15->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b16) ;
        }
else{b16->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b17) ;
        }
else{b17->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b18) ;
        }
else{b18->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b19) ;
        }
else{b19->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b20) ;
        }
else{b20->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b21) ;
        }
else{b21->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b22) ;
        }
else{b22->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b23) ;
        }
else{b23->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b24) ;
        }
else{b24->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b25) ;
        }
else{b25->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b26) ;
        }
else{b26->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b27) ;
        }
else{b27->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b28) ;
        }
else{b28->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b29) ;
        }
else{b29->Visible=false;}

El->Next();
if(El->Eof!=true)
        {
        UpdateButtonEl(b30) ;
        }
else{b30->Visible=false;}

}
//----------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g1Click(TObject *Sender)
{
OpenGrp(1);

}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g2Click(TObject *Sender)
{
OpenGrp(2);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g3Click(TObject *Sender)
{
OpenGrp(3);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g4Click(TObject *Sender)
{
OpenGrp(4);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g5Click(TObject *Sender)
{
OpenGrp(5);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g6Click(TObject *Sender)
{
OpenGrp(6);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g7Click(TObject *Sender)
{
OpenGrp(7);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g8Click(TObject *Sender)
{
OpenGrp(8);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g9Click(TObject *Sender)
{
OpenGrp(9);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g10Click(TObject *Sender)
{
OpenGrp(10);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g11Click(TObject *Sender)
{
OpenGrp(11);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g12Click(TObject *Sender)
{
OpenGrp(12);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g13Click(TObject *Sender)
{
OpenGrp(13);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g14Click(TObject *Sender)
{
OpenGrp(14);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g15Click(TObject *Sender)
{
OpenGrp(15);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g16Click(TObject *Sender)
{
OpenGrp(16);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g17Click(TObject *Sender)
{
OpenGrp(17);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g18Click(TObject *Sender)
{
OpenGrp(18);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g19Click(TObject *Sender)
{
OpenGrp(19);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g20Click(TObject *Sender)
{
OpenGrp(20);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g21Click(TObject *Sender)
{
OpenGrp(21);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g22Click(TObject *Sender)
{
OpenGrp(22);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g23Click(TObject *Sender)
{
OpenGrp(23);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g24Click(TObject *Sender)
{
OpenGrp(24);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g25Click(TObject *Sender)
{
OpenGrp(25);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g26Click(TObject *Sender)
{
OpenGrp(26);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g27Click(TObject *Sender)
{
OpenGrp(27);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g28Click(TObject *Sender)
{
OpenGrp(28);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g29Click(TObject *Sender)
{
OpenGrp(29);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::g30Click(TObject *Sender)
{
OpenGrp(30);
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprBVNomTouch::OpenFormInKol(void)
{

///

}
//---------------------------------------------------------------------------
void TFormaSpiskaSprBVNomTouch::OpenGrp(int Num)
{

Grp->First();
Grp->MoveBy(Num-1);
if(Grp->Eof!=true)
        {
		IdGrp=glStrToInt64(GrpID_GBVNOM->AsString);
        }
else
        {
         IdGrp=0;
        }

OpenNameElement();
}
//---------------------------------------------------------------------------
void TFormaSpiskaSprBVNomTouch::OpenElement(int Num)
{
El->First();
El->MoveBy(Num-1);
if(El->Eof!=true)
        {
		IdNom=glStrToInt64(ElIDNOM_BVNOM->AsString);


        if(MnVibor==true)
                {
                OpenFormSpiskaSprEd();
                }
        else
                {
                TypeEvent=1;
				Close();

                }
        }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int TFormaSpiskaSprBVNomTouch::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ViborEdinica)
        {
                //устанавливаем  IdEd и количество
                //посылаем сообщение форме родителю
		if (type_event==1)
				{
                IdEd=glStrToInt64(FormaSpiskaSprEdTouch->ElIDED->AsString);
                NameEd=FormaSpiskaSprEdTouch->ElNAMEED->AsString;
                KFEd=FormaSpiskaSprEdTouch->ElKFED->AsFloat;
				Kol=FormaSpiskaSprEdTouch->Kol;
				TypeEvent=1;
				//получим ICallBack для передачи события в вызывающую форму
						if(InterfaceOwnerObject)
							{
							IkanCallBack * i_callback=0;
							InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
							if (i_callback)
								{
								i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
								i_callback->kanRelease();
								}
							}
               }
        FormaSpiskaSprEdTouch=0;
        }



EditRekvisit=NO;
return -1;
}
//-----------------------------------------------------------------------------
void TFormaSpiskaSprBVNomTouch::OpenFormSpiskaSprEd(void)
{
if (FormaSpiskaSprEdTouch==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpSprEdTouch.1",IID_IFormaSpiskaSprEdTouch,
													(void**)&FormaSpiskaSprEdTouch);
		FormaSpiskaSprEdTouch->NameNom=ElNAMENOM->AsString;
		FormaSpiskaSprEdTouch->Init(InterfaceMainObject,InterfaceImpl);
		FormaSpiskaSprEdTouch->Vibor=true;
		FormaSpiskaSprEdTouch->NumberProcVibor=ViborEdinica;
		FormaSpiskaSprEdTouch->IdFirm=IdFirm;
		FormaSpiskaSprEdTouch->IdSklad=IdSklad;
		FormaSpiskaSprEdTouch->IdNom=glStrToInt64(ElIDNOM_BVNOM->AsString);
		FormaSpiskaSprEdTouch->IdBasEd=glStrToInt64(ElIDBASEDNOM->AsString);
        FormaSpiskaSprEdTouch->TypeNom=ElTNOM->AsInteger;
        FormaSpiskaSprEdTouch->OpenSpisokEd();
		IdNom=glStrToInt64(ElIDNOM_BVNOM->AsString);
        }
}
//------------------------------------------------------------------------------
bool TFormaSpiskaSprBVNomTouch::GetColor(void)
{
bool result=false;
if (ElTNOM->AsInteger==0)  //если товар
        {
		IDMRegOstNom * DMRegOstNom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMRegOstNom.1",IID_IDMRegOstNom,
													(void**)&DMRegOstNom);
		DMRegOstNom->Init(InterfaceMainObject,InterfaceImpl);
		if (IdFirm==0 && IdSklad==0)
			{
			DMRegOstNom->IdFirm=glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString);
			DMRegOstNom->IdSklad=glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString);
			}
		else
			{
			DMRegOstNom->IdFirm=IdFirm;
			DMRegOstNom->IdSklad=IdSklad;
			}
        DMRegOstNom->IdNom=glStrToInt64(ElIDNOM_BVNOM->AsString);
        DMRegOstNom->GetOstatok();
        if (DMRegOstNom->KolOst>0)
                {
                result=true;
                }
        else
                {
                result=false;
                }

        DMRegOstNom->kanRelease();
        }
else
        {
        result=true;
        }
return result;
}
//---------------------------------------------------------------------------





void __fastcall TFormaSpiskaSprBVNomTouch::b1Click(TObject *Sender)
{
OpenElement(1);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b2Click(TObject *Sender)
{
OpenElement(2);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b3Click(TObject *Sender)
{
OpenElement(3);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b4Click(TObject *Sender)
{
OpenElement(4);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b5Click(TObject *Sender)
{
OpenElement(5);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b6Click(TObject *Sender)
{
OpenElement(6);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b7Click(TObject *Sender)
{
OpenElement(7);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b8Click(TObject *Sender)
{
OpenElement(8);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b9Click(TObject *Sender)
{
OpenElement(9);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b10Click(TObject *Sender)
{
OpenElement(10);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b11Click(TObject *Sender)
{
OpenElement(11);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b12Click(TObject *Sender)
{
OpenElement(12);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b13Click(TObject *Sender)
{
OpenElement(13);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b14Click(TObject *Sender)
{
OpenElement(14);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b15Click(TObject *Sender)
{
OpenElement(15);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b16Click(TObject *Sender)
{
OpenElement(16);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b17Click(TObject *Sender)
{
OpenElement(17);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b18Click(TObject *Sender)
{
OpenElement(18);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b19Click(TObject *Sender)
{
OpenElement(19);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b20Click(TObject *Sender)
{
OpenElement(20);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b21Click(TObject *Sender)
{
OpenElement(21);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b22Click(TObject *Sender)
{
OpenElement(22);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b23Click(TObject *Sender)
{
OpenElement(23);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b24Click(TObject *Sender)
{
OpenElement(24);
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b25Click(TObject *Sender)
{
OpenElement(25);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b26Click(TObject *Sender)
{
OpenElement(26);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b27Click(TObject *Sender)
{
OpenElement(27);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b28Click(TObject *Sender)
{
OpenElement(28);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b29Click(TObject *Sender)
{
OpenElement(29);        
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprBVNomTouch::b30Click(TObject *Sender)
{
OpenElement(30);        
}
//---------------------------------------------------------------------------

