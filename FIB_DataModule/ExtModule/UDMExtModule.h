//---------------------------------------------------------------------------

#ifndef UDMExtModuleH
#define UDMExtModuleH
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
class TDMExtModule : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBBCDField *TableID_EXT_MODULE;
	TFIBBCDField *TableIDGRP_EXT_MODULE;
	TFIBSmallIntField *TableTYPE_EXT_MODULE;
	TFIBSmallIntField *TableISP_EXT_MODULE;
	TFIBBCDField *ElementID_EXT_MODULE;
	TFIBBCDField *ElementIDGRP_EXT_MODULE;
	TFIBSmallIntField *ElementTYPE_EXT_MODULE;
	TFIBSmallIntField *ElementISP_EXT_MODULE;
	TFIBBlobField *ElementBODY_EXT_MODULE;
	TFIBIntegerField *ElementRESIDENCE_EXT_MODULE;
	TFIBWideStringField *TableNAME_EXT_MODULE;
	TFIBWideStringField *TableFILE_NAME_EXT_MODULE;
	TFIBWideStringField *ElementNAME_EXT_MODULE;
	TFIBWideStringField *ElementFILE_NAME_EXT_MODULE;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
AnsiString GetTextQuery(__int64 id_grp, bool all) ;
public:		// User declarations
		__fastcall TDMExtModule(TComponent* Owner);

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


		void OpenTable(__int64 id_grp, bool all);
		int OpenElement(__int64 id );
		bool NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void ChancheGrp(__int64 new_id_grp);

		//поиск
		__int64 FindPoName(AnsiString name);

		__int64 IdGrp;
		bool AllElement;
		__int64 IdElement;


		__int64 GetIdGrpExtModule(__int64 id_ext_module);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMExtModule *DMExtModule;
//---------------------------------------------------------------------------
#endif
