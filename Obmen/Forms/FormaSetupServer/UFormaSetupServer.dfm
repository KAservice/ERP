object FormaSetupServer: TFormaSetupServer
  Left = 619
  Top = 119
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1089#1077#1088#1074#1077#1088#1072
  ClientHeight = 418
  ClientWidth = 433
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Label2: TLabel
    Left = 286
    Top = 30
    Width = 36
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1086#1088#1090':'
  end
  object Label3: TLabel
    Left = 10
    Top = 59
    Width = 125
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1084#1103' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103':'
  end
  object Label4: TLabel
    Left = 276
    Top = 69
    Width = 52
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1072#1088#1086#1083#1100':'
  end
  object Label6: TLabel
    Left = 20
    Top = 89
    Width = 141
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1090#1088#1086#1082#1072' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1080#1103':'
  end
  object Label7: TLabel
    Left = 20
    Top = 236
    Width = 184
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1090#1088#1086#1082#1072' '#1079#1072#1087#1091#1089#1082#1072' '#1072#1088#1093#1080#1074#1072#1090#1086#1088#1072
  end
  object Label8: TLabel
    Left = 20
    Top = 286
    Width = 204
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1090#1088#1086#1082#1072' '#1079#1072#1087#1091#1089#1082#1072' '#1088#1072#1089#1087#1072#1082#1086#1074#1097#1080#1082#1072':'
  end
  object Label5: TLabel
    Left = 10
    Top = 161
    Width = 164
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1073#1072#1079#1099' '#1076#1083#1103' '#1086#1073#1084#1077#1085#1072':'
    WordWrap = True
  end
  object Label9: TLabel
    Left = 49
    Top = 194
    Width = 130
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'ID '#1073#1072#1079#1099' '#1076#1083#1103' '#1086#1073#1084#1077#1085#1072':'
  end
  object PortEdit: TEdit
    Left = 335
    Top = 20
    Width = 70
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 0
    Text = 'PortEdit'
  end
  object NameUserEdit: TEdit
    Left = 138
    Top = 59
    Width = 119
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 1
    Text = 'NameUserEdit'
  end
  object PasswordUserEdit: TEdit
    Left = 335
    Top = 59
    Width = 70
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 2
    Text = 'PasswordUserEdit'
  end
  object ConnectStringEdit: TEdit
    Left = 20
    Top = 108
    Width = 385
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 3
    Text = 'ConnectStringEdit'
  end
  object PatchArhEdit: TEdit
    Left = 20
    Top = 256
    Width = 365
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 4
    Text = 'PatchArhEdit'
  end
  object ButtonViborFileArh: TButton
    Left = 384
    Top = 256
    Width = 26
    Height = 26
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '...'
    TabOrder = 5
    OnClick = ButtonViborFileArhClick
  end
  object ButtonSave: TButton
    Left = 187
    Top = 374
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1047#1072#1087#1080#1089#1072#1090#1100
    TabOrder = 6
    OnClick = ButtonSaveClick
  end
  object ButtonClose: TButton
    Left = 295
    Top = 374
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 7
    OnClick = ButtonCloseClick
  end
  object PatchUnArhEdit: TEdit
    Left = 20
    Top = 305
    Width = 365
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 8
    Text = 'PatchUnArhEdit'
  end
  object Button1: TButton
    Left = 384
    Top = 305
    Width = 26
    Height = 26
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '...'
    TabOrder = 9
    OnClick = Button1Click
  end
  object IdBaseForObmenEdit: TEdit
    Left = 236
    Top = 191
    Width = 169
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 10
    Text = 'IdBaseForObmenEdit'
  end
  object NameBaseForObmenEdit: TEdit
    Left = 236
    Top = 158
    Width = 169
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 11
    Text = 'NameBaseForObmenEdit'
  end
  object OpenDialog1: TOpenDialog
    Left = 8
    Top = 304
  end
end
