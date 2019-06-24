//---------------------------------------------------------------------------

#pragma hdrstop

#include "UkanSetupWebGrids.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//-------------------------------------------------------------------
TkanSetupWebGrids::TkanSetupWebGrids()
{

}

//-----------------------------------------------------------------------------
TkanSetupWebGrids::~TkanSetupWebGrids()
{


}
//----------------------------------------------------------------------------
void TkanSetupWebGrids::LoadSetupGrids(TTIWDBAdvWebGrid * grid)
{
UnicodeString program_catalog=ExtractFileDir(Application->ExeName);
UnicodeString file_name=program_catalog+"\\DBGridSetup.ini";

if (FileExists(file_name)==true)
	{
	TkanIniFile * ini=new TkanIniFile(file_name);
	//grid->ActiveRow=ini->ReadIntegerValue("TTIWDBAdvWebGrid","ConnectString",0);




	delete ini;
	}
else
	{
	SetDefaultSetupGrids(grid);
	}





}
//-----------------------------------------------------------------------------
void TkanSetupWebGrids::SetDefaultSetupGrids(TTIWDBAdvWebGrid * grid)
{
grid->ActiveRowColor=clHighlight;
grid->ActiveRowFontColor=clHighlightText;

grid->ColumnSizing=true;


grid->Controller->Color=clActiveCaption;
grid->Controller->Gradient1=clActiveCaption;
grid->Controller->Gradient2=clInactiveCaption;
//grid->Controller->GradientDirection=gdVertical;
grid->Controller->IndicatorType=itRecordFromTo;

grid->Controller->Pager=cpPrevNextFirstLast;
grid->Controller->PagerType=cptButton;
grid->Controller->Position=cpBoth;


grid->Controller->TextFirst="Начало";
grid->Controller->TextLast="Конец";
grid->Controller->TextNext="Вперед";
grid->Controller->TextPrev="Назад";


grid->DefaultRowHeight=15;
grid->EditColor=clNone;

grid->Font->FontName="Tahoma";



grid->MouseSelect=msMove;

grid->RowCount=18;

grid->SelectColor=clHighlight;
grid->SelectFontColor=clHighlightText;



}
//-----------------------------------------------------------------------------


