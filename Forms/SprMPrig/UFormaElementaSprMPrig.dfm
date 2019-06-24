object FormaElementaSprMPrig: TFormaElementaSprMPrig
  Left = 418
  Top = 75
  Caption = #1045#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1052#1077#1089#1090#1072' '#1080#1079#1075#1086#1090#1086#1074#1083#1077#1085#1080#1103'"'
  ClientHeight = 181
  ClientWidth = 342
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
    Top = 32
    Width = 79
    Height = 13
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object TLabel
    Left = 32
    Top = 96
    Width = 34
    Height = 13
    Caption = #1057#1082#1083#1072#1076':'
  end
  object Label2: TLabel
    Left = 8
    Top = 64
    Width = 76
    Height = 13
    Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077':'
  end
  object IDMPrigDBText: TDBText
    Left = 240
    Top = 1
    Width = 80
    Height = 17
    DataField = 'ID_MPRIG'
  end
  object Label3: TLabel
    Left = 218
    Top = 2
    Width = 14
    Height = 13
    Caption = 'ID:'
  end
  object cxButtonOK: TcxButton
    Left = 178
    Top = 148
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 0
  end
  object cxButtonClose: TcxButton
    Left = 259
    Top = 148
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 1
  end
  object NameSkladcxDBButtonEdit: TcxDBButtonEdit
    Left = 112
    Top = 86
    DataBinding.DataField = 'NAMESKLAD'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameSkladcxDBButtonEditPropertiesButtonClick
    TabOrder = 2
    Width = 209
  end
  object NameOborudcxDBButtonEdit: TcxDBButtonEdit
    Left = 112
    Top = 56
    DataBinding.DataField = 'NAME_OBORUD'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    TabOrder = 3
    Width = 208
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 113
    Top = 24
    DataBinding.DataField = 'NAME_MPRIG'
    TabOrder = 4
    Width = 207
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 88
    Top = 152
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
