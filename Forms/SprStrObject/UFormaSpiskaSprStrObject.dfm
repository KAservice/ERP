object FormaSpiskaSprStrObject: TFormaSpiskaSprStrObject
  Left = 224
  Top = 102
  Caption = #1057#1090#1088#1091#1082#1090#1091#1088#1072' '#1088#1077#1089#1090#1086#1088#1072#1085#1072
  ClientHeight = 549
  ClientWidth = 696
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 696
    Height = 57
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object Label1: TLabel
      Left = 200
      Top = 32
      Width = 239
      Height = 20
      Caption = #1057#1090#1088#1091#1082#1090#1091#1088#1072' '#1086#1073#1098#1077#1082#1090#1086#1074' '#1088#1077#1089#1090#1086#1088#1072#1085#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 857
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonNewGrp: TToolButton
        Left = 8
        Top = 0
        Caption = 'ToolButtonNewGrp'
        ImageIndex = 0
        OnClick = ToolButtonNewGrpClick
      end
      object ToolButtonEdiGrp: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButtonEdiGrp'
        ImageIndex = 1
        OnClick = ToolButtonEdiGrpClick
      end
      object ToolButtonDeleteGrp: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonDeleteGrp'
        ImageIndex = 2
        OnClick = ToolButtonDeleteGrpClick
      end
      object ToolButton2: TToolButton
        Left = 77
        Top = 0
        Width = 84
        Caption = 'ToolButton2'
        ImageIndex = 2
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 161
        Top = 0
        Width = 136
        Caption = 'ToolButton3'
        ImageIndex = 3
        Style = tbsSeparator
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 57
    Width = 9
    Height = 406
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 463
    Width = 696
    Height = 86
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    object cxButtonClose: TcxButton
      Left = 602
      Top = 31
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 0
    end
  end
  object Panel4: TPanel
    Left = 677
    Top = 57
    Width = 19
    Height = 406
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object TreeView1: TTreeView
    Left = 9
    Top = 57
    Width = 668
    Height = 406
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    Indent = 19
    ParentFont = False
    SortType = stText
    TabOrder = 4
    OnCustomDrawItem = TreeView1CustomDrawItem
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 40
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
