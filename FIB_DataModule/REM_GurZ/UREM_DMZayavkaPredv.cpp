//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_DMZayavkaPredv.h"

#include "IDMSprUser.h"
#include "IDMSetup.h"
#include "IREM_DMZayavkaDv.h"
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
__fastcall TREM_DMZayavkaPredv::TREM_DMZayavkaPredv(TComponent* Owner)
		: TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
Prosmotr=false;

flGetNumberDoc=true;
}
//-----------------------------------------------------------------
void __fastcall TREM_DMZayavkaPredv::DataModuleCreate(TObject *Sender)
{
//
Prosmotr=false;
flChangeData=false;
}
//----------------------------------------------------------------------------
bool TREM_DMZayavkaPredv::Init(void)
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
IBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;

GurZ->Database=DM_Connection->pFIBData;
NumDoc->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//----------------------------------------------------------------------------
int TREM_DMZayavkaPredv::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMZayavkaPredv::DataModuleDestroy(TObject *Sender)
{

GurZ->Close();

NumDoc->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void TREM_DMZayavkaPredv::NewDoc(void)
{

flGetNumberDoc=false;

       // OpenDoc(0);
		GurZ->Active=false;
		NumDoc->Active=false;

		GurZ->Open();

		GurZ->Append();

		IdZ=glStrToInt64(GurZID_REM_Z2->AsString);
		GurZPOS_REM_Z2->AsDateTime=Now();


		if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0) GurZIDUSER_REM_Z2->AsString=DM_Connection->UserInfoID_USER->AsString;
		GurZNAME_USER->AsString=DM_Connection->UserInfoNAME_USER->AsString;


		//id inf base
		if (glStrToInt64(DM_Connection->ARMInfoIDBASE_SARM->AsString)!=0)
			{
			GurZIDBASE_REM_Z2->AsString=DM_Connection->ARMInfoIDBASE_SARM->AsString;
			GurZNAME_SINFBASE_OBMEN->AsString=DM_Connection->ARMInfoNAME_SINFBASE_OBMEN->AsString;
			}
		else
			{
			if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
				{
				GurZIDBASE_REM_Z2->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
				GurZNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
				}
			}


		//firma
		if (glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString)!=0)
			{
			GurZIDFIRM_REM_Z2->AsString=DM_Connection->ARMInfoIDFIRM_SARM->AsString;
			GurZNAMEFIRM->AsString=DM_Connection->ARMInfoNAMEFIRM->AsString;
			}
		else
			{
			if (glStrToInt64(DM_Connection->UserInfoIDFIRM_USER->AsString)!=0)
				{
				GurZIDFIRM_REM_Z2->AsString=DM_Connection->UserInfoIDFIRM_USER->AsString;
				GurZNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;
				}
			}

		//sklad piemki
		if (glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString)!=0)
			{
			GurZIDSKLPR_REM_Z2->AsString=DM_Connection->ARMInfoIDSKLAD_SARM->AsString;
			GurZNAME_SKLAD_PR->AsString=DM_Connection->ARMInfoNAMESKLAD->AsString;
			}
		else
			{
			if (glStrToInt64(DM_Connection->UserInfoIDSKLAD_USER->AsString)!=0)
				{
				GurZIDSKLPR_REM_Z2->AsString=DM_Connection->UserInfoIDSKLAD_USER->AsString;
				GurZNAME_SKLAD_PR->AsString=DM_Connection->UserInfoNAMESKLAD->AsString;
				}
			}



		GurZNAME_REM_Z2->AsString="Заявка предв. №"+GurZNUM_REM_Z2->AsString+
						" от "+GurZPOS_REM_Z2->AsString;
		//GurZSOST_REM_Z2->AsString="б/у, отпечатки пальцев, посторонние частицы, царапины, потертости, сколы, трещины, повреждения разъема, красный индикатор";
		GurZ->Post();




flGetNumberDoc=true;
GurZ->Edit();
GetNumberNewDoc();
GurZ->Post();


}
//----------------------------------------------------------------------------
int TREM_DMZayavkaPredv::GetNumberNewDoc(void)
{
int result=0;
if (flGetNumberDoc==false) return result;

//получим номер документа
NumDoc->Active=false;
NumDoc->ParamByName("PARAM_IDBASE")->AsString=GurZIDBASE_REM_Z2->AsString;
NumDoc->ParamByName("PARAM_IDFIRM")->AsString=GurZIDFIRM_REM_Z2->AsString;
NumDoc->ParamByName("PARAM_IDSKLAD")->AsString=GurZIDSKLPR_REM_Z2->AsString;

NumDoc->Open();
//GurZPREFIKS_NUM_REM_Z->AsString=NumDoc->FieldByName("OUT_PREFIKS_DOC")->AsString;
GurZNUM_REM_Z2->AsInteger=NumDoc->FieldByName("OUT_NUMDOC")->AsInteger;
NumDoc->Close();
result=GurZNUM_REM_Z2->AsInteger;
return result;
}
//----------------------------------------------------------------------------
void TREM_DMZayavkaPredv::OpenDoc(__int64 id)
{

		GurZ->Active=false;


		GurZ->ParamByName("PARAM_ID")->AsString=id;


		GurZ->Open();


		GurZIDBASE_REM_Z2->ReadOnly=true;

//IDMSetup * DMSetup;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
//													(void**)&DMSetup);
//DMSetup->Init(InterfaceMainObject,0);
//Prosmotr=DMSetup->ProveritPosZapretaRed(GurZPOS_REM_Z->AsDateTime);
//DMSetup->kanRelease();

}

//----------------------------------------------------------------------------
void TREM_DMZayavkaPredv::CloseDoc(void)
{
		GurZ->CancelUpdates();


		GurZ->Active=false;

}
//----------------------------------------------------------------------------
bool TREM_DMZayavkaPredv::SaveDoc(void)
{
bool Res=false;

//IDMSetup * DMSetup;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
//													(void**)&DMSetup);
//DMSetup->Init(InterfaceMainObject,0);
//Prosmotr=DMSetup->ProveritPosZapretaRed(GurZPOS_REM_Z->AsDateTime);
//DMSetup->kanRelease();

if (Prosmotr==true)
        {

        TextError="Позиция документа меньше позиции запрета редактирования!";
        return Res;
        }

try
		{


		IdZ=glStrToInt64(GurZID_REM_Z2->AsString);
		GurZ->ApplyUpdToBase();

		IBTrUpdate->Commit();
		GurZ->CommitUpdToCach();

		OpenDoc(IdZ);


		Res=true;
		}
catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				TextError=exception.Message;
				Res=false;
				}
return Res;
}
//---------------------------------------------------------------------------
bool TREM_DMZayavkaPredv::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);

if (Prosmotr==true)
		{
		TextError="Позиция документа меньше позиции запрета редактирования!";
		return res;
		}

try
		{


		GurZ->Delete();
		GurZ->ApplyUpdates();

		IBTrUpdate->Commit();
        res=true;
        }
catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				TextError=exception.Message;
				res=false;
				}


return res;

}
//-----------------------------------------------------------------------------









void __fastcall TREM_DMZayavkaPredv::GurZIDFIRM_REM_ZChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavkaPredv::GurZIDSKLPR_REM_ZChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------


