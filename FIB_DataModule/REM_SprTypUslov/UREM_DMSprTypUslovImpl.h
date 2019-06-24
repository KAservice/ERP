#ifndef UREM_DMSprTypUslovImplH
#define UREM_DMSprTypUslovImplH
#include "IREM_DMSprTypUslov.h"
#include "UREM_DMSprTypUslov.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprTypUslovImpl)) TREM_DMSprTypUslovImpl : public IREM_DMSprTypUslov
{
public:
   TREM_DMSprTypUslovImpl();
   ~TREM_DMSprTypUslovImpl();
   TREM_DMSprTypUslov * Object;
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

//IREM_DMSprTypUslov
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

   virtual TpFIBQuery * get_pFIBQuery(void);
   virtual void set_pFIBQuery(TpFIBQuery * pFIBQuery);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_TableID_REM_STYPUSLOV(void);
   virtual void set_TableID_REM_STYPUSLOV(TFIBLargeIntField * TableID_REM_STYPUSLOV);

   virtual TFIBWideStringField * get_TableGID_REM_STYPUSLOV(void);
   virtual void set_TableGID_REM_STYPUSLOV(TFIBWideStringField * TableGID_REM_STYPUSLOV);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_STYPUSLOV(void);
   virtual void set_TableIDGRP_REM_STYPUSLOV(TFIBLargeIntField * TableIDGRP_REM_STYPUSLOV);

   virtual TFIBWideStringField * get_TableNAME_REM_STYPUSLOV(void);
   virtual void set_TableNAME_REM_STYPUSLOV(TFIBWideStringField * TableNAME_REM_STYPUSLOV);

   virtual TFIBWideStringField * get_TableDESCR_REM_STYPUSLOV(void);
   virtual void set_TableDESCR_REM_STYPUSLOV(TFIBWideStringField * TableDESCR_REM_STYPUSLOV);

   virtual TFIBLargeIntField * get_ElementID_REM_STYPUSLOV(void);
   virtual void set_ElementID_REM_STYPUSLOV(TFIBLargeIntField * ElementID_REM_STYPUSLOV);

   virtual TFIBWideStringField * get_ElementGID_REM_STYPUSLOV(void);
   virtual void set_ElementGID_REM_STYPUSLOV(TFIBWideStringField * ElementGID_REM_STYPUSLOV);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_STYPUSLOV(void);
   virtual void set_ElementIDBASE_REM_STYPUSLOV(TFIBLargeIntField * ElementIDBASE_REM_STYPUSLOV);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_STYPUSLOV(void);
   virtual void set_ElementIDGRP_REM_STYPUSLOV(TFIBLargeIntField * ElementIDGRP_REM_STYPUSLOV);

   virtual TFIBWideStringField * get_ElementNAME_REM_STYPUSLOV(void);
   virtual void set_ElementNAME_REM_STYPUSLOV(TFIBWideStringField * ElementNAME_REM_STYPUSLOV);

   virtual TFIBWideStringField * get_ElementDESCR_REM_STYPUSLOV(void);
   virtual void set_ElementDESCR_REM_STYPUSLOV(TFIBWideStringField * ElementDESCR_REM_STYPUSLOV);

   virtual TFIBWideStringField * get_TableNAME_ENG_REM_STYPUSLOV(void);
   virtual void set_TableNAME_ENG_REM_STYPUSLOV(TFIBWideStringField * TableNAME_ENG_REM_STYPUSLOV);

   virtual TFIBWideStringField * get_ElementNAME_ENG_REM_STYPUSLOV(void);
   virtual void set_ElementNAME_ENG_REM_STYPUSLOV(TFIBWideStringField * ElementNAME_ENG_REM_STYPUSLOV);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all);
   virtual void OpenTable(__int64 id_grp, bool all);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void ChancheGrp(__int64 id_new_grp, __int64 id_el);
   virtual __int64 GetIdGrpTypUsla(__int64 id);
};
#define CLSID_TREM_DMSprTypUslovImpl __uuidof(TREM_DMSprTypUslovImpl)
#endif
