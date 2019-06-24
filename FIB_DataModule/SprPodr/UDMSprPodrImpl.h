#ifndef UDMSprPodrImplH
#define UDMSprPodrImplH
#include "IDMSprPodr.h"
#include "UDMSprPodr.h"
//---------------------------------------------------------------
class __declspec(uuid("{BC3F8165-98C1-45D5-8BFC-3654FFC172C7}")) TDMSprPodrImpl : public IDMSprPodr
{
public:
   TDMSprPodrImpl();
   ~TDMSprPodrImpl();
   TDMSprPodr * Object;
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

//IDMSprPodr
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

   virtual TFIBBCDField * get_TableIDPOD(void);
   virtual void set_TableIDPOD(TFIBBCDField * TableIDPOD);

   virtual TFIBBCDField * get_TableIDTPRICEPOD(void);
   virtual void set_TableIDTPRICEPOD(TFIBBCDField * TableIDTPRICEPOD);

   virtual TFIBBCDField * get_ElementIDPOD(void);
   virtual void set_ElementIDPOD(TFIBBCDField * ElementIDPOD);

   virtual TFIBBCDField * get_ElementIDTPRICEPOD(void);
   virtual void set_ElementIDTPRICEPOD(TFIBBCDField * ElementIDTPRICEPOD);

   virtual TFIBWideStringField * get_TableNAMEPOD(void);
   virtual void set_TableNAMEPOD(TFIBWideStringField * TableNAMEPOD);

   virtual TFIBWideStringField * get_TableGID_SPOD(void);
   virtual void set_TableGID_SPOD(TFIBWideStringField * TableGID_SPOD);

   virtual TFIBBCDField * get_TableIDBASE_SPOD(void);
   virtual void set_TableIDBASE_SPOD(TFIBBCDField * TableIDBASE_SPOD);

   virtual TFIBWideStringField * get_TableNAME_TPRICE(void);
   virtual void set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE);

   virtual TFIBWideStringField * get_ElementNAMEPOD(void);
   virtual void set_ElementNAMEPOD(TFIBWideStringField * ElementNAMEPOD);

   virtual TFIBWideStringField * get_ElementGID_SPOD(void);
   virtual void set_ElementGID_SPOD(TFIBWideStringField * ElementGID_SPOD);

   virtual TFIBBCDField * get_ElementIDBASE_SPOD(void);
   virtual void set_ElementIDBASE_SPOD(TFIBBCDField * ElementIDBASE_SPOD);

   virtual TFIBWideStringField * get_ElementNAME_TPRICE(void);
   virtual void set_ElementNAME_TPRICE(TFIBWideStringField * ElementNAME_TPRICE);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
};
#define CLSID_TDMSprPodrImpl __uuidof(TDMSprPodrImpl)
#endif
