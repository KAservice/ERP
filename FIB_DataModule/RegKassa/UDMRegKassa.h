//---------------------------------------------------------------------------

#ifndef UDMRegKassaH
#define UDMRegKassaH
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
//---------------------------------------------------------------------------
class TDMRegKassa : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *DvRegOst;
	TpFIBDataSet *RegOst;
	TpFIBDataSet *Dv;
	TpFIBDataSet *Ostatok;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateTimeField *DvRegOstPOSDOC_RGKASSA_DV;
	TFIBSmallIntField *DvRegOstTDV_RGKASSA_DV;
	TFIBBCDField *DvRegOstSUM_RGKASSA_DV;
	TFIBIntegerField *DvRegOstOPER_RGKASSA_DV;
	TFIBBCDField *RegOstSUM_RGKASSA;
	TFIBBCDField *DvSUMDV;
	TFIBBCDField *OstatokSUMOST;
	TFIBBCDField *RegOstID_RGKASSA;
	TFIBBCDField *RegOstIDFIRM_RGKASSA;
	TFIBBCDField *RegOstIDKKM_RGKASSA;
	TFIBBCDField *DvRegOstID_RGKASSA_DV;
	TFIBBCDField *DvRegOstIDDOC_RGKASSA_DV;
	TFIBBCDField *DvRegOstIDFIRM_RGKASSA_DV;
	TFIBBCDField *DvRegOstIDKKM_RGKASSA_DV;
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TDMRegKassa(TComponent* Owner);

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

		//������� ���������
        int GetOstatok(void);

		__int64 IdDoc;  //��������
        TDateTime PosDoc;

		__int64 IdFirm;
		__int64 IdKKM;
        double Sum;
        int Operation;

        bool AddRecordPrihod(void);
        bool AddRecordRashod(void);
        bool UpdateTableOst(void);
        bool CancelDvReg(void);

        bool GetOstatokNa(TDateTime Pos, __int64 id_firm, __int64 id_kassa);
        double SumOstNa;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMRegKassa *DMRegKassa;
//---------------------------------------------------------------------------
#endif
