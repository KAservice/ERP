object REM_FormaElementaSprKKT: TREM_FormaElementaSprKKT
  Left = 249
  Top = 132
  Caption = #1069#1083#1077#1084#1077#1085#1090' '#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082#1072' "'#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077'"'
  ClientHeight = 665
  ClientWidth = 692
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
  OnClick = ActionCloseElementExecute
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object Panel2: TPanel
    Left = 0
    Top = 614
    Width = 692
    Height = 51
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object cxButtonSave: TcxButton
      Left = 352
      Top = 10
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSaveElement
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 451
      Top = 8
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 1
    end
    object cxButtonClose: TcxButton
      Left = 551
      Top = 10
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionCloseElement
      Cancel = True
      TabOrder = 2
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 692
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 41
    Width = 692
    Height = 573
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 2
    ClientRectBottom = 573
    ClientRectRight = 692
    ClientRectTop = 27
    object cxTabSheet1: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 0
      object Label2: TLabel
        Left = 71
        Top = 119
        Width = 102
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object Label1: TLabel
        Left = 20
        Top = 437
        Width = 106
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086':'
      end
      object NamecxDBTextEdit: TcxDBTextEdit
        Left = 176
        Top = 116
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_REM_SKKT'
        DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
        Properties.ValidateOnEnter = True
        TabOrder = 0
        Width = 496
      end
      object cxLabel1: TcxLabel
        Left = 340
        Top = 54
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088':'
      end
      object cxLabel3: TcxLabel
        Left = 398
        Top = 17
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1052#1086#1076#1077#1083#1100':'
      end
      object NameModelcxDBButtonEdit: TcxDBButtonEdit
        Left = 462
        Top = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_REM_SMODEL'
        DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = NameModelcxDBButtonEditPropertiesButtonClick
        TabOrder = 3
        Width = 210
      end
      object SerNumbercxDBTextEdit: TcxDBTextEdit
        Left = 462
        Top = 49
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'SERNUM_REM_SKKT'
        DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
        TabOrder = 4
        Width = 210
      end
      object NameKlientcxDBButtonEdit: TcxDBButtonEdit
        Left = 363
        Top = 82
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'OWNER_NAME'
        DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
        TabOrder = 5
        Width = 309
      end
      object cxLabel2: TcxLabel
        Left = 281
        Top = 87
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1083#1080#1077#1085#1090':'
      end
      object cxGroupBox1: TcxGroupBox
        Left = 20
        Top = 149
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1042#1050
        TabOrder = 7
        Height = 129
        Width = 336
        object SvkGRcxDBTextEdit: TcxDBTextEdit
          Left = 165
          Top = 30
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'CBKGR_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 0
          Width = 149
        end
        object SvkSOcxDBTextEdit: TcxDBTextEdit
          Left = 165
          Top = 79
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'CBKCO_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 1
          Width = 149
        end
        object cxLabel4: TcxLabel
          Left = 69
          Top = 30
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1043#1086#1089'. '#1088#1077#1077#1089#1090#1088':'
        end
        object cxLabel5: TcxLabel
          Left = 21
          Top = 79
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1057#1077#1088#1074'. '#1086#1073#1089#1083#1091#1078#1080#1074#1072#1085#1080#1077':'
        end
      end
      object cxGroupBox2: TcxGroupBox
        Left = 20
        Top = 297
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1086#1075#1086#1074#1086#1088
        TabOrder = 8
        Height = 129
        Width = 336
        object NumContractcxDBTextEdit: TcxDBTextEdit
          Left = 167
          Top = 20
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'NUMCONTRACT_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 0
          Width = 149
        end
        object DateContractcxDBDateEdit: TcxDBDateEdit
          Left = 167
          Top = 53
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'DATECONTRACT_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 1
          Width = 149
        end
        object SumContractcxDBCalcEdit: TcxDBCalcEdit
          Left = 167
          Top = 86
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'SUMCONTRACT_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 2
          Width = 149
        end
        object cxLabel6: TcxLabel
          Left = 48
          Top = 25
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1053#1086#1084#1077#1088' '#1076#1086#1075#1086#1074#1086#1088#1072':'
        end
        object cxLabel7: TcxLabel
          Left = 110
          Top = 86
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1057#1091#1084#1084#1072':'
        end
        object cxLabel8: TcxLabel
          Left = 58
          Top = 58
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1044#1072#1090#1072' '#1076#1086#1075#1086#1074#1086#1088#1072':'
        end
      end
      object cxGroupBox3: TcxGroupBox
        Left = 378
        Top = 297
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1045#1050#1051#1047
        TabOrder = 9
        Height = 129
        Width = 294
        object EklzSerNumcxDBTextEdit: TcxDBTextEdit
          Left = 128
          Top = 20
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'EKLZ_SERNUM_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 0
          Width = 149
        end
        object EklzRegNumcxDBTextEdit: TcxDBTextEdit
          Left = 128
          Top = 53
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'EKLZ_REGNUM_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 1
          Width = 149
        end
        object EklzActcxDBDateEdit: TcxDBDateEdit
          Left = 128
          Top = 86
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'EKLZ_ACT_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 2
          Width = 149
        end
        object cxLabel9: TcxLabel
          Left = 20
          Top = 21
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1047#1072#1074#1086#1076#1082#1089#1082#1086#1081' '#8470':'
        end
        object cxLabel10: TcxLabel
          Left = 4
          Top = 54
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1056#1077#1075#1080#1089#1090#1088#1072#1094#1080#1086#1085'.  '#8470
        end
        object cxLabel11: TcxLabel
          Left = 11
          Top = 86
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1044#1072#1090#1072' '#1072#1082#1090#1080#1074#1072#1094#1080#1080':'
        end
      end
      object RegNumcxDBTextEdit: TcxDBTextEdit
        Left = 523
        Top = 158
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'REGNUM_REM_SKKT'
        DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
        TabOrder = 10
        Width = 149
      end
      object ReleasecxDBDateEdit: TcxDBDateEdit
        Left = 523
        Top = 207
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'RELEASE_REM_SKKT'
        DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
        TabOrder = 11
        Width = 149
      end
      object VvodcxDBDateEdit: TcxDBDateEdit
        Left = 523
        Top = 252
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'VVOD_REM_SKKT'
        DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
        TabOrder = 12
        Width = 149
      end
      object cxLabel12: TcxLabel
        Left = 410
        Top = 159
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1056#1077#1075#1080#1089#1090#1088'. '#1085#1086#1084#1077#1088':'
      end
      object cxLabel13: TcxLabel
        Left = 418
        Top = 208
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1072#1090#1072' '#1074#1099#1087#1091#1089#1082#1072':'
      end
      object cxLabel14: TcxLabel
        Left = 373
        Top = 254
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1042#1074#1086#1076' '#1074' '#1101#1082#1089#1087#1083#1091#1072#1090#1072#1094#1080#1102':'
      end
      object PrimcxDBMemo: TcxDBMemo
        Left = 20
        Top = 453
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'PRIM_REM_SKKT'
        DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
        TabOrder = 16
        Height = 64
        Width = 652
      end
    end
    object cxTabSheet2: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1072#1089#1087#1086#1088#1090
      ImageIndex = 1
      object PasNumVercxDBTextEdit: TcxDBTextEdit
        Left = 148
        Top = 26
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'PAS_NUMVER_REM_SKKT'
        DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
        TabOrder = 0
        Width = 77
      end
      object PasNumPascxDBTextEdit: TcxDBTextEdit
        Left = 473
        Top = 26
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'PAS_NUMPAS_REM_SKKT'
        DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
        TabOrder = 1
        Width = 149
      end
      object cxGroupBox4: TcxGroupBox
        Left = 30
        Top = 73
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1077#1095#1072#1090#1072#1102#1097#1077#1077' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1086
        TabOrder = 2
        Height = 56
        Width = 614
        object PasNumPUcxDBSpinEdit: TcxDBSpinEdit
          Left = 492
          Top = 20
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'PAS_NUMPU_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 0
          Width = 100
        end
        object cxLabel15: TcxLabel
          Left = 411
          Top = 20
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1053#1086#1084#1077#1088' '#1055#1059':'
        end
      end
      object cxGroupBox5: TcxGroupBox
        Left = 30
        Top = 137
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1080#1089#1090#1077#1084#1085#1072#1103' '#1087#1083#1072#1090#1072
        TabOrder = 3
        Height = 81
        Width = 614
        object PasNumSPcxDBSpinEdit: TcxDBSpinEdit
          Left = 197
          Top = 30
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'PAS_NUMSP_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 0
          Width = 100
        end
        object PasNumSPPOcxDBSpinEdit: TcxDBSpinEdit
          Left = 492
          Top = 30
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'PAS_NUMSPPO_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 1
          Width = 100
        end
        object cxLabel16: TcxLabel
          Left = 79
          Top = 30
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1053#1086#1084#1077#1088' '#1057#1055':'
        end
        object cxLabel17: TcxLabel
          Left = 394
          Top = 39
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1053#1086#1084#1077#1088' '#1055#1054' '#1057#1055':'
        end
      end
      object cxGroupBox6: TcxGroupBox
        Left = 30
        Top = 225
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1060#1080#1089#1082#1072#1083#1100#1085#1072#1103' '#1087#1072#1084#1103#1090#1100
        TabOrder = 4
        Height = 72
        Width = 614
        object PasNumFPcxDBSpinEdit: TcxDBSpinEdit
          Left = 197
          Top = 30
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'PAS_NUMFP_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 0
          Width = 100
        end
        object PasNumFPPOcxDBSpinEdit: TcxDBSpinEdit
          Left = 492
          Top = 30
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'PAS_NUMFPPO_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 1
          Width = 100
        end
        object cxLabel18: TcxLabel
          Left = 118
          Top = 30
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1053#1086#1084#1077#1088' '#1060#1055':'
        end
        object cxLabel19: TcxLabel
          Left = 384
          Top = 30
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1053#1086#1084#1077#1088' '#1055#1054' '#1060#1055':'
        end
      end
      object PasPrimcxDBTextEdit: TcxDBTextEdit
        Left = 437
        Top = 511
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'PAS_PRIM_REM_SKKT'
        DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
        TabOrder = 5
        Width = 207
      end
      object PasDorcxDBTextEdit: TcxDBTextEdit
        Left = 437
        Top = 478
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'PAS_DOR_REM_SKKT'
        DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
        TabOrder = 6
        Width = 207
      end
      object cxGroupBox7: TcxGroupBox
        Left = 30
        Top = 304
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086#1077' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077
        TabOrder = 7
        Height = 70
        Width = 614
        object PasNumDocxDBSpinEdit: TcxDBSpinEdit
          Left = 197
          Top = 30
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'PAS_NUMDO_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 0
          Width = 100
        end
        object PasNumDoPocxDBSpinEdit: TcxDBSpinEdit
          Left = 492
          Top = 30
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'PAS_NUMDOPO_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 1
          Width = 100
        end
        object cxLabel21: TcxLabel
          Left = 98
          Top = 30
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1053#1086#1084#1077#1088' '#1044#1054':'
        end
        object cxLabel22: TcxLabel
          Left = 386
          Top = 30
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1053#1086#1084#1077#1088' '#1055#1054' '#1044#1054':'
        end
      end
      object cxGroupBox8: TcxGroupBox
        Left = 30
        Top = 382
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1072#1082#1077#1090' '#1087#1088#1080#1082#1083#1072#1076#1085#1099#1093' '#1087#1088#1086#1075#1088#1072#1084#1084
        TabOrder = 8
        Height = 71
        Width = 614
        object PasPppcxDBSpinEdit: TcxDBSpinEdit
          Left = 492
          Top = 26
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          DataBinding.DataField = 'PAS_NUMPPP_REM_SKKT'
          DataBinding.DataSource = REM_DMSprKKT.DataSourceElement
          TabOrder = 0
          Width = 100
        end
        object cxLabel20: TcxLabel
          Left = 401
          Top = 30
          Margins.Left = 4
          Margins.Top = 4
          Margins.Right = 4
          Margins.Bottom = 4
          Caption = #1053#1086#1084#1077#1088' '#1055#1055#1055':'
        end
      end
      object cxLabel23: TcxLabel
        Left = 188
        Top = 482
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1074#1077#1076#1077#1085#1080#1103' '#1086' '#1087#1088#1086#1074#1077#1076#1077#1085#1085#1099#1093' '#1076#1086#1088#1072#1073#1086#1090#1082#1072#1093':'
      end
      object cxLabel24: TcxLabel
        Left = 343
        Top = 511
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
      end
      object cxLabel25: TcxLabel
        Left = 353
        Top = 27
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1086#1084#1077#1088' '#1087#1072#1089#1087#1086#1088#1090#1072':'
      end
      object cxLabel26: TcxLabel
        Left = 42
        Top = 27
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1086#1084#1077#1088' '#1074#1077#1088#1089#1080#1080':'
      end
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 216
    Top = 97
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionSaveElement: TAction
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      ImageIndex = 55
      OnExecute = ActionSaveElementExecute
    end
    object ActionCloseElement: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      ShortCut = 16472
      OnExecute = ActionCloseElementExecute
    end
    object ActionOK: TAction
      Caption = #1054#1050
      ImageIndex = 54
      OnExecute = ActionOKExecute
    end
  end
end
