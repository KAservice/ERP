#ifndef UIHOT_DMGurAllDocH
#define UIHOT_DMGurAllDocH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{B145006D-32B7-4165-B9DF-E41775338F9A}"))IHOT_DMGurAllDoc : public IMainInterface
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

   __property TFIBDateTimeField * TablePOS_HOT_GALLDOC = {read = get_TablePOS_HOT_GALLDOC , write = set_TablePOS_HOT_GALLDOC};
   virtual TFIBDateTimeField * get_TablePOS_HOT_GALLDOC(void)=0;
   virtual void set_TablePOS_HOT_GALLDOC(TFIBDateTimeField * TablePOS_HOT_GALLDOC)=0;

   __property TFIBSmallIntField * TablePR_HOT_GALLDOC = {read = get_TablePR_HOT_GALLDOC , write = set_TablePR_HOT_GALLDOC};
   virtual TFIBSmallIntField * get_TablePR_HOT_GALLDOC(void)=0;
   virtual void set_TablePR_HOT_GALLDOC(TFIBSmallIntField * TablePR_HOT_GALLDOC)=0;

   __property TFIBBCDField * TableSUM_HOT_GALLDOC = {read = get_TableSUM_HOT_GALLDOC , write = set_TableSUM_HOT_GALLDOC};
   virtual TFIBBCDField * get_TableSUM_HOT_GALLDOC(void)=0;
   virtual void set_TableSUM_HOT_GALLDOC(TFIBBCDField * TableSUM_HOT_GALLDOC)=0;

   __property TpFIBDataSet * IBQ = {read = get_IBQ , write = set_IBQ};
   virtual TpFIBDataSet * get_IBQ(void)=0;
   virtual void set_IBQ(TpFIBDataSet * IBQ)=0;

   __property TFIBBCDField * TableID_HOT_GALLDOC = {read = get_TableID_HOT_GALLDOC , write = set_TableID_HOT_GALLDOC};
   virtual TFIBBCDField * get_TableID_HOT_GALLDOC(void)=0;
   virtual void set_TableID_HOT_GALLDOC(TFIBBCDField * TableID_HOT_GALLDOC)=0;

   __property TFIBBCDField * TableIDFIRM_HOT_GALLDOC = {read = get_TableIDFIRM_HOT_GALLDOC , write = set_TableIDFIRM_HOT_GALLDOC};
   virtual TFIBBCDField * get_TableIDFIRM_HOT_GALLDOC(void)=0;
   virtual void set_TableIDFIRM_HOT_GALLDOC(TFIBBCDField * TableIDFIRM_HOT_GALLDOC)=0;

   __property TFIBBCDField * TableIDKL_HOT_GALLDOC = {read = get_TableIDKL_HOT_GALLDOC , write = set_TableIDKL_HOT_GALLDOC};
   virtual TFIBBCDField * get_TableIDKL_HOT_GALLDOC(void)=0;
   virtual void set_TableIDKL_HOT_GALLDOC(TFIBBCDField * TableIDKL_HOT_GALLDOC)=0;

   __property TFIBBCDField * TableIDUSER_HOT_GALLDOC = {read = get_TableIDUSER_HOT_GALLDOC , write = set_TableIDUSER_HOT_GALLDOC};
   virtual TFIBBCDField * get_TableIDUSER_HOT_GALLDOC(void)=0;
   virtual void set_TableIDUSER_HOT_GALLDOC(TFIBBCDField * TableIDUSER_HOT_GALLDOC)=0;

   __property TFIBBCDField * TableIDDOCOSN_HOT_GALLDOC = {read = get_TableIDDOCOSN_HOT_GALLDOC , write = set_TableIDDOCOSN_HOT_GALLDOC};
   virtual TFIBBCDField * get_TableIDDOCOSN_HOT_GALLDOC(void)=0;
   virtual void set_TableIDDOCOSN_HOT_GALLDOC(TFIBBCDField * TableIDDOCOSN_HOT_GALLDOC)=0;

   __property TFIBBCDField * TableIDBASE_HOT_GALLDOC = {read = get_TableIDBASE_HOT_GALLDOC , write = set_TableIDBASE_HOT_GALLDOC};
   virtual TFIBBCDField * get_TableIDBASE_HOT_GALLDOC(void)=0;
   virtual void set_TableIDBASE_HOT_GALLDOC(TFIBBCDField * TableIDBASE_HOT_GALLDOC)=0;

   __property TFIBWideStringField * TableTDOC_HOT_GALLDOC = {read = get_TableTDOC_HOT_GALLDOC , write = set_TableTDOC_HOT_GALLDOC};
   virtual TFIBWideStringField * get_TableTDOC_HOT_GALLDOC(void)=0;
   virtual void set_TableTDOC_HOT_GALLDOC(TFIBWideStringField * TableTDOC_HOT_GALLDOC)=0;

   __property TFIBWideStringField * TableNAMEFIRM = {read = get_TableNAMEFIRM , write = set_TableNAMEFIRM};
   virtual TFIBWideStringField * get_TableNAMEFIRM(void)=0;
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBIntegerField * TableNUMBER_HOT_GALLDOC = {read = get_TableNUMBER_HOT_GALLDOC , write = set_TableNUMBER_HOT_GALLDOC};
   virtual TFIBIntegerField * get_TableNUMBER_HOT_GALLDOC(void)=0;
   virtual void set_TableNUMBER_HOT_GALLDOC(TFIBIntegerField * TableNUMBER_HOT_GALLDOC)=0;

   __property __int64 IdDocH = {read = get_IdDocH , write = set_IdDocH};
   virtual __int64 get_IdDocH(void)=0;
   virtual void set_IdDocH(__int64 IdDocH)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property UnicodeString StringTypeDoc = {read = get_StringTypeDoc , write = set_StringTypeDoc};
   virtual UnicodeString get_StringTypeDoc(void)=0;
   virtual void set_StringTypeDoc(UnicodeString StringTypeDoc)=0;

   __property bool OtborVkl = {read = get_OtborVkl , write = set_OtborVkl};
   virtual bool get_OtborVkl(void)=0;
   virtual void set_OtborVkl(bool OtborVkl)=0;

   __property bool OtborPoKlient = {read = get_OtborPoKlient , write = set_OtborPoKlient};
   virtual bool get_OtborPoKlient(void)=0;
   virtual void set_OtborPoKlient(bool OtborPoKlient)=0;

   __property bool OtborPoFirm = {read = get_OtborPoFirm , write = set_OtborPoFirm};
   virtual bool get_OtborPoFirm(void)=0;
   virtual void set_OtborPoFirm(bool OtborPoFirm)=0;

   __property bool OtborPoSklad = {read = get_OtborPoSklad , write = set_OtborPoSklad};
   virtual bool get_OtborPoSklad(void)=0;
   virtual void set_OtborPoSklad(bool OtborPoSklad)=0;

   __property bool OtborPoTypeDoc = {read = get_OtborPoTypeDoc , write = set_OtborPoTypeDoc};
   virtual bool get_OtborPoTypeDoc(void)=0;
   virtual void set_OtborPoTypeDoc(bool OtborPoTypeDoc)=0;

   __property bool NoCheck = {read = get_NoCheck , write = set_NoCheck};
   virtual bool get_NoCheck(void)=0;
   virtual void set_NoCheck(bool NoCheck)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   virtual void OpenTable()=0;
   virtual void UpdateTable(void)=0;
   virtual bool CancelDvRegDoc(AnsiString type_doc, __int64 id_doc)=0;
   virtual bool DvRegDoc(AnsiString type_doc, __int64 id_doc)=0;
   virtual void AllCancelDvRegDoc(void)=0;
   virtual void AllDvRegDoc(void)=0;
};
#define IID_IHOT_DMGurAllDoc __uuidof(IHOT_DMGurAllDoc)
#endif
