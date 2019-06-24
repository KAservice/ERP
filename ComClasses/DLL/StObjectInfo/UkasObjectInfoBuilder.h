//---------------------------------------------------------------------------

#ifndef UkasObjectInfoBuilderH
#define UkasObjectInfoBuilderH
//---------------------------------------------------------------------------
#include "UkasObjectInfo.h"
#include <ActnList.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------





class TkasObjectInfoBuilder
//построитель классов информации об объектах
{
private:


        TStringList * List;

public:
		TkasObjectInfoBuilder();
		~TkasObjectInfoBuilder();


		TkasObjectInfo * GetObjectInfo(UnicodeString name_object);
		bool Error;
		UnicodeString TextError;

		TkasObjectInfo * GetInfo(TkasObjectInfo * ob_roditel);
		int NumberString;

		UnicodeString GetValueStringParameter(void);
};

//---------------------------------------------------------------------------
#endif
