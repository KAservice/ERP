object FormaElementaSprBank: TFormaElementaSprBank
  Left = 459
  Top = 214
  Caption = #1045#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' '#1073#1072#1085#1082
  ClientHeight = 262
  ClientWidth = 561
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
    Left = 20
    Top = 20
    Width = 102
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 30
    Top = 98
    Width = 30
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1041#1048#1050':'
  end
  object Label3: TLabel
    Left = 315
    Top = 92
    Width = 42
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1043#1086#1088#1086#1076':'
  end
  object Label4: TLabel
    Left = 140
    Top = 142
    Width = 71
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1088#1088'. '#1089#1095#1077#1090':'
  end
  object cxButtonClose: TcxButton
    Left = 444
    Top = 212
    Width = 93
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 5
  end
  object cxButtonOK: TcxButton
    Left = 343
    Top = 212
    Width = 93
    Height = 30
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 4
  end
  object KorSchetcxDBTextEdit: TcxDBTextEdit
    Left = 217
    Top = 138
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'KSBANK'
    TabOrder = 3
    OnKeyDown = KorSchetcxDBTextEditKeyDown
    Width = 325
  end
  object GorodcxDBTextEdit: TcxDBTextEdit
    Left = 393
    Top = 89
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'GORBANK'
    TabOrder = 2
    OnKeyDown = GorodcxDBTextEditKeyDown
    Width = 149
  end
  object BikcxDBTextEdit: TcxDBTextEdit
    Left = 74
    Top = 89
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'BIKBANK'
    TabOrder = 1
    OnKeyDown = BikcxDBTextEditKeyDown
    Width = 149
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 20
    Top = 47
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataBinding.DataField = 'NAMEBANK'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 522
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 408
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
