//---------------------------------------------------------------------------

#ifndef UHOT_DMRegSostNFH
#define UHOT_DMRegSostNFH
//---------------------------------------------------------------------------
#include "UDM.h"


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
class THOT_DMRegSostNF : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *DvRegOst;
	TpFIBDataSet *RegOst;
	TpFIBDataSet *Dv;
	TpFIBDataSet *Ostatok;
	TpFIBTransaction *IBTr;
	TpFIBTransaction *IBTrUpdate;
	TFIBBCDField *DvSUMDV;
	TFIBBCDField *OstatokSUMOST;
	TFIBDateTimeField *DvRegOstPOS_HOT_RGSOSTNF_DV;
	TFIBIntegerField *DvRegOstTDV_HOT_RGSOSTNF_DV;
	TFIBIntegerField *DvRegOstOPER_HOT_RGSOSTNF_DV;
	TFIBBCDField *DvRegOstID_HOT_RGSOSTNF_DV;
	TFIBBCDField *DvRegOstIDDOCH_HOT_RGSOSTNF_DV;
	TFIBBCDField *DvRegOstIDSOST_HOT_RGSOSTNF_DV;
	TFIBBCDField *RegOstID_HOT_RGSOSTNF;
	TFIBBCDField *RegOstIDSOST_HOT_RGSOSTNF;
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall THOT_DMRegSostNF(TComponent* Owner);

		TDM * DM_Connection;
		bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        int GetOstatok(void);

		__int64 IdDocH;  //документ
        TDateTime PosDoc;

		__int64 IdSost;
        int Operation;

        bool AddRecordPrihod(void);
        bool AddRecordRashod(void);
        bool UpdateTableOst(void);
        bool CancelDvReg(void);

        bool GetOstatokNa(TDateTime Pos, __int64 id_firm, __int64 id_kassa);
        double SumOstNa;
};
//---------------------------------------------------------------------------
extern PACKAGE THOT_DMRegSostNF *HOT_DMRegSostNF;
//---------------------------------------------------------------------------
#endif
