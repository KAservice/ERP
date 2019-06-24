object FChanche: TFChanche
  Left = 209
  Top = 428
  Width = 449
  Height = 146
  Caption = #1048#1079#1084#1077#1085#1080#1090#1100
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 24
    Width = 79
    Height = 13
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 40
    Top = 56
    Width = 27
    Height = 13
    Caption = #1055#1091#1090#1100':'
  end
  object NameBase: TEdit
    Left = 96
    Top = 24
    Width = 217
    Height = 21
    TabOrder = 0
    Text = 'NameBase'
  end
  object FileName: TEdit
    Left = 96
    Top = 56
    Width = 217
    Height = 21
    TabOrder = 1
    Text = 'FileName'
  end
  object ButtonOK: TButton
    Left = 360
    Top = 24
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = ButtonOKClick
  end
  object ButtonCancel: TButton
    Left = 360
    Top = 56
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 3
    OnClick = ButtonCancelClick
  end
end
