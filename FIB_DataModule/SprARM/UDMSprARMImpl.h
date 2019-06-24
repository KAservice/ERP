#ifndef UDMSprARMImplH
#define UDMSprARMImplH
#include "IDMSprARM.h"
#include "UDMSprARM.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprARMImpl)) TDMSprARMImpl : public IDMSprARM
{
public:
   TDMSprARMImpl();
   ~TDMSprARMImpl();
   TDMSprARM * Object;
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

//IDMSprARM
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBLargeIntField * get_TableID_SARM(void);
   virtual void set_TableID_SARM(TFIBLargeIntField * TableID_SARM);

   virtual TFIBWideStringField * get_TableGID_SARM(void);
   virtual void set_TableGID_SARM(TFIBWideStringField * TableGID_SARM);

   virtual TFIBWideStringField * get_TableNAME_SARM(void);
   virtual void set_TableNAME_SARM(TFIBWideStringField * TableNAME_SARM);

   virtual TFIBIntegerField * get_TableCODE_SARM(void);
   virtual void set_TableCODE_SARM(TFIBIntegerField * TableCODE_SARM);

   virtual TFIBLargeIntField * get_TableIDFIRM_SARM(void);
   virtual void set_TableIDFIRM_SARM(TFIBLargeIntField * TableIDFIRM_SARM);

   virtual TFIBLargeIntField * get_TableIDSKLAD_SARM(void);
   virtual void set_TableIDSKLAD_SARM(TFIBLargeIntField * TableIDSKLAD_SARM);

   virtual TFIBLargeIntField * get_TableIDPODR_SARM(void);
   virtual void set_TableIDPODR_SARM(TFIBLargeIntField * TableIDPODR_SARM);

   virtual TFIBLargeIntField * get_TableIDKKM_SARM(void);
   virtual void set_TableIDKKM_SARM(TFIBLargeIntField * TableIDKKM_SARM);

   virtual TFIBWideStringField * get_TableSTRPAR_SARM(void);
   virtual void set_TableSTRPAR_SARM(TFIBWideStringField * TableSTRPAR_SARM);

   virtual TFIBWideStringField * get_TablePREFIKS_SARM(void);
   virtual void set_TablePREFIKS_SARM(TFIBWideStringField * TablePREFIKS_SARM);

   virtual TFIBLargeIntField * get_TableIDBASE_SARM(void);
   virtual void set_TableIDBASE_SARM(TFIBLargeIntField * TableIDBASE_SARM);

   virtual TFIBLargeIntField * get_TableIDACTCATEGORY_SARM(void);
   virtual void set_TableIDACTCATEGORY_SARM(TFIBLargeIntField * TableIDACTCATEGORY_SARM);

   virtual TFIBLargeIntField * get_ElementID_SARM(void);
   virtual void set_ElementID_SARM(TFIBLargeIntField * ElementID_SARM);

   virtual TFIBWideStringField * get_ElementGID_SARM(void);
   virtual void set_ElementGID_SARM(TFIBWideStringField * ElementGID_SARM);

   virtual TFIBWideStringField * get_ElementNAME_SARM(void);
   virtual void set_ElementNAME_SARM(TFIBWideStringField * ElementNAME_SARM);

   virtual TFIBIntegerField * get_ElementCODE_SARM(void);
   virtual void set_ElementCODE_SARM(TFIBIntegerField * ElementCODE_SARM);

   virtual TFIBLargeIntField * get_ElementIDFIRM_SARM(void);
   virtual void set_ElementIDFIRM_SARM(TFIBLargeIntField * ElementIDFIRM_SARM);

   virtual TFIBLargeIntField * get_ElementIDSKLAD_SARM(void);
   virtual void set_ElementIDSKLAD_SARM(TFIBLargeIntField * ElementIDSKLAD_SARM);

   virtual TFIBLargeIntField * get_ElementIDPODR_SARM(void);
   virtual void set_ElementIDPODR_SARM(TFIBLargeIntField * ElementIDPODR_SARM);

   virtual TFIBLargeIntField * get_ElementIDKKM_SARM(void);
   virtual void set_ElementIDKKM_SARM(TFIBLargeIntField * ElementIDKKM_SARM);

   virtual TFIBWideStringField * get_ElementSTRPAR_SARM(void);
   virtual void set_ElementSTRPAR_SARM(TFIBWideStringField * ElementSTRPAR_SARM);

   virtual TFIBWideStringField * get_ElementPREFIKS_SARM(void);
   virtual void set_ElementPREFIKS_SARM(TFIBWideStringField * ElementPREFIKS_SARM);

   virtual TFIBLargeIntField * get_ElementIDBASE_SARM(void);
   virtual void set_ElementIDBASE_SARM(TFIBLargeIntField * ElementIDBASE_SARM);

   virtual TFIBLargeIntField * get_ElementIDACTCATEGORY_SARM(void);
   virtual void set_ElementIDACTCATEGORY_SARM(TFIBLargeIntField * ElementIDACTCATEGORY_SARM);

   virtual TFIBWideStringField * get_ElementNAMEFIRM(void);
   virtual void set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM);

   virtual TFIBWideStringField * get_ElementNAMESKLAD(void);
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD);

   virtual TFIBWideStringField * get_ElementNAMEKKM(void);
   virtual void set_ElementNAMEKKM(TFIBWideStringField * ElementNAMEKKM);

   virtual TFIBWideStringField * get_ElementNAMEPOD(void);
   virtual void set_ElementNAMEPOD(TFIBWideStringField * ElementNAMEPOD);

   virtual TFIBLargeIntField * get_ElementIDTPRICEPOD(void);
   virtual void set_ElementIDTPRICEPOD(TFIBLargeIntField * ElementIDTPRICEPOD);

   virtual TFIBWideStringField * get_ElementNAME_TPRICE(void);
   virtual void set_ElementNAME_TPRICE(TFIBWideStringField * ElementNAME_TPRICE);

   virtual TFIBWideStringField * get_ElementNAME_SINFBASE_OBMEN(void);
   virtual void set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN);

   virtual TFIBWideStringField * get_ElementNAME_REM_SACTCATEGORY(void);
   virtual void set_ElementNAME_REM_SACTCATEGORY(TFIBWideStringField * ElementNAME_REM_SACTCATEGORY);

   virtual bool get_flSaveElement(void);
   virtual void set_flSaveElement(bool flSaveElement);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
   virtual int FindPoCodu(int code);
   virtual int FindPoName(String name);
   virtual AnsiString GetGIDElement(__int64 id);
   virtual AnsiString GetParameter(AnsiString parameter);
   virtual int GetMaxCode(void);
};
#define CLSID_TDMSprARMImpl __uuidof(TDMSprARMImpl)
#endif
