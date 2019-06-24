#ifndef UDMInterfMainMenuParImplH
#define UDMInterfMainMenuParImplH
#include "IDMInterfMainMenuPar.h"
#include "UDMInterfMainMenuPar.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMInterfMainMenuParImpl)) TDMInterfMainMenuParImpl : public IDMInterfMainMenuPar
{
public:
   TDMInterfMainMenuParImpl();
   ~TDMInterfMainMenuParImpl();
   TDMInterfMainMenuPar * Object;
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

//IDMInterfMainMenuPar
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TDataSource * get_DataSourceElement(void);
   virtual void set_DataSourceElement(TDataSource * DataSourceElement);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TFIBLargeIntField * get_TableID_INTERF_MAINMENU_PAR(void);
   virtual void set_TableID_INTERF_MAINMENU_PAR(TFIBLargeIntField * TableID_INTERF_MAINMENU_PAR);

   virtual TFIBLargeIntField * get_TableIDBASE_INTERF_MAINMENU_PAR(void);
   virtual void set_TableIDBASE_INTERF_MAINMENU_PAR(TFIBLargeIntField * TableIDBASE_INTERF_MAINMENU_PAR);

   virtual TFIBWideStringField * get_TableGID_INTERF_MAINMENU_PAR(void);
   virtual void set_TableGID_INTERF_MAINMENU_PAR(TFIBWideStringField * TableGID_INTERF_MAINMENU_PAR);

   virtual TFIBLargeIntField * get_TableIDMAINMENU_INTERF_MAINMENU_PAR(void);
   virtual void set_TableIDMAINMENU_INTERF_MAINMENU_PAR(TFIBLargeIntField * TableIDMAINMENU_INTERF_MAINMENU_PAR);

   virtual TFIBWideStringField * get_TableNAME_INTERF_MAINMENU_PAR(void);
   virtual void set_TableNAME_INTERF_MAINMENU_PAR(TFIBWideStringField * TableNAME_INTERF_MAINMENU_PAR);

   virtual TFIBWideStringField * get_TableVALUE_INTERF_MAINMENU_PAR(void);
   virtual void set_TableVALUE_INTERF_MAINMENU_PAR(TFIBWideStringField * TableVALUE_INTERF_MAINMENU_PAR);

   virtual TFIBDateTimeField * get_TableVALUE_TIMESTAMP_MAINMENU_PAR(void);
   virtual void set_TableVALUE_TIMESTAMP_MAINMENU_PAR(TFIBDateTimeField * TableVALUE_TIMESTAMP_MAINMENU_PAR);

   virtual TFIBSmallIntField * get_TableTYPE_VALUE_MAINMENU_PAR(void);
   virtual void set_TableTYPE_VALUE_MAINMENU_PAR(TFIBSmallIntField * TableTYPE_VALUE_MAINMENU_PAR);

   virtual TFIBIntegerField * get_TableTYPE_PAR_INTERF_MAINMENU_PAR(void);
   virtual void set_TableTYPE_PAR_INTERF_MAINMENU_PAR(TFIBIntegerField * TableTYPE_PAR_INTERF_MAINMENU_PAR);

   virtual TFIBLargeIntField * get_ElementID_INTERF_MAINMENU_PAR(void);
   virtual void set_ElementID_INTERF_MAINMENU_PAR(TFIBLargeIntField * ElementID_INTERF_MAINMENU_PAR);

   virtual TFIBLargeIntField * get_ElementIDBASE_INTERF_MAINMENU_PAR(void);
   virtual void set_ElementIDBASE_INTERF_MAINMENU_PAR(TFIBLargeIntField * ElementIDBASE_INTERF_MAINMENU_PAR);

   virtual TFIBWideStringField * get_ElementGID_INTERF_MAINMENU_PAR(void);
   virtual void set_ElementGID_INTERF_MAINMENU_PAR(TFIBWideStringField * ElementGID_INTERF_MAINMENU_PAR);

   virtual TFIBLargeIntField * get_ElementIDMAINMENU_INTERF_MAINMENU_PAR(void);
   virtual void set_ElementIDMAINMENU_INTERF_MAINMENU_PAR(TFIBLargeIntField * ElementIDMAINMENU_INTERF_MAINMENU_PAR);

   virtual TFIBWideStringField * get_ElementNAME_INTERF_MAINMENU_PAR(void);
   virtual void set_ElementNAME_INTERF_MAINMENU_PAR(TFIBWideStringField * ElementNAME_INTERF_MAINMENU_PAR);

   virtual TFIBWideStringField * get_ElementVALUE_INTERF_MAINMENU_PAR(void);
   virtual void set_ElementVALUE_INTERF_MAINMENU_PAR(TFIBWideStringField * ElementVALUE_INTERF_MAINMENU_PAR);

   virtual TFIBDateTimeField * get_ElementVALUE_TIMESTAMP_MAINMENU_PAR(void);
   virtual void set_ElementVALUE_TIMESTAMP_MAINMENU_PAR(TFIBDateTimeField * ElementVALUE_TIMESTAMP_MAINMENU_PAR);

   virtual TFIBSmallIntField * get_ElementTYPE_VALUE_MAINMENU_PAR(void);
   virtual void set_ElementTYPE_VALUE_MAINMENU_PAR(TFIBSmallIntField * ElementTYPE_VALUE_MAINMENU_PAR);

   virtual TFIBIntegerField * get_ElementTYPE_PAR_INTERF_MAINMENU_PAR(void);
   virtual void set_ElementTYPE_PAR_INTERF_MAINMENU_PAR(TFIBIntegerField * ElementTYPE_PAR_INTERF_MAINMENU_PAR);

   virtual __int64 get_IdOwner(void);
   virtual void set_IdOwner(__int64 IdOwner);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_owner);
   virtual bool SaveIsmen(void);
   virtual bool CancelIsmen(void);
   virtual bool TableAppend(__int64 id_owner);
   virtual bool TableDelete(void);
   virtual bool NewElement(__int64 id_owner);
   virtual int OpenElement(__int64 id );
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TDMInterfMainMenuParImpl __uuidof(TDMInterfMainMenuParImpl)
#endif
