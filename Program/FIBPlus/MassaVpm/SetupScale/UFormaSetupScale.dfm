object FormSetupScale: TFormSetupScale
  Left = 0
  Top = 0
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1074#1077#1089#1086#1074
  ClientHeight = 265
  ClientWidth = 490
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
  object Label1: TLabel
    Left = 85
    Top = 164
    Width = 85
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1101#1090#1080#1082#1077#1090#1082#1080':'
  end
  object Label2: TLabel
    Left = 267
    Top = 164
    Width = 95
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1096#1090#1088#1080#1093#1082#1086#1076#1072':'
  end
  object Label3: TLabel
    Left = 41
    Top = 72
    Width = 47
    Height = 13
    Caption = 'IP '#1072#1076#1088#1077#1089':'
  end
  object Label4: TLabel
    Left = 254
    Top = 94
    Width = 108
    Height = 13
    Caption = #1055#1088#1077#1092#1080#1082#1089' '#1096#1090#1088#1080#1093#1082#1086#1076#1072':'
  end
  object Label5: TLabel
    Left = 333
    Top = 67
    Width = 29
    Height = 13
    Caption = #1055#1086#1088#1090':'
  end
  object Label6: TLabel
    Left = 230
    Top = 121
    Width = 132
    Height = 13
    Caption = #1050#1086#1076' '#1079#1085#1072#1082#1072' '#1089#1077#1088#1090#1080#1092#1080#1082#1072#1094#1080#1080':'
  end
  object Label11: TLabel
    Left = 43
    Top = 3
    Width = 415
    Height = 23
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1074#1077#1089#1086#1074#1086#1075#1086' '#1082#1086#1084#1087#1083#1077#1082#1089#1072' '#1042#1055#1052' ('#1052#1072#1089#1089#1072'-'#1050')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelNameScale: TLabel
    Left = 162
    Top = 25
    Width = 137
    Height = 23
    Alignment = taCenter
    Caption = 'LabelNameScale'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label12: TLabel
    Left = 284
    Top = 191
    Width = 78
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1096#1088#1080#1092#1090#1072':'
  end
  object NumberLabelComboBox: TComboBox
    Left = 176
    Top = 161
    Width = 50
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9')
  end
  object CodeSertMaskEdit: TMaskEdit
    Left = 375
    Top = 118
    Width = 58
    Height = 21
    TabOrder = 1
    Text = 'CodeSertMaskEdit'
  end
  object ButtonSave: TButton
    Left = 263
    Top = 228
    Width = 75
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 2
    OnClick = ButtonSaveClick
  end
  object ButtonClose: TButton
    Left = 375
    Top = 228
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 3
    OnClick = ButtonCloseClick
  end
  object cxLabel1: TcxLabel
    Left = 41
    Top = 189
    Caption = #1053#1086#1084#1077#1088' '#1086#1089#1085#1086#1074#1085#1086#1081' '#1075#1088#1091#1087#1087#1099':'
  end
  object IPEdit: TEdit
    Left = 94
    Top = 64
    Width = 121
    Height = 21
    TabOrder = 5
    Text = 'IPEdit'
  end
  object PortEdit: TEdit
    Left = 375
    Top = 64
    Width = 57
    Height = 21
    TabOrder = 6
    Text = 'PortEdit'
  end
  object NumberBarCodeComboBox: TComboBox
    Left = 375
    Top = 161
    Width = 57
    Height = 21
    ItemHeight = 13
    TabOrder = 7
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9')
  end
  object PrefiksBarCodeEdit: TEdit
    Left = 375
    Top = 91
    Width = 58
    Height = 21
    TabOrder = 8
    Text = 'PrefiksBarCodeEdit'
  end
  object NumberOsnGrpComboBox: TComboBox
    Left = 176
    Top = 188
    Width = 50
    Height = 21
    ItemHeight = 13
    TabOrder = 9
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9')
  end
  object NumberFontComboBox: TComboBox
    Left = 375
    Top = 188
    Width = 57
    Height = 21
    ItemHeight = 13
    TabOrder = 10
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9')
  end
end
