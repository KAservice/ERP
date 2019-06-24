#ifndef UIDMGurLogH
#define UIDMGurLogH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{98C53E16-47EF-4C7C-B497-301169C0B4AC}")) IDMGurLog : public IMainInterface
{
public:
   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

   __property TpFIBDataSet * Table = {read = get_Table , write = set_Table};
   virtual TpFIBDataSet * get_Table(void)=0;
   virtual void set_Table(TpFIBDataSet * Table)=0;

   __property TpFIBTransaction * IBTr = {read = get_IBTr , write = set_IBTr};
   virtual TpFIBTransaction * get_IBTr(void)=0;
   virtual void set_IBTr(TpFIBTransaction * IBTr)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBDateTimeField * TablePOS_LOG = {read = get_TablePOS_LOG , write = set_TablePOS_LOG};
   virtual TFIBDateTimeField * get_TablePOS_LOG(void)=0;
   virtual void set_TablePOS_LOG(TFIBDateTimeField * TablePOS_LOG)=0;

   __property TFIBIntegerField * TableTYPE_LOG = {read = get_TableTYPE_LOG , write = set_TableTYPE_LOG};
   virtual TFIBIntegerField * get_TableTYPE_LOG(void)=0;
   virtual void set_TableTYPE_LOG(TFIBIntegerField * TableTYPE_LOG)=0;

   __property TFIBIntegerField * TableOPER_LOG = {read = get_TableOPER_LOG , write = set_TableOPER_LOG};
   virtual TFIBIntegerField * get_TableOPER_LOG(void)=0;
   virtual void set_TableOPER_LOG(TFIBIntegerField * TableOPER_LOG)=0;

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TFIBBCDField * TableID_LOG = {read = get_TableID_LOG , write = set_TableID_LOG};
   virtual TFIBBCDField * get_TableID_LOG(void)=0;
   virtual void set_TableID_LOG(TFIBBCDField * TableID_LOG)=0;

   __property TFIBBCDField * TableIDUSER_LOG = {read = get_TableIDUSER_LOG , write = set_TableIDUSER_LOG};
   virtual TFIBBCDField * get_TableIDUSER_LOG(void)=0;
   virtual void set_TableIDUSER_LOG(TFIBBCDField * TableIDUSER_LOG)=0;

   __property TFIBWideStringField * TableMESSAGE_LOG = {read = get_TableMESSAGE_LOG , write = set_TableMESSAGE_LOG};
   virtual TFIBWideStringField * get_TableMESSAGE_LOG(void)=0;
   virtual void set_TableMESSAGE_LOG(TFIBWideStringField * TableMESSAGE_LOG)=0;

   __property TFIBIntegerField * TableOBJECT_LOG = {read = get_TableOBJECT_LOG , write = set_TableOBJECT_LOG};
   virtual TFIBIntegerField * get_TableOBJECT_LOG(void)=0;
   virtual void set_TableOBJECT_LOG(TFIBIntegerField * TableOBJECT_LOG)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property __int64 IdUser = {read = get_IdUser , write = set_IdUser};
   virtual __int64 get_IdUser(void)=0;
   virtual void set_IdUser(__int64 IdUser)=0;

   __property int Type = {read = get_Type , write = set_Type};
   virtual int get_Type(void)=0;
   virtual void set_Type(int Type)=0;

   __property int ObjectLog = {read = get_ObjectLog , write = set_ObjectLog};
   virtual int get_ObjectLog(void)=0;
   virtual void set_ObjectLog(int ObjectLog)=0;

   __property int Oper = {read = get_Oper , write = set_Oper};
   virtual int get_Oper(void)=0;
   virtual void set_Oper(int Oper)=0;

   __property bool OtborVkl = {read = get_OtborVkl , write = set_OtborVkl};
   virtual bool get_OtborVkl(void)=0;
   virtual void set_OtborVkl(bool OtborVkl)=0;

   __property bool OtborPoUser = {read = get_OtborPoUser , write = set_OtborPoUser};
   virtual bool get_OtborPoUser(void)=0;
   virtual void set_OtborPoUser(bool OtborPoUser)=0;

   __property bool OtborPoType = {read = get_OtborPoType , write = set_OtborPoType};
   virtual bool get_OtborPoType(void)=0;
   virtual void set_OtborPoType(bool OtborPoType)=0;

   __property bool OtborPoObject = {read = get_OtborPoObject , write = set_OtborPoObject};
   virtual bool get_OtborPoObject(void)=0;
   virtual void set_OtborPoObject(bool OtborPoObject)=0;

   __property bool OtborPoOper = {read = get_OtborPoOper , write = set_OtborPoOper};
   virtual bool get_OtborPoOper(void)=0;
   virtual void set_OtborPoOper(bool OtborPoOper)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   virtual void OpenTable()=0;
   virtual void UpdateTable(void)=0;
};
#define IID_IDMGurLog __uuidof(IDMGurLog)
#endif
