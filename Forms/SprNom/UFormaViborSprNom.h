//---------------------------------------------------------------------------

#ifndef UFormaViborSprNomH
#define UFormaViborSprNomH
//---------------------------------------------------------------------------
#include "IDMSprNom.h"
#include "IDMSprGrpNom.h"
#include "IDMFibConnection.h"
#include "UDM.h"
//--------------------------------------------------------------------------
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
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxTreeView.hpp"
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaViborSprNom : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel5;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNewGrp;
        TToolButton *ToolButtonEdiGrp;
        TToolButton *ToolButtonDeleteGrp;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonEdit;
        TToolButton *ToolButtonDelete;
        TLabel *LabelNameGrp;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonAll;
        TToolButton *ToolButtonIsmGrp;
        TLabel *HintLabel;
        TToolButton *ToolButtonOst;
        TLabel *LabelFirma;
        TLabel *LabelSklad;
	TcxComboBox *SpisokTypePrice;
	TcxButton *cxButtonClose;
	TcxTreeView *cxTreeView1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1ZNACH_PRICE;
	TcxGridDBColumn *cxGrid1DBTableView1SUMKOL;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TToolButton *saveSetupFormToolButton;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonAllClick(TObject *Sender);
        void __fastcall TreeView1CustomDrawItem(TCustomTreeView *Sender,
          TTreeNode *Node, TCustomDrawState State, bool &DefaultDraw);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ToolButtonOstClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall cxTreeView1KeyPress(TObject *Sender, char &Key);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall cxTreeView1DblClick(TObject *Sender);
	void __fastcall saveSetupFormToolButtonClick(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����
		void UpdateDerevo(void);



public:		// User declarations
		__fastcall TFormaViborSprNom(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������

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
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

		IDMSprNom* DM;
		IDMSprGrpNom *DMGrp;

        __int64 IdGrp;    //������� ������
        bool AllElement;//������� �������� ��� �������� ��� ���




        
        void UpdateForm(void);
		bool FlagOstatok;
		void LoadFormSetup();
		void SaveFormSetup();


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaViborSprNom *FormaViborSprNom;
//---------------------------------------------------------------------------
#endif
