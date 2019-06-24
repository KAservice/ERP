//---------------------------------------------------------------------------

#ifndef UDMDataSetH
#define UDMDataSetH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBQuery.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDMDataSet : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBTransaction *Transaction;
	TpFIBDataSet *DataSet;
	TDataSource *DataSource;
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDMDataSet(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации

	typedef  void (__closure * TFunctionDeleteImplType)(void);
	TFunctionDeleteImplType FunctionDeleteImpl;
	bool flDeleteImpl;


	bool Init(void);
	int Done(void);

	UnicodeString TextError;
	int CodeError;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMDataSet *DMDataSet;
//---------------------------------------------------------------------------
#endif
