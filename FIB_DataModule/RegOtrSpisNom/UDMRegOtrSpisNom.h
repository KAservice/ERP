//---------------------------------------------------------------------------

#ifndef UDMRegOtrSpisNomH
#define UDMRegOtrSpisNomH
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
//---------------------------------------------------------------------------
class TDMRegOtrSpisNom : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *DvRegOst;
	TpFIBTransaction *IBTrUpdate;
	TFIBDateTimeField *DvRegOstPOSDOC_RGOTRSPIS_DV;
	TFIBSmallIntField *DvRegOstTDV_RGOTRSPIS_DV;
	TFIBBCDField *DvRegOstKOL_RGOTRSPIS_DV;
	TFIBBCDField *DvRegOstID_RGOTRSPIS_DV;
	TFIBBCDField *DvRegOstIDDOC_RGOTRSPIS_DV;
	TFIBBCDField *DvRegOstIDFIRM_RGOTRSPIS_DV;
	TFIBBCDField *DvRegOstIDSKL_RGOTRSPIS_DV;
	TFIBBCDField *DvRegOstIDNOM_RGOTRSPIS_DV;
	TFIBBCDField *DvRegOstIDSTRDOC_RGOTRSPIS_DV;
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMRegOtrSpisNom(TComponent* Owner);

		__int64 IdDoc;  //документ
        TDateTime PosDoc;

		__int64 IdFirm;
		__int64 IdSklad;
		__int64 IdNom;
        __int64 IdStrDoc;
        double Kol;

        void AddNom(void);
        void SpisatNom(void);
        bool CancelDvReg(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMRegOtrSpisNom *DMRegOtrSpisNom;
//---------------------------------------------------------------------------
#endif
