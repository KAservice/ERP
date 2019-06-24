#ifndef UREM_DMSprModelTypRabotImplH
#define UREM_DMSprModelTypRabotImplH
#include "IREM_DMSprModelTypRabot.h"
#include "UREM_DMSprModelTypRabot.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprModelTypRabotImpl)) TREM_DMSprModelTypRabotImpl : public IREM_DMSprModelTypRabot
{
public:
   TREM_DMSprModelTypRabotImpl();
   ~TREM_DMSprModelTypRabotImpl();
   TREM_DMSprModelTypRabot * Object;
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

//IREM_DMSprModelTypRabot
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBLargeIntField * get_TableID_REM_SMODEL_TRAB(void);
   virtual void set_TableID_REM_SMODEL_TRAB(TFIBLargeIntField * TableID_REM_SMODEL_TRAB);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SMODEL_TRAB(void);
   virtual void set_TableIDBASE_REM_SMODEL_TRAB(TFIBLargeIntField * TableIDBASE_REM_SMODEL_TRAB);

   virtual TFIBLargeIntField * get_TableIDTR_REM_SMODEL_TRAB(void);
   virtual void set_TableIDTR_REM_SMODEL_TRAB(TFIBLargeIntField * TableIDTR_REM_SMODEL_TRAB);

   virtual TFIBLargeIntField * get_TableIDMODEL_REM_SMODEL_TRAB(void);
   virtual void set_TableIDMODEL_REM_SMODEL_TRAB(TFIBLargeIntField * TableIDMODEL_REM_SMODEL_TRAB);

   virtual TFIBWideStringField * get_TableNAMENOM(void);
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM);

   virtual TFIBWideStringField * get_TableARTNOM(void);
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM);

   virtual TFIBIntegerField * get_TableCODENOM(void);
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM);

   virtual TFIBWideStringField * get_TableNAME_REM_STYPRABOT(void);
   virtual void set_TableNAME_REM_STYPRABOT(TFIBWideStringField * TableNAME_REM_STYPRABOT);

   virtual TFIBLargeIntField * get_ElementID_REM_SMODEL_TRAB(void);
   virtual void set_ElementID_REM_SMODEL_TRAB(TFIBLargeIntField * ElementID_REM_SMODEL_TRAB);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SMODEL_TRAB(void);
   virtual void set_ElementIDBASE_REM_SMODEL_TRAB(TFIBLargeIntField * ElementIDBASE_REM_SMODEL_TRAB);

   virtual TFIBLargeIntField * get_ElementIDTR_REM_SMODEL_TRAB(void);
   virtual void set_ElementIDTR_REM_SMODEL_TRAB(TFIBLargeIntField * ElementIDTR_REM_SMODEL_TRAB);

   virtual TFIBLargeIntField * get_ElementIDMODEL_REM_SMODEL_TRAB(void);
   virtual void set_ElementIDMODEL_REM_SMODEL_TRAB(TFIBLargeIntField * ElementIDMODEL_REM_SMODEL_TRAB);

   virtual TFIBWideStringField * get_ElementNAMENOM(void);
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM);

   virtual TFIBWideStringField * get_ElementARTNOM(void);
   virtual void set_ElementARTNOM(TFIBWideStringField * ElementARTNOM);

   virtual TFIBIntegerField * get_ElementCODENOM(void);
   virtual void set_ElementCODENOM(TFIBIntegerField * ElementCODENOM);

   virtual TFIBWideStringField * get_ElementNAME_REM_STYPRABOT(void);
   virtual void set_ElementNAME_REM_STYPRABOT(TFIBWideStringField * ElementNAME_REM_STYPRABOT);

   virtual __int64 get_IdOwner(void);
   virtual void set_IdOwner(__int64 IdOwner);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_owner);
   virtual bool NewElement(__int64 id_owner);
   virtual int OpenElement(__int64 id );
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TREM_DMSprModelTypRabotImpl __uuidof(TREM_DMSprModelTypRabotImpl)
#endif
