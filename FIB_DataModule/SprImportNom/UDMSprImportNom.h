//---------------------------------------------------------------------------

#ifndef UDMSprImportNomH
#define UDMSprImportNomH
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
class TDMSprImportNom : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableID_SIMPORTNOM;
	TFIBBCDField *TableIDBASE_SIMPORTNOM;
	TFIBBCDField *TableIDNOM_SIMPORTNOM;
	TFIBBCDField *TableIDKLIENT_SIMPORTNOM;
	TFIBBCDField *ElementID_SIMPORTNOM;
	TFIBBCDField *ElementIDBASE_SIMPORTNOM;
	TFIBBCDField *ElementIDNOM_SIMPORTNOM;
	TFIBBCDField *ElementIDKLIENT_SIMPORTNOM;
	TIntegerField *TableRECNO;
	TFIBWideStringField *TableCODE_SIMPORTNOM;
	TFIBWideStringField *TableART_SIMPORTNOM;
	TFIBWideStringField *TableNAME_SIMPORTNOM;
	TFIBWideStringField *ElementCODE_SIMPORTNOM;
	TFIBWideStringField *ElementART_SIMPORTNOM;
	TFIBWideStringField *ElementNAME_SIMPORTNOM;
	TFIBWideStringField *ElementNAMEKLIENT;
	TpFIBDataSet *pFIBDataSet1;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprImportNom(TComponent* Owner);

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

		bool Error;
		AnsiString TextError;

		void OpenTable(__int64 id_nom);
		int OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(__int64 id_nom);
		bool SaveElement(void);
		bool DeleteElement(__int64 id);


		__int64 FindNomPoArtikulu(__int64 id_post, UnicodeString artikul);
		__int64 FindNomPoCodu(__int64 id_post, UnicodeString code);
		__int64 FindNomPoName(__int64 id_post, UnicodeString name);
		__int64 FindElementPoArtikulu(__int64 id_post, UnicodeString artikul);
		__int64 FindElementPoCodu(__int64 id_post, UnicodeString code);
		__int64 FindElementPoName(__int64 id_post, UnicodeString name);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprImportNom *DMSprImportNom;
//---------------------------------------------------------------------------
#endif
