object FormaSetup: TFormaSetup
  Left = 619
  Top = 119
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
  ClientHeight = 340
  ClientWidth = 352
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 24
    Width = 46
    Height = 13
    Caption = 'IP '#1072#1076#1088#1077#1089':'
  end
  object Label2: TLabel
    Left = 232
    Top = 24
    Width = 28
    Height = 13
    Caption = #1055#1086#1088#1090':'
  end
  object Label3: TLabel
    Left = 8
    Top = 48
    Width = 99
    Height = 13
    Caption = #1048#1084#1103' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103':'
  end
  object Label4: TLabel
    Left = 224
    Top = 56
    Width = 41
    Height = 13
    Caption = #1055#1072#1088#1086#1083#1100':'
  end
  object Label5: TLabel
    Left = 56
    Top = 123
    Width = 196
    Height = 13
    Caption = #1055#1088#1077#1092#1080#1082#1089' '#1091#1076#1072#1083#1077#1085#1085#1086#1081' '#1073#1072#1079#1099' '#1076#1083#1103' '#1086#1073#1084#1077#1085#1072':'
  end
  object Label6: TLabel
    Left = 16
    Top = 72
    Width = 109
    Height = 13
    Caption = #1057#1090#1088#1086#1082#1072' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1080#1103':'
  end
  object Label7: TLabel
    Left = 16
    Top = 192
    Width = 141
    Height = 13
    Caption = #1057#1090#1088#1086#1082#1072' '#1079#1072#1087#1091#1089#1082#1072' '#1072#1088#1093#1080#1074#1072#1090#1086#1088#1072
  end
  object Label8: TLabel
    Left = 16
    Top = 232
    Width = 161
    Height = 13
    Caption = #1057#1090#1088#1086#1082#1072' '#1079#1072#1087#1091#1089#1082#1072' '#1088#1072#1089#1087#1072#1082#1086#1074#1097#1080#1082#1072':'
  end
  object Label9: TLabel
    Left = 16
    Top = 152
    Width = 85
    Height = 13
    Caption = #1050#1072#1090#1072#1083#1086#1075' '#1086#1073#1084#1077#1085#1072':'
  end
  object IPAdressEdit: TEdit
    Left = 56
    Top = 16
    Width = 153
    Height = 21
    TabOrder = 0
    Text = 'IPAdressEdit'
  end
  object PortEdit: TEdit
    Left = 272
    Top = 16
    Width = 57
    Height = 21
    TabOrder = 1
    Text = 'PortEdit'
  end
  object NameUserEdit: TEdit
    Left = 112
    Top = 48
    Width = 97
    Height = 21
    TabOrder = 2
    Text = 'NameUserEdit'
  end
  object PasswordUserEdit: TEdit
    Left = 272
    Top = 48
    Width = 57
    Height = 21
    TabOrder = 3
    Text = 'PasswordUserEdit'
  end
  object PrefiksEdit: TEdit
    Left = 272
    Top = 120
    Width = 57
    Height = 21
    TabOrder = 4
    Text = 'PrefiksEdit'
  end
  object ConnectStringEdit: TEdit
    Left = 16
    Top = 88
    Width = 313
    Height = 21
    TabOrder = 5
    Text = 'ConnectStringEdit'
  end
  object PatchArhEdit: TEdit
    Left = 16
    Top = 208
    Width = 297
    Height = 21
    TabOrder = 6
    Text = 'PatchArhEdit'
  end
  object ButtonViborFileArh: TButton
    Left = 312
    Top = 208
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 7
    OnClick = ButtonViborFileArhClick
  end
  object ButtonSave: TButton
    Left = 152
    Top = 304
    Width = 75
    Height = 25
    Caption = #1047#1072#1087#1080#1089#1072#1090#1100
    TabOrder = 8
    OnClick = ButtonSaveClick
  end
  object ButtonClose: TButton
    Left = 240
    Top = 304
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 9
    OnClick = ButtonCloseClick
  end
  object PatchUnArhEdit: TEdit
    Left = 16
    Top = 248
    Width = 297
    Height = 21
    TabOrder = 10
    Text = 'PatchUnArhEdit'
  end
  object Button1: TButton
    Left = 312
    Top = 248
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 11
    OnClick = Button1Click
  end
  object ViklPCCheckBox: TCheckBox
    Left = 16
    Top = 280
    Width = 249
    Height = 17
    Caption = #1074#1099#1082#1083#1102#1095#1080#1090#1100' '#1082#1086#1084#1087#1100#1102#1090#1077#1088' '#1087#1086#1089#1083#1077' '#1079#1072#1074#1077#1088#1096#1077#1085#1080#1103
    TabOrder = 12
  end
  object CatalogObmenaEdit: TEdit
    Left = 16
    Top = 168
    Width = 297
    Height = 21
    TabOrder = 13
    Text = 'CatalogObmenaEdit'
  end
  object ButtonViborCatalogObmena: TButton
    Left = 312
    Top = 168
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 14
    OnClick = ButtonViborCatalogObmenaClick
  end
  object OpenDialog1: TOpenDialog
    Left = 8
    Top = 304
  end
end
