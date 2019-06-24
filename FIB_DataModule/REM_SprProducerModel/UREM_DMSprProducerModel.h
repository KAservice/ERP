//---------------------------------------------------------------------------

#ifndef UREM_DMSprProducerModelH
#define UREM_DMSprProducerModelH
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
class TREM_DMSprProducerModel : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Element;
	TIntegerField *TableRECNO;
	TDataSource *DataSourceElement;
	TFIBLargeIntField *TableID_REM_SPRMODEL;
	TFIBWideStringField *TableCODE_REM_SPRMODEL;
	TFIBWideStringField *TableNAME_REM_SPRMODEL;
	TFIBLargeIntField *ElementID_REM_SPRMODEL;
	TFIBLargeIntField *ElementIDBASE_REM_SPRMODEL;
	TFIBWideStringField *ElementGID_REM_SPRMODEL;
	TFIBLargeIntField *ElementIDPR_REM_SPRMODEL;
	TFIBLargeIntField *ElementIDGRP_REM_SPRMODEL;
	TFIBLargeIntField *ElementIDMODEL_REM_SPRMODEL;
	TFIBWideStringField *ElementCODE_REM_SPRMODEL;
	TFIBWideStringField *ElementNAME_REM_SPRMODEL;
	TFIBWideStringField *ElementNAME_REM_SMODEL;
	TFIBWideStringField *TableNAME_REM_SMODEL;
	TFIBLargeIntField *TableIDPR_REM_SPRMODEL;
	TFIBLargeIntField *TableIDGRP_REM_SPRMODEL;
	TFIBWideStringField *TableNAME_SBRAND;
	TFIBWideStringField *TableNAME_SPRODUCER;
	TFIBWideStringField *TableNAME_REM_SACTCATEGORY;
	TFIBWideStringField *TableNAME_REM_STYPEDEVICE;
	TFIBLargeIntField *ElementIDBRAND_REM_SPRMODEL;
	TFIBLargeIntField *ElementIDACTCATEGORY_REM_SPRMODEL;
	TFIBLargeIntField *ElementIDTYPEDEVICE_REM_SPRMODEL;
	TFIBWideStringField *ElementNAME_SBRAND;
	TFIBWideStringField *ElementNAME_SPRODUCER;
	TFIBWideStringField *ElementNAME_REM_SACTCATEGORY;
	TFIBWideStringField *ElementNAME_REM_STYPEDEVICE;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprProducerModel(TComponent* Owner);

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

		__int64 IdGroupElement;
		__int64 IdGrp;
		bool AllElement;


		void OpenTable(__int64 id_group_element, __int64 id_grp, bool all);
		bool NewElement(__int64 id_group_element, __int64 id_grp);
		bool OpenElement(__int64 id);
		bool DeleteElement(__int64 id);
		bool SaveElement(void);
		void ChancheGrp(__int64 id_new_grp,__int64 id_element);


};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprProducerModel *REM_DMSprProducerModel;
//---------------------------------------------------------------------------
#endif
