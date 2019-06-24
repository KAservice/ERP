#ifndef UDMSprNumTelImplH
#define UDMSprNumTelImplH
#include "IDMSprNumTel.h"
#include "UDMSprNumTel.h"
//---------------------------------------------------------------
class __declspec(uuid("{9909176C-8538-4DF9-8FDF-52F5FE672D59}"))TDMSprNumTelImpl : public IDMSprNumTel
{
public:
   TDMSprNumTelImpl();
   ~TDMSprNumTelImpl();
   TDMSprNumTel * Object;
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

//IDMSprNumTel
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

   virtual TFIBBCDField * get_TableID_NUMTEL(void);
   virtual void set_TableID_NUMTEL(TFIBBCDField * TableID_NUMTEL);

   virtual TFIBBCDField * get_TableIDKLIENT_NUMTEL(void);
   virtual void set_TableIDKLIENT_NUMTEL(TFIBBCDField * TableIDKLIENT_NUMTEL);

   virtual TFIBBCDField * get_ElementID_NUMTEL(void);
   virtual void set_ElementID_NUMTEL(TFIBBCDField * ElementID_NUMTEL);

   virtual TFIBBCDField * get_ElementIDKLIENT_NUMTEL(void);
   virtual void set_ElementIDKLIENT_NUMTEL(TFIBBCDField * ElementIDKLIENT_NUMTEL);

   virtual TFIBWideStringField * get_TableCODE_NUMTEL(void);
   virtual void set_TableCODE_NUMTEL(TFIBWideStringField * TableCODE_NUMTEL);

   virtual TFIBWideStringField * get_TableNUMBER_NUMTEL(void);
   virtual void set_TableNUMBER_NUMTEL(TFIBWideStringField * TableNUMBER_NUMTEL);

   virtual TFIBWideStringField * get_TableGID_SNUMTEL(void);
   virtual void set_TableGID_SNUMTEL(TFIBWideStringField * TableGID_SNUMTEL);

   virtual TFIBWideStringField * get_ElementCODE_NUMTEL(void);
   virtual void set_ElementCODE_NUMTEL(TFIBWideStringField * ElementCODE_NUMTEL);

   virtual TFIBWideStringField * get_ElementNUMBER_NUMTEL(void);
   virtual void set_ElementNUMBER_NUMTEL(TFIBWideStringField * ElementNUMBER_NUMTEL);

   virtual TFIBWideStringField * get_ElementGID_SNUMTEL(void);
   virtual void set_ElementGID_SNUMTEL(TFIBWideStringField * ElementGID_SNUMTEL);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual void OpenTable(__int64 IdKl);
   virtual int OpenElement(__int64 Id);  //возвращает количество элементо;
   virtual void NewElement(__int64 IdKl);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
};
#define CLSID_TDMSprNumTelImpl __uuidof(TDMSprNumTelImpl)
#endif
