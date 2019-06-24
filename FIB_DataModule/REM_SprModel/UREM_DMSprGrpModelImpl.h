#ifndef UREM_DMSprGrpModelImplH
#define UREM_DMSprGrpModelImplH
#include "IREM_DMSprGrpModel.h"
#include "UREM_DMSprGrpModel.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprGrpModelImpl)) TREM_DMSprGrpModelImpl : public IREM_DMSprGrpModel
{
public:
   TREM_DMSprGrpModelImpl();
   ~TREM_DMSprGrpModelImpl();
   TREM_DMSprGrpModel * Object;
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

//IREM_DMSprGrpModel
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

   virtual TFIBLargeIntField * get_TableID_REM_SGRPMODEL(void);
   virtual void set_TableID_REM_SGRPMODEL(TFIBLargeIntField * TableID_REM_SGRPMODEL);

   virtual TFIBWideStringField * get_TableGID_REM_SGRPMODEL(void);
   virtual void set_TableGID_REM_SGRPMODEL(TFIBWideStringField * TableGID_REM_SGRPMODEL);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_SGRPMODEL(void);
   virtual void set_TableIDGRP_REM_SGRPMODEL(TFIBLargeIntField * TableIDGRP_REM_SGRPMODEL);

   virtual TFIBWideStringField * get_TableNAME_REM_SGRPMODEL(void);
   virtual void set_TableNAME_REM_SGRPMODEL(TFIBWideStringField * TableNAME_REM_SGRPMODEL);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SGRPMODEL(void);
   virtual void set_TableIDBASE_REM_SGRPMODEL(TFIBLargeIntField * TableIDBASE_REM_SGRPMODEL);

   virtual TFIBLargeIntField * get_ElementID_REM_SGRPMODEL(void);
   virtual void set_ElementID_REM_SGRPMODEL(TFIBLargeIntField * ElementID_REM_SGRPMODEL);

   virtual TFIBWideStringField * get_ElementGID_REM_SGRPMODEL(void);
   virtual void set_ElementGID_REM_SGRPMODEL(TFIBWideStringField * ElementGID_REM_SGRPMODEL);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SGRPMODEL(void);
   virtual void set_ElementIDGRP_REM_SGRPMODEL(TFIBLargeIntField * ElementIDGRP_REM_SGRPMODEL);

   virtual TFIBWideStringField * get_ElementNAME_REM_SGRPMODEL(void);
   virtual void set_ElementNAME_REM_SGRPMODEL(TFIBWideStringField * ElementNAME_REM_SGRPMODEL);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SGRPMODEL(void);
   virtual void set_ElementIDBASE_REM_SGRPMODEL(TFIBLargeIntField * ElementIDBASE_REM_SGRPMODEL);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
   virtual int GetIDElement(UnicodeString gid);
   virtual __int64 FindPoName(UnicodeString name);
};
#define CLSID_TREM_DMSprGrpModelImpl __uuidof(TREM_DMSprGrpModelImpl)
#endif
