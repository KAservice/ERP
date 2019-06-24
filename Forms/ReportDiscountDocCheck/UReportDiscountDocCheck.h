//---------------------------------------------------------------------------

#ifndef UReportDiscountDocCheckH
#define UReportDiscountDocCheckH
//#include "UDM.h"
#include "USheetEditor.h"
//#include "UDMQueryRead.h"
#include "UDMReportDiscountDocCheck.h"
//---------------------------------------------------------------------------
class TReportDiscountDocCheck
{
private:

public:
		TReportDiscountDocCheck();
		~TReportDiscountDocCheck();

	IDMFibConnection * DM_Connection;
	IkanCom *InterfaceGlobalCom;
	IkanUnknown * InterfaceMainObject;
	IkanUnknown * InterfaceOwnerObject;

	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		__int64 IdFirm;
		__int64 IdSklad;
		__int64 IdGrp;
		__int64 IdNom;
		int TypeNom;
		bool OnlyType;
		bool AddDoc;
		TDateTime PosNach;
		TDateTime PosCon;
//		TDMQueryRead * DMQueryRead;
//		TDMQueryRead * DMQueryDoc;

		void CreateReport(void);

		int x,y;

        int porNumStr;
        int porNumStrGrp;
        double SumRealReport;
		double SumSkReport;

		__int64 IdTecFirm;
		__int64 IdTecSklad;
		__int64 IdTecGrpNom;
        __int64 IdTecNom;

       // AnsiString GetTextQuery(void);
		void CreateReportDiscount(TSheetEditor *prForm);

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

        //AnsiString GetTextZaprosDoc(void);
        void CreateReportDoc(TSheetEditor *prForm);
		void OutputStringDoc(TSheetEditor *prForm);


        TDMReportDiscountDocCheck * DM;
};

#endif
