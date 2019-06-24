object HOT_FormaSpiskaTableSostNF: THOT_FormaSpiskaTableSostNF
  Left = 461
  Top = 146
  Caption = #1058#1072#1073#1083#1080#1094#1072' '#1089#1086#1089#1090#1086#1103#1085#1080#1081' '#1085#1086#1084#1077#1088#1085#1086#1075#1086' '#1092#1086#1085#1076#1072':'
  ClientHeight = 462
  ClientWidth = 910
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
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 910
    Height = 90
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
    object Label1: TLabel
      Left = 11
      Top = 43
      Width = 530
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1072#1073#1083#1080#1094#1072' '#1089#1086#1089#1090#1086#1103#1085#1080#1081' '#1085#1086#1084#1077#1088#1085#1086#1075#1086' '#1092#1086#1085#1076#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 910
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
      object ToolButtonNew: TToolButton
        Left = 8
        Top = 0
        Caption = 'ToolButtonNew'
        ImageIndex = 0
        OnClick = ToolButtonNewClick
      end
      object ToolButtonEdit: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        OnClick = ToolButtonEditClick
      end
      object ToolButtonDelete: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        OnClick = ToolButtonDeleteClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 90
    Width = 11
    Height = 303
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel3: TPanel
    Left = 894
    Top = 90
    Width = 16
    Height = 303
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object Panel4: TPanel
    Left = 0
    Top = 393
    Width = 910
    Height = 69
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 4
    object cxButton1: TcxButton
      Left = 792
      Top = 24
      Width = 102
      Height = 33
      Action = ActionClose
      TabOrder = 0
    end
  end
  object cxGrid1: TcxGrid
    Left = 11
    Top = 90
    Width = 883
    Height = 303
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 0
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyDown = cxGrid1DBTableView1KeyDown
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsView.ColumnAutoWidth = True
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 25
      end
      object cxGrid1DBTableView1NAMEPLAT: TcxGridDBColumn
        Caption = #1055#1083#1072#1090#1077#1083#1100#1097#1080#1082
        DataBinding.FieldName = 'NAMEPLAT'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 99
      end
      object cxGrid1DBTableView1NAMEGUEST: TcxGridDBColumn
        Caption = #1043#1086#1089#1090#1100
        DataBinding.FieldName = 'NAMEGUEST'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 101
      end
      object cxGrid1DBTableView1NAME_HOT_SNF: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NAME_HOT_SNF'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 105
      end
      object cxGrid1DBTableView1NAME_HOT_SSOSTNOM: TcxGridDBColumn
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
        DataBinding.FieldName = 'NAME_HOT_SSOSTNOM'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 105
      end
      object cxGrid1DBTableView1NAME_HOT_STYPEPOS: TcxGridDBColumn
        Caption = #1058#1080#1087' '#1087#1086#1089#1077#1083#1077#1085#1080#1103
        DataBinding.FieldName = 'NAME_HOT_STYPEPOS'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 83
      end
      object cxGrid1DBTableView1POSNACH_HOT_SOSTNF: TcxGridDBColumn
        Caption = #1047#1072#1077#1079#1076
        DataBinding.FieldName = 'POSNACH_HOT_SOSTNF'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 90
      end
      object cxGrid1DBTableView1POSCON_HOT_SOSTNF: TcxGridDBColumn
        Caption = #1042#1099#1077#1079#1076
        DataBinding.FieldName = 'POSCON_HOT_SOSTNF'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 87
      end
      object cxGrid1DBTableView1KOLM_HOT_SOSTNF: TcxGridDBColumn
        Caption = #1052#1077#1089#1090
        DataBinding.FieldName = 'KOLM_HOT_SOSTNF'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 20
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
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
