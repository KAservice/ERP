//---------------------------------------------------------------------------

#ifndef UMyPainterH
#define UMyPainterH
//---------------------------------------------------------------------------
class TMyPainter : TcxSheetPainter {
private:
void __fastcall GradientRect(const TRect &ARect, bool IsHorizontal, bool IsSelected);
protected:
virtual void __fastcall DrawHeaderBrick(int I, int J);
};

#endif
