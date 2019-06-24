#ifndef UDMSprNachislImplH
#define UDMSprNachislImplH
#include "IDMSprNachisl.h"
#include "UDMSprNachisl.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprNachislImpl)) TDMSprNachislImpl : public IDMSprNachisl
{
public:
   TDMSprNachislImpl();
   ~TDMSprNachislImpl();
   TDMSprNachisl * Object;
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

//IDMSprNachisl
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TpFIBDataSet * get_TypeNachisl(void);
   virtual void set_TypeNachisl(TpFIBDataSet * TypeNachisl);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBLargeIntField * get_TypeNachislID_STNACHISL(void);
   virtual void set_TypeNachislID_STNACHISL(TFIBLargeIntField * TypeNachislID_STNACHISL);

   virtual TFIBWideStringField * get_TypeNachislNAME_STNACHISL(void);
   virtual void set_TypeNachislNAME_STNACHISL(TFIBWideStringField * TypeNachislNAME_STNACHISL);

   virtual TFIBLargeIntField * get_TableID_SNACHISL(void);
   virtual void set_TableID_SNACHISL(TFIBLargeIntField * TableID_SNACHISL);

   virtual TFIBLargeIntField * get_TableIDBASE_SNACHISL(void);
   virtual void set_TableIDBASE_SNACHISL(TFIBLargeIntField * TableIDBASE_SNACHISL);

   virtual TFIBWideStringField * get_TableGID_SNACHISL(void);
   virtual void set_TableGID_SNACHISL(TFIBWideStringField * TableGID_SNACHISL);

   virtual TFIBLargeIntField * get_TableIDNOM_SNACHISL(void);
   virtual void set_TableIDNOM_SNACHISL(TFIBLargeIntField * TableIDNOM_SNACHISL);

   virtual TFIBLargeIntField * get_TableIDTNACH_SNACHISL(void);
   virtual void set_TableIDTNACH_SNACHISL(TFIBLargeIntField * TableIDTNACH_SNACHISL);

   virtual TFIBBCDField * get_TableVALUE_SNACHISL(void);
   virtual void set_TableVALUE_SNACHISL(TFIBBCDField * TableVALUE_SNACHISL);

   virtual TFIBWideStringField * get_TableNAME_STNACHISL(void);
   virtual void set_TableNAME_STNACHISL(TFIBWideStringField * TableNAME_STNACHISL);

   virtual TStringField * get_TableNAME_TYPE_NACHISL_LOOKUP(void);
   virtual void set_TableNAME_TYPE_NACHISL_LOOKUP(TStringField * TableNAME_TYPE_NACHISL_LOOKUP);

   virtual TFIBBCDField * get_ElementID_SNACHISL(void);
   virtual void set_ElementID_SNACHISL(TFIBBCDField * ElementID_SNACHISL);

   virtual TFIBBCDField * get_ElementIDBASE_SNACHISL(void);
   virtual void set_ElementIDBASE_SNACHISL(TFIBBCDField * ElementIDBASE_SNACHISL);

   virtual TFIBWideStringField * get_ElementGID_SNACHISL(void);
   virtual void set_ElementGID_SNACHISL(TFIBWideStringField * ElementGID_SNACHISL);

   virtual TFIBBCDField * get_ElementIDNOM_SNACHISL(void);
   virtual void set_ElementIDNOM_SNACHISL(TFIBBCDField * ElementIDNOM_SNACHISL);

   virtual TFIBBCDField * get_ElementIDTNACH_SNACHISL(void);
   virtual void set_ElementIDTNACH_SNACHISL(TFIBBCDField * ElementIDTNACH_SNACHISL);

   virtual TFIBBCDField * get_ElementVALUE_SNACHISL(void);
   virtual void set_ElementVALUE_SNACHISL(TFIBBCDField * ElementVALUE_SNACHISL);

   virtual __int64 get_IdNom(void);
   virtual void set_IdNom(__int64 IdNom);

   virtual __int64 get_IdTypeNachisl(void);
   virtual void set_IdTypeNachisl(__int64 IdTypeNachisl);

   virtual void OpenTable(__int64 id_nom);
   virtual bool SaveIsmen(void);
   virtual void CancelIsmen(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
   virtual __int64 FindElement(__int64 id_type_nachisl, __int64 id_nom);
};
#define CLSID_TDMSprNachislImpl __uuidof(TDMSprNachislImpl)
#endif
