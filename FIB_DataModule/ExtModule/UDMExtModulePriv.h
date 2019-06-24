//---------------------------------------------------------------------------

#ifndef UDMExtModulePrivH
#define UDMExtModulePrivH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
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
class TDMExtModulePriv : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBBCDField *TableIDMODULE_EXT_MODULE_PRIV;
	TFIBSmallIntField *TableINS_EXT_MODULE_PRIV;
	TFIBSmallIntField *TableEDIT_EXT_MODULE_PRIV;
	TFIBSmallIntField *TableDEL_EXT_MODULE_PRIV;
	TFIBSmallIntField *TableEXEC_EXT_MODULE_PRIV;
	TFIBBCDField *TableID_EXT_MODULE_PRIV;
	TFIBBCDField *TableIDGRPUSER_EXT_MODULE_PRIV;
	TpFIBDataSet *SprGrpUser;
	TDataSource *DataSourceSprGrpUser;
	TFIBBCDField *SprGrpUserID_SGRPUSER;
	TpFIBQuery *Query;
	TFIBWideStringField *SprGrpUserNAME_SGRPUSER;
	TFIBWideStringField *SprGrpUserROLE_SGRPUSER;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableNewRecord(TDataSet *DataSet);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
		__fastcall TDMExtModulePriv(TComponent* Owner);

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


		void OpenTable(__int64 id_module);
        void SaveIsmen(void);
        void CancelIsmen(void);
		void DeleteElement(__int64 id);

		__int64 IdModule;
		__int64 IdGrpUser;

		bool CheckPriv(__int64 id_module, __int64 idgrp_user);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMExtModulePriv *DMExtModulePriv;
//---------------------------------------------------------------------------
#endif
