object HOT_FormaDocReal: THOT_FormaDocReal
  Left = 288
  Top = 180
  Caption = #1056#1077#1072#1083#1080#1079#1072#1094#1080#1103' '#1090#1086#1074#1072#1088#1086#1074' '#1080' '#1091#1089#1083#1091#1075' '#1074' '#1075#1086#1089#1090#1080#1085#1080#1094#1077
  ClientHeight = 634
  ClientWidth = 817
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
  object Panel2: TPanel
    Left = 0
    Top = 198
    Width = 4
    Height = 245
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel3: TPanel
    Left = 0
    Top = 443
    Width = 817
    Height = 191
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object FSummaCheck: TLabel
      Left = 507
      Top = 79
      Width = 81
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1091#1084#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object SumDocDBText: TDBText
      Left = 606
      Top = 79
      Width = 154
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'SUM_HOT_GALLDOC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object DBTextFNameUser: TDBText
      Left = 5
      Top = 158
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
    object ProsmotrLabel: TLabel
      Left = 5
      Top = 130
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
    object cxButtonDvReg: TcxButton
      Left = 516
      Top = 139
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 2
    end
    object cxButtonSave: TcxButton
      Left = 416
      Top = 139
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonOK: TcxButton
      Left = 615
      Top = 139
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 3
    end
    object cxButtonClose: TcxButton
      Left = 715
      Top = 139
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 4
    end
    object cxButton1: TcxButton
      Left = 4
      Top = 79
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1063#1077#1082' '#1050#1050#1052
      TabOrder = 5
      OnClick = cxButton1Click
    end
    object cxButton2: TcxButton
      Left = 103
      Top = 79
      Width = 139
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1077#1072#1083#1080#1079#1072#1094#1080#1103' ('#1088#1086#1079#1085'.)'
      TabOrder = 6
      OnClick = cxButton2Click
    end
    object cxButton3: TcxButton
      Left = 250
      Top = 79
      Width = 135
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1077#1072#1083#1080#1079#1072#1094#1080#1103' ('#1086#1087#1090'.)'
      TabOrder = 7
      OnClick = cxButton3Click
    end
    object cxGroupBox1: TcxGroupBox
      Left = 4
      Top = 7
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1086#1085#1090#1088#1086#1083#1100#1085#1086'-'#1082#1072#1089#1089#1086#1074#1072#1103' '#1084#1072#1096#1080#1085#1072':'
      TabOrder = 0
      Height = 48
      Width = 794
      object Label5: TLabel
        Left = 160
        Top = 22
        Width = 87
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1079#1072#1074#1086#1076#1089#1082#1086#1081' '#8470
      end
      object Label6: TLabel
        Left = 377
        Top = 22
        Width = 42
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1088#1077#1075'. '#8470
      end
      object Label8: TLabel
        Left = 501
        Top = 22
        Width = 34
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #8470' '#1050#1051
      end
      object Label9: TLabel
        Left = 647
        Top = 22
        Width = 48
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #8470' '#1095#1077#1082#1072
      end
      object NameKKMcxDBTextEdit: TcxDBTextEdit
        Left = 4
        Top = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMEKKM_HOT_DREAL'
        TabOrder = 0
        OnKeyDown = NameKKMcxDBTextEditKeyDown
        Width = 149
      end
      object ZavNumbercxDBTextEdit: TcxDBTextEdit
        Left = 251
        Top = 15
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'ZAVNUM_HOT_DREAL'
        TabOrder = 1
        OnKeyDown = ZavNumbercxDBTextEditKeyDown
        Width = 118
      end
      object RegNumbercxDBTextEdit: TcxDBTextEdit
        Left = 426
        Top = 15
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'REGNUM_HOT_DREAL'
        TabOrder = 2
        OnKeyDown = RegNumbercxDBTextEditKeyDown
        Width = 68
      end
      object NumberKLcxDBTextEdit: TcxDBTextEdit
        Left = 555
        Top = 15
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NUMKL_HOT_DREAL'
        TabOrder = 3
        OnKeyDown = NumberKLcxDBTextEditKeyDown
        Width = 85
      end
      object NumCheckcxDBTextEdit: TcxDBTextEdit
        Left = 700
        Top = 15
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NUMCHECK_HOT_DREAL'
        TabOrder = 4
        OnKeyDown = NumCheckcxDBTextEditKeyDown
        Width = 80
      end
    end
  end
  object Panel4: TPanel
    Left = 814
    Top = 198
    Width = 3
    Height = 245
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 4
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 817
    Height = 198
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 10
      Top = 92
      Width = 299
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1077#1072#1083#1080#1079#1072#1094#1080#1103' ('#1075#1086#1089#1090'.) '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 484
      Top = 92
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
    object Label7: TLabel
      Left = 7
      Top = 172
      Width = 86
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label12: TLabel
      Left = 11
      Top = 44
      Width = 47
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
      Font.Style = []
      ParentFont = False
    end
    object Label13: TLabel
      Left = 441
      Top = 44
      Width = 70
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label14: TLabel
      Left = 11
      Top = 135
      Width = 82
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
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 466
      Top = 74
      Width = 43
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1082#1083#1072#1076':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 817
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 7
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
      object ToolButtonPrintNakl: TToolButton
        Left = 137
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1089#1095#1077#1090#1072' '#1089' '#1076#1086#1087'. '#1091#1089#1083#1091#1075#1072#1084#1080
        Caption = 'ToolButtonPrintNakl'
        ImageIndex = 42
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintNaklClick
      end
      object ToolButtonPrintAkt: TToolButton
        Left = 160
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1089#1095#1077#1090#1072' '#1073#1077#1079' '#1076#1086#1087'. '#1091#1089#1083#1091#1075
        Caption = 'ToolButtonPrintAkt'
        ImageIndex = 42
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintAktClick
      end
      object ToolButtonPrintOneGuest: TToolButton
        Left = 183
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1089#1095#1077#1090#1072' '#1086#1076#1085#1086#1084#1091' '#1075#1086#1089#1090#1102
        Caption = 'ToolButtonPrintOneGuest'
        ImageIndex = 42
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintOneGuestClick
      end
      object ToolButtonPrintSF: TToolButton
        Left = 206
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1089#1095#1077#1090#1072' '#1092#1072#1082#1090#1091#1088#1099' '#1089' '#1076#1086#1087'. '#1091#1089#1083#1091#1075#1072#1084#1080
        Caption = 'ToolButtonPrintSF'
        ImageIndex = 42
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintSFClick
      end
      object ToolButtonPrintSFNoDopUslug: TToolButton
        Left = 229
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1089#1095#1077#1090#1072' '#1092#1072#1082#1090#1091#1088#1099' '#1073#1077#1079' '#1076#1086#1087'. '#1091#1089#1083#1091#1075
        Caption = 'ToolButtonPrintSFNoDopUslug'
        ImageIndex = 42
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintSFNoDopUslugClick
      end
      object ToolButtonPrintSFOneGuest: TToolButton
        Left = 252
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1089#1095#1077#1090#1072' '#1092#1072#1082#1090#1091#1088#1099' '#1086#1076#1085#1086#1084#1091' '#1075#1086#1089#1090#1102
        Caption = 'ToolButtonPrintSFOneGuest'
        ImageIndex = 42
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonPrintSFOneGuestClick
      end
      object ToolButton3: TToolButton
        Left = 275
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButtonExtModule: TToolButton
        Left = 283
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 551
      Top = 44
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
      TabOrder = 0
      Width = 254
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 112
      Top = 44
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
      TabOrder = 1
      Width = 257
    end
    object NumberDoccxDBTextEdit: TcxDBTextEdit
      Left = 356
      Top = 103
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMBER_HOT_GALLDOC'
      TabOrder = 3
      OnKeyDown = NumberDoccxDBTextEditKeyDown
      Width = 120
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 535
      Top = 103
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POS_HOT_GALLDOC'
      Properties.Kind = ckDateTime
      TabOrder = 4
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 149
    end
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 112
      Top = 135
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
      TabOrder = 5
      Width = 256
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 112
      Top = 169
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PRIM_HOT_DREAL'
      TabOrder = 6
      OnKeyDown = PrimcxDBTextEditKeyDown
      Width = 572
    end
    object NameSkladcxDBButtonEdit: TcxDBButtonEdit
      Left = 551
      Top = 70
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
      Width = 254
    end
    object TypePricecxDBLookupComboBox: TcxDBLookupComboBox
      Left = 448
      Top = 135
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'IDTPRICE_HOT_DREAL'
      Properties.KeyFieldNames = 'ID_TPRICE'
      Properties.ListColumns = <
        item
          FieldName = 'NAME_TPRICE'
        end>
      TabOrder = 8
      Width = 249
    end
    object cxLabel2: TcxLabel
      Left = 391
      Top = 137
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1072#1088#1080#1092':'
    end
  end
  object cxGrid1: TcxGrid
    Left = 4
    Top = 198
    Width = 810
    Height = 245
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          FieldName = 'SUM_HOT_DREALT'
          Column = cxGrid1DBTableView1SUM_HOT_DREALT
          DisplayText = #1057#1091#1084#1084#1072':'
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 39
      end
      object cxGrid1DBTableView1TUSL_HOT_DREALT: TcxGridDBColumn
        Caption = #1058#1080#1087
        DataBinding.FieldName = 'TUSL_HOT_DREALT'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          #1053#1077' '#1079#1072#1076'.'
          #1054#1089#1085'.'
          #1041#1088#1086#1085'.'
          #1044#1086#1087'.'
          #1055#1080#1090'.')
        Properties.ReadOnly = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 44
      end
      object cxGrid1DBTableView1VIBORTYPEPRICE: TcxGridDBColumn
        Caption = #1058#1072#1088#1080#1092
        DataBinding.FieldName = 'VIBORTYPEPRICE'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 80
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
        Styles.Header = DM.cxStyleHeaderTable
        Width = 173
      end
      object cxGrid1DBTableView1KOL_HOT_DREALT: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOL_HOT_DREALT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 37
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
        Styles.Header = DM.cxStyleHeaderTable
        Width = 57
      end
      object cxGrid1DBTableView1KF_HOT_DREALT: TcxGridDBColumn
        Caption = #1050#1060
        DataBinding.FieldName = 'KF_HOT_DREALT'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 49
      end
      object cxGrid1DBTableView1PRICE_HOT_DREALT: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'PRICE_HOT_DREALT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 88
      end
      object cxGrid1DBTableView1SUM_HOT_DREALT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_HOT_DREALT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Footer = DM.cxStyleFooterSum
        Styles.Header = DM.cxStyleHeaderTable
        Width = 89
      end
    end
    object cxGrid1DBBandedTableView1: TcxGridDBBandedTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsSelection.InvertSelect = False
      OptionsView.NoDataToDisplayInfoText = '<'#1053#1077#1090' '#1076#1072#1085#1085#1099#1093'>'
      OptionsView.ColumnAutoWidth = True
      OptionsView.RowSeparatorWidth = 2
      OptionsView.FixedBandSeparatorWidth = 4
      Styles.Header = DM.cxStyleHeaderTable
      Bands = <
        item
          Caption = #1056#1077#1072#1083#1080#1079#1072#1094#1080#1103' '#1090#1086#1074#1072#1088#1086#1074' '#1080' '#1091#1089#1083#1091#1075
        end>
      object cxGrid1DBBandedTableView1RECNO: TcxGridDBBandedColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Width = 49
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAME_HOT_SNF: TcxGridDBBandedColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NAME_HOT_SNF'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_HOT_SNFPropertiesButtonClick
        Width = 90
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAME_HOT_SCATNOM: TcxGridDBBandedColumn
        Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103
        DataBinding.FieldName = 'NAME_HOT_SCATNOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_HOT_SCATNOMPropertiesButtonClick
        Width = 97
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAME_HOT_STYPEPOS: TcxGridDBBandedColumn
        Caption = #1058#1080#1087' '#1087#1086#1089#1077#1083#1077#1085#1080#1103
        DataBinding.FieldName = 'NAME_HOT_STYPEPOS'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_HOT_STYPEPOSPropertiesButtonClick
        Width = 98
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAMEKLIENT: TcxGridDBBandedColumn
        Caption = #1043#1086#1089#1090#1100
        DataBinding.FieldName = 'NAMEKLIENT'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAMEKLIENTPropertiesButtonClick
        Width = 130
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1POSNACH_HOT_DREALT: TcxGridDBBandedColumn
        Caption = #1053#1072#1095#1072#1083#1086' '#1080#1085#1090#1077#1088#1074#1072#1083#1072
        DataBinding.FieldName = 'POSNACH_HOT_DREALT'
        PropertiesClassName = 'TcxDateEditProperties'
        Properties.Kind = ckDateTime
        Width = 98
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1POSCON_HOT_DREALT: TcxGridDBBandedColumn
        Caption = #1050#1086#1085#1077#1094' '#1080#1085#1090#1077#1088#1074#1072#1083#1072
        DataBinding.FieldName = 'POSCON_HOT_DREALT'
        PropertiesClassName = 'TcxDateEditProperties'
        Properties.Kind = ckDateTime
        Width = 94
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1TUSL_HOT_DREALT: TcxGridDBBandedColumn
        Caption = #1058#1080#1087
        DataBinding.FieldName = 'TUSL_HOT_DREALT'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.DropDownListStyle = lsFixedList
        Properties.Items.Strings = (
          #1053#1077' '#1079#1072#1076'.'
          #1054#1089#1085'.'
          #1041#1088#1086#1085'.'
          #1044#1086#1087'.'
          #1055#1080#1090'.')
        Styles.Content = DM.cxStyleVidelString
        Width = 49
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1VIBORTYPEPRICE: TcxGridDBBandedColumn
        Caption = #1058#1072#1088#1080#1092
        DataBinding.FieldName = 'VIBORTYPEPRICE'
        Styles.Content = DM.cxStyleVidelString
        Width = 98
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 1
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
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAMENOMPropertiesButtonClick
        Styles.Content = DM.cxStyleVidelString
        Width = 221
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1KOL_HOT_DREALT: TcxGridDBBandedColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOL_HOT_DREALT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Content = DM.cxStyleVidelString
        Width = 60
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 1
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
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAMEEDPropertiesButtonClick
        Styles.Content = DM.cxStyleVidelString
        Width = 77
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1KF_HOT_DREALT: TcxGridDBBandedColumn
        Caption = #1050#1060
        DataBinding.FieldName = 'KF_HOT_DREALT'
        Options.Editing = False
        Styles.Content = DM.cxStyleVidelString
        Width = 39
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1PRICE_HOT_DREALT: TcxGridDBBandedColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'PRICE_HOT_DREALT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Content = DM.cxStyleVidelString
        Width = 56
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1SUM_HOT_DREALT: TcxGridDBBandedColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_HOT_DREALT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Content = DM.cxStyleVidelString
        Width = 56
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 1
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBBandedTableView1
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 184
    Top = 40
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
    Left = 280
    Top = 24
  end
end
