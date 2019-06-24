#ifndef UDMSprBankSchetImplH
#define UDMSprBankSchetImplH
#include "IDMSprBankSchet.h"
#include "UDMSprBankSchet.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprBankSchetImpl)) TDMSprBankSchetImpl : public IDMSprBankSchet
{
public:
   TDMSprBankSchetImpl();
   ~TDMSprBankSchetImpl();
   TDMSprBankSchet * Object;
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

//IDMSprBankSchet
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

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

   virtual TFIBBCDField * get_TableIDBSCHET(void);
   virtual void set_TableIDBSCHET(TFIBBCDField * TableIDBSCHET);

   virtual TFIBBCDField * get_TableIDBANKBSCHET(void);
   virtual void set_TableIDBANKBSCHET(TFIBBCDField * TableIDBANKBSCHET);

   virtual TFIBBCDField * get_TableIDFIRMBSCHET(void);
   virtual void set_TableIDFIRMBSCHET(TFIBBCDField * TableIDFIRMBSCHET);

   virtual TFIBBCDField * get_ElementIDBSCHET(void);
   virtual void set_ElementIDBSCHET(TFIBBCDField * ElementIDBSCHET);

   virtual TFIBBCDField * get_ElementIDBANKBSCHET(void);
   virtual void set_ElementIDBANKBSCHET(TFIBBCDField * ElementIDBANKBSCHET);

   virtual TFIBBCDField * get_ElementIDFIRMBSCHET(void);
   virtual void set_ElementIDFIRMBSCHET(TFIBBCDField * ElementIDFIRMBSCHET);

   virtual TFIBBCDField * get_ElementIDBANK(void);
   virtual void set_ElementIDBANK(TFIBBCDField * ElementIDBANK);

   virtual TFIBWideStringField * get_TableNAMEBSCHET(void);
   virtual void set_TableNAMEBSCHET(TFIBWideStringField * TableNAMEBSCHET);

   virtual TFIBWideStringField * get_TableNUMBSCHET(void);
   virtual void set_TableNUMBSCHET(TFIBWideStringField * TableNUMBSCHET);

   virtual TFIBWideStringField * get_TableGID_SBSCHET(void);
   virtual void set_TableGID_SBSCHET(TFIBWideStringField * TableGID_SBSCHET);

   virtual TFIBWideStringField * get_TableNAMEBANK(void);
   virtual void set_TableNAMEBANK(TFIBWideStringField * TableNAMEBANK);

   virtual TFIBWideStringField * get_TableBIKBANK(void);
   virtual void set_TableBIKBANK(TFIBWideStringField * TableBIKBANK);

   virtual TFIBWideStringField * get_TableGORBANK(void);
   virtual void set_TableGORBANK(TFIBWideStringField * TableGORBANK);

   virtual TFIBWideStringField * get_TableKSBANK(void);
   virtual void set_TableKSBANK(TFIBWideStringField * TableKSBANK);

   virtual TFIBWideStringField * get_ElementNAMEBSCHET(void);
   virtual void set_ElementNAMEBSCHET(TFIBWideStringField * ElementNAMEBSCHET);

   virtual TFIBWideStringField * get_ElementNUMBSCHET(void);
   virtual void set_ElementNUMBSCHET(TFIBWideStringField * ElementNUMBSCHET);

   virtual TFIBWideStringField * get_ElementGID_SBSCHET(void);
   virtual void set_ElementGID_SBSCHET(TFIBWideStringField * ElementGID_SBSCHET);

   virtual TFIBWideStringField * get_ElementNAMEBANK(void);
   virtual void set_ElementNAMEBANK(TFIBWideStringField * ElementNAMEBANK);

   virtual TFIBWideStringField * get_ElementBIKBANK(void);
   virtual void set_ElementBIKBANK(TFIBWideStringField * ElementBIKBANK);

   virtual TFIBWideStringField * get_ElementGORBANK(void);
   virtual void set_ElementGORBANK(TFIBWideStringField * ElementGORBANK);

   virtual TFIBWideStringField * get_ElementKSBANK(void);
   virtual void set_ElementKSBANK(TFIBWideStringField * ElementKSBANK);

   virtual TFIBWideStringField * get_ElementGID_SBANK(void);
   virtual void set_ElementGID_SBANK(TFIBWideStringField * ElementGID_SBANK);

   virtual TFIBWideStringField * get_ElementPREFIKS_NUM_SBSCHET(void);
   virtual void set_ElementPREFIKS_NUM_SBSCHET(TFIBWideStringField * ElementPREFIKS_NUM_SBSCHET);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual void OpenTable();
   virtual int OpenElement(__int64 Id);
   virtual void NewElement();
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
};
#define CLSID_TDMSprBankSchetImpl __uuidof(TDMSprBankSchetImpl)
#endif
