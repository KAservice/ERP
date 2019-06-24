object HOT_FormaDocRasm: THOT_FormaDocRasm
  Left = 520
  Top = 131
  Caption = #1041#1088#1086#1085#1080#1088#1086#1074#1072#1085#1080#1077
  ClientHeight = 654
  ClientWidth = 853
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
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Panel5: TPanel
    Left = 0
    Top = 0
    Width = 853
    Height = 267
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label3: TLabel
      Left = 406
      Top = 63
      Width = 155
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1086#1085#1085#1072#1103' '#1073#1072#1079#1072':'
    end
    object Label4: TLabel
      Left = 32
      Top = 69
      Width = 47
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1060#1080#1088#1084#1072':'
    end
    object Label1: TLabel
      Left = 10
      Top = 106
      Width = 312
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1056#1072#1079#1084#1077#1097#1077#1085#1080#1077'" '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 494
      Top = 106
      Width = 25
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1086#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label14: TLabel
      Left = 10
      Top = 203
      Width = 94
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1062#1077#1083#1100' '#1087#1088#1080#1077#1079#1076#1072':'
    end
    object Label6: TLabel
      Left = 17
      Top = 236
      Width = 86
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label5: TLabel
      Left = 18
      Top = 162
      Width = 83
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1083#1072#1090#1077#1083#1100#1097#1080#1082':'
    end
    object Label7: TLabel
      Left = 492
      Top = 209
      Width = 90
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1088#1075#1072#1085#1080#1079#1072#1094#1080#1103':'
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 561
      Top = 59
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
      TabOrder = 0
      Width = 257
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 106
      Top = 59
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
      TabOrder = 1
      Width = 257
    end
    object NumbercxDBTextEdit: TcxDBTextEdit
      Left = 348
      Top = 112
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMBER_HOT_GALLDOC'
      TabOrder = 2
      OnKeyDown = NumbercxDBTextEditKeyDown
      Width = 138
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 530
      Top = 112
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POS_HOT_GALLDOC'
      Properties.InputKind = ikStandard
      Properties.Kind = ckDateTime
      TabOrder = 3
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 189
    end
    object CelPrcxDBButtonEdit: TcxDBButtonEdit
      Left = 135
      Top = 199
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_HOT_SCELPR'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = CelPrcxDBButtonEditPropertiesButtonClick
      TabOrder = 5
      Width = 336
    end
    object DescrcxDBTextEdit: TcxDBTextEdit
      Left = 135
      Top = 233
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'DESCR_HOT_DRASM'
      TabOrder = 7
      OnKeyDown = DescrcxDBTextEditKeyDown
      Width = 555
    end
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 135
      Top = 166
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
      Width = 336
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 853
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 8
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
        ShowHint = True
      end
      object ToolButtonDelete: TToolButton
        Left = 40
        Top = 0
        Action = ActionDeleteString
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton2: TToolButton
        Left = 63
        Top = 0
        Width = 74
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 137
        Top = 0
        Caption = 'ToolButton3'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
      end
    end
    object OrgcxDBTextEdit: TcxDBTextEdit
      Left = 586
      Top = 199
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'ORG_HOT_DRASM'
      TabOrder = 6
      OnKeyDown = OrgcxDBTextEditKeyDown
      Width = 267
    end
    object TypePricecxDBLookupComboBox: TcxDBLookupComboBox
      Left = 535
      Top = 166
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'IDTPRICE_HOT_DRASM'
      Properties.KeyFieldNames = 'ID_TPRICE'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_TPRICE'
        end>
      TabOrder = 9
      Width = 249
    end
    object cxLabel2: TcxLabel
      Left = 479
      Top = 167
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1072#1088#1080#1092':'
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 538
    Width = 853
    Height = 116
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object ProsmotrLabel: TLabel
      Left = 10
      Top = 69
      Width = 131
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1090#1086#1083#1100#1082#1086' '#1087#1088#1086#1089#1084#1086#1090#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object DBTextFNameUser: TDBText
      Left = 10
      Top = 96
      Width = 139
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'FNAME_USER'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonClose: TcxButton
      Left = 756
      Top = 46
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 656
      Top = 46
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 1
    end
    object cxButtonDvReg: TcxButton
      Left = 556
      Top = 46
      Width = 93
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 2
    end
    object cxButtonSave: TcxButton
      Left = 457
      Top = 46
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 3
    end
    object cxButtonCreateDocReal: TcxButton
      Left = 108
      Top = 20
      Width = 93
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1077#1072#1083#1080#1079#1072#1094#1080#1103
      TabOrder = 4
      OnClick = cxButtonCreateDocRealClick
    end
    object cxButtonPrintAnketa: TcxButton
      Left = 9
      Top = 20
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1040#1085#1082#1077#1090#1072
      TabOrder = 5
      OnClick = cxButtonPrintAnketaClick
    end
    object cxButtonCreateDocViezd: TcxButton
      Left = 357
      Top = 46
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1082' "'#1042#1099#1077#1079#1076'"'
      TabOrder = 6
      OnClick = cxButtonCreateDocViezdClick
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 267
    Width = 853
    Height = 271
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 1
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
    end
    object cxGrid1DBBandedTableView1: TcxGridDBBandedTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsSelection.InvertSelect = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.RowSeparatorWidth = 4
      Styles.Header = DM.cxStyleHeaderTable
      Bands = <
        item
        end>
      object cxGrid1DBBandedTableView1BR_POSNACH_HOT_SOSTNF: TcxGridDBBandedColumn
        Caption = #1047#1072#1077#1079#1076
        DataBinding.FieldName = 'BR_POSNACH_HOT_SOSTNF'
        Options.Editing = False
        Styles.Content = DM.cxStyleVidStringSkyBlue
        Width = 71
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1BR_POSCON_HOT_SOSTNF: TcxGridDBBandedColumn
        Caption = #1042#1099#1077#1079#1076
        DataBinding.FieldName = 'BR_POSCON_HOT_SOSTNF'
        Options.Editing = False
        Styles.Content = DM.cxStyleVidStringSkyBlue
        Width = 83
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1BR_NAME_HOT_SNF: TcxGridDBBandedColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'BR_NAME_HOT_SNF'
        Options.Editing = False
        Styles.Content = DM.cxStyleVidStringSkyBlue
        Width = 83
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1BR_NAME_HOT_SCATNOM: TcxGridDBBandedColumn
        Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103
        DataBinding.FieldName = 'BR_NAME_HOT_SCATNOM'
        Options.Editing = False
        Styles.Content = DM.cxStyleVidStringSkyBlue
        Width = 81
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1BR_NAME_HOT_STYPEPOS: TcxGridDBBandedColumn
        Caption = #1058#1080#1087' '#1087#1086#1089#1077#1083#1077#1085#1080#1103
        DataBinding.FieldName = 'BR_NAME_HOT_STYPEPOS'
        Options.Editing = False
        Styles.Content = DM.cxStyleVidStringSkyBlue
        Width = 85
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1BR_NAME_HOT_SSOSTNOM: TcxGridDBBandedColumn
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
        DataBinding.FieldName = 'BR_NAME_HOT_SSOSTNOM'
        Options.Editing = False
        Styles.Content = DM.cxStyleVidStringSkyBlue
        Width = 85
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1BR_KOLM_HOT_SOSTNF: TcxGridDBBandedColumn
        Caption = #1052#1077#1089#1090
        DataBinding.FieldName = 'BR_KOLM_HOT_SOSTNF'
        Options.Editing = False
        Styles.Content = DM.cxStyleVidStringSkyBlue
        Width = 25
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1BR_NAMEGUEST: TcxGridDBBandedColumn
        Caption = #1043#1086#1089#1090#1100
        DataBinding.FieldName = 'BR_NAMEGUEST'
        Options.Editing = False
        Styles.Content = DM.cxStyleVidStringSkyBlue
        Width = 73
        Position.BandIndex = 0
        Position.ColIndex = 8
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1RASM_POSNACH_HOT_SOSTNF: TcxGridDBBandedColumn
        Caption = #1047#1072#1077#1079#1076
        DataBinding.FieldName = 'RASM_POSNACH_HOT_SOSTNF'
        PropertiesClassName = 'TcxDateEditProperties'
        Properties.Kind = ckDateTime
        Styles.Content = DM.cxStyleVidelString
        Width = 71
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1RASM_POSCON_HOT_SOSTNF: TcxGridDBBandedColumn
        Caption = #1042#1099#1077#1079#1076
        DataBinding.FieldName = 'RASM_POSCON_HOT_SOSTNF'
        PropertiesClassName = 'TcxDateEditProperties'
        Properties.Kind = ckDateTime
        Styles.Content = DM.cxStyleVidelString
        Width = 83
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1RASM_NAME_HOT_SNF: TcxGridDBBandedColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'RASM_NAME_HOT_SNF'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1RASM_NAME_HOT_SNFPropertiesButtonClick
        Styles.Content = DM.cxStyleVidelString
        Width = 83
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1RASM_NAME_HOT_SCATNOM: TcxGridDBBandedColumn
        Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103
        DataBinding.FieldName = 'RASM_NAME_HOT_SCATNOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1RASM_NAME_HOT_SCATNOMPropertiesButtonClick
        Styles.Content = DM.cxStyleVidelString
        Width = 81
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1RASM_NAME_HOT_STYPEPOS: TcxGridDBBandedColumn
        Caption = #1058#1080#1087' '#1087#1086#1089#1077#1083#1077#1085#1080#1103
        DataBinding.FieldName = 'RASM_NAME_HOT_STYPEPOS'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1RASM_NAME_HOT_STYPEPOSPropertiesButtonClick
        Styles.Content = DM.cxStyleVidelString
        Width = 85
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1RASM_NAME_HOT_SSOSTNOM: TcxGridDBBandedColumn
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
        DataBinding.FieldName = 'RASM_NAME_HOT_SSOSTNOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1RASM_NAME_HOT_SSOSTNOMPropertiesButtonClick
        Styles.Content = DM.cxStyleVidelString
        Width = 85
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1RASM_KOLM_HOT_SOSTNF: TcxGridDBBandedColumn
        Caption = #1052#1077#1089#1090
        DataBinding.FieldName = 'RASM_KOLM_HOT_SOSTNF'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Content = DM.cxStyleVidelString
        Width = 25
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1RASM_NAMEGUEST: TcxGridDBBandedColumn
        Caption = #1043#1086#1089#1090#1100
        DataBinding.FieldName = 'RASM_NAMEGUEST'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1RASM_NAMEGUESTPropertiesButtonClick
        Styles.Content = DM.cxStyleVidelString
        Width = 73
        Position.BandIndex = 0
        Position.ColIndex = 8
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1BR2_POSNACH_HOT_SOSTNF: TcxGridDBBandedColumn
        Caption = #1047#1072#1077#1079#1076
        DataBinding.FieldName = 'BR2_POSNACH_HOT_SOSTNF'
        PropertiesClassName = 'TcxDateEditProperties'
        Properties.Kind = ckDateTime
        Width = 71
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1BR2_POSCON_HOT_SOSTNF: TcxGridDBBandedColumn
        Caption = #1042#1099#1077#1079#1076
        DataBinding.FieldName = 'BR2_POSCON_HOT_SOSTNF'
        PropertiesClassName = 'TcxDateEditProperties'
        Properties.Kind = ckDateTime
        Width = 83
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1BR2_NAME_HOT_SNF: TcxGridDBBandedColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'BR2_NAME_HOT_SNF'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1BR2_NAME_HOT_SNFPropertiesButtonClick
        Width = 83
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1BR2_NAME_HOT_SCATNOM: TcxGridDBBandedColumn
        Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103
        DataBinding.FieldName = 'BR2_NAME_HOT_SCATNOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1BR2_NAME_HOT_SCATNOMPropertiesButtonClick
        Width = 81
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1BR2_NAME_HOT_STYPEPOS: TcxGridDBBandedColumn
        Caption = #1058#1080#1087' '#1087#1086#1089#1077#1083#1077#1085#1080#1103
        DataBinding.FieldName = 'BR2_NAME_HOT_STYPEPOS'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Width = 85
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1BR2_NAME_HOT_SSOSTNOM: TcxGridDBBandedColumn
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
        DataBinding.FieldName = 'BR2_NAME_HOT_SSOSTNOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Width = 85
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1BR2_KOLM_HOT_SOSTNF: TcxGridDBBandedColumn
        Caption = #1052#1077#1089#1090
        DataBinding.FieldName = 'BR2_KOLM_HOT_SOSTNF'
        PropertiesClassName = 'TcxCalcEditProperties'
        Width = 25
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1BR2_NAMEGUEST: TcxGridDBBandedColumn
        Caption = #1043#1086#1089#1090#1100
        DataBinding.FieldName = 'BR2_NAMEGUEST'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Width = 73
        Position.BandIndex = 0
        Position.ColIndex = 8
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1BR: TcxGridDBBandedColumn
        Caption = #1041#1088#1086#1085#1080#1088#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'BR'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBBandedTableView1BRPropertiesButtonClick
        Styles.Content = DM.cxStyleVidStringSkyBlue
        Width = 105
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1RASM: TcxGridDBBandedColumn
        Caption = #1056#1072#1079#1084#1077#1097#1077#1085#1080#1077
        DataBinding.FieldName = 'RASM'
        Options.Editing = False
        Styles.Content = DM.cxStyleVidelString
        Width = 105
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1BR2: TcxGridDBBandedColumn
        Caption = #1054#1089#1090'. '#1073#1088#1086#1085#1080#1088#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'BR2'
        Options.Editing = False
        Width = 105
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 2
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBBandedTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 8
    Top = 112
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
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
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 168
    Top = 24
  end
end
