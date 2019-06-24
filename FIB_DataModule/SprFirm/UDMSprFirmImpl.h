#ifndef UDMSprFirmImplH
#define UDMSprFirmImplH
#include "IDMSprFirm.h"
#include "UDMSprFirm.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprFirmImpl)) TDMSprFirmImpl : public IDMSprFirm
{
public:
   TDMSprFirmImpl();
   ~TDMSprFirmImpl();
   TDMSprFirm * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);

   //IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

//IDMSprFirm
   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBSmallIntField * get_ElementTYPEFIRM(void);
   virtual void set_ElementTYPEFIRM(TFIBSmallIntField * ElementTYPEFIRM);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_TableIDFIRM(void);
   virtual void set_TableIDFIRM(TFIBBCDField * TableIDFIRM);

   virtual TFIBBCDField * get_ElementIDFIRM(void);
   virtual void set_ElementIDFIRM(TFIBBCDField * ElementIDFIRM);

   virtual TFIBWideStringField * get_TableINNFIRM(void);
   virtual void set_TableINNFIRM(TFIBWideStringField * TableINNFIRM);

   virtual TFIBWideStringField * get_TableNAMEFIRM(void);
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM);

   virtual TFIBWideStringField * get_ElementNAMEFIRM(void);
   virtual void set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM);

   virtual TFIBWideStringField * get_ElementFNAMEFIRM(void);
   virtual void set_ElementFNAMEFIRM(TFIBWideStringField * ElementFNAMEFIRM);

   virtual TFIBWideStringField * get_ElementPADRFIRM(void);
   virtual void set_ElementPADRFIRM(TFIBWideStringField * ElementPADRFIRM);

   virtual TFIBWideStringField * get_ElementUADRFIRM(void);
   virtual void set_ElementUADRFIRM(TFIBWideStringField * ElementUADRFIRM);

   virtual TFIBWideStringField * get_ElementINNFIRM(void);
   virtual void set_ElementINNFIRM(TFIBWideStringField * ElementINNFIRM);

   virtual TFIBWideStringField * get_ElementKPPFIRM(void);
   virtual void set_ElementKPPFIRM(TFIBWideStringField * ElementKPPFIRM);

   virtual TFIBWideStringField * get_ElementDIRFIRM(void);
   virtual void set_ElementDIRFIRM(TFIBWideStringField * ElementDIRFIRM);

   virtual TFIBWideStringField * get_ElementBUHFIRM(void);
   virtual void set_ElementBUHFIRM(TFIBWideStringField * ElementBUHFIRM);

   virtual TFIBWideStringField * get_ElementKASFIRM(void);
   virtual void set_ElementKASFIRM(TFIBWideStringField * ElementKASFIRM);

   virtual TFIBWideStringField * get_ElementGID_SFIRM(void);
   virtual void set_ElementGID_SFIRM(TFIBWideStringField * ElementGID_SFIRM);

   virtual TFIBWideStringField * get_ElementNUMDOCREGFIRM(void);
   virtual void set_ElementNUMDOCREGFIRM(TFIBWideStringField * ElementNUMDOCREGFIRM);

   virtual TFIBWideStringField * get_ElementOKPOSFIRM(void);
   virtual void set_ElementOKPOSFIRM(TFIBWideStringField * ElementOKPOSFIRM);

   virtual TFIBWideStringField * get_ElementOKDPSFIRM(void);
   virtual void set_ElementOKDPSFIRM(TFIBWideStringField * ElementOKDPSFIRM);

   virtual TFIBWideStringField * get_ElementTELFIRM(void);
   virtual void set_ElementTELFIRM(TFIBWideStringField * ElementTELFIRM);

   virtual TFIBBCDField * get_ElementIDBASE_SFIRM(void);
   virtual void set_ElementIDBASE_SFIRM(TFIBBCDField * ElementIDBASE_SFIRM);

   virtual TFIBWideStringField * get_ElementKRNAMEFIRM(void);
   virtual void set_ElementKRNAMEFIRM(TFIBWideStringField * ElementKRNAMEFIRM);

   virtual TFIBWideStringField * get_ElementDATEDOCREGFIRM(void);
   virtual void set_ElementDATEDOCREGFIRM(TFIBWideStringField * ElementDATEDOCREGFIRM);

   virtual TFIBWideStringField * get_ElementPREFIKS_NUM_SFIRM(void);
   virtual void set_ElementPREFIKS_NUM_SFIRM(TFIBWideStringField * ElementPREFIKS_NUM_SFIRM);

   virtual bool OpenTable(void);
   virtual int  OpenElement(__int64 Id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual UnicodeString GetGIDElement(__int64 id);
   virtual __int64 GetIDElement(AnsiString gid);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_TDMSprFirmImpl __uuidof(TDMSprFirmImpl)
#endif
