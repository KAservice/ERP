//---------------------------------------------------------------------------

#ifndef UREM_DMZayavkaImageH
#define UREM_DMZayavkaImageH
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
class TREM_DMZayavkaImage : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBLargeIntField *TableID_REM_ZIMAGE;
	TFIBLargeIntField *TableIDBASE_REM_ZIMAGE;
	TFIBLargeIntField *TableIDZ_REM_ZIMAGE;
	TFIBWideStringField *TableNAME_REM_ZIMAGE;
	TFIBSmallIntField *TableSHOWUSER_REM_ZIMAGE;
	TFIBBlobField *TableIMAGE_REM_ZIMAGE;
	TFIBLargeIntField *ElementID_REM_ZIMAGE;
	TFIBLargeIntField *ElementIDBASE_REM_ZIMAGE;
	TFIBLargeIntField *ElementIDZ_REM_ZIMAGE;
	TFIBWideStringField *ElementNAME_REM_ZIMAGE;
	TFIBSmallIntField *ElementSHOWUSER_REM_ZIMAGE;
	TFIBBlobField *ElementIMAGE_REM_ZIMAGE;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TREM_DMZayavkaImage(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //��������� ������ ����������
		GUID ClsIdImpl;				 //GUID ������ ����������

		//�� ���� ����� ������� ������ ��� ������
		//��������� ������� ������ � ������ ����� (������� ���� ������� �� ���� ��� ������ ����-��)
		int ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������ (����� � ������� ������������ �����)
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									);


		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);


		void OpenTable(__int64 id_z);
		int OpenElement(__int64 id );
		bool NewElement(__int64 id_z);
        bool SaveElement(void);
		bool DeleteElement(__int64 id);

		__int64 IdElement;

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMZayavkaImage *REM_DMZayavkaImage;
//---------------------------------------------------------------------------
#endif
