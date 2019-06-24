#ifndef UDMSprNomImageImplH
#define UDMSprNomImageImplH
#include "IDMSprNomImage.h"
#include "UDMSprNomImage.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprNomImageImpl)) TDMSprNomImageImpl : public IDMSprNomImage
{
public:
   TDMSprNomImageImpl();
   ~TDMSprNomImageImpl();
   TDMSprNomImage * Object;
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

//IDMSprNomImage
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

   virtual TFIBLargeIntField * get_TableID_SNOMIMAGE(void);
   virtual void set_TableID_SNOMIMAGE(TFIBLargeIntField * TableID_SNOMIMAGE);

   virtual TFIBLargeIntField * get_TableIDBASE_SNOMIMAGE(void);
   virtual void set_TableIDBASE_SNOMIMAGE(TFIBLargeIntField * TableIDBASE_SNOMIMAGE);

   virtual TFIBWideStringField * get_TableGID_SNOMIMAGE(void);
   virtual void set_TableGID_SNOMIMAGE(TFIBWideStringField * TableGID_SNOMIMAGE);

   virtual TFIBLargeIntField * get_TableIDVIDIMAGE_SNOMIMAGE(void);
   virtual void set_TableIDVIDIMAGE_SNOMIMAGE(TFIBLargeIntField * TableIDVIDIMAGE_SNOMIMAGE);

   virtual TFIBLargeIntField * get_TableIDNOM_SNOMIMAGE(void);
   virtual void set_TableIDNOM_SNOMIMAGE(TFIBLargeIntField * TableIDNOM_SNOMIMAGE);

   virtual TFIBWideStringField * get_TableNAME_SNOMIMAGE(void);
   virtual void set_TableNAME_SNOMIMAGE(TFIBWideStringField * TableNAME_SNOMIMAGE);

   virtual TFIBBlobField * get_TableBODY_SNOMIMAGE(void);
   virtual void set_TableBODY_SNOMIMAGE(TFIBBlobField * TableBODY_SNOMIMAGE);

   virtual TFIBBlobField * get_TableBODY_SMALL_SNOMIMAGE(void);
   virtual void set_TableBODY_SMALL_SNOMIMAGE(TFIBBlobField * TableBODY_SMALL_SNOMIMAGE);

   virtual TFIBLargeIntField * get_ElementID_SNOMIMAGE(void);
   virtual void set_ElementID_SNOMIMAGE(TFIBLargeIntField * ElementID_SNOMIMAGE);

   virtual TFIBLargeIntField * get_ElementIDBASE_SNOMIMAGE(void);
   virtual void set_ElementIDBASE_SNOMIMAGE(TFIBLargeIntField * ElementIDBASE_SNOMIMAGE);

   virtual TFIBWideStringField * get_ElementGID_SNOMIMAGE(void);
   virtual void set_ElementGID_SNOMIMAGE(TFIBWideStringField * ElementGID_SNOMIMAGE);

   virtual TFIBLargeIntField * get_ElementIDVIDIMAGE_SNOMIMAGE(void);
   virtual void set_ElementIDVIDIMAGE_SNOMIMAGE(TFIBLargeIntField * ElementIDVIDIMAGE_SNOMIMAGE);

   virtual TFIBLargeIntField * get_ElementIDNOM_SNOMIMAGE(void);
   virtual void set_ElementIDNOM_SNOMIMAGE(TFIBLargeIntField * ElementIDNOM_SNOMIMAGE);

   virtual TFIBWideStringField * get_ElementNAME_SNOMIMAGE(void);
   virtual void set_ElementNAME_SNOMIMAGE(TFIBWideStringField * ElementNAME_SNOMIMAGE);

   virtual TFIBBlobField * get_ElementBODY_SNOMIMAGE(void);
   virtual void set_ElementBODY_SNOMIMAGE(TFIBBlobField * ElementBODY_SNOMIMAGE);

   virtual TFIBBlobField * get_ElementBODY_SMALL_SNOMIMAGE(void);
   virtual void set_ElementBODY_SMALL_SNOMIMAGE(TFIBBlobField * ElementBODY_SMALL_SNOMIMAGE);

   virtual TFIBWideStringField * get_TableNAME_SVIDIMAGE(void);
   virtual void set_TableNAME_SVIDIMAGE(TFIBWideStringField * TableNAME_SVIDIMAGE);

   virtual TFIBWideStringField * get_ElementNAME_SVIDIMAGE(void);
   virtual void set_ElementNAME_SVIDIMAGE(TFIBWideStringField * ElementNAME_SVIDIMAGE);

   virtual TFIBIntegerField * get_TableINDEX_SNOMIMAGE(void);
   virtual void set_TableINDEX_SNOMIMAGE(TFIBIntegerField * TableINDEX_SNOMIMAGE);

   virtual TFIBIntegerField * get_ElementINDEX_SNOMIMAGE(void);
   virtual void set_ElementINDEX_SNOMIMAGE(TFIBIntegerField * ElementINDEX_SNOMIMAGE);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_nom);
   virtual int OpenElement(__int64 id );
   virtual bool NewElement(__int64 id_nom);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TDMSprNomImageImpl __uuidof(TDMSprNomImageImpl)
#endif
