//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaSpiskaSprUser.h"
#include "IFormaElementaSprUser.h"
#include "UFormaEditUser.h"
#include "IDMQueryRead.h"
#include "IDMQueryUpdate.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxTreeView"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaSpiskaSprUser::TFormaSpiskaSprUser(TComponent* Owner)
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


bool TFormaSpiskaSprUser::Init(void)
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


InterfaceGlobalCom->kanCreateObject("Oberon.DMSprUser.1",IID_IDMSprUser, (void**)&DM);
DM->Init(InterfaceMainObject,InterfaceImpl);

InterfaceGlobalCom->kanCreateObject("Oberon.DMSprGrpUser.1",IID_IDMSprGrpUser, (void**)&DMGrp);
DMGrp->Init(InterfaceMainObject,InterfaceImpl);

cxGrid1DBTableView1->DataController->DataSource=DM->DataSourceTable;
Vibor=false;
TypeEvent-0;;
LabelNameGrp->Caption="Пользователи\\...";

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
int TFormaSpiskaSprUser::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprUser::FormClose(TObject *Sender,
      TCloseAction &Action)
{

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

DM->kanRelease();
DMGrp->kanRelease();
Action=caFree;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TFormaSpiskaSprUser::UpdateForm(void)
{
if (IdUser>0)
        {
		IdGrp=DM->GetIdGrpUser(IdUser);
		}
DM->DataSourceTable->Enabled=false;
DM->OpenTable(IdGrp,AllElement);

DMGrp->OpenTable();

TLocateOptions Opt;
Opt<<loCaseInsensitive;
DM->Table->Locate("ID_USER",IdUser,Opt);
UpdateDerevo();
DM->DataSourceTable->Enabled=true;

}
//---------------------------------------------------------------------------
//-------------------------------------------------------------------
//
void TFormaSpiskaSprUser::UpdateDerevo()
{

//очистим память от предыдущего дерева
if (cxTreeView1->Items->Count>0)
        {
		for (int i=0;i<cxTreeView1->Items->Item[0]->Count;i++)
                {
				delete (__int64*)cxTreeView1->Items->Item[i]->Data;
                }
        }

//
DMGrp->OpenTable();
cxTreeView1->Items->Clear();
__int64 *lpIDGrp=new __int64;
*lpIDGrp=0;

cxTreeView1->Items->AddObject(NULL,"Пользователи",lpIDGrp);

cxTreeView1->Items->Item[0]->Data=lpIDGrp;
DMGrp->Table->First();
while (! DMGrp->Table->Eof)
        {
		__int64 IDGrp=DMGrp->TableIDGRP_SGRPUSER->AsInt64;
		__int64 IDData;
        //ShowMessage("IDGrp="+IntToStr(IDGrp));
		for (int i=0;i<cxTreeView1->Items->Count;i++)
                {

				IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
                //ShowMessage("IDGrp="+IntToStr(IDGrp)+" IDData="+IntToStr(IDData));

                if (IDGrp==IDData)
                        {
						 lpIDGrp=new __int64;
						  *lpIDGrp=DMGrp->TableID_SGRPUSER->AsInt64;
                         // ShowMessage(" Записан ID="+IntToStr(*lpIDGrp));
						 cxTreeView1->Items->AddChildObjectFirst(cxTreeView1->Items->Item[i],
						 DMGrp->TableNAME_SGRPUSER->AsString, lpIDGrp);
                         break;
                       }

                }
        DMGrp->Table->Next();
        }
cxTreeView1->AlphaSort(true);


for (int i=0;i<cxTreeView1->Items->Count;i++)
		{
		__int64 IDData=*(__int64*)cxTreeView1->Items->Item[i]->Data;
				if (IdGrp==IDData)
                        {
						cxTreeView1->Selected=cxTreeView1->Items->Item[i];
                        if(AllElement!=true)
                                {
								LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
                                }
                        break;
                        }
        }
}
//---------------------------------------------------------------------------------
int TFormaSpiskaSprUser::ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{
if (number_procedure_end==ViborGrp)
		{
        UpdateDerevo();
		}

if(number_procedure_end==ViborElement)
        {
		IdUser=DM->TableID_USER->AsInteger;
        IdGrp=0;
		if (cxTreeView1->Selected!=NULL)
                {
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
                }
        UpdateForm();
		}

ViborRekvisit=NO;
return -1;
}
//--------------------------------------------------------------------------
void TFormaSpiskaSprUser::OpenFormElement()
{

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprUser::OpenFormNewElement()
{

}
//--------------------------------------------------------------------------
void TFormaSpiskaSprUser::DeleteElement()
{

}
//--------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprUser::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprUser");	
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprUser::ActionNewGrpUserExecute(TObject *Sender)
{


		IFormaElementaSprGrpUser * FormaGrpElementa;
		InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprGrpUser.1",IID_IFormaElementaSprGrpUser,
													(void**)&FormaGrpElementa);
		FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);

		if (cxTreeView1->Selected!=NULL)
				{
				IdGrp=*(__int64*)cxTreeView1->Selected->Data;
				FormaGrpElementa->DM->NewElement(IdGrp);
				}
		else
				{
				FormaGrpElementa->DM->NewElement(0);
				}

		FormaGrpElementa->NumberProcVibor=ViborGrp;


}
//---------------------------------------------------------------------------




void __fastcall TFormaSpiskaSprUser::ActionPoGrpExecute(TObject *Sender)
{
if (AllElement==true)
        {
        AllElement=false;
		LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";

		IdUser=glStrToInt64(DM->TableID_USER->AsString);
		IdGrp=glStrToInt64(DM->TableIDGRP_USER->AsString);
        }
else
        {
        AllElement=true ;
        LabelNameGrp->Caption="Все элементы...";
        }
UpdateForm();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprUser::ActionNewElementExecute(TObject *Sender)
{
IFormaElementaSprUser * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprUser.1",IID_IFormaElementaSprUser,
													(void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->NewElement(IdGrp);
FormaElementa->NumberProcVibor=ViborElement;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprUser::ActionEditElementExecute(TObject *Sender)
{
IFormaElementaSprUser * FormaElementa;
InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprUser.1",IID_IFormaElementaSprUser,
													(void**)&FormaElementa);
FormaElementa->Init(InterfaceMainObject,InterfaceImpl);
FormaElementa->DM->OpenElement(glStrToInt64(DM->TableID_USER->AsString));
FormaElementa->UpdateForm();
FormaElementa->NumberProcVibor=ViborElement;

}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprUser::ActionDeleteElementExecute(TObject *Sender)
{
DM->DeleteElement(glStrToInt64(DM->TableID_USER->AsString));
DM->OpenTable(IdGrp,AllElement);	
}
//---------------------------------------------------------------------------





void __fastcall TFormaSpiskaSprUser::ActionChangeGrpExecute(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
        {
		DM->ChancheGrp(*(__int64*)cxTreeView1->Selected->Data);
        }	
}
//---------------------------------------------------------------------------



void __fastcall TFormaSpiskaSprUser::ActionEditGrpUserExecute(TObject *Sender)
{

		if (cxTreeView1->Selected!=NULL)
                {
				IFormaElementaSprGrpUser * FormaGrpElementa;
				InterfaceGlobalCom->kanCreateObject("Oberon.FormaElementaSprGrpUser.1",IID_IFormaElementaSprGrpUser,
													(void**)&FormaGrpElementa);
				FormaGrpElementa->Init(InterfaceMainObject,InterfaceImpl);
				FormaGrpElementa->NumberProcVibor=ViborGrp;
				FormaGrpElementa->DM->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
                FormaGrpElementa->UpdateForm();
                }

}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprUser::ActionDeleteGrpUserExecute(TObject *Sender)
{
		if (cxTreeView1->Selected!=NULL)
                {
				DMGrp->DeleteElement(*(__int64*)cxTreeView1->Selected->Data);
				UpdateDerevo();
                }	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprUser::ToolButtonNewUserServerClick(
      TObject *Sender)
{
TFormaEditUser * forma=new TFormaEditUser(Application);
forma->DM_Connection=DM_Connection;
forma->InterfaceGlobalCom=InterfaceGlobalCom;
forma->InterfaceMainObject=InterfaceMainObject;
forma->Init();
if (!forma) return;
forma->Name2User=DM->TableNAME2_USER->AsString;

DMGrp->OpenElement(*(__int64*)cxTreeView1->Selected->Data);
forma->RoleUser=DMGrp->ElementROLE_SGRPUSER->AsString;
forma->UpdateForm();
forma->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprUser::ToolButtonUpdateClick(TObject *Sender)
{
UpdateForm();	
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprUser::cxTreeView1DblClick(TObject *Sender)
{
if (cxTreeView1->Selected!=NULL)
		{
		if(AllElement!=true)
				{
				LabelNameGrp->Caption="...\\ "+cxTreeView1->Selected->Text+" \\";
				}
		IdGrp=*(__int64*)cxTreeView1->Selected->Data;
		DM->OpenTable(IdGrp,AllElement);
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprUser::cxGrid1DBTableView1DblClick(
      TObject *Sender)
{
if (Vibor==true)
		{
		TypeEvent=1;
		DM->OpenElement(glStrToInt64(DM->TableID_USER->AsString));
		Close();
		}
else
		{
		ActionEditElementExecute(0);
		}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprUser::cxGrid1DBTableView1USERIDCustomDrawCell(
      TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
      TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone)
{
AnsiString ATextToDraw;
__int64 id_user;
if (dynamic_cast<TcxGridTableDataCellViewInfo *>(AViewInfo) != NULL)
	{
	ATextToDraw = AViewInfo->GridRecord->DisplayTexts[AViewInfo->Item->Index];
	}
else
	{
	ATextToDraw = VarAsType(AViewInfo->Item->Caption, varString);
	}

id_user=glStrToInt64(ATextToDraw);

	TRect ARec = AViewInfo->Bounds;

	ACanvas->Canvas->FillRect(ARec);
	Graphics::TBitmap *ABitmap = new Graphics::TBitmap();
if (id_user>0)
	{
	ToolBar1->Images->GetBitmap(16,ABitmap);
	}
else
	{
	ToolBar1->Images->GetBitmap(17,ABitmap);
	}
	ACanvas->Canvas->Draw((ARec.Left+ARec.Right-ABitmap->Width)/2,ARec.Top,ABitmap);
	ABitmap->Free();
	ADone = true;
}
//---------------------------------------------------------------------------


void __fastcall TFormaSpiskaSprUser::cxGrid1DBTableView1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
if (Key==VK_RETURN)
		{
if (Vibor==true)
		{
		TypeEvent=1;
		DM->OpenElement(glStrToInt64(DM->TableID_USER->AsString));
		Close();
		}
else
		{
		ActionEditElementExecute(0);
		}
		}
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprUser::ToolButtonNasnRoleAllUserClick(
      TObject *Sender)
{
if (Trim(DM_Connection->UserInfoNAME2_USER->AsString)!="SYSDBA")
	{
	ShowMessage("Назначать роли может только пользователь SYSDBA!");
	return;
	}

IDMSprUser * dm_spr_user;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprUser.1",IID_IDMSprUser,
													(void**)&dm_spr_user);
		dm_spr_user->Init(InterfaceMainObject,InterfaceImpl);
dm_spr_user->OpenTable(0, true);

int kol=0;
dm_spr_user->Table->First();
while(!dm_spr_user->Table->Eof)
	{
	if (Trim(dm_spr_user->TableNAME2_USER->AsString)!="SYSDBA")
		{
		DMGrp->OpenElement(glStrToInt64(dm_spr_user->TableIDGRP_USER->AsString));
		AnsiString role_user= Trim(DMGrp->ElementROLE_SGRPUSER->AsString);
		if (role_user.Length()>0 && dm_spr_user->TableUSERID->AsInteger>0)
			{
			IDMQueryUpdate * q;
			InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryUpdate.1",IID_IDMQueryUpdate,
													(void**)&q);
			q->Init(InterfaceMainObject,InterfaceImpl);
			q->pFIBQ->SQL->Clear();
			q->pFIBQ->SQL->Add("grant "+role_user+" to "+Trim(dm_spr_user->TableNAME2_USER->AsString));
			q->pFIBQ->ExecQuery();
			q->pFIBTr->Commit();
			q->kanRelease();
			kol++;
			}
		}
    dm_spr_user->Table->Next();
	}
	
dm_spr_user->kanRelease();
ShowMessage("Назначены роли "+IntToStr(kol)+" пользователям!");
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprUser::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormaSpiskaSprUser::ToolButtonAddStandartGrupClick(TObject *Sender)

{
__int64 id_grp_user=0;
DMGrp->NewElement(0);
DMGrp->Element->Edit();
DMGrp->ElementNAME_SGRPUSER->AsString="Администратор";
DMGrp->ElementROLE_SGRPUSER->AsString="ADMINISTRATORS";
DMGrp->Element->Post();
DMGrp->SaveElement();

DMGrp->NewElement(0);
DMGrp->Element->Edit();
DMGrp->ElementNAME_SGRPUSER->AsString="Кассир";
DMGrp->ElementROLE_SGRPUSER->AsString="CASHIERS";
DMGrp->Element->Post();
DMGrp->SaveElement();

DMGrp->NewElement(0);
DMGrp->Element->Edit();
DMGrp->ElementNAME_SGRPUSER->AsString="Менеджер";
DMGrp->ElementROLE_SGRPUSER->AsString="MANAGERSS";
DMGrp->Element->Post();
id_grp_user=glStrToInt64(DMGrp->ElementID_SGRPUSER->AsString);
DMGrp->SaveElement();

DM->NewElement(id_grp_user);
DM->Element->Edit();
DM->ElementNAME_USER->AsString="SYSDBA";
DM->ElementNAME2_USER->AsString="SYSDBA";
DM->Element->Post();
DM->SaveElement();


DMGrp->NewElement(0);
DMGrp->Element->Edit();
DMGrp->ElementNAME_SGRPUSER->AsString="Групповое проведение";
DMGrp->ElementROLE_SGRPUSER->AsString="ROLE_DVREGDOC_USER";
DMGrp->Element->Post();
id_grp_user=glStrToInt64(DMGrp->ElementID_SGRPUSER->AsString);
DMGrp->SaveElement();


DM->NewElement(id_grp_user);
DM->Element->Edit();
DM->ElementNAME_USER->AsString="DVREGDOC_USER";
DM->ElementNAME2_USER->AsString="DVREGDOC_USER";
DM->Element->Post();
DM->SaveElement();



DMGrp->NewElement(0);
DMGrp->Element->Edit();
DMGrp->ElementNAME_SGRPUSER->AsString="Обмен";
DMGrp->ElementROLE_SGRPUSER->AsString="ROLE_EXTUSER";
DMGrp->Element->Post();
id_grp_user=glStrToInt64(DMGrp->ElementID_SGRPUSER->AsString);
DMGrp->SaveElement();

DM->NewElement(id_grp_user);
DM->Element->Edit();
DM->ElementNAME_USER->AsString="EXTUSER";
DM->ElementNAME2_USER->AsString="EXTUSER";
DM->Element->Post();
DM->SaveElement();


DMGrp->NewElement(0);
DMGrp->Element->Edit();
DMGrp->ElementNAME_SGRPUSER->AsString="Информация о пользователе";
DMGrp->ElementROLE_SGRPUSER->AsString="ROLE_USERINFO";
DMGrp->Element->Post();
id_grp_user=glStrToInt64(DMGrp->ElementID_SGRPUSER->AsString);
DMGrp->SaveElement();

DM->NewElement(id_grp_user);
DM->Element->Edit();
DM->ElementNAME_USER->AsString="USERINFO";
DM->ElementNAME2_USER->AsString="USERINFO";
DM->Element->Post();
DM->SaveElement();



DMGrp->NewElement(0);
DMGrp->Element->Edit();
DMGrp->ElementNAME_SGRPUSER->AsString="Незарегистрированные пользователи сайта";
DMGrp->ElementROLE_SGRPUSER->AsString="ROLE_WEB_UNKNOWN_USER";
DMGrp->Element->Post();
id_grp_user=glStrToInt64(DMGrp->ElementID_SGRPUSER->AsString);
DMGrp->SaveElement();

DM->NewElement(id_grp_user);
DM->Element->Edit();
DM->ElementNAME_USER->AsString="WEB_UNKNOWN_USER";
DM->ElementNAME2_USER->AsString="WEB_UNKNOWN_USER";
DM->Element->Post();
DM->SaveElement();


DMGrp->NewElement(0);
DMGrp->Element->Edit();
DMGrp->ElementNAME_SGRPUSER->AsString="Зарегистрированные пользователи сайта";
DMGrp->ElementROLE_SGRPUSER->AsString="ROLE_WEB_USER";
DMGrp->Element->Post();
DMGrp->SaveElement();




UpdateForm();
}
//---------------------------------------------------------------------------

