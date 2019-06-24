#ifndef UREM_DMZayavkaImageImplH
#define UREM_DMZayavkaImageImplH
#include "IREM_DMZayavkaImage.h"
#include "UREM_DMZayavkaImage.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMZayavkaImageImpl)) TREM_DMZayavkaImageImpl : public IREM_DMZayavkaImage
{
public:
   TREM_DMZayavkaImageImpl();
   ~TREM_DMZayavkaImageImpl();
   TREM_DMZayavkaImage * Object;
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

//IREM_DMZayavkaImage
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

   virtual TFIBLargeIntField * get_TableID_REM_ZIMAGE(void);
   virtual void set_TableID_REM_ZIMAGE(TFIBLargeIntField * TableID_REM_ZIMAGE);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_ZIMAGE(void);
   virtual void set_TableIDBASE_REM_ZIMAGE(TFIBLargeIntField * TableIDBASE_REM_ZIMAGE);

   virtual TFIBLargeIntField * get_TableIDZ_REM_ZIMAGE(void);
   virtual void set_TableIDZ_REM_ZIMAGE(TFIBLargeIntField * TableIDZ_REM_ZIMAGE);

   virtual TFIBWideStringField * get_TableNAME_REM_ZIMAGE(void);
   virtual void set_TableNAME_REM_ZIMAGE(TFIBWideStringField * TableNAME_REM_ZIMAGE);

   virtual TFIBSmallIntField * get_TableSHOWUSER_REM_ZIMAGE(void);
   virtual void set_TableSHOWUSER_REM_ZIMAGE(TFIBSmallIntField * TableSHOWUSER_REM_ZIMAGE);

   virtual TFIBBlobField * get_TableIMAGE_REM_ZIMAGE(void);
   virtual void set_TableIMAGE_REM_ZIMAGE(TFIBBlobField * TableIMAGE_REM_ZIMAGE);

   virtual TFIBLargeIntField * get_ElementID_REM_ZIMAGE(void);
   virtual void set_ElementID_REM_ZIMAGE(TFIBLargeIntField * ElementID_REM_ZIMAGE);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_ZIMAGE(void);
   virtual void set_ElementIDBASE_REM_ZIMAGE(TFIBLargeIntField * ElementIDBASE_REM_ZIMAGE);

   virtual TFIBLargeIntField * get_ElementIDZ_REM_ZIMAGE(void);
   virtual void set_ElementIDZ_REM_ZIMAGE(TFIBLargeIntField * ElementIDZ_REM_ZIMAGE);

   virtual TFIBWideStringField * get_ElementNAME_REM_ZIMAGE(void);
   virtual void set_ElementNAME_REM_ZIMAGE(TFIBWideStringField * ElementNAME_REM_ZIMAGE);

   virtual TFIBSmallIntField * get_ElementSHOWUSER_REM_ZIMAGE(void);
   virtual void set_ElementSHOWUSER_REM_ZIMAGE(TFIBSmallIntField * ElementSHOWUSER_REM_ZIMAGE);

   virtual TFIBBlobField * get_ElementIMAGE_REM_ZIMAGE(void);
   virtual void set_ElementIMAGE_REM_ZIMAGE(TFIBBlobField * ElementIMAGE_REM_ZIMAGE);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_z);
   virtual int OpenElement(__int64 id );
   virtual bool NewElement(__int64 id_z);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TREM_DMZayavkaImageImpl __uuidof(TREM_DMZayavkaImageImpl)
#endif
