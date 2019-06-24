#ifndef UIMainCOMInterfaceH
#define UIMainCOMInterfaceH


#include <GlobalInterface.h>

class __declspec(uuid("{61383B61-62D0-48B8-B458-5054C4749AD9}")) IMainCOMInterface : public IkanUnknown
	{
public:

	virtual IkanCom * GetCOM(void)=0;

	};

#define IID_IMainCOMInterface __uuidof(IMainCOMInterface)




#endif
