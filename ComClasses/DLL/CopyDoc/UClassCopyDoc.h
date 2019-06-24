//---------------------------------------------------------------------------

#ifndef UClassCopyDocH
#define UClassCopyDocH


//---------------------------------------------------------------------------
#include "IDMFibConnection.h"


//---------------------------------------------------------------------------


#include <Classes.hpp>


class TClassCopyDoc
{
private:
		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;

	   	bool REM_CopyDocReal(__int64 id_doc, UnicodeString type_new_doc,
									 bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3);


		bool REM_CopyDocRealInPerem(__int64 id_doc, bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3);



	   bool REM_CopyDocAktInAkt(__int64 id_doc, bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3);



		__int64 CreateNewDocNaOsnPer(__int64 id_doc,UnicodeString type_new_doc,
									 bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3);

	   __int64 REM_CreateNewDocNaOsnPerDocRemPer(__int64 id_doc,
									 bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3);

	   __int64 CreateNewDocNaOsnOstNom(__int64 id_doc, UnicodeString type_new_doc,
									 bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3);

	   __int64 REM_CreateNewDocNaOsnOstNomDocRemOstNom(__int64 id_doc,
									 bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3);


public:
		TClassCopyDoc();
		~TClassCopyDoc();

		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

	typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl;
		bool flDeleteImpl;
		int CodeError;
		UnicodeString TextError;
		bool Init(void);
		int  Done(void);



		bool CreateNewCopyDoc(__int64 id_doc, UnicodeString type_doc, UnicodeString type_new_doc,
									 bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3);





	   __int64 CreateNewDocNaOsn(__int64 id_doc, UnicodeString type_doc,UnicodeString type_new_doc,
									 bool fl_save_doc, bool fl_open_form_doc,
									 int param1, int param2, int param3);


};

//---------------------------------------------------------------------------
#endif
