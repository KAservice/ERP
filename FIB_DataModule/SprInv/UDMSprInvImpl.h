#ifndef UDMSprInvImplH
#define UDMSprInvImplH
#include "IDMSprInv.h"
#include "UDMSprInv.h"
//---------------------------------------------------------------
class __declspec(uuid("{3062CFD7-A8F6-4E51-A2BE-397A1C5D1480}")) TDMSprInvImpl : public IDMSprInv
{
public:
   TDMSprInvImpl();
   ~TDMSprInvImpl();
   TDMSprInv * Object;
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

//IDMSprInv
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

   virtual TFIBDateField * get_TableDATE_SINV(void);
   virtual void set_TableDATE_SINV(TFIBDateField * TableDATE_SINV);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBDateField * get_ElementDATE_SINV(void);
   virtual void set_ElementDATE_SINV(TFIBDateField * ElementDATE_SINV);

   virtual TFIBBCDField * get_TableID_SINV(void);
   virtual void set_TableID_SINV(TFIBBCDField * TableID_SINV);

   virtual TFIBBCDField * get_ElementID_SINV(void);
   virtual void set_ElementID_SINV(TFIBBCDField * ElementID_SINV);

   virtual TFIBWideStringField * get_TableGID_SINV(void);
   virtual void set_TableGID_SINV(TFIBWideStringField * TableGID_SINV);

   virtual TFIBWideStringField * get_TableNAME_SINV(void);
   virtual void set_TableNAME_SINV(TFIBWideStringField * TableNAME_SINV);

   virtual TFIBWideStringField * get_ElementGID_SINV(void);
   virtual void set_ElementGID_SINV(TFIBWideStringField * ElementGID_SINV);

   virtual TFIBWideStringField * get_ElementNAME_SINV(void);
   virtual void set_ElementNAME_SINV(TFIBWideStringField * ElementNAME_SINV);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual void DeleteElement(__int64 Id);
   virtual __int64 GetIDElement(String gid);
   virtual AnsiString GetGIDElement(__int64 id);
};
#define CLSID_TDMSprInvImpl __uuidof(TDMSprInvImpl)
#endif
