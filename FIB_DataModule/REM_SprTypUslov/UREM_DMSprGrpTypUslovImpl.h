#ifndef UREM_DMSprGrpTypUslovImplH
#define UREM_DMSprGrpTypUslovImplH
#include "IREM_DMSprGrpTypUslov.h"
#include "UREM_DMSprGrpTypUslov.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprGrpTypUslovImpl)) TREM_DMSprGrpTypUslovImpl : public IREM_DMSprGrpTypUslov
{
public:
   TREM_DMSprGrpTypUslovImpl();
   ~TREM_DMSprGrpTypUslovImpl();
   TREM_DMSprGrpTypUslov * Object;
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

//IREM_DMSprGrpTypUslov
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

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_ElementID_REM_STYPUSLOV_GRP(void);
   virtual void set_ElementID_REM_STYPUSLOV_GRP(TFIBLargeIntField * ElementID_REM_STYPUSLOV_GRP);

   virtual TFIBWideStringField * get_ElementGID_REM_STYPUSLOV_GRP(void);
   virtual void set_ElementGID_REM_STYPUSLOV_GRP(TFIBWideStringField * ElementGID_REM_STYPUSLOV_GRP);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_STYPUSLOV_GRP(void);
   virtual void set_ElementIDBASE_REM_STYPUSLOV_GRP(TFIBLargeIntField * ElementIDBASE_REM_STYPUSLOV_GRP);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_STYPUSLOV_GRP(void);
   virtual void set_ElementIDGRP_REM_STYPUSLOV_GRP(TFIBLargeIntField * ElementIDGRP_REM_STYPUSLOV_GRP);

   virtual TFIBWideStringField * get_ElementNAME_REM_STYPUSLOV_GRP(void);
   virtual void set_ElementNAME_REM_STYPUSLOV_GRP(TFIBWideStringField * ElementNAME_REM_STYPUSLOV_GRP);

   virtual TFIBLargeIntField * get_TableID_REM_STYPUSLOV_GRP(void);
   virtual void set_TableID_REM_STYPUSLOV_GRP(TFIBLargeIntField * TableID_REM_STYPUSLOV_GRP);

   virtual TFIBWideStringField * get_TableGID_REM_STYPUSLOV_GRP(void);
   virtual void set_TableGID_REM_STYPUSLOV_GRP(TFIBWideStringField * TableGID_REM_STYPUSLOV_GRP);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_STYPUSLOV_GRP(void);
   virtual void set_TableIDBASE_REM_STYPUSLOV_GRP(TFIBLargeIntField * TableIDBASE_REM_STYPUSLOV_GRP);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_STYPUSLOV_GRP(void);
   virtual void set_TableIDGRP_REM_STYPUSLOV_GRP(TFIBLargeIntField * TableIDGRP_REM_STYPUSLOV_GRP);

   virtual TFIBWideStringField * get_TableNAME_REM_STYPUSLOV_GRP(void);
   virtual void set_TableNAME_REM_STYPUSLOV_GRP(TFIBWideStringField * TableNAME_REM_STYPUSLOV_GRP);

   virtual TFIBWideStringField * get_TableNAME_ENG_REM_STYPUSLOV_GRP(void);
   virtual void set_TableNAME_ENG_REM_STYPUSLOV_GRP(TFIBWideStringField * TableNAME_ENG_REM_STYPUSLOV_GRP);

   virtual TFIBWideStringField * get_ElementNAME_ENG_REM_STYPUSLOV_GRP(void);
   virtual void set_ElementNAME_ENG_REM_STYPUSLOV_GRP(TFIBWideStringField * ElementNAME_ENG_REM_STYPUSLOV_GRP);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
   virtual int GetIDElement(UnicodeString gid);
   virtual __int64 FindPoName(UnicodeString name);
};
#define CLSID_TREM_DMSprGrpTypUslovImpl __uuidof(TREM_DMSprGrpTypUslovImpl)
#endif
