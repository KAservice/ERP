#ifndef UIDMSprBankSchetH
#define UIDMSprBankSchetH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprBankSchet)) IDMSprBankSchet : public IMainInterface
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

   __property TFIBBCDField * TableIDBSCHET = {read = get_TableIDBSCHET , write = set_TableIDBSCHET};
   virtual TFIBBCDField * get_TableIDBSCHET(void)=0;
   virtual void set_TableIDBSCHET(TFIBBCDField * TableIDBSCHET)=0;

   __property TFIBBCDField * TableIDBANKBSCHET = {read = get_TableIDBANKBSCHET , write = set_TableIDBANKBSCHET};
   virtual TFIBBCDField * get_TableIDBANKBSCHET(void)=0;
   virtual void set_TableIDBANKBSCHET(TFIBBCDField * TableIDBANKBSCHET)=0;

   __property TFIBBCDField * TableIDFIRMBSCHET = {read = get_TableIDFIRMBSCHET , write = set_TableIDFIRMBSCHET};
   virtual TFIBBCDField * get_TableIDFIRMBSCHET(void)=0;
   virtual void set_TableIDFIRMBSCHET(TFIBBCDField * TableIDFIRMBSCHET)=0;

   __property TFIBBCDField * ElementIDBSCHET = {read = get_ElementIDBSCHET , write = set_ElementIDBSCHET};
   virtual TFIBBCDField * get_ElementIDBSCHET(void)=0;
   virtual void set_ElementIDBSCHET(TFIBBCDField * ElementIDBSCHET)=0;

   __property TFIBBCDField * ElementIDBANKBSCHET = {read = get_ElementIDBANKBSCHET , write = set_ElementIDBANKBSCHET};
   virtual TFIBBCDField * get_ElementIDBANKBSCHET(void)=0;
   virtual void set_ElementIDBANKBSCHET(TFIBBCDField * ElementIDBANKBSCHET)=0;

   __property TFIBBCDField * ElementIDFIRMBSCHET = {read = get_ElementIDFIRMBSCHET , write = set_ElementIDFIRMBSCHET};
   virtual TFIBBCDField * get_ElementIDFIRMBSCHET(void)=0;
   virtual void set_ElementIDFIRMBSCHET(TFIBBCDField * ElementIDFIRMBSCHET)=0;

   __property TFIBBCDField * ElementIDBANK = {read = get_ElementIDBANK , write = set_ElementIDBANK};
   virtual TFIBBCDField * get_ElementIDBANK(void)=0;
   virtual void set_ElementIDBANK(TFIBBCDField * ElementIDBANK)=0;

   __property TFIBWideStringField * TableNAMEBSCHET = {read = get_TableNAMEBSCHET , write = set_TableNAMEBSCHET};
   virtual TFIBWideStringField * get_TableNAMEBSCHET(void)=0;
   virtual void set_TableNAMEBSCHET(TFIBWideStringField * TableNAMEBSCHET)=0;

   __property TFIBWideStringField * TableNUMBSCHET = {read = get_TableNUMBSCHET , write = set_TableNUMBSCHET};
   virtual TFIBWideStringField * get_TableNUMBSCHET(void)=0;
   virtual void set_TableNUMBSCHET(TFIBWideStringField * TableNUMBSCHET)=0;

   __property TFIBWideStringField * TableGID_SBSCHET = {read = get_TableGID_SBSCHET , write = set_TableGID_SBSCHET};
   virtual TFIBWideStringField * get_TableGID_SBSCHET(void)=0;
   virtual void set_TableGID_SBSCHET(TFIBWideStringField * TableGID_SBSCHET)=0;

   __property TFIBWideStringField * TableNAMEBANK = {read = get_TableNAMEBANK , write = set_TableNAMEBANK};
   virtual TFIBWideStringField * get_TableNAMEBANK(void)=0;
   virtual void set_TableNAMEBANK(TFIBWideStringField * TableNAMEBANK)=0;

   __property TFIBWideStringField * TableBIKBANK = {read = get_TableBIKBANK , write = set_TableBIKBANK};
   virtual TFIBWideStringField * get_TableBIKBANK(void)=0;
   virtual void set_TableBIKBANK(TFIBWideStringField * TableBIKBANK)=0;

   __property TFIBWideStringField * TableGORBANK = {read = get_TableGORBANK , write = set_TableGORBANK};
   virtual TFIBWideStringField * get_TableGORBANK(void)=0;
   virtual void set_TableGORBANK(TFIBWideStringField * TableGORBANK)=0;

   __property TFIBWideStringField * TableKSBANK = {read = get_TableKSBANK , write = set_TableKSBANK};
   virtual TFIBWideStringField * get_TableKSBANK(void)=0;
   virtual void set_TableKSBANK(TFIBWideStringField * TableKSBANK)=0;

   __property TFIBWideStringField * ElementNAMEBSCHET = {read = get_ElementNAMEBSCHET , write = set_ElementNAMEBSCHET};
   virtual TFIBWideStringField * get_ElementNAMEBSCHET(void)=0;
   virtual void set_ElementNAMEBSCHET(TFIBWideStringField * ElementNAMEBSCHET)=0;

   __property TFIBWideStringField * ElementNUMBSCHET = {read = get_ElementNUMBSCHET , write = set_ElementNUMBSCHET};
   virtual TFIBWideStringField * get_ElementNUMBSCHET(void)=0;
   virtual void set_ElementNUMBSCHET(TFIBWideStringField * ElementNUMBSCHET)=0;

   __property TFIBWideStringField * ElementGID_SBSCHET = {read = get_ElementGID_SBSCHET , write = set_ElementGID_SBSCHET};
   virtual TFIBWideStringField * get_ElementGID_SBSCHET(void)=0;
   virtual void set_ElementGID_SBSCHET(TFIBWideStringField * ElementGID_SBSCHET)=0;

   __property TFIBWideStringField * ElementNAMEBANK = {read = get_ElementNAMEBANK , write = set_ElementNAMEBANK};
   virtual TFIBWideStringField * get_ElementNAMEBANK(void)=0;
   virtual void set_ElementNAMEBANK(TFIBWideStringField * ElementNAMEBANK)=0;

   __property TFIBWideStringField * ElementBIKBANK = {read = get_ElementBIKBANK , write = set_ElementBIKBANK};
   virtual TFIBWideStringField * get_ElementBIKBANK(void)=0;
   virtual void set_ElementBIKBANK(TFIBWideStringField * ElementBIKBANK)=0;

   __property TFIBWideStringField * ElementGORBANK = {read = get_ElementGORBANK , write = set_ElementGORBANK};
   virtual TFIBWideStringField * get_ElementGORBANK(void)=0;
   virtual void set_ElementGORBANK(TFIBWideStringField * ElementGORBANK)=0;

   __property TFIBWideStringField * ElementKSBANK = {read = get_ElementKSBANK , write = set_ElementKSBANK};
   virtual TFIBWideStringField * get_ElementKSBANK(void)=0;
   virtual void set_ElementKSBANK(TFIBWideStringField * ElementKSBANK)=0;

   __property TFIBWideStringField * ElementGID_SBANK = {read = get_ElementGID_SBANK , write = set_ElementGID_SBANK};
   virtual TFIBWideStringField * get_ElementGID_SBANK(void)=0;
   virtual void set_ElementGID_SBANK(TFIBWideStringField * ElementGID_SBANK)=0;

   __property TFIBWideStringField * ElementPREFIKS_NUM_SBSCHET = {read = get_ElementPREFIKS_NUM_SBSCHET , write = set_ElementPREFIKS_NUM_SBSCHET};
   virtual TFIBWideStringField * get_ElementPREFIKS_NUM_SBSCHET(void)=0;
   virtual void set_ElementPREFIKS_NUM_SBSCHET(TFIBWideStringField * ElementPREFIKS_NUM_SBSCHET)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   virtual void OpenTable()=0;
   virtual int OpenElement(__int64 Id)=0;
   virtual void NewElement()=0;
   virtual bool SaveElement(void)=0;
   virtual void DeleteElement(__int64 Id)=0;
};
#define IID_IDMSprBankSchet __uuidof(IDMSprBankSchet)
#endif
