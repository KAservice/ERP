//---------------------------------------------------------------------------

#ifndef UDMRegVipuskProdH
#define UDMRegVipuskProdH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <Classes.hpp>
#include <DB.hpp>
 ;

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
class TDMRegVipuskProd : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *DvRegOst;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateTimeField *DvRegOstPOSDOC_RGVIPPROD_DV;
	TFIBSmallIntField *DvRegOstTDV_RGVIPPROD_DV;
	TFIBBCDField *DvRegOstKOL_RGVIPPROD_DV;
	TFIBBCDField *DvRegOstSEB_RGVIPPROD_DV;
	TFIBBCDField *DvRegOstID_RGVIPPROD_DV;
	TFIBBCDField *DvRegOstIDDOC_RGVIPPROD_DV;
	TFIBBCDField *DvRegOstIDFIRM_RGVIPPROD_DV;
	TFIBBCDField *DvRegOstIDSKLAD_RGVIPPROD_DV;
	TFIBBCDField *DvRegOstIDNOM_RGVIPPROD_DV;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMRegVipuskProd(TComponent* Owner);


	IDMFibConnection * DM_Connection;
		bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


		__int64 IdDoc;  //документ
        TDateTime PosDoc;

		__int64 IdFirm;
		__int64 IdSklad;
		__int64 IdNom;
        __int64 IdStrDoc;

        double SebProd;
        double KolProd;

        void AddRecordPrihod(void);
        void AddRecordRashod(void);
        bool CancelDvReg(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMRegVipuskProd *DMRegVipuskProd;
//---------------------------------------------------------------------------
#endif
