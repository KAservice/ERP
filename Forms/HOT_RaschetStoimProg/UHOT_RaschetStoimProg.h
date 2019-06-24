//---------------------------------------------------------------------------

#ifndef UHOT_RaschetStoimProgH
#define UHOT_RaschetStoimProgH


#include "IDMFibConnection.h"
#include "UHOT_StringDoc.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TRaschetStoimProg
		{
private:


 public:
		TRaschetStoimProg();
		~TRaschetStoimProg();

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //��������� ������ ����������
		GUID ClsIdImpl;				 //GUID ������ ����������



		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		//��������� ��� �������
		bool AddBron;
		TDateTime PosNach;
		TDateTime PosCon;
		TDateTime PosNachBron;
		TDateTime PosConBron;
		__int64 IdNomer;
		__int64 IdTypePos;
		AnsiString NameTypePos;
		__int64 IdTypePrice;


		void GetTableDoc(void); //��������� �� ������ ������
		bool GetString(void);   //�������� ������, ���� ���� ������ �� true

		int NumberTecString;




		TList * ResultList;
		TStringDoc * StringDoc;


		void AddStringNewReal( TDateTime pos_nach, TDateTime pos_con,
							__int64 id_nom, AnsiString name_nom,
							__int64 id_ed, double kf, AnsiString name_ed,
							double price,
							double kol,
							int type_usl
							);

        };
//---------------------------------------------------------------------------
#endif
