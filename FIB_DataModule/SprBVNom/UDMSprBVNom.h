//---------------------------------------------------------------------------

#ifndef UDMSprBVNomH
#define UDMSprBVNomH
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
class TDMSprBVNom : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourcePodr;
	TpFIBDataSet *Table;
	TpFIBDataSet *Podr;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBIntegerField *TableCODE_BVNOM;
	TFIBBCDField *TableZNACH_PRICE;
	TIntegerField *TableRECNO;
	TpFIBDataSet *Element;
	TFIBIntegerField *ElementCODE_BVNOM;
	TFIBBCDField *ElementID_BVNOM;
	TFIBBCDField *ElementIDPOD_BVNOM;
	TFIBBCDField *ElementIDNOM_BVNOM;
	TFIBBCDField *ElementIDGRP_BVNOM;
	TFIBBCDField *PodrIDPOD;
	TFIBBCDField *PodrIDTPRICEPOD;
	TFIBBCDField *TableID_BVNOM;
	TFIBBCDField *TableIDPOD_BVNOM;
	TFIBBCDField *TableIDNOM_BVNOM;
	TFIBBCDField *TableIDGRP_BVNOM;
	TFIBWideStringField *TableGID_SBVNOM;
	TFIBWideStringField *TableNAMENOM;
	TFIBWideStringField *TableNAMEED;
	TFIBWideStringField *PodrNAMEPOD;
	TFIBWideStringField *PodrNAME_TPRICE;
	TFIBWideStringField *ElementGID_SBVNOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall TableNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprBVNom(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		__int64 IdPod;
		__int64 IdGrp;
        bool AllElement;

		void OpenTable(__int64 Pod, __int64 Grp,bool All);
		void NewElement(__int64 Pod, __int64 Grp);
		bool OpenElement(__int64 id);
		void InsertElement(__int64 Pod, __int64 Grp, __int64 id_nom);
        void DeleteElement();
        void SaveIsmen();
        void CancelIsmen();
		void ChancheGrp(__int64 id_new_grp);

		__int64 IdTypePrice;

		int FindPoCoduBV(int codeBV);
		bool FindPoPodrAndNom(__int64 id_podr, __int64 id_nom);
        __int64 IdNomBV;
        int NumberAddElement;

        bool Error;
        AnsiString TextError;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprBVNom *DMSprBVNom;
//---------------------------------------------------------------------------
#endif
