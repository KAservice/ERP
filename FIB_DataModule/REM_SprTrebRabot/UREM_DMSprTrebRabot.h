//---------------------------------------------------------------------------

#ifndef UREM_DMSprTrebRabotH
#define UREM_DMSprTrebRabotH
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
class TREM_DMSprTrebRabot : public TDataModule
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
	TFIBLargeIntField *TableID_REM_STREBRABOT;
	TFIBWideStringField *TableGID_REM_STREBRABOT;
	TFIBLargeIntField *TableIDBASE_REM_STREBRABOT;
	TFIBLargeIntField *TableIDDMN_REM_STREBRABOT;
	TFIBLargeIntField *TableIDTYPRABOT_REM_STREBRABOT;
	TFIBWideStringField *TableNAME_REM_STREBRABOT;
	TFIBWideStringField *TableNAME_REM_STYPRABOT;
	TFIBLargeIntField *ElementID_REM_STREBRABOT;
	TFIBWideStringField *ElementGID_REM_STREBRABOT;
	TFIBLargeIntField *ElementIDBASE_REM_STREBRABOT;
	TFIBLargeIntField *ElementIDDMN_REM_STREBRABOT;
	TFIBLargeIntField *ElementIDTYPRABOT_REM_STREBRABOT;
	TFIBWideStringField *ElementNAME_REM_STREBRABOT;
	TFIBWideStringField *ElementNAME_REM_STYPRABOT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall TREM_DMSprTrebRabot(TComponent* Owner);

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
extern PACKAGE TREM_DMSprTrebRabot *REM_DMSprTrebRabot;
//---------------------------------------------------------------------------
#endif
