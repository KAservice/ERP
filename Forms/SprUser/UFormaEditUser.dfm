object FormaEditUser: TFormaEditUser
  Left = 0
  Top = 0
  Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103' '#1074' '#1073#1072#1079#1077' Firebird'
  ClientHeight = 375
  ClientWidth = 304
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object NameUserLabel: TLabel
    Left = 8
    Top = 8
    Width = 89
    Height = 16
    Caption = 'NameUserLabel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object NameServerLabel: TLabel
    Left = 8
    Top = 27
    Width = 101
    Height = 16
    Caption = 'NameServerLabel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Name2UserLabel: TLabel
    Left = 8
    Top = 46
    Width = 96
    Height = 16
    Caption = 'Name2UserLabel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 53
    Top = 97
    Width = 99
    Height = 16
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1087#1072#1088#1086#1083#1100':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 39
    Top = 124
    Width = 113
    Height = 16
    Caption = #1055#1086#1074#1090#1086#1088#1080#1090#1077' '#1087#1072#1088#1086#1083#1100':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object RoleUserLabel: TLabel
    Left = 8
    Top = 68
    Width = 81
    Height = 16
    Caption = 'RoleUserLabel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object cxGroupBox1: TcxGroupBox
    Left = 8
    Top = 240
    Caption = #1056#1086#1083#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103' '#1074' '#1090#1077#1082#1091#1097#1077#1081' '#1073#1072#1079#1077
    TabOrder = 0
    Height = 73
    Width = 281
    object cxButtonAddRole: TcxButton
      Left = 31
      Top = 32
      Width = 97
      Height = 25
      Caption = #1053#1072#1079#1085#1072#1095#1080#1090#1100' '#1088#1086#1083#1100
      TabOrder = 0
      OnClick = cxButtonAddRoleClick
    end
    object cxButtonDelRole: TcxButton
      Left = 158
      Top = 32
      Width = 97
      Height = 25
      Caption = #1054#1090#1084#1077#1085#1080#1090#1100' '#1088#1086#1083#1100
      TabOrder = 1
      OnClick = cxButtonDelRoleClick
    end
  end
  object cxButtonClose: TcxButton
    Left = 214
    Top = 336
    Width = 75
    Height = 25
    Action = ActionClose
    TabOrder = 1
  end
  object cxGroupBox2: TcxGroupBox
    Left = 8
    Top = 161
    Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1080' '#1089#1077#1088#1074#1077#1088#1072' ('#1086#1073#1097#1080#1077' '#1076#1083#1103' '#1074#1089#1077#1093' '#1073#1072#1079')'
    TabOrder = 2
    Height = 73
    Width = 281
    object cxButtonNew: TcxButton
      Left = 24
      Top = 24
      Width = 75
      Height = 25
      Caption = #1053#1086#1074#1099#1081
      TabOrder = 0
      OnClick = cxButtonNewClick
    end
    object cxButtonEdit: TcxButton
      Left = 105
      Top = 24
      Width = 75
      Height = 25
      Caption = #1048#1079#1084#1077#1085#1080#1090#1100
      TabOrder = 1
      OnClick = cxButtonEditClick
    end
    object cxButtonDel: TcxButton
      Left = 186
      Top = 24
      Width = 75
      Height = 25
      Caption = #1059#1076#1072#1083#1080#1090#1100
      TabOrder = 2
      OnClick = cxButtonDelClick
    end
  end
  object PasswordEdit: TcxTextEdit
    Left = 168
    Top = 96
    Properties.PasswordChar = '*'
    TabOrder = 3
    Text = 'PasswordEdit'
    Width = 121
  end
  object Password2Edit: TcxTextEdit
    Left = 168
    Top = 123
    Properties.PasswordChar = '*'
    TabOrder = 4
    Text = 'Password2Edit'
    Width = 121
  end
  object pFIBSecurityService1: TpFIBSecurityService
    LibraryName = 'fbclient.dll'
    LoginPrompt = False
    SecurityAction = ActionAddUser
    UserID = 0
    GroupID = 0
    Left = 232
    Top = 16
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
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
  end
end
