//---------------------------------------------------------------------------

#ifndef UDMRegGoodsH
#define UDMRegGoodsH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"

//----------------------------------------------------------------------------
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <Classes.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class TDMRegGoods : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *DvRegOst;
	TpFIBDataSet *RegOst;
	TpFIBDataSet *DvNom;
	TpFIBDataSet *Ostatok;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateTimeField *DvRegOstPOSDOC_RGGOODS_DV;
	TFIBSmallIntField *DvRegOstTDV_RGGOODS_DV;
	TFIBBCDField *DvRegOstRPRICE_RGGOODS_DV;
	TFIBBCDField *DvRegOstKOL_RGGOODS_DV;
	TFIBIntegerField *DvRegOstOPER_RGGOODS_DV;
	TFIBIntegerField *DvRegOstTYPE_RGGOODS_DV;
	TFIBBCDField *RegOstRPRICE_RGGOODS;
	TFIBBCDField *RegOstKOL_RGGOODS;
	TFIBBCDField *DvNomKOLDV;
	TFIBBCDField *OstatokKOLOST;
	TFIBBCDField *RegOstID_RGGOODS;
	TFIBBCDField *RegOstIDFIRM_RGGOODS;
	TFIBBCDField *RegOstIDSKLAD_RGGOODS;
	TFIBBCDField *RegOstIDNOM_RGGOODS;
	TFIBBCDField *DvRegOstID_RGGOODS_DV;
	TFIBBCDField *DvRegOstIDDOC_RGGOODS_DV;
	TFIBBCDField *DvRegOstIDFIRM_RGGOODS_DV;
	TFIBBCDField *DvRegOstIDSKLAD_RGGOODS_DV;
	TFIBBCDField *DvRegOstIDNOM_RGGOODS_DV;
	TpFIBDataSet *TableOst;
	TpFIBDataSet *Query;
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations



		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
public:		// User declarations
        __fastcall TDMRegGoods(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������

		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //��������� ������ ����������
		GUID ClsIdImpl;				 //GUID ������ ����������




		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		__int64 IdSklad;
		__int64 IdNom;

        float SumOst;
        float KolOst;


		__int64 IdDoc;  //��������
        TDateTime PosDoc;

		__int64 IdFirm;
		double RPrice;
		__int64 IdStr;
        float Kol;
                       //��������
        int Operation; //1-����������, 2-�����������, 3-�� ������ ���������, 4-��������
                        //5-����������� � ���������� �����������
                        //6-����������� � ���������� ����.���������
                        //7 ������� ����������
						//8 ���� ��������
						//9 ������� �� ����������
						//10 �������� ������������ ��������
						//11 ����������

		int Type; //����� ��� ������� �����������
                        
        float Sum2;

        bool AddRecordPrihod(void);
        bool AddRecordRashod(void);
        bool UpdateTableOst(void);
        bool CancelDvReg(void);

		double GetOstatok(__int64 id_firm, __int64 id_sklad, __int64 id_nom);
		void GetOstatokPoPrice(__int64 id_firm, __int64 id_sklad, __int64 id_nom);
		double GetOstatokNa(TDateTime pos,__int64 id_firm, __int64 id_sklad, __int64 id_nom);
		double KolOstNa;

		double GetOstatokNaRoznSkladeNa(TDateTime pos,
										__int64 id_firm,
										__int64 id_sklad,
										__int64 id_nom,
										bool rozn_sklad,
										double rprice  );

		bool SkladRozn;
        bool NoOtrOstatok;


};
//---------------------------------------------------------------------------
extern PACKAGE TDMRegGoods *DMRegGoods;
//---------------------------------------------------------------------------
#endif
