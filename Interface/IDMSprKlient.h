#ifndef UIDMSprKlientH
#define UIDMSprKlientH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprKlient)) IDMSprKlient : public IMainInterface
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

   __property TFIBBCDField * TableIDKLIENT = {read = get_TableIDKLIENT , write = set_TableIDKLIENT};
   virtual TFIBBCDField * get_TableIDKLIENT(void)=0;
   virtual void set_TableIDKLIENT(TFIBBCDField * TableIDKLIENT)=0;

   __property TFIBBCDField * TableIDGRPKLIENT = {read = get_TableIDGRPKLIENT , write = set_TableIDGRPKLIENT};
   virtual TFIBBCDField * get_TableIDGRPKLIENT(void)=0;
   virtual void set_TableIDGRPKLIENT(TFIBBCDField * TableIDGRPKLIENT)=0;

   __property TFIBBCDField * ElementIDKLIENT = {read = get_ElementIDKLIENT , write = set_ElementIDKLIENT};
   virtual TFIBBCDField * get_ElementIDKLIENT(void)=0;
   virtual void set_ElementIDKLIENT(TFIBBCDField * ElementIDKLIENT)=0;

   __property TFIBBCDField * ElementIDTPRICEKLIENT = {read = get_ElementIDTPRICEKLIENT , write = set_ElementIDTPRICEKLIENT};
   virtual TFIBBCDField * get_ElementIDTPRICEKLIENT(void)=0;
   virtual void set_ElementIDTPRICEKLIENT(TFIBBCDField * ElementIDTPRICEKLIENT)=0;

   __property TFIBBCDField * ElementIDGRPKLIENT = {read = get_ElementIDGRPKLIENT , write = set_ElementIDGRPKLIENT};
   virtual TFIBBCDField * get_ElementIDGRPKLIENT(void)=0;
   virtual void set_ElementIDGRPKLIENT(TFIBBCDField * ElementIDGRPKLIENT)=0;

   __property TFIBBCDField * ElementIDVIDKLIENT = {read = get_ElementIDVIDKLIENT , write = set_ElementIDVIDKLIENT};
   virtual TFIBBCDField * get_ElementIDVIDKLIENT(void)=0;
   virtual void set_ElementIDVIDKLIENT(TFIBBCDField * ElementIDVIDKLIENT)=0;

   __property TFIBBCDField * ElementIDCOUNTRYKLIENT = {read = get_ElementIDCOUNTRYKLIENT , write = set_ElementIDCOUNTRYKLIENT};
   virtual TFIBBCDField * get_ElementIDCOUNTRYKLIENT(void)=0;
   virtual void set_ElementIDCOUNTRYKLIENT(TFIBBCDField * ElementIDCOUNTRYKLIENT)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * ElementMAXCREDIT_SKLIENT = {read = get_ElementMAXCREDIT_SKLIENT , write = set_ElementMAXCREDIT_SKLIENT};
   virtual TFIBBCDField * get_ElementMAXCREDIT_SKLIENT(void)=0;
   virtual void set_ElementMAXCREDIT_SKLIENT(TFIBBCDField * ElementMAXCREDIT_SKLIENT)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * TableINNKLIENT = {read = get_TableINNKLIENT , write = set_TableINNKLIENT};
   virtual TFIBWideStringField * get_TableINNKLIENT(void)=0;
   virtual void set_TableINNKLIENT(TFIBWideStringField * TableINNKLIENT)=0;

   __property TFIBWideStringField * TableTELKLIENT = {read = get_TableTELKLIENT , write = set_TableTELKLIENT};
   virtual TFIBWideStringField * get_TableTELKLIENT(void)=0;
   virtual void set_TableTELKLIENT(TFIBWideStringField * TableTELKLIENT)=0;

   __property TFIBWideStringField * TableADRKLIENT = {read = get_TableADRKLIENT , write = set_TableADRKLIENT};
   virtual TFIBWideStringField * get_TableADRKLIENT(void)=0;
   virtual void set_TableADRKLIENT(TFIBWideStringField * TableADRKLIENT)=0;

   __property TFIBWideStringField * ElementNAMEKLIENT = {read = get_ElementNAMEKLIENT , write = set_ElementNAMEKLIENT};
   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void)=0;
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)=0;

   __property TFIBWideStringField * ElementFNAME = {read = get_ElementFNAME , write = set_ElementFNAME};
   virtual TFIBWideStringField * get_ElementFNAME(void)=0;
   virtual void set_ElementFNAME(TFIBWideStringField * ElementFNAME)=0;

   __property TFIBWideStringField * ElementADRKLIENT = {read = get_ElementADRKLIENT , write = set_ElementADRKLIENT};
   virtual TFIBWideStringField * get_ElementADRKLIENT(void)=0;
   virtual void set_ElementADRKLIENT(TFIBWideStringField * ElementADRKLIENT)=0;

   __property TFIBWideStringField * ElementTELKLIENT = {read = get_ElementTELKLIENT , write = set_ElementTELKLIENT};
   virtual TFIBWideStringField * get_ElementTELKLIENT(void)=0;
   virtual void set_ElementTELKLIENT(TFIBWideStringField * ElementTELKLIENT)=0;

   __property TFIBWideStringField * ElementINNKLIENT = {read = get_ElementINNKLIENT , write = set_ElementINNKLIENT};
   virtual TFIBWideStringField * get_ElementINNKLIENT(void)=0;
   virtual void set_ElementINNKLIENT(TFIBWideStringField * ElementINNKLIENT)=0;

   __property TFIBWideStringField * ElementKPPKLIENT = {read = get_ElementKPPKLIENT , write = set_ElementKPPKLIENT};
   virtual TFIBWideStringField * get_ElementKPPKLIENT(void)=0;
   virtual void set_ElementKPPKLIENT(TFIBWideStringField * ElementKPPKLIENT)=0;

   __property TFIBIntegerField * ElementTKLIENT = {read = get_ElementTKLIENT , write = set_ElementTKLIENT};
   virtual TFIBIntegerField * get_ElementTKLIENT(void)=0;
   virtual void set_ElementTKLIENT(TFIBIntegerField * ElementTKLIENT)=0;

   __property TFIBWideStringField * ElementGID_SKLIENT = {read = get_ElementGID_SKLIENT , write = set_ElementGID_SKLIENT};
   virtual TFIBWideStringField * get_ElementGID_SKLIENT(void)=0;
   virtual void set_ElementGID_SKLIENT(TFIBWideStringField * ElementGID_SKLIENT)=0;

   __property TFIBWideStringField * ElementOKPOKLIENT = {read = get_ElementOKPOKLIENT , write = set_ElementOKPOKLIENT};
   virtual TFIBWideStringField * get_ElementOKPOKLIENT(void)=0;
   virtual void set_ElementOKPOKLIENT(TFIBWideStringField * ElementOKPOKLIENT)=0;

   __property TFIBBCDField * ElementIDBASE_SKLIENT = {read = get_ElementIDBASE_SKLIENT , write = set_ElementIDBASE_SKLIENT};
   virtual TFIBBCDField * get_ElementIDBASE_SKLIENT(void)=0;
   virtual void set_ElementIDBASE_SKLIENT(TFIBBCDField * ElementIDBASE_SKLIENT)=0;

   __property TFIBWideStringField * ElementKRNAME_SKLIENT = {read = get_ElementKRNAME_SKLIENT , write = set_ElementKRNAME_SKLIENT};
   virtual TFIBWideStringField * get_ElementKRNAME_SKLIENT(void)=0;
   virtual void set_ElementKRNAME_SKLIENT(TFIBWideStringField * ElementKRNAME_SKLIENT)=0;

   __property TFIBWideStringField * ElementDESCR_SKLIENT = {read = get_ElementDESCR_SKLIENT , write = set_ElementDESCR_SKLIENT};
   virtual TFIBWideStringField * get_ElementDESCR_SKLIENT(void)=0;
   virtual void set_ElementDESCR_SKLIENT(TFIBWideStringField * ElementDESCR_SKLIENT)=0;

   __property TFIBWideStringField * ElementMESSAGE_SKLIENT = {read = get_ElementMESSAGE_SKLIENT , write = set_ElementMESSAGE_SKLIENT};
   virtual TFIBWideStringField * get_ElementMESSAGE_SKLIENT(void)=0;
   virtual void set_ElementMESSAGE_SKLIENT(TFIBWideStringField * ElementMESSAGE_SKLIENT)=0;

   __property TFIBWideStringField * ElementEMAIL_SKLIENT = {read = get_ElementEMAIL_SKLIENT , write = set_ElementEMAIL_SKLIENT};
   virtual TFIBWideStringField * get_ElementEMAIL_SKLIENT(void)=0;
   virtual void set_ElementEMAIL_SKLIENT(TFIBWideStringField * ElementEMAIL_SKLIENT)=0;

   __property TFIBWideStringField * ElementWWW_SKLIENT = {read = get_ElementWWW_SKLIENT , write = set_ElementWWW_SKLIENT};
   virtual TFIBWideStringField * get_ElementWWW_SKLIENT(void)=0;
   virtual void set_ElementWWW_SKLIENT(TFIBWideStringField * ElementWWW_SKLIENT)=0;

   __property TFIBWideStringField * ElementNAME_SVIDKLIENT = {read = get_ElementNAME_SVIDKLIENT , write = set_ElementNAME_SVIDKLIENT};
   virtual TFIBWideStringField * get_ElementNAME_SVIDKLIENT(void)=0;
   virtual void set_ElementNAME_SVIDKLIENT(TFIBWideStringField * ElementNAME_SVIDKLIENT)=0;

   __property TFIBWideStringField * ElementNAME_SCOUNTRY = {read = get_ElementNAME_SCOUNTRY , write = set_ElementNAME_SCOUNTRY};
   virtual TFIBWideStringField * get_ElementNAME_SCOUNTRY(void)=0;
   virtual void set_ElementNAME_SCOUNTRY(TFIBWideStringField * ElementNAME_SCOUNTRY)=0;

   __property TFIBWideStringField * ElementYUR_ADRESS_SKLIENT = {read = get_ElementYUR_ADRESS_SKLIENT , write = set_ElementYUR_ADRESS_SKLIENT};
   virtual TFIBWideStringField * get_ElementYUR_ADRESS_SKLIENT(void)=0;
   virtual void set_ElementYUR_ADRESS_SKLIENT(TFIBWideStringField * ElementYUR_ADRESS_SKLIENT)=0;

   __property TFIBWideStringField * ElementPOCHT_ADRRESS_SKLIENT = {read = get_ElementPOCHT_ADRRESS_SKLIENT , write = set_ElementPOCHT_ADRRESS_SKLIENT};
   virtual TFIBWideStringField * get_ElementPOCHT_ADRRESS_SKLIENT(void)=0;
   virtual void set_ElementPOCHT_ADRRESS_SKLIENT(TFIBWideStringField * ElementPOCHT_ADRRESS_SKLIENT)=0;

   __property TFIBWideStringField * ElementFAMILIYA_SKLIENT = {read = get_ElementFAMILIYA_SKLIENT , write = set_ElementFAMILIYA_SKLIENT};
   virtual TFIBWideStringField * get_ElementFAMILIYA_SKLIENT(void)=0;
   virtual void set_ElementFAMILIYA_SKLIENT(TFIBWideStringField * ElementFAMILIYA_SKLIENT)=0;

   __property TFIBWideStringField * ElementIMYA_SKLIENT = {read = get_ElementIMYA_SKLIENT , write = set_ElementIMYA_SKLIENT};
   virtual TFIBWideStringField * get_ElementIMYA_SKLIENT(void)=0;
   virtual void set_ElementIMYA_SKLIENT(TFIBWideStringField * ElementIMYA_SKLIENT)=0;

   __property TFIBWideStringField * ElementOTCHESTVO_SKLIENT = {read = get_ElementOTCHESTVO_SKLIENT , write = set_ElementOTCHESTVO_SKLIENT};
   virtual TFIBWideStringField * get_ElementOTCHESTVO_SKLIENT(void)=0;
   virtual void set_ElementOTCHESTVO_SKLIENT(TFIBWideStringField * ElementOTCHESTVO_SKLIENT)=0;

   __property TFIBIntegerField * ElementTYPE_POISK_SKLIENT = {read = get_ElementTYPE_POISK_SKLIENT , write = set_ElementTYPE_POISK_SKLIENT};
   virtual TFIBIntegerField * get_ElementTYPE_POISK_SKLIENT(void)=0;
   virtual void set_ElementTYPE_POISK_SKLIENT(TFIBIntegerField * ElementTYPE_POISK_SKLIENT)=0;

   __property TFIBBCDField * ElementIDGRPNOM_SKLIENT = {read = get_ElementIDGRPNOM_SKLIENT , write = set_ElementIDGRPNOM_SKLIENT};
   virtual TFIBBCDField * get_ElementIDGRPNOM_SKLIENT(void)=0;
   virtual void set_ElementIDGRPNOM_SKLIENT(TFIBBCDField * ElementIDGRPNOM_SKLIENT)=0;

   __property TFIBBCDField * ElementIDGRPHW_SKLIENT = {read = get_ElementIDGRPHW_SKLIENT , write = set_ElementIDGRPHW_SKLIENT};
   virtual TFIBBCDField * get_ElementIDGRPHW_SKLIENT(void)=0;
   virtual void set_ElementIDGRPHW_SKLIENT(TFIBBCDField * ElementIDGRPHW_SKLIENT)=0;

   __property TFIBWideStringField * ElementNAMEGN = {read = get_ElementNAMEGN , write = set_ElementNAMEGN};
   virtual TFIBWideStringField * get_ElementNAMEGN(void)=0;
   virtual void set_ElementNAMEGN(TFIBWideStringField * ElementNAMEGN)=0;

   __property TFIBWideStringField * ElementNAME_REM_SGRP_HARDWARE = {read = get_ElementNAME_REM_SGRP_HARDWARE , write = set_ElementNAME_REM_SGRP_HARDWARE};
   virtual TFIBWideStringField * get_ElementNAME_REM_SGRP_HARDWARE(void)=0;
   virtual void set_ElementNAME_REM_SGRP_HARDWARE(TFIBWideStringField * ElementNAME_REM_SGRP_HARDWARE)=0;

   __property __int64 Id = {read = get_Id , write = set_Id};
   virtual __int64 get_Id(void)=0;
   virtual void set_Id(__int64 Id)=0;

   __property __int64 IdGroup = {read = get_IdGroup , write = set_IdGroup};
   virtual __int64 get_IdGroup(void)=0;
   virtual void set_IdGroup(__int64 IdGroup)=0;

   __property bool AllElement = {read = get_AllElement , write = set_AllElement};
   virtual bool get_AllElement(void)=0;
   virtual void set_AllElement(bool AllElement)=0;

   __property bool elSave = {read = get_elSave , write = set_elSave};
   virtual bool get_elSave(void)=0;
   virtual void set_elSave(bool elSave)=0;

   virtual bool OpenTable(__int64 id_grp, bool all)=0;
   virtual int OpenElement(__int64 id)=0;
   virtual void NewElement(__int64 id_grp)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 id)=0;
   virtual void ChancheGrp(__int64 new_grp)=0;
   virtual __int64 FindPoName(String Name)=0;
   virtual __int64 GetIDKlientPoName(AnsiString name)=0;
   virtual __int64 GetIdGrpKlient(__int64 id_klient)=0;
};
#define IID_IDMSprKlient __uuidof(IDMSprKlient)
#endif
