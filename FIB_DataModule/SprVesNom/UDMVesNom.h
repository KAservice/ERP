//---------------------------------------------------------------------------

#ifndef UDMVesNomH
#define UDMVesNomH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
//---------------------------------------------------------------------------
class TDMSprVesNom : public TDataModule
{
__published:	// IDE-managed Components
        TIBTransaction *IBTr;
        TDataSource *DataSourceTable;
        TIBDataSet *Table;
        TIntegerField *TableID_SPROD;
        TIntegerField *TableIDNOM_SPROD;
        TIBBCDField *TableNKOL_SPROD;
        TIBBCDField *TableBKOL_SPROD;
        TIBBCDField *TableKFPRICE_SPROD;
        TIntegerField *TableIDKOMPL_SPROD;
        TIBStringField *TableNAMENOM;
        TIntegerField *TableRECNO;
        TSmallintField *TableSPIS_SPROD;
        TIntegerField *TableIDED_SPROD;
        TIBBCDField *TableKF_SPROD;
        TIBStringField *TableNAMEED;
        TIntegerField *TableTNOM;
        TFloatField *TableNABASED;
        TFloatField *TableNNABASED;
        TIBBCDField *TableVALUE_SSEZKF;
        TFloatField *TableSEZKF;
        TIBBCDField *TableVALUE_SSEZKF_SPROD;
        TFloatField *TableSEZKF_SPROD;
        TIntegerField *TableIDNOMREST_SPROD;
        TIBStringField *TableGID_SSPROD;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall TableCalcFields(TDataSet *DataSet);
        void __fastcall TableSPIS_SPRODGetText(TField *Sender,
          AnsiString &Text, bool DisplayText);
        void __fastcall TableSPIS_SPRODSetText(TField *Sender,
          const AnsiString Text);
        void __fastcall TableNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprVesNom(TComponent* Owner);

        int IdNom;
        int IdNomRest;
        void OpenTable(int Nom);
        void NewElement(int Nom);
        void DeleteElement();
        void SaveIsmen();
        void CancelIsmen();


        float KolEdProd;    //количество на которое задан состав
        float KFEdProd;     //коэффициент единицы
        TDateTime Pos;
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprVesNom *DMSprVesNom;
//---------------------------------------------------------------------------
#endif
