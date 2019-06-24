#ifndef UIDMSprFirmH
#define UIDMSprFirmH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid(Global_IID_IDMSprFirm)) IDMSprFirm : public IMainInterface
{
public:
   __property TDataSource * DataSourceElement = {read = get_DataSourceElement , write = set_DataSourceElement};
   virtual TDataSource * get_DataSourceElement(void)=0;
   virtual void set_DataSourceElement(TDataSource * DataSourceElement)=0;

   __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

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

   __property TFIBSmallIntField * ElementTYPEFIRM = {read = get_ElementTYPEFIRM , write = set_ElementTYPEFIRM};
   virtual TFIBSmallIntField * get_ElementTYPEFIRM(void)=0;
   virtual void set_ElementTYPEFIRM(TFIBSmallIntField * ElementTYPEFIRM)=0;

   __property TpFIBQuery * pFIBQ = {read = get_pFIBQ , write = set_pFIBQ};
   virtual TpFIBQuery * get_pFIBQ(void)=0;
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ)=0;

   __property TFIBBCDField * TableIDFIRM = {read = get_TableIDFIRM , write = set_TableIDFIRM};
   virtual TFIBBCDField * get_TableIDFIRM(void)=0;
   virtual void set_TableIDFIRM(TFIBBCDField * TableIDFIRM)=0;

   __property TFIBBCDField * ElementIDFIRM = {read = get_ElementIDFIRM , write = set_ElementIDFIRM};
   virtual TFIBBCDField * get_ElementIDFIRM(void)=0;
   virtual void set_ElementIDFIRM(TFIBBCDField * ElementIDFIRM)=0;

   __property TFIBWideStringField * TableINNFIRM = {read = get_TableINNFIRM , write = set_TableINNFIRM};
   virtual TFIBWideStringField * get_TableINNFIRM(void)=0;
   virtual void set_TableINNFIRM(TFIBWideStringField * TableINNFIRM)=0;

   __property TFIBWideStringField * TableNAMEFIRM = {read = get_TableNAMEFIRM , write = set_TableNAMEFIRM};
   virtual TFIBWideStringField * get_TableNAMEFIRM(void)=0;
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)=0;

   __property TFIBWideStringField * ElementNAMEFIRM = {read = get_ElementNAMEFIRM , write = set_ElementNAMEFIRM};
   virtual TFIBWideStringField * get_ElementNAMEFIRM(void)=0;
   virtual void set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM)=0;

   __property TFIBWideStringField * ElementFNAMEFIRM = {read = get_ElementFNAMEFIRM , write = set_ElementFNAMEFIRM};
   virtual TFIBWideStringField * get_ElementFNAMEFIRM(void)=0;
   virtual void set_ElementFNAMEFIRM(TFIBWideStringField * ElementFNAMEFIRM)=0;

   __property TFIBWideStringField * ElementPADRFIRM = {read = get_ElementPADRFIRM , write = set_ElementPADRFIRM};
   virtual TFIBWideStringField * get_ElementPADRFIRM(void)=0;
   virtual void set_ElementPADRFIRM(TFIBWideStringField * ElementPADRFIRM)=0;

   __property TFIBWideStringField * ElementUADRFIRM = {read = get_ElementUADRFIRM , write = set_ElementUADRFIRM};
   virtual TFIBWideStringField * get_ElementUADRFIRM(void)=0;
   virtual void set_ElementUADRFIRM(TFIBWideStringField * ElementUADRFIRM)=0;

   __property TFIBWideStringField * ElementINNFIRM = {read = get_ElementINNFIRM , write = set_ElementINNFIRM};
   virtual TFIBWideStringField * get_ElementINNFIRM(void)=0;
   virtual void set_ElementINNFIRM(TFIBWideStringField * ElementINNFIRM)=0;

   __property TFIBWideStringField * ElementKPPFIRM = {read = get_ElementKPPFIRM , write = set_ElementKPPFIRM};
   virtual TFIBWideStringField * get_ElementKPPFIRM(void)=0;
   virtual void set_ElementKPPFIRM(TFIBWideStringField * ElementKPPFIRM)=0;

   __property TFIBWideStringField * ElementDIRFIRM = {read = get_ElementDIRFIRM , write = set_ElementDIRFIRM};
   virtual TFIBWideStringField * get_ElementDIRFIRM(void)=0;
   virtual void set_ElementDIRFIRM(TFIBWideStringField * ElementDIRFIRM)=0;

   __property TFIBWideStringField * ElementBUHFIRM = {read = get_ElementBUHFIRM , write = set_ElementBUHFIRM};
   virtual TFIBWideStringField * get_ElementBUHFIRM(void)=0;
   virtual void set_ElementBUHFIRM(TFIBWideStringField * ElementBUHFIRM)=0;

   __property TFIBWideStringField * ElementKASFIRM = {read = get_ElementKASFIRM , write = set_ElementKASFIRM};
   virtual TFIBWideStringField * get_ElementKASFIRM(void)=0;
   virtual void set_ElementKASFIRM(TFIBWideStringField * ElementKASFIRM)=0;

   __property TFIBWideStringField * ElementGID_SFIRM = {read = get_ElementGID_SFIRM , write = set_ElementGID_SFIRM};
   virtual TFIBWideStringField * get_ElementGID_SFIRM(void)=0;
   virtual void set_ElementGID_SFIRM(TFIBWideStringField * ElementGID_SFIRM)=0;

   __property TFIBWideStringField * ElementNUMDOCREGFIRM = {read = get_ElementNUMDOCREGFIRM , write = set_ElementNUMDOCREGFIRM};
   virtual TFIBWideStringField * get_ElementNUMDOCREGFIRM(void)=0;
   virtual void set_ElementNUMDOCREGFIRM(TFIBWideStringField * ElementNUMDOCREGFIRM)=0;

   __property TFIBWideStringField * ElementOKPOSFIRM = {read = get_ElementOKPOSFIRM , write = set_ElementOKPOSFIRM};
   virtual TFIBWideStringField * get_ElementOKPOSFIRM(void)=0;
   virtual void set_ElementOKPOSFIRM(TFIBWideStringField * ElementOKPOSFIRM)=0;

   __property TFIBWideStringField * ElementOKDPSFIRM = {read = get_ElementOKDPSFIRM , write = set_ElementOKDPSFIRM};
   virtual TFIBWideStringField * get_ElementOKDPSFIRM(void)=0;
   virtual void set_ElementOKDPSFIRM(TFIBWideStringField * ElementOKDPSFIRM)=0;

   __property TFIBWideStringField * ElementTELFIRM = {read = get_ElementTELFIRM , write = set_ElementTELFIRM};
   virtual TFIBWideStringField * get_ElementTELFIRM(void)=0;
   virtual void set_ElementTELFIRM(TFIBWideStringField * ElementTELFIRM)=0;

   __property TFIBBCDField * ElementIDBASE_SFIRM = {read = get_ElementIDBASE_SFIRM , write = set_ElementIDBASE_SFIRM};
   virtual TFIBBCDField * get_ElementIDBASE_SFIRM(void)=0;
   virtual void set_ElementIDBASE_SFIRM(TFIBBCDField * ElementIDBASE_SFIRM)=0;

   __property TFIBWideStringField * ElementKRNAMEFIRM = {read = get_ElementKRNAMEFIRM , write = set_ElementKRNAMEFIRM};
   virtual TFIBWideStringField * get_ElementKRNAMEFIRM(void)=0;
   virtual void set_ElementKRNAMEFIRM(TFIBWideStringField * ElementKRNAMEFIRM)=0;

   __property TFIBWideStringField * ElementDATEDOCREGFIRM = {read = get_ElementDATEDOCREGFIRM , write = set_ElementDATEDOCREGFIRM};
   virtual TFIBWideStringField * get_ElementDATEDOCREGFIRM(void)=0;
   virtual void set_ElementDATEDOCREGFIRM(TFIBWideStringField * ElementDATEDOCREGFIRM)=0;

   __property TFIBWideStringField * ElementPREFIKS_NUM_SFIRM = {read = get_ElementPREFIKS_NUM_SFIRM , write = set_ElementPREFIKS_NUM_SFIRM};
   virtual TFIBWideStringField * get_ElementPREFIKS_NUM_SFIRM(void)=0;
   virtual void set_ElementPREFIKS_NUM_SFIRM(TFIBWideStringField * ElementPREFIKS_NUM_SFIRM)=0;

   virtual bool OpenTable(void)=0;
   virtual int  OpenElement(__int64 Id)=0;
   virtual bool NewElement(void)=0;
   virtual bool SaveElement(void)=0;
   virtual bool DeleteElement(__int64 Id)=0;
   virtual UnicodeString GetGIDElement(__int64 id)=0;
   virtual __int64 GetIDElement(AnsiString gid)=0;
   virtual int GetIndexElementaPoID(__int64 id)=0;
};
#define IID_IDMSprFirm __uuidof(IDMSprFirm)
#endif
