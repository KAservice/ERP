//---------------------------------------------------------------------------

#ifndef UDMSprGrpVesNomH
#define UDMSprGrpVesNomH
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
class TDMSprGrpVesNom : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBBCDField *TableID_SGRPVESNOM;
	TFIBBCDField *TableIDGRP_SGRPVESNOM;
	TFIBBCDField *TableIDBASE_SGRPVESNOM;
	TFIBBCDField *TableIDSCALE_SGRPVESNOM;
	TFIBBCDField *ElementID_SGRPVESNOM;
	TFIBBCDField *ElementIDGRP_SGRPVESNOM;
	TFIBBCDField *ElementIDBASE_SGRPVESNOM;
	TFIBBCDField *ElementIDSCALE_SGRPVESNOM;
	TIntegerField *TableRECNO;
	TFIBWideStringField *TableNAME_SGRPVESNOM;
	TFIBWideStringField *ElementNAME_SGRPVESNOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprGrpVesNom(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv ;

		void OpenTable(__int64 id_scale);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_scale, __int64 id_grp);
        bool SaveElement(void);
		void DeleteElement(__int64 id);
		__int64 IdScale;

		bool Error;
		AnsiString TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprGrpVesNom *DMSprGrpVesNom;
//---------------------------------------------------------------------------
#endif
