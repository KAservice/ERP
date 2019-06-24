#ifndef UDMSprDogovorImplH
#define UDMSprDogovorImplH
#include "IDMSprDogovor.h"
#include "UDMSprDogovor.h"
//---------------------------------------------------------------
class __declspec(uuid("{F766335B-F031-41F2-9109-A4B608A69BB0}")) TDMSprDogovorImpl : public IDMSprDogovor
{
public:
   TDMSprDogovorImpl();
   ~TDMSprDogovorImpl();
   TDMSprDogovor * Object;
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

//IDMSprDogovor
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

   virtual TFIBDateField * get_TableDO_SDOG(void);
   virtual void set_TableDO_SDOG(TFIBDateField * TableDO_SDOG);

   virtual TFIBIntegerField * get_TableWAYPAY_SDOG(void);
   virtual void set_TableWAYPAY_SDOG(TFIBIntegerField * TableWAYPAY_SDOG);

   virtual TFIBBCDField * get_TableMAXSUMCREDIT_SDOG(void);
   virtual void set_TableMAXSUMCREDIT_SDOG(TFIBBCDField * TableMAXSUMCREDIT_SDOG);

   virtual TFIBIntegerField * get_TableSROK_SDOG(void);
   virtual void set_TableSROK_SDOG(TFIBIntegerField * TableSROK_SDOG);

   virtual TFIBDateField * get_TableDATE_SDOG(void);
   virtual void set_TableDATE_SDOG(TFIBDateField * TableDATE_SDOG);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBDateField * get_ElementDO_SDOG(void);
   virtual void set_ElementDO_SDOG(TFIBDateField * ElementDO_SDOG);

   virtual TFIBIntegerField * get_ElementWAYPAY_SDOG(void);
   virtual void set_ElementWAYPAY_SDOG(TFIBIntegerField * ElementWAYPAY_SDOG);

   virtual TFIBBCDField * get_ElementMAXSUMCREDIT_SDOG(void);
   virtual void set_ElementMAXSUMCREDIT_SDOG(TFIBBCDField * ElementMAXSUMCREDIT_SDOG);

   virtual TFIBIntegerField * get_ElementSROK_SDOG(void);
   virtual void set_ElementSROK_SDOG(TFIBIntegerField * ElementSROK_SDOG);

   virtual TFIBDateField * get_ElementDATE_SDOG(void);
   virtual void set_ElementDATE_SDOG(TFIBDateField * ElementDATE_SDOG);

   virtual TFIBBCDField * get_TableID_SDOG(void);
   virtual void set_TableID_SDOG(TFIBBCDField * TableID_SDOG);

   virtual TFIBBCDField * get_TableIDKLIENT_SDOG(void);
   virtual void set_TableIDKLIENT_SDOG(TFIBBCDField * TableIDKLIENT_SDOG);

   virtual TFIBBCDField * get_TableIDTPRICE_SDOG(void);
   virtual void set_TableIDTPRICE_SDOG(TFIBBCDField * TableIDTPRICE_SDOG);

   virtual TFIBBCDField * get_ElementID_SDOG(void);
   virtual void set_ElementID_SDOG(TFIBBCDField * ElementID_SDOG);

   virtual TFIBBCDField * get_ElementIDKLIENT_SDOG(void);
   virtual void set_ElementIDKLIENT_SDOG(TFIBBCDField * ElementIDKLIENT_SDOG);

   virtual TFIBBCDField * get_ElementIDTPRICE_SDOG(void);
   virtual void set_ElementIDTPRICE_SDOG(TFIBBCDField * ElementIDTPRICE_SDOG);

   virtual TFIBWideStringField * get_TableNAME_SDOG(void);
   virtual void set_TableNAME_SDOG(TFIBWideStringField * TableNAME_SDOG);

   virtual TFIBWideStringField * get_TableGID_SDOG(void);
   virtual void set_TableGID_SDOG(TFIBWideStringField * TableGID_SDOG);

   virtual TFIBWideStringField * get_TableNUMBER_SDOG(void);
   virtual void set_TableNUMBER_SDOG(TFIBWideStringField * TableNUMBER_SDOG);

   virtual TFIBWideStringField * get_ElementNAME_SDOG(void);
   virtual void set_ElementNAME_SDOG(TFIBWideStringField * ElementNAME_SDOG);

   virtual TFIBWideStringField * get_ElementGID_SDOG(void);
   virtual void set_ElementGID_SDOG(TFIBWideStringField * ElementGID_SDOG);

   virtual TFIBWideStringField * get_ElementNUMBER_SDOG(void);
   virtual void set_ElementNUMBER_SDOG(TFIBWideStringField * ElementNUMBER_SDOG);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual bool get_flSaveElement(void);
   virtual void set_flSaveElement(bool flSaveElement);

   virtual void OpenTable(__int64 IdKl);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(__int64 IdKl);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
};
#define CLSID_TDMSprDogovorImpl __uuidof(TDMSprDogovorImpl)
#endif
