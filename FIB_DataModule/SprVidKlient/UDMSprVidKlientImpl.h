#ifndef UDMSprVidKlientImplH
#define UDMSprVidKlientImplH
#include "IDMSprVidKlient.h"
#include "UDMSprVidKlient.h"
//---------------------------------------------------------------
class __declspec(uuid("{CF620497-A449-4A37-AB96-E318063B09A6}")) TDMSprVidKlientImpl : public IDMSprVidKlient
{
public:
   TDMSprVidKlientImpl();
   ~TDMSprVidKlientImpl();
   TDMSprVidKlient * Object;
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

//IDMSprVidKlient
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

   virtual TFIBBCDField * get_TableID_SVIDKLIENT(void);
   virtual void set_TableID_SVIDKLIENT(TFIBBCDField * TableID_SVIDKLIENT);

   virtual TFIBBCDField * get_ElementID_SVIDKLIENT(void);
   virtual void set_ElementID_SVIDKLIENT(TFIBBCDField * ElementID_SVIDKLIENT);

   virtual TFIBWideStringField * get_TableGID_SVIDKLIENT(void);
   virtual void set_TableGID_SVIDKLIENT(TFIBWideStringField * TableGID_SVIDKLIENT);

   virtual TFIBWideStringField * get_TableNAME_SVIDKLIENT(void);
   virtual void set_TableNAME_SVIDKLIENT(TFIBWideStringField * TableNAME_SVIDKLIENT);

   virtual TFIBWideStringField * get_ElementGID_SVIDKLIENT(void);
   virtual void set_ElementGID_SVIDKLIENT(TFIBWideStringField * ElementGID_SVIDKLIENT);

   virtual TFIBWideStringField * get_ElementNAME_SVIDKLIENT(void);
   virtual void set_ElementNAME_SVIDKLIENT(TFIBWideStringField * ElementNAME_SVIDKLIENT);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual bool SaveIsmen(void);
   virtual bool CancelIsmen(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_TDMSprVidKlientImpl __uuidof(TDMSprVidKlientImpl)
#endif
