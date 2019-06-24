//---------------------------------------------------------------------------

#ifndef UDMSprPropertiesNaborGrpH
#define UDMSprPropertiesNaborGrpH
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
class TDMSprPropertiesNaborGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_SPROPNABOR_GRP;
	TFIBLargeIntField *TableIDBASE_SPROPNABOR_GRP;
	TFIBWideStringField *TableGID_SPROPNABOR_GRP;
	TFIBLargeIntField *TableIDGRP_SPROPNABOR_GRP;
	TFIBWideStringField *TableNAME_SPROPNABOR_GRP;
	TFIBLargeIntField *ElementID_SPROPNABOR_GRP;
	TFIBLargeIntField *ElementIDBASE_SPROPNABOR_GRP;
	TFIBWideStringField *ElementGID_SPROPNABOR_GRP;
	TFIBLargeIntField *ElementIDGRP_SPROPNABOR_GRP;
	TFIBWideStringField *ElementNAME_SPROPNABOR_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMSprPropertiesNaborGrp(TComponent* Owner);

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
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


        void OpenTable(void);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);


		__int64 FindPoName(UnicodeString name);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprPropertiesNaborGrp *DMSprPropertiesNaborGrp;
//---------------------------------------------------------------------------
#endif
