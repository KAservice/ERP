//---------------------------------------------------------------------------

#ifndef UDMRegBankH
#define UDMRegBankH
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
class TDMRegBank : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *DvRegOst;
	TpFIBDataSet *RegOst;
	TpFIBDataSet *Dv;
	TpFIBDataSet *Ostatok;
	TpFIBTransaction *IBTrUpdate;
	TpFIBTransaction *IBTr;
	TFIBDateTimeField *DvRegOstPOSDOC_RGBANK_DV;
	TFIBSmallIntField *DvRegOstTDV_RGBANK_DV;
	TFIBBCDField *DvRegOstSUM_RGBANK_DV;
	TFIBIntegerField *DvRegOstOPER_RGBANK_DV;
	TFIBBCDField *RegOstSUM_RGBANK;
	TFIBBCDField *DvSUMDV;
	TFIBBCDField *OstatokSUMOST;
	TFIBBCDField *RegOstID_RGBANK;
	TFIBBCDField *RegOstIDFIRM_RGBANK;
	TFIBBCDField *RegOstIDBSCHET_RGBANK;
	TFIBBCDField *DvRegOstID_RGBANK_DV;
	TFIBBCDField *DvRegOstIDDOC_RGBANK_DV;
	TFIBBCDField *DvRegOstIDFIRM_RGBANK_DV;
	TFIBBCDField *DvRegOstIDBSCHET_RGBANK_DV;
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
	   bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


public:		// User declarations
		__fastcall TDMRegBank(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//из этой формы открыта другая для выбора
		//обработка события выбора в другой форме (которая была открыта из этой для выбора чего-то)
		int ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект (форму в которой производится выбор)
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									);


		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		//Текущий интерфейс

        int GetOstatok(void);

		__int64 IdDoc;  //документ
        TDateTime PosDoc;

		__int64 IdFirm;
        __int64 IdBSchet;
        float Sum;

        int Operation;

        bool AddRecordPrihod(void);
        bool AddRecordRashod(void);
        bool UpdateTableOst(void);
        bool CancelDvReg(void);

		bool GetOstatokNa(TDateTime Pos, __int64 id_firm, __int64 id_bschet);
        double SumOstNa;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMRegBank *DMRegBank;
//---------------------------------------------------------------------------
#endif
