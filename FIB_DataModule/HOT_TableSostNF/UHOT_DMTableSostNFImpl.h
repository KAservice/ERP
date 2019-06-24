#ifndef UHOT_DMTableSostNFImplH
#define UHOT_DMTableSostNFImplH
#include "IHOT_DMTableSostNF.h"
#include "UHOT_DMTableSostNF.h"
//---------------------------------------------------------------
class __declspec(uuid("{BF540B66-CBB3-4B30-A29E-74FB654CEB10}")) THOT_DMTableSostNFImpl : public IHOT_DMTableSostNF
{
public:
   THOT_DMTableSostNFImpl();
   ~THOT_DMTableSostNFImpl();
   THOT_DMTableSostNF * Object;
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

//IHOT_DMTableSostNF
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TFIBIntegerField * get_TableKOLM_HOT_SOSTNF(void);
   virtual void set_TableKOLM_HOT_SOSTNF(TFIBIntegerField * TableKOLM_HOT_SOSTNF);

   virtual TFIBDateTimeField * get_TablePOSNACH_HOT_SOSTNF(void);
   virtual void set_TablePOSNACH_HOT_SOSTNF(TFIBDateTimeField * TablePOSNACH_HOT_SOSTNF);

   virtual TFIBDateTimeField * get_TablePOSCON_HOT_SOSTNF(void);
   virtual void set_TablePOSCON_HOT_SOSTNF(TFIBDateTimeField * TablePOSCON_HOT_SOSTNF);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBIntegerField * get_ElementKOLM_HOT_SOSTNF(void);
   virtual void set_ElementKOLM_HOT_SOSTNF(TFIBIntegerField * ElementKOLM_HOT_SOSTNF);

   virtual TFIBDateTimeField * get_ElementPOSNACH_HOT_SOSTNF(void);
   virtual void set_ElementPOSNACH_HOT_SOSTNF(TFIBDateTimeField * ElementPOSNACH_HOT_SOSTNF);

   virtual TFIBDateTimeField * get_ElementPOSCON_HOT_SOSTNF(void);
   virtual void set_ElementPOSCON_HOT_SOSTNF(TFIBDateTimeField * ElementPOSCON_HOT_SOSTNF);

   virtual TFIBBCDField * get_TableID_HOT_SOSTNF(void);
   virtual void set_TableID_HOT_SOSTNF(TFIBBCDField * TableID_HOT_SOSTNF);

   virtual TFIBBCDField * get_TableIDNOMER_HOT_SOSTNF(void);
   virtual void set_TableIDNOMER_HOT_SOSTNF(TFIBBCDField * TableIDNOMER_HOT_SOSTNF);

   virtual TFIBBCDField * get_TableIDPLAT_HOT_SOSTNF(void);
   virtual void set_TableIDPLAT_HOT_SOSTNF(TFIBBCDField * TableIDPLAT_HOT_SOSTNF);

   virtual TFIBBCDField * get_TableIDGUEST_HOT_SOSTNF(void);
   virtual void set_TableIDGUEST_HOT_SOSTNF(TFIBBCDField * TableIDGUEST_HOT_SOSTNF);

   virtual TFIBBCDField * get_TableIDSOST_HOT_SOSTNF(void);
   virtual void set_TableIDSOST_HOT_SOSTNF(TFIBBCDField * TableIDSOST_HOT_SOSTNF);

   virtual TFIBBCDField * get_TableIDTPOS_HOT_SOSTNF(void);
   virtual void set_TableIDTPOS_HOT_SOSTNF(TFIBBCDField * TableIDTPOS_HOT_SOSTNF);

   virtual TFIBBCDField * get_TableIDCAT_HOT_SOSTNF(void);
   virtual void set_TableIDCAT_HOT_SOSTNF(TFIBBCDField * TableIDCAT_HOT_SOSTNF);

   virtual TFIBBCDField * get_TableIDDOCH_HOT_SOSTNF(void);
   virtual void set_TableIDDOCH_HOT_SOSTNF(TFIBBCDField * TableIDDOCH_HOT_SOSTNF);

   virtual TFIBBCDField * get_ElementID_HOT_SOSTNF(void);
   virtual void set_ElementID_HOT_SOSTNF(TFIBBCDField * ElementID_HOT_SOSTNF);

   virtual TFIBBCDField * get_ElementIDNOMER_HOT_SOSTNF(void);
   virtual void set_ElementIDNOMER_HOT_SOSTNF(TFIBBCDField * ElementIDNOMER_HOT_SOSTNF);

   virtual TFIBBCDField * get_ElementIDPLAT_HOT_SOSTNF(void);
   virtual void set_ElementIDPLAT_HOT_SOSTNF(TFIBBCDField * ElementIDPLAT_HOT_SOSTNF);

   virtual TFIBBCDField * get_ElementIDGUEST_HOT_SOSTNF(void);
   virtual void set_ElementIDGUEST_HOT_SOSTNF(TFIBBCDField * ElementIDGUEST_HOT_SOSTNF);

   virtual TFIBBCDField * get_ElementIDSOST_HOT_SOSTNF(void);
   virtual void set_ElementIDSOST_HOT_SOSTNF(TFIBBCDField * ElementIDSOST_HOT_SOSTNF);

   virtual TFIBBCDField * get_ElementIDTPOS_HOT_SOSTNF(void);
   virtual void set_ElementIDTPOS_HOT_SOSTNF(TFIBBCDField * ElementIDTPOS_HOT_SOSTNF);

   virtual TFIBBCDField * get_ElementIDCAT_HOT_SOSTNF(void);
   virtual void set_ElementIDCAT_HOT_SOSTNF(TFIBBCDField * ElementIDCAT_HOT_SOSTNF);

   virtual TFIBBCDField * get_ElementIDDOCH_HOT_SOSTNF(void);
   virtual void set_ElementIDDOCH_HOT_SOSTNF(TFIBBCDField * ElementIDDOCH_HOT_SOSTNF);

   virtual TFIBBCDField * get_ElementIDCEL_HOT_SOSTNF(void);
   virtual void set_ElementIDCEL_HOT_SOSTNF(TFIBBCDField * ElementIDCEL_HOT_SOSTNF);

   virtual TFIBWideStringField * get_TableNAMEPLAT(void);
   virtual void set_TableNAMEPLAT(TFIBWideStringField * TableNAMEPLAT);

   virtual TFIBWideStringField * get_TableNAMEGUEST(void);
   virtual void set_TableNAMEGUEST(TFIBWideStringField * TableNAMEGUEST);

   virtual TFIBWideStringField * get_TableNAME_HOT_SNF(void);
   virtual void set_TableNAME_HOT_SNF(TFIBWideStringField * TableNAME_HOT_SNF);

   virtual TFIBWideStringField * get_TableNAME_HOT_SSOSTNOM(void);
   virtual void set_TableNAME_HOT_SSOSTNOM(TFIBWideStringField * TableNAME_HOT_SSOSTNOM);

   virtual TFIBWideStringField * get_TableNAME_HOT_STYPEPOS(void);
   virtual void set_TableNAME_HOT_STYPEPOS(TFIBWideStringField * TableNAME_HOT_STYPEPOS);

   virtual TFIBWideStringField * get_ElementNAMEPLAT(void);
   virtual void set_ElementNAMEPLAT(TFIBWideStringField * ElementNAMEPLAT);

   virtual TFIBWideStringField * get_ElementNAMEGUEST(void);
   virtual void set_ElementNAMEGUEST(TFIBWideStringField * ElementNAMEGUEST);

   virtual TFIBWideStringField * get_ElementNAME_HOT_SNF(void);
   virtual void set_ElementNAME_HOT_SNF(TFIBWideStringField * ElementNAME_HOT_SNF);

   virtual TFIBWideStringField * get_ElementNAME_HOT_SSOSTNOM(void);
   virtual void set_ElementNAME_HOT_SSOSTNOM(TFIBWideStringField * ElementNAME_HOT_SSOSTNOM);

   virtual TFIBWideStringField * get_ElementNAME_HOT_STYPEPOS(void);
   virtual void set_ElementNAME_HOT_STYPEPOS(TFIBWideStringField * ElementNAME_HOT_STYPEPOS);

   virtual TFIBWideStringField * get_ElementNAME_HOT_SCATNOM(void);
   virtual void set_ElementNAME_HOT_SCATNOM(TFIBWideStringField * ElementNAME_HOT_SCATNOM);

   virtual TFIBWideStringField * get_ElementNAME_HOT_SCELPR(void);
   virtual void set_ElementNAME_HOT_SCELPR(TFIBWideStringField * ElementNAME_HOT_SCELPR);

   virtual __int64 get_IdPlat(void);
   virtual void set_IdPlat(__int64 IdPlat);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 Id);
};
#define CLSID_THOT_DMTableSostNFImpl __uuidof(THOT_DMTableSostNFImpl)
#endif
