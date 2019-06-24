object FormaViborBaseTouch: TFormaViborBaseTouch
  Left = 486
  Top = 165
  BorderIcons = []
  Caption = #1047#1072#1087#1091#1089#1082' '#1087#1088#1086#1075#1088#1072#1084#1084#1099':'
  ClientHeight = 301
  ClientWidth = 455
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object LabelFileName: TLabel
    Left = 10
    Top = 276
    Width = 262
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1086#1085#1085#1091#1102' '#1073#1072#1079#1091'...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 10
    Top = 167
    Width = 116
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 170
    Top = 167
    Width = 62
    Height = 20
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1072#1088#1086#1083#1100':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object ButtonOK: TButton
    Left = 224
    Top = 229
    Width = 105
    Height = 37
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1050
    TabOrder = 0
    OnClick = ButtonOKClick
  end
  object ButtonAdd: TButton
    Left = 334
    Top = 10
    Width = 104
    Height = 37
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '+'
    TabOrder = 1
    OnClick = ButtonAddClick
  end
  object ButtonDel: TButton
    Left = 334
    Top = 98
    Width = 104
    Height = 37
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '-'
    TabOrder = 2
    OnClick = ButtonDelClick
  end
  object ButtonCancel: TButton
    Left = 334
    Top = 229
    Width = 104
    Height = 37
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1090#1084'.'
    TabOrder = 3
    OnClick = ButtonCancelClick
  end
  object ButtonRename: TButton
    Left = 334
    Top = 54
    Width = 104
    Height = 37
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1079#1084'.'
    TabOrder = 4
    OnClick = ButtonRenameClick
  end
  object ListBox1: TListBox
    Left = 10
    Top = 10
    Width = 319
    Height = 150
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 5
    OnClick = ListBox1Click
  end
  object BitBtnInputCode: TBitBtn
    Left = 10
    Top = 229
    Width = 104
    Height = 37
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1050#1086#1076' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 6
    WordWrap = True
    OnClick = BitBtnInputCodeClick
  end
  object BitBtnInputPassword: TBitBtn
    Left = 117
    Top = 229
    Width = 105
    Height = 37
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1072#1088#1086#1083#1100
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 7
    OnClick = BitBtnInputPasswordClick
  end
  object CodeEdit: TEdit
    Left = 10
    Top = 187
    Width = 152
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Color = clBtnFace
    TabOrder = 8
    Text = 'CodeEdit'
  end
  object PasswordEdit: TEdit
    Left = 170
    Top = 187
    Width = 155
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Color = clBtnFace
    PasswordChar = '*'
    TabOrder = 9
    Text = 'PasswordEdit'
  end
  object ButtonUp: TButton
    Left = 334
    Top = 143
    Width = 104
    Height = 37
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '>'
    TabOrder = 10
    OnClick = ButtonUpClick
  end
  object ButtonDown: TButton
    Left = 334
    Top = 185
    Width = 104
    Height = 37
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = '<'
    TabOrder = 11
    OnClick = ButtonDownClick
  end
  object ActionList: TActionList
    Left = 215
    Top = 92
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
  end
end
