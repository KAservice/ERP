#ifndef UDMSprCodeTelImplH
#define UDMSprCodeTelImplH
#include "IDMSprCodeTel.h"
#include "UDMSprCodeTel.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprCodeTelImpl)) TDMSprCodeTelImpl : public IDMSprCodeTel
{
public:
   TDMSprCodeTelImpl();
   ~TDMSprCodeTelImpl();
   TDMSprCodeTel * Object;
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

//IDMSprCodeTel
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

   virtual TFIBLargeIntField * get_ElementID_CODETEL(void);
   virtual void set_ElementID_CODETEL(TFIBLargeIntField * ElementID_CODETEL);

   virtual TFIBLargeIntField * get_ElementIDNOM_CODETEL(void);
   virtual void set_ElementIDNOM_CODETEL(TFIBLargeIntField * ElementIDNOM_CODETEL);

   virtual TFIBWideStringField * get_ElementCODE_CODETEL(void);
   virtual void set_ElementCODE_CODETEL(TFIBWideStringField * ElementCODE_CODETEL);

   virtual TFIBWideStringField * get_ElementGID_SCODETEL(void);
   virtual void set_ElementGID_SCODETEL(TFIBWideStringField * ElementGID_SCODETEL);

   virtual TFIBWideStringField * get_ElementNAME_CODETEL(void);
   virtual void set_ElementNAME_CODETEL(TFIBWideStringField * ElementNAME_CODETEL);

   virtual TFIBWideStringField * get_ElementCODOPER_CODETEL(void);
   virtual void set_ElementCODOPER_CODETEL(TFIBWideStringField * ElementCODOPER_CODETEL);

   virtual TFIBLargeIntField * get_ElementIDNOMCOM_CODETEL(void);
   virtual void set_ElementIDNOMCOM_CODETEL(TFIBLargeIntField * ElementIDNOMCOM_CODETEL);

   virtual TFIBLargeIntField * get_ElementIDBASE_SCODETEL(void);
   virtual void set_ElementIDBASE_SCODETEL(TFIBLargeIntField * ElementIDBASE_SCODETEL);

   virtual TFIBBCDField * get_ElementPRCOMIS_SCODETEL(void);
   virtual void set_ElementPRCOMIS_SCODETEL(TFIBBCDField * ElementPRCOMIS_SCODETEL);

   virtual TFIBWideStringField * get_ElementNAMENOM(void);
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM);

   virtual TFIBWideStringField * get_ElementNAMENOMCOM(void);
   virtual void set_ElementNAMENOMCOM(TFIBWideStringField * ElementNAMENOMCOM);

   virtual TFIBLargeIntField * get_TableID_CODETEL(void);
   virtual void set_TableID_CODETEL(TFIBLargeIntField * TableID_CODETEL);

   virtual TFIBLargeIntField * get_TableIDNOM_CODETEL(void);
   virtual void set_TableIDNOM_CODETEL(TFIBLargeIntField * TableIDNOM_CODETEL);

   virtual TFIBWideStringField * get_TableCODE_CODETEL(void);
   virtual void set_TableCODE_CODETEL(TFIBWideStringField * TableCODE_CODETEL);

   virtual TFIBWideStringField * get_TableGID_SCODETEL(void);
   virtual void set_TableGID_SCODETEL(TFIBWideStringField * TableGID_SCODETEL);

   virtual TFIBWideStringField * get_TableNAME_CODETEL(void);
   virtual void set_TableNAME_CODETEL(TFIBWideStringField * TableNAME_CODETEL);

   virtual TFIBWideStringField * get_TableCODOPER_CODETEL(void);
   virtual void set_TableCODOPER_CODETEL(TFIBWideStringField * TableCODOPER_CODETEL);

   virtual TFIBLargeIntField * get_TableIDNOMCOM_CODETEL(void);
   virtual void set_TableIDNOMCOM_CODETEL(TFIBLargeIntField * TableIDNOMCOM_CODETEL);

   virtual TFIBLargeIntField * get_TableIDBASE_SCODETEL(void);
   virtual void set_TableIDBASE_SCODETEL(TFIBLargeIntField * TableIDBASE_SCODETEL);

   virtual TFIBBCDField * get_TablePRCOMIS_SCODETEL(void);
   virtual void set_TablePRCOMIS_SCODETEL(TFIBBCDField * TablePRCOMIS_SCODETEL);

   virtual TFIBWideStringField * get_TableNAMENOM(void);
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM);

   virtual TFIBIntegerField * get_TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR(void);
   virtual void set_TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR(TFIBIntegerField * TableNOM_DEPARTMENT_NUMOTDKKT_SDEPAR);

   virtual TFIBLargeIntField * get_TableNOM_DEPARTMENT_ID_SDEPARTMENT(void);
   virtual void set_TableNOM_DEPARTMENT_ID_SDEPARTMENT(TFIBLargeIntField * TableNOM_DEPARTMENT_ID_SDEPARTMENT);

   virtual TFIBWideStringField * get_TableNAMENOMCOM(void);
   virtual void set_TableNAMENOMCOM(TFIBWideStringField * TableNAMENOMCOM);

   virtual TFIBIntegerField * get_TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR(void);
   virtual void set_TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR(TFIBIntegerField * TableCOM_DEPARTMENT_NUMOTDKKT_SDEPAR);

   virtual TFIBLargeIntField * get_TableCOM_DEPARTMENT_ID_SDEPARTMENT(void);
   virtual void set_TableCOM_DEPARTMENT_ID_SDEPARTMENT(TFIBLargeIntField * TableCOM_DEPARTMENT_ID_SDEPARTMENT);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
};
#define CLSID_TDMSprCodeTelImpl __uuidof(TDMSprCodeTelImpl)
#endif
