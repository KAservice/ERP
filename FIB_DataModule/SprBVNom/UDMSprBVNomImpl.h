#ifndef UDMSprBVNomImplH
#define UDMSprBVNomImplH
#include "IDMSprBVNom.h"
#include "UDMSprBVNom.h"
//---------------------------------------------------------------
class __declspec(uuid("{7A70C656-6A98-408C-B85D-5B3FC5B8889F}")) TDMSprBVNomImpl : public IDMSprBVNom
{
public:
   TDMSprBVNomImpl();
   ~TDMSprBVNomImpl();
   TDMSprBVNom * Object;
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

//IDMSprBVNom
   virtual TDataSource * get_DataSourceTable(void);
   virtual void set_DataSourceTable(TDataSource * DataSourceTable);

   virtual TDataSource * get_DataSourcePodr(void);
   virtual void set_DataSourcePodr(TDataSource * DataSourcePodr);

   virtual TpFIBDataSet * get_Table(void);
   virtual void set_Table(TpFIBDataSet * Table);

   virtual TpFIBDataSet * get_Podr(void);
   virtual void set_Podr(TpFIBDataSet * Podr);

   virtual TpFIBTransaction * get_IBTr(void);
   virtual void set_IBTr(TpFIBTransaction * IBTr);

   virtual TpFIBTransaction * get_IBTrUpdate(void);
   virtual void set_IBTrUpdate(TpFIBTransaction * IBTrUpdate);

   virtual TFIBIntegerField * get_TableCODE_BVNOM(void);
   virtual void set_TableCODE_BVNOM(TFIBIntegerField * TableCODE_BVNOM);

   virtual TFIBBCDField * get_TableZNACH_PRICE(void);
   virtual void set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE);

   virtual TIntegerField * get_TableRECNO(void);
   virtual void set_TableRECNO(TIntegerField * TableRECNO);

   virtual TpFIBDataSet * get_Element(void);
   virtual void set_Element(TpFIBDataSet * Element);

   virtual TFIBIntegerField * get_ElementCODE_BVNOM(void);
   virtual void set_ElementCODE_BVNOM(TFIBIntegerField * ElementCODE_BVNOM);

   virtual TFIBBCDField * get_ElementID_BVNOM(void);
   virtual void set_ElementID_BVNOM(TFIBBCDField * ElementID_BVNOM);

   virtual TFIBBCDField * get_ElementIDPOD_BVNOM(void);
   virtual void set_ElementIDPOD_BVNOM(TFIBBCDField * ElementIDPOD_BVNOM);

   virtual TFIBBCDField * get_ElementIDNOM_BVNOM(void);
   virtual void set_ElementIDNOM_BVNOM(TFIBBCDField * ElementIDNOM_BVNOM);

   virtual TFIBBCDField * get_ElementIDGRP_BVNOM(void);
   virtual void set_ElementIDGRP_BVNOM(TFIBBCDField * ElementIDGRP_BVNOM);

   virtual TFIBBCDField * get_PodrIDPOD(void);
   virtual void set_PodrIDPOD(TFIBBCDField * PodrIDPOD);

   virtual TFIBBCDField * get_PodrIDTPRICEPOD(void);
   virtual void set_PodrIDTPRICEPOD(TFIBBCDField * PodrIDTPRICEPOD);

   virtual TFIBBCDField * get_TableID_BVNOM(void);
   virtual void set_TableID_BVNOM(TFIBBCDField * TableID_BVNOM);

   virtual TFIBBCDField * get_TableIDPOD_BVNOM(void);
   virtual void set_TableIDPOD_BVNOM(TFIBBCDField * TableIDPOD_BVNOM);

   virtual TFIBBCDField * get_TableIDNOM_BVNOM(void);
   virtual void set_TableIDNOM_BVNOM(TFIBBCDField * TableIDNOM_BVNOM);

   virtual TFIBBCDField * get_TableIDGRP_BVNOM(void);
   virtual void set_TableIDGRP_BVNOM(TFIBBCDField * TableIDGRP_BVNOM);

   virtual TFIBWideStringField * get_TableGID_SBVNOM(void);
   virtual void set_TableGID_SBVNOM(TFIBWideStringField * TableGID_SBVNOM);

   virtual TFIBWideStringField * get_TableNAMENOM(void);
   virtual void set_TableNAMENOM(TFIBWideStringField * TableNAMENOM);

   virtual TFIBWideStringField * get_TableNAMEED(void);
   virtual void set_TableNAMEED(TFIBWideStringField * TableNAMEED);

   virtual TFIBWideStringField * get_PodrNAMEPOD(void);
   virtual void set_PodrNAMEPOD(TFIBWideStringField * PodrNAMEPOD);

   virtual TFIBWideStringField * get_PodrNAME_TPRICE(void);
   virtual void set_PodrNAME_TPRICE(TFIBWideStringField * PodrNAME_TPRICE);

   virtual TFIBWideStringField * get_ElementGID_SBVNOM(void);
   virtual void set_ElementGID_SBVNOM(TFIBWideStringField * ElementGID_SBVNOM);

   virtual __int64 get_IdPod(void);
   virtual void set_IdPod(__int64 IdPod);

   virtual __int64 get_IdGrp(void);
   virtual void set_IdGrp(__int64 IdGrp);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual __int64 get_IdNomBV(void);
   virtual void set_IdNomBV(__int64 IdNomBV);


   virtual void OpenTable(__int64 Pod, __int64 Grp,bool All);
   virtual void NewElement(__int64 Pod, __int64 Grp);
   virtual bool OpenElement(__int64 id);
   virtual void InsertElement(__int64 Pod, __int64 Grp, __int64 id_nom);
   virtual void DeleteElement();
   virtual void SaveIsmen();
   virtual void CancelIsmen();
   virtual void ChancheGrp(__int64 id_new_grp);
   virtual int FindPoCoduBV(int codeBV);
   virtual bool FindPoPodrAndNom(__int64 id_podr, __int64 id_nom);
};
#define CLSID_TDMSprBVNomImpl __uuidof(TDMSprBVNomImpl)
#endif
