object FormaElementaSprStorageLocationGrp: TFormaElementaSprStorageLocationGrp
  Left = 462
  Top = 235
  Caption = #1043#1088#1091#1087#1087#1072' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
  ClientHeight = 247
  ClientWidth = 391
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
    Left = 16
    Top = 40
    Width = 118
    Height = 13
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1075#1088#1091#1087#1087#1099':'
  end
  object IdGnDBText: TDBText
    Left = 24
    Top = 8
    Width = 65
    Height = 17
    DataField = 'ID_SMHRAN_GRP'
  end
  object Label2: TLabel
    Left = 8
    Top = 8
    Width = 14
    Height = 13
    Caption = 'ID:'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 8
    Top = 62
    DataBinding.DataField = 'NAME_SMHRAN_GRP'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 372
  end
  object cxButtonOK: TcxButton
    Left = 215
    Top = 203
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 1
  end
  object cxButtonClose: TcxButton
    Left = 296
    Top = 203
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 2
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
