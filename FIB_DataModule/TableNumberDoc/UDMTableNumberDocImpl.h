#ifndef UDMTableNumberDocImplH
#define UDMTableNumberDocImplH
#include "IDMTableNumberDoc.h"
#include "UDMTableNumberDoc.h"
//---------------------------------------------------------------
class __declspec(uuid("{F5530199-B826-4FE9-BB23-9D6116DCC303}"))TDMTableNumberDocImpl : public IDMTableNumberDoc
{
public:
   TDMTableNumberDocImpl();
   ~TDMTableNumberDocImpl();
   TDMTableNumberDoc * Object;
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

//IDMTableNumberDoc
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

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

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBBCDField * get_TableID_TNUM_DOC(void);
   virtual void set_TableID_TNUM_DOC(TFIBBCDField * TableID_TNUM_DOC);

   virtual TFIBBCDField * get_ElementID_TNUM_DOC(void);
   virtual void set_ElementID_TNUM_DOC(TFIBBCDField * ElementID_TNUM_DOC);

   virtual TFIBWideStringField * get_TableGID_TNUM_DOC(void);
   virtual void set_TableGID_TNUM_DOC(TFIBWideStringField * TableGID_TNUM_DOC);

   virtual TFIBWideStringField * get_TableDOC_TNUM_DOC(void);
   virtual void set_TableDOC_TNUM_DOC(TFIBWideStringField * TableDOC_TNUM_DOC);

   virtual TFIBSmallIntField * get_TableTYPE_TNUM_DOC(void);
   virtual void set_TableTYPE_TNUM_DOC(TFIBSmallIntField * TableTYPE_TNUM_DOC);

   virtual TFIBWideStringField * get_ElementGID_TNUM_DOC(void);
   virtual void set_ElementGID_TNUM_DOC(TFIBWideStringField * ElementGID_TNUM_DOC);

   virtual TFIBWideStringField * get_ElementDOC_TNUM_DOC(void);
   virtual void set_ElementDOC_TNUM_DOC(TFIBWideStringField * ElementDOC_TNUM_DOC);

   virtual TFIBSmallIntField * get_ElementTYPE_TNUM_DOC(void);
   virtual void set_ElementTYPE_TNUM_DOC(TFIBSmallIntField * ElementTYPE_TNUM_DOC);

   virtual void OpenTable(void);
   virtual void SaveIsmen();
   virtual void CancelIsmen();
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(void);
   virtual void SaveElement(void);
   virtual void DeleteElement(__int64 Id);
   virtual TDateTime GetPosNachNumDoc(AnsiString type_doc);
};
#define CLSID_TDMTableNumberDocImpl __uuidof(TDMTableNumberDocImpl)
#endif
