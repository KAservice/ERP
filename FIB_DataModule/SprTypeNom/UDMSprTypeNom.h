//---------------------------------------------------------------------------

#ifndef UDMSprTypeNomH
#define UDMSprTypeNomH
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
class TDMSprTypeNom : public TDataModule
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
	TFIBLargeIntField *TableID_STNOM;
	TFIBLargeIntField *TableIDBASE_STNOM;
	TFIBWideStringField *TableNAME_STNOM;
	TFIBLargeIntField *ElementID_STNOM;
	TFIBLargeIntField *ElementIDBASE_STNOM;
	TFIBWideStringField *ElementNAME_STNOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations


bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprTypeNom(TComponent* Owner);

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

        bool OpenTable(void);
		bool  OpenElement(__int64 id);  //возвращает количество элементов
		bool NewElement(void);
        bool SaveElement(void);
        void CloseElement(void);
		bool DeleteElement(__int64 id);

		__int64 GetIdElementPoName(UnicodeString   name);
		int GetIndexInTablePoId(__int64 id_element);

		__int64 GetIdElementPoGid(UnicodeString gid);
		UnicodeString GetGidElementPoId(__int64 id);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprTypeNom *DMSprTypeNom;
//---------------------------------------------------------------------------
#endif
