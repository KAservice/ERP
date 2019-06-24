object HOT_FormaElementaSprCatNom: THOT_FormaElementaSprCatNom
  Left = 385
  Top = 51
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1050#1072#1090#1077#1075#1086#1088#1080#1080' '#1085#1086#1084#1077#1088#1086#1074'"'
  ClientHeight = 198
  ClientWidth = 445
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
  object Label2: TLabel
    Left = 10
    Top = 80
    Width = 78
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1087#1080#1089#1072#1085#1080#1077':'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 10
    Top = 38
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAME_HOT_SCATNOM'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 421
  end
  object DescrcxDBTextEdit: TcxDBTextEdit
    Left = 10
    Top = 100
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'DESCR_HOT_SCATNOM'
    TabOrder = 1
    OnKeyDown = DescrcxDBTextEditKeyDown
    Width = 421
  end
  object cxButtonOK: TcxButton
    Left = 236
    Top = 150
    Width = 94
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 2
  end
  object cxButtonClose: TcxButton
    Left = 338
    Top = 150
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 3
  end
  object ActionList: TActionList
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
