#ifndef UART_DMSprInfBlockPrivImplH
#define UART_DMSprInfBlockPrivImplH
#include "IART_DMSprInfBlockPriv.h"
#include "UART_DMSprInfBlockPriv.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TART_DMSprInfBlockPrivImpl)) TART_DMSprInfBlockPrivImpl : public IART_DMSprInfBlockPriv
{
public:
   TART_DMSprInfBlockPrivImpl();
   ~TART_DMSprInfBlockPrivImpl();
   TART_DMSprInfBlockPriv * Object;
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

//IART_DMSprInfBlockPriv
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

   virtual TpFIBDataSet * get_GrpUser(void);
   virtual void set_GrpUser(TpFIBDataSet * GrpUser);

   virtual TFIBLargeIntField * get_GrpUserID_SGRPUSER(void);
   virtual void set_GrpUserID_SGRPUSER(TFIBLargeIntField * GrpUserID_SGRPUSER);

   virtual TFIBWideStringField * get_GrpUserNAME_SGRPUSER(void);
   virtual void set_GrpUserNAME_SGRPUSER(TFIBWideStringField * GrpUserNAME_SGRPUSER);

   virtual TFIBLargeIntField * get_TableID_ART_IB_PRIV(void);
   virtual void set_TableID_ART_IB_PRIV(TFIBLargeIntField * TableID_ART_IB_PRIV);

   virtual TFIBLargeIntField * get_TableIDBASE_ART_IB_PRIV(void);
   virtual void set_TableIDBASE_ART_IB_PRIV(TFIBLargeIntField * TableIDBASE_ART_IB_PRIV);

   virtual TFIBLargeIntField * get_TableIDIB_ART_IB_PRIV(void);
   virtual void set_TableIDIB_ART_IB_PRIV(TFIBLargeIntField * TableIDIB_ART_IB_PRIV);

   virtual TFIBLargeIntField * get_TableIDGRPUSER_ART_IB_PRIV(void);
   virtual void set_TableIDGRPUSER_ART_IB_PRIV(TFIBLargeIntField * TableIDGRPUSER_ART_IB_PRIV);

   virtual TFIBSmallIntField * get_TableSEL_ART_IB_PRIV(void);
   virtual void set_TableSEL_ART_IB_PRIV(TFIBSmallIntField * TableSEL_ART_IB_PRIV);

   virtual TFIBSmallIntField * get_TableINS_ART_IB_PRIV(void);
   virtual void set_TableINS_ART_IB_PRIV(TFIBSmallIntField * TableINS_ART_IB_PRIV);

   virtual TFIBSmallIntField * get_TableUPD_ART_IB_PRIV(void);
   virtual void set_TableUPD_ART_IB_PRIV(TFIBSmallIntField * TableUPD_ART_IB_PRIV);

   virtual TFIBSmallIntField * get_TableDEL_ART_IB_PRIV(void);
   virtual void set_TableDEL_ART_IB_PRIV(TFIBSmallIntField * TableDEL_ART_IB_PRIV);

   virtual TFIBWideStringField * get_TableNAME_SGRPUSER(void);
   virtual void set_TableNAME_SGRPUSER(TFIBWideStringField * TableNAME_SGRPUSER);

   virtual TStringField * get_TableNAME_GRPUSER_LOOKUP(void);
   virtual void set_TableNAME_GRPUSER_LOOKUP(TStringField * TableNAME_GRPUSER_LOOKUP);

   virtual TFIBLargeIntField * get_ElementID_ART_IB_PRIV(void);
   virtual void set_ElementID_ART_IB_PRIV(TFIBLargeIntField * ElementID_ART_IB_PRIV);

   virtual TFIBLargeIntField * get_ElementIDBASE_ART_IB_PRIV(void);
   virtual void set_ElementIDBASE_ART_IB_PRIV(TFIBLargeIntField * ElementIDBASE_ART_IB_PRIV);

   virtual TFIBLargeIntField * get_ElementIDIB_ART_IB_PRIV(void);
   virtual void set_ElementIDIB_ART_IB_PRIV(TFIBLargeIntField * ElementIDIB_ART_IB_PRIV);

   virtual TFIBLargeIntField * get_ElementIDGRPUSER_ART_IB_PRIV(void);
   virtual void set_ElementIDGRPUSER_ART_IB_PRIV(TFIBLargeIntField * ElementIDGRPUSER_ART_IB_PRIV);

   virtual TFIBSmallIntField * get_ElementSEL_ART_IB_PRIV(void);
   virtual void set_ElementSEL_ART_IB_PRIV(TFIBSmallIntField * ElementSEL_ART_IB_PRIV);

   virtual TFIBSmallIntField * get_ElementINS_ART_IB_PRIV(void);
   virtual void set_ElementINS_ART_IB_PRIV(TFIBSmallIntField * ElementINS_ART_IB_PRIV);

   virtual TFIBSmallIntField * get_ElementUPD_ART_IB_PRIV(void);
   virtual void set_ElementUPD_ART_IB_PRIV(TFIBSmallIntField * ElementUPD_ART_IB_PRIV);

   virtual TFIBSmallIntField * get_ElementDEL_ART_IB_PRIV(void);
   virtual void set_ElementDEL_ART_IB_PRIV(TFIBSmallIntField * ElementDEL_ART_IB_PRIV);

   virtual __int64 get_IdIB(void);
   virtual void set_IdIB(__int64 IdIB);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual void OpenTable(__int64 id_ib);
   virtual bool SaveIsmen(void);
   virtual bool CancelIsmen(void);
   virtual bool TableAppend(__int64 id_ib);
   virtual bool TableDelete(void);
   virtual bool NewElement(__int64 id_ib);
   virtual int OpenElement(__int64 id );
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
};
#define CLSID_TART_DMSprInfBlockPrivImpl __uuidof(TART_DMSprInfBlockPrivImpl)
#endif
