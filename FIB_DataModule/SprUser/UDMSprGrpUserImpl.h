#ifndef UDMSprGrpUserImplH
#define UDMSprGrpUserImplH
#include "IDMSprGrpUser.h"
#include "UDMSprGrpUser.h"
//---------------------------------------------------------------
class __declspec(uuid("{CE5AB887-2A8B-414C-9398-CBAF3168B21A}"))TDMSprGrpUserImpl : public IDMSprGrpUser
{
public:
   TDMSprGrpUserImpl();
   ~TDMSprGrpUserImpl();
   TDMSprGrpUser * Object;
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

//IDMSprGrpUser
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

   virtual TFIBIntegerField * get_TableINTERF_SGRPUSER(void);
   virtual void set_TableINTERF_SGRPUSER(TFIBIntegerField * TableINTERF_SGRPUSER);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBBCDField * get_TableID_SGRPUSER(void);
   virtual void set_TableID_SGRPUSER(TFIBBCDField * TableID_SGRPUSER);

   virtual TFIBBCDField * get_TableIDGRP_SGRPUSER(void);
   virtual void set_TableIDGRP_SGRPUSER(TFIBBCDField * TableIDGRP_SGRPUSER);

   virtual TFIBBCDField * get_ElementID_SGRPUSER(void);
   virtual void set_ElementID_SGRPUSER(TFIBBCDField * ElementID_SGRPUSER);

   virtual TFIBBCDField * get_ElementIDGRP_SGRPUSER(void);
   virtual void set_ElementIDGRP_SGRPUSER(TFIBBCDField * ElementIDGRP_SGRPUSER);

   virtual TFIBWideStringField * get_TableGID_SGRPUSER(void);
   virtual void set_TableGID_SGRPUSER(TFIBWideStringField * TableGID_SGRPUSER);

   virtual TFIBWideStringField * get_TableNAME_SGRPUSER(void);
   virtual void set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER);

   virtual TFIBWideStringField * get_TableROLE_SGRPUSER(void);
   virtual void set_TableROLE_SGRPUSER(TFIBWideStringField * TableROLE_SGRPUSER);

   virtual TFIBWideStringField * get_ElementGID_SGRPUSER(void);
   virtual void set_ElementGID_SGRPUSER(TFIBWideStringField * ElementGID_SGRPUSER);

   virtual TFIBWideStringField * get_ElementNAME_SGRPUSER(void);
   virtual void set_ElementNAME_SGRPUSER(TFIBWideStringField * ElementNAME_SGRPUSER);

   virtual TFIBSmallIntField * get_ElementINTERF_SGRPUSER(void);
   virtual void set_ElementINTERF_SGRPUSER(TFIBSmallIntField * ElementINTERF_SGRPUSER);

   virtual TFIBWideStringField * get_ElementROLE_SGRPUSER(void);
   virtual void set_ElementROLE_SGRPUSER(TFIBWideStringField * ElementROLE_SGRPUSER);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
   virtual __int64 GetIDElement(String gid);
};
#define CLSID_TDMSprGrpUserImpl __uuidof(TDMSprGrpUserImpl)
#endif
