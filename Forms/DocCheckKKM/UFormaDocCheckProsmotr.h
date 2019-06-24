//---------------------------------------------------------------------------

#ifndef UFormaDocCheckProsmotrH
#define UFormaDocCheckProsmotrH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMDocCheck.h"




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

#include <Buttons.hpp>
#include "cxClasses.hpp"
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
#include "cxContainer.hpp"
#include "cxDBEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtons.hpp"
#include "cxDropDownEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormaDocCheckProsmotr : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TLabel *Label11;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *FSummaCheck;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label7;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TDBText *DBTextFNameUser;
        TLabel *Label3;
        TDBText *SumDocDBText;
        TLabel *Label6;
        TDBText *IdKlientDBText;
        TLabel *Label17;
        TLabel *ProsmotrLabel;
        TDBText *NameBaseDBText;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TLabel *LabelDateDoc;
	TLabel *NamePriceLabel;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1KOLCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1KFCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICECHKT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1SKCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1NADCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1PRSKCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1PRNADCHKT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxDBTextEdit *NalcxDBTextEdit;
	TcxDBTextEdit *OplNalcxDBTextEdit;
	TcxDBTextEdit *OplPCcxDBTextEdit;
	TcxButton *cxButtonClose;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxComboBox *Operation;
	TcxDBTextEdit *NKlcxDBTextEdit;
	TcxDBTextEdit *NCheckcxDBTextEdit;
	TcxDBTextEdit *NameKKMcxDBTextEdit;
	TcxDBTextEdit *NameSDogovorcxDBTextEdit;
	TcxDBTextEdit *NameKlientcxDBTextEdit;
	TcxDBTextEdit *NameFirmcxDBTextEdit;
	TcxDBTextEdit *NumDoccxDBTextEdit;
	TcxDBTextEdit *NameSkladcxDBTextEdit;
	TActionList *ActionList;
	TAction *ActionClose;
	TcxDBTextEdit *PrefiksNumcxDBTextEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionCloseExecute(TObject *Sender);


private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����


		void SummaCheck(void);


		double SumCheck;
public:		// User declarations
		__fastcall TFormaDocCheckProsmotr(TComponent* Owner);

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
		IDMDocCheck *DM;
		void UpdateForm(void);

        bool Prosmotr;    //������ ��������
		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����
		__int64 IdDoc;           //������������� ������� ������

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocCheckProsmotr *FormaDocCheckProsmotr;
//---------------------------------------------------------------------------
#endif
