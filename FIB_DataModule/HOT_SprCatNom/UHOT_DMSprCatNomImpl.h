#ifndef UHOT_DMSprCatNomImplH
#define UHOT_DMSprCatNomImplH
#include "IHOT_DMSprCatNom.h"
#include "UHOT_DMSprCatNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{586BE6A4-69FD-45EF-A7AA-76BA020BBFAC}")) THOT_DMSprCatNomImpl : public IHOT_DMSprCatNom
{
public:
   THOT_DMSprCatNomImpl();
   ~THOT_DMSprCatNomImpl();
   THOT_DMSprCatNom * Object;
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

//IHOT_DMSprCatNom
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

   virtual TFIBBCDField * get_ElementID_HOT_SCATNOM(void);
   virtual void set_ElementID_HOT_SCATNOM(TFIBBCDField * ElementID_HOT_SCATNOM);

   virtual TFIBBCDField * get_TableID_HOT_SCATNOM(void);
   virtual void set_TableID_HOT_SCATNOM(TFIBBCDField * TableID_HOT_SCATNOM);

   virtual TFIBWideStringField * get_ElementNAME_HOT_SCATNOM(void);
   virtual void set_ElementNAME_HOT_SCATNOM(TFIBWideStringField * ElementNAME_HOT_SCATNOM);

   virtual TFIBWideStringField * get_ElementDESCR_HOT_SCATNOM(void);
   virtual void set_ElementDESCR_HOT_SCATNOM(TFIBWideStringField * ElementDESCR_HOT_SCATNOM);

   virtual TFIBWideStringField * get_TableNAME_HOT_SCATNOM(void);
   virtual void set_TableNAME_HOT_SCATNOM(TFIBWideStringField * TableNAME_HOT_SCATNOM);

   virtual TFIBWideStringField * get_TableDESCR_HOT_SCATNOM(void);
   virtual void set_TableDESCR_HOT_SCATNOM(TFIBWideStringField * TableDESCR_HOT_SCATNOM);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual __int64 GetIDElement(String gid);
   virtual AnsiString GetGIDElement(__int64 id);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_THOT_DMSprCatNomImpl __uuidof(THOT_DMSprCatNomImpl)
#endif
