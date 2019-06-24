#ifndef UREM_DMSprProducerConditionImplH
#define UREM_DMSprProducerConditionImplH
#include "IREM_DMSprProducerCondition.h"
#include "UREM_DMSprProducerCondition.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprProducerConditionImpl)) TREM_DMSprProducerConditionImpl : public IREM_DMSprProducerCondition
{
public:
   TREM_DMSprProducerConditionImpl();
   ~TREM_DMSprProducerConditionImpl();
   TREM_DMSprProducerCondition * Object;
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

//IREM_DMSprProducerCondition
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBLargeIntField * get_TableID_REM_SPRCONDITION(void);
   virtual void set_TableID_REM_SPRCONDITION(TFIBLargeIntField * TableID_REM_SPRCONDITION);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SPRCONDITION(void);
   virtual void set_TableIDBASE_REM_SPRCONDITION(TFIBLargeIntField * TableIDBASE_REM_SPRCONDITION);

   virtual TFIBWideStringField * get_TableGID_REM_SPRCONDITION(void);
   virtual void set_TableGID_REM_SPRCONDITION(TFIBWideStringField * TableGID_REM_SPRCONDITION);

   virtual TFIBLargeIntField * get_TableIDPR_REM_SPRCONDITION(void);
   virtual void set_TableIDPR_REM_SPRCONDITION(TFIBLargeIntField * TableIDPR_REM_SPRCONDITION);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_SPRCONDITION(void);
   virtual void set_TableIDGRP_REM_SPRCONDITION(TFIBLargeIntField * TableIDGRP_REM_SPRCONDITION);

   virtual TFIBWideStringField * get_TableCODE_REM_SPRCONDITION(void);
   virtual void set_TableCODE_REM_SPRCONDITION(TFIBWideStringField * TableCODE_REM_SPRCONDITION);

   virtual TFIBWideStringField * get_TableNAME_REM_SPRCONDITION(void);
   virtual void set_TableNAME_REM_SPRCONDITION(TFIBWideStringField * TableNAME_REM_SPRCONDITION);

   virtual TFIBWideStringField * get_TableNAME_ENG_REM_SPRCONDITION(void);
   virtual void set_TableNAME_ENG_REM_SPRCONDITION(TFIBWideStringField * TableNAME_ENG_REM_SPRCONDITION);

   virtual TFIBLargeIntField * get_ElementID_REM_SPRCONDITION(void);
   virtual void set_ElementID_REM_SPRCONDITION(TFIBLargeIntField * ElementID_REM_SPRCONDITION);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SPRCONDITION(void);
   virtual void set_ElementIDBASE_REM_SPRCONDITION(TFIBLargeIntField * ElementIDBASE_REM_SPRCONDITION);

   virtual TFIBWideStringField * get_ElementGID_REM_SPRCONDITION(void);
   virtual void set_ElementGID_REM_SPRCONDITION(TFIBWideStringField * ElementGID_REM_SPRCONDITION);

   virtual TFIBLargeIntField * get_ElementIDPR_REM_SPRCONDITION(void);
   virtual void set_ElementIDPR_REM_SPRCONDITION(TFIBLargeIntField * ElementIDPR_REM_SPRCONDITION);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SPRCONDITION(void);
   virtual void set_ElementIDGRP_REM_SPRCONDITION(TFIBLargeIntField * ElementIDGRP_REM_SPRCONDITION);

   virtual TFIBWideStringField * get_ElementCODE_REM_SPRCONDITION(void);
   virtual void set_ElementCODE_REM_SPRCONDITION(TFIBWideStringField * ElementCODE_REM_SPRCONDITION);

   virtual TFIBWideStringField * get_ElementNAME_REM_SPRCONDITION(void);
   virtual void set_ElementNAME_REM_SPRCONDITION(TFIBWideStringField * ElementNAME_REM_SPRCONDITION);

   virtual TFIBWideStringField * get_ElementNAME_ENG_REM_SPRCONDITION(void);
   virtual void set_ElementNAME_ENG_REM_SPRCONDITION(TFIBWideStringField * ElementNAME_ENG_REM_SPRCONDITION);

   virtual void OpenTable(__int64 id_group_element, __int64 id_grp, bool all);
   virtual bool NewElement(__int64 id_group_element, __int64 id_grp);
   virtual bool OpenElement(__int64 id);
   virtual bool DeleteElement(__int64 id);
   virtual bool SaveElement(void);
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_element);
   virtual __int64 FindPoCodu(__int64 id_group_element, UnicodeString code);
   virtual __int64 FindPoName(__int64 id_group_element, UnicodeString name);
   virtual __int64 FindPoNameEng(__int64 id_group_element, UnicodeString name);
   virtual __int64 GetIdGrp(__int64 id_el);
};
#define CLSID_TREM_DMSprProducerConditionImpl __uuidof(TREM_DMSprProducerConditionImpl)
#endif
