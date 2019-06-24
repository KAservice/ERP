#ifndef UDMSprOborudImplH
#define UDMSprOborudImplH
#include "IDMSprOborud.h"
#include "UDMSprOborud.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprOborudImpl)) TDMSprOborudImpl : public IDMSprOborud
{
public:
   TDMSprOborudImpl();
   ~TDMSprOborudImpl();
   TDMSprOborud * Object;
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

//IDMSprOborud
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

   virtual TFIBSmallIntField * get_TableON_START_SOBORUD(void);
   virtual void set_TableON_START_SOBORUD(TFIBSmallIntField * TableON_START_SOBORUD);

   virtual TFIBSmallIntField * get_ElementON_START_SOBORUD(void);
   virtual void set_ElementON_START_SOBORUD(TFIBSmallIntField * ElementON_START_SOBORUD);

   virtual TFIBWideStringField * get_TableNAME_OBORUD(void);
   virtual void set_TableNAME_OBORUD(TFIBWideStringField * TableNAME_OBORUD);

   virtual TFIBWideStringField * get_TableCOMPNAME_OBORUD(void);
   virtual void set_TableCOMPNAME_OBORUD(TFIBWideStringField * TableCOMPNAME_OBORUD);

   virtual TFIBWideStringField * get_TableCOMNAME_OBORUD(void);
   virtual void set_TableCOMNAME_OBORUD(TFIBWideStringField * TableCOMNAME_OBORUD);

   virtual TFIBWideStringField * get_TableBAUDRATE_OBORUD(void);
   virtual void set_TableBAUDRATE_OBORUD(TFIBWideStringField * TableBAUDRATE_OBORUD);

   virtual TFIBWideStringField * get_TableMODEL_OBORUD(void);
   virtual void set_TableMODEL_OBORUD(TFIBWideStringField * TableMODEL_OBORUD);

   virtual TFIBWideStringField * get_TableGID_SOBORUD(void);
   virtual void set_TableGID_SOBORUD(TFIBWideStringField * TableGID_SOBORUD);

   virtual TFIBWideStringField * get_TableSTRPAR_SOBORUD(void);
   virtual void set_TableSTRPAR_SOBORUD(TFIBWideStringField * TableSTRPAR_SOBORUD);

   virtual TFIBWideStringField * get_TableMODUL_SOBORUD(void);
   virtual void set_TableMODUL_SOBORUD(TFIBWideStringField * TableMODUL_SOBORUD);

   virtual TFIBWideStringField * get_ElementNAME_OBORUD(void);
   virtual void set_ElementNAME_OBORUD(TFIBWideStringField * ElementNAME_OBORUD);

   virtual TFIBWideStringField * get_ElementCOMPNAME_OBORUD(void);
   virtual void set_ElementCOMPNAME_OBORUD(TFIBWideStringField * ElementCOMPNAME_OBORUD);

   virtual TFIBWideStringField * get_ElementCOMNAME_OBORUD(void);
   virtual void set_ElementCOMNAME_OBORUD(TFIBWideStringField * ElementCOMNAME_OBORUD);

   virtual TFIBWideStringField * get_ElementTYPE_OBORUD(void);
   virtual void set_ElementTYPE_OBORUD(TFIBWideStringField * ElementTYPE_OBORUD);

   virtual TFIBWideStringField * get_ElementMODEL_OBORUD(void);
   virtual void set_ElementMODEL_OBORUD(TFIBWideStringField * ElementMODEL_OBORUD);

   virtual TFIBWideStringField * get_ElementGID_SOBORUD(void);
   virtual void set_ElementGID_SOBORUD(TFIBWideStringField * ElementGID_SOBORUD);

   virtual TFIBWideStringField * get_ElementSTRPAR_SOBORUD(void);
   virtual void set_ElementSTRPAR_SOBORUD(TFIBWideStringField * ElementSTRPAR_SOBORUD);

   virtual TFIBWideStringField * get_ElementMODUL_SOBORUD(void);
   virtual void set_ElementMODUL_SOBORUD(TFIBWideStringField * ElementMODUL_SOBORUD);

   virtual TFIBWideStringField * get_TableTYPE_OBORUD(void);
   virtual void set_TableTYPE_OBORUD(TFIBWideStringField * TableTYPE_OBORUD);

   virtual TFIBWideStringField * get_ElementBAUDRATE_OBORUD(void);
   virtual void set_ElementBAUDRATE_OBORUD(TFIBWideStringField * ElementBAUDRATE_OBORUD);

   virtual TFIBLargeIntField * get_TableID_OBORUD(void);
   virtual void set_TableID_OBORUD(TFIBLargeIntField * TableID_OBORUD);

   virtual TFIBLargeIntField * get_TableIDARM_SOBORUD(void);
   virtual void set_TableIDARM_SOBORUD(TFIBLargeIntField * TableIDARM_SOBORUD);

   virtual TFIBLargeIntField * get_TableIDBASE_SOBORUD(void);
   virtual void set_TableIDBASE_SOBORUD(TFIBLargeIntField * TableIDBASE_SOBORUD);

   virtual TFIBLargeIntField * get_ElementID_OBORUD(void);
   virtual void set_ElementID_OBORUD(TFIBLargeIntField * ElementID_OBORUD);

   virtual TFIBLargeIntField * get_ElementIDARM_SOBORUD(void);
   virtual void set_ElementIDARM_SOBORUD(TFIBLargeIntField * ElementIDARM_SOBORUD);

   virtual TFIBLargeIntField * get_ElementIDBASE_SOBORUD(void);
   virtual void set_ElementIDBASE_SOBORUD(TFIBLargeIntField * ElementIDBASE_SOBORUD);

   virtual TFIBWideStringField * get_TablePROGID_SOBORUD(void);
   virtual void set_TablePROGID_SOBORUD(TFIBWideStringField * TablePROGID_SOBORUD);

   virtual TFIBWideStringField * get_ElementPROGID_SOBORUD(void);
   virtual void set_ElementPROGID_SOBORUD(TFIBWideStringField * ElementPROGID_SOBORUD);

   virtual __int64 get_IdKKM(void);
   virtual void set_IdKKM(__int64 IdKKM);

   virtual void OpenTable(__int64 id_kkm);
   virtual void OpenTablePoTypeOborud(__int64 id_kkm, UnicodeString type_oborud);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(__int64 id_kkm);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
   virtual UnicodeString GetParameter(UnicodeString parameter);
   virtual UnicodeString GetParameterPoTable(UnicodeString parameter);
};
#define CLSID_TDMSprOborudImpl __uuidof(TDMSprOborudImpl)
#endif
