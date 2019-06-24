object FormaElementaSprCustomerUser: TFormaElementaSprCustomerUser
  Left = 249
  Top = 132
  Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100
  ClientHeight = 465
  ClientWidth = 636
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object NameGrpLabel: TLabel
    Left = 522
    Top = 8
    Width = 93
    Height = 16
    Alignment = taRightJustify
    Caption = 'NameGrpLabel'
  end
  object Panel2: TPanel
    Left = 0
    Top = 421
    Width = 636
    Height = 44
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object cxButtonSave: TcxButton
      Left = 311
      Top = 10
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 411
      Top = 10
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 1
    end
    object cxButtonClose: TcxButton
      Left = 511
      Top = 10
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      Cancel = True
      TabOrder = 2
    end
    object cxButton1: TcxButton
      Left = 216
      Top = 10
      Width = 88
      Height = 31
      Caption = #1055#1072#1088#1086#1083#1100' 123'
      TabOrder = 3
      OnClick = cxButton1Click
    end
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 35
    Top = 99
    DataBinding.DataField = 'NAME_CUST_USER'
    TabOrder = 1
    Width = 580
  end
  object cxLabel1: TcxLabel
    Left = 48
    Top = 73
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object PasswordcxDBTextEdit: TcxDBTextEdit
    Left = 198
    Top = 229
    DataBinding.DataField = 'PASSWORD_CUST_USER'
    TabOrder = 3
    OnKeyPress = KeyWordscxDBTextEditKeyPress
    Width = 417
  end
  object LogincxDBTextEdit: TcxDBTextEdit
    Left = 198
    Top = 284
    DataBinding.DataField = 'LOGIN_CUST_USER'
    TabOrder = 4
    OnKeyPress = KeyWordscxDBTextEditKeyPress
    Width = 417
  end
  object cxLabel7: TcxLabel
    Left = 80
    Top = 230
    Caption = #1055#1072#1088#1086#1083#1100':'
  end
  object cxLabel8: TcxLabel
    Left = 80
    Top = 285
    Caption = 'Login:'
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 232
    Top = 8
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionSetMainTabSheet: TAction
      Caption = 'ActionSetMainTabSheet'
      ShortCut = 116
    end
    object ActionSetAdditionallyTabSheet: TAction
      Caption = 'ActionSetAdditionallyTabSheet'
      ShortCut = 117
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
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
  end
end
