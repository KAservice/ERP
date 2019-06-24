//---------------------------------------------------------------------------

#ifndef UDMSprNomRestH
#define UDMSprNomRestH
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
class TDMSprNomRest : public TDataModule
{
__published:	// IDE-managed Components
        TDataSource *DataSourceElement;
        TDataSource *DataSourceTable;
	TpFIBDataSet *Table;
	TpFIBDataSet *Element;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateTimeField *TablePOS_NOMREST;
	TIntegerField *TableRECNO;
	TpFIBDataSet *IBQ;
	TFIBBCDField *IBQNKOL_SPROD;
	TFIBBCDField *IBQBKOL_SPROD;
	TFIBBCDField *IBQKFPRICE_SPROD;
	TFIBSmallIntField *IBQSPIS_SPROD;
	TFIBBCDField *IBQVALUE_SSEZKF;
	TFIBBCDField *IBQVALUE_SSEZKF_SPROD;
	TFloatField *IBQSEZKF_SPROD;
	TFloatField *IBQSEZKF;
	TFIBBCDField *TableID_NOMREST;
	TFIBBCDField *TableIDNOM_NOMREST;
	TFIBBCDField *IBQID_SPROD;
	TFIBBCDField *IBQIDKOMPL_SPROD;
	TFIBWideStringField *TableNAME_NOMREST;
	TFIBWideStringField *IBQNAMENOM;
	TFIBBCDField *ElementID_NOMREST;
	TFIBBCDField *ElementIDNOM_NOMREST;
	TFIBBCDField *ElementIDMPRIG_NOMREST;
	TFIBWideStringField *ElementSOST_NOMREST;
	TFIBWideStringField *ElementTEHN_NOMREST;
	TFIBWideStringField *ElementVIH_NOMREST;
	TFIBWideStringField *ElementSROK_NOMREST;
	TFIBWideStringField *ElementNOMER_NOMREST;
	TFIBWideStringField *ElementNAME_NOMREST;
	TFIBDateTimeField *ElementPOS_NOMREST;
	TFIBBCDField *ElementIDEDPROD_NOMREST;
	TFIBBCDField *ElementKOLEDPROD_NOMREST;
	TFIBWideStringField *ElementGID_SNOMREST;
	TFIBBCDField *ElementIDBASE_SNOMREST;
	TFIBBCDField *ElementIDEDFACTOR_SNOMREST;
	TFIBBCDField *ElementENCEN_SNOMREST;
	TFIBBCDField *ElementIDPRODUCE_SNOMREST;
	TFIBBCDField *ElementIDLOSSFACTOR_SNOMREST;
	TFIBWideStringField *ElementVID_SNOMREST;
	TFIBWideStringField *ElementTEMP_SNOMREST;
	TFIBWideStringField *ElementAPPERANCE_SNOMREST;
	TFIBWideStringField *ElementCOLOUR_SNOMREST;
	TFIBWideStringField *ElementTASTE_SNOMREST;
	TFIBWideStringField *ElementSMELL_SNOMREST;
	TFIBWideStringField *ElementCONSISTENCE_SNOMREST;
	TFIBWideStringField *ElementMDSV_SNOMREST;
	TFIBWideStringField *ElementMDG_SNOMREST;
	TFIBWideStringField *ElementMDS_SNOMREST;
	TFIBWideStringField *ElementKMAM_SNOMREST;
	TFIBWideStringField *ElementBGKR_SNOMREST;
	TFIBWideStringField *ElementECOLI_SNOMREST;
	TFIBWideStringField *ElementKPS_SNOMREST;
	TFIBWideStringField *ElementPROTEUS_SNOMREST;
	TFIBWideStringField *ElementPMS_SNOMREST;
	TFIBWideStringField *ElementNAME_MPRIG;
	TFIBWideStringField *ElementNAMENOM;
	TFIBBCDField *ElementIDSKLAD_MPRIG;
	TFIBWideStringField *ElementNAMEED;
	TFIBBCDField *ElementKFED;
	TFIBWideStringField *ElementNAME_ED_FACTOR;
	TFIBBCDField *ElementKF_ED_FACTOR;
	TFIBWideStringField *ElementNAME_SPRODUCE;
	TFIBWideStringField *ElementNAME_SLOSS_FACTOR;
        void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall ElementNewRecord(TDataSet *DataSet);
	void __fastcall TableNAME_NOMRESTGetText(TField *Sender, AnsiString &Text,
          bool DisplayText);
	void __fastcall IBQCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
		__fastcall TDMSprNomRest(TComponent* Owner);

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

		bool Init(void);
		int Done(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        void OpenTable(void);

        int OpenElement(void);
        void NewElement(void);
        bool SaveElement(void);
        void DeleteElement(void);

		__int64 Id;
		__int64 IdNom;
        bool Error;
        String TextError;

		__int64 GetTekSostav(__int64 idNom, TDateTime pos);
		bool flSaveElement;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprNomRest *DMSprNomRest;
//---------------------------------------------------------------------------
#endif
