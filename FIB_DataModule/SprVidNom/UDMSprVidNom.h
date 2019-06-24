//---------------------------------------------------------------------------

#ifndef UDMSprVidNomH
#define UDMSprVidNomH
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
class TDMSprVidNom : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableID_SVIDNOM;
	TFIBBCDField *ElementID_SVIDNOM;
	TFIBWideStringField *TableGID_SVIDNOM;
	TFIBWideStringField *TableNAME_SVIDNOM;
	TFIBWideStringField *ElementNAME_SVIDNOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprVidNom(TComponent* Owner);


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
		bool NewElement(void);
		bool SaveElement(void);
		bool SaveIsmen(void);
		bool CancelIsmen(void);

        void CloseElement(void);
		bool DeleteElement(__int64 Id);


        bool Error;
		AnsiString TextError;

		int GetIndexElementaPoID(__int64 id);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprVidNom *DMSprVidNom;
//---------------------------------------------------------------------------
#endif
