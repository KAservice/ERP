//---------------------------------------------------------------------------

#ifndef UDMSprVidImageGrpH
#define UDMSprVidImageGrpH
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
class TDMSprVidImageGrp : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBQuery *pFIBQ;
	TFIBLargeIntField *TableID_SVIDIMAGE_GRP;
	TFIBLargeIntField *TableIDBASE_SVIDIMAGE_GRP;
	TFIBWideStringField *TableGID_SVIDIMAGE_GRP;
	TFIBLargeIntField *TableIDGRP_SVIDIMAGE_GRP;
	TFIBWideStringField *TableNAME_SVIDIMAGE_GRP;
	TIntegerField *TableRECNO;
	TFIBLargeIntField *ElementID_SVIDIMAGE_GRP;
	TFIBLargeIntField *ElementIDBASE_SVIDIMAGE_GRP;
	TFIBWideStringField *ElementGID_SVIDIMAGE_GRP;
	TFIBLargeIntField *ElementIDGRP_SVIDIMAGE_GRP;
	TFIBWideStringField *ElementNAME_SVIDIMAGE_GRP;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMSprVidImageGrp(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	IkanUnknown * InterfaceImpl; //��������� ������ ����������
	GUID ClsIdImpl;				 //GUID ������ ����������
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
extern PACKAGE TDMSprVidImageGrp *DMSprVidImageGrp;
//---------------------------------------------------------------------------
#endif
