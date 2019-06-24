object FormaElementaSprDepartment: TFormaElementaSprDepartment
  Left = 417
  Top = 182
  Caption = #1057#1087#1088#1086#1074#1086#1095#1085#1080#1082' '#1054#1090#1076#1077#1083#1099
  ClientHeight = 392
  ClientWidth = 527
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
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 527
    Height = 89
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    ExplicitWidth = 591
    object LabelHeader: TLabel
      Left = 8
      Top = 32
      Width = 345
      Height = 49
      Alignment = taCenter
      AutoSize = False
      Caption = #1085#1077#1080#1079#1074#1077#1089#1090#1085#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      WordWrap = True
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 89
    Width = 9
    Height = 234
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    ExplicitHeight = 145
  end
  object Panel3: TPanel
    Left = 0
    Top = 323
    Width = 527
    Height = 69
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    ExplicitTop = 234
    ExplicitWidth = 591
    object cxButtonClose: TcxButton
      Left = 429
      Top = 22
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 332
      Top = 22
      Width = 75
      Height = 25
      Action = ActionOK
      TabOrder = 1
    end
  end
  object Panel4: TPanel
    Left = 515
    Top = 89
    Width = 12
    Height = 234
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
    ExplicitLeft = 579
    ExplicitHeight = 145
  end
  object Panel5: TPanel
    Left = 9
    Top = 89
    Width = 506
    Height = 234
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 4
    ExplicitLeft = 8
    ExplicitTop = 83
    object cxDBTextEditNAME_SDEPARTMENT: TcxDBTextEdit
      Left = 152
      Top = 40
      DataBinding.DataField = 'NAME_SDEPARTMENT'
      TabOrder = 0
      Width = 297
    end
    object cxDBCalcEditNUMOTDKKT_SDEPARTMENT: TcxDBCalcEdit
      Left = 152
      Top = 88
      DataBinding.DataField = 'NUMOTDKKT_SDEPARTMENT'
      TabOrder = 1
      Width = 121
    end
    object cxLabel1: TcxLabel
      Left = 32
      Top = 40
      Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
    end
    object cxLabel2: TcxLabel
      Left = 32
      Top = 89
      Caption = #1053#1086#1084#1077#1088' '#1086#1090#1076#1077#1083#1072' '#1050#1050#1058':'
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 368
    Top = 24
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
