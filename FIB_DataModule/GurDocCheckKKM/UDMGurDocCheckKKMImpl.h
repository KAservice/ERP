#ifndef UDMGurDocCheckKKMImplH
#define UDMGurDocCheckKKMImplH
#include "IDMGurDocCheckKKM.h"
#include "UDMGurDocCheckKKM.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMGurDocCheckKKMImpl)) TDMGurDocCheckKKMImpl : public IDMGurDocCheckKKM
{
public:
   TDMGurDocCheckKKMImpl();
   ~TDMGurDocCheckKKMImpl();
   TDMGurDocCheckKKM * Object;
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

//IDMGurDocCheckKKM
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TFIBIntegerField * get_TableNUMDOC(void);
   virtual void set_TableNUMDOC(TFIBIntegerField * TableNUMDOC);

   virtual TFIBDateTimeField * get_TablePOSDOC(void);
   virtual void set_TablePOSDOC(TFIBDateTimeField * TablePOSDOC);

   virtual TFIBSmallIntField * get_TablePRDOC(void);
   virtual void set_TablePRDOC(TFIBSmallIntField * TablePRDOC);

   virtual TFIBBCDField * get_TableSUMDOC(void);
   virtual void set_TableSUMDOC(TFIBBCDField * TableSUMDOC);

   virtual TFIBLargeIntField * get_TableIDDOC(void);
   virtual void set_TableIDDOC(TFIBLargeIntField * TableIDDOC);

   virtual TFIBIntegerField * get_TableNCHECKCHK(void);
   virtual void set_TableNCHECKCHK(TFIBIntegerField * TableNCHECKCHK);

   virtual TFIBIntegerField * get_TableNKLCHK(void);
   virtual void set_TableNKLCHK(TFIBIntegerField * TableNKLCHK);

   virtual TFIBIntegerField * get_TableOPERCHK(void);
   virtual void set_TableOPERCHK(TFIBIntegerField * TableOPERCHK);

   virtual TFIBWideStringField * get_TableNAMEKKM(void);
   virtual void set_TableNAMEKKM(TFIBWideStringField * TableNAMEKKM);

   virtual TFIBWideStringField * get_TableNAMEFIRM(void);
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM);

   virtual TFIBWideStringField * get_TableNAMESKLAD(void);
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBBCDField * get_TableOPLNALCHK(void);
   virtual void set_TableOPLNALCHK(TFIBBCDField * TableOPLNALCHK);

   virtual TFIBBCDField * get_TableOPLPCCHK(void);
   virtual void set_TableOPLPCCHK(TFIBBCDField * TableOPLPCCHK);

   virtual TFIBBCDField * get_TableOPLPLATCARD_ALL_DCHK(void);
   virtual void set_TableOPLPLATCARD_ALL_DCHK(TFIBBCDField * TableOPLPLATCARD_ALL_DCHK);

   virtual TFIBBCDField * get_TableOPLCREDITCARD_ALL_DCHK(void);
   virtual void set_TableOPLCREDITCARD_ALL_DCHK(TFIBBCDField * TableOPLCREDITCARD_ALL_DCHK);

   virtual TFIBBCDField * get_TableOPL_OTHER_DCHK(void);
   virtual void set_TableOPL_OTHER_DCHK(TFIBBCDField * TableOPL_OTHER_DCHK);

   virtual __int64 get_IdDoc(void);
   virtual void set_IdDoc(__int64 IdDoc);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual __int64 get_IdKKM(void);
   virtual void set_IdKKM(__int64 IdKKM);

   virtual int get_NumberKL(void);
   virtual void set_NumberKL(int NumberKL);

   virtual void OpenTable();
   virtual void UpdateTable(void);
};
#define CLSID_TDMGurDocCheckKKMImpl __uuidof(TDMGurDocCheckKKMImpl)
#endif
