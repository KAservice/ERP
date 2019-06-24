object FormaGurDocCheckKKM: TFormaGurDocCheckKKM
  Left = 197
  Top = 111
  Caption = #1046#1091#1088#1085#1072#1083' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074' "'#1063#1077#1082' '#1050#1050#1052'":'
  ClientHeight = 619
  ClientWidth = 886
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
    Width = 886
    Height = 100
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object LabelInterval: TLabel
      Left = 197
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
      Width = 192
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1046#1091#1088#1085#1072#1083' '#1095#1077#1082#1086#1074' '#1050#1050#1052':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 335
      Top = 69
      Width = 103
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1086#1084#1077#1088' '#1050#1051':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object NameKKMLabel: TLabel
      Left = 39
      Top = 69
      Width = 277
      Height = 25
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = False
      Caption = 'NameKKMLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 886
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
      object ToolButtonNewDoc: TToolButton
        Left = 8
        Top = 0
        Caption = 'ToolButtonNewDoc'
        ImageIndex = 0
        OnClick = ToolButtonNewDocClick
      end
      object ToolButton4: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButton4'
        ImageIndex = 1
        OnClick = ToolButton4Click
      end
      object ToolButtonViborPerioda: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonViborPerioda'
        ImageIndex = 3
        OnClick = ToolButtonViborPeriodaClick
      end
      object ToolButton2: TToolButton
        Left = 77
        Top = 0
        Width = 51
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 128
        Top = 0
        Hint = #1054#1090#1084#1077#1085#1080#1090#1100' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1077
        Caption = 'ToolButton3'
        ImageIndex = 12
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton3Click
      end
      object ToolButtonDelete: TToolButton
        Left = 151
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButtonPrint: TToolButton
        Left = 174
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100
        Caption = 'ToolButtonPrint'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintClick
      end
      object ToolButton5: TToolButton
        Left = 197
        Top = 0
        Width = 180
        Caption = 'ToolButton5'
        ImageIndex = 0
        Style = tbsSeparator
      end
      object ToolButtonOtbor: TToolButton
        Left = 377
        Top = 0
        Hint = #1054#1090#1073#1086#1088
        Caption = 'ToolButtonOtbor'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonOtborClick
      end
      object ToolButtonCreateDocRepKKM: TToolButton
        Left = 400
        Top = 0
        Hint = 'C'#1086#1079#1076#1072#1090#1100' '#1086#1090#1095#1077#1090' '#1050#1050#1052
        Caption = 'ToolButtonCreateDocRepKKM'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateDocRepKKMClick
      end
      object ToolButtonrefresh: TToolButton
        Left = 423
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100
        Caption = 'ToolButtonrefresh'
        ImageIndex = 48
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonrefreshClick
      end
      object ToolButtonExtModule: TToolButton
        Left = 446
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
    end
    object ButtonViborKKM: TButton
      Left = 10
      Top = 69
      Width = 26
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = '...'
      TabOrder = 1
      OnClick = ButtonViborKKMClick
    end
    object NumberKLEdit: TcxTextEdit
      Left = 464
      Top = 66
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      TabOrder = 2
      Text = 'NumberKLEdit'
      OnKeyPress = NumberKLEditKeyPress
      Width = 118
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 100
    Width = 11
    Height = 449
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
    Top = 549
    Width = 886
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
    Left = 871
    Top = 100
    Width = 15
    Height = 449
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
    Top = 100
    Width = 860
    Height = 449
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyPress = cxGrid1DBTableView1KeyPress
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsCustomize.ColumnsQuickCustomization = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.ColumnAutoWidth = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1PRDOC: TcxGridDBColumn
        Caption = #1055#1088
        DataBinding.FieldName = 'PRDOC'
        OnCustomDrawCell = cxGrid1DBTableView1PRDOCCustomDrawCell
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 20
      end
      object cxGrid1DBTableView1OPERCHK: TcxGridDBColumn
        Caption = #1054#1087#1077#1088'.'
        DataBinding.FieldName = 'OPERCHK'
        OnCustomDrawCell = cxGrid1DBTableView1OPERCHKCustomDrawCell
        Width = 39
      end
      object cxGrid1DBTableView1POSDOC: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POSDOC'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 70
      end
      object cxGrid1DBTableView1NUMDOC: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088' '#1076#1086#1082'.'
        DataBinding.FieldName = 'NUMDOC'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 46
      end
      object cxGrid1DBTableView1NKLCHK: TcxGridDBColumn
        Caption = #8470' '#1050#1051
        DataBinding.FieldName = 'NKLCHK'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 35
      end
      object cxGrid1DBTableView1NCHECKCHK: TcxGridDBColumn
        Caption = #8470' '#1095#1077#1082#1072
        DataBinding.FieldName = 'NCHECKCHK'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 39
      end
      object cxGrid1DBTableView1NAMEKKM: TcxGridDBColumn
        Caption = #1050#1050#1052
        DataBinding.FieldName = 'NAMEKKM'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 47
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1055#1086#1082#1091#1087#1072#1090#1077#1083#1100
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 47
      end
      object cxGrid1DBTableView1SUMDOC: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUMDOC'
        Options.Editing = False
        Styles.Content = DM.cxStyleHeaderTable
        Styles.Header = DM.cxStyleHeaderTable
        Width = 43
      end
      object cxGrid1DBTableView1OPLNALCHK: TcxGridDBColumn
        Caption = #1053#1072#1083#1080#1095#1085#1099#1084#1080
        DataBinding.FieldName = 'OPLNALCHK'
        Width = 53
      end
      object cxGrid1DBTableView1OPLPCCHK: TcxGridDBColumn
        Caption = #1041#1072#1085#1082'. '#1082#1072#1088#1090#1086#1081
        DataBinding.FieldName = 'OPLPCCHK'
        Width = 52
      end
      object cxGrid1DBTableView1OPLPLATCARDD_ALL: TcxGridDBColumn
        Caption = #1055#1083#1072#1090'. '#1082#1072#1088#1090#1072#1084#1080
        DataBinding.FieldName = 'OPLPLATCARD_ALL_DCHK'
        Width = 51
      end
      object cxGrid1DBTableView1OPLCREDIRCARD_ALL_DCHK: TcxGridDBColumn
        Caption = #1050#1088#1077#1076#1080#1090'. '#1082#1072#1088#1090#1072#1084#1080
        DataBinding.FieldName = 'OPLCREDITCARD_ALL_DCHK'
        Width = 52
      end
      object cxGrid1DBTableView1OPL_OTHER_DCHK: TcxGridDBColumn
        Caption = #1055#1088#1086#1095#1077#1077
        DataBinding.FieldName = 'OPL_OTHER_DCHK'
        Width = 53
      end
      object cxGrid1DBTableView1NAMEFIRM: TcxGridDBColumn
        Caption = #1060#1080#1088#1084#1072
        DataBinding.FieldName = 'NAMEFIRM'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 74
      end
      object cxGrid1DBTableView1NAMESKLAD: TcxGridDBColumn
        Caption = #1057#1082#1083#1072#1076
        DataBinding.FieldName = 'NAMESKLAD'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 85
      end
      object cxGrid1DBTableView1NAME_USER: TcxGridDBColumn
        Caption = #1040#1074#1090#1086#1088
        DataBinding.FieldName = 'NAME_USER'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 40
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
    Left = 288
  end
end
