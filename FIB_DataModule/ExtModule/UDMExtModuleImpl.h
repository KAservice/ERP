#ifndef UDMExtModuleImplH
#define UDMExtModuleImplH
#include "IDMExtModule.h"
#include "UDMExtModule.h"
//---------------------------------------------------------------
class __declspec(uuid("{21051733-BB63-4EFA-A2FF-D316577E24AB}")) TDMExtModuleImpl : public IDMExtModule
{
public:
   TDMExtModuleImpl();
   ~TDMExtModuleImpl();
   TDMExtModule * Object;
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

//IDMExtModule
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

   virtual TFIBBCDField * get_TableID_EXT_MODULE(void);
   virtual void set_TableID_EXT_MODULE(TFIBBCDField * TableID_EXT_MODULE);

   virtual TFIBBCDField * get_TableIDGRP_EXT_MODULE(void);
   virtual void set_TableIDGRP_EXT_MODULE(TFIBBCDField * TableIDGRP_EXT_MODULE);

   virtual TFIBSmallIntField * get_TableTYPE_EXT_MODULE(void);
   virtual void set_TableTYPE_EXT_MODULE(TFIBSmallIntField * TableTYPE_EXT_MODULE);

   virtual TFIBSmallIntField * get_TableISP_EXT_MODULE(void);
   virtual void set_TableISP_EXT_MODULE(TFIBSmallIntField * TableISP_EXT_MODULE);

   virtual TFIBBCDField * get_ElementID_EXT_MODULE(void);
   virtual void set_ElementID_EXT_MODULE(TFIBBCDField * ElementID_EXT_MODULE);

   virtual TFIBBCDField * get_ElementIDGRP_EXT_MODULE(void);
   virtual void set_ElementIDGRP_EXT_MODULE(TFIBBCDField * ElementIDGRP_EXT_MODULE);

   virtual TFIBSmallIntField * get_ElementTYPE_EXT_MODULE(void);
   virtual void set_ElementTYPE_EXT_MODULE(TFIBSmallIntField * ElementTYPE_EXT_MODULE);

   virtual TFIBSmallIntField * get_ElementISP_EXT_MODULE(void);
   virtual void set_ElementISP_EXT_MODULE(TFIBSmallIntField * ElementISP_EXT_MODULE);

   virtual TFIBBlobField * get_ElementBODY_EXT_MODULE(void);
   virtual void set_ElementBODY_EXT_MODULE(TFIBBlobField * ElementBODY_EXT_MODULE);

   virtual TFIBIntegerField * get_ElementRESIDENCE_EXT_MODULE(void);
   virtual void set_ElementRESIDENCE_EXT_MODULE(TFIBIntegerField * ElementRESIDENCE_EXT_MODULE);

   virtual TFIBWideStringField * get_TableNAME_EXT_MODULE(void);
   virtual void set_TableNAME_EXT_MODULE(TFIBWideStringField * TableNAME_EXT_MODULE);

   virtual TFIBWideStringField * get_TableFILE_NAME_EXT_MODULE(void);
   virtual void set_TableFILE_NAME_EXT_MODULE(TFIBWideStringField * TableFILE_NAME_EXT_MODULE);

   virtual TFIBWideStringField * get_ElementNAME_EXT_MODULE(void);
   virtual void set_ElementNAME_EXT_MODULE(TFIBWideStringField * ElementNAME_EXT_MODULE);

   virtual TFIBWideStringField * get_ElementFILE_NAME_EXT_MODULE(void);
   virtual void set_ElementFILE_NAME_EXT_MODULE(TFIBWideStringField * ElementFILE_NAME_EXT_MODULE);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_grp, bool all);
   virtual int OpenElement(__int64 id );
   virtual bool NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void ChancheGrp(__int64 new_id_grp);
   virtual __int64 FindPoName(AnsiString name);
   virtual __int64 GetIdGrpExtModule(__int64 id_ext_module);
};
#define CLSID_TDMExtModuleImpl __uuidof(TDMExtModuleImpl)
#endif
