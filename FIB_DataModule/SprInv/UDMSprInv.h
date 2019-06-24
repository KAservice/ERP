//---------------------------------------------------------------------------

#ifndef UDMSprInvH
#define UDMSprInvH
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
class TDMSprInv : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateField *TableDATE_SINV;
	TIntegerField *TableRECNO;
	TFIBDateField *ElementDATE_SINV;
	TFIBBCDField *TableID_SINV;
	TFIBBCDField *ElementID_SINV;
	TFIBWideStringField *TableGID_SINV;
	TFIBWideStringField *TableNAME_SINV;
	TFIBWideStringField *ElementGID_SINV;
	TFIBWideStringField *ElementNAME_SINV;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprInv(TComponent* Owner);


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
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


        void OpenTable(void);
		int OpenElement(__int64 Id);
        void NewElement(void);
        bool SaveElement(void);
        void CloseElement(void);
		void DeleteElement(__int64 Id);

		__int64 GetIDElement(String gid);
        AnsiString GetGIDElement(__int64 id);

        bool Error;
        AnsiString TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprInv *DMSprInv;
//---------------------------------------------------------------------------
#endif
