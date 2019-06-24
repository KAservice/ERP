#ifndef UDMGurAllDocImplH
#define UDMGurAllDocImplH
#include "IDMGurAllDoc.h"
#include "UDMGurAllDoc.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMGurAllDocImpl)) TDMGurAllDocImpl : public IDMGurAllDoc
{
public:
   TDMGurAllDocImpl();
   ~TDMGurAllDocImpl();
   TDMGurAllDoc * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

//IDMGurAllDoc
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TFIBSmallIntField * get_TablePRDOC(void);
   virtual void set_TablePRDOC(TFIBSmallIntField * TablePRDOC);

   virtual TFIBIntegerField * get_TableNUMDOC(void);
   virtual void set_TableNUMDOC(TFIBIntegerField * TableNUMDOC);

   virtual TFIBBCDField * get_TableSUMDOC(void);
   virtual void set_TableSUMDOC(TFIBBCDField * TableSUMDOC);

   virtual TpFIBDataSet * get_IBQ(void);
   virtual void set_IBQ(TpFIBDataSet * IBQ);

   virtual TFIBDateTimeField * get_TablePOSDOC(void);
   virtual void set_TablePOSDOC(TFIBDateTimeField * TablePOSDOC);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_TableIDDOC(void);
   virtual void set_TableIDDOC(TFIBBCDField * TableIDDOC);

   virtual TFIBBCDField * get_TableIDFIRMDOC(void);
   virtual void set_TableIDFIRMDOC(TFIBBCDField * TableIDFIRMDOC);

   virtual TFIBBCDField * get_TableIDSKLDOC(void);
   virtual void set_TableIDSKLDOC(TFIBBCDField * TableIDSKLDOC);

   virtual TFIBBCDField * get_TableIDKLDOC(void);
   virtual void set_TableIDKLDOC(TFIBBCDField * TableIDKLDOC);

   virtual TFIBBCDField * get_TableIDDOGDOC(void);
   virtual void set_TableIDDOGDOC(TFIBBCDField * TableIDDOGDOC);

   virtual TFIBBCDField * get_TableIDUSERDOC(void);
   virtual void set_TableIDUSERDOC(TFIBBCDField * TableIDUSERDOC);

   virtual TFIBBCDField * get_TableIDDOCOSNDOC(void);
   virtual void set_TableIDDOCOSNDOC(TFIBBCDField * TableIDDOCOSNDOC);

   virtual TFIBBCDField * get_TableIDEXTDOC(void);
   virtual void set_TableIDEXTDOC(TFIBBCDField * TableIDEXTDOC);

   virtual TFIBBCDField * get_TableIDBASE_GALLDOC(void);
   virtual void set_TableIDBASE_GALLDOC(TFIBBCDField * TableIDBASE_GALLDOC);

   virtual TFIBBCDField * get_TableIDPROJECT_GALLDOC(void);
   virtual void set_TableIDPROJECT_GALLDOC(TFIBBCDField * TableIDPROJECT_GALLDOC);

   virtual TFIBWideStringField * get_TableTDOC(void);
   virtual void set_TableTDOC(TFIBWideStringField * TableTDOC);

   virtual TFIBWideStringField * get_TableGID_DOC(void);
   virtual void set_TableGID_DOC(TFIBWideStringField * TableGID_DOC);

   virtual TFIBWideStringField * get_TablePREFIKSDOC(void);
   virtual void set_TablePREFIKSDOC(TFIBWideStringField * TablePREFIKSDOC);

   virtual TFIBIntegerField * get_TableTYPEEXTDOC(void);
   virtual void set_TableTYPEEXTDOC(TFIBIntegerField * TableTYPEEXTDOC);

   virtual TFIBWideStringField * get_TableNAMEFIRM(void);
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM);

   virtual TFIBWideStringField * get_TableNAMESKLAD(void);
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBWideStringField * get_TableNAME_SPROJECT(void);
   virtual void set_TableNAME_SPROJECT(TFIBWideStringField * TableNAME_SPROJECT);

   virtual TFIBWideStringField * get_TablePREFIKS_NUM_GALLDOC(void);
   virtual void set_TablePREFIKS_NUM_GALLDOC(TFIBWideStringField * TablePREFIKS_NUM_GALLDOC);

   virtual TFIBBCDField * get_TableIDBUSINOP_GALLDOC(void);
   virtual void set_TableIDBUSINOP_GALLDOC(TFIBBCDField * TableIDBUSINOP_GALLDOC);

   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void);
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual UnicodeString get_StringTypeDoc(void);
   virtual void set_StringTypeDoc(UnicodeString StringTypeDoc);

   virtual bool get_OtborVkl(void);
   virtual void set_OtborVkl(bool OtborVkl);

   virtual bool get_NoCheck(void);
   virtual void set_NoCheck(bool NoCheck);

   virtual void OpenTable();
   virtual void UpdateTable(void);
   virtual __int64 FindDocPoIdDog(__int64 iddogovor);
   virtual bool CancelDvRegDoc(AnsiString type_doc, __int64 id_doc);
   virtual bool DvRegDoc(AnsiString type_doc, __int64 id_doc);
   virtual void AllCancelDvRegDoc(void);
   virtual void AllDvRegDoc(void);
};
#define CLSID_TDMGurAllDocImpl __uuidof(TDMGurAllDocImpl)
#endif
