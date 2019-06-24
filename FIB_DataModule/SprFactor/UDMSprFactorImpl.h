#ifndef UDMSprFactorImplH
#define UDMSprFactorImplH
#include "IDMSprFactor.h"
#include "UDMSprFactor.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprFactorImpl)) TDMSprFactorImpl : public IDMSprFactor
{
public:
   TDMSprFactorImpl();
   ~TDMSprFactorImpl();
   TDMSprFactor * Object;
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

//IDMSprFactor
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

   virtual TFIBLargeIntField * get_TableID_SFACTOR(void);
   virtual void set_TableID_SFACTOR(TFIBLargeIntField * TableID_SFACTOR);

   virtual TFIBWideStringField * get_TableGID_SFACTOR(void);
   virtual void set_TableGID_SFACTOR(TFIBWideStringField * TableGID_SFACTOR);

   virtual TFIBLargeIntField * get_TableIDBASE_SFACTOR(void);
   virtual void set_TableIDBASE_SFACTOR(TFIBLargeIntField * TableIDBASE_SFACTOR);

   virtual TFIBWideStringField * get_TableNAME_SFACTOR(void);
   virtual void set_TableNAME_SFACTOR(TFIBWideStringField * TableNAME_SFACTOR);

   virtual TFIBIntegerField * get_TableINDEX_SFACTOR(void);
   virtual void set_TableINDEX_SFACTOR(TFIBIntegerField * TableINDEX_SFACTOR);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_ElementID_SFACTOR(void);
   virtual void set_ElementID_SFACTOR(TFIBLargeIntField * ElementID_SFACTOR);

   virtual TFIBWideStringField * get_ElementGID_SFACTOR(void);
   virtual void set_ElementGID_SFACTOR(TFIBWideStringField * ElementGID_SFACTOR);

   virtual TFIBLargeIntField * get_ElementIDBASE_SFACTOR(void);
   virtual void set_ElementIDBASE_SFACTOR(TFIBLargeIntField * ElementIDBASE_SFACTOR);

   virtual TFIBWideStringField * get_ElementNAME_SFACTOR(void);
   virtual void set_ElementNAME_SFACTOR(TFIBWideStringField * ElementNAME_SFACTOR);

   virtual TFIBIntegerField * get_ElementINDEX_SFACTOR(void);
   virtual void set_ElementINDEX_SFACTOR(TFIBIntegerField * ElementINDEX_SFACTOR);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual bool SaveIsmen();
   virtual bool CancelIsmen();
   virtual __int64 GetIDElement(UnicodeString gid);
   virtual UnicodeString GetGIDElement(__int64 id);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_TDMSprFactorImpl __uuidof(TDMSprFactorImpl)
#endif
