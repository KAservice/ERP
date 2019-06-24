object HOT_FormaReportSostNF2: THOT_FormaReportSostNF2
  Left = 308
  Top = 124
  Caption = #1054#1090#1095#1077#1090' "'#1057#1086#1089#1090#1086#1103#1085#1080#1077' '#1085#1086#1084#1077#1088#1085#1086#1075#1086' '#1092#1086#1085#1076#1072'":'
  ClientHeight = 322
  ClientWidth = 605
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
    Width = 605
    Height = 177
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label4: TLabel
      Left = 8
      Top = 118
      Width = 56
      Height = 13
      Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103':'
    end
    object Label2: TLabel
      Left = 8
      Top = 48
      Width = 12
      Height = 29
      Caption = 'c'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label1: TLabel
      Left = 8
      Top = 8
      Width = 441
      Height = 29
      Caption = #1054#1090#1095#1077#1090' "'#1057#1086#1089#1090#1086#1103#1085#1080#1077' '#1085#1086#1084#1077#1088#1085#1086#1075#1086' '#1092#1086#1085#1076#1072'" '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 224
      Top = 48
      Width = 29
      Height = 29
      Caption = #1087#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 319
      Top = 83
      Width = 37
      Height = 13
      Caption = #1053#1086#1084#1077#1088':'
    end
    object Label9: TLabel
      Left = 315
      Top = 113
      Width = 57
      Height = 13
      Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077':'
    end
    object Label6: TLabel
      Left = 8
      Top = 86
      Width = 41
      Height = 13
      Caption = #1054#1073#1098#1077#1082#1090':'
    end
    object cxButtonCreateReport: TcxButton
      Left = 362
      Top = 146
      Width = 99
      Height = 25
      Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
      TabOrder = 0
      OnClick = cxButtonCreateReportClick
    end
    object cxButtonClose: TcxButton
      Left = 497
      Top = 146
      Width = 77
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 1
      OnClick = cxButtonCloseClick
    end
    object NameObjectcxButtonEdit: TcxButtonEdit
      Left = 70
      Top = 83
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = #1061
          Kind = bkText
        end>
      Properties.OnButtonClick = NameObjectcxButtonEditPropertiesButtonClick
      TabOrder = 2
      Text = 'NameObjectcxButtonEdit'
      Width = 211
    end
    object NameCatcxButtonEdit: TcxButtonEdit
      Left = 70
      Top = 110
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.OnButtonClick = NameCatcxButtonEditPropertiesButtonClick
      TabOrder = 3
      Text = 'NameCatcxButtonEdit'
      Width = 211
    end
    object PosNachcxDateEdit: TcxDateEdit
      Left = 40
      Top = 53
      Properties.InputKind = ikMask
      TabOrder = 4
      Width = 160
    end
    object PosConcxDateEdit: TcxDateEdit
      Left = 276
      Top = 53
      Properties.InputKind = ikMask
      TabOrder = 5
      Width = 145
    end
    object NameSostcxButtonEdit: TcxButtonEdit
      Left = 375
      Top = 107
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = #1061
          Kind = bkText
        end>
      Properties.OnButtonClick = NameSostcxButtonEditPropertiesButtonClick
      TabOrder = 6
      Text = 'NameSostcxButtonEdit'
      Width = 199
    end
    object NameNomercxButtonEdit: TcxButtonEdit
      Left = 375
      Top = 80
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = #1061
          Kind = bkText
        end>
      Properties.OnButtonClick = NameNomercxButtonEditPropertiesButtonClick
      TabOrder = 7
      Text = 'NameNomercxButtonEdit'
      Width = 199
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 177
    Width = 605
    Height = 145
    Align = alClient
    TabOrder = 1
    object cxGrid1TableView1: TcxGridTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsData.Editing = False
    end
    object cxGrid1BandedTableView1: TcxGridBandedTableView
      NavigatorButtons.ConfirmDelete = False
      OnCustomDrawCell = cxGrid1BandedTableView1CustomDrawCell
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsCustomize.ColumnsQuickCustomization = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsSelection.HideFocusRectOnExit = False
      OptionsSelection.CellMultiSelect = True
      Styles.Header = DM.cxStyleHeaderTable
      Bands = <
        item
          Caption = #1053#1086#1084#1077#1088
          FixedKind = fkLeft
          Styles.Header = DM.cxStyleHeaderTable
        end
        item
          Caption = #1044#1072#1090#1072
          Styles.Header = DM.cxStyleHeaderTable
        end>
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1BandedTableView1
    end
  end
  object ActionList: TActionList
    Left = 8
    Top = 264
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
  end
  object pFIBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 240
    Top = 136
  end
  object SostNF: TpFIBDataSet
    SelectSQL.Strings = (
      'select hot_sostnf.id_hot_sostnf,'
      '        hot_scatnom.id_hot_scatnom,'
      '        hot_scatnom.name_hot_scatnom,'
      '        hot_snf.id_hot_snf,'
      '        hot_snf.name_hot_snf,'
      '        hot_snf.kolm_hot_snf,'
      '        hot_ssostnom.id_hot_ssostnom,'
      '        hot_sostnf.posnach_hot_sostnf,'
      '        hot_sostnf.poscon_hot_sostnf,'
      '        hot_sostnf.kolm_hot_sostnf,'
      '        hot_ssostnom.name_hot_ssostnom,'
      '        hot_rgsostnf.id_hot_rgsostnf'
      'from hot_rgsostnf'
      ''
      '   left outer join hot_sostnf on'
      
        '   (hot_rgsostnf.idsost_hot_rgsostnf = hot_sostnf.id_hot_sostnf)' +
        '  and'
      '      ('
      
        '      (hot_sostnf.posnach_hot_sostnf between :param_posnach and ' +
        ':param_poscon)'
      '        or '
      
        '            (hot_sostnf.poscon_hot_sostnf between :param_posnach' +
        ' and :param_poscon)'
      '        or '
      
        '            (:param_posnach between hot_sostnf.posnach_hot_sostn' +
        'f and hot_sostnf.poscon_hot_sostnf)'
      '        or '
      
        '            (:param_poscon between hot_sostnf.posnach_hot_sostnf' +
        ' and hot_sostnf.poscon_hot_sostnf)'
      '      )'
      ''
      
        '   right outer join hot_snf on (hot_snf.id_hot_snf = hot_sostnf.' +
        'idnomer_hot_sostnf)'
      ''
      
        '   left outer join hot_ssostnom on (hot_sostnf.idsost_hot_sostnf' +
        ' = hot_ssostnom.id_hot_ssostnom)'
      
        '   left outer join hot_scatnom on (hot_snf.idcat_hot_snf = hot_s' +
        'catnom.id_hot_scatnom)'
      ''
      'order by hot_scatnom.name_hot_scatnom, hot_snf.name_hot_snf')
    Transaction = pFIBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 288
    Top = 136
    object SostNFID_HOT_SOSTNF: TFIBBCDField
      FieldName = 'ID_HOT_SOSTNF'
      Size = 0
      RoundByScale = True
    end
    object SostNFID_HOT_SCATNOM: TFIBBCDField
      FieldName = 'ID_HOT_SCATNOM'
      Size = 0
      RoundByScale = True
    end
    object SostNFNAME_HOT_SCATNOM: TFIBStringField
      FieldName = 'NAME_HOT_SCATNOM'
      Size = 50
      EmptyStrToNull = True
    end
    object SostNFID_HOT_SNF: TFIBBCDField
      FieldName = 'ID_HOT_SNF'
      Size = 0
      RoundByScale = True
    end
    object SostNFNAME_HOT_SNF: TFIBStringField
      FieldName = 'NAME_HOT_SNF'
      Size = 50
      EmptyStrToNull = True
    end
    object SostNFKOLM_HOT_SNF: TFIBIntegerField
      FieldName = 'KOLM_HOT_SNF'
    end
    object SostNFID_HOT_SSOSTNOM: TFIBBCDField
      FieldName = 'ID_HOT_SSOSTNOM'
      Size = 0
      RoundByScale = True
    end
    object SostNFPOSNACH_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'POSNACH_HOT_SOSTNF'
    end
    object SostNFPOSCON_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'POSCON_HOT_SOSTNF'
    end
    object SostNFKOLM_HOT_SOSTNF: TFIBIntegerField
      FieldName = 'KOLM_HOT_SOSTNF'
    end
    object SostNFNAME_HOT_SSOSTNOM: TFIBStringField
      FieldName = 'NAME_HOT_SSOSTNOM'
      Size = 50
      EmptyStrToNull = True
    end
    object SostNFID_HOT_RGSOSTNF: TFIBBCDField
      FieldName = 'ID_HOT_RGSOSTNF'
      Size = 0
      RoundByScale = True
    end
  end
end
