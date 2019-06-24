object REM_FormaZayavkaPredv: TREM_FormaZayavkaPredv
  Left = 288
  Top = 180
  Caption = #1047#1072#1103#1074#1082#1072' '#1085#1072' '#1088#1077#1084#1086#1085#1090' ('#1055#1088#1077#1076#1074'.)'
  ClientHeight = 655
  ClientWidth = 1018
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
  OnActivate = FormActivate
  OnClose = FormClose
  OnDeactivate = FormDeactivate
  PixelsPerInch = 120
  TextHeight = 16
  object Panel3: TPanel
    Left = 0
    Top = 602
    Width = 1018
    Height = 53
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object DBTextNameUser: TDBText
      Left = 12
      Top = 23
      Width = 129
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      AutoSize = True
      DataField = 'NAME_USER'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 442
      Top = 21
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
    object cxButtonSave: TcxButton
      Left = 715
      Top = 7
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonOK: TcxButton
      Left = 815
      Top = 7
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 0
    end
    object cxButtonClose: TcxButton
      Left = 915
      Top = 7
      Width = 93
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 2
    end
    object cxButtonOpenSpisokImage: TcxButton
      Left = 616
      Top = 7
      Width = 92
      Height = 30
      Caption = #1060#1086#1090#1086
      TabOrder = 3
    end
  end
  object Panel4: TPanel
    Left = 1014
    Top = 82
    Width = 4
    Height = 520
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 1
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1018
    Height = 82
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 3
    object Label1: TLabel
      Left = 12
      Top = 37
      Width = 411
      Height = 32
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1047#1072#1103#1074#1082#1072' '#1085#1072' '#1088#1077#1084#1086#1085#1090' ('#1087#1088#1077#1076#1074'.)  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -28
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 581
      Top = 37
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
    object NumcxDBTextEdit: TcxDBTextEdit
      Left = 442
      Top = 41
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'NUM_REM_Z2'
      TabOrder = 0
      OnKeyPress = NumcxDBTextEditKeyPress
      Width = 131
    end
    object PoscxDBDateEdit: TcxDBDateEdit
      Left = 629
      Top = 41
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      DataBinding.DataField = 'POS_REM_Z2'
      Properties.Kind = ckDateTime
      TabOrder = 1
      OnKeyPress = PoscxDBDateEditKeyPress
      Width = 221
    end
    object ToolBar3: TToolBar
      Left = 0
      Top = 0
      Width = 1018
      Height = 30
      Color = clBtnFace
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = DM.ImageList1
      ParentColor = False
      TabOrder = 2
      object ToolButton7: TToolButton
        Left = 0
        Top = 0
        Width = 17
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButton10: TToolButton
        Left = 17
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButton4'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateDocRemont: TToolButton
        Left = 40
        Top = 0
        Hint = #1089#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1056#1077#1084#1086#1085#1090
        Caption = 'ToolButtonCreateDocRemont'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonOpenDocRemont: TToolButton
        Left = 63
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1056#1077#1084#1086#1085#1090
        Caption = 'ToolButtonOpenDocRemont'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateCQuery: TToolButton
        Left = 86
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1079#1072#1087#1088#1086#1089
        Caption = 'ToolButtonCreateCQuery'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton1: TToolButton
        Left = 109
        Top = 0
        Width = 132
        Caption = 'ToolButton1'
        ImageIndex = 46
        Style = tbsSeparator
      end
      object ToolButtonCreateZayavku: TToolButton
        Left = 241
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1079#1072#1103#1074#1082#1091' '#1085#1072' '#1088#1077#1084#1086#1085#1090
        Caption = 'ToolButtonCreateZayavku'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateZayavkuClick
      end
    end
  end
  object cxPageControl2: TcxPageControl
    Left = 0
    Top = 82
    Width = 1014
    Height = 520
    ActivePage = cxTabSheet5
    Align = alClient
    TabOrder = 2
    ClientRectBottom = 520
    ClientRectRight = 1014
    ClientRectTop = 27
    object cxTabSheet5: TcxTabSheet
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 0
      object Label18: TLabel
        Left = 4
        Top = 445
        Width = 151
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1079#1072#1103#1074#1082#1080':'
      end
      object Label11: TLabel
        Left = 725
        Top = 123
        Width = 82
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1091#1084#1084#1072' '#1085#1072#1096#1072':'
      end
      object Label14: TLabel
        Left = 36
        Top = 18
        Width = 50
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1083#1080#1077#1085#1090':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label19: TLabel
        Left = 18
        Top = 42
        Width = 83
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1083#1080#1077#1085#1090' ('#1089#1090#1088'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label21: TLabel
        Left = 15
        Top = 66
        Width = 96
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1058#1077#1083#1077#1092#1086#1085' ('#1089#1090#1088'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label29: TLabel
        Left = 64
        Top = 109
        Width = 37
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = 'Email:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label20: TLabel
        Left = 38
        Top = 133
        Width = 76
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1040#1076#1088#1077#1089' ('#1089#1090#1088'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label22: TLabel
        Left = 580
        Top = 27
        Width = 86
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1052#1086#1076#1077#1083#1100' ('#1089#1090#1088'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label17: TLabel
        Left = 553
        Top = 59
        Width = 113
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088':'
      end
      object Label23: TLabel
        Left = 565
        Top = 88
        Width = 123
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088' 2:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label26: TLabel
        Left = 15
        Top = 216
        Width = 168
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077' ('#1074#1085#1077#1096#1085#1080#1081' '#1074#1080#1076'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 715
        Top = 155
        Width = 103
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1091#1084#1084#1072' '#1082#1083#1080#1077#1085#1090#1072':'
      end
      object Label5: TLabel
        Left = 489
        Top = 216
        Width = 105
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label8: TLabel
        Left = 489
        Top = 307
        Width = 61
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1080#1095#1080#1085#1072':'
      end
      object Label9: TLabel
        Left = 580
        Top = 192
        Width = 246
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1077#1076#1074#1072#1088#1080#1090#1077#1083#1100#1085#1099#1081' '#1089#1088#1086#1082' '#1088#1077#1084#1086#1085#1090#1072' ('#1076#1085'.):'
      end
      object Label10: TLabel
        Left = 580
        Top = 455
        Width = 73
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090':'
      end
      object Label15: TLabel
        Left = 592
        Top = 415
        Width = 61
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1080#1095#1080#1085#1072':'
      end
      object Label24: TLabel
        Left = 18
        Top = 307
        Width = 180
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086#1077' '#1086#1087#1080#1089#1072#1085#1080#1077':'
      end
      object NamecxDBTextEdit: TcxDBTextEdit
        Left = 172
        Top = 439
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_REM_Z2'
        TabOrder = 0
        OnKeyPress = NamecxDBTextEditKeyPress
        Width = 334
      end
      object cxDBCalcEditSUMNACHA_REM_Z2: TcxDBCalcEdit
        Left = 831
        Top = 120
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'SUMNACHA_REM_Z2'
        TabOrder = 1
        Width = 149
      end
      object NameKlientcxDBButtonEdit: TcxDBButtonEdit
        Left = 119
        Top = 7
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
        Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
        TabOrder = 2
        Width = 337
      end
      object KlientAdtrcxDBTextEdit: TcxDBTextEdit
        Left = 119
        Top = 135
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'KLIENT_ADR_REM_Z2'
        TabOrder = 3
        OnKeyPress = KlientAdtrcxDBTextEditKeyPress
        Width = 339
      end
      object EmailcxDBTextEdit: TcxDBTextEdit
        Left = 119
        Top = 103
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'KLIENT_EMAIL_REM_Z2'
        TabOrder = 4
        OnKeyPress = KlientPhonecxDBTextEditKeyPress
        Width = 339
      end
      object KlientPhonecxDBTextEdit: TcxDBTextEdit
        Left = 119
        Top = 71
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'KLIENT_PHONE_REM_Z2'
        TabOrder = 5
        OnKeyPress = KlientPhonecxDBTextEditKeyPress
        Width = 339
      end
      object KlientNamecxDBTextEdit: TcxDBTextEdit
        Left = 121
        Top = 39
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'KLIENT_NAME_REM_Z2'
        TabOrder = 6
        OnKeyPress = KlientNamecxDBTextEditKeyPress
        Width = 337
      end
      object SerNumcxDBTextEdit: TcxDBTextEdit
        Left = 696
        Top = 56
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'SERNUM1_REM_Z2'
        TabOrder = 7
        OnKeyPress = SerNumcxDBTextEditKeyPress
        Width = 284
      end
      object ModelcxDBTextEdit: TcxDBTextEdit
        Left = 696
        Top = 24
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'MODEL_STR_REM_Z2'
        TabOrder = 8
        OnKeyPress = ModelcxDBTextEditKeyPress
        Width = 284
      end
      object SerNum2cxDBTextEdit: TcxDBTextEdit
        Left = 696
        Top = 88
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'SERNUM2_REM_Z2'
        TabOrder = 9
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 284
      end
      object SostcxDBMemo: TcxDBMemo
        Left = 14
        Top = 239
        DataBinding.DataField = 'SOST_REM_Z2'
        TabOrder = 10
        Height = 61
        Width = 469
      end
      object NeisprcxDBMemo: TcxDBMemo
        Left = 489
        Top = 239
        DataBinding.DataField = 'NEISPR_REM_Z2'
        TabOrder = 11
        Height = 61
        Width = 491
      end
      object cxDBCalcEditSUMKLIENTA_REM_Z2: TcxDBCalcEdit
        Left = 831
        Top = 152
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'SUMKLIENTA_REM_Z2'
        TabOrder = 12
        Width = 149
      end
      object cxDBMemoPRICHINA_REM_Z2: TcxDBMemo
        Left = 489
        Top = 330
        DataBinding.DataField = 'PRICHINA_REM_Z2'
        TabOrder = 13
        Height = 65
        Width = 491
      end
      object cxDBImageComboBoxRESULT_REM_Z2: TcxDBImageComboBox
        Left = 678
        Top = 446
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItemRESULT_REM_Z2
        DataBinding.DataField = 'RESULT_REM_Z2'
        Properties.Items = <>
        TabOrder = 14
        Width = 302
      end
      object cxDBSpinEditSROK_REM_Z2: TcxDBSpinEdit
        Left = 831
        Top = 189
        DataBinding.DataField = 'SROK_REM_Z2'
        TabOrder = 15
        Width = 149
      end
      object cxDBImageComboBoxPRICHINA_LIST_REM_Z2: TcxDBImageComboBox
        Left = 678
        Top = 401
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItemPRICHINA_LIST_REM_Z2
        DataBinding.DataField = 'PRICHINA_LIST_REM_Z2'
        Properties.Items = <>
        TabOrder = 16
        Width = 302
      end
      object cxDBMemoDOPOPISANIE_REM_Z2: TcxDBMemo
        Left = 15
        Top = 330
        DataBinding.DataField = 'DOPOPISANIE_REM_Z2'
        TabOrder = 17
        Height = 65
        Width = 468
      end
    end
    object cxTabSheet10: TcxTabSheet
      Caption = #1044#1086#1087
      ImageIndex = 5
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label7: TLabel
        Left = 22
        Top = 332
        Width = 86
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
      end
      object Label16: TLabel
        Left = 609
        Top = 201
        Width = 53
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1052#1086#1076#1077#1083#1100':'
      end
      object Label13: TLabel
        Left = 560
        Top = 125
        Width = 102
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1082#1083#1072#1076' '#1087#1088#1080#1077#1084#1082#1080':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 618
        Top = 74
        Width = 44
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1080#1083#1077#1088':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label12: TLabel
        Left = 615
        Top = 50
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
      object Label6: TLabel
        Left = 592
        Top = 26
        Width = 70
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
      end
      object Label33: TLabel
        Left = 646
        Top = 2
        Width = 16
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = 'ID:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object NameHardwarecxDBButtonEdit: TcxDBButtonEdit
        Left = 3
        Top = 29
        DataBinding.DataField = 'NAME_REM_SHARDWARE'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameHardwarecxDBButtonEditPropertiesButtonClick
        TabOrder = 0
        Width = 324
      end
      object cxLabel5: TcxLabel
        Left = 3
        Top = 3
        Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077':'
      end
      object SerNumcxDBLabel: TcxDBLabel
        Left = 3
        Top = 59
        DataBinding.DataField = 'SERNUM_REM_SHARDWARE'
        Height = 21
        Width = 121
      end
      object SerNum2cxDBLabel: TcxDBLabel
        Left = 3
        Top = 83
        DataBinding.DataField = 'SERNUM2_REM_SHARDWARE'
        Height = 21
        Width = 121
      end
      object cxLabel3: TcxLabel
        Left = 532
        Top = 329
        Caption = #1050#1086#1084#1084#1077#1085#1090#1072#1088#1080#1081' '#1084#1072#1089#1090#1077#1088#1072':'
      end
      object CommentscxDBMemo: TcxDBMemo
        Left = 17
        Top = 355
        TabOrder = 5
        Height = 84
        Width = 509
      end
      object DescrcxDBMemo: TcxDBMemo
        Left = 532
        Top = 355
        DataBinding.DataField = 'DESCR_REM_Z2'
        TabOrder = 6
        Height = 86
        Width = 465
      end
      object NameBrandcxDBButtonEdit: TcxDBButtonEdit
        Left = 684
        Top = 146
        DataBinding.DataField = 'NAME_SBRAND'
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
        Properties.OnButtonClick = NameBrandcxDBButtonEditPropertiesButtonClick
        TabOrder = 7
        Width = 323
      end
      object cxLabel9: TcxLabel
        Left = 614
        Top = 148
        Caption = #1041#1088#1077#1085#1076':'
      end
      object cxLabel10: TcxLabel
        Left = 551
        Top = 174
        Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100':'
      end
      object cxLabel11: TcxLabel
        Left = 500
        Top = 224
        Caption = #1052#1086#1076#1077#1083#1100' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103':'
      end
      object cxLabel16: TcxLabel
        Left = 589
        Top = 250
        Caption = #1055#1088#1086#1076#1072#1074#1077#1094':'
      end
      object SellercxDBButtonEdit: TcxDBButtonEdit
        Left = 684
        Top = 248
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
        Properties.OnButtonClick = SellercxDBButtonEditPropertiesButtonClick
        TabOrder = 12
        Width = 323
      end
      object ProducerModelcxDBButtonEdit: TcxDBButtonEdit
        Left = 684
        Top = 222
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
        TabOrder = 13
        Width = 323
      end
      object NameModelcxDBButtonEdit: TcxDBButtonEdit
        Left = 684
        Top = 197
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_REM_SMODEL'
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
        Properties.OnButtonClick = NameModelcxDBButtonEditPropertiesButtonClick
        TabOrder = 14
        Width = 323
      end
      object NameproducercxDBButtonEdit: TcxDBButtonEdit
        Left = 684
        Top = 172
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
        Properties.OnButtonClick = NameproducercxDBButtonEditPropertiesButtonClick
        TabOrder = 15
        Width = 323
      end
      object NameSkladPrcxDBButtonEdit: TcxDBButtonEdit
        Left = 684
        Top = 120
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_SKLAD_PR'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameSkladPrcxDBButtonEditPropertiesButtonClick
        TabOrder = 16
        Width = 323
      end
      object cxLabel17: TcxLabel
        Left = 516
        Top = 97
        Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103' '#1091#1089#1090#1088#1086#1081#1089#1090#1074':'
      end
      object NameActivecategorycxDBButtonEdit: TcxDBButtonEdit
        Left = 684
        Top = 96
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
        Properties.OnButtonClick = NameActivecategorycxDBButtonEditPropertiesButtonClick
        TabOrder = 18
        Width = 323
      end
      object NameDialercxDBButtonEdit: TcxDBButtonEdit
        Left = 684
        Top = 72
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMEDILER'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameDialercxDBButtonEditPropertiesButtonClick
        TabOrder = 19
        Width = 323
      end
      object NameFirmcxDBButtonEdit: TcxDBButtonEdit
        Left = 684
        Top = 48
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
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxDBButtonEdit1PropertiesButtonClick
        TabOrder = 20
        Width = 323
      end
      object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
        Left = 684
        Top = 23
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
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameInfBasecxDBButtonEditPropertiesButtonClick
        TabOrder = 21
        Width = 323
      end
      object IDcxDBTextEdit: TcxDBTextEdit
        Left = 684
        Top = -1
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'ID_REM_Z2'
        Properties.ReadOnly = True
        TabOrder = 22
        OnKeyPress = NamecxDBTextEditKeyPress
        Width = 323
      end
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 920
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
    object ActionViborInfBase: TAction
      Caption = 'ActionViborInfBase'
    end
    object ActionViborFirm: TAction
      Caption = 'ActionViborFirm'
    end
    object ActionViborSkladPr: TAction
      Caption = 'ActionViborSkladPr'
    end
    object ActionViborDiler: TAction
      Caption = 'ActionViborDiler'
    end
    object ActionViborKlient: TAction
      Caption = 'ActionViborKlient'
    end
    object ActionViborTypeRemont: TAction
      Caption = 'ActionViborTypeRemont'
    end
    object ActionViborModel: TAction
      Caption = 'ActionViborModel'
    end
    object ActionViborSost: TAction
      Caption = 'ActionViborSost'
    end
    object ActionViborTecSklad: TAction
      Caption = 'ActionViborTecSklad'
    end
    object ActionAddNewKompl: TAction
      Caption = 'ActionAddNewKompl'
      ImageIndex = 0
    end
    object ActionEditKompl: TAction
      Caption = 'ActionEditKompl'
      ImageIndex = 1
    end
    object ActionAddNeispr: TAction
      Caption = 'ActionAddNeispr'
      ImageIndex = 0
    end
    object ActionEditNeispr: TAction
      Caption = 'ActionEditNeispr'
      ImageIndex = 1
    end
    object ActionDeleteKompl: TAction
      Caption = 'ActionDeleteKompl'
      ImageIndex = 2
    end
    object ActionDeleteNeispr: TAction
      Caption = 'ActionDeleteNeispr'
      ImageIndex = 2
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
    object ActionAddNewDopUsl: TAction
      Caption = 'ActionAddNewDopUsl'
      ImageIndex = 0
    end
    object ActionDeleteDopUsl: TAction
      Caption = 'ActionDeleteDopUsl'
      ImageIndex = 2
    end
    object ActionEditNomDopUsl: TAction
      Caption = 'ActionEditNomDopUsl'
      ImageIndex = 1
    end
    object ActionAddPerformedWork: TAction
      Caption = 'ActionAddPerformedWork'
      ImageIndex = 0
    end
    object ActionDeletePerformedWork: TAction
      Caption = 'ActionDeletePerformedWork'
      ImageIndex = 2
    end
    object ActionEditPerformedWork: TAction
      Caption = 'ActionEditPerformedWork'
      ImageIndex = 1
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 328
    Top = 8
  end
end
