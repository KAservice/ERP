//---------------------------------------------------------------------------

#ifndef UPrintAnyLabelH
#define UPrintAnyLabelH
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TPrintAnyLabel
{
private:

public:
		TPrintAnyLabel();
		~TPrintAnyLabel();

		__int64 IdNom;
		__int64 IdEd;
		__int64 IdOborud;
		__int64 IdFirm;
		double Price;
		int KolLabel;
		AnsiString TypeLabel;

		void PrintLabel(void);

		void PrintLabel58x30_1(void);

};
//-------------------------------------------------------------------------
#endif
