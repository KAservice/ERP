//---------------------------------------------------------------------------

#ifndef UDMDocPKORoznH
#define UDMDocPKORoznH
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
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMDocPKORozn : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocAll;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBBCDField *DocAllSUMDOC;
	TFIBIntegerField *DocOPERATION_DPKOROZN;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBIntegerField *DocNDS_DPKOROZN;
	TFIBBCDField *DocSUMNDS_DPKOROZN;
	TFIBLargeIntField *DocAllIDDOC;
	TFIBWideStringField *DocAllTDOC;
	TFIBLargeIntField *DocAllIDFIRMDOC;
	TFIBLargeIntField *DocAllIDSKLDOC;
	TFIBLargeIntField *DocAllIDKLDOC;
	TFIBLargeIntField *DocAllIDDOGDOC;
	TFIBLargeIntField *DocAllIDUSERDOC;
	TFIBWideStringField *DocAllGID_DOC;
	TFIBWideStringField *DocAllPREFIKSDOC;
	TFIBLargeIntField *DocAllIDDOCOSNDOC;
	TFIBLargeIntField *DocAllIDEXTDOC;
	TFIBIntegerField *DocAllTYPEEXTDOC;
	TFIBLargeIntField *DocAllIDBASE_GALLDOC;
	TFIBLargeIntField *DocAllIDPROJECT_GALLDOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocAllNAME_SDOG;
	TFIBLargeIntField *DocID_DPKOROZN;
	TFIBLargeIntField *DocIDDOC_DPKOROZN;
	TFIBWideStringField *DocGID_DPKOROZN;
	TFIBLargeIntField *DocIDKKM_DPKOROZN;
	TFIBWideStringField *DocPRIM_DPKOROZN;
	TFIBWideStringField *DocPROT_DPKOROZN;
	TFIBWideStringField *DocOSN_DPKOROZN;
	TFIBIntegerField *DocNUMCHECK_DPKOROZN;
	TFIBIntegerField *DocNUMKL_DPKOROZN;
	TFIBIntegerField *DocNKL_DPKOROZN;
	TFIBIntegerField *DocNCHECK_DPKOROZN;
	TFIBWideStringField *DocMODEL_DPKOROZN;
	TFIBWideStringField *DocREGNUM_DPKOROZN;
	TFIBWideStringField *DocSAVNUM_DPKOROZN;
	TFIBLargeIntField *DocIDBASE_DPKOROZN;
	TFIBLargeIntField *DocIDCARD_DPKOROZN;
	TFIBWideStringField *DocNAMEKKM;
	TFIBWideStringField *DocNAME_SDISCOUNT_CARD;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocIDKKM_DPKOROZNChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	double Summa(void);

			bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TDMDocPKORozn(TComponent* Owner);
	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IkanUnknown * InterfaceImpl; //интерфейс класса реализации
	GUID ClsIdImpl;				 //GUID класса реализации
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;
		UnicodeString TextError;
		bool Init(void);
		int Done(void);


		void NewDoc(void);
		void OpenDoc(__int64 IdDoc);
        bool SaveDoc(void);
        bool DvRegDoc(void);
        bool CancelDvRegDoc(void);
        void CloseDoc(void);

		bool DeleteDoc(__int64 id);

        bool NewElement;  // новый элемент
		bool Prosmotr;    //только просмотр
        __int64 IdDoc;           //идентификатор текущей записи

		bool EnableDvReg;

		int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocPKORozn *DMDocPKORozn;
//---------------------------------------------------------------------------
#endif
