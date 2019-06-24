//---------------------------------------------------------------------------

#ifndef UkanMapiMessageListH
#define UkanMapiMessageListH
#include "UkanMapiMessage.h"
//---------------------------------------------------------------------------


class TkanMapiMessageList
{
private:


public:
		TkanMapiMessageList();
		~TkanMapiMessageList();
		TList * List;

		int CountElement;
		bool GetFirstComand(void);
		TkanMapiMessage* GetElement(int index);


};
#endif
