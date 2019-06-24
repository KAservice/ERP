//---------------------------------------------------------------------------

#ifndef UDMSprMPrigH
#define UDMSprMPrigH
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
class TDMSprMPrig : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableID_MPRIG;
	TFIBBCDField *TableIDSKLAD_MPRIG;
	TFIBBCDField *TableIDOBORUD_MPRIG;
	TFIBBCDField *ElementID_MPRIG;
	TFIBBCDField *ElementIDSKLAD_MPRIG;
	TFIBBCDField *ElementIDOBORUD_MPRIG;
	TFIBBCDField *TableIDBASE_SMPRIG;
	TFIBBCDField *ElementIDBASE_SMPRIG;
	TFIBWideStringField *TableNAME_MPRIG;
	TFIBWideStringField *TableGID_SMPRIG;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableNAME_OBORUD;
	TFIBWideStringField *ElementNAME_MPRIG;
	TFIBWideStringField *ElementGID_SMPRIG;
	TFIBWideStringField *ElementNAMESKLAD;
	TFIBWideStringField *ElementNAME_OBORUD;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprMPrig(TComponent* Owner);


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
        void DeleteElement(__int64 Id);

        bool Error;
        String TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprMPrig *DMSprMPrig;
//---------------------------------------------------------------------------
#endif
