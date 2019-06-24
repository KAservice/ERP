object REM_FormaGurProverok: TREM_FormaGurProverok
  Left = 268
  Top = 221
  Caption = #1046#1091#1088#1085#1072#1083' '#1087#1088#1086#1074#1077#1088#1086#1082':'
  ClientHeight = 511
  ClientWidth = 1003
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
    Width = 1003
    Height = 185
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
      Width = 138
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1086#1083#1085#1099#1081' '#1078#1091#1088#1085#1072#1083':'
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
      Width = 1003
      Height = 26
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton6: TToolButton
        Left = 0
        Top = 0
        Caption = 'ToolButton6'
        ImageIndex = 0
      end
      object ToolButton1: TToolButton
        Left = 23
        Top = 0
        Width = 8
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonOpenDoc: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButtonOpenDoc'
        ImageIndex = 1
        OnClick = ToolButtonOpenDocClick
      end
      object ToolButtonViborPerioda: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonViborPerioda'
        ImageIndex = 3
        OnClick = ToolButtonViborPeriodaClick
      end
      object ToolButtonOpenDvDoc: TToolButton
        Left = 77
        Top = 0
        Hint = #1044#1074#1080#1078#1077#1085#1080#1103' '#1076#1086#1082#1091#1084#1077#1085#1090#1072
        Caption = 'ToolButtonOpenDvDoc'
        ImageIndex = 13
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonParamOtbor: TToolButton
        Left = 100
        Top = 0
        Hint = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1086#1090#1073#1086#1088#1072
        ImageIndex = 33
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonParamOtborClick
      end
      object ToolButtonOtbor: TToolButton
        Left = 123
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
        Left = 146
        Top = 0
        Hint = #1041#1077#1079' '#1095#1077#1082#1086#1074
        Caption = 'ToolButtonNoCheck'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
      end
      object ToolButton5: TToolButton
        Left = 169
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1088#1077#1077#1089#1090#1088#1072
        Caption = 'ToolButtonPrintReestr'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton2: TToolButton
        Left = 192
        Top = 0
        Width = 82
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 274
        Top = 0
        Hint = #1054#1090#1084#1077#1085#1080#1090#1100' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1077
        Caption = 'ToolButton3'
        ImageIndex = 12
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton3Click
      end
      object ToolButtonDelete: TToolButton
        Left = 297
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButtonAllCancelDvReg: TToolButton
        Left = 320
        Top = 0
        Hint = #1054#1090#1084#1077#1085#1080#1090#1100' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1077' '#1074#1089#1077#1093' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074
        Caption = 'ToolButtonAllCancelDvReg'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonDvRegDoc: TToolButton
        Left = 343
        Top = 0
        Hint = #1055#1088#1086#1074#1077#1089#1090#1080' '#1074#1089#1077' '#1076#1086#1082#1091#1084#1077#1085#1090#1099
        Caption = 'ToolButtonDvRegDoc'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonReportOtrSpis: TToolButton
        Left = 366
        Top = 0
        Hint = #1054#1090#1088#1080#1094'. '#1089#1087#1080#1089#1072#1085#1080#1077
        Caption = 'ToolButtonReportOtrSpis'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonDelAllDoc: TToolButton
        Left = 389
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1074#1089#1077' '#1076#1086#1082#1091#1084#1077#1085#1090#1099
        Caption = '---'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton4: TToolButton
        Left = 412
        Top = 0
        Width = 64
        Caption = 'ToolButton4'
        ImageIndex = 0
        Style = tbsSeparator
      end
      object ToolButtonRefresh: TToolButton
        Left = 476
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100
        Caption = 'ToolButtonRefresh'
        ImageIndex = 48
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonRefreshClick
      end
      object ToolButtonOpenExtModule: TToolButton
        Left = 499
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonOpenExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCopyDoc: TToolButton
        Left = 522
        Top = 0
        Hint = #1057#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1074' '#1085#1086#1074#1099#1081
        Caption = 'ToolButtonCopyDoc'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateNaOsn: TToolButton
        Left = 545
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1085#1072' '#1086#1089#1085#1086#1074#1072#1085#1080#1080
        Caption = 'ToolButtonCreateNaOsn'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
    end
    object Panel5: TPanel
      Left = 0
      Top = 66
      Width = 1003
      Height = 119
      Align = alBottom
      BevelEdges = []
      BevelOuter = bvNone
      TabOrder = 1
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 185
    Width = 11
    Height = 256
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
    Width = 1003
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
    Left = 988
    Top = 185
    Width = 15
    Height = 256
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
    Top = 185
    Width = 977
    Height = 256
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
      DataController.DataSource = REM_DMGurAllDoc.DataSourceTable
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
      object cxGrid1DBTableView1POS_REM_GUR_PROV: TcxGridDBColumn
        DataBinding.FieldName = 'POS_REM_GUR_PROV'
        Width = 67
      end
      object cxGrid1DBTableView1NUM_REM_GUR_PROV: TcxGridDBColumn
        DataBinding.FieldName = 'NUM_REM_GUR_PROV'
        Width = 83
      end
      object cxGrid1DBTableView1NAME_USER_PROV: TcxGridDBColumn
        DataBinding.FieldName = 'NAME_USER_PROV'
        Width = 48
      end
      object cxGrid1DBTableView1RES_REM_GUR_PROV: TcxGridDBColumn
        DataBinding.FieldName = 'RES_REM_GUR_PROV'
        Width = 27
      end
      object cxGrid1DBTableView1PRDOC: TcxGridDBColumn
        Caption = #1055#1088'.'
        DataBinding.FieldName = 'PR_REM_GALLDOC'
        Width = 36
      end
      object cxGrid1DBTableView1NAME_SINFBASE_OBMEN: TcxGridDBColumn
        Caption = #1041#1072#1079#1072
        DataBinding.FieldName = 'NAME_SINFBASE_OBMEN'
        Width = 44
      end
      object cxGrid1DBTableView1NAMEFIRM: TcxGridDBColumn
        Caption = #1060#1080#1088#1084#1072
        DataBinding.FieldName = 'NAMEFIRM'
        Width = 67
      end
      object cxGrid1DBTableView1POSDOC: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POS_REM_GALLDOC'
        Width = 76
      end
      object cxGrid1DBTableView1TDOC: TcxGridDBColumn
        Caption = #1044#1086#1082#1091#1084#1077#1085#1090
        DataBinding.FieldName = 'TDOC_REM_GALLDOC'
        Width = 79
      end
      object cxGrid1DBTableView1PREFIKS_NUM_REM_GALLDOC: TcxGridDBColumn
        DataBinding.FieldName = 'PREFIKS_NUM_REM_GALLDOC'
        Width = 20
        IsCaptionAssigned = True
      end
      object cxGrid1DBTableView1NUMDOC: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NUM_REM_GALLDOC'
        Width = 39
      end
      object cxGrid1DBTableView1NAMESKLAD: TcxGridDBColumn
        Caption = #1057#1082#1083#1072#1076
        DataBinding.FieldName = 'NAMESKLAD'
        Width = 137
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 135
      end
      object cxGrid1DBTableView1SUMDOC: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_REM_GALLDOC'
        Styles.Content = DM.cxStyleFooterSum
        Width = 51
      end
      object cxGrid1DBTableView1NAME_USER_DOC: TcxGridDBColumn
        Caption = #1040#1074#1090#1086#1088
        DataBinding.FieldName = 'NAME_USER_DOC'
        Width = 54
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
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 440
    Top = 24
  end
end
