//---------------------------------------------------------------------------

#ifndef UDMSprLossFactorH
#define UDMSprLossFactorH
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
class TDMSprLossFactor : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *Query;
	TFIBLargeIntField *TableID_SLOSS_FACTOR;
	TFIBWideStringField *TableGID_SLOSS_FACTOR;
	TFIBLargeIntField *TableIDBASE_SLOSS_FACTOR;
	TFIBWideStringField *TableNAME_SLOSS_FACTOR;
	TFIBWideStringField *TableCOMMENT_SLOSS_FACTOR;
	TFIBBCDField *TableENCEN_SLOSS_FACTOR;
	TFIBBCDField *TableBELKI_SLOSS_FACTOR;
	TFIBBCDField *TableGIRI_SLOSS_FACTOR;
	TFIBBCDField *TableUGL_SLOSS_FACTOR;
	TFIBWideStringField *TableCODE_SLOSS_FACTOR;
	TFIBLargeIntField *TableIDGRP_SLOSS_FACTOR;
	TFIBLargeIntField *ElementID_SLOSS_FACTOR;
	TFIBWideStringField *ElementGID_SLOSS_FACTOR;
	TFIBLargeIntField *ElementIDBASE_SLOSS_FACTOR;
	TFIBWideStringField *ElementNAME_SLOSS_FACTOR;
	TFIBWideStringField *ElementCOMMENT_SLOSS_FACTOR;
	TFIBBCDField *ElementENCEN_SLOSS_FACTOR;
	TFIBBCDField *ElementBELKI_SLOSS_FACTOR;
	TFIBBCDField *ElementGIRI_SLOSS_FACTOR;
	TFIBBCDField *ElementUGL_SLOSS_FACTOR;
	TFIBWideStringField *ElementCODE_SLOSS_FACTOR;
	TFIBLargeIntField *ElementIDGRP_SLOSS_FACTOR;
        void __fastcall DataModuleDestroy(TObject *Sender);



private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
        __fastcall TDMSprLossFactor(TComponent* Owner);

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


		bool OpenTable(__int64 id_grp, bool all);
		UnicodeString GetTextQuery(__int64 id_grp, bool all);
		bool OpenElement(__int64 id );
		bool NewElement(__int64 id_grp);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);
		bool ChancheGrp(__int64 id_new_grp,__int64 id_el);

		//поиск
		__int64 FindPoName(UnicodeString name);

		__int64 IdGrp;
        bool AllElement;
		__int64 IdElement;

		__int64 GetIDElement(UnicodeString gid);
		UnicodeString GetGIDElement(__int64 id);

		__int64 GetIdGrp(__int64 id_el);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprLossFactor *DMSprLossFactor;
//---------------------------------------------------------------------------
#endif
