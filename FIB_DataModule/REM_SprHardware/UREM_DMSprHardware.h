
#ifndef UREM_DMSprHardwareH
#define UREM_DMSprHardwareH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


//----------------------------------------------------------------------------


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
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TREM_DMSprHardware : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_REM_SHARDWARE;
	TFIBWideStringField *TableNAME_REM_SHARDWARE;
	TFIBWideStringField *TableSERNUM_REM_SHARDWARE;
	TFIBIntegerField *TableCODE_REM_SHARDWARE;
	TFIBIntegerField *TableSROKWARRANTY_REM_SHARDWARE;
	TFIBWideStringField *TableSERNUM2_REM_SHARDWARE;
	TFIBWideStringField *TableSERNUM_STR_REM_SHARDWARE;
	TFIBSmallIntField *TableFL_NECOND_REM_SHARDWARE;
	TFIBBCDField *TablePRICE_REM_SHARDWARE;
	TFIBSmallIntField *TableFL_FICT_REMONT_REM_SHARDWARE;
	TFIBSmallIntField *TableFL_REMONT_REM_SHARDWARE;
	TFIBSmallIntField *TableFL_ACT_REM_SHARDWARE;
	TFIBLargeIntField *ElementID_REM_SHARDWARE;
	TFIBLargeIntField *ElementIDBASE_REM_SHARDWARE;
	TFIBWideStringField *ElementNAME_REM_SHARDWARE;
	TFIBLargeIntField *ElementIDGRP_REM_SHARDWARE;
	TFIBLargeIntField *ElementIDMODEL_REM_SHARDWARE;
	TFIBLargeIntField *ElementIDPOST_REM_SHARDWARE;
	TFIBSmallIntField *ElementTYPESYSPOST_REM_SHARDWARE;
	TFIBLargeIntField *ElementIDDOCPOST_REM_SHARDWARE;
	TFIBWideStringField *ElementSERNUM_REM_SHARDWARE;
	TFIBDateField *ElementWARRANTY_REM_SHARDWARE;
	TFIBDateField *ElementSALE_REM_SHARDWARE;
	TFIBLargeIntField *ElementIDVLAD_REM_SHARDWARE;
	TFIBWideStringField *ElementNAMEVLAD_REM_SHARDWARE;
	TFIBSmallIntField *ElementTYPESYSSALE_REM_SHARDWARE;
	TFIBLargeIntField *ElementIDDOCSALE_REM_SHARDWARE;
	TFIBIntegerField *ElementCODE_REM_SHARDWARE;
	TFIBIntegerField *ElementSROKWARRANTY_REM_SHARDWARE;
	TFIBLargeIntField *ElementIDDOCREM_SALE_REM_SHARDWARE;
	TFIBWideStringField *ElementSERNUM2_REM_SHARDWARE;
	TFIBWideStringField *ElementSERNUM_STR_REM_SHARDWARE;
	TFIBSmallIntField *ElementFL_NECOND_REM_SHARDWARE;
	TFIBBCDField *ElementPRICE_REM_SHARDWARE;
	TFIBWideStringField *ElementPRICHINA_REM_SHARDWARE;
	TFIBWideStringField *ElementPRIM_REM_SHARDWARE;
	TFIBSmallIntField *ElementFL_FICT_REMONT_REM_SHARDWARE;
	TFIBSmallIntField *ElementFL_REMONT_REM_SHARDWARE;
	TFIBLargeIntField *ElementIDPRODUCER_REM_SHARDWARE;
	TFIBLargeIntField *ElementIDBRAND_REM_SHARDWARE;
	TFIBLargeIntField *ElementIDZ_REM_SHARDWARE;
	TFIBIntegerField *ElementTYPE_ELEMENTA_REM_SHARDWARE;
	TFIBSmallIntField *ElementFL_ACT_REM_SHARDWARE;
	TFIBSmallIntField *ElementFL_UTILIZ_REM_SHARDWARE;
	TFIBDateTimeField *ElementPOS_POST_REM_SHARDWARE;
	TFIBDateTimeField *ElementPOS_UTILIZ_REM_SHARDWARE;
	TFIBDateTimeField *ElementPOS_HRAN_DO_REM_SHARDWARE;
	TFIBLargeIntField *ElementIDPRMODEL_REM_SHARDWARE;
	TFIBWideStringField *ElementNAME_REM_SMODEL;
	TFIBWideStringField *ElementSUPPLIER_NAME;
	TFIBWideStringField *ElementOWNER_NAME;
	TFIBWideStringField *ElementTDOC_DOCPOST;
	TFIBDateTimeField *ElementPOSDOC_DOCPOST;
	TFIBIntegerField *ElementNUMDOC_DOCPOST;
	TFIBWideStringField *ElementTDOC_DOCSALE;
	TFIBDateTimeField *ElementPOSDOC_DOCSALE;
	TFIBIntegerField *ElementNUMDOC_DOCSALE;
	TFIBWideStringField *ElementNAME_SBRAND;
	TFIBWideStringField *ElementNAME_SPRODUCER;
	TFIBWideStringField *ElementNAME_REM_Z;
	TFIBWideStringField *ElementPREFIKS_NUM_REM_Z;
	TFIBDateTimeField *ElementPOS_REM_Z;
	TFIBIntegerField *ElementNUM_REM_Z;
	TFIBWideStringField *ElementMODEL_REM_Z;
	TFIBWideStringField *ElementSERNUM_REM_Z;
	TFIBWideStringField *ElementNAME_REM_SPRMODEL;
	TFIBWideStringField *TableNAME_ENG_REM_SHARDWARE;
	TFIBWideStringField *TableARTIKUL_REM_SHARDWARE;
	TFIBWideStringField *TablePARTNUM_REM_SHARDWARE;
	TFIBWideStringField *ElementSERNUM3_REM_SHARDWARE;
	TFIBWideStringField *ElementSERNUM4_REM_SHARDWARE;
	TFIBWideStringField *ElementNUMBAT_REM_SHARDWARE;
	TFIBWideStringField *ElementNUMGARTALON_REM_SHARDWARE;
	TFIBWideStringField *ElementSWCODE_REM_SHARDWARE;
	TFIBWideStringField *ElementHWCODE_REM_SHARDWARE;
	TFIBWideStringField *ElementVERPO_REM_SHARDWARE;
	TFIBWideStringField *ElementPARTNUM_REM_SHARDWARE;
	TFIBWideStringField *ElementMTM_REM_SHARDWARE;
	TFIBWideStringField *ElementFRU_REM_SHARDWARE;
	TFIBWideStringField *ElementNAME_ENG_REM_SHARDWARE;
	TFIBWideStringField *ElementCRU_REM_SHARDWARE;
	TFIBWideStringField *ElementARTIKUL_REM_SHARDWARE;
	TFIBLargeIntField *TableOUT_IDFIRM;
	TFIBWideStringField *TableOUT_NAME_FIRM;
	TFIBLargeIntField *TableOUT_IDSKLAD;
	TFIBWideStringField *TableOUT_NAME_SKLAD;
	TFIBLargeIntField *TableOUT_IDTNOM;
	TFIBWideStringField *TableOUT_NAME_TYPE_NOM;
	TFIBBCDField *TableOUT_OST;
	TFIBLargeIntField *TableIDGRP_REM_SHARDWARE;
	TFIBLargeIntField *TableOUT_IDMHRAN;
	TFIBWideStringField *TableOUT_NAME_MHRAN;
	TFIBSmallIntField *TableOUT_FL_OTCH_PROIZV;
	TFIBSmallIntField *TableOUT_FL_NO_RAZBOR;
	TFIBSmallIntField *ElementFL_OTCH_PROIZV_REM_SHARDWARE;
	TFIBSmallIntField *ElementFL_NO_RAZBOR_REM_SHARDWARE;
		void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementTDOC_DOCPOSTGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall ElementTDOC_DOCSALEGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


		int GetCodeNom(void);
		bool CheckCode(__int64 id_hw, int code);

        bool flCentralBase;
public:		// User declarations
		__fastcall TREM_DMSprHardware(TComponent* Owner);

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

		void OpenTable(__int64 id_grp, bool all);
		UnicodeString GetTextQuery(__int64 id_grp, bool all);
		int OpenElement(__int64 id);
		bool NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void ChancheGrp(__int64 new_id_grp, __int64 id_el);

		//поиск
		__int64 FindPoName(UnicodeString name);

		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;


		__int64 GetIdGrpElementa(__int64 id_element);
		__int64 GetIdPoCodu(int code);

		//поиск по заводскому номеру
		bool Table_FindPoSerNum1Like(__int64 id_grp, bool all, UnicodeString ser_num);
		//поиск по заводскому номеру2
		bool Table_FindPoSerNum2Like(__int64 id_grp, bool all, UnicodeString ser_num);
		//поиск по заводскому номеру строка
        bool Table_FindPoSerNumStrLike(__int64 id_grp, bool all, UnicodeString ser_num);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprHardware *REM_DMSprHardware;
//---------------------------------------------------------------------------
#endif
