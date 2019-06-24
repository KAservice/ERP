#ifndef UIMainInterfaceH
#define UIMainInterfaceH

#include <vcl.h>
#include <GlobalInterface.h>

class __declspec(uuid("{DD5AF383-B21F-49C3-B5B0-3428104D23D7}")) IMainInterface : public IkanUnknown
	{
public:


	//IMainInterface

	virtual int  get_CodeError(void)=0;
	virtual void set_CodeError(int CodeError)=0;

	virtual UnicodeString  get_TextError(void)=0;
	virtual void set_TextError(UnicodeString  TextError)=0;

	__property int CodeError = {read = get_CodeError,
												 write = set_CodeError};
	__property UnicodeString  TextError = {read = get_TextError,
												 write = set_TextError};

	virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)=0;
	virtual int Done(void)=0;

	};

#define IID_IMainInterface __uuidof(IMainInterface)




#endif
