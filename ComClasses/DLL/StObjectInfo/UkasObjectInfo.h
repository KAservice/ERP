//---------------------------------------------------------------------------

#ifndef UkasObjectInfoH
#define UkasObjectInfoH

#include "UkasObjectInfoProperties.h"
//---------------------------------------------------------------------------
class TkasObjectInfo
//���������� ������
{
private:




public:
		TkasObjectInfo();
		~TkasObjectInfo();


	   //������ �������
	   TList * ListProperties;
	   TkasObjectInfoProperties * ObjectInfoProperties;//���������� ��������
	   TList * ListObject; //������ ����������� ��������


	   UnicodeString NameObject;
	   UnicodeString TypeObject;
};



#endif
