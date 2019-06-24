#ifndef UDMSprGrpBVNomImplH
#define UDMSprGrpBVNomImplH
#include "IDMSprGrpBVNom.h"
#include "UDMSprGrpBVNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{EE848772-C33B-424D-AFFE-211A478F07E5}")) TDMSprGrpBVNomImpl : public IDMSprGrpBVNom
{
public:
   TDMSprGrpBVNomImpl();
   ~TDMSprGrpBVNomImpl();
   TDMSprGrpBVNom * Object;
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

//IDMSprGrpBVNom
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

   virtual TFIBBCDField * get_TableID_GBVNOM(void);
   virtual void set_TableID_GBVNOM(TFIBBCDField * TableID_GBVNOM);

   virtual TFIBBCDField * get_TableIDGRP_GBVNOM(void);
   virtual void set_TableIDGRP_GBVNOM(TFIBBCDField * TableIDGRP_GBVNOM);

   virtual TFIBBCDField * get_TableIDPOD_GBVNOM(void);
   virtual void set_TableIDPOD_GBVNOM(TFIBBCDField * TableIDPOD_GBVNOM);

   virtual TFIBBCDField * get_ElementID_GBVNOM(void);
   virtual void set_ElementID_GBVNOM(TFIBBCDField * ElementID_GBVNOM);

   virtual TFIBBCDField * get_ElementIDGRP_GBVNOM(void);
   virtual void set_ElementIDGRP_GBVNOM(TFIBBCDField * ElementIDGRP_GBVNOM);

   virtual TFIBBCDField * get_ElementIDPOD_GBVNOM(void);
   virtual void set_ElementIDPOD_GBVNOM(TFIBBCDField * ElementIDPOD_GBVNOM);

   virtual TFIBWideStringField * get_TableNAME_GBVNOM(void);
   virtual void set_TableNAME_GBVNOM(TFIBWideStringField * TableNAME_GBVNOM);

   virtual TFIBWideStringField * get_TableGID_SGBVNOM(void);
   virtual void set_TableGID_SGBVNOM(TFIBWideStringField * TableGID_SGBVNOM);

   virtual TFIBWideStringField * get_ElementNAME_GBVNOM(void);
   virtual void set_ElementNAME_GBVNOM(TFIBWideStringField * ElementNAME_GBVNOM);

   virtual TFIBWideStringField * get_ElementGID_SGBVNOM(void);
   virtual void set_ElementGID_SGBVNOM(TFIBWideStringField * ElementGID_SGBVNOM);

   virtual __int64 get_IdPod(void);
   virtual void set_IdPod(__int64 IdPod);

   virtual void OpenTable(__int64 Pod);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(__int64 Pod, __int64 Grp);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
};
#define CLSID_TDMSprGrpBVNomImpl __uuidof(TDMSprGrpBVNomImpl)
#endif
