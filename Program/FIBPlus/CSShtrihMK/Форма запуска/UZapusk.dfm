object FZapusk: TFZapusk
  Left = 362
  Top = 197
  Width = 363
  Height = 277
  Caption = #1047#1072#1087#1091#1089#1082' '#1087#1088#1086#1075#1088#1072#1084#1084#1099':'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 144
    Width = 171
    Height = 16
    Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100': CSShtrihMK'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object LabelFileName: TLabel
    Left = 8
    Top = 224
    Width = 60
    Height = 13
    Caption = #1055#1091#1090#1100' '#1082' '#1073#1072#1079#1077
  end
  object Label3: TLabel
    Left = 8
    Top = 168
    Width = 118
    Height = 16
    Caption = #1057#1077#1090#1077#1074#1086#1081' '#1085#1086#1084#1077#1088':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ButtonOK: TButton
    Left = 264
    Top = 160
    Width = 75
    Height = 25
    Caption = #1054#1050
    TabOrder = 0
    OnClick = ButtonOKClick
  end
  object ButtonAdd: TButton
    Left = 264
    Top = 16
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 1
    OnClick = ButtonAddClick
  end
  object ButtonDel: TButton
    Left = 264
    Top = 80
    Width = 75
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 2
    OnClick = ButtonDelClick
  end
  object ButtonCancel: TButton
    Left = 264
    Top = 192
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 3
    OnClick = ButtonCancelClick
  end
  object ButtonRename: TButton
    Left = 264
    Top = 48
    Width = 75
    Height = 25
    Caption = #1048#1079#1084#1077#1085#1080#1090#1100
    TabOrder = 4
    OnClick = ButtonRenameClick
  end
  object ListBox1: TListBox
    Left = 8
    Top = 8
    Width = 241
    Height = 121
    ItemHeight = 13
    TabOrder = 5
    OnClick = ListBox1Click
  end
  object SetNumber: TEdit
    Left = 144
    Top = 168
    Width = 57
    Height = 21
    TabOrder = 6
    Text = '0'
  end
  object UpDown1: TUpDown
    Left = 201
    Top = 168
    Width = 16
    Height = 21
    Associate = SetNumber
    Min = 0
    Position = 0
    TabOrder = 7
    Wrap = False
  end
end
