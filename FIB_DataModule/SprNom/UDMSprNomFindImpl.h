#ifndef UDMSprNomFindImplH
#define UDMSprNomFindImplH
#include "IDMSprNomFind.h"
#include "UDMSprNomFind.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprNomFindImpl)) TDMSprNomFindImpl : public IDMSprNomFind
{
public:
   TDMSprNomFindImpl();
   ~TDMSprNomFindImpl();
   TDMSprNomFind * Object;
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

//IDMSprNomFind
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBDataSet * get_SpTPrice(void);
   virtual void set_SpTPrice(TpFIBDataSet * SpTPrice);

   virtual TFIBLargeIntField * get_TableIDNOM(void);
   virtual void set_TableIDNOM(TFIBLargeIntField * TableIDNOM);

   virtual TFIBWideStringField * get_TableARTNOM(void);
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM);

   virtual TFIBIntegerField * get_TableCODENOM(void);
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM);

   virtual TFIBSmallIntField * get_TableTNOM(void);
   virtual void set_TableTNOM(TFIBSmallIntField * TableTNOM);

   virtual TFIBWideStringField * get_TableNAMENOM(void);
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM);

   virtual TFIBWideStringField * get_TableNAMEED(void);
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED);

   virtual TFIBBCDField * get_TableZNACH_PRICE(void);
   virtual void set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE);

   virtual TFIBLargeIntField * get_TableIDGRPNOM(void);
   virtual void set_TableIDGRPNOM(TFIBLargeIntField * TableIDGRPNOM);

   virtual TFIBBCDField * get_TableSUMKOL(void);
   virtual void set_TableSUMKOL(TFIBBCDField * TableSUMKOL);

   virtual TDataSource * get_DataSourceTPrice(void);
   virtual void set_DataSourceTPrice(TDataSource * DataSourceTPrice);

   virtual TFIBLargeIntField * get_SpTPriceID_TPRICE(void);
   virtual void set_SpTPriceID_TPRICE(TFIBLargeIntField * SpTPriceID_TPRICE);

   virtual TFIBWideStringField * get_SpTPriceNAME_TPRICE(void);
   virtual void set_SpTPriceNAME_TPRICE(TFIBWideStringField * SpTPriceNAME_TPRICE);

   virtual TFIBWideStringField * get_TableNAMEGN(void);
   virtual void set_TableNAMEGN(TFIBWideStringField * TableNAMEGN);

   virtual TFIBWideStringField * get_TableSHED(void);
   virtual void set_TableSHED(TFIBWideStringField * TableSHED);

   virtual TFIBBCDField * get_TableREM_OST(void);
   virtual void set_TableREM_OST(TFIBBCDField * TableREM_OST);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual __int64 get_IdFirm(void);
   virtual void set_IdFirm(__int64 IdFirm);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual bool SetTextQuery(UnicodeString text);
   virtual bool SetIntegerParam(UnicodeString name_param, int value_param);
   virtual bool SetInt64Param(UnicodeString name_param, __int64 value_param);
   virtual bool SetStringParam(UnicodeString name_param, UnicodeString value_param);
   virtual bool OpenTableResult(void);
};
#define CLSID_TDMSprNomFindImpl __uuidof(TDMSprNomFindImpl)
#endif
