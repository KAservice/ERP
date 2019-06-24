//---------------------------------------------------------------------------

#ifndef UDMSprNakSkidokH
#define UDMSprNakSkidokH
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
class TDMSprNakSkidok : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBBCDField *TableSUM_SNAK_SKIDOK;
	TFIBBCDField *TablePROCENT_SNAK_SKIDOK;
	TFIBSmallIntField *TablePERIOD_SNAK_SKIDOK;
	TFIBBCDField *ElementSUM_SNAK_SKIDOK;
	TFIBBCDField *ElementPROCENT_SNAK_SKIDOK;
	TFIBSmallIntField *ElementPERIOD_SNAK_SKIDOK;
	TpFIBQuery *Query;
	TFIBBCDField *TableID_SNAK_SKIDOK;
	TFIBBCDField *TableIDSKLAD_SNAK_SKIDOK;
	TFIBBCDField *TableIDVID_SNAK_SKIDOK;
	TFIBBCDField *ElementID_SNAK_SKIDOK;
	TFIBBCDField *ElementIDSKLAD_SNAK_SKIDOK;
	TFIBBCDField *ElementIDVID_SNAK_SKIDOK;
	TpFIBDataSet *TableNakSkidok;
	TFIBBCDField *TableNakSkidokID_SNAK_SKIDOK;
	TFIBBCDField *TableNakSkidokIDSKLAD_SNAK_SKIDOK;
	TFIBBCDField *TableNakSkidokIDVID_SNAK_SKIDOK;
	TFIBBCDField *TableNakSkidokSUM_SNAK_SKIDOK;
	TFIBBCDField *TableNakSkidokPROCENT_SNAK_SKIDOK;
	TFIBSmallIntField *TableNakSkidokPERIOD_SNAK_SKIDOK;
	TFIBWideStringField *TableGID_SNAK_SKIDOK;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableNAME_SVID_DCARD;
	TFIBWideStringField *ElementGID_SNAK_SKIDOK;
	TFIBWideStringField *ElementNAMESKLAD;
	TFIBWideStringField *ElementNAME_SVID_DCARD;
	TFIBWideStringField *TableNakSkidokGID_SNAK_SKIDOK;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprNakSkidok(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
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
		int OpenElement(__int64 id);  //возвращает количество элементов
		void NewElement(void);
        bool SaveElement(void);
		void DeleteElement(__int64 id);

        bool Error;
        String TextError;

		bool elSave;
		void GetSpisokSkidok(__int64 id_vid, __int64 id_sklad);
		void OpenTableNakSkidok(__int64 id_vid,__int64 id_sklad);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprNakSkidok *DMSprNakSkidok;
//---------------------------------------------------------------------------
#endif
