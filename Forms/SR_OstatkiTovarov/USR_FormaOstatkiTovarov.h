//---------------------------------------------------------------------------

#ifndef USR_FormaOstatkiTovarovH
#define USR_FormaOstatkiTovarovH
//---------------------------------------------------------------------------

#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMTableExtPrintForm.h"
#include "UDM.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprGrpNom.h"
#include "IFormaSpiskaSprNom.h"
//---------------------------------------------------------------------------
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
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtonEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxCalendar.hpp"
#include "cxLookAndFeels.hpp"
#include <ExtCtrls.hpp>
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
//---------------------------------------------------------------------------
class TSR_FormaOstatkiTovarov : public TForm
{
__published:	// IDE-managed Components
	TPopupMenu *PopupMenuExtModule;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TcxButtonEdit *NameNomEdit;
	TcxButtonEdit *NameGrpNomEdit;
	TcxButtonEdit *NameSkladEdit;
	TcxButtonEdit *NameFirmEdit;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TcxCheckBox *DocDvcxCheckBox;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TAction *ActionClose;
	TPanel *Panel2;
	TcxButton *cxButtonClose;
	TcxButton *cxButton1;
	TpFIBTransaction *pFIBTransaction;
	TpFIBDataSet *pFIBDataSet;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TDataSource *DataSource;
	TFIBWideStringField *pFIBDataSetREM_FIRM_NAME;
	TFIBWideStringField *pFIBDataSetOSN_FIRM_NAME;
	TFIBWideStringField *pFIBDataSetOSN_SKLAD_NAME;
	TFIBWideStringField *pFIBDataSetREM_SKLAD_NAME;
	TFIBWideStringField *pFIBDataSetARTNOM;
	TFIBIntegerField *pFIBDataSetCODENOM;
	TFIBWideStringField *pFIBDataSetSHED;
	TFIBWideStringField *pFIBDataSetNAMENOM;
	TFIBBCDField *pFIBDataSetKOL_RGGOODS;
	TFIBBCDField *pFIBDataSetKOL_REM_RGGOODS;
	TcxGridDBColumn *cxGrid1DBTableView1REM_FIRM_NAME;
	TcxGridDBColumn *cxGrid1DBTableView1OSN_FIRM_NAME;
	TcxGridDBColumn *cxGrid1DBTableView1OSN_SKLAD_NAME;
	TcxGridDBColumn *cxGrid1DBTableView1REM_SKLAD_NAME;
	TcxGridDBColumn *cxGrid1DBTableView1ARTNOM;
	TcxGridDBColumn *cxGrid1DBTableView1CODENOM;
	TcxGridDBColumn *cxGrid1DBTableView1SHED;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_RGGOODS;
	TcxGridDBColumn *cxGrid1DBTableView1KOL_REM_RGGOODS;
	TcxButton *cxButtonUpdate;
	TcxButton *cxButtonKartTovara;
	TFIBBCDField *pFIBDataSetIDNOM;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall NameNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameGrpNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmEditPropertiesButtonClick(TObject *Sender,
		  int AButtonIndex);

 		  		//������� ����� � �������
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall cxButtonUpdateClick(TObject *Sender);
	void __fastcall cxButtonKartTovaraClick(TObject *Sender);
				  
private:	// User declarations

    bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

public:		// User declarations
		__fastcall TSR_FormaOstatkiTovarov(TComponent* Owner);

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
		__int64 IdGrpNom;
		__int64 IdNom;

		void __fastcall EndEdit(TObject *Sender);

		enum  {ER_NoRekv,ViborFirm,ViborSklad,ViborGrpNom,ViborNom, NO} EditRekvisit;


		IFormaSpiskaSprSklad * SpisokSklad;
		void OpenFormSpiskaSprSklad(void);


		IFormaSpiskaSprFirm *SpisokFirm;
		IFormaSpiskaSprGrpNom * SpisokGrpNom;
		IFormaSpiskaSprNom *SpisokNom;

		void OpenFormSpiskaSprNom(void);
		void OpenFormSpiskaSprFirm(void);
		void OpenFormSpiskaSprGrpNom(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TSR_FormaOstatkiTovarov *SR_FormaOstatkiTovarov;
//---------------------------------------------------------------------------
#endif
