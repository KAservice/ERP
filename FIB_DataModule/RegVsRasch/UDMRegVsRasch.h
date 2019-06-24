//---------------------------------------------------------------------------

#ifndef UDMRegVsRaschH
#define UDMRegVsRaschH
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
class TDMRegVsRasch : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *DvRegOst;
	TpFIBDataSet *RegOst;
	TpFIBDataSet *Dv;
	TpFIBDataSet *Ostatok;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateTimeField *DvRegOstPOSDOC_VSRASCH_DV;
	TFIBSmallIntField *DvRegOstTDV_VSRASCH_DV;
	TFIBBCDField *DvRegOstSUM_VSRASCH_DV;
	TFIBBCDField *RegOstSUM_VSRASCH;
	TFIBBCDField *DvSUMDV;
	TFIBBCDField *OstatokSUMOST;
	TFIBBCDField *RegOstID_VSRASCH;
	TFIBBCDField *RegOstIDFIRM_VSRASCH;
	TFIBBCDField *RegOstIDKLIENT_VSRASCH;
	TFIBBCDField *RegOstIDDOG_VSRASCH;
	TFIBBCDField *DvRegOstID_VSRASCH_DV;
	TFIBBCDField *DvRegOstIDDOC_VSRASCH_DV;
	TFIBBCDField *DvRegOstIDFIRM_VSRASCH_DV;
	TFIBBCDField *DvRegOstIDKLIENT_VSRASCH_DV;
	TFIBBCDField *DvRegOstIDDOG_VSRASCH_DV;
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TDMRegVsRasch(TComponent* Owner);

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
		__int64 IdKlient;
        float Sum;

        bool AddRecordPrihod(void);
        bool AddRecordRashod(void);
        bool UpdateTableOst(bool provedenie);
        bool CancelDvReg(void);
        
        float SumOstNa;
        bool GetOstatokNa(TDateTime Pos, __int64 idFirm,__int64 idKlient);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMRegVsRasch *DMRegVsRasch;
//---------------------------------------------------------------------------
#endif
