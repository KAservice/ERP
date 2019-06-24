object REM_FormaDocSborkaKompl: TREM_FormaDocSborkaKompl
  Left = 225
  Top = 113
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1057#1073#1086#1088#1082#1072' '#1082#1086#1084#1087#1083#1077#1082#1090#1072' ('#1088#1077#1084#1086#1085#1090')'
  ClientHeight = 674
  ClientWidth = 927
  Color = clBtnFace
  Constraints.MinWidth = 935
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
  OnCreate = FormCreate
  OnDeactivate = FormDeactivate
  PixelsPerInch = 120
  TextHeight = 16
  object Panel3: TPanel
    Left = 0
    Top = 577
    Width = 927
    Height = 97
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object DBTextFNameUser: TDBText
      Left = 12
      Top = 2
      Width = 164
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
      Left = 12
      Top = 21
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
    object Label22: TLabel
      Left = 378
      Top = 15
      Width = 141
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1086#1089#1085#1086#1074#1072#1085#1080#1077':'
    end
    object ProsmotrTextLabel: TLabel
      Left = 12
      Top = 79
      Width = 114
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'ProsmotrTextLabel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonSave: TcxButton
      Left = 478
      Top = 47
      Width = 99
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonDvReg: TcxButton
      Left = 585
      Top = 47
      Width = 101
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 2
    end
    object cxButtonOK: TcxButton
      Left = 693
      Top = 47
      Width = 100
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 0
    end
    object cxButtonClose: TcxButton
      Left = 801
      Top = 47
      Width = 100
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 3
    end
    object DocOsncxDBButtonEdit: TcxDBButtonEdit
      Left = 522
      Top = 11
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
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
      Width = 384
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 321
    Width = 927
    Height = 227
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 1
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          FieldName = 'KOL_REM_DSBKOMPLT'
          Column = cxGrid1DBTableView1KOL_REM_DSBKOMPLT
        end
        item
          Kind = skSum
          FieldName = 'RSUM_REM_DSBKOMPL'
          Column = cxGrid1DBTableView1RSUM_REM_DSBKOMPLT
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
      object cxGrid1DBTableView1ID_REM_DSBKOMPLT: TcxGridDBColumn
        DataBinding.FieldName = 'ID_REM_DSBKOMPLT'
        Visible = False
      end
      object cxGrid1DBTableView1IDNOM_REM_DSBKOMPLT: TcxGridDBColumn
        DataBinding.FieldName = 'IDNOM_REM_DSBKOMPLT'
        Visible = False
      end
      object cxGrid1DBTableView1IDED_REM_DSBKOMPLT: TcxGridDBColumn
        DataBinding.FieldName = 'IDED_REM_DSBKOMPLT'
        Visible = False
      end
      object cxGrid1DBTableView1IDHW_REM_DSBKOMPLT: TcxGridDBColumn
        DataBinding.FieldName = 'IDHW_REM_DSBKOMPLT'
        Visible = False
      end
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 27
      end
      object cxGrid1DBTableView1DVREG_REM_DSBKOMPLT: TcxGridDBColumn
        Caption = #1044#1074'.'
        DataBinding.FieldName = 'DVREG_REM_DSBKOMPLT'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 27
      end
      object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODENOM'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 33
      end
      object cxGrid1DBTableView1ARTNOM: TcxGridDBColumn
        Caption = #1040#1088#1090#1080#1082#1091#1083
        DataBinding.FieldName = 'ARTNOM'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 38
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
        Width = 206
      end
      object cxGrid1DBTableView1KOL_REM_DSBKOMPLT: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOL_REM_DSBKOMPLT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 52
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
        Width = 46
      end
      object cxGrid1DBTableView1SHED: TcxGridDBColumn
        Caption = #1064#1050
        DataBinding.FieldName = 'SHED'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 35
      end
      object cxGrid1DBTableView1KF_REM_DSBKOMPLT: TcxGridDBColumn
        Caption = #1050#1060
        DataBinding.FieldName = 'KF_REM_DSBKOMPLT'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 35
      end
      object cxGrid1DBTableView1RPRICE_REM_DSBKOMPLT: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'RPRICE_REM_DSBKOMPLT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 38
      end
      object cxGrid1DBTableView1RSUM_REM_DSBKOMPLT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'RSUM_REM_DSBKOMPLT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 40
      end
      object cxGrid1DBTableView1CODE_REM_SHARDWARE: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_REM_SHARDWARE'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 50
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
        Width = 204
      end
      object cxGrid1DBTableView1SERNUM_REM_SHARDWARE: TcxGridDBColumn
        Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088
        DataBinding.FieldName = 'SERNUM_REM_SHARDWARE'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 94
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 30
    Width = 927
    Height = 291
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = cxTabSheet1
    Align = alTop
    TabOrder = 0
    ClientRectBottom = 291
    ClientRectRight = 927
    ClientRectTop = 27
    object cxTabSheet1: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 0
      object Label7: TLabel
        Left = 13
        Top = 229
        Width = 86
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
      end
      object Label6: TLabel
        Left = 7
        Top = 129
        Width = 200
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1084#1087#1083#1077#1082#1090' ('#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label14: TLabel
        Left = 8
        Top = 103
        Width = 199
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1084#1087#1083#1077#1082#1090' ('#1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label12: TLabel
        Left = 21
        Top = 7
        Width = 54
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1060#1080#1088#1084#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label1: TLabel
        Left = 4
        Top = 36
        Width = 386
        Height = 32
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1073#1086#1088#1082#1072' '#1082#1086#1084#1087#1083#1077#1082#1090#1072' ('#1088#1077#1084#1086#1085#1090')'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -28
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label17: TLabel
        Left = 482
        Top = 85
        Width = 16
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = 'ID:'
      end
      object Label2: TLabel
        Left = 513
        Top = 33
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
      object Label13: TLabel
        Left = 544
        Top = 7
        Width = 50
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1082#1083#1072#1076':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label21: TLabel
        Left = 593
        Top = 149
        Width = 55
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1058#1080#1087' '#1094#1077#1085':'
      end
      object LabelEditRekvisitBarCode: TLabel
        Left = 668
        Top = 231
        Width = 271
        Height = 26
        Caption = 'LabelEditRekvisitBarCode'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -23
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object PrimcxDBTextEdit: TcxDBTextEdit
        Left = 107
        Top = 232
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'PRIM_REM_DSBKOMPL'
        TabOrder = 9
        OnKeyDown = PrimcxDBTextEditKeyDown
        Width = 554
      end
      object NameFirmcxDBButtonEdit: TcxDBButtonEdit
        Left = 107
        Top = 4
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
        Width = 371
      end
      object NumDoccxDBTextEdit: TcxDBTextEdit
        Left = 396
        Top = 42
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NUM_REM_GALLDOC'
        TabOrder = 2
        OnKeyDown = NumDoccxDBTextEditKeyDown
        Width = 111
      end
      object PosDoccxDBDateEdit: TcxDBDateEdit
        Left = 547
        Top = 41
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'POS_REM_GALLDOC'
        Properties.Kind = ckDateTime
        TabOrder = 3
        OnKeyDown = PosDoccxDBDateEditKeyDown
        Width = 177
      end
      object NameSkladcxDBButtonEdit: TcxDBButtonEdit
        Left = 631
        Top = 4
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
        TabOrder = 1
        Width = 292
      end
      object TypePriceComboBox: TcxComboBox
        Left = 656
        Top = 147
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Properties.DropDownListStyle = lsEditFixedList
        Properties.OnChange = TypePriceComboBoxPropertiesChange
        TabOrder = 8
        Width = 267
      end
      object cxLabel2: TcxLabel
        Left = 13
        Top = 201
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
      end
      object NameProjectcxDBButtonEdit: TcxDBButtonEdit
        Left = 656
        Top = 114
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
        TabOrder = 7
        Width = 267
      end
      object cxLabel3: TcxLabel
        Left = 593
        Top = 114
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1086#1077#1082#1090':'
      end
      object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
        Left = 656
        Top = 82
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
        TabOrder = 6
        Width = 267
      end
      object cxLabel9: TcxLabel
        Left = 653
        Top = 62
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
      end
      object NameNomcxDBButtonEdit: TcxDBButtonEdit
        Left = 214
        Top = 96
        DataBinding.DataField = 'NAMENOM'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = NameNomcxDBButtonEditPropertiesButtonClick
        TabOrder = 4
        Width = 305
      end
      object NameHWcxDBButtonEdit: TcxDBButtonEdit
        Left = 214
        Top = 126
        DataBinding.DataField = 'NAME_REM_SHARDWARE'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = NameHWcxDBButtonEditPropertiesButtonClick
        TabOrder = 5
        Width = 305
      end
      object cxLabel1: TcxLabel
        Left = 448
        Top = 198
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1060':'
      end
      object cxLabel4: TcxLabel
        Left = 235
        Top = 201
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1056#1086#1079#1085'. '#1094#1077#1085#1072':'
      end
      object KolcxDBCalcEdit: TcxDBCalcEdit
        Left = 107
        Top = 198
        DataBinding.DataField = 'KOL_REM_DSBKOMPL'
        TabOrder = 15
        Width = 121
      end
      object RPricecxDBCalcEdit: TcxDBCalcEdit
        Left = 320
        Top = 198
        DataBinding.DataField = 'RPRICE_REM_DSBKOMPL'
        TabOrder = 16
        Width = 121
      end
      object KFcxDBLabel: TcxDBLabel
        Left = 481
        Top = 198
        DataBinding.DataField = 'KF_REM_DSBKOMPL'
        Height = 21
        Width = 121
      end
      object NameEdcxDBButtonEdit: TcxDBButtonEdit
        Left = 214
        Top = 156
        DataBinding.DataField = 'NAMEED'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = NameEdcxDBButtonEditPropertiesButtonClick
        TabOrder = 18
        Width = 176
      end
      object cxLabel5: TcxLabel
        Left = 130
        Top = 153
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1045#1076#1080#1085#1080#1094#1072':'
      end
    end
  end
  object ToolBar2: TToolBar
    Left = 0
    Top = 0
    Width = 927
    Height = 30
    Color = clBtnFace
    EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
    Images = DM.ImageList1
    ParentColor = False
    TabOrder = 3
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
    object ToolButtonCreateDocSborkaKompl: TToolButton
      Left = 325
      Top = 0
      Action = ActionCreateDocSborkaKompl
      ParentShowHint = False
      ShowHint = True
    end
    object NameBaseDBText: TDBText
      Left = 348
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
      Left = 699
      Top = 0
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 4
      Style = tbsSeparator
    end
    object ViborBaseButton: TButton
      Left = 707
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
    Top = 548
    Width = 927
    Height = 29
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Color = clSilver
    ParentBackground = False
    TabOrder = 4
    object cxLabel7: TcxLabel
      Left = 631
      Top = -7
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1091#1084#1084#1072':'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -18
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
    end
    object SumDoccxDBLabel: TcxDBLabel
      Left = 783
      Top = -5
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'SUM_REM_GALLDOC'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -18
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
      Height = 26
      Width = 101
    end
  end
  object ActionList: TActionList
    Left = 72
    Top = 56
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
    object ActionCreateDocSborkaKompl: TAction
      Caption = 'CreateDocSborkaKompl'
      Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1057#1073#1086#1088#1082#1072' '#1082#1086#1084#1087#1083#1077#1082#1090#1072
      ImageIndex = 45
      OnExecute = ActionCreateDocSborkaKomplExecute
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
    Left = 168
    Top = 32
  end
end
