#ifndef UREM_DMSprGrpKKTImplH
#define UREM_DMSprGrpKKTImplH
#include "IREM_DMSprGrpKKT.h"
#include "UREM_DMSprGrpKKT.h"
//---------------------------------------------------------------
class __declspec(uuid("{51406390-3598-460E-B453-6ADB1DDA0168}"))TREM_DMSprGrpKKTImpl : public IREM_DMSprGrpKKT
{
public:
   TREM_DMSprGrpKKTImpl();
   ~TREM_DMSprGrpKKTImpl();
   TREM_DMSprGrpKKT * Object;
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

//IREM_DMSprGrpKKT
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

   virtual TFIBLargeIntField * get_TableID_REM_SGRPKKT(void);
   virtual void set_TableID_REM_SGRPKKT(TFIBLargeIntField * TableID_REM_SGRPKKT);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SGRPKKT(void);
   virtual void set_TableIDBASE_REM_SGRPKKT(TFIBLargeIntField * TableIDBASE_REM_SGRPKKT);

   virtual TFIBWideStringField * get_TableNAME_REM_SGRPKKT(void);
   virtual void set_TableNAME_REM_SGRPKKT(TFIBWideStringField * TableNAME_REM_SGRPKKT);

   virtual TFIBLargeIntField * get_TableIDGRP_REM_SGRPKKT(void);
   virtual void set_TableIDGRP_REM_SGRPKKT(TFIBLargeIntField * TableIDGRP_REM_SGRPKKT);

   virtual TFIBLargeIntField * get_ElementID_REM_SGRPKKT(void);
   virtual void set_ElementID_REM_SGRPKKT(TFIBLargeIntField * ElementID_REM_SGRPKKT);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SGRPKKT(void);
   virtual void set_ElementIDBASE_REM_SGRPKKT(TFIBLargeIntField * ElementIDBASE_REM_SGRPKKT);

   virtual TFIBWideStringField * get_ElementNAME_REM_SGRPKKT(void);
   virtual void set_ElementNAME_REM_SGRPKKT(TFIBWideStringField * ElementNAME_REM_SGRPKKT);

   virtual TFIBLargeIntField * get_ElementIDGRP_REM_SGRPKKT(void);
   virtual void set_ElementIDGRP_REM_SGRPKKT(TFIBLargeIntField * ElementIDGRP_REM_SGRPKKT);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 FindPoName(UnicodeString name);
};
#define CLSID_TREM_DMSprGrpKKTImpl __uuidof(TREM_DMSprGrpKKTImpl)
#endif
