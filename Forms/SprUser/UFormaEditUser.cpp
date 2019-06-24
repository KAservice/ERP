//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaEditUser.h"

#include "IDMQueryUpdate.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IB_Services"
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTextEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaEditUser::TFormaEditUser(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

bool TFormaEditUser::Init(void)
{
bool result=false;

PasswordEdit->Text="";
Password2Edit->Text="";

//����������
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;
return result;
}
//---------------------------------------------------------------------------
void __fastcall TFormaEditUser::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaEditUser::UpdateForm(void)
{
NameUserLabel->Caption="��� �������� ������������: "+DM_Connection->NameUser;
Name2UserLabel->Caption="��� �������������� ������������: "+Name2User;
NameServerLabel->Caption="��� ������� ���� ������ Firebird: "+DM_Connection->NameServer;
RoleUserLabel->Caption="���� �������������� ������������: "+RoleUser;
}
//---------------------------------------------------------------------------





void __fastcall TFormaEditUser::cxButtonAddRoleClick(TObject *Sender)
{
if (Name2User=="SYSDBA")
	{
	UnicodeString s="������������ SYSDBA ���� �� �����������!";
	Application->MessageBox(s.c_str(),
				L"������!", MB_OK + MB_ICONEXCLAMATION);
	return;
	}

if (DM_Connection->NameUser!="SYSDBA")
	{
	UnicodeString s="������������ ���� �������!";
	Application->MessageBox(s.c_str(),
				L"������!", MB_OK + MB_ICONEXCLAMATION);
	return;
	}


IDMQueryUpdate * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryUpdate.1",IID_IDMQueryUpdate,
													(void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("grant "+RoleUser+" to "+Name2User);
q->pFIBQ->ExecQuery();
q->pFIBTr->Commit();
q->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TFormaEditUser::cxButtonDelRoleClick(TObject *Sender)
{
if (Name2User=="SYSDBA")
	{
	UnicodeString s="������������ SYSDBA ���� �� ����������!";
	Application->MessageBox(s.c_str(),
				L"������!", MB_OK + MB_ICONEXCLAMATION);
	return;
	}

if (DM_Connection->NameUser!="SYSDBA")
	{
	UnicodeString s="������������ ���� �������!";
	Application->MessageBox(s.c_str(),
				L"������!", MB_OK + MB_ICONEXCLAMATION);
	return;
	}

IDMQueryUpdate * q;
InterfaceGlobalCom->kanCreateObject("Oberon.DMQueryUpdate.1",IID_IDMQueryUpdate,
													(void**)&q);
q->Init(InterfaceMainObject,0);
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("revoke "+RoleUser+" from "+Name2User);
q->pFIBQ->ExecQuery();
q->pFIBTr->Commit();
q->kanRelease();
}
//---------------------------------------------------------------------------

void __fastcall TFormaEditUser::cxButtonNewClick(TObject *Sender)
{
if (PasswordEdit->Text!=Password2Edit->Text)
	{
	UnicodeString s="��������� ������ �� ���������! ";
	Application->MessageBox(s.c_str(),
				L"������!", MB_OK + MB_ICONEXCLAMATION);
	return;
	}

if (Name2User=="SYSDBA")
	{
	UnicodeString s="������������ SYSDBA ��� ��������������� �� �������! ";
	Application->MessageBox(s.c_str(),
				L"������!", MB_OK + MB_ICONEXCLAMATION);
	return;
	}

if (DM_Connection->NameUser!="SYSDBA")
	{
	UnicodeString s="������������ ���� �������!";
	Application->MessageBox(s.c_str(),
				L"������!", MB_OK + MB_ICONEXCLAMATION);
	return;
	}


pFIBSecurityService1->Active = false ;
pFIBSecurityService1->Params->Clear();
pFIBSecurityService1->Params->Add("user_name="+DM_Connection->NameUser);
pFIBSecurityService1->Params->Add("password="+DM_Connection->PasswordUser);
pFIBSecurityService1->ServerName=DM_Connection->NameServer;
pFIBSecurityService1->Protocol=TCP;
pFIBSecurityService1->Active = true ;
pFIBSecurityService1->UserName = Name2User;
pFIBSecurityService1->Password = PasswordEdit->Text;
pFIBSecurityService1->FirstName = Name2User;
pFIBSecurityService1->MiddleName = Name2User;
pFIBSecurityService1->LastName = Name2User;
try {pFIBSecurityService1->AddUser(); }
catch (Exception &exception)
{ ShowMessage("�� ������� �������� ������������! ������: "+exception.Message); }
pFIBSecurityService1->Active = false ;	
}
//---------------------------------------------------------------------------

void __fastcall TFormaEditUser::cxButtonEditClick(TObject *Sender)
{
if (PasswordEdit->Text!=Password2Edit->Text)
	{
	UnicodeString s="��������� ������ �� ���������! ";
	Application->MessageBox(s.c_str(),
				L"������!", MB_OK + MB_ICONEXCLAMATION);
	return;
	}

if (DM_Connection->NameUser!="SYSDBA")
	{
	UnicodeString s="������������ ���� �������!";
	Application->MessageBox(s.c_str(),
				L"������!", MB_OK + MB_ICONEXCLAMATION);
	return;
	}

pFIBSecurityService1->Active = false ;
pFIBSecurityService1->Params->Clear();
pFIBSecurityService1->Params->Add("user_name="+DM_Connection->NameUser);
pFIBSecurityService1->Params->Add("password="+DM_Connection->PasswordUser);
pFIBSecurityService1->ServerName=DM_Connection->NameServer;
pFIBSecurityService1->Protocol=TCP;
pFIBSecurityService1->Active = true ;
pFIBSecurityService1->UserName = Name2User;
pFIBSecurityService1->Password = PasswordEdit->Text;
pFIBSecurityService1->FirstName = Name2User;
pFIBSecurityService1->MiddleName = Name2User;
pFIBSecurityService1->LastName = Name2User;
try {pFIBSecurityService1->ModifyUser(); }
catch (Exception &exception)
{ ShowMessage("�� ������� �������� ��������� ������������! ������: "+exception.Message); }
pFIBSecurityService1->Active = false ;	
}
//---------------------------------------------------------------------------

void __fastcall TFormaEditUser::cxButtonDelClick(TObject *Sender)
{
if (Name2User=="SYSDBA")
	{
	UnicodeString s="������������ SYSDBA �� ����� ���� ������! ";
	Application->MessageBox(s.c_str(),
				L"������!", MB_OK + MB_ICONEXCLAMATION);
	return;
	}

if (DM_Connection->NameUser!="SYSDBA")
	{
	UnicodeString s="������������ ���� �������!";
	Application->MessageBox(s.c_str(),
				L"������!", MB_OK + MB_ICONEXCLAMATION);
	return;
	}


UnicodeString S = "������� ������������  "+Name2User + " �� ���� �������?";
if (Application->MessageBox(S.c_str(),
L"��������!", MB_OKCANCEL | MB_ICONQUESTION) == mrOk)
	{
	pFIBSecurityService1->Active = false ;
	pFIBSecurityService1->Params->Clear();
	pFIBSecurityService1->Params->Add("user_name="+DM_Connection->NameUser);
	pFIBSecurityService1->Params->Add("password="+DM_Connection->PasswordUser);
	pFIBSecurityService1->ServerName=DM_Connection->NameServer;
	pFIBSecurityService1->Protocol=TCP;
	pFIBSecurityService1->Active = true ;
	pFIBSecurityService1->UserName = Name2User;
	try {pFIBSecurityService1->DeleteUser(); }
	catch (Exception &exception)
	{ ShowMessage("�� ������� ������� ������������! ������: "+exception.Message); }
	pFIBSecurityService1->Active = false ;
	}	
}
//---------------------------------------------------------------------------

void __fastcall TFormaEditUser::ActionOpenHelpExecute(TObject *Sender)
{
Application->HelpJump("SprUser");	
}
//---------------------------------------------------------------------------

void __fastcall TFormaEditUser::ActionCloseExecute(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

