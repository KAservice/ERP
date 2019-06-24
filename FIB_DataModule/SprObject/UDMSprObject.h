//---------------------------------------------------------------------------

#ifndef UDMSprObjectH
#define UDMSprObjectH
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
class TDMSprObject : public TDataModule
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
	TFIBLargeIntField *TableID_SOBJECT;
	TFIBWideStringField *TableNAME_SOBJECT;
	TFIBLargeIntField *TableIDINFBASE_SOBJECT;
	TFIBLargeIntField *TableIDFIRM_SOBJECT;
	TFIBLargeIntField *TableIDSKLAD_SOBJECT;
	TFIBLargeIntField *TableIDKASSA_SOBJECT;
	TFIBLargeIntField *TableIDPODR_SOBJECT;
	TFIBWideStringField *TableNAME_SINFBASE_OBMEN;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *TableNAMESKLAD;
	TFIBWideStringField *TableNAMEKKM;
	TFIBWideStringField *TableNAMEPOD;
	TFIBLargeIntField *ElementID_SOBJECT;
	TFIBLargeIntField *ElementIDBASE_SOBJECT;
	TFIBWideStringField *ElementNAME_SOBJECT;
	TFIBLargeIntField *ElementIDINFBASE_SOBJECT;
	TFIBLargeIntField *ElementIDFIRM_SOBJECT;
	TFIBLargeIntField *ElementIDSKLAD_SOBJECT;
	TFIBLargeIntField *ElementIDKASSA_SOBJECT;
	TFIBLargeIntField *ElementIDPODR_SOBJECT;
	TFIBWideStringField *ElementNAME_SINFBASE_OBMEN;
	TFIBWideStringField *ElementNAMEFIRM;
	TFIBWideStringField *ElementNAMESKLAD;
	TFIBWideStringField *ElementNAMEKKM;
	TFIBWideStringField *ElementNAMEPOD;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations


bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprObject(TComponent* Owner);

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
extern PACKAGE TDMSprObject *DMSprObject;
//---------------------------------------------------------------------------
#endif
