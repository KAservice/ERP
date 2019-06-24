//---------------------------------------------------------------------------

#ifndef UFormaViborBVNomH
#define UFormaViborBVNomH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMSprBVNom.h"
#include "IDMSprGrpBVNom.h"

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
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
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
#include "cxTreeView.hpp"
#include <ActnList.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaViborBVNom : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel5;
        TLabel *LabelNameGrp;
        TLabel *Label1;
        TDBText *DBTextTypePrice;
	TcxButton *cxButtonClose;
	TcxTextEdit *EditPodr;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1CODE_BVNOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1ZNACH_PRICE;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxTreeView *cxTreeView1;
	TActionList *ActionList1;
	TAction *OpenHelp;
	TAction *ActionClose;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonAllClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);
	void __fastcall cxTreeView1DblClick(TObject *Sender);
	void __fastcall cxTreeView1KeyPress(TObject *Sender, char &Key);
	void __fastcall OpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;

		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����

		void UpdateDerevo(int Pod);
public:		// User declarations
		__fastcall TFormaViborBVNom(TComponent* Owner);
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
		IDMSprBVNom* DM;
		IDMSprGrpBVNom *DMGrp;

		__int64 IdGrp;    //������� ������
		__int64 IdPod;    //�������������
        __int64 ViborIdNom;  //��������� ������������
        bool AllElement;//������� �������� ��� �������� ��� ���
        bool Prosmotr;

        void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaViborBVNom *FormaViborBVNom;
//---------------------------------------------------------------------------
#endif
