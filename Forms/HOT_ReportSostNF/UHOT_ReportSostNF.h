//---------------------------------------------------------------------------

#ifndef UHOT_ReportSostNFH
#define UHOT_ReportSostNFH
//---------------------------------------------------------------------------

#include "UDM.h"
#include "USheetEditor.h"
#include "UDMQueryRead.h"
//---------------------------------------------------------------------------
class THOT_ReportSostNF
{
private:

public:
		THOT_ReportSostNF();
		~THOT_ReportSostNF();

		

		int IdObject;
		int IdCat;
		int IdNomer;
		int IdSost;

		TDateTime PosNach;
		TDateTime PosCon;
		TDMQueryRead * DMQuerySprNF;
		TDMQueryRead * DMQuerySostNF;

		void CreateReport(void);
		void OutputReportNomer(TSheetEditor *prForm);
        void OutputStringNomer(TSheetEditor *prForm);

		int x,y;

        int porNumStr;
        int porNumStrGrp;
        double SumRealReport;
		double SumSkReport;

		int IdTecFirm;
        int IdTecSklad;
        int IdTecGrpNom;
        int IdTecNom;

        AnsiString GetTextQuery(void);
		void CreateReportSostNF(TSheetEditor *prForm);

		void OutputZagolovokReport(TSheetEditor *prForm);

		void OutputStringFirm(TSheetEditor *prForm);
        int num_row_firm;
        double SumRealFirm;
		double SumSkFirm;
		void OutputStringItogiFirm(TSheetEditor *prForm);

		void OutputStringSklad(TSheetEditor *prForm);
        int num_row_sklad;
        double SumRealSklad;
		double SumSkSklad;
		void OutputStringItogiSklad(TSheetEditor *prForm);

		void OutputStringGrpNom(TSheetEditor *prForm);
        int num_row_grp_nom;
        double SumRealGrpNom;
		double SumSkGrpNom;
		void OutputStringItogiGrpNom(TSheetEditor *prForm);

		void OutputStringNom(TSheetEditor *prForm);

		void OutputPodavalReport(TSheetEditor *prForm);

        AnsiString GetTextZaprosDoc(void);
        void CreateReportDoc(TSheetEditor *prForm);
		void OutputStringDoc(TSheetEditor *prForm);



};

#endif
