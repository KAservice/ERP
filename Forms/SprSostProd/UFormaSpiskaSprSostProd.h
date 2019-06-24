//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprSostProdH
#define UFormaSpiskaSprSostProdH
//---------------------------------------------------------------------------

#include "IDMSprSostProd.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprEd.h"
#include "UDM.h"
#include "IFormaSpiskaSprSezKFSProd.h"
#include "IDMFibConnection.h"

#include "IFormaSpiskaSprProduce.h"
#include "IFormaSpiskaSprLossFactor.h"
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
#include <ActnList.hpp>
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
#include <DB.hpp>
#include "cxButtonEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"

//---------------------------------------------------------------------------
class TFormaSpiskaSprSostProd : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonDelete;
        TLabel *LabelNom;
        TLabel *LabelKolEd;
        TLabel *Label1;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1NKOL_SPROD;
	TcxGridDBColumn *cxGrid1DBTableView1BKOL_SPROD;
	TcxGridDBColumn *cxGrid1DBTableView1SPIS_SPROD;
	TcxGridDBColumn *cxGrid1DBTableView1KF_SPROD;
	TcxGridDBColumn *cxGrid1DBTableView1NAMENOM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEED;
	TcxGridDBColumn *cxGrid1DBTableView1RECNO;
	TcxGridDBColumn *cxGrid1DBTableView1SEZKF;
	TcxGridDBColumn *cxGrid1DBTableView1SEZKF_SPROD;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonReport;
	TcxButton *cxButtonSezKF;
	TAction *ActionClose;
	TAction *ActionOK;
	TAction *ActionSave;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SPRODUCE;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SLOSS_FACTOR;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAMENOMPropertiesButtonClick(
          TObject *Sender, int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAMEEDPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonSezKFClick(TObject *Sender);
	void __fastcall cxButtonReportClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionSaveExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAME_SPRODUCEPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxGrid1DBTableView1NAME_SLOSS_FACTORPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
        void DeleteElement();
		void OpenFormSpiskaSprNom(void);
		void OpenFormSpiskaSprEd(void);
				IFormaSpiskaSprNom *Nom;
		IFormaSpiskaSprEd * FormaSpiskaSprEd;
		IFormaSpiskaSprSezKFSProd *FormaSpiskaSprSezKFSProd;


		IFormaSpiskaSprProduce *FormaSpiskaSprProduce;
		IFormaSpiskaSprLossFactor *FormaSpiskaSprLossFactor;
		void OpenFormaSpiskaSprProduce(void);
		void OpenFormaSpiskaSprLossFactor(void);
		void EndViborProduce(void);
		void EndViborLossFactor(void);


		enum  {ER_NoRekv,ER_Nom, ER_Ed, ER_Produce, ER_LossFactor,
							ER_SezKf, ER_NO} EditRekvisit;
public:		// User declarations
		__fastcall TFormaSpiskaSprSostProd(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//из этой формы открыта другая для выбора
		//обработка события выбора в другой форме (которая была открыта из этой для выбора чего-то)
		int ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект (форму в которой производится выбор)
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									);


		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		//Текущий интерфейс
		IDMSprSostProd * DM;



		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме
		__int64 IdNomRest;
        __int64 IdNom;
		UnicodeString NameNom;

		double KolEdProd;
		UnicodeString NameEdProd;
		double KFEdProd;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprSostProd *FormaSpiskaSprSostProd;
//---------------------------------------------------------------------------
#endif
