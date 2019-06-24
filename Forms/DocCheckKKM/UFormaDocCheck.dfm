object FormaDocCheck: TFormaDocCheck
  Left = 225
  Top = 113
  Caption = #1063#1077#1082' '#1050#1050#1052
  ClientHeight = 548
  ClientWidth = 753
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
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel3: TPanel
    Left = 0
    Top = 469
    Width = 753
    Height = 79
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
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
    object cxButtonPrintCheckFR: TcxButton
      Left = 212
      Top = 38
      Width = 81
      Height = 25
      Caption = #1063#1077#1082' '#1085#1072' '#1060#1056
      TabOrder = 0
      OnClick = cxButtonPrintCheckFRClick
    end
    object cxButtonPrint: TcxButton
      Left = 300
      Top = 38
      Width = 81
      Height = 25
      Action = ActionPrint
      TabOrder = 1
    end
    object cxButtonSave: TcxButton
      Left = 388
      Top = 38
      Width = 81
      Height = 25
      Action = ActionSave
      TabOrder = 3
    end
    object cxButtonDvReg: TcxButton
      Left = 475
      Top = 38
      Width = 82
      Height = 25
      Action = ActionDvReg
      TabOrder = 4
    end
    object cxButtonOK: TcxButton
      Left = 563
      Top = 38
      Width = 81
      Height = 25
      Action = ActionOK
      TabOrder = 2
    end
    object cxButtonClose: TcxButton
      Left = 651
      Top = 38
      Width = 81
      Height = 25
      Action = ActionClose
      TabOrder = 5
    end
    object DocOsncxDBButtonEdit: TcxDBButtonEdit
      Left = 424
      Top = 9
      DataBinding.DataField = 'TDOC'
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
      TabOrder = 6
      Width = 312
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 257
    Width = 753
    Height = 188
    Align = alClient
    TabOrder = 1
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          FieldName = 'SUMCHKT'
          Column = cxGrid1DBTableView1SUMCHKT
        end
        item
          Kind = skSum
          Column = cxGrid1DBTableView1SKCHKT
        end
        item
          Kind = skSum
          Column = cxGrid1DBTableView1NADCHKT
        end
        item
          Kind = skSum
          FieldName = 'SUMNDS_DCHKT'
          Column = cxGrid1DBTableView1SUMNDS_DCHKT
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
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Width = 27
      end
      object cxGrid1DBTableView1NUMOTDKKT_SDEPARTMENT: TcxGridDBColumn
        Caption = #1054#1090#1076#1077#1083
        DataBinding.FieldName = 'NUMOTDKKT_SDEPARTMENT'
        Width = 32
      end
      object cxGrid1DBTableView1NAME_SDEPARTMENT: TcxGridDBColumn
        Caption = #1054#1090#1076#1077#1083
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
        Properties.OnButtonClick = cxGrid1DBTableView1NAME_SDEPARTMENTPropertiesButtonClick
        Width = 68
      end
      object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODENOM'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 44
      end
      object cxGrid1DBTableView1ARTNOM: TcxGridDBColumn
        Caption = #1040#1088#1090#1080#1082#1091#1083
        DataBinding.FieldName = 'ARTNOM'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 47
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        DataBinding.FieldName = 'NAMENOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.AutoSelect = False
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBTableView1NAMENOMPropertiesButtonClick
        Width = 118
      end
      object cxGrid1DBTableView1KOLCHKT: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOLCHKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.ImmediatePost = True
        Width = 27
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
        Width = 47
      end
      object cxGrid1DBTableView1KFCHKT: TcxGridDBColumn
        Caption = #1050#1060
        DataBinding.FieldName = 'KFCHKT'
        Options.Editing = False
        Width = 43
      end
      object cxGrid1DBTableView1SHED: TcxGridDBColumn
        Caption = #1064#1050
        DataBinding.FieldName = 'SHED'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 44
      end
      object cxGrid1DBTableView1PRICECHKT: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'PRICECHKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.ImmediatePost = True
        Width = 40
      end
      object cxGrid1DBTableView1SUMCHKT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUMCHKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Properties.ImmediatePost = True
        Options.ShowEditButtons = isebNever
        Width = 46
      end
      object cxGrid1DBTableView1NDS_DCHKT: TcxGridDBColumn
        Caption = #1053#1044#1057
        DataBinding.FieldName = 'NDS_DCHKT'
        PropertiesClassName = 'TcxImageComboBoxProperties'
        Properties.Items = <>
        Width = 33
      end
      object cxGrid1DBTableView1SUMNDS_DCHKT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072' '#1053#1044#1057
        DataBinding.FieldName = 'SUMNDS_DCHKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 47
      end
      object cxGrid1DBTableView1SKCHKT: TcxGridDBColumn
        Caption = #1057#1082#1080#1076#1082#1072
        DataBinding.FieldName = 'SKCHKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 49
      end
      object cxGrid1DBTableView1NADCHKT: TcxGridDBColumn
        Caption = #1053#1072#1076#1073#1072#1074#1082#1072
        DataBinding.FieldName = 'NADCHKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 39
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 30
    Width = 753
    Height = 227
    ActivePage = cxTabSheet1
    Align = alTop
    TabOrder = 0
    ClientRectBottom = 227
    ClientRectRight = 753
    ClientRectTop = 24
    object cxTabSheet1: TcxTabSheet
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 0
      object Label7: TLabel
        Left = 15
        Top = 179
        Width = 66
        Height = 13
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
      end
      object Label15: TLabel
        Left = 41
        Top = 123
        Width = 41
        Height = 13
        Caption = #1050#1072#1089#1089#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
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
        Width = 75
        Height = 13
        Caption = #1055#1086#1082#1091#1087#1072#1090#1077#1083#1100':'
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
        Left = 24
        Top = 37
        Width = 100
        Height = 26
        Caption = #1063#1077#1082' '#1050#1050#1052
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
        DataField = 'IDKLDOC'
      end
      object Label17: TLabel
        Left = 392
        Top = 69
        Width = 14
        Height = 13
        Caption = 'ID:'
      end
      object Label2: TLabel
        Left = 340
        Top = 33
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
      object Label16: TLabel
        Left = 462
        Top = 124
        Width = 63
        Height = 13
        Caption = #1054#1087#1077#1088#1072#1094#1080#1103':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
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
      object PrimcxDBTextEdit: TcxDBTextEdit
        Left = 87
        Top = 176
        DataBinding.DataField = 'PRIMCHK'
        TabOrder = 14
        OnKeyDown = PrimcxDBTextEditKeyDown
        Width = 450
      end
      object NameKassacxDBButtonEdit: TcxDBButtonEdit
        Left = 88
        Top = 120
        DataBinding.DataField = 'NAMEKKM'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameKassacxDBButtonEditPropertiesButtonClick
        TabOrder = 7
        Width = 301
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
        Left = 244
        Top = 40
        DataBinding.DataField = 'NUMDOC'
        TabOrder = 3
        OnKeyDown = NumDoccxDBTextEditKeyDown
        Width = 90
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
        TabOrder = 5
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
        Properties.OnButtonClick = NameDogcxDBButtonEditPropertiesButtonClick
        TabOrder = 6
        Width = 300
      end
      object PosDoccxDBDateEdit: TcxDBDateEdit
        Left = 379
        Top = 40
        DataBinding.DataField = 'POSDOC'
        Properties.Kind = ckDateTime
        TabOrder = 4
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
        TabOrder = 11
        Width = 217
      end
      object Operation: TcxComboBox
        Left = 532
        Top = 120
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          #1055#1088#1086#1076#1072#1078#1072
          #1042#1086#1079#1074#1088#1072#1090
          '')
        Properties.OnChange = OperationPropertiesChange
        TabOrder = 12
        Width = 217
      end
      object NameDCardcxDBButtonEdit: TcxDBButtonEdit
        Left = 532
        Top = 147
        DataBinding.DataField = 'NAME_SDISCOUNT_CARD'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameDCardcxDBButtonEditPropertiesButtonClick
        TabOrder = 13
        Width = 217
      end
      object cxLabel2: TcxLabel
        Left = 489
        Top = 148
        Caption = #1050#1072#1088#1090#1072':'
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
        TabOrder = 10
        Width = 217
      end
      object cxLabel3: TcxLabel
        Left = 482
        Top = 69
        Caption = #1055#1088#1086#1077#1082#1090':'
      end
      object NameBSchetcxDBButtonEdit: TcxDBButtonEdit
        Left = 88
        Top = 147
        DataBinding.DataField = 'NAMEBSCHET'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameBSchetcxDBButtonEditPropertiesButtonClick
        TabOrder = 8
        Width = 300
      end
      object cxLabel4: TcxLabel
        Left = 24
        Top = 148
        Caption = #1041#1072#1085#1082'. '#1089#1095#1077#1090':'
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
        TabOrder = 9
        Width = 217
      end
      object cxLabel9: TcxLabel
        Left = 530
        Top = 24
        Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
      end
      object PrefiksNumcxDBTextEdit: TcxDBTextEdit
        Left = 125
        Top = 40
        DataBinding.DataField = 'PREFIKS_NUM_GALLDOC'
        TabOrder = 2
        OnKeyDown = PrefiksNumcxDBTextEditKeyDown
        Width = 118
      end
    end
    object cxTabSheet2: TcxTabSheet
      Caption = #1050#1050#1052
      ImageIndex = 1
      object Label4: TLabel
        Left = 291
        Top = 120
        Width = 89
        Height = 13
        Caption = #1053#1086#1084#1077#1088' '#1095#1077#1082#1072' '#1050#1050#1052':'
      end
      object Label5: TLabel
        Left = 299
        Top = 98
        Width = 81
        Height = 13
        Caption = #1053#1086#1084#1077#1088' '#1050#1051' '#1050#1050#1052':'
      end
      object Label19: TLabel
        Left = 64
        Top = 98
        Width = 69
        Height = 13
        Caption = #1047#1072#1074#1086#1076#1089#1082#1086#1081' '#8470
      end
      object Label18: TLabel
        Left = 64
        Top = 76
        Width = 68
        Height = 13
        Caption = #1052#1086#1076#1077#1083#1100' '#1050#1050#1052':'
      end
      object Label3: TLabel
        Left = 27
        Top = 133
        Width = 105
        Height = 13
        Caption = #1056#1077#1075#1080#1089#1090#1088#1072#1094#1080#1086#1085#1085#1099#1081' '#8470
      end
      object Label20: TLabel
        Left = 63
        Top = 25
        Width = 418
        Height = 24
        Caption = #1056#1077#1082#1074#1080#1079#1080#1090#1099' '#1082#1086#1085#1090#1088#1086#1083#1100#1085#1086'-'#1082#1072#1089#1089#1086#1074#1086#1081' '#1084#1072#1096#1080#1085#1099':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object NumCheckcxDBTextEdit: TcxDBTextEdit
        Left = 386
        Top = 117
        DataBinding.DataField = 'NCHECKCHK'
        TabOrder = 0
        Width = 121
      end
      object ModelcxDBTextEdit: TcxDBTextEdit
        Left = 138
        Top = 71
        DataBinding.DataField = 'MODELCHK'
        TabOrder = 1
        Width = 121
      end
      object SavNumcxDBTextEdit: TcxDBTextEdit
        Left = 139
        Top = 98
        DataBinding.DataField = 'SAVNUMCHK'
        TabOrder = 2
        Width = 121
      end
      object NumKLcxDBTextEdit: TcxDBTextEdit
        Left = 386
        Top = 90
        DataBinding.DataField = 'NKLCHK'
        TabOrder = 3
        Width = 122
      end
      object RegNumcxDBTextEdit: TcxDBTextEdit
        Left = 138
        Top = 125
        DataBinding.DataField = 'REGNUMCHK'
        TabOrder = 4
        Width = 121
      end
    end
    object cxTabSheet3: TcxTabSheet
      Caption = #1054#1087#1083#1072#1090#1072
      ImageIndex = 2
      object Panel1: TPanel
        Left = 737
        Top = 17
        Width = 16
        Height = 161
        Align = alRight
        BevelOuter = bvNone
        TabOrder = 0
      end
      object Panel5: TPanel
        Left = 0
        Top = 17
        Width = 273
        Height = 161
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 1
        object Label11: TLabel
          Left = 12
          Top = 28
          Width = 74
          Height = 39
          Caption = #1055#1086#1083#1091#1095#1077#1085#1086' '#1085#1072#1083#1080#1095#1085#1099#1093' '#1086#1090' '#1087#1086#1082#1091#1087#1072#1090#1077#1083#1103':'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          WordWrap = True
        end
        object Label9: TLabel
          Left = 24
          Top = 58
          Width = 100
          Height = 13
          Caption = #1054#1087#1083#1072#1090#1072' '#1085#1072#1083#1080#1095#1085#1099#1084#1080':'
        end
        object Label10: TLabel
          Left = 24
          Top = 85
          Width = 105
          Height = 13
          Caption = #1041#1072#1085#1082#1086#1074#1089#1082#1086#1081' '#1082#1072#1088#1090#1086#1081'::'
        end
        object Label8: TLabel
          Left = 31
          Top = 112
          Width = 98
          Height = 13
          Caption = #1055#1083#1072#1090#1077#1078#1085#1086#1081' '#1082#1072#1088#1090#1086#1081':'
        end
        object Label23: TLabel
          Left = 31
          Top = 139
          Width = 95
          Height = 13
          Caption = #1050#1088#1077#1076#1080#1090#1085#1086#1081' '#1082#1072#1088#1090#1086#1081':'
        end
        object NalCHKcxDBCalcEdit: TcxDBCalcEdit
          Left = 144
          Top = 28
          DataBinding.DataField = 'NALCHK'
          Properties.ImmediatePost = True
          TabOrder = 0
          OnKeyDown = NalCHKcxDBCalcEditKeyDown
          Width = 112
        end
        object OplNalcxDBCalcEdit: TcxDBCalcEdit
          Left = 144
          Top = 55
          DataBinding.DataField = 'OPLNALCHK'
          Properties.ImmediatePost = True
          TabOrder = 1
          OnKeyDown = OplNalcxDBCalcEditKeyDown
          Width = 112
        end
        object OplPCcxDBCalcEdit: TcxDBCalcEdit
          Left = 144
          Top = 82
          DataBinding.DataField = 'OPLPCCHK'
          Properties.ImmediatePost = True
          TabOrder = 2
          OnKeyDown = OplPCcxDBCalcEditKeyDown
          Width = 112
        end
        object OplPlatCardcxDBCalcEdit: TcxDBCalcEdit
          Left = 144
          Top = 109
          DataBinding.DataField = 'OPLPLATCARD_DCHK'
          Properties.ImmediatePost = True
          TabOrder = 3
          Width = 112
        end
        object OplCreditCardcxDBCalcEdit: TcxDBCalcEdit
          Left = 144
          Top = 136
          DataBinding.DataField = 'OPLCREDITCARD_DCHK'
          Properties.ImmediatePost = True
          TabOrder = 4
          Width = 112
        end
      end
      object Panel6: TPanel
        Left = 0
        Top = 0
        Width = 753
        Height = 17
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 2
      end
      object GroupBox1: TGroupBox
        Left = 273
        Top = 17
        Width = 464
        Height = 161
        Align = alClient
        Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1099#1077' '#1082#1072#1088#1090#1099' '#1086#1087#1083#1072#1090#1099
        TabOrder = 3
        object ToolBar4: TToolBar
          Left = 2
          Top = 15
          Width = 460
          Height = 28
          Caption = 'ToolBar4'
          Color = clCaptionText
          Images = DM.ImageList1
          ParentColor = False
          TabOrder = 0
          object ToolButton4: TToolButton
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
            OnClick = ToolButtonAddPriceClick
          end
          object ToolButtonDeletePrice: TToolButton
            Left = 32
            Top = 0
            Caption = 'ToolButtonDeletePrice'
            ImageIndex = 2
            OnClick = ToolButtonDeletePriceClick
          end
        end
        object cxGrid2: TcxGrid
          Left = 2
          Top = 43
          Width = 460
          Height = 116
          Align = alClient
          TabOrder = 1
          object cxGrid2DBTableView1: TcxGridDBTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsView.ColumnAutoWidth = True
            OptionsView.GroupByBox = False
            object cxGrid2DBTableView1RECNO: TcxGridDBColumn
              Caption = #8470
              DataBinding.FieldName = 'RECNO'
              Width = 28
            end
            object cxGrid2DBTableView1NAME_SDISCOUNT_CARD: TcxGridDBColumn
              Caption = #1050#1072#1088#1090#1072
              DataBinding.FieldName = 'NAME_SDISCOUNT_CARD'
              PropertiesClassName = 'TcxButtonEditProperties'
              Properties.Buttons = <
                item
                  Default = True
                  Kind = bkEllipsis
                end>
              Properties.ReadOnly = True
              Properties.OnButtonClick = cxGrid2DBTableView1NAME_SDISCOUNT_CARDPropertiesButtonClick
              Width = 252
            end
            object cxGrid2DBTableView1SUMPLAT_DCHK_OPL: TcxGridDBColumn
              Caption = #1057#1091#1084#1084#1072' '#1086#1087#1083#1072#1090#1099
              DataBinding.FieldName = 'SUMPLAT_DCHK_OPL'
              PropertiesClassName = 'TcxCalcEditProperties'
              Width = 77
            end
            object cxGrid2DBTableView1SUMCREDIT_DCHK_OPL: TcxGridDBColumn
              Caption = #1057#1091#1084#1084#1072' '#1082#1088#1077#1076#1080#1090#1072
              DataBinding.FieldName = 'SUMCREDIT_DCHK_OPL'
              PropertiesClassName = 'TcxCalcEditProperties'
              Width = 76
            end
          end
          object cxGrid2Level1: TcxGridLevel
            GridView = cxGrid2DBTableView1
          end
        end
      end
      object Panel8: TPanel
        Left = 0
        Top = 178
        Width = 753
        Height = 25
        Align = alBottom
        BevelOuter = bvNone
        TabOrder = 4
        object cxLabel5: TcxLabel
          Left = 290
          Top = 4
          Caption = #1042#1089#1077#1075#1086' '#1087#1083#1072#1090'. '#1082#1072#1088#1090#1086#1081':'
          ParentFont = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clNavy
          Style.Font.Height = -12
          Style.Font.Name = 'MS Sans Serif'
          Style.Font.Style = [fsBold]
          Style.IsFontAssigned = True
        end
        object AllOplPlatCardcxDBLabel: TcxDBLabel
          Left = 420
          Top = 4
          DataBinding.DataField = 'OPLPLATCARD_ALL_DCHK'
          ParentFont = False
          Properties.Alignment.Horz = taLeftJustify
          Properties.Orientation = cxoLeft
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clNavy
          Style.Font.Height = -12
          Style.Font.Name = 'MS Sans Serif'
          Style.Font.Style = [fsBold]
          Style.IsFontAssigned = True
          Height = 21
          Width = 77
        end
        object cxLabel6: TcxLabel
          Left = 503
          Top = 4
          Caption = #1042#1089#1077#1075#1086' '#1082#1088#1077#1076#1080#1090#1085#1086#1081'  '#1082#1072#1088#1090#1086#1081':'
          ParentFont = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clNavy
          Style.Font.Height = -12
          Style.Font.Name = 'MS Sans Serif'
          Style.Font.Style = [fsBold]
          Style.IsFontAssigned = True
        end
        object AllOplCreditCardcxDBLabel: TcxDBLabel
          Left = 668
          Top = 4
          DataBinding.DataField = 'OPLCREDITCARD_ALL_DCHK'
          ParentFont = False
          Properties.Alignment.Horz = taLeftJustify
          Properties.Orientation = cxoLeft
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clNavy
          Style.Font.Height = -12
          Style.Font.Name = 'MS Sans Serif'
          Style.Font.Style = [fsBold]
          Style.IsFontAssigned = True
          Height = 21
          Width = 62
        end
      end
    end
  end
  object ToolBar2: TToolBar
    Left = 0
    Top = 0
    Width = 753
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
    object NameBaseDBText: TDBText
      Left = 256
      Top = 0
      Width = 457
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
      Left = 713
      Top = 0
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 4
      Style = tbsSeparator
    end
    object ViborBaseButton: TButton
      Left = 721
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
    Width = 753
    Height = 24
    Align = alBottom
    BevelOuter = bvNone
    Color = clSilver
    ParentBackground = False
    TabOrder = 4
    object SdachacxDBLabel: TcxDBLabel
      Left = 661
      Top = 2
      DataBinding.DataField = 'SDACHA_DCHK'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clRed
      Style.Font.Height = -15
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
      Height = 21
      Width = 67
    end
    object cxLabel1: TcxLabel
      Left = 590
      Top = 1
      Caption = #1057#1076#1072#1095#1072':'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clBlack
      Style.Font.Height = -15
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
    end
    object AllOplcxDBLabel: TcxDBLabel
      Left = 452
      Top = 2
      DataBinding.DataField = 'ALLOPL'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -15
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
      Height = 21
      Width = 121
    end
    object cxLabel7: TcxLabel
      Left = 177
      Top = 1
      Caption = #1057#1091#1084#1084#1072' '#1095#1077#1082#1072':'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -15
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
    end
    object cxLabel8: TcxLabel
      Left = 382
      Top = 1
      Caption = #1054#1087#1083#1072#1090#1072':'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -15
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
    end
    object SumDoccxDBLabel: TcxDBLabel
      Left = 279
      Top = 2
      DataBinding.DataField = 'SUMDOC'
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
    Left = 8
    Top = 80
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
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
      OnExecute = ActionPrintExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 288
  end
end
