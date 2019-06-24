//---------------------------------------------------------------------------

#ifndef UDMPriemPlatH
#define UDMPriemPlatH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDMPriemPlat : public TDataModule
{
__published:	// IDE-managed Components
	TpFIBDataSet *IBQNumTel;
	TpFIBDataSet *IBQNom;
	TpFIBDataSet *IBQCom;
	TpFIBTransaction *IBTr;
	TFIBBCDField *IBQNumTelIDKLIENT_NUMTEL;
	TFIBBCDField *IBQNomID_CODETEL;
	TFIBBCDField *IBQNomIDNOM_CODETEL;
	TFIBWideStringField *IBQNomCODE_CODETEL;
	TFIBWideStringField *IBQNomGID_SCODETEL;
	TFIBWideStringField *IBQNomNAME_CODETEL;
	TFIBWideStringField *IBQNomCODOPER_CODETEL;
	TFIBBCDField *IBQNomIDNOMCOM_CODETEL;
	TFIBBCDField *IBQNomIDBASE_SCODETEL;
	TFIBBCDField *IBQNomIDEXT_DOUT_SCODETEL;
	TFIBBCDField *IBQNomIDEXT_BASE_SCODETEL;
	TFIBSmallIntField *IBQNomTYPE_TBL_SCODETEL;
	TFIBBCDField *IBQNomIDNOM;
	TFIBWideStringField *IBQNomNAMENOM;
	TFIBWideStringField *IBQNomKRNAMENOM;
	TFIBBCDField *IBQNomIDED;
	TFIBWideStringField *IBQNomNAMEED;
	TFIBBCDField *IBQNomKFED;
	TFIBBCDField *IBQComID_CODETEL;
	TFIBBCDField *IBQComIDNOM_CODETEL;
	TFIBWideStringField *IBQComCODE_CODETEL;
	TFIBWideStringField *IBQComGID_SCODETEL;
	TFIBWideStringField *IBQComNAME_CODETEL;
	TFIBWideStringField *IBQComCODOPER_CODETEL;
	TFIBBCDField *IBQComIDNOMCOM_CODETEL;
	TFIBBCDField *IBQComIDBASE_SCODETEL;
	TFIBBCDField *IBQComIDEXT_DOUT_SCODETEL;
	TFIBBCDField *IBQComIDEXT_BASE_SCODETEL;
	TFIBSmallIntField *IBQComTYPE_TBL_SCODETEL;
	TFIBBCDField *IBQComIDNOM;
	TFIBWideStringField *IBQComNAMENOM;
	TFIBWideStringField *IBQComKRNAMENOM;
	TFIBBCDField *IBQComIDED;
	TFIBWideStringField *IBQComNAMEED;
	TFIBBCDField *IBQComKFED;
	TFIBBCDField *IBQNomIDBASEDNOM;
	TFIBBCDField *IBQComIDBASEDNOM;
	TFIBBCDField *IBQComPRCOMIS_SCODETEL;
	TFIBBCDField *IBQNomPRCOMIS_SCODETEL;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDMPriemPlat(TComponent* Owner);

		IDMFibConnection * DM_Connection;
		bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	__int64 GetIDKlientPoNumTel(AnsiString code, AnsiString number);


	__int64 OpenNom(__int64 id_el_spr_codetel);
	__int64 OpenCom(__int64 id_el_spr_codetel);


};
//---------------------------------------------------------------------------
extern PACKAGE TDMPriemPlat *DMPriemPlat;
//---------------------------------------------------------------------------
#endif
