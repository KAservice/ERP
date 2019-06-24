object REM_FormaElementaSprHardware: TREM_FormaElementaSprHardware
  Left = 249
  Top = 132
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077'"'
  ClientHeight = 512
  ClientWidth = 831
  Color = clBtnFace
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
  OnDeactivate = FormDeactivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 15
    Top = 249
    Width = 79
    Height = 13
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
  end
  object Panel2: TPanel
    Left = 0
    Top = 471
    Width = 831
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 21
    object cxButtonSave: TcxButton
      Left = 286
      Top = 8
      Width = 75
      Height = 25
      Action = ActionSaveElement
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 367
      Top = 8
      Width = 75
      Height = 25
      Action = ActionOK
      TabOrder = 1
    end
    object cxButtonClose: TcxButton
      Left = 448
      Top = 8
      Width = 75
      Height = 25
      Action = ActionCloseElement
      Cancel = True
      TabOrder = 2
    end
    object cxButtonIspZapchasti: TcxButton
      Left = 104
      Top = 8
      Width = 165
      Height = 25
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1048#1089#1087#1086#1083#1100#1079#1086#1074#1072#1085#1085#1099#1077' '#1079#1072#1087#1095#1072#1089#1090#1080
      TabOrder = 3
      OnClick = cxButtonIspZapchastiClick
    end
    object cxButtonOpenZ: TcxButton
      Left = 656
      Top = 8
      Width = 100
      Height = 25
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1079#1072#1103#1074#1082#1091
      TabOrder = 4
      OnClick = cxButtonOpenZClick
    end
  end
  object NamecxDBTextEdit: TcxDBTextEdit
    Left = 105
    Top = 243
    DataBinding.DataField = 'NAME_REM_SHARDWARE'
    Properties.ValidateOnEnter = True
    TabOrder = 8
    Width = 403
  end
  object OwnercxDBButtonEdit: TcxDBButtonEdit
    Left = 105
    Top = 292
    DataBinding.DataField = 'OWNER_NAME'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.OnButtonClick = OwnercxDBButtonEditPropertiesButtonClick
    TabOrder = 9
    Width = 403
  end
  object SuppliercxDBButtonEdit: TcxDBButtonEdit
    Left = 104
    Top = 336
    DataBinding.DataField = 'SUPPLIER_NAME'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.OnButtonClick = SuppliercxDBButtonEditPropertiesButtonClick
    TabOrder = 11
    Width = 404
  end
  object cxLabel12: TcxLabel
    Left = 28
    Top = 292
    Caption = #1042#1083#1072#1076#1077#1083#1077#1094':'
  end
  object cxLabel13: TcxLabel
    Left = 23
    Top = 340
    Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082':'
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 831
    Height = 21
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 24
    object CodecxDBTextEdit: TcxDBTextEdit
      Left = 209
      Top = 2
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'CODE_REM_SHARDWARE'
      TabOrder = 0
      Width = 98
    end
    object IDcxDBLabel: TcxDBLabel
      Left = 8
      Top = 4
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'ID_REM_SHARDWARE'
      Height = 17
      Width = 155
    end
    object cxDBTextEditARTIKUL_REM_SHARDWARE: TcxDBTextEdit
      Left = 370
      Top = 1
      DataBinding.DataField = 'ARTIKUL_REM_SHARDWARE'
      TabOrder = 2
      Width = 196
    end
    object cxLabel36: TcxLabel
      Left = 313
      Top = 4
      Caption = #1040#1088#1090#1080#1082#1091#1083':'
    end
    object cxLabel37: TcxLabel
      Left = 178
      Top = 4
      Caption = #1050#1086#1076':'
    end
  end
  object cxLabel1: TcxLabel
    Left = 130
    Top = 80
    Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088':'
  end
  object cxLabel2: TcxLabel
    Left = 1
    Top = 318
    Caption = #1042#1083#1072#1076#1077#1083#1077#1094' ('#1089#1090#1088#1086#1082#1072'):'
  end
  object cxLabel3: TcxLabel
    Left = 130
    Top = 54
    Caption = #1052#1086#1076#1077#1083#1100':'
  end
  object cxLabel4: TcxLabel
    Left = 626
    Top = 308
    Caption = #1043#1072#1088#1072#1085#1090#1080#1103' '#1076#1086':'
  end
  object cxLabel5: TcxLabel
    Left = 598
    Top = 331
    Caption = #1044#1072#1090#1072' '#1087#1088#1086#1076#1072#1078#1080':'
  end
  object cxLabel6: TcxLabel
    Left = 527
    Top = 356
    Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1087#1086#1089#1090#1072#1074#1082#1080':'
  end
  object cxLabel7: TcxLabel
    Left = 530
    Top = 382
    Caption = #1044#1086#1082#1091#1084#1077#1085#1090' '#1087#1088#1086#1076#1072#1078#1080':'
  end
  object NameModelcxDBButtonEdit: TcxDBButtonEdit
    Left = 183
    Top = 54
    DataBinding.DataField = 'NAME_REM_SMODEL'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.OnButtonClick = NameModelcxDBButtonEditPropertiesButtonClick
    TabOrder = 0
    Width = 324
  end
  object WarrantycxDBDateEdit: TcxDBDateEdit
    Left = 702
    Top = 308
    DataBinding.DataField = 'WARRANTY_REM_SHARDWARE'
    TabOrder = 14
    Width = 119
  end
  object SalecxDBDateEdit: TcxDBDateEdit
    Left = 700
    Top = 331
    DataBinding.DataField = 'SALE_REM_SHARDWARE'
    TabOrder = 12
    Width = 121
  end
  object SerNumbercxDBTextEdit: TcxDBTextEdit
    Left = 241
    Top = 80
    DataBinding.DataField = 'SERNUM_REM_SHARDWARE'
    TabOrder = 1
    Width = 266
  end
  object NameVladcxDBTextEdit: TcxDBTextEdit
    Left = 105
    Top = 314
    DataBinding.DataField = 'NAMEVLAD_REM_SHARDWARE'
    TabOrder = 10
    Width = 403
  end
  object DocPostcxDBButtonEdit: TcxDBButtonEdit
    Left = 643
    Top = 355
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataBinding.DataField = 'TDOC_DOCPOST'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = DocPostcxDBButtonEditPropertiesButtonClick
    TabOrder = 15
    Width = 178
  end
  object DocSalecxDBButtonEdit: TcxDBButtonEdit
    Left = 642
    Top = 379
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataBinding.DataField = 'TDOC_DOCSALE'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ReadOnly = True
    Properties.OnButtonClick = DocSalecxDBButtonEditPropertiesButtonClick
    TabOrder = 16
    Width = 179
  end
  object SerNum2cxDBTextEdit: TcxDBTextEdit
    Left = 241
    Top = 100
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataBinding.DataField = 'SERNUM2_REM_SHARDWARE'
    TabOrder = 2
    Width = 267
  end
  object SerNumStrcxDBTextEdit: TcxDBTextEdit
    Left = 19
    Top = 218
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataBinding.DataField = 'SERNUM_STR_REM_SHARDWARE'
    TabOrder = 7
    Width = 489
  end
  object cxLabel8: TcxLabel
    Left = 124
    Top = 101
    Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088' 2:'
  end
  object cxLabel9: TcxLabel
    Left = 19
    Top = 202
    Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088' '#1089#1090#1088#1086#1082#1072':'
  end
  object PrichinacxDBTextEdit: TcxDBTextEdit
    Left = 124
    Top = 371
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataBinding.DataField = 'PRICHINA_REM_SHARDWARE'
    TabOrder = 20
    Width = 383
  end
  object PrimcxDBTextEdit: TcxDBTextEdit
    Left = 122
    Top = 437
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataBinding.DataField = 'PRIM_REM_SHARDWARE'
    TabOrder = 17
    Width = 383
  end
  object NecondcxDBCheckBox: TcxDBCheckBox
    Left = 7
    Top = 101
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1053#1077#1082#1086#1085#1076#1080#1094#1080#1103
    DataBinding.DataField = 'FL_NECOND_REM_SHARDWARE'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 18
    Width = 98
  end
  object SrokWarrantycxDBCalcEdit: TcxDBCalcEdit
    Left = 703
    Top = 285
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataBinding.DataField = 'SROKWARRANTY_REM_SHARDWARE'
    TabOrder = 13
    Width = 118
  end
  object PricecxDBCalcEdit: TcxDBCalcEdit
    Left = 409
    Top = 401
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataBinding.DataField = 'PRICE_REM_SHARDWARE'
    TabOrder = 19
    Width = 98
  end
  object cxLabel10: TcxLabel
    Left = 594
    Top = 281
    Caption = #1057#1088#1086#1082' '#1075#1072#1088#1072#1085#1090#1080#1080':'
  end
  object cxLabel11: TcxLabel
    Left = 1
    Top = 372
    Caption = #1055#1088#1080#1095#1080#1085#1072' '#1085#1077#1082#1086#1085#1076#1080#1094#1080#1080':'
  end
  object cxLabel14: TcxLabel
    Left = 371
    Top = 401
    Caption = #1062#1077#1085#1072':'
  end
  object cxLabel15: TcxLabel
    Left = 25
    Top = 438
    Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
  end
  object FlRemontcxDBCheckBox: TcxDBCheckBox
    Left = 7
    Top = 125
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1073#1099#1083' '#1074' '#1088#1077#1084#1086#1085#1090#1077
    DataBinding.DataField = 'FL_REMONT_REM_SHARDWARE'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 38
    Width = 98
  end
  object FlFictRemontcxDBCheckBox: TcxDBCheckBox
    Left = 7
    Top = 150
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1092#1080#1082#1090#1080#1074#1085#1099#1081' '#1088#1077#1084#1086#1085#1090
    DataBinding.DataField = 'FL_FICT_REMONT_REM_SHARDWARE'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 39
    Width = 143
  end
  object TypeElementacxDBImageComboBox: TcxDBImageComboBox
    Left = 241
    Top = 26
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeElementaSprHW
    DataBinding.DataField = 'TYPE_ELEMENTA_REM_SHARDWARE'
    Properties.Items = <>
    TabOrder = 40
    Width = 266
  end
  object flActcxDBCheckBox: TcxDBCheckBox
    Left = 7
    Top = 54
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1072#1082#1090#1080#1074#1085#1086
    DataBinding.DataField = 'FL_ACT_REM_SHARDWARE'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 41
    Width = 79
  end
  object flUtilizcxDBCheckBox: TcxDBCheckBox
    Left = 7
    Top = 76
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1091#1090#1080#1083#1080#1079#1080#1088#1086#1074#1072#1085#1086
    DataBinding.DataField = 'FL_UTILIZ_REM_SHARDWARE'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 42
    Width = 108
  end
  object ProducercxDBButtonEdit: TcxDBButtonEdit
    Left = 618
    Top = 85
    DataBinding.DataField = 'NAME_SPRODUCER'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.OnButtonClick = ProducercxDBButtonEditPropertiesButtonClick
    TabOrder = 43
    Width = 203
  end
  object BrandcxDBButtonEdit: TcxDBButtonEdit
    Left = 618
    Top = 105
    DataBinding.DataField = 'NAME_SBRAND'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.OnButtonClick = BrandcxDBButtonEditPropertiesButtonClick
    TabOrder = 44
    Width = 203
  end
  object ZayavkacxDBButtonEdit: TcxDBButtonEdit
    Left = 643
    Top = 405
    DataBinding.DataField = 'NAME_REM_Z'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.OnButtonClick = ZayavkacxDBButtonEditPropertiesButtonClick
    TabOrder = 45
    Width = 178
  end
  object ModelProducercxDBButtonEdit: TcxDBButtonEdit
    Left = 618
    Top = 124
    DataBinding.DataField = 'NAME_REM_SPRMODEL'
    Properties.Buttons = <
      item
        Default = True
        Kind = bkEllipsis
      end>
    Properties.ClickKey = 13
    Properties.OnButtonClick = ModelProducercxDBButtonEditPropertiesButtonClick
    TabOrder = 46
    Width = 203
  end
  object PostupilocxDBDateEdit: TcxDBDateEdit
    Left = 640
    Top = 27
    DataBinding.DataField = 'POS_POST_REM_SHARDWARE'
    Properties.Kind = ckDateTime
    TabOrder = 47
    Width = 181
  end
  object UtilizirovanocxDBDateEdit: TcxDBDateEdit
    Left = 640
    Top = 66
    DataBinding.DataField = 'POS_UTILIZ_REM_SHARDWARE'
    Properties.Kind = ckDateTime
    TabOrder = 48
    Width = 181
  end
  object HranitDocxDBDateEdit: TcxDBDateEdit
    Left = 640
    Top = 46
    DataBinding.DataField = 'POS_HRAN_DO_REM_SHARDWARE'
    Properties.Kind = ckDateTime
    TabOrder = 49
    Width = 181
  end
  object ModelZcxDBLabel: TcxDBLabel
    Left = 522
    Top = 427
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataBinding.DataField = 'MODEL_REM_Z'
    Height = 17
    Width = 98
  end
  object PosZcxDBLabel: TcxDBLabel
    Left = 683
    Top = 450
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataBinding.DataField = 'POS_REM_Z'
    Height = 17
    Width = 99
  end
  object PrefikscxDBLabel: TcxDBLabel
    Left = 522
    Top = 450
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataBinding.DataField = 'PREFIKS_NUM_REM_Z'
    Height = 17
    Width = 39
  end
  object NumZcxDBLabel: TcxDBLabel
    Left = 580
    Top = 450
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataBinding.DataField = 'NUM_REM_Z'
    Height = 17
    Width = 98
  end
  object SerNumcxDBLabel: TcxDBLabel
    Left = 522
    Top = 438
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    DataBinding.DataField = 'SERNUM_REM_Z'
    Height = 17
    Width = 234
  end
  object cxLabel16: TcxLabel
    Left = 126
    Top = 27
    Caption = #1058#1080#1087' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1072':'
  end
  object cxLabel17: TcxLabel
    Left = 572
    Top = 106
    Caption = #1041#1088#1077#1085#1076':'
  end
  object cxLabel18: TcxLabel
    Left = 514
    Top = 119
    AutoSize = False
    Caption = #1052#1086#1076#1077#1083#1100' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103':'
    Properties.WordWrap = True
    Height = 33
    Width = 97
  end
  object cxLabel19: TcxLabel
    Left = 521
    Top = 86
    Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100':'
  end
  object cxLabel20: TcxLabel
    Left = 519
    Top = 405
    Caption = #1048#1079' '#1079#1072#1103#1074#1082#1080' '#1085#1072' '#1088#1077#1084#1086#1085#1090':'
  end
  object cxLabel21: TcxLabel
    Left = 558
    Top = 28
    Caption = #1055#1086#1089#1090#1091#1087#1080#1083#1086':'
  end
  object cxLabel22: TcxLabel
    Left = 544
    Top = 67
    Caption = #1059#1090#1080#1083#1080#1079#1080#1088#1086#1074#1072#1085#1086':'
  end
  object cxLabel23: TcxLabel
    Left = 569
    Top = 47
    Caption = #1061#1088#1072#1085#1080#1090#1100' '#1076#1086':'
  end
  object cxLabel24: TcxLabel
    Left = 122
    Top = 119
    Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088' 3:'
  end
  object cxDBTextEditSERNUM3_REM_SHARDWARE: TcxDBTextEdit
    Left = 241
    Top = 119
    DataBinding.DataField = 'SERNUM3_REM_SHARDWARE'
    TabOrder = 3
    Width = 266
  end
  object cxLabel25: TcxLabel
    Left = 122
    Top = 141
    Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088' 4:'
  end
  object cxDBTextEditSERNUM4_REM_SHARDWARE: TcxDBTextEdit
    Left = 241
    Top = 140
    DataBinding.DataField = 'SERNUM4_REM_SHARDWARE'
    TabOrder = 4
    Width = 266
  end
  object cxLabel26: TcxLabel
    Left = 163
    Top = 160
    Caption = #1053#1086#1084#1077#1088' '#1072#1082#1073':'
  end
  object cxDBTextEditNUMBAT_REM_SHARDWARE: TcxDBTextEdit
    Left = 241
    Top = 159
    DataBinding.DataField = 'NUMBAT_REM_SHARDWARE'
    TabOrder = 5
    Width = 266
  end
  object cxLabel27: TcxLabel
    Left = 169
    Top = 180
    Caption = #1053#1086#1084#1077#1088' '#1043#1058':'
  end
  object cxDBTextEditNUMGARTALON_REM_SHARDWARE: TcxDBTextEdit
    Left = 241
    Top = 179
    DataBinding.DataField = 'NUMGARTALON_REM_SHARDWARE'
    TabOrder = 6
    Width = 266
  end
  object cxLabel28: TcxLabel
    Left = 558
    Top = 145
    Caption = 'SW code:'
  end
  object cxDBTextEditSWCODE_REM_SHARDWARE: TcxDBTextEdit
    Left = 626
    Top = 145
    DataBinding.DataField = 'SWCODE_REM_SHARDWARE'
    TabOrder = 68
    Width = 195
  end
  object cxLabel29: TcxLabel
    Left = 557
    Top = 168
    Caption = 'HW code:'
  end
  object cxDBTextEditHWCODE_REM_SHARDWARE: TcxDBTextEdit
    Left = 625
    Top = 164
    DataBinding.DataField = 'HWCODE_REM_SHARDWARE'
    TabOrder = 70
    Width = 196
  end
  object cxLabel30: TcxLabel
    Left = 548
    Top = 184
    Caption = #1042#1077#1088#1089#1080#1103' '#1055#1054':'
  end
  object cxDBTextEditVERPO_REM_SHARDWARE: TcxDBTextEdit
    Left = 625
    Top = 184
    DataBinding.DataField = 'VERPO_REM_SHARDWARE'
    TabOrder = 72
    Width = 196
  end
  object cxLabel31: TcxLabel
    Left = 539
    Top = 204
    Caption = #1055#1072#1088#1090'. '#1085#1086#1084#1077#1088':'
  end
  object cxDBTextEditPARTNUM_REM_SHARDWARE: TcxDBTextEdit
    Left = 626
    Top = 203
    DataBinding.DataField = 'PARTNUM_REM_SHARDWARE'
    TabOrder = 74
    Width = 195
  end
  object cxLabel32: TcxLabel
    Left = 579
    Top = 223
    Caption = 'MTM:'
  end
  object cxDBTextEditMTM_REM_SHARDWARE: TcxDBTextEdit
    Left = 625
    Top = 223
    DataBinding.DataField = 'MTM_REM_SHARDWARE'
    TabOrder = 76
    Width = 196
  end
  object cxLabel33: TcxLabel
    Left = 581
    Top = 238
    Caption = 'FRU:'
  end
  object cxDBTextEditFRU_REM_SHARDWARE: TcxDBTextEdit
    Left = 625
    Top = 243
    DataBinding.DataField = 'FRU_REM_SHARDWARE'
    TabOrder = 78
    Width = 196
  end
  object cxLabel34: TcxLabel
    Left = 8
    Top = 269
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' ('#1072#1085#1075#1083'.):'
  end
  object cxDBTextEditNAME_ENG_REM_SHARDWARE: TcxDBTextEdit
    Left = 144
    Top = 269
    DataBinding.DataField = 'NAME_ENG_REM_SHARDWARE'
    TabOrder = 80
    Width = 364
  end
  object cxDBTextEditCRU_REM_SHARDWARE: TcxDBTextEdit
    Left = 626
    Top = 262
    DataBinding.DataField = 'CRU_REM_SHARDWARE'
    TabOrder = 81
    Width = 195
  end
  object cxLabel35: TcxLabel
    Left = 589
    Top = 261
    Caption = 'CRU:'
  end
  object cxDBCheckBoxFL_OTCH_PROIZV_REM_SHARDWARE: TcxDBCheckBox
    Left = 7
    Top = 29
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1054#1090#1095#1080#1090#1072#1085#1086' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1102
    DataBinding.DataField = 'FL_OTCH_PROIZV_REM_SHARDWARE'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 83
    Width = 143
  end
  object cxDBCheckBoxFL_NO_RAZBOR_REM_SHARDWARE: TcxDBCheckBox
    Left = 7
    Top = 175
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Caption = #1085#1077' '#1088#1072#1079#1073#1080#1088#1072#1090#1100
    DataBinding.DataField = 'FL_NO_RAZBOR_REM_SHARDWARE'
    Properties.ValueChecked = 1
    Properties.ValueUnchecked = 0
    TabOrder = 84
    Width = 143
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 104
    Top = 1
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
    end
    object ActionSaveElement: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveElementExecute
    end
    object ActionCloseElement: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseElementExecute
    end
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
  end
end
