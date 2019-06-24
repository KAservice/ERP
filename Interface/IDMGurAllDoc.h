#ifndef UIDMGurAllDocH
#define UIDMGurAllDocH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMGurAllDoc)) IDMGurAllDoc : public IMainInterface
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

   __property TFIBSmallIntField * TablePRDOC = {read = get_TablePRDOC , write = set_TablePRDOC};
   virtual TFIBSmallIntField * get_TablePRDOC(void)=0;
   virtual void set_TablePRDOC(TFIBSmallIntField * TablePRDOC)=0;

   __property TFIBIntegerField * TableNUMDOC = {read = get_TableNUMDOC , write = set_TableNUMDOC};
   virtual TFIBIntegerField * get_TableNUMDOC(void)=0;
   virtual void set_TableNUMDOC(TFIBIntegerField * TableNUMDOC)=0;

   __property TFIBBCDField * TableSUMDOC = {read = get_TableSUMDOC , write = set_TableSUMDOC};
   virtual TFIBBCDField * get_TableSUMDOC(void)=0;
   virtual void set_TableSUMDOC(TFIBBCDField * TableSUMDOC)=0;

   __property TpFIBDataSet * IBQ = {read = get_IBQ , write = set_IBQ};
   virtual TpFIBDataSet * get_IBQ(void)=0;
   virtual void set_IBQ(TpFIBDataSet * IBQ)=0;

   __property TFIBDateTimeField * TablePOSDOC = {read = get_TablePOSDOC , write = set_TablePOSDOC};
   virtual TFIBDateTimeField * get_TablePOSDOC(void)=0;
   virtual void set_TablePOSDOC(TFIBDateTimeField * TablePOSDOC)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * TableIDDOC = {read = get_TableIDDOC , write = set_TableIDDOC};
   virtual TFIBBCDField * get_TableIDDOC(void)=0;
   virtual void set_TableIDDOC(TFIBBCDField * TableIDDOC)=0;

   __property TFIBBCDField * TableIDFIRMDOC = {read = get_TableIDFIRMDOC , write = set_TableIDFIRMDOC};
   virtual TFIBBCDField * get_TableIDFIRMDOC(void)=0;
   virtual void set_TableIDFIRMDOC(TFIBBCDField * TableIDFIRMDOC)=0;

   __property TFIBBCDField * TableIDSKLDOC = {read = get_TableIDSKLDOC , write = set_TableIDSKLDOC};
   virtual TFIBBCDField * get_TableIDSKLDOC(void)=0;
   virtual void set_TableIDSKLDOC(TFIBBCDField * TableIDSKLDOC)=0;

   __property TFIBBCDField * TableIDKLDOC = {read = get_TableIDKLDOC , write = set_TableIDKLDOC};
   virtual TFIBBCDField * get_TableIDKLDOC(void)=0;
   virtual void set_TableIDKLDOC(TFIBBCDField * TableIDKLDOC)=0;

   __property TFIBBCDField * TableIDDOGDOC = {read = get_TableIDDOGDOC , write = set_TableIDDOGDOC};
   virtual TFIBBCDField * get_TableIDDOGDOC(void)=0;
   virtual void set_TableIDDOGDOC(TFIBBCDField * TableIDDOGDOC)=0;

   __property TFIBBCDField * TableIDUSERDOC = {read = get_TableIDUSERDOC , write = set_TableIDUSERDOC};
   virtual TFIBBCDField * get_TableIDUSERDOC(void)=0;
   virtual void set_TableIDUSERDOC(TFIBBCDField * TableIDUSERDOC)=0;

   __property TFIBBCDField * TableIDDOCOSNDOC = {read = get_TableIDDOCOSNDOC , write = set_TableIDDOCOSNDOC};
   virtual TFIBBCDField * get_TableIDDOCOSNDOC(void)=0;
   virtual void set_TableIDDOCOSNDOC(TFIBBCDField * TableIDDOCOSNDOC)=0;

   __property TFIBBCDField * TableIDEXTDOC = {read = get_TableIDEXTDOC , write = set_TableIDEXTDOC};
   virtual TFIBBCDField * get_TableIDEXTDOC(void)=0;
   virtual void set_TableIDEXTDOC(TFIBBCDField * TableIDEXTDOC)=0;

   __property TFIBBCDField * TableIDBASE_GALLDOC = {read = get_TableIDBASE_GALLDOC , write = set_TableIDBASE_GALLDOC};
   virtual TFIBBCDField * get_TableIDBASE_GALLDOC(void)=0;
   virtual void set_TableIDBASE_GALLDOC(TFIBBCDField * TableIDBASE_GALLDOC)=0;

   __property TFIBBCDField * TableIDPROJECT_GALLDOC = {read = get_TableIDPROJECT_GALLDOC , write = set_TableIDPROJECT_GALLDOC};
   virtual TFIBBCDField * get_TableIDPROJECT_GALLDOC(void)=0;
   virtual void set_TableIDPROJECT_GALLDOC(TFIBBCDField * TableIDPROJECT_GALLDOC)=0;

   __property TFIBWideStringField * TableTDOC = {read = get_TableTDOC , write = set_TableTDOC};
   virtual TFIBWideStringField * get_TableTDOC(void)=0;
   virtual void set_TableTDOC(TFIBWideStringField * TableTDOC)=0;

   __property TFIBWideStringField * TableGID_DOC = {read = get_TableGID_DOC , write = set_TableGID_DOC};
   virtual TFIBWideStringField * get_TableGID_DOC(void)=0;
   virtual void set_TableGID_DOC(TFIBWideStringField * TableGID_DOC)=0;

   __property TFIBWideStringField * TablePREFIKSDOC = {read = get_TablePREFIKSDOC , write = set_TablePREFIKSDOC};
   virtual TFIBWideStringField * get_TablePREFIKSDOC(void)=0;
   virtual void set_TablePREFIKSDOC(TFIBWideStringField * TablePREFIKSDOC)=0;

   __property TFIBIntegerField * TableTYPEEXTDOC = {read = get_TableTYPEEXTDOC , write = set_TableTYPEEXTDOC};
   virtual TFIBIntegerField * get_TableTYPEEXTDOC(void)=0;
   virtual void set_TableTYPEEXTDOC(TFIBIntegerField * TableTYPEEXTDOC)=0;

   __property TFIBWideStringField * TableNAMEFIRM = {read = get_TableNAMEFIRM , write = set_TableNAMEFIRM};
   virtual TFIBWideStringField * get_TableNAMEFIRM(void)=0;
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)=0;

   __property TFIBWideStringField * TableNAMESKLAD = {read = get_TableNAMESKLAD , write = set_TableNAMESKLAD};
   virtual TFIBWideStringField * get_TableNAMESKLAD(void)=0;
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)=0;

   __property TFIBWideStringField * TableNAMEKLIENT = {read = get_TableNAMEKLIENT , write = set_TableNAMEKLIENT};
   virtual TFIBWideStringField * get_TableNAMEKLIENT(void)=0;
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)=0;

   __property TFIBWideStringField * TableNAME_USER = {read = get_TableNAME_USER , write = set_TableNAME_USER};
   virtual TFIBWideStringField * get_TableNAME_USER(void)=0;
   virtual void set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)=0;

   __property TFIBWideStringField * TableNAME_SPROJECT = {read = get_TableNAME_SPROJECT , write = set_TableNAME_SPROJECT};
   virtual TFIBWideStringField * get_TableNAME_SPROJECT(void)=0;
   virtual void set_TableNAME_SPROJECT(TFIBWideStringField * TableNAME_SPROJECT)=0;

   __property TFIBWideStringField * TablePREFIKS_NUM_GALLDOC = {read = get_TablePREFIKS_NUM_GALLDOC , write = set_TablePREFIKS_NUM_GALLDOC};
   virtual TFIBWideStringField * get_TablePREFIKS_NUM_GALLDOC(void)=0;
   virtual void set_TablePREFIKS_NUM_GALLDOC(TFIBWideStringField * TablePREFIKS_NUM_GALLDOC)=0;

   __property TFIBBCDField * TableIDBUSINOP_GALLDOC = {read = get_TableIDBUSINOP_GALLDOC , write = set_TableIDBUSINOP_GALLDOC};
   virtual TFIBBCDField * get_TableIDBUSINOP_GALLDOC(void)=0;
   virtual void set_TableIDBUSINOP_GALLDOC(TFIBBCDField * TableIDBUSINOP_GALLDOC)=0;

   __property TFIBWideStringField * TableNAME_SINFBASE_OBMEN = {read = get_TableNAME_SINFBASE_OBMEN , write = set_TableNAME_SINFBASE_OBMEN};
   virtual TFIBWideStringField * get_TableNAME_SINFBASE_OBMEN(void)=0;
   virtual void set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

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

   __property bool NoCheck = {read = get_NoCheck , write = set_NoCheck};
   virtual bool get_NoCheck(void)=0;
   virtual void set_NoCheck(bool NoCheck)=0;

   virtual void OpenTable()=0;
   virtual void UpdateTable(void)=0;
   virtual __int64 FindDocPoIdDog(__int64 iddogovor)=0;
   virtual bool CancelDvRegDoc(AnsiString type_doc, __int64 id_doc)=0;
   virtual bool DvRegDoc(AnsiString type_doc, __int64 id_doc)=0;
   virtual void AllCancelDvRegDoc(void)=0;
   virtual void AllDvRegDoc(void)=0;
};
#define IID_IDMGurAllDoc __uuidof(IDMGurAllDoc)
#endif
