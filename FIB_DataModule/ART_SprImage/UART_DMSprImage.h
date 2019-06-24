//---------------------------------------------------------------------------

#ifndef UART_DMSprImageH
#define UART_DMSprImageH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"


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
#include <DBClient.hpp>
//---------------------------------------------------------------------------
class TART_DMSprImage : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TFIBLargeIntField *ElementID_ART_IMG;
	TFIBLargeIntField *ElementIDBASE_ART_IMG;
	TFIBWideStringField *ElementGUID_ART_IMG;
	TFIBDateTimeField *ElementPOS_ISM_ART_IMG;
	TFIBLargeIntField *ElementIDGRP_ART_IMG;
	TFIBWideStringField *ElementGUIDGRP_ART_IMG;
	TFIBWideStringField *ElementNAME_ART_IMG;
	TFIBWideStringField *ElementTEXT_ART_IMG;
	TFIBIntegerField *ElementHEIGHT_ART_IMG;
	TFIBIntegerField *ElementWIDTH_ART_IMG;
	TFIBBlobField *ElementIMAGE_ART_IMG;
	TFIBLargeIntField *TableID_ART_IMG;
	TFIBLargeIntField *TableIDBASE_ART_IMG;
	TFIBWideStringField *TableGUID_ART_IMG;
	TFIBDateTimeField *TablePOS_ISM_ART_IMG;
	TFIBLargeIntField *TableIDGRP_ART_IMG;
	TFIBWideStringField *TableGUIDGRP_ART_IMG;
	TFIBWideStringField *TableNAME_ART_IMG;
	TFIBWideStringField *TableTEXT_ART_IMG;
	TFIBIntegerField *TableHEIGHT_ART_IMG;
	TFIBIntegerField *TableWIDTH_ART_IMG;
	TFIBBlobField *TableIMAGE_ART_IMG;
        void __fastcall DataModuleDestroy(TObject *Sender);



private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TART_DMSprImage(TComponent* Owner);

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


		void OpenTable(__int64 id_grp, bool all);
		UnicodeString GetTextQuery(__int64 id_grp, bool all);
		int OpenElement(__int64 id );
		bool NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		void ChancheGrp(__int64 id_new_grp,__int64 id_prop);

		//поиск
		__int64 FindPoName(UnicodeString name);


		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;

		__int64 GetIdGrp(__int64 id_el);

};
//---------------------------------------------------------------------------
extern PACKAGE TART_DMSprImage *ART_DMSprImage;
//---------------------------------------------------------------------------
#endif
