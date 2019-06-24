#ifndef UDMSprImportEdImplH
#define UDMSprImportEdImplH
#include "IDMSprImportEd.h"
#include "UDMSprImportEd.h"
//---------------------------------------------------------------
class __declspec(uuid("{85D17C4E-0B65-4CE0-B6A5-647A8F56C5A5}")) TDMSprImportEdImpl : public IDMSprImportEd
{
public:
   TDMSprImportEdImpl();
   ~TDMSprImportEdImpl();
   TDMSprImportEd * Object;
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

//IDMSprImportEd
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

   virtual TFIBBCDField * get_TableID_SIMPORTED(void);
   virtual void set_TableID_SIMPORTED(TFIBBCDField * TableID_SIMPORTED);

   virtual TFIBBCDField * get_TableIDBASE_SIMPORTED(void);
   virtual void set_TableIDBASE_SIMPORTED(TFIBBCDField * TableIDBASE_SIMPORTED);

   virtual TFIBBCDField * get_TableIDNOM_SIMPORTED(void);
   virtual void set_TableIDNOM_SIMPORTED(TFIBBCDField * TableIDNOM_SIMPORTED);

   virtual TFIBBCDField * get_TableIDKLIENT_SIMPORTED(void);
   virtual void set_TableIDKLIENT_SIMPORTED(TFIBBCDField * TableIDKLIENT_SIMPORTED);

   virtual TFIBBCDField * get_TableIDED_SIMPORTED(void);
   virtual void set_TableIDED_SIMPORTED(TFIBBCDField * TableIDED_SIMPORTED);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBBCDField * get_ElementID_SIMPORTED(void);
   virtual void set_ElementID_SIMPORTED(TFIBBCDField * ElementID_SIMPORTED);

   virtual TFIBBCDField * get_ElementIDBASE_SIMPORTED(void);
   virtual void set_ElementIDBASE_SIMPORTED(TFIBBCDField * ElementIDBASE_SIMPORTED);

   virtual TFIBBCDField * get_ElementIDNOM_SIMPORTED(void);
   virtual void set_ElementIDNOM_SIMPORTED(TFIBBCDField * ElementIDNOM_SIMPORTED);

   virtual TFIBBCDField * get_ElementIDKLIENT_SIMPORTED(void);
   virtual void set_ElementIDKLIENT_SIMPORTED(TFIBBCDField * ElementIDKLIENT_SIMPORTED);

   virtual TFIBBCDField * get_ElementIDED_SIMPORTED(void);
   virtual void set_ElementIDED_SIMPORTED(TFIBBCDField * ElementIDED_SIMPORTED);

   virtual TFIBWideStringField * get_TableBARCODE_SIMPORTED(void);
   virtual void set_TableBARCODE_SIMPORTED(TFIBWideStringField * TableBARCODE_SIMPORTED);

   virtual TFIBWideStringField * get_TableCODE_SIMPORTED(void);
   virtual void set_TableCODE_SIMPORTED(TFIBWideStringField * TableCODE_SIMPORTED);

   virtual TFIBWideStringField * get_TableNAME_SIMPORTED(void);
   virtual void set_TableNAME_SIMPORTED(TFIBWideStringField * TableNAME_SIMPORTED);

   virtual TFIBWideStringField * get_ElementBARCODE_SIMPORTED(void);
   virtual void set_ElementBARCODE_SIMPORTED(TFIBWideStringField * ElementBARCODE_SIMPORTED);

   virtual TFIBWideStringField * get_ElementCODE_SIMPORTED(void);
   virtual void set_ElementCODE_SIMPORTED(TFIBWideStringField * ElementCODE_SIMPORTED);

   virtual TFIBWideStringField * get_ElementNAME_SIMPORTED(void);
   virtual void set_ElementNAME_SIMPORTED(TFIBWideStringField * ElementNAME_SIMPORTED);

   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void);
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT);

   virtual void OpenTable(__int64 id_ed);
   virtual int OpenElement(__int64 id);;
   virtual bool NewElement(__int64 id_nom,__int64 id_ed);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 dd);
};
#define CLSID_TDMSprImportEdImpl __uuidof(TDMSprImportEdImpl)
#endif
