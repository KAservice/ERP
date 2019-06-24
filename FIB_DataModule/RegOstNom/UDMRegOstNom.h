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

		__int64 IdFirm;
		__int64 IdSklad;
		__int64 IdNom;
        int GetOstatok(void);
        float SumOst;
        float KolOst;


		__int64 IdDoc;  //документ
        TDateTime PosDoc;

		__int64 IdPart;
		__int64 IdStr;
        float Kol;
        float Sum;
                       //списание
        int Operation; //1-реализация, 2-перемещение, 3-на выпуск продукции, 4-списание
                        //5-поступление в результате перемещений
                        //6-поступление в результате прих.накладной
                        //7 возврат поставщику
                        //8 ввод остатков
                        
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
