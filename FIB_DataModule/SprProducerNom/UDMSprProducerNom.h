//---------------------------------------------------------------------------

#ifndef UDMSprProducerNomH
#define UDMSprProducerNomH
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
class TDMSprProducerNom : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *Element;
	TIntegerField *TableRECNO;
	TpFIBDataSet *SpTPrice;
	TDataSource *DataSourceElement;
	TFIBLargeIntField *ElementID_SPRNOM;
	TFIBLargeIntField *ElementIDBASE_SPRNOM;
	TFIBWideStringField *ElementGID_SPRNOM;
	TFIBLargeIntField *ElementIDPROD_SPRNOM;
	TFIBLargeIntField *ElementIDGRP_SPRNOM;
	TFIBIntegerField *ElementCODE_SPRNOM;
	TFIBWideStringField *ElementART_SPRNOM;
	TFIBWideStringField *ElementNAME_SPRNOM;
	TFIBWideStringField *ElementKRNAME_SPRNOM;
	TFIBWideStringField *ElementFNAME_SPRNOM;
	TFIBIntegerField *ElementTYPE_SPRNOM;
	TFIBLargeIntField *ElementIDBASED_SPRNOM;
	TFIBLargeIntField *TableID_SPRNOM;
	TFIBLargeIntField *TableIDGRP_SPRNOM;
	TFIBLargeIntField *TableIDPROD_SPRNOM;
	TFIBIntegerField *TableCODE_SPRNOM;
	TFIBWideStringField *TableART_SPRNOM;
	TFIBWideStringField *TableNAME_SPRNOM;
	TFIBWideStringField *TableNAME_SPRED;
	TFIBWideStringField *TableBARCODE_SPRED;
	TFIBBCDField *TableVALUE_SPRPRICE;
	TFIBLargeIntField *SpTPriceID_SPRTYPE_PRICE;
	TFIBWideStringField *SpTPriceNAME_SPRTYPE_PRICE;
	TFIBWideStringField *TableMODEL_STR_SPRNOM;
	TFIBWideStringField *TableCODE_ANALOG_STR_SPRNOM;
	TFIBSmallIntField *TableFL_DOSTUPNO_SPRNOM;
	TFIBBCDField *TablePRICE_ZAKUP_SPRNOM;
	TFIBBCDField *TablePRICE_SPRNOM;
	TFIBWideStringField *ElementMODEL_STR_SPRNOM;
	TFIBWideStringField *ElementCODE_ANALOG_STR_SPRNOM;
	TFIBSmallIntField *ElementFL_DOSTUPNO_SPRNOM;
	TFIBBCDField *ElementPRICE_ZAKUP_SPRNOM;
	TFIBBCDField *ElementPRICE_SPRNOM;
	TFIBIntegerField *TableCODENOM;
	TFIBWideStringField *TableARTNOM;
	TFIBWideStringField *TableNAMENOM;
	TFIBWideStringField *TableSHED;
	TFIBWideStringField *TableNAMEED;
	TFIBLargeIntField *ElementIDNOM_SPRNOM;
	TFIBIntegerField *ElementCODENOM;
	TFIBWideStringField *ElementARTNOM;
	TFIBWideStringField *ElementNAMENOM;
	TFIBWideStringField *ElementSHED;
	TFIBWideStringField *ElementNAMEED;
	TpFIBQuery *pFIBQuery;
	TFIBDateTimeField *ElementISM_SPRNOM;
	TFIBDateTimeField *TableISM_SPRNOM;
	TFIBWideStringField *ElementREPAIRCODE_SPRNOM;
	TFIBWideStringField *ElementLOCATION_SPRNOM;
	TFIBWideStringField *ElementART2_SPRNOM;
	TFIBWideStringField *ElementANGL_NAME_SPRNOM;
	TFIBWideStringField *TableART2_SPRNOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprProducerNom(TComponent* Owner);

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

		__int64 IdProducer;
		__int64 IdGrp;
		bool AllElement;
		__int64 IdProducerTypePrice;


		void OpenTable(__int64 id_producer, __int64 id_grp, __int64 id_producer_type_price, bool all,
								UnicodeString in_str, int fl_poisk);

		bool NewElement(__int64 id_producer, __int64 id_grp);
		bool OpenElement(__int64 id);
		bool DeleteElement(__int64 id);
		bool SaveElement(void);

		void ChancheGrp(__int64 id_new_grp,__int64 id_producer_nom);

		//поиск
		__int64 FindPoCodu(__int64 id_producer, UnicodeString model, int Code);
		__int64 FindPoShtrihCodu(__int64 id_producer, UnicodeString model,UnicodeString shtrih_cod);
		__int64 FindPoName(__int64 id_producer, UnicodeString model,UnicodeString name);
		__int64 FindPoArtikulu(__int64 id_producer, UnicodeString model,UnicodeString artikul);
		__int64 GetIdGrpNom(__int64 id_nom);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprProducerNom *DMSprProducerNom;
//---------------------------------------------------------------------------
#endif
