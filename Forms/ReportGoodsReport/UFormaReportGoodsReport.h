//---------------------------------------------------------------------------

#ifndef UFormaReportGoodsReportH
#define UFormaReportGoodsReportH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprFirm.h"
#include "IDMFibConnection.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxCalendar.hpp"
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaReportGoodsReport : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label6;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonCreateReport;
	TcxButton *cxButtonClose;
	TcxCheckBox *GroupCheckPoDateCheckBox;
	TcxButtonEdit *NameSkladEdit;
	TcxButtonEdit *NameFirmEdit;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TcxButton *CreateReportRozncxButton;
	TcxButton *cxButtonCreateReportUnion;
	TAction *ActionClose;
	TcxCheckBox *cxCheckBoxSortPoTypeDoc;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonCreateReportClick(TObject *Sender);
	void __fastcall NameSkladEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall CreateReportRozncxButtonClick(TObject *Sender);
	void __fastcall cxButtonCreateReportUnionClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TFormaReportGoodsReport(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //��������� ������ ����������
		GUID ClsIdImpl;				 //GUID ������ ����������

		//�� ���� ����� ������� ������ ��� ������
		//��������� ������� ������ � ������ ����� (������� ���� ������� �� ���� ��� ������ ����-��)
		int ExternalEvent(IkanUnknown * pUnk,   //��������� �� �������� ������ (����� � ������� ������������ �����)
									REFIID id_object,      //��� ��������� �������
									int type_event,     //��� ������� � �������� �������
									int number_procedure_end  //����� ��������� � ���. �����, �������������� ������� ������
									);


		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		__int64 IdFirm;
		__int64 IdSkl;


        enum  {ER_NoRekv,ViborFirm,ViborSklad,ViborGrpNom,ViborNom, NO} EditRekvisit;


		IFormaSpiskaSprSklad * SpisokSklad;
		void OpenFormSpiskaSprSklad(void);

        IFormaSpiskaSprFirm *SpisokFirm;
		void OpenFormSpiskaSprFirm(void);





};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportGoodsReport *FormaReportGoodsReport;
//---------------------------------------------------------------------------
#endif
