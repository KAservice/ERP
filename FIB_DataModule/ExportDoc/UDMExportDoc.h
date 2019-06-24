//---------------------------------------------------------------------------

#ifndef UDMExportDocH
#define UDMExportDocH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

#include "UkanFile.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
//---------------------------------------------------------------------------
class TDMExportDoc : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *GurAllDoc;
	TpFIBTransaction *pFIBTr;
	TFIBBCDField *GurAllDocIDDOC;
	TFIBDateTimeField *GurAllDocPOSDOC;
	TFIBSmallIntField *GurAllDocPRDOC;
	TFIBIntegerField *GurAllDocNUMDOC;
	TFIBBCDField *GurAllDocIDFIRMDOC;
	TFIBBCDField *GurAllDocIDSKLDOC;
	TFIBBCDField *GurAllDocIDKLDOC;
	TFIBBCDField *GurAllDocIDDOGDOC;
	TFIBBCDField *GurAllDocSUMDOC;
	TFIBBCDField *GurAllDocIDUSERDOC;
	TFIBBCDField *GurAllDocIDDOCOSNDOC;
	TFIBBCDField *GurAllDocIDEXTDOC;
	TFIBBCDField *GurAllDocIDBASE_GALLDOC;
	TFIBBCDField *GurAllDocIDEXT_DOUT_GALLDOC;
	TFIBBCDField *GurAllDocIDEXT_BASE_GALLDOC;
	TpFIBDataSet *Check_Doc;
	TpFIBDataSet *Check_DocT;
	TFIBSmallIntField *Check_DocOPERCHK;
	TFIBIntegerField *Check_DocCODE_SDISCOUNT_CARD;
	TFIBIntegerField *Check_DocTCODENOM;
	TFIBBCDField *Check_DocTKOLCHKT;
	TFIBBCDField *Check_DocTKFCHKT;
	TFIBIntegerField *Check_DocTCODE_SED;
	TFIBBCDField *Check_DocTPRICECHKT;
	TFIBBCDField *Check_DocTSUMCHKT;
	TFIBBCDField *Check_DocTSKCHKT;
	TFIBBCDField *Check_DocTPRSKCHKT;
	TFIBBCDField *Check_DocIDKKM;
	TFIBBCDField *Check_DocID_TPRICE;
	TpFIBDataSet *TableFirm;
	TFIBBCDField *TableFirmIDFIRM;
	TpFIBDataSet *TableSklad;
	TpFIBDataSet *TableKassa;
	TFIBBCDField *TableSkladIDSKLAD;
	TFIBBCDField *TableKassaIDKKM;
	TpFIBDataSet *Per_Doc;
	TpFIBDataSet *Per_DocT;
	TFIBBCDField *Per_DocIDSKLPOLPER;
	TFIBBCDField *Per_DocIDRTPRICE_DPER;
	TFIBIntegerField *Per_DocTCODENOM;
	TFIBBCDField *Per_DocTKOLPERT;
	TFIBBCDField *Per_DocTKFPERT;
	TFIBIntegerField *Per_DocTCODE_SED;
	TFIBBCDField *Per_DocTPRICEPERT;
	TFIBBCDField *Per_DocTSUMPERT;
	TpFIBDataSet *PrihNakl_Doc;
	TpFIBDataSet *PrihNakl_DocT;
	TFIBIntegerField *PrihNakl_DocTCODENOM;
	TFIBBCDField *PrihNakl_DocTKOLPRNT;
	TFIBBCDField *PrihNakl_DocTKFPRNT;
	TFIBIntegerField *PrihNakl_DocTCODE_SED;
	TFIBBCDField *PrihNakl_DocTPRICEPRNT;
	TFIBBCDField *PrihNakl_DocTSUMPRNT;
	TFIBBCDField *PrihNakl_DocTNAC_DPRNT;
	TFIBBCDField *PrihNakl_DocTRPRICE_DPRNT;
	TFIBBCDField *PrihNakl_DocTRSUM_DPRNT;
	TFIBBCDField *PrihNakl_DocRSUM_DPRN;
	TFIBBCDField *PrihNakl_DocIDTPRICE;
	TFIBBCDField *PrihNakl_DocIDRTPRICE_DPRN;
	TpFIBDataSet *VPO_Doc;
	TpFIBDataSet *VPO_DocT;
	TFIBBCDField *VPO_DocIDTPRICE_DVPO;
	TFIBBCDField *VPO_DocIDRTPRICE_DVPO;
	TFIBIntegerField *VPO_DocTCODENOM;
	TFIBBCDField *VPO_DocTKOLVPOT;
	TFIBBCDField *VPO_DocTKFVPOT;
	TFIBIntegerField *VPO_DocTCODE_SED;
	TFIBBCDField *VPO_DocTPRICEVPOT;
	TFIBBCDField *VPO_DocTSUMVPOT;
	TFIBBCDField *VPO_DocTRPRICE_DVPOT;
	TFIBBCDField *VPO_DocTRSUM_DVPOT;
	TpFIBDataSet *IsmPrice_Doc;
	TpFIBDataSet *IsmPrice_DocT;
	TFIBBCDField *IsmPrice_DocIDOLDTPRICE_DISMPRICE;
	TFIBBCDField *IsmPrice_DocIDNEWTPRICE_DISMPRICE;
	TFIBIntegerField *IsmPrice_DocTCODENOM;
	TFIBBCDField *IsmPrice_DocTKOL_DISMPRICET;
	TFIBBCDField *IsmPrice_DocTKF_DISMPRICET;
	TFIBIntegerField *IsmPrice_DocTCODE_SED;
	TFIBBCDField *IsmPrice_DocTOLDPRICE_DISMPRICET;
	TFIBBCDField *IsmPrice_DocTNEWPRICE_DISMPRICET;
	TpFIBDataSet *Inv_Doc;
	TpFIBDataSet *Inv_DocT;
	TpFIBDataSet *Rev_Doc;
	TpFIBDataSet *Rev_DocT;
	TFIBBCDField *Inv_DocIDTPRICE_INV;
	TFIBIntegerField *Inv_DocTYPE_INV;
	TFIBBCDField *Inv_DocTKOLUCH_INVT;
	TFIBBCDField *Inv_DocTKOLFAKT_INVT;
	TFIBBCDField *Inv_DocTKF_INVT;
	TFIBIntegerField *Inv_DocTCODE_SED;
	TFIBBCDField *Inv_DocTPRICE_INVT;
	TFIBBCDField *Inv_DocTSUMF_INVT;
	TFIBBCDField *Rev_DocTKOL_DREVT;
	TFIBBCDField *Rev_DocTKF_DREVT;
	TFIBIntegerField *Rev_DocTCODE_SED;
	TFIBBCDField *Rev_DocTRPRICE_DREVT;
	TFIBBCDField *Rev_DocTRSUM_DREVT;
	TFIBBCDField *Rev_DocIDRTPRICE_DREV;
	TXMLDocument *XML;
	TFIBWideStringField *GurAllDocTDOC;
	TFIBWideStringField *GurAllDocGID_DOC;
	TFIBIntegerField *GurAllDocTYPEEXTDOC;
	TFIBWideStringField *GurAllDocNAMEFIRM;
	TFIBWideStringField *GurAllDocNAMESKLAD;
	TFIBWideStringField *GurAllDocNAMEKLIENT;
	TFIBWideStringField *GurAllDocNAME_USER;
	TFIBWideStringField *TableFirmNAMEFIRM;
	TFIBWideStringField *TableSkladNAMESKLAD;
	TFIBWideStringField *TableKassaNAMEKKM;
	TFIBIntegerField *Check_DocNCHECKCHK;
	TFIBIntegerField *Check_DocNKLCHK;
	TFIBWideStringField *Check_DocNAMEKKM;
	TFIBWideStringField *Check_DocNAME_TPRICE;
	TFIBWideStringField *Check_DocNAME_SDISCOUNT_CARD;
	TFIBWideStringField *Check_DocSHCODE_SDISCOUNT_CARD;
	TFIBWideStringField *Check_DocTNAMENOM;
	TFIBWideStringField *Check_DocTNAMEED;
	TFIBWideStringField *Check_DocTSHED;
	TFIBWideStringField *Per_DocNAMESKLAD;
	TFIBWideStringField *Per_DocNAME_TPRICE;
	TFIBWideStringField *Per_DocTNAMENOM;
	TFIBWideStringField *Per_DocTNAMEED;
	TFIBWideStringField *Per_DocTSHED;
	TFIBWideStringField *PrihNakl_DocNAME_ZAKTPRICE;
	TFIBWideStringField *PrihNakl_DocNAME_ROZNTPRICE;
	TFIBWideStringField *PrihNakl_DocTNAMENOM;
	TFIBWideStringField *PrihNakl_DocTNAMEED;
	TFIBWideStringField *PrihNakl_DocTSHED;
	TFIBWideStringField *VPO_DocNAME_ZAKTPRICE;
	TFIBWideStringField *VPO_DocNAME_ROZNTPRICE;
	TFIBWideStringField *VPO_DocTNAMENOM;
	TFIBWideStringField *VPO_DocTNAMEED;
	TFIBWideStringField *VPO_DocTSHED;
	TFIBWideStringField *IsmPrice_DocDESCR_DISMPRICE;
	TFIBWideStringField *IsmPrice_DocNAME_OLDTPRICE;
	TFIBWideStringField *IsmPrice_DocNAME_NEWTPRICE;
	TFIBWideStringField *IsmPrice_DocTNAMENOM;
	TFIBWideStringField *IsmPrice_DocTNAMEED;
	TFIBWideStringField *IsmPrice_DocTSHED;
	TFIBWideStringField *Inv_DocPRIM_INV;
	TFIBWideStringField *Inv_DocNAME_SINV;
	TFIBWideStringField *Inv_DocNAME_TPRICE;
	TFIBWideStringField *Inv_DocTNAMENOM;
	TFIBIntegerField *Inv_DocTCODENOM;
	TFIBWideStringField *Inv_DocTNAMEED;
	TFIBWideStringField *Inv_DocTSHED;
	TFIBWideStringField *Rev_DocNAME_SINV;
	TFIBWideStringField *Rev_DocDESCR_DREV;
	TFIBWideStringField *Rev_DocNAME_TPRICE;
	TFIBWideStringField *Rev_DocTNAMENOM;
	TFIBIntegerField *Rev_DocTCODENOM;
	TFIBWideStringField *Rev_DocTNAMEED;
	TFIBWideStringField *Rev_DocTSHED;
	TFIBWideStringField *GurAllDocINNKLIENT;
	TFIBWideStringField *PrihNakl_DocNUMDOCPOST_DPRN;
	TFIBDateTimeField *PrihNakl_DocPOSDOCPOST_DPRN;
	TFIBWideStringField *VPO_DocNUMDOCPOST_DVPO;
	TFIBDateTimeField *VPO_DocPOSDOCPOST_DVPO;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
	__fastcall TDMExportDoc(TComponent* Owner);



		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;


        bool Init(void);


		//IMainInterface

		int CodeError;
		UnicodeString TextError;



   TkanFile * OutFile;
   void SaveFileXML(UnicodeString str);
   AnsiString CatalogObmena;
   AnsiString FileNameOut;
   int Num;

   void ExportXMLAllDoc(TDateTime pos_nach, TDateTime pos_con);
   void ExportXMLDocCheck(__int64 id_doc);
   void ExportXMLDocPer(__int64 id_doc);
   void ExportXMLDocPrihNakl(__int64 id_doc);
   void ExportXMLDocVosvratPost(__int64 id_doc);
   void ExportXMLDocIsmPrice(__int64 id_doc);

   void ExportXMLDocInv(__int64 id_doc);
   void ExportXMLDocRev(__int64 id_doc);


   AnsiString GetTextDataTime(TDateTime pos);


   void ExportXMLSpr(void);
   void OutputSprFirm(void);
   void OutputSprSklad(void);
   void OutputSprKassa(void);


   void ImportDoc(AnsiString file_name);
   void ImportDocCHK(_di_IXMLNode  xml_doc);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMExportDoc *DMExportDoc;
//---------------------------------------------------------------------------
#endif
