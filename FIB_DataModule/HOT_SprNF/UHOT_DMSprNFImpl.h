#ifndef UHOT_DMSprNFImplH
#define UHOT_DMSprNFImplH
#include "IHOT_DMSprNF.h"
#include "UHOT_DMSprNF.h"
//---------------------------------------------------------------
class __declspec(uuid("{F6AC46C5-F37F-4728-A644-96A97876F514}")) THOT_DMSprNFImpl : public IHOT_DMSprNF
{
public:
   THOT_DMSprNFImpl();
   ~THOT_DMSprNFImpl();
   THOT_DMSprNF * Object;
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

//IHOT_DMSprNF
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBIntegerField * get_TableKOLM_HOT_SNF(void);
   virtual void set_TableKOLM_HOT_SNF(TFIBIntegerField * TableKOLM_HOT_SNF);

   virtual TFIBDateTimeField * get_TablePOSIN_HOT_SNF(void);
   virtual void set_TablePOSIN_HOT_SNF(TFIBDateTimeField * TablePOSIN_HOT_SNF);

   virtual TFIBDateTimeField * get_TablePOSOUT_HOT_SNF(void);
   virtual void set_TablePOSOUT_HOT_SNF(TFIBDateTimeField * TablePOSOUT_HOT_SNF);

   virtual TFIBIntegerField * get_ElementKOLM_HOT_SNF(void);
   virtual void set_ElementKOLM_HOT_SNF(TFIBIntegerField * ElementKOLM_HOT_SNF);

   virtual TFIBDateTimeField * get_ElementPOSIN_HOT_SNF(void);
   virtual void set_ElementPOSIN_HOT_SNF(TFIBDateTimeField * ElementPOSIN_HOT_SNF);

   virtual TFIBDateTimeField * get_ElementPOSOUT_HOT_SNF(void);
   virtual void set_ElementPOSOUT_HOT_SNF(TFIBDateTimeField * ElementPOSOUT_HOT_SNF);

   virtual TFIBBCDField * get_ElementID_HOT_SNF(void);
   virtual void set_ElementID_HOT_SNF(TFIBBCDField * ElementID_HOT_SNF);

   virtual TFIBBCDField * get_ElementIDOB_HOT_SNF(void);
   virtual void set_ElementIDOB_HOT_SNF(TFIBBCDField * ElementIDOB_HOT_SNF);

   virtual TFIBBCDField * get_ElementIDCAT_HOT_SNF(void);
   virtual void set_ElementIDCAT_HOT_SNF(TFIBBCDField * ElementIDCAT_HOT_SNF);

   virtual TFIBBCDField * get_TableID_HOT_SNF(void);
   virtual void set_TableID_HOT_SNF(TFIBBCDField * TableID_HOT_SNF);

   virtual TFIBBCDField * get_TableIDOB_HOT_SNF(void);
   virtual void set_TableIDOB_HOT_SNF(TFIBBCDField * TableIDOB_HOT_SNF);

   virtual TFIBBCDField * get_TableIDCAT_HOT_SNF(void);
   virtual void set_TableIDCAT_HOT_SNF(TFIBBCDField * TableIDCAT_HOT_SNF);

   virtual TFIBWideStringField * get_ElementNAME_HOT_SNF(void);
   virtual void set_ElementNAME_HOT_SNF(TFIBWideStringField * ElementNAME_HOT_SNF);

   virtual TFIBWideStringField * get_ElementNAME_HOT_SOBJECT(void);
   virtual void set_ElementNAME_HOT_SOBJECT(TFIBWideStringField * ElementNAME_HOT_SOBJECT);

   virtual TFIBWideStringField * get_ElementNAME_HOT_SCATNOM(void);
   virtual void set_ElementNAME_HOT_SCATNOM(TFIBWideStringField * ElementNAME_HOT_SCATNOM);

   virtual TFIBWideStringField * get_TableNAME_HOT_SNF(void);
   virtual void set_TableNAME_HOT_SNF(TFIBWideStringField * TableNAME_HOT_SNF);

   virtual TFIBWideStringField * get_TableNAME_HOT_SOBJECT(void);
   virtual void set_TableNAME_HOT_SOBJECT(TFIBWideStringField * TableNAME_HOT_SOBJECT);

   virtual TFIBWideStringField * get_TableNAME_HOT_SCATNOM(void);
   virtual void set_TableNAME_HOT_SCATNOM(TFIBWideStringField * TableNAME_HOT_SCATNOM);

   virtual void OpenTable(void);
   virtual void UpdateTable(void);
   virtual int OpenElement(__int64 Id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_THOT_DMSprNFImpl __uuidof(THOT_DMSprNFImpl)
#endif
