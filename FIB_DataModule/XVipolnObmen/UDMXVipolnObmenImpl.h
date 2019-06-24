#ifndef UDMXVipolnObmenImplH
#define UDMXVipolnObmenImplH
#include "IDMXVipolnObmen.h"
#include "UDMXVipolnObmen.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMXVipolnObmenImpl)) TDMXVipolnObmenImpl : public IDMXVipolnObmen
{
public:
   TDMXVipolnObmenImpl();
   ~TDMXVipolnObmenImpl();
   TDMXVipolnObmen * Object;
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

//IDMXVipolnObmen
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

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBLargeIntField * get_TableID_XVIPOLN_OBMEN(void);
   virtual void set_TableID_XVIPOLN_OBMEN(TFIBLargeIntField * TableID_XVIPOLN_OBMEN);

   virtual TFIBLargeIntField * get_TableIDBASE_XVIPOLN_OBMEN(void);
   virtual void set_TableIDBASE_XVIPOLN_OBMEN(TFIBLargeIntField * TableIDBASE_XVIPOLN_OBMEN);

   virtual TFIBLargeIntField * get_TableIDINFBASE_XVIPOLN_OBMEN(void);
   virtual void set_TableIDINFBASE_XVIPOLN_OBMEN(TFIBLargeIntField * TableIDINFBASE_XVIPOLN_OBMEN);

   virtual TFIBDateTimeField * get_TablePOS_ZAGR_XVIPOLN_OBMEN(void);
   virtual void set_TablePOS_ZAGR_XVIPOLN_OBMEN(TFIBDateTimeField * TablePOS_ZAGR_XVIPOLN_OBMEN);

   virtual TFIBDateTimeField * get_TablePOS_VIGR_XVIPOLN_OBMEN(void);
   virtual void set_TablePOS_VIGR_XVIPOLN_OBMEN(TFIBDateTimeField * TablePOS_VIGR_XVIPOLN_OBMEN);

   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void);
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN);

   virtual TFIBSmallIntField * get_TableNOACT_SINFBASE_OBMEN(void);
   virtual void set_TableNOACT_SINFBASE_OBMEN(TFIBSmallIntField * TableNOACT_SINFBASE_OBMEN);

   virtual TFIBLargeIntField * get_ElementID_XVIPOLN_OBMEN(void);
   virtual void set_ElementID_XVIPOLN_OBMEN(TFIBLargeIntField * ElementID_XVIPOLN_OBMEN);

   virtual TFIBLargeIntField * get_ElementIDBASE_XVIPOLN_OBMEN(void);
   virtual void set_ElementIDBASE_XVIPOLN_OBMEN(TFIBLargeIntField * ElementIDBASE_XVIPOLN_OBMEN);

   virtual TFIBLargeIntField * get_ElementIDINFBASE_XVIPOLN_OBMEN(void);
   virtual void set_ElementIDINFBASE_XVIPOLN_OBMEN(TFIBLargeIntField * ElementIDINFBASE_XVIPOLN_OBMEN);

   virtual TFIBDateTimeField * get_ElementPOS_ZAGR_XVIPOLN_OBMEN(void);
   virtual void set_ElementPOS_ZAGR_XVIPOLN_OBMEN(TFIBDateTimeField * ElementPOS_ZAGR_XVIPOLN_OBMEN);

   virtual TFIBDateTimeField * get_ElementPOS_VIGR_XVIPOLN_OBMEN(void);
   virtual void set_ElementPOS_VIGR_XVIPOLN_OBMEN(TFIBDateTimeField * ElementPOS_VIGR_XVIPOLN_OBMEN);

   virtual TFIBWideStringField * get_ElementNAME_SINFBASE_OBMEN(void);
   virtual void set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN);

   virtual TFIBSmallIntField * get_ElementNOACT_SINFBASE_OBMEN(void);
   virtual void set_ElementNOACT_SINFBASE_OBMEN(TFIBSmallIntField * ElementNOACT_SINFBASE_OBMEN);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(void);
   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all);
   virtual int OpenElement(__int64 id );
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_element);
   virtual __int64 FindPoName(UnicodeString name);
   virtual __int64 FindPoIdBase(__int64 id_base);
   virtual __int64 GetIdGrp(__int64 id_el);
};
#define CLSID_TDMXVipolnObmenImpl __uuidof(TDMXVipolnObmenImpl)
#endif
