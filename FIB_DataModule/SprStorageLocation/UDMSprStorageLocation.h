//---------------------------------------------------------------------------

#ifndef UDMSprStorageLocationH
#define UDMSprStorageLocationH
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
class TDMSprStorageLocation : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_SMHRAN;
	TFIBLargeIntField *TableIDBASE_SMHRAN;
	TFIBLargeIntField *TableIDGRP_SMHRAN;
	TFIBWideStringField *TableNAME_SMHRAN;
	TFIBLargeIntField *TableIDSKLAD_SMHRAN;
	TFIBSmallIntField *TableFL_DOSTUPNO_SMHRAN;
	TDataSource *DataSourceElement;
	TFIBLargeIntField *ElementID_SMHRAN;
	TFIBLargeIntField *ElementIDBASE_SMHRAN;
	TFIBLargeIntField *ElementIDGRP_SMHRAN;
	TFIBWideStringField *ElementNAME_SMHRAN;
	TFIBLargeIntField *ElementIDSKLAD_SMHRAN;
	TFIBSmallIntField *ElementFL_DOSTUPNO_SMHRAN;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMSprStorageLocation(TComponent* Owner);

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


		__int64 IdSklad;
		__int64 IdGrp;
		bool AllElement;


		bool OpenTable(__int64 id_sklad, __int64 id_grp,bool all);

		bool NewElement(__int64 id_sklad, __int64 id_grp);
		bool OpenElement(__int64 id);
		bool DeleteElement(__int64 id);
		bool ChangeGrp(__int64 id_new_grp,__int64 id_mhran);
		bool SaveElement(void);






};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprStorageLocation *DMSprStorageLocation;
//---------------------------------------------------------------------------
#endif
