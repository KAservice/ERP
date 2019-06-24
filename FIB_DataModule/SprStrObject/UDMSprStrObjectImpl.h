#ifndef UDMSprStrObjectImplH
#define UDMSprStrObjectImplH
#include "IDMSprStrObject.h"
#include "UDMSprStrObject.h"
//---------------------------------------------------------------
class __declspec(uuid("{8769B59B-4A4A-43B1-B053-5F5927439DCE}"))TDMSprStrObjectImpl : public IDMSprStrObject
{
public:
   TDMSprStrObjectImpl();
   ~TDMSprStrObjectImpl();
   TDMSprStrObject * Object;
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

//IDMSprStrObject
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

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBDataSet * get_Code(void);
   virtual void set_Code(TpFIBDataSet * Code);

   virtual TFIBIntegerField * get_CodeMAXCODE(void);
   virtual void set_CodeMAXCODE(TFIBIntegerField * CodeMAXCODE);

   virtual TFIBBCDField * get_TableID_STROB(void);
   virtual void set_TableID_STROB(TFIBBCDField * TableID_STROB);

   virtual TFIBBCDField * get_TableIDGRP_STROB(void);
   virtual void set_TableIDGRP_STROB(TFIBBCDField * TableIDGRP_STROB);

   virtual TFIBSmallIntField * get_TableGRP_STROB(void);
   virtual void set_TableGRP_STROB(TFIBSmallIntField * TableGRP_STROB);

   virtual TFIBBCDField * get_ElementID_STROB(void);
   virtual void set_ElementID_STROB(TFIBBCDField * ElementID_STROB);

   virtual TFIBBCDField * get_ElementIDGRP_STROB(void);
   virtual void set_ElementIDGRP_STROB(TFIBBCDField * ElementIDGRP_STROB);

   virtual TFIBSmallIntField * get_ElementGRP_STROB(void);
   virtual void set_ElementGRP_STROB(TFIBSmallIntField * ElementGRP_STROB);

   virtual TFIBWideStringField * get_TableNAME_STROB(void);
   virtual void set_TableNAME_STROB(TFIBWideStringField * TableNAME_STROB);

   virtual TFIBIntegerField * get_TableCODE_STROB(void);
   virtual void set_TableCODE_STROB(TFIBIntegerField * TableCODE_STROB);

   virtual TFIBWideStringField * get_TableGID_SSTROB(void);
   virtual void set_TableGID_SSTROB(TFIBWideStringField * TableGID_SSTROB);

   virtual TFIBWideStringField * get_ElementNAME_STROB(void);
   virtual void set_ElementNAME_STROB(TFIBWideStringField * ElementNAME_STROB);

   virtual TFIBIntegerField * get_ElementCODE_STROB(void);
   virtual void set_ElementCODE_STROB(TFIBIntegerField * ElementCODE_STROB);

   virtual TFIBWideStringField * get_ElementGID_SSTROB(void);
   virtual void set_ElementGID_SSTROB(TFIBWideStringField * ElementGID_SSTROB);

   virtual __int64 get_Id(void);
   virtual void set_Id(__int64 Id);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(__int64 IdGrp);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
   virtual __int64 FindPoCodu(int code);
};
#define CLSID_TDMSprStrObjectImpl __uuidof(TDMSprStrObjectImpl)
#endif
