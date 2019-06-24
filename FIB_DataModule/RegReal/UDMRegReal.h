//---------------------------------------------------------------------------

#ifndef UDMRegRealH
#define UDMRegRealH
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
class TDMRegReal : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *DvRegOst;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateTimeField *DvRegOstPOSDOC_RGREAL_DV;
	TFIBSmallIntField *DvRegOstTDV_RGREAL_DV;
	TFIBBCDField *DvRegOstSUMREAL_RGREAL_DV;
	TFIBBCDField *DvRegOstSEBREAL_RGREAL_DV;
	TFIBBCDField *DvRegOstRESREAL_RGREAL_DV;
	TFIBBCDField *DvRegOstKOL_RGREAL_DV;
	TFIBBCDField *DvRegOstKOLOTR_RGREAL_DV;
	TFIBIntegerField *DvRegOstOPER_RGREAL_DV;
	TFIBBCDField *DvRegOstID_RGREAL_DV;
	TFIBBCDField *DvRegOstIDDOC_RGREAL_DV;
	TFIBBCDField *DvRegOstIDFIRM_RGREAL_DV;
	TFIBBCDField *DvRegOstIDSKLAD_RGREAL_DV;
	TFIBBCDField *DvRegOstIDNOM_RGREAL_DV;
	TFIBBCDField *DvRegOstIDPART_RGREAL_DV;
	TFIBBCDField *DvRegOstIDPOK_RGREAL_DV;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMRegReal(TComponent* Owner);


	IDMFibConnection * DM_Connection;
		bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		__int64 IdDoc;  //документ
        TDateTime PosDoc;

		__int64 IdFirm;
		__int64 IdSklad;
		__int64 IdNom;
        __int64 IdStrDoc;
        double SumReal;
        double SebReal;
        double ResReal;
        double KolReal;
        double KolOtrReal;
        int Operation;
        
        void AddReal(void);
        void SpisatReal(void);
        bool CancelDvReg(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMRegReal *DMRegReal;
//---------------------------------------------------------------------------
#endif
