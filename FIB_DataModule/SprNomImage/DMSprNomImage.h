//---------------------------------------------------------------------------

#ifndef DMSprNomImageH
#define DMSprNomImageH
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
class TDMSprNomImage : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBLargeIntField *TableID_SNOMIMAGE;
	TFIBLargeIntField *TableIDBASE_SNOMIMAGE;
	TFIBWideStringField *TableGID_SNOMIMAGE;
	TFIBLargeIntField *TableIDVIDIMAGE_SNOMIMAGE;
	TFIBLargeIntField *TableIDNOM_SNOMIMAGE;
	TFIBWideStringField *TableNAME_SNOMIMAGE;
	TFIBBlobField *TableBODY_SNOMIMAGE;
	TFIBBlobField *TableBODY_SMALL_SNOMIMAGE;
	TFIBLargeIntField *ElementID_SNOMIMAGE;
	TFIBLargeIntField *ElementIDBASE_SNOMIMAGE;
	TFIBWideStringField *ElementGID_SNOMIMAGE;
	TFIBLargeIntField *ElementIDVIDIMAGE_SNOMIMAGE;
	TFIBLargeIntField *ElementIDNOM_SNOMIMAGE;
	TFIBWideStringField *ElementNAME_SNOMIMAGE;
	TFIBBlobField *ElementBODY_SNOMIMAGE;
	TFIBBlobField *ElementBODY_SMALL_SNOMIMAGE;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TDMSprNomImage(TComponent* Owner);

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


		void OpenTable(__int64 id_nom);
		int OpenElement(__int64 id );
		bool NewElement(__int64 id_nom);
		bool SaveElement(void);
		bool DeleteElement(__int64 id);

		__int64 IdElement;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprNomImage *DMSprNomImage;
//---------------------------------------------------------------------------
#endif
