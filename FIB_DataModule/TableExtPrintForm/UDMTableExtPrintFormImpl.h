#ifndef UDMTableExtPrintFormImplH
#define UDMTableExtPrintFormImplH
#include "IDMTableExtPrintForm.h"
#include "UDMTableExtPrintForm.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMTableExtPrintFormImpl)) TDMTableExtPrintFormImpl : public IDMTableExtPrintForm
{
public:
   TDMTableExtPrintFormImpl();
   ~TDMTableExtPrintFormImpl();
   TDMTableExtPrintForm * Object;
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

//IDMTableExtPrintForm
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

   virtual TFIBLargeIntField * get_TableID_EXTPRINT_FORM(void);
   virtual void set_TableID_EXTPRINT_FORM(TFIBLargeIntField * TableID_EXTPRINT_FORM);

   virtual TFIBWideStringField * get_TableNAME_EXTPRINT_FORM(void);
   virtual void set_TableNAME_EXTPRINT_FORM(TFIBWideStringField * TableNAME_EXTPRINT_FORM);

   virtual TFIBWideStringField * get_TableOBJECT_EXTPRINT_FORM(void);
   virtual void set_TableOBJECT_EXTPRINT_FORM(TFIBWideStringField * TableOBJECT_EXTPRINT_FORM);

   virtual TFIBWideStringField * get_TableFILE_NAME_EXTPRINT_FORM(void);
   virtual void set_TableFILE_NAME_EXTPRINT_FORM(TFIBWideStringField * TableFILE_NAME_EXTPRINT_FORM);

   virtual TFIBIntegerField * get_TableISPCONST_EXTPRINT_FORM(void);
   virtual void set_TableISPCONST_EXTPRINT_FORM(TFIBIntegerField * TableISPCONST_EXTPRINT_FORM);

   virtual TFIBWideStringField * get_TableGID_EXTPRINT_FORM(void);
   virtual void set_TableGID_EXTPRINT_FORM(TFIBWideStringField * TableGID_EXTPRINT_FORM);

   virtual TFIBLargeIntField * get_TableIDBASE_EXTPRINT_FORM(void);
   virtual void set_TableIDBASE_EXTPRINT_FORM(TFIBLargeIntField * TableIDBASE_EXTPRINT_FORM);

   virtual TFIBIntegerField * get_TableTYPEMODULE_EXTPRINT_FORM(void);
   virtual void set_TableTYPEMODULE_EXTPRINT_FORM(TFIBIntegerField * TableTYPEMODULE_EXTPRINT_FORM);

   virtual TFIBIntegerField * get_TableRESIDENCE_EXTPRINT_FORM(void);
   virtual void set_TableRESIDENCE_EXTPRINT_FORM(TFIBIntegerField * TableRESIDENCE_EXTPRINT_FORM);

   virtual TFIBBlobField * get_TableBODY_EXTPRINT_FORM(void);
   virtual void set_TableBODY_EXTPRINT_FORM(TFIBBlobField * TableBODY_EXTPRINT_FORM);

   virtual TFIBWideStringField * get_TableGUID_OB_EXTPRINT_FORM(void);
   virtual void set_TableGUID_OB_EXTPRINT_FORM(TFIBWideStringField * TableGUID_OB_EXTPRINT_FORM);

   virtual TFIBWideStringField * get_TableNAME_PROGRAM_MODULE(void);
   virtual void set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TablePROGID_PROGRAM_MODULE(void);
   virtual void set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_TablePATCH_PROGRAM_MODULE(void);
   virtual void set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE);

   virtual TFIBLargeIntField * get_ElementID_EXTPRINT_FORM(void);
   virtual void set_ElementID_EXTPRINT_FORM(TFIBLargeIntField * ElementID_EXTPRINT_FORM);

   virtual TFIBWideStringField * get_ElementNAME_EXTPRINT_FORM(void);
   virtual void set_ElementNAME_EXTPRINT_FORM(TFIBWideStringField * ElementNAME_EXTPRINT_FORM);

   virtual TFIBWideStringField * get_ElementOBJECT_EXTPRINT_FORM(void);
   virtual void set_ElementOBJECT_EXTPRINT_FORM(TFIBWideStringField * ElementOBJECT_EXTPRINT_FORM);

   virtual TFIBWideStringField * get_ElementFILE_NAME_EXTPRINT_FORM(void);
   virtual void set_ElementFILE_NAME_EXTPRINT_FORM(TFIBWideStringField * ElementFILE_NAME_EXTPRINT_FORM);

   virtual TFIBIntegerField * get_ElementISPCONST_EXTPRINT_FORM(void);
   virtual void set_ElementISPCONST_EXTPRINT_FORM(TFIBIntegerField * ElementISPCONST_EXTPRINT_FORM);

   virtual TFIBWideStringField * get_ElementGID_EXTPRINT_FORM(void);
   virtual void set_ElementGID_EXTPRINT_FORM(TFIBWideStringField * ElementGID_EXTPRINT_FORM);

   virtual TFIBLargeIntField * get_ElementIDBASE_EXTPRINT_FORM(void);
   virtual void set_ElementIDBASE_EXTPRINT_FORM(TFIBLargeIntField * ElementIDBASE_EXTPRINT_FORM);

   virtual TFIBIntegerField * get_ElementTYPEMODULE_EXTPRINT_FORM(void);
   virtual void set_ElementTYPEMODULE_EXTPRINT_FORM(TFIBIntegerField * ElementTYPEMODULE_EXTPRINT_FORM);

   virtual TFIBIntegerField * get_ElementRESIDENCE_EXTPRINT_FORM(void);
   virtual void set_ElementRESIDENCE_EXTPRINT_FORM(TFIBIntegerField * ElementRESIDENCE_EXTPRINT_FORM);

   virtual TFIBBlobField * get_ElementBODY_EXTPRINT_FORM(void);
   virtual void set_ElementBODY_EXTPRINT_FORM(TFIBBlobField * ElementBODY_EXTPRINT_FORM);

   virtual TFIBWideStringField * get_ElementGUID_OB_EXTPRINT_FORM(void);
   virtual void set_ElementGUID_OB_EXTPRINT_FORM(TFIBWideStringField * ElementGUID_OB_EXTPRINT_FORM);

   virtual TFIBWideStringField * get_ElementNAME_PROGRAM_MODULE(void);
   virtual void set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementPROGID_PROGRAM_MODULE(void);
   virtual void set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE);

   virtual TFIBWideStringField * get_ElementPATCH_PROGRAM_MODULE(void);
   virtual void set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE);

   virtual void OpenTable(REFIID guid, bool all);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual void DeleteElement(__int64 Id);
   virtual __int64 GetIDElement(String gid);
   virtual AnsiString GetGIDElement(__int64 id);
};
#define CLSID_TDMTableExtPrintFormImpl __uuidof(TDMTableExtPrintFormImpl)
#endif
