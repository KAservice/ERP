//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMGurAllDoc.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#include "UDMDocPrihNakl.h"
#include "UDMSetup.h"
#include "UDMDocCheck.h"
#include "UDMDocInv.h"
#include "UDMDocOstNom.h"
#include "UDMDocPer.h"
#include "UDMDocPlP.h"
#include "UDMDocPostNaSchet.h"
#include "UDMDocReal.h"
#include "UDMDocRepKKM.h"
#include "UDMDocRKO.h"
#include "UDMDocSpisNom.h"
#include "UDMDocVosvratPost.h"
#include "UDMDocPKO.h"
#include "UDMDocOstVs.h"
#include "UDMDocPKORozn.h"
#include "UDMDocRealRozn.h"
#include "UDMDocRKORozn.h"
#include "UDMDocSchetFact.h"
#include "UDMDocSchet.h"
//#include "UDMDocRecKDR.h"
#include "UDMDocVosvratPok.h"
#include "UDMDocIsmPrice.h"
#include "UDMDocRev.h"
#include "UDMDocSpOtrOst.h"
#include "UDMDocRealRest.h"
#include "UDMDocVipuskProd.h"
#include "UDMDocSborkaKompl.h"
#include "UDMDocRasborkaKompl.h"
#include "UDMDocZamena.h"
#include "UDMDocKorrVs.h"
#include "UDMDocVipBanka.h"
#include "UDMDocRegAdvCust.h"
#include "UDMDocRegBank.h"
#include "UDMDocRegGoods.h"
#include "UDMDocRegKassa.h"
#include "UDMDocRegOstNom.h"
#include "UDMDocRegPaySale.h"
#include "UDMDocRegVsRasch.h"
#include "UDMDocRegCardBalance.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
//TDMGurAllDoc *DMGurAllDoc;
extern String glGetNameDoc(String StrCodeDoc);
extern AnsiString glStringFullTypeDoc;
extern AnsiString glStringFullTypeDocNoCheck;
//---------------------------------------------------------------------------
__fastcall TDMGurAllDoc::TDMGurAllDoc(TComponent* Owner)
        : TDataModule(Owner)
{
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

void __fastcall TDMGurAllDoc::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
RegOstNomDv->Active=false;

}
//---------------------------------------------------------------------------
void TDMGurAllDoc::OpenTable()
{
Table->Active=false;
AnsiString zapros="select GALLDOC.*, NAMEFIRM, NAMESKLAD, NAMEKLIENT, NAME_USER, NAME_SPROJECT ";
zapros=zapros+" from GALLDOC";
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
                zapros=zapros+" AND TDOC in ("+glStringFullTypeDocNoCheck+" ) ";
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
        TDMDocPrihNakl *DMDocPRN= new TDMDocPrihNakl (Application);
		DMDocPRN->IdDoc=id_doc;
		DMDocPRN->EnableDvReg=true;
        if (DMDocPRN->DvRegDoc()==true){result=true;}
        delete DMDocPRN;
        }

if(type_doc=="CHK")
        {
        TDMDocCheck *DMDocCHK= new TDMDocCheck (Application);
        DMDocCHK->EnableDvReg=true;
		DMDocCHK->IdDoc=id_doc;
        if (DMDocCHK->DvRegDoc()==true){result=true;}
        delete DMDocCHK;
        }

if(type_doc=="SCH")
        {
        TDMDocSchet *doc= new TDMDocSchet  (Application);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
        if (doc->DvRegDoc()==true){result=true;}
        delete doc;
        }

if(type_doc=="INV")
        {
        TDMDocInv *doc= new TDMDocInv  (Application);
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
        doc->OpenDoc(id_doc);
        if (doc->DvRegDoc()==true){result=true;}
        delete doc;
        }

if(type_doc=="OSN")
        {
        TDMDocOstNom *DMDocOstNom= new TDMDocOstNom  (Application);
		DMDocOstNom->IdDoc=id_doc;
		DMDocOstNom->EnableDvReg=true;
        if (DMDocOstNom->DvRegDoc()==true){result=true;}
        delete DMDocOstNom;
        }

if(type_doc=="PER")
        {
        TDMDocPer *DMDocPer= new TDMDocPer  (Application);
        DMDocPer->EnableDvReg=true;
		DMDocPer->IdDoc=id_doc;
		DMDocPer->EnableDvReg=true;
        if (DMDocPer->DvRegDoc()==true){result=true;}
        delete DMDocPer;
        }


if(type_doc=="REA")
        {
        TDMDocReal *DMDocReal= new TDMDocReal  (Application);
        DMDocReal->EnableDvReg=true;
		DMDocReal->IdDoc=id_doc;
		DMDocReal->EnableDvReg=true;
        if (DMDocReal->DvRegDoc()==true){result=true;}
        delete DMDocReal;
        }

if(type_doc=="SPN")
        {
        TDMDocSpisNom *DMDocSpisNom= new TDMDocSpisNom  (Application);
		DMDocSpisNom->IdDoc=id_doc;
		DMDocSpisNom->EnableDvReg=true;
        if (DMDocSpisNom->DvRegDoc()==true){result=true;}
        delete DMDocSpisNom;
        }

if(type_doc=="VPO")
        {
        TDMDocVosvratPost *DMDocVosvratPost= new TDMDocVosvratPost  (Application);
		DMDocVosvratPost->IdDoc=id_doc;
		DMDocVosvratPost->EnableDvReg=true;
        if (DMDocVosvratPost->DvRegDoc()==true){result=true;}
        delete DMDocVosvratPost;
        }


if(type_doc=="PKO")
        {
        TDMDocPKO *DMDocPKO= new TDMDocPKO  (Application);
		DMDocPKO->IdDoc=id_doc;
		DMDocPKO->EnableDvReg=true;
        if (DMDocPKO->DvRegDoc()==true){result=true;}
        delete DMDocPKO;
        }

if(type_doc=="RKO")
        {
        TDMDocRKO *DMDocRKO= new TDMDocRKO  (Application);
		DMDocRKO->IdDoc=id_doc;
		DMDocRKO->EnableDvReg=true;
        if (DMDocRKO->DvRegDoc()==true){result=true;}
        delete DMDocRKO;
        }

if(type_doc=="PLP")
        {
        TDMDocPLP *DMDocPLP= new TDMDocPLP  (Application);
		DMDocPLP->IdDoc=id_doc;
		DMDocPLP->EnableDvReg=true;
        if (DMDocPLP->DvRegDoc()==true){result=true;}
        delete DMDocPLP;
        }

if(type_doc=="PNS")
        {
        TDMDocPostNaSchet *DMDocPostNaSchet = new TDMDocPostNaSchet  (Application);
		DMDocPostNaSchet->IdDoc=id_doc;
		DMDocPostNaSchet->EnableDvReg=true;
        if (DMDocPostNaSchet->DvRegDoc()==true){result=true;}
        delete DMDocPostNaSchet;
        }


if(type_doc=="OSTVS")
        {
        TDMDocOstVs *doc= new TDMDocOstVs  (Application);
        doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
        if(doc->DvRegDoc()==true)result=true;
        delete doc;
        }

if(type_doc=="SCHFACT")
        {
        TDMDocSchetFact *doc= new TDMDocSchetFact  (Application);
        doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
        if (doc->DvRegDoc()==true)result=true;
        delete doc;
        }

if(type_doc=="REALROZN")
		{
		TDMDocRealRozn *doc= new TDMDocRealRozn  (Application);
		doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="REAL_REST")
		{
		TDMDocRealRest *doc= new TDMDocRealRest (Application);
		doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->OpenDoc(id_doc);
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="PKOROZN")
        {
        TDMDocPKORozn *doc= new TDMDocPKORozn  (Application);
        //doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
        if(doc->DvRegDoc()==true)result=true;
        delete doc;
        }


if(type_doc=="RKOROZN")
        {
        TDMDocRKORozn *doc= new TDMDocRKORozn  (Application);
        //doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
        if(doc->DvRegDoc()==true) result=true;
        delete doc;
        }

if(type_doc=="REC_KDR")
        {

		}

if(type_doc=="VPOK")
        {
		TDMDocVosvratPok *doc= new TDMDocVosvratPok  (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}
if(type_doc=="ISMPRICE")
		{
		TDMDocIsmPrice *doc= new TDMDocIsmPrice  (Application);
        //doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="SPOTROST")
		{
		TDMDocSpOtrOst *doc= new TDMDocSpOtrOst  (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="REV")
		{
		TDMDocRev *doc= new TDMDocRev (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="VIPPROD")
		{
		TDMDocVipuskProd *doc= new TDMDocVipuskProd (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="SBKOMPL")
		{
		TDMDocSborkaKompl *doc= new TDMDocSborkaKompl (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="RASBKOMPL")
		{
		TDMDocRasborkaKompl *doc= new TDMDocRasborkaKompl (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="ZAMENA")
		{
		TDMDocZamena *doc= new TDMDocZamena (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}


if(type_doc=="KORRVS")
		{
		TDMDocKorrVS *doc= new TDMDocKorrVS (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="VIPBANK")
		{
		TDMDocVipBanka *doc= new TDMDocVipBanka (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="RG_ADVCUST")
		{
		TDMDocRegAdvCust *doc= new TDMDocRegAdvCust (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="RG_BANK")
		{
		TDMDocRegBank *doc= new TDMDocRegBank (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="RG_GOODS")
		{
		TDMDocRegGoods *doc= new TDMDocRegGoods (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="RG_KASSA")
		{
		TDMDocRegKassa *doc= new TDMDocRegKassa (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="RG_OSTNOM")
		{
		TDMDocRegOstNom *doc= new TDMDocRegOstNom (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="RG_PAYSALE")
		{
		TDMDocRegPaySale *doc= new TDMDocRegPaySale (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="RG_VSRASCH")
		{
		TDMDocRegVsRasch *doc= new TDMDocRegVsRasch (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

if(type_doc=="RG_CARDBAL")
		{
		TDMDocRegCardBalance *doc= new TDMDocRegCardBalance (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		doc->EnableDvReg=true;
		if(doc->DvRegDoc()==true) result=true;
		delete doc;
		}

return result;
}
//----------------------------------------------------------------------
bool TDMGurAllDoc::CancelDvRegDoc(AnsiString type_doc, __int64 id_doc)
{
bool result=false;
if(type_doc=="PRN")
        {
        TDMDocPrihNakl *DMDoc= new TDMDocPrihNakl (Application);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
        delete DMDoc;
        }

if(type_doc=="CHK")
        {
        TDMDocCheck *DMDoc= new TDMDocCheck (Application);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
        delete DMDoc;
        }

if(type_doc=="SCH")
        {
        TDMDocSchet *doc= new TDMDocSchet  (Application);
		doc->IdDoc=id_doc;
		if (doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
        delete doc;
        }

if(type_doc=="INV")
        {
        TDMDocInv *doc= new TDMDocInv  (Application);
		doc->IdDoc=id_doc;
		if (doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
        delete doc;
        }

if(type_doc=="OSN")
        {
        TDMDocOstNom *DMDoc= new TDMDocOstNom  (Application);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
        delete DMDoc;
        }

if(type_doc=="PER")
        {
        TDMDocPer *DMDoc= new TDMDocPer  (Application);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
        delete DMDoc;
        }


if(type_doc=="REA")
        {
        TDMDocReal *DMDoc= new TDMDocReal  (Application);
		DMDoc->IdDoc=id_doc;
		if (DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
        delete DMDoc;
        }

if(type_doc=="SPN")
        {
        TDMDocSpisNom *DMDoc= new TDMDocSpisNom  (Application);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
        delete DMDoc;
        }

if(type_doc=="VPO")
        {
        TDMDocVosvratPost *DMDoc= new TDMDocVosvratPost  (Application);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
        delete DMDoc;
        }


if(type_doc=="PKO")
        {
        TDMDocPKO *DMDoc= new TDMDocPKO  (Application);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
        delete DMDoc;
        }

if(type_doc=="RKO")
        {
        TDMDocRKO *DMDoc= new TDMDocRKO  (Application);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
        delete DMDoc;
        }

if(type_doc=="PLP")
        {
        TDMDocPLP *DMDoc= new TDMDocPLP  (Application);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
        delete DMDoc;
        }

if(type_doc=="PNS")
        {
        TDMDocPostNaSchet *DMDoc= new TDMDocPostNaSchet  (Application);
		DMDoc->IdDoc=id_doc;
		if(DMDoc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=DMDoc->TextError;}
        delete DMDoc;
        }


if(type_doc=="OSTVS")
        {
        TDMDocOstVs *doc= new TDMDocOstVs  (Application);
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
        delete doc;
        }

if(type_doc=="SCHFACT")
        {
        TDMDocSchetFact *doc= new TDMDocSchetFact (Application);
		doc->IdDoc=id_doc;
		if (doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
        delete doc;
        }

if(type_doc=="REALROZN")
		{
		TDMDocRealRozn *doc= new TDMDocRealRozn (Application);
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="REAL_REST")
		{
		TDMDocRealRest *doc= new TDMDocRealRest(Application);
		doc->IdDoc=id_doc;
		doc->OpenDoc(id_doc);
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="PKOROZN")
        {
        TDMDocPKORozn *doc= new TDMDocPKORozn (Application);
		doc->IdDoc=id_doc;
		if (doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
        delete doc;
        }

if(type_doc=="RKOROZN")
        {
        TDMDocRKORozn *doc= new TDMDocRKORozn (Application);
		doc->IdDoc=id_doc;
		if (doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
        delete doc;
        }
        
if(type_doc=="REC_KDR")
		{

		}

if(type_doc=="VPOK")
		{
		TDMDocVosvratPok *doc= new TDMDocVosvratPok  (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="ISMPRICE")
		{
		TDMDocIsmPrice *doc= new TDMDocIsmPrice  (Application);
        //doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="SPOTROST")
		{
		TDMDocSpOtrOst *doc= new TDMDocSpOtrOst  (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="REV")
		{
		TDMDocRev *doc= new TDMDocRev (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="VIPPROD")
		{
		TDMDocVipuskProd *doc= new TDMDocVipuskProd (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="SBKOMPL")
		{
		TDMDocSborkaKompl *doc= new TDMDocSborkaKompl (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="RASBKOMPL")
		{
		TDMDocRasborkaKompl *doc= new TDMDocRasborkaKompl (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="ZAMENA")
		{
		TDMDocZamena *doc= new TDMDocZamena (Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="KORRVS")
		{
		TDMDocKorrVS *doc= new TDMDocKorrVS(Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="VIPBANK")
		{
		TDMDocVipBanka *doc= new TDMDocVipBanka(Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}


if(type_doc=="RG_ADVCUST")
		{
		TDMDocRegAdvCust *doc= new TDMDocRegAdvCust(Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="RG_BANK")
		{
		TDMDocRegBank *doc= new TDMDocRegBank(Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="RG_GOODS")
		{
		TDMDocRegGoods *doc= new TDMDocRegGoods(Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="RG_KASSA")
		{
		TDMDocRegKassa *doc= new TDMDocRegKassa(Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="RG_OSTNOM")
		{
		TDMDocRegOstNom *doc= new TDMDocRegOstNom(Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="RG_PAYSALE")
		{
		TDMDocRegPaySale *doc= new TDMDocRegPaySale(Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="RG_VSRASCH")
		{
		TDMDocRegVsRasch *doc= new TDMDocRegVsRasch(Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}

if(type_doc=="RG_CARDBAL")
		{
		TDMDocRegCardBalance *doc= new TDMDocRegCardBalance(Application);
		//doc->EnableDvReg=true;
		doc->IdDoc=id_doc;
		if(doc->CancelDvRegDoc()==true)
			{ result=true;}
		else {TextError=doc->TextError;}
		delete doc;
		}


return result;
}
//--------------------------------------------------------------------------

void __fastcall TDMGurAllDoc::TableTDOCGetText(TField *Sender, AnsiString &Text,
      bool DisplayText)
{
Text=glGetNameDoc(TableTDOC->AsString);
}
//---------------------------------------------------------------------------

void __fastcall TDMGurAllDoc::TableSUMDOCGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
if (TableSUMDOC->AsFloat!=0)
		{
		Text=FloatToStrF(TableSUMDOC->AsFloat, ffFixed,15,2);

		}	
}
//---------------------------------------------------------------------------

