#ifndef UIREM_DMZayavkaH
#define UIREM_DMZayavkaH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IREM_DMZayavka)) IREM_DMZayavka : public IMainInterface
{
public:
   __property TDataSource * DataSourceGurZKompl = {read = get_DataSourceGurZKompl , write = set_DataSourceGurZKompl};
   virtual TDataSource * get_DataSourceGurZKompl(void)=0;
   virtual void set_DataSourceGurZKompl(TDataSource * DataSourceGurZKompl)=0;

   __property TDataSource * DataSourceGurZNeispr = {read = get_DataSourceGurZNeispr , write = set_DataSourceGurZNeispr};
   virtual TDataSource * get_DataSourceGurZNeispr(void)=0;
   virtual void set_DataSourceGurZNeispr(TDataSource * DataSourceGurZNeispr)=0;

   __property TDataSource * DataSourceGurZ = {read = get_DataSourceGurZ , write = set_DataSourceGurZ};
   virtual TDataSource * get_DataSourceGurZ(void)=0;
   virtual void set_DataSourceGurZ(TDataSource * DataSourceGurZ)=0;

   __property TpFIBDataSet * GurZ = {read = get_GurZ , write = set_GurZ};
   virtual TpFIBDataSet * get_GurZ(void)=0;
   virtual void set_GurZ(TpFIBDataSet * GurZ)=0;

   __property TpFIBDataSet * GurZKompl = {read = get_GurZKompl , write = set_GurZKompl};
   virtual TpFIBDataSet * get_GurZKompl(void)=0;
   virtual void set_GurZKompl(TpFIBDataSet * GurZKompl)=0;

   __property TpFIBDataSet * GurZNeispr = {read = get_GurZNeispr , write = set_GurZNeispr};
   virtual TpFIBDataSet * get_GurZNeispr(void)=0;
   virtual void set_GurZNeispr(TpFIBDataSet * GurZNeispr)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TpFIBDataSet * NumDoc = {read = get_NumDoc , write = set_NumDoc};
   virtual TpFIBDataSet * get_NumDoc(void)=0;
   virtual void set_NumDoc(TpFIBDataSet * NumDoc)=0;

   __property TIntegerField * GurZKomplRECNO = {read = get_GurZKomplRECNO , write = set_GurZKomplRECNO};
   virtual TIntegerField * get_GurZKomplRECNO(void)=0;
   virtual void set_GurZKomplRECNO(TIntegerField * GurZKomplRECNO)=0;

   __property TIntegerField * GurZNeisprRECNO = {read = get_GurZNeisprRECNO , write = set_GurZNeisprRECNO};
   virtual TIntegerField * get_GurZNeisprRECNO(void)=0;
   virtual void set_GurZNeisprRECNO(TIntegerField * GurZNeisprRECNO)=0;

   __property TFIBLargeIntField * GurZID_REM_Z = {read = get_GurZID_REM_Z , write = set_GurZID_REM_Z};
   virtual TFIBLargeIntField * get_GurZID_REM_Z(void)=0;
   virtual void set_GurZID_REM_Z(TFIBLargeIntField * GurZID_REM_Z)=0;

   __property TFIBWideStringField * GurZGID_REM_Z = {read = get_GurZGID_REM_Z , write = set_GurZGID_REM_Z};
   virtual TFIBWideStringField * get_GurZGID_REM_Z(void)=0;
   virtual void set_GurZGID_REM_Z(TFIBWideStringField * GurZGID_REM_Z)=0;

   __property TFIBWideStringField * GurZPREFIKS_REM_Z = {read = get_GurZPREFIKS_REM_Z , write = set_GurZPREFIKS_REM_Z};
   virtual TFIBWideStringField * get_GurZPREFIKS_REM_Z(void)=0;
   virtual void set_GurZPREFIKS_REM_Z(TFIBWideStringField * GurZPREFIKS_REM_Z)=0;

   __property TFIBIntegerField * GurZNUM_REM_Z = {read = get_GurZNUM_REM_Z , write = set_GurZNUM_REM_Z};
   virtual TFIBIntegerField * get_GurZNUM_REM_Z(void)=0;
   virtual void set_GurZNUM_REM_Z(TFIBIntegerField * GurZNUM_REM_Z)=0;

   __property TFIBDateTimeField * GurZPOS_REM_Z = {read = get_GurZPOS_REM_Z , write = set_GurZPOS_REM_Z};
   virtual TFIBDateTimeField * get_GurZPOS_REM_Z(void)=0;
   virtual void set_GurZPOS_REM_Z(TFIBDateTimeField * GurZPOS_REM_Z)=0;

   __property TFIBLargeIntField * GurZIDBASE_REM_Z = {read = get_GurZIDBASE_REM_Z , write = set_GurZIDBASE_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDBASE_REM_Z(void)=0;
   virtual void set_GurZIDBASE_REM_Z(TFIBLargeIntField * GurZIDBASE_REM_Z)=0;

   __property TFIBLargeIntField * GurZIDMODEL_REM_Z = {read = get_GurZIDMODEL_REM_Z , write = set_GurZIDMODEL_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDMODEL_REM_Z(void)=0;
   virtual void set_GurZIDMODEL_REM_Z(TFIBLargeIntField * GurZIDMODEL_REM_Z)=0;

   __property TFIBLargeIntField * GurZIDSKLPR_REM_Z = {read = get_GurZIDSKLPR_REM_Z , write = set_GurZIDSKLPR_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDSKLPR_REM_Z(void)=0;
   virtual void set_GurZIDSKLPR_REM_Z(TFIBLargeIntField * GurZIDSKLPR_REM_Z)=0;

   __property TFIBLargeIntField * GurZIDKLIENT_REM_Z = {read = get_GurZIDKLIENT_REM_Z , write = set_GurZIDKLIENT_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDKLIENT_REM_Z(void)=0;
   virtual void set_GurZIDKLIENT_REM_Z(TFIBLargeIntField * GurZIDKLIENT_REM_Z)=0;

   __property TFIBLargeIntField * GurZIDDILER_REM_Z = {read = get_GurZIDDILER_REM_Z , write = set_GurZIDDILER_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDDILER_REM_Z(void)=0;
   virtual void set_GurZIDDILER_REM_Z(TFIBLargeIntField * GurZIDDILER_REM_Z)=0;

   __property TFIBWideStringField * GurZNAME_REM_Z = {read = get_GurZNAME_REM_Z , write = set_GurZNAME_REM_Z};
   virtual TFIBWideStringField * get_GurZNAME_REM_Z(void)=0;
   virtual void set_GurZNAME_REM_Z(TFIBWideStringField * GurZNAME_REM_Z)=0;

   __property TFIBWideStringField * GurZDESCR_REM_Z = {read = get_GurZDESCR_REM_Z , write = set_GurZDESCR_REM_Z};
   virtual TFIBWideStringField * get_GurZDESCR_REM_Z(void)=0;
   virtual void set_GurZDESCR_REM_Z(TFIBWideStringField * GurZDESCR_REM_Z)=0;

   __property TFIBLargeIntField * GurZIDTYPEREM_REM_Z = {read = get_GurZIDTYPEREM_REM_Z , write = set_GurZIDTYPEREM_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDTYPEREM_REM_Z(void)=0;
   virtual void set_GurZIDTYPEREM_REM_Z(TFIBLargeIntField * GurZIDTYPEREM_REM_Z)=0;

   __property TFIBLargeIntField * GurZIDSOST_REM_Z = {read = get_GurZIDSOST_REM_Z , write = set_GurZIDSOST_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDSOST_REM_Z(void)=0;
   virtual void set_GurZIDSOST_REM_Z(TFIBLargeIntField * GurZIDSOST_REM_Z)=0;

   __property TFIBLargeIntField * GurZIDTECSKL_REM_Z = {read = get_GurZIDTECSKL_REM_Z , write = set_GurZIDTECSKL_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDTECSKL_REM_Z(void)=0;
   virtual void set_GurZIDTECSKL_REM_Z(TFIBLargeIntField * GurZIDTECSKL_REM_Z)=0;

   __property TFIBLargeIntField * GurZIDUSER_REM_Z = {read = get_GurZIDUSER_REM_Z , write = set_GurZIDUSER_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDUSER_REM_Z(void)=0;
   virtual void set_GurZIDUSER_REM_Z(TFIBLargeIntField * GurZIDUSER_REM_Z)=0;

   __property TFIBIntegerField * GurZOPER_REM_Z = {read = get_GurZOPER_REM_Z , write = set_GurZOPER_REM_Z};
   virtual TFIBIntegerField * get_GurZOPER_REM_Z(void)=0;
   virtual void set_GurZOPER_REM_Z(TFIBIntegerField * GurZOPER_REM_Z)=0;

   __property TFIBBCDField * GurZSUM_REM_Z = {read = get_GurZSUM_REM_Z , write = set_GurZSUM_REM_Z};
   virtual TFIBBCDField * get_GurZSUM_REM_Z(void)=0;
   virtual void set_GurZSUM_REM_Z(TFIBBCDField * GurZSUM_REM_Z)=0;

   __property TFIBDateField * GurZSROK_REM_Z = {read = get_GurZSROK_REM_Z , write = set_GurZSROK_REM_Z};
   virtual TFIBDateField * get_GurZSROK_REM_Z(void)=0;
   virtual void set_GurZSROK_REM_Z(TFIBDateField * GurZSROK_REM_Z)=0;

   __property TFIBSmallIntField * GurZOUT_REM_Z = {read = get_GurZOUT_REM_Z , write = set_GurZOUT_REM_Z};
   virtual TFIBSmallIntField * get_GurZOUT_REM_Z(void)=0;
   virtual void set_GurZOUT_REM_Z(TFIBSmallIntField * GurZOUT_REM_Z)=0;

   __property TFIBLargeIntField * GurZIDFIRM_REM_Z = {read = get_GurZIDFIRM_REM_Z , write = set_GurZIDFIRM_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDFIRM_REM_Z(void)=0;
   virtual void set_GurZIDFIRM_REM_Z(TFIBLargeIntField * GurZIDFIRM_REM_Z)=0;

   __property TFIBWideStringField * GurZNAMEFIRM = {read = get_GurZNAMEFIRM , write = set_GurZNAMEFIRM};
   virtual TFIBWideStringField * get_GurZNAMEFIRM(void)=0;
   virtual void set_GurZNAMEFIRM(TFIBWideStringField * GurZNAMEFIRM)=0;

   __property TFIBWideStringField * GurZNAME_SINFBASE_OBMEN = {read = get_GurZNAME_SINFBASE_OBMEN , write = set_GurZNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_GurZNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_GurZNAME_SINFBASE_OBMEN(TFIBWideStringField * GurZNAME_SINFBASE_OBMEN)=0;

   __property TFIBWideStringField * GurZNAME_REM_SMODEL = {read = get_GurZNAME_REM_SMODEL , write = set_GurZNAME_REM_SMODEL};
   virtual TFIBWideStringField * get_GurZNAME_REM_SMODEL(void)=0;
   virtual void set_GurZNAME_REM_SMODEL(TFIBWideStringField * GurZNAME_REM_SMODEL)=0;

   __property TFIBWideStringField * GurZNAME_SKLAD_PR = {read = get_GurZNAME_SKLAD_PR , write = set_GurZNAME_SKLAD_PR};
   virtual TFIBWideStringField * get_GurZNAME_SKLAD_PR(void)=0;
   virtual void set_GurZNAME_SKLAD_PR(TFIBWideStringField * GurZNAME_SKLAD_PR)=0;

   __property TFIBWideStringField * GurZNAMEKLIENT = {read = get_GurZNAMEKLIENT , write = set_GurZNAMEKLIENT};
   virtual TFIBWideStringField * get_GurZNAMEKLIENT(void)=0;
   virtual void set_GurZNAMEKLIENT(TFIBWideStringField * GurZNAMEKLIENT)=0;

   __property TFIBWideStringField * GurZNAMEDILER = {read = get_GurZNAMEDILER , write = set_GurZNAMEDILER};
   virtual TFIBWideStringField * get_GurZNAMEDILER(void)=0;
   virtual void set_GurZNAMEDILER(TFIBWideStringField * GurZNAMEDILER)=0;

   __property TFIBWideStringField * GurZNAME_STREMONT = {read = get_GurZNAME_STREMONT , write = set_GurZNAME_STREMONT};
   virtual TFIBWideStringField * get_GurZNAME_STREMONT(void)=0;
   virtual void set_GurZNAME_STREMONT(TFIBWideStringField * GurZNAME_STREMONT)=0;

   __property TFIBWideStringField * GurZNAME_REMSSOST = {read = get_GurZNAME_REMSSOST , write = set_GurZNAME_REMSSOST};
   virtual TFIBWideStringField * get_GurZNAME_REMSSOST(void)=0;
   virtual void set_GurZNAME_REMSSOST(TFIBWideStringField * GurZNAME_REMSSOST)=0;

   __property TFIBWideStringField * GurZNAME_SKLAD_TEC = {read = get_GurZNAME_SKLAD_TEC , write = set_GurZNAME_SKLAD_TEC};
   virtual TFIBWideStringField * get_GurZNAME_SKLAD_TEC(void)=0;
   virtual void set_GurZNAME_SKLAD_TEC(TFIBWideStringField * GurZNAME_SKLAD_TEC)=0;

   __property TFIBWideStringField * GurZNAME_USER = {read = get_GurZNAME_USER , write = set_GurZNAME_USER};
   virtual TFIBWideStringField * get_GurZNAME_USER(void)=0;
   virtual void set_GurZNAME_USER(TFIBWideStringField * GurZNAME_USER)=0;

   __property TFIBLargeIntField * GurZKomplID_REM_ZKOMPL = {read = get_GurZKomplID_REM_ZKOMPL , write = set_GurZKomplID_REM_ZKOMPL};
   virtual TFIBLargeIntField * get_GurZKomplID_REM_ZKOMPL(void)=0;
   virtual void set_GurZKomplID_REM_ZKOMPL(TFIBLargeIntField * GurZKomplID_REM_ZKOMPL)=0;

   __property TFIBWideStringField * GurZKomplGID_REM_ZKOMPL = {read = get_GurZKomplGID_REM_ZKOMPL , write = set_GurZKomplGID_REM_ZKOMPL};
   virtual TFIBWideStringField * get_GurZKomplGID_REM_ZKOMPL(void)=0;
   virtual void set_GurZKomplGID_REM_ZKOMPL(TFIBWideStringField * GurZKomplGID_REM_ZKOMPL)=0;

   __property TFIBWideStringField * GurZKomplPREFIKS_REM_ZKOMPL = {read = get_GurZKomplPREFIKS_REM_ZKOMPL , write = set_GurZKomplPREFIKS_REM_ZKOMPL};
   virtual TFIBWideStringField * get_GurZKomplPREFIKS_REM_ZKOMPL(void)=0;
   virtual void set_GurZKomplPREFIKS_REM_ZKOMPL(TFIBWideStringField * GurZKomplPREFIKS_REM_ZKOMPL)=0;

   __property TFIBLargeIntField * GurZKomplIDZ_REM_ZKOMPL = {read = get_GurZKomplIDZ_REM_ZKOMPL , write = set_GurZKomplIDZ_REM_ZKOMPL};
   virtual TFIBLargeIntField * get_GurZKomplIDZ_REM_ZKOMPL(void)=0;
   virtual void set_GurZKomplIDZ_REM_ZKOMPL(TFIBLargeIntField * GurZKomplIDZ_REM_ZKOMPL)=0;

   __property TFIBLargeIntField * GurZKomplIDKOMPL_REM_ZKOMPL = {read = get_GurZKomplIDKOMPL_REM_ZKOMPL , write = set_GurZKomplIDKOMPL_REM_ZKOMPL};
   virtual TFIBLargeIntField * get_GurZKomplIDKOMPL_REM_ZKOMPL(void)=0;
   virtual void set_GurZKomplIDKOMPL_REM_ZKOMPL(TFIBLargeIntField * GurZKomplIDKOMPL_REM_ZKOMPL)=0;

   __property TFIBBCDField * GurZKomplKOL_REM_ZKOMPL = {read = get_GurZKomplKOL_REM_ZKOMPL , write = set_GurZKomplKOL_REM_ZKOMPL};
   virtual TFIBBCDField * get_GurZKomplKOL_REM_ZKOMPL(void)=0;
   virtual void set_GurZKomplKOL_REM_ZKOMPL(TFIBBCDField * GurZKomplKOL_REM_ZKOMPL)=0;

   __property TFIBLargeIntField * GurZKomplIDBASE_REM_ZKOMPL = {read = get_GurZKomplIDBASE_REM_ZKOMPL , write = set_GurZKomplIDBASE_REM_ZKOMPL};
   virtual TFIBLargeIntField * get_GurZKomplIDBASE_REM_ZKOMPL(void)=0;
   virtual void set_GurZKomplIDBASE_REM_ZKOMPL(TFIBLargeIntField * GurZKomplIDBASE_REM_ZKOMPL)=0;

   __property TFIBWideStringField * GurZKomplNAME_REM_SKOMPLMODEL = {read = get_GurZKomplNAME_REM_SKOMPLMODEL , write = set_GurZKomplNAME_REM_SKOMPLMODEL};
   virtual TFIBWideStringField * get_GurZKomplNAME_REM_SKOMPLMODEL(void)=0;
   virtual void set_GurZKomplNAME_REM_SKOMPLMODEL(TFIBWideStringField * GurZKomplNAME_REM_SKOMPLMODEL)=0;

   __property TFIBLargeIntField * GurZNeisprID_REM_ZNEISPR = {read = get_GurZNeisprID_REM_ZNEISPR , write = set_GurZNeisprID_REM_ZNEISPR};
   virtual TFIBLargeIntField * get_GurZNeisprID_REM_ZNEISPR(void)=0;
   virtual void set_GurZNeisprID_REM_ZNEISPR(TFIBLargeIntField * GurZNeisprID_REM_ZNEISPR)=0;

   __property TFIBWideStringField * GurZNeisprGID_REM_ZNEISPR = {read = get_GurZNeisprGID_REM_ZNEISPR , write = set_GurZNeisprGID_REM_ZNEISPR};
   virtual TFIBWideStringField * get_GurZNeisprGID_REM_ZNEISPR(void)=0;
   virtual void set_GurZNeisprGID_REM_ZNEISPR(TFIBWideStringField * GurZNeisprGID_REM_ZNEISPR)=0;

   __property TFIBWideStringField * GurZNeisprPREFIKS_REM_ZNEISPR = {read = get_GurZNeisprPREFIKS_REM_ZNEISPR , write = set_GurZNeisprPREFIKS_REM_ZNEISPR};
   virtual TFIBWideStringField * get_GurZNeisprPREFIKS_REM_ZNEISPR(void)=0;
   virtual void set_GurZNeisprPREFIKS_REM_ZNEISPR(TFIBWideStringField * GurZNeisprPREFIKS_REM_ZNEISPR)=0;

   __property TFIBLargeIntField * GurZNeisprIDZ_REM_ZNEISPR = {read = get_GurZNeisprIDZ_REM_ZNEISPR , write = set_GurZNeisprIDZ_REM_ZNEISPR};
   virtual TFIBLargeIntField * get_GurZNeisprIDZ_REM_ZNEISPR(void)=0;
   virtual void set_GurZNeisprIDZ_REM_ZNEISPR(TFIBLargeIntField * GurZNeisprIDZ_REM_ZNEISPR)=0;

   __property TFIBLargeIntField * GurZNeisprIDNEISPR_REM_ZNEISPR = {read = get_GurZNeisprIDNEISPR_REM_ZNEISPR , write = set_GurZNeisprIDNEISPR_REM_ZNEISPR};
   virtual TFIBLargeIntField * get_GurZNeisprIDNEISPR_REM_ZNEISPR(void)=0;
   virtual void set_GurZNeisprIDNEISPR_REM_ZNEISPR(TFIBLargeIntField * GurZNeisprIDNEISPR_REM_ZNEISPR)=0;

   __property TFIBLargeIntField * GurZNeisprIDBASE_REM_ZNEISPR = {read = get_GurZNeisprIDBASE_REM_ZNEISPR , write = set_GurZNeisprIDBASE_REM_ZNEISPR};
   virtual TFIBLargeIntField * get_GurZNeisprIDBASE_REM_ZNEISPR(void)=0;
   virtual void set_GurZNeisprIDBASE_REM_ZNEISPR(TFIBLargeIntField * GurZNeisprIDBASE_REM_ZNEISPR)=0;

   __property TFIBWideStringField * GurZNeisprNAME_REM_SNEISPR = {read = get_GurZNeisprNAME_REM_SNEISPR , write = set_GurZNeisprNAME_REM_SNEISPR};
   virtual TFIBWideStringField * get_GurZNeisprNAME_REM_SNEISPR(void)=0;
   virtual void set_GurZNeisprNAME_REM_SNEISPR(TFIBWideStringField * GurZNeisprNAME_REM_SNEISPR)=0;

   __property TFIBWideStringField * GurZNEISPR_REM_Z = {read = get_GurZNEISPR_REM_Z , write = set_GurZNEISPR_REM_Z};
   virtual TFIBWideStringField * get_GurZNEISPR_REM_Z(void)=0;
   virtual void set_GurZNEISPR_REM_Z(TFIBWideStringField * GurZNEISPR_REM_Z)=0;

   __property TFIBWideStringField * GurZKLIENT_NAME_REM_Z = {read = get_GurZKLIENT_NAME_REM_Z , write = set_GurZKLIENT_NAME_REM_Z};
   virtual TFIBWideStringField * get_GurZKLIENT_NAME_REM_Z(void)=0;
   virtual void set_GurZKLIENT_NAME_REM_Z(TFIBWideStringField * GurZKLIENT_NAME_REM_Z)=0;

   __property TFIBWideStringField * GurZKLIENT_ADR_REM_Z = {read = get_GurZKLIENT_ADR_REM_Z , write = set_GurZKLIENT_ADR_REM_Z};
   virtual TFIBWideStringField * get_GurZKLIENT_ADR_REM_Z(void)=0;
   virtual void set_GurZKLIENT_ADR_REM_Z(TFIBWideStringField * GurZKLIENT_ADR_REM_Z)=0;

   __property TFIBWideStringField * GurZKLIENT_PHONE_REM_Z = {read = get_GurZKLIENT_PHONE_REM_Z , write = set_GurZKLIENT_PHONE_REM_Z};
   virtual TFIBWideStringField * get_GurZKLIENT_PHONE_REM_Z(void)=0;
   virtual void set_GurZKLIENT_PHONE_REM_Z(TFIBWideStringField * GurZKLIENT_PHONE_REM_Z)=0;

   __property TFIBWideStringField * GurZKOMPLECT_REM_Z = {read = get_GurZKOMPLECT_REM_Z , write = set_GurZKOMPLECT_REM_Z};
   virtual TFIBWideStringField * get_GurZKOMPLECT_REM_Z(void)=0;
   virtual void set_GurZKOMPLECT_REM_Z(TFIBWideStringField * GurZKOMPLECT_REM_Z)=0;

   __property TFIBWideStringField * GurZMODEL_REM_Z = {read = get_GurZMODEL_REM_Z , write = set_GurZMODEL_REM_Z};
   virtual TFIBWideStringField * get_GurZMODEL_REM_Z(void)=0;
   virtual void set_GurZMODEL_REM_Z(TFIBWideStringField * GurZMODEL_REM_Z)=0;

   __property TFIBWideStringField * GurZSOST_REM_Z = {read = get_GurZSOST_REM_Z , write = set_GurZSOST_REM_Z};
   virtual TFIBWideStringField * get_GurZSOST_REM_Z(void)=0;
   virtual void set_GurZSOST_REM_Z(TFIBWideStringField * GurZSOST_REM_Z)=0;

   __property TFIBWideStringField * GurZSERNUM2_REM_Z = {read = get_GurZSERNUM2_REM_Z , write = set_GurZSERNUM2_REM_Z};
   virtual TFIBWideStringField * get_GurZSERNUM2_REM_Z(void)=0;
   virtual void set_GurZSERNUM2_REM_Z(TFIBWideStringField * GurZSERNUM2_REM_Z)=0;

   __property TFIBWideStringField * GurZSERNUM_REM_Z = {read = get_GurZSERNUM_REM_Z , write = set_GurZSERNUM_REM_Z};
   virtual TFIBWideStringField * get_GurZSERNUM_REM_Z(void)=0;
   virtual void set_GurZSERNUM_REM_Z(TFIBWideStringField * GurZSERNUM_REM_Z)=0;

   __property TFIBWideStringField * GurZCOMENTS_REM_Z = {read = get_GurZCOMENTS_REM_Z , write = set_GurZCOMENTS_REM_Z};
   virtual TFIBWideStringField * get_GurZCOMENTS_REM_Z(void)=0;
   virtual void set_GurZCOMENTS_REM_Z(TFIBWideStringField * GurZCOMENTS_REM_Z)=0;

   __property TFIBDateTimeField * GurZPOSOUT_REM_Z = {read = get_GurZPOSOUT_REM_Z , write = set_GurZPOSOUT_REM_Z};
   virtual TFIBDateTimeField * get_GurZPOSOUT_REM_Z(void)=0;
   virtual void set_GurZPOSOUT_REM_Z(TFIBDateTimeField * GurZPOSOUT_REM_Z)=0;

   __property TFIBDateTimeField * GurZPOSREMONT_REM_Z = {read = get_GurZPOSREMONT_REM_Z , write = set_GurZPOSREMONT_REM_Z};
   virtual TFIBDateTimeField * get_GurZPOSREMONT_REM_Z(void)=0;
   virtual void set_GurZPOSREMONT_REM_Z(TFIBDateTimeField * GurZPOSREMONT_REM_Z)=0;

   __property TFIBIntegerField * GurZWARRANTY_REM_Z = {read = get_GurZWARRANTY_REM_Z , write = set_GurZWARRANTY_REM_Z};
   virtual TFIBIntegerField * get_GurZWARRANTY_REM_Z(void)=0;
   virtual void set_GurZWARRANTY_REM_Z(TFIBIntegerField * GurZWARRANTY_REM_Z)=0;

   __property TpFIBDataSet * DopUsl = {read = get_DopUsl , write = set_DopUsl};
   virtual TpFIBDataSet * get_DopUsl(void)=0;
   virtual void set_DopUsl(TpFIBDataSet * DopUsl)=0;

   __property TDataSource * DataSourceDopUsl = {read = get_DataSourceDopUsl , write = set_DataSourceDopUsl};
   virtual TDataSource * get_DataSourceDopUsl(void)=0;
   virtual void set_DataSourceDopUsl(TDataSource * DataSourceDopUsl)=0;

   __property TFIBLargeIntField * DopUslID_REM_ZDOPUSL = {read = get_DopUslID_REM_ZDOPUSL , write = set_DopUslID_REM_ZDOPUSL};
   virtual TFIBLargeIntField * get_DopUslID_REM_ZDOPUSL(void)=0;
   virtual void set_DopUslID_REM_ZDOPUSL(TFIBLargeIntField * DopUslID_REM_ZDOPUSL)=0;

   __property TFIBWideStringField * DopUslGID_REM_ZDOPUSL = {read = get_DopUslGID_REM_ZDOPUSL , write = set_DopUslGID_REM_ZDOPUSL};
   virtual TFIBWideStringField * get_DopUslGID_REM_ZDOPUSL(void)=0;
   virtual void set_DopUslGID_REM_ZDOPUSL(TFIBWideStringField * DopUslGID_REM_ZDOPUSL)=0;

   __property TFIBLargeIntField * DopUslIDBASE_REM_ZDOPUSL = {read = get_DopUslIDBASE_REM_ZDOPUSL , write = set_DopUslIDBASE_REM_ZDOPUSL};
   virtual TFIBLargeIntField * get_DopUslIDBASE_REM_ZDOPUSL(void)=0;
   virtual void set_DopUslIDBASE_REM_ZDOPUSL(TFIBLargeIntField * DopUslIDBASE_REM_ZDOPUSL)=0;

   __property TFIBLargeIntField * DopUslIDZ_REM_ZDOPUSL = {read = get_DopUslIDZ_REM_ZDOPUSL , write = set_DopUslIDZ_REM_ZDOPUSL};
   virtual TFIBLargeIntField * get_DopUslIDZ_REM_ZDOPUSL(void)=0;
   virtual void set_DopUslIDZ_REM_ZDOPUSL(TFIBLargeIntField * DopUslIDZ_REM_ZDOPUSL)=0;

   __property TFIBLargeIntField * DopUslIDNOM_REM_ZDOPUSL = {read = get_DopUslIDNOM_REM_ZDOPUSL , write = set_DopUslIDNOM_REM_ZDOPUSL};
   virtual TFIBLargeIntField * get_DopUslIDNOM_REM_ZDOPUSL(void)=0;
   virtual void set_DopUslIDNOM_REM_ZDOPUSL(TFIBLargeIntField * DopUslIDNOM_REM_ZDOPUSL)=0;

   __property TFIBLargeIntField * DopUslIDED_REM_ZDOPUSL = {read = get_DopUslIDED_REM_ZDOPUSL , write = set_DopUslIDED_REM_ZDOPUSL};
   virtual TFIBLargeIntField * get_DopUslIDED_REM_ZDOPUSL(void)=0;
   virtual void set_DopUslIDED_REM_ZDOPUSL(TFIBLargeIntField * DopUslIDED_REM_ZDOPUSL)=0;

   __property TFIBBCDField * DopUslKOL_REM_ZDOPUSL = {read = get_DopUslKOL_REM_ZDOPUSL , write = set_DopUslKOL_REM_ZDOPUSL};
   virtual TFIBBCDField * get_DopUslKOL_REM_ZDOPUSL(void)=0;
   virtual void set_DopUslKOL_REM_ZDOPUSL(TFIBBCDField * DopUslKOL_REM_ZDOPUSL)=0;

   __property TFIBBCDField * DopUslKF_REM_ZDOPUSL = {read = get_DopUslKF_REM_ZDOPUSL , write = set_DopUslKF_REM_ZDOPUSL};
   virtual TFIBBCDField * get_DopUslKF_REM_ZDOPUSL(void)=0;
   virtual void set_DopUslKF_REM_ZDOPUSL(TFIBBCDField * DopUslKF_REM_ZDOPUSL)=0;

   __property TFIBBCDField * DopUslPRICE_REM_ZDOPUSL = {read = get_DopUslPRICE_REM_ZDOPUSL , write = set_DopUslPRICE_REM_ZDOPUSL};
   virtual TFIBBCDField * get_DopUslPRICE_REM_ZDOPUSL(void)=0;
   virtual void set_DopUslPRICE_REM_ZDOPUSL(TFIBBCDField * DopUslPRICE_REM_ZDOPUSL)=0;

   __property TFIBBCDField * DopUslSUM_REM_ZDOPUSL = {read = get_DopUslSUM_REM_ZDOPUSL , write = set_DopUslSUM_REM_ZDOPUSL};
   virtual TFIBBCDField * get_DopUslSUM_REM_ZDOPUSL(void)=0;
   virtual void set_DopUslSUM_REM_ZDOPUSL(TFIBBCDField * DopUslSUM_REM_ZDOPUSL)=0;

   __property TFIBWideStringField * DopUslTEXTNOM_REM_ZDOPUSL = {read = get_DopUslTEXTNOM_REM_ZDOPUSL , write = set_DopUslTEXTNOM_REM_ZDOPUSL};
   virtual TFIBWideStringField * get_DopUslTEXTNOM_REM_ZDOPUSL(void)=0;
   virtual void set_DopUslTEXTNOM_REM_ZDOPUSL(TFIBWideStringField * DopUslTEXTNOM_REM_ZDOPUSL)=0;

   __property TFIBWideStringField * DopUslNAMENOM = {read = get_DopUslNAMENOM , write = set_DopUslNAMENOM};
   virtual TFIBWideStringField * get_DopUslNAMENOM(void)=0;
   virtual void set_DopUslNAMENOM(TFIBWideStringField * DopUslNAMENOM)=0;

   __property TFIBWideStringField * DopUslNAMEED = {read = get_DopUslNAMEED , write = set_DopUslNAMEED};
   virtual TFIBWideStringField * get_DopUslNAMEED(void)=0;
   virtual void set_DopUslNAMEED(TFIBWideStringField * DopUslNAMEED)=0;

   __property TpFIBDataSet * PerformedWork = {read = get_PerformedWork , write = set_PerformedWork};
   virtual TpFIBDataSet * get_PerformedWork(void)=0;
   virtual void set_PerformedWork(TpFIBDataSet * PerformedWork)=0;

   __property TDataSource * DataSourcePerformedWork = {read = get_DataSourcePerformedWork , write = set_DataSourcePerformedWork};
   virtual TDataSource * get_DataSourcePerformedWork(void)=0;
   virtual void set_DataSourcePerformedWork(TDataSource * DataSourcePerformedWork)=0;

   __property TFIBLargeIntField * PerformedWorkID_REM_ZPERFWORK = {read = get_PerformedWorkID_REM_ZPERFWORK , write = set_PerformedWorkID_REM_ZPERFWORK};
   virtual TFIBLargeIntField * get_PerformedWorkID_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkID_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkID_REM_ZPERFWORK)=0;

   __property TFIBWideStringField * PerformedWorkGID_REM_ZPERFWORK = {read = get_PerformedWorkGID_REM_ZPERFWORK , write = set_PerformedWorkGID_REM_ZPERFWORK};
   virtual TFIBWideStringField * get_PerformedWorkGID_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkGID_REM_ZPERFWORK(TFIBWideStringField * PerformedWorkGID_REM_ZPERFWORK)=0;

   __property TFIBLargeIntField * PerformedWorkIDBASE_REM_ZPERFWORK = {read = get_PerformedWorkIDBASE_REM_ZPERFWORK , write = set_PerformedWorkIDBASE_REM_ZPERFWORK};
   virtual TFIBLargeIntField * get_PerformedWorkIDBASE_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkIDBASE_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDBASE_REM_ZPERFWORK)=0;

   __property TFIBLargeIntField * PerformedWorkIDZ_REM_ZPERFWORK = {read = get_PerformedWorkIDZ_REM_ZPERFWORK , write = set_PerformedWorkIDZ_REM_ZPERFWORK};
   virtual TFIBLargeIntField * get_PerformedWorkIDZ_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkIDZ_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDZ_REM_ZPERFWORK)=0;

   __property TFIBLargeIntField * PerformedWorkIDNOM_REM_ZPERFWORK = {read = get_PerformedWorkIDNOM_REM_ZPERFWORK , write = set_PerformedWorkIDNOM_REM_ZPERFWORK};
   virtual TFIBLargeIntField * get_PerformedWorkIDNOM_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkIDNOM_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDNOM_REM_ZPERFWORK)=0;

   __property TFIBLargeIntField * PerformedWorkIDED_REM_ZPERFWORK = {read = get_PerformedWorkIDED_REM_ZPERFWORK , write = set_PerformedWorkIDED_REM_ZPERFWORK};
   virtual TFIBLargeIntField * get_PerformedWorkIDED_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkIDED_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDED_REM_ZPERFWORK)=0;

   __property TFIBBCDField * PerformedWorkKOL_REM_ZPERFWORK = {read = get_PerformedWorkKOL_REM_ZPERFWORK , write = set_PerformedWorkKOL_REM_ZPERFWORK};
   virtual TFIBBCDField * get_PerformedWorkKOL_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkKOL_REM_ZPERFWORK(TFIBBCDField * PerformedWorkKOL_REM_ZPERFWORK)=0;

   __property TFIBBCDField * PerformedWorkKF_REM_ZPERFWORK = {read = get_PerformedWorkKF_REM_ZPERFWORK , write = set_PerformedWorkKF_REM_ZPERFWORK};
   virtual TFIBBCDField * get_PerformedWorkKF_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkKF_REM_ZPERFWORK(TFIBBCDField * PerformedWorkKF_REM_ZPERFWORK)=0;

   __property TFIBBCDField * PerformedWorkPRICE_REM_ZPERFWORK = {read = get_PerformedWorkPRICE_REM_ZPERFWORK , write = set_PerformedWorkPRICE_REM_ZPERFWORK};
   virtual TFIBBCDField * get_PerformedWorkPRICE_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkPRICE_REM_ZPERFWORK(TFIBBCDField * PerformedWorkPRICE_REM_ZPERFWORK)=0;

   __property TFIBBCDField * PerformedWorkSUM_REM_ZPERFWORK = {read = get_PerformedWorkSUM_REM_ZPERFWORK , write = set_PerformedWorkSUM_REM_ZPERFWORK};
   virtual TFIBBCDField * get_PerformedWorkSUM_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkSUM_REM_ZPERFWORK(TFIBBCDField * PerformedWorkSUM_REM_ZPERFWORK)=0;

   __property TFIBWideStringField * PerformedWorkTEXTNOM_REM_ZPERFWORK = {read = get_PerformedWorkTEXTNOM_REM_ZPERFWORK , write = set_PerformedWorkTEXTNOM_REM_ZPERFWORK};
   virtual TFIBWideStringField * get_PerformedWorkTEXTNOM_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkTEXTNOM_REM_ZPERFWORK(TFIBWideStringField * PerformedWorkTEXTNOM_REM_ZPERFWORK)=0;

   __property TFIBDateTimeField * PerformedWorkPOS_REM_ZPERFWORK = {read = get_PerformedWorkPOS_REM_ZPERFWORK , write = set_PerformedWorkPOS_REM_ZPERFWORK};
   virtual TFIBDateTimeField * get_PerformedWorkPOS_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkPOS_REM_ZPERFWORK(TFIBDateTimeField * PerformedWorkPOS_REM_ZPERFWORK)=0;

   __property TFIBSmallIntField * PerformedWorkRESULT_REM_ZPERFWORK = {read = get_PerformedWorkRESULT_REM_ZPERFWORK , write = set_PerformedWorkRESULT_REM_ZPERFWORK};
   virtual TFIBSmallIntField * get_PerformedWorkRESULT_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkRESULT_REM_ZPERFWORK(TFIBSmallIntField * PerformedWorkRESULT_REM_ZPERFWORK)=0;

   __property TFIBSmallIntField * PerformedWorkADDACT_REM_ZPERFWORK = {read = get_PerformedWorkADDACT_REM_ZPERFWORK , write = set_PerformedWorkADDACT_REM_ZPERFWORK};
   virtual TFIBSmallIntField * get_PerformedWorkADDACT_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkADDACT_REM_ZPERFWORK(TFIBSmallIntField * PerformedWorkADDACT_REM_ZPERFWORK)=0;

   __property TFIBSmallIntField * PerformedWorkSHOWFORUSER_REM_ZPERFWORK = {read = get_PerformedWorkSHOWFORUSER_REM_ZPERFWORK , write = set_PerformedWorkSHOWFORUSER_REM_ZPERFWORK};
   virtual TFIBSmallIntField * get_PerformedWorkSHOWFORUSER_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkSHOWFORUSER_REM_ZPERFWORK(TFIBSmallIntField * PerformedWorkSHOWFORUSER_REM_ZPERFWORK)=0;

   __property TFIBWideStringField * PerformedWorkNAMENOM = {read = get_PerformedWorkNAMENOM , write = set_PerformedWorkNAMENOM};
   virtual TFIBWideStringField * get_PerformedWorkNAMENOM(void)=0;
   virtual void set_PerformedWorkNAMENOM(TFIBWideStringField * PerformedWorkNAMENOM)=0;

   __property TFIBWideStringField * PerformedWorkNAMEED = {read = get_PerformedWorkNAMEED , write = set_PerformedWorkNAMEED};
   virtual TFIBWideStringField * get_PerformedWorkNAMEED(void)=0;
   virtual void set_PerformedWorkNAMEED(TFIBWideStringField * PerformedWorkNAMEED)=0;

   __property TFIBLargeIntField * PerformedWorkIDUSER_REM_ZPERFWORK = {read = get_PerformedWorkIDUSER_REM_ZPERFWORK , write = set_PerformedWorkIDUSER_REM_ZPERFWORK};
   virtual TFIBLargeIntField * get_PerformedWorkIDUSER_REM_ZPERFWORK(void)=0;
   virtual void set_PerformedWorkIDUSER_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDUSER_REM_ZPERFWORK)=0;

   __property TFIBWideStringField * PerformedWorkNAME_USER = {read = get_PerformedWorkNAME_USER , write = set_PerformedWorkNAME_USER};
   virtual TFIBWideStringField * get_PerformedWorkNAME_USER(void)=0;
   virtual void set_PerformedWorkNAME_USER(TFIBWideStringField * PerformedWorkNAME_USER)=0;

   __property TFIBLargeIntField * GurZIDMEXANIK_REM_Z = {read = get_GurZIDMEXANIK_REM_Z , write = set_GurZIDMEXANIK_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDMEXANIK_REM_Z(void)=0;
   virtual void set_GurZIDMEXANIK_REM_Z(TFIBLargeIntField * GurZIDMEXANIK_REM_Z)=0;

   __property TFIBLargeIntField * GurZIDBRAND_REM_Z = {read = get_GurZIDBRAND_REM_Z , write = set_GurZIDBRAND_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDBRAND_REM_Z(void)=0;
   virtual void set_GurZIDBRAND_REM_Z(TFIBLargeIntField * GurZIDBRAND_REM_Z)=0;

   __property TFIBLargeIntField * GurZIDACTCAT_REM_Z = {read = get_GurZIDACTCAT_REM_Z , write = set_GurZIDACTCAT_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDACTCAT_REM_Z(void)=0;
   virtual void set_GurZIDACTCAT_REM_Z(TFIBLargeIntField * GurZIDACTCAT_REM_Z)=0;

   __property TFIBWideStringField * GurZGUID_REM_Z = {read = get_GurZGUID_REM_Z , write = set_GurZGUID_REM_Z};
   virtual TFIBWideStringField * get_GurZGUID_REM_Z(void)=0;
   virtual void set_GurZGUID_REM_Z(TFIBWideStringField * GurZGUID_REM_Z)=0;

   __property TFIBLargeIntField * GurZIDZOSN_REM_Z = {read = get_GurZIDZOSN_REM_Z , write = set_GurZIDZOSN_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDZOSN_REM_Z(void)=0;
   virtual void set_GurZIDZOSN_REM_Z(TFIBLargeIntField * GurZIDZOSN_REM_Z)=0;

   __property TFIBSmallIntField * GurZFL_POVTOR_REM_Z = {read = get_GurZFL_POVTOR_REM_Z , write = set_GurZFL_POVTOR_REM_Z};
   virtual TFIBSmallIntField * get_GurZFL_POVTOR_REM_Z(void)=0;
   virtual void set_GurZFL_POVTOR_REM_Z(TFIBSmallIntField * GurZFL_POVTOR_REM_Z)=0;

   __property TFIBWideStringField * GurZDILER_NUMZ_REM_Z = {read = get_GurZDILER_NUMZ_REM_Z , write = set_GurZDILER_NUMZ_REM_Z};
   virtual TFIBWideStringField * get_GurZDILER_NUMZ_REM_Z(void)=0;
   virtual void set_GurZDILER_NUMZ_REM_Z(TFIBWideStringField * GurZDILER_NUMZ_REM_Z)=0;

   __property TFIBDateTimeField * GurZDILER_POSZ_REM_Z = {read = get_GurZDILER_POSZ_REM_Z , write = set_GurZDILER_POSZ_REM_Z};
   virtual TFIBDateTimeField * get_GurZDILER_POSZ_REM_Z(void)=0;
   virtual void set_GurZDILER_POSZ_REM_Z(TFIBDateTimeField * GurZDILER_POSZ_REM_Z)=0;

   __property TFIBWideStringField * GurZDILER_GUIDZ_REM_Z = {read = get_GurZDILER_GUIDZ_REM_Z , write = set_GurZDILER_GUIDZ_REM_Z};
   virtual TFIBWideStringField * get_GurZDILER_GUIDZ_REM_Z(void)=0;
   virtual void set_GurZDILER_GUIDZ_REM_Z(TFIBWideStringField * GurZDILER_GUIDZ_REM_Z)=0;

   __property TFIBWideStringField * GurZSC_NUMZ_REM_Z = {read = get_GurZSC_NUMZ_REM_Z , write = set_GurZSC_NUMZ_REM_Z};
   virtual TFIBWideStringField * get_GurZSC_NUMZ_REM_Z(void)=0;
   virtual void set_GurZSC_NUMZ_REM_Z(TFIBWideStringField * GurZSC_NUMZ_REM_Z)=0;

   __property TFIBDateTimeField * GurZSC_POSZ_REM_Z = {read = get_GurZSC_POSZ_REM_Z , write = set_GurZSC_POSZ_REM_Z};
   virtual TFIBDateTimeField * get_GurZSC_POSZ_REM_Z(void)=0;
   virtual void set_GurZSC_POSZ_REM_Z(TFIBDateTimeField * GurZSC_POSZ_REM_Z)=0;

   __property TFIBWideStringField * GurZSC_GUIDZ_REM_Z = {read = get_GurZSC_GUIDZ_REM_Z , write = set_GurZSC_GUIDZ_REM_Z};
   virtual TFIBWideStringField * get_GurZSC_GUIDZ_REM_Z(void)=0;
   virtual void set_GurZSC_GUIDZ_REM_Z(TFIBWideStringField * GurZSC_GUIDZ_REM_Z)=0;

   __property TFIBSmallIntField * GurZFL_ADDREPORT_REM_Z = {read = get_GurZFL_ADDREPORT_REM_Z , write = set_GurZFL_ADDREPORT_REM_Z};
   virtual TFIBSmallIntField * get_GurZFL_ADDREPORT_REM_Z(void)=0;
   virtual void set_GurZFL_ADDREPORT_REM_Z(TFIBSmallIntField * GurZFL_ADDREPORT_REM_Z)=0;

   __property TFIBWideStringField * GurZSERNUM_STR_REM_Z = {read = get_GurZSERNUM_STR_REM_Z , write = set_GurZSERNUM_STR_REM_Z};
   virtual TFIBWideStringField * get_GurZSERNUM_STR_REM_Z(void)=0;
   virtual void set_GurZSERNUM_STR_REM_Z(TFIBWideStringField * GurZSERNUM_STR_REM_Z)=0;

   __property TFIBWideStringField * GurZNAME_MEXANIK = {read = get_GurZNAME_MEXANIK , write = set_GurZNAME_MEXANIK};
   virtual TFIBWideStringField * get_GurZNAME_MEXANIK(void)=0;
   virtual void set_GurZNAME_MEXANIK(TFIBWideStringField * GurZNAME_MEXANIK)=0;

   __property TFIBWideStringField * GurZNAME_SBRAND = {read = get_GurZNAME_SBRAND , write = set_GurZNAME_SBRAND};
   virtual TFIBWideStringField * get_GurZNAME_SBRAND(void)=0;
   virtual void set_GurZNAME_SBRAND(TFIBWideStringField * GurZNAME_SBRAND)=0;

   __property TFIBWideStringField * GurZNAME_REM_SACTCATEGORY = {read = get_GurZNAME_REM_SACTCATEGORY , write = set_GurZNAME_REM_SACTCATEGORY};
   virtual TFIBWideStringField * get_GurZNAME_REM_SACTCATEGORY(void)=0;
   virtual void set_GurZNAME_REM_SACTCATEGORY(TFIBWideStringField * GurZNAME_REM_SACTCATEGORY)=0;

   __property TFIBLargeIntField * GurZIDHW_REM_Z = {read = get_GurZIDHW_REM_Z , write = set_GurZIDHW_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDHW_REM_Z(void)=0;
   virtual void set_GurZIDHW_REM_Z(TFIBLargeIntField * GurZIDHW_REM_Z)=0;

   __property TFIBLargeIntField * GurZIDKKT_REM_Z = {read = get_GurZIDKKT_REM_Z , write = set_GurZIDKKT_REM_Z};
   virtual TFIBLargeIntField * get_GurZIDKKT_REM_Z(void)=0;
   virtual void set_GurZIDKKT_REM_Z(TFIBLargeIntField * GurZIDKKT_REM_Z)=0;

   __property TFIBWideStringField * GurZNAME_REM_SHARDWARE = {read = get_GurZNAME_REM_SHARDWARE , write = set_GurZNAME_REM_SHARDWARE};
   virtual TFIBWideStringField * get_GurZNAME_REM_SHARDWARE(void)=0;
   virtual void set_GurZNAME_REM_SHARDWARE(TFIBWideStringField * GurZNAME_REM_SHARDWARE)=0;

   __property TFIBWideStringField * GurZSERNUM_REM_SHARDWARE = {read = get_GurZSERNUM_REM_SHARDWARE , write = set_GurZSERNUM_REM_SHARDWARE};
   virtual TFIBWideStringField * get_GurZSERNUM_REM_SHARDWARE(void)=0;
   virtual void set_GurZSERNUM_REM_SHARDWARE(TFIBWideStringField * GurZSERNUM_REM_SHARDWARE)=0;

   __property TFIBWideStringField * GurZSERNUM2_REM_SHARDWARE = {read = get_GurZSERNUM2_REM_SHARDWARE , write = set_GurZSERNUM2_REM_SHARDWARE};
   virtual TFIBWideStringField * get_GurZSERNUM2_REM_SHARDWARE(void)=0;
   virtual void set_GurZSERNUM2_REM_SHARDWARE(TFIBWideStringField * GurZSERNUM2_REM_SHARDWARE)=0;

   __property TFIBWideStringField * GurZNAME_REM_SKKT = {read = get_GurZNAME_REM_SKKT , write = set_GurZNAME_REM_SKKT};
   virtual TFIBWideStringField * get_GurZNAME_REM_SKKT(void)=0;
   virtual void set_GurZNAME_REM_SKKT(TFIBWideStringField * GurZNAME_REM_SKKT)=0;

   __property TFIBWideStringField * GurZSERNUM_REM_SKKT = {read = get_GurZSERNUM_REM_SKKT , write = set_GurZSERNUM_REM_SKKT};
   virtual TFIBWideStringField * get_GurZSERNUM_REM_SKKT(void)=0;
   virtual void set_GurZSERNUM_REM_SKKT(TFIBWideStringField * GurZSERNUM_REM_SKKT)=0;

   __property TFIBIntegerField * GurZFL_KLIENT_UVEDOML_REM_Z = {read = get_GurZFL_KLIENT_UVEDOML_REM_Z , write = set_GurZFL_KLIENT_UVEDOML_REM_Z};
   virtual TFIBIntegerField * get_GurZFL_KLIENT_UVEDOML_REM_Z(void)=0;
   virtual void set_GurZFL_KLIENT_UVEDOML_REM_Z(TFIBIntegerField * GurZFL_KLIENT_UVEDOML_REM_Z)=0;

   __property TFIBIntegerField * GurZFL_TREB_KONS_KL_REM_Z = {read = get_GurZFL_TREB_KONS_KL_REM_Z , write = set_GurZFL_TREB_KONS_KL_REM_Z};
   virtual TFIBIntegerField * get_GurZFL_TREB_KONS_KL_REM_Z(void)=0;
   virtual void set_GurZFL_TREB_KONS_KL_REM_Z(TFIBIntegerField * GurZFL_TREB_KONS_KL_REM_Z)=0;

   __property TFIBIntegerField * GurZFL_KL_OTV_NA_ZAPROS_REM_Z = {read = get_GurZFL_KL_OTV_NA_ZAPROS_REM_Z , write = set_GurZFL_KL_OTV_NA_ZAPROS_REM_Z};
   virtual TFIBIntegerField * get_GurZFL_KL_OTV_NA_ZAPROS_REM_Z(void)=0;
   virtual void set_GurZFL_KL_OTV_NA_ZAPROS_REM_Z(TFIBIntegerField * GurZFL_KL_OTV_NA_ZAPROS_REM_Z)=0;

   __property TFIBWideStringField * GurZPREFIKS_NUM_REM_Z = {read = get_GurZPREFIKS_NUM_REM_Z , write = set_GurZPREFIKS_NUM_REM_Z};
   virtual TFIBWideStringField * get_GurZPREFIKS_NUM_REM_Z(void)=0;
   virtual void set_GurZPREFIKS_NUM_REM_Z(TFIBWideStringField * GurZPREFIKS_NUM_REM_Z)=0;

   __property TFIBWideStringField * GurZNUM_GARDOC_REM_Z = {read = get_GurZNUM_GARDOC_REM_Z , write = set_GurZNUM_GARDOC_REM_Z};
   virtual TFIBWideStringField * get_GurZNUM_GARDOC_REM_Z(void)=0;
   virtual void set_GurZNUM_GARDOC_REM_Z(TFIBWideStringField * GurZNUM_GARDOC_REM_Z)=0;

   __property TFIBIntegerField * GurZFL_FICTIV_REM_Z = {read = get_GurZFL_FICTIV_REM_Z , write = set_GurZFL_FICTIV_REM_Z};
   virtual TFIBIntegerField * get_GurZFL_FICTIV_REM_Z(void)=0;
   virtual void set_GurZFL_FICTIV_REM_Z(TFIBIntegerField * GurZFL_FICTIV_REM_Z)=0;

   __property TFIBSmallIntField * GurZFL_NE_OTCH_REM_Z = {read = get_GurZFL_NE_OTCH_REM_Z , write = set_GurZFL_NE_OTCH_REM_Z};
   virtual TFIBSmallIntField * get_GurZFL_NE_OTCH_REM_Z(void)=0;
   virtual void set_GurZFL_NE_OTCH_REM_Z(TFIBSmallIntField * GurZFL_NE_OTCH_REM_Z)=0;

   __property TFIBSmallIntField * GurZFL_NADO_OTCH_REM_Z = {read = get_GurZFL_NADO_OTCH_REM_Z , write = set_GurZFL_NADO_OTCH_REM_Z};
   virtual TFIBSmallIntField * get_GurZFL_NADO_OTCH_REM_Z(void)=0;
   virtual void set_GurZFL_NADO_OTCH_REM_Z(TFIBSmallIntField * GurZFL_NADO_OTCH_REM_Z)=0;

   __property TFIBSmallIntField * GurZFL_ISM_GARDOC_REM_Z = {read = get_GurZFL_ISM_GARDOC_REM_Z , write = set_GurZFL_ISM_GARDOC_REM_Z};
   virtual TFIBSmallIntField * get_GurZFL_ISM_GARDOC_REM_Z(void)=0;
   virtual void set_GurZFL_ISM_GARDOC_REM_Z(TFIBSmallIntField * GurZFL_ISM_GARDOC_REM_Z)=0;

   __property TFIBSmallIntField * GurZFL_ISM_SERNUM_REM_Z = {read = get_GurZFL_ISM_SERNUM_REM_Z , write = set_GurZFL_ISM_SERNUM_REM_Z};
   virtual TFIBSmallIntField * get_GurZFL_ISM_SERNUM_REM_Z(void)=0;
   virtual void set_GurZFL_ISM_SERNUM_REM_Z(TFIBSmallIntField * GurZFL_ISM_SERNUM_REM_Z)=0;

   __property TFIBSmallIntField * GurZFL_ISM_SERNUM2_REM_Z = {read = get_GurZFL_ISM_SERNUM2_REM_Z , write = set_GurZFL_ISM_SERNUM2_REM_Z};
   virtual TFIBSmallIntField * get_GurZFL_ISM_SERNUM2_REM_Z(void)=0;
   virtual void set_GurZFL_ISM_SERNUM2_REM_Z(TFIBSmallIntField * GurZFL_ISM_SERNUM2_REM_Z)=0;

   __property TFIBWideStringField * GurZNUM_GARDOC_NEW_REM_Z = {read = get_GurZNUM_GARDOC_NEW_REM_Z , write = set_GurZNUM_GARDOC_NEW_REM_Z};
   virtual TFIBWideStringField * get_GurZNUM_GARDOC_NEW_REM_Z(void)=0;
   virtual void set_GurZNUM_GARDOC_NEW_REM_Z(TFIBWideStringField * GurZNUM_GARDOC_NEW_REM_Z)=0;

   __property TFIBWideStringField * GurZSERNUM_NEW_REM_Z = {read = get_GurZSERNUM_NEW_REM_Z , write = set_GurZSERNUM_NEW_REM_Z};
   virtual TFIBWideStringField * get_GurZSERNUM_NEW_REM_Z(void)=0;
   virtual void set_GurZSERNUM_NEW_REM_Z(TFIBWideStringField * GurZSERNUM_NEW_REM_Z)=0;

   __property TFIBWideStringField * GurZSERNUM2_NEW_REM_Z = {read = get_GurZSERNUM2_NEW_REM_Z , write = set_GurZSERNUM2_NEW_REM_Z};
   virtual TFIBWideStringField * get_GurZSERNUM2_NEW_REM_Z(void)=0;
   virtual void set_GurZSERNUM2_NEW_REM_Z(TFIBWideStringField * GurZSERNUM2_NEW_REM_Z)=0;

   __property TFIBSmallIntField * GurZGOTOVO_K_VIDACHE_REM_Z = {read = get_GurZGOTOVO_K_VIDACHE_REM_Z , write = set_GurZGOTOVO_K_VIDACHE_REM_Z};
   virtual TFIBSmallIntField * get_GurZGOTOVO_K_VIDACHE_REM_Z(void)=0;
   virtual void set_GurZGOTOVO_K_VIDACHE_REM_Z(TFIBSmallIntField * GurZGOTOVO_K_VIDACHE_REM_Z)=0;

   __property TDataSource * DataSourceGurZ_1 = {read = get_DataSourceGurZ_1 , write = set_DataSourceGurZ_1};
   virtual TDataSource * get_DataSourceGurZ_1(void)=0;
   virtual void set_DataSourceGurZ_1(TDataSource * DataSourceGurZ_1)=0;

   __property TpFIBDataSet * GurZ_1 = {read = get_GurZ_1 , write = set_GurZ_1};
   virtual TpFIBDataSet * get_GurZ_1(void)=0;
   virtual void set_GurZ_1(TpFIBDataSet * GurZ_1)=0;

   __property TFIBLargeIntField * GurZ_1ID_REM_Z_1 = {read = get_GurZ_1ID_REM_Z_1 , write = set_GurZ_1ID_REM_Z_1};
   virtual TFIBLargeIntField * get_GurZ_1ID_REM_Z_1(void)=0;
   virtual void set_GurZ_1ID_REM_Z_1(TFIBLargeIntField * GurZ_1ID_REM_Z_1)=0;

   __property TFIBLargeIntField * GurZ_1IDBASE_REM_Z_1 = {read = get_GurZ_1IDBASE_REM_Z_1 , write = set_GurZ_1IDBASE_REM_Z_1};
   virtual TFIBLargeIntField * get_GurZ_1IDBASE_REM_Z_1(void)=0;
   virtual void set_GurZ_1IDBASE_REM_Z_1(TFIBLargeIntField * GurZ_1IDBASE_REM_Z_1)=0;

   __property TFIBLargeIntField * GurZ_1IDZ_REM_Z_1 = {read = get_GurZ_1IDZ_REM_Z_1 , write = set_GurZ_1IDZ_REM_Z_1};
   virtual TFIBLargeIntField * get_GurZ_1IDZ_REM_Z_1(void)=0;
   virtual void set_GurZ_1IDZ_REM_Z_1(TFIBLargeIntField * GurZ_1IDZ_REM_Z_1)=0;

   __property TFIBLargeIntField * GurZ_1IDPRMODEL_REM_Z_1 = {read = get_GurZ_1IDPRMODEL_REM_Z_1 , write = set_GurZ_1IDPRMODEL_REM_Z_1};
   virtual TFIBLargeIntField * get_GurZ_1IDPRMODEL_REM_Z_1(void)=0;
   virtual void set_GurZ_1IDPRMODEL_REM_Z_1(TFIBLargeIntField * GurZ_1IDPRMODEL_REM_Z_1)=0;

   __property TFIBLargeIntField * GurZ_1IDPRODUCER_REM_Z_1 = {read = get_GurZ_1IDPRODUCER_REM_Z_1 , write = set_GurZ_1IDPRODUCER_REM_Z_1};
   virtual TFIBLargeIntField * get_GurZ_1IDPRODUCER_REM_Z_1(void)=0;
   virtual void set_GurZ_1IDPRODUCER_REM_Z_1(TFIBLargeIntField * GurZ_1IDPRODUCER_REM_Z_1)=0;

   __property TFIBIntegerField * GurZ_1FL_VKL_REM_Z_1 = {read = get_GurZ_1FL_VKL_REM_Z_1 , write = set_GurZ_1FL_VKL_REM_Z_1};
   virtual TFIBIntegerField * get_GurZ_1FL_VKL_REM_Z_1(void)=0;
   virtual void set_GurZ_1FL_VKL_REM_Z_1(TFIBIntegerField * GurZ_1FL_VKL_REM_Z_1)=0;

   __property TFIBIntegerField * GurZ_1FL_ZIP_REM_Z_1 = {read = get_GurZ_1FL_ZIP_REM_Z_1 , write = set_GurZ_1FL_ZIP_REM_Z_1};
   virtual TFIBIntegerField * get_GurZ_1FL_ZIP_REM_Z_1(void)=0;
   virtual void set_GurZ_1FL_ZIP_REM_Z_1(TFIBIntegerField * GurZ_1FL_ZIP_REM_Z_1)=0;

   __property TFIBIntegerField * GurZ_1FL_DEFECT_DEMO_REM_Z_1 = {read = get_GurZ_1FL_DEFECT_DEMO_REM_Z_1 , write = set_GurZ_1FL_DEFECT_DEMO_REM_Z_1};
   virtual TFIBIntegerField * get_GurZ_1FL_DEFECT_DEMO_REM_Z_1(void)=0;
   virtual void set_GurZ_1FL_DEFECT_DEMO_REM_Z_1(TFIBIntegerField * GurZ_1FL_DEFECT_DEMO_REM_Z_1)=0;

   __property TFIBIntegerField * GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1 = {read = get_GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1 , write = set_GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1};
   virtual TFIBIntegerField * get_GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1(void)=0;
   virtual void set_GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1(TFIBIntegerField * GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1)=0;

   __property TFIBLargeIntField * GurZ_1IDSELLER_REM_Z_1 = {read = get_GurZ_1IDSELLER_REM_Z_1 , write = set_GurZ_1IDSELLER_REM_Z_1};
   virtual TFIBLargeIntField * get_GurZ_1IDSELLER_REM_Z_1(void)=0;
   virtual void set_GurZ_1IDSELLER_REM_Z_1(TFIBLargeIntField * GurZ_1IDSELLER_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1KLIENT_EMAIL_REM_Z_1 = {read = get_GurZ_1KLIENT_EMAIL_REM_Z_1 , write = set_GurZ_1KLIENT_EMAIL_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1KLIENT_EMAIL_REM_Z_1(void)=0;
   virtual void set_GurZ_1KLIENT_EMAIL_REM_Z_1(TFIBWideStringField * GurZ_1KLIENT_EMAIL_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1KLIENT_DOP_INFO_REM_Z_1 = {read = get_GurZ_1KLIENT_DOP_INFO_REM_Z_1 , write = set_GurZ_1KLIENT_DOP_INFO_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1KLIENT_DOP_INFO_REM_Z_1(void)=0;
   virtual void set_GurZ_1KLIENT_DOP_INFO_REM_Z_1(TFIBWideStringField * GurZ_1KLIENT_DOP_INFO_REM_Z_1)=0;

   __property TFIBLargeIntField * GurZ_1IDADRKV_REM_Z_1 = {read = get_GurZ_1IDADRKV_REM_Z_1 , write = set_GurZ_1IDADRKV_REM_Z_1};
   virtual TFIBLargeIntField * get_GurZ_1IDADRKV_REM_Z_1(void)=0;
   virtual void set_GurZ_1IDADRKV_REM_Z_1(TFIBLargeIntField * GurZ_1IDADRKV_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1NAME_SPRODUCER = {read = get_GurZ_1NAME_SPRODUCER , write = set_GurZ_1NAME_SPRODUCER};
   virtual TFIBWideStringField * get_GurZ_1NAME_SPRODUCER(void)=0;
   virtual void set_GurZ_1NAME_SPRODUCER(TFIBWideStringField * GurZ_1NAME_SPRODUCER)=0;

   __property TFIBWideStringField * GurZ_1NAME_REM_SPRMODEL = {read = get_GurZ_1NAME_REM_SPRMODEL , write = set_GurZ_1NAME_REM_SPRMODEL};
   virtual TFIBWideStringField * get_GurZ_1NAME_REM_SPRMODEL(void)=0;
   virtual void set_GurZ_1NAME_REM_SPRMODEL(TFIBWideStringField * GurZ_1NAME_REM_SPRMODEL)=0;

   __property TFIBWideStringField * GurZ_1NAME_SSELLER = {read = get_GurZ_1NAME_SSELLER , write = set_GurZ_1NAME_SSELLER};
   virtual TFIBWideStringField * get_GurZ_1NAME_SSELLER(void)=0;
   virtual void set_GurZ_1NAME_SSELLER(TFIBWideStringField * GurZ_1NAME_SSELLER)=0;

   __property TFIBWideStringField * GurZ_1NAME_SADR_DOM = {read = get_GurZ_1NAME_SADR_DOM , write = set_GurZ_1NAME_SADR_DOM};
   virtual TFIBWideStringField * get_GurZ_1NAME_SADR_DOM(void)=0;
   virtual void set_GurZ_1NAME_SADR_DOM(TFIBWideStringField * GurZ_1NAME_SADR_DOM)=0;

   __property TFIBWideStringField * GurZ_1NAME_SADR_STREET = {read = get_GurZ_1NAME_SADR_STREET , write = set_GurZ_1NAME_SADR_STREET};
   virtual TFIBWideStringField * get_GurZ_1NAME_SADR_STREET(void)=0;
   virtual void set_GurZ_1NAME_SADR_STREET(TFIBWideStringField * GurZ_1NAME_SADR_STREET)=0;

   __property TFIBWideStringField * GurZ_1POSTCODE_SADR_STREET = {read = get_GurZ_1POSTCODE_SADR_STREET , write = set_GurZ_1POSTCODE_SADR_STREET};
   virtual TFIBWideStringField * get_GurZ_1POSTCODE_SADR_STREET(void)=0;
   virtual void set_GurZ_1POSTCODE_SADR_STREET(TFIBWideStringField * GurZ_1POSTCODE_SADR_STREET)=0;

   __property TFIBWideStringField * GurZ_1NAME_SADR_NASPUNKT = {read = get_GurZ_1NAME_SADR_NASPUNKT , write = set_GurZ_1NAME_SADR_NASPUNKT};
   virtual TFIBWideStringField * get_GurZ_1NAME_SADR_NASPUNKT(void)=0;
   virtual void set_GurZ_1NAME_SADR_NASPUNKT(TFIBWideStringField * GurZ_1NAME_SADR_NASPUNKT)=0;

   __property TFIBWideStringField * GurZ_1NAME_SADR_REGION = {read = get_GurZ_1NAME_SADR_REGION , write = set_GurZ_1NAME_SADR_REGION};
   virtual TFIBWideStringField * get_GurZ_1NAME_SADR_REGION(void)=0;
   virtual void set_GurZ_1NAME_SADR_REGION(TFIBWideStringField * GurZ_1NAME_SADR_REGION)=0;

   __property TFIBWideStringField * GurZ_1CODE_SADR_REGION = {read = get_GurZ_1CODE_SADR_REGION , write = set_GurZ_1CODE_SADR_REGION};
   virtual TFIBWideStringField * get_GurZ_1CODE_SADR_REGION(void)=0;
   virtual void set_GurZ_1CODE_SADR_REGION(TFIBWideStringField * GurZ_1CODE_SADR_REGION)=0;

   __property TFIBWideStringField * GurZ_1NAME_SADR_KV = {read = get_GurZ_1NAME_SADR_KV , write = set_GurZ_1NAME_SADR_KV};
   virtual TFIBWideStringField * get_GurZ_1NAME_SADR_KV(void)=0;
   virtual void set_GurZ_1NAME_SADR_KV(TFIBWideStringField * GurZ_1NAME_SADR_KV)=0;

   __property TFIBIntegerField * GurZ_1FL_PLOMBA_SET_REM_Z_1 = {read = get_GurZ_1FL_PLOMBA_SET_REM_Z_1 , write = set_GurZ_1FL_PLOMBA_SET_REM_Z_1};
   virtual TFIBIntegerField * get_GurZ_1FL_PLOMBA_SET_REM_Z_1(void)=0;
   virtual void set_GurZ_1FL_PLOMBA_SET_REM_Z_1(TFIBIntegerField * GurZ_1FL_PLOMBA_SET_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1TEXT_PLOMBA_REM_Z_1 = {read = get_GurZ_1TEXT_PLOMBA_REM_Z_1 , write = set_GurZ_1TEXT_PLOMBA_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1TEXT_PLOMBA_REM_Z_1(void)=0;
   virtual void set_GurZ_1TEXT_PLOMBA_REM_Z_1(TFIBWideStringField * GurZ_1TEXT_PLOMBA_REM_Z_1)=0;

   __property TFIBIntegerField * GurZ_1FL_PROBLEM_DEVICE_REM_Z_1 = {read = get_GurZ_1FL_PROBLEM_DEVICE_REM_Z_1 , write = set_GurZ_1FL_PROBLEM_DEVICE_REM_Z_1};
   virtual TFIBIntegerField * get_GurZ_1FL_PROBLEM_DEVICE_REM_Z_1(void)=0;
   virtual void set_GurZ_1FL_PROBLEM_DEVICE_REM_Z_1(TFIBIntegerField * GurZ_1FL_PROBLEM_DEVICE_REM_Z_1)=0;

   __property TFIBIntegerField * GurZ_1FL_PROBLEM_KLIENT_REM_Z_1 = {read = get_GurZ_1FL_PROBLEM_KLIENT_REM_Z_1 , write = set_GurZ_1FL_PROBLEM_KLIENT_REM_Z_1};
   virtual TFIBIntegerField * get_GurZ_1FL_PROBLEM_KLIENT_REM_Z_1(void)=0;
   virtual void set_GurZ_1FL_PROBLEM_KLIENT_REM_Z_1(TFIBIntegerField * GurZ_1FL_PROBLEM_KLIENT_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1NEISPR_ENG_REM_Z_1 = {read = get_GurZ_1NEISPR_ENG_REM_Z_1 , write = set_GurZ_1NEISPR_ENG_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1NEISPR_ENG_REM_Z_1(void)=0;
   virtual void set_GurZ_1NEISPR_ENG_REM_Z_1(TFIBWideStringField * GurZ_1NEISPR_ENG_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1DEFECT_ENG_REM_Z_1 = {read = get_GurZ_1DEFECT_ENG_REM_Z_1 , write = set_GurZ_1DEFECT_ENG_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1DEFECT_ENG_REM_Z_1(void)=0;
   virtual void set_GurZ_1DEFECT_ENG_REM_Z_1(TFIBWideStringField * GurZ_1DEFECT_ENG_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1SOLUTION_ENG_REM_Z_1 = {read = get_GurZ_1SOLUTION_ENG_REM_Z_1 , write = set_GurZ_1SOLUTION_ENG_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1SOLUTION_ENG_REM_Z_1(void)=0;
   virtual void set_GurZ_1SOLUTION_ENG_REM_Z_1(TFIBWideStringField * GurZ_1SOLUTION_ENG_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1STR_CODE_VIGR_REM_Z_1 = {read = get_GurZ_1STR_CODE_VIGR_REM_Z_1 , write = set_GurZ_1STR_CODE_VIGR_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1STR_CODE_VIGR_REM_Z_1(void)=0;
   virtual void set_GurZ_1STR_CODE_VIGR_REM_Z_1(TFIBWideStringField * GurZ_1STR_CODE_VIGR_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1NAME_SADR_STROEN = {read = get_GurZ_1NAME_SADR_STROEN , write = set_GurZ_1NAME_SADR_STROEN};
   virtual TFIBWideStringField * get_GurZ_1NAME_SADR_STROEN(void)=0;
   virtual void set_GurZ_1NAME_SADR_STROEN(TFIBWideStringField * GurZ_1NAME_SADR_STROEN)=0;

   __property TFIBWideStringField * GurZ_1NAME_SADR_RAYON = {read = get_GurZ_1NAME_SADR_RAYON , write = set_GurZ_1NAME_SADR_RAYON};
   virtual TFIBWideStringField * get_GurZ_1NAME_SADR_RAYON(void)=0;
   virtual void set_GurZ_1NAME_SADR_RAYON(TFIBWideStringField * GurZ_1NAME_SADR_RAYON)=0;

   __property TFIBIntegerField * GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1 = {read = get_GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1 , write = set_GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1};
   virtual TFIBIntegerField * get_GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1(void)=0;
   virtual void set_GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1(TFIBIntegerField * GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1)=0;

   __property TFIBWideStringField * GurZNeisprNAME_ENG_REM_SNEISPR = {read = get_GurZNeisprNAME_ENG_REM_SNEISPR , write = set_GurZNeisprNAME_ENG_REM_SNEISPR};
   virtual TFIBWideStringField * get_GurZNeisprNAME_ENG_REM_SNEISPR(void)=0;
   virtual void set_GurZNeisprNAME_ENG_REM_SNEISPR(TFIBWideStringField * GurZNeisprNAME_ENG_REM_SNEISPR)=0;

   __property TFIBWideStringField * GurZNeisprNAME_REM_SGRPNEISPR = {read = get_GurZNeisprNAME_REM_SGRPNEISPR , write = set_GurZNeisprNAME_REM_SGRPNEISPR};
   virtual TFIBWideStringField * get_GurZNeisprNAME_REM_SGRPNEISPR(void)=0;
   virtual void set_GurZNeisprNAME_REM_SGRPNEISPR(TFIBWideStringField * GurZNeisprNAME_REM_SGRPNEISPR)=0;

   __property TFIBWideStringField * GurZNeisprNAME_ENG_REM_SGRPNEISPR = {read = get_GurZNeisprNAME_ENG_REM_SGRPNEISPR , write = set_GurZNeisprNAME_ENG_REM_SGRPNEISPR};
   virtual TFIBWideStringField * get_GurZNeisprNAME_ENG_REM_SGRPNEISPR(void)=0;
   virtual void set_GurZNeisprNAME_ENG_REM_SGRPNEISPR(TFIBWideStringField * GurZNeisprNAME_ENG_REM_SGRPNEISPR)=0;

   __property TFIBWideStringField * GurZ_1FAMILIYA_REM_Z_1 = {read = get_GurZ_1FAMILIYA_REM_Z_1 , write = set_GurZ_1FAMILIYA_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1FAMILIYA_REM_Z_1(void)=0;
   virtual void set_GurZ_1FAMILIYA_REM_Z_1(TFIBWideStringField * GurZ_1FAMILIYA_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1IMYA_REM_Z_1 = {read = get_GurZ_1IMYA_REM_Z_1 , write = set_GurZ_1IMYA_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1IMYA_REM_Z_1(void)=0;
   virtual void set_GurZ_1IMYA_REM_Z_1(TFIBWideStringField * GurZ_1IMYA_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1OTCHESTVO_REM_Z_1 = {read = get_GurZ_1OTCHESTVO_REM_Z_1 , write = set_GurZ_1OTCHESTVO_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1OTCHESTVO_REM_Z_1(void)=0;
   virtual void set_GurZ_1OTCHESTVO_REM_Z_1(TFIBWideStringField * GurZ_1OTCHESTVO_REM_Z_1)=0;

   __property TFIBDateField * GurZ_1DATE_VIPUSK_REM_Z_1 = {read = get_GurZ_1DATE_VIPUSK_REM_Z_1 , write = set_GurZ_1DATE_VIPUSK_REM_Z_1};
   virtual TFIBDateField * get_GurZ_1DATE_VIPUSK_REM_Z_1(void)=0;
   virtual void set_GurZ_1DATE_VIPUSK_REM_Z_1(TFIBDateField * GurZ_1DATE_VIPUSK_REM_Z_1)=0;

   __property TFIBDateField * GurZ_1DATE_PRODAGI_REM_Z_1 = {read = get_GurZ_1DATE_PRODAGI_REM_Z_1 , write = set_GurZ_1DATE_PRODAGI_REM_Z_1};
   virtual TFIBDateField * get_GurZ_1DATE_PRODAGI_REM_Z_1(void)=0;
   virtual void set_GurZ_1DATE_PRODAGI_REM_Z_1(TFIBDateField * GurZ_1DATE_PRODAGI_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1PODO_REM_Z_1 = {read = get_GurZ_1PODO_REM_Z_1 , write = set_GurZ_1PODO_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1PODO_REM_Z_1(void)=0;
   virtual void set_GurZ_1PODO_REM_Z_1(TFIBWideStringField * GurZ_1PODO_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1POPOSLE_REM_Z_1 = {read = get_GurZ_1POPOSLE_REM_Z_1 , write = set_GurZ_1POPOSLE_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1POPOSLE_REM_Z_1(void)=0;
   virtual void set_GurZ_1POPOSLE_REM_Z_1(TFIBWideStringField * GurZ_1POPOSLE_REM_Z_1)=0;

   __property TFIBLargeIntField * GurZ_1IDPRNEISPR_REM_Z_1 = {read = get_GurZ_1IDPRNEISPR_REM_Z_1 , write = set_GurZ_1IDPRNEISPR_REM_Z_1};
   virtual TFIBLargeIntField * get_GurZ_1IDPRNEISPR_REM_Z_1(void)=0;
   virtual void set_GurZ_1IDPRNEISPR_REM_Z_1(TFIBLargeIntField * GurZ_1IDPRNEISPR_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1PARTNUM_REM_Z_1 = {read = get_GurZ_1PARTNUM_REM_Z_1 , write = set_GurZ_1PARTNUM_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1PARTNUM_REM_Z_1(void)=0;
   virtual void set_GurZ_1PARTNUM_REM_Z_1(TFIBWideStringField * GurZ_1PARTNUM_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1REFERENCE_REM_Z_1 = {read = get_GurZ_1REFERENCE_REM_Z_1 , write = set_GurZ_1REFERENCE_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1REFERENCE_REM_Z_1(void)=0;
   virtual void set_GurZ_1REFERENCE_REM_Z_1(TFIBWideStringField * GurZ_1REFERENCE_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1SWCODE_REM_Z_1 = {read = get_GurZ_1SWCODE_REM_Z_1 , write = set_GurZ_1SWCODE_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1SWCODE_REM_Z_1(void)=0;
   virtual void set_GurZ_1SWCODE_REM_Z_1(TFIBWideStringField * GurZ_1SWCODE_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1HWCODE_REM_Z_1 = {read = get_GurZ_1HWCODE_REM_Z_1 , write = set_GurZ_1HWCODE_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1HWCODE_REM_Z_1(void)=0;
   virtual void set_GurZ_1HWCODE_REM_Z_1(TFIBWideStringField * GurZ_1HWCODE_REM_Z_1)=0;

   __property TFIBIntegerField * GurZ_1KEMSDANO_REM_Z_1 = {read = get_GurZ_1KEMSDANO_REM_Z_1 , write = set_GurZ_1KEMSDANO_REM_Z_1};
   virtual TFIBIntegerField * get_GurZ_1KEMSDANO_REM_Z_1(void)=0;
   virtual void set_GurZ_1KEMSDANO_REM_Z_1(TFIBIntegerField * GurZ_1KEMSDANO_REM_Z_1)=0;

   __property TFIBDateTimeField * GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1 = {read = get_GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1 , write = set_GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1};
   virtual TFIBDateTimeField * get_GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1(void)=0;
   virtual void set_GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1(TFIBDateTimeField * GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1SERNUM3_REM_Z_1 = {read = get_GurZ_1SERNUM3_REM_Z_1 , write = set_GurZ_1SERNUM3_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1SERNUM3_REM_Z_1(void)=0;
   virtual void set_GurZ_1SERNUM3_REM_Z_1(TFIBWideStringField * GurZ_1SERNUM3_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1SERNUM4_REM_Z_1 = {read = get_GurZ_1SERNUM4_REM_Z_1 , write = set_GurZ_1SERNUM4_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1SERNUM4_REM_Z_1(void)=0;
   virtual void set_GurZ_1SERNUM4_REM_Z_1(TFIBWideStringField * GurZ_1SERNUM4_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1NUMBAT_REM_Z_1 = {read = get_GurZ_1NUMBAT_REM_Z_1 , write = set_GurZ_1NUMBAT_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1NUMBAT_REM_Z_1(void)=0;
   virtual void set_GurZ_1NUMBAT_REM_Z_1(TFIBWideStringField * GurZ_1NUMBAT_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1NAME_REM_SPRNEISPR = {read = get_GurZ_1NAME_REM_SPRNEISPR , write = set_GurZ_1NAME_REM_SPRNEISPR};
   virtual TFIBWideStringField * get_GurZ_1NAME_REM_SPRNEISPR(void)=0;
   virtual void set_GurZ_1NAME_REM_SPRNEISPR(TFIBWideStringField * GurZ_1NAME_REM_SPRNEISPR)=0;

   __property TFIBWideStringField * GurZ_1NAME_ENG_REM_SPRNEISPR = {read = get_GurZ_1NAME_ENG_REM_SPRNEISPR , write = set_GurZ_1NAME_ENG_REM_SPRNEISPR};
   virtual TFIBWideStringField * get_GurZ_1NAME_ENG_REM_SPRNEISPR(void)=0;
   virtual void set_GurZ_1NAME_ENG_REM_SPRNEISPR(TFIBWideStringField * GurZ_1NAME_ENG_REM_SPRNEISPR)=0;

   __property TFIBWideStringField * GurZ_1CODE_REM_SPRNEISPR = {read = get_GurZ_1CODE_REM_SPRNEISPR , write = set_GurZ_1CODE_REM_SPRNEISPR};
   virtual TFIBWideStringField * get_GurZ_1CODE_REM_SPRNEISPR(void)=0;
   virtual void set_GurZ_1CODE_REM_SPRNEISPR(TFIBWideStringField * GurZ_1CODE_REM_SPRNEISPR)=0;

   __property TFIBWideStringField * GurZ_1NAME_REM_SPRNEISPR_GRP = {read = get_GurZ_1NAME_REM_SPRNEISPR_GRP , write = set_GurZ_1NAME_REM_SPRNEISPR_GRP};
   virtual TFIBWideStringField * get_GurZ_1NAME_REM_SPRNEISPR_GRP(void)=0;
   virtual void set_GurZ_1NAME_REM_SPRNEISPR_GRP(TFIBWideStringField * GurZ_1NAME_REM_SPRNEISPR_GRP)=0;

   __property TFIBWideStringField * GurZ_1NAME_ENG_REM_SPRNEISPR_GRP = {read = get_GurZ_1NAME_ENG_REM_SPRNEISPR_GRP , write = set_GurZ_1NAME_ENG_REM_SPRNEISPR_GRP};
   virtual TFIBWideStringField * get_GurZ_1NAME_ENG_REM_SPRNEISPR_GRP(void)=0;
   virtual void set_GurZ_1NAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * GurZ_1NAME_ENG_REM_SPRNEISPR_GRP)=0;

   __property TFIBSmallIntField * GurZ_1FL_ISM_SERNUM3_REM_Z_1 = {read = get_GurZ_1FL_ISM_SERNUM3_REM_Z_1 , write = set_GurZ_1FL_ISM_SERNUM3_REM_Z_1};
   virtual TFIBSmallIntField * get_GurZ_1FL_ISM_SERNUM3_REM_Z_1(void)=0;
   virtual void set_GurZ_1FL_ISM_SERNUM3_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_SERNUM3_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1SERNUM3_NEW_REM_Z_1 = {read = get_GurZ_1SERNUM3_NEW_REM_Z_1 , write = set_GurZ_1SERNUM3_NEW_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1SERNUM3_NEW_REM_Z_1(void)=0;
   virtual void set_GurZ_1SERNUM3_NEW_REM_Z_1(TFIBWideStringField * GurZ_1SERNUM3_NEW_REM_Z_1)=0;

   __property TFIBSmallIntField * GurZ_1FL_ISM_SERNUM4_REM_Z_1 = {read = get_GurZ_1FL_ISM_SERNUM4_REM_Z_1 , write = set_GurZ_1FL_ISM_SERNUM4_REM_Z_1};
   virtual TFIBSmallIntField * get_GurZ_1FL_ISM_SERNUM4_REM_Z_1(void)=0;
   virtual void set_GurZ_1FL_ISM_SERNUM4_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_SERNUM4_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1SERNUM4_NEW_REM_Z_1 = {read = get_GurZ_1SERNUM4_NEW_REM_Z_1 , write = set_GurZ_1SERNUM4_NEW_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1SERNUM4_NEW_REM_Z_1(void)=0;
   virtual void set_GurZ_1SERNUM4_NEW_REM_Z_1(TFIBWideStringField * GurZ_1SERNUM4_NEW_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1FL_ISM_REFERENCE_REM_Z_1 = {read = get_GurZ_1FL_ISM_REFERENCE_REM_Z_1 , write = set_GurZ_1FL_ISM_REFERENCE_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1FL_ISM_REFERENCE_REM_Z_1(void)=0;
   virtual void set_GurZ_1FL_ISM_REFERENCE_REM_Z_1(TFIBWideStringField * GurZ_1FL_ISM_REFERENCE_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1REFERENCE_NEW_REM_Z_1 = {read = get_GurZ_1REFERENCE_NEW_REM_Z_1 , write = set_GurZ_1REFERENCE_NEW_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1REFERENCE_NEW_REM_Z_1(void)=0;
   virtual void set_GurZ_1REFERENCE_NEW_REM_Z_1(TFIBWideStringField * GurZ_1REFERENCE_NEW_REM_Z_1)=0;

   __property TFIBSmallIntField * GurZ_1FL_ISM_HWCODE_REM_Z_1 = {read = get_GurZ_1FL_ISM_HWCODE_REM_Z_1 , write = set_GurZ_1FL_ISM_HWCODE_REM_Z_1};
   virtual TFIBSmallIntField * get_GurZ_1FL_ISM_HWCODE_REM_Z_1(void)=0;
   virtual void set_GurZ_1FL_ISM_HWCODE_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_HWCODE_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1HWCODE_NEW_REM_Z_1 = {read = get_GurZ_1HWCODE_NEW_REM_Z_1 , write = set_GurZ_1HWCODE_NEW_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1HWCODE_NEW_REM_Z_1(void)=0;
   virtual void set_GurZ_1HWCODE_NEW_REM_Z_1(TFIBWideStringField * GurZ_1HWCODE_NEW_REM_Z_1)=0;

   __property TFIBSmallIntField * GurZ_1FL_ISM_SWCODE_REM_Z_1 = {read = get_GurZ_1FL_ISM_SWCODE_REM_Z_1 , write = set_GurZ_1FL_ISM_SWCODE_REM_Z_1};
   virtual TFIBSmallIntField * get_GurZ_1FL_ISM_SWCODE_REM_Z_1(void)=0;
   virtual void set_GurZ_1FL_ISM_SWCODE_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_SWCODE_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1SWCODE_NEW_REM_Z_1 = {read = get_GurZ_1SWCODE_NEW_REM_Z_1 , write = set_GurZ_1SWCODE_NEW_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1SWCODE_NEW_REM_Z_1(void)=0;
   virtual void set_GurZ_1SWCODE_NEW_REM_Z_1(TFIBWideStringField * GurZ_1SWCODE_NEW_REM_Z_1)=0;

   __property TFIBSmallIntField * GurZ_1FL_ISM_PARTNUM_REM_Z_1 = {read = get_GurZ_1FL_ISM_PARTNUM_REM_Z_1 , write = set_GurZ_1FL_ISM_PARTNUM_REM_Z_1};
   virtual TFIBSmallIntField * get_GurZ_1FL_ISM_PARTNUM_REM_Z_1(void)=0;
   virtual void set_GurZ_1FL_ISM_PARTNUM_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_PARTNUM_REM_Z_1)=0;

   __property TFIBWideStringField * GurZ_1PARTNUM_NEW_REM_Z_1 = {read = get_GurZ_1PARTNUM_NEW_REM_Z_1 , write = set_GurZ_1PARTNUM_NEW_REM_Z_1};
   virtual TFIBWideStringField * get_GurZ_1PARTNUM_NEW_REM_Z_1(void)=0;
   virtual void set_GurZ_1PARTNUM_NEW_REM_Z_1(TFIBWideStringField * GurZ_1PARTNUM_NEW_REM_Z_1)=0;

   __property TDataSource * DataSourcePrNeispr = {read = get_DataSourcePrNeispr , write = set_DataSourcePrNeispr};
   virtual TDataSource * get_DataSourcePrNeispr(void)=0;
   virtual void set_DataSourcePrNeispr(TDataSource * DataSourcePrNeispr)=0;

   __property TpFIBDataSet * GurZPrNeispr = {read = get_GurZPrNeispr , write = set_GurZPrNeispr};
   virtual TpFIBDataSet * get_GurZPrNeispr(void)=0;
   virtual void set_GurZPrNeispr(TpFIBDataSet * GurZPrNeispr)=0;

   __property TFIBLargeIntField * GurZPrNeisprID_REM_ZPRNEISPR = {read = get_GurZPrNeisprID_REM_ZPRNEISPR , write = set_GurZPrNeisprID_REM_ZPRNEISPR};
   virtual TFIBLargeIntField * get_GurZPrNeisprID_REM_ZPRNEISPR(void)=0;
   virtual void set_GurZPrNeisprID_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprID_REM_ZPRNEISPR)=0;

   __property TFIBLargeIntField * GurZPrNeisprIDBASE_REM_ZPRNEISPR = {read = get_GurZPrNeisprIDBASE_REM_ZPRNEISPR , write = set_GurZPrNeisprIDBASE_REM_ZPRNEISPR};
   virtual TFIBLargeIntField * get_GurZPrNeisprIDBASE_REM_ZPRNEISPR(void)=0;
   virtual void set_GurZPrNeisprIDBASE_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprIDBASE_REM_ZPRNEISPR)=0;

   __property TFIBWideStringField * GurZPrNeisprGID_REM_ZPRNEISPR = {read = get_GurZPrNeisprGID_REM_ZPRNEISPR , write = set_GurZPrNeisprGID_REM_ZPRNEISPR};
   virtual TFIBWideStringField * get_GurZPrNeisprGID_REM_ZPRNEISPR(void)=0;
   virtual void set_GurZPrNeisprGID_REM_ZPRNEISPR(TFIBWideStringField * GurZPrNeisprGID_REM_ZPRNEISPR)=0;

   __property TFIBLargeIntField * GurZPrNeisprIDPRCOND_REM_ZPRNEISPR = {read = get_GurZPrNeisprIDPRCOND_REM_ZPRNEISPR , write = set_GurZPrNeisprIDPRCOND_REM_ZPRNEISPR};
   virtual TFIBLargeIntField * get_GurZPrNeisprIDPRCOND_REM_ZPRNEISPR(void)=0;
   virtual void set_GurZPrNeisprIDPRCOND_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprIDPRCOND_REM_ZPRNEISPR)=0;

   __property TFIBLargeIntField * GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR = {read = get_GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR , write = set_GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR};
   virtual TFIBLargeIntField * get_GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR(void)=0;
   virtual void set_GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR)=0;

   __property TFIBLargeIntField * GurZPrNeisprIDZ_REM_ZPRNEISPR = {read = get_GurZPrNeisprIDZ_REM_ZPRNEISPR , write = set_GurZPrNeisprIDZ_REM_ZPRNEISPR};
   virtual TFIBLargeIntField * get_GurZPrNeisprIDZ_REM_ZPRNEISPR(void)=0;
   virtual void set_GurZPrNeisprIDZ_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprIDZ_REM_ZPRNEISPR)=0;

   __property TFIBWideStringField * GurZPrNeisprNAME_REM_SPRNEISPR = {read = get_GurZPrNeisprNAME_REM_SPRNEISPR , write = set_GurZPrNeisprNAME_REM_SPRNEISPR};
   virtual TFIBWideStringField * get_GurZPrNeisprNAME_REM_SPRNEISPR(void)=0;
   virtual void set_GurZPrNeisprNAME_REM_SPRNEISPR(TFIBWideStringField * GurZPrNeisprNAME_REM_SPRNEISPR)=0;

   __property TFIBWideStringField * GurZPrNeisprCODE_REM_SPRNEISPR = {read = get_GurZPrNeisprCODE_REM_SPRNEISPR , write = set_GurZPrNeisprCODE_REM_SPRNEISPR};
   virtual TFIBWideStringField * get_GurZPrNeisprCODE_REM_SPRNEISPR(void)=0;
   virtual void set_GurZPrNeisprCODE_REM_SPRNEISPR(TFIBWideStringField * GurZPrNeisprCODE_REM_SPRNEISPR)=0;

   __property TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRNEISPR = {read = get_GurZPrNeisprNAME_ENG_REM_SPRNEISPR , write = set_GurZPrNeisprNAME_ENG_REM_SPRNEISPR};
   virtual TFIBWideStringField * get_GurZPrNeisprNAME_ENG_REM_SPRNEISPR(void)=0;
   virtual void set_GurZPrNeisprNAME_ENG_REM_SPRNEISPR(TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRNEISPR)=0;

   __property TFIBWideStringField * GurZPrNeisprNAME_REM_SPRNEISPR_GRP = {read = get_GurZPrNeisprNAME_REM_SPRNEISPR_GRP , write = set_GurZPrNeisprNAME_REM_SPRNEISPR_GRP};
   virtual TFIBWideStringField * get_GurZPrNeisprNAME_REM_SPRNEISPR_GRP(void)=0;
   virtual void set_GurZPrNeisprNAME_REM_SPRNEISPR_GRP(TFIBWideStringField * GurZPrNeisprNAME_REM_SPRNEISPR_GRP)=0;

   __property TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP = {read = get_GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP , write = set_GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP};
   virtual TFIBWideStringField * get_GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP(void)=0;
   virtual void set_GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP)=0;

   __property TFIBWideStringField * GurZPrNeisprCODE_REM_SPRCONDITION = {read = get_GurZPrNeisprCODE_REM_SPRCONDITION , write = set_GurZPrNeisprCODE_REM_SPRCONDITION};
   virtual TFIBWideStringField * get_GurZPrNeisprCODE_REM_SPRCONDITION(void)=0;
   virtual void set_GurZPrNeisprCODE_REM_SPRCONDITION(TFIBWideStringField * GurZPrNeisprCODE_REM_SPRCONDITION)=0;

   __property TFIBWideStringField * GurZPrNeisprNAME_REM_SPRCONDITION = {read = get_GurZPrNeisprNAME_REM_SPRCONDITION , write = set_GurZPrNeisprNAME_REM_SPRCONDITION};
   virtual TFIBWideStringField * get_GurZPrNeisprNAME_REM_SPRCONDITION(void)=0;
   virtual void set_GurZPrNeisprNAME_REM_SPRCONDITION(TFIBWideStringField * GurZPrNeisprNAME_REM_SPRCONDITION)=0;

   __property TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRCONDITION = {read = get_GurZPrNeisprNAME_ENG_REM_SPRCONDITION , write = set_GurZPrNeisprNAME_ENG_REM_SPRCONDITION};
   virtual TFIBWideStringField * get_GurZPrNeisprNAME_ENG_REM_SPRCONDITION(void)=0;
   virtual void set_GurZPrNeisprNAME_ENG_REM_SPRCONDITION(TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRCONDITION)=0;

   __property TFIBWideStringField * GurZPrNeisprCODE_REM_SPRCOND_GRP = {read = get_GurZPrNeisprCODE_REM_SPRCOND_GRP , write = set_GurZPrNeisprCODE_REM_SPRCOND_GRP};
   virtual TFIBWideStringField * get_GurZPrNeisprCODE_REM_SPRCOND_GRP(void)=0;
   virtual void set_GurZPrNeisprCODE_REM_SPRCOND_GRP(TFIBWideStringField * GurZPrNeisprCODE_REM_SPRCOND_GRP)=0;

   __property TFIBWideStringField * GurZPrNeisprNAME_REM_SPRCOND_GRP = {read = get_GurZPrNeisprNAME_REM_SPRCOND_GRP , write = set_GurZPrNeisprNAME_REM_SPRCOND_GRP};
   virtual TFIBWideStringField * get_GurZPrNeisprNAME_REM_SPRCOND_GRP(void)=0;
   virtual void set_GurZPrNeisprNAME_REM_SPRCOND_GRP(TFIBWideStringField * GurZPrNeisprNAME_REM_SPRCOND_GRP)=0;

   __property TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP = {read = get_GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP , write = set_GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP};
   virtual TFIBWideStringField * get_GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP(void)=0;
   virtual void set_GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP(TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP)=0;

   __property TIntegerField * GurZPrNeisprRECNO = {read = get_GurZPrNeisprRECNO , write = set_GurZPrNeisprRECNO};
   virtual TIntegerField * get_GurZPrNeisprRECNO(void)=0;
   virtual void set_GurZPrNeisprRECNO(TIntegerField * GurZPrNeisprRECNO)=0;

   __property TFIBBCDField * GurZ_1PREDOPLATA_REM_Z_1 = {read = get_GurZ_1PREDOPLATA_REM_Z_1 , write = set_GurZ_1PREDOPLATA_REM_Z_1};
   virtual TFIBBCDField * get_GurZ_1PREDOPLATA_REM_Z_1(void)=0;
   virtual void set_GurZ_1PREDOPLATA_REM_Z_1(TFIBBCDField * GurZ_1PREDOPLATA_REM_Z_1)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property __int64 IdZ = {read = get_IdZ , write = set_IdZ};
   virtual __int64 get_IdZ(void)=0;
   virtual void set_IdZ(__int64 IdZ)=0;

   __property bool flChangeData = {read = get_flChangeData , write = set_flChangeData};
   virtual bool get_flChangeData(void)=0;
   virtual void set_flChangeData(bool flChangeData)=0;

   virtual void NewDoc(void)=0;
   virtual void OpenDoc(__int64 id)=0;
   virtual bool SaveDoc(void)=0;
   virtual bool DeleteDoc(__int64 id)=0;
   virtual void CloseDoc(void)=0;
   virtual void AddNewRecordDv(void)=0;
};
#define IID_IREM_DMZayavka __uuidof(IREM_DMZayavka)
#endif
