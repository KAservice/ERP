object REM_FormaDocZStart: TREM_FormaDocZStart
  Left = 290
  Top = 119
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1053#1072#1095#1072#1083#1086' '#1088#1077#1084#1086#1085#1090#1072'"'
  ClientHeight = 712
  ClientWidth = 901
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
    Top = 616
    Width = 901
    Height = 96
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object DBTextFNameUser: TDBText
      Left = 20
      Top = 10
      Width = 139
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'FNAME_USER'
      DataSource = REM_DMDocRemont.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 20
      Top = 30
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
    object LabelInfo: TLabel
      Left = 0
      Top = 80
      Width = 55
      Height = 16
      Caption = 'LabelInfo'
    end
    object cxButtonPrint: TcxButton
      Left = 230
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 0
    end
    object cxButtonSave: TcxButton
      Left = 330
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonDvReg: TcxButton
      Left = 430
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 2
    end
    object cxButtonOK: TcxButton
      Left = 529
      Top = 49
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
      Left = 629
      Top = 49
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 4
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 618
    Width = 0
    Height = 8
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 899
    Top = 618
    Width = 2
    Height = 8
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
    Width = 901
    Height = 618
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 59
      Top = 98
      Width = 218
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1072#1095#1072#1083#1086' '#1088#1077#1084#1086#1085#1090#1072'  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 441
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
    object Label3: TLabel
      Left = 27
      Top = 561
      Width = 86
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object Label5: TLabel
      Left = 28
      Top = 69
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
      Top = 43
      Width = 43
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1082#1083#1072#1076':'
    end
    object Label4: TLabel
      Left = 30
      Top = 158
      Width = 50
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1083#1080#1077#1085#1090':'
    end
    object Label7: TLabel
      Left = 30
      Top = 197
      Width = 50
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1103#1074#1082#1072':'
    end
    object Label8: TLabel
      Left = 511
      Top = 177
      Width = 14
      Height = 16
      Caption = #8470
    end
    object Label9: TLabel
      Left = 688
      Top = 177
      Width = 15
      Height = 16
      Caption = #1086#1090
    end
    object Label11: TLabel
      Left = 573
      Top = 276
      Width = 49
      Height = 16
      Caption = #1057#1077#1088' '#8470'2'
    end
    object Label12: TLabel
      Left = 489
      Top = 78
      Width = 87
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1058#1080#1087' '#1088#1077#1084#1086#1085#1090#1072':'
    end
    object Label27: TLabel
      Left = 19
      Top = 241
      Width = 72
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1086#1080#1079#1074'-'#1083#1100':'
    end
    object Label25: TLabel
      Left = 566
      Top = 306
      Width = 55
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1077#1088' '#8470' 3:'
    end
    object Label26: TLabel
      Left = 566
      Top = 336
      Width = 55
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1077#1088' '#8470' 4:'
    end
    object Label24: TLabel
      Left = 546
      Top = 364
      Width = 75
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1086#1084#1077#1088' '#1040#1050#1041':'
    end
    object Label21: TLabel
      Left = 767
      Top = 388
      Width = 95
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1072#1090#1072' '#1087#1088#1086#1076#1072#1078#1080':'
    end
    object Label20: TLabel
      Left = 567
      Top = 388
      Width = 93
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1044#1072#1090#1072' '#1074#1099#1087#1091#1089#1082#1072':'
    end
    object Label22: TLabel
      Left = 567
      Top = 436
      Width = 69
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1088#1086#1076#1072#1074#1077#1094':'
    end
    object Label16: TLabel
      Left = 567
      Top = 490
      Width = 101
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1054' '#1076#1086' '#1088#1077#1084#1086#1085#1090#1072':'
    end
    object Label14: TLabel
      Left = 26
      Top = 462
      Width = 312
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100' ('#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103') '#1082#1083#1080#1077#1085#1090#1072' (CFC):'
    end
    object Label13: TLabel
      Left = 264
      Top = 336
      Width = 70
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1077#1084' '#1089#1076#1072#1085#1086':'
    end
    object Label28: TLabel
      Left = 26
      Top = 301
      Width = 158
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1052#1086#1076#1077#1083#1100' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103':'
    end
    object Label15: TLabel
      Left = 27
      Top = 388
      Width = 105
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100':'
    end
    object Label18: TLabel
      Left = 35
      Top = 592
      Width = 73
      Height = 16
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077':'
    end
    object Label17: TLabel
      Left = 552
      Top = 218
      Width = 71
      Height = 16
      Caption = #8470' '#1075#1072#1088'. '#1076#1086#1082'.'
    end
    object Label19: TLabel
      Left = 573
      Top = 248
      Width = 49
      Height = 16
      Caption = #1057#1077#1088' '#8470'1'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 901
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 6
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
      object ToolButtonOpenExtModule: TToolButton
        Left = 242
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonOpenExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateCheck: TToolButton
        Left = 265
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1063#1077#1082' '#1050#1050#1052
        Caption = 'ToolButtonCreateCheck'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateRealRozn: TToolButton
        Left = 288
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' "'#1056#1077#1072#1083#1080#1079#1072#1094#1080#1103' '#1088#1086#1079#1085'."'
        Caption = 'ToolButtonCreateRealRozn'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateReal: TToolButton
        Left = 311
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' "'#1056#1077#1072#1083#1080#1079#1072#1094#1080#1103'"'
        Caption = 'ToolButtonCreateReal'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonOpenZayavka: TToolButton
        Left = 334
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1079#1072#1103#1074#1082#1091
        Caption = 'ToolButtonOpenZayavka'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenZayavkaClick
      end
      object ToolButtonSetOtchitanZayvka: TToolButton
        Left = 357
        Top = 0
        Hint = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1092#1083#1072#1075' '#1086#1090#1095#1080#1090#1072#1085' '#1074' '#1079#1072#1103#1074#1082#1077
        Caption = 'ToolButtonSetOtchitanZayvka'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSetOtchitanZayvkaClick
      end
      object ToolButtonAddDataInZ: TToolButton
        Left = 380
        Top = 0
        Hint = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1076#1072#1085#1085#1099#1084#1080' '#1080#1079' '#1079#1072#1103#1074#1082#1080
        Caption = 'ToolButtonAddDataInZ'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddDataInZClick
      end
    end
    object PrimcxDBTextEdit: TcxDBTextEdit
      Left = 114
      Top = 558
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'PRIM_REM_DZSTART'
      TabOrder = 5
      OnKeyDown = PrimcxDBTextEditKeyDown
      Width = 611
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 326
      Top = 102
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUM_REM_GALLDOC'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      TabOrder = 3
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 100
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 485
      Top = 102
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POS_REM_GALLDOC'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      Properties.Kind = ckDateTime
      Properties.OnChange = PosDoccxDBDateEditPropertiesChange
      TabOrder = 4
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 196
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 97
      Top = 65
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEFIRM'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = False
      Properties.OnButtonClick = NameFirmcxDBButtonEditPropertiesButtonClick
      TabOrder = 1
      Width = 337
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 98
      Top = 38
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_SINFBASE_OBMEN'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = False
      Properties.OnButtonClick = NameInfBasecxDBButtonEditPropertiesButtonClick
      TabOrder = 0
      Width = 336
    end
    object cxLabel1: TcxLabel
      Left = 20
      Top = 39
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
    object NameSkladcxDBButtonEdit: TcxDBButtonEdit
      Left = 532
      Top = 38
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMESKLAD'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameSkladcxDBButtonEditPropertiesButtonClick
      TabOrder = 2
      Width = 306
    end
    object NameKlientcxDBButtonEdit: TcxDBButtonEdit
      Left = 98
      Top = 154
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAMEKLIENT'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 8
      Width = 336
    end
    object NameZcxDBButtonEdit: TcxDBButtonEdit
      Left = 98
      Top = 191
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NAME_REM_Z'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDoc
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameZcxDBButtonEditPropertiesButtonClick
      TabOrder = 9
      Width = 336
    end
    object NameKlientcxDBLabel: TcxDBLabel
      Left = 457
      Top = 134
      DataBinding.DataField = 'KLIENT_NAME_REM_Z'
      Height = 21
      Width = 201
    end
    object ModelcxDBLabel: TcxDBLabel
      Left = 459
      Top = 150
      DataBinding.DataField = 'MODEL_REM_Z'
      Height = 21
      Width = 191
    end
    object PosZcxDBLabel: TcxDBLabel
      Left = 734
      Top = 175
      DataBinding.DataField = 'POS_REM_Z'
      Height = 21
      Width = 121
    end
    object NumZcxDBLabel: TcxDBLabel
      Left = 547
      Top = 177
      DataBinding.DataField = 'NUM_REM_Z'
      Height = 21
      Width = 121
    end
    object TypeRemontcxDBImageComboBox: TcxDBImageComboBox
      Left = 587
      Top = 71
      RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeRemont
      DataBinding.DataField = 'TYPE_REMONT_REM_DZSTART'
      Properties.Items = <>
      TabOrder = 14
      Width = 251
    end
    object ProducercxDBButtonEdit: TcxDBButtonEdit
      Left = 98
      Top = 238
      DataBinding.DataField = 'NAME_SPRODUCER'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.OnButtonClick = ProducercxDBButtonEditPropertiesButtonClick
      TabOrder = 15
      Width = 336
    end
    object SerNum3cxDBTextEdit: TcxDBTextEdit
      Left = 628
      Top = 303
      DataBinding.DataField = 'SERNUM3_REM_DZSTART'
      TabOrder = 16
      Width = 226
    end
    object SerNum4cxDBTextEdit: TcxDBTextEdit
      Left = 628
      Top = 333
      DataBinding.DataField = 'SERNUM4_REM_DZSTART'
      TabOrder = 17
      Width = 226
    end
    object NumBatcxDBTextEdit: TcxDBTextEdit
      Left = 628
      Top = 363
      DataBinding.DataField = 'NUMBAT_REM_DZSTART'
      TabOrder = 18
      Width = 226
    end
    object DateVipuskcxDBDateEdit: TcxDBDateEdit
      Left = 567
      Top = 411
      DataBinding.DataField = 'DATEVIPUSK_REM_DZSTART'
      TabOrder = 19
      Width = 121
    end
    object DateProdagicxDBDateEdit: TcxDBDateEdit
      Left = 773
      Top = 411
      DataBinding.DataField = 'DATE_PRODAGI_REM_DZSTART'
      TabOrder = 20
      Width = 121
    end
    object ProdaveccxDBTextEdit: TcxDBTextEdit
      Left = 567
      Top = 459
      DataBinding.DataField = 'PRODAVEC_REM_DZSTART'
      TabOrder = 21
      Width = 327
    end
    object PODOcxDBTextEdit: TcxDBTextEdit
      Left = 567
      Top = 513
      DataBinding.DataField = 'PODO_REM_DZSTART'
      TabOrder = 22
      Width = 327
    end
    object CFCPRcxDBButtonEdit: TcxDBButtonEdit
      Left = 123
      Top = 487
      DataBinding.DataField = 'NAME_REM_SPRNEISPR'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      Properties.OnButtonClick = CFCPRcxDBButtonEditPropertiesButtonClick
      TabOrder = 23
      Width = 424
    end
    object KEM_SDANOcxDBImageComboBox: TcxDBImageComboBox
      Left = 341
      Top = 333
      RepositoryItem = DM.cxEditRepository1ImageComboBoxREM_KemSdano
      DataBinding.DataField = 'KEM_SDANO_REM_DZSTART'
      Properties.Items = <>
      TabOrder = 24
      Width = 183
    end
    object NameNeisprcxDBButtonEdit: TcxDBButtonEdit
      Left = 123
      Top = 411
      DataBinding.DataField = 'NAME_REM_SNEISPR'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end
        item
          Caption = 'X'
          Kind = bkText
        end>
      TabOrder = 25
      Width = 424
    end
    object ProducerModelcxDBButtonEdit: TcxDBButtonEdit
      Left = 220
      Top = 298
      DataBinding.DataField = 'NAME_REM_SPRMODEL'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.OnButtonClick = ProducerModelcxDBButtonEditPropertiesButtonClick
      TabOrder = 26
      Width = 327
    end
    object SOSTcxDBTextEdit: TcxDBTextEdit
      Left = 115
      Top = 589
      DataBinding.DataField = 'SOST_REM_DZSTART'
      TabOrder = 27
      Width = 610
    end
    object SerNum2cxDBTextEdit: TcxDBTextEdit
      Left = 628
      Top = 273
      DataBinding.DataField = 'SERNUM2_REM_Z'
      Properties.ReadOnly = True
      TabOrder = 28
      Width = 226
    end
    object SerNum1cxDBTextEdit: TcxDBTextEdit
      Left = 628
      Top = 245
      DataBinding.DataField = 'SERNUM_REM_Z'
      Properties.ReadOnly = True
      TabOrder = 29
      Width = 226
    end
    object NumGarDoccxDBTextEdit: TcxDBTextEdit
      Left = 629
      Top = 215
      DataBinding.DataField = 'NUM_GARDOC_REM_Z'
      Properties.ReadOnly = True
      TabOrder = 30
      Width = 226
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
    end
    object ActionDeleteString: TAction
      Caption = 'ActionDeleteString'
      ImageIndex = 2
      ShortCut = 46
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
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 400
    Top = 24
  end
end
