#ifndef UREM_DMSprTypRabotImplH
#define UREM_DMSprTypRabotImplH
#include "IREM_DMSprTypRabot.h"
#include "UREM_DMSprTypRabot.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprTypRabotImpl)) TREM_DMSprTypRabotImpl : public IREM_DMSprTypRabot
{
public:
   TREM_DMSprTypRabotImpl();
   ~TREM_DMSprTypRabotImpl();
   TREM_DMSprTypRabot * Object;
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

//IREM_DMSprTypRabot
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

   virtual TFIBLargeIntField * get_TableID_REM_STYPRABOT(void);
   virtual void set_TableID_REM_STYPRABOT(TFIBLargeIntField * TableID_REM_STYPRABOT);

   virtual TFIBWideStringField * get_TableGID_REM_STYPRABOT(void);
   virtual void set_TableGID_REM_STYPRABOT(TFIBWideStringField * TableGID_REM_STYPRABOT);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_STYPRABOT(void);
   virtual void set_TableIDBASE_REM_STYPRABOT(TFIBLargeIntField * TableIDBASE_REM_STYPRABOT);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_STYPRABOT(void);
   virtual void set_TableIDGRP_REM_STYPRABOT(TFIBLargeIntField * TableIDGRP_REM_STYPRABOT);

   virtual TFIBLargeIntField * get_TableIDNOM_REM_STYPRABOT(void);
   virtual void set_TableIDNOM_REM_STYPRABOT(TFIBLargeIntField * TableIDNOM_REM_STYPRABOT);

   virtual TFIBWideStringField * get_TableNAME_REM_STYPRABOT(void);
   virtual void set_TableNAME_REM_STYPRABOT(TFIBWideStringField * TableNAME_REM_STYPRABOT);

   virtual TFIBWideStringField * get_TableDESCR_REM_STYPRABOT(void);
   virtual void set_TableDESCR_REM_STYPRABOT(TFIBWideStringField * TableDESCR_REM_STYPRABOT);

   virtual TFIBWideStringField * get_TableNAMENOM(void);
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM);

   virtual TFIBWideStringField * get_TableARTNOM(void);
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM);

   virtual TFIBIntegerField * get_TableCODENOM(void);
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM);

   virtual TFIBLargeIntField * get_ElementID_REM_STYPRABOT(void);
   virtual void set_ElementID_REM_STYPRABOT(TFIBLargeIntField * ElementID_REM_STYPRABOT);

   virtual TFIBWideStringField * get_ElementGID_REM_STYPRABOT(void);
   virtual void set_ElementGID_REM_STYPRABOT(TFIBWideStringField * ElementGID_REM_STYPRABOT);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_STYPRABOT(void);
   virtual void set_ElementIDBASE_REM_STYPRABOT(TFIBLargeIntField * ElementIDBASE_REM_STYPRABOT);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_STYPRABOT(void);
   virtual void set_ElementIDGRP_REM_STYPRABOT(TFIBLargeIntField * ElementIDGRP_REM_STYPRABOT);

   virtual TFIBLargeIntField * get_ElementIDNOM_REM_STYPRABOT(void);
   virtual void set_ElementIDNOM_REM_STYPRABOT(TFIBLargeIntField * ElementIDNOM_REM_STYPRABOT);

   virtual TFIBWideStringField * get_ElementNAME_REM_STYPRABOT(void);
   virtual void set_ElementNAME_REM_STYPRABOT(TFIBWideStringField * ElementNAME_REM_STYPRABOT);

   virtual TFIBWideStringField * get_ElementDESCR_REM_STYPRABOT(void);
   virtual void set_ElementDESCR_REM_STYPRABOT(TFIBWideStringField * ElementDESCR_REM_STYPRABOT);

   virtual TFIBWideStringField * get_ElementNAMENOM(void);
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM);

   virtual TFIBWideStringField * get_ElementARTNOM(void);
   virtual void set_ElementARTNOM(TFIBWideStringField * ElementARTNOM);

   virtual TFIBIntegerField * get_ElementCODENOM(void);
   virtual void set_ElementCODENOM(TFIBIntegerField * ElementCODENOM);

   virtual TFIBWideStringField * get_TableNAME_ENG_REM_STYPRABOT(void);
   virtual void set_TableNAME_ENG_REM_STYPRABOT(TFIBWideStringField * TableNAME_ENG_REM_STYPRABOT);

   virtual TFIBWideStringField * get_ElementNAME_ENG_REM_STYPRABOT(void);
   virtual void set_ElementNAME_ENG_REM_STYPRABOT(TFIBWideStringField * ElementNAME_ENG_REM_STYPRABOT);

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
   virtual __int64 GetIdGrpTypRabot(__int64 id);
   virtual __int64 FindPoNom(__int64 id_nom);
};
#define CLSID_TREM_DMSprTypRabotImpl __uuidof(TREM_DMSprTypRabotImpl)
#endif
