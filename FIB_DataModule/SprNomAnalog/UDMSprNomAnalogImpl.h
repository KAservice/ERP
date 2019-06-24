#ifndef UDMSprNomAnalogImplH
#define UDMSprNomAnalogImplH
#include "IDMSprNomAnalog.h"
#include "UDMSprNomAnalog.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprNomAnalogImpl)) TDMSprNomAnalogImpl : public IDMSprNomAnalog
{
public:
   TDMSprNomAnalogImpl();
   ~TDMSprNomAnalogImpl();
   TDMSprNomAnalog * Object;
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

//IDMSprNomAnalog
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourcePodr(void);
   virtual void set_DataSourcePodr(TDataSource * DataSourcePodr);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TFIBLargeIntField * get_TableID_SNOM_ANALOG(void);
   virtual void set_TableID_SNOM_ANALOG(TFIBLargeIntField * TableID_SNOM_ANALOG);

   virtual TFIBLargeIntField * get_TableIDBASE_SNOM_ANALOG(void);
   virtual void set_TableIDBASE_SNOM_ANALOG(TFIBLargeIntField * TableIDBASE_SNOM_ANALOG);

   virtual TFIBWideStringField * get_TableGID_SNOM_ANALOG(void);
   virtual void set_TableGID_SNOM_ANALOG(TFIBWideStringField * TableGID_SNOM_ANALOG);

   virtual TFIBLargeIntField * get_TableIDNOM_SNOM_ANALOG(void);
   virtual void set_TableIDNOM_SNOM_ANALOG(TFIBLargeIntField * TableIDNOM_SNOM_ANALOG);

   virtual TFIBLargeIntField * get_TableIDNOMANALOG_SNOM_ANALOG(void);
   virtual void set_TableIDNOMANALOG_SNOM_ANALOG(TFIBLargeIntField * TableIDNOMANALOG_SNOM_ANALOG);

   virtual TFIBLargeIntField * get_TableIDTYPEANALOG_SNOM_ANALOG(void);
   virtual void set_TableIDTYPEANALOG_SNOM_ANALOG(TFIBLargeIntField * TableIDTYPEANALOG_SNOM_ANALOG);

   virtual TFIBWideStringField * get_TableNAME_STYPE_ANALOG(void);
   virtual void set_TableNAME_STYPE_ANALOG(TFIBWideStringField * TableNAME_STYPE_ANALOG);

   virtual TFIBWideStringField * get_TableNAMENOM(void);
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM);

   virtual TFIBWideStringField * get_TableARTNOM(void);
   virtual void set_TableARTNOM(TFIBWideStringField * TableARTNOM);

   virtual TFIBIntegerField * get_TableCODENOM(void);
   virtual void set_TableCODENOM(TFIBIntegerField * TableCODENOM);

   virtual TFIBWideStringField * get_TableNAMEED(void);
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED);

   virtual TFIBWideStringField * get_TableSHED(void);
   virtual void set_TableSHED(TFIBWideStringField * TableSHED);

   virtual TFIBBCDField * get_TableZNACH_PRICE(void);
   virtual void set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE);

   virtual TFIBLargeIntField * get_ElementID_SNOM_ANALOG(void);
   virtual void set_ElementID_SNOM_ANALOG(TFIBLargeIntField * ElementID_SNOM_ANALOG);

   virtual TFIBLargeIntField * get_ElementIDBASE_SNOM_ANALOG(void);
   virtual void set_ElementIDBASE_SNOM_ANALOG(TFIBLargeIntField * ElementIDBASE_SNOM_ANALOG);

   virtual TFIBWideStringField * get_ElementGID_SNOM_ANALOG(void);
   virtual void set_ElementGID_SNOM_ANALOG(TFIBWideStringField * ElementGID_SNOM_ANALOG);

   virtual TFIBLargeIntField * get_ElementIDNOM_SNOM_ANALOG(void);
   virtual void set_ElementIDNOM_SNOM_ANALOG(TFIBLargeIntField * ElementIDNOM_SNOM_ANALOG);

   virtual TFIBLargeIntField * get_ElementIDNOMANALOG_SNOM_ANALOG(void);
   virtual void set_ElementIDNOMANALOG_SNOM_ANALOG(TFIBLargeIntField * ElementIDNOMANALOG_SNOM_ANALOG);

   virtual TFIBLargeIntField * get_ElementIDTYPEANALOG_SNOM_ANALOG(void);
   virtual void set_ElementIDTYPEANALOG_SNOM_ANALOG(TFIBLargeIntField * ElementIDTYPEANALOG_SNOM_ANALOG);

   virtual TFIBWideStringField * get_ElementNAME_STYPE_ANALOG(void);
   virtual void set_ElementNAME_STYPE_ANALOG(TFIBWideStringField * ElementNAME_STYPE_ANALOG);

   virtual TFIBWideStringField * get_ElementNAMENOM(void);
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM);

   virtual TFIBWideStringField * get_ElementARTNOM(void);
   virtual void set_ElementARTNOM(TFIBWideStringField * ElementARTNOM);

   virtual TFIBIntegerField * get_ElementCODENOM(void);
   virtual void set_ElementCODENOM(TFIBIntegerField * ElementCODENOM);

   virtual TFIBWideStringField * get_ElementNAMEED(void);
   virtual void set_ElementNAMEED(TFIBWideStringField * ElementNAMEED);

   virtual TFIBWideStringField * get_ElementSHED(void);
   virtual void set_ElementSHED(TFIBWideStringField * ElementSHED);

   virtual TpFIBDataSet * get_SpisokTypeAnalog(void);
   virtual void set_SpisokTypeAnalog(TpFIBDataSet * SpisokTypeAnalog);

   virtual TDataSource * get_DataSourceSpisokTypeAnalog(void);
   virtual void set_DataSourceSpisokTypeAnalog(TDataSource * DataSourceSpisokTypeAnalog);

   virtual TFIBWideStringField * get_SpisokTypeAnalogNAME_STYPE_ANALOG(void);
   virtual void set_SpisokTypeAnalogNAME_STYPE_ANALOG(TFIBWideStringField * SpisokTypeAnalogNAME_STYPE_ANALOG);

   virtual TFIBLargeIntField * get_SpisokTypeAnalogID_STYPE_ANALOG(void);
   virtual void set_SpisokTypeAnalogID_STYPE_ANALOG(TFIBLargeIntField * SpisokTypeAnalogID_STYPE_ANALOG);

   virtual TStringField * get_TableNAME_TYPE_ANALOG_LOOKUP(void);
   virtual void set_TableNAME_TYPE_ANALOG_LOOKUP(TStringField * TableNAME_TYPE_ANALOG_LOOKUP);

   virtual __int64 get_IdRodElement(void);
   virtual void set_IdRodElement(__int64 IdRodElement);

   virtual __int64 get_IdElement(void);
   virtual void set_IdElement(__int64 IdElement);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual bool NewElement(__int64 id_rod_element);
   virtual bool InsertElement(__int64 id_rod_element, __int64 id_nom);
   virtual bool OpenElement(__int64 id);
   virtual bool DeleteElement(__int64 id);
   virtual bool SaveElement(void);
   virtual bool OpenTable(__int64 id_rod_element, __int64 id_type_price);
   virtual bool TableSaveIsmen(void);
   virtual bool TableCancelIsmen(void);
   virtual bool TableNewElement(__int64 id_rod_element);
   virtual bool TableAppend(void);
   virtual bool TableDelete(void);
   virtual bool TableEdit(void);
   virtual bool TablePost(void);
};
#define CLSID_TDMSprNomAnalogImpl __uuidof(TDMSprNomAnalogImpl)
#endif
