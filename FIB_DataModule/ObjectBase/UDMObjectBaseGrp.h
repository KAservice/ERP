//---------------------------------------------------------------------------

#ifndef UDMObjectBaseGrpH
#define UDMObjectBaseGrpH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

//--------------------------------------------------------------------------
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
class TDMObjectBaseGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBLargeIntField *TableID_OBJECT_BASE_GRP;
	TFIBLargeIntField *TableIDBASE_OBJECT_BASE_GRP;
	TFIBWideStringField *TableNAME_OBJECT_BASE_GRP;
	TFIBLargeIntField *TableIDGRP_OBJECT_BASE_GRP;
	TFIBLargeIntField *ElementID_OBJECT_BASE_GRP;
	TFIBLargeIntField *ElementIDBASE_OBJECT_BASE_GRP;
	TFIBWideStringField *ElementNAME_OBJECT_BASE_GRP;
	TFIBLargeIntField *ElementIDGRP_OBJECT_BASE_GRP;
	TIntegerField *TableRECNO;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMObjectBaseGrp(TComponent* Owner);

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		bool Error;
		AnsiString TextError;

		void OpenTable(void);
		void Table_First(void);
		void Table_Next(void);


		int OpenElement(__int64 id);
		void NewElement( __int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void Element_Edit(void);
		void Element_Post(void);



		__int64 IdGrp;


};
//---------------------------------------------------------------------------
extern PACKAGE TDMObjectBaseGrp *DMObjectBaseGrp;
//---------------------------------------------------------------------------
#endif
