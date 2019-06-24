object FormaSetupOtborGurRoznDoc: TFormaSetupOtborGurRoznDoc
  Left = 251
  Top = 117
  BorderStyle = bsSingle
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1086#1090#1073#1086#1088#1072
  ClientHeight = 159
  ClientWidth = 341
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 48
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
  object Label4: TLabel
    Left = 16
    Top = 80
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
    Top = 124
    Width = 75
    Height = 25
    Action = ActionOK
    TabOrder = 0
  end
  object cxButtonClose: TcxButton
    Left = 256
    Top = 124
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 1
  end
  object TypeDocComboBox: TcxComboBox
    Left = 104
    Top = 78
    Properties.DropDownListStyle = lsFixedList
    Properties.Items.Strings = (
      #1053#1077#1090
      #1063#1077#1082' '#1050#1050#1052
      #1054#1090#1095#1105#1090' '#1050#1050#1052
      #1056#1077#1072#1083#1080#1079#1072#1094#1080#1103' '#1088#1086#1079#1085'.'
      #1055#1088#1080#1093#1086#1076' '#1085#1072#1083'.'
      #1056#1072#1089#1093#1086#1076' '#1085#1072#1083'.'
      #1040#1082#1090' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080)
    Properties.OnChange = TypeDocComboBoxPropertiesChange
    TabOrder = 2
    Width = 205
  end
  object NameKlientEdit: TcxButtonEdit
    Left = 104
    Top = 42
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end
      item
        Caption = 'X'
        Kind = bkText
      end>
    Properties.OnButtonClick = NameKlientEditPropertiesButtonClick
    TabOrder = 3
    Text = 'NameKlientEdit'
    Width = 205
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 64
    Top = 136
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
