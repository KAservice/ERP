object FormaSpiskaSprSezKFSProd: TFormaSpiskaSprSezKFSProd
  Left = 382
  Top = 162
  Caption = #1057#1077#1079#1086#1085#1085#1099#1077' '#1082#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1099' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
  ClientHeight = 309
  ClientWidth = 368
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
    Width = 368
    Height = 89
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object LabelNom: TLabel
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
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 368
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      ParentShowHint = False
      ShowHint = False
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonNew: TToolButton
        Left = 8
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1080#1085#1075#1088#1080#1076#1080#1077#1085#1090
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonNewClick
      end
      object ToolButtonDelete: TToolButton
        Left = 31
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1080#1085#1075#1088#1080#1076#1080#1077#1085#1090
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 89
    Width = 9
    Height = 151
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 240
    Width = 368
    Height = 69
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    object cxButtonOK: TcxButton
      Left = 200
      Top = 22
      Width = 75
      Height = 25
      Action = ActionOK
      TabOrder = 0
    end
    object cxButtonClose: TcxButton
      Left = 281
      Top = 22
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 1
    end
  end
  object Panel4: TPanel
    Left = 356
    Top = 89
    Width = 12
    Height = 151
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object DBGrid1: TDBGrid
    Left = 9
    Top = 89
    Width = 347
    Height = 151
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnDblClick = DBGrid1DblClick
    Columns = <
      item
        Expanded = False
        FieldName = 'MONTH_SSEZKF_SPROD'
        Title.Caption = #1052#1077#1089#1103#1094
        Width = 156
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'VALUE_SSEZKF_SPROD'
        Title.Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090
        Width = 159
        Visible = True
      end>
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 304
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
