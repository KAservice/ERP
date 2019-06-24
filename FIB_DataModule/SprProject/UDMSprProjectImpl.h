#ifndef UDMSprProjectImplH
#define UDMSprProjectImplH
#include "IDMSprProject.h"
#include "UDMSprProject.h"
//---------------------------------------------------------------
class __declspec(uuid("{7F3B1996-6924-411A-983D-F74497279075}"))TDMSprProjectImpl : public IDMSprProject
{
public:
   TDMSprProjectImpl();
   ~TDMSprProjectImpl();
   TDMSprProject * Object;
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

//IDMSprProject
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

   virtual TFIBBCDField * get_TableID_SPROJECT(void);
   virtual void set_TableID_SPROJECT(TFIBBCDField * TableID_SPROJECT);

   virtual TFIBBCDField * get_TableIDGRP_SPROJECT(void);
   virtual void set_TableIDGRP_SPROJECT(TFIBBCDField * TableIDGRP_SPROJECT);

   virtual TFIBBCDField * get_ElementID_SPROJECT(void);
   virtual void set_ElementID_SPROJECT(TFIBBCDField * ElementID_SPROJECT);

   virtual TFIBBCDField * get_ElementIDGRP_SPROJECT(void);
   virtual void set_ElementIDGRP_SPROJECT(TFIBBCDField * ElementIDGRP_SPROJECT);

   virtual TFIBIntegerField * get_ElementCODE_SPROJECT(void);
   virtual void set_ElementCODE_SPROJECT(TFIBIntegerField * ElementCODE_SPROJECT);

   virtual TpFIBDataSet * get_Code(void);
   virtual void set_Code(TpFIBDataSet * Code);

   virtual TFIBIntegerField * get_CodeMAXCODE(void);
   virtual void set_CodeMAXCODE(TFIBIntegerField * CodeMAXCODE);

   virtual TFIBIntegerField * get_TableCODE_SPROJECT(void);
   virtual void set_TableCODE_SPROJECT(TFIBIntegerField * TableCODE_SPROJECT);

   virtual TFIBWideStringField * get_TableNAME_SPROJECT(void);
   virtual void set_TableNAME_SPROJECT(TFIBWideStringField * TableNAME_SPROJECT);

   virtual TFIBWideStringField * get_ElementNAME_SPROJECT(void);
   virtual void set_ElementNAME_SPROJECT(TFIBWideStringField * ElementNAME_SPROJECT);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual AnsiString GetTextQuery(__int64 id_grp, bool all);
   virtual void OpenTable(__int64 id_grp, bool all);
   virtual int OpenElement(__int64 id );
   virtual bool NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void ChancheGrp(__int64 new_id_grp);
   virtual __int64 FindPoCodu(int code);
   virtual __int64 FindPoName(AnsiString name);
   virtual __int64 GetIdGrpProject(__int64 id_project);
   virtual int GetCodeProject(void);
   virtual bool CheckCode(__int64 id_project, int code);
};
#define CLSID_TDMSprProjectImpl __uuidof(TDMSprProjectImpl)
#endif
