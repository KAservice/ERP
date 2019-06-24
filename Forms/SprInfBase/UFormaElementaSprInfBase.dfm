object FormaElementaSprInfBase: TFormaElementaSprInfBase
  Left = 418
  Top = 359
  Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1086#1085#1085#1072#1103' '#1073#1072#1079#1072
  ClientHeight = 257
  ClientWidth = 518
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
    Left = 10
    Top = 30
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object IDDBText: TDBText
    Left = 390
    Top = 20
    Width = 88
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Alignment = taRightJustify
    AutoSize = True
    DataField = 'ID_SINFBASE_OBMEN'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object IdTIsmDBText: TDBText
    Left = 324
    Top = 120
    Width = 80
    Height = 21
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataField = 'IDTIZM_SINFBASE_OBMEN'
  end
  object Label4: TLabel
    Left = 10
    Top = 120
    Width = 306
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1095#1072#1083#1100#1085#1099#1081'  '#1085#1086#1084#1077#1088' '#1079#1072#1087#1080#1089#1080' '#1090#1072#1073#1083#1080#1094#1099' '#1080#1079#1084#1077#1085#1077#1085#1080#1081
  end
  object Label2: TLabel
    Left = 220
    Top = 92
    Width = 204
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1088#1077#1092#1080#1082#1089' '#1085#1086#1084#1077#1088#1086#1074' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074':'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 10
    Top = 53
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_SINFBASE_OBMEN'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 496
  end
  object cxButtonSave: TcxButton
    Left = 192
    Top = 217
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionSave
    TabOrder = 3
  end
  object cxButtonOK: TcxButton
    Left = 292
    Top = 217
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 4
  end
  object cxButtonClose: TcxButton
    Left = 391
    Top = 217
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 5
  end
  object cxLabel1: TcxLabel
    Left = 20
    Top = 166
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    AutoSize = False
    Caption = 
      #1042#1085#1080#1084#1072#1085#1080#1077'! '#1057#1087#1080#1089#1086#1082' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1086#1085#1085#1099#1093' '#1073#1072#1079' '#1088#1077#1076#1072#1082#1090#1080#1088#1091#1077#1090#1089#1103' '#1090#1086#1083#1100#1082#1086' '#1074' '#1094#1077#1085#1090#1088 +
      #1072#1083#1100#1085#1086#1081' '#1073#1072#1079#1077'!'
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clRed
    Style.Font.Height = -15
    Style.Font.Name = 'MS Sans Serif'
    Style.Font.Style = [fsBold]
    Style.IsFontAssigned = True
    Properties.WordWrap = True
    Height = 44
    Width = 423
  end
  object NoActcxDBCheckBox: TcxDBCheckBox
    Left = 10
    Top = 144
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1085#1077' '#1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1090#1100' '#1073#1072#1079#1091
    DataBinding.DataField = 'NOACT_SINFBASE_OBMEN'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 2
    Width = 188
  end
  object PrefiksNumDoccxDBTextEdit: TcxDBTextEdit
    Left = 432
    Top = 85
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'PREF_NUM_SINFBASE_OBMEN'
    TabOrder = 1
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 73
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 280
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
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
  end
end
