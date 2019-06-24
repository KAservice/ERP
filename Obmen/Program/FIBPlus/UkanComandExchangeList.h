//---------------------------------------------------------------------------

#ifndef UkanComandExchangeListH
#define UkanComandExchangeListH
#include "UkanComandExchange.h"

//---------------------------------------------------------------------------

class TkanComandExchangeList
{
private:


public:
		TkanComandExchangeList();
		~TkanComandExchangeList();
		TList * List;

		int ComandCount;
		bool GetFirstComand(void);
		TkanComandExchange* GetComand(int index_comand);


};

#endif
