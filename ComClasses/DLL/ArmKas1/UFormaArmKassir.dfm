object FormaARMKassir: TFormaARMKassir
  Left = 250
  Top = 138
  Caption = #1040#1056#1052' '#1082#1072#1089#1089#1080#1088#1072
  ClientHeight = 534
  ClientWidth = 753
  Color = clBtnFace
  Constraints.MinWidth = 760
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  WindowState = wsMaximized
  OnActivate = FormActivate
  OnClose = FormClose
  OnDeactivate = FormDeactivate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel5: TPanel
    Left = 0
    Top = 408
    Width = 753
    Height = 126
    Align = alBottom
    BevelInner = bvLowered
    BevelOuter = bvNone
    TabOrder = 0
    object Prim: TLabel
      Left = 7
      Top = 63
      Width = 468
      Height = 40
      AutoSize = False
      Caption = 'Prim'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object GroupBoxSum: TGroupBox
      Left = 1
      Top = 6
      Width = 150
      Height = 50
      Caption = #1057#1091#1084#1084#1072' '#1095#1077#1082#1072':'
      TabOrder = 2
      object SumDoc: TDBText
        Left = 2
        Top = 15
        Width = 146
        Height = 33
        Align = alClient
        Alignment = taRightJustify
        DataField = 'SUMDOC'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        ExplicitWidth = 147
        ExplicitHeight = 34
      end
    end
    object GroupBoxSdacha: TGroupBox
      Left = 591
      Top = 5
      Width = 150
      Height = 50
      Caption = #1057#1076#1072#1095#1072':'
      TabOrder = 3
      object Sdacha: TDBText
        Left = 2
        Top = 15
        Width = 146
        Height = 33
        Align = alClient
        Alignment = taRightJustify
        DataField = 'SDACHA_DCHK'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        ExplicitWidth = 147
        ExplicitHeight = 34
      end
    end
    object GroupBoxPC: TGroupBox
      Left = 305
      Top = 6
      Width = 150
      Height = 50
      Caption = #1055#1083#1072#1090'. '#1082#1072#1088#1090#1086#1081':'
      TabOrder = 1
      object OplataPC: TcxDBCalcEdit
        Left = 6
        Top = 15
        DataBinding.DataField = 'OPLPCCHK'
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -19
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = [fsBold]
        Style.IsFontAssigned = True
        TabOrder = 0
        OnExit = OplataPCExit
        OnKeyDown = OplataPCKeyDown
        Width = 139
      end
    end
    object GroupBoxNal: TGroupBox
      Left = 153
      Top = 6
      Width = 150
      Height = 50
      Caption = #1053#1072#1083#1080#1095#1085#1099#1084#1080':'
      TabOrder = 0
      object Nal: TcxDBCalcEdit
        Left = 6
        Top = 15
        DataBinding.DataField = 'NALCHK'
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -19
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = [fsBold]
        Style.HotTrack = True
        Style.IsFontAssigned = True
        TabOrder = 0
        OnExit = NalExit
        OnKeyDown = NalKeyDown
        Width = 137
      end
    end
    object StatusBar: TStatusBar
      Left = 1
      Top = 106
      Width = 751
      Height = 19
      Panels = <
        item
          Text = #1060#1080#1088#1084#1072
          Width = 200
        end
        item
          Text = #1057#1082#1083#1072#1076
          Width = 200
        end
        item
          Text = #1050#1050#1052
          Width = 100
        end
        item
          Text = #1060#1056' '#8470
          Width = 80
        end
        item
          Text = #1050#1051' '#8470
          Width = 75
        end
        item
          Text = #1095#1077#1082' '#8470
          Width = 50
        end>
    end
    object ButtonPrint: TcxButton
      Left = 488
      Top = 61
      Width = 122
      Height = 41
      Action = ActionPrint
      TabOrder = 5
    end
    object ButtonClose: TcxButton
      Left = 616
      Top = 61
      Width = 125
      Height = 41
      Action = ActionClose
      TabOrder = 6
    end
    object GroupBoxAllOplata: TGroupBox
      Left = 461
      Top = 6
      Width = 124
      Height = 49
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1054#1087#1083#1072#1090#1072
      TabOrder = 7
      object AllOplataDBText: TDBText
        Left = 2
        Top = 15
        Width = 120
        Height = 32
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alClient
        Alignment = taRightJustify
        DataField = 'ALLOPL'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        ExplicitWidth = 121
        ExplicitHeight = 33
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 753
    Height = 85
    Align = alTop
    BevelInner = bvLowered
    BevelOuter = bvNone
    TabOrder = 1
    object NameDoc: TLabel
      Left = 8
      Top = 44
      Width = 111
      Height = 24
      Caption = #1063#1077#1082' '#1050#1050#1052' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object NameKKMLabel: TLabel
      Left = 638
      Top = 8
      Width = 111
      Height = 16
      Alignment = taRightJustify
      Caption = 'NameKKMLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object TypePriceLabel: TLabel
      Left = 637
      Top = 26
      Width = 112
      Height = 16
      Alignment = taRightJustify
      Caption = 'TypePriceLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object UchLabel: TLabel
      Left = 657
      Top = 44
      Width = 89
      Height = 24
      Alignment = taRightJustify
      Caption = 'UchLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object NumberDocDBText: TDBText
      Left = 128
      Top = 40
      Width = 105
      Height = 25
      DataField = 'NUMDOC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object NameKlientDBText: TDBText
      Left = 8
      Top = 8
      Width = 249
      Height = 17
      DataField = 'NAMEKLIENT'
    end
    object Oper: TDBText
      Left = 455
      Top = 43
      Width = 43
      Height = 24
      Alignment = taCenter
      AutoSize = True
      DataField = 'OPERCHK'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object NameDCardcxDBLabel: TcxDBLabel
      Left = 7
      Top = 26
      AutoSize = True
      DataBinding.DataField = 'NAME_SDISCOUNT_CARD'
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 85
    Width = 753
    Height = 323
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 2
    TabStop = False
    ClientRectBottom = 323
    ClientRectRight = 753
    ClientRectTop = 24
    object cxTabSheet1: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103' Ctrl+Z'
      ImageIndex = 0
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 753
        Height = 53
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        object PanelName: TPanel
          Left = 1
          Top = 2
          Width = 374
          Height = 48
          BevelOuter = bvLowered
          TabOrder = 0
          object NameNomDBText: TDBText
            Left = 8
            Top = 7
            Width = 361
            Height = 26
            DataField = 'NAMENOM'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -19
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Label5: TLabel
            Left = 8
            Top = 32
            Width = 79
            Height = 13
            Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
          end
        end
        object PanelKol: TPanel
          Left = 379
          Top = 2
          Width = 122
          Height = 48
          BevelOuter = bvLowered
          TabOrder = 1
          object Label6: TLabel
            Left = 8
            Top = 32
            Width = 62
            Height = 13
            Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
          end
          object KolDBText: TDBText
            Left = 8
            Top = 7
            Width = 105
            Height = 26
            Alignment = taRightJustify
            DataField = 'KOLCHKT'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -23
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
        end
        object PanelKF: TPanel
          Left = 505
          Top = 1
          Width = 113
          Height = 49
          BevelOuter = bvLowered
          TabOrder = 2
          object Label7: TLabel
            Left = 8
            Top = 32
            Width = 21
            Height = 13
            Caption = #1050#1060':'
          end
          object KFDBText: TDBText
            Left = 7
            Top = 8
            Width = 96
            Height = 25
            Alignment = taRightJustify
            DataField = 'KFCHKT'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -23
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
        end
        object PanelPrice: TPanel
          Left = 622
          Top = 1
          Width = 130
          Height = 49
          BevelOuter = bvLowered
          TabOrder = 3
          object Label8: TLabel
            Left = 8
            Top = 32
            Width = 29
            Height = 13
            Caption = #1062#1077#1085#1072':'
          end
          object PriceDBText: TDBText
            Left = 8
            Top = 8
            Width = 113
            Height = 25
            Alignment = taRightJustify
            DataField = 'PRICECHKT'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -23
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
        end
      end
      object cxGrid1: TcxGrid
        Left = 0
        Top = 53
        Width = 753
        Height = 246
        Align = alClient
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnExit = cxGrid1Exit
        object cxGrid1DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <
            item
              Kind = skSum
              Column = cxGrid1DBTableView1SUMCHKT
            end
            item
              Kind = skSum
              Column = cxGrid1DBTableView1SKCHKT
            end
            item
              Kind = skSum
              Column = cxGrid1DBTableView1NADCHKT
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsBehavior.IncSearch = True
          OptionsCustomize.ColumnsQuickCustomization = True
          OptionsSelection.InvertSelect = False
          OptionsView.NoDataToDisplayInfoText = '<'#1053#1077#1090' '#1076#1072#1085#1085#1099#1093'>'
          OptionsView.ColumnAutoWidth = True
          OptionsView.Footer = True
          OptionsView.GroupByBox = False
          object cxGrid1DBTableView1RECNO: TcxGridDBColumn
            Caption = #8470
            DataBinding.FieldName = 'RECNO'
            Width = 20
          end
          object cxGrid1DBTableView1NUMOTDKKT_SDEPARTMENT: TcxGridDBColumn
            Caption = #1054#1090#1076#1077#1083
            DataBinding.FieldName = 'NUMOTDKKT_SDEPARTMENT'
            Width = 24
          end
          object cxGrid1DBTableView1NAME_SDEPARTMENT: TcxGridDBColumn
            Caption = #1053#1072#1080#1084'. '#1086#1090#1076#1077#1083#1072
            DataBinding.FieldName = 'NAME_SDEPARTMENT'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end
              item
                Caption = 'X'
                Kind = bkText
              end>
            Width = 45
          end
          object cxGrid1DBTableView1CodeNom: TcxGridDBColumn
            Caption = #1050#1086#1076
            DataBinding.FieldName = 'CODENOM'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 35
          end
          object cxGrid1DBTableView1ArtNom: TcxGridDBColumn
            Caption = #1040#1088#1090#1080#1082#1091#1083
            DataBinding.FieldName = 'ARTNOM'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 59
          end
          object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
            Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
            DataBinding.FieldName = 'NAMENOM'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.ReadOnly = True
            Properties.OnButtonClick = cxGrid1DBTableView1NAMENOMPropertiesButtonClick
            Width = 152
          end
          object cxGrid1DBTableView1KOLCHKT: TcxGridDBColumn
            Caption = #1050#1086#1083'.'
            DataBinding.FieldName = 'KOLCHKT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.OnValidate = cxGrid1DBTableView1KOLCHKTPropertiesValidate
            Width = 31
          end
          object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
            Caption = #1045#1076#1080#1085#1080#1094#1072
            DataBinding.FieldName = 'NAMEED'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.ReadOnly = True
            Properties.OnButtonClick = cxGrid1DBTableView1NAMEEDPropertiesButtonClick
            Width = 38
          end
          object cxGrid1DBTableView1BarCode: TcxGridDBColumn
            Caption = #1064#1090#1088#1080#1093#1082#1086#1076
            DataBinding.FieldName = 'SHED'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 83
          end
          object cxGrid1DBTableView1KFCHKT: TcxGridDBColumn
            Caption = #1050
            DataBinding.FieldName = 'KFCHKT'
            Options.Editing = False
            Width = 27
          end
          object cxGrid1DBTableView1PRICECHKT: TcxGridDBColumn
            Caption = #1062#1077#1085#1072
            DataBinding.FieldName = 'PRICECHKT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 49
          end
          object cxGrid1DBTableView1SUMCHKT: TcxGridDBColumn
            Caption = #1057#1091#1084#1084#1072
            DataBinding.FieldName = 'SUMCHKT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 65
          end
          object cxGrid1DBTableView1PRSKCHKT: TcxGridDBColumn
            Caption = '-%'
            DataBinding.FieldName = 'PRSKCHKT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.ReadOnly = True
            Width = 23
          end
          object cxGrid1DBTableView1PRNADCHKT: TcxGridDBColumn
            Caption = '+%'
            DataBinding.FieldName = 'PRNADCHKT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.ReadOnly = True
            Width = 20
          end
          object cxGrid1DBTableView1SKCHKT: TcxGridDBColumn
            Caption = #1057#1082#1080#1076#1082#1072
            DataBinding.FieldName = 'SKCHKT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.ReadOnly = True
            Width = 33
          end
          object cxGrid1DBTableView1NADCHKT: TcxGridDBColumn
            Caption = #1053#1072#1076#1073#1072#1074#1082#1072
            DataBinding.FieldName = 'NADCHKT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.ReadOnly = True
            Width = 35
          end
        end
        object cxGrid1Level1: TcxGridLevel
          GridView = cxGrid1DBTableView1
        end
      end
    end
    object cxTabSheet2: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1054#1087#1083#1072#1090#1072' Ctrl+X'
      ImageIndex = 1
      object GroupBox14: TGroupBox
        Left = 189
        Top = 0
        Width = 564
        Height = 299
        Align = alClient
        Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1099#1077' '#1082#1072#1088#1090#1099' '#1086#1087#1083#1072#1090#1099':'
        TabOrder = 0
        object cxGrid2: TcxGrid
          Left = 2
          Top = 43
          Width = 560
          Height = 213
          Align = alClient
          TabOrder = 0
          object cxGrid2DBTableView1: TcxGridDBTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <
              item
                Kind = skSum
                FieldName = 'SUMCREDIT_DCHK_OPL'
                Column = cxGrid2DBTableView1SUMCREDIT_DCHK_OPL
              end
              item
                Kind = skSum
                FieldName = 'SUMPLAT_DCHK_OPL'
                Column = cxGrid2DBTableView1SUMPLAT_DCHK_OPL
              end>
            DataController.Summary.SummaryGroups = <>
            OptionsView.ColumnAutoWidth = True
            OptionsView.Footer = True
            OptionsView.GroupByBox = False
            Styles.Header = DM.cxStyleHeaderTable
            object cxGrid2DBTableView1RECNO: TcxGridDBColumn
              Caption = #8470
              DataBinding.FieldName = 'RECNO'
              Width = 27
            end
            object cxGrid2DBTableView1NAME_SDISCOUNT_CARD: TcxGridDBColumn
              Caption = #1050#1072#1088#1090#1072
              DataBinding.FieldName = 'NAME_SDISCOUNT_CARD'
              Width = 297
            end
            object cxGrid2DBTableView1SUMPLAT_DCHK_OPL: TcxGridDBColumn
              Caption = #1057#1091#1084#1084#1072' '#1087#1083#1072#1090#1077#1078#1072
              DataBinding.FieldName = 'SUMPLAT_DCHK_OPL'
              Width = 101
            end
            object cxGrid2DBTableView1SUMCREDIT_DCHK_OPL: TcxGridDBColumn
              Caption = #1057#1091#1084#1084#1072' '#1082#1088#1077#1076#1080#1090#1072
              DataBinding.FieldName = 'SUMCREDIT_DCHK_OPL'
              Width = 103
            end
          end
          object cxGrid2Level1: TcxGridLevel
            GridView = cxGrid2DBTableView1
          end
        end
        object Panel10: TPanel
          Left = 2
          Top = 256
          Width = 560
          Height = 41
          Align = alBottom
          BevelOuter = bvNone
          TabOrder = 1
          object GroupBox15: TGroupBox
            Left = 4
            Top = -1
            Width = 277
            Height = 41
            Caption = #1042#1089#1077#1075#1086' '#1087#1083#1072#1090#1077#1078#1085#1099#1084#1080' '#1082#1072#1088#1090#1072#1084#1080':'
            TabOrder = 0
            object AllOplPlatCardcxDBLabel: TcxDBLabel
              Left = 2
              Top = 15
              Align = alClient
              DataBinding.DataField = 'OPLPLATCARD_ALL_DCHK'
              ParentFont = False
              Properties.Alignment.Horz = taRightJustify
              Properties.Orientation = cxoLeft
              Style.BorderStyle = ebsNone
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clNavy
              Style.Font.Height = -16
              Style.Font.Name = 'MS Sans Serif'
              Style.Font.Style = [fsBold]
              Style.IsFontAssigned = True
              Height = 24
              Width = 273
              AnchorX = 275
            end
          end
          object GroupBox16: TGroupBox
            Left = 287
            Top = -1
            Width = 285
            Height = 41
            Caption = #1042#1089#1077#1075#1086' '#1082#1088#1077#1076#1080#1090#1085#1099#1084#1080' '#1082#1072#1088#1090#1072#1084#1080':'
            TabOrder = 1
            object AllOplCreditCardcxDBLabel: TcxDBLabel
              Left = 2
              Top = 15
              Align = alClient
              DataBinding.DataField = 'OPLCREDITCARD_ALL_DCHK'
              ParentFont = False
              Properties.Alignment.Horz = taRightJustify
              Properties.Orientation = cxoLeft
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clNavy
              Style.Font.Height = -16
              Style.Font.Name = 'MS Sans Serif'
              Style.Font.Style = [fsBold]
              Style.IsFontAssigned = True
              Height = 24
              Width = 281
              AnchorX = 283
            end
          end
        end
        object ToolBar4: TToolBar
          Left = 2
          Top = 15
          Width = 560
          Height = 28
          Caption = 'ToolBar4'
          Color = clCaptionText
          Images = DM.ImageList1
          ParentColor = False
          TabOrder = 2
          object ToolButton1: TToolButton
            Left = 0
            Top = 0
            Width = 9
            Caption = 'ToolButton1'
            ImageIndex = 3
            Style = tbsSeparator
          end
          object ToolButtonAddPrice: TToolButton
            Left = 9
            Top = 0
            Caption = 'ToolButtonAddPrice'
            ImageIndex = 0
          end
          object ToolButtonDeletePrice: TToolButton
            Left = 32
            Top = 0
            Caption = 'ToolButtonDeletePrice'
            ImageIndex = 2
          end
        end
      end
      object Panel7: TPanel
        Left = 0
        Top = 0
        Width = 7
        Height = 299
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 1
      end
      object Panel3: TPanel
        Left = 7
        Top = 0
        Width = 182
        Height = 299
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alLeft
        TabOrder = 2
        object GroupBox13: TGroupBox
          Left = 1
          Top = 1
          Width = 169
          Height = 143
          Caption = #1054#1089#1085#1086#1074#1085#1072#1103' '#1082#1072#1088#1090#1072' '#1086#1087#1083#1072#1090#1099':'
          TabOrder = 0
          object GroupBox11: TGroupBox
            Left = 6
            Top = 14
            Width = 160
            Height = 50
            Caption = #1055#1083#1072#1090#1077#1078#1085#1072#1103' '#1082#1072#1088#1090#1072
            TabOrder = 0
            object OplataPlatCardcxDBCalcEdit: TcxDBCalcEdit
              Left = 13
              Top = 17
              Margins.Left = 2
              Margins.Top = 2
              Margins.Right = 2
              Margins.Bottom = 2
              DataBinding.DataField = 'OPLPLATCARD_DCHK'
              ParentFont = False
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clWindowText
              Style.Font.Height = -19
              Style.Font.Name = 'MS Sans Serif'
              Style.Font.Style = [fsBold]
              Style.IsFontAssigned = True
              TabOrder = 0
              OnKeyPress = OplataPlatCardcxDBCalcEditKeyPress
              Width = 145
            end
          end
          object GroupBox12: TGroupBox
            Left = 6
            Top = 71
            Width = 160
            Height = 53
            Caption = #1050#1088#1077#1076#1080#1090#1085#1072#1103' '#1082#1072#1088#1090#1072
            TabOrder = 1
            object OplataCreditCardcxDBCalcEdit: TcxDBCalcEdit
              Left = 13
              Top = 17
              Margins.Left = 2
              Margins.Top = 2
              Margins.Right = 2
              Margins.Bottom = 2
              DataBinding.DataField = 'OPLCREDITCARD_DCHK'
              ParentFont = False
              Style.Font.Charset = DEFAULT_CHARSET
              Style.Font.Color = clWindowText
              Style.Font.Height = -19
              Style.Font.Name = 'MS Sans Serif'
              Style.Font.Style = [fsBold]
              Style.IsFontAssigned = True
              TabOrder = 0
              OnKeyPress = OplataCreditCardcxDBCalcEditKeyPress
              Width = 145
            end
          end
        end
        object GroupBox1: TGroupBox
          Left = 1
          Top = 149
          Width = 169
          Height = 71
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = #1055#1088#1086#1095#1072#1103' '#1086#1087#1083#1072#1090#1072
          TabOrder = 1
        end
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 344
    Top = 48
    object N14: TMenuItem
      Caption = #1053#1086#1074#1099#1081' '#1095#1077#1082
      GroupIndex = 10
      object NewCheckSale: TMenuItem
        Caption = #1055#1088#1086#1076#1072#1078#1072
        ShortCut = 112
        OnClick = NewCheckSaleClick
      end
      object NewCheckReturnSale: TMenuItem
        Caption = #1042#1086#1079#1074#1088#1072#1090
        ShortCut = 113
        OnClick = NewCheckReturnSaleClick
      end
      object OpenCheck: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1095#1077#1082' '#1087#1088#1086#1076#1072#1078#1080
        ShortCut = 114
        OnClick = OpenCheckClick
      end
      object OpenCheckForVosvratMainMenu: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1095#1077#1082' '#1076#1083#1103' '#1074#1086#1079#1074#1088#1072#1090#1072
        ShortCut = 115
        OnClick = OpenCheckForVosvratMainMenuClick
      end
    end
    object N2: TMenuItem
      Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
      GroupIndex = 10
      object MenuInputCodeBV: TMenuItem
        Caption = #1055#1086' '#1082#1086#1076#1091' '#1041#1042
        ShortCut = 116
        OnClick = MenuInputCodeBVClick
      end
      object MenuInputCodeNom: TMenuItem
        Caption = #1055#1086' '#1082#1086#1076#1091' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
        ShortCut = 117
        OnClick = MenuInputCodeNomClick
      end
      object N8: TMenuItem
        Caption = #1048#1079' '#1089#1087#1088'. '#1041#1042
        ShortCut = 118
        OnClick = N8Click
      end
      object N11: TMenuItem
        Caption = #1048#1079' '#1089#1087#1088'. '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        ShortCut = 119
        OnClick = N11Click
      end
      object AddSvobSum: TMenuItem
        Caption = #1057#1074#1086#1073#1086#1076#1085#1072#1103' '#1089#1091#1084#1084#1072
        ShortCut = 16500
        OnClick = AddSvobSumClick
      end
      object PoBarCode: TMenuItem
        Caption = #1055#1086' '#1064#1050' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
        ShortCut = 45
        OnClick = PoBarCodeClick
      end
      object PoArtikulu: TMenuItem
        Caption = #1055#1086' '#1072#1088#1090#1080#1082#1091#1083#1091
        ShortCut = 16503
        OnClick = PoArtikuluClick
      end
    end
    object N1: TMenuItem
      Caption = #1044#1077#1081#1089#1090#1074#1080#1103
      GroupIndex = 10
      object N4: TMenuItem
        Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1077#1076#1080#1085#1080#1094#1091
        ShortCut = 16474
        OnClick = N4Click
      end
      object DeleteString: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
        ShortCut = 46
        OnClick = DeleteStringClick
      end
      object VibratProjectMainMenu: TMenuItem
        Caption = #1042#1099#1073#1088#1072#1090#1100' '#1087#1088#1086#1077#1082#1090
        ShortCut = 16472
        OnClick = VibratProjectMainMenuClick
      end
    end
    object N3: TMenuItem
      Caption = #1054#1087#1083#1072#1090#1072
      GroupIndex = 10
      object N9: TMenuItem
        Caption = #1053#1072#1083#1080#1095#1085#1099#1077
        ShortCut = 120
        OnClick = N9Click
      end
      object N10: TMenuItem
        Caption = #1055#1083#1072#1090'. '#1082#1072#1088#1090#1072
        ShortCut = 121
        OnClick = N10Click
      end
    end
    object N6: TMenuItem
      Caption = #1057#1082#1080#1076#1082#1080
      GroupIndex = 10
      object ViborDiscCardMainmenu: TMenuItem
        Caption = #1042#1099#1073#1088#1072#1090#1100' '#1082#1072#1088#1090#1091
        ShortCut = 122
        OnClick = ViborDiscCardMainmenuClick
      end
    end
    object N15: TMenuItem
      Caption = #1055#1077#1095#1072#1090#1100
      GroupIndex = 10
      object MenuPrintCheck: TMenuItem
        Caption = #1055#1077#1095#1072#1090#1100' '#1095#1077#1082#1072
        OnClick = MenuPrintCheckClick
      end
      object PrintPovtorCheckOnFR: TMenuItem
        Caption = #1055#1086#1074#1090#1086#1088' '#1095#1077#1082#1072
        ShortCut = 8315
        OnClick = PrintPovtorCheckOnFRClick
      end
      object N12: TMenuItem
        Caption = #1055#1077#1095#1072#1090#1100' '#1090#1086#1074#1072#1088#1085#1086#1075#1086' '#1095#1077#1082#1072
        OnClick = N12Click
      end
      object mmPrintCoodsCheckOnFR: TMenuItem
        Caption = #1055#1077#1095#1072#1090#1100' '#1090#1086#1074#1072#1088#1085#1086#1075#1086' '#1095#1077#1082#1072' '#1085#1072' '#1060#1056
        OnClick = mmPrintCoodsCheckOnFRClick
      end
      object SaveCheckMainMenu: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1095#1077#1082
        ShortCut = 123
        OnClick = SaveCheckMainMenuClick
      end
      object CloseDoc: TMenuItem
        Caption = #1047#1072#1082#1088#1099#1090#1100' '#1095#1077#1082
        ShortCut = 16507
        OnClick = CloseDocClick
      end
    end
    object N7: TMenuItem
      Caption = #1054#1090#1095#1077#1090#1099' '#1050#1050#1052
      GroupIndex = 10
      object PrintXreport: TMenuItem
        Caption = 'X-'#1086#1090#1095#1077#1090
        OnClick = PrintXreportClick
      end
      object PrintZreport: TMenuItem
        Caption = 'Z-'#1086#1090#1095#1077#1090
        OnClick = PrintZreportClick
      end
      object Vnesenie: TMenuItem
        Caption = #1042#1085#1077#1089#1077#1085#1080#1077
        OnClick = VnesenieClick
      end
      object Snatie: TMenuItem
        Caption = #1057#1085#1103#1090#1080#1077
        OnClick = SnatieClick
      end
    end
    object MainMenuExtModule: TMenuItem
      Caption = #1042#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
      GroupIndex = 10
    end
    object N5: TMenuItem
      Caption = #1057#1077#1088#1074#1080#1089
      GroupIndex = 10
      object N13: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1085#1072#1089#1090#1088#1086#1081#1082#1080
        OnClick = N13Click
      end
    end
  end
  object ActionList1: TActionList
    Left = 416
    Top = 48
    object OpenHelp: TAction
      Caption = 'OpenHelp'
    end
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
    object ActionSetMainTabScheet: TAction
      Caption = 'ActionSetMainTabScheet'
      ShortCut = 16474
      OnExecute = ActionSetMainTabScheetExecute
    end
    object ActionSetOplataTabScheet: TAction
      Caption = 'ActionSetOplataTabScheet'
      ShortCut = 16472
      OnExecute = ActionSetOplataTabScheetExecute
    end
  end
end
