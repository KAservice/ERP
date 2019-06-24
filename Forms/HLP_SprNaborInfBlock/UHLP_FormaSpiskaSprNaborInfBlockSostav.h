//---------------------------------------------------------------------------

#ifndef UHLP_FormaSpiskaSprNaborInfBlockSostavH
#define UHLP_FormaSpiskaSprNaborInfBlockSostavH
//---------------------------------------------------------------------------


#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMTableExtPrintForm.h"
#include "UDM.h"
#include "IHLP_DMSprNaborInfBlockSostav.h"
#include "IHLP_DMSprNaborInfBlockSostavGrp.h"
#include "IHLP_DMSprNaborInfBlock.h"
#include "IHLP_FormaSpiskaSprInfBlock.h"
#include "IHLP_FormaSpiskaSprNaborInfBlock.h"
//----------------------------------------------------------------------------
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
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class THLP_FormaSpiskaSprNaborInfBlockSostav : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
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
        TLabel *Label1;
        TToolButton *ToolButtonChancheGrp;
        TToolButton *ToolButton5;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxTreeView *cxTreeView1;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TcxButtonEdit *NameGroupElementcxButtonEdit;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_ART_IB;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewGrpClick(TObject *Sender);
        void __fastcall ToolButtonEdiGrpClick(TObject *Sender);
        void __fastcall ToolButtonDeleteGrpClick(TObject *Sender);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonAllClick(TObject *Sender);
        void __fastcall ToolButtonChancheGrpClick(TObject *Sender);
	void __fastcall cxTreeView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall EditPodrPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1KeyDown(TObject *Sender, WORD &Key,
		  TShiftState Shift);

	//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAME_ART_IBPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		IDMTableExtPrintForm * DMTableExtPrintForm;
		void RunExternalModule(__int64 id_module, int type_module);

		IHLP_DMSprNaborInfBlockSostavGrp *DMGrp;
		IHLP_DMSprNaborInfBlock * DMGroupElement;

		IHLP_FormaSpiskaSprInfBlock * FormaViborOsnSpr;
		IHLP_FormaSpiskaSprInfBlock * FormaViborOsnSprCopy;

		IHLP_FormaSpiskaSprNaborInfBlock * FormaViborGroupElement;


		void OpenFormViborOsnSpr();

		void OpenFormSpiskaSprGroupElement();

		void OpenFormGrpElement();
		void OpenFormNewGrpElement();
		void DeleteGrpElement();

		void UpdateDerevo(int id_group_element);

		enum{NO,VR_ViborGrp, VR_ViborOsnSpr, VR_ViborGroupElement} ViborRekvisit;

		int KolAddElement;
public:		// User declarations
		__fastcall THLP_FormaSpiskaSprNaborInfBlockSostav(TComponent* Owner);

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

		IHLP_DMSprNaborInfBlockSostav* DM;

		bool Prosmotr;

		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����
		bool Podbor;

		__int64 IdGroupElement;
		UnicodeString NameGroupElement;
		__int64 IdGrp;  //������� ������
		__int64 IdElement;
		__int64 ViborIdOsnElement;
		bool AllElement;//������� �������� ��� �������� ��� ���

		void DeleteElement();
        void UpdateForm(void);


};
//---------------------------------------------------------------------------
extern PACKAGE THLP_FormaSpiskaSprNaborInfBlockSostav *HLP_FormaSpiskaSprNaborInfBlockSostav;
//---------------------------------------------------------------------------
#endif
