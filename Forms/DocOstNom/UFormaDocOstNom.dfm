object FormaDocOstNom: TFormaDocOstNom
  Left = 252
  Top = 265
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1042#1074#1086#1076' '#1086#1089#1090#1072#1090#1082#1086#1074'"'
  ClientHeight = 538
  ClientWidth = 838
  Color = clBtnFace
  Constraints.MinWidth = 848
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnActivate = FormActivate
  OnClose = FormClose
  OnDeactivate = FormDeactivate
  PixelsPerInch = 120
  TextHeight = 16
  object Panel2: TPanel
    Left = 0
    Top = 442
    Width = 838
    Height = 96
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object NameUserDBText: TDBText
      Left = 20
      Top = 10
      Width = 152
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'FNAME_USER'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 236
      Top = 7
      Width = 155
      Height = 24
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1090#1086#1083#1100#1082#1086' '#1087#1088#1086#1089#1084#1086#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -18
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonPoGrp: TcxButton
      Left = 79
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1086' '#1075#1088#1091#1087#1087#1072#1084
      TabOrder = 0
      OnClick = cxButtonPoGrpClick
    end
    object cxButtonPrint: TcxButton
      Left = 178
      Top = 49
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 1
    end
    object cxButtonSave: TcxButton
      Left = 281
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 2
    end
    object cxButtonDvReg: TcxButton
      Left = 380
      Top = 49
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 3
    end
    object cxButtonOK: TcxButton
      Left = 480
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 4
    end
    object cxButtonClose: TcxButton
      Left = 580
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      Cancel = True
      TabOrder = 5
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 218
    Width = 11
    Height = 224
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 827
    Top = 218
    Width = 11
    Height = 224
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 838
    Height = 218
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    ExplicitTop = -8
    object Label1: TLabel
      Left = 2
      Top = 114
      Width = 199
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1042#1074#1086#1076' '#1086#1089#1090#1072#1090#1082#1086#1074'  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 463
      Top = 110
      Width = 40
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1086#1090' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 11
      Top = 171
      Width = 86
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label5: TLabel
      Left = 20
      Top = 80
      Width = 47
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
    end
    object Label6: TLabel
      Left = 482
      Top = 36
      Width = 43
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1082#1083#1072#1076':'
    end
    object Label4: TLabel
      Left = 449
      Top = 150
      Width = 152
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1094#1077#1085' '#1087#1088#1080#1086#1073#1088#1077#1090#1077#1085#1080#1103':'
    end
    object DocOsnLabel: TLabel
      Left = 11
      Top = 201
      Width = 83
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'DocOsnLabel'
    end
    object TypeRPriceLabel: TLabel
      Left = 463
      Top = 188
      Width = 138
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1094#1077#1085' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080':'
    end
    object Label7: TLabel
      Left = 20
      Top = 64
      Width = 52
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1073#1098#1077#1082#1090':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 838
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 11
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 17
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonInsert: TToolButton
        Left = 17
        Top = 0
        Action = ActionAddRecord
      end
      object ToolButtonDelete: TToolButton
        Left = 40
        Top = 0
        Action = ActionDeleteRecord
      end
      object ToolButton6: TToolButton
        Left = 63
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButton6'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton2: TToolButton
        Left = 86
        Top = 0
        Width = 82
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonAddPrice: TToolButton
        Left = 168
        Top = 0
        Hint = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1094#1077#1085#1099
        Caption = 'ToolButtonAddPrice'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddPriceClick
      end
      object ToolButton5: TToolButton
        Left = 191
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1088#1086#1082#1080' '#1075#1086#1076#1085#1086#1089#1090#1080' '#1080#1079' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072'"'
        Caption = 'ToolButton5'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton5Click
      end
      object ToolButton3: TToolButton
        Left = 214
        Top = 0
        Width = 113
        Caption = 'ToolButton3'
        ImageIndex = 0
        Style = tbsSeparator
      end
      object ToolButton4: TToolButton
        Left = 327
        Top = 0
        Width = 8
        Caption = 'ToolButton4'
        ImageIndex = 1
        Style = tbsSeparator
      end
      object ToolButtonAddOstatki: TToolButton
        Left = 335
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1086#1089#1090#1072#1090#1082#1080' '#1089#1086' '#1089#1082#1083#1072#1076#1072
        Caption = 'ToolButtonAddOstatki'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddOstatkiClick
      end
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 87
      Top = 85
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEFIRM'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameFirmcxDBButtonEditPropertiesButtonClick
      TabOrder = 0
      Width = 261
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 87
      Top = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SINFBASE_OBMEN'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameInfBasecxDBButtonEditPropertiesButtonClick
      TabOrder = 1
      Width = 261
    end
    object cxLabel1: TcxLabel
      Left = 5
      Top = 44
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 348
      Top = 114
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMDOC'
      TabOrder = 6
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 107
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 497
      Top = 114
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POSDOC'
      Properties.Kind = ckDateTime
      TabOrder = 7
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 208
    end
    object NameSkladcxDBButtonEdit: TcxDBButtonEdit
      Left = 533
      Top = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMESKLAD'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameSkladcxDBButtonEditPropertiesButtonClick
      TabOrder = 2
      Width = 289
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 100
      Top = 167
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PRIMOSN'
      TabOrder = 10
      OnKeyDown = PrimcxDBTextEditKeyDown
      Width = 325
    end
    object TypePriceComboBox: TcxComboBox
      Left = 601
      Top = 150
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.OnChange = TypePriceComboBoxPropertiesChange
      TabOrder = 8
      Text = 'TypePriceComboBox'
      Width = 220
    end
    object TypeRPriceComboBox: TcxComboBox
      Left = 601
      Top = 183
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.OnChange = TypeRPriceComboBoxPropertiesChange
      TabOrder = 9
      Text = 'TypeRPriceComboBox'
      Width = 220
    end
    object EditPropPartcxButton: TcxButton
      Left = 729
      Top = 112
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1072#1088#1090#1080#1103
      TabOrder = 13
      OnClick = EditPropPartcxButtonClick
    end
    object cxLabel9: TcxLabel
      Left = 404
      Top = 60
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
    end
    object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
      Left = 533
      Top = 59
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SBUSINESS_OPER'
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
      Properties.OnButtonClick = NameBusinessOpercxDBButtonEditPropertiesButtonClick
      TabOrder = 3
      Width = 288
    end
    object NameProjectcxDBButtonEdit: TcxDBButtonEdit
      Left = 533
      Top = 85
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SPROJECT'
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
      Properties.OnButtonClick = NameProjectcxDBButtonEditPropertiesButtonClick
      TabOrder = 4
      Width = 288
    end
    object cxLabel3: TcxLabel
      Left = 470
      Top = 86
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1086#1077#1082#1090':'
    end
    object PrefiksNumcxDBTextEdit: TcxDBTextEdit
      Left = 199
      Top = 114
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PREFIKS_NUM_GALLDOC'
      TabOrder = 5
      Width = 145
    end
    object NameObjectcxDBButtonEdit: TcxDBButtonEdit
      Left = 87
      Top = 59
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SOBJECT'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameObjectcxDBButtonEditPropertiesButtonClick
      TabOrder = 16
      Width = 261
    end
  end
  object TablecxPageControl: TcxPageControl
    Left = 11
    Top = 218
    Width = 816
    Height = 224
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = MaincxTabSheet
    Align = alClient
    TabOrder = 4
    ClientRectBottom = 224
    ClientRectRight = 816
    ClientRectTop = 27
    object MaincxTabSheet: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103' (F5)'
      ImageIndex = 0
      object cxGrid1: TcxGrid
        Left = 0
        Top = 0
        Width = 816
        Height = 197
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        TabOrder = 0
        object cxGrid1DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <
            item
              Kind = skSum
              Column = cxGrid1DBTableView1SUMOSNT
            end
            item
              Kind = skSum
              Column = cxGrid1DBTableView1RSUM_DOSNT
            end
            item
              Kind = skSum
              FieldName = 'SUMNDS_DOSNT'
              Column = cxGrid1DBTableView1SUMNDS_DOSNT
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsBehavior.GoToNextCellOnEnter = True
          OptionsBehavior.IncSearch = True
          OptionsCustomize.ColumnsQuickCustomization = True
          OptionsSelection.InvertSelect = False
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.Footer = True
          Styles.Footer = DM.cxStyleHeaderTable
          Styles.Header = DM.cxStyleHeaderTable
          object cxGrid1DBTableView1RECNO: TcxGridDBColumn
            Caption = #8470
            DataBinding.FieldName = 'RECNO'
            Options.Editing = False
            Styles.Header = DM.cxStyleHeaderTable
            Width = 29
          end
          object cxGrid1DBTableView1ARTNOM: TcxGridDBColumn
            Caption = #1040#1088#1090'.'
            DataBinding.FieldName = 'ARTNOM'
            Width = 42
          end
          object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
            Caption = #1050#1086#1076
            DataBinding.FieldName = 'CODENOM'
            Width = 30
          end
          object cxGrid1DBTableView1NAME_TYPE_NOM_LOOCUP: TcxGridDBColumn
            Caption = #1058#1080#1087
            DataBinding.FieldName = 'NAME_TYPE_NOM_LOOCUP'
            Width = 44
          end
          object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
            Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
            DataBinding.FieldName = 'NAMENOM'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.ReadOnly = True
            Properties.OnButtonClick = cxGrid1DBTableView1NAMENOMPropertiesButtonClick
            Styles.Header = DM.cxStyleHeaderTable
            Width = 149
          end
          object cxGrid1DBTableView1KOLOSNT: TcxGridDBColumn
            Caption = #1050#1086#1083'.'
            DataBinding.FieldName = 'KOLOSNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Precision = 15
            Styles.Header = DM.cxStyleHeaderTable
            Width = 38
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
            Styles.Header = DM.cxStyleHeaderTable
            Width = 28
          end
          object cxGrid1DBTableView1SHED: TcxGridDBColumn
            Caption = #1064#1050
            DataBinding.FieldName = 'SHED'
            Width = 39
          end
          object cxGrid1DBTableView1KFOSNT: TcxGridDBColumn
            Caption = #1050
            DataBinding.FieldName = 'KFOSNT'
            Options.Editing = False
            Styles.Header = DM.cxStyleHeaderTable
            Width = 21
          end
          object cxGrid1DBTableView1PRICEOSNT: TcxGridDBColumn
            Caption = #1062#1077#1085#1072
            DataBinding.FieldName = 'PRICEOSNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Precision = 15
            Styles.Header = DM.cxStyleHeaderTable
            Width = 59
          end
          object cxGrid1DBTableView1SUMOSNT: TcxGridDBColumn
            Caption = #1057#1091#1084#1084#1072
            DataBinding.FieldName = 'SUMOSNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Precision = 15
            Styles.Header = DM.cxStyleHeaderTable
            Width = 55
          end
          object cxGrid1DBTableView1NDS_DOSNT: TcxGridDBColumn
            Caption = #1053#1044#1057
            DataBinding.FieldName = 'NDS_DOSNT'
            RepositoryItem = DM.cxEditRepository1ImageComboBoxNDS
            Width = 45
          end
          object cxGrid1DBTableView1SUMNDS_DOSNT: TcxGridDBColumn
            Caption = #1057#1091#1084#1084#1072' '#1053#1044#1057
            DataBinding.FieldName = 'SUMNDS_DOSNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Precision = 15
            Width = 54
          end
          object cxGrid1DBTableView1NAC_DOSNT: TcxGridDBColumn
            Caption = '%'
            DataBinding.FieldName = 'NAC_DOSNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.OnValidate = cxGrid1DBTableView1NAC_DOSNTPropertiesValidate
            Styles.Header = DM.cxStyleHeaderTable
            Width = 35
          end
          object cxGrid1DBTableView1RPRICE_DOSNT: TcxGridDBColumn
            Caption = #1056#1086#1079#1085'. '#1094#1077#1085#1072
            DataBinding.FieldName = 'RPRICE_DOSNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Precision = 15
            Styles.Header = DM.cxStyleHeaderTable
            Width = 68
          end
          object cxGrid1DBTableView1RSUM_DOSNT: TcxGridDBColumn
            Caption = #1056#1086#1079#1085'. '#1089#1091#1084#1084#1072
            DataBinding.FieldName = 'RSUM_DOSNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Properties.Precision = 15
            Styles.Header = DM.cxStyleHeaderTable
            Width = 66
          end
        end
        object cxGrid1Level1: TcxGridLevel
          GridView = cxGrid1DBTableView1
        end
      end
    end
    object AdditionallycxTabSheet: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1087#1086#1083#1085'. (F6)'
      ImageIndex = 1
      object cxGrid2: TcxGrid
        Left = 0
        Top = 0
        Width = 816
        Height = 197
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
          DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsBehavior.IncSearch = True
          OptionsSelection.InvertSelect = False
          OptionsView.ColumnAutoWidth = True
          Styles.Header = DM.cxStyleHeaderTable
          Bands = <
            item
            end>
          object cxGrid2DBBandedTableView1RECNO: TcxGridDBBandedColumn
            Caption = #8470
            DataBinding.FieldName = 'RECNO'
            Width = 22
            Position.BandIndex = 0
            Position.ColIndex = 0
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1NAMENOM: TcxGridDBBandedColumn
            Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
            DataBinding.FieldName = 'NAMENOM'
            Options.Editing = False
            Width = 173
            Position.BandIndex = 0
            Position.ColIndex = 1
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1KOLOSNT: TcxGridDBBandedColumn
            Caption = #1050#1086#1083'.'
            DataBinding.FieldName = 'KOLOSNT'
            Options.Editing = False
            Width = 35
            Position.BandIndex = 0
            Position.ColIndex = 2
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1KFOSNT: TcxGridDBBandedColumn
            Caption = #1050#1060
            DataBinding.FieldName = 'KFOSNT'
            Options.Editing = False
            Width = 25
            Position.BandIndex = 0
            Position.ColIndex = 3
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1NAMEED: TcxGridDBBandedColumn
            Caption = #1045#1076#1080#1085#1080#1094#1072
            DataBinding.FieldName = 'NAMEED'
            Options.Editing = False
            Width = 41
            Position.BandIndex = 0
            Position.ColIndex = 4
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1SRGODNPART: TcxGridDBBandedColumn
            Caption = #1057#1088#1086#1082' '#1075#1086#1076#1085#1086#1089#1090#1080
            DataBinding.FieldName = 'SRGODNPART'
            PropertiesClassName = 'TcxDateEditProperties'
            Properties.Kind = ckDateTime
            Width = 82
            Position.BandIndex = 0
            Position.ColIndex = 5
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1GTDPART: TcxGridDBBandedColumn
            Caption = #1043#1058#1044
            DataBinding.FieldName = 'GTDPART'
            Width = 160
            Position.BandIndex = 0
            Position.ColIndex = 6
            Position.RowIndex = 0
          end
          object cxGrid2DBBandedTableView1SERTPART: TcxGridDBBandedColumn
            Caption = #1057#1077#1088#1090#1080#1092#1080#1082#1072#1090
            DataBinding.FieldName = 'SERTPART'
            Width = 123
            Position.BandIndex = 0
            Position.ColIndex = 7
            Position.RowIndex = 0
          end
        end
        object cxGrid2Level1: TcxGridLevel
          GridView = cxGrid2DBBandedTableView1
        end
      end
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 16
    Top = 80
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionAddRecord: TAction
      Caption = 'ActionAddRecord'
      ImageIndex = 0
      ShortCut = 45
      OnExecute = ActionAddRecordExecute
    end
    object ActionDeleteRecord: TAction
      Caption = 'ActionDeleteRecord'
      ImageIndex = 2
      ShortCut = 46
      OnExecute = ActionDeleteRecordExecute
    end
    object ActionSetMainTabSheet: TAction
      Caption = 'ActionSetMainTabSheet'
      ShortCut = 116
      OnExecute = ActionSetMainTabSheetExecute
    end
    object ActionSetAdditionallyTabSheet: TAction
      Caption = 'ActionSetAdditionallyTabSheet'
      ShortCut = 117
      OnExecute = ActionSetAdditionallyTabSheetExecute
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
    object ActionDvReg: TAction
      Caption = #1055#1088#1086#1074#1077#1089#1090#1080
      ImageIndex = 56
      OnExecute = ActionDvRegExecute
    end
    object ActionSave: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveExecute
    end
    object ActionPrint: TAction
      Caption = #1055#1077#1095#1072#1090#1100
      ImageIndex = 43
      OnExecute = ActionPrintExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 96
    Top = 8
  end
end
