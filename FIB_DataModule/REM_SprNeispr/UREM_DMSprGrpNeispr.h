//---------------------------------------------------------------------------

#ifndef UREM_DMSprGrpNeisprH
#define UREM_DMSprGrpNeisprH
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
class TREM_DMSprGrpNeispr : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_REM_SGRPNEISPR;
	TFIBWideStringField *TableGID_REM_SGRPNEISPR;
	TFIBLargeIntField *TableIDGRP_REM_SGRPNEISPR;
	TFIBWideStringField *TableNAME_REM_SGRPNEISPR;
	TFIBLargeIntField *TableIDBASE_REM_SGRPNEISPR;
	TFIBLargeIntField *ElementID_REM_SGRPNEISPR;
	TFIBWideStringField *ElementGID_REM_SGRPNEISPR;
	TFIBLargeIntField *ElementIDGRP_REM_SGRPNEISPR;
	TFIBWideStringField *ElementNAME_REM_SGRPNEISPR;
	TFIBLargeIntField *ElementIDBASE_REM_SGRPNEISPR;
	TFIBWideStringField *ElementNAME_ENG_REM_SGRPNEISPR;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMSprGrpNeispr(TComponent* Owner);

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

        void OpenTable(void);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_grp);
        bool SaveElement(void);
        void DeleteElement(__int64 id);

        int GetIDElement(UnicodeString gid);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprGrpNeispr *REM_DMSprGrpNeispr;
//---------------------------------------------------------------------------
#endif
