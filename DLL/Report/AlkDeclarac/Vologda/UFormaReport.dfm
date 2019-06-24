object FormaReport: TFormaReport
  Left = 0
  Top = 0
  Caption = #1040#1083#1082#1086#1075#1086#1083#1100#1085#1072#1103' '#1076#1077#1082#1083#1072#1088#1072#1094#1080#1103
  ClientHeight = 710
  ClientWidth = 1217
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 17
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1217
    Height = 127
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 64
      Top = 51
      Width = 11
      Height = 28
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'c'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 356
      Top = 50
      Width = 25
      Height = 28
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1087#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 34
      Top = 89
      Width = 58
      Height = 21
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 411
      Top = 89
      Width = 51
      Height = 21
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1082#1083#1072#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 679
      Top = 89
      Width = 61
      Height = 21
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1043#1088#1091#1087#1087#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object ControlBar1: TControlBar
      Left = 1
      Top = 1
      Width = 1215
      Height = 42
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Align = alTop
      TabOrder = 0
      object ToolBar1: TToolBar
        Left = 11
        Top = 2
        Width = 238
        Height = 22
        Caption = 'ToolBar1'
        Images = imgStandart
        TabOrder = 0
        object ToolButton4: TToolButton
          Left = 0
          Top = 0
          Action = ActionExportExcel
        end
        object ToolButton1: TToolButton
          Left = 23
          Top = 0
          Action = ActionPageSetup
        end
        object ToolButton2: TToolButton
          Left = 46
          Top = 0
          Action = ActionPreeView
        end
        object ToolButton3: TToolButton
          Left = 69
          Top = 0
          Action = ActionPrint
        end
        object ToolButton6: TToolButton
          Left = 92
          Top = 0
          Width = 31
          Caption = 'ToolButton6'
          ImageIndex = 0
          Style = tbsSeparator
        end
        object ToolButtonCheckAll: TToolButton
          Left = 123
          Top = 0
          Action = ActionCheckAll
          ParentShowHint = False
          ShowHint = True
        end
        object ToolButtonCheckClear: TToolButton
          Left = 146
          Top = 0
          Action = ActionClearAll
          ParentShowHint = False
          ShowHint = True
        end
        object ToolButtonOpenRepPoDay: TToolButton
          Left = 169
          Top = 0
          Action = ActionShowGrafikPoday
          ParentShowHint = False
          ShowHint = True
        end
        object ToolButtonCreateDiagramm: TToolButton
          Left = 192
          Top = 0
          Action = ActionShowDiagramm
          ParentShowHint = False
          ShowHint = True
        end
      end
    end
    object NameFirmcxLookupComboBox: TcxLookupComboBox
      Left = 99
      Top = 88
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.KeyFieldNames = 'IDFIRM'
      Properties.ListColumns = <
        item
          FieldName = 'NAMEFIRM'
        end>
      Properties.ListSource = DataSourceFirma
      TabOrder = 1
      Width = 284
    end
    object NameSkladcxLookupComboBox: TcxLookupComboBox
      Left = 472
      Top = 88
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.KeyFieldNames = 'IDSKLAD'
      Properties.ListColumns = <
        item
          FieldName = 'NAMESKLAD'
        end>
      Properties.ListSource = DataSourceSklad
      TabOrder = 2
      Width = 190
    end
    object PosNachcxDateEdit: TcxDateEdit
      Left = 109
      Top = 51
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.Kind = ckDateTime
      TabOrder = 3
      Width = 223
    end
    object PosConcxDateEdit: TcxDateEdit
      Left = 391
      Top = 54
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.Kind = ckDateTime
      TabOrder = 4
      Width = 158
    end
    object cxButtonRunReportPoGrp: TcxButton
      Left = 689
      Top = 51
      Width = 98
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1073#1085#1086#1074#1080#1090#1100
      TabOrder = 5
      OnClick = cxButtonRunReportPoGrpClick
    end
    object cxButtonCreateRasdel1: TcxButton
      Left = 1098
      Top = 51
      Width = 99
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1072#1079#1076#1077#1083' 1'
      TabOrder = 6
      OnClick = cxButtonCreateRasdel1Click
    end
    object cxButtonCreateRasdel2: TcxButton
      Left = 1098
      Top = 92
      Width = 99
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1072#1079#1076#1077#1083' 2'
      TabOrder = 7
      OnClick = cxButtonCreateRasdel2Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 649
    Width = 1217
    Height = 61
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    TabOrder = 1
    object cxButtonClose: TcxButton
      Left = 889
      Top = 21
      Width = 98
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = cxButtonCloseClick
    end
    object cxButtonPrintRasdel2: TcxButton
      Left = 276
      Top = 16
      Width = 187
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1077#1095#1072#1090#1100' '#1088#1072#1079#1076#1077#1083' 2'
      TabOrder = 1
      OnClick = cxButtonPrintRasdel2Click
    end
    object cxButtonPrintRasdel1: TcxButton
      Left = 94
      Top = 16
      Width = 174
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1077#1095#1072#1090#1100' '#1088#1072#1079#1076#1077#1083' 1'
      TabOrder = 2
      OnClick = cxButtonPrintRasdel1Click
    end
  end
  object NameGrpcxLookupComboBox: TcxLookupComboBox
    Left = 743
    Top = 88
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Properties.KeyFieldNames = 'IDGN'
    Properties.ListColumns = <
      item
        FieldName = 'NAMEGN'
      end>
    Properties.ListSource = DataSourceGrp
    TabOrder = 2
    Width = 247
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 127
    Width = 1217
    Height = 522
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 3
    ClientRectBottom = 522
    ClientRectRight = 1217
    ClientRectTop = 28
    object cxTabSheet1: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1086' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072#1084
      ImageIndex = 0
      object cxGrid1: TcxGrid
        Left = 0
        Top = 0
        Width = 1217
        Height = 494
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
        object cxGrid1DBBandedTableView1: TcxGridDBBandedTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.DataSource = DataSourceReport
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <
            item
              Kind = skSum
              FieldName = 'OUT_CONOSTKOL'
              Column = cxGrid1DBBandedTableView1OUT_CONOSTKOL
            end
            item
              Kind = skSum
              FieldName = 'OUT_CONOSTKOL_FISED'
              Column = cxGrid1DBBandedTableView1OUT_CONOSTKOL_FISED
            end
            item
              Kind = skSum
              FieldName = 'OUT_NACHOSTKOL'
              Column = cxGrid1DBBandedTableView1OUT_NACHOSTKOL
            end
            item
              Kind = skSum
              FieldName = 'OUT_NACHOSTKOL_FISED'
              Column = cxGrid1DBBandedTableView1OUT_NACHOSTKOL_FISED
            end
            item
              Kind = skSum
              FieldName = 'OUT_PRIHODKOL'
              Column = cxGrid1DBBandedTableView1OUT_PRIHODKOL
            end
            item
              Kind = skSum
              FieldName = 'OUT_PRIHODKOL_FISED'
              Column = cxGrid1DBBandedTableView1OUT_PRIHODKOL_FISED
            end
            item
              Kind = skSum
              FieldName = 'OUT_RASHODKOL'
              Column = cxGrid1DBBandedTableView1OUT_RASHODKOL
            end
            item
              Kind = skSum
              FieldName = 'OUT_RASHODKOL_FISED'
              Column = cxGrid1DBBandedTableView1OUT_RASHODKOL_FISED
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsData.Deleting = False
          OptionsData.DeletingConfirmation = False
          OptionsData.Editing = False
          OptionsData.Inserting = False
          OptionsSelection.InvertSelect = False
          OptionsView.ColumnAutoWidth = True
          OptionsView.Footer = True
          OptionsView.RowSeparatorWidth = 2
          Styles.Footer = cxStyle7
          Styles.Header = cxStyle7
          Bands = <
            item
            end>
          object cxGrid1DBBandedTableView1OUT_NAMEPOST: TcxGridDBBandedColumn
            Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082
            DataBinding.FieldName = 'OUT_NAMEPOST'
            Width = 177
            Position.BandIndex = 0
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object cxGrid1DBBandedTableView1OUT_NAME_PRODUCER: TcxGridDBBandedColumn
            Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100
            DataBinding.FieldName = 'OUT_NAME_PRODUCER'
            Width = 188
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object cxGrid1DBBandedTableView1OUT_NACHOSTKOL: TcxGridDBBandedColumn
            Caption = #1053#1072#1095'. '#1086#1089#1090#1072#1090#1086#1082' ('#1073#1072#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_NACHOSTKOL'
            Width = 98
            Position.BandIndex = 0
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object cxGrid1DBBandedTableView1OUT_PRIHODKOL: TcxGridDBBandedColumn
            Caption = #1055#1088#1080#1093#1086#1076' ('#1073#1072#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_PRIHODKOL'
            Width = 98
            Position.BandIndex = 0
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object cxGrid1DBBandedTableView1OUT_RASHODKOL: TcxGridDBBandedColumn
            Caption = #1056#1072#1089#1093#1086#1076' ('#1073#1072#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_RASHODKOL'
            Width = 101
            Position.BandIndex = 0
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object cxGrid1DBBandedTableView1OUT_CONOSTKOL: TcxGridDBBandedColumn
            Caption = #1050#1086#1085'. '#1086#1089#1090#1072#1090#1086#1082' ('#1073#1072#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_CONOSTKOL'
            Width = 101
            Position.BandIndex = 0
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object cxGrid1DBBandedTableView1OUT_NACHOSTKOL_FISED: TcxGridDBBandedColumn
            Caption = #1053#1072#1095'. '#1086#1089#1090#1072#1090#1086#1082' ('#1092#1080#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_NACHOSTKOL_FISED'
            Width = 98
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 1
          end
          object cxGrid1DBBandedTableView1OUT_PRIHODKOL_FISED: TcxGridDBBandedColumn
            Caption = #1055#1088#1080#1093#1086#1076' ('#1092#1080#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_PRIHODKOL_FISED'
            Width = 98
            Position.BandIndex = 0
            Position.ColIndex = 2
            Position.RowIndex = 1
          end
          object cxGrid1DBBandedTableView1OUT_RASHODKOL_FISED: TcxGridDBBandedColumn
            Caption = #1056#1072#1089#1093#1086#1076' ('#1092#1080#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_RASHODKOL_FISED'
            Width = 101
            Position.BandIndex = 0
            Position.ColIndex = 3
            Position.RowIndex = 1
          end
          object cxGrid1DBBandedTableView1OUT_CONOSTKOL_FISED: TcxGridDBBandedColumn
            Caption = #1050#1086#1085'. '#1086#1089#1090#1072#1090#1086#1082' ('#1092#1080#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_CONOSTKOL_FISED'
            Width = 101
            Position.BandIndex = 0
            Position.ColIndex = 4
            Position.RowIndex = 1
          end
          object cxGrid1DBBandedTableView1Column1: TcxGridDBBandedColumn
            Width = 365
            Position.BandIndex = 0
            Position.ColIndex = 0
            Position.RowIndex = 1
          end
        end
        object cxGrid1Level1: TcxGridLevel
          GridView = cxGrid1DBBandedTableView1
        end
      end
    end
    object cxTabSheet2: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1086#1081
      ImageIndex = 1
      object cxGrid2: TcxGrid
        Left = 0
        Top = 0
        Width = 1217
        Height = 494
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        TabOrder = 0
        object cxGrid2DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
        end
        object cxGrid2DBBandedTableView1: TcxGridDBBandedTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.DataSource = DataSourceReportPoNom
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <
            item
              Kind = skSum
              FieldName = 'OUT_CONOSTKOL'
              Column = cxGrid2DBBandedTableView1OUT_CONOSTKOL
            end
            item
              Kind = skSum
              FieldName = 'OUT_CONOSTKOL_FISED'
              Column = cxGrid2DBBandedTableView1OUT_CONOSTKOL_FISED
            end
            item
              Kind = skSum
              FieldName = 'OUT_NACHOSTKOL'
              Column = cxGrid2DBBandedTableView1OUT_NACHOSTKOL
            end
            item
              Kind = skSum
              FieldName = 'OUT_NACHOSTKOL_FISED'
              Column = cxGrid2DBBandedTableView1OUT_NACHOSTKOL_FISED
            end
            item
              Kind = skSum
              FieldName = 'OUT_PRIHODKOL'
              Column = cxGrid2DBBandedTableView1OUT_PRIHODKOL
            end
            item
              Kind = skSum
              FieldName = 'OUT_PRIHODKOL_FISED'
              Column = cxGrid2DBBandedTableView1OUT_PRIHODKOL_FISED
            end
            item
              Kind = skSum
              FieldName = 'OUT_RASHODKOL'
              Column = cxGrid2DBBandedTableView1OUT_RASHODKOL
            end
            item
              Kind = skSum
              FieldName = 'OUT_RASHODKOL_FISED'
              Column = cxGrid2DBBandedTableView1OUT_RASHODKOL_FISED
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsData.CancelOnExit = False
          OptionsData.Deleting = False
          OptionsData.DeletingConfirmation = False
          OptionsData.Editing = False
          OptionsData.Inserting = False
          OptionsSelection.InvertSelect = False
          OptionsView.ColumnAutoWidth = True
          OptionsView.Footer = True
          OptionsView.RowSeparatorWidth = 2
          Styles.Footer = cxStyle7
          Styles.Header = cxStyle7
          Bands = <
            item
              Caption = #1054#1090#1095#1077#1090
            end>
          object cxGrid2DBBandedTableView1OUT_NAMEPOST: TcxGridDBBandedColumn
            Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082
            DataBinding.FieldName = 'OUT_NAMEPOST'
            Visible = False
            GroupIndex = 0
            Width = 129
            Position.BandIndex = 0
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1OUT_NAME_PRODUCER: TcxGridDBBandedColumn
            Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100
            DataBinding.FieldName = 'OUT_NAME_PRODUCER'
            Visible = False
            GroupIndex = 1
            Width = 128
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1OUT_NAMENOM: TcxGridDBBandedColumn
            Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
            DataBinding.FieldName = 'OUT_NAMENOM'
            Width = 128
            Position.BandIndex = 0
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1OUT_NACHOSTKOL: TcxGridDBBandedColumn
            Caption = #1053#1072#1095'. '#1086#1089#1090#1072#1090#1086#1082' ('#1073#1072#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_NACHOSTKOL'
            Width = 59
            Position.BandIndex = 0
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1OUT_PRIHODKOL: TcxGridDBBandedColumn
            Caption = #1055#1088#1080#1093#1086#1076' ('#1073#1072#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_PRIHODKOL'
            Width = 61
            Position.BandIndex = 0
            Position.ColIndex = 6
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1OUT_RASHODKOL: TcxGridDBBandedColumn
            Caption = #1056#1072#1089#1093#1086#1076' ('#1073#1072#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_RASHODKOL'
            Width = 61
            Position.BandIndex = 0
            Position.ColIndex = 7
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1OUT_CONOSTKOL: TcxGridDBBandedColumn
            Caption = #1050#1086#1085'. '#1086#1089#1090#1086#1090#1086#1082' ('#1073#1072#1079'.'#1077#1076'.)L'
            DataBinding.FieldName = 'OUT_CONOSTKOL'
            Width = 61
            Position.BandIndex = 0
            Position.ColIndex = 8
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1OUT_NAME_BASEED: TcxGridDBBandedColumn
            Caption = #1041#1072#1079'.'#1077#1076
            DataBinding.FieldName = 'OUT_NAME_BASEED'
            Width = 75
            Position.BandIndex = 0
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1OUT_KF2_BASEED: TcxGridDBBandedColumn
            Caption = #1050#1060'2 '#1073#1072#1079'.'#1077#1076
            DataBinding.FieldName = 'OUT_KF2_BASEED'
            Width = 61
            Position.BandIndex = 0
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1OUT_NAME_FISED: TcxGridDBBandedColumn
            Caption = #1060#1080#1079'.'#1077#1076
            DataBinding.FieldName = 'OUT_NAME_FISED'
            Width = 106
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 1
          end
          object cxGrid2DBBandedTableView1OUT_KF2_FISED: TcxGridDBBandedColumn
            Caption = #1050#1060'2 '#1092#1080#1079'.'#1077#1076'.'
            DataBinding.FieldName = 'OUT_KF2_FISED'
            Width = 86
            Position.BandIndex = 0
            Position.ColIndex = 2
            Position.RowIndex = 1
          end
          object cxGrid2DBBandedTableView1OUT_NACHOSTKOL_FISED: TcxGridDBBandedColumn
            Caption = #1053#1072#1095'. '#1086#1089#1090#1072#1090#1086#1082' ('#1092#1080#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_NACHOSTKOL_FISED'
            Width = 84
            Position.BandIndex = 0
            Position.ColIndex = 3
            Position.RowIndex = 1
          end
          object cxGrid2DBBandedTableView1OUT_PRIHODKOL_FISED: TcxGridDBBandedColumn
            Caption = #1055#1088#1080#1093#1086#1076' ('#1092#1080#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_PRIHODKOL_FISED'
            Width = 85
            Position.BandIndex = 0
            Position.ColIndex = 4
            Position.RowIndex = 1
          end
          object cxGrid2DBBandedTableView1OUT_RASHODKOL_FISED: TcxGridDBBandedColumn
            Caption = #1056#1072#1089#1093#1086#1076' ('#1092#1080#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_RASHODKOL_FISED'
            Width = 87
            Position.BandIndex = 0
            Position.ColIndex = 5
            Position.RowIndex = 1
          end
          object cxGrid2DBBandedTableView1OUT_CONOSTKOL_FISED: TcxGridDBBandedColumn
            Caption = #1050#1086#1085'.'#1086#1089#1090#1072#1090#1086#1082' ('#1092#1080#1079'.'#1077#1076'.)'
            DataBinding.FieldName = 'OUT_CONOSTKOL_FISED'
            Width = 86
            Position.BandIndex = 0
            Position.ColIndex = 6
            Position.RowIndex = 1
          end
          object cxGrid2DBBandedTableView1Column1: TcxGridDBBandedColumn
            Width = 195
            Position.BandIndex = 0
            Position.ColIndex = 0
            Position.RowIndex = 1
          end
        end
        object cxGrid2Level1: TcxGridLevel
          GridView = cxGrid2DBBandedTableView1
        end
      end
    end
    object cxTabSheet3: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072
      ImageIndex = 2
      object Label6: TLabel
        Left = 679
        Top = 4
        Width = 58
        Height = 18
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1043#1088#1091#1087#1087#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label7: TLabel
        Left = 679
        Top = 64
        Width = 95
        Height = 18
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object GroupBox1: TGroupBox
        Left = 4
        Top = 136
        Width = 311
        Height = 347
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1040#1083#1082#1086#1075#1086#1083#1100#1085#1099#1077' '#1075#1088#1091#1087#1087#1099
        TabOrder = 0
        object ToolBar2: TToolBar
          Left = 2
          Top = 19
          Width = 307
          Height = 22
          Caption = 'ToolBar2'
          EdgeBorders = [ebLeft]
          Images = imgStandart
          TabOrder = 0
          object ToolButton10: TToolButton
            Left = 0
            Top = 0
            Width = 8
            Caption = 'ToolButton10'
            ImageIndex = 3
            Style = tbsSeparator
          end
          object AlcGrpAddToolButton: TToolButton
            Left = 8
            Top = 0
            Caption = 'AlcGrpAddToolButton'
            ImageIndex = 19
            OnClick = AlcGrpAddToolButtonClick
          end
          object AlcGrpDeleteToolButton: TToolButton
            Left = 31
            Top = 0
            Caption = 'AlcGrpDeleteToolButton'
            ImageIndex = 21
            OnClick = AlcGrpDeleteToolButtonClick
          end
          object AlcGrpRefreshToolButton: TToolButton
            Left = 54
            Top = 0
            Caption = 'AlcGrpRefreshToolButton'
            ImageIndex = 23
            OnClick = AlcGrpRefreshToolButtonClick
          end
        end
        object AlcGrpcxGrid: TcxGrid
          Left = 2
          Top = 41
          Width = 307
          Height = 304
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Align = alClient
          TabOrder = 1
          object AlcGrpcxGridDBTableView1: TcxGridDBTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
          end
          object AlcGrpcxGridTableView1: TcxGridTableView
            NavigatorButtons.ConfirmDelete = False
            OnCellClick = AlcGrpcxGridTableView1CellClick
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsView.ColumnAutoWidth = True
            OptionsView.GroupByBox = False
            object AlcGrpcxGridTableView1NAME: TcxGridColumn
              Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
              Width = 165
            end
          end
          object AlcGrpcxGridLevel1: TcxGridLevel
            GridView = AlcGrpcxGridTableView1
          end
        end
      end
      object TovGrpGroupBox: TGroupBox
        Left = 320
        Top = 136
        Width = 312
        Height = 347
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1058#1086#1074#1072#1088#1085#1099#1077' '#1075#1088#1091#1087#1087#1099
        TabOrder = 1
        object ToolBar3: TToolBar
          Left = 2
          Top = 19
          Width = 308
          Height = 22
          Caption = 'ToolBar2'
          EdgeBorders = [ebLeft]
          Images = imgStandart
          TabOrder = 0
          object ToolButton5: TToolButton
            Left = 0
            Top = 0
            Width = 8
            Caption = 'ToolButton10'
            ImageIndex = 3
            Style = tbsSeparator
          end
          object TovGrpAddToolButton: TToolButton
            Left = 8
            Top = 0
            Caption = 'AlcGrpAddToolButton'
            ImageIndex = 19
            OnClick = TovGrpAddToolButtonClick
          end
          object TovGrpDeleteToolButton: TToolButton
            Left = 31
            Top = 0
            Caption = 'AlcGrpDeleteToolButton'
            ImageIndex = 21
            OnClick = TovGrpDeleteToolButtonClick
          end
          object TovGrpSaveToolButton: TToolButton
            Left = 54
            Top = 0
            Caption = 'AlcGrpSaveToolButton'
            ImageIndex = 2
            OnClick = TovGrpSaveToolButtonClick
          end
          object TovGrpRefreshToolButton: TToolButton
            Left = 77
            Top = 0
            Caption = 'AlcGrpRefreshToolButton'
            ImageIndex = 23
            OnClick = TovGrpRefreshToolButtonClick
          end
        end
        object TovGrpcxGrid: TcxGrid
          Left = 2
          Top = 41
          Width = 308
          Height = 304
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Align = alClient
          TabOrder = 1
          object cxGridDBTableView1: TcxGridDBTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
          end
          object cxGridTableView1: TcxGridTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsView.ColumnAutoWidth = True
            OptionsView.GroupByBox = False
            object cxGridColumn1: TcxGridColumn
              Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
              Width = 165
            end
          end
          object TovGrpcxGridTableView1: TcxGridTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsView.ColumnAutoWidth = True
            OptionsView.GroupByBox = False
            object TovGrpcxGridTableView1NAME: TcxGridColumn
              Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
              Width = 159
            end
            object TovGrpcxGridTableView1ID: TcxGridColumn
              Caption = 'ID'
              Width = 73
            end
          end
          object TovGrpcxGridLevel1: TcxGridLevel
            GridView = TovGrpcxGridTableView1
          end
        end
      end
      object cxLookupComboBox1: TcxLookupComboBox
        Left = 679
        Top = 29
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Properties.DropDownListStyle = lsFixedList
        Properties.KeyFieldNames = 'IDGRPKL'
        Properties.ListColumns = <
          item
            FieldName = 'NAMEGRPKL'
          end>
        Properties.ListSource = DataSourceGrpKlient
        Properties.OnValidate = cxLookupComboBox1PropertiesValidate
        EditValue = 0
        TabOrder = 2
        Width = 257
      end
      object NameKlientcxLookupComboBox: TcxLookupComboBox
        Left = 679
        Top = 89
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Properties.DropDownListStyle = lsFixedList
        Properties.KeyFieldNames = 'IDKLIENT'
        Properties.ListColumns = <
          item
            FieldName = 'NAMEKLIENT'
          end>
        Properties.ListSource = DataSourceSpisokKlient
        TabOrder = 3
        Width = 257
      end
      object GroupBox2: TGroupBox
        Left = 642
        Top = 136
        Width = 311
        Height = 347
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1080' '#1086#1073#1083#1072#1089#1090#1080
        TabOrder = 4
        object ToolBar4: TToolBar
          Left = 2
          Top = 19
          Width = 307
          Height = 22
          Caption = 'ToolBar2'
          EdgeBorders = [ebLeft]
          Images = imgStandart
          TabOrder = 0
          object ToolButton7: TToolButton
            Left = 0
            Top = 0
            Width = 8
            Caption = 'ToolButton10'
            ImageIndex = 3
            Style = tbsSeparator
          end
          object ProducerAddToolButton: TToolButton
            Left = 8
            Top = 0
            Caption = 'AlcGrpAddToolButton'
            ImageIndex = 19
            OnClick = ProducerAddToolButtonClick
          end
          object ProducerDeleteToolButton: TToolButton
            Left = 31
            Top = 0
            Caption = 'AlcGrpDeleteToolButton'
            ImageIndex = 21
            OnClick = ProducerDeleteToolButtonClick
          end
          object ProducerSaveToolButton: TToolButton
            Left = 54
            Top = 0
            Caption = 'AlcGrpSaveToolButton'
            ImageIndex = 2
            OnClick = ProducerSaveToolButtonClick
          end
          object ProducerRefreshToolButton: TToolButton
            Left = 77
            Top = 0
            Caption = 'AlcGrpRefreshToolButton'
            ImageIndex = 23
            OnClick = ProducerRefreshToolButtonClick
          end
        end
        object ProducercxGrid: TcxGrid
          Left = 2
          Top = 41
          Width = 307
          Height = 304
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Align = alClient
          TabOrder = 1
          object cxGridDBTableView2: TcxGridDBTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
          end
          object cxGridTableView2: TcxGridTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsView.ColumnAutoWidth = True
            OptionsView.GroupByBox = False
            object cxGridColumn2: TcxGridColumn
              Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
              Width = 165
            end
          end
          object ProducercxGridTableView: TcxGridTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsView.ColumnAutoWidth = True
            OptionsView.GroupByBox = False
            object ProducercxGridTableViewID: TcxGridColumn
              Caption = 'ID'
              Width = 44
            end
            object ProducercxGridTableViewNAME: TcxGridColumn
              Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
              Width = 188
            end
          end
          object ProducercxGridLevel1: TcxGridLevel
            GridView = ProducercxGridTableView
          end
        end
      end
      object GroupBox3: TGroupBox
        Left = 961
        Top = 136
        Width = 311
        Height = 347
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082#1080' '#1086#1073#1083#1072#1089#1090#1080
        TabOrder = 5
        object ToolBar5: TToolBar
          Left = 2
          Top = 19
          Width = 307
          Height = 22
          Caption = 'ToolBar2'
          EdgeBorders = [ebLeft]
          Images = imgStandart
          TabOrder = 0
          object ToolButton8: TToolButton
            Left = 0
            Top = 0
            Width = 8
            Caption = 'ToolButton10'
            ImageIndex = 3
            Style = tbsSeparator
          end
          object ToolButton9: TToolButton
            Left = 8
            Top = 0
            Caption = 'AlcGrpAddToolButton'
            ImageIndex = 19
            OnClick = ToolButton9Click
          end
          object ToolButton11: TToolButton
            Left = 31
            Top = 0
            Caption = 'AlcGrpDeleteToolButton'
            ImageIndex = 21
            OnClick = ToolButton11Click
          end
          object ToolButton12: TToolButton
            Left = 54
            Top = 0
            Caption = 'AlcGrpSaveToolButton'
            ImageIndex = 2
            OnClick = ToolButton12Click
          end
          object ToolButton13: TToolButton
            Left = 77
            Top = 0
            Caption = 'AlcGrpRefreshToolButton'
            ImageIndex = 23
            OnClick = ToolButton13Click
          end
        end
        object PostcxGrid: TcxGrid
          Left = 2
          Top = 41
          Width = 307
          Height = 304
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Align = alClient
          TabOrder = 1
          object cxGridDBTableView3: TcxGridDBTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
          end
          object cxGridTableView3: TcxGridTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsView.ColumnAutoWidth = True
            OptionsView.GroupByBox = False
            object cxGridColumn3: TcxGridColumn
              Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
              Width = 165
            end
          end
          object PostcxGridTableView: TcxGridTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsView.ColumnAutoWidth = True
            OptionsView.GroupByBox = False
            object PostcxGridTableViewID: TcxGridColumn
              Caption = 'ID'
              Width = 75
            end
            object PostcxGridTableViewNAME: TcxGridColumn
              Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
              Width = 157
            end
          end
          object PostcxGridLevel: TcxGridLevel
            GridView = PostcxGridTableView
          end
        end
      end
    end
    object cxTabSheet4: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1072#1079#1076#1077#1083' 1'
      ImageIndex = 3
      object Rasdel1cxGrid: TcxGrid
        Left = 0
        Top = 0
        Width = 1217
        Height = 494
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        TabOrder = 0
        object Rasdel1cxGridDBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
        end
        object Rasdel1cxGridTableView1: TcxGridTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <
            item
              Format = '0.000'
              Kind = skSum
              Column = Rasdel1cxGridTableView1CONOST
            end
            item
              Format = '0.000'
              Kind = skSum
              Column = Rasdel1cxGridTableView1FISED_CONOST
            end
            item
              Format = '0.000'
              Kind = skSum
              Column = Rasdel1cxGridTableView1FISED_NACHOST
            end
            item
              Format = '0.000'
              Kind = skSum
              Column = Rasdel1cxGridTableView1FISED_PRIHOD
            end
            item
              Format = '0.000'
              Kind = skSum
              Column = Rasdel1cxGridTableView1FISED_RASHOD
            end
            item
              Format = '0.000'
              Kind = skSum
              Column = Rasdel1cxGridTableView1PRIHOD
            end
            item
              Format = '0.000'
              Kind = skSum
              Column = Rasdel1cxGridTableView1RASHOD
            end
            item
              Format = '0.000'
              Kind = skSum
              Column = Rasdel1cxGridTableView1NACHOST
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsCustomize.ColumnHiding = True
          OptionsCustomize.ColumnsQuickCustomization = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.Footer = True
          OptionsView.GroupByBox = False
          Styles.Content = cxStyle8
          Styles.Footer = cxStyle7
          object Rasdel1cxGridTableView1NAMEGRP: TcxGridColumn
            Caption = #1042#1080#1076' '#1087#1088#1086#1076#1091#1082#1094#1080#1080
            Width = 194
          end
          object Rasdel1cxGridTableView1NACHOST: TcxGridColumn
            Caption = #1054#1089#1090'. '#1085#1072' '#1085#1072#1095'. '#1073#1091#1090'.'
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Properties.DisplayFormat = '0.000'
            FooterAlignmentHorz = taRightJustify
            Width = 102
          end
          object Rasdel1cxGridTableView1FISED_NACHOST: TcxGridColumn
            Caption = #1054#1089#1090'. '#1085#1072' '#1085#1072#1095'. '#1083#1080#1090#1088
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Properties.DisplayFormat = '0.000'
            FooterAlignmentHorz = taRightJustify
            Width = 91
          end
          object Rasdel1cxGridTableView1PRIHOD: TcxGridColumn
            Caption = #1055#1088#1080#1093#1086#1076' '#1073#1091#1090'.'
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Properties.DisplayFormat = '0.000'
            FooterAlignmentHorz = taRightJustify
            Width = 90
          end
          object Rasdel1cxGridTableView1FISED_PRIHOD: TcxGridColumn
            Caption = #1055#1088#1080#1093#1086#1076' '#1083#1080#1090#1088
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Properties.DisplayFormat = '0.000'
            FooterAlignmentHorz = taRightJustify
            Width = 90
          end
          object Rasdel1cxGridTableView1RASHOD: TcxGridColumn
            Caption = #1056#1072#1089#1093#1086#1076' '#1073#1091#1090'.'
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Properties.DisplayFormat = '0.000'
            FooterAlignmentHorz = taRightJustify
            Width = 90
          end
          object Rasdel1cxGridTableView1FISED_RASHOD: TcxGridColumn
            Caption = #1056#1072#1089#1093#1086#1076' '#1083#1080#1090#1088
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Properties.DisplayFormat = '0.000'
            FooterAlignmentHorz = taRightJustify
            Width = 91
          end
          object Rasdel1cxGridTableView1CONOST: TcxGridColumn
            Caption = #1050#1086#1085'. '#1086#1089#1090'. '#1073#1091#1090'.'
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Properties.DisplayFormat = '0.000'
            FooterAlignmentHorz = taRightJustify
            Width = 90
          end
          object Rasdel1cxGridTableView1FISED_CONOST: TcxGridColumn
            Caption = #1050#1086#1085'. '#1086#1089#1090'. '#1083#1080#1090#1088
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Properties.DisplayFormat = '0.000'
            FooterAlignmentHorz = taRightJustify
            Width = 91
          end
        end
        object Rasdel1cxGridLevel1: TcxGridLevel
          GridView = Rasdel1cxGridTableView1
        end
      end
    end
    object cxTabSheet5: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1072#1079#1076#1077#1083' 2'
      ImageIndex = 4
      object Rasdel2cxGrid: TcxGrid
        Left = 0
        Top = 0
        Width = 1217
        Height = 494
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        TabOrder = 0
        object Rasdel2cxGridDBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
        end
        object Rasdel2cxGridTableView1: TcxGridTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <
            item
              Kind = skSum
              Column = Rasdel2cxGridTableView1FISED_PRIHOD
            end
            item
              Kind = skSum
              Column = Rasdel2cxGridTableView1PRIHOD
            end>
          DataController.Summary.FooterSummaryItems = <
            item
              Kind = skSum
              Column = Rasdel2cxGridTableView1FISED_PRIHOD
            end
            item
              Kind = skSum
              Column = Rasdel2cxGridTableView1PRIHOD
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsCustomize.ColumnsQuickCustomization = True
          OptionsSelection.InvertSelect = False
          OptionsView.ColumnAutoWidth = True
          OptionsView.Footer = True
          OptionsView.GroupRowStyle = grsOffice11
          OptionsView.GroupSummaryLayout = gslAlignWithColumnsAndDistribute
          OptionsView.Indicator = True
          object Rasdel2cxGridTableView1NAMEGRP: TcxGridColumn
            Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1075#1088#1091#1087#1087#1099
          end
          object Rasdel2cxGridTableView1NAME_POST: TcxGridColumn
            Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082
          end
          object Rasdel2cxGridTableView1IDPOST: TcxGridColumn
            Caption = 'ID '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072
          end
          object Rasdel2cxGridTableView1NAME_PRODUCER: TcxGridColumn
            Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100
          end
          object Rasdel2cxGridTableView1IDPRODUCER: TcxGridColumn
            Caption = 'ID '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103
          end
          object Rasdel2cxGridTableView1PRIHOD: TcxGridColumn
            Caption = #1055#1088#1080#1093#1086#1076' '#1073#1072#1079'. '#1077#1076'.'
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            FooterAlignmentHorz = taRightJustify
            GroupSummaryAlignment = taRightJustify
          end
          object Rasdel2cxGridTableView1FISED_PRIHOD: TcxGridColumn
            Caption = #1055#1088#1080#1093#1086#1076' '#1092#1080#1079'. '#1077#1076'.'
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Alignment.Horz = taRightJustify
            FooterAlignmentHorz = taRightJustify
            GroupSummaryAlignment = taRightJustify
          end
          object Rasdel2cxGridTableView1OBL_PRODUCERPOST: TcxGridColumn
          end
          object Rasdel2cxGridTableView1OBL_POST: TcxGridColumn
          end
        end
        object Rasdel2cxGridLevel1: TcxGridLevel
          GridView = Rasdel2cxGridTableView1
        end
      end
    end
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 72
    Top = 408
    PixelsPerInch = 120
    object cxStyle1: TcxStyle
      AssignedValues = [svColor, svFont]
      Color = clMaroon
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
    end
    object cxStyle2: TcxStyle
      AssignedValues = [svFont, svTextColor]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clNavy
    end
    object cxStyle3: TcxStyle
      AssignedValues = [svFont, svTextColor]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clTeal
    end
    object cxStyle4: TcxStyle
      AssignedValues = [svTextColor]
      TextColor = clNavy
    end
    object cxStyle5: TcxStyle
      AssignedValues = [svFont, svTextColor]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clMaroon
    end
    object cxStyle6: TcxStyle
      AssignedValues = [svTextColor]
      TextColor = clMaroon
    end
    object cxStyle7: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
    end
    object cxStyle8: TcxStyle
      AssignedValues = [svFont]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
    end
  end
  object imgStandart: TImageList
    Left = 104
    Top = 408
    Bitmap = {
      494C010118001C00140010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000007000000001002000000000000070
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000D7D6D5008E6D4D00A6672900BE6A1700CE6F0F00D17A
      1900C36B1400AE69240092694100A7A09A000000000000000000000000000000
      00000000000000000000E9E9E900927A6300A06F3F00B16F2B00BE702200C179
      2A00B66F2800A56F370093735400B3AFAB000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000004B464100585046005950
      4600595146005952460059524600595346005953460059544600595546005955
      4600585546005350440000000000000000000000000000000000000000000000
      00000000000000000000978E8600AD570000DB6E0000F2790000FD800100FF8C
      0D00F57B0000E3720000BB5E000067431D000000000000000000000000000000
      00000000000000000000B1ADA900A9550000D96D0000F1790000FD7F0100FF8E
      0F00F57B0000E3730000BB5E000068431D000000000000000000000000000000
      0000663D10000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000053504400F9B97900FDBD
      7800FDC17700FFCA7D00FDCA7800FDCE7800FDD27800FDD67800FDDB7800FDDE
      7800FBE17700D6C36C0000000000000000000000000000000000000000000000
      00000000000000000000978F8700AD570000DB6E0000F2790000FD800100FF8C
      0D00F57B0000E3720000BB5E000068431E000000000000000000000000000000
      00000000000000000000B2AEAA00A9550000D96D0000F1790000FD7F0100FF8E
      0F00F57B0000E3730000BB5E000068431E000000000000000000000000000000
      0000FFCF01000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000053504400FBC69100FFC0
      8200FFB97F0066B52F00FFCB7D00FFCE8000FFD07A00FCD17700FFD67900FFD9
      7900FDDD7800D8C16D0000000000000000000000000000000000000000000000
      00000000000000000000978F8700AD570000DB6E0000F2790000FD800100FF8C
      0D00F57B0000E3720000BB5E000068431E000000000000000000000000000000
      00000000000000000000B2AEAA00A9550000D96D0000F1790000FD7F0100FF8E
      0F00F57B0000E3730000BB5E000068431E00000000000000000000000000896F
      6000F9BF0100CB930100F9BF0100F9BF0100F9BF0100E2A901007A4A00000000
      0000000000000000000000000000000000000000000053504400FBD1A500FBCC
      98008EA54D0006D1040000DC010000D8000014C20A00C4B25D00FED37900FFD5
      7900FDD77800D8BD6D0000000000000000000000000000000000000000000000
      0000000000000000000098908800AE580000DD6F0000F67B0000FF820100FF8F
      0D00F97D0000E6730000BC5F000068431E000000000000000000000000000000
      00000000000000000000B2AEAA00AA550000DB6E0000F47A0000FF810100FF90
      0F00F87C0000E6740000BC5F000068431E00000000000000000000000000AD5D
      0100DF7E0100DF7E0100DF7E0100DF7E0100DF7E0100DF7E0100DF7E0100DF7E
      0100643B20000000000000000000000000000000000053504400FADAB700FEDB
      B600029C030000AD080000AE080000B0080001B0090004B609004B932500FCD2
      7A00FDD17800D8B76D000000000000000000918F8D006E665F0061564A005C4E
      3F00685344005D4F410048362400522A00003D1F00002C160000271400002814
      00002B16000032190000402204006D5D4D000000000000000000000000000000
      00000000000000000000C3C1C00085410000A8530000B95C0000C2610100C56C
      0A00BB5E0000AA5600008D47000061472D00000000000000000000000000C43D
      0100C43E0300C43F0300C5400600C7420800C7440B00C8470E00C94A1200CA4D
      1600CB511A006832180000000000000000000000000053504400F9E1C800EDD3
      B200006C010000730B0000730A00E3B37800D3A86400477F270000750C00A39D
      4D00FBCA7700D8B36D000000000000000000A7948100B79D8300BD9E8000BE9E
      7F00DEB39100BE9E7F00BD9F8100B79D8400A08E7C0000000000000000000000
      0000000000000000000000000000000000009493B8008F8FB4008E8EB3008E8E
      B3008E8EB3008E8EB3008F8EB400918FB4008887AA00BF6B1D00FD7F0100FF8E
      0F00F57B0000E3730000BC5E000068431D00A08B7F000000000078381A00D36D
      4800D4724F00D6785500D87D5C004C1E0500000000000000000072524000A363
      4800E29E8600E4A48D007D615000000000000000000053504400FAE8D600FFE9
      D200FFE3C800F4D4B000CFB98C00848D5500FEC88F00FCBD7C00E6B36E000044
      0700FFCF8000D8AE6D000000000000000000A4907E0084846600938F6D009591
      6E00AA9E7A0095916E0093906E008E8D6E0081856C009AA89A0099A79900919E
      910000000000000000000000000000000000B0AFDB00C8C7FB00C6C5F900C6C5
      F900C6C5F900C6C5F900C6C5F900C6C5F900B2B2E100BC691B00FD7F0100FF8E
      0F00F57B0000E3730000BB5E000068431E00E8B7010000000000AC998F007D61
      50006D442C009A756200C9ADA100F9EDE80066442E0000000000000000000000
      0000A08B7F00F3F1EF00F3F1EF00000000000000000053504400EEE6D500FFF0
      DF00FEE9D400FEE3C900FDDDBB00FBD6AE00FFD1A300FFC99300FBBE8100DBAC
      6800FEC07800D7A96C000000000000000000A18E7A00A78E72009EC6A2008AAF
      8A008FB58F008FB58F008FB58F008FB68F008FB58F0080A28000A5CCA400EFEF
      EF0000000000000000000000000000000000BFBEED00B9B8E800B9B8E800B9B8
      E800B9B8E800B9B8E800B8B7E800B1B4E800B0B5EA00BA681B00FD7F0100FF8E
      0F00F57B0000E3730000BB5E000068431E007D520000F3C30100000000000000
      000000000000000000004E271000724C2000957E7000957E7000000000000000
      00000000000000000000DCD4CF00957E70000000000053504400DFDDCF0058B3
      4D00FFF4E400FEEAD600FEE6CD00FFE7D300FFDFC000FFD7AE00FFCF9B00FDC3
      8900FCBC7A00D7A46D000000000000000000A18E7A00B3987D009387650086A7
      8600C8FDC800C3F6C300C3F6C300C3F6C300C8FCC80090B38F00AFB2AF000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000AFACAA00A34F0000D3670000F2790000FF800100FF8F
      0F00F67C0000E4730000BB5E000068431E0000000000FCC70100FCC701007046
      10000000000000000000000000007D615000FCC70100FCC70100FCC70100FCC7
      0100CD990100896F60000000000066442F000000000053504400FEFBFA0005BA
      06002FAD2B00F9E5DF00FFF5E9004FAA430000CF000004B5060029A31B00FED1
      A700FDC79000D8A472000000000000000000806D5900725B43006F553F0085A7
      860090B69000C4F8C400C3F6C300C5F9C50089AE890087906800A68F7900A792
      7A00A6937F00A89B8E00B5B0AC00EFEFEF00D5D4D400AEA7A000A7978700A690
      7B00A5927900A68F79008D7258008A4600006B3600005A2E0000572C0000582E
      0200592D00005E2F00006433000060472D0000000000704B3000E4890100E489
      0100E4890100BA6A0100914D0100BA6A0100E4890100E4890100E4890100E489
      0100E489010000000000000000005A3520000000000053504400F9F6F400ECE9
      E500009C000000A10000009E0400009F010000A2090000A0090011901200FEDC
      B700FDD2A500D8AF85000000000000000000000000000000000000000000FDFD
      FD00B7DEB600ACD9AC00C4F6C400A9D5A9009CC7A300FA780000FF810200FF8D
      0C00F77C0000E4730000BD5F00006844200085430000CB660000EC760000FB7D
      0000FF981800FC7E0000EF780000D1690000984C000000000000000000000000
      0000000000000000000000000000000000000000000000000000602E1000CB4B
      0100CB4B0100CB4B0100CB4B0100CB4B0100CB4C0200CB4D0400CC4F0600CC51
      0900683211000000000000000000000000000000000053504400FAF9F800FDFA
      F800F1EFEC00066C0C000070070000730B000071080002770F00C3C59E00FFE9
      CA00FFE4BF00DFBC990000000000000000000000000000000000000000000000
      0000D9DAD900C1ECC000BBEDBB00B7E7BF00D3680000F2790000FE800200FF8C
      0C00F57B0000E2720000BA5E00006A48250082420000C9650000EA750000F97C
      0000FF971800FA7D0000ED770000CF680000954B000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000A08B
      7F00AA4C2700D1684100D36E4900D5745100D77B5A00D9826200DB896B00DD90
      7300000000000000000000000000000000000000000053504400FBFAF900FEFD
      FC00FEFBFA00FFFFFF00FFFAF800D9DCCC00FFF7EF0009511100403F3F00BEB4
      A200BCB7AF007A7B7C0000000000000000000000000000000000000000000000
      00000000000098A09800CFFCCE008E662800DC6F0000F2790000FE800200FF8C
      0C00F57B0000E2720000BA5E00006A48250082420000C9650000EA750000F97C
      0000FF971800FA7D0000ED770000CF680000954B000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000B8A89F00704F3C006E4731006F49330072524000A0897C00AC98
      8C00000000000000000000000000000000000000000053504400FBFAFB00FFFF
      FD00FFFCFC00FFFCFB00FFFCF900FDF9F500FEF8F200E1E4D3003F3F3E00FAF1
      E400C8C8C7000000000000000000000000000000000000000000000000000000
      00000000000000000000707D6500AF560000DC6F0000F2790000FE800200FF8C
      0C00F57B0000E2720000BA5E00006A48250082420000C9650000EA750000F97C
      0000FF971800FA7D0000ED770000CF680000954B000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007D604F00957E
      7000000000000000000000000000000000000000000053504400FBFBFB00FFFE
      FE00FFFEFE00FFFDFC00FFFDFC00FFFBFA00FFFBF800FDFEFA003F3F3F00D7D6
      D500000000000000000000000000000000000000000000000000000000000000
      000000000000000000009C928A008C470000954B0000954A0000944B0100944F
      0400944A0000944B00008F480000624221006D37000086440000864300008542
      000085490700854200008643000087440000793D000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000A08B7F000000
      0000000000000000000000000000000000000000000053504400FBFBFB00FFFF
      FF00FFFFFE00FFFEFE00FFFEFD00FFFDFD00FFFCFB00FFFFFF003F3F3F000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF0003030300FFFFFF00FFFFFF0003030300FFFFFF00FFFFFF000303
      0300FFFFFF00FFFFFF0003030300FFFFFF0000000000642A0300642A0300642A
      0300642A0300642A0300642A0300000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000EBEAEA00947F6A009D714500AD703300B8712A00BB79
      2F00B2712F00A4713E0094775B00B3AEAA000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF000303030000000000642A0300ECCA86008586
      FF00ECCA8600ECCA8600642A0300996C24000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000ADA7A200AB550000DA6E0000F0790000FD7F0100FF8D
      0D00F67B0000E4730000BD5F0000653A0E000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00CEE4F000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000382339003F2BFC004746
      DA00696CF40000000000642A03009E7733000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000AFA9A400AA550000DA6E0000F0790000FD7F0100FF8D
      0D00F67B0000E4730000BD5F0000653B0F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00077FAF002CA4CD00ACD3E500FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0097969F00361DEB0044379F007470
      99002514B5004A44EB00642A0300A9864C000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000006274
      6200576657005A6A5900837E7500AA550000DA6E0000F0790000FD7F0100FF8D
      0D00F67B0000E4730000BD5F0000653B0F000000000000000000000000000000
      0000DEDEDE009AA59A006B7D6B00516B51007C917C0000000000000000000000
      000000000000000000000000000000000000000000000000000000000000AADD
      F3006BF8FF0049CEE8007DFFFF001884B500FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0003030300190D870044379F007469AF000000
      0000000000001C0CA3004746DA009E7733000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000A5CB
      A300D4FFD100C0ECBD007D786F00AB550000DC6F0000F37A0000FF800100FF8F
      0D00F97C0000E6740000BE600000653B0F0000000000000000004D674D00003D
      0000005100000361030003690300046C04002179220000000000000000000000
      0000000000000000000000000000000000000000000000000000000000001FAD
      D3001997C70053DFF6005CE4F70053D6F1001F96C100E5F0F700FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000642A03008E7A54000000
      000000000000000000002921BA003D43C1000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000A1C8
      A000CFFFCC00BCE7B9008B87820086410000A9530000B85C0000C2620100C46B
      0800BB5E0000AA5600008E4700005C3D1F00000000000D330400027202000189
      0100009500000097000000950000019401001B9A1C000000000000000000C6C8
      CD00737C950030417200626777000000000000000000000000002081BE0023B4
      DC0041D9F40028ADD30026AAD10051DCF30061E8FB0061E4F40099CDE200FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000085551500855515008555
      15008555150085551500855515002C24CB002514B50000000000000000000000
      0000000000000000000000000000000000006078600061796000617960009DC2
      9B00CFFFCC00BBE6B8005F775F00627961005F776100BB680E00FD7F0100FF8D
      0D00F67B0000E4730000BE5F0000653A0E007570660029691200018E01000B8C
      0B0021A621002EBD2E0033C8340037CD38003E9E52001A2D600016296400192E
      6E001F3678001F377F001528600000000000000000003745B3000A44D4001A5D
      AF000C8DBD002FC4E4003FD7F10033BDDF0050DCF3005CE5F60077FFFF003C9E
      C500FFFFFF00FFFFFF00FFFFFF00030303000000000000000000000000000000
      000000000000000000000000000000000000190D8700D7D6E000000000000000
      000000000000000000000000000000000000B0D9AE00D1FFCE00D1FFCE00D0FF
      CD00CFFFCC00CFFFCC00D1FFCE00D1FFCE00CAFAC900B9660B00FD7F0100FF8D
      0D00F67B0000E4730000BD5F0000653B0F008C807100605C26006CC1630043D9
      490030D2330034CD32003DD33C0042DC40001F3973001E367C00213B8500243E
      8C00233F9300223F9E0024429E0000000000E3E4F4000B54EE000B45DF000B4F
      EA002B30A6001BBADA001294C50023A8D70041DAF4001697C7002FB3D800FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000642A0300642A0300642A
      0300642A0300642A0300642A0300000000000000000000000000000000000000
      000000000000000000000000000000000000B3DDB100D2FFCF00D2FFCF00CEFE
      CB00CFFFCC00CFFFCC00D1FFCF00D0FFCF00C9FACA00B9660C00FD7F0100FF8D
      0D00F67B0000E4730000BD5F0000653B0F00A99080009E6E3900A06F3800A166
      35009D613D00907F55007ABC6A0065F267001A2E91002343A800335ACD004473
      F000497CFF004074FF003060F60000000000000000001834B1000E47F2000D4C
      F3000C4BF5001529AE001A98CB002BC3E900108DC00035CAEA00EFF4F900FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000642A0300ECCA86006669
      CC00ECCA8600ECCA8600642A0300A17427000000000000000000000000000000
      000000000000000000000000000000000000C8CAC800C8CAC800C7C8C7009CC2
      9B00CFFFCC00BAE6B80068655B00894B0800AE5E0800E5760300FF800100FF8E
      0D00F77C0000E5730000BD5F0000653B0F0000000000986532009B6835009F6C
      3900A3703D00A8784300AD7D4600AB6E34006295FF005082FF004274FD00396B
      FE003366FE003366FF004170FD000000000000000000000000001742C2000E4F
      FD000E4FFE000E4FFB001057FA001A4AA80025D0ED00C1DFE900FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF000303030000000000642A03004538FA005251
      F1005154C20000000000642A0300A27937000000000034343400343434003434
      340034343400000000003434340000000000CDCCCC00ACA39C00A69484009CC3
      9E00CFFFCC00BBE7B900745B3E008B4600006A350000582C0000552B0000542C
      0200572B00005C2F0000623100005A3D200000000000E6DAD0009A6836009965
      3200A06D3B00A4723F00A9764300AB78450096623E00356AFE003366FF003466
      FF002B5FFF007093FF00000000000000000000000000000000001B2CA2000E4B
      FF001978FF000866FD000A7AFB000CA0FF002234AA00FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF0000000000FFFFFF0000000000321BE5003422A7008C86
      B6003427D9003D3CB700642A0300A78245000000000000000000000000000000
      0000000000000000000000000000000000008E470000CE670000ED7500008EBA
      9A00C4F3C400B0DDB200C26A0B00D0690000954A000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000D1BAA300B48D6600AF835500B1825300B58A5D007377B5007A9AFC00CAD7
      FF0000000000000000000000000000000000000000004C5DBA000D58FF001C78
      ED00808ACF00194BBD001BB9FF001836AE000000000000000000000000000000
      0000000000000000000000000000000000001C0CA3003422A7009590D4000000
      0000000000002915CE003639A300A78245000000000000000000000000000000
      0000000000000000000000000000000000008B460000CC660000EB760000C26C
      0F00C9822000C56E0F00E1740400CE6800009249000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C9CCEA000D72FF0018A0FF008691
      D10000000000000000008C96D500000000000000000000000000000000000000
      000000000000000000000000000000000000000000006852660089754A000000
      00000000000000000000382FD4002E2E8F000000000000000000000000000000
      0000000000000000000000000000000000008B460000CC660000EB760000F97C
      0000FF981800F97D0000EC770000CE6800009249000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001345C8000F8AFB001E24A1000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000642A0300642A0300642A
      030057220100642A030076320000382FD400190D870000000000000000000000
      0000000000000000000000000000000000008B460000CC660000EB760000FA7C
      0000FF991800FA7D0000EC770000CE6800009249000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001C9DF4001842BA00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000BFA88A00B7955E00B795
      5E00B7955E00B7955E00B7955E00B7955E002514B500A09FAA00000000000000
      0000000000000000000000000000000000007038000082410000814000007F40
      00007F4606007F3F00008140000082410000743A000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000A5636B00A563
      6B00A5636B00A5636B00A5636B00A5636B00A5636B00A5636B00A5636B00A563
      6B00A5636B00A5636B00A5636B00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000B5948400FFEF
      C60039525200EFD6AD0039525200EFCE9400EFC68C00EFBD8400EFC67B00EFBD
      840039525200EFC68400A5636B00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000008B340C000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C0000000
      0000C0C0C0000000000000000000000000000000000000000000B59484003952
      5200395252003952520039525200395252003952520039525200395252003952
      52003952520039525200A5636B0000000000000000000000000096543F009C64
      2E00EB91560000000000878D7100319300003CC33600000000009EA4D0000007
      F7005151FE00000000000000000000000000000000000000000077475B000000
      00000000000000000000000000000000000000000000000000000003BE009393
      E000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000C0C0C00000000000000000000000000000000000B5948C00FFEF
      DE0039525200F7DEBD0039525200EFCEA500EFCE9C00EFC69400EFC68C00EFBD
      840039525200EFC68400A5636B000000000000000000000000009A5640009C65
      3300F09C5F0000000000878E6F003593030044CA3F000000000098A0D000040D
      F5005656FE0000000000000000000000000000000000000000009A5E5A000000
      0000000000000000000000000000000000000000000000000000575DFE000000
      00000000000000000000000000000000000000000000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C00000FFFF0000FFFF0000FFFF00C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000BD948C00FFF7
      E70039525200F7DEC600F7DEBD00EFD6AD00EFCEA500EFCE9C00EFC69400EFC6
      8C00EFBD8400EFC68400A5636B000000000000000000000000009A5640009C65
      3200F09C5F0000000000868D6E003594030044CA3F0000000000979FCF00040D
      F5005757FE00000000000000000000000000000000000000000096443100A25F
      A7009A239B000000000000000000000000000000000000000000000000000000
      00003333BE005252BA005B5BF4000000000000000000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000808080008080800080808000C0C0C000C0C0
      C00000000000C0C0C00000000000000000000000000000000000C69C9400FFF7
      EF0039525200F7E7CE00F7DEC600F7DEBD00EFD6AD00EFCEA500EFCE9C00EFC6
      9400EFC68C00EFC68400A5636B000000000000000000000000009A5640009C65
      3200F09C5F0000000000868D6E003594030044CA3F0000000000989FCF00040D
      F5005757FE00000000000000000000000000000000000000000092412F000000
      00008B078B000000000000000000000000000000000000000000000000000000
      00006F6FCA007D7DFF009E9EFD00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000C0C0C000C0C0C000000000000000000000000000C6A59C00FFFF
      FF0039525200F7EFDE00F7E7CE00F7DEC600F7DEBD00EFD6AD00EFCEA500EFCE
      9C00EFC69400EFC68C00A5636B000000000000000000000000009A5640009C65
      3200F09C5F0000000000868D6E003594030044CA3F0000000000959DCD00090E
      E9004748F20000000000000000000000000000000000000000008E3D30000000
      0000B87EB800D697D60000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C0000000
      0000C0C0C00000000000C0C0C000000000000000000000000000CEAD9C00FFFF
      FF0039525200FFEFE700F7EFDE00F7E7CE00F7DEC600F7DEBD00EFD6AD00EFCE
      A500EFCE9C00EFCE9400A5636B000000000000000000000000009A5640009C65
      3200F09C5F0000000000868D6E003594030044CA3F0000000000000000008589
      EF008589EF0000000000000000000000000000000000000000008B3A30000000
      000000000000A827A80000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0C0
      C00000000000C0C0C00000000000000000000000000000000000CEAD9C00FFFF
      FF0039525200FFF7EF00FFEFE700F7EFDE00F7E7CE00F7DEC600F7DEBD00EFD6
      AD00EFCEA500F7D6A500A5636B000000000000000000000000009A5640009C65
      3200F09C5F0000000000868D6E003594030044CA3F0000000000000000000000
      0000000000000000000000000000000000000000000000000000873630000000
      000000000000930B930000000000000000000000000076087600BF62BF00A837
      A80000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000C0C0C00000000000C0C0C000000000000000000000000000D6B5A500FFFF
      FF0039525200FFFFFF00FFF7EF00FFEFE700F7EFDE00F7E7CE00F7DEC600F7D6
      B500F7D6AD00EFCEA500A5636B000000000000000000000000009A5640009C65
      3200F09C5F0000000000878F7000348F030044CA3F0000000000000000000000
      0000000000000000000000000000000000000000000000000000843330000000
      000000000000993799000000000000000000780F7800F7EBF700000000009710
      9700000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF000000000000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000D6B5A500FFFF
      FF0039525200FFFFFF00FFFFFF00FFF7EF00FFEFE700FFE7D600F7E7CE00F7E7
      CE00DECEB500B5AD9400A5636B000000000000000000000000009A5640009C65
      3200F09C5F00000000009EAA8D00389706005BCB550000000000000000000000
      00000000000000000000000000000000000000000000000000006D130D000000
      0000000000000000000092009200A033A000F2DEF2000000000000000000880A
      8800000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000DEB5A500FFFF
      FF0039525200FFFFFF00FFFFFF00FFFFFF00FFF7EF00FFEFE700EFDECE00B58C
      7B00A57B6B009C736300A5636B000000000000000000000000009A5640009C65
      3200F09C5F000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000007A423D007E272C000000
      0000000000000000000000000000000000000000000000000000000000009F4C
      9F00000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF000000000000000000000000000000000000000000FFFF
      FF00000000000000000000000000000000000000000000000000E7BDA500FFFF
      FF0039525200FFFFFF00FFFFFF00FFFFFF00FFFFF700FFFFF700DEC6BD00AD73
      5A00E79C5200E78C3100B56B4A00000000000000000000000000995640009D65
      3300F09B5E000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000009A5C72000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000B446B4000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000E7BDA5003952
      52003952520039525200FFFFFF00FFFFFF00FFFFFF00FFFFFF00DEC6C600BD84
      6300FFB55A00BD7B5A000000000000000000000000000000000094513E009257
      2C00DE854E000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00009C6147000000000000000000000000000000000000000000000000000000
      00008C008C000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E7BDA500F7F7
      EF0039525200F7F7EF00F7F7EF00F7F7EF00F7F7EF00F7F7EF00DEC6BD00B57B
      6300C6846B00000000000000000000000000000000000000000000000000C39F
      8600DBB8A6000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000B4745400A1471B0000000000000000000000000000000000000000000000
      000000000000C976C90000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000EFC6AD00EFCE
      B500EFCEB500E7C6B500E7C6B500E7C6B500E7C6B500E7C6B500E7C6B500A56B
      5A00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000008400
      0000840000008400000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0084000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008400000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      0000000000008080800000000000000000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0084000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008400000000000000000000000000000000000000808080000000
      0000000000000000000000000000000000008080800000000000000000000000
      0000000000000000000080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000080808000C0C0C000C0C0
      C000808080000000000080808000000000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0084000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008400000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000004D4D
      4D004D4D4D004D4D4D004D4D4D004D4D4D004D4D4D004D4D4D004D4D4D004D4D
      4D00000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF000000000080808000C0C0C000C0C0C000FFFF
      0000808080008080800000000000000000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0084000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008400000000000000000000000000000000000000808080000000
      0000000000000000000000000000000000008080800000000000000000000000
      0000000000000000000080808000000000000000000000000000000000000000
      00004D4D4D004D4D4D0000000000000000000000000000000000000000004D4D
      4D00000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000C0C0C000C0C0C000C0C0C000C0C0
      C00080808000C0C0C00000000000000000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0084000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008400000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000004D4D4D004D4D4D00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000C0C0C000FFFF0000C0C0C000C0C0
      C00080808000C0C0C00000000000000000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0084000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008400000000000000000000000000000000000000808080000000
      0000808080000000000080808000000000008080800000000000808080000000
      0000808080000000000080808000000000000000000000000000000000000000
      000000000000000000004D4D4D004D4D4D000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF000000000080808000FFFF0000FFFF0000C0C0
      C000808080008080800000000000000000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0084000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008400000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000004D4D4D004D4D4D0000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000080808000C0C0C000C0C0
      C000808080000000000000000000000000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0084000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008400000000000000000000000000000000000000808080000000
      0000000000000000000000000000000000008080800000000000000000000000
      0000000000000000000080808000000000000000000000000000000000000000
      000000000000000000004D4D4D004D4D4D000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0084000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008400000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000004D4D4D004D4D4D00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000008400
      0000840000008400000000000000000000000000000000000000808080000000
      0000000000000000000000000000000000008080800000000000000000000000
      0000000000000000000080808000000000000000000000000000000000000000
      00004D4D4D004D4D4D0000000000000000000000000000000000000000004D4D
      4D00000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000084000000840000008400
      00008400000084000000FFFFFF00840000008400000084000000840000008400
      0000FFFFFF008400000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000004D4D
      4D004D4D4D004D4D4D004D4D4D004D4D4D004D4D4D004D4D4D004D4D4D004D4D
      4D00000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000C0C0C0000000
      0000000000000000000000000000000000000000000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000008400
      0000840000008400000000000000000000000000000000000000808080000000
      0000808080000000000080808000000000008080800000000000808080000000
      0000808080000000000080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000084000000840000008400000084000000840000008400
      0000840000008400000084000000840000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000084000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00840000000000000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000008400
      0000840000008400000000000000000000000000000000000000000000000000
      0000000000000000000080000000800000008000000080000000800000008000
      0000800000008000000080000000000000000000000000000000000000000000
      0000000000000000000080000000800000008000000080000000800000008000
      0000800000008000000080000000800000000000000000000000000000000000
      0000000000000000000084000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00840000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008400000000000000000000000000000000000000000000000000
      0000000000000000000080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0080000000000000000000000000000000000000000000
      0000000000000000000080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00800000000000000000000000000000000000
      0000000000000000000084000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00840000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008400000000000000000000000000000000000000000000000000
      0000000000000000000080000000FFFFFF000000000000000000000000000000
      000000000000FFFFFF0080000000000000000000000080808000008080008080
      8000008080008080800080000000FFFFFF008000000080000000800000008000
      00008000000080000000FFFFFF00800000000000000000000000000000008400
      0000840000008400000084000000840000008400000084000000840000008400
      0000840000008400000084000000840000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008400000000000000000000000000000000000000000000000000
      0000000000000000000080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0080000000000000000000000000808000808080000080
      8000808080000080800080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00800000000000000000000000000000008400
      0000FFFFFF00FFFFFF0084000000840000008400000084000000840000008400
      00008400000084000000FFFFFF00840000000000000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000008400
      00008400000084000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0080000000FFFFFF000000000000000000000000000000
      000000000000FFFFFF0080000000000000000000000080808000008080008080
      8000008080008080800080000000FFFFFF00800000008000000080000000FFFF
      FF00800000008000000080000000800000000000000000000000000000008400
      0000FFFFFF00FFFFFF0084000000840000008400000084000000840000008400
      0000840000008400000084000000840000000000000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000008400
      0000FFFFFF0084000000000000000000000000000000FFFFFF00000000000000
      0000000000000000000080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0080000000000000000000000000808000808080000080
      8000808080000080800080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0080000000FFFFFF0080000000000000000000000000000000000000008400
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00840000000000000000000000000000000000000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000008400
      00008400000084000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0080000000FFFFFF000000000000000000FFFFFF008000
      0000800000008000000080000000000000000000000080808000008080008080
      8000008080008080800080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00800000008000000000000000000000000000000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000008400
      0000840000000000000000000000000000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0084000000000000000000000000000000FFFFFF00000000000000
      0000000000000000000080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF008000
      0000FFFFFF008000000000000000000000000000000000808000808080000080
      8000808080000080800080000000800000008000000080000000800000008000
      0000800000000000000000000000000000000000000084000000FFFFFF008400
      000084000000840000008400000084000000840000008400000084000000FFFF
      FF00840000000000000000000000000000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0084000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0080000000FFFFFF00FFFFFF00FFFFFF00FFFFFF008000
      0000800000000000000000000000000000000000000080808000008080008080
      8000008080008080800000808000808080000080800080808000008080008080
      8000008080000000000000000000000000000000000084000000FFFFFF008400
      0000840000008400000084000000840000008400000084000000840000008400
      0000840000000000000000000000000000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0084000000000000000000000000000000FFFFFF00000000000000
      0000FFFFFF000000000080000000800000008000000080000000800000008000
      0000000000000000000000000000000000000000000000808000808080000000
      0000000000000000000000000000000000000000000000000000000000008080
      8000808080000000000000000000000000000000000084000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00840000000000
      0000000000000000000000000000000000000000000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000008400
      00008400000084000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000808080000000
      0000000000000000000000000000000000000000000000000000000000008080
      8000008080000000000000000000000000000000000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000000000
      0000000000000000000000000000000000000000000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000008400
      0000FFFFFF0084000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000808000808080000080
      80000000000000FFFF00000000000000000000FFFF0000000000808080000080
      8000808080000000000000000000000000000000000084000000840000008400
      00008400000084000000840000008400000084000000FFFFFF00840000000000
      0000000000000000000000000000000000000000000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000008400
      0000840000008400000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000FFFF0000FFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000084000000840000008400
      0000840000008400000084000000840000008400000084000000840000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000800000008000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000008080000080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000008000
      0000000000000000000080000000000000000000000080000000800000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000008080000080
      8000008080000080800000808000008080000080800000808000008080000000
      0000000000000000000000000000000000000000000000000000008080000080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000008000
      0000000000000000000080000000000000008000000000000000000000008000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000FFFF00000000000080
      8000008080000080800000808000008080000080800000808000008080000080
      8000000000000000000000000000000000000000000000000000008080000080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000008000
      0000000000000000000080000000000000008000000000000000000000008000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000000000000000000000000000FFFFFF0000FFFF000000
      0000008080000080800000808000008080000080800000808000008080000080
      8000008080000000000000000000000000000000000000000000008080000080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000000000
      0000800000008000000080000000000000008000000000000000000000008000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000FFFF00FFFFFF0000FF
      FF00000000000080800000808000008080000080800000808000008080000080
      8000008080000080800000000000000000000000000000000000008080000080
      8000008080000080800000808000008080000080800000808000008080000080
      8000008080000080800000000000000000000000000000000000000000000000
      0000000000000000000080000000000000008000000080000000800000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000000000000000000000000000FFFFFF0000FFFF00FFFF
      FF0000FFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000008080000080
      8000000000000000000000000000000000000000000000000000000000000000
      0000008080000080800000000000000000000000000000000000000000000000
      0000000000000000000080000000000000008000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000FFFF00FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00000000000000
      0000000000000000000000000000000000000000000000000000008080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000000000000000000000000000FFFFFF0000FFFF00FFFF
      FF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000008080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000FFFF00FFFFFF0000FF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000008080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000008080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000008080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000008080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000700000000100010000000000800300000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FC00FC00FFFF8003FC00FC00F7FF8003
      FC00FC00F7FF8003FC00FC00E01F8003FC00FC00E00780030000FC00E0038003
      007F000040C18003000F000040718003000F00003C3C8003001FFC008E028003
      0000000080068003E000007FC0078003F000007FE00F8003F800007FF80F8007
      FC00007FFFCF800FFC00007FFFDF801FFFFFE00081FFFC00FFFFE00080FFFC00
      FFFFE0008484FC00FFFFE00000FFE000F07FE0001890E000C07FE0009CFFE000
      8061C000807F000000018000FF3F00000001000081FF00000001800080FF0000
      8001C000848400008003C00080FF007FF00F80FF1890007FFFFF0DFF9CFF007F
      FFFF1FFF807F007FFFFF3FFF803F007FFFFFC001FFFFFFFFC007C001FFFFDFFF
      8003C001C447DFCF0001C001C447DFDF0001C001C447C7F10001C001C447D7F1
      0000C001C447D3FF0000C001C467DBFF8000C001C47FDB8FC000C001C47FDB2F
      E001C001C47FDC6FE007C001C7FF9FEFF007C001C7FFDFF7F003C003C7FFF7F7
      F803C007E7FFF3FBFFFFC00FFFFFFFFFFFFFFFFFFFFF80068003C001FFFF8004
      8003FFFFFFFF80008003DF7DFFFF80018003FFFFE00F80018003DF7DF3EF8001
      8003FFFFF9FF80018003D555FCFF80018003FFFFFE7F80038003DF7DFCFF8007
      8003FFFFF9FF80078003DF7DF3EF80078003FFFFE00F800F8003D555FFFF801F
      FFFFFFFFFFFF803FFFFFFFFFFFFFFFFFFFFFFFFFFC00FFFFFFFFFFFFFC008003
      FC01FC00FC008003FC018000FC008003FC010000E000800300010000E0008003
      00010000E000800300010001E007800300010003800780030003000380078003
      0007000380078003000F0003801F800300FF0FC3801F800301FF0003801F8003
      03FF8007801FFFFFFFFFF87FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC001F3FF
      C007001F8031ED9FC007000F8031ED6FC00700078031ED6FC00700038001F16F
      C00700018001FD1FC00700008001FC7FC007001F8FF1FEFFC007001F8FF1FC7F
      C007001F8FF1FD7FC0078FF18FF1F93FC00FFFF98FF1FBBFC01FFF758FF5FBBF
      C03FFF8F8001FBBFFFFFFFFFFFFFFFFF00000000000000000000000000000000
      000000000000}
  end
  object ActionList1: TActionList
    Images = imgStandart
    Left = 168
    Top = 408
    object ActionPrint: TAction
      Caption = 'ActionPrint'
      ImageIndex = 12
      OnExecute = ActionPrintExecute
    end
    object ActionPreeView: TAction
      Caption = 'ActionPreeView'
      ImageIndex = 11
      OnExecute = ActionPreeViewExecute
    end
    object ActionPageSetup: TAction
      Caption = 'ActionPageSetup'
      ImageIndex = 13
      OnExecute = ActionPageSetupExecute
    end
    object ActionExportExcel: TAction
      Caption = 'ActionExportExcel'
      ImageIndex = 2
      OnExecute = ActionExportExcelExecute
    end
    object ActionCheckAll: TAction
      Caption = 'ActionCheckAll'
      Hint = #1042#1099#1076#1077#1083#1080#1090#1100' '#1074#1089#1077' '#1101#1083#1077#1084#1077#1085#1090#1099
      ImageIndex = 18
    end
    object ActionClearAll: TAction
      Caption = 'ActionClearAll'
      Hint = #1054#1095#1080#1090#1080#1090#1100' '#1074#1099#1076#1077#1083#1077#1085#1080#1077
      ImageIndex = 17
    end
    object ActionShowGrafikPoday: TAction
      Caption = 'ActionShowGrafikPoday'
      Hint = #1043#1088#1072#1092#1080#1082' '#1087#1086' '#1076#1085#1103#1084
      ImageIndex = 15
    end
    object ActionShowDiagramm: TAction
      Caption = 'ActionShowDiagramm'
      Hint = #1044#1080#1072#1075#1088#1072#1084#1084#1072
      ImageIndex = 16
    end
  end
  object dxComponentPrinter1: TdxComponentPrinter
    CurrentLink = dxComponentPrinter1Link2
    Version = 0
    Left = 40
    Top = 408
    object dxComponentPrinter1Link1: TdxGridReportLink
      Active = True
      Component = cxGrid1
      PrinterPage.DMPaper = 1
      PrinterPage.Footer = 6350
      PrinterPage.Header = 6350
      PrinterPage.Margins.Bottom = 12700
      PrinterPage.Margins.Left = 12700
      PrinterPage.Margins.Right = 12700
      PrinterPage.Margins.Top = 12700
      PrinterPage.PageSize.X = 215900
      PrinterPage.PageSize.Y = 279400
      PrinterPage._dxMeasurementUnits_ = 0
      PrinterPage._dxLastMU_ = 2
      ReportDocument.CreationDate = 40673.676112627310000000
      OptionsSize.AutoWidth = True
      BuiltInReportLink = True
    end
    object dxComponentPrinter1Link2: TdxGridReportLink
      Active = True
      Component = cxGrid2
      PrinterPage.DMPaper = 1
      PrinterPage.Footer = 6350
      PrinterPage.Header = 6350
      PrinterPage.Margins.Bottom = 12700
      PrinterPage.Margins.Left = 12700
      PrinterPage.Margins.Right = 12700
      PrinterPage.Margins.Top = 12700
      PrinterPage.PageSize.X = 215900
      PrinterPage.PageSize.Y = 279400
      PrinterPage._dxMeasurementUnits_ = 0
      PrinterPage._dxLastMU_ = 2
      ReportDocument.CreationDate = 40673.676112650460000000
      OptionsSize.AutoWidth = True
      BuiltInReportLink = True
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 136
    Top = 408
  end
  object ReportDataSet: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      'from '
      
        'REPORT_PO_GRPNOM_S_POST_REPORT2(:PARAM_POSNACH,:PARAM_POSCON,:PA' +
        'RAM_IDFIRM,:PARAM_IDSKLAD,:PARAM_IDGRP)')
    Left = 360
    Top = 400
    poUseLargeIntField = True
    object ReportDataSetOUT_NAMEPOST: TFIBWideStringField
      FieldName = 'OUT_NAMEPOST'
      Size = 200
    end
    object ReportDataSetOUT_IDPOST: TFIBLargeIntField
      FieldName = 'OUT_IDPOST'
    end
    object ReportDataSetOUT_NAME_PRODUCER: TFIBWideStringField
      FieldName = 'OUT_NAME_PRODUCER'
      Size = 200
    end
    object ReportDataSetOUT_IDPRODUCER: TFIBLargeIntField
      FieldName = 'OUT_IDPRODUCER'
    end
    object ReportDataSetOUT_NACHOSTKOL: TFIBBCDField
      FieldName = 'OUT_NACHOSTKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportDataSetOUT_PRIHODKOL: TFIBBCDField
      FieldName = 'OUT_PRIHODKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportDataSetOUT_RASHODKOL: TFIBBCDField
      FieldName = 'OUT_RASHODKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportDataSetOUT_CONOSTKOL: TFIBBCDField
      FieldName = 'OUT_CONOSTKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportDataSetOUT_NACHOSTKOL_FISED: TFIBBCDField
      FieldName = 'OUT_NACHOSTKOL_FISED'
      Size = 3
      RoundByScale = True
    end
    object ReportDataSetOUT_PRIHODKOL_FISED: TFIBBCDField
      FieldName = 'OUT_PRIHODKOL_FISED'
      Size = 3
      RoundByScale = True
    end
    object ReportDataSetOUT_RASHODKOL_FISED: TFIBBCDField
      FieldName = 'OUT_RASHODKOL_FISED'
      Size = 3
      RoundByScale = True
    end
    object ReportDataSetOUT_CONOSTKOL_FISED: TFIBBCDField
      FieldName = 'OUT_CONOSTKOL_FISED'
      Size = 3
      RoundByScale = True
    end
  end
  object pFIBTransaction1: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 48
    Top = 496
  end
  object DataSourceReport: TDataSource
    DataSet = ReportDataSet
    Left = 320
    Top = 400
  end
  object SpisokFirm: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '   IDFIRM,'
      '   NAMEFIRM'
      'from '
      '   SFIRM'
      'order by NAMEFIRM')
    Left = 192
    Top = 64
    poUseLargeIntField = True
    object SpisokFirmIDFIRM: TFIBLargeIntField
      FieldName = 'IDFIRM'
    end
    object SpisokFirmNAMEFIRM: TFIBWideStringField
      FieldName = 'NAMEFIRM'
      Size = 200
    end
  end
  object SpisokSklad: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '   IDSKLAD,'
      '   NAMESKLAD'
      'from'
      '   SSKLAD'
      'order by NAMESKLAD')
    Left = 440
    Top = 64
    poUseLargeIntField = True
    object SpisokSkladIDSKLAD: TFIBLargeIntField
      FieldName = 'IDSKLAD'
    end
    object SpisokSkladNAMESKLAD: TFIBWideStringField
      FieldName = 'NAMESKLAD'
      Size = 200
    end
  end
  object SpisokGrp: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '   IDGN,'
      '   NAMEGN'
      'from'
      '   SGRPNOM'
      'order by NAMEGN')
    Left = 664
    Top = 64
    poUseLargeIntField = True
    object SpisokGrpIDGN: TFIBLargeIntField
      FieldName = 'IDGN'
    end
    object SpisokGrpNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 200
    end
  end
  object DataSourceFirma: TDataSource
    DataSet = SpisokFirm
    Left = 160
    Top = 64
  end
  object DataSourceSklad: TDataSource
    DataSet = SpisokSklad
    Left = 416
    Top = 64
  end
  object DataSourceGrp: TDataSource
    DataSet = SpisokGrp
    Left = 632
    Top = 64
  end
  object ReportPoNom: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      'from '
      
        'REPORT_PO_GRPNOM_S_POST_REPORT(:PARAM_POSNACH,:PARAM_POSCON,:PAR' +
        'AM_IDFIRM,:PARAM_IDSKLAD,:PARAM_IDGRP)')
    Left = 560
    Top = 496
    poUseLargeIntField = True
    object ReportPoNomOUT_NAMEPOST: TFIBWideStringField
      FieldName = 'OUT_NAMEPOST'
      Size = 200
    end
    object ReportPoNomOUT_IDPOST: TFIBLargeIntField
      FieldName = 'OUT_IDPOST'
    end
    object ReportPoNomOUT_NAME_PRODUCER: TFIBWideStringField
      FieldName = 'OUT_NAME_PRODUCER'
      Size = 200
    end
    object ReportPoNomOUT_IDPRODUCER: TFIBLargeIntField
      FieldName = 'OUT_IDPRODUCER'
    end
    object ReportPoNomOUT_NAMENOM: TFIBWideStringField
      FieldName = 'OUT_NAMENOM'
      Size = 200
    end
    object ReportPoNomOUT_IDNOM: TFIBLargeIntField
      FieldName = 'OUT_IDNOM'
    end
    object ReportPoNomOUT_NACHOSTKOL: TFIBBCDField
      FieldName = 'OUT_NACHOSTKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportPoNomOUT_PRIHODKOL: TFIBBCDField
      FieldName = 'OUT_PRIHODKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportPoNomOUT_RASHODKOL: TFIBBCDField
      FieldName = 'OUT_RASHODKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportPoNomOUT_CONOSTKOL: TFIBBCDField
      FieldName = 'OUT_CONOSTKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportPoNomOUT_NAME_BASEED: TFIBWideStringField
      FieldName = 'OUT_NAME_BASEED'
      Size = 200
    end
    object ReportPoNomOUT_KF2_BASEED: TFIBBCDField
      FieldName = 'OUT_KF2_BASEED'
      Size = 3
      RoundByScale = True
    end
    object ReportPoNomOUT_NAME_FISED: TFIBWideStringField
      FieldName = 'OUT_NAME_FISED'
      Size = 200
    end
    object ReportPoNomOUT_KF2_FISED: TFIBBCDField
      FieldName = 'OUT_KF2_FISED'
      Size = 3
      RoundByScale = True
    end
    object ReportPoNomOUT_NACHOSTKOL_FISED: TFIBBCDField
      FieldName = 'OUT_NACHOSTKOL_FISED'
      Size = 3
      RoundByScale = True
    end
    object ReportPoNomOUT_PRIHODKOL_FISED: TFIBBCDField
      FieldName = 'OUT_PRIHODKOL_FISED'
      Size = 3
      RoundByScale = True
    end
    object ReportPoNomOUT_RASHODKOL_FISED: TFIBBCDField
      FieldName = 'OUT_RASHODKOL_FISED'
      Size = 3
      RoundByScale = True
    end
    object ReportPoNomOUT_CONOSTKOL_FISED: TFIBBCDField
      FieldName = 'OUT_CONOSTKOL_FISED'
      Size = 3
      RoundByScale = True
    end
  end
  object DataSourceReportPoNom: TDataSource
    DataSet = ReportPoNom
    Left = 528
    Top = 496
  end
  object GrpDataSet: TpFIBDataSet
    SelectSQL.Strings = (
      'select NAMEGN'
      'from SGRPNOM'
      'where IDGN=:PARAM_IDGRP')
    Left = 384
    Top = 224
    poUseLargeIntField = True
    object GrpDataSetNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 200
    end
  end
  object SpisokGrpKlient: TpFIBDataSet
    SelectSQL.Strings = (
      'select IDGRPKL, NAMEGRPKL '
      'from SGRPKL'
      'order by NAMEGRPKL')
    Left = 608
    Top = 152
    poUseLargeIntField = True
    object SpisokGrpKlientIDGRPKL: TFIBLargeIntField
      FieldName = 'IDGRPKL'
    end
    object SpisokGrpKlientNAMEGRPKL: TFIBWideStringField
      FieldName = 'NAMEGRPKL'
      Size = 200
    end
  end
  object SpisokKlient: TpFIBDataSet
    SelectSQL.Strings = (
      'select IDKLIENT, NAMEKLIENT'
      'from SKLIENT'
      'where IDGRPKLIENT=:PARAM_IDGRP'
      'order by NAMEKLIENT')
    Left = 624
    Top = 184
    poUseLargeIntField = True
    object SpisokKlientIDKLIENT: TFIBLargeIntField
      FieldName = 'IDKLIENT'
    end
    object SpisokKlientNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
  end
  object DataSourceSpisokKlient: TDataSource
    DataSet = SpisokKlient
    Left = 568
    Top = 184
  end
  object DataSourceGrpKlient: TDataSource
    DataSet = SpisokGrpKlient
    Left = 560
    Top = 152
  end
  object KlientDataSet: TpFIBDataSet
    SelectSQL.Strings = (
      'select NAMEKLIENT'
      'from SKLIENT'
      'where IDKLIENT=:PARAM_ID')
    Left = 656
    Top = 296
    poUseLargeIntField = True
    object KlientDataSetNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
  end
  object ReportRasdel1: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      'from '
      
        'REPORT_PO_GRPNOM_S_POST_REPORT2(:PARAM_POSNACH,:PARAM_POSCON,:PA' +
        'RAM_IDFIRM,:PARAM_IDSKLAD,:PARAM_IDGRP)')
    Left = 896
    Top = 312
    poUseLargeIntField = True
    object ReportRasdel1OUT_NAMEPOST: TFIBWideStringField
      FieldName = 'OUT_NAMEPOST'
      Size = 200
    end
    object ReportRasdel1OUT_IDPOST: TFIBLargeIntField
      FieldName = 'OUT_IDPOST'
    end
    object ReportRasdel1OUT_NAME_PRODUCER: TFIBWideStringField
      FieldName = 'OUT_NAME_PRODUCER'
      Size = 200
    end
    object ReportRasdel1OUT_IDPRODUCER: TFIBLargeIntField
      FieldName = 'OUT_IDPRODUCER'
    end
    object ReportRasdel1OUT_NACHOSTKOL: TFIBBCDField
      FieldName = 'OUT_NACHOSTKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportRasdel1OUT_PRIHODKOL: TFIBBCDField
      FieldName = 'OUT_PRIHODKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportRasdel1OUT_RASHODKOL: TFIBBCDField
      FieldName = 'OUT_RASHODKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportRasdel1OUT_CONOSTKOL: TFIBBCDField
      FieldName = 'OUT_CONOSTKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportRasdel1OUT_NACHOSTKOL_FISED: TFIBBCDField
      FieldName = 'OUT_NACHOSTKOL_FISED'
      Size = 3
      RoundByScale = True
    end
    object ReportRasdel1OUT_PRIHODKOL_FISED: TFIBBCDField
      FieldName = 'OUT_PRIHODKOL_FISED'
      Size = 3
      RoundByScale = True
    end
    object ReportRasdel1OUT_RASHODKOL_FISED: TFIBBCDField
      FieldName = 'OUT_RASHODKOL_FISED'
      Size = 3
      RoundByScale = True
    end
    object ReportRasdel1OUT_CONOSTKOL_FISED: TFIBBCDField
      FieldName = 'OUT_CONOSTKOL_FISED'
      Size = 3
      RoundByScale = True
    end
  end
  object ReportRasdel2: TpFIBDataSet
    SelectSQL.Strings = (
      'select *'
      'from '
      
        'REPORT_PO_GRPNOM_S_POST_REPORT2(:PARAM_POSNACH,:PARAM_POSCON,:PA' +
        'RAM_IDFIRM,:PARAM_IDSKLAD,:PARAM_IDGRP)')
    Left = 896
    Top = 344
    poUseLargeIntField = True
    object ReportRasdel2OUT_NAMEPOST: TFIBWideStringField
      FieldName = 'OUT_NAMEPOST'
      Size = 200
    end
    object ReportRasdel2OUT_IDPOST: TFIBLargeIntField
      FieldName = 'OUT_IDPOST'
    end
    object ReportRasdel2OUT_NAME_PRODUCER: TFIBWideStringField
      FieldName = 'OUT_NAME_PRODUCER'
      Size = 200
    end
    object ReportRasdel2OUT_IDPRODUCER: TFIBLargeIntField
      FieldName = 'OUT_IDPRODUCER'
    end
    object ReportRasdel2OUT_NACHOSTKOL: TFIBBCDField
      FieldName = 'OUT_NACHOSTKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportRasdel2OUT_PRIHODKOL: TFIBBCDField
      FieldName = 'OUT_PRIHODKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportRasdel2OUT_RASHODKOL: TFIBBCDField
      FieldName = 'OUT_RASHODKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportRasdel2OUT_CONOSTKOL: TFIBBCDField
      FieldName = 'OUT_CONOSTKOL'
      Size = 3
      RoundByScale = True
    end
    object ReportRasdel2OUT_NACHOSTKOL_FISED: TFIBBCDField
      FieldName = 'OUT_NACHOSTKOL_FISED'
      Size = 3
      RoundByScale = True
    end
    object ReportRasdel2OUT_PRIHODKOL_FISED: TFIBBCDField
      FieldName = 'OUT_PRIHODKOL_FISED'
      Size = 3
      RoundByScale = True
    end
    object ReportRasdel2OUT_RASHODKOL_FISED: TFIBBCDField
      FieldName = 'OUT_RASHODKOL_FISED'
      Size = 3
      RoundByScale = True
    end
    object ReportRasdel2OUT_CONOSTKOL_FISED: TFIBBCDField
      FieldName = 'OUT_CONOSTKOL_FISED'
      Size = 3
      RoundByScale = True
    end
  end
  object Query: TpFIBQuery
    Left = 440
    Top = 8
    qoStartTransaction = True
  end
end
