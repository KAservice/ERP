object FormaGurRoznDoc: TFormaGurRoznDoc
  Left = 288
  Top = 205
  Caption = #1046#1091#1088#1085#1072#1083' '#1088#1086#1079#1085#1080#1095#1085#1099#1093' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074':'
  ClientHeight = 511
  ClientWidth = 889
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
  OnResize = FormResize
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 889
    Height = 90
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object LabelInterval: TLabel
      Left = 315
      Top = 39
      Width = 71
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1077#1088#1080#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 10
      Top = 39
      Width = 269
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1046#1091#1088#1085#1072#1083' '#1088#1086#1079#1085#1080#1095#1085#1099#1093' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object StrOtborLabel: TLabel
      Left = 677
      Top = 66
      Width = 192
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090' '#1085#1077' '#1074#1099#1073#1088#1072#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 889
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonOpenDoc: TToolButton
        Left = 8
        Top = 0
        Caption = 'ToolButtonOpenDoc'
        ImageIndex = 1
        OnClick = ToolButtonOpenDocClick
      end
      object ToolButtonViborPerioda: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButtonViborPerioda'
        ImageIndex = 3
        OnClick = ToolButtonViborPeriodaClick
      end
      object ToolButtonParamOtbor: TToolButton
        Left = 54
        Top = 0
        Hint = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1086#1090#1073#1086#1088#1072
        ImageIndex = 33
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonParamOtborClick
      end
      object ToolButtonOtbor: TToolButton
        Left = 77
        Top = 0
        Hint = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1086#1090#1073#1086#1088#1086#1084
        Caption = 'ToolButtonOtbor'
        ImageIndex = 30
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonOtborClick
      end
      object ToolButton2: TToolButton
        Left = 100
        Top = 0
        Width = 82
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonPrint: TToolButton
        Left = 182
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100
        Caption = 'ToolButtonPrint'
        ImageIndex = 43
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintClick
      end
      object ToolButtonRefresh: TToolButton
        Left = 205
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100
        Caption = 'ToolButtonRefresh'
        ImageIndex = 48
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonRefreshClick
      end
      object ToolButtonExtModule: TToolButton
        Left = 228
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 90
    Width = 11
    Height = 351
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
    Top = 441
    Width = 889
    Height = 70
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 874
    Top = 90
    Width = 15
    Height = 351
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
    Top = 90
    Width = 863
    Height = 351
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DMGurRoznDoc.DataSourceTable
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
      object cxGrid1DBTableView1PRDOC: TcxGridDBColumn
        DataBinding.FieldName = 'PRDOC'
        OnCustomDrawCell = cxGrid1DBTableView1PRDOCCustomDrawCell
        Width = 31
        IsCaptionAssigned = True
      end
      object cxGrid1DBTableView1NAMEFIRM: TcxGridDBColumn
        Caption = #1060#1080#1088#1084#1072
        DataBinding.FieldName = 'NAMEFIRM'
        Width = 77
      end
      object cxGrid1DBTableView1POSDOC: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POSDOC'
        Width = 60
      end
      object cxGrid1DBTableView1TDOC: TcxGridDBColumn
        Caption = #1044#1086#1082#1091#1084#1077#1085#1090
        DataBinding.FieldName = 'TDOC'
        Width = 69
      end
      object cxGrid1DBTableView1NUMDOC: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NUMDOC'
        Width = 77
      end
      object cxGrid1DBTableView1NAMESKLAD: TcxGridDBColumn
        Caption = #1057#1082#1083#1072#1076
        DataBinding.FieldName = 'NAMESKLAD'
        Width = 102
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 123
      end
      object cxGrid1DBTableView1SUMDOC: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUMDOC'
        Width = 44
      end
      object cxGrid1DBTableView1NAME_USER: TcxGridDBColumn
        Caption = #1040#1074#1090#1086#1088
        DataBinding.FieldName = 'NAME_USER'
        Width = 88
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList1: TActionList
    Left = 8
    Top = 8
    object OpenHelp: TAction
      Caption = 'OpenHelp'
      ShortCut = 112
      OnExecute = OpenHelpExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 288
  end
end
