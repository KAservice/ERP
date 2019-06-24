#ifndef UDMSprVidImageImplH
#define UDMSprVidImageImplH
#include "IDMSprVidImage.h"
#include "UDMSprVidImage.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprVidImageImpl)) TDMSprVidImageImpl : public IDMSprVidImage
{
public:
   TDMSprVidImageImpl();
   ~TDMSprVidImageImpl();
   TDMSprVidImage * Object;
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

//IDMSprVidImage
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

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBLargeIntField * get_TableID_SVIDIMAGE(void);
   virtual void set_TableID_SVIDIMAGE(TFIBLargeIntField * TableID_SVIDIMAGE);

   virtual TFIBLargeIntField * get_TableIDBASE_SVIDIMAGE(void);
   virtual void set_TableIDBASE_SVIDIMAGE(TFIBLargeIntField * TableIDBASE_SVIDIMAGE);

   virtual TFIBWideStringField * get_TableGID_SVIDIMAGE(void);
   virtual void set_TableGID_SVIDIMAGE(TFIBWideStringField * TableGID_SVIDIMAGE);

   virtual TFIBLargeIntField * get_TableIDGRP_SVIDIMAGE(void);
   virtual void set_TableIDGRP_SVIDIMAGE(TFIBLargeIntField * TableIDGRP_SVIDIMAGE);

   virtual TFIBWideStringField * get_TableNAME_SVIDIMAGE(void);
   virtual void set_TableNAME_SVIDIMAGE(TFIBWideStringField * TableNAME_SVIDIMAGE);

   virtual TFIBLargeIntField * get_ElementID_SVIDIMAGE(void);
   virtual void set_ElementID_SVIDIMAGE(TFIBLargeIntField * ElementID_SVIDIMAGE);

   virtual TFIBLargeIntField * get_ElementIDBASE_SVIDIMAGE(void);
   virtual void set_ElementIDBASE_SVIDIMAGE(TFIBLargeIntField * ElementIDBASE_SVIDIMAGE);

   virtual TFIBWideStringField * get_ElementGID_SVIDIMAGE(void);
   virtual void set_ElementGID_SVIDIMAGE(TFIBWideStringField * ElementGID_SVIDIMAGE);

   virtual TFIBLargeIntField * get_ElementIDGRP_SVIDIMAGE(void);
   virtual void set_ElementIDGRP_SVIDIMAGE(TFIBLargeIntField * ElementIDGRP_SVIDIMAGE);

   virtual TFIBWideStringField * get_ElementNAME_SVIDIMAGE(void);
   virtual void set_ElementNAME_SVIDIMAGE(TFIBWideStringField * ElementNAME_SVIDIMAGE);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_grp, bool all);
   virtual UnicodeString GetTextQuery(__int64 id_grp, bool all);
   virtual int OpenElement(__int64 id );
   virtual bool NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void ChancheGrp(__int64 id_new_grp,__int64 id_prop);
   virtual __int64 FindPoName(UnicodeString name);
   virtual __int64 GetIdGrp(__int64 id_el);
};
#define CLSID_TDMSprVidImageImpl __uuidof(TDMSprVidImageImpl)
#endif
