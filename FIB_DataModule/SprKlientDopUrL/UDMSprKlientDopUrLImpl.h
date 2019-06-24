#ifndef UDMSprKlientDopUrLImplH
#define UDMSprKlientDopUrLImplH
#include "IDMSprKlientDopUrL.h"
#include "UDMSprKlientDopUrL.h"
//---------------------------------------------------------------
class __declspec(uuid("{87E37D1D-4148-40C7-B05A-AB9BF1DD328A}")) TDMSprKlientDopUrLImpl : public IDMSprKlientDopUrL
{
public:
   TDMSprKlientDopUrLImpl();
   ~TDMSprKlientDopUrLImpl();
   TDMSprKlientDopUrL * Object;
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

//IDMSprKlientDopUrL
   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBBCDField * get_ElementID_SKLIENT_DOPURL(void);
   virtual void set_ElementID_SKLIENT_DOPURL(TFIBBCDField * ElementID_SKLIENT_DOPURL);

   virtual TFIBBCDField * get_ElementIDKLIENT_SKLIENT_DOPURL(void);
   virtual void set_ElementIDKLIENT_SKLIENT_DOPURL(TFIBBCDField * ElementIDKLIENT_SKLIENT_DOPURL);

   virtual TFIBWideStringField * get_ElementGID_SKLIENT_DOPURL(void);
   virtual void set_ElementGID_SKLIENT_DOPURL(TFIBWideStringField * ElementGID_SKLIENT_DOPURL);

   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void);
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT);

   virtual __int64 get_Id(void);
   virtual void set_Id(__int64 Id);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual int OpenElement(void);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(void);
};
#define CLSID_TDMSprKlientDopUrLImpl __uuidof(TDMSprKlientDopUrLImpl)
#endif
