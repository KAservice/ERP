object REM_FormaElementaSprNeispr: TREM_FormaElementaSprNeispr
  Left = 249
  Top = 132
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1077#1081'"'
  ClientHeight = 286
  ClientWidth = 570
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
    Top = 75
    Width = 105
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100':'
  end
  object Label2: TLabel
    Left = 30
    Top = 130
    Width = 160
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100' (English):'
  end
  object Panel2: TPanel
    Left = 0
    Top = 236
    Width = 570
    Height = 50
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object cxButtonOK: TcxButton
      Left = 315
      Top = 10
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 0
    end
    object cxButtonClose: TcxButton
      Left = 415
      Top = 10
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 1
    end
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 30
    Top = 98
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_REM_SNEISPR'
    DataBinding.DataSource = REM_DMSprNeispr.DataSourceElement
    TabOrder = 1
    Width = 497
  end
  object NameEngcxDBTextEdit: TcxDBTextEdit
    Left = 30
    Top = 154
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_ENG_REM_SNEISPR'
    TabOrder = 2
    Width = 497
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 24
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
