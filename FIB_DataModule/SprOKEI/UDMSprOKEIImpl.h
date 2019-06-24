#ifndef UDMSprOKEIImplH
#define UDMSprOKEIImplH
#include "IDMSprOKEI.h"
#include "UDMSprOKEI.h"
//---------------------------------------------------------------
class __declspec(uuid("{A304D69B-17C9-4BFA-9846-9E67E9283D90}")) TDMSprOKEIImpl : public IDMSprOKEI
{
public:
   TDMSprOKEIImpl();
   ~TDMSprOKEIImpl();
   TDMSprOKEI * Object;
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

//IDMSprOKEI
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

   virtual TFIBBCDField * get_TableIDOKEI(void);
   virtual void set_TableIDOKEI(TFIBBCDField * TableIDOKEI);

   virtual TFIBBCDField * get_ElementIDOKEI(void);
   virtual void set_ElementIDOKEI(TFIBBCDField * ElementIDOKEI);

   virtual TFIBWideStringField * get_TableNAMEOKEI(void);
   virtual void set_TableNAMEOKEI(TFIBWideStringField * TableNAMEOKEI);

   virtual TFIBIntegerField * get_TableCODEOKEI(void);
   virtual void set_TableCODEOKEI(TFIBIntegerField * TableCODEOKEI);

   virtual TFIBWideStringField * get_TableGID_SOKEI(void);
   virtual void set_TableGID_SOKEI(TFIBWideStringField * TableGID_SOKEI);

   virtual TFIBBCDField * get_TableIDBASE_SOKEI(void);
   virtual void set_TableIDBASE_SOKEI(TFIBBCDField * TableIDBASE_SOKEI);

   virtual TFIBWideStringField * get_ElementNAMEOKEI(void);
   virtual void set_ElementNAMEOKEI(TFIBWideStringField * ElementNAMEOKEI);

   virtual TFIBIntegerField * get_ElementCODEOKEI(void);
   virtual void set_ElementCODEOKEI(TFIBIntegerField * ElementCODEOKEI);

   virtual TFIBWideStringField * get_ElementGID_SOKEI(void);
   virtual void set_ElementGID_SOKEI(TFIBWideStringField * ElementGID_SOKEI);

   virtual void OpenTable();
   virtual int  OpenElement(__int64 Id);;
   virtual void NewElement();
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
};
#define CLSID_TDMSprOKEIImpl __uuidof(TDMSprOKEIImpl)
#endif
