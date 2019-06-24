#ifndef UDMSprBusinessOperImplH
#define UDMSprBusinessOperImplH
#include "IDMSprBusinessOper.h"
#include "UDMSprBusinessOper.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprBusinessOperImpl)) TDMSprBusinessOperImpl : public IDMSprBusinessOper
{
public:
   TDMSprBusinessOperImpl();
   ~TDMSprBusinessOperImpl();
   TDMSprBusinessOper * Object;
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

//IDMSprBusinessOper
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBLargeIntField * get_TableID_SBUSINESS_OPER(void);
   virtual void set_TableID_SBUSINESS_OPER(TFIBLargeIntField * TableID_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_TableGID_SBUSINESS_OPER(void);
   virtual void set_TableGID_SBUSINESS_OPER(TFIBWideStringField * TableGID_SBUSINESS_OPER);

   virtual TFIBLargeIntField * get_TableIDBASE_SBUSINESS_OPER(void);
   virtual void set_TableIDBASE_SBUSINESS_OPER(TFIBLargeIntField * TableIDBASE_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_TableNAME_SBUSINESS_OPER(void);
   virtual void set_TableNAME_SBUSINESS_OPER(TFIBWideStringField * TableNAME_SBUSINESS_OPER);

   virtual TFIBLargeIntField * get_TableIDGRP_SBUSINESS_OPER(void);
   virtual void set_TableIDGRP_SBUSINESS_OPER(TFIBLargeIntField * TableIDGRP_SBUSINESS_OPER);

   virtual TFIBLargeIntField * get_ElementID_SBUSINESS_OPER(void);
   virtual void set_ElementID_SBUSINESS_OPER(TFIBLargeIntField * ElementID_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_ElementGID_SBUSINESS_OPER(void);
   virtual void set_ElementGID_SBUSINESS_OPER(TFIBWideStringField * ElementGID_SBUSINESS_OPER);

   virtual TFIBLargeIntField * get_ElementIDBASE_SBUSINESS_OPER(void);
   virtual void set_ElementIDBASE_SBUSINESS_OPER(TFIBLargeIntField * ElementIDBASE_SBUSINESS_OPER);

   virtual TFIBWideStringField * get_ElementNAME_SBUSINESS_OPER(void);
   virtual void set_ElementNAME_SBUSINESS_OPER(TFIBWideStringField * ElementNAME_SBUSINESS_OPER);

   virtual TFIBLargeIntField * get_ElementIDGRP_SBUSINESS_OPER(void);
   virtual void set_ElementIDGRP_SBUSINESS_OPER(TFIBLargeIntField * ElementIDGRP_SBUSINESS_OPER);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_grp, bool all);
   virtual int OpenElement(__int64 id );
   virtual bool NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void ChancheGrp(__int64 new_id_grp);
   virtual __int64 GetIdPoName(UnicodeString name);
   virtual __int64 GetIdGrpBusinessOper(__int64 id_bo);
};
#define CLSID_TDMSprBusinessOperImpl __uuidof(TDMSprBusinessOperImpl)
#endif
