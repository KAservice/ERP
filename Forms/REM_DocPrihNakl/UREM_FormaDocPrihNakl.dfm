object REM_FormaDocPrihNakl: TREM_FormaDocPrihNakl
  Left = 290
  Top = 119
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1055#1088#1080#1093#1086#1076#1085#1072#1103' '#1085#1072#1082#1083#1072#1076#1085#1072#1103' ('#1088#1077#1084#1086#1085#1090')"'
  ClientHeight = 555
  ClientWidth = 798
  Color = clBtnFace
  Constraints.MinWidth = 689
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  Position = poScreenCenter
  Visible = True
  OnActivate = FormActivate
  OnClose = FormClose
  OnDeactivate = FormDeactivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 477
    Width = 798
    Height = 78
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object DBTextFNameUser: TDBText
      Left = 16
      Top = 8
      Width = 119
      Height = 16
      AutoSize = True
      DataField = 'FNAME_USER'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 16
      Top = 24
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
    object DBTextSUM_REM_GALLDOC: TDBText
      Left = 496
      Top = 7
      Width = 181
      Height = 16
      AutoSize = True
      DataField = 'SUM_REM_GALLDOC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonPrint: TcxButton
      Left = 187
      Top = 40
      Width = 75
      Height = 25
      Action = ActionPrint
      TabOrder = 0
    end
    object cxButtonSave: TcxButton
      Left = 268
      Top = 40
      Width = 75
      Height = 25
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonDvReg: TcxButton
      Left = 349
      Top = 40
      Width = 75
      Height = 25
      Action = ActionDvReg
      TabOrder = 2
    end
    object cxButtonOK: TcxButton
      Left = 430
      Top = 40
      Width = 75
      Height = 25
      Action = ActionOK
      TabOrder = 3
    end
    object cxButtonClose: TcxButton
      Left = 511
      Top = 40
      Width = 75
      Height = 25
      Action = ActionClose
      TabOrder = 4
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 235
    Width = 0
    Height = 242
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 796
    Top = 235
    Width = 2
    Height = 242
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 798
    Height = 235
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 9
      Top = 102
      Width = 343
      Height = 24
      Caption = #1055#1088#1080#1093#1086#1076#1085#1072#1103' '#1085#1072#1082#1083#1072#1076#1085#1072#1103' ('#1088#1077#1084#1086#1085#1090')  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 426
      Top = 97
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
    object Label3: TLabel
      Left = 13
      Top = 211
      Width = 66
      Height = 13
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label4: TLabel
      Left = 19
      Top = 157
      Width = 61
      Height = 13
      Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082':'
    end
    object Label5: TLabel
      Left = 29
      Top = 56
      Width = 40
      Height = 13
      Caption = #1060#1080#1088#1084#1072':'
    end
    object Label6: TLabel
      Left = 392
      Top = 35
      Width = 34
      Height = 13
      Caption = #1057#1082#1083#1072#1076':'
    end
    object Label7: TLabel
      Left = 382
      Top = 157
      Width = 117
      Height = 13
      Caption = #1058#1080#1087' '#1094#1077#1085' '#1087#1088#1080#1086#1073#1088#1077#1090#1077#1085#1080#1103':'
    end
    object RTPriceLabel: TLabel
      Left = 393
      Top = 179
      Width = 106
      Height = 13
      Caption = #1058#1080#1087' '#1094#1077#1085' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 798
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
        Action = ActionAddString
        ParentShowHint = False
        PopupMenu = PopupMenu1
        ShowHint = True
      end
      object ToolButtonDelete: TToolButton
        Left = 40
        Top = 0
        Action = ActionDeleteString
        ParentShowHint = False
        PopupMenu = PopupMenu1
        ShowHint = True
      end
      object ToolButton2: TToolButton
        Left = 63
        Top = 0
        Width = 171
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 234
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButtonExtModule: TToolButton
        Left = 242
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton5: TToolButton
        Left = 265
        Top = 0
        Action = ActionEditNom
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton6: TToolButton
        Left = 288
        Top = 0
        Action = ActionEditEd
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonLoadNaOsnPrihNakl: TToolButton
        Left = 311
        Top = 0
        Hint = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1085#1072' '#1086#1089#1085#1086#1074#1072#1085#1080#1080' '#1055#1088#1080#1093#1086#1076#1085#1086#1081' '#1085#1072#1082#1083#1072#1076#1085#1086#1081
        Caption = 'ToolButtonLoadNaOsnPrihNakl'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonLoadNaOsnPrihNaklClick
      end
      object ToolButtonAddSprHW: TToolButton
        Left = 334
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077' '#1085#1086#1074#1099#1077' '#1101#1083#1077#1084#1077#1085#1090#1099
        Caption = 'ToolButtonAddSprHW'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddSprHWClick
      end
      object ToolButton4: TToolButton
        Left = 357
        Top = 0
        Action = ActionEditOborud
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonSetDvRegAll: TToolButton
        Left = 380
        Top = 0
        Hint = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1092#1083#1072#1075' '#1044#1074#1080#1078#1077#1085#1080#1077' '#1088#1077#1075#1080#1089#1090#1088#1086#1074' '#1091' '#1074#1089#1077#1093' '#1087#1086#1079#1080#1094#1080#1081
        Caption = 'ToolButtonSetDvRegAll'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSetDvRegAllClick
      end
      object ToolButtonCancelDvRegAll: TToolButton
        Left = 403
        Top = 0
        Hint = #1057#1073#1088#1086#1089#1090#1100' '#1092#1083#1072#1075' '#1044#1074#1080#1078#1077#1085#1080#1077' '#1088#1077#1075#1080#1089#1090#1088#1086#1074' '#1091' '#1074#1089#1077#1093' '#1087#1086#1079#1080#1094#1080#1081
        Caption = 'ToolButtonCancelDvRegAll'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCancelDvRegAllClick
      end
      object ToolButton7: TToolButton
        Left = 426
        Top = 0
        Width = 75
        Caption = 'ToolButton7'
        ImageIndex = 46
        Style = tbsSeparator
      end
      object ToolButtonSetPostupilo: TToolButton
        Left = 501
        Top = 0
        Hint = #1059#1089#1090#1072#1074#1080#1090#1100' '#1042#1099#1087#1086#1083#1085#1077#1085#1086' '#1080' '#1076#1072#1090#1091' '#1087#1086#1089#1090#1091#1087#1083#1077#1085#1080#1103' '#1074' '#1079#1072#1087#1088#1086#1089#1072#1093
        Caption = 'ToolButtonSetPostupilo'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSetPostupiloClick
      end
      object ToolButtonCreateDocPrihNakl: TToolButton
        Left = 524
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1087#1088#1080#1093#1086#1076#1085#1091#1102' '#1085#1072#1082#1083#1072#1076#1085#1091#1102
        Caption = 'ToolButtonCreateDocPrihNakl'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateDocPrihNaklClick
      end
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 89
      Top = 209
      DataBinding.DataField = 'PRIM_REM_DPRN'
      TabOrder = 8
      OnKeyDown = PrimcxDBTextEditKeyDown
      Width = 403
    end
    object TypeRPriceComboBox: TcxComboBox
      Left = 505
      Top = 176
      Properties.DropDownListStyle = lsFixedList
      Properties.OnChange = TypeRPriceComboBoxPropertiesChange
      TabOrder = 10
      Width = 176
    end
    object TypePriceComboBox: TcxComboBox
      Left = 505
      Top = 153
      Properties.DropDownListStyle = lsFixedList
      Properties.OnChange = TypePriceComboBoxPropertiesChange
      TabOrder = 9
      Width = 176
    end
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 86
      Top = 154
      DataBinding.DataField = 'NAMEKLIENT'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 7
      Width = 273
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 326
      Top = 105
      DataBinding.DataField = 'NUM_REM_GALLDOC'
      TabOrder = 3
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 81
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 478
      Top = 106
      DataBinding.DataField = 'POS_REM_GALLDOC'
      Properties.Kind = ckDateTime
      TabOrder = 4
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 121
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 80
      Top = 53
      DataBinding.DataField = 'NAMEFIRM'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameFirmcxDBButtonEditPropertiesButtonClick
      TabOrder = 1
      Width = 273
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 80
      Top = 31
      DataBinding.DataField = 'NAME_SINFBASE_OBMEN'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameInfBasecxDBButtonEditPropertiesButtonClick
      TabOrder = 0
      Width = 273
    end
    object cxLabel1: TcxLabel
      Left = 16
      Top = 32
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
    object NameSkladcxDBButtonEdit: TcxDBButtonEdit
      Left = 432
      Top = 31
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
      Width = 249
    end
    object PosDocPostcxDBDateEdit: TcxDBDateEdit
      Left = 560
      Top = 127
      DataBinding.DataField = 'POSDOCPOST_REM_DPRN'
      Properties.Kind = ckDateTime
      TabOrder = 6
      OnKeyPress = PosDocPostcxDBDateEditKeyPress
      Width = 121
    end
    object NumDocPostcxDBTextEdit: TcxDBTextEdit
      Left = 422
      Top = 127
      DataBinding.DataField = 'NUMDOCPOST_REM_DPRN'
      TabOrder = 5
      OnKeyPress = NumDocPostcxDBTextEditKeyPress
      Width = 111
    end
    object cxLabel2: TcxLabel
      Left = 282
      Top = 128
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1072' '#8470
    end
    object cxLabel3: TcxLabel
      Left = 539
      Top = 132
      Caption = #1086#1090
    end
    object cxLabel9: TcxLabel
      Left = 359
      Top = 51
      Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
    end
    object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
      Left = 460
      Top = 50
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
      TabOrder = 16
      Width = 221
    end
    object NameProjectcxDBButtonEdit: TcxDBButtonEdit
      Left = 460
      Top = 71
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
      TabOrder = 17
      Width = 221
    end
    object cxLabel4: TcxLabel
      Left = 413
      Top = 72
      Caption = #1055#1088#1086#1077#1082#1090':'
    end
    object OtchetPostcxDBCheckBox: TcxDBCheckBox
      Left = 527
      Top = 197
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1086#1090#1095#1077#1090' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1091
      DataBinding.DataField = 'FL_TREB_OTCHET_REM_DPRN'
      Properties.ValueChecked = 1
      Properties.ValueUnchecked = 0
      TabOrder = 19
      Width = 137
    end
    object OtvHrancxDBCheckBox: TcxDBCheckBox
      Left = 527
      Top = 214
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1086#1090#1074'. '#1093#1088#1072#1085#1077#1085#1080#1077
      DataBinding.DataField = 'FL_OTV_HRAN_REM_DPRN'
      Properties.ValueChecked = 1
      Properties.ValueUnchecked = 0
      TabOrder = 20
      Width = 99
    end
  end
  object TablecxPageControl: TcxPageControl
    Left = 0
    Top = 235
    Width = 796
    Height = 242
    ActivePage = MaincxTabSheet
    Align = alClient
    TabOrder = 4
    ClientRectBottom = 242
    ClientRectRight = 796
    ClientRectTop = 24
    object MaincxTabSheet: TcxTabSheet
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103' (F5)'
      ImageIndex = 0
      object cxGrid1: TcxGrid
        Left = 0
        Top = 0
        Width = 796
        Height = 218
        Align = alClient
        TabOrder = 0
        object cxGrid1DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <
            item
              Kind = skSum
              Column = cxGrid1DBTableView1SUM_REM_DPRNT
            end
            item
              Kind = skSum
              Column = cxGrid1DBTableView1RSUM_REM_DPRNT
            end>
          DataController.Summary.SummaryGroups = <>
          OptionsBehavior.GoToNextCellOnEnter = True
          OptionsBehavior.IncSearch = True
          OptionsCustomize.ColumnsQuickCustomization = True
          OptionsSelection.InvertSelect = False
          OptionsSelection.MultiSelect = True
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.Footer = True
          Styles.Footer = DM.cxStyleHeaderTable
          Styles.Header = DM.cxStyleHeaderTable
          object cxGrid1DBTableView1ID_REM_DPRNT: TcxGridDBColumn
            DataBinding.FieldName = 'ID_REM_DPRNT'
            Visible = False
          end
          object cxGrid1DBTableView1IDNOM_REM_DPRNT: TcxGridDBColumn
            DataBinding.FieldName = 'IDNOM_REM_DPRNT'
            Visible = False
          end
          object cxGrid1DBTableView1IDED_REM_DPRNT: TcxGridDBColumn
            DataBinding.FieldName = 'IDED_REM_DPRNT'
            Visible = False
          end
          object cxGrid1DBTableView1IDHW_REM_DPRNT: TcxGridDBColumn
            DataBinding.FieldName = 'IDHW_REM_DPRNT'
            Visible = False
          end
          object cxGrid1DBTableView1RECNO: TcxGridDBColumn
            Caption = #8470
            DataBinding.FieldName = 'RECNO'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 25
          end
          object cxGrid1DBTableView1DVREG_REM_DPRNT: TcxGridDBColumn
            Caption = #1044#1074'.'
            DataBinding.FieldName = 'DVREG_REM_DPRNT'
            PropertiesClassName = 'TcxCheckBoxProperties'
            Properties.ValueChecked = 1
            Properties.ValueUnchecked = 0
            Width = 27
          end
          object cxGrid1DBTableView1NAME_REM_CQUERY: TcxGridDBColumn
            DataBinding.FieldName = 'NAME_REM_CQUERY'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.OnButtonClick = cxGrid1DBTableView1NAME_REM_CQUERYPropertiesButtonClick
            Width = 102
          end
          object cxGrid1DBTableView1NAME_REM_Z: TcxGridDBColumn
            DataBinding.FieldName = 'NAME_REM_Z'
            Width = 103
          end
          object cxGrid1DBTableView1FL_ADD_IN_SOBORUD_SNOM: TcxGridDBColumn
            DataBinding.FieldName = 'FL_ADD_IN_SOBORUD_SNOM'
            PropertiesClassName = 'TcxCheckBoxProperties'
            Properties.ValueChecked = 1
            Properties.ValueUnchecked = 0
            Width = 23
          end
          object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
            Caption = #1050#1086#1076
            DataBinding.FieldName = 'CODENOM'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 42
          end
          object cxGrid1DBTableView1ARTNOM: TcxGridDBColumn
            Caption = #1040#1088#1090#1080#1082#1091#1083
            DataBinding.FieldName = 'ARTNOM'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 39
          end
          object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
            Caption = #1053#1086#1084#1077#1082#1083#1072#1090#1091#1088#1072
            DataBinding.FieldName = 'NAMENOM'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.OnButtonClick = cxGrid1DBTableView1NAMENOMPropertiesButtonClick
            Width = 129
          end
          object cxGrid1DBTableView1KOL_REM_DPRNT: TcxGridDBColumn
            Caption = #1050#1086#1083'.'
            DataBinding.FieldName = 'KOL_REM_DPRNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 31
          end
          object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
            Caption = #1045#1076'.'
            DataBinding.FieldName = 'NAMEED'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.OnButtonClick = cxGrid1DBTableView1NAMEEDPropertiesButtonClick
            Width = 50
          end
          object cxGrid1DBTableView1SHED: TcxGridDBColumn
            Caption = #1064#1050
            DataBinding.FieldName = 'SHED'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 26
          end
          object cxGrid1DBTableView1KF_REM_DPRNT: TcxGridDBColumn
            Caption = #1050#1060
            DataBinding.FieldName = 'KF_REM_DPRNT'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 22
          end
          object cxGrid1DBTableView1PRICE_REM_DPRNT: TcxGridDBColumn
            Caption = #1062#1077#1085#1072
            DataBinding.FieldName = 'PRICE_REM_DPRNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 35
          end
          object cxGrid1DBTableView1SUM_REM_DPRNT: TcxGridDBColumn
            Caption = #1057#1091#1084#1084#1072
            DataBinding.FieldName = 'SUM_REM_DPRNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 38
          end
          object cxGrid1DBTableView1RPRICE_REM_DPRNT: TcxGridDBColumn
            Caption = #1056#1086#1079#1085'. '#1094#1077#1085#1072
            DataBinding.FieldName = 'RPRICE_REM_DPRNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 29
          end
          object cxGrid1DBTableView1RSUM_REM_DPRNT: TcxGridDBColumn
            Caption = #1056#1086#1079#1085'. '#1089#1091#1084#1084#1072
            DataBinding.FieldName = 'RSUM_REM_DPRNT'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 31
          end
          object cxGrid1DBTableView1NAME_REM_SHARDWARE: TcxGridDBColumn
            Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077
            DataBinding.FieldName = 'NAME_REM_SHARDWARE'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.OnButtonClick = cxGrid1DBTableView1NAME_REM_SHARDWAREPropertiesButtonClick
            Width = 85
          end
          object cxGrid1DBTableView1CODE_REM_SHARDWARE: TcxGridDBColumn
            Caption = #1050#1086#1076
            DataBinding.FieldName = 'CODE_REM_SHARDWARE'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 55
          end
          object cxGrid1DBTableView1SERNUM_REM_SHARDWARE: TcxGridDBColumn
            Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088
            DataBinding.FieldName = 'SERNUM_REM_SHARDWARE'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 86
          end
          object cxGrid1DBTableView1NAME_SMHRAN: TcxGridDBColumn
            Caption = #1052#1077#1089#1090#1086' '#1093#1088#1072#1085#1077#1085#1080#1103
            DataBinding.FieldName = 'NAME_SMHRAN'
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
            Properties.OnButtonClick = cxGrid1DBTableView1NAME_SMHRANPropertiesButtonClick
            Width = 54
          end
        end
        object cxGrid1Level1: TcxGridLevel
          GridView = cxGrid1DBTableView1
        end
      end
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 616
    Top = 392
    object AddNewString: TMenuItem
      Caption = #1053#1086#1074#1072#1103' '#1089#1090#1088#1086#1082#1072
      ShortCut = 45
      OnClick = AddNewStringClick
    end
    object DeleteString: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
      ShortCut = 46
      OnClick = DeleteStringClick
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionAddString: TAction
      Caption = 'ActionAddString'
      ImageIndex = 0
      ShortCut = 45
      OnExecute = ActionAddStringExecute
    end
    object ActionDeleteString: TAction
      Caption = 'ActionDeleteString'
      ImageIndex = 2
      ShortCut = 46
      OnExecute = ActionDeleteStringExecute
    end
    object ActionSetMainTabSheet: TAction
      Caption = 'ActionSetMainTabSheet'
      ShortCut = 116
    end
    object ActionSetAdditionallyTabSheet: TAction
      Caption = 'ActionSetAdditionallyTabSheet'
      ShortCut = 117
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
    end
    object ActionEditNom: TAction
      Caption = 'ActionEditNom'
      Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
      ImageIndex = 45
      ShortCut = 118
      OnExecute = ActionEditNomExecute
    end
    object ActionEditEd: TAction
      Caption = 'ActionEditEd'
      Hint = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '#1077#1076#1080#1085#1080#1094#1099
      ImageIndex = 45
      ShortCut = 119
      OnExecute = ActionEditEdExecute
    end
    object ActionEditOborud: TAction
      Caption = 'ActionEditOborud'
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1086#1088#1084#1091' '#1101#1083#1077#1084#1077#1085#1090#1072' '#1089#1087#1088'. '#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077
      ImageIndex = 45
      ShortCut = 120
      OnExecute = ActionEditOborudExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 384
    Top = 16
  end
end
