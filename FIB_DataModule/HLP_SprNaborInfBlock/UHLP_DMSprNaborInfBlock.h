//---------------------------------------------------------------------------

#ifndef UHLP_DMSprNaborInfBlockH
#define UHLP_DMSprNaborInfBlockH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


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
#include <DBClient.hpp>
//---------------------------------------------------------------------------
class THLP_DMSprNaborInfBlock : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_HLP_N_IB;
	TFIBLargeIntField *TableIDBASE_HLP_N_IB;
	TFIBWideStringField *TableGUID_HLP_N_IB;
	TFIBDateTimeField *TablePOS_ISM_HLP_N_IB;
	TFIBLargeIntField *TableIDGRP_HLP_N_IB;
	TFIBWideStringField *TableNAME_HLP_N_IB;
	TFIBIntegerField *TableINDEX_HLP_N_IB;
	TFIBLargeIntField *ElementID_HLP_N_IB;
	TFIBLargeIntField *ElementIDBASE_HLP_N_IB;
	TFIBWideStringField *ElementGUID_HLP_N_IB;
	TFIBDateTimeField *ElementPOS_ISM_HLP_N_IB;
	TFIBLargeIntField *ElementIDGRP_HLP_N_IB;
	TFIBWideStringField *ElementNAME_HLP_N_IB;
	TFIBIntegerField *ElementINDEX_HLP_N_IB;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);



private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall THLP_DMSprNaborInfBlock(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Error;
		UnicodeString TextError;


		bool Init(void);
		int Done(void);


		void OpenTable(__int64 id_grp, bool all);
		UnicodeString GetTextQuery(__int64 id_grp, bool all);
		int OpenElement(__int64 id );
		bool NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void ChancheGrp(__int64 id_new_grp,__int64 id_element);

		//поиск
		__int64 FindPoName(UnicodeString name);


		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;

		__int64 GetIdGrp(__int64 id_el);

};
//---------------------------------------------------------------------------
extern PACKAGE THLP_DMSprNaborInfBlock *HLP_DMSprNaborInfBlock;
//---------------------------------------------------------------------------
#endif
