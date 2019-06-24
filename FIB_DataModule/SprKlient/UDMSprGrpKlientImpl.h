#ifndef UDMSprGrpKlientImplH
#define UDMSprGrpKlientImplH
#include "IDMSprGrpKlient.h"
#include "UDMSprGrpKlient.h"
//---------------------------------------------------------------
class __declspec(uuid("{82FCD399-53D1-489E-8D50-EF1A01FD1544}")) TDMSprGrpKlientImpl : public IDMSprGrpKlient
{
public:
   TDMSprGrpKlientImpl();
   ~TDMSprGrpKlientImpl();
   TDMSprGrpKlient * Object;
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

//IDMSprGrpKlient
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

   virtual TFIBBCDField * get_TableIDGRPKL(void);
   virtual void set_TableIDGRPKL(TFIBBCDField * TableIDGRPKL);

   virtual TFIBBCDField * get_TableGRPKL(void);
   virtual void set_TableGRPKL(TFIBBCDField * TableGRPKL);

   virtual TFIBBCDField * get_ElementIDGRPKL(void);
   virtual void set_ElementIDGRPKL(TFIBBCDField * ElementIDGRPKL);

   virtual TFIBBCDField * get_ElementGRPKL(void);
   virtual void set_ElementGRPKL(TFIBBCDField * ElementGRPKL);

   virtual TFIBWideStringField * get_TableNAMEGRPKL(void);
   virtual void set_TableNAMEGRPKL(TFIBWideStringField * TableNAMEGRPKL);

   virtual TFIBWideStringField * get_TableGID_SGRPKL(void);
   virtual void set_TableGID_SGRPKL(TFIBWideStringField * TableGID_SGRPKL);

   virtual TFIBWideStringField * get_ElementNAMEGRPKL(void);
   virtual void set_ElementNAMEGRPKL(TFIBWideStringField * ElementNAMEGRPKL);

   virtual TFIBWideStringField * get_ElementGID_SGRPKL(void);
   virtual void set_ElementGID_SGRPKL(TFIBWideStringField * ElementGID_SGRPKL);

   virtual bool OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(__int64 IdGrp);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 Id);
};
#define CLSID_TDMSprGrpKlientImpl __uuidof(TDMSprGrpKlientImpl)
#endif
