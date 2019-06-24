object HOT_FormaReportSostNF: THOT_FormaReportSostNF
  Left = 308
  Top = 124
  Caption = #1054#1090#1095#1077#1090' "'#1057#1086#1089#1090#1086#1103#1085#1080#1077' '#1085#1086#1084#1077#1088#1085#1086#1075#1086' '#1092#1086#1085#1076#1072'":'
  ClientHeight = 396
  ClientWidth = 887
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
    Width = 887
    Height = 171
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label4: TLabel
      Left = 10
      Top = 145
      Width = 71
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103':'
    end
    object Label2: TLabel
      Left = 10
      Top = 59
      Width = 14
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'c'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label1: TLabel
      Left = 10
      Top = 10
      Width = 492
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1090#1095#1077#1090' "'#1057#1086#1089#1090#1086#1103#1085#1080#1077' '#1085#1086#1084#1077#1088#1085#1086#1075#1086' '#1092#1086#1085#1076#1072'" '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 276
      Top = 59
      Width = 32
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1087#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 393
      Top = 102
      Width = 46
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1086#1084#1077#1088':'
    end
    object Label9: TLabel
      Left = 388
      Top = 139
      Width = 73
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077':'
      Visible = False
    end
    object Label6: TLabel
      Left = 10
      Top = 106
      Width = 52
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1073#1098#1077#1082#1090':'
    end
    object cxButtonCreateReport: TcxButton
      Left = 732
      Top = 63
      Width = 122
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
      TabOrder = 0
      OnClick = cxButtonCreateReportClick
    end
    object cxButtonClose: TcxButton
      Left = 732
      Top = 101
      Width = 122
      Height = 27
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 1
    end
    object NameObjectcxButtonEdit: TcxButtonEdit
      Left = 86
      Top = 102
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
          Caption = #1061
          Kind = bkText
        end>
      Properties.OnButtonClick = NameObjectcxButtonEditPropertiesButtonClick
      TabOrder = 2
      Text = 'NameObjectcxButtonEdit'
      Width = 260
    end
    object NameCatcxButtonEdit: TcxButtonEdit
      Left = 86
      Top = 135
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
      Properties.OnButtonClick = NameCatcxButtonEditPropertiesButtonClick
      TabOrder = 3
      Text = 'NameCatcxButtonEdit'
      Width = 260
    end
    object PosNachcxDateEdit: TcxDateEdit
      Left = 49
      Top = 65
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.InputKind = ikMask
      TabOrder = 4
      Width = 197
    end
    object PosConcxDateEdit: TcxDateEdit
      Left = 340
      Top = 65
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.InputKind = ikMask
      TabOrder = 5
      Width = 178
    end
    object NameSostcxButtonEdit: TcxButtonEdit
      Left = 462
      Top = 132
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
          Caption = #1061
          Kind = bkText
        end>
      Properties.OnButtonClick = NameSostcxButtonEditPropertiesButtonClick
      TabOrder = 6
      Text = 'NameSostcxButtonEdit'
      Visible = False
      Width = 244
    end
    object NameNomercxButtonEdit: TcxButtonEdit
      Left = 462
      Top = 98
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
          Caption = #1061
          Kind = bkText
        end>
      Properties.OnButtonClick = NameNomercxButtonEditPropertiesButtonClick
      TabOrder = 7
      Text = 'NameNomercxButtonEdit'
      Width = 244
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 171
    Width = 887
    Height = 225
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 1
    object cxGrid1BandedTableView1: TcxGridBandedTableView
      OnDblClick = cxGrid1BandedTableView1DblClick
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
      OptionsView.GroupByBox = False
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
      object cxGrid1BandedTableView1Column1: TcxGridBandedColumn
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 0
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1BandedTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 744
    Top = 8
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
  end
  object pFIBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 536
    Top = 8
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
      '        hot_rgsostnf.id_hot_rgsostnf,'
      '        hot_ssostnom.color_hot_ssostnom'
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
      
        'order by hot_scatnom.name_hot_scatnom, hot_snf.name_hot_snf,hot_' +
        'sostnf.posnach_hot_sostnf'
      '')
    Transaction = pFIBTr
    Left = 584
    Top = 8
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
    object SostNFID_HOT_SNF: TFIBBCDField
      FieldName = 'ID_HOT_SNF'
      Size = 0
      RoundByScale = True
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
      DisplayFormat = 'c'
    end
    object SostNFPOSCON_HOT_SOSTNF: TFIBDateTimeField
      FieldName = 'POSCON_HOT_SOSTNF'
      DisplayFormat = 'c'
    end
    object SostNFKOLM_HOT_SOSTNF: TFIBIntegerField
      FieldName = 'KOLM_HOT_SOSTNF'
    end
    object SostNFID_HOT_RGSOSTNF: TFIBBCDField
      FieldName = 'ID_HOT_RGSOSTNF'
      Size = 0
      RoundByScale = True
    end
    object SostNFCOLOR_HOT_SSOSTNOM: TFIBIntegerField
      FieldName = 'COLOR_HOT_SSOSTNOM'
    end
    object SostNFNAME_HOT_SCATNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SCATNOM'
      Size = 100
    end
    object SostNFNAME_HOT_SNF: TFIBWideStringField
      FieldName = 'NAME_HOT_SNF'
      Size = 100
    end
    object SostNFNAME_HOT_SSOSTNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SSOSTNOM'
      Size = 100
    end
  end
end
