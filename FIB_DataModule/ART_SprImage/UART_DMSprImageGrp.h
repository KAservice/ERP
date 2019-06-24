//---------------------------------------------------------------------------

#ifndef UART_DMSprImageGrpH
#define UART_DMSprImageGrpH
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
class TART_DMSprImageGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_ART_IMG_GRP;
	TFIBLargeIntField *TableIDBASE_ART_IMG_GRP;
	TFIBWideStringField *TableGUID_ART_IMG_GRP;
	TFIBDateTimeField *TablePOS_ISM_ART_IMG_GRP;
	TFIBLargeIntField *TableIDGRP_ART_IMG_GRP;
	TFIBWideStringField *TableGUIDGRP_ART_IMG_GRP;
	TFIBWideStringField *TableNAME_ART_IMG_GRP;
	TFIBLargeIntField *ElementID_ART_IMG_GRP;
	TFIBLargeIntField *ElementIDBASE_ART_IMG_GRP;
	TFIBWideStringField *ElementGUID_ART_IMG_GRP;
	TFIBDateTimeField *ElementPOS_ISM_ART_IMG_GRP;
	TFIBLargeIntField *ElementIDGRP_ART_IMG_GRP;
	TFIBWideStringField *ElementGUIDGRP_ART_IMG_GRP;
	TFIBWideStringField *ElementNAME_ART_IMG_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TART_DMSprImageGrp(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Error;
		UnicodeString TextError;

		bool Init(void);
		int Done(void);


        void OpenTable(void);
		int OpenElement(__int64 id);
		void NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);


		__int64 FindPoName(UnicodeString name);
};
//---------------------------------------------------------------------------
extern PACKAGE TART_DMSprImageGrp *ART_DMSprImageGrp;
//---------------------------------------------------------------------------
#endif
