#ifndef UDMSprCountryImplH
#define UDMSprCountryImplH
#include "IDMSprCountry.h"
#include "UDMSprCountry.h"
//---------------------------------------------------------------
class __declspec(uuid("{B24F7B12-A908-4BBC-9B19-A4637675506A}")) TDMSprCountryImpl : public IDMSprCountry
{
public:
   TDMSprCountryImpl();
   ~TDMSprCountryImpl();
   TDMSprCountry * Object;
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

//IDMSprCountry
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

   virtual TFIBBCDField * get_TableID_SCOUNTRY(void);
   virtual void set_TableID_SCOUNTRY(TFIBBCDField * TableID_SCOUNTRY);

   virtual TFIBBCDField * get_ElementID_SCOUNTRY(void);
   virtual void set_ElementID_SCOUNTRY(TFIBBCDField * ElementID_SCOUNTRY);

   virtual TFIBWideStringField * get_TableCODE_SCOUNTRY(void);
   virtual void set_TableCODE_SCOUNTRY(TFIBWideStringField * TableCODE_SCOUNTRY);

   virtual TFIBWideStringField * get_TableGID_SCOUNTRY(void);
   virtual void set_TableGID_SCOUNTRY(TFIBWideStringField * TableGID_SCOUNTRY);

   virtual TFIBWideStringField * get_TableNAME_SCOUNTRY(void);
   virtual void set_TableNAME_SCOUNTRY(TFIBWideStringField * TableNAME_SCOUNTRY);

   virtual TFIBWideStringField * get_ElementCODE_SCOUNTRY(void);
   virtual void set_ElementCODE_SCOUNTRY(TFIBWideStringField * ElementCODE_SCOUNTRY);

   virtual TFIBWideStringField * get_ElementGID_SCOUNTRY(void);
   virtual void set_ElementGID_SCOUNTRY(TFIBWideStringField * ElementGID_SCOUNTRY);

   virtual TFIBWideStringField * get_ElementNAME_SCOUNTRY(void);
   virtual void set_ElementNAME_SCOUNTRY(TFIBWideStringField * ElementNAME_SCOUNTRY);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual __int64 GetIDElement(String gid);
   virtual AnsiString GetGIDElement(__int64 id);
   virtual __int64 GetIdPoName(UnicodeString name);
};
#define CLSID_TDMSprCountryImpl __uuidof(TDMSprCountryImpl)
#endif
