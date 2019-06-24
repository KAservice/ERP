//---------------------------------------------------------------------------

#ifndef UDMSprPartH
#define UDMSprPartH
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
class TDMSprPart : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBBCDField *TablePRICEZPART;
	TFIBBCDField *TableKOLOSTNOM;
	TIntegerField *TableRECNO;
	TFIBBCDField *ElementPRICEZPART;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableIDPART;
	TFIBBCDField *TableIDKLPART;
	TFIBBCDField *TableIDFIRMPART;
	TFIBBCDField *TableIDNOMPART;
	TFIBBCDField *ElementIDKLPART;
	TFIBBCDField *ElementIDFIRMPART;
	TFIBBCDField *ElementIDNOMPART;
	TFIBBCDField *TableIDDOCPART;
	TFIBBCDField *ElementIDDOCPART;
	TFIBBCDField *ElementIDPART;
	TFIBDateTimeField *TableSRGODNPART;
	TFIBDateTimeField *ElementSRGODNPART;
	TFIBIntegerField *TableCODEPART;
	TFIBWideStringField *TableDOCPART;
	TFIBWideStringField *TableGTDPART;
	TFIBWideStringField *TableSERTPART;
	TFIBWideStringField *TableGID_SPART;
	TFIBBCDField *TableIDBASE_SPART;
	TFIBBCDField *TableIDEXT_DOUT_SPART;
	TFIBBCDField *TableIDEXT_BASE_SPART;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *TableNAMEKLIENT;
	TFIBIntegerField *ElementCODEPART;
	TFIBWideStringField *ElementDOCPART;
	TFIBWideStringField *ElementGTDPART;
	TFIBWideStringField *ElementGID_SPART;
	TFIBBCDField *ElementIDBASE_SPART;
	TFIBWideStringField *ElementNAMEKLIENT;
	TFIBWideStringField *ElementNAMENOM;
	TFIBWideStringField *ElementNAMEFIRM;
	TFIBWideStringField *ElementSERTPART;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprPart(TComponent* Owner);

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

		void OpenTable(__int64 IdNom);
		int OpenElement(__int64 Id);  //возвращает количество элементов
		void NewElement(__int64 IdNom);
        bool SaveElement(void);
		void DeleteElement(__int64 Id);

        bool Error;
        AnsiString TextError;		
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprPart *DMSprPart;
//---------------------------------------------------------------------------
#endif
