//---------------------------------------------------------------------------

#ifndef UDMInterfMainMenuParH
#define UDMInterfMainMenuParH
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
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMInterfMainMenuPar : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TFIBLargeIntField *TableID_INTERF_MAINMENU_PAR;
	TFIBLargeIntField *TableIDBASE_INTERF_MAINMENU_PAR;
	TFIBWideStringField *TableGID_INTERF_MAINMENU_PAR;
	TFIBLargeIntField *TableIDMAINMENU_INTERF_MAINMENU_PAR;
	TFIBWideStringField *TableNAME_INTERF_MAINMENU_PAR;
	TFIBWideStringField *TableVALUE_INTERF_MAINMENU_PAR;
	TFIBDateTimeField *TableVALUE_TIMESTAMP_MAINMENU_PAR;
	TFIBSmallIntField *TableTYPE_VALUE_MAINMENU_PAR;
	TFIBIntegerField *TableTYPE_PAR_INTERF_MAINMENU_PAR;
	TFIBLargeIntField *ElementID_INTERF_MAINMENU_PAR;
	TFIBLargeIntField *ElementIDBASE_INTERF_MAINMENU_PAR;
	TFIBWideStringField *ElementGID_INTERF_MAINMENU_PAR;
	TFIBLargeIntField *ElementIDMAINMENU_INTERF_MAINMENU_PAR;
	TFIBWideStringField *ElementNAME_INTERF_MAINMENU_PAR;
	TFIBWideStringField *ElementVALUE_INTERF_MAINMENU_PAR;
	TFIBDateTimeField *ElementVALUE_TIMESTAMP_MAINMENU_PAR;
	TFIBSmallIntField *ElementTYPE_VALUE_MAINMENU_PAR;
	TFIBIntegerField *ElementTYPE_PAR_INTERF_MAINMENU_PAR;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMInterfMainMenuPar(TComponent* Owner);

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
        bool Error;
		UnicodeString TextError;


		bool Init(void);
		int Done(void);


		__int64 IdOwner;
		__int64 IdElement;

		void OpenTable(__int64 id_owner);
		bool SaveIsmen(void);
		bool CancelIsmen(void);
		bool TableAppend(__int64 id_owner);
		bool TableDelete(void);

		bool NewElement(__int64 id_owner);
		int OpenElement(__int64 id );
		bool SaveElement(void);
		bool DeleteElement(__int64 id);



};
//---------------------------------------------------------------------------
extern PACKAGE TDMInterfMainMenuPar *DMInterfMainMenuPar;
//---------------------------------------------------------------------------
#endif
