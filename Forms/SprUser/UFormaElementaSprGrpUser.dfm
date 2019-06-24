object FormaElementaSprGrpUser: TFormaElementaSprGrpUser
  Left = 462
  Top = 235
  Caption = #1043#1088#1091#1087#1087#1072' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077#1081
  ClientHeight = 213
  ClientWidth = 377
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
    Left = 8
    Top = 31
    Width = 118
    Height = 13
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1075#1088#1091#1087#1087#1099':'
  end
  object IdGnDBText: TDBText
    Left = 304
    Top = 8
    Width = 65
    Height = 17
    DataField = 'ID_SGRPUSER'
  end
  object Label2: TLabel
    Left = 282
    Top = 8
    Width = 14
    Height = 13
    Caption = 'ID:'
  end
  object Label3: TLabel
    Left = 8
    Top = 83
    Width = 32
    Height = 13
    Caption = 'ROLE:'
  end
  object Label4: TLabel
    Left = 53
    Top = 83
    Width = 152
    Height = 13
    Caption = '('#1090#1086#1083#1100#1082#1086' '#1072#1085#1075#1083#1080#1081#1089#1082#1080#1077' '#1089#1080#1084#1074#1086#1083#1099')'
  end
  object cxButtonOK: TcxButton
    Left = 213
    Top = 180
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 3
  end
  object cxButtonClose: TcxButton
    Left = 294
    Top = 180
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 4
  end
  object InterfUserComboBox: TcxComboBox
    Left = 8
    Top = 136
    Properties.DropDownListStyle = lsFixedList
    Properties.Items.Strings = (
      '0 - '#1085#1077' '#1079#1072#1076#1072#1085
      '1 - '#1040#1076#1084#1080#1085#1080#1089#1090#1088#1072#1090#1086#1088
      '2 - '#1050#1072#1089#1089#1080#1088)
    Properties.OnChange = InterfUserComboBoxPropertiesChange
    TabOrder = 2
    Width = 237
  end
  object RolecxDBTextEdit: TcxDBTextEdit
    Left = 8
    Top = 105
    DataBinding.DataField = 'ROLE_SGRPUSER'
    TabOrder = 1
    OnKeyDown = RolecxDBTextEditKeyDown
    Width = 237
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 8
    Top = 53
    DataBinding.DataField = 'NAME_SGRPUSER'
    TabOrder = 0
    OnKeyDown = NamecxDBTextEditKeyDown
    Width = 361
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 312
    Top = 112
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
