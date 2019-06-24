//---------------------------------------------------------------------------

#ifndef UkanComandExchangeH
#define UkanComandExchangeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//#include "UkanMAPI.h"
#include "UkanGlobalConstant.h"

//---------------------------------------------------------------------------
class TkanComandExchange
{
private:

	UnicodeString GetCatalogObmena(__int64 id_tec_base,__int64 id_base_for_obmen);
	UnicodeString GetStringParameter(UnicodeString name_parameter);

	   //	bool DeleteComandFromSource_ObmenCatalogObmena(void);
	   //	bool DeleteComandFromSource_ObmenMAPI(void);

	  //	bool SendComandFromSource_ObmenCatalogObmena(void);
	  //	bool SendComandFromSource_ObmenMAPI(void);

	 //	void GetTypeObmen(void);
		enum {TypeExchange_ForCatalogObmena,TypeExchange_ForMail, TypeExchange_No} TypeExchange;
public:
		TkanComandExchange();
		~TkanComandExchange();

		UnicodeString ID;
		bool RunComand;//надо ли выполнять даную команду
		//например после успешного выполнения ставим false;
		UnicodeString TextError;
		int IdTecBase;
		int IdBaseForObmen;
		UnicodeString LocalCatalog;

		enum {TypeComandExchange_UpdateBase,
				TypeComandExchange_CreateFile,
				TypeComandExchange_No} TypeComandExchange;


		//список вложенных (присоединенных) файлов
		TStringList * FileList;
		int FileList_GetCount(void);
		UnicodeString FileList_GetString(int index_string);
		void FileList_AddString(UnicodeString file_name);

		bool NewComand(void);

};


#endif
