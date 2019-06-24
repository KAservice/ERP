object FormaElementaSprScale: TFormaElementaSprScale
  Left = 233
  Top = 313
  Caption = #1069#1083#1077#1082#1090#1088#1086#1085#1085#1099#1077' '#1074#1077#1089#1099
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
  object Label2: TLabel
    Left = 192
    Top = 8
    Width = 14
    Height = 13
    Caption = 'ID:'
  end
  object cxButtonClose: TcxButton
    Left = 294
    Top = 120
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 0
  end
  object cxButtonOK: TcxButton
    Left = 213
    Top = 120
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 1
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 16
    Top = 62
    DataBinding.DataField = 'NAME_SSCALE'
    TabOrder = 2
    Width = 364
  end
  object IdScalecxDBLabel: TcxDBLabel
    Left = 214
    Top = 6
    AutoSize = True
    DataBinding.DataField = 'ID_SSCALE'
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 64
    Top = 136
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
