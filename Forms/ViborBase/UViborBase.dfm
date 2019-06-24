object ViborBase: TViborBase
  Left = 473
  Top = 181
  Width = 365
  Height = 275
  BorderIcons = []
  Caption = #1047#1072#1087#1091#1089#1082' '#1087#1088#1086#1075#1088#1072#1084#1084#1099':'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 136
    Width = 98
    Height = 16
    Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 176
    Width = 52
    Height = 16
    Caption = #1055#1072#1088#1086#1083#1100':'
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
    Width = 89
    Height = 16
    Caption = #1055#1091#1090#1100' '#1082' '#1073#1072#1079#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ButtonOK: TButton
    Left = 264
    Top = 152
    Width = 75
    Height = 25
    Caption = #1054#1050
    TabOrder = 0
    OnClick = ButtonOKClick
  end
  object ButtonAdd: TButton
    Left = 264
    Top = 24
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 1
    OnClick = ButtonAddClick
  end
  object ButtonDel: TButton
    Left = 264
    Top = 88
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
  object Password: TEdit
    Left = 8
    Top = 192
    Width = 241
    Height = 21
    PasswordChar = '*'
    TabOrder = 4
    OnKeyPress = PasswordKeyPress
  end
  object ButtonRename: TButton
    Left = 264
    Top = 56
    Width = 75
    Height = 25
    Caption = #1048#1079#1084#1077#1085#1080#1090#1100
    TabOrder = 5
    OnClick = ButtonRenameClick
  end
  object ListBox1: TListBox
    Left = 8
    Top = 8
    Width = 241
    Height = 121
    ItemHeight = 13
    TabOrder = 6
    OnClick = ListBox1Click
  end
  object User: TEdit
    Left = 8
    Top = 152
    Width = 241
    Height = 21
    TabOrder = 7
    OnKeyPress = UserKeyPress
  end
end
