//---------------------------------------------------------------------------

#ifndef UFormaDocRealRoznTouchH
#define UFormaDocRealRoznTouchH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IDMDocRealRozn.h"
#include "IDMFibConnection.h"
#include "IDisplayPok.h"
#include "IScaner.h"
#include "IFiskReg.h"
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
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDocRealRoznTouch : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TButton *ButtonClose;
        TPanel *Panel4;
        TLabel *FSummaCheck;
        TPanel *Panel1;
        TLabel *LabelNameDoc;
        TLabel *LabelPrim;
        TButton *ButtonOK;
        TLabel *LabelFirm;
        TLabel *LabelSklad;
        TDBText *DBTextFNameUser;
        TDBText *SumDocDBText;
        TLabel *LabelKlient;
        TButton *ButtonPrint;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_DREALROZNT;
	TcxGridDBColumn *cxGrid1DBTableView1KF_DREALROZNT;
	TcxGridDBColumn *cxGrid1DBTableView1PRICE_DREALROZNT;
	TcxGridDBColumn *cxGrid1DBTableView1SUM_DREALROZNT;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1PRSK_DREALROZNT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMSK_DREALROZNT;
	TDBText *NameFirmDBText;
	TDBText *NameSkladDBText;
	TDBText *NameKlientDBText;
	TDBText *PrimDBText;
	TDBText *NumDocDBText;
	TDBText *DateDocDBText;
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonSaveClick(TObject *Sender);
        void __fastcall ButtonOKClick(TObject *Sender);
        void __fastcall ButtonPrintClick(TObject *Sender);

private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // ��� ������� ������ � ������� ����� ��� �������� � ���������� �����


        enum  {ER_NoRekv,ViborTovar,ViborEdinica,ViborFirm,ViborSklad,ViborKlient, NO} EditRekvisit;
		bool PrintDocFR(void);

	IFiskReg  *glFR;
	IDisplayPok * glDisplayPok;
public:		// User declarations
		__fastcall TFormaDocRealRoznTouch(TComponent* Owner);

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


		bool Vibor;                        //����� ������� ��� ������
		int NumberProcVibor;               //����� ��������� ������������ ��� ��������� ������ �� ������� �����
        bool Prosmotr;

		 IDMDocRealRozn *DM;


         void UpdateForm(void);

		UnicodeString NameFirm;
		UnicodeString NameSklad;
		UnicodeString NameKlient;
		UnicodeString NameDoc;
		UnicodeString Prim;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocRealRoznTouch *FormaDocRealRoznTouch;
//---------------------------------------------------------------------------
#endif
