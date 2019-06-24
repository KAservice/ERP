//---------------------------------------------------------------------------

#ifndef UkanComandBuilderH
#define UkanComandBuilderH
//---------------------------------------------------------------------------
#include "UkanComandExchange.h"
#include "UkanMAPI.h"
#include <Classes.hpp>
#include "UkanComandExchangeList.h"
#include "UkanMapiMessage.h"


class TkanComandBuilder
{
private:
        enum {TypeExchange_ForCatalogObmena,TypeExchange_ForMAPI, TypeExchange_No} TypeExchange;
		UnicodeString GetCatalogObmena(__int64 id_tec_base,__int64 id_base_for_obmen);
		UnicodeString GetStringParameter(UnicodeString name_parameter);


       void GetTypeObmen(void);

public:
		TkanComandBuilder();
		~TkanComandBuilder();

		__int64 IdTecBase;
		__int64 IdBaseForObmen;
		UnicodeString LocalCatalog;
		UnicodeString TextError;

		bool GetListComand(TkanComandExchangeList * comand_list);
		bool GetListForObmenCatalog(TkanComandExchangeList * comand_list);
		bool GetListForObmenMAPI(TkanComandExchangeList * comand_list);


		//удаляет команду из первоисточника
		bool DeleteComandFromSource(TkanComandExchange * comand);
		bool DeleteComandFromCatalogObmena(TkanComandExchange * comand);
		bool DeleteComandFromMAPI(TkanComandExchange * comand);

		//посылает команду в первоисточник
		bool SendComandFromSource(TkanComandExchange * comand);
		bool SendComandForCatalogObmena(TkanComandExchange * comand);
		bool SendComandForMAPI(TkanComandExchange * comand);


		bool CreateComandFromMailMessage(TkanMapiMessage *mapi_message,TkanComandExchange * comand);
		bool CreateKanMessageFromComand(TkanMapiMessage *mapi_message,TkanComandExchange * comand);

};
#endif
