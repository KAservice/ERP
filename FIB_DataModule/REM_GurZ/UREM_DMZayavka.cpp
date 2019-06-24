//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UREM_DMZayavka.h"

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
__fastcall TREM_DMZayavka::TREM_DMZayavka(TComponent* Owner)
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
void __fastcall TREM_DMZayavka::DataModuleCreate(TObject *Sender)
{
//
Prosmotr=false;
flChangeData=false;
}
//----------------------------------------------------------------------------
bool TREM_DMZayavka::Init(void)
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
GurZ_1->Database=DM_Connection->pFIBData;
GurZKompl->Database=DM_Connection->pFIBData;
GurZNeispr->Database=DM_Connection->pFIBData;
DopUsl->Database=DM_Connection->pFIBData;
PerformedWork->Database=DM_Connection->pFIBData;
GurZPrNeispr->Database=DM_Connection->pFIBData;
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
int TREM_DMZayavka::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMZayavka::DataModuleDestroy(TObject *Sender)
{
GurZ_1->Close();
GurZ->Close();
GurZKompl->Close();
GurZNeispr->Close();
DopUsl->Close();
PerformedWork->Close();
GurZPrNeispr->Close();
NumDoc->Active=false;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//----------------------------------------------------------------------------
void TREM_DMZayavka::NewDoc(void)
{

flGetNumberDoc=false;

       // OpenDoc(0);
		GurZ->Active=false;
		GurZ_1->Active=false;
		GurZKompl->Active=false;
		GurZNeispr->Active=false;
		DopUsl->Active=false;
		PerformedWork->Close();
		GurZPrNeispr->Close();
		NumDoc->Active=false;

		GurZ->Open();

		GurZKompl->Open();
		
		GurZ->Append();

		IdZ=glStrToInt64(GurZID_REM_Z->AsString);
		GurZPOS_REM_Z->AsDateTime=Now();
		GurZSROK_REM_Z->AsDateTime=Now()+3;

		if (glStrToInt64(DM_Connection->UserInfoID_USER->AsString)!=0) GurZIDUSER_REM_Z->AsString=DM_Connection->UserInfoID_USER->AsString;
		GurZNAME_USER->AsString=DM_Connection->UserInfoNAME_USER->AsString;


		//id inf base
		if (glStrToInt64(DM_Connection->ARMInfoIDBASE_SARM->AsString)!=0)
			{
			GurZIDBASE_REM_Z->AsString=DM_Connection->ARMInfoIDBASE_SARM->AsString;
			GurZNAME_SINFBASE_OBMEN->AsString=DM_Connection->ARMInfoNAME_SINFBASE_OBMEN->AsString;
			}
		else
			{
			if (glStrToInt64(DM_Connection->UserInfoIDBASE_SUSER->AsString)!=0)
				{
				GurZIDBASE_REM_Z->AsString=DM_Connection->UserInfoIDBASE_SUSER->AsString;
				GurZNAME_SINFBASE_OBMEN->AsString=DM_Connection->UserInfoNAME_SINFBASE_OBMEN->AsString;
				}
			}

		//active category
		if (glStrToInt64(DM_Connection->ARMInfoIDACTCATEGORY_SARM->AsString)!=0)
			{
			GurZIDACTCAT_REM_Z->AsString=DM_Connection->ARMInfoIDACTCATEGORY_SARM->AsString;
			GurZNAME_REM_SACTCATEGORY->AsString=DM_Connection->ARMInfoNAME_REM_SACTCATEGORY->AsString;
			}
		else
			{
			if (glStrToInt64(DM_Connection->UserInfoIDACTCATEGORY_SUSER->AsString)!=0)
				{
				GurZIDACTCAT_REM_Z->AsString=DM_Connection->UserInfoIDACTCATEGORY_SUSER->AsString;
				GurZNAME_REM_SACTCATEGORY->AsString=DM_Connection->UserInfoNAME_REM_SACTCATEGORY->AsString;
				}
			}

		//firma
		if (glStrToInt64(DM_Connection->ARMInfoIDFIRM_SARM->AsString)!=0)
			{
			GurZIDFIRM_REM_Z->AsString=DM_Connection->ARMInfoIDFIRM_SARM->AsString;
			GurZNAMEFIRM->AsString=DM_Connection->ARMInfoNAMEFIRM->AsString;
			}
		else
			{
			if (glStrToInt64(DM_Connection->UserInfoIDFIRM_USER->AsString)!=0)
				{
				GurZIDFIRM_REM_Z->AsString=DM_Connection->UserInfoIDFIRM_USER->AsString;
				GurZNAMEFIRM->AsString=DM_Connection->UserInfoNAMEFIRM->AsString;
				}
			}

		//sklad piemki
		if (glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString)!=0)
			{
			GurZIDSKLPR_REM_Z->AsString=DM_Connection->ARMInfoIDSKLAD_SARM->AsString;
			GurZNAME_SKLAD_PR->AsString=DM_Connection->ARMInfoNAMESKLAD->AsString;
			}
		else
			{
			if (glStrToInt64(DM_Connection->UserInfoIDSKLAD_USER->AsString)!=0)
				{
				GurZIDSKLPR_REM_Z->AsString=DM_Connection->UserInfoIDSKLAD_USER->AsString;
				GurZNAME_SKLAD_PR->AsString=DM_Connection->UserInfoNAMESKLAD->AsString;
				}
			}

				//sklad tec
		if (glStrToInt64(DM_Connection->ARMInfoIDSKLAD_SARM->AsString)!=0)
			{
			GurZIDTECSKL_REM_Z->AsString=DM_Connection->ARMInfoIDSKLAD_SARM->AsString;
			GurZNAME_SKLAD_TEC->AsString=DM_Connection->ARMInfoNAMESKLAD->AsString;
			}
		else
			{
			if (glStrToInt64(DM_Connection->UserInfoIDSKLAD_USER->AsString)!=0)
				{
				GurZIDTECSKL_REM_Z->AsString=DM_Connection->UserInfoIDSKLAD_USER->AsString;
				GurZNAME_SKLAD_TEC->AsString=DM_Connection->UserInfoNAMESKLAD->AsString;
				}
			}

		GurZNAME_REM_Z->AsString="Заявка №"+GurZPREFIKS_NUM_REM_Z->AsString+GurZNUM_REM_Z->AsString+
						" от "+GurZPOS_REM_Z->AsString;
		GurZSOST_REM_Z->AsString="б/у, отпечатки пальцев, посторонние частицы, царапины, потертости, сколы, трещины, повреждения разъема, красный индикатор, пленка на экране";

		GUID guid;
		CoCreateGuid(&guid);
		GurZGUID_REM_Z->AsString=GUIDToString(guid);
		GurZ->Post();

		GurZ_1->ParamByName("PARAM_IDZ")->AsString=IdZ;
		GurZ_1->Open();
		GurZ_1->Edit();
		GurZ_1KLIENT_EMAIL_REM_Z_1->AsString="no@no.com";
		GurZ_1->Post();

		GurZKompl->ParamByName("PARAM_IDZ")->AsString=IdZ;
		GurZKompl->Open();

		GurZNeispr->ParamByName("PARAM_IDZ")->AsString=IdZ;
		GurZNeispr->Open();

		DopUsl->ParamByName("PARAM_IDZ")->AsString=IdZ;
		DopUsl->Open();

		PerformedWork->ParamByName("PARAM_IDZ")->AsString=IdZ;
		PerformedWork->Open();

		GurZPrNeispr->ParamByName("PARAM_IDZ")->AsString=IdZ;
		GurZPrNeispr->Open();


flGetNumberDoc=true;
GurZ->Edit();
GurZ_1->Edit();
GetNumberNewDoc();
GurZ->Post();


}
//----------------------------------------------------------------------------
int TREM_DMZayavka::GetNumberNewDoc(void)
{
int result=0;
if (flGetNumberDoc==false) return result;

//получим номер документа
NumDoc->Active=false;
NumDoc->ParamByName("PARAM_IDBASE")->AsString=GurZIDBASE_REM_Z->AsString;
NumDoc->ParamByName("PARAM_IDFIRM")->AsString=GurZIDFIRM_REM_Z->AsString;
NumDoc->ParamByName("PARAM_IDSKLAD")->AsString=GurZIDSKLPR_REM_Z->AsString;

NumDoc->Open();
GurZPREFIKS_NUM_REM_Z->AsString=NumDoc->FieldByName("OUT_PREFIKS_DOC")->AsString;
GurZNUM_REM_Z->AsInteger=NumDoc->FieldByName("OUT_NUMDOC")->AsInteger;
NumDoc->Close();
result=GurZNUM_REM_Z->AsInteger;
return result;
}
//----------------------------------------------------------------------------
void TREM_DMZayavka::OpenDoc(__int64 id)
{

		GurZ->Active=false;
		GurZ_1->Active=false;
		GurZNeispr->Active=false;
		GurZKompl->Active=false;
		DopUsl->Active=false;
		PerformedWork->Active=false;
		GurZPrNeispr->Active=false;

		GurZ->ParamByName("PARAM_ID")->AsString=id;
		GurZ_1->ParamByName("PARAM_IDZ")->AsString=id;
		GurZNeispr->ParamByName("PARAM_IDZ")->AsString=id;
		GurZKompl->ParamByName("PARAM_IDZ")->AsString=id;
		DopUsl->ParamByName("PARAM_IDZ")->AsString=id;
		PerformedWork->ParamByName("PARAM_IDZ")->AsString=id;
		GurZPrNeispr->ParamByName("PARAM_IDZ")->AsString=id;

		GurZ->Open();
		GurZ_1->Open();
		GurZNeispr->Open();
		GurZKompl->Open();
		DopUsl->Open();
		PerformedWork->Open();
		GurZPrNeispr->Open();
		GurZIDBASE_REM_Z->ReadOnly=true;

//IDMSetup * DMSetup;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
//													(void**)&DMSetup);
//DMSetup->Init(InterfaceMainObject,0);
//Prosmotr=DMSetup->ProveritPosZapretaRed(GurZPOS_REM_Z->AsDateTime);
//DMSetup->kanRelease();

}

//----------------------------------------------------------------------------
void TREM_DMZayavka::CloseDoc(void)
{
		GurZ->CancelUpdates();
		GurZ_1->CancelUpdates();
		GurZNeispr->CancelUpdates();
		GurZKompl->CancelUpdates();
		DopUsl->CancelUpdates();
		PerformedWork->CancelUpdates();
		GurZPrNeispr->CancelUpdates();

		GurZ->Active=false;
		GurZ_1->Active=false;
		GurZKompl->Active=false;
		GurZNeispr->Active=false;
		DopUsl->Active=false;
		PerformedWork->Active=false;
		GurZPrNeispr->Active=false;
}
//----------------------------------------------------------------------------
bool TREM_DMZayavka::SaveDoc(void)
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
//		GurZ->Edit();
//		GurZIDUSER_REM_Z->AsString=DM_Connection->UserInfoID_USER->AsString;
//		GurZ->Post();

		IdZ=glStrToInt64(GurZID_REM_Z->AsString);
		GurZ->ApplyUpdToBase();
		GurZ_1->ApplyUpdToBase();
		GurZKompl->ApplyUpdToBase();
		GurZNeispr->ApplyUpdToBase();
		DopUsl->ApplyUpdToBase();
		PerformedWork->ApplyUpdToBase();
		GurZPrNeispr->ApplyUpdToBase();
		IBTrUpdate->Commit();
		GurZ->CommitUpdToCach();
		GurZ_1->CommitUpdToCach();
		GurZNeispr->CommitUpdToCach();
		GurZKompl->CommitUpdToCach();
		DopUsl->CommitUpdToCach();
		PerformedWork->CommitUpdToCach();
		GurZPrNeispr->CommitUpdToCach();
		OpenDoc(IdZ);

		AddNewRecordDv();


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
bool TREM_DMZayavka::DeleteDoc(__int64 id)
{
bool res=false;

OpenDoc(id);

if (Prosmotr==true)
		{
		TextError="Позиция документа меньше позиции запрета редактирования!";
		return res;
		}


//удалим изменения заявки

		IREM_DMZayavkaDv * dm_z_dv;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMZayavkaDv,IID_IREM_DMZayavkaDv,
								 (void**)&dm_z_dv);
		dm_z_dv->Init(InterfaceMainObject,InterfaceImpl);
		dm_z_dv->OpenTable(id);

		dm_z_dv->Table->First();
		while(!dm_z_dv->Table->Eof)
				{
				//ShowMessage(IntToStr(DocT->RecNo));
				dm_z_dv->DeleteElement(glStrToInt64(dm_z_dv->TableID_REM_Z_DV->AsString));
				dm_z_dv->Table->Next();
				}

		dm_z_dv->kanRelease();




try
        {

		GurZNeispr->First();
		while(!GurZNeispr->Eof)
				{
				//ShowMessage(IntToStr(DocT->RecNo));
				GurZNeispr->Delete();
				}

		GurZKompl->First();
		while(!GurZKompl->Eof)
				{
				//ShowMessage(IntToStr(DocT->RecNo));
				GurZKompl->Delete();
				}

		DopUsl->First();
		while(!DopUsl->Eof)
				{
				//ShowMessage(IntToStr(DocT->RecNo));
				DopUsl->Delete();
				}

		PerformedWork->First();
		while(!PerformedWork->Eof)
				{
				//ShowMessage(IntToStr(DocT->RecNo));
				PerformedWork->Delete();
				}

		GurZPrNeispr->First();
		while(!GurZPrNeispr->Eof)
				{
				//ShowMessage(IntToStr(DocT->RecNo));
				GurZPrNeispr->Delete();
				}


		if (GurZ_1->RecordCount>0) GurZ_1->Delete();
		GurZ->Delete();

		GurZ_1->ApplyUpdates();
		GurZKompl->ApplyUpdates();
		GurZNeispr->ApplyUpdates();
		DopUsl->ApplyUpdates();
		PerformedWork->ApplyUpdates();
		GurZPrNeispr->ApplyUpdates();

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
void __fastcall TREM_DMZayavka::GurZPOS_REM_ZChange(TField *Sender)
{
//IDMSetup * DMSetup;
//InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMSetup,
//													(void**)&DMSetup);
//DMSetup->Init(InterfaceMainObject,0);
//Prosmotr=DMSetup->ProveritPosZapretaRed(GurZPOS_REM_Z->AsDateTime);
//DMSetup->kanRelease();
}
//---------------------------------------------------------------------------




void __fastcall TREM_DMZayavka::GurZKomplNewRecord(TDataSet *DataSet)
{
GurZKomplIDZ_REM_ZKOMPL->AsString=GurZID_REM_Z->AsString;
GurZKomplIDBASE_REM_ZKOMPL->AsString=GurZIDBASE_REM_Z->AsString ;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::GurZNeisprNewRecord(TDataSet *DataSet)
{
GurZNeisprIDZ_REM_ZNEISPR->AsString=GurZID_REM_Z->AsString;
GurZNeisprIDBASE_REM_ZNEISPR->AsString=GurZIDBASE_REM_Z->AsString ;
}
//---------------------------------------------------------------------------


void __fastcall TREM_DMZayavka::GurZKomplCalcFields(TDataSet *DataSet)
{
GurZKomplRECNO->AsInteger=GurZKompl->RecNo;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::GurZNeisprCalcFields(TDataSet *DataSet)
{
GurZNeisprRECNO->AsInteger=GurZNeispr->RecNo;
}
//---------------------------------------------------------------------------
void TREM_DMZayavka::AddNewRecordDv(void)
{
if (flChangeData==false) return;

		IREM_DMZayavkaDv * REM_DMZayavkaDv;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMZayavkaDv.1",IID_IREM_DMZayavkaDv,
													(void**)&REM_DMZayavkaDv);
		REM_DMZayavkaDv->Init(InterfaceMainObject,0);
		REM_DMZayavkaDv->IdBaseZayavki=glStrToInt64(GurZIDBASE_REM_Z->AsString);
		REM_DMZayavkaDv->AddRecordDv(Now(),
						glStrToInt64(GurZID_REM_Z->AsString),
						0,
						glStrToInt64(GurZIDSOST_REM_Z->AsString),
						glStrToInt64(GurZIDTYPEREM_REM_Z->AsString),
						glStrToInt64(GurZIDUSER_REM_Z->AsString),
						glStrToInt64(GurZIDTECSKL_REM_Z->AsString),
						GurZSUM_REM_Z->AsFloat,
						GurZSROK_REM_Z->Value,
						GurZOUT_REM_Z->AsInteger
						);

		REM_DMZayavkaDv->kanRelease();

}
//установим флаг изменения
//-------------------------------------------------------------------------
void __fastcall TREM_DMZayavka::GurZIDTYPEREM_REM_ZChange(TField *Sender)
{
flChangeData=true;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::GurZIDSOST_REM_ZChange(TField *Sender)
{
flChangeData=true;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::GurZIDTECSKL_REM_ZChange(TField *Sender)
{
flChangeData=true;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::GurZSUM_REM_ZChange(TField *Sender)
{
flChangeData=true;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::GurZSROK_REM_ZChange(TField *Sender)
{
flChangeData=true;	
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::GurZOUT_REM_ZChange(TField *Sender)
{
flChangeData=true;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::DopUslNewRecord(TDataSet *DataSet)
{
DopUslIDZ_REM_ZDOPUSL->AsString=GurZID_REM_Z->AsString;
DopUslIDBASE_REM_ZDOPUSL->AsString=GurZIDBASE_REM_Z->AsString ;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::DopUslKOL_REM_ZDOPUSLChange(TField *Sender)
{

DopUslSUM_REM_ZDOPUSL->AsFloat=DopUslKOL_REM_ZDOPUSL->AsFloat*DopUslPRICE_REM_ZDOPUSL->AsFloat;

}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::DopUslPRICE_REM_ZDOPUSLChange(TField *Sender)
{

DopUslSUM_REM_ZDOPUSL->AsFloat=DopUslKOL_REM_ZDOPUSL->AsFloat*DopUslPRICE_REM_ZDOPUSL->AsFloat;


}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::PerformedWorkNewRecord(TDataSet *DataSet)
{
PerformedWorkIDZ_REM_ZPERFWORK->AsString=GurZID_REM_Z->AsString;
PerformedWorkIDBASE_REM_ZPERFWORK->AsString=GurZIDBASE_REM_Z->AsString ;
PerformedWorkIDUSER_REM_ZPERFWORK->AsString=DM_Connection->UserInfoID_USER->AsString;
PerformedWorkNAME_USER->AsString=DM_Connection->UserInfoNAME_USER->AsString;
PerformedWorkPOS_REM_ZPERFWORK->AsDateTime=Now();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::PerformedWorkKOL_REM_ZPERFWORKChange(TField *Sender)

{
PerformedWorkSUM_REM_ZPERFWORK->AsFloat=PerformedWorkKOL_REM_ZPERFWORK->AsFloat
							*PerformedWorkPRICE_REM_ZPERFWORK->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::PerformedWorkPRICE_REM_ZPERFWORKChange(TField *Sender)

{
PerformedWorkSUM_REM_ZPERFWORK->AsFloat=PerformedWorkKOL_REM_ZPERFWORK->AsFloat
							*PerformedWorkPRICE_REM_ZPERFWORK->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::GurZIDBASE_REM_ZChange(TField *Sender)
{
if(GurZ_1->Active==true)
	{
	GurZ_1IDBASE_REM_Z_1->AsString=GurZIDBASE_REM_Z->AsString ;
	}

if(GurZNeispr->Active==true)
	{
		GurZNeispr->First();
		while(!GurZNeispr->Eof)
				{
				GurZNeispr->Edit();
				GurZNeisprIDBASE_REM_ZNEISPR->AsString=GurZIDBASE_REM_Z->AsString ;
				GurZNeispr->Post();
				GurZNeispr->Next();
				}
	}

if (GurZKompl->Active==true)
	{
		GurZKompl->First();
		while(!GurZKompl->Eof)
				{
				GurZKompl->Edit();
				GurZKomplIDBASE_REM_ZKOMPL->AsString=GurZIDBASE_REM_Z->AsString ;
				GurZKompl->Post();
				GurZKompl->Next();
				}
	}

if (PerformedWork->Active==true)
	{
		PerformedWork->First();
		while(!PerformedWork->Eof)
				{
				PerformedWork->Edit();
				PerformedWorkIDBASE_REM_ZPERFWORK->AsString=GurZIDBASE_REM_Z->AsString ;
				PerformedWork->Post();
				PerformedWork->Next();
				}
	}

if (DopUsl->Active==true)
	{
		DopUsl->First();
		while(!DopUsl->Eof)
				{
				DopUsl->Edit();
				DopUslIDBASE_REM_ZDOPUSL->AsString=GurZIDBASE_REM_Z->AsString ;
				DopUsl->Post();
				DopUsl->Next();
				}
	}

if (GurZPrNeispr->Active==true)
	{
		GurZPrNeispr->First();
		while(!GurZPrNeispr->Eof)
				{
				GurZPrNeispr->Edit();
				GurZPrNeisprIDBASE_REM_ZPRNEISPR->AsString=GurZIDBASE_REM_Z->AsString ;
				GurZPrNeispr->Post();
				GurZPrNeispr->Next();
				}
	}

}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::GurZIDFIRM_REM_ZChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::GurZIDSKLPR_REM_ZChange(TField *Sender)
{
GetNumberNewDoc();
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::GurZ_1NewRecord(TDataSet *DataSet)
{
GurZ_1IDZ_REM_Z_1->AsString=GurZID_REM_Z->AsString;
GurZ_1IDBASE_REM_Z_1->AsString=GurZIDBASE_REM_Z->AsString ;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::GurZPrNeisprCalcFields(TDataSet *DataSet)
{
GurZPrNeisprRECNO->AsInteger=GurZPrNeispr->RecNo;
}
//---------------------------------------------------------------------------

void __fastcall TREM_DMZayavka::GurZPrNeisprNewRecord(TDataSet *DataSet)
{
GurZPrNeisprIDZ_REM_ZPRNEISPR->AsString=GurZID_REM_Z->AsString;
GurZPrNeisprIDBASE_REM_ZPRNEISPR->AsString=GurZIDBASE_REM_Z->AsString ;
}
//---------------------------------------------------------------------------

