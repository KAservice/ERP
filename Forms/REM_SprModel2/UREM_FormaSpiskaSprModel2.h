//---------------------------------------------------------------------------

#ifndef UREM_FormaSpiskaSprModel2H
#define UREM_FormaSpiskaSprModel2H
//---------------------------------------------------------------------------


#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMTableExtPrintForm.h"
#include "UDM.h"
#include "IREM_DMSprModel2.h"
#include "IREM_DMSprModel2Grp.h"
#include "IREM_DMSprTypeDevice.h"
#include "IREM_FormaSpiskaSprModel.h"
#include "IREM_FormaSpiskaSprTypeDevice.h"
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
class TREM_FormaSpiskaSprModel2 : public TForm
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
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxTreeView *cxTreeView1;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TcxButtonEdit *NameGroupElementcxButtonEdit;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_REM_SMODEL2;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewGrpClick(TObject *Sender);
        void __fastcall ToolButtonEdiGrpClick(TObject *Sender);
        void __fastcall ToolButtonDeleteGrpClick(TObject *Sender);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonAllClick(TObject *Sender);
        void __fastcall ToolButtonChancheGrpClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
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

private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		IDMTableExtPrintForm * DMTableExtPrintForm;
		void RunExternalModule(__int64 id_module, int type_module);

		IREM_DMSprModel2Grp *DMGrp;
		IREM_DMSprTypeDevice * DMGroupElement;

		IREM_FormaSpiskaSprModel * FormaViborOsnSpr;
		IREM_FormaSpiskaSprModel * FormaViborOsnSprCopy;

		IREM_FormaSpiskaSprTypeDevice * FormaViborGroupElement;


		void OpenFormViborOsnSpr();

		void OpenFormSpiskaSprGroupElement();

		void OpenFormGrpElement();
		void OpenFormNewGrpElement();
		void DeleteGrpElement();

		void UpdateDerevo(int id_group_element);

		enum{NO,VR_ViborGrp, VR_ViborOsnSpr, VR_ViborGroupElement} ViborRekvisit;

		int KolAddElement;
public:		// User declarations
		__fastcall TREM_FormaSpiskaSprModel2(TComponent* Owner);

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

		IREM_DMSprModel2* DM;

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
extern PACKAGE TREM_FormaSpiskaSprModel2 *REM_FormaSpiskaSprModel2;
//---------------------------------------------------------------------------
#endif
