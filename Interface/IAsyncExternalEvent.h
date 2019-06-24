#ifndef UIAsyncExternalEventH
#define UIAsyncExternalEventH


#include "GlobalInterface.h"


class __declspec(uuid("{64471BA2-B4C7-45A4-8501-C3AD95D89A76}")) IAsyncExternalEvent : public IkanUnknown
	{
public:
	//���������� ����������� ������� �������� �����
    virtual int SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form)=0;
	virtual int AsyncExternalEvent(char * object, char* event, char* data)=0;
	//��� ������� ������������ � �����, ������� ��������� �� ������� �������
	};

#define IID_IAsyncExternalEvent __uuidof(IAsyncExternalEvent)

#endif
