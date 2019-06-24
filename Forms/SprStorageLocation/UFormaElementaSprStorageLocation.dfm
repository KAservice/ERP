object FormaElementaSprStorageLocation: TFormaElementaSprStorageLocation
  Left = 413
  Top = 248
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' '#1055#1088#1086#1076#1072#1074#1094#1099
  ClientHeight = 196
  ClientWidth = 495
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
    Left = 24
    Top = 88
    Width = 79
    Height = 13
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object IdDBText: TDBText
    Left = 352
    Top = 8
    Width = 65
    Height = 17
    DataField = 'ID_SMHRAN'
  end
  object Label2: TLabel
    Left = 328
    Top = 8
    Width = 14
    Height = 13
    Caption = 'ID:'
  end
  object cxButtonOK: TcxButton
    Left = 295
    Top = 145
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 0
  end
  object cxButtonClose: TcxButton
    Left = 389
    Top = 145
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 1
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 116
    Top = 85
    DataBinding.DataField = 'NAME_SMHRAN'
    TabOrder = 2
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 322
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 456
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
