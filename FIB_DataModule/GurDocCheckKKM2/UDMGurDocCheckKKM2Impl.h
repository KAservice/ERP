#ifndef UDMGurDocCheckKKM2ImplH
#define UDMGurDocCheckKKM2ImplH
#include "IDMGurDocCheckKKM2.h"
#include "UDMGurDocCheckKKM2.h"
//---------------------------------------------------------------
class __declspec(uuid("{20436750-1473-405E-96C0-976741A037CE}"))TDMGurDocCheckKKM2Impl : public IDMGurDocCheckKKM2
{
public:
   TDMGurDocCheckKKM2Impl();
   ~TDMGurDocCheckKKM2Impl();
   TDMGurDocCheckKKM2 * Object;
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

//IDMGurDocCheckKKM2
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TFIBIntegerField * get_TableNUMDOC(void);
   virtual void set_TableNUMDOC(TFIBIntegerField * TableNUMDOC);

   virtual TFIBDateTimeField * get_TablePOSDOC(void);
   virtual void set_TablePOSDOC(TFIBDateTimeField * TablePOSDOC);

   virtual TFIBSmallIntField * get_TablePRDOC(void);
   virtual void set_TablePRDOC(TFIBSmallIntField * TablePRDOC);

   virtual TFIBBCDField * get_TableSUMDOC(void);
   virtual void set_TableSUMDOC(TFIBBCDField * TableSUMDOC);

   virtual TFIBBCDField * get_TableIDDOC(void);
   virtual void set_TableIDDOC(TFIBBCDField * TableIDDOC);

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

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

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

   virtual bool OpenTable(void);
   virtual void UpdateTable(void);
};
#define CLSID_TDMGurDocCheckKKM2Impl __uuidof(TDMGurDocCheckKKM2Impl)
#endif
