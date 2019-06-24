object FormaDocVosvratPok: TFormaDocVosvratPok
  Left = 290
  Top = 119
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1042#1086#1079#1074#1088#1072#1090' '#1086#1090' '#1087#1086#1082#1091#1087#1072#1090#1077#1083#1103'"'
  ClientHeight = 602
  ClientWidth = 913
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
    Top = 517
    Width = 913
    Height = 85
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object DBTextFNameUser: TDBText
      Left = 20
      Top = 26
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
      Left = 20
      Top = 42
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
    object cxButtonPrint: TcxButton
      Left = 327
      Top = 41
      Width = 91
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 0
    end
    object cxButtonSave: TcxButton
      Left = 427
      Top = 41
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonDvReg: TcxButton
      Left = 527
      Top = 41
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 2
    end
    object cxButtonOK: TcxButton
      Left = 626
      Top = 41
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 3
    end
    object cxButtonClose: TcxButton
      Left = 726
      Top = 41
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 4
    end
    object cxButtonCreateRKORozn: TcxButton
      Left = 228
      Top = 41
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1056#1072#1089#1093#1086#1076' '#1085#1072#1083'.'
      TabOrder = 5
      OnClick = cxButtonCreateRKORoznClick
    end
    object DocOsncxDBButtonEdit: TcxDBButtonEdit
      Left = 522
      Top = 11
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
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
      Width = 384
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 409
    Width = 11
    Height = 108
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 902
    Top = 409
    Width = 11
    Height = 108
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
    Width = 913
    Height = 409
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 25
      Top = 108
      Width = 293
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1086#1090' '#1087#1086#1082#1091#1087#1072#1090#1077#1083#1103'  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 593
      Top = 103
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
      Left = 20
      Top = 378
      Width = 86
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label4: TLabel
      Left = 30
      Top = 150
      Width = 82
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1086#1082#1091#1087#1072#1090#1077#1083#1100':'
    end
    object Label5: TLabel
      Left = 26
      Top = 76
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
      Top = 35
      Width = 43
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1082#1083#1072#1076':'
    end
    object Label7: TLabel
      Left = 534
      Top = 146
      Width = 136
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1079#1072#1082#1091#1087#1086#1095#1085#1099#1093' '#1094#1077#1085':'
    end
    object Label8: TLabel
      Left = 541
      Top = 178
      Width = 129
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1088#1086#1079#1085#1080#1095#1085#1099#1093' '#1094#1077#1085':'
    end
    object Label9: TLabel
      Left = 42
      Top = 210
      Width = 68
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1087#1077#1088#1072#1094#1080#1103':'
    end
    object Label11: TLabel
      Left = 49
      Top = 180
      Width = 58
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1075#1086#1074#1086#1088':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 913
      Height = 28
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 23
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
      object ToolButtonPodbor: TToolButton
        Left = 40
        Top = 0
        Caption = 'ToolButtonPodbor'
        ImageIndex = 14
        OnClick = ToolButtonPodborClick
      end
      object ToolButtonDelete: TToolButton
        Left = 63
        Top = 0
        Action = ActionDeleteString
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton2: TToolButton
        Left = 86
        Top = 0
        Width = 171
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 257
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButtonextModule: TToolButton
        Left = 265
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonextModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonNewDocRKO: TToolButton
        Left = 288
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1056#1072#1089#1093#1086#1076#1085#1099#1081' '#1082#1072#1089#1089#1086#1074#1099#1081' '#1086#1088#1076#1077#1088
        Caption = 'ToolButtonNewDocRKO'
        ImageIndex = 52
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateDocRKO: TToolButton
        Left = 311
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1056#1072#1089#1093#1086#1076#1085#1099#1081' '#1082#1072#1089#1089#1086#1074#1099' '#1086#1088#1076#1077#1088
        Caption = 'ToolButtonCreateDocRKO'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateDocRKOClick
      end
    end
    object DescrcxDBTextEdit: TcxDBTextEdit
      Left = 114
      Top = 379
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'DESCR_DVPOK'
      TabOrder = 22
      OnKeyDown = DescrcxDBTextEditKeyDown
      Width = 476
    end
    object OperComboBox: TcxComboBox
      Left = 114
      Top = 206
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.DropDownListStyle = lsFixedList
      Properties.Items.Strings = (
        '0 - '#1085#1077' '#1079#1072#1076#1072#1085#1072
        '1 - '#1074#1086#1079#1074#1088#1072#1090' '#1088#1086#1079#1085#1080#1095#1086#1081' '#1087#1088#1086#1076#1072#1078#1080
        '2 - '#1074#1086#1079#1074#1088#1072#1090' '#1086#1087#1090#1086#1074#1086#1081' '#1087#1088#1086#1076#1072#1078#1080
        '3 - '#1074#1086#1079#1074#1088#1072#1090' '#1082#1088#1077#1076#1080#1090#1072)
      Properties.OnChange = OperComboBoxPropertiesChange
      TabOrder = 10
      OnKeyDown = OperComboBoxKeyDown
      Width = 355
    end
    object TypePriceComboBox: TcxComboBox
      Left = 678
      Top = 142
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.DropDownListStyle = lsFixedList
      Properties.OnChange = TypePriceComboBoxPropertiesChange
      TabOrder = 11
      Width = 191
    end
    object TypeRPriceComboBox: TcxComboBox
      Left = 678
      Top = 174
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Properties.DropDownListStyle = lsFixedList
      Properties.OnChange = TypeRPriceComboBoxPropertiesChange
      TabOrder = 12
      Width = 191
    end
    object NameDogcxDBButtonEdit: TcxDBButtonEdit
      Left = 114
      Top = 177
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
      Properties.OnButtonClick = NameDogcxDBButtonEditPropertiesButtonClick
      TabOrder = 9
      Width = 355
    end
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 114
      Top = 147
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
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 8
      Width = 355
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 503
      Top = 111
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUMDOC'
      TabOrder = 6
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 90
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 626
      Top = 110
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POSDOC'
      Properties.Kind = ckDateTime
      TabOrder = 7
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 253
    end
    object NameSkladcxDBButtonEdit: TcxDBButtonEdit
      Left = 532
      Top = 32
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
      Width = 301
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 78
      Top = 73
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
      Width = 302
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 78
      Top = 42
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
      Properties.OnButtonClick = NmaeInfBasecxDBButtonEditPropertiesButtonClick
      TabOrder = 0
      Width = 302
    end
    object cxLabel1: TcxLabel
      Left = 2
      Top = 43
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
    object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
      Left = 561
      Top = 57
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
      Width = 272
    end
    object cxLabel9: TcxLabel
      Left = 437
      Top = 58
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
    end
    object cxLabel3: TcxLabel
      Left = 503
      Top = 83
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1086#1077#1082#1090':'
    end
    object NameProjectcxDBButtonEdit: TcxDBButtonEdit
      Left = 561
      Top = 82
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
      Width = 272
    end
    object KlientNameStrcxDBTextEdit: TcxDBTextEdit
      Left = 114
      Top = 235
      DataBinding.DataField = 'KLIENT_NAME_DVPOK'
      TabOrder = 13
      Width = 371
    end
    object cxLabel5: TcxLabel
      Left = -1
      Top = 236
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1083#1080#1077#1085#1090' ('#1089#1090#1088#1086#1082#1072'):'
    end
    object cxLabel6: TcxLabel
      Left = 61
      Top = 264
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1040#1076#1088#1077#1089':'
    end
    object KlientAdrcxDBTextEdit: TcxDBTextEdit
      Left = 114
      Top = 262
      DataBinding.DataField = 'KLIENT_ADR_DVPOK'
      TabOrder = 14
      Width = 371
    end
    object KlientPhonecxDBTextEdit: TcxDBTextEdit
      Left = 114
      Top = 292
      DataBinding.DataField = 'KLIENT_PHONE_DVPOK'
      TabOrder = 15
      Width = 371
    end
    object cxLabel8: TcxLabel
      Left = 40
      Top = 295
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1077#1083#1077#1092#1086#1085':'
    end
    object cxLabel11: TcxLabel
      Left = 44
      Top = 322
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1072#1089#1087#1086#1088#1090':'
    end
    object PassportcxDBTextEdit: TcxDBTextEdit
      Left = 114
      Top = 322
      DataBinding.DataField = 'KLIENT_PASSPORT_DVPOK'
      TabOrder = 16
      Width = 761
    end
    object PrichinacxDBTextEdit: TcxDBTextEdit
      Left = 114
      Top = 349
      DataBinding.DataField = 'PRICHINA_DVPOK'
      TabOrder = 17
      Width = 761
    end
    object cxLabel10: TcxLabel
      Left = 44
      Top = 350
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1095#1080#1085#1072':'
    end
    object NumDocSalecxDBTextEdit: TcxDBTextEdit
      Left = 529
      Top = 282
      DataBinding.DataField = 'NUMDOCSALE_DVPOK'
      TabOrder = 20
      Width = 205
    end
    object PosDocSalecxDBDateEdit: TcxDBDateEdit
      Left = 748
      Top = 282
      DataBinding.DataField = 'POSDOCSALE_DVPOK'
      TabOrder = 21
      Width = 121
    end
    object cxLabel4: TcxLabel
      Left = 529
      Top = 259
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1087#1088#1086#1076#1072#1078#1080':'
    end
    object NumDocKlientcxDBTextEdit: TcxDBTextEdit
      Left = 529
      Top = 228
      DataBinding.DataField = 'NUMDOCKL_DVPOK'
      TabOrder = 18
      Width = 205
    end
    object cxLabel2: TcxLabel
      Left = 529
      Top = 201
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1082#1083#1080#1077#1085#1090#1072':'
    end
    object PosDocKlientcxDBDateEdit: TcxDBDateEdit
      Left = 748
      Top = 228
      DataBinding.DataField = 'POSDOCKL_DVPOK'
      TabOrder = 19
      Width = 121
    end
    object PrefiksNumcxDBTextEdit: TcxDBTextEdit
      Left = 350
      Top = 111
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PREFIKS_NUM_GALLDOC'
      TabOrder = 5
      OnKeyDown = PrefiksNumcxDBTextEditKeyDown
      Width = 145
    end
  end
  object cxGrid1: TcxGrid
    Left = 11
    Top = 409
    Width = 891
    Height = 108
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          Column = cxGrid1DBTableView1RSUM_DVPOKT
        end
        item
          Kind = skSum
          Column = cxGrid1DBTableView1SUM_DVPOKT
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsSelection.InvertSelect = False
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.GroupByBox = False
      Styles.Footer = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 43
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
        Styles.Header = DM.cxStyleHeaderTable
        Width = 202
      end
      object cxGrid1DBTableView1KOL_DVPOKT: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOL_DVPOKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 43
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
        Width = 53
      end
      object cxGrid1DBTableView1KF_DVPOKT: TcxGridDBColumn
        Caption = #1050
        DataBinding.FieldName = 'KF_DVPOKT'
        Options.Editing = False
        Styles.Header = DM.cxStyleHeaderTable
        Width = 45
      end
      object cxGrid1DBTableView1PRICE_DVPOKT: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'PRICE_DVPOKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 80
      end
      object cxGrid1DBTableView1SUM_DVPOKT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_DVPOKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 80
      end
      object cxGrid1DBTableView1RPRICE_DVPOKT: TcxGridDBColumn
        Caption = #1056#1086#1079#1085'. '#1094#1077#1085#1072
        DataBinding.FieldName = 'RPRICE_DVPOKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 78
      end
      object cxGrid1DBTableView1RSUM_DVPOKT: TcxGridDBColumn
        Caption = #1056#1086#1079#1085'. '#1089#1091#1084#1084#1072
        DataBinding.FieldName = 'RSUM_DVPOKT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Header = DM.cxStyleHeaderTable
        Width = 80
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
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
    object ActionPrint: TAction
      Caption = #1055#1077#1095#1072#1090#1100
      ImageIndex = 43
      OnExecute = ActionPrintExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 208
    Top = 8
  end
end
