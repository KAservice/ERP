//---------------------------------------------------------------------------

#ifndef UDMDocRegOstNomH
#define UDMDocRegOstNomH
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
class TDMDocRegOstNom : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceDoc;
        TDataSource *DataSourceDocT;
        TDataSource *DataSourceDocAll;
	TpFIBDataSet *DocAll;
	TpFIBDataSet *Doc;
	TpFIBDataSet *DocT;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TpFIBTransaction *IBTrDvReg;
	TpFIBDataSet *NumDoc;
	TpFIBQuery *pFIBQ;
	TpFIBQuery *QueryCancelDvReg;
	TpFIBQuery *QueryDvReg;
	TFIBDateTimeField *DocAllPOSDOC;
	TFIBSmallIntField *DocAllPRDOC;
	TFIBIntegerField *DocAllNUMDOC;
	TFIBBCDField *DocAllSUMDOC;
	TIntegerField *DocTRECNO;
	TFIBSmallIntField *DocTTDV_DRG_OSTNOMT;
	TFIBBCDField *DocTKOL_DRG_OSTNOMT;
	TFIBBCDField *DocTSUM_DRG_OSTNOMT;
	TFIBSmallIntField *DocTOPER_DRG_OSTNOMT;
	TFIBLargeIntField *DocAllIDDOC;
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
	TFIBLargeIntField *DocID_DRG_OSTNOM;
	TFIBLargeIntField *DocIDDOC_DRG_OSTNOM;
	TFIBWideStringField *DocDESCR_DRG_OSTNOM;
	TFIBLargeIntField *DocIDBASE_DRG_OSTNOM;
	TFIBLargeIntField *DocTID_DRG_OSTNOMT;
	TFIBLargeIntField *DocTIDDOC_DRG_OSTNOMT;
	TFIBLargeIntField *DocTIDFIRM_DRG_OSTNOMT;
	TFIBLargeIntField *DocTIDSKLAD_DRG_OSTNOMT;
	TFIBLargeIntField *DocTIDNOM_DRG_OSTNOMT;
	TFIBLargeIntField *DocTIDPART_DRG_OSTNOMT;
	TFIBLargeIntField *DocTIDBASE_DRG_OSTNOMT;
	TFIBWideStringField *DocTNAMEFIRM;
	TFIBWideStringField *DocTNAMESKLAD;
	TFIBWideStringField *DocTNAMENOM;
	TFIBWideStringField *DocTDOCPART;
	TFIBWideStringField *DocAllTDOC;
	TFIBLargeIntField *DocAllIDBUSINOP_GALLDOC;
	TFIBWideStringField *DocAllNAME_SPROJECT;
	TFIBWideStringField *DocAllNAME_SBUSINESS_OPER;
	TFIBWideStringField *DocAllPREFIKS_NUM_GALLDOC;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DocTNewRecord(TDataSet *DataSet);
	void __fastcall DocAllPOSDOCChange(TField *Sender);
	void __fastcall DocTCalcFields(TDataSet *DataSet);
	void __fastcall DocNewRecord(TDataSet *DataSet);
	void __fastcall DocAllIDBASE_GALLDOCChange(TField *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
			bool flGetNumberDoc;  //��� ��������� ������ ��������� �� �����
							  // ������ ��� �������� ����� ���������
public:		// User declarations
        __fastcall TDMDocRegOstNom(TComponent* Owner);

	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;
	IkanUnknown * InterfaceImpl; //��������� ������ ����������
	GUID ClsIdImpl;				 //GUID ������ ����������
	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;
		UnicodeString TextError;
		bool Init(void);
		int Done(void);

		__int64 IdDoc;           //������������� ������� ������
		bool Prosmotr;    //������ ��������
		bool EnableDvReg; //��������� �������� ���������

		bool NewDoc(void);
		bool OpenDoc(__int64 IdDoc);
		bool SaveDoc(void);
		bool DeleteDoc(__int64 id);

        bool DvRegDoc(void);
		bool CancelDvRegDoc(void);

		void TableAppend(void);
		void TableDelete(void);

         int GetNumberNewDoc(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMDocRegOstNom *DMDocRegOstNom;
//---------------------------------------------------------------------------
#endif
