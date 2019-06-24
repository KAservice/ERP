//---------------------------------------------------------------------------

#ifndef UDMRegPaySaleH
#define UDMRegPaySaleH
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
class TDMRegPaySale : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *DvRegOst;
	TpFIBDataSet *RegOst;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateTimeField *DvRegOstPOS_RGPAYSALE_DV;
	TFIBIntegerField *DvRegOstTDV_RGPAYSALE_DV;
	TFIBDateField *DvRegOstDATE_RGPAYSALE_DV;
	TFIBBCDField *DvRegOstSUM_RGPAYSALE_DV;
	TFIBDateField *RegOstDATE_RGPAYSALE;
	TFIBBCDField *RegOstSUM_RGPAYSALE;
	TFIBBCDField *RegOstID_RGPAYSALE;
	TFIBBCDField *RegOstIDFIRM_RGPAYSALE;
	TFIBBCDField *RegOstIDKLIENT_RGPAYSALE;
	TFIBBCDField *RegOstIDDOG_RGPAYSALE;
	TFIBBCDField *RegOstIDDOCSALE_RGPAYSALE;
	TFIBBCDField *DvRegOstID_RGPAYSALE_DV;
	TFIBBCDField *DvRegOstIDDOC_RGPAYSALE_DV;
	TFIBBCDField *DvRegOstIDFIRM_RGPAYSALE_DV;
	TFIBBCDField *DvRegOstIDKLIENT_RGPAYSALE_DV;
	TFIBBCDField *DvRegOstIDDOG_RGPAYSALE_DV;
	TFIBBCDField *DvRegOstIDDOCSALE_RGPAYSALE_DV;
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TDMRegPaySale(TComponent* Owner);

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


		__int64 IdDoc;  //��������
        TDateTime PosDoc;
		__int64 IdFirm;
		__int64 IdKlient;
		__int64 IdDogovor;
        __int64 IdDocSale;
        TDate DatePay;
        float Sum;


        bool AddRecordPrihod(void);
        bool AddRecordRashod(void);
        bool UpdateTableOst(void);
        bool CancelDvReg(void);




};
//---------------------------------------------------------------------------
extern PACKAGE TDMRegPaySale *DMRegPaySale;
//---------------------------------------------------------------------------
#endif
