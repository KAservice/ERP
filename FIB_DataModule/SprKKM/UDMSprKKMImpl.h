#ifndef UDMSprKKMImplH
#define UDMSprKKMImplH
#include "IDMSprKKM.h"
#include "UDMSprKKM.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprKKMImpl)) TDMSprKKMImpl : public IDMSprKKM
{
public:
   TDMSprKKMImpl();
   ~TDMSprKKMImpl();
   TDMSprKKM * Object;
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

//IDMSprKKM
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBBCDField * get_TableIDKKM(void);
   virtual void set_TableIDKKM(TFIBBCDField * TableIDKKM);

   virtual TFIBBCDField * get_ElementIDKKM(void);
   virtual void set_ElementIDKKM(TFIBBCDField * ElementIDKKM);

   virtual TFIBWideStringField * get_TableNAMEKKM(void);
   virtual void set_TableNAMEKKM(TFIBWideStringField * TableNAMEKKM);

   virtual TFIBWideStringField * get_TableGID_SKKM(void);
   virtual void set_TableGID_SKKM(TFIBWideStringField * TableGID_SKKM);

   virtual TFIBWideStringField * get_TableCATOBMKKM(void);
   virtual void set_TableCATOBMKKM(TFIBWideStringField * TableCATOBMKKM);

   virtual TFIBWideStringField * get_ElementNAMEKKM(void);
   virtual void set_ElementNAMEKKM(TFIBWideStringField * ElementNAMEKKM);

   virtual TFIBWideStringField * get_ElementGID_SKKM(void);
   virtual void set_ElementGID_SKKM(TFIBWideStringField * ElementGID_SKKM);

   virtual TFIBWideStringField * get_ElementCATOBMKKM(void);
   virtual void set_ElementCATOBMKKM(TFIBWideStringField * ElementCATOBMKKM);

   virtual TFIBWideStringField * get_ElementPREFIKS_NUM_SKKM(void);
   virtual void set_ElementPREFIKS_NUM_SKKM(TFIBWideStringField * ElementPREFIKS_NUM_SKKM);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
   virtual AnsiString GetGIDElement(__int64 id);
};
#define CLSID_TDMSprKKMImpl __uuidof(TDMSprKKMImpl)
#endif
