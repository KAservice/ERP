//---------------------------------------------------------------------------


#pragma hdrstop

#include "UMyPainter.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

void __fastcall TMyPainter::DrawHeaderBrick(int I, int J) {
TRect ARect; TcxSSInfoBrick brick = ViewInfo.Bricks[I][J]; 
//get the brick region
ARect = brick.DisplayRect; 
if (I == 1 && J == 0) ARect.Left--;
if (J == 1 && I == 0) ARect.Top--;
if (I == 0 && J == 0)
//do not use gradient for the top left header panel brick
Canvas->FillRect(ARect, fsSolid, (TColor)Cxpainterwrapper::ColorToRGB(clBtnFace), (TColor)Cxpainterwrapper::ColorToRGB(clBtnFace));
else
GradientRect(ARect, J == 0, brick.IsSelected && !HideSelection); 
//draw the border for a brick
Canvas->FrameRect(ARect, (TColor)Canvas->GetNativeColor(NULL, clBtnShadow), brick.IsSelected && !HideSelection);
//draw a row or column id
if (I != 0 || J != 0) {
OffsetRect(&ARect, 0, 2); Canvas->ExDrawText(ARect, brick.TextSettings); } 
//prevent a brick from being changed by subsequent calls
//to drawing functions
Canvas->ExcludeClipRect(brick.DisplayRect); 
}
//---------------------------------------------------------------------------
void __fastcall TMyPainter::GradientRect(const TRect &ARect, 
bool IsHorizontal, bool IsSelected) {
int I, dR,dG, dB;
byte R, G, B, R1, G1, B1;
//rectangle filled previously
TRect PrevLine; 
//rectangle to fill currently
TRect LineRect; HBRUSH ABrush;
int index;
const TColor Colors[2][2] = 
{{clWhite, clBtnShadow}, {clHighlight, clWhite}}; 
if(IsSelected)
index = 1; 
else
index = 0; 
//get the Red, Green and Blue components of the starting color
//for the gradient
ColorToRGBValues(Colors[index][0], R1, G1, B1); 
//get the Red, Green and Blue components of the ending color
//for the gradient
ColorToRGBValues(Colors[index][1], R, G, B); dR = R - R1; dG = G - G1; dB = B - B1; LineRect = ARect; PrevLine = ARect; 
for(I = 0; I<=255; I++) {
//determine rectangle boundaries for horizontal filling
if(IsHorizontal) {
LineRect.Top = ARect.Top + MulDiv(I, ARect.Bottom - ARect.Top, 0x100); LineRect.Bottom = ARect.Top + MulDiv(I + 1, ARect.Bottom - ARect.Top, 0x100); }
//determine rectangle boundaries for vertical filling
else {
LineRect.Left = ARect.Left + MulDiv(I, ARect.Right - ARect.Left, 0x100); LineRect.Right = ARect.Left + MulDiv(I + 1, ARect.Right - ARect.Left, 0x100); }
//step over if the same rectangle was filled before
if (PrevLine == LineRect) continue;
//define colors to fill
R = R1 + MulDiv(I, dR, 0xFF); G = G1 + MulDiv(I, dG, 0xFF); B = B1 + MulDiv(I, dB, 0xFF);
//create a brush to fill
ABrush = CreateSolidBrush(RGB(R, G, B));
try {
FillRect(Canvas->Canvas->Handle, &LineRect, ABrush); }
__finally {
DeleteObject(ABrush); } }
}
//-----------------------------------------------------------------------------------