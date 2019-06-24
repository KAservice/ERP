//---------------------------------------------------------------------------

#ifndef UHLP_DMSprImageH
#define UHLP_DMSprImageH
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
class THLP_DMSprImage : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_HLP_IMG;
	TFIBLargeIntField *TableIDBASE_HLP_IMG;
	TFIBWideStringField *TableGUID_HLP_IMG;
	TFIBDateTimeField *TablePOS_ISM_HLP_IMG;
	TFIBLargeIntField *TableIDGRP_HLP_IMG;
	TFIBWideStringField *TableGUIDGRP_HLP_IMG;
	TFIBWideStringField *TableNAME_HLP_IMG;
	TFIBWideStringField *TableTEXT_HLP_IMG;
	TFIBIntegerField *TableHEIGHT_HLP_IMG;
	TFIBIntegerField *TableWIDTH_HLP_IMG;
	TFIBBlobField *TableIMAGE_HLP_IMG;
	TFIBIntegerField *TableINDEX_HLP_IMG;
	TFIBLargeIntField *ElementID_HLP_IMG;
	TFIBLargeIntField *ElementIDBASE_HLP_IMG;
	TFIBWideStringField *ElementGUID_HLP_IMG;
	TFIBDateTimeField *ElementPOS_ISM_HLP_IMG;
	TFIBLargeIntField *ElementIDGRP_HLP_IMG;
	TFIBWideStringField *ElementGUIDGRP_HLP_IMG;
	TFIBWideStringField *ElementNAME_HLP_IMG;
	TFIBWideStringField *ElementTEXT_HLP_IMG;
	TFIBIntegerField *ElementHEIGHT_HLP_IMG;
	TFIBIntegerField *ElementWIDTH_HLP_IMG;
	TFIBBlobField *ElementIMAGE_HLP_IMG;
	TFIBIntegerField *ElementINDEX_HLP_IMG;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);



private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall THLP_DMSprImage(TComponent* Owner);

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
extern PACKAGE THLP_DMSprImage *HLP_DMSprImage;
//---------------------------------------------------------------------------
#endif
