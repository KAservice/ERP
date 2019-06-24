#ifndef UDMExtModuleGrpImplH
#define UDMExtModuleGrpImplH
#include "IDMExtModuleGrp.h"
#include "UDMExtModuleGrp.h"
//---------------------------------------------------------------
class __declspec(uuid("{9063FB91-0272-48DF-AE9C-68AFB9C8ED31}")) TDMExtModuleGrpImpl : public IDMExtModuleGrp
{
public:
   TDMExtModuleGrpImpl();
   ~TDMExtModuleGrpImpl();
   TDMExtModuleGrp * Object;
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

//IDMExtModuleGrp
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

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_TableID_EXT_MODULE_GRP(void);
   virtual void set_TableID_EXT_MODULE_GRP(TFIBBCDField * TableID_EXT_MODULE_GRP);

   virtual TFIBBCDField * get_TableIDGRP_EXT_MODULE_GRP(void);
   virtual void set_TableIDGRP_EXT_MODULE_GRP(TFIBBCDField * TableIDGRP_EXT_MODULE_GRP);

   virtual TFIBBCDField * get_ElementID_EXT_MODULE_GRP(void);
   virtual void set_ElementID_EXT_MODULE_GRP(TFIBBCDField * ElementID_EXT_MODULE_GRP);

   virtual TFIBBCDField * get_ElementIDGRP_EXT_MODULE_GRP(void);
   virtual void set_ElementIDGRP_EXT_MODULE_GRP(TFIBBCDField * ElementIDGRP_EXT_MODULE_GRP);

   virtual TFIBWideStringField * get_TableNAME_EXT_MODULE_GRP(void);
   virtual void set_TableNAME_EXT_MODULE_GRP(TFIBWideStringField * TableNAME_EXT_MODULE_GRP);

   virtual TFIBWideStringField * get_ElementNAME_EXT_MODULE_GRP(void);
   virtual void set_ElementNAME_EXT_MODULE_GRP(TFIBWideStringField * ElementNAME_EXT_MODULE_GRP);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 FindPoName(AnsiString name);
};
#define CLSID_TDMExtModuleGrpImpl __uuidof(TDMExtModuleGrpImpl)
#endif
