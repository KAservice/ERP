//---------------------------------------------------------------------------

#ifndef UART_FormaSpiskaSprNaborInfBlockH
#define UART_FormaSpiskaSprNaborInfBlockH
//---------------------------------------------------------------------------

#include "UDM.h"
#include "IART_DMSprNaborInfBlock.h"
#include "IART_DMSprNaborInfBlockGrp.h"
#include "IDMFibConnection.h"
#include "IDMTableExtPrintForm.h"
//-----------------------------------------------------------------------------

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
#include <Menus.hpp>
#include <ActnList.hpp>
#include "cxClasses.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
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
#include "cxTreeView.hpp"
#include <DB.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TART_FormaSpiskaSprNaborInfBlock : public TForm
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
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxTreeView *cxTreeView1;
	TcxButton *cxButtonClose;
	TAction *ActionClose;
	TPopupMenu *PopupMenuExtModule;
	TToolButton *ToolButton5;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_ART_N_IB;
	TcxGridDBColumn *cxGrid1DBTableView1ID_ART_N_IB;
	TcxGridLevel *cxGrid1Level1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewGrpClick(TObject *Sender);
        void __fastcall ToolButtonEdiGrpClick(TObject *Sender);
        void __fastcall ToolButtonDeleteGrpClick(TObject *Sender);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonEditClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonAllClick(TObject *Sender);
        void __fastcall ToolButtonIsmGrpClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxTreeView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall ActionCloseExecute(TObject *Sender);
		//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

			//������� ����� � �������
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

        void OpenFormElement();
		void OpenFormNewElement();
		void DeleteElement();

		void OpenFormGrpElement();
		void OpenFormNewGrpElement();
		void DeleteGrpElement();

		void UpdateDerevo(void);
		enum{NO,ViborGrp,ViborElement, RekvisitPodborNom} ViborRekvisit;

public:		// User declarations
		__fastcall TART_FormaSpiskaSprNaborInfBlock(TComponent* Owner);

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
        bool Prosmotr;    //������ ��������
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����

		IART_DMSprNaborInfBlock* DM;
		IART_DMSprNaborInfBlockGrp *DMGrp;


		__int64 IdGrp;      //������� ������
		__int64 IdElement;       //������� �������
		bool AllElement;//������� �������� ��� �������� ��� ���


        void UpdateForm(void);
        UnicodeString TextMessage;

};
//---------------------------------------------------------------------------
extern PACKAGE TART_FormaSpiskaSprNaborInfBlock *ART_FormaSpiskaSprNaborInfBlock;
//---------------------------------------------------------------------------
#endif
