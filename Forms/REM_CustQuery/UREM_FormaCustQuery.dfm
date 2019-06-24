object REM_FormaCustQuery: TREM_FormaCustQuery
  Left = 288
  Top = 180
  Caption = #1047#1072#1087#1088#1086#1089' '#1047#1072#1082#1072#1079#1095#1080#1082#1072
  ClientHeight = 577
  ClientWidth = 850
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
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 331
    Width = 3
    Height = 172
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 0
  end
  object Panel3: TPanel
    Left = 0
    Top = 503
    Width = 850
    Height = 74
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object DBTextNameUser: TDBText
      Left = 3
      Top = 55
      Width = 111
      Height = 16
      AutoSize = True
      DataField = 'NAME_USER'
      DataSource = REM_DMZayavka.DataSourceGurZ
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 221
      Top = 52
      Width = 111
      Height = 16
      Caption = #1090#1086#1083#1100#1082#1086' '#1087#1088#1086#1089#1084#1086#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonSave: TcxButton
      Left = 548
      Top = 52
      Width = 74
      Height = 24
      Action = ActionSave
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 629
      Top = 52
      Width = 75
      Height = 24
      Action = ActionOK
      TabOrder = 1
    end
    object cxButtonClose: TcxButton
      Left = 710
      Top = 52
      Width = 76
      Height = 24
      Action = ActionClose
      TabOrder = 2
    end
    object SostcxDBImageComboBox: TcxDBImageComboBox
      Left = 7
      Top = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      RepositoryItem = DM.cxEditRepository1ImageComboBoxItemSostQueryCust
      DataBinding.DataField = 'RUN_REM_CQUERY'
      Properties.Items = <>
      TabOrder = 3
      Width = 320
    end
  end
  object Panel4: TPanel
    Left = 840
    Top = 331
    Width = 10
    Height = 172
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 850
    Height = 137
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 3
    object Label1: TLabel
      Left = 10
      Top = 88
      Width = 235
      Height = 26
      Caption = #1047#1072#1087#1088#1086#1089' '#1047#1072#1082#1072#1079#1095#1080#1082#1072' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 407
      Top = 83
      Width = 32
      Height = 26
      Caption = #1086#1090' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label12: TLabel
      Left = 16
      Top = 61
      Width = 40
      Height = 13
      Caption = #1060#1080#1088#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label13: TLabel
      Left = 349
      Top = 39
      Width = 81
      Height = 13
      Caption = #1057#1082#1083#1072#1076' '#1087#1088#1080#1077#1084#1082#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 1
      Top = 36
      Width = 55
      Height = 13
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
    object Label5: TLabel
      Left = 363
      Top = 64
      Width = 67
      Height = 13
      Caption = #1058#1080#1087' '#1079#1072#1087#1088#1086#1089#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 62
      Top = 34
      DataBinding.DataField = 'NAME_SINFBASE_OBMEN'
      DataBinding.DataSource = REM_DMCustQuery.DataSourceDoc
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameInfBasecxDBButtonEditPropertiesButtonClick
      TabOrder = 0
      Width = 253
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 62
      Top = 61
      DataBinding.DataField = 'NAMEFIRM'
      DataBinding.DataSource = REM_DMCustQuery.DataSourceDoc
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = cxDBButtonEdit1PropertiesButtonClick
      TabOrder = 1
      Width = 253
    end
    object NameSkladPrcxDBButtonEdit: TcxDBButtonEdit
      Left = 451
      Top = 36
      DataBinding.DataField = 'NAMESKLAD'
      DataBinding.DataSource = REM_DMCustQuery.DataSourceDoc
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameSkladPrcxDBButtonEditPropertiesButtonClick
      TabOrder = 2
      Width = 273
    end
    object NumcxDBTextEdit: TcxDBTextEdit
      Left = 280
      Top = 88
      DataBinding.DataField = 'NUM_REM_CQUERY'
      DataBinding.DataSource = REM_DMCustQuery.DataSourceDoc
      TabOrder = 3
      Width = 106
    end
    object PoscxDBDateEdit: TcxDBDateEdit
      Left = 471
      Top = 91
      DataBinding.DataField = 'POS_REM_CQUERY'
      DataBinding.DataSource = REM_DMCustQuery.DataSourceDoc
      Properties.Kind = ckDateTime
      TabOrder = 4
      Width = 218
    end
    object ToolBar3: TToolBar
      Left = 0
      Top = 0
      Width = 850
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 5
      object ToolButton7: TToolButton
        Left = 0
        Top = 0
        Width = 17
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButton10: TToolButton
        Left = 17
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButton4'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
    end
    object TypeCQuerycxDBImageComboBox: TcxDBImageComboBox
      Left = 451
      Top = 61
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      RepositoryItem = DM.cxEditRepository1ImageComboBoxItemTypeCustomerQuery
      DataBinding.DataField = 'TYPE_REM_CQUERY'
      Properties.Items = <>
      TabOrder = 6
      Width = 273
    end
    object cxDBLabelKLIENT_NAME_REM_CQUERY: TcxDBLabel
      Left = 10
      Top = 115
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      AutoSize = True
      DataBinding.DataField = 'KLIENT_NAME_REM_CQUERY'
    end
    object cxDBLabelNAME_MODEL_REM_CQUERY: TcxDBLabel
      Left = 290
      Top = 115
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      AutoSize = True
      DataBinding.DataField = 'NAME_MODEL_REM_CQUERY'
    end
  end
  object Panel5: TPanel
    Left = 7
    Top = 331
    Width = 833
    Height = 172
    Align = alClient
    Caption = 'Panel5'
    TabOrder = 4
    object ToolBar1: TToolBar
      Left = 1
      Top = 1
      Width = 831
      Height = 26
      ButtonHeight = 23
      Caption = 'ToolBar1'
      EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Caption = 'ActionAddNewKompl'
        ImageIndex = 0
        OnClick = ToolButton1Click
      end
      object ToolButton5: TToolButton
        Left = 23
        Top = 0
        Caption = 'ActionEditKompl'
        ImageIndex = 1
      end
      object ToolButton6: TToolButton
        Left = 46
        Top = 0
        Caption = 'ActionDeleteKompl'
        ImageIndex = 2
        OnClick = ToolButton6Click
      end
      object ToolButtonShowHistori: TToolButton
        Left = 69
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1080#1089#1090#1086#1088#1080#1102
        Caption = 'ToolButtonShowHistori'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonShowHistoriClick
      end
    end
    object cxGrid1: TcxGrid
      Left = 1
      Top = 27
      Width = 831
      Height = 144
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Align = alClient
      TabOrder = 1
      ExplicitTop = 23
      object cxGrid1DBBandedTableView1: TcxGridDBBandedTableView
        NavigatorButtons.ConfirmDelete = False
        DataController.DataSource = REM_DMCustQuery.DataSourceDocT
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.IncSearch = True
        OptionsCustomize.DataRowSizing = True
        OptionsCustomize.BandHiding = True
        OptionsSelection.InvertSelect = False
        OptionsView.CellAutoHeight = True
        OptionsView.ColumnAutoWidth = True
        OptionsView.GroupByBox = False
        OptionsView.RowSeparatorWidth = 4
        OptionsView.BandHeaders = False
        Styles.Header = DM.cxStyleHeaderTable
        Bands = <
          item
            Width = 150
          end
          item
            Width = 502
          end>
        object cxGrid1DBBandedTableView1NAME_REM_SSOST_CQUERY: TcxGridDBBandedColumn
          Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
          DataBinding.FieldName = 'NAME_REM_SSOST_CQUERY'
          PropertiesClassName = 'TcxButtonEditProperties'
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_REM_SSOST_CQUERYPropertiesButtonClick
          Width = 212
          Position.BandIndex = 0
          Position.ColIndex = 0
          Position.LineCount = 2
          Position.RowIndex = 1
        end
        object cxGrid1DBBandedTableView1NAMENOM_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
          DataBinding.FieldName = 'NAMENOM_REM_CQUERYT'
          PropertiesClassName = 'TcxMemoProperties'
          Width = 315
          Position.BandIndex = 1
          Position.ColIndex = 1
          Position.RowIndex = 0
        end
        object cxGrid1DBBandedTableView1NAMENOM: TcxGridDBBandedColumn
          Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
          DataBinding.FieldName = 'NAMENOM'
          PropertiesClassName = 'TcxButtonEditProperties'
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.OnButtonClick = cxGrid1DBBandedTableView1NAMENOMPropertiesButtonClick
          Width = 164
          Position.BandIndex = 1
          Position.ColIndex = 3
          Position.RowIndex = 1
        end
        object cxGrid1DBBandedTableView1KOL_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1050#1086#1083'.'
          DataBinding.FieldName = 'KOL_REM_CQUERYT'
          Width = 25
          Position.BandIndex = 1
          Position.ColIndex = 4
          Position.RowIndex = 1
        end
        object cxGrid1DBBandedTableView1KF_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1050#1060
          DataBinding.FieldName = 'KF_REM_CQUERYT'
          Width = 22
          Position.BandIndex = 1
          Position.ColIndex = 5
          Position.RowIndex = 1
        end
        object cxGrid1DBBandedTableView1PRICE_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1062#1077#1085#1072
          DataBinding.FieldName = 'PRICE_REM_CQUERYT'
          PropertiesClassName = 'TcxCalcEditProperties'
          Width = 41
          Position.BandIndex = 1
          Position.ColIndex = 8
          Position.RowIndex = 1
        end
        object cxGrid1DBBandedTableView1SUM_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1057#1091#1084#1084#1072
          DataBinding.FieldName = 'SUM_REM_CQUERYT'
          PropertiesClassName = 'TcxCalcEditProperties'
          Width = 42
          Position.BandIndex = 1
          Position.ColIndex = 9
          Position.RowIndex = 1
        end
        object cxGrid1DBBandedTableView1PRICE_DO_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1062#1077#1085#1072' '#1047#1072#1082#1072#1079#1095#1080#1082#1072
          DataBinding.FieldName = 'PRICE_DO_REM_CQUERYT'
          PropertiesClassName = 'TcxCalcEditProperties'
          Width = 37
          Position.BandIndex = 1
          Position.ColIndex = 2
          Position.RowIndex = 0
        end
        object cxGrid1DBBandedTableView1PRICE_TEC_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1062#1077#1085#1072' '#1085#1072#1096#1072
          DataBinding.FieldName = 'PRICE_TEC_REM_CQUERYT'
          PropertiesClassName = 'TcxCalcEditProperties'
          Width = 41
          Position.BandIndex = 1
          Position.ColIndex = 3
          Position.RowIndex = 0
        end
        object cxGrid1DBBandedTableView1PRICE_SOGL_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1062#1077#1085#1072' '#1089#1086#1075#1083'.'
          DataBinding.FieldName = 'PRICE_SOGL_REM_CQUERYT'
          PropertiesClassName = 'TcxCalcEditProperties'
          Width = 42
          Position.BandIndex = 1
          Position.ColIndex = 4
          Position.RowIndex = 0
        end
        object cxGrid1DBBandedTableView1SROK_POST_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1057#1088#1086#1082' '#1087#1086#1089#1090#1072#1074#1082#1080
          DataBinding.FieldName = 'SROK_POST_REM_CQUERYT'
          PropertiesClassName = 'TcxCalcEditProperties'
          Width = 85
          Position.BandIndex = 0
          Position.ColIndex = 0
          Position.LineCount = 2
          Position.RowIndex = 2
        end
        object cxGrid1DBBandedTableView1POS_POST_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1044#1072#1090#1072' '#1087#1086#1089#1090#1072#1074#1082#1080
          DataBinding.FieldName = 'POS_POST_REM_CQUERYT'
          PropertiesClassName = 'TcxDateEditProperties'
          Width = 106
          Position.BandIndex = 0
          Position.ColIndex = 1
          Position.LineCount = 2
          Position.RowIndex = 2
        end
        object cxGrid1DBBandedTableView1RUN_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1042#1099#1087#1086#1083#1085#1077#1085#1086
          DataBinding.FieldName = 'RUN_REM_CQUERYT'
          PropertiesClassName = 'TcxCheckBoxProperties'
          Properties.ValueChecked = 1
          Properties.ValueUnchecked = 0
          Width = 78
          Position.BandIndex = 0
          Position.ColIndex = 2
          Position.RowIndex = 0
        end
        object cxGrid1DBBandedTableView1COMMENTS_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1050#1086#1084#1084#1077#1085#1090#1072#1088#1080#1081
          DataBinding.FieldName = 'COMMENTS_REM_CQUERYT'
          PropertiesClassName = 'TcxMemoProperties'
          Properties.ScrollBars = ssBoth
          Styles.Content = DM.cxStyleVidStringSkyBlue
          Width = 127
          Position.BandIndex = 1
          Position.ColIndex = 0
          Position.RowIndex = 4
        end
        object cxGrid1DBBandedTableView1NAMEED: TcxGridDBBandedColumn
          Caption = #1045#1076#1080#1085#1080#1094#1072
          DataBinding.FieldName = 'NAMEED'
          PropertiesClassName = 'TcxButtonEditProperties'
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Width = 38
          Position.BandIndex = 1
          Position.ColIndex = 6
          Position.RowIndex = 1
        end
        object cxGrid1DBBandedTableView1RECNO: TcxGridDBBandedColumn
          Caption = #8470
          DataBinding.FieldName = 'RECNO'
          Width = 100
          Position.BandIndex = 0
          Position.ColIndex = 0
          Position.RowIndex = 0
        end
        object cxGrid1DBBandedTableView1ACT_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1040#1082#1090'.'
          DataBinding.FieldName = 'ACT_REM_CQUERYT'
          PropertiesClassName = 'TcxCheckBoxProperties'
          Properties.ValueChecked = 1
          Properties.ValueUnchecked = 0
          Width = 115
          Position.BandIndex = 0
          Position.ColIndex = 1
          Position.RowIndex = 0
        end
        object cxGrid1DBBandedTableView1CODENOM: TcxGridDBBandedColumn
          Caption = #1050#1086#1076' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
          DataBinding.FieldName = 'CODENOM'
          Width = 31
          Position.BandIndex = 1
          Position.ColIndex = 1
          Position.RowIndex = 1
        end
        object cxGrid1DBBandedTableView1ARTNOM: TcxGridDBBandedColumn
          Caption = #1040#1088#1090#1080#1082#1091#1083' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
          DataBinding.FieldName = 'ARTNOM'
          Width = 83
          Position.BandIndex = 1
          Position.ColIndex = 0
          Position.RowIndex = 1
        end
        object cxGrid1DBBandedTableView1SHED: TcxGridDBBandedColumn
          Caption = #1064#1050
          DataBinding.FieldName = 'SHED'
          Width = 52
          Position.BandIndex = 1
          Position.ColIndex = 7
          Position.RowIndex = 1
        end
        object cxGrid1DBBandedTableView1ART_SPRNOM: TcxGridDBBandedColumn
          Caption = #1040#1088#1090#1080#1082#1091#1083' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072
          DataBinding.FieldName = 'ART_SPRNOM'
          Width = 80
          Position.BandIndex = 1
          Position.ColIndex = 0
          Position.RowIndex = 2
        end
        object cxGrid1DBBandedTableView1CODE_SPRNOM: TcxGridDBBandedColumn
          Caption = #1050#1086#1076' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072
          DataBinding.FieldName = 'CODE_SPRNOM'
          Width = 30
          Position.BandIndex = 1
          Position.ColIndex = 1
          Position.RowIndex = 2
        end
        object cxGrid1DBBandedTableView1NAME_SPRNOM: TcxGridDBBandedColumn
          Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072
          DataBinding.FieldName = 'NAME_SPRNOM'
          PropertiesClassName = 'TcxButtonEditProperties'
          Properties.Buttons = <
            item
              Default = True
              Kind = bkEllipsis
            end>
          Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_REM_SPRNOMPropertiesButtonClick
          Width = 392
          Position.BandIndex = 1
          Position.ColIndex = 2
          Position.RowIndex = 2
        end
        object cxGrid1DBBandedTableView1ART_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1040#1088#1090#1080#1082#1091#1083
          DataBinding.FieldName = 'ART_REM_CQUERYT'
          Width = 83
          Position.BandIndex = 1
          Position.ColIndex = 0
          Position.RowIndex = 0
        end
        object cxGrid1DBBandedTableView1FL_ADD_IN_SOBORUD_SNOM: TcxGridDBBandedColumn
          DataBinding.FieldName = 'FL_ADD_IN_SOBORUD_SNOM'
          PropertiesClassName = 'TcxCheckBoxProperties'
          Properties.ValueChecked = 1
          Properties.ValueUnchecked = 0
          Width = 20
          Position.BandIndex = 1
          Position.ColIndex = 2
          Position.RowIndex = 1
        end
        object cxGrid1DBBandedTableView1REF_REM_CQUERYT: TcxGridDBBandedColumn
          Caption = #1057#1089#1099#1083#1082#1072' '#1085#1072' '#1090#1086#1074#1072#1088
          DataBinding.FieldName = 'REF_REM_CQUERYT'
          Styles.Content = DM.cxStyleVidelString
          Position.BandIndex = 1
          Position.ColIndex = 0
          Position.RowIndex = 3
        end
      end
      object cxGrid1Level1: TcxGridLevel
        GridView = cxGrid1DBBandedTableView1
      end
    end
  end
  object Panel6: TPanel
    Left = 3
    Top = 331
    Width = 4
    Height = 172
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 5
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 137
    Width = 850
    Height = 194
    ActivePage = cxTabSheet1
    Align = alTop
    TabOrder = 6
    ClientRectBottom = 194
    ClientRectRight = 850
    ClientRectTop = 24
    object cxTabSheet1: TcxTabSheet
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 0
      object Label27: TLabel
        Left = 17
        Top = 44
        Width = 56
        Height = 13
        Caption = #1055#1088#1086#1080#1079#1074'-'#1083#1100':'
      end
      object Label17: TLabel
        Left = 20
        Top = 71
        Width = 53
        Height = 13
        Caption = #1055#1088#1086#1076#1072#1074#1077#1094':'
      end
      object NameBrandcxDBButtonEdit: TcxDBButtonEdit
        Left = 79
        Top = 18
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NAME_SBRAND'
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
        Properties.OnButtonClick = NameBrandcxDBButtonEditPropertiesButtonClick
        TabOrder = 0
        Width = 250
      end
      object cxLabel9: TcxLabel
        Left = 22
        Top = 19
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1041#1088#1077#1085#1076':'
      end
      object ProducercxDBButtonEdit: TcxDBButtonEdit
        Left = 78
        Top = 43
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NAME_SPRODUCER'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = ProducercxDBButtonEditPropertiesButtonClick
        TabOrder = 2
        Width = 251
      end
      object cxLabel2: TcxLabel
        Left = 379
        Top = 19
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1053#1086#1084#1077#1088' '#1079#1072#1082#1072#1079#1072' '#1055#1086#1089#1090#1072#1074#1097#1080#1082#1091':'
      end
      object NumZakazacxDBSpinEdit: TcxDBSpinEdit
        Left = 401
        Top = 40
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NUM_ZAKAZA_REM_CQUERY'
        TabOrder = 4
        Width = 124
      end
      object cxLabel3: TcxLabel
        Left = 578
        Top = 19
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1044#1072#1090#1072' '#1079#1072#1082#1072#1079#1072':'
      end
      object DateZakazacxDBDateEdit: TcxDBDateEdit
        Left = 578
        Top = 40
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'DATE_ZAKAZA_REM_CQUERY'
        TabOrder = 6
        Width = 126
      end
      object cxLabel6: TcxLabel
        Left = 62
        Top = 141
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1050#1083#1080#1077#1085#1090' '#1091#1074#1077#1076#1086#1084#1083#1077#1085' '#1086' '#1075#1086#1090#1086#1074#1085#1086#1089#1090#1080':'
      end
      object KlientUvedomlencxDBImageComboBox: TcxDBImageComboBox
        Left = 250
        Top = 144
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxKlientUvedomlen
        DataBinding.DataField = 'FL_KLIENT_UVEDOML_REM_CQUERY'
        Properties.Items = <>
        TabOrder = 8
        Width = 263
      end
      object cxLabel5: TcxLabel
        Left = 22
        Top = 95
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1044#1086#1083#1078#1085#1086' '#1087#1086#1089#1090#1091#1087#1080#1090#1100':'
      end
      object PlanPostavkicxDBDateEdit: TcxDBDateEdit
        Left = 22
        Top = 116
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'PLAN_POSTAVKI_REM_CQUERY'
        TabOrder = 10
        Width = 132
      end
      object ZakazanocxDBDateEdit: TcxDBDateEdit
        Left = 250
        Top = 114
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'ZAKAZANO_REM_CQUERY'
        Properties.Kind = ckDateTime
        TabOrder = 11
        Width = 136
      end
      object cxLabel7: TcxLabel
        Left = 250
        Top = 93
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1047#1072#1082#1072#1079#1072#1085#1086':'
      end
      object OtpravlenocxDBDateEdit: TcxDBDateEdit
        Left = 407
        Top = 114
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'OTPRAVLENO_REM_CQUERY'
        TabOrder = 13
        Width = 136
      end
      object cxLabel8: TcxLabel
        Left = 407
        Top = 93
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1054#1090#1087#1088#1072#1074#1083#1077#1085#1086':'
      end
      object cxLabel4: TcxLabel
        Left = 567
        Top = 93
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1055#1086#1089#1090#1091#1087#1080#1083#1086':'
      end
      object PostupilocxDBDateEdit: TcxDBDateEdit
        Left = 567
        Top = 114
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'POSTUPILO_REM_CQUERY'
        Properties.Kind = ckDateTime
        TabOrder = 16
        Width = 137
      end
      object cxDBButtonEditPRODAVEC_NAME: TcxDBButtonEdit
        Left = 78
        Top = 68
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'PRODAVEC_NAME'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxDBButtonEditPRODAVEC_NAMEPropertiesButtonClick
        TabOrder = 17
        Width = 251
      end
    end
    object cxTabSheet2: TcxTabSheet
      Caption = #1050#1083#1080#1077#1085#1090
      ImageIndex = 1
      object Label14: TLabel
        Left = 26
        Top = 24
        Width = 39
        Height = 13
        Caption = #1050#1083#1080#1077#1085#1090':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label19: TLabel
        Left = 21
        Top = 52
        Width = 65
        Height = 13
        Caption = #1050#1083#1080#1077#1085#1090' ('#1089#1090#1088'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label20: TLabel
        Left = 26
        Top = 83
        Width = 60
        Height = 13
        Caption = #1040#1076#1088#1077#1089' ('#1089#1090#1088'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label21: TLabel
        Left = 21
        Top = 110
        Width = 74
        Height = 13
        Caption = #1058#1077#1083#1077#1092#1086#1085' ('#1089#1090#1088'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object NameKlientcxDBButtonEdit: TcxDBButtonEdit
        Left = 122
        Top = 21
        DataBinding.DataField = 'NAMEKLIENT'
        DataBinding.DataSource = REM_DMCustQuery.DataSourceDoc
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
        TabOrder = 0
        Width = 250
      end
      object KlientNamecxDBTextEdit: TcxDBTextEdit
        Left = 122
        Top = 48
        DataBinding.DataField = 'KLIENT_NAME_REM_CQUERY'
        TabOrder = 1
        OnKeyPress = KlientNamecxDBTextEditKeyPress
        Width = 251
      end
      object KlientAdtrcxDBTextEdit: TcxDBTextEdit
        Left = 121
        Top = 75
        DataBinding.DataField = 'KLIENT_ADR_REM_CQUERY'
        TabOrder = 2
        OnKeyPress = KlientAdtrcxDBTextEditKeyPress
        Width = 251
      end
      object KlientPhonecxDBTextEdit: TcxDBTextEdit
        Left = 121
        Top = 102
        DataBinding.DataField = 'KLIENT_PHONE_REM_CQUERY'
        TabOrder = 3
        OnKeyPress = KlientPhonecxDBTextEditKeyPress
        Width = 252
      end
    end
    object cxTabSheet3: TcxTabSheet
      Caption = #1059#1089#1090#1088#1086#1081#1089#1090#1074#1086
      ImageIndex = 2
      object Label16: TLabel
        Left = 37
        Top = 82
        Width = 42
        Height = 13
        Caption = #1052#1086#1076#1077#1083#1100':'
      end
      object Label4: TLabel
        Left = 24
        Top = 109
        Width = 84
        Height = 13
        Caption = #1052#1086#1076#1077#1083#1100' '#1087#1088#1086#1080#1079#1074'.:'
      end
      object Label22: TLabel
        Left = 32
        Top = 140
        Width = 68
        Height = 13
        Caption = #1052#1086#1076#1077#1083#1100' ('#1089#1090#1088'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 24
        Top = 54
        Width = 76
        Height = 13
        Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077':'
      end
      object ModelcxDBTextEdit: TcxDBTextEdit
        Left = 123
        Top = 133
        DataBinding.DataField = 'NAME_MODEL_REM_CQUERY'
        TabOrder = 0
        OnKeyPress = ModelcxDBTextEditKeyPress
        Width = 229
      end
      object NameProducerModelcxDBButtonEdit: TcxDBButtonEdit
        Left = 123
        Top = 106
        DataBinding.DataField = 'NAME_REM_SPRMODEL'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameProducerModelcxDBButtonEditPropertiesButtonClick
        TabOrder = 1
        Width = 230
      end
      object NameModelcxDBButtonEdit: TcxDBButtonEdit
        Left = 123
        Top = 77
        DataBinding.DataField = 'NAME_REM_SMODEL'
        DataBinding.DataSource = REM_DMCustQuery.DataSourceDoc
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameModelcxDBButtonEditPropertiesButtonClick
        TabOrder = 2
        Width = 229
      end
      object NameZcxDBButtonEdit: TcxDBButtonEdit
        Left = 123
        Top = 21
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NAME_REM_Z'
        DataBinding.DataSource = REM_DMCustQuery.DataSourceDoc
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = NameZcxDBButtonEditPropertiesButtonClick
        TabOrder = 3
        Width = 230
      end
      object cxLabel1: TcxLabel
        Left = 33
        Top = 22
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1047#1072#1103#1074#1082#1072':'
      end
      object NameSprHardwarecxDBButtonEdit: TcxDBButtonEdit
        Left = 124
        Top = 51
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NAME_REM_SHARDWARE'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = NameSprHardwarecxDBButtonEditPropertiesButtonClick
        TabOrder = 5
        Width = 229
      end
      object SerNumSprHardwarecxDBLabel: TcxDBLabel
        Left = 384
        Top = 47
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'SERNUM_REM_SHARDWARE'
        Height = 17
        Width = 98
      end
      object SerNum2SprhardwarecxDBLabel: TcxDBLabel
        Left = 504
        Top = 43
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'SERNUM2_REM_SHARDWARE'
        Height = 17
        Width = 98
      end
      object PosZcxDBLabel: TcxDBLabel
        Left = 629
        Top = 22
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'POS_REM_Z'
        DataBinding.DataSource = REM_DMCustQuery.DataSourceDoc
        Height = 17
        Width = 98
      end
      object NumZcxDBLabel: TcxDBLabel
        Left = 503
        Top = 22
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NUM_REM_Z'
        DataBinding.DataSource = REM_DMCustQuery.DataSourceDoc
        Height = 17
        Width = 99
      end
      object ModelZcxDBLabel: TcxDBLabel
        Left = 384
        Top = 26
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'MODEL_REM_Z'
        DataBinding.DataSource = REM_DMCustQuery.DataSourceDoc
        Height = 17
        Width = 98
      end
    end
    object cxTabSheet4: TcxTabSheet
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090#1099
      ImageIndex = 3
      object Label7: TLabel
        Left = 14
        Top = 21
        Width = 87
        Height = 13
        Caption = 'ID '#1091' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label8: TLabel
        Left = 17
        Top = 54
        Width = 135
        Height = 13
        Caption = #1047#1072#1082#1072#1079' '#1091' '#1055#1086#1089#1090#1072#1074#1097#1080#1082#1072' '#1047#1048#1055':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label9: TLabel
        Left = 22
        Top = 73
        Width = 144
        Height = 13
        Caption = #1047#1072#1082#1072#1079' '#1091' '#1089#1077#1088#1074#1080#1089' '#1087#1088#1086#1074#1072#1081#1076#1077#1088#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label10: TLabel
        Left = 33
        Top = 99
        Width = 104
        Height = 13
        Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1086#1090#1087#1088#1072#1074#1082#1080':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label11: TLabel
        Left = 22
        Top = 122
        Width = 128
        Height = 13
        Caption = #1058#1088#1072#1085#1089#1087#1086#1088#1090#1085#1072#1103' '#1082#1086#1084#1087#1072#1085#1080#1103':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label15: TLabel
        Left = 33
        Top = 146
        Width = 111
        Height = 13
        Caption = #1053#1086#1084#1077#1088' '#1085#1072#1082#1083#1072#1076#1085#1086#1081' '#1058#1050':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object cxDBTexNUM_STR_ZAK_POST_REM_CQUERY: TcxDBTextEdit
        Left = 172
        Top = 45
        DataBinding.DataField = 'NUM_STR_ZAK_POST_REM_CQUERY'
        TabOrder = 0
        OnKeyPress = ModelcxDBTextEditKeyPress
        Width = 230
      end
      object cxDBDateEditPOS_ZAK_POST_REM_CQUERY: TcxDBDateEdit
        Left = 407
        Top = 45
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'POS_ZAK_POST_REM_CQUERY'
        Properties.Kind = ckDateTime
        TabOrder = 1
        Width = 157
      end
      object cxDBTextEditNUM_STR_ZAK_SPROV_REM_CQUERY: TcxDBTextEdit
        Left = 172
        Top = 72
        DataBinding.DataField = 'NUM_STR_ZAK_SPROV_REM_CQUERY'
        TabOrder = 2
        OnKeyPress = ModelcxDBTextEditKeyPress
        Width = 230
      end
      object cxDBDateEditPOS_ZAK_SPROV_REM_CQUERY: TcxDBDateEdit
        Left = 407
        Top = 71
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'POS_ZAK_SPROV_REM_CQUERY'
        Properties.Kind = ckDateTime
        TabOrder = 3
        Width = 157
      end
      object cxDBTextEditNUM_DOC_OTPR_POST_REM_CQUERY: TcxDBTextEdit
        Left = 172
        Top = 96
        DataBinding.DataField = 'NUM_DOC_OTPR_POST_REM_CQUERY'
        TabOrder = 4
        OnKeyPress = ModelcxDBTextEditKeyPress
        Width = 230
      end
      object cxDBDateEditPOS_DOC_OTPR_POST_REM_CQUERY: TcxDBDateEdit
        Left = 407
        Top = 96
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'POS_DOC_OTPR_POST_REM_CQUERY'
        Properties.Kind = ckDateTime
        TabOrder = 5
        Width = 157
      end
      object cxDBTextEditNUMDOCTK_REM_CQUERY: TcxDBTextEdit
        Left = 172
        Top = 143
        DataBinding.DataField = 'NUMDOCTK_REM_CQUERY'
        TabOrder = 6
        OnKeyPress = ModelcxDBTextEditKeyPress
        Width = 230
      end
      object cxDBTextEditTK_REM_CQUERY: TcxDBTextEdit
        Left = 172
        Top = 119
        DataBinding.DataField = 'TK_REM_CQUERY'
        TabOrder = 7
        OnKeyPress = ModelcxDBTextEditKeyPress
        Width = 230
      end
      object cxDBTextEditNUM_STR_ZAK_POST_REM_CQUERY: TcxDBTextEdit
        Left = 107
        Top = 18
        DataBinding.DataField = 'NUM_STR_ZAK_POST_REM_CQUERY'
        TabOrder = 8
        OnKeyPress = KlientPhonecxDBTextEditKeyPress
        Width = 252
      end
    end
    object cxTabSheet5: TcxTabSheet
      Caption = #1044#1086#1087
      ImageIndex = 4
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 776
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionViborInfBase: TAction
      Caption = 'ActionViborInfBase'
    end
    object ActionViborFirm: TAction
      Caption = 'ActionViborFirm'
    end
    object ActionViborSkladPr: TAction
      Caption = 'ActionViborSkladPr'
    end
    object ActionViborDiler: TAction
      Caption = 'ActionViborDiler'
    end
    object ActionViborKlient: TAction
      Caption = 'ActionViborKlient'
    end
    object ActionViborTypeRemont: TAction
      Caption = 'ActionViborTypeRemont'
    end
    object ActionViborModel: TAction
      Caption = 'ActionViborModel'
    end
    object ActionViborSost: TAction
      Caption = 'ActionViborSost'
    end
    object ActionViborTecSklad: TAction
      Caption = 'ActionViborTecSklad'
    end
    object ActionAddNewKompl: TAction
      Caption = 'ActionAddNewKompl'
    end
    object ActionEditKompl: TAction
      Caption = 'ActionEditKompl'
    end
    object ActionAddNeispr: TAction
      Caption = 'ActionAddNeispr'
    end
    object ActionEditNeispr: TAction
      Caption = 'ActionEditNeispr'
    end
    object ActionDeleteKompl: TAction
      Caption = 'ActionDeleteKompl'
    end
    object ActionDeleteNeispr: TAction
      Caption = 'ActionDeleteNeispr'
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 784
    Top = 8
  end
end
