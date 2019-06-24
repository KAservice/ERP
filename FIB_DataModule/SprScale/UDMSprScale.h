//---------------------------------------------------------------------------

#ifndef UDMSprScaleH
#define UDMSprScaleH
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
class TDMSprScale : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TIntegerField *TableRECNO;
	TFIBBCDField *ElementID_SSCALE;
	TFIBBCDField *TableID_SSCALE;
	TFIBWideStringField *TableGID_SSCALE;
	TFIBWideStringField *TableNAME_SSCALE;
	TFIBWideStringField *ElementGID_SSCALE;
	TFIBWideStringField *ElementNAME_SSCALE;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall Table1CalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprScale(TComponent* Owner);


	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IkanUnknown * InterfaceImpl; //��������� ������ ����������
	GUID ClsIdImpl;				 //GUID ������ ����������
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        void OpenTable(void);
		int OpenElement(__int64 id);
        void NewElement(void);
        bool SaveElement(void);
		void DeleteElement(__int64 id);

        __int64 GetIDElement(String gid);

        bool Error;
        AnsiString TextError;

        

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprScale *DMSprScale;
//---------------------------------------------------------------------------
#endif
