object REM_FormaInfoPriem: TREM_FormaInfoPriem
  Left = 268
  Top = 221
  Caption = #1056#1077#1084#1086#1085#1090', '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1084#1086#1076#1077#1083#1080':'
  ClientHeight = 597
  ClientWidth = 1098
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
  WindowState = wsMaximized
  OnActivate = FormActivate
  OnClose = FormClose
  OnDeactivate = FormDeactivate
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1098
    Height = 257
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object Label27: TLabel
      Left = 433
      Top = 33
      Width = 72
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1086#1080#1079#1074'-'#1083#1100':'
    end
    object Label28: TLabel
      Left = 414
      Top = 57
      Width = 91
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1052#1086#1076#1077#1083#1100' '#1087#1088'-'#1083#1103':'
    end
    object Label16: TLabel
      Left = 25
      Top = 33
      Width = 108
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087#1099' '#1091#1089#1090#1088#1086#1081#1089#1090#1074':'
    end
    object Label2: TLabel
      Left = 797
      Top = 33
      Width = 44
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1041#1088#1077#1085#1076':'
    end
    object Label3: TLabel
      Left = 11
      Top = 57
      Width = 122
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1043#1088#1091#1087#1087#1099' '#1091#1089#1090#1088#1086#1081#1089#1090#1074':'
    end
    object Label4: TLabel
      Left = 60
      Top = 73
      Width = 63
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1052#1086#1076#1077#1083#1100' 2:'
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 1098
      Height = 26
      ButtonHeight = 23
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonAddNewZ: TToolButton
        Left = 8
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1085#1086#1074#1091#1102' '#1079#1072#1103#1074#1082#1091
        Caption = 'ToolButtonAddNewZ'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddNewZClick
      end
      object ToolButtonCreateZayavkaPredv: TToolButton
        Left = 31
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1087#1088#1077#1076#1074#1072#1088#1080#1090#1077#1083#1100#1085#1091#1102' '#1079#1072#1103#1074#1082#1091
        Caption = 'ToolButtonCreateZayavkaPredv'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateZayavkaPredvClick
      end
      object ToolButton2: TToolButton
        Left = 54
        Top = 0
        Width = 82
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButtonOpenDoc: TToolButton
        Left = 136
        Top = 0
        Caption = 'ToolButtonOpenDoc'
        ImageIndex = 1
        OnClick = ToolButtonOpenDocClick
      end
      object ToolButton4: TToolButton
        Left = 159
        Top = 0
        Width = 64
        Caption = 'ToolButton4'
        ImageIndex = 0
        Style = tbsSeparator
      end
      object ToolButtonOpenExtModule: TToolButton
        Left = 223
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonOpenExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonOpenGurAllDoc: TToolButton
        Left = 246
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090#1099' '#1087#1086' '#1079#1072#1103#1074#1082#1077
        Caption = 'ToolButtonOpenGurAllDoc'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenGurAllDocClick
      end
      object ToolButtonCopyZayavka: TToolButton
        Left = 269
        Top = 0
        Hint = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1079#1072#1103#1074#1082#1091
        Caption = 'ToolButtonCopyZayavka'
        ImageIndex = 52
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCopyZayavkaClick
      end
      object ToolButtonCreateNaOsnSprHardware: TToolButton
        Left = 292
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1085#1086#1074#1091#1102' '#1079#1072#1103#1074#1082#1091' '#1085#1072' '#1086#1089#1085#1086#1074#1077' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' '#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077
        Caption = 'ToolButtonCreateNaOsnSprHardware'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateNaOsnSprHardwareClick
      end
      object ToolButtonZapShapkuNaOsnZayavki: TToolButton
        Left = 315
        Top = 0
        Hint = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1096#1072#1087#1082#1091' '#1085#1072' '#1086#1089#1085#1086#1074#1072#1085#1080#1080' '#1090#1077#1082#1091#1097#1077#1081' '#1079#1072#1103#1074#1082#1080
        Caption = 'ToolButtonZapShapkuNaOsnZayavki'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonZapShapkuNaOsnZayavkiClick
      end
    end
    object ModelcxTextEdit: TcxTextEdit
      Left = 860
      Top = 74
      TabOrder = 1
      Text = 'ModelcxTextEdit'
      Width = 201
    end
    object SerNumcxTextEdit: TcxTextEdit
      Left = 181
      Top = 119
      TabOrder = 3
      Text = 'SerNumcxTextEdit'
      Width = 201
    end
    object cxLabel1: TcxLabel
      Left = 23
      Top = 120
      Caption = #1047#1072#1074#1086#1076#1089#1082#1086#1081' '#1085#1086#1084#1077#1088':'
    end
    object cxLabel2: TcxLabel
      Left = 23
      Top = 146
      Caption = #1047#1072#1074#1086#1076#1089#1082#1086#1081' '#1085#1086#1084#1077#1088' 2:'
    end
    object SerNum2cxTextEdit: TcxTextEdit
      Left = 181
      Top = 149
      TabOrder = 6
      Text = 'SerNum2cxTextEdit'
      Width = 201
    end
    object NameHardwarecxButtonEdit: TcxButtonEdit
      Left = 771
      Top = 156
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameHardwarecxButtonEditPropertiesButtonClick
      TabOrder = 7
      Text = 'NameHardwarecxButtonEdit'
      Width = 312
    end
    object cxLabel5: TcxLabel
      Left = 646
      Top = 156
      Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077':'
    end
    object cxLabel3: TcxLabel
      Left = 749
      Top = 130
      Caption = #1050#1083#1080#1077#1085#1090':'
    end
    object KlientNamecxTextEdit: TcxTextEdit
      Left = 821
      Top = 129
      TabOrder = 10
      Text = 'KlientNamecxTextEdit'
      Width = 201
    end
    object cxButtonPoiskPoSerNum: TcxButton
      Left = 436
      Top = 119
      Width = 177
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1079#1072#1074'. '#1085#1086#1084#1077#1088#1091
      TabOrder = 11
      OnClick = cxButtonPoiskPoSerNumClick
    end
    object cxButtonPoiskPoSerNum2: TcxButton
      Left = 436
      Top = 150
      Width = 177
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1079#1072#1074'. '#1085#1086#1084#1077#1088#1091' 2'
      TabOrder = 12
      OnClick = cxButtonPoiskPoSerNum2Click
    end
    object NumGarDoccxTextEdit: TcxTextEdit
      Left = 181
      Top = 179
      TabOrder = 2
      Text = 'NumGarDoccxTextEdit'
      Width = 201
    end
    object cxLabel6: TcxLabel
      Left = 3
      Top = 172
      Caption = #1053#1086#1084#1077#1088' '#1075#1072#1088'. '#1076#1086#1082#1091#1084#1077#1085#1090#1072':'
    end
    object cxButtonPoNumGarDoc: TcxButton
      Left = 436
      Top = 181
      Width = 177
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1085#1086#1084#1077#1088#1091' '#1075#1072#1088'. '#1076#1086#1082'.'
      TabOrder = 14
      OnClick = cxButtonPoNumGarDocClick
    end
    object cxCheckBoxIspSprHardware: TcxCheckBox
      Left = 8
      Top = 209
      Caption = #1080#1089#1087#1086#1083#1100#1079#1086#1074#1072#1090#1100' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077
      TabOrder = 15
      Width = 330
    end
    object cxLabelHint: TcxLabel
      Left = 25
      Top = 235
      Caption = 'cxLabelHint'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clRed
      Style.Font.Height = -13
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
    end
    object cxLabelSerNum1: TcxLabel
      Left = 678
      Top = 186
      Caption = 'cxLabelSerNum1'
    end
    object cxLabelSerNum2: TcxLabel
      Left = 940
      Top = 186
      Caption = 'cxLabelSerNum2'
    end
    object NameSkladcxButtonEdit: TcxButtonEdit
      Left = 867
      Top = 202
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
      Properties.OnButtonClick = NameSkladcxButtonEditPropertiesButtonClick
      TabOrder = 19
      Text = 'NameSkladcxButtonEdit'
      Width = 216
    end
    object cxLabel7: TcxLabel
      Left = 791
      Top = 203
      Caption = #1057#1082#1083#1072#1076':'
    end
    object ProducercxLookupComboBox: TcxLookupComboBox
      Left = 512
      Top = 32
      Properties.KeyFieldNames = 'ID_SPRODUCER'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_SPRODUCER'
        end>
      Properties.OnChange = ProducercxLookupComboBoxPropertiesChange
      TabOrder = 21
      Width = 257
    end
    object BrandcxLookupComboBox: TcxLookupComboBox
      Left = 848
      Top = 32
      Properties.KeyFieldNames = 'ID_SBRAND'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_SBRAND'
        end>
      TabOrder = 22
      Width = 213
    end
    object GroupcxLookupComboBox: TcxLookupComboBox
      Left = 512
      Top = 56
      Properties.KeyFieldNames = 'ID_REM_SPRMODEL_GRP'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_REM_SPRMODEL_GRP'
        end>
      Properties.OnChange = GroupcxLookupComboBoxPropertiesChange
      TabOrder = 23
      Width = 257
    end
    object PrModelcxLookupComboBox: TcxLookupComboBox
      Left = 512
      Top = 80
      Properties.KeyFieldNames = 'ID_REM_SPRMODEL'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_REM_SPRMODEL'
        end>
      TabOrder = 24
      Width = 257
    end
    object cxLabel4: TcxLabel
      Left = 797
      Top = 75
      Caption = #1052#1086#1076#1077#1083#1100':'
    end
    object TypeDevice2cxLookupComboBox: TcxLookupComboBox
      Left = 140
      Top = 32
      Properties.KeyFieldNames = 'ID_REM_STYPEDEVICE'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_REM_STYPEDEVICE'
        end>
      Properties.OnChange = TypeDevice2cxLookupComboBoxPropertiesChange
      TabOrder = 26
      Width = 267
    end
    object GroupModel2cxLookupComboBox: TcxLookupComboBox
      Left = 140
      Top = 56
      Properties.KeyFieldNames = 'ID_REM_SMODEL2_GRP'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_REM_SMODEL2_GRP'
        end>
      Properties.OnChange = GroupModel2cxLookupComboBoxPropertiesChange
      TabOrder = 27
      Width = 267
    end
    object Model2cxLookupComboBox: TcxLookupComboBox
      Left = 140
      Top = 80
      Properties.KeyFieldNames = 'ID_REM_SMODEL2'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_REM_SMODEL2'
        end>
      TabOrder = 28
      Width = 267
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 257
    Width = 4
    Height = 317
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 574
    Width = 1098
    Height = 23
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 1083
    Top = 257
    Width = 15
    Height = 317
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object cxPageControl1: TcxPageControl
    Left = 4
    Top = 257
    Width = 1079
    Height = 317
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 4
    ClientRectBottom = 317
    ClientRectRight = 1079
    ClientRectTop = 27
    object cxTabSheet1: TcxTabSheet
      Caption = #1046#1091#1088#1085#1072#1083
      ImageIndex = 0
      object cxGrid1: TcxGrid
        Left = 0
        Top = 0
        Width = 1079
        Height = 290
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Align = alClient
        TabOrder = 0
        LevelTabs.Style = 8
        object cxGrid1DBTableView1: TcxGridDBTableView
          OnDblClick = cxGrid1DBTableView1DblClick
          OnKeyPress = cxGrid1DBTableView1KeyPress
          NavigatorButtons.ConfirmDelete = False
          DataController.DataSource = REM_DMGurZ.DataSourceTable
          DataController.Summary.DefaultGroupSummaryItems = <
            item
            end>
          DataController.Summary.FooterSummaryItems = <
            item
              Kind = skCount
              FieldName = 'ID_REM_Z'
              Column = cxGrid1DBTableView1OUT_KLIENT_NAME
            end
            item
              Kind = skSum
              FieldName = 'SUM_REM_Z'
              Column = cxGrid1DBTableView1OUT_SUM
            end>
          DataController.Summary.SummaryGroups = <
            item
              Links = <
                item
                  Column = cxGrid1DBTableView1OUT_SUM
                end>
              SummaryItems = <
                item
                end>
            end>
          OptionsBehavior.IncSearch = True
          OptionsCustomize.ColumnsQuickCustomization = True
          OptionsData.Deleting = False
          OptionsData.DeletingConfirmation = False
          OptionsData.Editing = False
          OptionsData.Inserting = False
          OptionsView.ShowEditButtons = gsebForFocusedRecord
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.Footer = True
          OptionsView.GroupByBox = False
          Styles.Header = DM.cxStyleHeaderTable
          object cxGrid1DBTableView1OUT_TYPE_TABLE: TcxGridDBColumn
            DataBinding.FieldName = 'OUT_TYPE_TABLE'
            Width = 21
          end
          object cxGrid1DBTableView1GOTOVO_K_VIDACHE_REM_Z: TcxGridDBColumn
            Caption = #1043#1086#1090#1086#1074#1086' '#1082' '#1074#1099#1076#1072#1095#1077
            DataBinding.FieldName = 'OUT_GOTOVO_K_VIDACHE'
            OnCustomDrawCell = cxGrid1DBTableView1GOTOVO_K_VIDACHE_REM_ZCustomDrawCell
            Width = 23
          end
          object cxGrid1DBTableView1OUT_OUT: TcxGridDBColumn
            Caption = #1042#1099#1087'.'
            DataBinding.FieldName = 'OUT_OUT'
            OnCustomDrawCell = cxGrid1DBTableView1OUT_OUTCustomDrawCell
            Width = 22
          end
          object cxGrid1DBTableView1OUT_FL_POVTOR: TcxGridDBColumn
            Caption = #1055#1086#1074#1090#1086#1088
            DataBinding.FieldName = 'OUT_FL_POVTOR'
            PropertiesClassName = 'TcxCheckBoxProperties'
            Properties.ValueChecked = 1
            Properties.ValueUnchecked = 0
            Width = 61
          end
          object cxGrid1DBTableView1OUT_NAME_SKLAD: TcxGridDBColumn
            DataBinding.FieldName = 'OUT_NAME_SKLAD'
            Width = 100
          end
          object cxGrid1DBTableView1OUT_NAME_SBRAND: TcxGridDBColumn
            Caption = #1041#1088#1077#1085#1076
            DataBinding.FieldName = 'OUT_NAME_SBRAND'
            Width = 63
          end
          object cxGrid1DBTableView1OUT_NAME_STREMONT: TcxGridDBColumn
            Caption = #1058#1080#1087
            DataBinding.FieldName = 'OUT_NAME_STREMONT'
            Width = 67
          end
          object cxGrid1DBTableView1OUT_PREFIKS_NUM: TcxGridDBColumn
            Caption = #1055#1088#1077#1092#1080#1082#1089
            DataBinding.FieldName = 'OUT_PREFIKS_NUM'
            Width = 35
          end
          object cxGrid1DBTableView1OUT_NUM: TcxGridDBColumn
            Caption = #8470
            DataBinding.FieldName = 'OUT_NUM'
            Width = 60
          end
          object cxGrid1DBTableView1OUT_POS: TcxGridDBColumn
            Caption = #1044#1072#1090#1072
            DataBinding.FieldName = 'OUT_POS'
            Width = 128
          end
          object cxGrid1DBTableView1OUT_NAME_REM_SMODEL: TcxGridDBColumn
            Caption = #1052#1086#1076#1077#1083#1100
            DataBinding.FieldName = 'OUT_NAME_REM_SMODEL'
            Width = 97
          end
          object cxGrid1DBTableView1OUT_MODEL: TcxGridDBColumn
            Caption = #1052#1086#1076#1077#1083#1100
            DataBinding.FieldName = 'OUT_MODEL'
            Width = 120
          end
          object cxGrid1DBTableView1OUT_SERNUM1: TcxGridDBColumn
            Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088
            DataBinding.FieldName = 'OUT_SERNUM1'
            Width = 124
          end
          object cxGrid1DBTableView1OUT_SERNUM2: TcxGridDBColumn
            Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088' 2'
            DataBinding.FieldName = 'OUT_SERNUM2'
            Width = 111
          end
          object cxGrid1DBTableView1OUT_NAME_REMSSOST: TcxGridDBColumn
            Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
            DataBinding.FieldName = 'OUT_NAME_REMSSOST'
            Width = 109
          end
          object cxGrid1DBTableView1OUT_SUM: TcxGridDBColumn
            Caption = #1057#1091#1084#1084#1072
            DataBinding.FieldName = 'OUT_SUM'
            Width = 61
          end
          object cxGrid1DBTableView1OUT_KLIENT_NAME: TcxGridDBColumn
            Caption = #1050#1083#1080#1077#1085#1090
            DataBinding.FieldName = 'OUT_KLIENT_NAME'
            Width = 179
          end
        end
        object cxGrid1Level1: TcxGridLevel
          GridView = cxGrid1DBTableView1
        end
      end
    end
    object cxTabSheet3: TcxTabSheet
      Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103
      ImageIndex = 2
      object Panel8: TPanel
        Left = 0
        Top = 0
        Width = 1079
        Height = 41
        Align = alTop
        BevelOuter = bvNone
        Caption = 'Panel8'
        TabOrder = 0
        object cxButtonUpdateInfblock: TcxButton
          Left = 19
          Top = 9
          Width = 177
          Height = 25
          Caption = #1054#1073#1085#1086#1074#1080#1090#1100
          TabOrder = 0
          OnClick = cxButtonUpdateInfblockClick
        end
      end
      object cxGrid5: TcxGrid
        Left = 0
        Top = 41
        Width = 1079
        Height = 249
        Align = alClient
        TabOrder = 1
        object InfocxGridDBTableView: TcxGridDBTableView
          OnDblClick = InfocxGridDBTableViewDblClick
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsData.CancelOnExit = False
          OptionsData.Deleting = False
          OptionsData.DeletingConfirmation = False
          OptionsData.Editing = False
          OptionsData.Inserting = False
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          Styles.Header = DM.cxStyleHeaderTable
          object InfocxGridDBTableViewOUT_ISTOCHNIK: TcxGridDBColumn
            Caption = #1048#1089#1090#1086#1095#1085#1080#1082
            DataBinding.FieldName = 'OUT_ISTOCHNIK'
            RepositoryItem = DM.cxEditRepository1ImageComboBoxItemOUT_ISTOCHNIK
            Width = 128
          end
          object InfocxGridDBTableViewOUT_NAME_MODEL: TcxGridDBColumn
            Caption = #1052#1086#1076#1077#1083#1100
            DataBinding.FieldName = 'OUT_NAME_MODEL'
            Width = 147
          end
          object InfocxGridDBTableViewOUT_NAME_PRMODEL: TcxGridDBColumn
            Caption = #1052#1086#1076#1077#1083#1100' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103
            DataBinding.FieldName = 'OUT_NAME_PRMODEL'
            Width = 128
          end
          object InfocxGridDBTableViewOUT_NAME_GRP_INFO: TcxGridDBColumn
            Caption = #1043#1088#1091#1087#1087#1072
            DataBinding.FieldName = 'OUT_NAME_GRP_INFO'
            Width = 141
          end
          object InfocxGridDBTableViewOUT_NAME: TcxGridDBColumn
            Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
            DataBinding.FieldName = 'OUT_NAME'
            Width = 205
          end
          object InfocxGridDBTableViewOUT_INFO_VALUE_IS_SPR: TcxGridDBColumn
            Caption = #1048#1085#1092'. '#1080#1079' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072
            DataBinding.FieldName = 'OUT_INFO_VALUE_IS_SPR'
            Width = 256
          end
          object InfocxGridDBTableViewOUT_INFO_TEXT: TcxGridDBColumn
            Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103
            DataBinding.FieldName = 'OUT_INFO_TEXT'
            Width = 388
          end
        end
        object cxGridLevel3: TcxGridLevel
          GridView = InfocxGridDBTableView
        end
      end
    end
    object cxTabSheet5: TcxTabSheet
      Caption = #1047#1072#1087#1095#1072#1089#1090#1080' / '#1088#1072#1073#1086#1090#1099
      ImageIndex = 4
      object Panel6: TPanel
        Left = 0
        Top = 0
        Width = 1079
        Height = 57
        Align = alTop
        BevelOuter = bvNone
        Caption = 'Panel6'
        TabOrder = 0
        object cxButtonUpdatePrInfBlock: TcxButton
          Left = 19
          Top = 9
          Width = 177
          Height = 25
          Caption = #1054#1073#1085#1086#1074#1080#1090#1100
          TabOrder = 0
          OnClick = cxButtonUpdatePrInfBlockClick
        end
      end
      object cxGrid3: TcxGrid
        Left = 0
        Top = 57
        Width = 1079
        Height = 233
        Align = alClient
        TabOrder = 1
        object ZipcxGrid3DBTableView: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsData.CancelOnExit = False
          OptionsData.Deleting = False
          OptionsData.DeletingConfirmation = False
          OptionsData.Editing = False
          OptionsData.Inserting = False
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          Styles.Header = DM.cxStyleHeaderTable
          object ZipcxGrid3DBTableViewOUT_ISTOCHNIC: TcxGridDBColumn
            Caption = #1048#1089#1090#1086#1095#1085#1080#1082
            DataBinding.FieldName = 'OUT_ISTOCHNIC'
            RepositoryItem = DM.cxEditRepository1ImageComboBoxItemOUT_ISTOCHNIK
            Width = 151
          end
          object ZipcxGrid3DBTableViewOUT_DOSTUPNO: TcxGridDBColumn
            Caption = #1044#1086#1089#1090#1091#1087#1085#1086' '#1082' '#1079#1072#1082#1072#1079#1091
            DataBinding.FieldName = 'OUT_DOSTUPNO'
            PropertiesClassName = 'TcxCheckBoxProperties'
            Properties.ValueChecked = 1
            Properties.ValueUnchecked = 0
            Width = 28
          end
          object ZipcxGrid3DBTableViewOUT_NAME_MODEL: TcxGridDBColumn
            Caption = #1052#1086#1076#1077#1083#1100
            DataBinding.FieldName = 'OUT_NAME_MODEL'
            Width = 107
          end
          object ZipcxGrid3DBTableViewOUT_NAME_PRMODEL: TcxGridDBColumn
            Caption = #1052#1086#1076#1077#1083#1100' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103
            DataBinding.FieldName = 'OUT_NAME_PRMODEL'
            Width = 99
          end
          object ZipcxGrid3DBTableViewOUT_NAME: TcxGridDBColumn
            Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
            DataBinding.FieldName = 'OUT_NAME'
            Width = 289
          end
          object ZipcxGrid3DBTableViewOUT_NAME_NOM: TcxGridDBColumn
            Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
            DataBinding.FieldName = 'OUT_NAME_NOM'
            Width = 287
          end
          object ZipcxGrid3DBTableViewOUT_PRICE: TcxGridDBColumn
            Caption = #1062#1077#1085#1072
            DataBinding.FieldName = 'OUT_PRICE'
            Width = 31
          end
          object ZipcxGrid3DBTableViewOUT_OSTATOK: TcxGridDBColumn
            Caption = #1054#1089#1090#1086#1090#1086#1082
            DataBinding.FieldName = 'OUT_OSTATOK'
            Width = 39
          end
        end
        object cxGrid3Level1: TcxGridLevel
          GridView = ZipcxGrid3DBTableView
        end
      end
    end
  end
  object ActionList: TActionList
    Left = 16
    Top = 72
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 8
    Top = 32
  end
end
