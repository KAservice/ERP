//---------------------------------------------------------------------------

#ifndef UFormaCreateReportKKMH
#define UFormaCreateReportKKMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <DBGrids.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "UDMDocCheck.h"
#include "IDMFibConnection.h"

#include "UFormaSpiskaSprFirm.h"
#include "UFormaSpiskaSprSklad.h"
#include "UFormaSpiskaSprKKM.h"
#include <ActnList.hpp>
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaCreateReportKKM : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label12;
        TLabel *Label15;
        TLabel *Label5;
        TLabel *Label13;
        TLabel *Label1;
        TLabel *Label2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDateEdit *DateTimePicker1;
	TcxDateEdit *DateTimePicker2;
	TcxButtonEdit *EditFirm;
	TcxButtonEdit *EditSklad;
	TcxButtonEdit *EditKKM;
	TcxTextEdit *NumberKlEdit;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonClose;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall EditFirmPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall EditSkladPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall EditKKMPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);

private:	// User declarations




        TFormaSpiskaSprFirm *SpisokFirm;
        TFormaSpiskaSprSklad * SpisokSklad;
        TFormaSpiskaSprKKM * SpisokKKM;

        void OpenFormSpiskaSprFirm(void);
        void OpenFormSpiskaSprSklad(void);
        void OpenFormSpiskaSprKKM(void);

        void __fastcall EndEdit(TObject *Sender);

        enum  {ViborFirm,ViborSklad, ViborKKM,  NO} EditRekvisit;


        void SummaCheck(void);

public:		// User declarations
        __fastcall TFormaCreateReportKKM(TComponent* Owner);



	IDMFibConnection * DM_Connection;
		bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


         void UpdateForm(void);


         HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца

		__int64 IdFirm;
		__int64 IdSklad;
        __int64 IdKKM;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaCreateReportKKM *FormaCreateReportKKM;
//---------------------------------------------------------------------------
#endif
