object HLP_FormaElementaSprInfBlockGrp: THLP_FormaElementaSprInfBlockGrp
  Left = 462
  Top = 235
  Caption = #1043#1088#1091#1087#1087#1072' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1086#1085#1085#1099#1093' '#1073#1083#1086#1082#1086#1074
  ClientHeight = 208
  ClientWidth = 401
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
    Top = 42
    Width = 118
    Height = 13
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1075#1088#1091#1087#1087#1099':'
  end
  object IdGnDBText: TDBText
    Left = 24
    Top = 8
    Width = 65
    Height = 17
    DataField = 'ID_HLP_IB_GRP'
  end
  object Label2: TLabel
    Left = 8
    Top = 8
    Width = 14
    Height = 13
    Caption = 'ID:'
  end
  object Label3: TLabel
    Left = 8
    Top = 89
    Width = 30
    Height = 13
    Caption = 'GUID:'
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 8
    Top = 62
    DataBinding.DataField = 'NAME_HLP_IB_GRP'
    TabOrder = 0
    Width = 372
  end
  object cxButtonOK: TcxButton
    Left = 215
    Top = 164
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 2
  end
  object cxButtonClose: TcxButton
    Left = 296
    Top = 164
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 3
  end
  object GUIDcxDBTextEdit: TcxDBTextEdit
    Left = 8
    Top = 108
    DataBinding.DataField = 'GUID_GRP_HLP_IB_GRP'
    TabOrder = 1
    OnKeyDown = GUIDcxDBTextEditKeyDown
    Width = 372
  end
  object IndexcxDBSpinEdit: TcxDBSpinEdit
    Left = 255
    Top = 20
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataBinding.DataField = 'INDEX_HLP_IB_GRP'
    TabOrder = 4
    Width = 125
  end
  object cxLabel3: TcxLabel
    Left = 193
    Top = 21
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1048#1085#1076#1077#1082#1089':'
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 120
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
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
