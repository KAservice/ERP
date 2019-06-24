object FormaGurPlat: TFormaGurPlat
  Left = 304
  Top = 175
  Caption = #1046#1091#1088#1085#1072#1083' '#1087#1083#1072#1090#1077#1078#1077#1081':'
  ClientHeight = 642
  ClientWidth = 1012
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
  WindowState = wsMaximized
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1012
    Height = 80
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object LabelInterval: TLabel
      Left = 187
      Top = 39
      Width = 82
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1077#1088#1080#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 10
      Top = 39
      Width = 182
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1046#1091#1088#1085#1072#1083' '#1087#1083#1072#1090#1077#1078#1077#1081':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object NameKlientDBText: TDBText
      Left = 834
      Top = 59
      Width = 114
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      AutoSize = True
      DataField = 'NAMEKLIENT'
      DataSource = DMGurPlat.DataSourceTable
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 1012
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
      object ToolButtonViborPerioda: TToolButton
        Left = 8
        Top = 0
        Caption = 'ToolButtonViborPerioda'
        ImageIndex = 3
        OnClick = ToolButtonViborPeriodaClick
      end
      object ToolButtonAdd: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButtonAdd'
        ImageIndex = 0
        OnClick = ToolButtonAddClick
      end
      object ToolButtonEdit: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonEdit'
        ImageIndex = 1
        OnClick = ToolButtonEditClick
      end
      object ToolButtonDelete: TToolButton
        Left = 77
        Top = 0
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        OnClick = ToolButtonDeleteClick
      end
      object ToolButton2: TToolButton
        Left = 100
        Top = 0
        Width = 69
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonCreateFile: TToolButton
        Left = 169
        Top = 0
        Hint = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100' '#1092#1072#1081#1083' '#1076#1083#1103' '#1052#1077#1075#1072#1092#1086#1085
        Caption = 'ToolButtonCreateFile'
        ImageIndex = 20
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateFileClick
      end
      object ToolButton3: TToolButton
        Left = 192
        Top = 0
        Hint = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100' '#1092#1072#1081#1083' '#1076#1083#1103' '#1050#1080#1073#1077#1088#1083#1072#1090
        Caption = 'ToolButton3'
        ImageIndex = 19
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton3Click
      end
      object ToolButtonRefresh: TToolButton
        Left = 215
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100
        Caption = 'ToolButtonRefresh'
        ImageIndex = 48
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonRefreshClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 80
    Width = 11
    Height = 475
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 555
    Width = 1012
    Height = 87
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
    object KolStrLabel: TLabel
      Left = 162
      Top = 10
      Width = 220
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1087#1083#1072#1090#1077#1078#1077#1081': 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object SumNoOutPlatLabel: TLabel
      Left = 423
      Top = 49
      Width = 340
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = #1057#1091#1084#1084#1072'  '#1085#1077#1087#1088#1086#1074#1077#1076#1077#1085#1085#1099#1093' '#1087#1083#1072#1090#1077#1078#1081': 0.00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object SumOutPlatLabel: TLabel
      Left = 439
      Top = 30
      Width = 324
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = #1057#1091#1084#1084#1072' '#1087#1088#1086#1074#1077#1076#1077#1085#1085#1099#1093' '#1087#1083#1072#1090#1077#1078#1077#1081': 0.00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object SumAllPlatLabel: TLabel
      Left = 520
      Top = 10
      Width = 243
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = #1057#1091#1084#1084#1072' '#1074#1089#1077#1093' '#1087#1083#1072#1090#1077#1078#1077#1081': 0.00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object KolOutLabel: TLabel
      Left = 105
      Top = 30
      Width = 274
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1087#1088#1086#1074'. '#1087#1083#1072#1090#1077#1078#1077#1081': 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object KolNoOutLabel: TLabel
      Left = 83
      Top = 49
      Width = 296
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1085#1077#1087#1088#1086#1074'. '#1087#1083#1072#1090#1077#1078#1077#1081': 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonClear: TcxButton
      Left = 18
      Top = 39
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100
      TabOrder = 0
      OnClick = cxButtonClearClick
    end
    object cxButtonClose: TcxButton
      Left = 798
      Top = 30
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 1
    end
  end
  object Panel4: TPanel
    Left = 997
    Top = 80
    Width = 15
    Height = 475
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object cxGrid1: TcxGrid
    Left = 11
    Top = 80
    Width = 986
    Height = 475
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DMGurPlat.DataSourceTable
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.ColumnAutoWidth = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1OUT_GURNALPLAT: TcxGridDBColumn
        Caption = #1042#1099#1075#1088'.'
        DataBinding.FieldName = 'OUT_GURNALPLAT'
        OnCustomDrawCell = cxGrid1DBTableView1OUT_GURNALPLATCustomDrawCell
        Width = 34
      end
      object cxGrid1DBTableView1POS_GURNALPLAT: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POS_GURNALPLAT'
        Width = 118
      end
      object cxGrid1DBTableView1CODOPER_GURNALPLAT: TcxGridDBColumn
        Caption = #1054#1087#1077#1088#1072#1090#1086#1088
        DataBinding.FieldName = 'CODOPER_GURNALPLAT'
        Width = 66
      end
      object cxGrid1DBTableView1NUMKV_GURNALPLAT: TcxGridDBColumn
        Caption = #8470' '#1082#1074#1080#1090'.'
        DataBinding.FieldName = 'NUMKV_GURNALPLAT'
        Width = 55
      end
      object cxGrid1DBTableView1CODE_GURNALPLAT: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_GURNALPLAT'
        Width = 56
      end
      object cxGrid1DBTableView1NUMTEL_GURNALPLAT: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NUMTEL_GURNALPLAT'
        Width = 93
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1040#1073#1086#1085#1077#1085#1090
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 103
      end
      object cxGrid1DBTableView1SUM_GURNALPLAT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_GURNALPLAT'
        Width = 64
      end
      object cxGrid1DBTableView1PROCENT_COMMISSION_GURNALPLAT: TcxGridDBColumn
        Caption = '%'
        DataBinding.FieldName = 'PROCENT_COMMISSION_GURNALPLAT'
        Width = 23
      end
      object cxGrid1DBTableView1SUMKL_GURNALPLAT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072' '#1082#1083#1080#1077#1085#1090#1091
        DataBinding.FieldName = 'SUMKL_GURNALPLAT'
        Width = 67
      end
      object cxGrid1DBTableView1NAME_USER: TcxGridDBColumn
        Caption = #1040#1074#1090#1086#1088
        DataBinding.FieldName = 'NAME_USER'
        Width = 120
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList1: TActionList
    Images = DM.ImageList1
    Left = 216
    Top = 104
    object OpenHelp: TAction
      Caption = 'OpenHelp'
      ShortCut = 112
      OnExecute = OpenHelpExecute
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
  end
end
