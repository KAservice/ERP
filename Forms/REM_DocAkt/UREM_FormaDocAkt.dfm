object REM_FormaDocAkt: TREM_FormaDocAkt
  Left = 290
  Top = 119
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1040#1082#1090' '#1089#1077#1088#1074#1080#1089#1085#1086#1075#1086' '#1094#1077#1085#1090#1088#1072'"'
  ClientHeight = 547
  ClientWidth = 712
  Color = clBtnFace
  Constraints.MinWidth = 689
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
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 469
    Width = 712
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
    Top = 321
    Width = 0
    Height = 148
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 711
    Top = 321
    Width = 1
    Height = 148
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 712
    Height = 121
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 23
      Top = 80
      Width = 68
      Height = 24
      Caption = #1040#1050#1058' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 202
      Top = 80
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
    object Label5: TLabel
      Left = 23
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
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 712
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 5
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
      object ToolButtonAddDataIsZ: TToolButton
        Left = 265
        Top = 0
        Hint = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1076#1072#1085#1085#1099#1084#1080' '#1080#1079' '#1079#1072#1103#1074#1082#1080
        Caption = 'ToolButtonAddDataIsZ'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddDataIsZClick
      end
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 106
      Top = 85
      DataBinding.DataField = 'NUM_REM_GALLDOC'
      TabOrder = 3
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 81
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 234
      Top = 88
      DataBinding.DataField = 'POS_REM_GALLDOC'
      Properties.Kind = ckDateTime
      Properties.OnChange = PosDoccxDBDateEditPropertiesChange
      TabOrder = 4
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 159
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 79
      Top = 53
      DataBinding.DataField = 'NAMEFIRM'
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.ReadOnly = False
      Properties.OnButtonClick = NameFirmcxDBButtonEditPropertiesButtonClick
      TabOrder = 1
      Width = 274
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
      Properties.ReadOnly = False
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
    object cxLabel9: TcxLabel
      Left = 359
      Top = 58
      Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
    end
    object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
      Left = 460
      Top = 57
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
      TabOrder = 8
      Width = 221
    end
    object NameProjectcxDBButtonEdit: TcxDBButtonEdit
      Left = 460
      Top = 77
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
      TabOrder = 9
      Width = 221
    end
    object cxLabel4: TcxLabel
      Left = 413
      Top = 78
      Caption = #1055#1088#1086#1077#1082#1090':'
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 121
    Width = 712
    Height = 200
    ActivePage = cxTabSheet1
    Align = alTop
    TabOrder = 4
    ClientRectBottom = 200
    ClientRectRight = 712
    ClientRectTop = 24
    object cxTabSheet1: TcxTabSheet
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 0
      object Label3: TLabel
        Left = 5
        Top = 152
        Width = 66
        Height = 13
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
      end
      object Label9: TLabel
        Left = 25
        Top = 63
        Width = 40
        Height = 13
        Caption = #1047#1072#1103#1074#1082#1072':'
      end
      object Label4: TLabel
        Left = 24
        Top = 14
        Width = 39
        Height = 13
        Caption = #1050#1083#1080#1077#1085#1090':'
      end
      object Label8: TLabel
        Left = 412
        Top = 68
        Width = 143
        Height = 13
        Caption = #1053#1086#1084#1077#1088' '#1040#1082#1090#1072' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103
      end
      object PrimcxDBTextEdit: TcxDBTextEdit
        Left = 77
        Top = 149
        DataBinding.DataField = 'PRIM_REM_DAKT'
        TabOrder = 0
        OnKeyDown = PrimcxDBTextEditKeyDown
        Width = 497
      end
      object NameZcxDBButtonEdit: TcxDBButtonEdit
        Left = 80
        Top = 63
        DataBinding.DataField = 'NAME_REM_Z'
        DataBinding.DataSource = REM_DMDocRemont.DataSourceDoc
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
        Properties.OnButtonClick = NameZcxDBButtonEditPropertiesButtonClick
        TabOrder = 1
        Width = 273
      end
      object TypecxDBImageComboBox: TcxDBImageComboBox
        Left = 80
        Top = 37
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeAktRemont
        DataBinding.DataField = 'TYPE_REM_DAKT'
        Properties.Items = <>
        TabOrder = 2
        Width = 274
      end
      object NameKlientcxDBButtonEdit: TcxDBButtonEdit
        Left = 80
        Top = 11
        DataBinding.DataField = 'NAMEKLIENT'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
        TabOrder = 3
        Width = 273
      end
      object SerNumZcxDBLabel: TcxDBLabel
        Left = 80
        Top = 105
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'SERNUM_REM_Z'
        Height = 17
        Width = 179
      end
      object ModelcxDBLabel: TcxDBLabel
        Left = 80
        Top = 89
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        AutoSize = True
        DataBinding.DataField = 'NAME_REM_SMODEL'
      end
      object KlSoglasencxDBCheckBox: TcxDBCheckBox
        Left = 423
        Top = 14
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1082#1083#1080#1077#1085#1090' '#1089#1086#1075#1083#1072#1089#1077#1085' '#1089' '#1072#1082#1090#1086#1084
        DataBinding.DataField = 'KL_SOGLASEN_REM_DAKT'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 6
        Width = 163
      end
      object PodpisancxDBCheckBox: TcxDBCheckBox
        Left = 423
        Top = 39
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1072#1082#1090' '#1087#1086#1076#1087#1080#1089#1072#1085' '#1082#1083#1080#1077#1085#1090#1086#1084
        DataBinding.DataField = 'PODPISAN_REM_DAKT'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 7
        Width = 153
      end
      object SerNum2ZcxDBLabel: TcxDBLabel
        Left = 80
        Top = 123
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'SERNUM2_REM_Z'
        Height = 17
        Width = 160
      end
      object cxDBTextEditNUM_U_PROISV_REM_DAKT: TcxDBTextEdit
        Left = 570
        Top = 65
        DataBinding.DataField = 'NUM_U_PROISV_REM_DAKT'
        TabOrder = 9
        Width = 121
      end
    end
    object cxTabSheet2: TcxTabSheet
      Caption = #1053#1077#1080#1089#1087#1088
      ImageIndex = 1
      object Label7: TLabel
        Left = 23
        Top = 14
        Width = 195
        Height = 13
        Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100' '#1082#1083#1080#1077#1085#1090#1072' ('#1079#1072#1103#1074#1083#1077#1085#1085#1072#1103'):'
      end
      object Label10: TLabel
        Left = 90
        Top = 41
        Width = 97
        Height = 13
        Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100' '#1057#1062
      end
      object Label12: TLabel
        Left = 90
        Top = 68
        Width = 97
        Height = 13
        Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1099#1081' '#1073#1083#1086#1082
      end
      object cxDBTextEditNEISPR_KLIENTA_REM_DAKT: TcxDBTextEdit
        Left = 224
        Top = 11
        DataBinding.DataField = 'NEISPR_KLIENTA_REM_DAKT'
        TabOrder = 0
        Width = 433
      end
      object cxDBTextEditNEISPR_SC_REM_DAKT: TcxDBTextEdit
        Left = 224
        Top = 38
        DataBinding.DataField = 'NEISPR_SC_REM_DAKT'
        TabOrder = 1
        Width = 433
      end
      object cxDBTextEditNEISPR_BLOK_REM_DAKT: TcxDBTextEdit
        Left = 224
        Top = 65
        DataBinding.DataField = 'NEISPR_BLOK_REM_DAKT'
        TabOrder = 2
        Width = 433
      end
    end
    object cxTabSheet3: TcxTabSheet
      Caption = #1048#1079#1076#1077#1083#1080#1077
      ImageIndex = 2
      object Label21: TLabel
        Left = 16
        Top = 15
        Width = 44
        Height = 13
        Caption = #1048#1079#1076#1077#1083#1080#1077
      end
      object Label22: TLabel
        Left = 415
        Top = 15
        Width = 73
        Height = 13
        Caption = #1044#1072#1090#1072' '#1087#1088#1086#1076#1072#1078#1080
      end
      object Label23: TLabel
        Left = 19
        Top = 42
        Width = 39
        Height = 13
        Caption = #1052#1086#1076#1077#1083#1100
      end
      object Label24: TLabel
        Left = 24
        Top = 69
        Width = 17
        Height = 13
        Caption = '1'#8470
      end
      object Label25: TLabel
        Left = 23
        Top = 96
        Width = 17
        Height = 13
        Caption = '2'#8470
      end
      object Label26: TLabel
        Left = 24
        Top = 123
        Width = 17
        Height = 13
        Caption = '3'#8470
      end
      object Label27: TLabel
        Left = 16
        Top = 150
        Width = 84
        Height = 13
        Caption = #1053#1086#1084#1077#1088' '#1091#1087#1072#1082#1086#1074#1082#1080
      end
      object Label28: TLabel
        Left = 421
        Top = 130
        Width = 82
        Height = 13
        Caption = #1053#1086#1084#1077#1088' '#1090#1077#1093#1083#1080#1089#1090#1072
      end
      object cxDBTextEditISD_NAME_REM_DAKT: TcxDBTextEdit
        Left = 106
        Top = 12
        DataBinding.DataField = 'ISD_NAME_REM_DAKT'
        TabOrder = 0
        Width = 289
      end
      object cxDBTextEditISD_MODEL_REM_DAKT: TcxDBTextEdit
        Left = 106
        Top = 39
        DataBinding.DataField = 'ISD_MODEL_REM_DAKT'
        TabOrder = 1
        Width = 289
      end
      object cxDBTextEditISD_SERNUM1_REM_DAKT: TcxDBTextEdit
        Left = 106
        Top = 66
        DataBinding.DataField = 'ISD_SERNUM1_REM_DAKT'
        TabOrder = 2
        Width = 289
      end
      object cxDBTextEditISD_SERNUM2_REM_DAKT: TcxDBTextEdit
        Left = 106
        Top = 93
        DataBinding.DataField = 'ISD_SERNUM2_REM_DAKT'
        TabOrder = 3
        Width = 289
      end
      object cxDBDateEditISD_DATE_PRODAGI_REM_DAKT: TcxDBDateEdit
        Left = 511
        Top = 12
        DataBinding.DataField = 'ISD_DATE_PRODAGI_REM_DAKT'
        TabOrder = 4
        Width = 121
      end
      object cxDBTextEditISD_SERNUM3_REM_DAKT: TcxDBTextEdit
        Left = 106
        Top = 120
        DataBinding.DataField = 'ISD_SERNUM3_REM_DAKT'
        TabOrder = 5
        Width = 289
      end
      object cxDBTextEditISD_NUMUP_REM_DAKT: TcxDBTextEdit
        Left = 106
        Top = 147
        DataBinding.DataField = 'ISD_NUMUP_REM_DAKT'
        TabOrder = 6
        Width = 289
      end
      object cxDBTextEditISD_NUMTEXLIST_REM_DAKT: TcxDBTextEdit
        Left = 416
        Top = 149
        DataBinding.DataField = 'ISD_NUMTEXLIST_REM_DAKT'
        TabOrder = 7
        Width = 289
      end
    end
    object cxTabSheet4: TcxTabSheet
      Caption = #1050#1083#1080#1077#1085#1090', '#1087#1088#1086#1076#1072#1074#1077#1094
      ImageIndex = 3
      object Label29: TLabel
        Left = 401
        Top = 86
        Width = 48
        Height = 13
        Caption = #1058#1077#1083#1077#1092#1086#1085':'
      end
      object Label30: TLabel
        Left = 83
        Top = 49
        Width = 31
        Height = 13
        Caption = #1040#1076#1088#1077#1089
      end
      object Label31: TLabel
        Left = 83
        Top = 13
        Width = 36
        Height = 13
        Caption = #1050#1083#1080#1077#1085#1090
      end
      object Label32: TLabel
        Left = 401
        Top = 13
        Width = 53
        Height = 13
        Caption = #1055#1088#1086#1076#1072#1074#1077#1094':'
      end
      object Label33: TLabel
        Left = 401
        Top = 49
        Width = 34
        Height = 13
        Caption = #1040#1076#1088#1077#1089':'
      end
      object Label34: TLabel
        Left = 82
        Top = 86
        Width = 45
        Height = 13
        Caption = #1058#1077#1083#1077#1092#1086#1085
      end
      object cxDBTextEditKLIENT_NAME_REM_DAKT: TcxDBTextEdit
        Left = 83
        Top = 28
        DataBinding.DataField = 'KLIENT_NAME_REM_DAKT'
        TabOrder = 0
        Width = 289
      end
      object cxDBTextEditKLIENT_PHONE_REM_DAKT: TcxDBTextEdit
        Left = 83
        Top = 100
        DataBinding.DataField = 'KLIENT_PHONE_REM_DAKT'
        TabOrder = 1
        Width = 289
      end
      object cxDBTextEditPRODAVEC_TEL_REM_DAKT: TcxDBTextEdit
        Left = 401
        Top = 100
        DataBinding.DataField = 'PRODAVEC_TEL_REM_DAKT'
        TabOrder = 2
        Width = 289
      end
      object cxDBTextEditPRODAVEC_NAME_REM_DAKT: TcxDBTextEdit
        Left = 401
        Top = 28
        DataBinding.DataField = 'PRODAVEC_NAME_REM_DAKT'
        TabOrder = 3
        Width = 289
      end
      object cxDBTextEditRODAVEC_ADR_REM_DAKT: TcxDBTextEdit
        Left = 401
        Top = 64
        DataBinding.DataField = 'PRODAVEC_ADR_REM_DAKT'
        TabOrder = 4
        Width = 289
      end
      object cxDBTextEditKLIENT_ADR_REM_DAKT: TcxDBTextEdit
        Left = 83
        Top = 64
        DataBinding.DataField = 'KLIENT_ADR_REM_DAKT'
        TabOrder = 5
        Width = 289
      end
    end
    object cxTabSheet5: TcxTabSheet
      Caption = #1050#1086#1084#1087#1083#1077#1082#1090#1072#1094#1080#1103', '#1087#1086#1074#1088#1077#1078#1076#1077#1085#1080#1103
      ImageIndex = 4
      object Label14: TLabel
        Left = 40
        Top = 113
        Width = 74
        Height = 13
        Caption = #1050#1086#1084#1087#1083#1077#1082#1090#1072#1094#1080#1103
      end
      object Label15: TLabel
        Left = 34
        Top = 47
        Width = 63
        Height = 13
        Caption = #1053#1077#1082#1086#1084#1087#1083#1077#1082#1090
      end
      object Label16: TLabel
        Left = 23
        Top = 20
        Width = 74
        Height = 13
        Caption = #1050#1086#1084#1087#1083#1077#1082#1090#1072#1094#1080#1103
      end
      object Label17: TLabel
        Left = 16
        Top = 74
        Width = 144
        Height = 13
        Caption = #1052#1077#1093#1072#1085#1080#1095#1077#1089#1082#1080#1077' '#1087#1086#1074#1088#1077#1078#1076#1077#1085#1080#1103
      end
      object Label18: TLabel
        Left = 339
        Top = 115
        Width = 109
        Height = 13
        Caption = #1052#1077#1093#1072#1085'. '#1087#1086#1074#1088#1077#1078#1076#1077#1085#1080#1103':'
      end
      object cxDBImageComboBoxFL_FULL_KOMPL_REM_DAKT: TcxDBImageComboBox
        Left = 144
        Top = 109
        RepositoryItem = DM.cxEditRepository1ImageComboBoxAktFlKompl
        DataBinding.DataField = 'FL_FULL_KOMPL_REM_DAKT'
        Properties.Items = <>
        TabOrder = 0
        Width = 177
      end
      object cxDBTextEditKOMPL_STR_REM_DAKT: TcxDBTextEdit
        Left = 120
        Top = 17
        DataBinding.DataField = 'KOMPL_STR_REM_DAKT'
        TabOrder = 1
        Width = 433
      end
      object cxDBTextEditNEKOMPL_STR_REM_DAKT: TcxDBTextEdit
        Left = 120
        Top = 44
        DataBinding.DataField = 'NEKOMPL_STR_REM_DAKT'
        TabOrder = 2
        Width = 433
      end
      object cxDBTextEditMEXPOVR_STR_REM_DAKT: TcxDBTextEdit
        Left = 187
        Top = 71
        DataBinding.DataField = 'MEXPOVR_STR_REM_DAKT'
        TabOrder = 3
        Width = 433
      end
      object cxDBImageComboBoxFL_MEXPOVR_REM_DAKT: TcxDBImageComboBox
        Left = 460
        Top = 109
        RepositoryItem = DM.cxEditRepository1ImageComboBoxAktFlMexPovr
        DataBinding.DataField = 'FL_MEXPOVR_REM_DAKT'
        Properties.Items = <>
        TabOrder = 4
        Width = 177
      end
    end
    object cxTabSheet6: TcxTabSheet
      Caption = #1055#1088#1080#1095#1080#1085#1072
      ImageIndex = 5
      object Label11: TLabel
        Left = 18
        Top = 27
        Width = 109
        Height = 13
        Caption = #1055#1088#1080#1095#1080#1085#1072' '#1074#1099#1076#1072#1095#1080' '#1072#1082#1090#1072
      end
      object Label19: TLabel
        Left = 17
        Top = 111
        Width = 99
        Height = 13
        Caption = #1055#1088#1080#1095#1080#1085#1072' '#1089#1086#1089#1090#1086#1103#1085#1080#1103
      end
      object Label20: TLabel
        Left = 16
        Top = 139
        Width = 136
        Height = 13
        Caption = #1055#1088#1080#1095#1080#1085#1072' '#1089#1086#1089#1090#1086#1103#1085#1080#1103' '#1076#1088#1091#1075#1072#1103
      end
      object Label13: TLabel
        Left = 3
        Top = 76
        Width = 120
        Height = 13
        Caption = #1055#1088#1080#1095#1080#1085#1072' '#1074#1099#1076#1072#1095#1080' '#1076#1088#1091#1075#1072#1103
      end
      object Label35: TLabel
        Left = 331
        Top = 27
        Width = 93
        Height = 13
        Caption = #1052#1077#1089#1090#1086#1085#1072#1093#1086#1078#1076#1077#1085#1080#1077
      end
      object cxDBImageComboBoxFL_PRICHINA_ACTA_REM_DAKT: TcxDBImageComboBox
        Left = 133
        Top = 27
        RepositoryItem = DM.cxEditRepository1ImageComboBoxAktPrichinaAkta
        DataBinding.DataField = 'FL_PRICHINA_ACTA_REM_DAKT'
        Properties.Items = <>
        TabOrder = 0
        Width = 177
      end
      object cxDBTextEditPRICHINA_SOST_DR_REM_DAKT: TcxDBTextEdit
        Left = 174
        Top = 136
        DataBinding.DataField = 'PRICHINA_SOST_DR_REM_DAKT'
        TabOrder = 1
        Width = 433
      end
      object cxDBTextEditPRICHINA_ACTA_DR_STR_REM_DAKT: TcxDBTextEdit
        Left = 133
        Top = 68
        DataBinding.DataField = 'PRICHINA_ACTA_DR_STR_REM_DAKT'
        TabOrder = 2
        Width = 474
      end
      object cxDBImageComboBoxFL_PRICHINA_SOST_REM_DAKT: TcxDBImageComboBox
        Left = 133
        Top = 109
        RepositoryItem = DM.cxEditRepository1ImageComboBoxAktPrichinaSost
        DataBinding.DataField = 'FL_PRICHINA_SOST_REM_DAKT'
        Properties.Items = <>
        TabOrder = 3
        Width = 177
      end
      object cxDBImageComboBoxFL_MESTONAX_REM_DAKT: TcxDBImageComboBox
        Left = 430
        Top = 27
        RepositoryItem = DM.cxEditRepository1ImageComboBoxAktFlMestonax
        DataBinding.DataField = 'FL_MESTONAX_REM_DAKT'
        Properties.Items = <>
        TabOrder = 4
        Width = 177
      end
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 321
    Width = 711
    Height = 148
    Align = alClient
    TabOrder = 5
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = REM_DMDocRemont.DataSourceDocT
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          FieldName = 'SUM_REM_DREMONTT'
        end
        item
          Kind = skSum
          FieldName = 'SUMMEX_REM_DREMONTT'
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      Styles.Footer = DM.cxStyleHeaderTable
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        PropertiesClassName = 'TcxLabelProperties'
        Width = 42
      end
      object cxGrid1DBTableView1INDEX_REM_DAKTT: TcxGridDBColumn
        Caption = #1048#1085#1076#1077#1082#1089
        DataBinding.FieldName = 'INDEX_REM_DAKTT'
        Width = 66
      end
      object cxGrid1DBTableView1TEXT_REM_DAKTT: TcxGridDBColumn
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        DataBinding.FieldName = 'TEXT_REM_DAKTT'
        PropertiesClassName = 'TcxMemoProperties'
        Width = 767
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
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 448
    Top = 40
  end
end
