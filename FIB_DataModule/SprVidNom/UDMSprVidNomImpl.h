#ifndef UDMSprVidNomImplH
#define UDMSprVidNomImplH
#include "IDMSprVidNom.h"
#include "UDMSprVidNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{E8D6D98A-B1A8-4A10-B3D7-6F062C70447B}")) TDMSprVidNomImpl : public IDMSprVidNom
{
public:
   TDMSprVidNomImpl();
   ~TDMSprVidNomImpl();
   TDMSprVidNom * Object;
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

//IDMSprVidNom
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

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_TableID_SVIDNOM(void);
   virtual void set_TableID_SVIDNOM(TFIBBCDField * TableID_SVIDNOM);

   virtual TFIBBCDField * get_ElementID_SVIDNOM(void);
   virtual void set_ElementID_SVIDNOM(TFIBBCDField * ElementID_SVIDNOM);

   virtual TFIBWideStringField * get_TableGID_SVIDNOM(void);
   virtual void set_TableGID_SVIDNOM(TFIBWideStringField * TableGID_SVIDNOM);

   virtual TFIBWideStringField * get_TableNAME_SVIDNOM(void);
   virtual void set_TableNAME_SVIDNOM(TFIBWideStringField * TableNAME_SVIDNOM);

   virtual TFIBWideStringField * get_ElementNAME_SVIDNOM(void);
   virtual void set_ElementNAME_SVIDNOM(TFIBWideStringField * ElementNAME_SVIDNOM);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual bool NewElement(void);
   virtual bool SaveElement(void);
   virtual bool SaveIsmen(void);
   virtual bool CancelIsmen(void);
   virtual void CloseElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual int GetIndexElementaPoID(__int64 id);
};
#define CLSID_TDMSprVidNomImpl __uuidof(TDMSprVidNomImpl)
#endif
