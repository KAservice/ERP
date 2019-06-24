#ifndef UIDMSprObjectH
#define UIDMSprObjectH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprObject)) IDMSprObject : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBDataSet * Element = {read = get_Element , write = set_Element};
   virtual TpFIBDataSet * get_Element(void)=0;
   virtual void set_Element(TpFIBDataSet * Element)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBLargeIntField * TableID_SOBJECT = {read = get_TableID_SOBJECT , write = set_TableID_SOBJECT};
   virtual TFIBLargeIntField * get_TableID_SOBJECT(void)=0;
   virtual void set_TableID_SOBJECT(TFIBLargeIntField * TableID_SOBJECT)=0;

   __property TFIBWideStringField * TableNAME_SOBJECT = {read = get_TableNAME_SOBJECT , write = set_TableNAME_SOBJECT};
   virtual TFIBWideStringField * get_TableNAME_SOBJECT(void)=0;
   virtual void set_TableNAME_SOBJECT(TFIBWideStringField * TableNAME_SOBJECT)=0;

   __property TFIBLargeIntField * TableIDINFBASE_SOBJECT = {read = get_TableIDINFBASE_SOBJECT , write = set_TableIDINFBASE_SOBJECT};
   virtual TFIBLargeIntField * get_TableIDINFBASE_SOBJECT(void)=0;
   virtual void set_TableIDINFBASE_SOBJECT(TFIBLargeIntField * TableIDINFBASE_SOBJECT)=0;

   __property TFIBLargeIntField * TableIDFIRM_SOBJECT = {read = get_TableIDFIRM_SOBJECT , write = set_TableIDFIRM_SOBJECT};
   virtual TFIBLargeIntField * get_TableIDFIRM_SOBJECT(void)=0;
   virtual void set_TableIDFIRM_SOBJECT(TFIBLargeIntField * TableIDFIRM_SOBJECT)=0;

   __property TFIBLargeIntField * TableIDSKLAD_SOBJECT = {read = get_TableIDSKLAD_SOBJECT , write = set_TableIDSKLAD_SOBJECT};
   virtual TFIBLargeIntField * get_TableIDSKLAD_SOBJECT(void)=0;
   virtual void set_TableIDSKLAD_SOBJECT(TFIBLargeIntField * TableIDSKLAD_SOBJECT)=0;

   __property TFIBLargeIntField * TableIDKASSA_SOBJECT = {read = get_TableIDKASSA_SOBJECT , write = set_TableIDKASSA_SOBJECT};
   virtual TFIBLargeIntField * get_TableIDKASSA_SOBJECT(void)=0;
   virtual void set_TableIDKASSA_SOBJECT(TFIBLargeIntField * TableIDKASSA_SOBJECT)=0;

   __property TFIBLargeIntField * TableIDPODR_SOBJECT = {read = get_TableIDPODR_SOBJECT , write = set_TableIDPODR_SOBJECT};
   virtual TFIBLargeIntField * get_TableIDPODR_SOBJECT(void)=0;
   virtual void set_TableIDPODR_SOBJECT(TFIBLargeIntField * TableIDPODR_SOBJECT)=0;

   __property TFIBWideStringField * TableNAME_SINFBASE_OBMEN = {read = get_TableNAME_SINFBASE_OBMEN , write = set_TableNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * TableNAMEFIRM = {read = get_TableNAMEFIRM , write = set_TableNAMEFIRM};
   virtual TFIBWideStringField * get_TableNAMEFIRM(void)=0;
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)=0;

   __property TFIBWideStringField * TableNAMESKLAD = {read = get_TableNAMESKLAD , write = set_TableNAMESKLAD};
   virtual TFIBWideStringField * get_TableNAMESKLAD(void)=0;
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)=0;

   __property TFIBWideStringField * TableNAMEKKM = {read = get_TableNAMEKKM , write = set_TableNAMEKKM};
   virtual TFIBWideStringField * get_TableNAMEKKM(void)=0;
   virtual void set_TableNAMEKKM(TFIBWideStringField * TableNAMEKKM)=0;

   __property TFIBWideStringField * TableNAMEPOD = {read = get_TableNAMEPOD , write = set_TableNAMEPOD};
   virtual TFIBWideStringField * get_TableNAMEPOD(void)=0;
   virtual void set_TableNAMEPOD(TFIBWideStringField * TableNAMEPOD)=0;

   __property TFIBLargeIntField * ElementID_SOBJECT = {read = get_ElementID_SOBJECT , write = set_ElementID_SOBJECT};
   virtual TFIBLargeIntField * get_ElementID_SOBJECT(void)=0;
   virtual void set_ElementID_SOBJECT(TFIBLargeIntField * ElementID_SOBJECT)=0;

   __property TFIBLargeIntField * ElementIDBASE_SOBJECT = {read = get_ElementIDBASE_SOBJECT , write = set_ElementIDBASE_SOBJECT};
   virtual TFIBLargeIntField * get_ElementIDBASE_SOBJECT(void)=0;
   virtual void set_ElementIDBASE_SOBJECT(TFIBLargeIntField * ElementIDBASE_SOBJECT)=0;

   __property TFIBWideStringField * ElementNAME_SOBJECT = {read = get_ElementNAME_SOBJECT , write = set_ElementNAME_SOBJECT};
   virtual TFIBWideStringField * get_ElementNAME_SOBJECT(void)=0;
   virtual void set_ElementNAME_SOBJECT(TFIBWideStringField * ElementNAME_SOBJECT)=0;

   __property TFIBLargeIntField * ElementIDINFBASE_SOBJECT = {read = get_ElementIDINFBASE_SOBJECT , write = set_ElementIDINFBASE_SOBJECT};
   virtual TFIBLargeIntField * get_ElementIDINFBASE_SOBJECT(void)=0;
   virtual void set_ElementIDINFBASE_SOBJECT(TFIBLargeIntField * ElementIDINFBASE_SOBJECT)=0;

   __property TFIBLargeIntField * ElementIDFIRM_SOBJECT = {read = get_ElementIDFIRM_SOBJECT , write = set_ElementIDFIRM_SOBJECT};
   virtual TFIBLargeIntField * get_ElementIDFIRM_SOBJECT(void)=0;
   virtual void set_ElementIDFIRM_SOBJECT(TFIBLargeIntField * ElementIDFIRM_SOBJECT)=0;

   __property TFIBLargeIntField * ElementIDSKLAD_SOBJECT = {read = get_ElementIDSKLAD_SOBJECT , write = set_ElementIDSKLAD_SOBJECT};
   virtual TFIBLargeIntField * get_ElementIDSKLAD_SOBJECT(void)=0;
   virtual void set_ElementIDSKLAD_SOBJECT(TFIBLargeIntField * ElementIDSKLAD_SOBJECT)=0;

   __property TFIBLargeIntField * ElementIDKASSA_SOBJECT = {read = get_ElementIDKASSA_SOBJECT , write = set_ElementIDKASSA_SOBJECT};
   virtual TFIBLargeIntField * get_ElementIDKASSA_SOBJECT(void)=0;
   virtual void set_ElementIDKASSA_SOBJECT(TFIBLargeIntField * ElementIDKASSA_SOBJECT)=0;

   __property TFIBLargeIntField * ElementIDPODR_SOBJECT = {read = get_ElementIDPODR_SOBJECT , write = set_ElementIDPODR_SOBJECT};
   virtual TFIBLargeIntField * get_ElementIDPODR_SOBJECT(void)=0;
   virtual void set_ElementIDPODR_SOBJECT(TFIBLargeIntField * ElementIDPODR_SOBJECT)=0;

   __property TFIBWideStringField * ElementNAME_SINFBASE_OBMEN = {read = get_ElementNAME_SINFBASE_OBMEN , write = set_ElementNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_ElementNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * ElementNAMEFIRM = {read = get_ElementNAMEFIRM , write = set_ElementNAMEFIRM};
   virtual TFIBWideStringField * get_ElementNAMEFIRM(void)=0;
   virtual void set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM)=0;

   __property TFIBWideStringField * ElementNAMESKLAD = {read = get_ElementNAMESKLAD , write = set_ElementNAMESKLAD};
   virtual TFIBWideStringField * get_ElementNAMESKLAD(void)=0;
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)=0;

   __property TFIBWideStringField * ElementNAMEKKM = {read = get_ElementNAMEKKM , write = set_ElementNAMEKKM};
   virtual TFIBWideStringField * get_ElementNAMEKKM(void)=0;
   virtual void set_ElementNAMEKKM(TFIBWideStringField * ElementNAMEKKM)=0;

   __property TFIBWideStringField * ElementNAMEPOD = {read = get_ElementNAMEPOD , write = set_ElementNAMEPOD};
   virtual TFIBWideStringField * get_ElementNAMEPOD(void)=0;
   virtual void set_ElementNAMEPOD(TFIBWideStringField * ElementNAMEPOD)=0;

   virtual bool OpenTable(void)=0;
   virtual bool  OpenElement(__int64 id)=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 GetIdElementPoName(UnicodeString   name)=0;
   virtual int GetIndexInTablePoId(__int64 id_element)=0;
   virtual __int64 GetIdElementPoGid(UnicodeString gid)=0;
   virtual UnicodeString GetGidElementPoId(__int64 id)=0;
};
#define IID_IDMSprObject __uuidof(IDMSprObject)
#endif
