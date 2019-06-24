object FormaViborOplat_ARM2: TFormaViborOplat_ARM2
  Left = 0
  Top = 0
  Caption = #1042#1074#1086#1076' '#1086#1087#1083#1072#1090#1099
  ClientHeight = 401
  ClientWidth = 637
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -24
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 29
  object Panel1: TPanel
    Left = 0
    Top = 339
    Width = 637
    Height = 62
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object cxButtonPrint: TcxButton
      Left = 376
      Top = 8
      Width = 125
      Height = 44
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 0
    end
    object cxButtonClose: TcxButton
      Left = 508
      Top = 8
      Width = 119
      Height = 44
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      Cancel = True
      TabOrder = 1
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 637
    Height = 52
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object cxLabel1: TcxLabel
      Left = 0
      Top = 10
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1087#1083#1072#1090#1072':'
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 52
    Width = 637
    Height = 287
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 0
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
    end
    object cxGrid1TableView1: TcxGridTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Format = '0.00'
          Kind = skSum
          Column = cxGrid1TableView1NAL
        end
        item
          Format = '0.00'
          Kind = skSum
          Column = cxGrid1TableView1OPLPLATCARD
        end
        item
          Format = '0.00'
          Kind = skSum
          Column = cxGrid1TableView1SDACHA
        end
        item
          Format = '0.00'
          Kind = skSum
          Column = cxGrid1TableView1SUMCHECK
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsBehavior.FocusCellOnCycle = True
      OptionsSelection.InvertSelect = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.GroupByBox = False
      object cxGrid1TableView1IDFIRM: TcxGridColumn
        Caption = 'IDFIRM'
        Visible = False
      end
      object cxGrid1TableView1NAMEFIRM: TcxGridColumn
        Caption = #1060#1080#1088#1084#1072
        Options.Editing = False
        Width = 135
      end
      object cxGrid1TableView1SUMCHECK: TcxGridColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.ValueType = 'Variant'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Properties.DisplayFormat = '0.00'
        Options.Editing = False
        Width = 80
      end
      object cxGrid1TableView1NAL: TcxGridColumn
        Caption = #1053#1072#1083'.'
        DataBinding.ValueType = 'Variant'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Properties.DisplayFormat = '0.00'
        Properties.OnValidate = cxGrid1TableView1NALPropertiesValidate
        Width = 80
      end
      object cxGrid1TableView1OPLPLATCARD: TcxGridColumn
        Caption = #1050#1072#1088#1090#1086#1081
        DataBinding.ValueType = 'Float'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Properties.DisplayFormat = '0.00'
        Properties.OnValidate = cxGrid1TableView1OPLPLATCARDPropertiesValidate
        Width = 80
      end
      object cxGrid1TableView1SDACHA: TcxGridColumn
        Caption = #1057#1076#1072#1095#1072
        DataBinding.ValueType = 'Float'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Properties.DisplayFormat = '0.00'
        Options.Editing = False
        Width = 80
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1TableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 344
    Top = 16
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
    object ActionPrint: TAction
      Caption = #1055#1077#1095#1072#1090#1100
      ImageIndex = 54
      OnExecute = ActionPrintExecute
    end
  end
end
