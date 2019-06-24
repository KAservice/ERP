//---------------------------------------------------------------------------

#ifndef UDMDocRKOH
#define UDMDocRKOH
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
class TDMDocRKO : public TDataModule
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
	TFIBSmallIntField *DocADDKDRRKO;
	TFIBBCDField *DocSUMUSNRKO;
	TFIBSmallIntField *DocOPERATIONRKO;
	TpFIBDataSet *NumDoc;
	TpFIBTransaction *IBTrDvReg;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBBCDField *DocAllIDDOC;
	TFIBBCDField *DocAllIDFIRMDOC;
	TFIBBCDField *DocAllIDSKLDOC;
	TFIBBCDField *DocAllIDKLDOC;
	TFIBBCDField *DocAllIDDOGDOC;
	TFIBBCDField *DocAllIDUSERDOC;
	TFIBBCDField *DocAllIDDOCOSNDOC;
	TFIBBCDField *DocIDRKO;
	TFIBBCDField *DocIDDOCRKO;
	TFIBBCDField *DocIDKKMRKO;
	TFIBBCDField *DocIDKLRKO;
	TFIBBCDField *DocAllIDEXTDOC;
	TFIBBCDField *DocIDBASE_DRKO;
	TFIBBCDField *DocAllIDBASE_GALLDOC;
	TFIBIntegerField *DocNDS_DRKO;
	TFIBBCDField *DocSUMNDS_DRKO;
	TFIBWideStringField *DocAllGID_DOC;
	TFIBWideStringField *DocAllFNAME_USER;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBWideStringField *DocVIDATRKO;
	TFIBWideStringField *DocOSNRKO;
	TFIBWideStringField *DocPRILRKO;
	TFIBWideStringField *DocDOCPOLRKO;
	TFIBWideStringField *DocGID_DRKO;
	TFIBIntegerField *DocNKLRKO;
	TFIBIntegerField *DocNCHECKRKO;
	TFIBWideStringField *DocMODELRKO;
	TFIBWideStringField *DocREGNUMRKO;
	TFIBWideStringField *DocSAVNUMRKO;
	TFIBWideStringField *DocNAMEKKM;
	TFIBWideStringField *DocAllTDOC;
	TFIBIntegerField *DocAllTYPEEXTDOC;
	TFIBBCDField *DocAllIDPROJECT_GALLDOC;
	TFIBBCDField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
	TFIBWideStringField *DocKORRSCHET_DRKO;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocIDKKMRKOChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	double Summa(void);

		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
        __fastcall TDMDocRKO(TComponent* Owner);

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
extern PACKAGE TDMDocRKO *DMDocRKO;
//---------------------------------------------------------------------------
#endif
