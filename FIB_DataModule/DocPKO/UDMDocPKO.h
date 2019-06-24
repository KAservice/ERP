//---------------------------------------------------------------------------

#ifndef UDMDocPKOH
#define UDMDocPKOH
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
class TDMDocPKO : public TDataModule
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
	TFIBSmallIntField *DocADDKDRPKO;
	TFIBBCDField *DocSUMUSNPKO;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TFIBIntegerField *DocNKLPKO;
	TFIBIntegerField *DocNCHECKPKO;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBIntegerField *DocNDS_DPKO;
	TFIBBCDField *DocSUMNDS_DPKO;
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
	TFIBLargeIntField *DocIDPKO;
	TFIBLargeIntField *DocIDDOCPKO;
	TFIBLargeIntField *DocIDKKMPKO;
	TFIBLargeIntField *DocIDKLPKO;
	TFIBWideStringField *DocPROTPKO;
	TFIBWideStringField *DocOSNPKO;
	TFIBWideStringField *DocPRILPKO;
	TFIBWideStringField *DocGID_DPKO;
	TFIBIntegerField *DocOPERATIONPKO;
	TFIBWideStringField *DocMODELPKO;
	TFIBWideStringField *DocREGNUMPKO;
	TFIBWideStringField *DocSAVNUMPKO;
	TFIBLargeIntField *DocIDBASE_DPKO;
	TFIBWideStringField *DocNAMEKKM;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBWideStringField *DocKORRSCHET_DPKO;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DocAll1SUMDOCChange(TField *Sender);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocIDKKMPKOChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	double Summa(void);

			bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TDMDocPKO(TComponent* Owner);

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
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца


		bool EnableDvReg;

		int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocPKO *DMDocPKO;
//---------------------------------------------------------------------------
#endif
