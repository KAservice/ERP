#ifndef UDMSprInfBaseImplH
#define UDMSprInfBaseImplH
#include "IDMSprInfBase.h"
#include "UDMSprInfBase.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprInfBaseImpl)) TDMSprInfBaseImpl : public IDMSprInfBase
{
public:
   TDMSprInfBaseImpl();
   ~TDMSprInfBaseImpl();
   TDMSprInfBase * Object;
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

//IDMSprInfBase
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

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_TableID_SINFBASE_OBMEN(void);
   virtual void set_TableID_SINFBASE_OBMEN(TFIBBCDField * TableID_SINFBASE_OBMEN);

   virtual TFIBIntegerField * get_TableIDTIZM_SINFBASE_OBMEN(void);
   virtual void set_TableIDTIZM_SINFBASE_OBMEN(TFIBIntegerField * TableIDTIZM_SINFBASE_OBMEN);

   virtual TFIBBCDField * get_ElementID_SINFBASE_OBMEN(void);
   virtual void set_ElementID_SINFBASE_OBMEN(TFIBBCDField * ElementID_SINFBASE_OBMEN);

   virtual TFIBIntegerField * get_ElementIDTIZM_SINFBASE_OBMEN(void);
   virtual void set_ElementIDTIZM_SINFBASE_OBMEN(TFIBIntegerField * ElementIDTIZM_SINFBASE_OBMEN);

   virtual TFIBSmallIntField * get_ElementNOACT_SINFBASE_OBMEN(void);
   virtual void set_ElementNOACT_SINFBASE_OBMEN(TFIBSmallIntField * ElementNOACT_SINFBASE_OBMEN);

   virtual TFIBSmallIntField * get_TableNOACT_SINFBASE_OBMEN(void);
   virtual void set_TableNOACT_SINFBASE_OBMEN(TFIBSmallIntField * TableNOACT_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_TableGID_SINFBASE_OBMEN(void);
   virtual void set_TableGID_SINFBASE_OBMEN(TFIBWideStringField * TableGID_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void);
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_ElementGID_SINFBASE_OBMEN(void);
   virtual void set_ElementGID_SINFBASE_OBMEN(TFIBWideStringField * ElementGID_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_ElementNAME_SINFBASE_OBMEN(void);
   virtual void set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_ElementPREF_NUM_SINFBASE_OBMEN(void);
   virtual void set_ElementPREF_NUM_SINFBASE_OBMEN(TFIBWideStringField * ElementPREF_NUM_SINFBASE_OBMEN);

   virtual __int64 GetIdPoPrefiks(AnsiString prefiks);
   virtual __int64 GetIdPoName(AnsiString name);
   virtual void OpenTable(void);
   virtual int  OpenElement(__int64 id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
};
#define CLSID_TDMSprInfBaseImpl __uuidof(TDMSprInfBaseImpl)
#endif
