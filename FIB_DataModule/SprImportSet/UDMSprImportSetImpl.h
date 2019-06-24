#ifndef UDMSprImportSetImplH
#define UDMSprImportSetImplH
#include "IDMSprImportSet.h"
#include "UDMSprImportSet.h"
//---------------------------------------------------------------
class __declspec(uuid("{D1829FBD-4301-4BE2-9B3D-60942EE5FC3E}")) TDMSprImportSetImpl : public IDMSprImportSet
{
public:
   TDMSprImportSetImpl();
   ~TDMSprImportSetImpl();
   TDMSprImportSet * Object;
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

//IDMSprImportSet
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

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_TableID_SIMPORTSET(void);
   virtual void set_TableID_SIMPORTSET(TFIBBCDField * TableID_SIMPORTSET);

   virtual TFIBBCDField * get_TableIDBASE_SIMPORTSET(void);
   virtual void set_TableIDBASE_SIMPORTSET(TFIBBCDField * TableIDBASE_SIMPORTSET);

   virtual TFIBSmallIntField * get_TableTYPE_SEARCH_SIMPORTSET(void);
   virtual void set_TableTYPE_SEARCH_SIMPORTSET(TFIBSmallIntField * TableTYPE_SEARCH_SIMPORTSET);

   virtual TFIBSmallIntField * get_TableTYPE_OBR_SIMPORTSET(void);
   virtual void set_TableTYPE_OBR_SIMPORTSET(TFIBSmallIntField * TableTYPE_OBR_SIMPORTSET);

   virtual TFIBBCDField * get_ElementID_SIMPORTSET(void);
   virtual void set_ElementID_SIMPORTSET(TFIBBCDField * ElementID_SIMPORTSET);

   virtual TFIBBCDField * get_ElementIDBASE_SIMPORTSET(void);
   virtual void set_ElementIDBASE_SIMPORTSET(TFIBBCDField * ElementIDBASE_SIMPORTSET);

   virtual TFIBSmallIntField * get_ElementTYPE_SEARCH_SIMPORTSET(void);
   virtual void set_ElementTYPE_SEARCH_SIMPORTSET(TFIBSmallIntField * ElementTYPE_SEARCH_SIMPORTSET);

   virtual TFIBSmallIntField * get_ElementTYPE_OBR_SIMPORTSET(void);
   virtual void set_ElementTYPE_OBR_SIMPORTSET(TFIBSmallIntField * ElementTYPE_OBR_SIMPORTSET);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBWideStringField * get_TableNAME_SIMPORTSET(void);
   virtual void set_TableNAME_SIMPORTSET(TFIBWideStringField * TableNAME_SIMPORTSET);

   virtual TFIBWideStringField * get_TableSTRPAR_SIMPORTSET(void);
   virtual void set_TableSTRPAR_SIMPORTSET(TFIBWideStringField * TableSTRPAR_SIMPORTSET);

   virtual TFIBWideStringField * get_TableDIR_SIMPORTSET(void);
   virtual void set_TableDIR_SIMPORTSET(TFIBWideStringField * TableDIR_SIMPORTSET);

   virtual TFIBWideStringField * get_ElementNAME_SIMPORTSET(void);
   virtual void set_ElementNAME_SIMPORTSET(TFIBWideStringField * ElementNAME_SIMPORTSET);

   virtual TFIBWideStringField * get_ElementSTRPAR_SIMPORTSET(void);
   virtual void set_ElementSTRPAR_SIMPORTSET(TFIBWideStringField * ElementSTRPAR_SIMPORTSET);

   virtual TFIBWideStringField * get_ElementDIR_SIMPORTSET(void);
   virtual void set_ElementDIR_SIMPORTSET(TFIBWideStringField * ElementDIR_SIMPORTSET);

   virtual int get_TypeObr(void);
   virtual void set_TypeObr(int TypeObr);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 GetIDElement(String gid);
   virtual AnsiString GetGIDElement(__int64 id);
   virtual int GetIndexElementaPoID(__int64 id);
   virtual AnsiString GetParameter(AnsiString parameter);
};
#define CLSID_TDMSprImportSetImpl __uuidof(TDMSprImportSetImpl)
#endif
