//---------------------------------------------------------------------------

#ifndef USheetEditorCFH
#define USheetEditorCFH
//---------------------------------------------------------------------------
#include "GlobalInterface.h"
//---------------------------------------------------------------------------
class TSheetEditorCF : public IkanClassFactory
{
public:
   TSheetEditorCF();
   ~TSheetEditorCF();

   int NumRefs;


	virtual int kanQueryInterface(REFIID id_interface, void ** ppv);
	virtual int kanAddRef(void);
	virtual int kanRelease(void);
   	virtual int kanCreateInstance(REFIID id_interface, void ** ppv);
};


#endif
