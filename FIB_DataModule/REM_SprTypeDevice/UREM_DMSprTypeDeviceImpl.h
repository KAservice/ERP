#ifndef UREM_DMSprTypeDeviceImplH
#define UREM_DMSprTypeDeviceImplH
#include "IREM_DMSprTypeDevice.h"
#include "UREM_DMSprTypeDevice.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TREM_DMSprTypeDeviceImpl)) TREM_DMSprTypeDeviceImpl : public IREM_DMSprTypeDevice
{
public:
   TREM_DMSprTypeDeviceImpl();
   ~TREM_DMSprTypeDeviceImpl();
   TREM_DMSprTypeDevice * Object;
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

//IREM_DMSprTypeDevice
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

   virtual TFIBLargeIntField * get_TableID_REM_STYPEDEVICE(void);
   virtual void set_TableID_REM_STYPEDEVICE(TFIBLargeIntField * TableID_REM_STYPEDEVICE);

   virtual TFIBWideStringField * get_TableGID_REM_STYPEDEVICE(void);
   virtual void set_TableGID_REM_STYPEDEVICE(TFIBWideStringField * TableGID_REM_STYPEDEVICE);

   virtual TFIBLargeIntField * get_TableIDBASE_REM_STYPEDEVICE(void);
   virtual void set_TableIDBASE_REM_STYPEDEVICE(TFIBLargeIntField * TableIDBASE_REM_STYPEDEVICE);

   virtual TFIBWideStringField * get_TableNAME_REM_STYPEDEVICE(void);
   virtual void set_TableNAME_REM_STYPEDEVICE(TFIBWideStringField * TableNAME_REM_STYPEDEVICE);

   virtual TFIBLargeIntField * get_ElementID_REM_STYPEDEVICE(void);
   virtual void set_ElementID_REM_STYPEDEVICE(TFIBLargeIntField * ElementID_REM_STYPEDEVICE);

   virtual TFIBWideStringField * get_ElementGID_REM_STYPEDEVICE(void);
   virtual void set_ElementGID_REM_STYPEDEVICE(TFIBWideStringField * ElementGID_REM_STYPEDEVICE);

   virtual TFIBLargeIntField * get_ElementIDBASE_REM_STYPEDEVICE(void);
   virtual void set_ElementIDBASE_REM_STYPEDEVICE(TFIBLargeIntField * ElementIDBASE_REM_STYPEDEVICE);

   virtual TFIBWideStringField * get_ElementNAME_REM_STYPEDEVICE(void);
   virtual void set_ElementNAME_REM_STYPEDEVICE(TFIBWideStringField * ElementNAME_REM_STYPEDEVICE);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TREM_DMSprTypeDeviceImpl __uuidof(TREM_DMSprTypeDeviceImpl)
#endif
