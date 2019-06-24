//---------------------------------------------------------------------------

#ifndef UREM_DMSprModel2GrpH
#define UREM_DMSprModel2GrpH
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
class TREM_DMSprModel2Grp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_REM_SMODEL2_GRP;
	TFIBWideStringField *TableGID_REM_SMODEL2_GRP;
	TFIBLargeIntField *TableIDBASE_REM_SMODEL2_GRP;
	TFIBLargeIntField *TableIDGRP_REM_SMODEL2_GRP;
	TFIBWideStringField *TableNAME_REM_SMODEL2_GRP;
	TFIBLargeIntField *TableIDTYPEDEV_REM_SMODEL2_GRP;
	TFIBLargeIntField *ElementID_REM_SMODEL2_GRP;
	TFIBWideStringField *ElementGID_REM_SMODEL2_GRP;
	TFIBLargeIntField *ElementIDBASE_REM_SMODEL2_GRP;
	TFIBLargeIntField *ElementIDGRP_REM_SMODEL2_GRP;
	TFIBWideStringField *ElementNAME_REM_SMODEL2_GRP;
	TFIBLargeIntField *ElementIDTYPEDEV_REM_SMODEL2_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TREM_DMSprModel2Grp(TComponent* Owner);

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
		__int64 IdElement;
		bool AllElement;


		bool OpenTable(__int64 id_group_element);
		bool OpenElement(__int64 id);
		bool NewElement(__int64 id_group_element, __int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);


};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprModel2Grp *REM_DMSprModel2Grp;
//---------------------------------------------------------------------------
#endif
