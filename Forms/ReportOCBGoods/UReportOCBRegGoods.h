//---------------------------------------------------------------------------

#ifndef UReportOCBRegGoodsH
#define UReportOCBRegGoodsH
#include "IDMFibConnection.h"
#include "IDMQueryRead.h"
#include "UDM.h"
#include "USheetEditor.h"
#include "IDMSprFirm.h"
#include "UFormIndicator.h"
//---------------------------------------------------------------------------
class TReportOCBRegGoods

{
private:
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:
		TReportOCBRegGoods();
		~TReportOCBRegGoods();

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

	   bool Init();

		IDMQueryRead * DMQueryRead;
		IDMQueryRead * DMQueryReadDoc;

		__int64 IdFirm;
		__int64 IdSkl;
		__int64 IdGrpNom;
		__int64 IdNom;
		TDateTime DateNach;
		TDateTime DateCon;

		bool OutputDocDv;

		int numRow;
        int numCol;
        int porNumStr;
        int porNumStrGrp;
        double NachOstReport;
        double PrihodReport;
        double RashodReport;
        double ConOstReport;

        int IdTypePrice;

        int NumStrGrp;


		__int64 IdTecFirm;
		__int64 IdTecSklad;
		__int64 IdTecGrpNom;
        __int64 IdTecNom;

        void CreateReport(void);
        AnsiString GetTextQuery(void);
        void CreateReportOCB( TSheetEditor *prForm);

        void OutputZagolovokReport(TSheetEditor *prForm);

        void OutputStringFirm(TSheetEditor *prForm);
        int num_row_firm;
        double NachOstFirm;
        double PrihodFirm;
        double RashodFirm;
        double ConOstFirm;
        void OutputStringItogiFirm(TSheetEditor *prForm);

        void OutputStringSklad(TSheetEditor *prForm);
        int num_row_sklad;
        double NachOstSklad;
        double PrihodSklad;
        double RashodSklad;
        double ConOstSklad;
        void OutputStringItogiSklad(TSheetEditor *prForm);

        void OutputStringGrpNom(TSheetEditor *prForm);
        int num_row_grp_nom;
        double NachOstGrpNom;
        double PrihodGrpNom;
        double RashodGrpNom;
        double ConOstGrpNom;
        void OutputStringItogiGrpNom(TSheetEditor *prForm);

		void OutputStringNom(TSheetEditor *prForm);
		void OutputPodavalReport(TSheetEditor *prForm);

		AnsiString GetTextZaprosDoc(void);
		void CreateReportDoc(TSheetEditor *prForm);
		void OutputStringDoc(TSheetEditor *prForm);
		double TecConOstatokPoDocKol;
        double TecConOstatokPoDocSum;
	   TFormIndicator * FormIndicator;

};
#endif
