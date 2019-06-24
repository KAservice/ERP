//---------------------------------------------------------------------------

#ifndef UReportDvRegDocH
#define UReportDvRegDocH
#include "IDMFibConnection.h"
#include "ISheetEditor.h"

//---------------------------------------------------------------------------
class TReportDvRegDoc
{
private:


public:
		TReportDvRegDoc();
		~TReportDvRegDoc();


	IDMFibConnection * DM_Connection;
	IkanCom * InterfaceGlobalCom;
	IkanUnknown * InterfaceMainObject;




	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		__int64 IdDoc;

		void CreateReport(void);
		void OutputReport_RegAdvCust(void);
		void OutputReport_RegBank(void);
		void OutputReport_RegGoods(void);
		void OutputReport_RegKassa(void);
		void OutputReport_RegOstNom(void);
		void OutputReport_RegOtrSpis(void);
		void OutputReport_RegPaySale(void);
		void OutputReport_RegSebProd(void);
		void OutputReport_RegVipProd(void);
		void OutputReport_RegVSRasch(void);
		void OutputReport_RegReal(void);

		int x,y;

		ISheetEditor * SE;
};


#endif
