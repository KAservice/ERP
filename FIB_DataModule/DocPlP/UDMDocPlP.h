//---------------------------------------------------------------------------

#ifndef UDMDocPlPH
#define UDMDocPlPH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


//---------------------------------------------------------------------------
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
#include <DB.hpp>


//---------------------------------------------------------------------------
class TDMDocPLP : public TDataModule
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
	TpFIBDataSet *NumDoc;
	TpFIBTransaction *IBTrDvReg;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
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
	TFIBLargeIntField *DocIDPLP;
	TFIBLargeIntField *DocIDDOCPLP;
	TFIBLargeIntField *DocIDBSCHPLP;
	TFIBLargeIntField *DocIDRSCHPLP;
	TFIBIntegerField *DocVIDPLP;
	TFIBIntegerField *DocOCHPLP;
	TFIBDateField *DocSROKPLP;
	TFIBWideStringField *DocNASNPLP;
	TFIBWideStringField *DocGID_DPLP;
	TFIBIntegerField *DocADDKDRPLP;
	TFIBIntegerField *DocOPERATIONPLP;
	TFIBBCDField *DocSUMUSNPLP;
	TFIBWideStringField *DocNALOG_STATUS_PLP;
	TFIBWideStringField *DocNALOG_OSN_PLP;
	TFIBWideStringField *DocNALOG_NUM_PLP;
	TFIBWideStringField *DocNALOG_TPLAT_PLP;
	TFIBWideStringField *DocNALOG_KBK_PLP;
	TFIBWideStringField *DocNALOG_OKATO_PLP;
	TFIBWideStringField *DocNALOG_PERIOD_PLP;
	TFIBDateField *DocNALOG_DATE_PLP;
	TFIBLargeIntField *DocIDBASE_DPLP;
	TFIBIntegerField *DocNDS_DPLP;
	TFIBBCDField *DocSUMNDS_DPLP;
	TFIBWideStringField *DocNAMEBSCHET;
	TFIBWideStringField *DocNAMERSCHET;
	TFIBWideStringField *DocAllNAME_SINFBASE_OBMEN;
	TFIBWideStringField *DocAllNAMEFIRM;
	TFIBWideStringField *DocAllNAMEKLIENT;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocAllSUMDOCChange(TField *Sender);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
	void __fastcall DocIDBSCHPLPChange(TField *Sender);
	void __fastcall DocAllIDFIRMDOCChange(TField *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		bool flGetNumberDoc;  //при созданнии нового документа не будем
							  // каждый раз получать номер документа
public:		// User declarations
		__fastcall TDMDocPLP(TComponent* Owner);

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
		void OpenDoc(__int64 id);
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
extern PACKAGE TDMDocPLP *DMDocPLP;
//---------------------------------------------------------------------------
#endif
