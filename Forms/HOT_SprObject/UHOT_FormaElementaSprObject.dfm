object HOT_FormaElementaSprObject: THOT_FormaElementaSprObject
  Left = 385
  Top = 51
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1050#1072#1090#1077#1075#1086#1088#1080#1080' '#1085#1086#1084#1077#1088#1086#1074'"'
  ClientHeight = 158
  ClientWidth = 356
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 102
    Height = 16
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 8
    Top = 64
    Width = 216
    Height = 16
    Caption = #1057#1082#1083#1072#1076' ('#1084#1077#1089#1090#1086' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080' '#1091#1089#1083#1091#1075'):'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 8
    Top = 30
    DataBinding.DataField = 'NAME_HOT_SOBJECT'
    TabOrder = 0
    Width = 337
  end
  object cxButtonOK: TcxButton
    Left = 189
    Top = 120
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 1
  end
  object cxButtonClose: TcxButton
    Left = 270
    Top = 120
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 2
  end
  object NameSkladcxDBButtonEdit: TcxDBButtonEdit
    Left = 8
    Top = 86
    DataBinding.DataField = 'NAMESKLAD'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = NameSkladcxDBButtonEditPropertiesButtonClick
    TabOrder = 3
    Width = 337
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
