//---------------------------------------------------------------------------

#ifndef UDMSprInfBaseH
#define UDMSprInfBaseH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


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
class TDMSprInfBase : public TDataModule
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
	TFIBBCDField *TableID_SINFBASE_OBMEN;
	TFIBIntegerField *TableIDTIZM_SINFBASE_OBMEN;
	TFIBBCDField *ElementID_SINFBASE_OBMEN;
	TFIBIntegerField *ElementIDTIZM_SINFBASE_OBMEN;
	TFIBSmallIntField *ElementNOACT_SINFBASE_OBMEN;
	TFIBSmallIntField *TableNOACT_SINFBASE_OBMEN;
	TFIBWideStringField *TableGID_SINFBASE_OBMEN;
	TFIBWideStringField *TableNAME_SINFBASE_OBMEN;
	TFIBWideStringField *ElementGID_SINFBASE_OBMEN;
	TFIBWideStringField *ElementNAME_SINFBASE_OBMEN;
	TFIBWideStringField *ElementPREF_NUM_SINFBASE_OBMEN;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprInfBase(TComponent* Owner);


	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


        __int64 Id;
        bool Error;
		String TextError;

		__int64 GetIdPoPrefiks(AnsiString prefiks);
        __int64 GetIdPoName(AnsiString name);

        void OpenTable(void);
		int  OpenElement(__int64 id);
        void NewElement(void);
        bool SaveElement(void);
		void DeleteElement(__int64 id);



};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprInfBase *DMSprInfBase;
//---------------------------------------------------------------------------
#endif
