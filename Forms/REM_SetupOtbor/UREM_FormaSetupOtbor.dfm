object REM_FormaSetupOtbor: TREM_FormaSetupOtbor
  Left = 139
  Top = 99
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1086#1090#1073#1086#1088#1072
  ClientHeight = 273
  ClientWidth = 417
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 10
    Top = 138
    Width = 93
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 10
    Top = 59
    Width = 57
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1060#1080#1088#1084#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 20
    Top = 98
    Width = 53
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1057#1082#1083#1072#1076':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 10
    Top = 177
    Width = 78
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1044#1086#1082#1091#1084#1077#1085#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 10
    Top = 20
    Width = 176
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1086#1090#1073#1086#1088#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object cxButtonOK: TcxButton
    Left = 215
    Top = 229
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionOK
    TabOrder = 4
  end
  object cxButtonClose: TcxButton
    Left = 315
    Top = 229
    Width = 92
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Action = ActionClose
    TabOrder = 5
  end
  object TypeDocComboBox: TcxComboBox
    Left = 118
    Top = 176
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.DropDownListStyle = lsFixedList
    Properties.Items.Strings = (
      #1053#1077' '#1079#1072#1076#1072#1085
      #1040#1082#1090' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080
      #1040#1082#1090' '#1089#1087#1080#1089#1072#1085#1080#1103
      #1042#1086#1079#1074#1088#1072#1090' '#1087#1086#1082#1091#1087#1072#1090#1077#1083#1103
      #1042#1086#1079#1074#1088#1072#1090' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1091
      #1042#1099#1087#1091#1089#1082' '#1087#1088#1086#1076#1091#1082#1094#1080#1080
      #1048#1085#1074#1077#1085#1090#1072#1088#1080#1079#1072#1094#1080#1103
      #1050#1086#1088#1088'. '#1074#1079#1072#1080#1084#1086#1088#1072#1089#1095#1077#1090#1086#1074
      #1054#1089#1090#1072#1090#1082#1080' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
      #1054#1090#1095#1077#1090' '#1050#1050#1052
      #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077
      #1055#1077#1088#1077#1086#1094#1077#1085#1082#1072
      #1055#1083#1072#1090'. '#1087#1086#1088#1091#1095#1077#1085#1080#1077
      #1055#1086#1089#1090#1091#1087#1083'. '#1085#1072' '#1089#1095#1077#1090
      '')
    Properties.OnChange = TypeDocComboBoxPropertiesChange
    TabOrder = 3
    Width = 282
  end
  object NameKlientEdit: TcxButtonEdit
    Left = 118
    Top = 132
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
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
    Width = 282
  end
  object NameSkladEdit: TcxButtonEdit
    Left = 118
    Top = 97
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
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
    Width = 282
  end
  object NameFirmEdit: TcxButtonEdit
    Left = 118
    Top = 64
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
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
    Width = 282
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
