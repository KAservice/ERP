//---------------------------------------------------------------------------

#ifndef UDMSprGrpProjectH
#define UDMSprGrpProjectH
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
class TDMSprGrpProject : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableID_SGRPPROJECT;
	TFIBBCDField *TableIDGRP_SGRPPROJECT;
	TFIBBCDField *ElementID_SGRPPROJECT;
	TFIBBCDField *ElementIDGRP_SGRPPROJECT;
	TFIBWideStringField *TableNAME_SGRPPROJECT;
	TFIBWideStringField *ElementNAME_SGRPPROJECT;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprGrpProject(TComponent* Owner);


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
		int OpenElement(__int64 id);
		void NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);

        bool Error;
		AnsiString TextError;

		__int64 FindPoName(AnsiString name);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprGrpProject *DMSprGrpProject;
//---------------------------------------------------------------------------
#endif
