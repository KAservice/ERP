#ifndef UIConnectionInterfaceH
#define UIConnectionInterfaceH


#include "IDMFibConnection.h"

class __declspec(uuid("{08F4E751-4204-469D-872E-7AA303710DAA}")) IConnectionInterface : public IkanUnknown
	{
public:

	virtual IDMFibConnection * GetFibConnection(void)=0;

	};

#define IID_IConnectionInterface __uuidof(IConnectionInterface)




#endif
