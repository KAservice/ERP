#ifndef UDMViborOborudImplH
#define UDMViborOborudImplH
#include "IDMViborOborud.h"
#include "UDMViborOborud.h"
//---------------------------------------------------------------
class __declspec(uuid("{194B4928-C39B-4CA5-9B33-127816EEEC4F}")) TDMViborOborudImpl : public IDMViborOborud
{
public:
   TDMViborOborudImpl();
   ~TDMViborOborudImpl();
   TDMViborOborud * Object;
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

//IDMViborOborud
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TFIBBCDField * get_TableID_OBORUD(void);
   virtual void set_TableID_OBORUD(TFIBBCDField * TableID_OBORUD);

   virtual TFIBBCDField * get_TableIDARM_SOBORUD(void);
   virtual void set_TableIDARM_SOBORUD(TFIBBCDField * TableIDARM_SOBORUD);

   virtual TFIBSmallIntField * get_TableON_START_SOBORUD(void);
   virtual void set_TableON_START_SOBORUD(TFIBSmallIntField * TableON_START_SOBORUD);

   virtual TFIBWideStringField * get_TableNAME_OBORUD(void);
   virtual void set_TableNAME_OBORUD(TFIBWideStringField * TableNAME_OBORUD);

   virtual TFIBWideStringField * get_TableCOMPNAME_OBORUD(void);
   virtual void set_TableCOMPNAME_OBORUD(TFIBWideStringField * TableCOMPNAME_OBORUD);

   virtual TFIBWideStringField * get_TableCOMNAME_OBORUD(void);
   virtual void set_TableCOMNAME_OBORUD(TFIBWideStringField * TableCOMNAME_OBORUD);

   virtual TFIBWideStringField * get_TableBAUDRATE_OBORUD(void);
   virtual void set_TableBAUDRATE_OBORUD(TFIBWideStringField * TableBAUDRATE_OBORUD);

   virtual TFIBWideStringField * get_TableTYPE_OBORUD(void);
   virtual void set_TableTYPE_OBORUD(TFIBWideStringField * TableTYPE_OBORUD);

   virtual TFIBWideStringField * get_TableMODEL_OBORUD(void);
   virtual void set_TableMODEL_OBORUD(TFIBWideStringField * TableMODEL_OBORUD);

   virtual TFIBWideStringField * get_TableGID_SOBORUD(void);
   virtual void set_TableGID_SOBORUD(TFIBWideStringField * TableGID_SOBORUD);

   virtual TFIBWideStringField * get_TableSTRPAR_SOBORUD(void);
   virtual void set_TableSTRPAR_SOBORUD(TFIBWideStringField * TableSTRPAR_SOBORUD);

   virtual TFIBWideStringField * get_TableMODUL_SOBORUD(void);
   virtual void set_TableMODUL_SOBORUD(TFIBWideStringField * TableMODUL_SOBORUD);

   virtual TFIBBCDField * get_TableIDBASE_SOBORUD(void);
   virtual void set_TableIDBASE_SOBORUD(TFIBBCDField * TableIDBASE_SOBORUD);

   virtual __int64 get_IdArm(void);
   virtual void set_IdArm(__int64 IdArm);

   virtual void OpenTable(__int64 id_arm, AnsiString type_oborud);
};
#define CLSID_TDMViborOborudImpl __uuidof(TDMViborOborudImpl)
#endif
