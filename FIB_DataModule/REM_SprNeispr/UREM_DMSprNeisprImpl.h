#ifndef UREM_DMSprNeisprImplH
#define UREM_DMSprNeisprImplH
#include "IREM_DMSprNeispr.h"
#include "UREM_DMSprNeispr.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprNeisprImpl)) TREM_DMSprNeisprImpl : public IREM_DMSprNeispr
{
public:
   TREM_DMSprNeisprImpl();
   ~TREM_DMSprNeisprImpl();
   TREM_DMSprNeispr * Object;
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

//IREM_DMSprNeispr
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

   virtual TFIBLargeIntField * get_TableID_REM_SNEISPR(void);
   virtual void set_TableID_REM_SNEISPR(TFIBLargeIntField * TableID_REM_SNEISPR);

   virtual TFIBWideStringField * get_TableGID_REM_SNEISPR(void);
   virtual void set_TableGID_REM_SNEISPR(TFIBWideStringField * TableGID_REM_SNEISPR);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_SNEISPR(void);
   virtual void set_TableIDGRP_REM_SNEISPR(TFIBLargeIntField * TableIDGRP_REM_SNEISPR);

   virtual TFIBWideStringField * get_TableNAME_REM_SNEISPR(void);
   virtual void set_TableNAME_REM_SNEISPR(TFIBWideStringField * TableNAME_REM_SNEISPR);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SNEISPR(void);
   virtual void set_TableIDBASE_REM_SNEISPR(TFIBLargeIntField * TableIDBASE_REM_SNEISPR);

   virtual TFIBLargeIntField * get_ElementID_REM_SNEISPR(void);
   virtual void set_ElementID_REM_SNEISPR(TFIBLargeIntField * ElementID_REM_SNEISPR);

   virtual TFIBWideStringField * get_ElementGID_REM_SNEISPR(void);
   virtual void set_ElementGID_REM_SNEISPR(TFIBWideStringField * ElementGID_REM_SNEISPR);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SNEISPR(void);
   virtual void set_ElementIDGRP_REM_SNEISPR(TFIBLargeIntField * ElementIDGRP_REM_SNEISPR);

   virtual TFIBWideStringField * get_ElementNAME_REM_SNEISPR(void);
   virtual void set_ElementNAME_REM_SNEISPR(TFIBWideStringField * ElementNAME_REM_SNEISPR);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SNEISPR(void);
   virtual void set_ElementIDBASE_REM_SNEISPR(TFIBLargeIntField * ElementIDBASE_REM_SNEISPR);

   virtual TFIBWideStringField * get_TableNAME_ENG_REM_SNEISPR(void);
   virtual void set_TableNAME_ENG_REM_SNEISPR(TFIBWideStringField * TableNAME_ENG_REM_SNEISPR);

   virtual TFIBWideStringField * get_ElementNAME_ENG_REM_SNEISPR(void);
   virtual void set_ElementNAME_ENG_REM_SNEISPR(TFIBWideStringField * ElementNAME_ENG_REM_SNEISPR);

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
   virtual void ChancheGrp(__int64 id_new_grp);
   virtual __int64 GetIDElement(UnicodeString gid);
   virtual UnicodeString GetGIDElement(__int64 id);
   virtual __int64 GetIdGrpNom(__int64 id);
};
#define CLSID_TREM_DMSprNeisprImpl __uuidof(TREM_DMSprNeisprImpl)
#endif
