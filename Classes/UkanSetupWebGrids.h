//---------------------------------------------------------------------------

#ifndef UkanSetupWebGridsH
#define UkanSetupWebGridsH
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <IWAppForm.hpp>
#include "IWBaseControl.hpp"
#include "IWBaseHTMLControl.hpp"
#include "IWControl.hpp"
#include "IWTreeview.hpp"
#include "IWVCLBaseControl.hpp"
#include "IWCompLabel.hpp"
#include "IWCompButton.hpp"
#include "IWDBAdvWebGrid.hpp"
#include "IWWebGrid.hpp"
#include "IWContainer.hpp"
#include "IWHTML40Container.hpp"
#include "IWHTMLContainer.hpp"
#include "IWRegion.hpp"
#include "IWVCLBaseContainer.hpp"
#include "UkanIniFile.h"

//-----------------------------------------------------------------------------
class TkanSetupWebGrids
{
private:

public:
		TkanSetupWebGrids();
		~TkanSetupWebGrids();

		void LoadSetupGrids(TTIWDBAdvWebGrid * grid);
		void SetDefaultSetupGrids(TTIWDBAdvWebGrid * grid);
};
#endif
