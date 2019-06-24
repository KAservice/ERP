#ifndef UREM_DMSprTrebUslovImplH
#define UREM_DMSprTrebUslovImplH
#include "IREM_DMSprTrebUslov.h"
#include "UREM_DMSprTrebUslov.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprTrebUslovImpl)) TREM_DMSprTrebUslovImpl : public IREM_DMSprTrebUslov
{
public:
   TREM_DMSprTrebUslovImpl();
   ~TREM_DMSprTrebUslovImpl();
   TREM_DMSprTrebUslov * Object;
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

//IREM_DMSprTrebUslov
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

   virtual TFIBLargeIntField * get_TableID_REM_STREBUSLOV(void);
   virtual void set_TableID_REM_STREBUSLOV(TFIBLargeIntField * TableID_REM_STREBUSLOV);

   virtual TFIBWideStringField * get_TableGID_REM_STREBUSLOV(void);
   virtual void set_TableGID_REM_STREBUSLOV(TFIBWideStringField * TableGID_REM_STREBUSLOV);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_STREBUSLOV(void);
   virtual void set_TableIDBASE_REM_STREBUSLOV(TFIBLargeIntField * TableIDBASE_REM_STREBUSLOV);

   virtual TFIBLargeIntField * get_TableIDDMN_REM_STREBUSLOV(void);
   virtual void set_TableIDDMN_REM_STREBUSLOV(TFIBLargeIntField * TableIDDMN_REM_STREBUSLOV);

   virtual TFIBLargeIntField * get_TableIDTYPUSLA_REM_STREBUSLOV(void);
   virtual void set_TableIDTYPUSLA_REM_STREBUSLOV(TFIBLargeIntField * TableIDTYPUSLA_REM_STREBUSLOV);

   virtual TFIBWideStringField * get_TableNAME_REM_STREBUSLOV(void);
   virtual void set_TableNAME_REM_STREBUSLOV(TFIBWideStringField * TableNAME_REM_STREBUSLOV);

   virtual TFIBWideStringField * get_TableNAME_REM_STYPUSLOV(void);
   virtual void set_TableNAME_REM_STYPUSLOV(TFIBWideStringField * TableNAME_REM_STYPUSLOV);

   virtual TFIBLargeIntField * get_ElementID_REM_STREBUSLOV(void);
   virtual void set_ElementID_REM_STREBUSLOV(TFIBLargeIntField * ElementID_REM_STREBUSLOV);

   virtual TFIBWideStringField * get_ElementGID_REM_STREBUSLOV(void);
   virtual void set_ElementGID_REM_STREBUSLOV(TFIBWideStringField * ElementGID_REM_STREBUSLOV);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_STREBUSLOV(void);
   virtual void set_ElementIDBASE_REM_STREBUSLOV(TFIBLargeIntField * ElementIDBASE_REM_STREBUSLOV);

   virtual TFIBLargeIntField * get_ElementIDDMN_REM_STREBUSLOV(void);
   virtual void set_ElementIDDMN_REM_STREBUSLOV(TFIBLargeIntField * ElementIDDMN_REM_STREBUSLOV);

   virtual TFIBLargeIntField * get_ElementIDTYPUSLA_REM_STREBUSLOV(void);
   virtual void set_ElementIDTYPUSLA_REM_STREBUSLOV(TFIBLargeIntField * ElementIDTYPUSLA_REM_STREBUSLOV);

   virtual TFIBWideStringField * get_ElementNAME_REM_STREBUSLOV(void);
   virtual void set_ElementNAME_REM_STREBUSLOV(TFIBWideStringField * ElementNAME_REM_STREBUSLOV);

   virtual TFIBWideStringField * get_ElementNAME_REM_STYPUSLOV(void);
   virtual void set_ElementNAME_REM_STYPUSLOV(TFIBWideStringField * ElementNAME_REM_STYPUSLOV);

   virtual void OpenTable(__int64 id_defect_model_neispr);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_defect_model_neispr);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TREM_DMSprTrebUslovImpl __uuidof(TREM_DMSprTrebUslovImpl)
#endif
