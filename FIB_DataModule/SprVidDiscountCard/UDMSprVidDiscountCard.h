//---------------------------------------------------------------------------

#ifndef UDMSprVidDiscountCardH
#define UDMSprVidDiscountCardH
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
class TDMSprVidDiscountCard : public TDataModule
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
	TFIBBCDField *TableID_SVID_DCARD;
	TFIBBCDField *ElementID_SVID_DCARD;
	TFIBWideStringField *TableGID_SVID_DCARD;
	TFIBWideStringField *TableNAME_SVID_DCARD;
	TFIBWideStringField *ElementGID_SVID_DCARD;
	TFIBWideStringField *ElementNAME_SVID_DCARD;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprVidDiscountCard(TComponent* Owner);


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
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv ;

        void OpenTable(void);
		int OpenElement(__int64 Id);
		bool NewElement(void);
        bool SaveElement(void);
        void CloseElement(void);
		bool DeleteElement(__int64 Id);

        __int64 GetIDElement(String gid);
		AnsiString GetGIDElement(__int64 id);

        bool Error;
		AnsiString TextError;

		int GetIndexElementaPoID(__int64 id);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprVidDiscountCard *DMSprVidDiscountCard;
//---------------------------------------------------------------------------
#endif
