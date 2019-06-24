//---------------------------------------------------------------------------

#ifndef UREM_DMSprProducerNeisprGrpH
#define UREM_DMSprProducerNeisprGrpH
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
class TREM_DMSprProducerNeisprGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_REM_SPRNEISPR_GRP;
	TFIBLargeIntField *TableIDBASE_REM_SPRNEISPR_GRP;
	TFIBWideStringField *TableGID_REM_SPRNEISPR_GRP;
	TFIBLargeIntField *TableIDPR_REM_SPRNEISPR_GRP;
	TFIBWideStringField *TableNAME_REM_SPRNEISPR_GRP;
	TFIBLargeIntField *TableIDGRP_REM_SPRNEISPR_GRP;
	TFIBLargeIntField *ElementID_REM_SPRNEISPR_GRP;
	TFIBLargeIntField *ElementIDBASE_REM_SPRNEISPR_GRP;
	TFIBWideStringField *ElementGID_REM_SPRNEISPR_GRP;
	TFIBLargeIntField *ElementIDPR_REM_SPRNEISPR_GRP;
	TFIBWideStringField *ElementNAME_REM_SPRNEISPR_GRP;
	TFIBLargeIntField *ElementIDGRP_REM_SPRNEISPR_GRP;
	TFIBWideStringField *TableNAME_ENG_REM_SPRNEISPR_GRP;
	TFIBWideStringField *ElementNAME_ENG_REM_SPRNEISPR_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprProducerNeisprGrp(TComponent* Owner);

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

		void OpenTable(__int64 id_group_element);
		int OpenElement(__int64 id);
		bool NewElement(__int64 id_group_element, __int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		__int64 IdGroupElement;


};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprProducerNeisprGrp *REM_DMSprProducerNeisprGrp;
//---------------------------------------------------------------------------
#endif
