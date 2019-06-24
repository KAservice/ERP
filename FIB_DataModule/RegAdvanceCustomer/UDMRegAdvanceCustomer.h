//---------------------------------------------------------------------------

#ifndef UDMRegAdvanceCustomerH
#define UDMRegAdvanceCustomerH
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
class TDMRegAdvanceCustomer : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *DvRegOst;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *RegOst;
	TFIBDateTimeField *DvRegOstPOS_RGADVCUST_DV;
	TFIBIntegerField *DvRegOstTDV_RGADVCUST_DV;
	TFIBBCDField *DvRegOstSUM_RGADVCUST_DV;
	TFIBBCDField *RegOstSUM_RGADVCUST;
	TpFIBTransaction *IBTr;
	TFIBBCDField *DvRegOstID_RGADVCUST_DV;
	TFIBBCDField *DvRegOstIDDOC_RGADVCUST_DV;
	TFIBBCDField *DvRegOstIDFIRM_RGADVCUST_DV;
	TFIBBCDField *DvRegOstIDKLIENT_RGADVCUST_DV;
	TFIBBCDField *RegOstID_RGADVCUST;
	TFIBBCDField *RegOstIDFIRM_RGADVCUST;
	TFIBBCDField *RegOstIDKLIENT_RGADVCUST;
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
        __fastcall TDMRegAdvanceCustomer(TComponent* Owner);

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

		__int64 IdDoc;  //документ
        TDateTime PosDoc;
		__int64 IdFirm;
		__int64 IdKlient;
        float Sum;


        bool AddRecordPrihod(void);
        bool AddRecordRashod(void);
        bool UpdateTableOst(void);
        bool CancelDvReg(void);

        double GetOstatokAdvance(__int64 id_firm, __int64 id_klient);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMRegAdvanceCustomer *DMRegAdvanceCustomer;
//---------------------------------------------------------------------------
#endif
