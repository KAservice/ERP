object FormaReportDiscountDocCheckForCashier: TFormaReportDiscountDocCheckForCashier
  Left = 308
  Top = 124
  Caption = #1054#1090#1095#1077#1090' '#1086' '#1089#1082#1080#1076#1082#1072#1093':'
  ClientHeight = 320
  ClientWidth = 527
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 30
    Top = 10
    Width = 216
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1090#1095#1077#1090' '#1086' '#1089#1082#1080#1076#1082#1072#1093' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 10
    Top = 39
    Width = 14
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'c'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 224
    Top = 41
    Width = 32
    Height = 32
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1087#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 39
    Top = 148
    Width = 50
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1043#1088#1091#1087#1087#1072' '
  end
  object Label8: TLabel
    Left = 20
    Top = 167
    Width = 99
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099':'
  end
  object Label9: TLabel
    Left = 20
    Top = 197
    Width = 100
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072':'
  end
  object LabelNameFirm: TLabel
    Left = 49
    Top = 84
    Width = 149
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'LabelNameFirm'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object LabelNameSklad: TLabel
    Left = 49
    Top = 116
    Width = 158
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'LabelNameSklad'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 9
    Top = -1
    Width = 507
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 
      #1054#1090#1095#1077#1090' '#1089#1090#1088#1086#1080#1090#1089#1103' '#1087#1086' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1084' "'#1063#1077#1082' '#1050#1050#1052'" '#1059#1095#1080#1090#1099#1074#1072#1102#1090#1089#1103' '#1090#1086#1083#1100#1082#1086' '#1095#1077#1082#1080' '#1087 +
      #1088#1086#1076#1072#1078#1080'.'
  end
  object cxButtonCreate: TcxButton
    Left = 286
    Top = 274
    Width = 123
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = cxButtonCreateClick
  end
  object cxButtonClose: TcxButton
    Left = 416
    Top = 274
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 1
  end
  object DocCheckBox: TcxCheckBox
    Left = 68
    Top = 274
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1089' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1084#1080
    TabOrder = 2
    Width = 149
  end
  object OnlyCheckBox: TcxCheckBox
    Left = 122
    Top = 224
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1087#1086#1082#1072#1079#1099#1074#1072#1090#1100
    TabOrder = 3
    Width = 123
  end
  object TypeNomComboBox: TcxComboBox
    Left = 271
    Top = 224
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.DropDownListStyle = lsFixedList
    Properties.Items.Strings = (
      #1058#1086#1083#1100#1082#1086' '#1090#1086#1074#1072#1088#1099' (0)'
      #1058#1086#1083#1100#1082#1086' '#1091#1089#1083#1091#1075#1080' (1)'
      #1058#1086#1083#1100#1082#1086' '#1087#1088#1086#1076#1091#1082#1094#1080#1103' (2)')
    TabOrder = 4
    Width = 232
  end
  object NameNomEdit: TcxButtonEdit
    Left = 122
    Top = 191
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
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
    Width = 381
  end
  object NameGrpNomEdit: TcxButtonEdit
    Left = 122
    Top = 158
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ClearKey = 16449
    Properties.ClickKey = 0
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameGrpNomEditPropertiesButtonClick
    TabOrder = 6
    Text = 'NameGrpNomEdit'
    Width = 381
  end
  object DateNach: TcxDateEdit
    Left = 32
    Top = 50
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Kind = ckDateTime
    TabOrder = 7
    Width = 185
  end
  object DateCon: TcxDateEdit
    Left = 273
    Top = 50
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.Kind = ckDateTime
    TabOrder = 8
    Width = 181
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
