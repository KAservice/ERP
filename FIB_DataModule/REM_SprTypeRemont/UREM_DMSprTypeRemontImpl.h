#ifndef UREM_DMSprTypeRemontImplH
#define UREM_DMSprTypeRemontImplH
#include "IREM_DMSprTypeRemont.h"
#include "UREM_DMSprTypeRemont.h"
//---------------------------------------------------------------
class __declspec(uuid("{2F053F7D-464F-4655-9000-06B1E0D2C8FC}")) TREM_DMSprTypeRemontImpl : public IREM_DMSprTypeRemont
{
public:
   TREM_DMSprTypeRemontImpl();
   ~TREM_DMSprTypeRemontImpl();
   TREM_DMSprTypeRemont * Object;
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

//IREM_DMSprTypeRemont
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

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBLargeIntField * get_ElementID_STREMONT(void);
   virtual void set_ElementID_STREMONT(TFIBLargeIntField * ElementID_STREMONT);

   virtual TFIBWideStringField * get_ElementGID_STREMONT(void);
   virtual void set_ElementGID_STREMONT(TFIBWideStringField * ElementGID_STREMONT);

   virtual TFIBWideStringField * get_ElementNAME_STREMONT(void);
   virtual void set_ElementNAME_STREMONT(TFIBWideStringField * ElementNAME_STREMONT);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_STREMONT(void);
   virtual void set_ElementIDBASE_REM_STREMONT(TFIBLargeIntField * ElementIDBASE_REM_STREMONT);

   virtual TFIBLargeIntField * get_TableID_STREMONT(void);
   virtual void set_TableID_STREMONT(TFIBLargeIntField * TableID_STREMONT);

   virtual TFIBWideStringField * get_TableGID_STREMONT(void);
   virtual void set_TableGID_STREMONT(TFIBWideStringField * TableGID_STREMONT);

   virtual TFIBWideStringField * get_TableNAME_STREMONT(void);
   virtual void set_TableNAME_STREMONT(TFIBWideStringField * TableNAME_STREMONT);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_STREMONT(void);
   virtual void set_TableIDBASE_REM_STREMONT(TFIBLargeIntField * TableIDBASE_REM_STREMONT);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 GetIDElement(UnicodeString gid);
   virtual UnicodeString GetGIDElement(__int64 id);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_TREM_DMSprTypeRemontImpl __uuidof(TREM_DMSprTypeRemontImpl)
#endif
