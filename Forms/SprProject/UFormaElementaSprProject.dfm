object FormaElementaSprProject: TFormaElementaSprProject
  Left = 462
  Top = 235
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1055#1088#1086#1077#1082#1090#1099'"'
  ClientHeight = 169
  ClientWidth = 388
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 40
    Width = 79
    Height = 13
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 8
    Top = 62
    DataBinding.DataField = 'NAME_SPROJECT'
    TabOrder = 1
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 372
  end
  object cxButtonOK: TcxButton
    Left = 215
    Top = 112
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 2
  end
  object cxButtonClose: TcxButton
    Left = 296
    Top = 112
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 3
  end
  object CodecxDBTextEdit: TcxDBTextEdit
    Left = 259
    Top = 16
    DataBinding.DataField = 'CODE_SPROJECT'
    TabOrder = 0
    OnKeyDown = CodecxDBTextEditKeyDown
    Width = 121
  end
  object cxLabel1: TcxLabel
    Left = 227
    Top = 17
    Caption = #1050#1086#1076':'
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 352
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
  end
end
