//---------------------------------------------------------------------------

#ifndef UREM_DMZayavkaH
#define UREM_DMZayavkaH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
//---------------------------------------------------------------------------
class TREM_DMZayavka : public TDataModule
{
__published:	// IDE-managed Components
	TDataSource *DataSourceGurZKompl;
	TDataSource *DataSourceGurZNeispr;
	TDataSource *DataSourceGurZ;
	TpFIBDataSet *GurZ;
	TpFIBDataSet *GurZKompl;
	TpFIBDataSet *GurZNeispr;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *NumDoc;
	TIntegerField *GurZKomplRECNO;
	TIntegerField *GurZNeisprRECNO;
	TFIBLargeIntField *GurZID_REM_Z;
	TFIBWideStringField *GurZGID_REM_Z;
	TFIBWideStringField *GurZPREFIKS_REM_Z;
	TFIBIntegerField *GurZNUM_REM_Z;
	TFIBDateTimeField *GurZPOS_REM_Z;
	TFIBLargeIntField *GurZIDBASE_REM_Z;
	TFIBLargeIntField *GurZIDMODEL_REM_Z;
	TFIBLargeIntField *GurZIDSKLPR_REM_Z;
	TFIBLargeIntField *GurZIDKLIENT_REM_Z;
	TFIBLargeIntField *GurZIDDILER_REM_Z;
	TFIBWideStringField *GurZNAME_REM_Z;
	TFIBWideStringField *GurZDESCR_REM_Z;
	TFIBLargeIntField *GurZIDTYPEREM_REM_Z;
	TFIBLargeIntField *GurZIDSOST_REM_Z;
	TFIBLargeIntField *GurZIDTECSKL_REM_Z;
	TFIBLargeIntField *GurZIDUSER_REM_Z;
	TFIBIntegerField *GurZOPER_REM_Z;
	TFIBBCDField *GurZSUM_REM_Z;
	TFIBDateField *GurZSROK_REM_Z;
	TFIBSmallIntField *GurZOUT_REM_Z;
	TFIBLargeIntField *GurZIDFIRM_REM_Z;
	TFIBWideStringField *GurZNAMEFIRM;
	TFIBWideStringField *GurZNAME_SINFBASE_OBMEN;
	TFIBWideStringField *GurZNAME_REM_SMODEL;
	TFIBWideStringField *GurZNAME_SKLAD_PR;
	TFIBWideStringField *GurZNAMEKLIENT;
	TFIBWideStringField *GurZNAMEDILER;
	TFIBWideStringField *GurZNAME_STREMONT;
	TFIBWideStringField *GurZNAME_REMSSOST;
	TFIBWideStringField *GurZNAME_SKLAD_TEC;
	TFIBWideStringField *GurZNAME_USER;
	TFIBLargeIntField *GurZKomplID_REM_ZKOMPL;
	TFIBWideStringField *GurZKomplGID_REM_ZKOMPL;
	TFIBWideStringField *GurZKomplPREFIKS_REM_ZKOMPL;
	TFIBLargeIntField *GurZKomplIDZ_REM_ZKOMPL;
	TFIBLargeIntField *GurZKomplIDKOMPL_REM_ZKOMPL;
	TFIBBCDField *GurZKomplKOL_REM_ZKOMPL;
	TFIBLargeIntField *GurZKomplIDBASE_REM_ZKOMPL;
	TFIBWideStringField *GurZKomplNAME_REM_SKOMPLMODEL;
	TFIBLargeIntField *GurZNeisprID_REM_ZNEISPR;
	TFIBWideStringField *GurZNeisprGID_REM_ZNEISPR;
	TFIBWideStringField *GurZNeisprPREFIKS_REM_ZNEISPR;
	TFIBLargeIntField *GurZNeisprIDZ_REM_ZNEISPR;
	TFIBLargeIntField *GurZNeisprIDNEISPR_REM_ZNEISPR;
	TFIBLargeIntField *GurZNeisprIDBASE_REM_ZNEISPR;
	TFIBWideStringField *GurZNeisprNAME_REM_SNEISPR;
	TFIBWideStringField *GurZNEISPR_REM_Z;
	TFIBWideStringField *GurZKLIENT_NAME_REM_Z;
	TFIBWideStringField *GurZKLIENT_ADR_REM_Z;
	TFIBWideStringField *GurZKLIENT_PHONE_REM_Z;
	TFIBWideStringField *GurZKOMPLECT_REM_Z;
	TFIBWideStringField *GurZMODEL_REM_Z;
	TFIBWideStringField *GurZSOST_REM_Z;
	TFIBWideStringField *GurZSERNUM2_REM_Z;
	TFIBWideStringField *GurZSERNUM_REM_Z;
	TFIBWideStringField *GurZCOMENTS_REM_Z;
	TFIBDateTimeField *GurZPOSOUT_REM_Z;
	TFIBDateTimeField *GurZPOSREMONT_REM_Z;
	TFIBIntegerField *GurZWARRANTY_REM_Z;
	TpFIBDataSet *DopUsl;
	TDataSource *DataSourceDopUsl;
	TFIBLargeIntField *DopUslID_REM_ZDOPUSL;
	TFIBWideStringField *DopUslGID_REM_ZDOPUSL;
	TFIBLargeIntField *DopUslIDBASE_REM_ZDOPUSL;
	TFIBLargeIntField *DopUslIDZ_REM_ZDOPUSL;
	TFIBLargeIntField *DopUslIDNOM_REM_ZDOPUSL;
	TFIBLargeIntField *DopUslIDED_REM_ZDOPUSL;
	TFIBBCDField *DopUslKOL_REM_ZDOPUSL;
	TFIBBCDField *DopUslKF_REM_ZDOPUSL;
	TFIBBCDField *DopUslPRICE_REM_ZDOPUSL;
	TFIBBCDField *DopUslSUM_REM_ZDOPUSL;
	TFIBWideStringField *DopUslTEXTNOM_REM_ZDOPUSL;
	TFIBWideStringField *DopUslNAMENOM;
	TFIBWideStringField *DopUslNAMEED;
	TpFIBDataSet *PerformedWork;
	TDataSource *DataSourcePerformedWork;
	TFIBLargeIntField *PerformedWorkID_REM_ZPERFWORK;
	TFIBWideStringField *PerformedWorkGID_REM_ZPERFWORK;
	TFIBLargeIntField *PerformedWorkIDBASE_REM_ZPERFWORK;
	TFIBLargeIntField *PerformedWorkIDZ_REM_ZPERFWORK;
	TFIBLargeIntField *PerformedWorkIDNOM_REM_ZPERFWORK;
	TFIBLargeIntField *PerformedWorkIDED_REM_ZPERFWORK;
	TFIBBCDField *PerformedWorkKOL_REM_ZPERFWORK;
	TFIBBCDField *PerformedWorkKF_REM_ZPERFWORK;
	TFIBBCDField *PerformedWorkPRICE_REM_ZPERFWORK;
	TFIBBCDField *PerformedWorkSUM_REM_ZPERFWORK;
	TFIBWideStringField *PerformedWorkTEXTNOM_REM_ZPERFWORK;
	TFIBDateTimeField *PerformedWorkPOS_REM_ZPERFWORK;
	TFIBSmallIntField *PerformedWorkRESULT_REM_ZPERFWORK;
	TFIBSmallIntField *PerformedWorkADDACT_REM_ZPERFWORK;
	TFIBSmallIntField *PerformedWorkSHOWFORUSER_REM_ZPERFWORK;
	TFIBWideStringField *PerformedWorkNAMENOM;
	TFIBWideStringField *PerformedWorkNAMEED;
	TFIBLargeIntField *PerformedWorkIDUSER_REM_ZPERFWORK;
	TFIBWideStringField *PerformedWorkNAME_USER;
	TFIBLargeIntField *GurZIDMEXANIK_REM_Z;
	TFIBLargeIntField *GurZIDBRAND_REM_Z;
	TFIBLargeIntField *GurZIDACTCAT_REM_Z;
	TFIBWideStringField *GurZGUID_REM_Z;
	TFIBLargeIntField *GurZIDZOSN_REM_Z;
	TFIBSmallIntField *GurZFL_POVTOR_REM_Z;
	TFIBWideStringField *GurZDILER_NUMZ_REM_Z;
	TFIBDateTimeField *GurZDILER_POSZ_REM_Z;
	TFIBWideStringField *GurZDILER_GUIDZ_REM_Z;
	TFIBWideStringField *GurZSC_NUMZ_REM_Z;
	TFIBDateTimeField *GurZSC_POSZ_REM_Z;
	TFIBWideStringField *GurZSC_GUIDZ_REM_Z;
	TFIBSmallIntField *GurZFL_ADDREPORT_REM_Z;
	TFIBWideStringField *GurZSERNUM_STR_REM_Z;
	TFIBWideStringField *GurZNAME_MEXANIK;
	TFIBWideStringField *GurZNAME_SBRAND;
	TFIBWideStringField *GurZNAME_REM_SACTCATEGORY;
	TFIBLargeIntField *GurZIDHW_REM_Z;
	TFIBLargeIntField *GurZIDKKT_REM_Z;
	TFIBWideStringField *GurZNAME_REM_SHARDWARE;
	TFIBWideStringField *GurZSERNUM_REM_SHARDWARE;
	TFIBWideStringField *GurZSERNUM2_REM_SHARDWARE;
	TFIBWideStringField *GurZNAME_REM_SKKT;
	TFIBWideStringField *GurZSERNUM_REM_SKKT;
	TFIBIntegerField *GurZFL_KLIENT_UVEDOML_REM_Z;
	TFIBIntegerField *GurZFL_TREB_KONS_KL_REM_Z;
	TFIBIntegerField *GurZFL_KL_OTV_NA_ZAPROS_REM_Z;
	TFIBWideStringField *GurZPREFIKS_NUM_REM_Z;
	TFIBWideStringField *GurZNUM_GARDOC_REM_Z;
	TFIBIntegerField *GurZFL_FICTIV_REM_Z;
	TFIBSmallIntField *GurZFL_NE_OTCH_REM_Z;
	TFIBSmallIntField *GurZFL_NADO_OTCH_REM_Z;
	TFIBSmallIntField *GurZFL_ISM_GARDOC_REM_Z;
	TFIBSmallIntField *GurZFL_ISM_SERNUM_REM_Z;
	TFIBSmallIntField *GurZFL_ISM_SERNUM2_REM_Z;
	TFIBWideStringField *GurZNUM_GARDOC_NEW_REM_Z;
	TFIBWideStringField *GurZSERNUM_NEW_REM_Z;
	TFIBWideStringField *GurZSERNUM2_NEW_REM_Z;
	TFIBSmallIntField *GurZGOTOVO_K_VIDACHE_REM_Z;
	TDataSource *DataSourceGurZ_1;
	TpFIBDataSet *GurZ_1;
	TFIBLargeIntField *GurZ_1ID_REM_Z_1;
	TFIBLargeIntField *GurZ_1IDBASE_REM_Z_1;
	TFIBLargeIntField *GurZ_1IDZ_REM_Z_1;
	TFIBLargeIntField *GurZ_1IDPRMODEL_REM_Z_1;
	TFIBLargeIntField *GurZ_1IDPRODUCER_REM_Z_1;
	TFIBIntegerField *GurZ_1FL_VKL_REM_Z_1;
	TFIBIntegerField *GurZ_1FL_ZIP_REM_Z_1;
	TFIBIntegerField *GurZ_1FL_DEFECT_DEMO_REM_Z_1;
	TFIBIntegerField *GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1;
	TFIBLargeIntField *GurZ_1IDSELLER_REM_Z_1;
	TFIBWideStringField *GurZ_1KLIENT_EMAIL_REM_Z_1;
	TFIBWideStringField *GurZ_1KLIENT_DOP_INFO_REM_Z_1;
	TFIBLargeIntField *GurZ_1IDADRKV_REM_Z_1;
	TFIBWideStringField *GurZ_1NAME_SPRODUCER;
	TFIBWideStringField *GurZ_1NAME_REM_SPRMODEL;
	TFIBWideStringField *GurZ_1NAME_SSELLER;
	TFIBWideStringField *GurZ_1NAME_SADR_DOM;
	TFIBWideStringField *GurZ_1NAME_SADR_STREET;
	TFIBWideStringField *GurZ_1POSTCODE_SADR_STREET;
	TFIBWideStringField *GurZ_1NAME_SADR_NASPUNKT;
	TFIBWideStringField *GurZ_1NAME_SADR_REGION;
	TFIBWideStringField *GurZ_1CODE_SADR_REGION;
	TFIBWideStringField *GurZ_1NAME_SADR_KV;
	TFIBIntegerField *GurZ_1FL_PLOMBA_SET_REM_Z_1;
	TFIBWideStringField *GurZ_1TEXT_PLOMBA_REM_Z_1;
	TFIBIntegerField *GurZ_1FL_PROBLEM_DEVICE_REM_Z_1;
	TFIBIntegerField *GurZ_1FL_PROBLEM_KLIENT_REM_Z_1;
	TFIBWideStringField *GurZ_1NEISPR_ENG_REM_Z_1;
	TFIBWideStringField *GurZ_1DEFECT_ENG_REM_Z_1;
	TFIBWideStringField *GurZ_1SOLUTION_ENG_REM_Z_1;
	TFIBWideStringField *GurZ_1STR_CODE_VIGR_REM_Z_1;
	TFIBWideStringField *GurZ_1NAME_SADR_STROEN;
	TFIBWideStringField *GurZ_1NAME_SADR_RAYON;
	TFIBIntegerField *GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1;
	TFIBWideStringField *GurZNeisprNAME_ENG_REM_SNEISPR;
	TFIBWideStringField *GurZNeisprNAME_REM_SGRPNEISPR;
	TFIBWideStringField *GurZNeisprNAME_ENG_REM_SGRPNEISPR;
	TFIBWideStringField *GurZ_1FAMILIYA_REM_Z_1;
	TFIBWideStringField *GurZ_1IMYA_REM_Z_1;
	TFIBWideStringField *GurZ_1OTCHESTVO_REM_Z_1;
	TFIBDateField *GurZ_1DATE_VIPUSK_REM_Z_1;
	TFIBDateField *GurZ_1DATE_PRODAGI_REM_Z_1;
	TFIBWideStringField *GurZ_1PODO_REM_Z_1;
	TFIBWideStringField *GurZ_1POPOSLE_REM_Z_1;
	TFIBLargeIntField *GurZ_1IDPRNEISPR_REM_Z_1;
	TFIBWideStringField *GurZ_1PARTNUM_REM_Z_1;
	TFIBWideStringField *GurZ_1REFERENCE_REM_Z_1;
	TFIBWideStringField *GurZ_1SWCODE_REM_Z_1;
	TFIBWideStringField *GurZ_1HWCODE_REM_Z_1;
	TFIBIntegerField *GurZ_1KEMSDANO_REM_Z_1;
	TFIBDateTimeField *GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1;
	TFIBWideStringField *GurZ_1SERNUM3_REM_Z_1;
	TFIBWideStringField *GurZ_1SERNUM4_REM_Z_1;
	TFIBWideStringField *GurZ_1NUMBAT_REM_Z_1;
	TFIBWideStringField *GurZ_1NAME_REM_SPRNEISPR;
	TFIBWideStringField *GurZ_1NAME_ENG_REM_SPRNEISPR;
	TFIBWideStringField *GurZ_1CODE_REM_SPRNEISPR;
	TFIBWideStringField *GurZ_1NAME_REM_SPRNEISPR_GRP;
	TFIBWideStringField *GurZ_1NAME_ENG_REM_SPRNEISPR_GRP;
	TFIBSmallIntField *GurZ_1FL_ISM_SERNUM3_REM_Z_1;
	TFIBWideStringField *GurZ_1SERNUM3_NEW_REM_Z_1;
	TFIBSmallIntField *GurZ_1FL_ISM_SERNUM4_REM_Z_1;
	TFIBWideStringField *GurZ_1SERNUM4_NEW_REM_Z_1;
	TFIBWideStringField *GurZ_1FL_ISM_REFERENCE_REM_Z_1;
	TFIBWideStringField *GurZ_1REFERENCE_NEW_REM_Z_1;
	TFIBSmallIntField *GurZ_1FL_ISM_HWCODE_REM_Z_1;
	TFIBWideStringField *GurZ_1HWCODE_NEW_REM_Z_1;
	TFIBSmallIntField *GurZ_1FL_ISM_SWCODE_REM_Z_1;
	TFIBWideStringField *GurZ_1SWCODE_NEW_REM_Z_1;
	TFIBSmallIntField *GurZ_1FL_ISM_PARTNUM_REM_Z_1;
	TFIBWideStringField *GurZ_1PARTNUM_NEW_REM_Z_1;
	TDataSource *DataSourcePrNeispr;
	TpFIBDataSet *GurZPrNeispr;
	TFIBLargeIntField *GurZPrNeisprID_REM_ZPRNEISPR;
	TFIBLargeIntField *GurZPrNeisprIDBASE_REM_ZPRNEISPR;
	TFIBWideStringField *GurZPrNeisprGID_REM_ZPRNEISPR;
	TFIBLargeIntField *GurZPrNeisprIDPRCOND_REM_ZPRNEISPR;
	TFIBLargeIntField *GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR;
	TFIBLargeIntField *GurZPrNeisprIDZ_REM_ZPRNEISPR;
	TFIBWideStringField *GurZPrNeisprNAME_REM_SPRNEISPR;
	TFIBWideStringField *GurZPrNeisprCODE_REM_SPRNEISPR;
	TFIBWideStringField *GurZPrNeisprNAME_ENG_REM_SPRNEISPR;
	TFIBWideStringField *GurZPrNeisprNAME_REM_SPRNEISPR_GRP;
	TFIBWideStringField *GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP;
	TFIBWideStringField *GurZPrNeisprCODE_REM_SPRCONDITION;
	TFIBWideStringField *GurZPrNeisprNAME_REM_SPRCONDITION;
	TFIBWideStringField *GurZPrNeisprNAME_ENG_REM_SPRCONDITION;
	TFIBWideStringField *GurZPrNeisprCODE_REM_SPRCOND_GRP;
	TFIBWideStringField *GurZPrNeisprNAME_REM_SPRCOND_GRP;
	TFIBWideStringField *GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP;
	TIntegerField *GurZPrNeisprRECNO;
	TFIBBCDField *GurZ_1PREDOPLATA_REM_Z_1;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall GurZPOS_REM_ZChange(TField *Sender);
	void __fastcall GurZKomplNewRecord(TDataSet *DataSet);
	void __fastcall GurZNeisprNewRecord(TDataSet *DataSet);
	void __fastcall GurZKomplCalcFields(TDataSet *DataSet);
	void __fastcall GurZNeisprCalcFields(TDataSet *DataSet);
	void __fastcall GurZIDTYPEREM_REM_ZChange(TField *Sender);
	void __fastcall GurZIDSOST_REM_ZChange(TField *Sender);
	void __fastcall GurZIDTECSKL_REM_ZChange(TField *Sender);
	void __fastcall GurZSUM_REM_ZChange(TField *Sender);
	void __fastcall GurZSROK_REM_ZChange(TField *Sender);
	void __fastcall GurZOUT_REM_ZChange(TField *Sender);
	void __fastcall DopUslNewRecord(TDataSet *DataSet);
	void __fastcall DopUslKOL_REM_ZDOPUSLChange(TField *Sender);
	void __fastcall DopUslPRICE_REM_ZDOPUSLChange(TField *Sender);
	void __fastcall PerformedWorkNewRecord(TDataSet *DataSet);
	void __fastcall PerformedWorkKOL_REM_ZPERFWORKChange(TField *Sender);
	void __fastcall PerformedWorkPRICE_REM_ZPERFWORKChange(TField *Sender);
	void __fastcall GurZIDBASE_REM_ZChange(TField *Sender);
	void __fastcall GurZIDFIRM_REM_ZChange(TField *Sender);
	void __fastcall GurZIDSKLPR_REM_ZChange(TField *Sender);
	void __fastcall GurZ_1NewRecord(TDataSet *DataSet);
	void __fastcall GurZPrNeisprCalcFields(TDataSet *DataSet);
	void __fastcall GurZPrNeisprNewRecord(TDataSet *DataSet);
private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


   int GetNumberNewDoc(void);
		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TREM_DMZayavka(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);



		//Текущий интерфейс
		void NewDoc(void);
		void OpenDoc(__int64 id);
        bool SaveDoc(void);
		bool DeleteDoc(__int64 id);
        void CloseDoc(void); 

		bool Prosmotr;    //только просмотр
		__int64 IdZ;           //идентификатор текущей записи

		void AddNewRecordDv(void);

		bool flChangeData;

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMZayavka *REM_DMZayavka;
//---------------------------------------------------------------------------
#endif
