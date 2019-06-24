//---------------------------------------------------------------------------

#ifndef UReportGoodsReportH
#define UReportGoodsReportH
#include "IDMQueryRead.h"
#include "UDM.h"
#include "USheetEditor.h"
#include "IDMSprFirm.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------

class TReportGoodsReport
{
private:
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:
		TReportGoodsReport();
		~TReportGoodsReport();
		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
	bool Init(void);


		__int64 IdFirm;
		__int64 IdSklad;

		int GroupCheckPoDate;
		bool SortPoTypeDoc;

		TDateTime PosNach;
		TDateTime PosCon;
		IDMQueryRead * DMQueryRead;
		IDMSprFirm * DMSprFirm;

		void CreateReport(void);
		void OutputZagolovokReport(TSheetEditor *prForm);
		void GreateReportPrihod(TSheetEditor *prForm);
		void OutputStringPrihod(TSheetEditor *prForm);
		void OutputItogiPrihoda(TSheetEditor *prForm);
        void OutputZagolovokRashod(TSheetEditor *prForm);
		void GreateReportRashod(TSheetEditor *prForm);
		void OutputStringRashod(TSheetEditor *prForm);
		void OutputPodvalReport(TSheetEditor *prForm);
		int x,y;

        int porNumStr;
		int porNumStrGrp;
		double SumNachOst;
		double SumPrihod;
		double SumRashod;
		double SumConOst;



		void CreateReportRozn(void);
		void GreateReportPrihodRozn(TSheetEditor *prForm);
		void GreateReportRashodRozn(TSheetEditor *prForm);


};
#endif
