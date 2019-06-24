//---------------------------------------------------------------------------

#ifndef UFormaSprNomFindH
#define UFormaSprNomFindH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UDM.h"
#include "IDMSprNomFind.h"
#include "IDMSprGrpNom.h"
#include <Menus.hpp>
#include "IDMFibConnection.h"

#include "IDMSprSklad.h"
#include "IDMSprFirm.h"
//----------------------------------------------------------------------------

#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"


#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
#include <DBCtrls.hpp>
#include <ActnList.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxTreeView.hpp"
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxLookAndFeels.hpp"
#include "cxLabel.hpp"
#include "cxMemo.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
//---------------------------------------------------------------------------
class TFormaSprNomFind : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel5;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TLabel *LabelNameGrp;
        TToolButton *ToolButton4;
        TLabel *HintLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TToolButton *ToolButtonOnlyOstatok;
	TToolButton *ToolButtonPriceSklad;
	TcxTreeView *cxTreeView1;
	TcxButton *cxButtonClose;
	TToolButton *ToolButtonSaveSetup;
	TAction *ActionClose;
	TPanel *Panel6;
	TPanel *Panel7;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1ZNACH_PRICE;
	TcxGridDBColumn *cxGrid1DBTableView1SUMKOL;
	TcxGridDBColumn *cxGrid1DBTableView1IDNOM;
	TcxGridLevel *cxGrid1Level1;
	TcxTextEdit *cxTextEditWord;
	TcxButton *cxButtonFind;
	TcxLabel *cxLabel1;
	TcxMemo *cxMemoIshodNom;
	TcxLabel *cxLabel2;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEGN;
	TcxGridDBColumn *cxGrid1DBTableView1IDGRPNOM;
	TcxLookupComboBox *TypePricecxLookupComboBox;
	TcxLookupComboBox *NameFirmcxLookupComboBox;
	TcxLookupComboBox *NameSkladcxLookupComboBox;
	TcxButton *cxButtonGetPrice;
	TcxButton *cxButtonGetOstatki;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel5;
	TcxGridDBColumn *cxGrid1DBTableView1SHED;
	TcxButton *cxButtonOstPoServ;
	TcxGridDBColumn *cxGrid1DBTableView1REM_OST;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

	void __fastcall cxTreeView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall cxTreeView1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ToolButtonSaveSetupClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall cxButtonFindClick(TObject *Sender);
	void __fastcall cxButtonGetPriceClick(TObject *Sender);
	void __fastcall cxButtonGetOstatkiClick(TObject *Sender);
	void __fastcall cxButtonOstPoServClick(TObject *Sender);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����



		void UpdateDerevo(void);


		void SaveFormSetup(void);
		void LoadFormSetup(void);
		bool NoUpdateForm;

		IDMSprFirm * DMSprFirm;
        IDMSprSklad * DMSprSklad;

public:		// User declarations
		__fastcall TFormaSprNomFind(TComponent* Owner);

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

		//������� ���������
		IDMSprNomFind* DM;
		IDMSprGrpNom *DMGrp;

		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

		__int64 IdGrp;      //������� ������
		__int64 IdNom;       //������� �������

        bool AllElement;//������� �������� ��� �������� ��� ���



		void UpdateForm(void);

		UnicodeString NameNom;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSprNomFind *FormaSprNomFind;
//---------------------------------------------------------------------------
#endif
