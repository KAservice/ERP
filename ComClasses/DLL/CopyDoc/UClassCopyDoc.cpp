//---------------------------------------------------------------------------


#pragma hdrstop

#include "UClassCopyDoc.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

#include "IREM_DMDocReal.h"
#include "IREM_FormaDocPer.h"
#include "IDMDocPer.h"
#include "IDMDocOstNom.h"
#include "IREM_FormaDocOstNom.h"

#include "IREM_DMDocAkt.h"
#include "IREM_FormaDocAkt.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
TClassCopyDoc::TClassCopyDoc()
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;

}

//-----------------------------------------------------------------------------
TClassCopyDoc::~TClassCopyDoc()
{

}
//---------------------------------------------------------------------------
bool TClassCopyDoc::Init(void)
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






result=true;

return result;
}
//----------------------------------------------------------------------------
int TClassCopyDoc::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
bool TClassCopyDoc::CreateNewCopyDoc(__int64 id_doc, UnicodeString type_doc, UnicodeString type_new_doc,
									 bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3)
{
bool result=false;


if (type_doc=="REMREAL")
	{
	 result=REM_CopyDocReal(id_doc,type_new_doc,
									 fl_save_doc,fl_open_form_doc,
									 param1, param2, param3);
	}
else if (type_doc=="REMAKT")
	{
	result=REM_CopyDocAktInAkt(id_doc,fl_save_doc,fl_open_form_doc,
									 param1,param2,param3);
	}
else
	{
	result=false;
	TextError="Процедура копирования выбранного документа в другой не предусмотрена!";
	}


return result;
}
//----------------------------------------------------------------------------


bool TClassCopyDoc::REM_CopyDocReal(__int64 id_doc, UnicodeString type_new_doc,
									 bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3)
{
bool result=false;

if (type_new_doc=="REMPER")
	{
	 result=REM_CopyDocRealInPerem(id_doc, fl_save_doc,fl_open_form_doc,
									 param1, param2, param3);

	}
else
	{
	result=false;
	TextError="Процедура копирования документа Реализация в данный документ не предусмотрена!";
	}

return result;
}
//----------------------------------------------------------------------------


bool TClassCopyDoc::REM_CopyDocRealInPerem(__int64 id_doc, bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3)
{
bool result=false;

IREM_DMDocReal * real;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocReal,IID_IREM_DMDocReal,
												 (void**)&real);
real->Init(InterfaceMainObject,InterfaceImpl);

IREM_FormaDocPer * per;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPer,IID_IREM_FormaDocPer,
												 (void**)&per);
per->Init(InterfaceMainObject,InterfaceImpl);


real->OpenDoc(id_doc);


per->DM->NewDoc();

per->DM->DocAll->Edit();
per->DM->DocAllIDFIRM_REM_GALLDOC->AsString=real->DocAllIDFIRM_REM_GALLDOC->AsString;
per->DM->DocAllNAMEFIRM->AsString=real->DocAllNAMEFIRM->AsString;
per->DM->DocAllIDSKLAD_REM_GALLDOC->AsString=real->DocAllIDSKLAD_REM_GALLDOC->AsString;
per->DM->DocAllNAMESKLAD->AsString=real->DocAllNAMESKLAD->AsString;
per->DM->DocAllIDKLIENT_REM_GALLDOC->AsString=real->DocAllIDKLIENT_REM_GALLDOC->AsString;
per->DM->DocAllNAMEKLIENT->AsString=real->DocAllNAMEKLIENT->AsString;
per->DM->DocAll->Post();

per->DM->Doc->Edit();
per->DM->DocPRIM_REM_DPER->AsString="Документ создан копированием из Реализации №"+
											real->DocAllNUM_REM_GALLDOC->AsString+" от "+
											real->DocAllPOS_REM_GALLDOC->AsString;

per->DM->Doc->Post();

per->UpdateForm();


real->DocT->First();
while(!real->DocT->Eof)
	{
	per->DM->AddDocNewString();
	per->DM->DocT->Edit();
	per->DM->DocTIDNOM_REM_DPERT->AsString=real->DocTIDNOM_REM_DREALT->AsString;
	per->DM->DocTNAMENOM->AsString=real->DocTNAMENOM->AsString;
	per->DM->DocTARTNOM->AsString=real->DocTARTNOM->AsString;
	per->DM->DocTSHED->AsString=real->DocTSHED->AsString;
    per->DM->DocTCODENOM->AsString=real->DocTCODENOM->AsString;

	per->DM->DocTIDED_REM_DPERT->AsString=real->DocTIDED_REM_DREALT->AsString;
	per->DM->DocTNAMEED->AsString=real->DocTNAMEED->AsString;

	per->DM->DocTIDHW_REM_DPERT->AsString=real->DocTIDHW_REM_DREALT->AsString;
	per->DM->DocTNAME_REM_SHARDWARE->AsString=real->DocTNAME_REM_SHARDWARE->AsString;
	per->DM->DocTCODE_REM_SHARDWARE->AsString=real->DocTCODE_REM_SHARDWARE->AsString;
	per->DM->DocTSERNUM_REM_SHARDWARE->AsString=real->DocTSERNUM_REM_SHARDWARE->AsString;

	per->DM->DocTKOL_REM_DPERT->AsFloat=real->DocTKOL_REM_DREALT->AsFloat;
	per->DM->DocTKF_REM_DPERT->AsFloat=real->DocTKF_REM_DREALT->AsFloat;
	per->DM->DocTRPRICE_REM_DPERT->AsFloat=real->DocTPRICE_REM_DREALT->AsFloat;
	per->DM->DocT->Post();
	real->DocT->Next();
	}


result=true;
real->kanRelease();

return result;
}
//----------------------------------------------------------------------------
__int64 TClassCopyDoc::CreateNewDocNaOsn(__int64 id_doc, UnicodeString type_doc, UnicodeString type_new_doc,
									 bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3)
{
__int64 result=0;

if (type_doc=="PER")
	{
	 result=CreateNewDocNaOsnPer(id_doc,type_new_doc,
									 fl_save_doc,fl_open_form_doc,
									 param1, param2, param3);

	}
else if (type_doc=="OSN")
	{
	 result=CreateNewDocNaOsnOstNom(id_doc,type_new_doc,
									 fl_save_doc,fl_open_form_doc,
									 param1, param2, param3);

	}
else
	{
	result=-1;
	TextError="Процедура копирования выбранного документа в другой не предусмотрена!";
	}

return result;
}
//-----------------------------------------------------------------------------
//на основании ПЕРЕМЕЩЕНИЯ
__int64 TClassCopyDoc::CreateNewDocNaOsnPer(__int64 id_doc, UnicodeString type_new_doc,
									 bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3)
{
__int64 result=0;

if (type_new_doc=="REMPER")
	{
	 result=REM_CreateNewDocNaOsnPerDocRemPer(id_doc, fl_save_doc,fl_open_form_doc,
									 param1, param2, param3);

	}
else
	{
	result=-1;
	TextError="Процедура копирования документа Перемещение в данный документ не предусмотрена!";
	}

return result;
}
//-----------------------------------------------------------------------------
//на основании ПЕРЕМЕЩЕНИЯ  Перемещение (Ремонт)
__int64 TClassCopyDoc::REM_CreateNewDocNaOsnPerDocRemPer(__int64 id_doc,
									 bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3)
{
__int64 result=0;

IDMDocPer * per;
InterfaceGlobalCom->kanCreateObject(ProgId_DMDocPer,IID_IDMDocPer,
												 (void**)&per);
per->Init(InterfaceMainObject,InterfaceImpl);

IREM_FormaDocPer * rem_per;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocPer,IID_IREM_FormaDocPer,
												 (void**)&rem_per);
rem_per->Init(InterfaceMainObject,InterfaceImpl);


per->OpenDoc(id_doc);


rem_per->DM->NewDoc();

rem_per->DM->DocAll->Edit();

rem_per->DM->DocAllTYPEEXTDOC_REM_GALLDOC->AsString=GC_TypeSubSystem_MainModul;
rem_per->DM->DocAllIDEXTDOC_REM_GALLDOC->AsString=per->DocAllIDDOC->AsString;

rem_per->DM->DocAllIDFIRM_REM_GALLDOC->AsString=per->DocAllIDFIRMDOC->AsString;
rem_per->DM->DocAllNAMEFIRM->AsString=per->DocAllNAMEFIRM->AsString;
rem_per->DM->DocAllIDSKLAD_REM_GALLDOC->AsString=per->DocAllIDSKLDOC->AsString;
rem_per->DM->DocAllNAMESKLAD->AsString=per->DocAllNAMESKLAD->AsString;
rem_per->DM->DocAllIDKLIENT_REM_GALLDOC->AsString=per->DocAllIDKLDOC->AsString;
//rem_per->DM->DocAllNAMEKLIENT->AsString=per->DocAllNAMEKLIENT->AsString;
rem_per->DM->DocAll->Post();

rem_per->DM->Doc->Edit();
rem_per->DM->DocPRIM_REM_DPER->AsString="Документ создан на основании документа Перемещения №"+
											per->DocAllNUMDOC->AsString+" от "+
											per->DocAllPOSDOC->AsString;
rem_per->DM->DocIDSKLPOL_REM_DPER->AsString=per->DocIDSKLPOLPER->AsString;
rem_per->DM->DocNAMESKLAD->AsString=per->DocNAMESKLAD->AsString;
rem_per->DM->Doc->Post();

rem_per->UpdateForm();


per->DocT->First();
while(!per->DocT->Eof)
	{
	rem_per->DM->AddDocNewString();
	rem_per->DM->DocT->Edit();
	rem_per->DM->DocTIDNOM_REM_DPERT->AsString=per->DocTIDNOMPERT->AsString;
	rem_per->DM->DocTNAMENOM->AsString=per->DocTNAMENOM->AsString;
	rem_per->DM->DocTARTNOM->AsString=per->DocTARTNOM->AsString;
	rem_per->DM->DocTSHED->AsString=per->DocTSHED->AsString;
	rem_per->DM->DocTCODENOM->AsString=per->DocTCODENOM->AsString;

	rem_per->DM->DocTIDED_REM_DPERT->AsString=per->DocTIDEDPERT->AsString;
	rem_per->DM->DocTNAMEED->AsString=per->DocTNAMEED->AsString;

	//rem_per->DM->DocTIDHW_REM_DPERT->AsString=per->DocTIDHW_REM_DREALT->AsString;
	//rem_per->DM->DocTNAME_REM_SHARDWARE->AsString=per->DocTNAME_REM_SHARDWARE->AsString;
	//rem_per->DM->DocTCODE_REM_SHARDWARE->AsString=per->DocTCODE_REM_SHARDWARE->AsString;
	//rem_per->DM->DocTSERNUM_REM_SHARDWARE->AsString=per->DocTSERNUM_REM_SHARDWARE->AsString;

	rem_per->DM->DocTKOL_REM_DPERT->AsFloat=per->DocTKOLPERT->AsFloat;
	rem_per->DM->DocTKF_REM_DPERT->AsFloat=per->DocTKFPERT->AsFloat;
	rem_per->DM->DocTRPRICE_REM_DPERT->AsFloat=per->DocTPRICEPERT->AsFloat;
	rem_per->DM->DocT->Post();
	per->DocT->Next();
	}


result=glStrToInt64(rem_per->DM->DocAllID_REM_GALLDOC->AsString);
per->kanRelease();

return result;
}
//-----------------------------------------------------------------------------
//на основании Ввода остатков
__int64 TClassCopyDoc::CreateNewDocNaOsnOstNom(__int64 id_doc, UnicodeString type_new_doc,
									 bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3)
{
__int64 result=0;

if (type_new_doc=="REMOSN")
	{
	 result=REM_CreateNewDocNaOsnOstNomDocRemOstNom(id_doc, fl_save_doc,fl_open_form_doc,
									 param1, param2, param3);

	}
else
	{
	result=-1;
	TextError="Процедура копирования документа Перемещение в данный документ не предусмотрена!";
	}

return result;
}
//-----------------------------------------------------------------------------
//на основании Ввода остатков  Остатки номенклатуры (Ремонт)
__int64 TClassCopyDoc::REM_CreateNewDocNaOsnOstNomDocRemOstNom(__int64 id_doc,
									 bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3)
{
__int64 result=0;

IDMDocOstNom * ost_nom;
InterfaceGlobalCom->kanCreateObject(ProgId_DMDocOstNom,IID_IDMDocOstNom,
												 (void**)&ost_nom);
ost_nom->Init(InterfaceMainObject,InterfaceImpl);

IREM_FormaDocOstNom * rem_ost_nom;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocOstNom,IID_IREM_FormaDocOstNom,
												 (void**)&rem_ost_nom);
rem_ost_nom->Init(InterfaceMainObject,InterfaceImpl);


ost_nom->OpenDoc(id_doc);


rem_ost_nom->DM->NewDoc();

rem_ost_nom->DM->DocAll->Edit();

rem_ost_nom->DM->DocAllTYPEEXTDOC_REM_GALLDOC->AsString=GC_TypeSubSystem_MainModul;
rem_ost_nom->DM->DocAllIDEXTDOC_REM_GALLDOC->AsString=ost_nom->DocAllIDDOC->AsString;

rem_ost_nom->DM->DocAllIDFIRM_REM_GALLDOC->AsString=ost_nom->DocAllIDFIRMDOC->AsString;
rem_ost_nom->DM->DocAllNAMEFIRM->AsString=ost_nom->DocAllNAMEFIRM->AsString;
rem_ost_nom->DM->DocAllIDSKLAD_REM_GALLDOC->AsString=ost_nom->DocAllIDSKLDOC->AsString;
rem_ost_nom->DM->DocAllNAMESKLAD->AsString=ost_nom->DocAllNAMESKLAD->AsString;
//rem_ost_nom->DM->DocAllIDKLIENT_REM_GALLDOC->AsString=per->DocAllIDKLDOC->AsString;
//rem_per->DM->DocAllNAMEKLIENT->AsString=per->DocAllNAMEKLIENT->AsString;
rem_ost_nom->DM->DocAll->Post();

rem_ost_nom->DM->Doc->Edit();
rem_ost_nom->DM->DocPRIM_REM_DOSN->AsString="Документ создан на основании документа Ввод остатков №"+
											ost_nom->DocAllNUMDOC->AsString+" от "+
											ost_nom->DocAllPOSDOC->AsString;
rem_ost_nom->DM->Doc->Post();

rem_ost_nom->UpdateForm();


ost_nom->DocT->First();
while(!ost_nom->DocT->Eof)
	{
	rem_ost_nom->DM->AddDocNewString();
	rem_ost_nom->DM->DocT->Edit();
	rem_ost_nom->DM->DocTIDNOM_REM_DOSNT->AsString=ost_nom->DocTIDNOMOSNT->AsString;
	rem_ost_nom->DM->DocTNAMENOM->AsString=ost_nom->DocTNAMENOM->AsString;
//	rem_ost_nom->DM->DocTARTNOM->AsString=ost_nom->DocTARTNOM->AsString;
//	rem_ost_nom->DM->DocTSHED->AsString=ost_nom->DocTSHED->AsString;
//	rem_ost_nom->DM->DocTCODENOM->AsString=ost_nom->DocTCODENOM->AsString;

	rem_ost_nom->DM->DocTIDED_REM_DOSNT->AsString=ost_nom->DocTIDEDOSNT->AsString;
	rem_ost_nom->DM->DocTNAMEED->AsString=ost_nom->DocTNAMEED->AsString;

	//rem_per->DM->DocTIDHW_REM_DPERT->AsString=per->DocTIDHW_REM_DREALT->AsString;
	//rem_per->DM->DocTNAME_REM_SHARDWARE->AsString=per->DocTNAME_REM_SHARDWARE->AsString;
	//rem_per->DM->DocTCODE_REM_SHARDWARE->AsString=per->DocTCODE_REM_SHARDWARE->AsString;
	//rem_per->DM->DocTSERNUM_REM_SHARDWARE->AsString=per->DocTSERNUM_REM_SHARDWARE->AsString;

	rem_ost_nom->DM->DocTKOL_REM_DOSNT->AsFloat=ost_nom->DocTKOLOSNT->AsFloat;
	rem_ost_nom->DM->DocTKF_REM_DOSNT->AsFloat=ost_nom->DocTKFOSNT->AsFloat;
	rem_ost_nom->DM->DocTPRICE_REM_DOSNT->AsFloat=ost_nom->DocTPRICEOSNT->AsFloat;
	rem_ost_nom->DM->DocTRPRICE_REM_DOSNT->AsFloat=ost_nom->DocTRPRICE_DOSNT->AsFloat;
	rem_ost_nom->DM->DocT->Post();
	ost_nom->DocT->Next();
	}


result=glStrToInt64(rem_ost_nom->DM->DocAllID_REM_GALLDOC->AsString);
ost_nom->kanRelease();

return result;
}
//-----------------------------------------------------------------------------
bool TClassCopyDoc::REM_CopyDocAktInAkt(__int64 id_doc, bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3)
{
bool result=false;

IREM_DMDocAkt * doc;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocAkt,IID_IREM_DMDocAkt,
												 (void**)&doc);
doc->Init(InterfaceMainObject,InterfaceImpl);

IREM_FormaDocAkt * new_form_doc;
InterfaceGlobalCom->kanCreateObject(ProgId_REM_FormaDocAkt,IID_IREM_FormaDocAkt,
												 (void**)&new_form_doc);
new_form_doc->Init(InterfaceMainObject,InterfaceImpl);


doc->OpenDoc(id_doc);


new_form_doc->DM->NewDoc();

new_form_doc->DM->DocAll->Edit();
new_form_doc->DM->DocAllIDFIRM_REM_GALLDOC->AsString=doc->DocAllIDFIRM_REM_GALLDOC->AsString;
new_form_doc->DM->DocAllNAMEFIRM->AsString=doc->DocAllNAMEFIRM->AsString;
new_form_doc->DM->DocAllIDSKLAD_REM_GALLDOC->AsString=doc->DocAllIDSKLAD_REM_GALLDOC->AsString;
new_form_doc->DM->DocAllNAMESKLAD->AsString=doc->DocAllNAMESKLAD->AsString;
new_form_doc->DM->DocAllIDKLIENT_REM_GALLDOC->AsString=doc->DocAllIDKLIENT_REM_GALLDOC->AsString;
new_form_doc->DM->DocAllNAMEKLIENT->AsString=doc->DocAllNAMEKLIENT->AsString;
new_form_doc->DM->DocAll->Post();

new_form_doc->DM->Doc->Edit();
new_form_doc->DM->DocPRIM_REM_DAKT->AsString="Документ создан копированием из Акта №"+
											doc->DocAllNUM_REM_GALLDOC->AsString+" от "+
											doc->DocAllPOS_REM_GALLDOC->AsString;

new_form_doc->DM->Doc->Post();

new_form_doc->UpdateForm();


doc->DocT->First();
while(!doc->DocT->Eof)
	{
	new_form_doc->DM->DocT->Append();
	new_form_doc->DM->DocT->Edit();
	new_form_doc->DM->DocTINDEX_REM_DAKTT->AsString=doc->DocTINDEX_REM_DAKTT->AsString;
	new_form_doc->DM->DocTTEXT_REM_DAKTT->AsString=doc->DocTTEXT_REM_DAKTT->AsString;

	new_form_doc->DM->DocT->Post();
	doc->DocT->Next();
	}


result=true;
doc->kanRelease();

return result;
}