#ifndef UREM_DMZayavkaDvImplH
#define UREM_DMZayavkaDvImplH
#include "IREM_DMZayavkaDv.h"
#include "UREM_DMZayavkaDv.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMZayavkaDvImpl)) TREM_DMZayavkaDvImpl : public IREM_DMZayavkaDv
{
public:
   TREM_DMZayavkaDvImpl();
   ~TREM_DMZayavkaDvImpl();
   TREM_DMZayavkaDv * Object;
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

//IREM_DMZayavkaDv
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

   virtual TFIBLargeIntField * get_TableID_REM_Z_DV(void);
   virtual void set_TableID_REM_Z_DV(TFIBLargeIntField * TableID_REM_Z_DV);

   virtual TFIBWideStringField * get_TableGID_REM_Z_DV(void);
   virtual void set_TableGID_REM_Z_DV(TFIBWideStringField * TableGID_REM_Z_DV);

   virtual TFIBDateTimeField * get_TablePOS_REM_Z_DV(void);
   virtual void set_TablePOS_REM_Z_DV(TFIBDateTimeField * TablePOS_REM_Z_DV);

   virtual TFIBLargeIntField * get_TableIDZ_REM_Z_DV(void);
   virtual void set_TableIDZ_REM_Z_DV(TFIBLargeIntField * TableIDZ_REM_Z_DV);

   virtual TFIBSmallIntField * get_TableOPER_REM_Z_DV(void);
   virtual void set_TableOPER_REM_Z_DV(TFIBSmallIntField * TableOPER_REM_Z_DV);

   virtual TFIBLargeIntField * get_TableIDSOST_REM_Z_DV(void);
   virtual void set_TableIDSOST_REM_Z_DV(TFIBLargeIntField * TableIDSOST_REM_Z_DV);

   virtual TFIBLargeIntField * get_TableIDTREMONT_REM_Z_DV(void);
   virtual void set_TableIDTREMONT_REM_Z_DV(TFIBLargeIntField * TableIDTREMONT_REM_Z_DV);

   virtual TFIBLargeIntField * get_TableIDUSER_REM_Z_DV(void);
   virtual void set_TableIDUSER_REM_Z_DV(TFIBLargeIntField * TableIDUSER_REM_Z_DV);

   virtual TFIBBCDField * get_TableSUM_REM_Z_DV(void);
   virtual void set_TableSUM_REM_Z_DV(TFIBBCDField * TableSUM_REM_Z_DV);

   virtual TFIBDateField * get_TableSROK_REM_Z_DV(void);
   virtual void set_TableSROK_REM_Z_DV(TFIBDateField * TableSROK_REM_Z_DV);

   virtual TFIBSmallIntField * get_TableOUT_REM_Z_DV(void);
   virtual void set_TableOUT_REM_Z_DV(TFIBSmallIntField * TableOUT_REM_Z_DV);

   virtual TFIBLargeIntField * get_TableIDTECSKL_REM_Z_DV(void);
   virtual void set_TableIDTECSKL_REM_Z_DV(TFIBLargeIntField * TableIDTECSKL_REM_Z_DV);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_Z_DV(void);
   virtual void set_TableIDBASE_REM_Z_DV(TFIBLargeIntField * TableIDBASE_REM_Z_DV);

   virtual TFIBWideStringField * get_TableNAME_STREMONT(void);
   virtual void set_TableNAME_STREMONT(TFIBWideStringField * TableNAME_STREMONT);

   virtual TFIBWideStringField * get_TableNAME_REMSSOST(void);
   virtual void set_TableNAME_REMSSOST(TFIBWideStringField * TableNAME_REMSSOST);

   virtual TFIBWideStringField * get_TableNAME_SKLAD_TEC(void);
   virtual void set_TableNAME_SKLAD_TEC(TFIBWideStringField * TableNAME_SKLAD_TEC);

   virtual TFIBWideStringField * get_TableNAME_USER(void);
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER);

   virtual TFIBLargeIntField * get_ElementID_REM_Z_DV(void);
   virtual void set_ElementID_REM_Z_DV(TFIBLargeIntField * ElementID_REM_Z_DV);

   virtual TFIBWideStringField * get_ElementGID_REM_Z_DV(void);
   virtual void set_ElementGID_REM_Z_DV(TFIBWideStringField * ElementGID_REM_Z_DV);

   virtual TFIBDateTimeField * get_ElementPOS_REM_Z_DV(void);
   virtual void set_ElementPOS_REM_Z_DV(TFIBDateTimeField * ElementPOS_REM_Z_DV);

   virtual TFIBLargeIntField * get_ElementIDZ_REM_Z_DV(void);
   virtual void set_ElementIDZ_REM_Z_DV(TFIBLargeIntField * ElementIDZ_REM_Z_DV);

   virtual TFIBSmallIntField * get_ElementOPER_REM_Z_DV(void);
   virtual void set_ElementOPER_REM_Z_DV(TFIBSmallIntField * ElementOPER_REM_Z_DV);

   virtual TFIBLargeIntField * get_ElementIDSOST_REM_Z_DV(void);
   virtual void set_ElementIDSOST_REM_Z_DV(TFIBLargeIntField * ElementIDSOST_REM_Z_DV);

   virtual TFIBLargeIntField * get_ElementIDTREMONT_REM_Z_DV(void);
   virtual void set_ElementIDTREMONT_REM_Z_DV(TFIBLargeIntField * ElementIDTREMONT_REM_Z_DV);

   virtual TFIBLargeIntField * get_ElementIDUSER_REM_Z_DV(void);
   virtual void set_ElementIDUSER_REM_Z_DV(TFIBLargeIntField * ElementIDUSER_REM_Z_DV);

   virtual TFIBBCDField * get_ElementSUM_REM_Z_DV(void);
   virtual void set_ElementSUM_REM_Z_DV(TFIBBCDField * ElementSUM_REM_Z_DV);

   virtual TFIBDateField * get_ElementSROK_REM_Z_DV(void);
   virtual void set_ElementSROK_REM_Z_DV(TFIBDateField * ElementSROK_REM_Z_DV);

   virtual TFIBSmallIntField * get_ElementOUT_REM_Z_DV(void);
   virtual void set_ElementOUT_REM_Z_DV(TFIBSmallIntField * ElementOUT_REM_Z_DV);

   virtual TFIBLargeIntField * get_ElementIDTECSKL_REM_Z_DV(void);
   virtual void set_ElementIDTECSKL_REM_Z_DV(TFIBLargeIntField * ElementIDTECSKL_REM_Z_DV);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_Z_DV(void);
   virtual void set_ElementIDBASE_REM_Z_DV(TFIBLargeIntField * ElementIDBASE_REM_Z_DV);

   virtual TFIBWideStringField * get_ElementNAME_STREMONT(void);
   virtual void set_ElementNAME_STREMONT(TFIBWideStringField * ElementNAME_STREMONT);

   virtual TFIBWideStringField * get_ElementNAME_REMSSOST(void);
   virtual void set_ElementNAME_REMSSOST(TFIBWideStringField * ElementNAME_REMSSOST);

   virtual TFIBWideStringField * get_ElementNAME_SKLAD_TEC(void);
   virtual void set_ElementNAME_SKLAD_TEC(TFIBWideStringField * ElementNAME_SKLAD_TEC);

   virtual TFIBWideStringField * get_ElementNAME_USER(void);
   virtual void set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER);

   virtual bool get_Prosmotr(void);
   virtual void set_Prosmotr(bool Prosmotr);

   virtual __int64 get_IdZ(void);
   virtual void set_IdZ(__int64 IdZ);

   virtual __int64 get_IdBaseZayavki(void);
   virtual void set_IdBaseZayavki(__int64 IdBaseZayavki);

   virtual void OpenTable(__int64 id_z);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(__int64 id_z);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 GetIDElement(UnicodeString gid);
   virtual UnicodeString GetGIDElement(__int64 id);
   virtual bool AddRecordDv(TDateTime pos,	__int64 id_z,int oper,	__int64 id_sost,__int64 id_type_remont,	__int64 id_user,__int64 id_tec_sklad,double sum,TDate date,int out);
};
#define CLSID_TREM_DMZayavkaDvImpl __uuidof(TREM_DMZayavkaDvImpl)
#endif
