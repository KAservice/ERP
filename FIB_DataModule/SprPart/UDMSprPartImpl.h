#ifndef UDMSprPartImplH
#define UDMSprPartImplH
#include "IDMSprPart.h"
#include "UDMSprPart.h"
//---------------------------------------------------------------
class __declspec(uuid("{035DB0CF-39EF-409F-995C-DF8CE0E07E82}")) TDMSprPartImpl : public IDMSprPart
{
public:
   TDMSprPartImpl();
   ~TDMSprPartImpl();
   TDMSprPart * Object;
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

//IDMSprPart
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

   virtual TFIBBCDField * get_TablePRICEZPART(void);
   virtual void set_TablePRICEZPART(TFIBBCDField * TablePRICEZPART);

   virtual TFIBBCDField * get_TableKOLOSTNOM(void);
   virtual void set_TableKOLOSTNOM(TFIBBCDField * TableKOLOSTNOM);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBBCDField * get_ElementPRICEZPART(void);
   virtual void set_ElementPRICEZPART(TFIBBCDField * ElementPRICEZPART);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_TableIDPART(void);
   virtual void set_TableIDPART(TFIBBCDField * TableIDPART);

   virtual TFIBBCDField * get_TableIDKLPART(void);
   virtual void set_TableIDKLPART(TFIBBCDField * TableIDKLPART);

   virtual TFIBBCDField * get_TableIDFIRMPART(void);
   virtual void set_TableIDFIRMPART(TFIBBCDField * TableIDFIRMPART);

   virtual TFIBBCDField * get_TableIDNOMPART(void);
   virtual void set_TableIDNOMPART(TFIBBCDField * TableIDNOMPART);

   virtual TFIBBCDField * get_ElementIDKLPART(void);
   virtual void set_ElementIDKLPART(TFIBBCDField * ElementIDKLPART);

   virtual TFIBBCDField * get_ElementIDFIRMPART(void);
   virtual void set_ElementIDFIRMPART(TFIBBCDField * ElementIDFIRMPART);

   virtual TFIBBCDField * get_ElementIDNOMPART(void);
   virtual void set_ElementIDNOMPART(TFIBBCDField * ElementIDNOMPART);

   virtual TFIBBCDField * get_TableIDDOCPART(void);
   virtual void set_TableIDDOCPART(TFIBBCDField * TableIDDOCPART);

   virtual TFIBBCDField * get_ElementIDDOCPART(void);
   virtual void set_ElementIDDOCPART(TFIBBCDField * ElementIDDOCPART);

   virtual TFIBBCDField * get_ElementIDPART(void);
   virtual void set_ElementIDPART(TFIBBCDField * ElementIDPART);

   virtual TFIBDateTimeField * get_TableSRGODNPART(void);
   virtual void set_TableSRGODNPART(TFIBDateTimeField * TableSRGODNPART);

   virtual TFIBDateTimeField * get_ElementSRGODNPART(void);
   virtual void set_ElementSRGODNPART(TFIBDateTimeField * ElementSRGODNPART);

   virtual TFIBIntegerField * get_TableCODEPART(void);
   virtual void set_TableCODEPART(TFIBIntegerField * TableCODEPART);

   virtual TFIBWideStringField * get_TableDOCPART(void);
   virtual void set_TableDOCPART(TFIBWideStringField * TableDOCPART);

   virtual TFIBWideStringField * get_TableGTDPART(void);
   virtual void set_TableGTDPART(TFIBWideStringField * TableGTDPART);

   virtual TFIBWideStringField * get_TableSERTPART(void);
   virtual void set_TableSERTPART(TFIBWideStringField * TableSERTPART);

   virtual TFIBWideStringField * get_TableGID_SPART(void);
   virtual void set_TableGID_SPART(TFIBWideStringField * TableGID_SPART);

   virtual TFIBBCDField * get_TableIDBASE_SPART(void);
   virtual void set_TableIDBASE_SPART(TFIBBCDField * TableIDBASE_SPART);

   virtual TFIBBCDField * get_TableIDEXT_DOUT_SPART(void);
   virtual void set_TableIDEXT_DOUT_SPART(TFIBBCDField * TableIDEXT_DOUT_SPART);

   virtual TFIBBCDField * get_TableIDEXT_BASE_SPART(void);
   virtual void set_TableIDEXT_BASE_SPART(TFIBBCDField * TableIDEXT_BASE_SPART);

   virtual TFIBWideStringField * get_TableNAMEFIRM(void);
   virtual void set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBIntegerField * get_ElementCODEPART(void);
   virtual void set_ElementCODEPART(TFIBIntegerField * ElementCODEPART);

   virtual TFIBWideStringField * get_ElementDOCPART(void);
   virtual void set_ElementDOCPART(TFIBWideStringField * ElementDOCPART);

   virtual TFIBWideStringField * get_ElementGTDPART(void);
   virtual void set_ElementGTDPART(TFIBWideStringField * ElementGTDPART);

   virtual TFIBWideStringField * get_ElementGID_SPART(void);
   virtual void set_ElementGID_SPART(TFIBWideStringField * ElementGID_SPART);

   virtual TFIBBCDField * get_ElementIDBASE_SPART(void);
   virtual void set_ElementIDBASE_SPART(TFIBBCDField * ElementIDBASE_SPART);

   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void);
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT);

   virtual TFIBWideStringField * get_ElementNAMENOM(void);
   virtual void set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM);

   virtual TFIBWideStringField * get_ElementNAMEFIRM(void);
   virtual void set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM);

   virtual TFIBWideStringField * get_ElementSERTPART(void);
   virtual void set_ElementSERTPART(TFIBWideStringField * ElementSERTPART);

   virtual void OpenTable(__int64 IdNom);
   virtual int OpenElement(__int64 Id);;
   virtual void NewElement(__int64 IdNom);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
};
#define CLSID_TDMSprPartImpl __uuidof(TDMSprPartImpl)
#endif
