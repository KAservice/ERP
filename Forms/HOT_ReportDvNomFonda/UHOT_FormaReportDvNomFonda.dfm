object HOT_FormaReportDvNomFonda: THOT_FormaReportDvNomFonda
  Left = 0
  Top = 0
  Caption = #1054#1090#1095#1077#1090' "'#1044#1074#1080#1078#1077#1085#1080#1077' '#1085#1086#1084#1077#1088#1085#1086#1075#1086' '#1092#1086#1085#1076#1072'"'
  ClientHeight = 475
  ClientWidth = 806
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
    Width = 806
    Height = 106
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object PosNach: TcxDateEdit
      Left = 63
      Top = 41
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.Kind = ckDateTime
      TabOrder = 0
      Width = 158
    end
    object PosCon: TcxDateEdit
      Left = 293
      Top = 41
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.Kind = ckDateTime
      TabOrder = 1
      Width = 158
    end
    object cxLabel1: TcxLabel
      Left = 10
      Top = 10
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1074#1080#1078#1077#1085#1080#1077' '#1085#1086#1084#1077#1088#1085#1086#1075#1086' '#1092#1086#1085#1076#1072' '
    end
    object cxButtonUpdate: TcxButton
      Left = 490
      Top = 65
      Width = 98
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1073#1085#1086#1074#1080#1090#1100
      TabOrder = 3
      OnClick = cxButtonUpdateClick
    end
    object cxLabel2: TcxLabel
      Left = 21
      Top = 42
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1089
    end
    object cxLabel3: TcxLabel
      Left = 251
      Top = 42
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1087#1086
    end
    object NameSostcxButtonEdit: TcxButtonEdit
      Left = 127
      Top = 76
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
      Properties.OnButtonClick = NameSostcxButtonEditPropertiesButtonClick
      TabOrder = 6
      Text = 'NameSostcxButtonEdit'
      Width = 282
    end
    object cxLabel4: TcxLabel
      Left = 31
      Top = 76
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077':'
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 421
    Width = 806
    Height = 54
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 106
    Width = 806
    Height = 315
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 2
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DataSource1
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
      OptionsSelection.InvertSelect = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.Indicator = True
      Styles.GroupSummary = DM.cxStyleFooterSum
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1NAME_HOT_SOBJECT: TcxGridDBColumn
        Caption = #1054#1073#1098#1077#1082#1090
        DataBinding.FieldName = 'NAME_HOT_SOBJECT'
        Visible = False
        GroupIndex = 0
      end
      object cxGrid1DBTableView1NAME_HOT_SCATNOM: TcxGridDBColumn
        Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103
        DataBinding.FieldName = 'NAME_HOT_SCATNOM'
        Visible = False
        GroupIndex = 1
      end
      object cxGrid1DBTableView1TDV_HOT_RGSOSTNF_DV: TcxGridDBColumn
        Caption = #1044#1074'.'
        DataBinding.FieldName = 'TDV_HOT_RGSOSTNF_DV'
        Width = 20
      end
      object cxGrid1DBTableView1POS_HOT_RGSOSTNF_DV: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POS_HOT_RGSOSTNF_DV'
        Width = 61
      end
      object cxGrid1DBTableView1NAME_HOT_SSOSTNOM: TcxGridDBColumn
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
        DataBinding.FieldName = 'NAME_HOT_SSOSTNOM'
        Width = 82
      end
      object cxGrid1DBTableView1NAME_HOT_SNF: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NAME_HOT_SNF'
        Width = 98
      end
      object cxGrid1DBTableView1POSNACH_HOT_SOSTNF: TcxGridDBColumn
        Caption = #1047#1072#1077#1079#1076
        DataBinding.FieldName = 'POSNACH_HOT_SOSTNF'
        Width = 87
      end
      object cxGrid1DBTableView1POSCON_HOT_SOSTNF: TcxGridDBColumn
        Caption = #1042#1099#1077#1079#1076
        DataBinding.FieldName = 'POSCON_HOT_SOSTNF'
        Width = 84
      end
      object cxGrid1DBTableView1OPER_HOT_RGSOSTNF_DV: TcxGridDBColumn
        DataBinding.FieldName = 'OPER_HOT_RGSOSTNF_DV'
        Width = 21
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1043#1086#1089#1090#1100
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 127
      end
    end
    object cxGrid1Level1: TcxGridLevel
      Caption = #1054#1090#1095#1077#1090' '#1086' '#1076#1074#1080#1078#1077#1085#1080#1080' '#1085#1086#1084#1077#1088#1085#1086#1075#1086' '#1092#1086#1085#1076#1072
      GridView = cxGrid1DBTableView1
    end
  end
  object cxButtonPrint: TcxButton
    Left = 596
    Top = 65
    Width = 98
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1077#1095#1072#1090#1100
    TabOrder = 3
    OnClick = cxButtonPrintClick
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '        hot_sobject.name_hot_sobject,'
      '        hot_scatnom.name_hot_scatnom,'
      '        hot_snf.name_hot_snf,'
      '        sklient.nameklient,'
      '        hot_sostnf.posnach_hot_sostnf,'
      '        hot_sostnf.poscon_hot_sostnf,'
      '        hot_ssostnom.name_hot_ssostnom,'
      '        hot_rgsostnf_dv.*'
      'from hot_rgsostnf_dv'
      
        'left outer join hot_sostnf on hot_rgsostnf_dv.idsost_hot_rgsostn' +
        'f_dv=hot_sostnf.id_hot_sostnf'
      
        'left outer join hot_snf on hot_sostnf.idnomer_hot_sostnf=hot_snf' +
        '.id_hot_snf'
      
        'left outer join hot_scatnom on hot_snf.idcat_hot_snf=hot_scatnom' +
        '.id_hot_scatnom'
      
        'left outer join hot_sobject on hot_snf.idob_hot_snf=hot_sobject.' +
        'id_hot_sobject'
      
        'left outer join sklient on hot_sostnf.idguest_hot_sostnf=sklient' +
        '.idklient'
      
        'left outer join hot_ssostnom on hot_sostnf.idsost_hot_sostnf=hot' +
        '_ssostnom.id_hot_ssostnom'
      
        'where hot_rgsostnf_dv.pos_hot_rgsostnf_dv between :PARAM_POSNACH' +
        ' and :PARAM_POSCON'
      'order by TDV_HOT_RGSOSTNF_DV')
    Transaction = pFIBTr
    DefaultFormats.DateTimeDisplayFormat = 'dd.mm.yyyy hh:mm '
    DefaultFormats.DisplayFormatTime = 'hh:mm'
    Left = 704
    object TablePOSNACH_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'POSNACH_HOT_SOSTNF'
      DisplayFormat = 'c'
    end
    object TablePOSCON_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'POSCON_HOT_SOSTNF'
      DisplayFormat = 'c'
    end
    object TablePOS_HOT_RGSOSTNF_DV: TFIBDateTimeField
      FieldName = 'POS_HOT_RGSOSTNF_DV'
      DisplayFormat = 'c'
    end
    object TableTDV_HOT_RGSOSTNF_DV: TFIBIntegerField
      FieldName = 'TDV_HOT_RGSOSTNF_DV'
      OnGetText = TableTDV_HOT_RGSOSTNF_DVGetText
    end
    object TableOPER_HOT_RGSOSTNF_DV: TFIBIntegerField
      FieldName = 'OPER_HOT_RGSOSTNF_DV'
    end
    object TableNAME_HOT_SOBJECT: TFIBWideStringField
      FieldName = 'NAME_HOT_SOBJECT'
      Size = 100
    end
    object TableNAME_HOT_SCATNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SCATNOM'
      Size = 100
    end
    object TableNAME_HOT_SNF: TFIBWideStringField
      FieldName = 'NAME_HOT_SNF'
      Size = 100
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 100
    end
    object TableNAME_HOT_SSOSTNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SSOSTNOM'
      Size = 100
    end
  end
  object pFIBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read_committed'
      'rec_version'
      'nowait'
      'read')
    TPBMode = tpbDefault
    Left = 752
  end
  object DataSource1: TDataSource
    DataSet = Table
    Left = 496
  end
  object dxComponentPrinter1: TdxComponentPrinter
    CurrentLink = dxComponentPrinter1Link1
    Version = 0
    Left = 560
    Top = 32
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
      ReportDocument.CreationDate = 40414.771669525460000000
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      OptionsFormatting.UseNativeStyles = True
      OptionsOnEveryPage.FilterBar = False
      OptionsPreview.MaxLineCount = 3
      OptionsPreview.Visible = False
      OptionsSize.AutoWidth = True
      OptionsView.Footers = False
      OptionsView.FilterBar = False
      OptionsView.GroupFooters = False
      StyleRepository = DM.cxStyleRepository1
      Styles.Caption = DM.cxStyleCaptionReport
      Styles.Header = DM.cxStyleHeaderReport
      Styles.Selection = DM.cxStyleHeaderReport
      BuiltInReportLink = True
    end
  end
end
