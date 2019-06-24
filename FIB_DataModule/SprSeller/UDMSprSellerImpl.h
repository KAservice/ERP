#ifndef UDMSprSellerImplH
#define UDMSprSellerImplH
#include "IDMSprSeller.h"
#include "UDMSprSeller.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprSellerImpl)) TDMSprSellerImpl : public IDMSprSeller
{
public:
   TDMSprSellerImpl();
   ~TDMSprSellerImpl();
   TDMSprSeller * Object;
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

//IDMSprSeller
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

   virtual TFIBLargeIntField * get_TableID_SSELLER(void);
   virtual void set_TableID_SSELLER(TFIBLargeIntField * TableID_SSELLER);

   virtual TFIBLargeIntField * get_TableIDBASE_SSELLER(void);
   virtual void set_TableIDBASE_SSELLER(TFIBLargeIntField * TableIDBASE_SSELLER);

   virtual TFIBWideStringField * get_TableNAME_SSELLER(void);
   virtual void set_TableNAME_SSELLER(TFIBWideStringField * TableNAME_SSELLER);

   virtual TFIBWideStringField * get_TableADR_SSELLER(void);
   virtual void set_TableADR_SSELLER(TFIBWideStringField * TableADR_SSELLER);

   virtual TFIBWideStringField * get_TablePHONE_SSELLER(void);
   virtual void set_TablePHONE_SSELLER(TFIBWideStringField * TablePHONE_SSELLER);

   virtual TFIBLargeIntField * get_TableIDKLIENT_SSELLER(void);
   virtual void set_TableIDKLIENT_SSELLER(TFIBLargeIntField * TableIDKLIENT_SSELLER);

   virtual TFIBWideStringField * get_TableNAME_FOR_PRINT_SSELLER(void);
   virtual void set_TableNAME_FOR_PRINT_SSELLER(TFIBWideStringField * TableNAME_FOR_PRINT_SSELLER);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBWideStringField * get_TableINNKLIENT(void);
   virtual void set_TableINNKLIENT(TFIBWideStringField * TableINNKLIENT);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TFIBLargeIntField * get_ElementID_SSELLER(void);
   virtual void set_ElementID_SSELLER(TFIBLargeIntField * ElementID_SSELLER);

   virtual TFIBLargeIntField * get_ElementIDBASE_SSELLER(void);
   virtual void set_ElementIDBASE_SSELLER(TFIBLargeIntField * ElementIDBASE_SSELLER);

   virtual TFIBWideStringField * get_ElementNAME_SSELLER(void);
   virtual void set_ElementNAME_SSELLER(TFIBWideStringField * ElementNAME_SSELLER);

   virtual TFIBWideStringField * get_ElementADR_SSELLER(void);
   virtual void set_ElementADR_SSELLER(TFIBWideStringField * ElementADR_SSELLER);

   virtual TFIBWideStringField * get_ElementPHONE_SSELLER(void);
   virtual void set_ElementPHONE_SSELLER(TFIBWideStringField * ElementPHONE_SSELLER);

   virtual TFIBLargeIntField * get_ElementIDKLIENT_SSELLER(void);
   virtual void set_ElementIDKLIENT_SSELLER(TFIBLargeIntField * ElementIDKLIENT_SSELLER);

   virtual TFIBWideStringField * get_ElementNAME_FOR_PRINT_SSELLER(void);
   virtual void set_ElementNAME_FOR_PRINT_SSELLER(TFIBWideStringField * ElementNAME_FOR_PRINT_SSELLER);

   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void);
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT);

   virtual bool OpenTable();
   virtual bool  OpenElement(__int64 id);
   virtual bool NewElement();
   virtual bool SaveElement(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual __int64 GetIdElementPoName(UnicodeString   name);
   virtual int GetIndexInTablePoId(__int64 id_element);
   virtual __int64 GetIdElementPoGid(UnicodeString gid);
   virtual UnicodeString GetGidElementPoId(__int64 id);
};
#define CLSID_TDMSprSellerImpl __uuidof(TDMSprSellerImpl)
#endif
