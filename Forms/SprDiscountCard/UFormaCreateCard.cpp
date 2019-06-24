//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaCreateCard.h"
#include "UDM.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IDMSprKlient.h"
#include "IDMSprDiscountCard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxTextEdit"
#pragma link "cxCalc"
#pragma link "cxCheckBox"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxButtonEdit"
#pragma link "cxButtons"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxImageComboBox"
#pragma link "cxCheckGroup"
#pragma link "cxRadioGroup"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaCreateCard::TFormaCreateCard(TComponent* Owner)
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
bool TFormaCreateCard::Init(void)
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


StartNumbercxTextEdit->Text="";
EndNumbercxTextEdit->Text="";
PrefiksCardcxTextEdit->Text="";
NameGrpKlientcxButtonEdit->Text="";
NameKlientcxButtonEdit->Text="";
VidCardcxButtonEdit->Text="";
NameCardcxTextEdit->Text="";
NameKlientcxTextEdit->Text="";


result=true;
return result;
}
//----------------------------------------------------------------------------
int  TFormaCreateCard::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaCreateCard::FormClose(TObject *Sender, TCloseAction &Action)

{
if(FormaSpiskaSprKlient)FormaSpiskaSprKlient->kanRelease();
if(FormaSpiskaSprVidDiscountCard)FormaSpiskaSprVidDiscountCard->kanRelease();
if(SpisokGrpKlient)SpisokGrpKlient->kanRelease();


Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
int TFormaCreateCard::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ER_ViborKlient)
		{
		if (type_event==1)    //выбор сделан
			{
			EndViborKlient();
			}
		FormaSpiskaSprKlient=0;
		}


if (number_procedure_end==ER_ViborTypeCard)
		{
		if (type_event==1)    //выбор сделан
			{
			EndViborVidDiscountCard();
			}
		FormaSpiskaSprVidDiscountCard=0;
		}

if (number_procedure_end==ER_ViborGrpKlient)
        {
		if (type_event==1)
                {
				IdGrpKlient=SpisokGrpKlient->DM->ElementIDGRPKL->AsInt64;
                NameGrpKlientcxButtonEdit->Text=SpisokGrpKlient->DM->ElementNAMEGRPKL->AsString;
                }
        SpisokGrpKlient=0;
		}

FindNextControl(ActiveControl,true,true,false)->SetFocus();
return -1;
}

//--------------------------------------------------------------------------
void __fastcall TFormaCreateCard::EndViborKlient(void)
{
	IdKlient=glStrToInt64(FormaSpiskaSprKlient->DM->TableIDKLIENT->AsString);
	NameKlient=FormaSpiskaSprKlient->DM->TableNAMEKLIENT->AsString;
	NameKlientcxButtonEdit->Text=NameKlient;
}
//----------------------------------------------------------------------------
void TFormaCreateCard::ViborKlient(void)
{
if (FormaSpiskaSprKlient==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprKlient.1",IID_IFormaSpiskaSprKlient,
													(void**)&FormaSpiskaSprKlient);
	FormaSpiskaSprKlient->Init(InterfaceMainObject,InterfaceImpl);
	FormaSpiskaSprKlient->Vibor=true;
	FormaSpiskaSprKlient->UpdateForm();
	FormaSpiskaSprKlient->NumberProcVibor=ER_ViborKlient;
	}
}
//----------------------------------------------------------------------------
void TFormaCreateCard::ViborVidDiscountCard(void)
{
if (FormaSpiskaSprVidDiscountCard==0)
	{
	InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprVidDiscountCard.1",IID_IFormaSpiskaSprVidDiscountCard,
													(void**)&FormaSpiskaSprVidDiscountCard);
	FormaSpiskaSprVidDiscountCard->Init(InterfaceMainObject,InterfaceImpl);
	//настройка формы
	FormaSpiskaSprVidDiscountCard->Vibor=true;
	FormaSpiskaSprVidDiscountCard->NumberProcVibor=ER_ViborTypeCard;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormaCreateCard::EndViborVidDiscountCard(void)
{
IdVidCard=glStrToInt64(FormaSpiskaSprVidDiscountCard->DM->TableID_SVID_DCARD->AsString);
NameVidCard=FormaSpiskaSprVidDiscountCard->DM->TableNAME_SVID_DCARD->AsString;
VidCardcxButtonEdit->Text=NameVidCard;
}
//------------------------------------------------------------------------------
void __fastcall TFormaCreateCard::NameKlientcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborKlient();
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateCard::VidCardcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
ViborVidDiscountCard();
}
//---------------------------------------------------------------------------
void TFormaCreateCard::OpenFormSpiskaSprGrpKlient(void)
{
if (SpisokGrpKlient==NULL)
        {
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaSpiskaSprGrpKlient.1",IID_IFormaSpiskaSprGrpKlient,
													(void**)&SpisokGrpKlient);
		SpisokGrpKlient->Init(InterfaceMainObject,InterfaceImpl);
        SpisokGrpKlient->Vibor=true;
		SpisokGrpKlient->NumberProcVibor=ER_ViborGrpKlient;
        }

}
//--------------------------------------------------------------------------
void __fastcall TFormaCreateCard::NameGrpKlientcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex)
{
OpenFormSpiskaSprGrpKlient();
}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateCard::cxButtonCreateClick(TObject *Sender)
{

int StartNumberCard=StrToInt(StartNumbercxTextEdit->Text);
int EndNumberCard=StrToInt(EndNumbercxTextEdit->Text);
int TecNumberCard=StartNumberCard;

IDMSprDiscountCard * DMCard;
InterfaceGlobalCom->kanCreateObject("Oberon.DMSprDiscountCard.1",IID_IDMSprDiscountCard, (void**)&DMCard);
DMCard->Init(InterfaceMainObject,InterfaceImpl);

IDMSprKlient * DMKlient;
InterfaceGlobalCom->kanCreateObject(ProgId_DMSprKlient,IID_IDMSprKlient, (void**)&DMKlient);
DMKlient->Init(InterfaceMainObject,InterfaceImpl);


while(TecNumberCard <= EndNumberCard)
	{
	__int64 id_tec_klient=0;
	//создаем клиента если надо
	if (NewKlientcxRadioButton->Checked==true)
		{
		DMKlient->NewElement(IdGrpKlient);
		id_tec_klient=glStrToInt64(DMKlient->ElementIDKLIENT->AsString);
		DMKlient->Element->Edit();
		DMKlient->ElementIDGRPKLIENT->AsString=IdGrpKlient;
		DMKlient->ElementNAMEKLIENT->AsString=NameKlientcxTextEdit->Text+IntToStr(TecNumberCard);
		DMKlient->Element->Post();
		if (DMKlient->SaveElement()==false)
			{
			UnicodeString V="Ошибка при записи клиента "+DMKlient->TextError+" Продолжить?";
			UnicodeString Z="Внимание!";
			if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
                {
                }
			else
                {
                return;
				}

			}
		}

	if (ViborKlientcxRadioButton->Checked==true)
		{
        id_tec_klient=IdKlient;
		}
	//создаем карту

	DMCard->NewElement(id_tec_klient);
	DMCard->Element->Edit();
	DMCard->ElementACT_SDISCOUNT_CARD->AsInteger=1;
	DMCard->ElementIDVID_SDISCOUNT_CARD->AsString=IdVidCard;
	DMCard->ElementTYPE_SDISCOUNT_CARD->AsString=cxImageComboBoxTypeCard->EditValue;
	DMCard->ElementNAME_SDISCOUNT_CARD->AsString="Карта "+IntToStr(TecNumberCard)+
	"  "+VidCardcxButtonEdit->EditText+" Скидка "+ProcentcxCalcEdit->Text;

	DMCard->ElementFL_DISC_SDISCOUNT_CARD->AsInteger=1;
	DMCard->ElementPRSK_SDISCOUNT_CARD->AsFloat=StrToFloat(ProcentcxCalcEdit->Text);

	if (SingleCardcxCheckBox->Checked==true)
		{
		DMCard->ElementSINGLE_SDISCOUNT_CARD->AsInteger=1;
		}
	else
		{
		DMCard->ElementSINGLE_SDISCOUNT_CARD->AsInteger=0;
		}


	//код карты
	DMCard->ElementCODE_SDISCOUNT_CARD->AsInteger=TecNumberCard;
	//получим штрих код
	UnicodeString ShtrihCod=IntToStr(DMCard->ElementCODE_SDISCOUNT_CARD->AsInteger);
	ShtrihCod=glDopStrL(ShtrihCod,"0",10);
	ShtrihCod=PrefiksCardcxTextEdit->Text+ShtrihCod;
	DMCard->ElementSHCODE_SDISCOUNT_CARD->AsString=glAddEAN13(ShtrihCod);

	DMCard->Element->Post();



	if (DMCard->SaveElement()==false)
			{
			UnicodeString V="Ошибка при записи Карты "+DMCard->TextError+" Продолжить?";
			UnicodeString Z="Внимание!";
			if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDYES)
                {
                }
			else
                {
                return;
				}

			}


	TecNumberCard++;
	}

DMCard->kanRelease();
DMKlient->kanRelease();


ShowMessage("Выполнено!");

}
//---------------------------------------------------------------------------

void __fastcall TFormaCreateCard::cxButtonCloseClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------



