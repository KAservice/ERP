object FormaSetupKlient: TFormaSetupKlient
  Left = 619
  Top = 119
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
  ClientHeight = 478
  ClientWidth = 417
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
  object Label1: TLabel
    Left = 10
    Top = 30
    Width = 57
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'IP '#1072#1076#1088#1077#1089':'
  end
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
    Top = 202
    Width = 184
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1090#1088#1086#1082#1072' '#1079#1072#1087#1091#1089#1082#1072' '#1072#1088#1093#1080#1074#1072#1090#1086#1088#1072
  end
  object Label8: TLabel
    Left = 10
    Top = 256
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
    Top = 145
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
    Top = 178
    Width = 130
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'ID '#1073#1072#1079#1099' '#1076#1083#1103' '#1086#1073#1084#1077#1085#1072':'
  end
  object Label10: TLabel
    Left = 148
    Top = 363
    Width = 162
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1085#1090#1077#1088#1074#1072#1083'  '#1086#1073#1084#1077#1085#1072' ('#1084#1080#1085'.):'
  end
  object Label11: TLabel
    Left = 57
    Top = 396
    Width = 255
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1085#1090#1077#1088#1074#1072#1083'  '#1086#1073#1084#1077#1085#1072' '#1087#1086#1089#1083#1077' '#1086#1096#1080#1073#1082#1080' ('#1084#1080#1085'.):'
  end
  object IPAdressEdit: TEdit
    Left = 69
    Top = 20
    Width = 188
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 0
    Text = 'IPAdressEdit'
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
    TabOrder = 1
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
    TabOrder = 2
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
    TabOrder = 3
    Text = 'PasswordUserEdit'
  end
  object ConnectStringEdit: TEdit
    Left = 10
    Top = 108
    Width = 395
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 4
    Text = 'ConnectStringEdit'
  end
  object PatchArhEdit: TEdit
    Left = 11
    Top = 223
    Width = 366
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 5
    Text = 'PatchArhEdit'
  end
  object ButtonViborFileArh: TButton
    Left = 379
    Top = 223
    Width = 26
    Height = 26
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '...'
    TabOrder = 6
    OnClick = ButtonViborFileArhClick
  end
  object ButtonSave: TButton
    Left = 196
    Top = 437
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1047#1072#1087#1080#1089#1072#1090#1100
    TabOrder = 7
    OnClick = ButtonSaveClick
  end
  object ButtonClose: TButton
    Left = 313
    Top = 437
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 8
    OnClick = ButtonCloseClick
  end
  object PatchUnArhEdit: TEdit
    Left = 11
    Top = 279
    Width = 366
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 9
    Text = 'PatchUnArhEdit'
  end
  object Button1: TButton
    Left = 379
    Top = 279
    Width = 26
    Height = 26
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '...'
    TabOrder = 10
    OnClick = Button1Click
  end
  object ViklPCCheckBox: TCheckBox
    Left = 10
    Top = 313
    Width = 306
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1074#1099#1082#1083#1102#1095#1080#1090#1100' '#1082#1086#1084#1087#1100#1102#1090#1077#1088' '#1087#1086#1089#1083#1077' '#1079#1072#1074#1077#1088#1096#1077#1085#1080#1103
    TabOrder = 11
  end
  object IdBaseForObmenEdit: TEdit
    Left = 236
    Top = 175
    Width = 169
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 12
    Text = 'IdBaseForObmenEdit'
  end
  object NameBaseForObmenEdit: TEdit
    Left = 236
    Top = 142
    Width = 169
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 13
    Text = 'NameBaseForObmenEdit'
  end
  object AutoObmenCheckBox: TCheckBox
    Left = 10
    Top = 336
    Width = 385
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1072#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080#1081' '#1086#1073#1084#1077#1085' '#1095#1077#1088#1077#1079' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1085#1099#1081' '#1080#1085#1090#1077#1088#1074#1072#1083
    TabOrder = 14
  end
  object IntervalEdit: TEdit
    Left = 313
    Top = 359
    Width = 92
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 15
    Text = 'IntervalEdit'
  end
  object IntervalObmenaAfterErrorEdit: TEdit
    Left = 313
    Top = 393
    Width = 92
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 16
    Text = 'IntervalObmenaAfterErrorEdit'
  end
  object OpenDialog1: TOpenDialog
    Left = 8
    Top = 304
  end
end
