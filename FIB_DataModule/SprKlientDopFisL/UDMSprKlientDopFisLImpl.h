#ifndef UDMSprKlientDopFisLImplH
#define UDMSprKlientDopFisLImplH
#include "IDMSprKlientDopFisL.h"
#include "UDMSprKlientDopFisL.h"
//---------------------------------------------------------------
class __declspec(uuid("{DBA981FD-158D-4B4F-A131-E44299ECC511}")) TDMSprKlientDopFisLImpl : public IDMSprKlientDopFisL
{
public:
   TDMSprKlientDopFisLImpl();
   ~TDMSprKlientDopFisLImpl();
   TDMSprKlientDopFisL * Object;
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

//IDMSprKlientDopFisL
   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBIntegerField * get_ElementPOL_SKLIENT_DOPFISL(void);
   virtual void set_ElementPOL_SKLIENT_DOPFISL(TFIBIntegerField * ElementPOL_SKLIENT_DOPFISL);

   virtual TFIBBCDField * get_ElementID_SKLIENT_DOPFISL(void);
   virtual void set_ElementID_SKLIENT_DOPFISL(TFIBBCDField * ElementID_SKLIENT_DOPFISL);

   virtual TFIBBCDField * get_ElementIDKLIENT_SKLIENT_DOPFISL(void);
   virtual void set_ElementIDKLIENT_SKLIENT_DOPFISL(TFIBBCDField * ElementIDKLIENT_SKLIENT_DOPFISL);

   virtual TFIBDateField * get_ElementDATEROG_SKLIENT_DOPFISL(void);
   virtual void set_ElementDATEROG_SKLIENT_DOPFISL(TFIBDateField * ElementDATEROG_SKLIENT_DOPFISL);

   virtual TFIBWideStringField * get_ElementMESTOROG_SKLIENT_DOPFISL(void);
   virtual void set_ElementMESTOROG_SKLIENT_DOPFISL(TFIBWideStringField * ElementMESTOROG_SKLIENT_DOPFISL);

   virtual TFIBWideStringField * get_ElementDOLRAB_SKLIENT_DOPFISL(void);
   virtual void set_ElementDOLRAB_SKLIENT_DOPFISL(TFIBWideStringField * ElementDOLRAB_SKLIENT_DOPFISL);

   virtual TFIBWideStringField * get_ElementMESTORAB_SKLIENT_DOPFISL(void);
   virtual void set_ElementMESTORAB_SKLIENT_DOPFISL(TFIBWideStringField * ElementMESTORAB_SKLIENT_DOPFISL);

   virtual TFIBBCDField * get_ElementIDBASE_SKLIENT_DOPFISL(void);
   virtual void set_ElementIDBASE_SKLIENT_DOPFISL(TFIBBCDField * ElementIDBASE_SKLIENT_DOPFISL);

   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void);
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT);

   virtual TFIBWideStringField * get_ElementGID_SKLIENT_DOPFISL(void);
   virtual void set_ElementGID_SKLIENT_DOPFISL(TFIBWideStringField * ElementGID_SKLIENT_DOPFISL);

   virtual __int64 get_Id(void);
   virtual void set_Id(__int64 Id);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual int OpenElement(void);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(void);
};
#define CLSID_TDMSprKlientDopFisLImpl __uuidof(TDMSprKlientDopFisLImpl)
#endif
