//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UREM_DMGurAllDoc.h"

//---------------------------------------------------------------------------
#include "IDMSetup.h"
#include "IREM_DMDocRemont.h"
#include "IREM_DMDocRemontHW.h"
#include "IREM_DMDocRemontKKT.h"
#include "IREM_DMDocKM1.h"
#include "IREM_DMDocKM2.h"
#include "IREM_DMDocSetServKKT.h"
#include "IREM_DMDocSetServHW.h"
#include "IREM_DMDocPrihNakl.h"
#include "IREM_DMDocReal.h"
#include "IREM_DMDocSborkaKompl.h"
#include "IREM_DMDocPostOtDilera.h"
#include "IREM_DMDocPerServCentr.h"
#include "IREM_DMDocVosvratDileru.h"
#include "IREM_DMDocVosvratIsSC.h"
#include "IREM_DMDocVosvratPok.h"
#include "IREM_DMDocAkt.h"
#include "IREM_DMDocPer.h"

#include "IREM_DMDocZPost.h"
#include "IREM_DMDocZVid.h"
#include "IREM_DMDocZPer.h"
#include "IREM_DMDocZStart.h"
#include "IREM_DMDocZEnd.h"
#include "IREM_DMDocZOper.h"
#include "IREM_DMDocZTreb.h"
#include "IREM_DMDocZAktPr.h"
#include "IREM_DMDocZVosvrZap.h"

#include "IREM_DMDocSpisNom.h"
#include "IREM_DMDocOstNom.h"
#include "IREM_DMDocRegOtchetPost.h"
#include "IREM_DMDocVidachaHW.h"
#include "IREM_DMDocVosvratHW.h"
#include "IREM_DMDocZakazPost.h"
#include "IREM_DMDocOtprPost.h"

#include "IREM_DMDocVZipPer.h"
#include "IREM_DMDocVZipVosvratPost.h"

#include "UGlobalFunction.h"
#include "UGlobalConstant.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//extern AnsiString glGetNameDocRemont(AnsiString str_code_doc);
//---------------------------------------------------------------------------
__fastcall TREM_DMGurAllDoc::TREM_DMGurAllDoc(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
OtborVkl=false;
}
//---------------------------------------------------------------------------

bool TREM_DMGurAllDoc::Init(void)
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

Table->Database=DM_Connection->pFIBData;
IBQ->Database=DM_Connection->pFIBData;
pFIBQ->Database=DM_Connection->pFIBData;


DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TREM_DMGurAllDoc::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TREM_DMGurAllDoc::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;

}
//---------------------------------------------------------------------------
void TREM_DMGurAllDoc::OpenTable()
{
Table->Active=false;
UnicodeString zapros="select rem_galldoc.id_rem_galldoc,                          \
			rem_galldoc.idbase_rem_galldoc,                                       \
			rem_galldoc.idfirm_rem_galldoc,                                       \
			rem_galldoc.idsklad_rem_galldoc,                                      \
			rem_galldoc.idklient_rem_galldoc,                                     \
			rem_galldoc.iduser_rem_galldoc,                                       \
			rem_galldoc.pos_rem_galldoc,                                          \
			rem_galldoc.num_rem_galldoc,                                          \
			rem_galldoc.pr_rem_galldoc,                                           \
			rem_galldoc.tdoc_rem_galldoc,                                         \
			rem_galldoc.iddocosn_rem_galldoc,                                     \
			rem_galldoc.typeextdoc_rem_galldoc,                                   \
			rem_galldoc.idextdoc_rem_galldoc,                                     \
			rem_galldoc.sum_rem_galldoc,                                          \
			rem_galldoc.idproject_rem_galldoc,                                    \
			rem_galldoc.idbusinop_rem_galldoc,                                   \
			rem_galldoc.prefiks_num_rem_galldoc,                                 \
			 NAMEFIRM, NAMESKLAD, NAMEKLIENT, NAME_USER,                 \
			 sinfbase_obmen.name_sinfbase_obmen,                           \
			rem_gur_prov.id_rem_gur_prov,                                   \
			rem_gur_prov.res_rem_gur_prov,                                   \
			rem_gur_vigrt.iddoc_rem_gur_vigrt                                \
			from                                                                      \
			REM_GALLDOC                                                               \
			left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_REM_GALLDOC    \
			LEFT OUTER JOIN SFIRM ON IDFIRM_REM_GALLDOC = IDFIRM                      \
			left outer join SSKLAD on IDSKLAD_REM_GALLDOC = IDSKLAD                   \
			left outer join SKLIENT on IDKLIENT_REM_GALLDOC =IDKLIENT                 \
			left outer join SUSER on  IDUSER_REM_GALLDOC = ID_USER                    \
			left outer join rem_gur_prov on REM_GALLDOC.id_rem_galldoc= rem_gur_prov.iddoc_rem_gur_prov           \
			left outer join rem_gur_vigrt on REM_GALLDOC.id_rem_galldoc= rem_gur_vigrt.iddocvigr_rem_gur_vigrt    \
			where POS_REM_GALLDOC between  :PARAM_POSNACH and :PARAM_POSCON           \
			order by POS_REM_GALLDOC ";
Table->SelectSQL->Clear();
Table->SelectSQL->Add(zapros);
Table->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
Table->Active=true;

}
//---------------------------------------------------------------------------
void TREM_DMGurAllDoc::UpdateTable(void)
{
IdDoc=glStrToInt64(TableID_REM_GALLDOC->AsString);
DataSourceTable->Enabled=false;

OpenTable();
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("ID_REM_GALLDOC",IntToStr(IdDoc),Opt);

DataSourceTable->Enabled=true;
}

//-----------------------------------------------------------------------

void TREM_DMGurAllDoc::AllCancelDvRegDoc(void)
{
Table->First();
while(!Table->Eof)
        {
		CancelDvRegDoc(Trim(TableTDOC_REM_GALLDOC->AsString), glStrToInt64(TableID_REM_GALLDOC->AsString));
		Table->Next();
		}

}
//--------------------------------------------------------------------
void TREM_DMGurAllDoc::AllDvRegDoc(void)
{
Table->First();
while(!Table->Eof)
		{
		CancelDvRegDoc(Trim(TableTDOC_REM_GALLDOC->AsString), glStrToInt64(TableID_REM_GALLDOC->AsString));
		Table->Next();
		}
}
//-----------------------------------------------------------------------
bool TREM_DMGurAllDoc::DvRegDoc(UnicodeString type_doc, __int64 id_doc)
{
bool result;
if(type_doc=="REMONT")
		{
		IREM_DMDocRemont *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocRemont.1",IID_IREM_DMDocRemont,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMONTHW")
		{
		IREM_DMDocRemontHW *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocRemontHW.1",IID_IREM_DMDocRemontHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMONTKKT")
		{
		IREM_DMDocRemontKKT *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocRemontKKT.1",IID_IREM_DMDocRemontKKT,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="KM1")
		{
		IREM_DMDocKM1 *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocKM1.1",IID_IREM_DMDocKM1,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="KM1")
		{
		IREM_DMDocKM2 *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocKM2.1",IID_IREM_DMDocKM2,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}
if(type_doc=="SETSERVKKT")
		{
		IREM_DMDocSetServKKT *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocSetServKKT.1",IID_IREM_DMDocSetServKKT,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="SETSERVHW")
		{
		IREM_DMDocSetServHW *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocSetServHW.1",IID_IREM_DMDocSetServHW,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMPRN")
		{
		IREM_DMDocPrihNakl *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocPrihNakl,IID_IREM_DMDocPrihNakl,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMREAL")
		{
		IREM_DMDocReal *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocReal,IID_IREM_DMDocReal,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMSBKOMPL")
		{
		IREM_DMDocSborkaKompl *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocSborkaKompl,IID_IREM_DMDocSborkaKompl,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="POSTOTDIL")
		{
		IREM_DMDocPostOtDilera *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocPostOtDilera,IID_IREM_DMDocPostOtDilera,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}


if(type_doc=="PERSC")
		{
		IREM_DMDocPerServCentr *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocPerServCentr,IID_IREM_DMDocPerServCentr,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="VOSDILERU")
		{
		IREM_DMDocVosvratDileru *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVosvratDileru,IID_IREM_DMDocVosvratDileru,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="VOSVISSC")
		{
		IREM_DMDocVosvratIsSC *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVosvratIsSC,IID_IREM_DMDocVosvratIsSC,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMVPOK")
		{
		IREM_DMDocVosvratPok *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVosvratPok,IID_IREM_DMDocVosvratPok,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}


if(type_doc=="REMAKT")
		{
		IREM_DMDocAkt *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocAkt,IID_IREM_DMDocAkt,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMPER")
		{
		IREM_DMDocPer *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocPer,IID_IREM_DMDocPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}



if(type_doc=="REMZPOST")
		{
		IREM_DMDocZPost *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZPost,IID_IREM_DMDocZPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMZVID")
		{
		IREM_DMDocZVid *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZVid,IID_IREM_DMDocZVid,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMZPER")
		{
		IREM_DMDocZPer *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZPer,IID_IREM_DMDocZPer,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMZSTART")
		{
		IREM_DMDocZStart *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZStart,IID_IREM_DMDocZStart,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMZEND")
		{
		IREM_DMDocZEnd *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZEnd,IID_IREM_DMDocZEnd,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMZOPER")
		{
		IREM_DMDocZOper *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZOper,IID_IREM_DMDocZOper,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}


if(type_doc=="REMZTREB")
		{
		IREM_DMDocZTreb *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZTreb,IID_IREM_DMDocZTreb,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMZAKTPR")
		{
		IREM_DMDocZAktPr *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZAktPr,IID_IREM_DMDocZAktPr,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}


if(type_doc=="REMZVZAP")
		{
		IREM_DMDocZVosvrZap *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZVosvrZap,IID_IREM_DMDocZVosvrZap,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMSPN")
		{
		IREM_DMDocSpisNom *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocSpisNom,IID_IREM_DMDocSpisNom,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REMOSN")
		{
		IREM_DMDocOstNom *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocOstNom,IID_IREM_DMDocOstNom,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REM_RGOTCHPOST")
		{
		IREM_DMDocRegOtchetPost *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocRegOtchetPost ,IID_IREM_DMDocRegOtchetPost ,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REM_VIDACHA_HW")
		{
		IREM_DMDocVidachaHW *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVidachaHW ,IID_IREM_DMDocVidachaHW ,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REM_VOSVRAT_HW")
		{
		IREM_DMDocVosvratHW *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVosvratHW ,IID_IREM_DMDocVosvratHW ,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}


if(type_doc=="REM_ZAKPOST")
		{
		IREM_DMDocZakazPost *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZakazPost ,IID_IREM_DMDocZakazPost ,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REM_OTPRPOST")
		{
		IREM_DMDocOtprPost *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocOtprPost ,IID_IREM_DMDocOtprPost ,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}


if(type_doc=="REM_VZPER")
		{
		IREM_DMDocVZipPer *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVZipPer ,IID_IREM_DMDocVZipPer ,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

if(type_doc=="REM_VZVPO")
		{
		IREM_DMDocVZipVosvratPost *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVZipVosvratPost ,IID_IREM_DMDocVZipVosvratPost ,
													(void**)&doc);
		doc->Init(InterfaceMainObject,0);
		doc->IdDoc=id_doc;
		//doc->EnableDvReg=true;
		if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
		}

return result;
}
//----------------------------------------------------------------------
bool TREM_DMGurAllDoc::CancelDvRegDoc(UnicodeString type_doc, __int64 id_doc)
{
bool result=false;
if(type_doc=="REMONT")
		{
		IREM_DMDocRemont *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocRemont.1",IID_IREM_DMDocRemont,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMONTHW")
		{
		IREM_DMDocRemontHW *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocRemontHW.1",IID_IREM_DMDocRemontHW,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMONTKKT")
		{
		IREM_DMDocRemontKKT *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocRemontKKT.1",IID_IREM_DMDocRemontKKT,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="KM1")
		{
		IREM_DMDocKM1 *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocKM1.1",IID_IREM_DMDocKM1,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="KM2")
		{
		IREM_DMDocKM2 *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocKM2.1",IID_IREM_DMDocKM2,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="SETSERVKKT")
		{
		IREM_DMDocSetServKKT *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocSetServKKT.1",IID_IREM_DMDocSetServKKT,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="SETSERVHW")
		{
		IREM_DMDocSetServHW *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.REM_DMDocSetServHW.1",IID_IREM_DMDocSetServHW,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMPRN")
		{
		IREM_DMDocPrihNakl *DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocPrihNakl,IID_IREM_DMDocPrihNakl,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMREAL")
		{
		IREM_DMDocReal *DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocReal,IID_IREM_DMDocReal,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMSBKOMPL")
		{
		IREM_DMDocSborkaKompl *DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocSborkaKompl,IID_IREM_DMDocSborkaKompl,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="POSTOTDIL")
		{
		IREM_DMDocPostOtDilera *DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocPostOtDilera,IID_IREM_DMDocPostOtDilera,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="PERSC")
		{
		IREM_DMDocPerServCentr *DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocPerServCentr,IID_IREM_DMDocPerServCentr,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="VOSDILERU")
		{
		IREM_DMDocVosvratDileru *DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVosvratDileru,IID_IREM_DMDocVosvratDileru,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="VOSVISSC")
		{
		IREM_DMDocVosvratIsSC * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVosvratIsSC,IID_IREM_DMDocVosvratIsSC,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMVPOK")
		{
		IREM_DMDocVosvratPok * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVosvratPok,IID_IREM_DMDocVosvratPok,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMAKT")
		{
		IREM_DMDocAkt * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocAkt,IID_IREM_DMDocAkt,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMPER")
		{
		IREM_DMDocPer * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocPer,IID_IREM_DMDocPer,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMZPOST")
		{
		IREM_DMDocZPost * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZPost,IID_IREM_DMDocZPost,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}


if(type_doc=="REMZVID")
		{
		IREM_DMDocZVid * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZVid,IID_IREM_DMDocZVid,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}


if(type_doc=="REMZPER")
		{
		IREM_DMDocZPer * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZPer,IID_IREM_DMDocZPer,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}


if(type_doc=="REMZSTART")
		{
		IREM_DMDocZStart * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZStart,IID_IREM_DMDocZStart,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}


if(type_doc=="REMZEND")
		{
		IREM_DMDocZEnd * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZEnd,IID_IREM_DMDocZEnd,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMZOPER")
		{
		IREM_DMDocZOper * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZOper,IID_IREM_DMDocZOper,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMZTREB")
		{
		IREM_DMDocZTreb * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZTreb,IID_IREM_DMDocZTreb,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMZAKTPR")
		{
		IREM_DMDocZAktPr * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZAktPr,IID_IREM_DMDocZAktPr,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMZVZAP")
		{
		IREM_DMDocZVosvrZap * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZVosvrZap,IID_IREM_DMDocZVosvrZap,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMSPN")
		{
		IREM_DMDocSpisNom * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocSpisNom,IID_IREM_DMDocSpisNom,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}


if(type_doc=="REM_RGOTCHPOST")
		{
		IREM_DMDocRegOtchetPost * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocRegOtchetPost,IID_IREM_DMDocRegOtchetPost,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REMOSN")
		{
		IREM_DMDocOstNom * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocOstNom,IID_IREM_DMDocOstNom,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}



if(type_doc=="REM_VIDACHA_HW")
		{
		IREM_DMDocVidachaHW * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVidachaHW,IID_IREM_DMDocVidachaHW,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REM_VOSVRAT_HW")
		{
		IREM_DMDocVosvratHW * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVosvratHW,IID_IREM_DMDocVosvratHW,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REM_ZAKPOST")
		{
		IREM_DMDocZakazPost * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocZakazPost,IID_IREM_DMDocZakazPost,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REM_OTPRPOST")
		{
		IREM_DMDocOtprPost * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocOtprPost,IID_IREM_DMDocOtprPost,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}


if(type_doc=="REM_VZPER")
		{
		IREM_DMDocVZipPer * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVZipPer,IID_IREM_DMDocVZipPer,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="REM_VZVPO")
		{
		IREM_DMDocVZipVosvratPost * DMDoc;
		InterfaceGlobalCom->kanCreateObject(ProgId_REM_DMDocVZipVosvratPost,IID_IREM_DMDocVZipVosvratPost,
													(void**)&DMDoc);
		DMDoc->Init(InterfaceMainObject,0);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}
return result;
}
//--------------------------------------------------------------------------

void __fastcall TREM_DMGurAllDoc::TableTDOC_REM_GALLDOCGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
Text=glGetNameDocRemont(TableTDOC_REM_GALLDOC->AsString);
}
//---------------------------------------------------------------------------
//открыть журнал только с выбранным оборудованием
bool TREM_DMGurAllDoc::OpenTableOnlyHardware(__int64 id_hw)
{
bool result=false;
//надо использовать процедуру
Table->Active=false;
Table->SelectSQL->Clear();
//Table->Fields->Clear();

UnicodeString zapros="select REM_GALLDOC_GET_TABLE_PO_IDHW.id_rem_galldoc,         \
						REM_GALLDOC_GET_TABLE_PO_IDHW.idbase_rem_galldoc,         \
						REM_GALLDOC_GET_TABLE_PO_IDHW.idfirm_rem_galldoc,         \
						REM_GALLDOC_GET_TABLE_PO_IDHW.idsklad_rem_galldoc,         \
						REM_GALLDOC_GET_TABLE_PO_IDHW.idklient_rem_galldoc,       \
						REM_GALLDOC_GET_TABLE_PO_IDHW.iduser_rem_galldoc,         \
						REM_GALLDOC_GET_TABLE_PO_IDHW.pos_rem_galldoc,            \
						REM_GALLDOC_GET_TABLE_PO_IDHW.num_rem_galldoc,            \
						REM_GALLDOC_GET_TABLE_PO_IDHW.pr_rem_galldoc,             \
						REM_GALLDOC_GET_TABLE_PO_IDHW.tdoc_rem_galldoc,           \
						REM_GALLDOC_GET_TABLE_PO_IDHW.iddocosn_rem_galldoc,       \
						REM_GALLDOC_GET_TABLE_PO_IDHW.typeextdoc_rem_galldoc,     \
						REM_GALLDOC_GET_TABLE_PO_IDHW.idextdoc_rem_galldoc,       \
						REM_GALLDOC_GET_TABLE_PO_IDHW.sum_rem_galldoc,            \
						REM_GALLDOC_GET_TABLE_PO_IDHW.idproject_rem_galldoc,      \
						REM_GALLDOC_GET_TABLE_PO_IDHW.idbusinop_rem_galldoc,      \
						REM_GALLDOC_GET_TABLE_PO_IDHW.prefiks_num_rem_galldoc,     \
			 NAMEFIRM, NAMESKLAD, NAMEKLIENT, NAME_USER,                                                             \
			sinfbase_obmen.name_sinfbase_obmen,                                     \
			rem_gur_prov.id_rem_gur_prov,                                   \
			rem_gur_prov.res_rem_gur_prov,                                   \
			rem_gur_vigrt.iddoc_rem_gur_vigrt                                \
			from REM_GALLDOC_GET_TABLE_PO_IDHW(:PARAM_IDHW,:PARAM_POSNACH,:PARAM_POSCON)                              \
			left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_REM_GALLDOC                                  \
			LEFT OUTER JOIN SFIRM ON REM_GALLDOC_GET_TABLE_PO_IDHW.idfirm_rem_galldoc = IDFIRM                       \
			left outer join SSKLAD on REM_GALLDOC_GET_TABLE_PO_IDHW.idsklad_rem_galldoc = IDSKLAD                    \
			left outer join SKLIENT on REM_GALLDOC_GET_TABLE_PO_IDHW.idklient_rem_galldoc =IDKLIENT                  \
			left outer join SUSER on  REM_GALLDOC_GET_TABLE_PO_IDHW.iduser_rem_galldoc = ID_USER                     \
			left outer join rem_gur_prov on REM_GALLDOC_GET_TABLE_PO_IDHW.id_rem_galldoc= rem_gur_prov.iddoc_rem_gur_prov           \
			left outer join rem_gur_vigrt on REM_GALLDOC_GET_TABLE_PO_IDHW.id_rem_galldoc= rem_gur_vigrt.iddocvigr_rem_gur_vigrt    \
			order by POS_REM_GALLDOC  ";
Table->SelectSQL->Add(zapros);
Table->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
Table->ParamByName("PARAM_IDHW")->AsString=id_hw;
Table->Active=true;
return result;
}
//---------------------------------------------------------------------------

//открыть журнал только с выбранной заявкой
bool TREM_DMGurAllDoc::OpenTableOnlyZayavka(__int64 id_z)
{
bool result=false;
//надо использовать процедуру
Table->Active=false;
Table->SelectSQL->Clear();
//Table->Fields->Clear();

UnicodeString zapros="select REM_GALLDOC_GET_TABLE_PO_IDZ.id_rem_galldoc,         \
						REM_GALLDOC_GET_TABLE_PO_IDZ.idbase_rem_galldoc,         \
						REM_GALLDOC_GET_TABLE_PO_IDZ.idfirm_rem_galldoc,         \
						REM_GALLDOC_GET_TABLE_PO_IDZ.idsklad_rem_galldoc,         \
						REM_GALLDOC_GET_TABLE_PO_IDZ.idklient_rem_galldoc,       \
						REM_GALLDOC_GET_TABLE_PO_IDZ.iduser_rem_galldoc,         \
						REM_GALLDOC_GET_TABLE_PO_IDZ.pos_rem_galldoc,            \
						REM_GALLDOC_GET_TABLE_PO_IDZ.num_rem_galldoc,            \
						REM_GALLDOC_GET_TABLE_PO_IDZ.pr_rem_galldoc,             \
						REM_GALLDOC_GET_TABLE_PO_IDZ.tdoc_rem_galldoc,           \
						REM_GALLDOC_GET_TABLE_PO_IDZ.iddocosn_rem_galldoc,       \
						REM_GALLDOC_GET_TABLE_PO_IDZ.typeextdoc_rem_galldoc,     \
						REM_GALLDOC_GET_TABLE_PO_IDZ.idextdoc_rem_galldoc,       \
						REM_GALLDOC_GET_TABLE_PO_IDZ.sum_rem_galldoc,            \
						REM_GALLDOC_GET_TABLE_PO_IDZ.idproject_rem_galldoc,      \
						REM_GALLDOC_GET_TABLE_PO_IDZ.idbusinop_rem_galldoc,      \
						REM_GALLDOC_GET_TABLE_PO_IDZ.prefiks_num_rem_galldoc,     \
			 NAMEFIRM, NAMESKLAD, NAMEKLIENT, NAME_USER,                                                             \
			sinfbase_obmen.name_sinfbase_obmen,                                   \
			rem_gur_prov.id_rem_gur_prov,                                   \
			rem_gur_prov.res_rem_gur_prov,                                   \
			rem_gur_vigrt.iddoc_rem_gur_vigrt                                \
			from REM_GALLDOC_GET_TABLE_PO_IDZ(:PARAM_IDZ,:PARAM_POSNACH,:PARAM_POSCON)                              \
			left outer join SINFBASE_OBMEN on ID_SINFBASE_OBMEN=IDBASE_REM_GALLDOC                                  \
			LEFT OUTER JOIN SFIRM ON REM_GALLDOC_GET_TABLE_PO_IDZ.idfirm_rem_galldoc = IDFIRM                       \
			left outer join SSKLAD on REM_GALLDOC_GET_TABLE_PO_IDZ.idsklad_rem_galldoc = IDSKLAD                    \
			left outer join SKLIENT on REM_GALLDOC_GET_TABLE_PO_IDZ.idklient_rem_galldoc =IDKLIENT                  \
			left outer join SUSER on  REM_GALLDOC_GET_TABLE_PO_IDZ.iduser_rem_galldoc = ID_USER                     \
			left outer join rem_gur_prov on REM_GALLDOC_GET_TABLE_PO_IDZ.id_rem_galldoc= rem_gur_prov.iddoc_rem_gur_prov           \
			left outer join rem_gur_vigrt on REM_GALLDOC_GET_TABLE_PO_IDZ.id_rem_galldoc= rem_gur_vigrt.iddocvigr_rem_gur_vigrt    \
			order by POS_REM_GALLDOC  ";
Table->SelectSQL->Add(zapros);
Table->ParamByName("PARAM_POSNACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_POSCON")->AsDateTime=PosCon;
Table->ParamByName("PARAM_IDZ")->AsString=id_z;
Table->Active=true;
return result;
}
//---------------------------------------------------------------------------
