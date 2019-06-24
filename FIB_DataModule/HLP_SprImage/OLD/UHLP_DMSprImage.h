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
	TIntegerField *TableRECNO;
	TpFIBQuery *Query;
	TFIBLargeIntField *ElementID_HLP_IMAGE;
	TFIBLargeIntField *ElementIDBASE_HLP_IMAGE;
	TFIBWideStringField *ElementGID_HLP_IMAGE;
	TFIBWideStringField *ElementGUID_HLP_IMAGE;
	TFIBWideStringField *ElementGUIDELEMENT_HLP_IMAGE;
	TFIBWideStringField *ElementTEXT_HLP_IMAGE;
	TFIBSmallIntField *ElementTYPE_HLP_IMAGE;
	TFIBWideStringField *ElementNAME_HLP_IMAGE;
	TFIBBlobField *ElementIMAGE_HLP_IMAGE;
	TFIBWideStringField *ElementGUIDGRP_HLP_IMAGE;
	TFIBLargeIntField *ElementIDGRP_HLP_IMAGE;
	TFIBLargeIntField *TableID_HLP_IMAGE;
	TFIBLargeIntField *TableIDBASE_HLP_IMAGE;
	TFIBWideStringField *TableGID_HLP_IMAGE;
	TFIBWideStringField *TableGUID_HLP_IMAGE;
	TFIBWideStringField *TableGUIDELEMENT_HLP_IMAGE;
	TFIBWideStringField *TableTEXT_HLP_IMAGE;
	TFIBSmallIntField *TableTYPE_HLP_IMAGE;
	TFIBWideStringField *TableNAME_HLP_IMAGE;
	TFIBBlobField *TableIMAGE_HLP_IMAGE;
	TFIBWideStringField *TableGUIDGRP_HLP_IMAGE;
	TFIBLargeIntField *TableIDGRP_HLP_IMAGE;
	TFIBIntegerField *TableHEIGHT_HLP_IMAGE;
	TFIBIntegerField *TableWIDTH_HLP_IMAGE;
	TFIBIntegerField *ElementHEIGHT_HLP_IMAGE;
	TFIBIntegerField *ElementWIDTH_HLP_IMAGE;
        void __fastcall DataModuleDestroy(TObject *Sender);



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
