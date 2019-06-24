object FormaRunFastScript: TFormaRunFastScript
  Left = 0
  Top = 0
  Caption = #1042#1099#1087#1086#1083#1085#1077#1085#1080#1077' '#1089#1082#1088#1080#1087#1090#1072'...'
  ClientHeight = 87
  ClientWidth = 234
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object FileNameScriptLabel: TLabel
    Left = 16
    Top = 32
    Width = 95
    Height = 13
    Caption = 'FileNameScriptLabel'
  end
  object fsScript1: TfsScript
    SyntaxType = 'C++Script'
    Left = 192
    Top = 16
  end
  object fsCPP1: TfsCPP
    Left = 96
  end
  object fsPascal1: TfsPascal
  end
  object fsJScript1: TfsJScript
    Left = 32
  end
  object fsBasic1: TfsBasic
    Left = 64
  end
  object fsFormsRTTI1: TfsFormsRTTI
    Left = 104
    Top = 56
  end
  object fsClassesRTTI1: TfsClassesRTTI
    Left = 136
    Top = 56
  end
end
