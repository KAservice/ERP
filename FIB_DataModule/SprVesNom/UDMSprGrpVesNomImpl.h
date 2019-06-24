#ifndef UDMSprGrpVesNomImplH
#define UDMSprGrpVesNomImplH
#include "IDMSprGrpVesNom.h"
#include "UDMSprGrpVesNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{611BB41B-2760-4C16-B2B4-85FBADD9979F}"))TDMSprGrpVesNomImpl : public IDMSprGrpVesNom
{
public:
   TDMSprGrpVesNomImpl();
   ~TDMSprGrpVesNomImpl();
   TDMSprGrpVesNom * Object;
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

//IDMSprGrpVesNom
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

   virtual TFIBBCDField * get_TableID_SGRPVESNOM(void);
   virtual void set_TableID_SGRPVESNOM(TFIBBCDField * TableID_SGRPVESNOM);

   virtual TFIBBCDField * get_TableIDGRP_SGRPVESNOM(void);
   virtual void set_TableIDGRP_SGRPVESNOM(TFIBBCDField * TableIDGRP_SGRPVESNOM);

   virtual TFIBBCDField * get_TableIDBASE_SGRPVESNOM(void);
   virtual void set_TableIDBASE_SGRPVESNOM(TFIBBCDField * TableIDBASE_SGRPVESNOM);

   virtual TFIBBCDField * get_TableIDSCALE_SGRPVESNOM(void);
   virtual void set_TableIDSCALE_SGRPVESNOM(TFIBBCDField * TableIDSCALE_SGRPVESNOM);

   virtual TFIBBCDField * get_ElementID_SGRPVESNOM(void);
   virtual void set_ElementID_SGRPVESNOM(TFIBBCDField * ElementID_SGRPVESNOM);

   virtual TFIBBCDField * get_ElementIDGRP_SGRPVESNOM(void);
   virtual void set_ElementIDGRP_SGRPVESNOM(TFIBBCDField * ElementIDGRP_SGRPVESNOM);

   virtual TFIBBCDField * get_ElementIDBASE_SGRPVESNOM(void);
   virtual void set_ElementIDBASE_SGRPVESNOM(TFIBBCDField * ElementIDBASE_SGRPVESNOM);

   virtual TFIBBCDField * get_ElementIDSCALE_SGRPVESNOM(void);
   virtual void set_ElementIDSCALE_SGRPVESNOM(TFIBBCDField * ElementIDSCALE_SGRPVESNOM);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBWideStringField * get_TableNAME_SGRPVESNOM(void);
   virtual void set_TableNAME_SGRPVESNOM(TFIBWideStringField * TableNAME_SGRPVESNOM);

   virtual TFIBWideStringField * get_ElementNAME_SGRPVESNOM(void);
   virtual void set_ElementNAME_SGRPVESNOM(TFIBWideStringField * ElementNAME_SGRPVESNOM);

   virtual __int64 get_IdScale(void);
   virtual void set_IdScale(__int64 IdScale);

   virtual void OpenTable(__int64 id_scale);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_scale, __int64 id_grp);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
};
#define CLSID_TDMSprGrpVesNomImpl __uuidof(TDMSprGrpVesNomImpl)
#endif
