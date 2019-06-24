#ifndef UDMSprTypeAnalogImplH
#define UDMSprTypeAnalogImplH
#include "IDMSprTypeAnalog.h"
#include "UDMSprTypeAnalog.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprTypeAnalogImpl)) TDMSprTypeAnalogImpl : public IDMSprTypeAnalog
{
public:
   TDMSprTypeAnalogImpl();
   ~TDMSprTypeAnalogImpl();
   TDMSprTypeAnalog * Object;
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

//IDMSprTypeAnalog
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourcePodr(void);
   virtual void set_DataSourcePodr(TDataSource * DataSourcePodr);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TFIBLargeIntField * get_TableID_STYPE_ANALOG(void);
   virtual void set_TableID_STYPE_ANALOG(TFIBLargeIntField * TableID_STYPE_ANALOG);

   virtual TFIBLargeIntField * get_TableIDBASE_STYPE_ANALOG(void);
   virtual void set_TableIDBASE_STYPE_ANALOG(TFIBLargeIntField * TableIDBASE_STYPE_ANALOG);

   virtual TFIBWideStringField * get_TableGID_STYPE_ANALOG(void);
   virtual void set_TableGID_STYPE_ANALOG(TFIBWideStringField * TableGID_STYPE_ANALOG);

   virtual TFIBWideStringField * get_TableNAME_STYPE_ANALOG(void);
   virtual void set_TableNAME_STYPE_ANALOG(TFIBWideStringField * TableNAME_STYPE_ANALOG);

   virtual TFIBLargeIntField * get_ElementID_STYPE_ANALOG(void);
   virtual void set_ElementID_STYPE_ANALOG(TFIBLargeIntField * ElementID_STYPE_ANALOG);

   virtual TFIBLargeIntField * get_ElementIDBASE_STYPE_ANALOG(void);
   virtual void set_ElementIDBASE_STYPE_ANALOG(TFIBLargeIntField * ElementIDBASE_STYPE_ANALOG);

   virtual TFIBWideStringField * get_ElementGID_STYPE_ANALOG(void);
   virtual void set_ElementGID_STYPE_ANALOG(TFIBWideStringField * ElementGID_STYPE_ANALOG);

   virtual TFIBWideStringField * get_ElementNAME_STYPE_ANALOG(void);
   virtual void set_ElementNAME_STYPE_ANALOG(TFIBWideStringField * ElementNAME_STYPE_ANALOG);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual bool NewElement(void);
   virtual bool InsertElement(UnicodeString name);
   virtual bool OpenElement(__int64 id);
   virtual bool DeleteElement(__int64 id);
   virtual bool SaveElement(void);
   virtual bool OpenTable(void);
   virtual bool TableSaveIsmen(void);
   virtual bool TableCancelIsmen(void);
   virtual bool TableNewElement(void);
   virtual bool TableAppend(void);
   virtual bool TableDelete(void);
   virtual bool TableEdit(void);
   virtual bool TablePost(void);
};
#define CLSID_TDMSprTypeAnalogImpl __uuidof(TDMSprTypeAnalogImpl)
#endif
