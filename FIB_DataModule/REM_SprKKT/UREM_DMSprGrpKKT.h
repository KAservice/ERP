//---------------------------------------------------------------------------

#ifndef UREM_DMSprGrpKKTH
#define UREM_DMSprGrpKKTH
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
class TREM_DMSprGrpKKT : public TDataModule
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
	TFIBLargeIntField *TableID_REM_SGRPKKT;
	TFIBLargeIntField *TableIDBASE_REM_SGRPKKT;
	TFIBWideStringField *TableNAME_REM_SGRPKKT;
	TFIBLargeIntField *TableIDGRP_REM_SGRPKKT;
	TFIBLargeIntField *ElementID_REM_SGRPKKT;
	TFIBLargeIntField *ElementIDBASE_REM_SGRPKKT;
	TFIBWideStringField *ElementNAME_REM_SGRPKKT;
	TFIBLargeIntField *ElementIDGRP_REM_SGRPKKT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall TREM_DMSprGrpKKT(TComponent* Owner);

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
		bool DeleteElement(__int64 id);

		__int64 FindPoName(UnicodeString name);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprGrpKKT *REM_DMSprGrpKKT;
//---------------------------------------------------------------------------
#endif
