//---------------------------------------------------------------------------

#ifndef UDMRegSebProdH
#define UDMRegSebProdH
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
class TDMRegSebProd : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *DvRegOst;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateTimeField *DvRegOstPOSDOC_RGSEBPROD_DV;
	TFIBSmallIntField *DvRegOstTDV_RGSEBPROD_DV;
	TFIBBCDField *DvRegOstKOL_RGSEBPROD_DV;
	TFIBBCDField *DvRegOstKOLOTR_RGSEBPROD_DV;
	TFIBBCDField *DvRegOstSUM_RGSEBPROD_DV;
	TFIBBCDField *DvRegOstID_RGSEBPROD_DV;
	TFIBBCDField *DvRegOstIDDOC_RGSEBPROD_DV;
	TFIBBCDField *DvRegOstIDVIPPROD_RGSEBPROD_DV;
	TFIBBCDField *DvRegOstIDFIRM_RGSEBPROD_DV;
	TFIBBCDField *DvRegOstIDSKLAD_RGSEBPROD_DV;
	TFIBBCDField *DvRegOstIDNOM_RGSEBPROD_DV;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMRegSebProd(TComponent* Owner);


	IDMFibConnection * DM_Connection;
		bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		__int64 IdDoc;  //документ
        TDateTime PosDoc;

		__int64 IdVipuskProd;
		__int64 IdFirm;
		__int64 IdSklad;
		__int64 IdNom;
        __int64 IdStrDoc;

        double SumSeb;
        double KolOtr;
        double Kol;

        void AddRecordPrihod(void);
        void AddRecordRashod(void);
        bool CancelDvReg(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMRegSebProd *DMRegSebProd;
//---------------------------------------------------------------------------
#endif
