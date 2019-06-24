#ifndef UDMSprGrpProjectImplH
#define UDMSprGrpProjectImplH
#include "IDMSprGrpProject.h"
#include "UDMSprGrpProject.h"
//---------------------------------------------------------------
class __declspec(uuid("{5212959A-9E08-43D6-BA1B-FEEC3200A48C}")) TDMSprGrpProjectImpl : public IDMSprGrpProject
{
public:
   TDMSprGrpProjectImpl();
   ~TDMSprGrpProjectImpl();
   TDMSprGrpProject * Object;
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

//IDMSprGrpProject
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

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_TableID_SGRPPROJECT(void);
   virtual void set_TableID_SGRPPROJECT(TFIBBCDField * TableID_SGRPPROJECT);

   virtual TFIBBCDField * get_TableIDGRP_SGRPPROJECT(void);
   virtual void set_TableIDGRP_SGRPPROJECT(TFIBBCDField * TableIDGRP_SGRPPROJECT);

   virtual TFIBBCDField * get_ElementID_SGRPPROJECT(void);
   virtual void set_ElementID_SGRPPROJECT(TFIBBCDField * ElementID_SGRPPROJECT);

   virtual TFIBBCDField * get_ElementIDGRP_SGRPPROJECT(void);
   virtual void set_ElementIDGRP_SGRPPROJECT(TFIBBCDField * ElementIDGRP_SGRPPROJECT);

   virtual TFIBWideStringField * get_TableNAME_SGRPPROJECT(void);
   virtual void set_TableNAME_SGRPPROJECT(TFIBWideStringField * TableNAME_SGRPPROJECT);

   virtual TFIBWideStringField * get_ElementNAME_SGRPPROJECT(void);
   virtual void set_ElementNAME_SGRPPROJECT(TFIBWideStringField * ElementNAME_SGRPPROJECT);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 FindPoName(AnsiString name);
};
#define CLSID_TDMSprGrpProjectImpl __uuidof(TDMSprGrpProjectImpl)
#endif
