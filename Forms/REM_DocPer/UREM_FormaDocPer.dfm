object REM_FormaDocPer: TREM_FormaDocPer
  Left = 225
  Top = 113
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1056#1077#1072#1083#1080#1079#1072#1094#1080#1103' ('#1088#1077#1084#1086#1085#1090')'
  ClientHeight = 548
  ClientWidth = 969
  Color = clBtnFace
  Constraints.MinWidth = 760
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  OnDeactivate = FormDeactivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel3: TPanel
    Left = 0
    Top = 469
    Width = 969
    Height = 79
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    ExplicitWidth = 753
    object DBTextFNameUser: TDBText
      Left = 10
      Top = 2
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
      Left = 10
      Top = 17
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
    object Label22: TLabel
      Left = 307
      Top = 12
      Width = 111
      Height = 13
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1086#1089#1085#1086#1074#1072#1085#1080#1077':'
    end
    object ProsmotrTextLabel: TLabel
      Left = 10
      Top = 64
      Width = 88
      Height = 13
      Caption = 'ProsmotrTextLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonSave: TcxButton
      Left = 388
      Top = 38
      Width = 81
      Height = 25
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonDvReg: TcxButton
      Left = 475
      Top = 38
      Width = 82
      Height = 25
      Action = ActionDvReg
      TabOrder = 2
    end
    object cxButtonOK: TcxButton
      Left = 563
      Top = 38
      Width = 81
      Height = 25
      Action = ActionOK
      TabOrder = 0
    end
    object cxButtonClose: TcxButton
      Left = 651
      Top = 38
      Width = 81
      Height = 25
      Action = ActionClose
      TabOrder = 3
    end
    object DocOsncxDBButtonEdit: TcxDBButtonEdit
      Left = 424
      Top = 9
      DataBinding.DataField = 'TDOC_REM_GALLDOC'
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
      TabOrder = 4
      Width = 312
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 228
    Width = 969
    Height = 217
    Align = alClient
    TabOrder = 1
    ExplicitWidth = 753
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          FieldName = 'KOL_REM_DPERT'
          Column = cxGrid1DBTableView1KOL_REM_DPERT
        end
        item
          Kind = skSum
          FieldName = 'RSUM_REM_DPERT'
          Column = cxGrid1DBTableView1RSUM_REM_DPERT
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsBehavior.IncSearch = True
      OptionsBehavior.PullFocusing = True
      OptionsSelection.InvertSelect = False
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1ID_REM_DPERT: TcxGridDBColumn
        DataBinding.FieldName = 'ID_REM_DPERT'
        Visible = False
      end
      object cxGrid1DBTableView1IDNOM_REM_DPERT: TcxGridDBColumn
        DataBinding.FieldName = 'IDNOM_REM_DPERT'
        Visible = False
      end
      object cxGrid1DBTableView1IDED_REM_DPERT: TcxGridDBColumn
        DataBinding.FieldName = 'IDED_REM_DPERT'
        Visible = False
      end
      object cxGrid1DBTableView1IDHW_REM_DPERT: TcxGridDBColumn
        DataBinding.FieldName = 'IDHW_REM_DPERT'
        Visible = False
      end
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 20
      end
      object cxGrid1DBTableView1DVREG_REM_DPERT: TcxGridDBColumn
        Caption = #1044#1074'.'
        DataBinding.FieldName = 'DVREG_REM_DPERT'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 20
      end
      object cxGrid1DBTableView1DVREG_POL_REM_DPERT: TcxGridDBColumn
        Caption = #1044#1074'. '#1088#1077#1075'. '#1087#1086#1083'.'
        DataBinding.FieldName = 'DVREG_POL_REM_DPERT'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 35
      end
      object cxGrid1DBTableView1NAME_STNOM: TcxGridDBColumn
        Caption = #1058#1080#1087' '#1085#1086#1084'.'
        DataBinding.FieldName = 'NAME_STNOM'
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
        Properties.OnButtonClick = cxGrid1DBTableView1NAME_STNOMPropertiesButtonClick
        Width = 30
      end
      object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODENOM'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 22
      end
      object cxGrid1DBTableView1ARTNOM: TcxGridDBColumn
        Caption = #1040#1088#1090#1080#1082#1091#1083
        DataBinding.FieldName = 'ARTNOM'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 25
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
        Properties.OnButtonClick = cxGrid1DBTableView1NAMENOMPropertiesButtonClick
        Width = 132
      end
      object cxGrid1DBTableView1KOL_REM_DPERT: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOL_REM_DPERT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 34
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
        Width = 30
      end
      object cxGrid1DBTableView1SHED: TcxGridDBColumn
        Caption = #1064#1050
        DataBinding.FieldName = 'SHED'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 22
      end
      object cxGrid1DBTableView1KF_REM_DPERT: TcxGridDBColumn
        Caption = #1050#1060
        DataBinding.FieldName = 'KF_REM_DPERT'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 23
      end
      object cxGrid1DBTableView1RPRICE_REM_DPERT: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'RPRICE_REM_DPERT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 24
      end
      object cxGrid1DBTableView1RSUM_REM_DPERT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'RSUM_REM_DPERT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 27
      end
      object cxGrid1DBTableView1CODE_REM_SHARDWARE: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_REM_SHARDWARE'
        PropertiesClassName = 'TcxLabelProperties'
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
        Width = 131
      end
      object cxGrid1DBTableView1SERNUM_REM_SHARDWARE: TcxGridDBColumn
        Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088
        DataBinding.FieldName = 'SERNUM_REM_SHARDWARE'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 62
      end
      object cxGrid1DBTableView1NAME_SMHRAN_OTPR: TcxGridDBColumn
        Caption = #1052#1077#1089#1090#1086' '#1093#1088#1072#1085'. '#1086#1090#1087#1088'.'
        DataBinding.FieldName = 'NAME_SMHRAN_OTPR'
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
        Properties.OnButtonClick = cxGrid1DBTableView1NAME_SMHRAN_OTPRPropertiesButtonClick
        Width = 41
      end
      object cxGrid1DBTableView1NAME_SMHRAN_POL: TcxGridDBColumn
        Caption = #1052#1077#1089#1090#1086' '#1093#1088#1072#1085'. '#1087#1086#1083'.'
        DataBinding.FieldName = 'NAME_SMHRAN_POL'
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
        Properties.OnButtonClick = cxGrid1DBTableView1NAME_SMHRAN_POLPropertiesButtonClick
        Width = 42
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 30
    Width = 969
    Height = 198
    ActivePage = cxTabSheet1
    Align = alTop
    TabOrder = 0
    ExplicitWidth = 753
    ClientRectBottom = 198
    ClientRectRight = 969
    ClientRectTop = 24
    object cxTabSheet1: TcxTabSheet
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 0
      ExplicitWidth = 753
      object Label7: TLabel
        Left = 11
        Top = 154
        Width = 66
        Height = 13
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
      end
      object Label6: TLabel
        Left = 26
        Top = 96
        Width = 56
        Height = 13
        Caption = #1044#1086#1075#1086#1074#1086#1088':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label14: TLabel
        Left = 7
        Top = 69
        Width = 73
        Height = 13
        Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label12: TLabel
        Left = 17
        Top = 6
        Width = 47
        Height = 13
        Caption = #1060#1080#1088#1084#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label1: TLabel
        Left = 2
        Top = 29
        Width = 259
        Height = 26
        Caption = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077' ('#1088#1077#1084#1086#1085#1090')'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -23
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object IdKlientDBText: TDBText
        Left = 410
        Top = 69
        Width = 65
        Height = 17
        DataField = 'IDKLIENT_REM_GALLDOC'
      end
      object Label17: TLabel
        Left = 392
        Top = 69
        Width = 14
        Height = 13
        Caption = 'ID:'
      end
      object Label2: TLabel
        Left = 349
        Top = 29
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
      object Label13: TLabel
        Left = 442
        Top = 6
        Width = 41
        Height = 13
        Caption = #1057#1082#1083#1072#1076':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label21: TLabel
        Left = 483
        Top = 96
        Width = 43
        Height = 13
        Caption = #1058#1080#1087' '#1094#1077#1085':'
      end
      object LabelEditRekvisitBarCode: TLabel
        Left = 543
        Top = 143
        Width = 240
        Height = 24
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = 'LabelEditRekvisitBarCode'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object PrimcxDBTextEdit: TcxDBTextEdit
        Left = 87
        Top = 147
        DataBinding.DataField = 'PRIM_REM_DPER'
        TabOrder = 10
        OnKeyDown = PrimcxDBTextEditKeyDown
        Width = 450
      end
      object NameFirmcxDBButtonEdit: TcxDBButtonEdit
        Left = 87
        Top = 3
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
        Width = 301
      end
      object NumDoccxDBTextEdit: TcxDBTextEdit
        Left = 271
        Top = 34
        DataBinding.DataField = 'NUM_REM_GALLDOC'
        TabOrder = 2
        OnKeyDown = NumDoccxDBTextEditKeyDown
        Width = 71
      end
      object NameKlientcxDBButtonEdit: TcxDBButtonEdit
        Left = 87
        Top = 66
        DataBinding.DataField = 'NAMEKLIENT'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
        TabOrder = 4
        Width = 301
      end
      object NameDogcxDBButtonEdit: TcxDBButtonEdit
        Left = 88
        Top = 93
        DataBinding.DataField = 'NAME_SDOG'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        TabOrder = 5
        Width = 300
      end
      object PosDoccxDBDateEdit: TcxDBDateEdit
        Left = 379
        Top = 34
        DataBinding.DataField = 'POS_REM_GALLDOC'
        Properties.Kind = ckDateTime
        TabOrder = 3
        OnKeyDown = PosDoccxDBDateEditKeyDown
        Width = 144
      end
      object NameSkladcxDBButtonEdit: TcxDBButtonEdit
        Left = 513
        Top = 3
        DataBinding.DataField = 'NAMESKLAD'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameSkladcxDBButtonEditPropertiesButtonClick
        TabOrder = 1
        Width = 237
      end
      object TypePriceComboBox: TcxComboBox
        Left = 532
        Top = 93
        Properties.DropDownListStyle = lsEditFixedList
        Properties.OnChange = TypePriceComboBoxPropertiesChange
        TabOrder = 8
        Width = 217
      end
      object NameSkladPolcxDBButtonEdit: TcxDBButtonEdit
        Left = 121
        Top = 119
        DataBinding.DataField = 'NAMESKLAD'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameSkladPolcxDBButtonEditPropertiesButtonClick
        TabOrder = 9
        Width = 301
      end
      object cxLabel2: TcxLabel
        Left = 11
        Top = 119
        Caption = #1057#1082#1083#1072#1076' '#1087#1086#1083#1091#1095#1072#1090#1077#1083#1100':'
      end
      object NameProjectcxDBButtonEdit: TcxDBButtonEdit
        Left = 532
        Top = 66
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
        TabOrder = 7
        Width = 217
      end
      object cxLabel3: TcxLabel
        Left = 482
        Top = 69
        Caption = #1055#1088#1086#1077#1082#1090':'
      end
      object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
        Left = 532
        Top = 40
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
        TabOrder = 6
        Width = 217
      end
      object cxLabel9: TcxLabel
        Left = 530
        Top = 24
        Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
      end
    end
  end
  object ToolBar2: TToolBar
    Left = 0
    Top = 0
    Width = 969
    Height = 30
    Color = clBtnFace
    EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
    Images = DM.ImageList1
    ParentColor = False
    TabOrder = 3
    ExplicitWidth = 904
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
      Action = ActionInsertString
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButtonDelete: TToolButton
      Left = 40
      Top = 0
      Action = ActionDeleteString
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButtonExtModule: TToolButton
      Left = 63
      Top = 0
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
      Caption = 'ToolButtonExtModule'
      DropdownMenu = PopupMenuExtModule
      ImageIndex = 51
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButton2: TToolButton
      Left = 86
      Top = 0
      Width = 170
      Caption = 'ToolButton2'
      ImageIndex = 3
      Style = tbsSeparator
    end
    object ToolButtonChangeERBC: TToolButton
      Left = 256
      Top = 0
      Action = ActionChangeERBC
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButtonAddPoCoduHW: TToolButton
      Left = 279
      Top = 0
      Action = ActionAddHWPoCodu
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButtonAddPoIdHW: TToolButton
      Left = 302
      Top = 0
      Action = ActionAddPoId
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButtonAddPoCodu: TToolButton
      Left = 325
      Top = 0
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1086' '#1082#1086#1076#1091' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
      Caption = 'ToolButtonAddPoCodu'
      ImageIndex = 45
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButtonAddPoCoduClick
    end
    object ToolButtonCreateDocPer: TToolButton
      Left = 348
      Top = 0
      Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077
      Caption = 'ToolButtonCreateDocPer'
      ImageIndex = 45
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButtonCreateDocPerClick
    end
    object ToolButtonAddProcent: TToolButton
      Left = 371
      Top = 0
      Hint = #1059#1074#1077#1083#1080#1095#1080#1090#1100' '#1094#1077#1085#1099' '#1085#1072' '#1087#1088#1086#1094#1077#1085#1090' '#1085#1072#1094#1077#1085#1082#1080
      Caption = 'ToolButtonAddProcent'
      ImageIndex = 45
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButtonAddProcentClick
    end
    object ToolButtonSetDvRegAll: TToolButton
      Left = 394
      Top = 0
      Hint = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1092#1083#1072#1075' '#1044#1074#1080#1078#1077#1085#1080#1077' '#1088#1077#1075#1080#1089#1090#1088#1086#1074' '#1091' '#1074#1089#1077#1093' '#1087#1086#1079#1080#1094#1080#1081
      Caption = 'ToolButtonSetDvRegAll'
      ImageIndex = 45
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButtonSetDvRegAllClick
    end
    object ToolButtonCancalDvRegAll: TToolButton
      Left = 417
      Top = 0
      Hint = #1057#1073#1088#1086#1089#1090#1100' '#1092#1083#1072#1075' '#1044#1074#1080#1078#1077#1085#1080#1077' '#1088#1077#1075#1080#1089#1090#1088#1086#1074' '#1091' '#1074#1089#1077#1093' '#1087#1086#1079#1080#1094#1080#1081
      Caption = 'ToolButtonCancalDvRegAll'
      ImageIndex = 45
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButtonCancalDvRegAllClick
    end
    object ToolButtonAddMHran: TToolButton
      Left = 440
      Top = 0
      Hint = #1055#1088#1086#1089#1090#1072#1074#1080#1090#1100' '#1091' '#1074#1089#1077#1093' '#1087#1086#1079#1080#1094#1080#1081' '#1085#1080#1078#1077' '#1076#1072#1085#1085#1086#1077' '#1084#1077#1089#1090#1086' '#1093#1088#1072#1085#1077#1085#1080#1103
      Caption = 'ToolButtonAddMHran'
      ImageIndex = 45
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButtonAddMHranClick
    end
    object ToolButton4: TToolButton
      Left = 463
      Top = 0
      Hint = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1092#1083#1072#1075' '#1044#1074#1080#1078#1077#1085#1080#1077' '#1088#1077#1075#1080#1089#1090#1088#1086#1074' '#1091' '#1074#1089#1077#1093' '#1087#1086#1079#1080#1094#1080#1081' '#1054#1090#1087#1088#1072#1074#1080#1090#1077#1083#1100
      Caption = 'ToolButton4'
      ImageIndex = 45
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButton4Click
    end
    object ToolButton5: TToolButton
      Left = 486
      Top = 0
      Hint = #1057#1073#1088#1086#1089#1090#1100' '#1092#1083#1072#1075' '#1044#1074#1080#1078#1077#1085#1080#1077' '#1088#1077#1075#1080#1089#1090#1088#1086#1074' '#1091' '#1074#1089#1077#1093' '#1087#1086#1079#1080#1094#1080#1081
      Caption = 'ToolButton5'
      ImageIndex = 45
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButton5Click
    end
    object ToolButton6: TToolButton
      Left = 509
      Top = 0
      Hint = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1092#1083#1072#1075' '#1044#1074#1080#1078#1077#1085#1080#1077' '#1088#1077#1075#1080#1089#1090#1088#1086#1074' '#1091' '#1074#1089#1077#1093' '#1087#1086#1079#1080#1094#1080#1081' '#1055#1086#1083#1091#1095#1072#1090#1077#1083#1100
      Caption = 'ToolButton6'
      ImageIndex = 45
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButton6Click
    end
    object ToolButton7: TToolButton
      Left = 532
      Top = 0
      Hint = #1057#1073#1088#1086#1089#1090#1100' '#1092#1083#1072#1075' '#1044#1074#1080#1078#1077#1085#1080#1077' '#1088#1077#1075#1080#1089#1090#1088#1086#1074' '#1091' '#1074#1089#1077#1093' '#1087#1086#1079#1080#1094#1080#1081' '#1055#1086#1083#1091#1095#1072#1090#1077#1083#1100
      Caption = 'ToolButton7'
      ImageIndex = 45
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButton7Click
    end
    object NameBaseDBText: TDBText
      Left = 555
      Top = 0
      Width = 351
      Height = 22
      Alignment = taRightJustify
      DataField = 'NAME_SINFBASE_OBMEN'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolButton3: TToolButton
      Left = 906
      Top = 0
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 4
      Style = tbsSeparator
    end
    object ViborBaseButton: TButton
      Left = 914
      Top = 0
      Width = 22
      Height = 22
      Caption = '...'
      TabOrder = 0
      TabStop = False
      OnClick = ViborBaseButtonClick
    end
  end
  object Panel7: TPanel
    Left = 0
    Top = 445
    Width = 969
    Height = 24
    Align = alBottom
    BevelOuter = bvNone
    Color = clSilver
    ParentBackground = False
    TabOrder = 4
    ExplicitWidth = 753
    object cxLabel7: TcxLabel
      Left = 513
      Top = -6
      Caption = #1057#1091#1084#1084#1072':'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -15
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
    end
    object SumDoccxDBLabel: TcxDBLabel
      Left = 636
      Top = -4
      DataBinding.DataField = 'SUM_REM_GALLDOC'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -15
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
      Height = 21
      Width = 82
    end
  end
  object ActionList: TActionList
    Left = 24
    Top = 64
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionInsertString: TAction
      Caption = 'ActionInsertString'
      ImageIndex = 0
      ShortCut = 45
      OnExecute = ActionInsertStringExecute
    end
    object ActionDeleteString: TAction
      Caption = 'ActionDeleteString'
      ImageIndex = 2
      ShortCut = 46
      OnExecute = ActionDeleteStringExecute
    end
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
    object ActionOK: TAction
      Caption = 'OK'
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
    object ActionChangeERBC: TAction
      Caption = 'ActionChangeERBC'
      Hint = #1048#1079#1084#1077#1085#1080#1090#1100' '#1090#1080#1087' '#1096#1090#1088#1080#1093#1082#1086#1076#1072
      ImageIndex = 45
      OnExecute = ActionChangeERBCExecute
    end
    object ActionAddHWPoCodu: TAction
      Caption = 'ActionAddHWPoCodu'
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1086' '#1082#1086#1076#1091' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
      ImageIndex = 45
      OnExecute = ActionAddHWPoCoduExecute
    end
    object ActionAddPoId: TAction
      Caption = 'ActionAddPoId'
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1086' '#1085#1086#1084#1077#1088#1091' '#1089#1090#1080#1082#1077#1088#1072
      ImageIndex = 45
      OnExecute = ActionAddPoIdExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 368
    Top = 40
  end
end
