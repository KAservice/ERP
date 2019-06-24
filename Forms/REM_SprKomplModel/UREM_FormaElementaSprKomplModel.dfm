object REM_FormaElementaSprKomplModel: TREM_FormaElementaSprKomplModel
  Left = 645
  Top = 0
  Caption = #1045#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1045#1076#1080#1085#1080#1094#1099' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099'"'
  ClientHeight = 240
  ClientWidth = 428
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
    Top = 24
    Width = 117
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 183
    Top = 99
    Width = 95
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 10
    Top = 51
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_REM_SKOMPLMODEL'
    DataBinding.DataSource = REM_DMSprKomplModel.DataSourceElement
    TabOrder = 0
    Width = 408
  end
  object KolcxDBTextEdit: TcxDBTextEdit
    Left = 291
    Top = 93
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'KOL_REM_SKOMPLMODEL'
    DataBinding.DataSource = REM_DMSprKomplModel.DataSourceElement
    TabOrder = 1
    Width = 127
  end
  object OsncxDBCheckBox: TcxDBCheckBox
    Left = 10
    Top = 136
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1086#1089#1085#1086#1074#1085#1086#1077' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1086
    DataBinding.DataField = 'OSN_REM_SKOMPLMODEL'
    DataBinding.DataSource = REM_DMSprKomplModel.DataSourceElement
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 2
    Width = 211
  end
  object NeIspcxDBCheckBox: TcxDBCheckBox
    Left = 229
    Top = 136
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1085#1077' '#1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1090#1100
    DataBinding.DataField = 'NEISP_REM_SKOMPLMODEL'
    DataBinding.DataSource = REM_DMSprKomplModel.DataSourceElement
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 3
    Width = 172
  end
  object cxButtonOK: TcxButton
    Left = 201
    Top = 190
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 4
  end
  object cxButtonClose: TcxButton
    Left = 303
    Top = 190
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 5
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 240
    Top = 32
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
