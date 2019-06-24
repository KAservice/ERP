//---------------------------------------------------------------------------

#ifndef UREM_DMSprTrebUslovH
#define UREM_DMSprTrebUslovH
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
class TREM_DMSprTrebUslov : public TDataModule
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
	TFIBLargeIntField *TableID_REM_STREBUSLOV;
	TFIBWideStringField *TableGID_REM_STREBUSLOV;
	TFIBLargeIntField *TableIDBASE_REM_STREBUSLOV;
	TFIBLargeIntField *TableIDDMN_REM_STREBUSLOV;
	TFIBLargeIntField *TableIDTYPUSLA_REM_STREBUSLOV;
	TFIBWideStringField *TableNAME_REM_STREBUSLOV;
	TFIBWideStringField *TableNAME_REM_STYPUSLOV;
	TFIBLargeIntField *ElementID_REM_STREBUSLOV;
	TFIBWideStringField *ElementGID_REM_STREBUSLOV;
	TFIBLargeIntField *ElementIDBASE_REM_STREBUSLOV;
	TFIBLargeIntField *ElementIDDMN_REM_STREBUSLOV;
	TFIBLargeIntField *ElementIDTYPUSLA_REM_STREBUSLOV;
	TFIBWideStringField *ElementNAME_REM_STREBUSLOV;
	TFIBWideStringField *ElementNAME_REM_STYPUSLOV;
	TpFIBDatabase *pFIBDatabase1;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall TREM_DMSprTrebUslov(TComponent* Owner);

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

		void OpenTable(__int64 id_defect_model_neispr);
		int OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(__int64 id_defect_model_neispr);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);


};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMSprTrebUslov *REM_DMSprTrebUslov;
//---------------------------------------------------------------------------
#endif
