//---------------------------------------------------------------------------

#ifndef UDMExtModuleGrpH
#define UDMExtModuleGrpH
//---------------------------------------------------------------------------

#include "IDMFibConnection.h"
//------------------------------------------------------------------------------
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
class TDMExtModuleGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableID_EXT_MODULE_GRP;
	TFIBBCDField *TableIDGRP_EXT_MODULE_GRP;
	TFIBBCDField *ElementID_EXT_MODULE_GRP;
	TFIBBCDField *ElementIDGRP_EXT_MODULE_GRP;
	TFIBWideStringField *TableNAME_EXT_MODULE_GRP;
	TFIBWideStringField *ElementNAME_EXT_MODULE_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
        __fastcall TDMExtModuleGrp(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//из этой формы открыта другая для выбора
		//обработка события выбора в другой форме (которая была открыта из этой для выбора чего-то)
		int ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект (форму в которой производится выбор)
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									);


		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);


        void OpenTable(void);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);


		__int64 FindPoName(AnsiString name);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMExtModuleGrp *DMExtModuleGrp;
//---------------------------------------------------------------------------
#endif
