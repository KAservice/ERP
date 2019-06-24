//---------------------------------------------------------------------------

#ifndef UDMSprRaschSchetH
#define UDMSprRaschSchetH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
#include <IBDatabase.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
//---------------------------------------------------------------------------
class TDMSprRaschSchet : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableIDRSCHET;
	TFIBBCDField *TableIDKLRSCHET;
	TFIBBCDField *TableIDBANKRSCHET;
	TFIBBCDField *TableIDBANK;
	TFIBBCDField *ElementIDRSCHET;
	TFIBBCDField *ElementIDKLRSCHET;
	TFIBBCDField *ElementIDBANKRSCHET;
	TFIBBCDField *ElementIDBANK;
	TFIBWideStringField *TableNAMERSCHET;
	TFIBWideStringField *TableNUMRSCHET;
	TFIBWideStringField *TableGID_SRSCHET;
	TFIBWideStringField *TableNAMEBANK;
	TFIBWideStringField *TableBIKBANK;
	TFIBWideStringField *TableGORBANK;
	TFIBWideStringField *TableKSBANK;
	TFIBWideStringField *ElementNAMERSCHET;
	TFIBWideStringField *ElementNUMRSCHET;
	TFIBWideStringField *ElementGID_SRSCHET;
	TFIBWideStringField *ElementNAMEBANK;
	TFIBWideStringField *ElementBIKBANK;
	TFIBWideStringField *ElementGORBANK;
	TFIBWideStringField *ElementKSBANK;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprRaschSchet(TComponent* Owner);

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

		void OpenTable(__int64 IdKlient);
		int OpenElement(__int64 Id);  //возвращает количество элементов
		void NewElement(__int64 IdKlient);
        bool SaveElement(void);
		void DeleteElement(__int64 Id);

        bool Error;
        AnsiString TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprRaschSchet *DMSprRaschSchet;
//---------------------------------------------------------------------------
#endif
