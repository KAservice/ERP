#ifndef UDMSprDocKlientImplH
#define UDMSprDocKlientImplH
#include "IDMSprDocKlient.h"
#include "UDMSprDocKlient.h"
//---------------------------------------------------------------
class __declspec(uuid("{0446D62C-C834-4C74-B248-D3B3CBC6FFBC}")) TDMSprDocKlientImpl : public IDMSprDocKlient
{
public:
   TDMSprDocKlientImpl();
   ~TDMSprDocKlientImpl();
   TDMSprDocKlient * Object;
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

//IDMSprDocKlient
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

   virtual TFIBDateField * get_TableDATEVID_SDOCKLIENT(void);
   virtual void set_TableDATEVID_SDOCKLIENT(TFIBDateField * TableDATEVID_SDOCKLIENT);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBDateField * get_ElementDATEVID_SDOCKLIENT(void);
   virtual void set_ElementDATEVID_SDOCKLIENT(TFIBDateField * ElementDATEVID_SDOCKLIENT);

   virtual TFIBBCDField * get_TableID_SDOCKLIENT(void);
   virtual void set_TableID_SDOCKLIENT(TFIBBCDField * TableID_SDOCKLIENT);

   virtual TFIBBCDField * get_TableIDKLIENT_SDOCKLIENT(void);
   virtual void set_TableIDKLIENT_SDOCKLIENT(TFIBBCDField * TableIDKLIENT_SDOCKLIENT);

   virtual TFIBBCDField * get_ElementID_SDOCKLIENT(void);
   virtual void set_ElementID_SDOCKLIENT(TFIBBCDField * ElementID_SDOCKLIENT);

   virtual TFIBBCDField * get_ElementIDKLIENT_SDOCKLIENT(void);
   virtual void set_ElementIDKLIENT_SDOCKLIENT(TFIBBCDField * ElementIDKLIENT_SDOCKLIENT);

   virtual TFIBWideStringField * get_TableNAME_SDOCKLIENT(void);
   virtual void set_TableNAME_SDOCKLIENT(TFIBWideStringField * TableNAME_SDOCKLIENT);

   virtual TFIBWideStringField * get_TableSER_SDOCKLIENT(void);
   virtual void set_TableSER_SDOCKLIENT(TFIBWideStringField * TableSER_SDOCKLIENT);

   virtual TFIBWideStringField * get_TableNUM_SDOCKLIENT(void);
   virtual void set_TableNUM_SDOCKLIENT(TFIBWideStringField * TableNUM_SDOCKLIENT);

   virtual TFIBWideStringField * get_TableVID_SDOCKLIENT(void);
   virtual void set_TableVID_SDOCKLIENT(TFIBWideStringField * TableVID_SDOCKLIENT);

   virtual TFIBWideStringField * get_TableGID_SDOCKLIENT(void);
   virtual void set_TableGID_SDOCKLIENT(TFIBWideStringField * TableGID_SDOCKLIENT);

   virtual TFIBBCDField * get_TableIDBASE_SDOCKLIENT(void);
   virtual void set_TableIDBASE_SDOCKLIENT(TFIBBCDField * TableIDBASE_SDOCKLIENT);

   virtual TFIBWideStringField * get_ElementNAME_SDOCKLIENT(void);
   virtual void set_ElementNAME_SDOCKLIENT(TFIBWideStringField * ElementNAME_SDOCKLIENT);

   virtual TFIBWideStringField * get_ElementSER_SDOCKLIENT(void);
   virtual void set_ElementSER_SDOCKLIENT(TFIBWideStringField * ElementSER_SDOCKLIENT);

   virtual TFIBWideStringField * get_ElementNUM_SDOCKLIENT(void);
   virtual void set_ElementNUM_SDOCKLIENT(TFIBWideStringField * ElementNUM_SDOCKLIENT);

   virtual TFIBWideStringField * get_ElementVID_SDOCKLIENT(void);
   virtual void set_ElementVID_SDOCKLIENT(TFIBWideStringField * ElementVID_SDOCKLIENT);

   virtual TFIBWideStringField * get_ElementGID_SDOCKLIENT(void);
   virtual void set_ElementGID_SDOCKLIENT(TFIBWideStringField * ElementGID_SDOCKLIENT);

   virtual TFIBBCDField * get_ElementIDBASE_SDOCKLIENT(void);
   virtual void set_ElementIDBASE_SDOCKLIENT(TFIBBCDField * ElementIDBASE_SDOCKLIENT);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual void OpenTable(__int64 IdKl);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(__int64 IdKl);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
};
#define CLSID_TDMSprDocKlientImpl __uuidof(TDMSprDocKlientImpl)
#endif
