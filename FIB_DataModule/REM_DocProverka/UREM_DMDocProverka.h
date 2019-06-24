//---------------------------------------------------------------------------

#ifndef UREM_DMDocProverkaH
#define UREM_DMDocProverkaH
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
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TREM_DMDocProverka : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDocAll;
	TpFIBDataSet *DocAll;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TpFIBQuery *pFIBQ;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBIntegerField *NumDocMAXNUMBER;
	TFIBLargeIntField *DocAllID_REM_GUR_PROV;
	TFIBLargeIntField *DocAllIDBASE_REM_GUR_PROV;
	TFIBDateTimeField *DocAllPOS_REM_GUR_PROV;
	TFIBIntegerField *DocAllNUM_REM_GUR_PROV;
	TFIBWideStringField *DocAllDESCR_REM_GUR_PROV;
	TFIBLargeIntField *DocAllIDDOC_REM_GUR_PROV;
	TFIBLargeIntField *DocAllIDUSER_REM_GUR_PROV;
	TFIBIntegerField *DocAllRES_REM_GUR_PROV;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMESKLAD;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocAllNAME_USER_DOC;
	TFIBWideStringField *DocAllNAME_USER_PROV;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllPREFIKS_NUM_REM_GALLDOC;
	TFIBSmallIntField *DocAllPR_REM_GALLDOC;
	TFIBIntegerField *DocAllNUM_REM_GALLDOC;
	TFIBDateTimeField *DocAllPOS_REM_GALLDOC;
	TFIBWideStringField *DocAllTDOC_REM_GALLDOC;
	TpFIBTransaction *IBTrUpdate;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DocAllPOS_REM_GALLDOCChange(TField *Sender);
	void __fastcall DocAllTDOC_REM_GALLDOCGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
    			bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TREM_DMDocProverka(TComponent* Owner);

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

		__int64 IdDoc;           //идентификатор текущей записи
		bool Prosmotr;    //только просмотр

		bool NewDoc(void);
		bool OpenDoc(__int64 id);
		bool SaveDoc(void);
		bool DeleteDoc(__int64 id);

        bool DvRegDoc(void);
		bool CancelDvRegDoc(void);

        int GetNumberNewDoc(void);




};
//---------------------------------------------------------------------------
extern PACKAGE TREM_DMDocProverka *REM_DMDocProverka;
//---------------------------------------------------------------------------
#endif
