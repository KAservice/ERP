//---------------------------------------------------------------------------

#ifndef UDMReportDiscountDocCheckH
#define UDMReportDiscountDocCheckH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMQueryRead.h"


//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TDMReportDiscountDocCheck : public TDataModule
{
__published:	// IDE-managed Components
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDMReportDiscountDocCheck(TComponent* Owner);

	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;


		bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	IDMQueryRead *DM;
	IDMQueryRead * DMDoc;

	AnsiString GetTextQuery(__int64 id_firm, __int64 id_sklad,
											__int64 id_grp, __int64 id_nom,
											bool only_type, int type_nom);

	void OpenReport(TDateTime pos_nach, TDateTime pos_con,
											__int64 id_firm, __int64 id_sklad,
											__int64 id_grp, __int64 id_nom,
											bool only_type, int type_nom);

	AnsiString GetTextZaprosDoc(__int64 id_firm,
								__int64 id_sklad,
								__int64 id_nom);

	void OpenReportDoc(TDateTime pos_nach, TDateTime pos_con,
													__int64 id_firm,
													__int64 id_sklad,
													__int64 id_nom);

};
//---------------------------------------------------------------------------
extern PACKAGE TDMReportDiscountDocCheck *DMReportDiscountDocCheck;
//---------------------------------------------------------------------------
#endif
