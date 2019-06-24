//---------------------------------------------------------------------------

#ifndef UDMRegOstNomH
#define UDMRegOstNomH
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
class TDMRegOstNom : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *DvRegOst;
	TpFIBDataSet *RegOst;
	TpFIBDataSet *DvNom;
	TpFIBDataSet *Ostatok;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateTimeField *DvRegOstPOSDOC_OSTNOMDV;
	TFIBSmallIntField *DvRegOstTDV_OSTNOMDV;
	TFIBBCDField *DvRegOstSUM_OSTNOMDV;
	TFIBBCDField *DvRegOstKOL_OSTNOMDV;
	TFIBIntegerField *DvRegOstOPER_OSTNOMDV;
	TFIBBCDField *DvRegOstSUM2_OSTNOMDV;
	TFIBBCDField *RegOstSUMOSTNOM;
	TFIBBCDField *RegOstKOLOSTNOM;
	TFIBBCDField *DvNomKOLDV;
	TFIBBCDField *DvNomSUMDV;
	TFIBBCDField *OstatokKOLOST;
	TFIBBCDField *OstatokSUMOST;
	TFIBBCDField *RegOstIDOSTNOM;
	TFIBBCDField *RegOstIDFIRMOSTNOM;
	TFIBBCDField *RegOstIDSKLOSTNOM;
	TFIBBCDField *RegOstIDNOMOSTNOM;
	TFIBBCDField *RegOstIDPARTOSTNOM;
	TFIBBCDField *DvRegOstID_OSTNOMDV;
	TFIBBCDField *DvRegOstIDDOC_OSTNOMDV;
	TFIBBCDField *DvRegOstIDFIRM_OSTNOMDV;
	TFIBBCDField *DvRegOstIDSKL_OSTNOMDV;
	TFIBBCDField *DvRegOstIDNOM_OSTNOMDV;
	TFIBBCDField *DvRegOstIDPART_OSTNOMDV;
	TFIBBCDField *DvRegOstIDSTRDOC_OSTNOMDV;
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TDMRegOstNom(TComponent* Owner);

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

		__int64 IdFirm;
		__int64 IdSklad;
		__int64 IdNom;
        int GetOstatok(void);
        float SumOst;
        float KolOst;


		__int64 IdDoc;  //��������
        TDateTime PosDoc;

		__int64 IdPart;
		__int64 IdStr;
        float Kol;
        float Sum;
                       //��������
        int Operation; //1-����������, 2-�����������, 3-�� ������ ���������, 4-��������
                        //5-����������� � ���������� �����������
                        //6-����������� � ���������� ����.���������
                        //7 ������� ����������
                        //8 ���� ��������
                        
        float Sum2;

        bool AddRecordPrihod(void);
        bool AddRecordRashod(void);
        bool UpdateTableOst(void);
        bool CancelDvReg(void);


		bool GetOstatokNa(TDateTime Pos, __int64 idFirm, __int64 idSklad, __int64 idNom);
        float SumOstNa;
        float KolOstNa;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMRegOstNom *DMRegOstNom;
//---------------------------------------------------------------------------
#endif
