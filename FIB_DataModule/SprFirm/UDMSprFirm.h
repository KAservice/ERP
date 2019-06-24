//---------------------------------------------------------------------------

#ifndef UDMSprFirmH
#define UDMSprFirmH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
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
class TDMSprFirm : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceElement;
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBSmallIntField *ElementTYPEFIRM;
	TpFIBQuery *pFIBQ;
	TFIBBCDField *TableIDFIRM;
	TFIBBCDField *ElementIDFIRM;
	TFIBWideStringField *TableINNFIRM;
	TFIBWideStringField *TableNAMEFIRM;
	TFIBWideStringField *ElementNAMEFIRM;
	TFIBWideStringField *ElementFNAMEFIRM;
	TFIBWideStringField *ElementPADRFIRM;
	TFIBWideStringField *ElementUADRFIRM;
	TFIBWideStringField *ElementINNFIRM;
	TFIBWideStringField *ElementKPPFIRM;
	TFIBWideStringField *ElementDIRFIRM;
	TFIBWideStringField *ElementBUHFIRM;
	TFIBWideStringField *ElementKASFIRM;
	TFIBWideStringField *ElementGID_SFIRM;
	TFIBWideStringField *ElementNUMDOCREGFIRM;
	TFIBWideStringField *ElementOKPOSFIRM;
	TFIBWideStringField *ElementOKDPSFIRM;
	TFIBWideStringField *ElementTELFIRM;
	TFIBBCDField *ElementIDBASE_SFIRM;
	TFIBWideStringField *ElementKRNAMEFIRM;
	TFIBWideStringField *ElementDATEDOCREGFIRM;
	TFIBWideStringField *ElementPREFIKS_NUM_SFIRM;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		void GetPriv(void);
public:		// User declarations
		__fastcall TDMSprFirm(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;

        bool Error;
		UnicodeString TextError;


		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);




		bool OpenTable(void);
		int  OpenElement(__int64 Id);  //возвращает количество элементов
		bool NewElement(void);
		bool SaveElement(void);
		bool DeleteElement(__int64 Id);

		UnicodeString GetGIDElement(__int64 id);
		__int64 GetIDElement(AnsiString gid);

		int GetIndexElementaPoID(__int64 id);





};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprFirm *DMSprFirm;
//---------------------------------------------------------------------------
#endif
