#ifndef UDMSprImportNomImplH
#define UDMSprImportNomImplH
#include "IDMSprImportNom.h"
#include "UDMSprImportNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{9F332130-04C5-4BA2-9E6E-A13C3AED44A8}")) TDMSprImportNomImpl : public IDMSprImportNom
{
public:
   TDMSprImportNomImpl();
   ~TDMSprImportNomImpl();
   TDMSprImportNom * Object;
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

//IDMSprImportNom
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

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_TableID_SIMPORTNOM(void);
   virtual void set_TableID_SIMPORTNOM(TFIBBCDField * TableID_SIMPORTNOM);

   virtual TFIBBCDField * get_TableIDBASE_SIMPORTNOM(void);
   virtual void set_TableIDBASE_SIMPORTNOM(TFIBBCDField * TableIDBASE_SIMPORTNOM);

   virtual TFIBBCDField * get_TableIDNOM_SIMPORTNOM(void);
   virtual void set_TableIDNOM_SIMPORTNOM(TFIBBCDField * TableIDNOM_SIMPORTNOM);

   virtual TFIBBCDField * get_TableIDKLIENT_SIMPORTNOM(void);
   virtual void set_TableIDKLIENT_SIMPORTNOM(TFIBBCDField * TableIDKLIENT_SIMPORTNOM);

   virtual TFIBBCDField * get_ElementID_SIMPORTNOM(void);
   virtual void set_ElementID_SIMPORTNOM(TFIBBCDField * ElementID_SIMPORTNOM);

   virtual TFIBBCDField * get_ElementIDBASE_SIMPORTNOM(void);
   virtual void set_ElementIDBASE_SIMPORTNOM(TFIBBCDField * ElementIDBASE_SIMPORTNOM);

   virtual TFIBBCDField * get_ElementIDNOM_SIMPORTNOM(void);
   virtual void set_ElementIDNOM_SIMPORTNOM(TFIBBCDField * ElementIDNOM_SIMPORTNOM);

   virtual TFIBBCDField * get_ElementIDKLIENT_SIMPORTNOM(void);
   virtual void set_ElementIDKLIENT_SIMPORTNOM(TFIBBCDField * ElementIDKLIENT_SIMPORTNOM);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBWideStringField * get_TableCODE_SIMPORTNOM(void);
   virtual void set_TableCODE_SIMPORTNOM(TFIBWideStringField * TableCODE_SIMPORTNOM);

   virtual TFIBWideStringField * get_TableART_SIMPORTNOM(void);
   virtual void set_TableART_SIMPORTNOM(TFIBWideStringField * TableART_SIMPORTNOM);

   virtual TFIBWideStringField * get_TableNAME_SIMPORTNOM(void);
   virtual void set_TableNAME_SIMPORTNOM(TFIBWideStringField * TableNAME_SIMPORTNOM);

   virtual TFIBWideStringField * get_ElementCODE_SIMPORTNOM(void);
   virtual void set_ElementCODE_SIMPORTNOM(TFIBWideStringField * ElementCODE_SIMPORTNOM);

   virtual TFIBWideStringField * get_ElementART_SIMPORTNOM(void);
   virtual void set_ElementART_SIMPORTNOM(TFIBWideStringField * ElementART_SIMPORTNOM);

   virtual TFIBWideStringField * get_ElementNAME_SIMPORTNOM(void);
   virtual void set_ElementNAME_SIMPORTNOM(TFIBWideStringField * ElementNAME_SIMPORTNOM);

   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void);
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT);

   virtual void OpenTable(__int64 id_nom);
   virtual int OpenElement(__int64 id);;
   virtual bool NewElement(__int64 id_nom);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 FindNomPoArtikulu(__int64 id_post, UnicodeString artikul);
   virtual __int64 FindNomPoCodu(__int64 id_post, UnicodeString code);
   virtual __int64 FindNomPoName(__int64 id_post, UnicodeString name);
   virtual __int64 FindElementPoArtikulu(__int64 id_post, UnicodeString artikul);
   virtual __int64 FindElementPoCodu(__int64 id_post, UnicodeString code);
   virtual __int64 FindElementPoName(__int64 id_post, UnicodeString name);
};
#define CLSID_TDMSprImportNomImpl __uuidof(TDMSprImportNomImpl)
#endif
