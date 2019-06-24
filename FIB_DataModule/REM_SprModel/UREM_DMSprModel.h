//---------------------------------------------------------------------------

#ifndef UREM_DMSprModelH
#define UREM_DMSprModelH
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
class TREM_DMSprModel : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQuery;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_REM_SMODEL;
	TFIBWideStringField *TableGID_REM_SMODEL;
	TFIBLargeIntField *TableIDGRP_REM_SMODEL;
	TFIBWideStringField *TableNAME_REM_SMODEL;
	TFIBLargeIntField *TableIDBASE_REM_SMODEL;
	TFIBLargeIntField *ElementID_REM_SMODEL;
	TFIBWideStringField *ElementGID_REM_SMODEL;
	TFIBLargeIntField *ElementIDGRP_REM_SMODEL;
	TFIBWideStringField *ElementNAME_REM_SMODEL;
	TFIBLargeIntField *ElementIDBASE_REM_SMODEL;
	TFIBLargeIntField *ElementIDNOM_REM_SMODEL;
	TFIBWideStringField *ElementSTRCODE_REM_SMODEL;
	TFIBWideStringField *ElementNAMENOM;
	TFIBLargeIntField *ElementIDBRAND_REM_SMODEL;
	TFIBWideStringField *ElementNAME_SBRAND;
	TFIBWideStringField *TableSTRCODE_REM_SMODEL;
	TFIBLargeIntField *TableIDBRAND_REM_SMODEL;
	TFIBLargeIntField *TableIDPRMODEL_REM_SMODEL;
	TFIBWideStringField *TableDESCR_REM_SMODEL;
	TFIBWideStringField *TableNAME_REM_SPRMODEL;
	TFIBWideStringField *TableNAME_SBRAND;
	TFIBLargeIntField *TableIDNOM_REM_SMODEL;
	TFIBWideStringField *TableNAMENOM;
	TFIBLargeIntField *ElementIDPRMODEL_REM_SMODEL;
	TFIBWideStringField *ElementDESCR_REM_SMODEL;
	TFIBWideStringField *ElementCODE_REM_SMODEL;
	TFIBWideStringField *ElementNAME_REM_SPRMODEL;
	TFIBLargeIntField *ElementIDMODELNEISPR_REM_SMODEL;
	TFIBWideStringField *ElementNAME_REM_SMODEL_NEISPR;
	TFIBWideStringField *TableCODE_REM_SMODEL;
	TFIBLargeIntField *TableIDMODELNEISPR_REM_SMODEL;
	TFIBWideStringField *TableNAME_REM_SMODEL_NEISPR;
	TFIBLargeIntField *ElementIDPRODUCER_REM_SMODEL;
	TFIBLargeIntField *ElementIDACTCATEGORY_REM_SMODEL;
	TFIBLargeIntField *ElementIDTYPEDEVICE_REM_SMODEL;
	TFIBWideStringField *ElementNAME_SPRODUCER;
	TFIBWideStringField *ElementNAME_REM_SACTCATEGORY;
	TFIBWideStringField *ElementNAME_REM_STYPEDEVICE;
	TFIBLargeIntField *TableIDPRODUCER_REM_SMODEL;
	TFIBLargeIntField *TableIDACTCATEGORY_REM_SMODEL;
	TFIBLargeIntField *TableIDTYPEDEVICE_REM_SMODEL;
	TFIBWideStringField *TableNAME_SPRODUCER;
	TFIBWideStringField *TableNAME_REM_SACTCATEGORY;
	TFIBWideStringField *TableNAME_REM_STYPEDEVICE;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprModel(TComponent* Owner);

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

		UnicodeString GetTextQuery(__int64 id_grp, bool all);
		void OpenTable(__int64 id_grp, bool all);
		int OpenElement(__int64 id);
		bool NewElement(__int64 id_grp);
		bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void ChancheGrp(__int64 id_new_grp, __int64 id_el);


		__int64 GetIDElement(UnicodeString gid);
		UnicodeString GetGIDElement(__int64 id);
		__int64 GetIdGrpNom(__int64 id);
		__int64 FindPoNom(__int64 id_nom);

		__int64 IdGrp;
		bool AllElement;

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprModel *REM_DMSprModel;
//---------------------------------------------------------------------------
#endif
