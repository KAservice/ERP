object FormaSetupOtbor: TFormaSetupOtbor
  Left = 139
  Top = 99
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1086#1090#1073#1086#1088#1072
  ClientHeight = 222
  ClientWidth = 339
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
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 112
    Width = 79
    Height = 16
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 48
    Width = 47
    Height = 16
    Caption = #1060#1080#1088#1084#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 16
    Top = 80
    Width = 43
    Height = 16
    Caption = #1057#1082#1083#1072#1076':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 144
    Width = 67
    Height = 16
    Caption = #1044#1086#1082#1091#1084#1077#1085#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 8
    Top = 16
    Width = 150
    Height = 20
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1086#1090#1073#1086#1088#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object cxButtonOK: TcxButton
    Left = 175
    Top = 186
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 3
  end
  object cxButtonClose: TcxButton
    Left = 256
    Top = 186
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 4
  end
  object NameKlientEdit: TcxButtonEdit
    Left = 96
    Top = 107
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameKlientEditPropertiesButtonClick
    TabOrder = 2
    Text = 'NameKlientEdit'
    Width = 229
  end
  object NameSkladEdit: TcxButtonEdit
    Left = 96
    Top = 79
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameSkladEditPropertiesButtonClick
    TabOrder = 1
    Text = 'NameSkladEdit'
    Width = 229
  end
  object NameFirmEdit: TcxButtonEdit
    Left = 96
    Top = 52
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = NameFirmEditPropertiesButtonClick
    TabOrder = 0
    Text = 'NameFirmEdit'
    Width = 229
  end
  object TypeDoccxImageComboBox: TcxImageComboBox
    Left = 96
    Top = 143
    RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeDocForOtbor
    Properties.Items = <>
    TabOrder = 5
    Width = 229
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 40
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
