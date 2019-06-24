//---------------------------------------------------------------------------

#ifndef UDMGurLogH
#define UDMGurLogH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

//------------------------------------------------------------------------------
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
class TDMGurLog : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBTransaction *IBTr;
	TpFIBQuery *pFIBQ;
	TFIBDateTimeField *TablePOS_LOG;
	TFIBIntegerField *TableTYPE_LOG;
	TFIBIntegerField *TableOPER_LOG;
	TpFIBTransaction *IBTrUpdate;
	TFIBBCDField *TableID_LOG;
	TFIBBCDField *TableIDUSER_LOG;
	TFIBWideStringField *TableMESSAGE_LOG;
	TFIBIntegerField *TableOBJECT_LOG;
	TFIBWideStringField *TableNAME_USER;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TDMGurLog(TComponent* Owner);

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


		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����


		//������� ���������

        void OpenTable();
        void UpdateTable(void);


		__int64 IdUser;
		int Type;
		int ObjectLog;
		int Oper;

        bool OtborVkl;
		bool OtborPoUser;
		bool OtborPoType;
		bool OtborPoObject;
		bool OtborPoOper;
		TDateTime PosNach;
		TDateTime PosCon;
		

};
//---------------------------------------------------------------------------
extern PACKAGE TDMGurLog *DMGurLog;
//---------------------------------------------------------------------------
#endif
