//---------------------------------------------------------------------------

#ifndef UDMSprGrpNomH
#define UDMSprGrpNomH
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
class TDMSprGrpNom : public TDataModule
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
	TFIBBCDField *TableIDGN;
	TFIBBCDField *TableIDGRPGN;
	TFIBBCDField *ElementIDGN;
	TFIBBCDField *ElementIDGRPGN;
	TFIBWideStringField *TableNAMEGN;
	TFIBWideStringField *TableGID_SGRPNOM;
	TFIBWideStringField *ElementNAMEGN;
	TFIBWideStringField *ElementGID_SGRPNOM;
	TFIBBCDField *ElementIDVIDIMAGENABOR_SGRPNOM;
	TFIBBCDField *ElementIDPROPNABOR_SGRPNOM;
	TFIBWideStringField *ElementNAME_SPROPNABOR;
	TFIBWideStringField *ElementNAME_SVIDIMAGE_NABOR;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprGrpNom(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации


		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);



		//Текущий интерфейс
        void OpenTable(void);
		int OpenElement(__int64 Id);
		void NewElement(__int64 IdGrp);
        bool SaveElement(void);
		bool DeleteElement(__int64 Id);

		__int64 GetIDElement(String gid);
		AnsiString GetGIDElement(__int64 id);

		__int64 FindPoName(AnsiString name);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprGrpNom *DMSprGrpNom;
//---------------------------------------------------------------------------
#endif
