#ifndef UIDMSprProducerH
#define UIDMSprProducerH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprProducer)) IDMSprProducer : public IMainInterface
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

   __property TFIBLargeIntField * TableID_SPRODUCER = {read = get_TableID_SPRODUCER , write = set_TableID_SPRODUCER};
   virtual TFIBLargeIntField * get_TableID_SPRODUCER(void)=0;
   virtual void set_TableID_SPRODUCER(TFIBLargeIntField * TableID_SPRODUCER)=0;

   __property TFIBLargeIntField * TableIDBASE_SPRODUCER = {read = get_TableIDBASE_SPRODUCER , write = set_TableIDBASE_SPRODUCER};
   virtual TFIBLargeIntField * get_TableIDBASE_SPRODUCER(void)=0;
   virtual void set_TableIDBASE_SPRODUCER(TFIBLargeIntField * TableIDBASE_SPRODUCER)=0;

   __property TFIBWideStringField * TableGID_SPRODUCER = {read = get_TableGID_SPRODUCER , write = set_TableGID_SPRODUCER};
   virtual TFIBWideStringField * get_TableGID_SPRODUCER(void)=0;
   virtual void set_TableGID_SPRODUCER(TFIBWideStringField * TableGID_SPRODUCER)=0;

   __property TFIBWideStringField * TableNAME_SPRODUCER = {read = get_TableNAME_SPRODUCER , write = set_TableNAME_SPRODUCER};
   virtual TFIBWideStringField * get_TableNAME_SPRODUCER(void)=0;
   virtual void set_TableNAME_SPRODUCER(TFIBWideStringField * TableNAME_SPRODUCER)=0;

   __property TFIBLargeIntField * TableIDKLIENT_SPRODUCER = {read = get_TableIDKLIENT_SPRODUCER , write = set_TableIDKLIENT_SPRODUCER};
   virtual TFIBLargeIntField * get_TableIDKLIENT_SPRODUCER(void)=0;
   virtual void set_TableIDKLIENT_SPRODUCER(TFIBLargeIntField * TableIDKLIENT_SPRODUCER)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * TableINNKLIENT = {read = get_TableINNKLIENT , write = set_TableINNKLIENT};
   virtual TFIBWideStringField * get_TableINNKLIENT(void)=0;
   virtual void set_TableINNKLIENT(TFIBWideStringField * TableINNKLIENT)=0;

   __property TFIBLargeIntField * ElementID_SPRODUCER = {read = get_ElementID_SPRODUCER , write = set_ElementID_SPRODUCER};
   virtual TFIBLargeIntField * get_ElementID_SPRODUCER(void)=0;
   virtual void set_ElementID_SPRODUCER(TFIBLargeIntField * ElementID_SPRODUCER)=0;

   __property TFIBLargeIntField * ElementIDBASE_SPRODUCER = {read = get_ElementIDBASE_SPRODUCER , write = set_ElementIDBASE_SPRODUCER};
   virtual TFIBLargeIntField * get_ElementIDBASE_SPRODUCER(void)=0;
   virtual void set_ElementIDBASE_SPRODUCER(TFIBLargeIntField * ElementIDBASE_SPRODUCER)=0;

   __property TFIBWideStringField * ElementGID_SPRODUCER = {read = get_ElementGID_SPRODUCER , write = set_ElementGID_SPRODUCER};
   virtual TFIBWideStringField * get_ElementGID_SPRODUCER(void)=0;
   virtual void set_ElementGID_SPRODUCER(TFIBWideStringField * ElementGID_SPRODUCER)=0;

   __property TFIBWideStringField * ElementNAME_SPRODUCER = {read = get_ElementNAME_SPRODUCER , write = set_ElementNAME_SPRODUCER};
   virtual TFIBWideStringField * get_ElementNAME_SPRODUCER(void)=0;
   virtual void set_ElementNAME_SPRODUCER(TFIBWideStringField * ElementNAME_SPRODUCER)=0;

   __property TFIBLargeIntField * ElementIDKLIENT_SPRODUCER = {read = get_ElementIDKLIENT_SPRODUCER , write = set_ElementIDKLIENT_SPRODUCER};
   virtual TFIBLargeIntField * get_ElementIDKLIENT_SPRODUCER(void)=0;
   virtual void set_ElementIDKLIENT_SPRODUCER(TFIBLargeIntField * ElementIDKLIENT_SPRODUCER)=0;

   __property TFIBWideStringField * ElementNAMEKLIENT = {read = get_ElementNAMEKLIENT , write = set_ElementNAMEKLIENT};
   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void)=0;
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)=0;

   __property TFIBLargeIntField * ElementIDPOST_ZIP_SPRODUCER = {read = get_ElementIDPOST_ZIP_SPRODUCER , write = set_ElementIDPOST_ZIP_SPRODUCER};
   virtual TFIBLargeIntField * get_ElementIDPOST_ZIP_SPRODUCER(void)=0;
   virtual void set_ElementIDPOST_ZIP_SPRODUCER(TFIBLargeIntField * ElementIDPOST_ZIP_SPRODUCER)=0;

   __property TFIBWideStringField * ElementPOST_ZIP_NAME = {read = get_ElementPOST_ZIP_NAME , write = set_ElementPOST_ZIP_NAME};
   virtual TFIBWideStringField * get_ElementPOST_ZIP_NAME(void)=0;
   virtual void set_ElementPOST_ZIP_NAME(TFIBWideStringField * ElementPOST_ZIP_NAME)=0;

   __property TFIBDateTimeField * TablePOSZAGRNOM_SPRODUCER = {read = get_TablePOSZAGRNOM_SPRODUCER , write = set_TablePOSZAGRNOM_SPRODUCER};
   virtual TFIBDateTimeField * get_TablePOSZAGRNOM_SPRODUCER(void)=0;
   virtual void set_TablePOSZAGRNOM_SPRODUCER(TFIBDateTimeField * TablePOSZAGRNOM_SPRODUCER)=0;

   __property TFIBDateTimeField * ElementPOSZAGRNOM_SPRODUCER = {read = get_ElementPOSZAGRNOM_SPRODUCER , write = set_ElementPOSZAGRNOM_SPRODUCER};
   virtual TFIBDateTimeField * get_ElementPOSZAGRNOM_SPRODUCER(void)=0;
   virtual void set_ElementPOSZAGRNOM_SPRODUCER(TFIBDateTimeField * ElementPOSZAGRNOM_SPRODUCER)=0;

   __property TFIBIntegerField * ElementTYPE_POISK_SPRNOM_SPRODUCER = {read = get_ElementTYPE_POISK_SPRNOM_SPRODUCER , write = set_ElementTYPE_POISK_SPRNOM_SPRODUCER};
   virtual TFIBIntegerField * get_ElementTYPE_POISK_SPRNOM_SPRODUCER(void)=0;
   virtual void set_ElementTYPE_POISK_SPRNOM_SPRODUCER(TFIBIntegerField * ElementTYPE_POISK_SPRNOM_SPRODUCER)=0;

   __property TFIBLargeIntField * ElementIDINETCAT_USL_SPRODUCER = {read = get_ElementIDINETCAT_USL_SPRODUCER , write = set_ElementIDINETCAT_USL_SPRODUCER};
   virtual TFIBLargeIntField * get_ElementIDINETCAT_USL_SPRODUCER(void)=0;
   virtual void set_ElementIDINETCAT_USL_SPRODUCER(TFIBLargeIntField * ElementIDINETCAT_USL_SPRODUCER)=0;

   __property TFIBLargeIntField * ElementIDGRPINETCAT_USL_SPRODUCER = {read = get_ElementIDGRPINETCAT_USL_SPRODUCER , write = set_ElementIDGRPINETCAT_USL_SPRODUCER};
   virtual TFIBLargeIntField * get_ElementIDGRPINETCAT_USL_SPRODUCER(void)=0;
   virtual void set_ElementIDGRPINETCAT_USL_SPRODUCER(TFIBLargeIntField * ElementIDGRPINETCAT_USL_SPRODUCER)=0;

   __property TFIBWideStringField * ElementNAME_SINETCATALOG = {read = get_ElementNAME_SINETCATALOG , write = set_ElementNAME_SINETCATALOG};
   virtual TFIBWideStringField * get_ElementNAME_SINETCATALOG(void)=0;
   virtual void set_ElementNAME_SINETCATALOG(TFIBWideStringField * ElementNAME_SINETCATALOG)=0;

   __property TFIBWideStringField * ElementNAME_SNOMINETCAT_GRP = {read = get_ElementNAME_SNOMINETCAT_GRP , write = set_ElementNAME_SNOMINETCAT_GRP};
   virtual TFIBWideStringField * get_ElementNAME_SNOMINETCAT_GRP(void)=0;
   virtual void set_ElementNAME_SNOMINETCAT_GRP(TFIBWideStringField * ElementNAME_SNOMINETCAT_GRP)=0;

   __property TFIBLargeIntField * ElementIDGRPNOM_ZIP_SPRODUCER = {read = get_ElementIDGRPNOM_ZIP_SPRODUCER , write = set_ElementIDGRPNOM_ZIP_SPRODUCER};
   virtual TFIBLargeIntField * get_ElementIDGRPNOM_ZIP_SPRODUCER(void)=0;
   virtual void set_ElementIDGRPNOM_ZIP_SPRODUCER(TFIBLargeIntField * ElementIDGRPNOM_ZIP_SPRODUCER)=0;

   __property TFIBLargeIntField * ElementIDGRPNOM_RAB_SPRODUCER = {read = get_ElementIDGRPNOM_RAB_SPRODUCER , write = set_ElementIDGRPNOM_RAB_SPRODUCER};
   virtual TFIBLargeIntField * get_ElementIDGRPNOM_RAB_SPRODUCER(void)=0;
   virtual void set_ElementIDGRPNOM_RAB_SPRODUCER(TFIBLargeIntField * ElementIDGRPNOM_RAB_SPRODUCER)=0;

   __property TFIBLargeIntField * ElementIDGRP_HW_SPRODUCER = {read = get_ElementIDGRP_HW_SPRODUCER , write = set_ElementIDGRP_HW_SPRODUCER};
   virtual TFIBLargeIntField * get_ElementIDGRP_HW_SPRODUCER(void)=0;
   virtual void set_ElementIDGRP_HW_SPRODUCER(TFIBLargeIntField * ElementIDGRP_HW_SPRODUCER)=0;

   __property TFIBWideStringField * ElementNAMEGN = {read = get_ElementNAMEGN , write = set_ElementNAMEGN};
   virtual TFIBWideStringField * get_ElementNAMEGN(void)=0;
   virtual void set_ElementNAMEGN(TFIBWideStringField * ElementNAMEGN)=0;

   __property TFIBWideStringField * ElementRAB_NAMEGN = {read = get_ElementRAB_NAMEGN , write = set_ElementRAB_NAMEGN};
   virtual TFIBWideStringField * get_ElementRAB_NAMEGN(void)=0;
   virtual void set_ElementRAB_NAMEGN(TFIBWideStringField * ElementRAB_NAMEGN)=0;

   __property TFIBWideStringField * ElementNAME_REM_SGRP_HARDWARE = {read = get_ElementNAME_REM_SGRP_HARDWARE , write = set_ElementNAME_REM_SGRP_HARDWARE};
   virtual TFIBWideStringField * get_ElementNAME_REM_SGRP_HARDWARE(void)=0;
   virtual void set_ElementNAME_REM_SGRP_HARDWARE(TFIBWideStringField * ElementNAME_REM_SGRP_HARDWARE)=0;

   virtual bool OpenTable()=0;
   virtual bool  OpenElement(__int64 id)=0;
   virtual bool NewElement()=0;
   virtual bool SaveElement(void)=0;
   virtual void CloseElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual __int64 GetIdElementPoName(UnicodeString   name)=0;
   virtual int GetIndexInTablePoId(__int64 id_element)=0;
   virtual __int64 GetIdElementPoGid(UnicodeString gid)=0;
   virtual UnicodeString GetGidElementPoId(__int64 id)=0;
};
#define IID_IDMSprProducer __uuidof(IDMSprProducer)
#endif
