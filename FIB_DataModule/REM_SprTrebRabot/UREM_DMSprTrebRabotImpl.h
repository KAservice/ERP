#ifndef UREM_DMSprTrebRabotImplH
#define UREM_DMSprTrebRabotImplH
#include "IREM_DMSprTrebRabot.h"
#include "UREM_DMSprTrebRabot.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprTrebRabotImpl)) TREM_DMSprTrebRabotImpl : public IREM_DMSprTrebRabot
{
public:
   TREM_DMSprTrebRabotImpl();
   ~TREM_DMSprTrebRabotImpl();
   TREM_DMSprTrebRabot * Object;
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

//IREM_DMSprTrebRabot
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

   virtual TFIBLargeIntField * get_TableID_REM_STREBRABOT(void);
   virtual void set_TableID_REM_STREBRABOT(TFIBLargeIntField * TableID_REM_STREBRABOT);

   virtual TFIBWideStringField * get_TableGID_REM_STREBRABOT(void);
   virtual void set_TableGID_REM_STREBRABOT(TFIBWideStringField * TableGID_REM_STREBRABOT);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_STREBRABOT(void);
   virtual void set_TableIDBASE_REM_STREBRABOT(TFIBLargeIntField * TableIDBASE_REM_STREBRABOT);

   virtual TFIBLargeIntField * get_TableIDDMN_REM_STREBRABOT(void);
   virtual void set_TableIDDMN_REM_STREBRABOT(TFIBLargeIntField * TableIDDMN_REM_STREBRABOT);

   virtual TFIBLargeIntField * get_TableIDTYPRABOT_REM_STREBRABOT(void);
   virtual void set_TableIDTYPRABOT_REM_STREBRABOT(TFIBLargeIntField * TableIDTYPRABOT_REM_STREBRABOT);

   virtual TFIBWideStringField * get_TableNAME_REM_STREBRABOT(void);
   virtual void set_TableNAME_REM_STREBRABOT(TFIBWideStringField * TableNAME_REM_STREBRABOT);

   virtual TFIBWideStringField * get_TableNAME_REM_STYPRABOT(void);
   virtual void set_TableNAME_REM_STYPRABOT(TFIBWideStringField * TableNAME_REM_STYPRABOT);

   virtual TFIBLargeIntField * get_ElementID_REM_STREBRABOT(void);
   virtual void set_ElementID_REM_STREBRABOT(TFIBLargeIntField * ElementID_REM_STREBRABOT);

   virtual TFIBWideStringField * get_ElementGID_REM_STREBRABOT(void);
   virtual void set_ElementGID_REM_STREBRABOT(TFIBWideStringField * ElementGID_REM_STREBRABOT);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_STREBRABOT(void);
   virtual void set_ElementIDBASE_REM_STREBRABOT(TFIBLargeIntField * ElementIDBASE_REM_STREBRABOT);

   virtual TFIBLargeIntField * get_ElementIDDMN_REM_STREBRABOT(void);
   virtual void set_ElementIDDMN_REM_STREBRABOT(TFIBLargeIntField * ElementIDDMN_REM_STREBRABOT);

   virtual TFIBLargeIntField * get_ElementIDTYPRABOT_REM_STREBRABOT(void);
   virtual void set_ElementIDTYPRABOT_REM_STREBRABOT(TFIBLargeIntField * ElementIDTYPRABOT_REM_STREBRABOT);

   virtual TFIBWideStringField * get_ElementNAME_REM_STREBRABOT(void);
   virtual void set_ElementNAME_REM_STREBRABOT(TFIBWideStringField * ElementNAME_REM_STREBRABOT);

   virtual TFIBWideStringField * get_ElementNAME_REM_STYPRABOT(void);
   virtual void set_ElementNAME_REM_STYPRABOT(TFIBWideStringField * ElementNAME_REM_STYPRABOT);

   virtual void OpenTable(__int64 id_defect_model_neispr);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_defect_model_neispr);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TREM_DMSprTrebRabotImpl __uuidof(TREM_DMSprTrebRabotImpl)
#endif
