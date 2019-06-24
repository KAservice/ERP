//---------------------------------------------------------------------------

#ifndef UREM_DMSprHardwareIspH
#define UREM_DMSprHardwareIspH
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
class TREM_DMSprHardwareIsp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_REM_SHARDWARE_ISP;
	TFIBLargeIntField *TableIDBASE_REM_SHARDWARE_ISP;
	TFIBLargeIntField *TableIDHW_REM_SHARDWARE_ISP;
	TFIBDateTimeField *TablePOS_REM_SHARDWARE_ISP;
	TFIBLargeIntField *TableIDUSER_REM_SHARDWARE_ISP;
	TFIBLargeIntField *TableIDTYPEUSEL_REM_SHARDWARE_ISP;
	TFIBBCDField *TableKOL_REM_SHARDWARE_ISP;
	TFIBWideStringField *TableDESCR_REM_SHARDWARE_ISP;
	TFIBSmallIntField *TableFL_OTCH_PR_REM_SHARDWARE_ISP;
	TFIBSmallIntField *TableFL_REAL_ISP_REM_SHARDWARE_ISP;
	TFIBLargeIntField *TableIDZ_REM_SHARDWARE_ISP;
	TFIBWideStringField *TableNAME_REM_STYPUSLOV;
	TFIBWideStringField *TableNAME_USER;
	TFIBWideStringField *TableNAME_REM_Z;
	TFIBWideStringField *TablePREFIKS_NUM_REM_Z;
	TFIBDateTimeField *TablePOS_REM_Z;
	TFIBIntegerField *TableNUM_REM_Z;
	TFIBWideStringField *TableMODEL_REM_Z;
	TFIBWideStringField *TableSERNUM_REM_Z;
	TFIBLargeIntField *ElementID_REM_SHARDWARE_ISP;
	TFIBLargeIntField *ElementIDBASE_REM_SHARDWARE_ISP;
	TFIBLargeIntField *ElementIDHW_REM_SHARDWARE_ISP;
	TFIBDateTimeField *ElementPOS_REM_SHARDWARE_ISP;
	TFIBLargeIntField *ElementIDUSER_REM_SHARDWARE_ISP;
	TFIBLargeIntField *ElementIDTYPEUSEL_REM_SHARDWARE_ISP;
	TFIBBCDField *ElementKOL_REM_SHARDWARE_ISP;
	TFIBWideStringField *ElementDESCR_REM_SHARDWARE_ISP;
	TFIBSmallIntField *ElementFL_OTCH_PR_REM_SHARDWARE_ISP;
	TFIBSmallIntField *ElementFL_REAL_ISP_REM_SHARDWARE_ISP;
	TFIBLargeIntField *ElementIDZ_REM_SHARDWARE_ISP;
	TFIBWideStringField *ElementNAME_REM_STYPUSLOV;
	TFIBWideStringField *ElementNAME_USER;
	TFIBWideStringField *ElementNAME_REM_Z;
	TFIBWideStringField *ElementPREFIKS_NUM_REM_Z;
	TFIBDateTimeField *ElementPOS_REM_Z;
	TFIBIntegerField *ElementNUM_REM_Z;
	TFIBWideStringField *ElementMODEL_REM_Z;
	TFIBWideStringField *ElementSERNUM_REM_Z;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprHardwareIsp(TComponent* Owner);

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

		void OpenTable(__int64 id_owner);
		int OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(__int64 id_owner);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);

		__int64 IdOwner;



};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprHardwareIsp *REM_DMSprHardwareIsp;
//---------------------------------------------------------------------------
#endif
