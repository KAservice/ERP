#ifndef UDMSprNakSkidokImplH
#define UDMSprNakSkidokImplH
#include "IDMSprNakSkidok.h"
#include "UDMSprNakSkidok.h"
//---------------------------------------------------------------
class __declspec(uuid("{C5C26779-F884-4558-9CF3-CFA6D75D63AA}")) TDMSprNakSkidokImpl : public IDMSprNakSkidok
{
public:
   TDMSprNakSkidokImpl();
   ~TDMSprNakSkidokImpl();
   TDMSprNakSkidok * Object;
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

//IDMSprNakSkidok
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

   virtual TFIBBCDField * get_TableSUM_SNAK_SKIDOK(void);
   virtual void set_TableSUM_SNAK_SKIDOK(TFIBBCDField * TableSUM_SNAK_SKIDOK);

   virtual TFIBBCDField * get_TablePROCENT_SNAK_SKIDOK(void);
   virtual void set_TablePROCENT_SNAK_SKIDOK(TFIBBCDField * TablePROCENT_SNAK_SKIDOK);

   virtual TFIBSmallIntField * get_TablePERIOD_SNAK_SKIDOK(void);
   virtual void set_TablePERIOD_SNAK_SKIDOK(TFIBSmallIntField * TablePERIOD_SNAK_SKIDOK);

   virtual TFIBBCDField * get_ElementSUM_SNAK_SKIDOK(void);
   virtual void set_ElementSUM_SNAK_SKIDOK(TFIBBCDField * ElementSUM_SNAK_SKIDOK);

   virtual TFIBBCDField * get_ElementPROCENT_SNAK_SKIDOK(void);
   virtual void set_ElementPROCENT_SNAK_SKIDOK(TFIBBCDField * ElementPROCENT_SNAK_SKIDOK);

   virtual TFIBSmallIntField * get_ElementPERIOD_SNAK_SKIDOK(void);
   virtual void set_ElementPERIOD_SNAK_SKIDOK(TFIBSmallIntField * ElementPERIOD_SNAK_SKIDOK);

   virtual TpFIBQuery * get_Query(void);
   virtual void set_Query(TpFIBQuery * Query);

   virtual TFIBBCDField * get_TableID_SNAK_SKIDOK(void);
   virtual void set_TableID_SNAK_SKIDOK(TFIBBCDField * TableID_SNAK_SKIDOK);

   virtual TFIBBCDField * get_TableIDSKLAD_SNAK_SKIDOK(void);
   virtual void set_TableIDSKLAD_SNAK_SKIDOK(TFIBBCDField * TableIDSKLAD_SNAK_SKIDOK);

   virtual TFIBBCDField * get_TableIDVID_SNAK_SKIDOK(void);
   virtual void set_TableIDVID_SNAK_SKIDOK(TFIBBCDField * TableIDVID_SNAK_SKIDOK);

   virtual TFIBBCDField * get_ElementID_SNAK_SKIDOK(void);
   virtual void set_ElementID_SNAK_SKIDOK(TFIBBCDField * ElementID_SNAK_SKIDOK);

   virtual TFIBBCDField * get_ElementIDSKLAD_SNAK_SKIDOK(void);
   virtual void set_ElementIDSKLAD_SNAK_SKIDOK(TFIBBCDField * ElementIDSKLAD_SNAK_SKIDOK);

   virtual TFIBBCDField * get_ElementIDVID_SNAK_SKIDOK(void);
   virtual void set_ElementIDVID_SNAK_SKIDOK(TFIBBCDField * ElementIDVID_SNAK_SKIDOK);

   virtual TpFIBDataSet * get_TableNakSkidok(void);
   virtual void set_TableNakSkidok(TpFIBDataSet * TableNakSkidok);

   virtual TFIBBCDField * get_TableNakSkidokID_SNAK_SKIDOK(void);
   virtual void set_TableNakSkidokID_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokID_SNAK_SKIDOK);

   virtual TFIBBCDField * get_TableNakSkidokIDSKLAD_SNAK_SKIDOK(void);
   virtual void set_TableNakSkidokIDSKLAD_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokIDSKLAD_SNAK_SKIDOK);

   virtual TFIBBCDField * get_TableNakSkidokIDVID_SNAK_SKIDOK(void);
   virtual void set_TableNakSkidokIDVID_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokIDVID_SNAK_SKIDOK);

   virtual TFIBBCDField * get_TableNakSkidokSUM_SNAK_SKIDOK(void);
   virtual void set_TableNakSkidokSUM_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokSUM_SNAK_SKIDOK);

   virtual TFIBBCDField * get_TableNakSkidokPROCENT_SNAK_SKIDOK(void);
   virtual void set_TableNakSkidokPROCENT_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokPROCENT_SNAK_SKIDOK);

   virtual TFIBSmallIntField * get_TableNakSkidokPERIOD_SNAK_SKIDOK(void);
   virtual void set_TableNakSkidokPERIOD_SNAK_SKIDOK(TFIBSmallIntField * TableNakSkidokPERIOD_SNAK_SKIDOK);

   virtual TFIBWideStringField * get_TableGID_SNAK_SKIDOK(void);
   virtual void set_TableGID_SNAK_SKIDOK(TFIBWideStringField * TableGID_SNAK_SKIDOK);

   virtual TFIBWideStringField * get_TableNAMESKLAD(void);
   virtual void set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD);

   virtual TFIBWideStringField * get_TableNAME_SVID_DCARD(void);
   virtual void set_TableNAME_SVID_DCARD(TFIBWideStringField * TableNAME_SVID_DCARD);

   virtual TFIBWideStringField * get_ElementGID_SNAK_SKIDOK(void);
   virtual void set_ElementGID_SNAK_SKIDOK(TFIBWideStringField * ElementGID_SNAK_SKIDOK);

   virtual TFIBWideStringField * get_ElementNAMESKLAD(void);
   virtual void set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD);

   virtual TFIBWideStringField * get_ElementNAME_SVID_DCARD(void);
   virtual void set_ElementNAME_SVID_DCARD(TFIBWideStringField * ElementNAME_SVID_DCARD);

   virtual TFIBWideStringField * get_TableNakSkidokGID_SNAK_SKIDOK(void);
   virtual void set_TableNakSkidokGID_SNAK_SKIDOK(TFIBWideStringField * TableNakSkidokGID_SNAK_SKIDOK);

   virtual void OpenTable(void);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(void);
   virtual bool SaveElement(void);
   virtual void DeleteElement(__int64 id);
   virtual void GetSpisokSkidok(__int64 id_vid, __int64 id_sklad);
   virtual void OpenTableNakSkidok(__int64 id_vid,__int64 id_sklad);
};
#define CLSID_TDMSprNakSkidokImpl __uuidof(TDMSprNakSkidokImpl)
#endif
