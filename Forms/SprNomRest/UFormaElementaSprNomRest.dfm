object FormaElementaSprNomRest: TFormaElementaSprNomRest
  Left = 333
  Top = 258
  Caption = #1044#1086#1087'. '#1093#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1080' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
  ClientHeight = 591
  ClientWidth = 676
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
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 676
    Height = 41
    Align = alTop
    TabOrder = 0
    object LabelNom: TLabel
      Left = 23
      Top = 2
      Width = 96
      Height = 26
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'LabelNom'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 528
    Width = 676
    Height = 63
    Align = alBottom
    TabOrder = 1
    object cxButtonSost: TcxButton
      Left = 168
      Top = 16
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1057#1086#1089#1090#1072#1074
      TabOrder = 0
      OnClick = cxButtonSostClick
    end
    object cxButtonPrint: TcxButton
      Left = 267
      Top = 16
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 1
    end
    object cxButtonSave: TcxButton
      Left = 367
      Top = 16
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 2
    end
    object cxButtonOK: TcxButton
      Left = 467
      Top = 16
      Width = 92
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 3
    end
    object cxButtonClose: TcxButton
      Left = 566
      Top = 16
      Width = 93
      Height = 31
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 4
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 41
    Width = 676
    Height = 487
    ActivePage = cxTabSheet2
    Align = alClient
    MultiLine = True
    TabOrder = 2
    ClientRectBottom = 487
    ClientRectRight = 676
    ClientRectTop = 27
    object cxTabSheet2: TcxTabSheet
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 1
      object Label5: TLabel
        Left = 20
        Top = 128
        Width = 147
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1052#1077#1089#1090#1086' '#1087#1088#1080#1075#1086#1090#1086#1074#1083#1077#1085#1080#1103':'
      end
      object Label1: TLabel
        Left = 20
        Top = 158
        Width = 170
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1086#1089#1090#1072#1074' '#1082#1088#1072#1090#1082#1086' ('#1076#1083#1103' '#1084#1077#1085#1102'):'
      end
      object Label3: TLabel
        Left = 473
        Top = 79
        Width = 43
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1042#1099#1093#1086#1076':'
      end
      object Label6: TLabel
        Left = 20
        Top = 89
        Width = 196
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1086#1084#1077#1088' '#1087#1086' '#1089#1073#1086#1088#1085#1080#1082#1091' '#1088#1077#1094#1077#1087#1090#1091#1088':'
      end
      object Label7: TLabel
        Left = 20
        Top = 39
        Width = 102
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
      end
      object Label8: TLabel
        Left = 29
        Top = 262
        Width = 186
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1086#1089#1090#1072#1074' '#1087#1088#1086#1076#1091#1082#1094#1080#1080' '#1079#1072#1076#1072#1085' '#1085#1072':'
      end
      object KFEdDBText: TDBText
        Left = 577
        Top = 262
        Width = 80
        Height = 21
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataField = 'KFED'
      end
      object Label9: TLabel
        Left = 487
        Top = 262
        Width = 82
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1060' '#1077#1076#1080#1085#1080#1094#1099':'
      end
      object Label10: TLabel
        Left = 62
        Top = 309
        Width = 154
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1086#1082#1072#1079#1072#1090#1077#1083#1080' '#1079#1072#1076#1072#1085#1099' '#1085#1072' '
      end
      object Label14: TLabel
        Left = 46
        Top = 347
        Width = 231
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1086#1076#1091#1082#1090' '#1076#1083#1103' '#1088#1072#1089#1095#1077#1090#1072' '#1087#1086#1082#1072#1079#1072#1090#1077#1083#1077#1081' '
      end
      object Label15: TLabel
        Left = 46
        Top = 397
        Width = 440
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1086#1090#1077#1088#1080' '#1087#1086#1082#1072#1079#1072#1090#1077#1083#1077#1081' '#1074' '#1079#1072#1074#1080#1089#1080#1084#1086#1089#1090#1080' '#1086#1090' '#1090#1077#1093#1085#1086#1083#1086#1075#1080#1080' '#1087#1088#1080#1075#1086#1090#1086#1074#1083#1077#1085#1080#1103' '
      end
      object NameEdcxDBButtonEdit: TcxDBButtonEdit
        Left = 330
        Top = 259
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMEED'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameEdcxDBButtonEditPropertiesButtonClick
        TabOrder = 0
        Width = 149
      end
      object KolEdProdcxDBCalcEdit: TcxDBCalcEdit
        Left = 223
        Top = 259
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'KOLEDPROD_NOMREST'
        TabOrder = 1
        OnKeyDown = KolEdProdcxDBCalcEditKeyDown
        Width = 99
      end
      object SostKrcxDBMemo: TcxDBMemo
        Left = 20
        Top = 181
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'SOST_NOMREST'
        TabOrder = 2
        Height = 58
        Width = 632
      end
      object MPrigcxDBButtonEdit: TcxDBButtonEdit
        Left = 167
        Top = 124
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_MPRIG'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = MPrigcxDBButtonEditPropertiesButtonClick
        TabOrder = 3
        Width = 272
      end
      object NomercxDBTextEdit: TcxDBTextEdit
        Left = 213
        Top = 81
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NOMER_NOMREST'
        TabOrder = 4
        OnKeyDown = NomercxDBTextEditKeyDown
        Width = 149
      end
      object VihodcxDBTextEdit: TcxDBTextEdit
        Left = 533
        Top = 75
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'VIH_NOMREST'
        TabOrder = 5
        OnKeyDown = VihodcxDBTextEditKeyDown
        Width = 119
      end
      object PoscxDBDateEdit: TcxDBDateEdit
        Left = 503
        Top = 36
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'POS_NOMREST'
        Properties.Kind = ckDateTime
        TabOrder = 6
        OnKeyDown = PoscxDBDateEditKeyDown
        Width = 149
      end
      object NamecxDBTextEdit: TcxDBTextEdit
        Left = 138
        Top = 36
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_NOMREST'
        TabOrder = 7
        OnKeyDown = NamecxDBTextEditKeyDown
        Width = 346
      end
      object NameEdFactorcxDBButtonEdit: TcxDBButtonEdit
        Left = 223
        Top = 306
        DataBinding.DataField = 'NAME_ED_FACTOR'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = NameEdFactorcxDBButtonEditPropertiesButtonClick
        TabOrder = 8
        Width = 150
      end
      object NameProducecxDBButtonEdit: TcxDBButtonEdit
        Left = 223
        Top = 370
        DataBinding.DataField = 'NAME_SPRODUCE'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = NameProducecxDBButtonEditPropertiesButtonClick
        TabOrder = 9
        Width = 354
      end
      object NameLossFactorcxDBButtonEdit: TcxDBButtonEdit
        Left = 223
        Top = 420
        DataBinding.DataField = 'NAME_SLOSS_FACTOR'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = NameLossFactorcxDBButtonEditPropertiesButtonClick
        TabOrder = 10
        Width = 354
      end
    end
    object cxTabSheet3: TcxTabSheet
      Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086
      ImageIndex = 2
      object Label4: TLabel
        Left = 23
        Top = 264
        Width = 210
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1088#1086#1082' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080' '#1087#1088#1080' '#1093#1088#1072#1085#1077#1085#1080#1080':'
      end
      object Label11: TLabel
        Left = 32
        Top = 328
        Width = 178
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1086#1083#1078#1085#1086' '#1087#1086#1076#1072#1074#1072#1090#1100#1089#1103' '#1074' '#1074#1080#1076#1077':'
      end
      object Label12: TLabel
        Left = 32
        Top = 382
        Width = 188
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1058#1077#1084#1087#1077#1088#1072#1090#1091#1088#1072' '#1087#1086#1076#1072#1095#1080' '#1073#1083#1102#1076#1072':'
      end
      object Label2: TLabel
        Left = 231
        Top = 14
        Width = 208
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1058#1077#1093#1085#1086#1083#1086#1075#1080#1103' '#1087#1088#1080#1075#1086#1090#1086#1074#1083#1077#1085#1080#1103':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label13: TLabel
        Left = 159
        Top = 240
        Width = 343
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1054#1092#1086#1088#1084#1083#1077#1085#1080#1077', '#1087#1086#1076#1072#1095#1072', '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1103' '#1080' '#1093#1088#1072#1085#1077#1085#1080#1077
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object SrokcxDBTextEdit: TcxDBTextEdit
        Left = 176
        Top = 296
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'SROK_NOMREST'
        TabOrder = 0
        OnKeyDown = SrokcxDBTextEditKeyDown
        Width = 439
      end
      object VidcxDBTextEdit: TcxDBTextEdit
        Left = 176
        Top = 351
        DataBinding.DataField = 'VID_SNOMREST'
        TabOrder = 1
        Width = 439
      end
      object TempcxDBTextEdit: TcxDBTextEdit
        Left = 176
        Top = 413
        DataBinding.DataField = 'TEMP_SNOMREST'
        TabOrder = 2
        Width = 439
      end
      object TehnologcxDBMemo: TcxDBMemo
        Left = 12
        Top = 38
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'TEHN_NOMREST'
        TabOrder = 3
        Height = 194
        Width = 632
      end
    end
    object cxTabSheet1: TcxTabSheet
      Caption = #1055#1086#1082#1072#1079#1072#1090#1077#1083#1080' '#1082#1072#1095#1077#1089#1090#1074#1072' '#1080' '#1073#1077#1079#1086#1087#1072#1089#1085#1086#1089#1090#1080
      ImageIndex = 2
      object ApperancecxDBTextEdit: TcxDBTextEdit
        Left = 152
        Top = 29
        DataBinding.DataField = 'APPERANCE_SNOMREST'
        TabOrder = 0
        Width = 457
      end
      object cxLabel1: TcxLabel
        Left = 54
        Top = 30
        Caption = #1042#1085#1077#1096#1085#1080#1081' '#1074#1080#1076':'
      end
      object ColourcxDBTextEdit: TcxDBTextEdit
        Left = 152
        Top = 53
        DataBinding.DataField = 'COLOUR_SNOMREST'
        TabOrder = 2
        Width = 457
      end
      object TastecxDBTextEdit: TcxDBTextEdit
        Left = 152
        Top = 77
        DataBinding.DataField = 'TASTE_SNOMREST'
        TabOrder = 3
        Width = 457
      end
      object SmellcxDBTextEdit: TcxDBTextEdit
        Left = 152
        Top = 101
        DataBinding.DataField = 'SMELL_SNOMREST'
        TabOrder = 4
        Width = 457
      end
      object ConsistencecxDBTextEdit: TcxDBTextEdit
        Left = 152
        Top = 125
        DataBinding.DataField = 'CONSISTENCE_SNOMREST'
        TabOrder = 5
        Width = 457
      end
      object cxLabel2: TcxLabel
        Left = 107
        Top = 54
        Caption = #1062#1074#1077#1090':'
      end
      object cxLabel3: TcxLabel
        Left = 108
        Top = 78
        Caption = #1042#1082#1091#1089':'
      end
      object cxLabel4: TcxLabel
        Left = 100
        Top = 102
        Caption = #1047#1072#1087#1072#1093':'
      end
      object cxLabel5: TcxLabel
        Left = 48
        Top = 126
        Caption = #1050#1086#1085#1089#1080#1089#1090#1077#1085#1094#1080#1103':'
      end
      object MDSVcxDBTextEdit: TcxDBTextEdit
        Left = 480
        Top = 183
        DataBinding.DataField = 'MDSV_SNOMREST'
        TabOrder = 10
        Width = 129
      end
      object MDGcxDBTextEdit: TcxDBTextEdit
        Left = 480
        Top = 213
        DataBinding.DataField = 'MDG_SNOMREST'
        TabOrder = 11
        Width = 129
      end
      object MIScxDBTextEdit: TcxDBTextEdit
        Left = 480
        Top = 243
        DataBinding.DataField = 'MDS_SNOMREST'
        TabOrder = 12
        Width = 129
      end
      object KMAMcxDBTextEdit: TcxDBTextEdit
        Left = 480
        Top = 273
        DataBinding.DataField = 'KMAM_SNOMREST'
        TabOrder = 13
        Width = 129
      end
      object BGKPcxDBTextEdit: TcxDBTextEdit
        Left = 480
        Top = 303
        DataBinding.DataField = 'BGKR_SNOMREST'
        TabOrder = 14
        Width = 129
      end
      object ECOLIcxDBTextEdit: TcxDBTextEdit
        Left = 480
        Top = 333
        DataBinding.DataField = 'ECOLI_SNOMREST'
        TabOrder = 15
        Width = 129
      end
      object KPScxDBTextEdit: TcxDBTextEdit
        Left = 480
        Top = 363
        DataBinding.DataField = 'KPS_SNOMREST'
        TabOrder = 16
        Width = 129
      end
      object PROTEUScxDBTextEdit: TcxDBTextEdit
        Left = 480
        Top = 393
        DataBinding.DataField = 'PROTEUS_SNOMREST'
        TabOrder = 17
        Width = 129
      end
      object PMScxDBTextEdit: TcxDBTextEdit
        Left = 480
        Top = 423
        DataBinding.DataField = 'PMS_SNOMREST'
        TabOrder = 18
        Width = 129
      end
      object cxLabel6: TcxLabel
        Left = 169
        Top = 184
        Caption = #1052#1072#1089#1089#1086#1074#1072#1103' '#1076#1086#1083#1103' '#1089#1091#1093#1080#1093' '#1074#1077#1097#1077#1089#1090#1074' % ('#1085#1077' '#1084#1077#1085#1077#1077')'
      end
      object cxLabel7: TcxLabel
        Left = 228
        Top = 214
        Caption = #1052#1072#1089#1089#1086#1074#1072#1103' '#1076#1086#1083#1103' '#1078#1080#1088#1072' % ('#1085#1077' '#1084#1077#1085#1077#1077')'
      end
      object cxLabel8: TcxLabel
        Left = 231
        Top = 244
        Caption = #1052#1072#1089#1089#1086#1074#1072#1103' '#1076#1086#1083#1103' '#1089#1086#1083#1080' % ('#1085#1077' '#1073#1086#1083#1077#1077')'
      end
      object cxLabel9: TcxLabel
        Left = 54
        Top = 266
        AutoSize = False
        Caption = 
          #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1084#1077#1079#1086#1092#1086#1083#1100#1085#1099#1093' '#1072#1101#1088#1086#1073#1085#1099#1093' '#1080' '#1092#1072#1082#1091#1083#1100#1090#1072#1090#1080#1074#1085#1086' '#1072#1085#1072#1101#1088#1086#1073#1085#1099#1093' '#1084#1080#1082#1088#1086 +
          #1086#1088#1075#1072#1085#1080#1079#1084#1086#1074', '#1050#1054#1045' '#1074' 1'#1075' '#1087#1088#1086#1076#1091#1082#1090#1072', '#1085#1077' '#1073#1086#1083#1077#1077
        Properties.WordWrap = True
        Height = 54
        Width = 424
      end
      object cxLabel10: TcxLabel
        Left = 73
        Top = 304
        AutoSize = False
        Caption = 
          #1041#1072#1082#1090#1077#1088#1080#1080' '#1075#1088#1091#1087#1087#1099' '#1082#1080#1096#1077#1095#1085#1099#1093' '#1087#1072#1083#1086#1095#1077#1082', '#1085#1077' '#1076#1086#1087#1091#1089#1082#1072#1077#1090#1089#1103' '#1074' '#1084#1072#1089#1089#1077' '#1087#1088#1086#1076#1091#1082#1090 +
          #1072'. '#1075'.'
        Properties.WordWrap = True
        Height = 43
        Width = 351
      end
      object cxLabel11: TcxLabel
        Left = 392
        Top = 334
        Caption = 'E. coli'
      end
      object cxLabel12: TcxLabel
        Left = 184
        Top = 364
        Caption = #1050#1072#1091#1075#1091#1083#1072#1079#1086#1087#1086#1083#1086#1078#1080#1090#1077#1083#1100#1085#1099#1077' '#1089#1090#1072#1092#1080#1083#1086#1082#1086#1082#1080
      end
      object cxLabel13: TcxLabel
        Left = 402
        Top = 394
        Caption = 'Proteus'
      end
      object cxLabel14: TcxLabel
        Left = 88
        Top = 424
        Caption = #1087#1072#1090#1086#1075#1077#1085#1085#1099#1077' '#1084#1080#1082#1088#1086#1086#1088#1075#1072#1085#1080#1079#1084#1099', '#1074' '#1090#1086#1084' '#1095#1080#1089#1083#1077' '#1089#1072#1083#1100#1084#1086#1085#1077#1083#1083#1099
      end
      object cxLabel15: TcxLabel
        Left = 50
        Top = 3
        Caption = #1054#1088#1075#1072#1085#1086#1083#1077#1087#1090#1080#1095#1077#1089#1082#1080#1077' '#1087#1086#1082#1072#1079#1072#1090#1077#1083#1080' '#1073#1083#1102#1076#1072' ('#1080#1079#1076#1077#1083#1080#1103')'
        Style.TextStyle = [fsBold]
      end
      object cxLabel16: TcxLabel
        Left = 66
        Top = 155
        Caption = #1060#1080#1079#1080#1082#1086'-'#1093#1080#1084#1080#1095#1077#1089#1082#1080#1077' '#1087#1086#1082#1072#1079#1072#1090#1077#1083#1080
        Style.TextStyle = [fsBold]
      end
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 320
    Top = 24
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
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
end
