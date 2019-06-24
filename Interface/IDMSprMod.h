#ifndef UIDMSprModH
#define UIDMSprModH
#include "IMainInterface.h"
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{0B364548-34EC-430C-A44A-C382020FDF79}")) IDMSprMod : public IMainInterface
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

   __property TpFIBTransaction * IBTrUpdate = {read = get_IBTrUpdate , write = set_IBTrUpdate};
   virtual TpFIBTransaction * get_IBTrUpdate(void)=0;
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)=0;

   __property TIntegerField * TableRECNO = {read = get_TableRECNO , write = set_TableRECNO};
   virtual TIntegerField * get_TableRECNO(void)=0;
   virtual void set_TableRECNO(TIntegerField * TableRECNO)=0;

   __property TFIBBCDField * TableID_MOD = {read = get_TableID_MOD , write = set_TableID_MOD};
   virtual TFIBBCDField * get_TableID_MOD(void)=0;
   virtual void set_TableID_MOD(TFIBBCDField * TableID_MOD)=0;

   __property TFIBBCDField * TableIDNOM_MOD = {read = get_TableIDNOM_MOD , write = set_TableIDNOM_MOD};
   virtual TFIBBCDField * get_TableIDNOM_MOD(void)=0;
   virtual void set_TableIDNOM_MOD(TFIBBCDField * TableIDNOM_MOD)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   virtual void OpenTable(__int64 Nom)=0;
   virtual void NewElement(__int64 Nom)=0;
   virtual void DeleteElement()=0;
   virtual void SaveIsmen()=0;
   virtual void CancelIsmen()=0;
};
#define IID_IDMSprMod __uuidof(IDMSprMod)
#endif
