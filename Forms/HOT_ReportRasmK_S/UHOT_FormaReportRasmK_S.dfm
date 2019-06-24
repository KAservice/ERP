object HOT_FormaReportRasmK_S: THOT_FormaReportRasmK_S
  Left = 0
  Top = 0
  Caption = #1054#1090#1095#1077#1090' "'#1056#1072#1079#1084#1077#1097#1077#1085#1080#1077'"'
  ClientHeight = 486
  ClientWidth = 881
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 17
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 881
    Height = 119
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object cxLabel1: TcxLabel
      Left = 13
      Top = 0
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1072#1079#1084#1077#1097#1077#1085#1080#1077' ('#1082#1086#1081#1082#1086'/'#1089#1091#1090#1082#1080')  '#1089
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -23
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object PosNachcxDateEdit: TcxDateEdit
      Left = 398
      Top = 9
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.Kind = ckDateTime
      TabOrder = 1
      Width = 197
    end
    object PosConcxDateEdit: TcxDateEdit
      Left = 659
      Top = 9
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.Kind = ckDateTime
      TabOrder = 2
      Width = 207
    end
    object cxLabel3: TcxLabel
      Left = 619
      Top = 0
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1087#1086
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -23
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object NameFirmcxButtonEdit: TcxButtonEdit
      Left = 73
      Top = 54
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameFirmcxButtonEditPropertiesButtonClick
      TabOrder = 4
      Text = 'NameFirmcxButtonEdit'
      Width = 317
    end
    object cxLabel2: TcxLabel
      Left = 13
      Top = 59
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
    end
    object cxButtonCreate: TcxButton
      Left = 413
      Top = 51
      Width = 128
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
      TabOrder = 6
      OnClick = cxButtonCreateClick
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 433
    Width = 881
    Height = 53
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object cxButtonClose: TcxButton
      Left = 739
      Top = 8
      Width = 98
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 0
    end
    object cxButtonPrint: TcxButton
      Left = 633
      Top = 8
      Width = 98
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 1
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 119
    Width = 881
    Height = 314
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 2
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = HOT_DMReportRasmK_S.DataSourceReport
      DataController.Summary.DefaultGroupSummaryItems = <
        item
          Kind = skSum
          Column = cxGrid1DBTableView1KOL_K_S
          DisplayText = #1048#1090#1086#1075#1086' '
        end
        item
          Kind = skSum
          Column = cxGrid1DBTableView1KOLSUTOK
        end
        item
          Kind = skCount
          DisplayText = #1050#1086#1083'.'
        end>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          Column = cxGrid1DBTableView1KOL_K_S
        end
        item
          Kind = skSum
          Column = cxGrid1DBTableView1KOLSUTOK
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsCustomize.ColumnsQuickCustomization = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsSelection.HideFocusRectOnExit = False
      OptionsSelection.InvertSelect = False
      OptionsSelection.UnselectFocusedRecordOnExit = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.GroupSummaryLayout = gslAlignWithColumns
      Styles.Footer = DM.cxStyleHeaderTable
      Styles.GroupSummary = DM.cxStyleFooterSum
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1NAME_HOT_SOBJECT: TcxGridDBColumn
        Caption = #1054#1073#1098#1077#1082#1090
        DataBinding.FieldName = 'NAME_HOT_SOBJECT'
        Visible = False
        GroupIndex = 0
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1043#1086#1089#1090#1100
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 72
      end
      object cxGrid1DBTableView1NAME_SCOUNTRY: TcxGridDBColumn
        Caption = #1057#1090#1088#1072#1085#1072
        DataBinding.FieldName = 'NAME_SCOUNTRY'
        Width = 110
      end
      object cxGrid1DBTableView1NAME_SVIDKLIENT: TcxGridDBColumn
        Caption = #1042#1080#1076
        DataBinding.FieldName = 'NAME_SVIDKLIENT'
        Width = 89
      end
      object cxGrid1DBTableView1NAME_HOT_SCELPR: TcxGridDBColumn
        Caption = #1062#1077#1083#1100' '#1087#1088#1080#1077#1079#1076#1072
        DataBinding.FieldName = 'NAME_HOT_SCELPR'
        Width = 133
      end
      object cxGrid1DBTableView1POSNACH_HOT_SOSTNF: TcxGridDBColumn
        Caption = #1047#1072#1077#1079#1076
        DataBinding.FieldName = 'POSNACH_HOT_SOSTNF'
        Width = 63
      end
      object cxGrid1DBTableView1POSCON_HOT_SOSTNF: TcxGridDBColumn
        Caption = #1042#1099#1077#1079#1076
        DataBinding.FieldName = 'POSCON_HOT_SOSTNF'
        Width = 61
      end
      object cxGrid1DBTableView1KOLSUTOK: TcxGridDBColumn
        Caption = #1057#1091#1090'.'
        DataBinding.FieldName = 'KOLSUTOK'
        Width = 55
      end
      object cxGrid1DBTableView1KOLM_HOT_SOSTNF: TcxGridDBColumn
        Caption = #1052#1077#1089#1090
        DataBinding.FieldName = 'KOLM_HOT_SOSTNF'
        Width = 37
      end
      object cxGrid1DBTableView1KOL_K_S: TcxGridDBColumn
        Caption = #1050'/'#1089
        DataBinding.FieldName = 'KOL_K_S'
        Width = 35
      end
      object cxGrid1DBTableView1INTERVAL: TcxGridDBColumn
        Caption = #1048#1085#1090#1077#1088#1074#1072#1083
        DataBinding.FieldName = 'INTERVAL'
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object dxComponentPrinter1: TdxComponentPrinter
    CurrentLink = dxComponentPrinter1Link1
    Version = 0
    Left = 632
    Top = 40
    object dxComponentPrinter1Link1: TdxGridReportLink
      Active = True
      Component = cxGrid1
      PrinterPage.DMPaper = 9
      PrinterPage.Footer = 6350
      PrinterPage.Header = 6350
      PrinterPage.Margins.Bottom = 12700
      PrinterPage.Margins.Left = 12700
      PrinterPage.Margins.Right = 12700
      PrinterPage.Margins.Top = 12700
      PrinterPage.PageSize.X = 210000
      PrinterPage.PageSize.Y = 297000
      PrinterPage._dxMeasurementUnits_ = 0
      PrinterPage._dxLastMU_ = 2
      ReportDocument.CreationDate = 40414.794706307870000000
      OptionsFormatting.UseNativeStyles = True
      OptionsSize.AutoWidth = True
      StyleRepository = DM.cxStyleRepository1
      Styles.BandHeader = DM.cxStyleBandHeadeReportr
      Styles.Caption = DM.cxStyleCaptionReport
      Styles.FilterBar = DM.cxStyleFilterBarReport
      Styles.Footer = DM.cxStyleFooterReport
      Styles.Header = DM.cxStyleHeaderReport
      BuiltInReportLink = True
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 712
    Top = 96
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
    object ActionPrint: TAction
      Caption = #1055#1077#1095#1072#1090#1100
      ImageIndex = 43
      OnExecute = ActionPrintExecute
    end
  end
end
