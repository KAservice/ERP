#ifndef UDMSprKlientImplH
#define UDMSprKlientImplH
#include "IDMSprKlient.h"
#include "UDMSprKlient.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TDMSprKlientImpl)) TDMSprKlientImpl : public IDMSprKlient
{
public:
   TDMSprKlientImpl();
   ~TDMSprKlientImpl();
   TDMSprKlient * Object;
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

//IDMSprKlient
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

   virtual TFIBBCDField * get_TableIDKLIENT(void);
   virtual void set_TableIDKLIENT(TFIBBCDField * TableIDKLIENT);

   virtual TFIBBCDField * get_TableIDGRPKLIENT(void);
   virtual void set_TableIDGRPKLIENT(TFIBBCDField * TableIDGRPKLIENT);

   virtual TFIBBCDField * get_ElementIDKLIENT(void);
   virtual void set_ElementIDKLIENT(TFIBBCDField * ElementIDKLIENT);

   virtual TFIBBCDField * get_ElementIDTPRICEKLIENT(void);
   virtual void set_ElementIDTPRICEKLIENT(TFIBBCDField * ElementIDTPRICEKLIENT);

   virtual TFIBBCDField * get_ElementIDGRPKLIENT(void);
   virtual void set_ElementIDGRPKLIENT(TFIBBCDField * ElementIDGRPKLIENT);

   virtual TFIBBCDField * get_ElementIDVIDKLIENT(void);
   virtual void set_ElementIDVIDKLIENT(TFIBBCDField * ElementIDVIDKLIENT);

   virtual TFIBBCDField * get_ElementIDCOUNTRYKLIENT(void);
   virtual void set_ElementIDCOUNTRYKLIENT(TFIBBCDField * ElementIDCOUNTRYKLIENT);

   virtual TpFIBQuery * get_pFIBQ(void);
   virtual void set_pFIBQ(TpFIBQuery * pFIBQ);

   virtual TFIBBCDField * get_ElementMAXCREDIT_SKLIENT(void);
   virtual void set_ElementMAXCREDIT_SKLIENT(TFIBBCDField * ElementMAXCREDIT_SKLIENT);

   virtual TFIBWideStringField * get_TableNAMEKLIENT(void);
   virtual void set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT);

   virtual TFIBWideStringField * get_TableINNKLIENT(void);
   virtual void set_TableINNKLIENT(TFIBWideStringField * TableINNKLIENT);

   virtual TFIBWideStringField * get_TableTELKLIENT(void);
   virtual void set_TableTELKLIENT(TFIBWideStringField * TableTELKLIENT);

   virtual TFIBWideStringField * get_TableADRKLIENT(void);
   virtual void set_TableADRKLIENT(TFIBWideStringField * TableADRKLIENT);

   virtual TFIBWideStringField * get_ElementNAMEKLIENT(void);
   virtual void set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT);

   virtual TFIBWideStringField * get_ElementFNAME(void);
   virtual void set_ElementFNAME(TFIBWideStringField * ElementFNAME);

   virtual TFIBWideStringField * get_ElementADRKLIENT(void);
   virtual void set_ElementADRKLIENT(TFIBWideStringField * ElementADRKLIENT);

   virtual TFIBWideStringField * get_ElementTELKLIENT(void);
   virtual void set_ElementTELKLIENT(TFIBWideStringField * ElementTELKLIENT);

   virtual TFIBWideStringField * get_ElementINNKLIENT(void);
   virtual void set_ElementINNKLIENT(TFIBWideStringField * ElementINNKLIENT);

   virtual TFIBWideStringField * get_ElementKPPKLIENT(void);
   virtual void set_ElementKPPKLIENT(TFIBWideStringField * ElementKPPKLIENT);

   virtual TFIBIntegerField * get_ElementTKLIENT(void);
   virtual void set_ElementTKLIENT(TFIBIntegerField * ElementTKLIENT);

   virtual TFIBWideStringField * get_ElementGID_SKLIENT(void);
   virtual void set_ElementGID_SKLIENT(TFIBWideStringField * ElementGID_SKLIENT);

   virtual TFIBWideStringField * get_ElementOKPOKLIENT(void);
   virtual void set_ElementOKPOKLIENT(TFIBWideStringField * ElementOKPOKLIENT);

   virtual TFIBBCDField * get_ElementIDBASE_SKLIENT(void);
   virtual void set_ElementIDBASE_SKLIENT(TFIBBCDField * ElementIDBASE_SKLIENT);

   virtual TFIBWideStringField * get_ElementKRNAME_SKLIENT(void);
   virtual void set_ElementKRNAME_SKLIENT(TFIBWideStringField * ElementKRNAME_SKLIENT);

   virtual TFIBWideStringField * get_ElementDESCR_SKLIENT(void);
   virtual void set_ElementDESCR_SKLIENT(TFIBWideStringField * ElementDESCR_SKLIENT);

   virtual TFIBWideStringField * get_ElementMESSAGE_SKLIENT(void);
   virtual void set_ElementMESSAGE_SKLIENT(TFIBWideStringField * ElementMESSAGE_SKLIENT);

   virtual TFIBWideStringField * get_ElementEMAIL_SKLIENT(void);
   virtual void set_ElementEMAIL_SKLIENT(TFIBWideStringField * ElementEMAIL_SKLIENT);

   virtual TFIBWideStringField * get_ElementWWW_SKLIENT(void);
   virtual void set_ElementWWW_SKLIENT(TFIBWideStringField * ElementWWW_SKLIENT);

   virtual TFIBWideStringField * get_ElementNAME_SVIDKLIENT(void);
   virtual void set_ElementNAME_SVIDKLIENT(TFIBWideStringField * ElementNAME_SVIDKLIENT);

   virtual TFIBWideStringField * get_ElementNAME_SCOUNTRY(void);
   virtual void set_ElementNAME_SCOUNTRY(TFIBWideStringField * ElementNAME_SCOUNTRY);

   virtual TFIBWideStringField * get_ElementYUR_ADRESS_SKLIENT(void);
   virtual void set_ElementYUR_ADRESS_SKLIENT(TFIBWideStringField * ElementYUR_ADRESS_SKLIENT);

   virtual TFIBWideStringField * get_ElementPOCHT_ADRRESS_SKLIENT(void);
   virtual void set_ElementPOCHT_ADRRESS_SKLIENT(TFIBWideStringField * ElementPOCHT_ADRRESS_SKLIENT);

   virtual TFIBWideStringField * get_ElementFAMILIYA_SKLIENT(void);
   virtual void set_ElementFAMILIYA_SKLIENT(TFIBWideStringField * ElementFAMILIYA_SKLIENT);

   virtual TFIBWideStringField * get_ElementIMYA_SKLIENT(void);
   virtual void set_ElementIMYA_SKLIENT(TFIBWideStringField * ElementIMYA_SKLIENT);

   virtual TFIBWideStringField * get_ElementOTCHESTVO_SKLIENT(void);
   virtual void set_ElementOTCHESTVO_SKLIENT(TFIBWideStringField * ElementOTCHESTVO_SKLIENT);

   virtual TFIBIntegerField * get_ElementTYPE_POISK_SKLIENT(void);
   virtual void set_ElementTYPE_POISK_SKLIENT(TFIBIntegerField * ElementTYPE_POISK_SKLIENT);

   virtual TFIBBCDField * get_ElementIDGRPNOM_SKLIENT(void);
   virtual void set_ElementIDGRPNOM_SKLIENT(TFIBBCDField * ElementIDGRPNOM_SKLIENT);

   virtual TFIBBCDField * get_ElementIDGRPHW_SKLIENT(void);
   virtual void set_ElementIDGRPHW_SKLIENT(TFIBBCDField * ElementIDGRPHW_SKLIENT);

   virtual TFIBWideStringField * get_ElementNAMEGN(void);
   virtual void set_ElementNAMEGN(TFIBWideStringField * ElementNAMEGN);

   virtual TFIBWideStringField * get_ElementNAME_REM_SGRP_HARDWARE(void);
   virtual void set_ElementNAME_REM_SGRP_HARDWARE(TFIBWideStringField * ElementNAME_REM_SGRP_HARDWARE);

   virtual __int64 get_Id(void);
   virtual void set_Id(__int64 Id);

   virtual __int64 get_IdGroup(void);
   virtual void set_IdGroup(__int64 IdGroup);

   virtual bool get_AllElement(void);
   virtual void set_AllElement(bool AllElement);

   virtual bool get_elSave(void);
   virtual void set_elSave(bool elSave);

   virtual bool OpenTable(__int64 id_grp, bool all);
   virtual int OpenElement(__int64 id);
   virtual void NewElement(__int64 id_grp);
   virtual bool SaveElement(void);
   virtual bool DeleteElement(__int64 id);
   virtual void ChancheGrp(__int64 new_grp);
   virtual __int64 FindPoName(String Name);
   virtual __int64 GetIDKlientPoName(AnsiString name);
   virtual __int64 GetIdGrpKlient(__int64 id_klient);
};
#define CLSID_TDMSprKlientImpl __uuidof(TDMSprKlientImpl)
#endif
