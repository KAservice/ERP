#ifndef UDMSprTypeNachislImplH
#define UDMSprTypeNachislImplH
#include "IDMSprTypeNachisl.h"
#include "UDMSprTypeNachisl.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprTypeNachislImpl)) TDMSprTypeNachislImpl : public IDMSprTypeNachisl
{
public:
   TDMSprTypeNachislImpl();
   ~TDMSprTypeNachislImpl();
   TDMSprTypeNachisl * Object;
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

//IDMSprTypeNachisl
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

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_TableID_STNACHISL(void);
   virtual void set_TableID_STNACHISL(TFIBBCDField * TableID_STNACHISL);

   virtual TFIBBCDField * get_TableIDBASE_STNACHISL(void);
   virtual void set_TableIDBASE_STNACHISL(TFIBBCDField * TableIDBASE_STNACHISL);

   virtual TFIBWideStringField * get_TableNAME_STNACHISL(void);
   virtual void set_TableNAME_STNACHISL(TFIBWideStringField * TableNAME_STNACHISL);

   virtual TFIBWideStringField * get_TableGID_STNACHISL(void);
   virtual void set_TableGID_STNACHISL(TFIBWideStringField * TableGID_STNACHISL);

   virtual TFIBBCDField * get_ElementID_STNACHISL(void);
   virtual void set_ElementID_STNACHISL(TFIBBCDField * ElementID_STNACHISL);

   virtual TFIBBCDField * get_ElementIDBASE_STNACHISL(void);
   virtual void set_ElementIDBASE_STNACHISL(TFIBBCDField * ElementIDBASE_STNACHISL);

   virtual TFIBWideStringField * get_ElementNAME_STNACHISL(void);
   virtual void set_ElementNAME_STNACHISL(TFIBWideStringField * ElementNAME_STNACHISL);

   virtual TFIBWideStringField * get_ElementGID_STNACHISL(void);
   virtual void set_ElementGID_STNACHISL(TFIBWideStringField * ElementGID_STNACHISL);

   virtual void OpenTable();
   virtual int  OpenElement(__int64 Id);
   virtual void NewElement();
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual void DeleteElement(__int64 Id);
   virtual __int64 GetIDTypePrice(String   name);
   virtual int GetIndexTypePricePoId(__int64 id_type_price);
   virtual __int64 GetIDElement(String gid);
   virtual AnsiString GetGIDElement(__int64 id);
};
#define CLSID_TDMSprTypeNachislImpl __uuidof(TDMSprTypeNachislImpl)
#endif
