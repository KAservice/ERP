//---------------------------------------------------------------------------

#ifndef UDMUribAllSprH
#define UDMUribAllSprH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "UDMXTableIsm.h"
#include "UDMXDataOut.h"
#include "UDMXFieldBase.h"
#include "UDMXTableBase.h"
#include "UDMSprObmenTypeDoc.h"
#include "UDMSprObmenSklad.h"
#include "UDMSprTypePrice.h"
#include "UDMSprPrice.h"
#include "FIBDatabase.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBQuery.hpp"
//---------------------------------------------------------------------------
class TDMUribAllSpr : public TDataModule
{
__published:	// IDE-managed Components
	TIBQuery *IBQ33;
        TIBTransaction *IBTr1;
	TIBQuery *IBQ233;
        TIBTransaction *IBTr2;
	TpFIBTransaction *IBTr;
	TpFIBQuery *IBQ;
	TpFIBQuery *IBQ2;
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMUribAllSpr(TComponent* Owner);


        String FileNameXML;
        String CatalogFile;

        String FloatToStringComma(double value);
        double StringToFloatComma(String value);

        //заполение таблицы выходных данных ----------------------------
        TDMXTableIsm *TableIsm;
        TDMXDataOut * DataOut;
        TDMSprObmenTypeDoc * DMTypeDoc;
        TDMSprObmenSklad  * DMSprObmenSklad;


        void SaveFileXML(String str);
        String FormatForXML(String s);

        //создание XML файла -------------------------------------------
        void CreateXMLDoc(int id_base);
        void OutputTableInXMLFile(String table_name);
        void OutputFKInXMLFile(String name_field, int value_field );

        String GetNameGid(String name_table);

        //--------------------------------------------------------------
        HANDLE IdRodForm;
        HANDLE IdDochForm;

        bool Vibor;
        bool OutReady;





        int IdBase;
        String PrefiksBase;
        String FileNameOut;
        String CatalogObmena;
		int OutSprNacenka;
		int OutZakPrice;

        TDMXTableBase *DMXTableBase;
        TDMXFieldBase *DMXFieldBase;

        bool CheckFieldForOutput(String name_field, String name_table);
        bool CheckRecordForOutput(AnsiString name_table);
        
        void OutProtocol(String str);

        void OutputSpr(String name_table);
        bool NoOutputEd;

        int IdMessage;
        AnsiString GIDMessage;

		int NumRecord;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMUribAllSpr *DMUribAllSpr;
//---------------------------------------------------------------------------
#endif
