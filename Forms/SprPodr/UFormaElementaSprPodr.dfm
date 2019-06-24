object FormaElementaSprPodr: TFormaElementaSprPodr
  Left = 373
  Top = 10
  Caption = #1045#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1055#1086#1076#1088#1072#1079#1076#1077#1083#1077#1085#1080#1103'"'
  ClientHeight = 178
  ClientWidth = 340
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 64
    Width = 79
    Height = 13
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object TLabel
    Left = 32
    Top = 96
    Width = 43
    Height = 13
    Caption = #1058#1080#1087' '#1094#1077#1085':'
  end
  object cxButtonOK: TcxButton
    Left = 176
    Top = 136
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 2
  end
  object cxButtonClose: TcxButton
    Left = 257
    Top = 136
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 3
  end
  object NameTPricecxDBButtonEdit: TcxDBButtonEdit
    Left = 112
    Top = 93
    DataBinding.DataField = 'NAME_TPRICE'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameTPricecxDBButtonEditPropertiesButtonClick
    TabOrder = 1
    Width = 209
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 116
    Top = 61
    DataBinding.DataField = 'NAMEPOD'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 205
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 40
    Top = 16
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
