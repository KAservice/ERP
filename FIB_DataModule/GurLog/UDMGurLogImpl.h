#ifndef UDMGurLogImplH
#define UDMGurLogImplH
#include "IDMGurLog.h"
#include "UDMGurLog.h"
//---------------------------------------------------------------
class __declspec(uuid("{F0B31C53-8241-43DE-B43C-79B150827226}")) TDMGurLogImpl : public IDMGurLog
{
public:
   TDMGurLogImpl();
   ~TDMGurLogImpl();
   TDMGurLog * Object;
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

//IDMGurLog
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBDateTimeField * get_TablePOS_LOG(void);
   virtual void set_TablePOS_LOG(TFIBDateTimeField * TablePOS_LOG);

   virtual TFIBIntegerField * get_TableTYPE_LOG(void);
   virtual void set_TableTYPE_LOG(TFIBIntegerField * TableTYPE_LOG);

   virtual TFIBIntegerField * get_TableOPER_LOG(void);
   virtual void set_TableOPER_LOG(TFIBIntegerField * TableOPER_LOG);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBBCDField * get_TableID_LOG(void);
   virtual void set_TableID_LOG(TFIBBCDField * TableID_LOG);

   virtual TFIBBCDField * get_TableIDUSER_LOG(void);
   virtual void set_TableIDUSER_LOG(TFIBBCDField * TableIDUSER_LOG);

   virtual TFIBWideStringField * get_TableMESSAGE_LOG(void);
   virtual void set_TableMESSAGE_LOG(TFIBWideStringField * TableMESSAGE_LOG);

   virtual TFIBIntegerField * get_TableOBJECT_LOG(void);
   virtual void set_TableOBJECT_LOG(TFIBIntegerField * TableOBJECT_LOG);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual __int64 get_IdUser(void);
   virtual void set_IdUser(__int64 IdUser);

   virtual int get_Type(void);
   virtual void set_Type(int Type);

   virtual int get_ObjectLog(void);
   virtual void set_ObjectLog(int ObjectLog);

   virtual int get_Oper(void);
   virtual void set_Oper(int Oper);

   virtual bool get_OtborVkl(void);
   virtual void set_OtborVkl(bool OtborVkl);

   virtual bool get_OtborPoUser(void);
   virtual void set_OtborPoUser(bool OtborPoUser);

   virtual bool get_OtborPoType(void);
   virtual void set_OtborPoType(bool OtborPoType);

   virtual bool get_OtborPoObject(void);
   virtual void set_OtborPoObject(bool OtborPoObject);

   virtual bool get_OtborPoOper(void);
   virtual void set_OtborPoOper(bool OtborPoOper);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual void OpenTable();
   virtual void UpdateTable(void);
};
#define CLSID_TDMGurLogImpl __uuidof(TDMGurLogImpl)
#endif
