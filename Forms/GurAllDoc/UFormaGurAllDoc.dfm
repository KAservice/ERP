object FormaGurAllDoc: TFormaGurAllDoc
  Left = 268
  Top = 221
  Caption = #1055#1086#1083#1085#1099#1081' '#1078#1091#1088#1085#1072#1083':'
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
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 889
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
      Left = 167
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
      Width = 159
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1086#1083#1085#1099#1081' '#1078#1091#1088#1085#1072#1083':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object StrOtborLabel: TLabel
      Left = 643
      Top = 49
      Width = 226
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090' '#1085#1077' '#1074#1099#1073#1088#1072#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 889
      Height = 26
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
      object ToolButtonOpenDvDoc: TToolButton
        Left = 54
        Top = 0
        Hint = #1044#1074#1080#1078#1077#1085#1080#1103' '#1076#1086#1082#1091#1084#1077#1085#1090#1072
        Caption = 'ToolButtonOpenDvDoc'
        ImageIndex = 13
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenDvDocClick
      end
      object ToolButtonParamOtbor: TToolButton
        Left = 77
        Top = 0
        Hint = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1086#1090#1073#1086#1088#1072
        ImageIndex = 33
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonParamOtborClick
      end
      object ToolButtonOtbor: TToolButton
        Left = 100
        Top = 0
        Hint = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1086#1090#1073#1086#1088#1086#1084
        Caption = 'ToolButtonOtbor'
        ImageIndex = 30
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonOtborClick
      end
      object ToolButtonNoCheck: TToolButton
        Left = 123
        Top = 0
        Hint = #1041#1077#1079' '#1095#1077#1082#1086#1074
        Caption = 'ToolButtonNoCheck'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonNoCheckClick
      end
      object ToolButton5: TToolButton
        Left = 146
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1088#1077#1077#1089#1090#1088#1072
        Caption = 'ToolButtonPrintReestr'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton5Click
      end
      object ToolButton2: TToolButton
        Left = 169
        Top = 0
        Width = 82
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 251
        Top = 0
        Hint = #1054#1090#1084#1077#1085#1080#1090#1100' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1077
        Caption = 'ToolButton3'
        ImageIndex = 12
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton3Click
      end
      object ToolButtonDelete: TToolButton
        Left = 274
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButtonAllCancelDvReg: TToolButton
        Left = 297
        Top = 0
        Hint = #1054#1090#1084#1077#1085#1080#1090#1100' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1077' '#1074#1089#1077#1093' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074
        Caption = 'ToolButtonAllCancelDvReg'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAllCancelDvRegClick
      end
      object ToolButtonDvRegDoc: TToolButton
        Left = 320
        Top = 0
        Hint = #1055#1088#1086#1074#1077#1089#1090#1080' '#1074#1089#1077' '#1076#1086#1082#1091#1084#1077#1085#1090#1099
        Caption = 'ToolButtonDvRegDoc'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDvRegDocClick
      end
      object ToolButtonReportOtrSpis: TToolButton
        Left = 343
        Top = 0
        Hint = #1054#1090#1088#1080#1094'. '#1089#1087#1080#1089#1072#1085#1080#1077
        Caption = 'ToolButtonReportOtrSpis'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonDelAllDoc: TToolButton
        Left = 366
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1074#1089#1077' '#1076#1086#1082#1091#1084#1077#1085#1090#1099
        Caption = '---'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDelAllDocClick
      end
      object ToolButton4: TToolButton
        Left = 389
        Top = 0
        Width = 64
        Caption = 'ToolButton4'
        ImageIndex = 0
        Style = tbsSeparator
      end
      object ToolButtonRefresh: TToolButton
        Left = 453
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100
        Caption = 'ToolButtonRefresh'
        ImageIndex = 48
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonRefreshClick
      end
      object ToolButtonExtModule: TToolButton
        Left = 476
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
    Top = 80
    Width = 11
    Height = 361
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
    Top = 80
    Width = 15
    Height = 361
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
    Width = 863
    Height = 361
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyPress = cxGrid1DBTableView1KeyPress
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          Column = cxGrid1DBTableView1SUMDOC
        end
        item
          Kind = skCount
          Column = cxGrid1DBTableView1TDOC
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsCustomize.ColumnsQuickCustomization = True
      OptionsData.Editing = False
      OptionsView.NoDataToDisplayInfoText = '<'#1053#1077#1090' '#1076#1072#1085#1085#1099#1093'>'
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1PRDOC: TcxGridDBColumn
        Caption = #1055#1088'.'
        DataBinding.FieldName = 'PRDOC'
        OnCustomDrawCell = cxGrid1DBTableView1PRDOCCustomDrawCell
        Width = 32
      end
      object cxGrid1DBTableView1NAME_SINFBASE_OBMEN: TcxGridDBColumn
        Caption = #1041#1072#1079#1072
        DataBinding.FieldName = 'NAME_SINFBASE_OBMEN'
        Width = 63
      end
      object cxGrid1DBTableView1NAMEFIRM: TcxGridDBColumn
        Caption = #1060#1080#1088#1084#1072
        DataBinding.FieldName = 'NAMEFIRM'
        Width = 70
      end
      object cxGrid1DBTableView1POSDOC: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POSDOC'
        Width = 82
      end
      object cxGrid1DBTableView1TDOC: TcxGridDBColumn
        Caption = #1044#1086#1082#1091#1084#1077#1085#1090
        DataBinding.FieldName = 'TDOC'
        Width = 84
      end
      object cxGrid1DBTableView1PREFIKS_NUM_GALLDOC: TcxGridDBColumn
        DataBinding.FieldName = 'PREFIKS_NUM_GALLDOC'
        Width = 20
        IsCaptionAssigned = True
      end
      object cxGrid1DBTableView1NUMDOC: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NUMDOC'
        Width = 52
      end
      object cxGrid1DBTableView1NAMESKLAD: TcxGridDBColumn
        Caption = #1057#1082#1083#1072#1076
        DataBinding.FieldName = 'NAMESKLAD'
        Width = 144
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 143
      end
      object cxGrid1DBTableView1SUMDOC: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUMDOC'
        Styles.Content = DM.cxStyleFooterSum
        Width = 50
      end
      object cxGrid1DBTableView1NAME_USER: TcxGridDBColumn
        Caption = #1040#1074#1090#1086#1088
        DataBinding.FieldName = 'NAME_USER'
        Width = 61
      end
      object cxGrid1DBTableView1NAME_SPROJECT: TcxGridDBColumn
        Caption = #1055#1088#1086#1077#1082#1090
        DataBinding.FieldName = 'NAME_SPROJECT'
        Width = 48
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 528
    Top = 8
  end
end
