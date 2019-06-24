//---------------------------------------------------------------------------

#ifndef UkasObjectInfoH
#define UkasObjectInfoH

#include "UkasObjectInfoProperties.h"
//---------------------------------------------------------------------------
class TkasObjectInfo
//конкретный объект
{
private:




public:
		TkasObjectInfo();
		~TkasObjectInfo();


	   //список свойств
	   TList * ListProperties;
	   TkasObjectInfoProperties * ObjectInfoProperties;//конкретное свойство
	   TList * ListObject; //список подчиненных объектов


	   UnicodeString NameObject;
	   UnicodeString TypeObject;
};



#endif
