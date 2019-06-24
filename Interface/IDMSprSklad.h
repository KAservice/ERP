#ifndef UIDMSprSkladH
#define UIDMSprSkladH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprSklad)) IDMSprSklad : public IMainInterface
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

   __property TFIBIntegerField * TableTSKLAD = {read = get_TableTSKLAD , write = set_TableTSKLAD};
   virtual TFIBIntegerField * get_TableTSKLAD(void)=0;
   virtual void set_TableTSKLAD(TFIBIntegerField * TableTSKLAD)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBIntegerField * ElementTSKLAD = {read = get_ElementTSKLAD , write = set_ElementTSKLAD};
   virtual TFIBIntegerField * get_ElementTSKLAD(void)=0;
   virtual void set_ElementTSKLAD(TFIBIntegerField * ElementTSKLAD)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBWideStringField * TableNAMESKLAD = {read = get_TableNAMESKLAD , write = set_TableNAMESKLAD};
   virtual TFIBWideStringField * get_TableNAMESKLAD(void)=0;
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)=0;

   __property TFIBWideStringField * TableMOLSKLAD = {read = get_TableMOLSKLAD , write = set_TableMOLSKLAD};
   virtual TFIBWideStringField * get_TableMOLSKLAD(void)=0;
   virtual void set_TableMOLSKLAD(TFIBWideStringField * TableMOLSKLAD)=0;

   __property TFIBWideStringField * TableADRSKLAD = {read = get_TableADRSKLAD , write = set_TableADRSKLAD};
   virtual TFIBWideStringField * get_TableADRSKLAD(void)=0;
   virtual void set_TableADRSKLAD(TFIBWideStringField * TableADRSKLAD)=0;

   __property TFIBWideStringField * TableGID_SSKLAD = {read = get_TableGID_SSKLAD , write = set_TableGID_SSKLAD};
   virtual TFIBWideStringField * get_TableGID_SSKLAD(void)=0;
   virtual void set_TableGID_SSKLAD(TFIBWideStringField * TableGID_SSKLAD)=0;

   __property TFIBWideStringField * ElementNAMESKLAD = {read = get_ElementNAMESKLAD , write = set_ElementNAMESKLAD};
   virtual TFIBWideStringField * get_ElementNAMESKLAD(void)=0;
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)=0;

   __property TFIBWideStringField * ElementMOLSKLAD = {read = get_ElementMOLSKLAD , write = set_ElementMOLSKLAD};
   virtual TFIBWideStringField * get_ElementMOLSKLAD(void)=0;
   virtual void set_ElementMOLSKLAD(TFIBWideStringField * ElementMOLSKLAD)=0;

   __property TFIBWideStringField * ElementADRSKLAD = {read = get_ElementADRSKLAD , write = set_ElementADRSKLAD};
   virtual TFIBWideStringField * get_ElementADRSKLAD(void)=0;
   virtual void set_ElementADRSKLAD(TFIBWideStringField * ElementADRSKLAD)=0;

   __property TFIBWideStringField * ElementGID_SSKLAD = {read = get_ElementGID_SSKLAD , write = set_ElementGID_SSKLAD};
   virtual TFIBWideStringField * get_ElementGID_SSKLAD(void)=0;
   virtual void set_ElementGID_SSKLAD(TFIBWideStringField * ElementGID_SSKLAD)=0;

   __property TFIBSmallIntField * ElementDBLUCHETALLNOM_SSKLAD = {read = get_ElementDBLUCHETALLNOM_SSKLAD , write = set_ElementDBLUCHETALLNOM_SSKLAD};
   virtual TFIBSmallIntField * get_ElementDBLUCHETALLNOM_SSKLAD(void)=0;
   virtual void set_ElementDBLUCHETALLNOM_SSKLAD(TFIBSmallIntField * ElementDBLUCHETALLNOM_SSKLAD)=0;

   __property TFIBSmallIntField * ElementDBLUCHET_SSKLAD = {read = get_ElementDBLUCHET_SSKLAD , write = set_ElementDBLUCHET_SSKLAD};
   virtual TFIBSmallIntField * get_ElementDBLUCHET_SSKLAD(void)=0;
   virtual void set_ElementDBLUCHET_SSKLAD(TFIBSmallIntField * ElementDBLUCHET_SSKLAD)=0;

   __property TFIBWideStringField * ElementPREFIKS_NUM_SSKLAD = {read = get_ElementPREFIKS_NUM_SSKLAD , write = set_ElementPREFIKS_NUM_SSKLAD};
   virtual TFIBWideStringField * get_ElementPREFIKS_NUM_SSKLAD(void)=0;
   virtual void set_ElementPREFIKS_NUM_SSKLAD(TFIBWideStringField * ElementPREFIKS_NUM_SSKLAD)=0;

   __property TFIBWideStringField * ElementPHONE_SSKLAD = {read = get_ElementPHONE_SSKLAD , write = set_ElementPHONE_SSKLAD};
   virtual TFIBWideStringField * get_ElementPHONE_SSKLAD(void)=0;
   virtual void set_ElementPHONE_SSKLAD(TFIBWideStringField * ElementPHONE_SSKLAD)=0;

   __property TFIBWideStringField * ElementEMAIL_SSKLAD = {read = get_ElementEMAIL_SSKLAD , write = set_ElementEMAIL_SSKLAD};
   virtual TFIBWideStringField * get_ElementEMAIL_SSKLAD(void)=0;
   virtual void set_ElementEMAIL_SSKLAD(TFIBWideStringField * ElementEMAIL_SSKLAD)=0;

   __property TFIBWideStringField * ElementVKONTAKTE_SSKLAD = {read = get_ElementVKONTAKTE_SSKLAD , write = set_ElementVKONTAKTE_SSKLAD};
   virtual TFIBWideStringField * get_ElementVKONTAKTE_SSKLAD(void)=0;
   virtual void set_ElementVKONTAKTE_SSKLAD(TFIBWideStringField * ElementVKONTAKTE_SSKLAD)=0;

   __property TFIBWideStringField * ElementWEBSITE_SSKLAD = {read = get_ElementWEBSITE_SSKLAD , write = set_ElementWEBSITE_SSKLAD};
   virtual TFIBWideStringField * get_ElementWEBSITE_SSKLAD(void)=0;
   virtual void set_ElementWEBSITE_SSKLAD(TFIBWideStringField * ElementWEBSITE_SSKLAD)=0;

   __property TFIBWideStringField * ElementDOPINFO_SSKLAD = {read = get_ElementDOPINFO_SSKLAD , write = set_ElementDOPINFO_SSKLAD};
   virtual TFIBWideStringField * get_ElementDOPINFO_SSKLAD(void)=0;
   virtual void set_ElementDOPINFO_SSKLAD(TFIBWideStringField * ElementDOPINFO_SSKLAD)=0;

   __property TFIBWideStringField * ElementREGIM_RABOTI_SSKLAD = {read = get_ElementREGIM_RABOTI_SSKLAD , write = set_ElementREGIM_RABOTI_SSKLAD};
   virtual TFIBWideStringField * get_ElementREGIM_RABOTI_SSKLAD(void)=0;
   virtual void set_ElementREGIM_RABOTI_SSKLAD(TFIBWideStringField * ElementREGIM_RABOTI_SSKLAD)=0;

   __property TFIBLargeIntField * TableIDSKLAD = {read = get_TableIDSKLAD , write = set_TableIDSKLAD};
   virtual TFIBLargeIntField * get_TableIDSKLAD(void)=0;
   virtual void set_TableIDSKLAD(TFIBLargeIntField * TableIDSKLAD)=0;

   __property TFIBLargeIntField * TableIDBASE_SSKLAD = {read = get_TableIDBASE_SSKLAD , write = set_TableIDBASE_SSKLAD};
   virtual TFIBLargeIntField * get_TableIDBASE_SSKLAD(void)=0;
   virtual void set_TableIDBASE_SSKLAD(TFIBLargeIntField * TableIDBASE_SSKLAD)=0;

   __property TFIBSmallIntField * TableDBLUCHETALLNOM_SSKLAD = {read = get_TableDBLUCHETALLNOM_SSKLAD , write = set_TableDBLUCHETALLNOM_SSKLAD};
   virtual TFIBSmallIntField * get_TableDBLUCHETALLNOM_SSKLAD(void)=0;
   virtual void set_TableDBLUCHETALLNOM_SSKLAD(TFIBSmallIntField * TableDBLUCHETALLNOM_SSKLAD)=0;

   __property TFIBSmallIntField * TableDBLUCHET_SSKLAD = {read = get_TableDBLUCHET_SSKLAD , write = set_TableDBLUCHET_SSKLAD};
   virtual TFIBSmallIntField * get_TableDBLUCHET_SSKLAD(void)=0;
   virtual void set_TableDBLUCHET_SSKLAD(TFIBSmallIntField * TableDBLUCHET_SSKLAD)=0;

   __property TFIBWideStringField * TablePREFIKS_NUM_SSKLAD = {read = get_TablePREFIKS_NUM_SSKLAD , write = set_TablePREFIKS_NUM_SSKLAD};
   virtual TFIBWideStringField * get_TablePREFIKS_NUM_SSKLAD(void)=0;
   virtual void set_TablePREFIKS_NUM_SSKLAD(TFIBWideStringField * TablePREFIKS_NUM_SSKLAD)=0;

   __property TFIBWideStringField * TablePHONE_SSKLAD = {read = get_TablePHONE_SSKLAD , write = set_TablePHONE_SSKLAD};
   virtual TFIBWideStringField * get_TablePHONE_SSKLAD(void)=0;
   virtual void set_TablePHONE_SSKLAD(TFIBWideStringField * TablePHONE_SSKLAD)=0;

   __property TFIBWideStringField * TableEMAIL_SSKLAD = {read = get_TableEMAIL_SSKLAD , write = set_TableEMAIL_SSKLAD};
   virtual TFIBWideStringField * get_TableEMAIL_SSKLAD(void)=0;
   virtual void set_TableEMAIL_SSKLAD(TFIBWideStringField * TableEMAIL_SSKLAD)=0;

   __property TFIBWideStringField * TableVKONTAKTE_SSKLAD = {read = get_TableVKONTAKTE_SSKLAD , write = set_TableVKONTAKTE_SSKLAD};
   virtual TFIBWideStringField * get_TableVKONTAKTE_SSKLAD(void)=0;
   virtual void set_TableVKONTAKTE_SSKLAD(TFIBWideStringField * TableVKONTAKTE_SSKLAD)=0;

   __property TFIBWideStringField * TableWEBSITE_SSKLAD = {read = get_TableWEBSITE_SSKLAD , write = set_TableWEBSITE_SSKLAD};
   virtual TFIBWideStringField * get_TableWEBSITE_SSKLAD(void)=0;
   virtual void set_TableWEBSITE_SSKLAD(TFIBWideStringField * TableWEBSITE_SSKLAD)=0;

   __property TFIBWideStringField * TableDOPINFO_SSKLAD = {read = get_TableDOPINFO_SSKLAD , write = set_TableDOPINFO_SSKLAD};
   virtual TFIBWideStringField * get_TableDOPINFO_SSKLAD(void)=0;
   virtual void set_TableDOPINFO_SSKLAD(TFIBWideStringField * TableDOPINFO_SSKLAD)=0;

   __property TFIBWideStringField * TableREGIM_RABOTI_SSKLAD = {read = get_TableREGIM_RABOTI_SSKLAD , write = set_TableREGIM_RABOTI_SSKLAD};
   virtual TFIBWideStringField * get_TableREGIM_RABOTI_SSKLAD(void)=0;
   virtual void set_TableREGIM_RABOTI_SSKLAD(TFIBWideStringField * TableREGIM_RABOTI_SSKLAD)=0;

   __property TFIBLargeIntField * ElementIDSKLAD = {read = get_ElementIDSKLAD , write = set_ElementIDSKLAD};
   virtual TFIBLargeIntField * get_ElementIDSKLAD(void)=0;
   virtual void set_ElementIDSKLAD(TFIBLargeIntField * ElementIDSKLAD)=0;

   __property TFIBLargeIntField * ElementIDBASE_SSKLAD = {read = get_ElementIDBASE_SSKLAD , write = set_ElementIDBASE_SSKLAD};
   virtual TFIBLargeIntField * get_ElementIDBASE_SSKLAD(void)=0;
   virtual void set_ElementIDBASE_SSKLAD(TFIBLargeIntField * ElementIDBASE_SSKLAD)=0;

   virtual void OpenTable(void)=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
   virtual __int64 GetIDElement(String gid)=0;
   virtual AnsiString GetGIDElement(__int64 id)=0;
   virtual int GetIndexElementaPoID(__int64 id)=0;
};
#define IID_IDMSprSklad __uuidof(IDMSprSklad)
#endif
