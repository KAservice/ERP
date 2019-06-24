#ifndef UDMSprGrpNomImplH
#define UDMSprGrpNomImplH
#include "IDMSprGrpNom.h"
#include "UDMSprGrpNom.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprGrpNomImpl)) TDMSprGrpNomImpl : public IDMSprGrpNom
{
public:
   TDMSprGrpNomImpl();
   ~TDMSprGrpNomImpl();
   TDMSprGrpNom * Object;
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

//IDMSprGrpNom
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

   virtual TFIBBCDField * get_TableIDGN(void);
   virtual void set_TableIDGN(TFIBBCDField * TableIDGN);

   virtual TFIBBCDField * get_TableIDGRPGN(void);
   virtual void set_TableIDGRPGN(TFIBBCDField * TableIDGRPGN);

   virtual TFIBBCDField * get_ElementIDGN(void);
   virtual void set_ElementIDGN(TFIBBCDField * ElementIDGN);

   virtual TFIBBCDField * get_ElementIDGRPGN(void);
   virtual void set_ElementIDGRPGN(TFIBBCDField * ElementIDGRPGN);

   virtual TFIBWideStringField * get_TableNAMEGN(void);
   virtual void set_TableNAMEGN(TFIBWideStringField * TableNAMEGN);

   virtual TFIBWideStringField * get_TableGID_SGRPNOM(void);
   virtual void set_TableGID_SGRPNOM(TFIBWideStringField * TableGID_SGRPNOM);

   virtual TFIBWideStringField * get_ElementNAMEGN(void);
   virtual void set_ElementNAMEGN(TFIBWideStringField * ElementNAMEGN);

   virtual TFIBWideStringField * get_ElementGID_SGRPNOM(void);
   virtual void set_ElementGID_SGRPNOM(TFIBWideStringField * ElementGID_SGRPNOM);

   virtual TFIBBCDField * get_ElementIDVIDIMAGENABOR_SGRPNOM(void);
   virtual void set_ElementIDVIDIMAGENABOR_SGRPNOM(TFIBBCDField * ElementIDVIDIMAGENABOR_SGRPNOM);

   virtual TFIBBCDField * get_ElementIDPROPNABOR_SGRPNOM(void);
   virtual void set_ElementIDPROPNABOR_SGRPNOM(TFIBBCDField * ElementIDPROPNABOR_SGRPNOM);

   virtual TFIBWideStringField * get_ElementNAME_SPROPNABOR(void);
   virtual void set_ElementNAME_SPROPNABOR(TFIBWideStringField * ElementNAME_SPROPNABOR);

   virtual TFIBWideStringField * get_ElementNAME_SVIDIMAGE_NABOR(void);
   virtual void set_ElementNAME_SVIDIMAGE_NABOR(TFIBWideStringField * ElementNAME_SVIDIMAGE_NABOR);


   virtual void OpenTable(void);
   virtual int OpenElement(__int64 Id);
   virtual void NewElement(__int64 IdGrp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 Id);
   virtual __int64 GetIDElement(String gid);
   virtual AnsiString GetGIDElement(__int64 id);
   virtual __int64 FindPoName(AnsiString name);
};
#define CLSID_TDMSprGrpNomImpl __uuidof(TDMSprGrpNomImpl)
#endif
