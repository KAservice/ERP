//---------------------------------------------------------------------------

#ifndef UDMSprPropertiesNaborSostavH
#define UDMSprPropertiesNaborSostavH
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
class TDMSprPropertiesNaborSostav : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *TableID_SPROPNABOR_SOST;
	TFIBLargeIntField *TableIDBASE_SPROPNABOR_SOST;
	TFIBWideStringField *TableGID_SPROPNABOR_SOST;
	TFIBLargeIntField *TableIDPROPNABOR_SPROPNABOR_SOST;
	TFIBLargeIntField *TableIDPROP_SPROPNABOR_SOST;
	TFIBIntegerField *TableINDEXSORT_SPROPNABOR_SOST;
	TFIBLargeIntField *ElementID_SPROPNABOR_SOST;
	TFIBLargeIntField *ElementIDBASE_SPROPNABOR_SOST;
	TFIBWideStringField *ElementGID_SPROPNABOR_SOST;
	TFIBLargeIntField *ElementIDPROPNABOR_SPROPNABOR_SOST;
	TFIBLargeIntField *ElementIDPROP_SPROPNABOR_SOST;
	TFIBIntegerField *ElementINDEXSORT_SPROPNABOR_SOST;
	TFIBWideStringField *TableNAME_SPROP;
	TFIBWideStringField *ElementNAME_SPROP;
	TFIBWideStringField *TableNAME_FOR_PRINT_SPROP;
	TFIBWideStringField *TableNAME_SPROP_GRP;
	TFIBWideStringField *TableNAME_FOR_PRINT_SPROP_GRP;
	TFIBSmallIntField *TableADD1_SPROPNABOR_SOST;
	TFIBSmallIntField *TableADD2_SPROPNABOR_SOST;
	TFIBSmallIntField *TableADD3_SPROPNABOR_SOST;
	TFIBSmallIntField *TableADD4_SPROPNABOR_SOST;
	TFIBSmallIntField *TableADD5_SPROPNABOR_SOST;
	TFIBSmallIntField *ElementADD1_SPROPNABOR_SOST;
	TFIBSmallIntField *ElementADD2_SPROPNABOR_SOST;
	TFIBSmallIntField *ElementADD3_SPROPNABOR_SOST;
	TFIBSmallIntField *ElementADD4_SPROPNABOR_SOST;
	TFIBSmallIntField *ElementADD5_SPROPNABOR_SOST;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations


bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
		__fastcall TDMSprPropertiesNaborSostav(TComponent* Owner);

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




		void OpenTable(__int64 id_nabor);
		int OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(__int64 id_nabor);
		bool SaveElement(void);
		bool DeleteElement(__int64 id);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprPropertiesNaborSostav *DMSprPropertiesNaborSostav;
//---------------------------------------------------------------------------
#endif
