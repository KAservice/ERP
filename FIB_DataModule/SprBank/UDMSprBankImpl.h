#ifndef UDMSprBankImplH
#define UDMSprBankImplH
#include "IDMSprBank.h"
#include "UDMSprBank.h"
//---------------------------------------------------------------
class __declspec(uuid("{2C96BAAD-7682-4E20-BFB5-804CA4AE58C9}")) TDMSprBankImpl : public IDMSprBank
{
public:
   TDMSprBankImpl();
   ~TDMSprBankImpl();
   TDMSprBank * Object;
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

//IDMSprBank
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBBCDField * get_TableIDBANK(void);
   virtual void set_TableIDBANK(TFIBBCDField * TableIDBANK);

   virtual TFIBBCDField * get_ElementIDBANK(void);
   virtual void set_ElementIDBANK(TFIBBCDField * ElementIDBANK);

   virtual TFIBWideStringField * get_TableNAMEBANK(void);
   virtual void set_TableNAMEBANK(TFIBWideStringField * TableNAMEBANK);

   virtual TFIBWideStringField * get_TableGORBANK(void);
   virtual void set_TableGORBANK(TFIBWideStringField * TableGORBANK);

   virtual TFIBWideStringField * get_ElementNAMEBANK(void);
   virtual void set_ElementNAMEBANK(TFIBWideStringField * ElementNAMEBANK);

   virtual TFIBWideStringField * get_ElementBIKBANK(void);
   virtual void set_ElementBIKBANK(TFIBWideStringField * ElementBIKBANK);

   virtual TFIBWideStringField * get_ElementGORBANK(void);
   virtual void set_ElementGORBANK(TFIBWideStringField * ElementGORBANK);

   virtual TFIBWideStringField * get_ElementKSBANK(void);
   virtual void set_ElementKSBANK(TFIBWideStringField * ElementKSBANK);

   virtual TFIBWideStringField * get_ElementGID_SBANK(void);
   virtual void set_ElementGID_SBANK(TFIBWideStringField * ElementGID_SBANK);

   virtual bool get_Error(void);
   virtual void set_Error(bool Error);

   virtual void OpenTable();
   virtual int  OpenElement(__int64 Id);;
   virtual void NewElement();
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
};
#define CLSID_TDMSprBankImpl __uuidof(TDMSprBankImpl)
#endif
