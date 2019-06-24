#ifndef UHOT_DMSprPrOsnUslugImplH
#define UHOT_DMSprPrOsnUslugImplH
#include "IHOT_DMSprPrOsnUslug.h"
#include "UHOT_DMSprPrOsnUslug.h"
//---------------------------------------------------------------
class __declspec(uuid("{F31E17C1-20F7-4203-AA7A-FE681AAF652C}")) THOT_DMSprPrOsnUslugImpl : public IHOT_DMSprPrOsnUslug
{
public:
   THOT_DMSprPrOsnUslugImpl();
   ~THOT_DMSprPrOsnUslugImpl();
   THOT_DMSprPrOsnUslug * Object;
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

//IHOT_DMSprPrOsnUslug
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBBCDField * get_ElementID_HOT_SPROSNUSL(void);
   virtual void set_ElementID_HOT_SPROSNUSL(TFIBBCDField * ElementID_HOT_SPROSNUSL);

   virtual TFIBBCDField * get_ElementIDCAT_HOT_SPROSNUSL(void);
   virtual void set_ElementIDCAT_HOT_SPROSNUSL(TFIBBCDField * ElementIDCAT_HOT_SPROSNUSL);

   virtual TFIBBCDField * get_ElementIDNOMPR_HOT_SPROSNUSL(void);
   virtual void set_ElementIDNOMPR_HOT_SPROSNUSL(TFIBBCDField * ElementIDNOMPR_HOT_SPROSNUSL);

   virtual TFIBBCDField * get_ElementIDNOMBR_HOT_SPROSNUSL(void);
   virtual void set_ElementIDNOMBR_HOT_SPROSNUSL(TFIBBCDField * ElementIDNOMBR_HOT_SPROSNUSL);

   virtual TFIBBCDField * get_ElementIDTPOS_HOT_SPROSNUSL(void);
   virtual void set_ElementIDTPOS_HOT_SPROSNUSL(TFIBBCDField * ElementIDTPOS_HOT_SPROSNUSL);

   virtual TFIBBCDField * get_TableID_HOT_SPROSNUSL(void);
   virtual void set_TableID_HOT_SPROSNUSL(TFIBBCDField * TableID_HOT_SPROSNUSL);

   virtual TFIBBCDField * get_TableIDCAT_HOT_SPROSNUSL(void);
   virtual void set_TableIDCAT_HOT_SPROSNUSL(TFIBBCDField * TableIDCAT_HOT_SPROSNUSL);

   virtual TFIBBCDField * get_TableIDNOMPR_HOT_SPROSNUSL(void);
   virtual void set_TableIDNOMPR_HOT_SPROSNUSL(TFIBBCDField * TableIDNOMPR_HOT_SPROSNUSL);

   virtual TFIBBCDField * get_TableIDNOMBR_HOT_SPROSNUSL(void);
   virtual void set_TableIDNOMBR_HOT_SPROSNUSL(TFIBBCDField * TableIDNOMBR_HOT_SPROSNUSL);

   virtual TFIBBCDField * get_TableIDTPOS_HOT_SPROSNUSL(void);
   virtual void set_TableIDTPOS_HOT_SPROSNUSL(TFIBBCDField * TableIDTPOS_HOT_SPROSNUSL);

   virtual TFIBBCDField * get_TableIDBASE_HOT_SPROSNUSL(void);
   virtual void set_TableIDBASE_HOT_SPROSNUSL(TFIBBCDField * TableIDBASE_HOT_SPROSNUSL);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBWideStringField * get_TableNAME_HOT_SCATNOM(void);
   virtual void set_TableNAME_HOT_SCATNOM(TFIBWideStringField * TableNAME_HOT_SCATNOM);

   virtual TFIBWideStringField * get_TableNAME_HOT_STYPEPOS(void);
   virtual void set_TableNAME_HOT_STYPEPOS(TFIBWideStringField * TableNAME_HOT_STYPEPOS);

   virtual TFIBWideStringField * get_TableNAMENOMPR(void);
   virtual void set_TableNAMENOMPR(TFIBWideStringField * TableNAMENOMPR);

   virtual TFIBWideStringField * get_TableNAMENOMBR(void);
   virtual void set_TableNAMENOMBR(TFIBWideStringField * TableNAMENOMBR);

   virtual TFIBWideStringField * get_ElementNAME_HOT_SCATNOM(void);
   virtual void set_ElementNAME_HOT_SCATNOM(TFIBWideStringField * ElementNAME_HOT_SCATNOM);

   virtual TFIBWideStringField * get_ElementNAME_HOT_STYPEPOS(void);
   virtual void set_ElementNAME_HOT_STYPEPOS(TFIBWideStringField * ElementNAME_HOT_STYPEPOS);

   virtual TFIBWideStringField * get_ElementNAMENOMPR(void);
   virtual void set_ElementNAMENOMPR(TFIBWideStringField * ElementNAMENOMPR);

   virtual TFIBWideStringField * get_ElementNAMENOMBR(void);
   virtual void set_ElementNAMENOMBR(TFIBWideStringField * ElementNAMENOMBR);

   virtual __int64 get_IdNomBron(void);
   virtual void set_IdNomBron(__int64 IdNomBron);

   virtual __int64 get_IdNomProg(void);
   virtual void set_IdNomProg(__int64 IdNomProg);

   virtual void OpenTable(void);
   virtual void UpdateTable(void);
   virtual int OpenElement(__int64 Id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual int GetIndexElementaPoID(__int64 id);
   virtual void GetNomBronAndProg(__int64 id_cat,__int64 id_type_pos);
};
#define CLSID_THOT_DMSprPrOsnUslugImpl __uuidof(THOT_DMSprPrOsnUslugImpl)
#endif
