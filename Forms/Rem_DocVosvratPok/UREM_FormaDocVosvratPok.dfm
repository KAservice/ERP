object REM_FormaDocVosvratPok: TREM_FormaDocVosvratPok
  Left = 225
  Top = 113
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1042#1086#1079#1074#1088#1072#1090' '#1086#1090' '#1087#1086#1082#1091#1087#1072#1090#1077#1083#1103' ('#1088#1077#1084#1086#1085#1090')'
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
      Left = 373
      Top = 14
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
      Properties.OnButtonClick = DocOsncxDBButtonEditPropertiesButtonClick
      TabOrder = 4
      Width = 384
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 425
    Width = 927
    Height = 123
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
          FieldName = 'KOL_REM_DVPOKT'
          Column = cxGrid1DBTableView1KOL_REM_DVPOKT
        end
        item
          Kind = skSum
          FieldName = 'SUM_REM_DVPOKT'
          Column = cxGrid1DBTableView1SUM_REM_DVPOKT
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsBehavior.IncSearch = True
      OptionsBehavior.PullFocusing = True
      OptionsSelection.InvertSelect = False
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1ID_REM_DVPOKT: TcxGridDBColumn
        DataBinding.FieldName = 'ID_REM_DVPOKT'
        Visible = False
      end
      object cxGrid1DBTableView1IDNOM_REM_DVPOKT: TcxGridDBColumn
        DataBinding.FieldName = 'IDNOM_REM_DVPOKT'
        Visible = False
      end
      object cxGrid1DBTableView1IDED_REM_DVPOKT: TcxGridDBColumn
        DataBinding.FieldName = 'IDED_REM_DVPOKT'
        Visible = False
      end
      object cxGrid1DBTableView1IDHW_REM_DVPOKT: TcxGridDBColumn
        DataBinding.FieldName = 'IDHW_REM_DVPOKT'
        Visible = False
      end
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 28
      end
      object cxGrid1DBTableView1DVREG_REM_DVPOKT: TcxGridDBColumn
        Caption = #1044#1074'.'
        DataBinding.FieldName = 'DVREG_REM_DVPOKT'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 29
      end
      object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODENOM'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 34
      end
      object cxGrid1DBTableView1ARTNOM: TcxGridDBColumn
        Caption = #1040#1088#1090#1080#1082#1091#1083
        DataBinding.FieldName = 'ARTNOM'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 40
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
        Width = 188
      end
      object cxGrid1DBTableView1KOL_REM_DVPOKT: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOL_REM_DVPOKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 57
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
        Width = 31
      end
      object cxGrid1DBTableView1SHED: TcxGridDBColumn
        Caption = #1064#1050
        DataBinding.FieldName = 'SHED'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 59
      end
      object cxGrid1DBTableView1KF_REM_DVPOKT: TcxGridDBColumn
        Caption = #1050#1060
        DataBinding.FieldName = 'KF_REM_DVPOKT'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 32
      end
      object cxGrid1DBTableView1PRICE_REM_DVPOKT: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'PRICE_REM_DVPOKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 42
      end
      object cxGrid1DBTableView1SUM_REM_DVPOKT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_REM_DVPOKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 44
      end
      object cxGrid1DBTableView1CODE_REM_SHARDWARE: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_REM_SHARDWARE'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 56
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
        Width = 196
      end
      object cxGrid1DBTableView1SERNUM_REM_SHARDWARE: TcxGridDBColumn
        Caption = #1057#1077#1088'. '#1085#1086#1084#1077#1088
        DataBinding.FieldName = 'SERNUM_REM_SHARDWARE'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 89
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
    Height = 395
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = cxTabSheet1
    Align = alTop
    TabOrder = 0
    ClientRectBottom = 395
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
        Left = 11
        Top = 344
        Width = 86
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
      end
      object Label6: TLabel
        Left = 49
        Top = 139
        Width = 67
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1086#1075#1086#1074#1086#1088':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label14: TLabel
        Left = 22
        Top = 104
        Width = 94
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1086#1082#1091#1087#1072#1090#1077#1083#1100':'
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
        Left = 2
        Top = 36
        Width = 298
        Height = 64
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1042#1086#1079#1074#1088#1072#1090' '#1087#1086#1082#1091#1087#1072#1090#1077#1083#1103' ('#1088#1077#1084#1086#1085#1090')'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -28
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        WordWrap = True
      end
      object IdKlientDBText: TDBText
        Left = 412
        Top = 89
        Width = 80
        Height = 21
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataField = 'IDKLIENT_REM_GALLDOC'
      end
      object Label17: TLabel
        Left = 388
        Top = 89
        Width = 16
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = 'ID:'
      end
      object Label2: TLabel
        Left = 429
        Top = 43
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
        Left = 594
        Top = 118
        Width = 55
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1058#1080#1087' '#1094#1077#1085':'
      end
      object LabelEditRekvisitBarCode: TLabel
        Left = 676
        Top = 339
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
        Left = 121
        Top = 341
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'DESCR_REM_DVPOK'
        TabOrder = 20
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
        Left = 312
        Top = 51
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NUM_REM_GALLDOC'
        TabOrder = 2
        OnKeyDown = NumDoccxDBTextEditKeyDown
        Width = 111
      end
      object NameKlientcxDBButtonEdit: TcxDBButtonEdit
        Left = 121
        Top = 104
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
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
        Width = 371
      end
      object NameDogcxDBButtonEdit: TcxDBButtonEdit
        Left = 121
        Top = 136
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_SDOG'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        TabOrder = 5
        Width = 371
      end
      object PosDoccxDBDateEdit: TcxDBDateEdit
        Left = 467
        Top = 51
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
        Left = 655
        Top = 114
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Properties.DropDownListStyle = lsEditFixedList
        Properties.OnChange = TypePriceComboBoxPropertiesChange
        TabOrder = 8
        Width = 267
      end
      object NameDCardcxDBButtonEdit: TcxDBButtonEdit
        Left = 121
        Top = 165
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_SDISCOUNT_CARD'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameDCardcxDBButtonEditPropertiesButtonClick
        TabOrder = 9
        Width = 371
      end
      object cxLabel2: TcxLabel
        Left = 70
        Top = 166
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1072#1088#1090#1072':'
      end
      object NameProjectcxDBButtonEdit: TcxDBButtonEdit
        Left = 655
        Top = 81
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
        Top = 85
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1086#1077#1082#1090':'
      end
      object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
        Left = 655
        Top = 49
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
        Left = 652
        Top = 29
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
      end
      object KlientNameStrcxDBTextEdit: TcxDBTextEdit
        Left = 121
        Top = 196
        DataBinding.DataField = 'KLIENT_NAME_REM_DVPOK'
        TabOrder = 10
        Width = 371
      end
      object KlientAdrcxDBTextEdit: TcxDBTextEdit
        Left = 121
        Top = 223
        DataBinding.DataField = 'KLIENT_ADR_REM_DVPOK'
        TabOrder = 11
        Width = 371
      end
      object KlientPhonecxDBTextEdit: TcxDBTextEdit
        Left = 121
        Top = 253
        DataBinding.DataField = 'KLIENT_PHONE_REM_DVPOK'
        TabOrder = 12
        Width = 371
      end
      object PrichinacxDBTextEdit: TcxDBTextEdit
        Left = 121
        Top = 310
        DataBinding.DataField = 'PRICHINA_REM_DVPOK'
        TabOrder = 14
        Width = 761
      end
      object NumDocSalecxDBTextEdit: TcxDBTextEdit
        Left = 536
        Top = 234
        DataBinding.DataField = 'NUMDOCSALE_REM_DVPOK'
        TabOrder = 15
        Width = 205
      end
      object NumDocKlientcxDBTextEdit: TcxDBTextEdit
        Left = 536
        Top = 180
        DataBinding.DataField = 'NUMDOCKL_REM_DVPOK'
        TabOrder = 16
        Width = 205
      end
      object cxLabel1: TcxLabel
        Left = 536
        Top = 153
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1082#1083#1080#1077#1085#1090#1072':'
      end
      object cxLabel4: TcxLabel
        Left = 536
        Top = 211
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1087#1088#1086#1076#1072#1078#1080':'
      end
      object cxLabel5: TcxLabel
        Left = 6
        Top = 197
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1083#1080#1077#1085#1090' ('#1089#1090#1088#1086#1082#1072'):'
      end
      object cxLabel6: TcxLabel
        Left = 68
        Top = 225
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1040#1076#1088#1077#1089':'
      end
      object cxLabel8: TcxLabel
        Left = 47
        Top = 256
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1058#1077#1083#1077#1092#1086#1085':'
      end
      object cxLabel10: TcxLabel
        Left = 51
        Top = 311
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1080#1095#1080#1085#1072':'
      end
      object PassportcxDBTextEdit: TcxDBTextEdit
        Left = 121
        Top = 283
        DataBinding.DataField = 'KLIENT_PASSPORT_REM_DVPOK'
        TabOrder = 13
        Width = 761
      end
      object cxLabel11: TcxLabel
        Left = 51
        Top = 283
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1072#1089#1087#1086#1088#1090':'
      end
      object PosDocKlientcxDBDateEdit: TcxDBDateEdit
        Left = 755
        Top = 180
        DataBinding.DataField = 'POSDOCKL_REM_DVPOK'
        TabOrder = 28
        Width = 121
      end
      object PosDocSalecxDBDateEdit: TcxDBDateEdit
        Left = 755
        Top = 234
        DataBinding.DataField = 'POSDOCSALE_REM_DVPOK'
        TabOrder = 29
        Width = 121
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
    object ToolButtonCreateDocVosvratPok: TToolButton
      Left = 325
      Top = 0
      Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1042#1086#1079#1074#1088#1072#1090
      Caption = 'ToolButtonCreateDocVosvratPok'
      ImageIndex = 45
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButtonCreateDocVosvratPokClick
    end
    object NameBaseDBText: TDBText
      Left = 348
      Top = 0
      Width = 486
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
      Left = 834
      Top = 0
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 4
      Style = tbsSeparator
    end
    object ViborBaseButton: TButton
      Left = 842
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
    object ActionOpenFormArmKassir: TAction
      Caption = 'ActionOpenFormArmKassir'
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1086#1088#1084#1091' '#1050#1072#1089#1089#1080#1088#1072
      ImageIndex = 45
      OnExecute = ActionOpenFormArmKassirExecute
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
    Left = 304
    Top = 72
  end
end
