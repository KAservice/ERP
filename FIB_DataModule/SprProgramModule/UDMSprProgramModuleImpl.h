#ifndef UDMSprProgramModuleImplH
#define UDMSprProgramModuleImplH
#include "IDMSprProgramModule.h"
#include "UDMSprProgramModule.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprProgramModuleImpl)) TDMSprProgramModuleImpl : public IDMSprProgramModule
{
public:
   TDMSprProgramModuleImpl();
   ~TDMSprProgramModuleImpl();
   TDMSprProgramModule * Object;
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

//IDMSprProgramModule
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

   virtual TFIBLargeIntField * get_TableID_PROGRAM_MODULE(void);
   virtual void set_TableID_PROGRAM_MODULE(TFIBLargeIntField * TableID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TableNAME_PROGRAM_MODULE(void);
   virtual void set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TablePROGID_PROGRAM_MODULE(void);
   virtual void set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TableMODULE_PROGRAM_MODULE(void);
   virtual void set_TableMODULE_PROGRAM_MODULE(TFIBWideStringField * TableMODULE_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TableDESCR_PROGRAM_MODULE(void);
   virtual void set_TableDESCR_PROGRAM_MODULE(TFIBWideStringField * TableDESCR_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TablePATCH_PROGRAM_MODULE(void);
   virtual void set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE);

   virtual TFIBLargeIntField * get_TableIDBASE_PROGRAM_MODULE(void);
   virtual void set_TableIDBASE_PROGRAM_MODULE(TFIBLargeIntField * TableIDBASE_PROGRAM_MODULE);

   virtual TFIBLargeIntField * get_ElementID_PROGRAM_MODULE(void);
   virtual void set_ElementID_PROGRAM_MODULE(TFIBLargeIntField * ElementID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementNAME_PROGRAM_MODULE(void);
   virtual void set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementPROGID_PROGRAM_MODULE(void);
   virtual void set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementMODULE_PROGRAM_MODULE(void);
   virtual void set_ElementMODULE_PROGRAM_MODULE(TFIBWideStringField * ElementMODULE_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementDESCR_PROGRAM_MODULE(void);
   virtual void set_ElementDESCR_PROGRAM_MODULE(TFIBWideStringField * ElementDESCR_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementPATCH_PROGRAM_MODULE(void);
   virtual void set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE);

   virtual TFIBLargeIntField * get_ElementIDBASE_PROGRAM_MODULE(void);
   virtual void set_ElementIDBASE_PROGRAM_MODULE(TFIBLargeIntField * ElementIDBASE_PROGRAM_MODULE);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBWideStringField * get_TableGUID_PROGRAM_MODULE(void);
   virtual void set_TableGUID_PROGRAM_MODULE(TFIBWideStringField * TableGUID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementGUID_PROGRAM_MODULE(void);
   virtual void set_ElementGUID_PROGRAM_MODULE(TFIBWideStringField * ElementGUID_PROGRAM_MODULE);

   virtual TFIBIntegerField * get_TableTYPEMOD_PROGRAM_MODULE(void);
   virtual void set_TableTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * TableTYPEMOD_PROGRAM_MODULE);

   virtual TFIBIntegerField * get_ElementTYPEMOD_PROGRAM_MODULE(void);
   virtual void set_ElementTYPEMOD_PROGRAM_MODULE(TFIBIntegerField * ElementTYPEMOD_PROGRAM_MODULE);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
   virtual __int64 GetIDElement(UnicodeString gid);
   virtual GUID GetCLSIDFromProgID(UnicodeString prog_id);
   virtual UnicodeString GetProgIDFromCLSID (GUID guid);
   virtual UnicodeString GetNameModuleFromCLSID(GUID guid);
   virtual UnicodeString GetFullPatchFromCLSID(GUID guid);
   virtual __int64 GetIdModuleFromGUID(GUID guid);
   virtual __int64 GetIdModuleFromProgId(UnicodeString prog_id);
};
#define CLSID_TDMSprProgramModuleImpl __uuidof(TDMSprProgramModuleImpl)
#endif
