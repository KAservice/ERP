//---------------------------------------------------------------------------

#ifndef UREM_DMZayavkaPredvH
#define UREM_DMZayavkaPredvH
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
class TREM_DMZayavkaPredv : public TDataModule
{
__published:	// IDE-managed Components
	TDataSource *DataSourceGurZ;
	TpFIBDataSet *GurZ;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBDataSet *NumDoc;
	TFIBLargeIntField *GurZID_REM_Z2;
	TFIBLargeIntField *GurZIDBASE_REM_Z2;
	TFIBWideStringField *GurZPREFIKS_REM_Z2;
	TFIBIntegerField *GurZNUM_REM_Z2;
	TFIBWideStringField *GurZGUID_REM_Z2;
	TFIBDateTimeField *GurZPOS_REM_Z2;
	TFIBLargeIntField *GurZIDMODEL_REM_Z2;
	TFIBLargeIntField *GurZIDPRMODEL_REM_Z2;
	TFIBLargeIntField *GurZIDFIRM_REM_Z2;
	TFIBLargeIntField *GurZIDSKLPR_REM_Z2;
	TFIBLargeIntField *GurZIDKLIENT_REM_Z2;
	TFIBLargeIntField *GurZIDDILER_REM_Z2;
	TFIBWideStringField *GurZNAME_REM_Z2;
	TFIBWideStringField *GurZDESCR_REM_Z2;
	TFIBWideStringField *GurZKLIENT_NAME_REM_Z2;
	TFIBWideStringField *GurZKLIENT_ADR_REM_Z2;
	TFIBWideStringField *GurZKLIENT_PHONE_REM_Z2;
	TFIBWideStringField *GurZKLIENT_EMAIL_REM_Z2;
	TFIBLargeIntField *GurZIDBRAND_REM_Z2;
	TFIBLargeIntField *GurZIDPRODUCER_REM_Z2;
	TFIBWideStringField *GurZNEISPR_REM_Z2;
	TFIBWideStringField *GurZSOST_REM_Z2;
	TFIBWideStringField *GurZMODEL_STR_REM_Z2;
	TFIBWideStringField *GurZSERNUM1_REM_Z2;
	TFIBWideStringField *GurZSERNUM2_REM_Z2;
	TFIBLargeIntField *GurZIDKKT_REM_Z2;
	TFIBLargeIntField *GurZIDHW_REM_Z2;
	TFIBLargeIntField *GurZIDSELLER_REM_Z2;
	TFIBWideStringField *GurZDOPOPISANIE_REM_Z2;
	TFIBBCDField *GurZSUMKLIENTA_REM_Z2;
	TFIBBCDField *GurZSUMNACHA_REM_Z2;
	TFIBIntegerField *GurZRESULT_REM_Z2;
	TFIBWideStringField *GurZPRICHINA_REM_Z2;
	TFIBIntegerField *GurZPRICHINA_LIST_REM_Z2;
	TFIBIntegerField *GurZSROK_REM_Z2;
	TFIBLargeIntField *GurZIDUSER_REM_Z2;
	TFIBWideStringField *GurZNAMEFIRM;
	TFIBWideStringField *GurZNAME_SINFBASE_OBMEN;
	TFIBWideStringField *GurZNAME_REM_SMODEL;
	TFIBWideStringField *GurZNAME_SKLAD_PR;
	TFIBWideStringField *GurZNAMEKLIENT;
	TFIBWideStringField *GurZNAMEDILER;
	TFIBWideStringField *GurZNAME_USER;
	TFIBWideStringField *GurZNAME_SBRAND;
	TFIBWideStringField *GurZNAME_REM_SHARDWARE;
	TFIBWideStringField *GurZSERNUM_REM_SHARDWARE;
	TFIBWideStringField *GurZSERNUM2_REM_SHARDWARE;
	TFIBWideStringField *GurZNAME_REM_SKKT;
	TFIBWideStringField *GurZSERNUM_REM_SKKT;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall GurZIDFIRM_REM_ZChange(TField *Sender);
	void __fastcall GurZIDSKLPR_REM_ZChange(TField *Sender);
private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


   int GetNumberNewDoc(void);
		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TREM_DMZayavkaPredv(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);



		//Текущий интерфейс
		void NewDoc(void);
		void OpenDoc(__int64 id);
        bool SaveDoc(void);
		bool DeleteDoc(__int64 id);
        void CloseDoc(void); 

		bool Prosmotr;    //только просмотр
		__int64 IdZ;           //идентификатор текущей записи


		bool flChangeData;

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMZayavkaPredv *REM_DMZayavkaPredv;
//---------------------------------------------------------------------------
#endif
