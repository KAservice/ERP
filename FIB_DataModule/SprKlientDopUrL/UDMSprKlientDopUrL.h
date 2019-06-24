//---------------------------------------------------------------------------

#ifndef UDMSprKlientDopUrLH
#define UDMSprKlientDopUrLH
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
//---------------------------------------------------------------------------
class TDMSprKlientDopUrL : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceElement;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBBCDField *ElementID_SKLIENT_DOPURL;
	TFIBBCDField *ElementIDKLIENT_SKLIENT_DOPURL;
	TFIBWideStringField *ElementGID_SKLIENT_DOPURL;
	TFIBWideStringField *ElementNAMEKLIENT;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprKlientDopUrL(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        int OpenElement(void);
        void NewElement(void);
        bool SaveElement(void);
        bool DeleteElement(void);

		__int64 Id;
        __int64 IdKlient;
        bool Error;
        String TextError;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprKlientDopUrL *DMSprKlientDopUrL;
//---------------------------------------------------------------------------
#endif
