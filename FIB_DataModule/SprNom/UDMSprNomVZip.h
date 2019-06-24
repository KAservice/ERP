//---------------------------------------------------------------------------

#ifndef UDMSprNomVZipH
#define UDMSprNomVZipH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


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
#include <DBClient.hpp>
//---------------------------------------------------------------------------
class TDMSprNomVZip : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBQuery *pFIBQuery;
	TFIBLargeIntField *TableOUT_IDNOM;
	TFIBWideStringField *TableOUT_NAME_NOM;
	TFIBIntegerField *TableOUT_CODE;
	TFIBWideStringField *TableOUT_ARTIKUL;
	TFIBLargeIntField *TableOUT_IDED;
	TFIBWideStringField *TableOUT_NAME_ED;
	TFIBWideStringField *TableOUT_SHED;
	TFIBBCDField *TableOUT_PRICE;
	TFIBBCDField *TableOUT_OST;
	TFIBLargeIntField *TableOUT_IDFIRM;
	TFIBWideStringField *TableOUT_NAME_FIRM;
	TFIBLargeIntField *TableOUT_IDSKLAD;
	TFIBWideStringField *TableOUT_NAME_SKLAD;
	TFIBLargeIntField *TableOUT_IDKLIENT;
	TFIBWideStringField *TableOUT_NAME_KLIENT;
	TFIBLargeIntField *TableOUT_IDTNOM;
	TFIBWideStringField *TableOUT_NAME_TNOM;
	TFIBLargeIntField *TableOUT_IDZ;
	TFIBWideStringField *TableOUT_NAME_Z;
	TFIBLargeIntField *TableOUT_IDGRPNOM;
	TIntegerField *TableRECNO;
	TpFIBDataSet *SpTPrice;
	TFIBBCDField *SpTPriceID_TPRICE;
	TFIBWideStringField *SpTPriceNAME_TPRICE;
	TFIBLargeIntField *TableOUT_IDMHRAN;
	TFIBWideStringField *TableOUT_NAME_MHRAN;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableAfterScroll(TDataSet *DataSet);



private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TDMSprNomVZip(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);

        bool Error;
		String TextError;

        //Текущий интерфейс
		void OpenTable(__int64 Grp, bool All);

		//поиск
		__int64 FindPoCodu(int Code);
		__int64 FindPoShtrihCodu(AnsiString shtrih_cod);
		__int64 FindPoName(AnsiString name);
		__int64 FindPoArtikulu(UnicodeString artikul);
		int GetIndexTypePrice(void);

		__int64 GetIdBasEd(__int64 id_nom);

		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;
		__int64 IdTypePrice;

		__int64 IdFirm;
		__int64 IdSklad;
		__int64 IdKlient;
		__int64 IdTNom;
		__int64 IdNom;
		__int64 IdZ;
		bool CheckOst;
		bool OnlyChange;
		bool PriceSklad;
		bool OnlyOstatok;



		__int64 GetIDElement(String gid);
		AnsiString GetGIDElement(__int64 id);
		int PorNumberString;
		__int64 GetIdGrpNom(__int64 id_nom);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprNomVZip *DMSprNomVZip;
//---------------------------------------------------------------------------
#endif
