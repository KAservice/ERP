#ifndef UDMSprScaleImplH
#define UDMSprScaleImplH
#include "IDMSprScale.h"
#include "UDMSprScale.h"
//---------------------------------------------------------------
class __declspec(uuid("{9254616B-5242-454A-9DBA-48C1264FBBC4}")) TDMSprScaleImpl : public IDMSprScale
{
public:
   TDMSprScaleImpl();
   ~TDMSprScaleImpl();
   TDMSprScale * Object;
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

//IDMSprScale
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

   virtual TFIBBCDField * get_ElementID_SSCALE(void);
   virtual void set_ElementID_SSCALE(TFIBBCDField * ElementID_SSCALE);

   virtual TFIBBCDField * get_TableID_SSCALE(void);
   virtual void set_TableID_SSCALE(TFIBBCDField * TableID_SSCALE);

   virtual TFIBWideStringField * get_TableGID_SSCALE(void);
   virtual void set_TableGID_SSCALE(TFIBWideStringField * TableGID_SSCALE);

   virtual TFIBWideStringField * get_TableNAME_SSCALE(void);
   virtual void set_TableNAME_SSCALE(TFIBWideStringField * TableNAME_SSCALE);

   virtual TFIBWideStringField * get_ElementGID_SSCALE(void);
   virtual void set_ElementGID_SSCALE(TFIBWideStringField * ElementGID_SSCALE);

   virtual TFIBWideStringField * get_ElementNAME_SSCALE(void);
   virtual void set_ElementNAME_SSCALE(TFIBWideStringField * ElementNAME_SSCALE);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
   virtual __int64 GetIDElement(String gid);
};
#define CLSID_TDMSprScaleImpl __uuidof(TDMSprScaleImpl)
#endif
