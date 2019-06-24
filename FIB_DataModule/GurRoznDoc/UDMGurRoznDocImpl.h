#ifndef UDMGurRoznDocImplH
#define UDMGurRoznDocImplH
#include "IDMGurRoznDoc.h"
#include "UDMGurRoznDoc.h"
//---------------------------------------------------------------
class __declspec(uuid("{E1C5B1D4-1E69-436C-B0D1-3783D76DCD5A}"))TDMGurRoznDocImpl : public IDMGurRoznDoc
{
public:
   TDMGurRoznDocImpl();
   ~TDMGurRoznDocImpl();
   TDMGurRoznDoc * Object;
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

//IDMGurRoznDoc
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_IBQ(void);
   virtual void set_IBQ(TpFIBDataSet * IBQ);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TFIBDateTimeField * get_TablePOSDOC(void);
   virtual void set_TablePOSDOC(TFIBDateTimeField * TablePOSDOC);

   virtual TFIBSmallIntField * get_TablePRDOC(void);
   virtual void set_TablePRDOC(TFIBSmallIntField * TablePRDOC);

   virtual TFIBIntegerField * get_TableNUMDOC(void);
   virtual void set_TableNUMDOC(TFIBIntegerField * TableNUMDOC);

   virtual TFIBBCDField * get_TableSUMDOC(void);
   virtual void set_TableSUMDOC(TFIBBCDField * TableSUMDOC);

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

   virtual TFIBIntegerField * get_TableTYPEEXTDOC(void);
   virtual void set_TableTYPEEXTDOC(TFIBIntegerField * TableTYPEEXTDOC);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBBCDField * get_TableIDBASE_GALLDOC(void);
   virtual void set_TableIDBASE_GALLDOC(TFIBBCDField * TableIDBASE_GALLDOC);

   virtual TFIBWideStringField * get_TableTDOC(void);
   virtual void set_TableTDOC(TFIBWideStringField * TableTDOC);

   virtual TFIBWideStringField * get_TableGID_DOC(void);
   virtual void set_TableGID_DOC(TFIBWideStringField * TableGID_DOC);

   virtual TFIBWideStringField * get_TablePREFIKSDOC(void);
   virtual void set_TablePREFIKSDOC(TFIBWideStringField * TablePREFIKSDOC);

   virtual TFIBBCDField * get_TableIDPROJECT_GALLDOC(void);
   virtual void set_TableIDPROJECT_GALLDOC(TFIBBCDField * TableIDPROJECT_GALLDOC);

   virtual TFIBWideStringField * get_TableNAMEFIRM(void);
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM);

   virtual TFIBWideStringField * get_TableNAMESKLAD(void);
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

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

   virtual UnicodeString get_StringFullTypeDoc(void);
   virtual void set_StringFullTypeDoc(UnicodeString StringFullTypeDoc);

   virtual bool get_OtborVkl(void);
   virtual void set_OtborVkl(bool OtborVkl);

   virtual bool get_OtborPoKlient(void);
   virtual void set_OtborPoKlient(bool OtborPoKlient);

   virtual bool get_OtborPoFirm(void);
   virtual void set_OtborPoFirm(bool OtborPoFirm);

   virtual bool get_OtborPoSklad(void);
   virtual void set_OtborPoSklad(bool OtborPoSklad);

   virtual bool get_OtborPoTypeDoc(void);
   virtual void set_OtborPoTypeDoc(bool OtborPoTypeDoc);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual __int64 get_IdBase(void);
   virtual void set_IdBase(__int64 IdBase);

   virtual void OpenTable();
   virtual void UpdateTable(void);
   virtual int FindDocPoIdDog(__int64 iddogovor);
};
#define CLSID_TDMGurRoznDocImpl __uuidof(TDMGurRoznDocImpl)
#endif
