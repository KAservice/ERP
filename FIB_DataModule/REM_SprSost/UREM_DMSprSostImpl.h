#ifndef UREM_DMSprSostImplH
#define UREM_DMSprSostImplH
#include "IREM_DMSprSost.h"
#include "UREM_DMSprSost.h"
//---------------------------------------------------------------
class __declspec(uuid("{14F11F3C-417C-461C-B8FE-0D81AF78073C}")) TREM_DMSprSostImpl : public IREM_DMSprSost
{
public:
   TREM_DMSprSostImpl();
   ~TREM_DMSprSostImpl();
   TREM_DMSprSost * Object;
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

//IREM_DMSprSost
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

   virtual TFIBLargeIntField * get_TableID_REMSSOST(void);
   virtual void set_TableID_REMSSOST(TFIBLargeIntField * TableID_REMSSOST);

   virtual TFIBWideStringField * get_TableGID_REMSSOST(void);
   virtual void set_TableGID_REMSSOST(TFIBWideStringField * TableGID_REMSSOST);

   virtual TFIBWideStringField * get_TableNAME_REMSSOST(void);
   virtual void set_TableNAME_REMSSOST(TFIBWideStringField * TableNAME_REMSSOST);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_SSOST(void);
   virtual void set_TableIDBASE_REM_SSOST(TFIBLargeIntField * TableIDBASE_REM_SSOST);

   virtual TFIBLargeIntField * get_ElementID_REMSSOST(void);
   virtual void set_ElementID_REMSSOST(TFIBLargeIntField * ElementID_REMSSOST);

   virtual TFIBWideStringField * get_ElementGID_REMSSOST(void);
   virtual void set_ElementGID_REMSSOST(TFIBWideStringField * ElementGID_REMSSOST);

   virtual TFIBWideStringField * get_ElementNAME_REMSSOST(void);
   virtual void set_ElementNAME_REMSSOST(TFIBWideStringField * ElementNAME_REMSSOST);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_SSOST(void);
   virtual void set_ElementIDBASE_REM_SSOST(TFIBLargeIntField * ElementIDBASE_REM_SSOST);

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
#define CLSID_TREM_DMSprSostImpl __uuidof(TREM_DMSprSostImpl)
#endif
