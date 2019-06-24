#ifndef IkasDataModuleH
#define IkasDataModuleH

#include <guiddef.h>
#include <MainInterface.h>




class __declspec(uuid("{634D80EA-B900-4ADD-AC06-F5AD24C74D45}")) IkasDataModule : public IMainInterface
{
public:
//	virtual int kanGetClassObject(REFIID id_class, REFIID id_interface, void ** ppv)=0;
//	virtual int kanProgIDFromCLSID(GUID guid, char *  prog_id )=0;
//	virtual int kanCLSIDFromProgID(char * prog_id, GUID * guid)=0;
//	virtual int kanAddClass(REFIID id_class, char * prog_id, char * file_name_modul)=0;
//	virtual int kanRemoveClass(REFIID id_class)=0;
//	virtual int kanRegisterClassInModule(char * file_name_modul)=0;
//	virtual int kanUnregisterClassInModule(char * file_name_modul)=0;
//	virtual int kanCreateObject(char * prog_id, REFIID id_interface, void**ppv)=0;
};
#define IID_IkasDataModule __uuidof(IkasDataModule)







#endif
