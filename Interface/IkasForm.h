#ifndef IkasFormInterfaceH
#define IkasFormInterfaceH

#include <guiddef.h>
#include <IMainInterface.h>




class __declspec(uuid("{2B49266B-D51A-4E2C-A784-F9B7A3773D9D}")) IkasForm : public IMainInterface
{
public:
	virtual void UpdateForm(void)=0;
	__property bool Vibor = {read = get_Vibor , write = set_Vibor};   virtual bool get_Vibor(void)=0;   virtual void set_Vibor(bool Vibor)=0;  //форма открыта для выбора
	__property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};   virtual int get_NumberProcVibor(void)=0;   virtual void set_NumberProcVibor(int NumberProcVibor)=0;  //какую процедуру использовать для обработки выбора во внешней форме


};
#define IID_IkasForm __uuidof(IkasForm)







#endif
