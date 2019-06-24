#ifndef UHOT_DMSprTypePoselImplH
#define UHOT_DMSprTypePoselImplH
#include "IHOT_DMSprTypePosel.h"
#include "UHOT_DMSprTypePosel.h"
//---------------------------------------------------------------
class __declspec(uuid("{0246C675-0FE3-47E8-A52C-B10EC62599DB}")) THOT_DMSprTypePoselImpl : public IHOT_DMSprTypePosel
{
public:
   THOT_DMSprTypePoselImpl();
   ~THOT_DMSprTypePoselImpl();
   THOT_DMSprTypePosel * Object;
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

//IHOT_DMSprTypePosel
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

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBSmallIntField * get_TableKOLM_HOT_STYPEPOS(void);
   virtual void set_TableKOLM_HOT_STYPEPOS(TFIBSmallIntField * TableKOLM_HOT_STYPEPOS);

   virtual TFIBSmallIntField * get_TableALL_HOT_STYPEPOS(void);
   virtual void set_TableALL_HOT_STYPEPOS(TFIBSmallIntField * TableALL_HOT_STYPEPOS);

   virtual TFIBSmallIntField * get_ElementKOLM_HOT_STYPEPOS(void);
   virtual void set_ElementKOLM_HOT_STYPEPOS(TFIBSmallIntField * ElementKOLM_HOT_STYPEPOS);

   virtual TFIBSmallIntField * get_ElementALL_HOT_STYPEPOS(void);
   virtual void set_ElementALL_HOT_STYPEPOS(TFIBSmallIntField * ElementALL_HOT_STYPEPOS);

   virtual TFIBBCDField * get_TableID_HOT_STYPEPOS(void);
   virtual void set_TableID_HOT_STYPEPOS(TFIBBCDField * TableID_HOT_STYPEPOS);

   virtual TFIBBCDField * get_ElementID_HOT_STYPEPOS(void);
   virtual void set_ElementID_HOT_STYPEPOS(TFIBBCDField * ElementID_HOT_STYPEPOS);

   virtual TFIBWideStringField * get_TableNAME_HOT_STYPEPOS(void);
   virtual void set_TableNAME_HOT_STYPEPOS(TFIBWideStringField * TableNAME_HOT_STYPEPOS);

   virtual TFIBWideStringField * get_ElementNAME_HOT_STYPEPOS(void);
   virtual void set_ElementNAME_HOT_STYPEPOS(TFIBWideStringField * ElementNAME_HOT_STYPEPOS);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_THOT_DMSprTypePoselImpl __uuidof(THOT_DMSprTypePoselImpl)
#endif
