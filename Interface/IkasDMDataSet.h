#ifndef IkasDMDataSetH
#define IkasDMDataSetH



#include <DB.hpp>


class __declspec(uuid("{EE4CCD73-545C-49FF-825D-A46FCCA1852A}")) IkasDMDataSet
{
public:
	virtual TDataSource * kanGetDataSource(int index_data_source)=0;
};
#define IID_IkasDMDataSet __uuidof(IkasDMDataSet)







#endif
