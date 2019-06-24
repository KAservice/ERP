object FormaElementaSprStrObject: TFormaElementaSprStrObject
  Left = 426
  Top = 358
  Caption = #1043#1088#1091#1087#1087#1072' '
  ClientHeight = 169
  ClientWidth = 388
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 40
    Width = 118
    Height = 13
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1075#1088#1091#1087#1087#1099':'
  end
  object Label2: TLabel
    Left = 152
    Top = 16
    Width = 74
    Height = 13
    Caption = #1050#1086#1076' '#1101#1083#1077#1084#1077#1085#1090#1072':'
  end
  object cxButtonOK: TcxButton
    Left = 208
    Top = 120
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 0
  end
  object cxButtonClose: TcxButton
    Left = 289
    Top = 120
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 1
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 16
    Top = 80
    DataBinding.DataField = 'NAME_STROB'
    TabOrder = 2
    Width = 364
  end
  object CodecxDBTextEdit: TcxDBTextEdit
    Left = 252
    Top = 12
    DataBinding.DataField = 'CODE_STROB'
    TabOrder = 3
    Width = 128
  end
  object GRPcxDBCheckBox: TcxDBCheckBox
    Left = 8
    Top = 10
    Caption = #1075#1088#1091#1087#1087#1072
    DataBinding.DataField = 'GRP_STROB'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 4
    Width = 121
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
