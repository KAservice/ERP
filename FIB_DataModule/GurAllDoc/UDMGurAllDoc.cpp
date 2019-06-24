//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMGurAllDoc.h"

#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#include "IDMDocPrihNakl.h"
#include "IDMSetup.h"
#include "IDMDocCheck.h"
#include "IDMDocInv.h"
#include "IDMDocOstNom.h"
#include "IDMDocPer.h"
#include "IDMDocPlP.h"
#include "IDMDocPostNaSchet.h"
#include "IDMDocReal.h"
#include "IDMDocRepKKM.h"
#include "IDMDocRKO.h"
#include "IDMDocSpisNom.h"
#include "IDMDocVosvratPost.h"
#include "IDMDocPKO.h"
#include "IDMDocOstVs.h"
#include "IDMDocPKORozn.h"
#include "IDMDocRealRozn.h"
#include "IDMDocRKORozn.h"
#include "IDMDocSchetFact.h"
#include "IDMDocSchet.h"
#include "IDMDocVosvratPok.h"
#include "IDMDocIsmPrice.h"
#include "IDMDocRev.h"
#include "IDMDocSpOtrOst.h"
#include "IDMDocVipuskProd.h"
#include "IDMDocSborkaKompl.h"
#include "IDMDocRasborkaKompl.h"
#include "IDMDocZamena.h"
#include "IDMDocKorrVs.h"
#include "IDMDocVipBanka.h"
#include "IDMDocRegAdvCust.h"
#include "IDMDocRegBank.h"
#include "IDMDocRegGoods.h"
#include "IDMDocRegKassa.h"
#include "IDMDocRegOstNom.h"
#include "IDMDocRegPaySale.h"
#include "IDMDocRegVsRasch.h"
#include "IDMDocRegCardBalance.h"
#include "IDMDocOtchetPost.h"
#include "IDMDocRegOtchetPost.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMGurAllDoc::TDMGurAllDoc(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//---------------------------------------------------------------------------

void __fastcall TDMGurAllDoc::DataModuleCreate(TObject *Sender)
{
OtborVkl=false;
//OtborPoFirm=false;
//OtborPoKlient=false;
//OtborPoSklad=false;
//OtborPoTypeDoc=false;
NoCheck=false;
StringTypeDoc="";
}
//---------------------------------------------------------------------------
bool TDMGurAllDoc::Init(void)
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
pFIBQ->Database=DM_Connection->pFIBData;
Table->Database=DM_Connection->pFIBData;
IBQ->Database=DM_Connection->pFIBData;

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
int TDMGurAllDoc::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------

void __fastcall TDMGurAllDoc::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TDMGurAllDoc::OpenTable()
{
Table->Active=false;
AnsiString zapros="select GALLDOC.*, NAMEFIRM, NAMESKLAD, NAMEKLIENT, NAME_USER, NAME_SPROJECT, ";
zapros=zapros+" sinfbase_obmen.name_sinfbase_obmen";
zapros=zapros+" from GALLDOC";
zapros=zapros+" left outer join sinfbase_obmen on sinfbase_obmen.id_sinfbase_obmen=galldoc.idbase_galldoc";
zapros=zapros+" LEFT OUTER JOIN SFIRM ON IDFIRMDOC=IDFIRM";
zapros=zapros+" left outer join SSKLAD on IDSKLDOC=IDSKLAD";
zapros=zapros+" left outer join SKLIENT on IDKLDOC=IDKLIENT";
zapros=zapros+" left outer join SUSER on  IDUSERDOC= ID_USER";
zapros=zapros+" left outer join SPROJECT on  IDPROJECT_GALLDOC= ID_SPROJECT";
if (IdSklad>0 && OtborVkl==true)
        {
        zapros=zapros+" left outer join DPER on IDDOCPER=IDDOC";
        }

zapros=zapros+" where POSDOC between  :PARAM_DATE_NACH and :PARAM_DATE_CON";

if (StringTypeDoc!="" && OtborVkl==true)
        {
        zapros=zapros+" AND TDOC in ("+StringTypeDoc+" ) ";
        }
else
        {
        if (NoCheck==true)
                {
                zapros=zapros+" AND TDOC in ("+glGetStringFullTypeDocNoCheck()+" ) ";
                }
        else
                {
                //zapros=zapros+" AND TDOC in ("+glStringFullTypeDoc+" ) ";
                }
        }

if (IdFirm>0 && OtborVkl==true)
        {
        zapros=zapros+" AND IDFIRMDOC="+IntToStr(IdFirm);
        }

if (IdKlient>0 && OtborVkl==true)
        {
        zapros=zapros+" AND IDKLDOC="+IntToStr(IdKlient);
        }

if (IdSklad>0 && OtborVkl==true)
        {
        zapros=zapros+" AND (IDSKLDOC="+IntToStr(IdSklad)+" OR IDSKLPOLPER="+IntToStr(IdSklad)+")";
        }

zapros=zapros+" order by POSDOC";

Table->SelectSQL->Clear();
Table->SelectSQL->Add(zapros);
Table->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosNach;
Table->ParamByName("PARAM_DATE_CON")->AsDateTime=PosCon; 
Table->Active=true;

}
//---------------------------------------------------------------------------
void TDMGurAllDoc::UpdateTable(void)
{
IdDoc=TableIDDOC->AsInt64;
DataSourceTable->Enabled=false;

OpenTable();
TLocateOptions Opt;
Opt<<loCaseInsensitive;
Table->Locate("IDDOC",IntToStr(IdDoc),Opt);

DataSourceTable->Enabled=true;
}
//----------------------------------------------------------------------------

__int64 TDMGurAllDoc::FindDocPoIdDog(__int64 iddogovor)
{
__int64 result=0;

pFIBQ->Close();
pFIBQ->SQL->Clear();
		pFIBQ->SQL->Add("select IDDOC , TDOC from GALLDOC where IDDOGDOC=:PARAM_IDDOG");
		pFIBQ->ParamByName("PARAM_IDDOG")->AsInt64=iddogovor;
		pFIBQ->ExecQuery();
		result=pFIBQ->RecordCount;
pFIBQ->Close();
return result;
}
//-----------------------------------------------------------------------

void TDMGurAllDoc::AllCancelDvRegDoc(void)
{
Table->First();
while(!Table->Eof)
        {
		CancelDvRegDoc(Trim(TableTDOC->AsString), TableIDDOC->AsInt64);
        Table->Next();
        }

}
//--------------------------------------------------------------------
void TDMGurAllDoc::AllDvRegDoc(void)
{
Table->First();
while(!Table->Eof)
        {
		CancelDvRegDoc(Trim(TableTDOC->AsString), TableIDDOC->AsInt64);
        Table->Next();
        }
}
//-----------------------------------------------------------------------
bool TDMGurAllDoc::DvRegDoc(AnsiString type_doc, __int64 id_doc)
{
bool result;
if(type_doc=="PRN")
        {
		IDMDocPrihNakl *DMDocPRN;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPrihNakl.1",IID_IDMDocPrihNakl,
													(void**)&DMDocPRN);
		DMDocPRN->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDocPRN->IdDoc=id_doc;
		DMDocPRN->EnableDvReg=true;
        if (DMDocPRN->DvRegDoc()==true){result=true;}
		DMDocPRN->kanRelease();
        }

if(type_doc=="CHK")
        {
		IDMDocCheck *DMDocCHK;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
													(void**)&DMDocCHK);
		DMDocCHK->Init(InterfaceMainObject,InterfaceOwnerObject);
        DMDocCHK->EnableDvReg=true;
		DMDocCHK->IdDoc=id_doc;
        if (DMDocCHK->DvRegDoc()==true){result=true;}
		DMDocCHK->kanRelease();
        }

if(type_doc=="SCH")
        {
		IDMDocSchet *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSchet.1",IID_IDMDocSchet,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
        if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
        }

if(type_doc=="INV")
        {
		IDMDocInv *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocInv.1",IID_IDMDocInv,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
        doc->OpenDoc(id_doc);
        if (doc->DvRegDoc()==true){result=true;}
		doc->kanRelease();
        }

if(type_doc=="OSN")
        {
		IDMDocOstNom *DMDocOstNom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocOstNom.1",IID_IDMDocOstNom,
													(void**)&DMDocOstNom);
DMDocOstNom->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDocOstNom->IdDoc=id_doc;
		DMDocOstNom->EnableDvReg=true;
        if (DMDocOstNom->DvRegDoc()==true){result=true;}
		DMDocOstNom->kanRelease();
		}

if(type_doc=="PER")
        {
		IDMDocPer *DMDocPer;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPer.1",IID_IDMDocPer,
													(void**)&DMDocPer);
DMDocPer->Init(InterfaceMainObject,InterfaceOwnerObject);
        DMDocPer->EnableDvReg=true;
		DMDocPer->IdDoc=id_doc;
		DMDocPer->EnableDvReg=true;
        if (DMDocPer->DvRegDoc()==true){result=true;}
		DMDocPer->kanRelease();
        }


if(type_doc=="REA")
        {
		IDMDocReal *DMDocReal;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocReal.1",IID_IDMDocReal,
													(void**)&DMDocReal);
DMDocReal->Init(InterfaceMainObject,InterfaceOwnerObject);
        DMDocReal->EnableDvReg=true;
		DMDocReal->IdDoc=id_doc;
		DMDocReal->EnableDvReg=true;
        if (DMDocReal->DvRegDoc()==true){result=true;}
		DMDocReal->kanRelease();
        }

if(type_doc=="SPN")
        {
		IDMDocSpisNom *DMDocSpisNom;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSpisNom.1",IID_IDMDocSpisNom,
													(void**)&DMDocSpisNom);
DMDocSpisNom->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDocSpisNom->IdDoc=id_doc;
		DMDocSpisNom->EnableDvReg=true;
        if (DMDocSpisNom->DvRegDoc()==true){result=true;}
		DMDocSpisNom->kanRelease();
        }

if(type_doc=="VPO")
        {
		IDMDocVosvratPost *DMDocVosvratPost;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVosvratPost.1",IID_IDMDocVosvratPost,
													(void**)&DMDocVosvratPost);
DMDocVosvratPost->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDocVosvratPost->IdDoc=id_doc;
		DMDocVosvratPost->EnableDvReg=true;
        if (DMDocVosvratPost->DvRegDoc()==true){result=true;}
		DMDocVosvratPost->kanRelease();
        }


if(type_doc=="PKO")
        {
		IDMDocPKO *DMDocPKO;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPKO.1",IID_IDMDocPKO,
													(void**)&DMDocPKO);
DMDocPKO->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDocPKO->IdDoc=id_doc;
		DMDocPKO->EnableDvReg=true;
        if (DMDocPKO->DvRegDoc()==true){result=true;}
		DMDocPKO->kanRelease();
        }

if(type_doc=="RKO")
        {
		IDMDocRKO *DMDocRKO;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRKO.1",IID_IDMDocRKO,
													(void**)&DMDocRKO);
DMDocRKO->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDocRKO->IdDoc=id_doc;
		DMDocRKO->EnableDvReg=true;
        if (DMDocRKO->DvRegDoc()==true){result=true;}
		DMDocRKO->kanRelease();
        }

if(type_doc=="PLP")
		{
		IDMDocPlP *DMDocPLP;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPLP.1",IID_IDMDocPlP,
													(void**)&DMDocPLP);
DMDocPLP->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDocPLP->IdDoc=id_doc;
		DMDocPLP->EnableDvReg=true;
        if (DMDocPLP->DvRegDoc()==true){result=true;}
		DMDocPLP->kanRelease();
        }

if(type_doc=="PNS")
        {
		IDMDocPostNaSchet *DMDocPostNaSchet;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSetup.1",IID_IDMDocPostNaSchet,
													(void**)&DMDocPostNaSchet);
DMDocPostNaSchet->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDocPostNaSchet->IdDoc=id_doc;
		DMDocPostNaSchet->EnableDvReg=true;
        if (DMDocPostNaSchet->DvRegDoc()==true){result=true;}
		DMDocPostNaSchet->kanRelease();
        }


if(type_doc=="OSTVS")
        {
		IDMDocOstVs *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocOstVs.1",IID_IDMDocOstVs,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
        doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
        if(doc->DvRegDoc()==true)result=true;
		doc->kanRelease();
        }

if(type_doc=="SCHFACT")
        {
		IDMDocSchetFact *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSchetFact.1",IID_IDMDocSchetFact,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
        doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
        if (doc->DvRegDoc()==true)result=true;
		doc->kanRelease();
        }

if(type_doc=="REALROZN")
		{
		IDMDocRealRozn *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRealRozn.1",IID_IDMDocRealRozn,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}


if(type_doc=="PKOROZN")
        {
		IDMDocPKORozn *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPKORozn.1",IID_IDMDocPKORozn,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
        if(doc->DvRegDoc()==true)result=true;
		doc->kanRelease();
        }


if(type_doc=="RKOROZN")
        {
		IDMDocRKORozn *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRKORozn.1",IID_IDMDocRKORozn,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
        if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="VPOK")
        {
		IDMDocVosvratPok *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVosvratPok.1",IID_IDMDocVosvratPok,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}
if(type_doc=="ISMPRICE")
		{
		IDMDocIsmPrice *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocIsmPrice.1",IID_IDMDocIsmPrice,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="SPOTROST")
		{
		IDMDocSpOtrOst *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSpOtrOst.1",IID_IDMDocSpOtrOst,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="REV")
		{
		IDMDocRev *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRev.1",IID_IDMDocRev,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="VIPPROD")
		{
		IDMDocVipuskProd *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVipuskProd.1",IID_IDMDocVipuskProd,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="SBKOMPL")
		{
		IDMDocSborkaKompl *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSborkaKompl.1",IID_IDMDocSborkaKompl,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="RASBKOMPL")
		{
		IDMDocRasborkaKompl *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRasborkaKompl.1",IID_IDMDocRasborkaKompl,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="ZAMENA")
		{
		IDMDocZamena *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocZamena.1",IID_IDMDocZamena,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}


if(type_doc=="KORRVS")
		{
		IDMDocKorrVs *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocKorrVS.1",IID_IDMDocKorrVs,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="VIPBANK")
		{
		IDMDocVipBanka *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVipBanka.1",IID_IDMDocVipBanka,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="RG_ADVCUST")
		{
		IDMDocRegAdvCust *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegAdvCust.1",IID_IDMDocRegAdvCust,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="RG_BANK")
		{
		IDMDocRegBank *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegBank.1",IID_IDMDocRegBank,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="RG_GOODS")
		{
		IDMDocRegGoods *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegGoods.1",IID_IDMDocRegGoods,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="RG_KASSA")
		{
		IDMDocRegKassa *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegKassa.1",IID_IDMDocRegKassa,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="RG_OSTNOM")
		{
		IDMDocRegOstNom *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegOstNom.1",IID_IDMDocRegOstNom,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="RG_PAYSALE")
		{
		IDMDocRegPaySale *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegPaySale.1",IID_IDMDocRegPaySale,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="RG_VSRASCH")
		{
		IDMDocRegVsRasch *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegVsRasch.1",IID_IDMDocRegVsRasch,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="RG_CARDBAL")
		{
		IDMDocRegCardBalance *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegCardBalance.1",IID_IDMDocRegCardBalance,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

if(type_doc=="OTCHPOST")
		{
		IDMDocOtchetPost *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMDocOtchetPost,IID_IDMDocOtchetPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}


if(type_doc=="RG_OTCHPOST")
		{
		IDMDocRegOtchetPost *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMDocRegOtchetPost,IID_IDMDocRegOtchetPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		doc->kanRelease();
		}

return result;
}
//----------------------------------------------------------------------
bool TDMGurAllDoc::CancelDvRegDoc(AnsiString type_doc, __int64 id_doc)
{
bool result=false;
if(type_doc=="PRN")
        {
		IDMDocPrihNakl *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPrihNakl.1",IID_IDMDocPrihNakl,
													(void**)&DMDoc);
DMDoc->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
        }

if(type_doc=="CHK")
		{
		IDMDocCheck *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
													(void**)&DMDoc);
DMDoc->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
        }

if(type_doc=="SCH")
        {
		IDMDocSchet *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSchet.1",IID_IDMDocSchet,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		if (doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
        }

if(type_doc=="INV")
		{
		IDMDocInv *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocInv.1",IID_IDMDocInv,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		if (doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
        }

if(type_doc=="OSN")
        {
		IDMDocOstNom *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocOstNom.1",IID_IDMDocOstNom,
													(void**)&DMDoc);
DMDoc->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
        }

if(type_doc=="PER")
        {
		IDMDocPer *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPer.1",IID_IDMDocPer,
													(void**)&DMDoc);
DMDoc->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
        }


if(type_doc=="REA")
        {
		IDMDocReal *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocReal.1",IID_IDMDocReal,
													(void**)&DMDoc);
DMDoc->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
        }

if(type_doc=="SPN")
        {
		IDMDocSpisNom *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSpisNom.1",IID_IDMDocSpisNom,
													(void**)&DMDoc);
DMDoc->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
        }

if(type_doc=="VPO")
		{
		IDMDocVosvratPost *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVosvratPost.1",IID_IDMDocVosvratPost,
													(void**)&DMDoc);
DMDoc->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
        }


if(type_doc=="PKO")
        {
		IDMDocPKO *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPKO.1",IID_IDMDocPKO,
													(void**)&DMDoc);
DMDoc->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
        }

if(type_doc=="RKO")
        {
		IDMDocRKO *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRKO.1",IID_IDMDocRKO,
													(void**)&DMDoc);
DMDoc->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
		}

if(type_doc=="PLP")
		{
		IDMDocPlP *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPLP.1",IID_IDMDocPlP,
													(void**)&DMDoc);
DMDoc->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
        }

if(type_doc=="PNS")
		{
		IDMDocPostNaSchet *DMDoc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPostNaSchet.1",IID_IDMDocPostNaSchet,
													(void**)&DMDoc);
DMDoc->Init(InterfaceMainObject,InterfaceOwnerObject);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
		DMDoc->kanRelease();
        }


if(type_doc=="OSTVS")
        {
		IDMDocOstVs *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocOstVs.1",IID_IDMDocOstVs,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="SCHFACT")
        {
		IDMDocSchetFact *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSchetFact.1",IID_IDMDocSchetFact,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		if (doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
        }

if(type_doc=="REALROZN")
		{
		IDMDocRealRozn *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRealRozn.1",IID_IDMDocRealRozn,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}


if(type_doc=="PKOROZN")
        {
		IDMDocPKORozn *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocPKORozn.1",IID_IDMDocPKORozn,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		if (doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
        }

if(type_doc=="RKOROZN")
        {
		IDMDocRKORozn *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRKORozn.1",IID_IDMDocRKORozn,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		doc->IdDoc=id_doc;
		if (doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
        }


if(type_doc=="VPOK")
		{
		IDMDocVosvratPok *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVosvratPok.1",IID_IDMDocVosvratPok,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="ISMPRICE")
		{
		IDMDocIsmPrice *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocIsmPrice.1",IID_IDMDocIsmPrice,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
        //doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="SPOTROST")
		{
		IDMDocSpOtrOst *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSpOtrOst.1",IID_IDMDocSpOtrOst,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="REV")
		{
		IDMDocRev *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRev.1",IID_IDMDocRev,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="VIPPROD")
		{
		IDMDocVipuskProd *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVipuskProd.1",IID_IDMDocVipuskProd,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="SBKOMPL")
		{
		IDMDocSborkaKompl *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocSborkaKompl.1",IID_IDMDocSborkaKompl,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="RASBKOMPL")
		{
		IDMDocRasborkaKompl *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRasborkaKompl.1",IID_IDMDocRasborkaKompl,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="ZAMENA")
		{
		IDMDocZamena *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocZamena.1",IID_IDMDocZamena,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="KORRVS")
		{
		IDMDocKorrVs *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocKorrVS.1",IID_IDMDocKorrVs,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="VIPBANK")
		{
		IDMDocVipBanka *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocVipBanka.1",IID_IDMDocVipBanka,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}


if(type_doc=="RG_ADVCUST")
		{
		IDMDocRegAdvCust *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegAdvCust.1",IID_IDMDocRegAdvCust,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="RG_BANK")
		{
		IDMDocRegBank *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegBank.1",IID_IDMDocRegBank,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="RG_GOODS")
		{
		IDMDocRegGoods *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegGoods.1",IID_IDMDocRegGoods,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="RG_KASSA")
		{
		IDMDocRegKassa *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegKassa.1",IID_IDMDocRegKassa,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="RG_OSTNOM")
		{
		IDMDocRegOstNom *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegOstNom.1",IID_IDMDocRegOstNom,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="RG_PAYSALE")
		{
		IDMDocRegPaySale *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegPaySale.1",IID_IDMDocRegPaySale,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="RG_VSRASCH")
		{
		IDMDocRegVsRasch *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegVsRasch.1",IID_IDMDocRegVsRasch,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}

if(type_doc=="RG_CARDBAL")
		{
		IDMDocRegCardBalance *doc;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMDocRegCardBalance.1",IID_IDMDocRegCardBalance,
													(void**)&doc);
doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}


if(type_doc=="OTCHPOST")
		{
		IDMDocOtchetPost *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMDocOtchetPost,IID_IDMDocOtchetPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}



if(type_doc=="RG_OTCHPOST")
		{
		IDMDocRegOtchetPost *doc;
		InterfaceGlobalCom->kanCreateObject(ProgId_DMDocRegOtchetPost,IID_IDMDocRegOtchetPost,
													(void**)&doc);
		doc->Init(InterfaceMainObject,InterfaceOwnerObject);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		doc->kanRelease();
		}


return result;
}
//--------------------------------------------------------------------------


void __fastcall TDMGurAllDoc::TableSUMDOCGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
if (TableSUMDOC->AsFloat!=0)
		{
		Text=FloatToStrF(TableSUMDOC->AsFloat, ffFixed,15,2);

		}	
}
//---------------------------------------------------------------------------

void __fastcall TDMGurAllDoc::TableTDOCGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
Text=glGetNameDoc(TableTDOC->AsString);
}
//---------------------------------------------------------------------------

