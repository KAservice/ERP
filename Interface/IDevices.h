#ifndef UIDevicesH
#define UIDevicesH


#include "GlobalInterface.h"


class __declspec(uuid("{6A408DD8-2F98-4885-B266-0F22D9096766}")) IDevices : public IkanUnknown
	{
public:


	//IHardware
	virtual int  GetDeviceObject(int type_interface_device, void** ppv)=0;
	};

#define IID_IDevices __uuidof(IDevices)

#endif
