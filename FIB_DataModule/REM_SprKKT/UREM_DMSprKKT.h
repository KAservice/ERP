//---------------------------------------------------------------------------

#ifndef UREM_DMSprKKTH
#define UREM_DMSprKKTH
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
class TREM_DMSprKKT : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_REM_SKKT;
	TFIBWideStringField *TableNAME_REM_SKKT;
	TFIBWideStringField *TableSERNUM_REM_SKKT;
	TFIBWideStringField *TableNAME_REM_SMODEL;
	TFIBWideStringField *TableMESTOUST_REM_SKKT;
	TFIBLargeIntField *TableIDGRP_REM_SKKT;
	TFIBLargeIntField *ElementID_REM_SKKT;
	TFIBLargeIntField *ElementIDBASE_REM_SKKT;
	TFIBWideStringField *ElementNAME_REM_SKKT;
	TFIBWideStringField *ElementSERNUM_REM_SKKT;
	TFIBLargeIntField *ElementIDMODEL_REM_SKKT;
	TFIBWideStringField *ElementREGNUM_REM_SKKT;
	TFIBLargeIntField *ElementIDKLIENT_REM_SKKT;
	TFIBWideStringField *ElementMESTOUST_REM_SKKT;
	TFIBDateField *ElementRELEASE_REM_SKKT;
	TFIBDateField *ElementVVOD_REM_SKKT;
	TFIBWideStringField *ElementCBKGR_REM_SKKT;
	TFIBWideStringField *ElementCBKCO_REM_SKKT;
	TFIBWideStringField *ElementNUMCONTRACT_REM_SKKT;
	TFIBDateField *ElementDATECONTRACT_REM_SKKT;
	TFIBBCDField *ElementSUMCONTRACT_REM_SKKT;
	TFIBWideStringField *ElementEKLZ_SERNUM_REM_SKKT;
	TFIBWideStringField *ElementEKLZ_REGNUM_REM_SKKT;
	TFIBDateField *ElementEKLZ_ACT_REM_SKKT;
	TFIBWideStringField *ElementPAS_NUMVER_REM_SKKT;
	TFIBWideStringField *ElementPAS_NUMPAS_REM_SKKT;
	TFIBWideStringField *ElementPAS_NUMPU_REM_SKKT;
	TFIBWideStringField *ElementPAS_NUMSP_REM_SKKT;
	TFIBWideStringField *ElementPAS_NUMSPPO_REM_SKKT;
	TFIBWideStringField *ElementPAS_NUMFP_REM_SKKT;
	TFIBWideStringField *ElementPAS_NUMFPPO_REM_SKKT;
	TFIBWideStringField *ElementPAS_NUMDO_REM_SKKT;
	TFIBWideStringField *ElementPAS_NUMDOPO_REM_SKKT;
	TFIBWideStringField *ElementPAS_NUMPPP_REM_SKKT;
	TFIBWideStringField *ElementPAS_DOR_REM_SKKT;
	TFIBWideStringField *ElementPAS_PRIM_REM_SKKT;
	TFIBLargeIntField *ElementIDGRP_REM_SKKT;
	TFIBWideStringField *ElementPRIM_REM_SKKT;
	TFIBWideStringField *ElementNAME_REM_SMODEL;
	TFIBWideStringField *ElementOWNER_NAME;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementREGNUM_REM_SKKTChange(TField *Sender);
	void __fastcall ElementIDKLIENT_REM_SKKTChange(TField *Sender);
	void __fastcall ElementMESTOUST_REM_SKKTChange(TField *Sender);
	void __fastcall ElementCBKGR_REM_SKKTChange(TField *Sender);
	void __fastcall ElementCBKCO_REM_SKKTChange(TField *Sender);
	void __fastcall ElementNUMCONTRACT_REM_SKKTChange(TField *Sender);
	void __fastcall ElementDATECONTRACT_REM_SKKTChange(TField *Sender);
	void __fastcall ElementSUMCONTRACT_REM_SKKTChange(TField *Sender);
	void __fastcall ElementEKLZ_SERNUM_REM_SKKTChange(TField *Sender);
	void __fastcall ElementEKLZ_REGNUM_REM_SKKTChange(TField *Sender);
	void __fastcall ElementEKLZ_ACT_REM_SKKTChange(TField *Sender);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall TREM_DMSprKKT(TComponent* Owner);

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
		void ChancheGrp(__int64 new_id_grp);

		//поиск
		__int64 FindPoName(UnicodeString name);

		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;


		__int64 GetIdGrpElementa(__int64 id_element);

		void AddNewRecordDv(void);
		bool flChangeData;

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprKKT *REM_DMSprKKT;
//---------------------------------------------------------------------------
#endif
