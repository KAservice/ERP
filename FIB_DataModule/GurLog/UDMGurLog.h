//---------------------------------------------------------------------------

#ifndef UDMGurLogH
#define UDMGurLogH
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
class TDMGurLog : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBQuery *pFIBQ;
	TFIBDateTimeField *TablePOS_LOG;
	TFIBIntegerField *TableTYPE_LOG;
	TFIBIntegerField *TableOPER_LOG;
	TpFIBTransaction *IBTrUpdate;
	TFIBBCDField *TableID_LOG;
	TFIBBCDField *TableIDUSER_LOG;
	TFIBWideStringField *TableMESSAGE_LOG;
	TFIBIntegerField *TableOBJECT_LOG;
	TFIBWideStringField *TableNAME_USER;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMGurLog(TComponent* Owner);

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


		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме


		//Текущий интерфейс

        void OpenTable();
        void UpdateTable(void);


		__int64 IdUser;
		int Type;
		int ObjectLog;
		int Oper;

        bool OtborVkl;
		bool OtborPoUser;
		bool OtborPoType;
		bool OtborPoObject;
		bool OtborPoOper;
		TDateTime PosNach;
		TDateTime PosCon;
		

};
//---------------------------------------------------------------------------
extern PACKAGE TDMGurLog *DMGurLog;
//---------------------------------------------------------------------------
#endif
