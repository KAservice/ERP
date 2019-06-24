
#ifndef UREM_DMSprHardwareVZipH
#define UREM_DMSprHardwareVZipH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


//----------------------------------------------------------------------------


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
class TREM_DMSprHardwareVZip : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBQuery *Query;
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
	TFIBLargeIntField *TableOUT_IDHW;
	TFIBWideStringField *TableOUT_NAME_HW;
	TFIBWideStringField *TableOUT_SERNUM1_HW;
	TFIBWideStringField *TableOUT_SERNUM2_HW;
	TFIBWideStringField *TableOUT_MODEL_HW;
	TFIBWideStringField *TableOUT_PRMODEL_HW;
	TFIBIntegerField *TableOUT_CODE_HW;
	TFIBWideStringField *TableOUT_ARTIKUL_HW;
	TFIBWideStringField *TableOUT_NAME_ENG_HW;
	TFIBSmallIntField *TableOUT_FL_ACT_HW;
	TFIBSmallIntField *TableOUT_FL_REMONT_HW;
	TFIBSmallIntField *TableOUT_FL_NECOND_HW;
	TFIBWideStringField *TableOUT_NAME_BRAND_HW;
	TFIBWideStringField *TableOUT_NAME_PRODUCER_HW;
	TFIBLargeIntField *TableOUT_IDGRPHW;
	TFIBLargeIntField *TableOUT_IDMHRAN;
	TFIBWideStringField *TableOUT_NAME_MHRAN;
	TFIBSmallIntField *TableOUT_FL_OTCH_PROIZV;
	TFIBSmallIntField *TableOUT_FL_NO_RAZBOR;
		void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


		int GetCodeNom(void);
		bool CheckCode(__int64 id_hw, int code);

        bool flCentralBase;
public:		// User declarations
		__fastcall TREM_DMSprHardwareVZip(TComponent* Owner);

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

		void OpenTable(__int64 id_grp, bool all);
		__int64 GetIdGrpElementa(__int64 id_element);

		//поиск
		__int64 FindPoName(UnicodeString name);

		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;
		__int64 IdFirm;
		__int64 IdSklad;
		__int64 IdKlient;
		__int64 IdTNom;
		__int64 IdNom;
		__int64 IdZ;


		//поиск по заводскому номеру
		bool Table_FindPoSerNum1Like(__int64 id_grp, bool all, UnicodeString ser_num);
		//поиск по заводскому номеру2
		bool Table_FindPoSerNum2Like(__int64 id_grp, bool all, UnicodeString ser_num);
		//поиск по заводскому номеру строка
        bool Table_FindPoSerNumStrLike(__int64 id_grp, bool all, UnicodeString ser_num);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprHardwareVZip *REM_DMSprHardwareVZip;
//---------------------------------------------------------------------------
#endif
