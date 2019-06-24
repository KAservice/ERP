object FormaReportDiscountDocCheck: TFormaReportDiscountDocCheck
  Left = 308
  Top = 124
  Caption = #1054#1090#1095#1077#1090' '#1086' '#1089#1082#1080#1076#1082#1072#1093':'
  ClientHeight = 401
  ClientWidth = 432
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 8
    Width = 170
    Height = 26
    Caption = #1054#1090#1095#1077#1090' '#1086' '#1089#1082#1080#1076#1082#1072#1093' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 30
    Top = 50
    Width = 12
    Height = 26
    Caption = 'c'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 224
    Top = 48
    Width = 24
    Height = 26
    Caption = #1087#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 32
    Top = 144
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label6: TLabel
    Left = 30
    Top = 121
    Width = 40
    Height = 13
    Caption = #1060#1080#1088#1084#1072':'
  end
  object Label7: TLabel
    Left = 32
    Top = 168
    Width = 38
    Height = 13
    Caption = #1043#1088#1091#1087#1087#1072' '
  end
  object Label8: TLabel
    Left = 16
    Top = 184
    Width = 77
    Height = 13
    Caption = #1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
  end
  object Label9: TLabel
    Left = 16
    Top = 208
    Width = 77
    Height = 13
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object Label5: TLabel
    Left = 7
    Top = -1
    Width = 403
    Height = 13
    Caption = 
      #1054#1090#1095#1077#1090' '#1089#1090#1088#1086#1080#1090#1089#1103' '#1087#1086' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1084' "'#1063#1077#1082' '#1050#1050#1052'" '#1059#1095#1080#1090#1099#1074#1072#1102#1090#1089#1103' '#1090#1086#1083#1100#1082#1086' '#1095#1077#1082#1080' '#1087 +
      #1088#1086#1076#1072#1078#1080'.'
  end
  object cxButtonCreate: TcxButton
    Left = 239
    Top = 288
    Width = 99
    Height = 25
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = cxButtonCreateClick
  end
  object cxButtonClose: TcxButton
    Left = 344
    Top = 364
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 1
  end
  object DocCheckBox: TcxCheckBox
    Left = 92
    Top = 283
    Caption = #1089' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1084#1080
    TabOrder = 2
    Width = 121
  end
  object OnlyCheckBox: TcxCheckBox
    Left = 92
    Top = 240
    Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100
    TabOrder = 3
    Width = 121
  end
  object TypeNomComboBox: TcxComboBox
    Left = 228
    Top = 240
    Properties.DropDownListStyle = lsFixedList
    Properties.Items.Strings = (
      #1058#1086#1083#1100#1082#1086' '#1090#1086#1074#1072#1088#1099' (0)'
      #1058#1086#1083#1100#1082#1086' '#1091#1089#1083#1091#1075#1080' (1)'
      #1058#1086#1083#1100#1082#1086' '#1087#1088#1086#1076#1091#1082#1094#1080#1103' (2)')
    TabOrder = 4
    Width = 185
  end
  object NameNomEdit: TcxButtonEdit
    Left = 93
    Top = 203
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameNomEditPropertiesButtonClick
    TabOrder = 5
    Text = 'NameNomEdit'
    Width = 321
  end
  object NameGrpNomEdit: TcxButtonEdit
    Left = 92
    Top = 176
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameGrpNomEditPropertiesButtonClick
    TabOrder = 6
    Text = 'NameGrpNomEdit'
    Width = 321
  end
  object NameSkladEdit: TcxButtonEdit
    Left = 92
    Top = 145
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.OnButtonClick = NameSkladEditPropertiesButtonClick
    TabOrder = 7
    Text = 'NameSkladEdit'
    Width = 321
  end
  object NameFirmEdit: TcxButtonEdit
    Left = 92
    Top = 118
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameFirmEditPropertiesButtonClick
    TabOrder = 8
    Text = 'NameFirmEdit'
    Width = 321
  end
  object DateNach: TcxDateEdit
    Left = 48
    Top = 57
    Properties.Kind = ckDateTime
    TabOrder = 9
    Width = 165
  end
  object DateCon: TcxDateEdit
    Left = 259
    Top = 57
    Properties.Kind = ckDateTime
    TabOrder = 10
    Width = 154
  end
  object NameKlientcxButtonEdit: TcxButtonEdit
    Left = 96
    Top = 328
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.OnButtonClick = NameKlientcxButtonEditPropertiesButtonClick
    TabOrder = 11
    Text = 'NameKlientcxButtonEdit'
    Width = 317
  end
  object cxLabel1: TcxLabel
    Left = 8
    Top = 329
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
  end
  object cxButtonCreateReportGrid: TcxButton
    Left = 239
    Top = 364
    Width = 99
    Height = 25
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 13
    OnClick = cxButtonCreateReportGridClick
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 232
    Top = 8
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
  end
end
