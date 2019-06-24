object FormaElementaSprProperties: TFormaElementaSprProperties
  Left = 249
  Top = 132
  Caption = #1061#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1072' ('#1089#1074#1086#1081#1089#1090#1074#1086')'
  ClientHeight = 212
  ClientWidth = 494
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
  object NameGrpLabel: TLabel
    Left = 391
    Top = 8
    Width = 93
    Height = 16
    Alignment = taRightJustify
    Caption = 'NameGrpLabel'
  end
  object Panel2: TPanel
    Left = 0
    Top = 168
    Width = 494
    Height = 44
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object cxButtonSave: TcxButton
      Left = 192
      Top = 10
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 292
      Top = 10
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 1
    end
    object cxButtonClose: TcxButton
      Left = 391
      Top = 10
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      Cancel = True
      TabOrder = 2
    end
    object cxButtonValuesList: TcxButton
      Left = 97
      Top = 10
      Width = 86
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1085#1072#1095#1077#1085#1080#1103
      TabOrder = 3
      OnClick = cxButtonValuesListClick
    end
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 16
    Top = 72
    DataBinding.DataField = 'NAME_SPROP'
    TabOrder = 1
    OnKeyPress = NamecxDBTextEditKeyPress
    Width = 417
  end
  object cxLabel1: TcxLabel
    Left = 16
    Top = 46
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object NameForPrintcxDBTextEdit: TcxDBTextEdit
    Left = 16
    Top = 128
    DataBinding.DataField = 'NAME_FOR_PRINT_SPROP'
    TabOrder = 3
    OnKeyPress = NameForPrintcxDBTextEditKeyPress
    Width = 417
  end
  object cxLabel2: TcxLabel
    Left = 16
    Top = 108
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1076#1083#1103' '#1087#1077#1095#1072#1090#1080':'
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 416
    Top = 8
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionSetMainTabSheet: TAction
      Caption = 'ActionSetMainTabSheet'
      ShortCut = 116
    end
    object ActionSetAdditionallyTabSheet: TAction
      Caption = 'ActionSetAdditionallyTabSheet'
      ShortCut = 117
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
