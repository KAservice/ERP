object HOT_FormaElementaSprSostNom: THOT_FormaElementaSprSostNom
  Left = 385
  Top = 51
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1057#1086#1089#1090#1086#1103#1085#1080#1103' '#1085#1086#1084#1077#1088#1086#1074'"'
  ClientHeight = 230
  ClientWidth = 448
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 20
  object Label1: TLabel
    Left = 10
    Top = 10
    Width = 117
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 10
    Top = 38
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_HOT_SSOSTNOM'
    TabOrder = 0
    Width = 421
  end
  object cxButtonOK: TcxButton
    Left = 236
    Top = 189
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 1
  end
  object cxButtonClose: TcxButton
    Left = 338
    Top = 189
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 2
  end
  object FlBroncxDBCheckBox: TcxDBCheckBox
    Left = 10
    Top = 83
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1088#1072#1079#1088#1077#1096#1080#1090#1100' '#1073#1088#1086#1085#1080#1088#1086#1074#1072#1085#1080#1077' '#1085#1086#1084#1077#1088#1072
    DataBinding.DataField = 'FLBRON_HOT_SSOSTNOM'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 3
    Width = 341
  end
  object FlRasmcxDBCheckBox: TcxDBCheckBox
    Left = 10
    Top = 113
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1088#1072#1079#1088#1077#1096#1080#1090#1100' '#1079#1072#1089#1077#1083#1077#1085#1080#1077' '#1085#1086#1084#1077#1088#1072
    DataBinding.DataField = 'FLRASM_HOT_SSOSTNOM'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 4
    Width = 311
  end
  object IdcxDBLabel: TcxDBLabel
    Left = 324
    Top = 4
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'ID_HOT_SSOSTNOM'
    Height = 26
    Width = 107
  end
  object cxLabel1: TcxLabel
    Left = 291
    Top = 5
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'ID:'
  end
  object ColorcxDBColorComboBox: TcxDBColorComboBox
    Left = 10
    Top = 160
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'COLOR_HOT_SSOSTNOM'
    Properties.CustomColors = <>
    TabOrder = 7
    Width = 201
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 40
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
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
  end
end
