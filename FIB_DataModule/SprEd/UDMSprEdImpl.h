#ifndef UDMSprEdImplH
#define UDMSprEdImplH
#include "IDMSprEd.h"
#include "UDMSprEd.h"
//---------------------------------------------------------------
class __declspec(uuid("{8C43E7BC-156E-4711-BAEE-C1EBEBF76CF4}")) TDMSprEdImpl : public IDMSprEd
{
public:
   TDMSprEdImpl();
   ~TDMSprEdImpl();
   TDMSprEd * Object;
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

//IDMSprEd
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

   virtual TFIBBCDField * get_TableKFED(void);
   virtual void set_TableKFED(TFIBBCDField * TableKFED);

   virtual TFIBIntegerField * get_TableTSHED(void);
   virtual void set_TableTSHED(TFIBIntegerField * TableTSHED);

   virtual TFIBSmallIntField * get_TableNEISPED(void);
   virtual void set_TableNEISPED(TFIBSmallIntField * TableNEISPED);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBBCDField * get_ElementKFED(void);
   virtual void set_ElementKFED(TFIBBCDField * ElementKFED);

   virtual TFIBIntegerField * get_ElementTSHED(void);
   virtual void set_ElementTSHED(TFIBIntegerField * ElementTSHED);

   virtual TFIBSmallIntField * get_ElementNEISPED(void);
   virtual void set_ElementNEISPED(TFIBSmallIntField * ElementNEISPED);

   virtual TpFIBDataSet * get_OKEI(void);
   virtual void set_OKEI(TpFIBDataSet * OKEI);

   virtual TFIBIntegerField * get_OKEICODEOKEI(void);
   virtual void set_OKEICODEOKEI(TFIBIntegerField * OKEICODEOKEI);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_ElementIDED(void);
   virtual void set_ElementIDED(TFIBBCDField * ElementIDED);

   virtual TFIBBCDField * get_ElementIDNOMED(void);
   virtual void set_ElementIDNOMED(TFIBBCDField * ElementIDNOMED);

   virtual TFIBBCDField * get_ElementIDOKEIED(void);
   virtual void set_ElementIDOKEIED(TFIBBCDField * ElementIDOKEIED);

   virtual TFIBBCDField * get_OKEIIDOKEI(void);
   virtual void set_OKEIIDOKEI(TFIBBCDField * OKEIIDOKEI);

   virtual TFIBIntegerField * get_TableCODE_SED(void);
   virtual void set_TableCODE_SED(TFIBIntegerField * TableCODE_SED);

   virtual TFIBIntegerField * get_ElementCODE_SED(void);
   virtual void set_ElementCODE_SED(TFIBIntegerField * ElementCODE_SED);

   virtual TFIBBCDField * get_TableKF2_SED(void);
   virtual void set_TableKF2_SED(TFIBBCDField * TableKF2_SED);

   virtual TFIBBCDField * get_TableVES_SED(void);
   virtual void set_TableVES_SED(TFIBBCDField * TableVES_SED);

   virtual TFIBBCDField * get_ElementKF2_SED(void);
   virtual void set_ElementKF2_SED(TFIBBCDField * ElementKF2_SED);

   virtual TFIBBCDField * get_ElementVES_SED(void);
   virtual void set_ElementVES_SED(TFIBBCDField * ElementVES_SED);

   virtual TFIBLargeIntField * get_TableIDED(void);
   virtual void set_TableIDED(TFIBLargeIntField * TableIDED);

   virtual TFIBLargeIntField * get_TableIDNOMED(void);
   virtual void set_TableIDNOMED(TFIBLargeIntField * TableIDNOMED);

   virtual TFIBLargeIntField * get_TableIDOKEIED(void);
   virtual void set_TableIDOKEIED(TFIBLargeIntField * TableIDOKEIED);

   virtual TFIBWideStringField * get_TableNAMEED(void);
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED);

   virtual TFIBWideStringField * get_TableSHED(void);
   virtual void set_TableSHED(TFIBWideStringField * TableSHED);

   virtual TFIBWideStringField * get_TableGID_SED(void);
   virtual void set_TableGID_SED(TFIBWideStringField * TableGID_SED);

   virtual TFIBWideStringField * get_ElementNAMEED(void);
   virtual void set_ElementNAMEED(TFIBWideStringField * ElementNAMEED);

   virtual TFIBWideStringField * get_ElementSHED(void);
   virtual void set_ElementSHED(TFIBWideStringField * ElementSHED);

   virtual TFIBWideStringField * get_ElementGID_SED(void);
   virtual void set_ElementGID_SED(TFIBWideStringField * ElementGID_SED);

   virtual TFIBWideStringField * get_OKEINAMEOKEI(void);
   virtual void set_OKEINAMEOKEI(TFIBWideStringField * OKEINAMEOKEI);

   virtual TFIBWideStringField * get_ElementNAMEOKEI(void);
   virtual void set_ElementNAMEOKEI(TFIBWideStringField * ElementNAMEOKEI);

   virtual void OpenTable(__int64 IdNom);
   virtual int OpenElement(__int64 Id);;
   virtual bool NewElement(__int64 IdNom);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual void NewShtrihCod(void);
   virtual __int64 FindEdPoSh(String ShtrihCod);
   virtual __int64 FindEdPoCodu(int code);
   virtual __int64 GetIDElement(String gid);
   virtual AnsiString GetGIDElement(__int64 id);
   virtual __int64 GetIdNomPoShtrihCodu(AnsiString shtrih_cod);
   virtual bool CheckBarCode(__int64 id_ed, AnsiString sh);
   virtual bool CheckCode(__int64 id_ed, int code);
   virtual int GetCodeEd(void);
};
#define CLSID_TDMSprEdImpl __uuidof(TDMSprEdImpl)
#endif
