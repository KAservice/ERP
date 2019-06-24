//---------------------------------------------------------------------------

#ifndef UDMSprStorageLocationGrpH
#define UDMSprStorageLocationGrpH
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
class TDMSprStorageLocationGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_SMHRAN_GRP;
	TFIBLargeIntField *TableIDBASE_SMHRAN_GRP;
	TFIBLargeIntField *TableIDGRP_SMHRAN_GRP;
	TFIBWideStringField *TableNAME_SMHRAN_GRP;
	TFIBLargeIntField *TableIDSKLAD_SMHRAN_GRP;
	TFIBLargeIntField *ElementID_SMHRAN_GRP;
	TFIBLargeIntField *ElementIDBASE_SMHRAN_GRP;
	TFIBLargeIntField *ElementIDGRP_SMHRAN_GRP;
	TFIBWideStringField *ElementNAME_SMHRAN_GRP;
	TFIBLargeIntField *ElementIDSKLAD_SMHRAN_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMSprStorageLocationGrp(TComponent* Owner);

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


		void OpenTable(__int64 id_sklad);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_sklad, __int64 id_grp);
		bool SaveElement(void);
		void DeleteElement(__int64 id);
		__int64 IdSklad;


};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprStorageLocationGrp *DMSprStorageLocationGrp;
//---------------------------------------------------------------------------
#endif
