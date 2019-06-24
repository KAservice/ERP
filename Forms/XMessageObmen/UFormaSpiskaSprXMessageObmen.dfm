object FormaSpiskaSprXMessageObmen: TFormaSpiskaSprXMessageObmen
  Left = 327
  Top = 149
  Caption = #1057#1087#1080#1089#1086#1082' '#1089#1086#1086#1073#1097#1077#1085#1080#1081' '#1086#1073#1084#1077#1085#1072
  ClientHeight = 345
  ClientWidth = 597
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
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 597
    Height = 57
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object LabelInterval: TLabel
      Left = 8
      Top = 32
      Width = 61
      Height = 16
      Caption = #1055#1077#1088#1080#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelOtbor: TLabel
      Left = 502
      Top = 32
      Width = 90
      Height = 20
      Alignment = taRightJustify
      Caption = 'LabelOtbor'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 597
      Height = 29
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton2: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton2'
        ImageIndex = 1
        Style = tbsSeparator
      end
      object ToolButton1: TToolButton
        Left = 8
        Top = 0
        Hint = #1056#1072#1089#1089#1095#1080#1090#1072#1090#1100' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1086#1073#1085#1086#1074#1083#1103#1077#1084#1099#1093' '#1079#1072#1087#1080#1089#1077#1081
        Caption = 'ToolButton1'
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton1Click
      end
      object ToolButton3: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButton3'
        ImageIndex = 3
        OnClick = ToolButton3Click
      end
      object ToolButtonViborInfBase: TToolButton
        Left = 54
        Top = 0
        Hint = #1042#1099#1073#1088#1072#1090#1100' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1086#1085#1085#1091#1102' '#1073#1072#1079#1091
        Caption = 'ToolButtonViborInfBase'
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonViborInfBaseClick
      end
      object ToolButtonOtbor: TToolButton
        Left = 77
        Top = 0
        Hint = #1054#1090#1073#1086#1088
        Caption = 'ToolButtonOtbor'
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonOtborClick
      end
      object ToolButtonPrintForm: TToolButton
        Left = 100
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100
        Caption = 'ToolButtonPrintForm'
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintFormClick
      end
      object ToolButton4: TToolButton
        Left = 123
        Top = 0
        Width = 8
        Caption = 'ToolButton4'
        ImageIndex = 0
        Style = tbsSeparator
      end
      object ToolButtonSortPoDate: TToolButton
        Left = 131
        Top = 0
        Hint = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072' '#1087#1086' '#1076#1072#1090#1077
        Caption = 'ToolButtonSortPoDate'
        Grouped = True
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonSortPoDateClick
      end
      object ToolButtonSortPoGid: TToolButton
        Left = 154
        Top = 0
        Hint = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072' '#1087#1086' GID'
        Caption = 'ToolButtonSortPoGid'
        Grouped = True
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonSortPoGidClick
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 304
    Width = 597
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 57
    Width = 597
    Height = 247
    Align = alClient
    TabOrder = 2
    ExplicitLeft = 24
    ExplicitTop = 128
    ExplicitWidth = 565
    ExplicitHeight = 153
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DMXMessageObmen.DataSourceTable
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsView.ColumnAutoWidth = True
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
      end
      object cxGrid1DBTableView1POS_XMESSAGE_OBMEN: TcxGridDBColumn
        Caption = #1044#1072#1090#1072' / '#1074#1088#1077#1084#1103
        DataBinding.FieldName = 'POS_XMESSAGE_OBMEN'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
      end
      object cxGrid1DBTableView1OUT_XMESSAGE_OBMEN: TcxGridDBColumn
        Caption = #1058#1080#1087
        DataBinding.FieldName = 'OUT_XMESSAGE_OBMEN'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
      end
      object cxGrid1DBTableView1NAME_SINFBASE_OBMEN: TcxGridDBColumn
        Caption = #1048#1085#1092'. '#1073#1072#1079#1072
        DataBinding.FieldName = 'NAME_SINFBASE_OBMEN'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 216
      end
      object cxGrid1DBTableView1GID_XMESSAGE_OBMEN: TcxGridDBColumn
        Caption = 'GID '#1089#1086#1086#1073#1097#1077#1085#1080#1103
        DataBinding.FieldName = 'GID_XMESSAGE_OBMEN'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
      end
      object cxGrid1DBTableView1KOLERR_XMESSAGE_OBMEN: TcxGridDBColumn
        Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090
        DataBinding.FieldName = 'KOLERR_XMESSAGE_OBMEN'
        OnCustomDrawCell = cxGrid1DBTableView1KOLERR_XMESSAGE_OBMENCustomDrawCell
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
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
end
