object REM_FormaZayavka: TREM_FormaZayavka
  Left = 288
  Top = 180
  Caption = #1047#1072#1103#1074#1082#1072' '#1085#1072' '#1088#1077#1084#1086#1085#1090
  ClientHeight = 532
  ClientWidth = 827
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
  object Panel3: TPanel
    Left = 0
    Top = 489
    Width = 827
    Height = 43
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object DBTextNameUser: TDBText
      Left = 10
      Top = 19
      Width = 111
      Height = 16
      AutoSize = True
      DataField = 'NAME_USER'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 359
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
    object cxButtonSave: TcxButton
      Left = 581
      Top = 6
      Width = 75
      Height = 24
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonOK: TcxButton
      Left = 662
      Top = 6
      Width = 75
      Height = 24
      Action = ActionOK
      TabOrder = 0
    end
    object cxButtonClose: TcxButton
      Left = 743
      Top = 6
      Width = 76
      Height = 24
      Action = ActionClose
      TabOrder = 2
    end
    object cxButtonOpenSpisokImage: TcxButton
      Left = 501
      Top = 6
      Width = 74
      Height = 24
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1060#1086#1090#1086
      TabOrder = 3
      OnClick = cxButtonOpenSpisokImageClick
    end
  end
  object Panel4: TPanel
    Left = 824
    Top = 169
    Width = 3
    Height = 320
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 1
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 827
    Height = 67
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 3
    object Label1: TLabel
      Left = 10
      Top = 30
      Width = 238
      Height = 26
      Caption = #1047#1072#1103#1074#1082#1072' '#1085#1072' '#1088#1077#1084#1086#1085#1090'  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 379
      Top = 30
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
    object Label15: TLabel
      Left = 618
      Top = 48
      Width = 74
      Height = 13
      Caption = #1057#1088#1086#1082' '#1088#1077#1084#1086#1085#1090#1072':'
    end
    object NumcxDBTextEdit: TcxDBTextEdit
      Left = 266
      Top = 37
      DataBinding.DataField = 'NUM_REM_Z'
      TabOrder = 0
      OnKeyPress = NumcxDBTextEditKeyPress
      Width = 106
    end
    object PoscxDBDateEdit: TcxDBDateEdit
      Left = 418
      Top = 37
      DataBinding.DataField = 'POS_REM_Z'
      Properties.Kind = ckDateTime
      TabOrder = 1
      OnKeyPress = PoscxDBDateEditKeyPress
      Width = 179
    end
    object ToolBar3: TToolBar
      Left = 0
      Top = 0
      Width = 827
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
        OnClick = ToolButtonCreateDocRemontClick
      end
      object ToolButtonOpenDocRemont: TToolButton
        Left = 63
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1056#1077#1084#1086#1085#1090
        Caption = 'ToolButtonOpenDocRemont'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenDocRemontClick
      end
      object ToolButtonCreateCQuery: TToolButton
        Left = 86
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1079#1072#1087#1088#1086#1089
        Caption = 'ToolButtonCreateCQuery'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateCQueryClick
      end
      object ToolButton17: TToolButton
        Left = 109
        Top = 0
        Width = 156
        Caption = 'ToolButton17'
        ImageIndex = 46
        Style = tbsSeparator
      end
      object ToolButtonCreateDocPost: TToolButton
        Left = 265
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1055#1086#1089#1090#1091#1087#1083#1077#1085#1080#1077
        Caption = 'ToolButtonCreateDocPost'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateDocPostClick
      end
      object ToolButtonCreateDocZVidacha: TToolButton
        Left = 288
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1042#1099#1076#1072#1095#1072' '#1079#1072#1103#1074#1082#1080
        Caption = 'ToolButtonCreateDocZVidacha'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateDocZVidachaClick
      end
      object ToolButton3: TToolButton
        Left = 311
        Top = 0
        Width = 151
        Caption = 'ToolButton3'
        ImageIndex = 46
        Style = tbsSeparator
      end
      object ToolButtonOpenGarTalon: TToolButton
        Left = 462
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1087#1086' '#1079#1072#1074#1086#1076#1089#1082#1086#1084#1091' '#1085#1086#1084#1077#1088#1091' 1'
        Caption = 'ToolButtonOpenGarTalon'
        ImageIndex = 82
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenGarTalonClick
      end
      object ToolButtonCreateDocPrihNal: TToolButton
        Left = 485
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1085#1072' '#1087#1088#1077#1076#1086#1087#1083#1072#1090#1091' '#1055#1088#1080#1093#1086#1076' '#1085#1072#1083#1080#1095#1085#1099#1093
        Caption = 'ToolButtonCreateDocPrihNal'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateDocPrihNalClick
      end
    end
    object SrokcxDBDateEdit: TcxDBDateEdit
      Left = 701
      Top = 41
      DataBinding.DataField = 'SROK_REM_Z'
      TabOrder = 3
      Width = 121
    end
  end
  object cxPageControl2: TcxPageControl
    Left = 0
    Top = 169
    Width = 824
    Height = 320
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    ActivePage = cxTabSheet5
    Align = alClient
    TabOrder = 2
    ClientRectBottom = 320
    ClientRectRight = 824
    ClientRectTop = 24
    object cxTabSheet5: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 0
      object Label9: TLabel
        Left = 3
        Top = 67
        Width = 143
        Height = 13
        Caption = #1058#1077#1082#1091#1097#1077#1077' '#1084#1077#1089#1090#1086#1085#1072#1093#1086#1078#1076#1077#1085#1080#1077':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label8: TLabel
        Left = 70
        Top = 93
        Width = 68
        Height = 13
        Caption = #1058#1080#1087' '#1088#1077#1084#1086#1085#1090#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label18: TLabel
        Left = 401
        Top = 258
        Width = 118
        Height = 13
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1079#1072#1103#1074#1082#1080':'
      end
      object Label12: TLabel
        Left = 462
        Top = 67
        Width = 40
        Height = 13
        Caption = #1060#1080#1088#1084#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label6: TLabel
        Left = 443
        Top = 41
        Width = 55
        Height = 13
        Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
      end
      object Label13: TLabel
        Left = 58
        Top = 41
        Width = 81
        Height = 13
        Caption = #1057#1082#1083#1072#1076' '#1087#1088#1080#1077#1084#1082#1080':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 464
        Top = 91
        Width = 36
        Height = 13
        Caption = #1044#1080#1083#1077#1088':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label10: TLabel
        Left = 87
        Top = 119
        Width = 57
        Height = 13
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label11: TLabel
        Left = 595
        Top = 158
        Width = 37
        Height = 13
        Caption = #1057#1091#1084#1084#1072':'
      end
      object Label33: TLabel
        Left = 115
        Top = 15
        Width = 14
        Height = 13
        Caption = 'ID:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label34: TLabel
        Left = 430
        Top = 15
        Width = 65
        Height = 13
        Caption = 'ID '#1074#1099#1075#1088#1091#1079#1082#1080':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label35: TLabel
        Left = 108
        Top = 148
        Width = 40
        Height = 13
        Caption = #1055#1086#1074#1090#1086#1088':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label58: TLabel
        Left = 569
        Top = 186
        Width = 64
        Height = 13
        Caption = #1055#1088#1077#1076#1086#1087#1083#1072#1090#1072':'
      end
      object NameSkladTeccxDBButtonEdit: TcxDBButtonEdit
        Left = 170
        Top = 65
        DataBinding.DataField = 'NAME_SKLAD_TEC'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameSkladTeccxDBButtonEditPropertiesButtonClick
        TabOrder = 2
        Width = 253
      end
      object NameTypeRemontcxDBButtonEdit: TcxDBButtonEdit
        Left = 170
        Top = 91
        DataBinding.DataField = 'NAME_STREMONT'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameStrcxDBButtonEditPropertiesButtonClick
        TabOrder = 0
        Width = 253
      end
      object NamecxDBTextEdit: TcxDBTextEdit
        Left = 401
        Top = 272
        DataBinding.DataField = 'NAME_REM_Z'
        TabOrder = 4
        OnKeyPress = NamecxDBTextEditKeyPress
        Width = 406
      end
      object NameFirmcxDBButtonEdit: TcxDBButtonEdit
        Left = 506
        Top = 65
        DataBinding.DataField = 'NAMEFIRM'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxDBButtonEdit1PropertiesButtonClick
        TabOrder = 6
        Width = 254
      end
      object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
        Left = 506
        Top = 39
        DataBinding.DataField = 'NAME_SINFBASE_OBMEN'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameInfBasecxDBButtonEditPropertiesButtonClick
        TabOrder = 5
        Width = 254
      end
      object NameDialercxDBButtonEdit: TcxDBButtonEdit
        Left = 506
        Top = 91
        DataBinding.DataField = 'NAMEDILER'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameDialercxDBButtonEditPropertiesButtonClick
        TabOrder = 7
        Width = 254
      end
      object NameSkladPrcxDBButtonEdit: TcxDBButtonEdit
        Left = 170
        Top = 39
        DataBinding.DataField = 'NAME_SKLAD_PR'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameSkladPrcxDBButtonEditPropertiesButtonClick
        TabOrder = 1
        Width = 253
      end
      object OutcxDBImageComboBox: TcxDBImageComboBox
        Left = 16
        Top = 237
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItemSostZayvkiNaRemont
        DataBinding.DataField = 'OUT_REM_Z'
        ParentFont = False
        Properties.Items = <>
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clNavy
        Style.Font.Height = -11
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = [fsBold]
        Style.IsFontAssigned = True
        TabOrder = 9
        Width = 274
      end
      object GotovoKVadachecxDBImageComboBox: TcxDBImageComboBox
        Left = 16
        Top = 262
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItemGotovoKVidache
        DataBinding.DataField = 'GOTOVO_K_VIDACHE_REM_Z'
        ParentFont = False
        Properties.Items = <>
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clNavy
        Style.Font.Height = -11
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = [fsBold]
        Style.IsFontAssigned = True
        TabOrder = 10
        Width = 274
      end
      object NameSostcxDBButtonEdit: TcxDBButtonEdit
        Left = 170
        Top = 117
        DataBinding.DataField = 'NAME_REMSSOST'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameSostcxDBButtonEditPropertiesButtonClick
        TabOrder = 3
        Width = 253
      end
      object OtremontcxDBDateEdit: TcxDBDateEdit
        Left = 530
        Top = 214
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'POSREMONT_REM_Z'
        Properties.Kind = ckDateTime
        TabOrder = 11
        Width = 121
      end
      object cxLabel1: TcxLabel
        Left = 416
        Top = 218
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1044#1072#1090#1072' '#1088#1077#1084#1086#1085#1090#1072':'
      end
      object cxLabel2: TcxLabel
        Left = 422
        Top = 239
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080':'
      end
      object VidanocxDBDateEdit: TcxDBDateEdit
        Left = 530
        Top = 238
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'POSOUT_REM_Z'
        Properties.Kind = ckDateTime
        TabOrder = 14
        Width = 121
      end
      object SumcxDBCalcEdit: TcxDBCalcEdit
        Left = 639
        Top = 156
        DataBinding.DataField = 'SUM_REM_Z'
        TabOrder = 8
        Width = 121
      end
      object cxLabel4: TcxLabel
        Left = 715
        Top = 217
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1043#1072#1088#1072#1085#1090#1080#1103':'
      end
      object WarrantycxDBCalcEdit: TcxDBCalcEdit
        Left = 715
        Top = 238
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'WARRANTY_REM_Z'
        TabOrder = 16
        Width = 84
      end
      object StrCodeVigrcxDBTextEdit: TcxDBTextEdit
        Left = 506
        Top = 13
        TabStop = False
        DataBinding.DataField = 'STR_CODE_VIGR_REM_Z_1'
        TabOrder = 17
        OnKeyPress = NamecxDBTextEditKeyPress
        Width = 254
      end
      object IDcxDBTextEdit: TcxDBTextEdit
        Left = 170
        Top = 13
        DataBinding.DataField = 'ID_REM_Z'
        Properties.ReadOnly = True
        TabOrder = 18
        OnKeyPress = NamecxDBTextEditKeyPress
        Width = 253
      end
      object OnlyDiagnosticcxDBCheckBox: TcxDBCheckBox
        Left = 17
        Top = 200
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1090#1086#1083#1100#1082#1086' '#1076#1080#1072#1075#1085#1086#1089#1090#1080#1082#1072
        DataBinding.DataField = 'FL_ONLY_DAGNOSTIC_REM_Z_1'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 19
        Width = 169
      end
      object FlPovtorcxDBImageComboBox: TcxDBImageComboBox
        Left = 170
        Top = 142
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItem_REM_FL_POVTOR_REM_Z
        DataBinding.DataField = 'FL_POVTOR_REM_Z'
        Properties.Items = <>
        TabOrder = 20
        Width = 253
      end
      object cxLabel17: TcxLabel
        Left = 444
        Top = 116
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103' '#1091#1089#1090#1088#1086#1081#1089#1090#1074':'
      end
      object NameActivecategorycxDBButtonEdit: TcxDBButtonEdit
        Left = 506
        Top = 131
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NAME_REM_SACTCATEGORY'
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
        TabOrder = 22
        Width = 250
      end
      object cxDBCalcEditPREDOPLATA_REM_Z_1: TcxDBCalcEdit
        Left = 639
        Top = 183
        DataBinding.DataField = 'PREDOPLATA_REM_Z_1'
        TabOrder = 23
        Width = 121
      end
    end
    object cxTabSheet6: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1050#1083#1080#1077#1085#1090
      ImageIndex = 1
      object Label14: TLabel
        Left = 29
        Top = 28
        Width = 39
        Height = 13
        Caption = #1050#1083#1080#1077#1085#1090':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label19: TLabel
        Left = 14
        Top = 138
        Width = 65
        Height = 13
        Caption = #1050#1083#1080#1077#1085#1090' ('#1089#1090#1088'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label20: TLabel
        Left = 30
        Top = 212
        Width = 60
        Height = 13
        Caption = #1040#1076#1088#1077#1089' ('#1089#1090#1088'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label21: TLabel
        Left = 11
        Top = 158
        Width = 74
        Height = 13
        Caption = #1058#1077#1083#1077#1092#1086#1085' ('#1089#1090#1088'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label29: TLabel
        Left = 51
        Top = 193
        Width = 28
        Height = 13
        Caption = 'Email:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label30: TLabel
        Left = 395
        Top = 28
        Width = 53
        Height = 13
        Caption = #1044#1086#1087' '#1080#1085#1092#1086':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label36: TLabel
        Left = 14
        Top = 60
        Width = 52
        Height = 13
        Caption = #1060#1072#1084#1080#1083#1080#1103':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label37: TLabel
        Left = 41
        Top = 86
        Width = 25
        Height = 13
        Caption = #1048#1084#1103':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label38: TLabel
        Left = 14
        Top = 112
        Width = 50
        Height = 13
        Caption = #1054#1090#1095#1077#1089#1090#1074#1086':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label51: TLabel
        Left = 154
        Top = 243
        Width = 57
        Height = 13
        Caption = #1050#1077#1084' '#1089#1076#1072#1085#1086':'
      end
      object NameKlientcxDBButtonEdit: TcxDBButtonEdit
        Left = 98
        Top = 25
        DataBinding.DataField = 'NAMEKLIENT'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
        TabOrder = 0
        Width = 274
      end
      object KlientNamecxDBTextEdit: TcxDBTextEdit
        Left = 98
        Top = 136
        DataBinding.DataField = 'KLIENT_NAME_REM_Z'
        TabOrder = 4
        OnKeyPress = KlientNamecxDBTextEditKeyPress
        Width = 273
      end
      object KlientAdtrcxDBTextEdit: TcxDBTextEdit
        Left = 98
        Top = 214
        DataBinding.DataField = 'KLIENT_ADR_REM_Z'
        TabOrder = 8
        OnKeyPress = KlientAdtrcxDBTextEditKeyPress
        Width = 273
      end
      object KlientPhonecxDBTextEdit: TcxDBTextEdit
        Left = 96
        Top = 162
        DataBinding.DataField = 'KLIENT_PHONE_REM_Z'
        TabOrder = 5
        OnKeyPress = KlientPhonecxDBTextEditKeyPress
        Width = 275
      end
      object EmailcxDBTextEdit: TcxDBTextEdit
        Left = 96
        Top = 188
        DataBinding.DataField = 'KLIENT_EMAIL_REM_Z_1'
        TabOrder = 6
        OnKeyPress = KlientPhonecxDBTextEditKeyPress
        Width = 275
      end
      object DopInfocxDBMemo: TcxDBMemo
        Left = 454
        Top = 25
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'KLIENT_DOP_INFO_REM_Z_1'
        TabOrder = 7
        Height = 41
        Width = 346
      end
      object AdrCodeRegioncxDBTextEdit: TcxDBTextEdit
        Left = 453
        Top = 94
        DataBinding.DataField = 'CODE_SADR_REGION'
        TabOrder = 9
        Width = 28
      end
      object AdrRegioncxDBTextEdit: TcxDBTextEdit
        Left = 499
        Top = 94
        DataBinding.DataField = 'NAME_SADR_REGION'
        TabOrder = 10
        Width = 301
      end
      object AdrNasPunktcxDBTextEdit: TcxDBTextEdit
        Left = 453
        Top = 146
        DataBinding.DataField = 'NAME_SADR_NASPUNKT'
        TabOrder = 11
        Width = 347
      end
      object AdrPostCodecxDBTextEdit: TcxDBTextEdit
        Left = 454
        Top = 172
        DataBinding.DataField = 'POSTCODE_SADR_STREET'
        TabOrder = 12
        Width = 116
      end
      object AdrStreetcxDBTextEdit: TcxDBTextEdit
        Left = 577
        Top = 172
        DataBinding.DataField = 'NAME_SADR_STREET'
        TabOrder = 13
        Width = 219
      end
      object AdrDomcxDBTextEdit: TcxDBTextEdit
        Left = 605
        Top = 198
        DataBinding.DataField = 'NAME_SADR_DOM'
        TabOrder = 14
        Width = 63
      end
      object AdrKVcxDBTextEdit: TcxDBTextEdit
        Left = 743
        Top = 198
        DataBinding.DataField = 'NAME_SADR_KV'
        TabOrder = 15
        Width = 57
      end
      object StroencxDBTextEdit: TcxDBTextEdit
        Left = 674
        Top = 198
        DataBinding.DataField = 'NAME_SADR_STROEN'
        TabOrder = 16
        Width = 63
      end
      object RayoncxDBTextEdit: TcxDBTextEdit
        Left = 454
        Top = 120
        DataBinding.DataField = 'NAME_SADR_RAYON'
        TabOrder = 17
        Width = 346
      end
      object cxDBTextEditFAMILIYA_REM_Z_1: TcxDBTextEdit
        Left = 98
        Top = 58
        DataBinding.DataField = 'FAMILIYA_REM_Z_1'
        TabOrder = 1
        Width = 274
      end
      object cxDBTextEditIMYA_REM_Z_1: TcxDBTextEdit
        Left = 98
        Top = 84
        DataBinding.DataField = 'IMYA_REM_Z_1'
        TabOrder = 2
        Width = 274
      end
      object cxDBTextEditOTCHESTVO_REM_Z_1: TcxDBTextEdit
        Left = 98
        Top = 110
        DataBinding.DataField = 'OTCHESTVO_REM_Z_1'
        TabOrder = 3
        OnKeyPress = cxDBTextEditOTCHESTVO_REM_Z_1KeyPress
        Width = 274
      end
      object ButtonAddressVibor: TButton
        Left = 739
        Top = 69
        Width = 61
        Height = 20
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1042#1099#1073#1088#1072#1090#1100
        TabOrder = 18
        OnClick = ButtonAddressViborClick
      end
      object cxLabel14: TcxLabel
        Left = 479
        Top = 234
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1047#1072#1087#1095#1072#1089#1090#1080':'
      end
      object FlZipcxDBImageComboBox: TcxDBImageComboBox
        Left = 540
        Top = 229
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItem_REM_Z_FL_ZIP
        DataBinding.DataField = 'FL_ZIP_REM_Z_1'
        Properties.Items = <>
        TabOrder = 20
        Width = 260
      end
      object FlKlientPreupregdencxDBImageComboBox: TcxDBImageComboBox
        Left = 540
        Top = 260
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItem_REM_Z_KLIENT_PREDUPREGDEN
        DataBinding.DataField = 'FL_KL_PREDUPR_NO_GARANT_REM_Z_1'
        Properties.Items = <>
        TabOrder = 21
        Width = 260
      end
      object cxLabel15: TcxLabel
        Left = 437
        Top = 262
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1055#1088#1077#1076#1091#1087#1088#1077#1078#1076#1077#1085#1080#1103':'
      end
      object KEM_SDANOcxDBImageComboBox: TcxDBImageComboBox
        Left = 223
        Top = 238
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxREM_KemSdano
        DataBinding.DataField = 'KEMSDANO_REM_Z_1'
        Properties.Items = <>
        TabOrder = 23
        Width = 149
      end
    end
    object cxTabSheet7: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1059#1089#1090#1088#1086#1081#1089#1090#1074#1086
      ImageIndex = 2
      object Label16: TLabel
        Left = 496
        Top = 46
        Width = 42
        Height = 13
        Caption = #1052#1086#1076#1077#1083#1100':'
      end
      object Label22: TLabel
        Left = 45
        Top = 24
        Width = 68
        Height = 13
        Caption = #1052#1086#1076#1077#1083#1100' ('#1089#1090#1088'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label24: TLabel
        Left = 37
        Top = 47
        Width = 75
        Height = 13
        Caption = #1043#1072#1088'. '#1076#1086#1082#1091#1084#1077#1085#1090':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label17: TLabel
        Left = 27
        Top = 67
        Width = 89
        Height = 13
        Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088':'
      end
      object Label23: TLabel
        Left = 19
        Top = 86
        Width = 98
        Height = 13
        Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088' 2:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label26: TLabel
        Left = 20
        Top = 174
        Width = 131
        Height = 13
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077' ('#1074#1085#1077#1096#1085#1080#1081' '#1074#1080#1076'):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label40: TLabel
        Left = 20
        Top = 109
        Width = 98
        Height = 13
        Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088' 3:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label41: TLabel
        Left = 20
        Top = 128
        Width = 98
        Height = 13
        Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088' 4:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label42: TLabel
        Left = 37
        Top = 150
        Width = 81
        Height = 13
        Caption = #1053#1086#1084#1077#1088' '#1073#1072#1090#1072#1088#1077#1080':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label43: TLabel
        Left = 395
        Top = 108
        Width = 161
        Height = 13
        Caption = #1055#1072#1088#1090'. '#1085#1086#1084#1077#1088' / '#1052#1058#1052' /Product ID:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label44: TLabel
        Left = 486
        Top = 128
        Width = 53
        Height = 13
        Caption = 'Reference:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label45: TLabel
        Left = 467
        Top = 147
        Width = 72
        Height = 13
        Caption = 'Software code:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label46: TLabel
        Left = 464
        Top = 167
        Width = 76
        Height = 13
        Caption = 'Hardware code:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label47: TLabel
        Left = 506
        Top = 186
        Width = 34
        Height = 13
        Caption = #1055#1054' '#1076#1086':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label48: TLabel
        Left = 488
        Top = 206
        Width = 52
        Height = 13
        Caption = #1055#1054' '#1087#1086#1089#1083#1077':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label49: TLabel
        Left = 618
        Top = 230
        Width = 75
        Height = 13
        Caption = #1044#1072#1090#1072' '#1074#1099#1087#1091#1089#1082#1072':'
      end
      object Label50: TLabel
        Left = 616
        Top = 256
        Width = 76
        Height = 13
        Caption = #1044#1072#1090#1072' '#1087#1088#1086#1076#1072#1078#1080':'
      end
      object NameModelcxDBButtonEdit: TcxDBButtonEdit
        Left = 558
        Top = 42
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
        TabOrder = 11
        Width = 262
      end
      object SerNum2cxDBTextEdit: TcxDBTextEdit
        Left = 136
        Top = 85
        DataBinding.DataField = 'SERNUM2_REM_Z'
        TabOrder = 2
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 230
      end
      object SerNumcxDBTextEdit: TcxDBTextEdit
        Left = 136
        Top = 64
        DataBinding.DataField = 'SERNUM_REM_Z'
        TabOrder = 3
        OnKeyPress = SerNumcxDBTextEditKeyPress
        Width = 230
      end
      object NumGarDoccxDBTextEdit: TcxDBTextEdit
        Left = 137
        Top = 43
        DataBinding.DataField = 'NUM_GARDOC_REM_Z'
        TabOrder = 1
        OnKeyPress = ModelcxDBTextEditKeyPress
        Width = 229
      end
      object ModelcxDBTextEdit: TcxDBTextEdit
        Left = 137
        Top = 22
        DataBinding.DataField = 'MODEL_REM_Z'
        TabOrder = 0
        OnKeyPress = ModelcxDBTextEditKeyPress
        Width = 229
      end
      object SostcxDBMemo: TcxDBMemo
        Left = 19
        Top = 193
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'SOST_REM_Z'
        TabOrder = 4
        Height = 55
        Width = 348
      end
      object cxLabel9: TcxLabel
        Left = 494
        Top = 2
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1041#1088#1077#1085#1076':'
      end
      object cxLabel10: TcxLabel
        Left = 450
        Top = 24
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100':'
      end
      object cxLabel11: TcxLabel
        Left = 409
        Top = 64
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1052#1086#1076#1077#1083#1100' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103':'
      end
      object cxLabel16: TcxLabel
        Left = 480
        Top = 85
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1055#1088#1086#1076#1072#1074#1077#1094':'
      end
      object SellercxDBButtonEdit: TcxDBButtonEdit
        Left = 558
        Top = 84
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NAME_SSELLER'
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
        TabOrder = 13
        Width = 263
      end
      object ProducerModelcxDBButtonEdit: TcxDBButtonEdit
        Left = 558
        Top = 63
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NAME_REM_SPRMODEL'
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
        Properties.OnButtonClick = ProducerModelcxDBButtonEditPropertiesButtonClick
        TabOrder = 12
        Width = 263
      end
      object NameproducercxDBButtonEdit: TcxDBButtonEdit
        Left = 558
        Top = 22
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NAME_SPRODUCER'
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
        TabOrder = 6
        Width = 260
      end
      object NameBrandcxDBButtonEdit: TcxDBButtonEdit
        Left = 558
        Top = 2
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
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
        TabOrder = 5
        Width = 260
      end
      object PlombaSetcxDBCheckBox: TcxDBCheckBox
        Left = 51
        Top = 253
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1086#1087#1083#1086#1084#1073#1080#1088#1086#1074#1072#1085#1086' '#1087#1086#1089#1083#1077' '#1088#1077#1084#1086#1085#1090#1072
        DataBinding.DataField = 'FL_PLOMBA_SET_REM_Z_1'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 14
        Width = 190
      end
      object TextPlombacxDBTextEdit: TcxDBTextEdit
        Left = 288
        Top = 254
        DataBinding.DataField = 'TEXT_PLOMBA_REM_Z_1'
        TabOrder = 15
        OnKeyPress = ModelcxDBTextEditKeyPress
        Width = 78
      end
      object cxDBTextEditSERNUM3_REM_Z_1: TcxDBTextEdit
        Left = 137
        Top = 106
        DataBinding.DataField = 'SERNUM3_REM_Z_1'
        TabOrder = 16
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 230
      end
      object cxDBTextEditSERNUM4_REM_Z_1: TcxDBTextEdit
        Left = 137
        Top = 127
        DataBinding.DataField = 'SERNUM4_REM_Z_1'
        TabOrder = 17
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 230
      end
      object cxDBTextEditNUMBAT_REM_Z_1: TcxDBTextEdit
        Left = 136
        Top = 148
        DataBinding.DataField = 'NUMBAT_REM_Z_1'
        TabOrder = 18
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 230
      end
      object cxDBTextEditPARTNUM_REM_Z_1: TcxDBTextEdit
        Left = 558
        Top = 104
        DataBinding.DataField = 'PARTNUM_REM_Z_1'
        TabOrder = 19
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 263
      end
      object cxDBTextEditREFERENCE_REM_Z_1: TcxDBTextEdit
        Left = 558
        Top = 124
        DataBinding.DataField = 'REFERENCE_REM_Z_1'
        TabOrder = 20
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 263
      end
      object cxDBTextEditSWCODE_REM_Z_1: TcxDBTextEdit
        Left = 558
        Top = 143
        DataBinding.DataField = 'SWCODE_REM_Z_1'
        TabOrder = 21
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 263
      end
      object cxDBTextEditHWCODE_REM_Z_1: TcxDBTextEdit
        Left = 558
        Top = 163
        DataBinding.DataField = 'HWCODE_REM_Z_1'
        TabOrder = 22
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 263
      end
      object cxDBTextEditPODO_REM_Z_1: TcxDBTextEdit
        Left = 558
        Top = 182
        DataBinding.DataField = 'PODO_REM_Z_1'
        TabOrder = 23
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 263
      end
      object cxDBTextEditPOPOSLE_REM_Z_1: TcxDBTextEdit
        Left = 558
        Top = 202
        DataBinding.DataField = 'POPOSLE_REM_Z_1'
        TabOrder = 24
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 263
      end
      object cxDBDateEditDATE_VIPUSK_REM_Z_1: TcxDBDateEdit
        Left = 700
        Top = 228
        DataBinding.DataField = 'DATE_VIPUSK_REM_Z_1'
        TabOrder = 25
        Width = 121
      end
      object cxDBDateEditDATE_PRODAGI_REM_Z_1: TcxDBDateEdit
        Left = 700
        Top = 254
        DataBinding.DataField = 'DATE_PRODAGI_REM_Z_1'
        TabOrder = 26
        Width = 121
      end
    end
    object cxTabSheet8: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1050#1086#1084#1087#1083#1077#1082#1090#1072#1094#1080#1103
      ImageIndex = 3
      object ToolBar1: TToolBar
        Left = 0
        Top = 0
        Width = 824
        Height = 26
        ButtonHeight = 23
        Caption = 'ToolBar1'
        EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
        Images = DM.ImageList1
        TabOrder = 0
        object ToolButton1: TToolButton
          Left = 0
          Top = 0
          Action = ActionAddNewKompl
        end
        object ToolButton5: TToolButton
          Left = 23
          Top = 0
          Action = ActionEditKompl
        end
        object ToolButton6: TToolButton
          Left = 46
          Top = 0
          Action = ActionDeleteKompl
        end
        object ToolButton16: TToolButton
          Left = 69
          Top = 0
          Caption = 'ToolButton16'
          DropdownMenu = PopupMenuAddKompl
          ImageIndex = 45
        end
      end
      object cxGrid1: TcxGrid
        Left = 0
        Top = 26
        Width = 824
        Height = 206
        Align = alClient
        TabOrder = 1
        object cxGrid1DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsBehavior.IncSearch = True
          OptionsSelection.InvertSelect = False
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          Styles.Header = DM.cxStyleHeaderTable
          object cxGrid1DBTableView1RECNO: TcxGridDBColumn
            Caption = #8470
            DataBinding.FieldName = 'RECNO'
            Width = 30
          end
          object cxGrid1DBTableView1NAME_REM_SKOMPLMODEL: TcxGridDBColumn
            Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
            DataBinding.FieldName = 'NAME_REM_SKOMPLMODEL'
            Width = 239
          end
          object cxGrid1DBTableView1KOL_REM_ZKOMPL: TcxGridDBColumn
            Caption = #1050#1086#1083'.'
            DataBinding.FieldName = 'KOL_REM_ZKOMPL'
            Width = 75
          end
        end
        object cxGrid1Level1: TcxGridLevel
          GridView = cxGrid1DBTableView1
        end
      end
      object KomplcxDBMemo: TcxDBMemo
        Left = 0
        Top = 232
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alBottom
        DataBinding.DataField = 'KOMPLECT_REM_Z'
        TabOrder = 2
        Height = 64
        Width = 824
      end
    end
    object cxTabSheet9: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100
      ImageIndex = 4
      object Panel2: TPanel
        Left = 0
        Top = 228
        Width = 824
        Height = 68
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alBottom
        TabOrder = 0
        object Label39: TLabel
          Left = 10
          Top = 45
          Width = 155
          Height = 13
          Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100' '#1082#1083#1080#1077#1085#1090#1072' (CFC):'
        end
        object NameGrpCFCcxDBLabel: TcxDBLabel
          Left = 176
          Top = 28
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          DataBinding.DataField = 'NAME_REM_SPRNEISPR_GRP'
          Height = 18
          Width = 190
        end
        object cxDBButtonEditNAME_REM_SPRNEISPR: TcxDBButtonEdit
          Left = 176
          Top = 42
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
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
          Properties.OnButtonClick = CFCcxDBButtonEditPropertiesButtonClick
          TabOrder = 1
          Width = 345
        end
        object CodeNeisprPrcxDBLabel: TcxDBLabel
          Left = 405
          Top = 25
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          DataBinding.DataField = 'CODE_REM_SPRNEISPR'
          Height = 17
          Width = 62
        end
        object cxDBLabelNAME_ENG_REM_SPRNEISPR: TcxDBLabel
          Left = 547
          Top = 45
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          DataBinding.DataField = 'NAME_ENG_REM_SPRNEISPR'
          Height = 17
          Width = 274
        end
        object cxDBLabelNAME_ENG_REM_SPRNEISPR_GRP: TcxDBLabel
          Left = 546
          Top = 35
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          DataBinding.DataField = 'NAME_ENG_REM_SPRNEISPR_GRP'
          Height = 17
          Width = 261
        end
        object FlDefectDemocxDBImageComboBox: TcxDBImageComboBox
          Left = 501
          Top = 5
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          RepositoryItem = DM.cxEditRepository1ImageComboBoxItem_REM_Z_FL_DEFECT_DEMO
          DataBinding.DataField = 'FL_DEFECT_DEMO_REM_Z_1'
          Properties.Items = <>
          TabOrder = 5
          Width = 260
        end
        object FlVklcxDBImageComboBox: TcxDBImageComboBox
          Left = 85
          Top = 5
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          RepositoryItem = DM.cxEditRepository1ImageComboBoxItem_REM_Z_FL_VKL
          DataBinding.DataField = 'FL_VKL_REM_Z_1'
          Properties.Items = <>
          TabOrder = 6
          Width = 260
        end
        object cxLabel12: TcxLabel
          Left = 14
          Top = 24
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = #1042#1082#1083#1102#1095#1077#1085#1080#1077':'
        end
        object cxLabel13: TcxLabel
          Left = 349
          Top = 5
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Caption = #1044#1077#1084#1086#1085#1089#1090#1088#1072#1094#1080#1103' '#1076#1077#1092#1077#1082#1090#1072':'
        end
      end
      object Panel5: TPanel
        Left = 0
        Top = 26
        Width = 824
        Height = 58
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alTop
        BevelEdges = []
        TabOrder = 1
        object cxGrid2: TcxGrid
          Left = 1
          Top = 1
          Width = 822
          Height = 56
          Align = alClient
          TabOrder = 0
          object cxGrid2DBTableView1: TcxGridDBTableView
            NavigatorButtons.ConfirmDelete = False
            DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
            DataController.Summary.DefaultGroupSummaryItems = <>
            DataController.Summary.FooterSummaryItems = <>
            DataController.Summary.SummaryGroups = <>
            OptionsBehavior.IncSearch = True
            OptionsSelection.InvertSelect = False
            OptionsView.ColumnAutoWidth = True
            OptionsView.GroupByBox = False
            Styles.Header = DM.cxStyleHeaderTable
            object cxGrid2DBTableView1RECNO: TcxGridDBColumn
              Caption = #8470
              DataBinding.FieldName = 'RECNO'
              Width = 29
            end
            object cxGrid2DBTableView1NAME_REM_SGRPNEISPR: TcxGridDBColumn
              DataBinding.FieldName = 'NAME_REM_SGRPNEISPR'
              Width = 172
            end
            object cxGrid2DBTableView1NAME_ENG_REM_SGRPNEISPR: TcxGridDBColumn
              DataBinding.FieldName = 'NAME_ENG_REM_SGRPNEISPR'
              Width = 254
            end
            object cxGrid2DBTableView1NAME_REM_SNEISPR: TcxGridDBColumn
              Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
              DataBinding.FieldName = 'NAME_REM_SNEISPR'
              Width = 278
            end
            object cxGrid2DBTableView1NAME_ENG_REM_SNEISPR: TcxGridDBColumn
              DataBinding.FieldName = 'NAME_ENG_REM_SNEISPR'
              Width = 279
            end
          end
          object cxGrid2Level1: TcxGridLevel
            GridView = cxGrid2DBTableView1
          end
        end
      end
      object Panel6: TPanel
        Left = 0
        Top = 84
        Width = 824
        Height = 16
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alTop
        Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1080' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103
        TabOrder = 2
      end
      object ToolBar6: TToolBar
        Left = 0
        Top = 0
        Width = 824
        Height = 26
        ButtonHeight = 23
        Caption = 'ToolBar2'
        EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
        Images = DM.ImageList1
        TabOrder = 3
        object ToolButton18: TToolButton
          Left = 0
          Top = 0
          Action = ActionAddNeispr
        end
        object ToolButton19: TToolButton
          Left = 23
          Top = 0
          Action = ActionEditNeispr
        end
        object ToolButton20: TToolButton
          Left = 46
          Top = 0
          Action = ActionDeleteNeispr
        end
        object ToolButton2: TToolButton
          Left = 69
          Top = 0
          Width = 435
          Caption = 'ToolButton2'
          ImageIndex = 3
          Style = tbsSeparator
        end
        object ToolButtonAddProducerNeispr: TToolButton
          Left = 504
          Top = 0
          Caption = 'ToolButtonAddProducerNeispr'
          ImageIndex = 0
          OnClick = ToolButtonAddProducerNeisprClick
        end
        object ToolButtonEditProducerNeispr: TToolButton
          Left = 527
          Top = 0
          Caption = 'ToolButtonEditProducerNeispr'
          ImageIndex = 1
        end
        object ToolButtonDelProducerneispr: TToolButton
          Left = 550
          Top = 0
          Caption = 'ToolButtonDelProducerneispr'
          ImageIndex = 2
          OnClick = ToolButtonDelProducerneisprClick
        end
      end
      object Panel7: TPanel
        Left = 0
        Top = 163
        Width = 824
        Height = 65
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alBottom
        Caption = 'Panel7'
        TabOrder = 4
        object NeisprcxDBMemo: TcxDBMemo
          Left = 1
          Top = 1
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Align = alLeft
          DataBinding.DataField = 'NEISPR_REM_Z'
          TabOrder = 0
          Height = 63
          Width = 559
        end
        object NeisprEngcxDBMemo: TcxDBMemo
          Left = 560
          Top = 1
          Margins.Left = 2
          Margins.Top = 2
          Margins.Right = 2
          Margins.Bottom = 2
          Align = alClient
          DataBinding.DataField = 'NEISPR_ENG_REM_Z_1'
          TabOrder = 1
          Height = 63
          Width = 263
        end
      end
      object cxGrid5: TcxGrid
        Left = 0
        Top = 100
        Width = 824
        Height = 63
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alClient
        TabOrder = 5
        object cxGrid5DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          object cxGrid5DBTableView1CODE_REM_SPRCOND_GRP: TcxGridDBColumn
            DataBinding.FieldName = 'CODE_REM_SPRCOND_GRP'
            Width = 29
          end
          object cxGrid5DBTableView1NAME_REM_SPRCOND_GRP: TcxGridDBColumn
            DataBinding.FieldName = 'NAME_REM_SPRCOND_GRP'
            Width = 163
          end
          object cxGrid5DBTableView1CODE_REM_SPRCONDITION: TcxGridDBColumn
            DataBinding.FieldName = 'CODE_REM_SPRCONDITION'
            Width = 42
          end
          object cxGrid5DBTableView1NAME_REM_SPRCONDITION: TcxGridDBColumn
            DataBinding.FieldName = 'NAME_REM_SPRCONDITION'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.OnButtonClick = cxGrid5DBTableView1NAME_REM_SPRCONDITIONPropertiesButtonClick
            Width = 194
          end
          object cxGrid5DBTableView1NAME_REM_SPRNEISPR_GRP: TcxGridDBColumn
            DataBinding.FieldName = 'NAME_REM_SPRNEISPR_GRP'
            Width = 194
          end
          object cxGrid5DBTableView1CODE_REM_SPRNEISPR: TcxGridDBColumn
            DataBinding.FieldName = 'CODE_REM_SPRNEISPR'
            Width = 30
          end
          object cxGrid5DBTableView1NAME_REM_SPRNEISPR: TcxGridDBColumn
            DataBinding.FieldName = 'NAME_REM_SPRNEISPR'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.OnButtonClick = cxGrid5DBTableView1NAME_REM_SPRNEISPRPropertiesButtonClick
            Width = 195
          end
        end
        object cxGrid5Level1: TcxGridLevel
          GridView = cxGrid5DBTableView1
        end
      end
    end
    object cxTabSheet10: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1044#1086#1087
      ImageIndex = 5
      object NameHardwarecxDBButtonEdit: TcxDBButtonEdit
        Left = 14
        Top = 41
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NAME_REM_SHARDWARE'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameHardwarecxDBButtonEditPropertiesButtonClick
        TabOrder = 0
        Width = 263
      end
      object cxLabel5: TcxLabel
        Left = 14
        Top = 20
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077':'
      end
      object SerNumcxDBLabel: TcxDBLabel
        Left = 16
        Top = 65
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'SERNUM_REM_SHARDWARE'
        Height = 17
        Width = 99
      end
      object SerNum2cxDBLabel: TcxDBLabel
        Left = 16
        Top = 87
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'SERNUM2_REM_SHARDWARE'
        Height = 17
        Width = 99
      end
      object cxLabel3: TcxLabel
        Left = 33
        Top = 167
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1050#1086#1084#1084#1077#1085#1090#1072#1088#1080#1081' '#1084#1072#1089#1090#1077#1088#1072':'
      end
      object KlientOtvetNaZaproscxDBImageComboBox: TcxDBImageComboBox
        Left = 435
        Top = 112
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxKlientOtvetNaZapros
        DataBinding.DataField = 'FL_KL_OTV_NA_ZAPROS_REM_Z'
        Properties.Items = <>
        TabOrder = 5
        Width = 196
      end
      object cxLabel7: TcxLabel
        Left = 340
        Top = 94
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1050#1083#1080#1077#1085#1090' '#1086#1090#1074#1077#1090#1080#1083' '#1085#1072' '#1079#1072#1087#1088#1086#1089':'
      end
      object TrebKonsultKlientacxDBImageComboBox: TcxDBImageComboBox
        Left = 435
        Top = 73
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxTrebKonsultKlienta
        DataBinding.DataField = 'FL_TREB_KONS_KL_REM_Z'
        Properties.Items = <>
        TabOrder = 7
        Width = 196
      end
      object cxLabel8: TcxLabel
        Left = 331
        Top = 52
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1058#1088#1077#1073#1091#1077#1090#1089#1103' '#1082#1086#1085#1089#1091#1083#1100#1090#1072#1094#1080#1103', '#1089#1086#1075#1083#1072#1089#1086#1074#1072#1085#1080#1077' '#1082#1083#1080#1077#1085#1090#1072':'
      end
      object KlientUvedomlencxDBImageComboBox: TcxDBImageComboBox
        Left = 435
        Top = 34
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxKlientUvedomlen
        DataBinding.DataField = 'FL_KLIENT_UVEDOML_REM_Z'
        Properties.Items = <>
        TabOrder = 9
        Width = 196
      end
      object cxLabel6: TcxLabel
        Left = 331
        Top = 13
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1050#1083#1080#1077#1085#1090' '#1091#1074#1077#1076#1086#1084#1083#1077#1085' '#1086' '#1075#1086#1090#1086#1074#1085#1086#1089#1090#1080', '#1074#1099#1087#1086#1083#1085#1077#1085#1085#1099#1093' '#1088#1072#1073#1086#1090#1072#1093':'
      end
      object AddReportcxDBCheckBox: TcxDBCheckBox
        Left = 644
        Top = 76
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1086#1090#1095#1080#1090#1072#1085' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1102
        DataBinding.DataField = 'FL_ADDREPORT_REM_Z'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 11
        Width = 169
      end
      object CommentscxDBMemo: TcxDBMemo
        Left = 32
        Top = 189
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'COMENTS_REM_Z'
        TabOrder = 12
        Height = 68
        Width = 454
      end
      object cxDBDateEditPOS_ZAPROSA_NA_AKT_REM_Z_1: TcxDBDateEdit
        Left = 435
        Top = 149
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'POS_ZAPROSA_NA_AKT_REM_Z_1'
        Properties.Kind = ckDateTime
        TabOrder = 13
        Width = 196
      end
      object cxLabel18: TcxLabel
        Left = 309
        Top = 146
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1044#1072#1090#1072' '#1079#1072#1087#1088#1086#1089#1072' '#1085#1072' '#1072#1082#1090':'
      end
    end
    object cxTabSheet11: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1044#1086#1087'. '#1091#1089#1083#1091#1075#1080
      ImageIndex = 6
      object ToolBar4: TToolBar
        Left = 0
        Top = 0
        Width = 824
        Height = 29
        Caption = 'ToolBar4'
        Images = DM.ImageList1
        TabOrder = 0
        object ToolButton12: TToolButton
          Left = 0
          Top = 0
          Width = 17
          Caption = 'ToolButton12'
          ImageIndex = 3
          Style = tbsSeparator
        end
        object ToolButton8: TToolButton
          Left = 17
          Top = 0
          Action = ActionAddNewDopUsl
        end
        object ToolButton9: TToolButton
          Left = 40
          Top = 0
          Action = ActionEditNomDopUsl
        end
        object ToolButton11: TToolButton
          Left = 63
          Top = 0
          Action = ActionDeleteDopUsl
        end
      end
      object cxGrid3: TcxGrid
        Left = 0
        Top = 29
        Width = 824
        Height = 267
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alClient
        TabOrder = 1
        object cxGrid3DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          Styles.Header = DM.cxStyleHeaderTable
          object cxGrid3DBTableView1NAMENOM: TcxGridDBColumn
            Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
            DataBinding.FieldName = 'NAMENOM'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.ReadOnly = True
            Properties.OnButtonClick = cxGrid3DBTableView1NAMENOMPropertiesButtonClick
            Width = 317
          end
          object cxGrid3DBTableView1TEXTNOM_REM_ZDOPUSL: TcxGridDBColumn
            Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' ('#1090#1077#1082#1089#1090')'
            DataBinding.FieldName = 'TEXTNOM_REM_ZDOPUSL'
            PropertiesClassName = 'TcxTextEditProperties'
            Width = 288
          end
          object cxGrid3DBTableView1KOL_REM_ZDOPUSL: TcxGridDBColumn
            Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086
            DataBinding.FieldName = 'KOL_REM_ZDOPUSL'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 123
          end
          object cxGrid3DBTableView1NAMEED: TcxGridDBColumn
            Caption = #1045#1076#1080#1085#1080#1094#1072
            DataBinding.FieldName = 'NAMEED'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.ReadOnly = True
            Properties.OnButtonClick = cxGrid3DBTableView1NAMEEDPropertiesButtonClick
            Width = 117
          end
          object cxGrid3DBTableView1KF_REM_ZDOPUSL: TcxGridDBColumn
            Caption = #1050#1060
            DataBinding.FieldName = 'KF_REM_ZDOPUSL'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 87
          end
          object cxGrid3DBTableView1PRICE_REM_ZDOPUSL: TcxGridDBColumn
            Caption = #1062#1077#1085#1072
            DataBinding.FieldName = 'PRICE_REM_ZDOPUSL'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 136
          end
          object cxGrid3DBTableView1SUM_REM_ZDOPUSL: TcxGridDBColumn
            Caption = #1057#1091#1084#1084#1072
            DataBinding.FieldName = 'SUM_REM_ZDOPUSL'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 115
          end
        end
        object cxGrid3Level1: TcxGridLevel
          GridView = cxGrid3DBTableView1
        end
      end
    end
    object cxTabSheet12: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1042#1099#1087#1086#1083#1085#1077#1085#1099#1077' '#1088#1072#1073#1086#1090#1099', '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103
      ImageIndex = 7
      object ToolBar5: TToolBar
        Left = 0
        Top = 0
        Width = 824
        Height = 25
        Caption = 'ToolBar5'
        Images = DM.ImageList1
        TabOrder = 0
        object ToolButton13: TToolButton
          Left = 0
          Top = 0
          Action = ActionAddPerformedWork
        end
        object ToolButton14: TToolButton
          Left = 23
          Top = 0
          Action = ActionEditPerformedWork
        end
        object ToolButton15: TToolButton
          Left = 46
          Top = 0
          Action = ActionDeletePerformedWork
        end
      end
      object cxGrid4: TcxGrid
        Left = 0
        Top = 25
        Width = 824
        Height = 271
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Align = alClient
        TabOrder = 1
        object cxGrid4DBTableView1: TcxGridDBTableView
          NavigatorButtons.ConfirmDelete = False
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          OptionsView.CellAutoHeight = True
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          Styles.Header = DM.cxStyleHeaderTable
          object cxGrid4DBTableView1POS_REM_ZPERFWORK: TcxGridDBColumn
            Caption = #1044#1072#1090#1072
            DataBinding.FieldName = 'POS_REM_ZPERFWORK'
            PropertiesClassName = 'TcxDateEditProperties'
            Width = 131
          end
          object cxGrid4DBTableView1SHOWFORUSER_REM_ZPERFWORK: TcxGridDBColumn
            Caption = #1055#1086#1083#1100#1079'.'
            DataBinding.FieldName = 'SHOWFORUSER_REM_ZPERFWORK'
            PropertiesClassName = 'TcxCheckBoxProperties'
            Properties.ValueChecked = 1
            Properties.ValueUnchecked = 0
            Width = 55
          end
          object cxGrid4DBTableView1ADDACT_REM_ZPERFWORK: TcxGridDBColumn
            Caption = #1040#1082#1090
            DataBinding.FieldName = 'ADDACT_REM_ZPERFWORK'
            PropertiesClassName = 'TcxCheckBoxProperties'
            Properties.ValueChecked = -1
            Properties.ValueUnchecked = 0
            Width = 69
          end
          object cxGrid4DBTableView1NAMENOM: TcxGridDBColumn
            Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072', '#1074#1099#1087#1086#1083#1085#1077#1085#1085#1099#1077' '#1088#1072#1073#1086#1090#1099
            DataBinding.FieldName = 'NAMENOM'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.OnButtonClick = cxGrid4DBTableView1NAMENOMPropertiesButtonClick
            Width = 228
          end
          object cxGrid4DBTableView1TEXTNOM_REM_ZPERFWORK: TcxGridDBColumn
            Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072' ('#1090#1077#1082#1089#1090'), '#1074#1099#1087#1086#1083#1085#1077#1085#1085#1099#1077' '#1088#1072#1073#1086#1090#1099
            DataBinding.FieldName = 'TEXTNOM_REM_ZPERFWORK'
            PropertiesClassName = 'TcxTextEditProperties'
            Width = 255
          end
          object cxGrid4DBTableView1KOL_REM_ZPERFWORK: TcxGridDBColumn
            Caption = #1050#1086#1083'.'
            DataBinding.FieldName = 'KOL_REM_ZPERFWORK'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 75
          end
          object cxGrid4DBTableView1NAMEED: TcxGridDBColumn
            Caption = #1045#1076#1080#1085#1080#1094#1072
            DataBinding.FieldName = 'NAMEED'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Kind = bkEllipsis
              end>
            Properties.OnButtonClick = cxGrid4DBTableView1NAMEEDPropertiesButtonClick
            Width = 77
          end
          object cxGrid4DBTableView1KF_REM_ZPERFWORK: TcxGridDBColumn
            Caption = #1050#1060
            DataBinding.FieldName = 'KF_REM_ZPERFWORK'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 52
          end
          object cxGrid4DBTableView1PRICE_REM_ZPERFWORK: TcxGridDBColumn
            Caption = #1062#1077#1085#1072
            DataBinding.FieldName = 'PRICE_REM_ZPERFWORK'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 64
          end
          object cxGrid4DBTableView1SUM_REM_ZPERFWORK: TcxGridDBColumn
            Caption = #1057#1091#1084#1084#1072
            DataBinding.FieldName = 'SUM_REM_ZPERFWORK'
            PropertiesClassName = 'TcxCalcEditProperties'
            Width = 72
          end
          object cxGrid4DBTableView1RESULT_REM_ZPERFWORK: TcxGridDBColumn
            Caption = #1056#1077#1079'.'
            DataBinding.FieldName = 'RESULT_REM_ZPERFWORK'
            PropertiesClassName = 'TcxCheckBoxProperties'
            Properties.ValueChecked = 1
            Properties.ValueUnchecked = 0
            Width = 50
          end
          object cxGrid4DBTableView1NAME_USER: TcxGridDBColumn
            Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1100
            DataBinding.FieldName = 'NAME_USER'
            PropertiesClassName = 'TcxLabelProperties'
            Width = 55
          end
        end
        object cxGrid4Level1: TcxGridLevel
          GridView = cxGrid4DBTableView1
        end
      end
    end
    object cxTabSheet13: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1053#1086#1074#1099#1077' '#1085#1086#1084#1077#1088#1072
      ImageIndex = 8
      object Label25: TLabel
        Left = 321
        Top = 30
        Width = 112
        Height = 13
        Caption = #1053#1086#1074#1099#1081' '#1043#1072#1088'. '#1076#1086#1082#1091#1084#1077#1085#1090':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label27: TLabel
        Left = 308
        Top = 56
        Width = 125
        Height = 13
        Caption = #1053#1086#1074#1099#1081' '#1089#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088':'
      end
      object Label28: TLabel
        Left = 300
        Top = 76
        Width = 134
        Height = 13
        Caption = #1053#1086#1074#1099#1081' '#1089#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088' 2:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label52: TLabel
        Left = 297
        Top = 109
        Width = 135
        Height = 13
        Caption = #1053#1086#1074#1099#1081' '#1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088' 3:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label53: TLabel
        Left = 297
        Top = 128
        Width = 135
        Height = 13
        Caption = #1053#1086#1074#1099#1081' '#1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088' 4:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label54: TLabel
        Left = 324
        Top = 180
        Width = 106
        Height = 13
        Caption = #1053#1086#1074#1099#1081'  '#1055#1072#1088#1090'. '#1085#1086#1084#1077#1088':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label55: TLabel
        Left = 340
        Top = 199
        Width = 90
        Height = 13
        Caption = #1053#1086#1074#1099#1081' Reference:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label56: TLabel
        Left = 326
        Top = 219
        Width = 109
        Height = 13
        Caption = #1053#1086#1074#1099#1081' Software code:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label57: TLabel
        Left = 320
        Top = 238
        Width = 113
        Height = 13
        Caption = #1053#1086#1074#1099#1081' Hardware code:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object IsmGarDoccxDBCheckBox: TcxDBCheckBox
        Left = 70
        Top = 33
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1080#1079#1084#1077#1085#1077#1085' '#1075#1072#1088'. '#1076#1086#1082#1091#1084#1077#1085#1090
        DataBinding.DataField = 'FL_ISM_GARDOC_REM_Z'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 0
        Width = 179
      end
      object IsmSerNumcxDBCheckBox: TcxDBCheckBox
        Left = 70
        Top = 54
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1080#1079#1084#1077#1085#1077#1085' '#1089#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088
        DataBinding.DataField = 'FL_ISM_SERNUM_REM_Z'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 1
        Width = 179
      end
      object IsmSerNum2cxDBCheckBox: TcxDBCheckBox
        Left = 70
        Top = 75
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1080#1079#1084#1077#1085#1077#1085' '#1089#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088' 2'
        DataBinding.DataField = 'FL_ISM_SERNUM2_REM_Z'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 2
        Width = 179
      end
      object NewSerNum2cxDBTextEdit: TcxDBTextEdit
        Left = 450
        Top = 77
        DataBinding.DataField = 'SERNUM2_NEW_REM_Z'
        TabOrder = 3
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 231
      end
      object NewSerNumcxDBTextEdit: TcxDBTextEdit
        Left = 449
        Top = 51
        DataBinding.DataField = 'SERNUM_NEW_REM_Z'
        TabOrder = 4
        OnKeyPress = SerNumcxDBTextEditKeyPress
        Width = 231
      end
      object NewNumGarDoccxDBTextEdit: TcxDBTextEdit
        Left = 450
        Top = 25
        DataBinding.DataField = 'NUM_GARDOC_NEW_REM_Z'
        TabOrder = 5
        OnKeyPress = ModelcxDBTextEditKeyPress
        Width = 230
      end
      object cxDBTextEditSERNUM3_NEW_REM_Z_1: TcxDBTextEdit
        Left = 450
        Top = 106
        DataBinding.DataField = 'SERNUM3_NEW_REM_Z_1'
        TabOrder = 6
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 231
      end
      object cxDBTextEditSERNUM4_NEW_REM_Z_1: TcxDBTextEdit
        Left = 450
        Top = 127
        DataBinding.DataField = 'SERNUM4_NEW_REM_Z_1'
        TabOrder = 7
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 231
      end
      object cxDBTextEditPARTNUM_NEW_REM_Z_1: TcxDBTextEdit
        Left = 450
        Top = 176
        DataBinding.DataField = 'PARTNUM_NEW_REM_Z_1'
        TabOrder = 8
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 263
      end
      object cxDBTextEditREFERENCE_NEW_REM_Z_1: TcxDBTextEdit
        Left = 450
        Top = 195
        DataBinding.DataField = 'REFERENCE_NEW_REM_Z_1'
        TabOrder = 9
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 263
      end
      object cxDBTextEditSWCODE_NEW_REM_Z_1: TcxDBTextEdit
        Left = 450
        Top = 215
        DataBinding.DataField = 'SWCODE_NEW_REM_Z_1'
        TabOrder = 10
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 263
      end
      object cxDBTextEditHWCODE_NEW_REM_Z_1: TcxDBTextEdit
        Left = 450
        Top = 234
        DataBinding.DataField = 'HWCODE_NEW_REM_Z_1'
        TabOrder = 11
        OnKeyPress = SerNum2cxDBTextEditKeyPress
        Width = 263
      end
      object cxDBCheckBoxFL_ISM_SERNUM3_REM_Z_1: TcxDBCheckBox
        Left = 70
        Top = 106
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1080#1079#1084#1077#1085#1077#1085' '#1089#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088' 3'
        DataBinding.DataField = 'FL_ISM_SERNUM3_REM_Z_1'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 12
        Width = 179
      end
      object cxDBCheckBoxFL_ISM_SERNUM4_REM_Z_1: TcxDBCheckBox
        Left = 70
        Top = 131
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1080#1079#1084#1077#1085#1077#1085' '#1089#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088' 4'
        DataBinding.DataField = 'FL_ISM_SERNUM4_REM_Z_1'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 13
        Width = 179
      end
      object cxDBCheckBoxFL_ISM_PARTNUM_REM_Z_1: TcxDBCheckBox
        Left = 70
        Top = 180
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1080#1079#1084#1077#1085#1077#1085' '#1087#1072#1088#1090'. '#1085#1086#1084#1077#1088
        DataBinding.DataField = 'FL_ISM_PARTNUM_REM_Z_1'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 14
        Width = 197
      end
      object cxDBCheckBoxFL_ISM_REFERENCE_REM_Z_1: TcxDBCheckBox
        Left = 70
        Top = 199
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1080#1079#1084#1077#1085#1077#1085' Reference'
        DataBinding.DataField = 'FL_ISM_REFERENCE_REM_Z_1'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 15
        Width = 179
      end
      object cxDBCheckBoxFL_ISM_SWCODE_REM_Z_1: TcxDBCheckBox
        Left = 70
        Top = 219
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1080#1079#1084#1077#1085#1077#1085' Softwarecode'
        DataBinding.DataField = 'FL_ISM_SWCODE_REM_Z_1'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 16
        Width = 197
      end
      object cxDBCheckBoxFL_ISM_HWCODE_REM_Z_1: TcxDBCheckBox
        Left = 70
        Top = 238
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1080#1079#1084#1077#1085#1077#1085' Hardwarecode'
        DataBinding.DataField = 'FL_ISM_HWCODE_REM_Z_1'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 17
        Width = 179
      end
    end
    object cxTabSheet1: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1057#1083#1091#1078#1077#1073#1085#1072#1103' '#1080#1085#1092'.'
      ImageIndex = 9
      object Label7: TLabel
        Left = 15
        Top = 107
        Width = 66
        Height = 13
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
      end
      object Label4: TLabel
        Left = 40
        Top = 20
        Width = 107
        Height = 13
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1055#1088#1086#1073#1083#1077#1084#1085#1099#1081' '#1082#1083#1080#1077#1085#1090':'
      end
      object Label5: TLabel
        Left = 15
        Top = 54
        Width = 127
        Height = 13
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1055#1088#1086#1073#1083#1077#1084#1085#1086#1077' '#1091#1089#1090#1088#1086#1081#1089#1090#1074#1086':'
      end
      object Label31: TLabel
        Left = 19
        Top = 179
        Width = 78
        Height = 13
        Caption = #1044#1077#1092#1077#1082#1090' ('#1072#1085#1075#1083'.):'
      end
      object Label32: TLabel
        Left = 15
        Top = 224
        Width = 83
        Height = 13
        Caption = #1056#1077#1096#1077#1085#1080#1077' ('#1072#1085#1075#1083'.):'
      end
      object FlProblemKlientcxDBImageComboBox: TcxDBImageComboBox
        Left = 177
        Top = 17
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItem_REM_FL_PROBLEM_KLIENT
        DataBinding.DataField = 'FL_PROBLEM_KLIENT_REM_Z_1'
        Properties.Items = <>
        TabOrder = 0
        Width = 273
      end
      object FictivcxDBCheckBox: TcxDBCheckBox
        Left = 548
        Top = 13
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1092#1080#1082#1090#1080#1074#1085#1072#1103
        DataBinding.DataField = 'FL_FICTIV_REM_Z'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 1
        Width = 169
      end
      object flNeOtchcxDBCheckBox: TcxDBCheckBox
        Left = 548
        Top = 37
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1085#1077' '#1086#1090#1095#1080#1090#1099#1074#1072#1090#1100
        DataBinding.DataField = 'FL_NE_OTCH_REM_Z'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 2
        Width = 105
      end
      object flNadoOtchcxDBCheckBox: TcxDBCheckBox
        Left = 548
        Top = 62
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1085#1072#1076#1086' '#1086#1090#1095#1080#1090#1072#1090#1100
        DataBinding.DataField = 'FL_NADO_OTCH_REM_Z'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 3
        Width = 119
      end
      object DescrcxDBMemo: TcxDBMemo
        Left = 127
        Top = 107
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'DESCR_REM_Z'
        TabOrder = 4
        Height = 63
        Width = 433
      end
      object FlProblemDevicecxDBImageComboBox: TcxDBImageComboBox
        Left = 177
        Top = 52
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItem_REM_FL_PROBLEM_DEVICE
        DataBinding.DataField = 'FL_PROBLEM_DEVICE_REM_Z_1'
        Properties.Items = <>
        TabOrder = 5
        Width = 272
      end
      object DefectEngcxDBMemo: TcxDBMemo
        Left = 127
        Top = 175
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'DEFECT_ENG_REM_Z_1'
        TabOrder = 6
        Height = 40
        Width = 433
      end
      object SolutionEngcxDBMemo: TcxDBMemo
        Left = 127
        Top = 220
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'SOLUTION_ENG_REM_Z_1'
        TabOrder = 7
        Height = 41
        Width = 433
      end
      object ViborTypDefectcxButton: TcxButton
        Left = 576
        Top = 175
        Width = 141
        Height = 24
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1048#1079' '#1089#1087#1088'. '#1090#1080#1087'. '#1076#1077#1092#1077#1082#1090#1086#1074
        TabOrder = 8
        OnClick = ViborTypDefectcxButtonClick
      end
      object VibortyprabotcxButton: TcxButton
        Left = 579
        Top = 220
        Width = 138
        Height = 25
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1048#1079' '#1089#1087#1088'. '#1090#1080#1087'. '#1088#1072#1073#1086#1090
        TabOrder = 9
        OnClick = VibortyprabotcxButtonClick
      end
    end
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 67
    Width = 827
    Height = 102
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    Align = alTop
    Caption = #1056#1077#1084#1086#1085#1090
    TabOrder = 4
    object ModelcxDBLabel: TcxDBLabel
      Left = 16
      Top = 41
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'MODEL_REM_Z'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -15
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
      Height = 25
      Width = 355
    end
    object SerNumber1cxDBLabel: TcxDBLabel
      Left = 464
      Top = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'SERNUM_REM_Z'
      Height = 17
      Width = 187
    end
    object SerNumber2cxDBLabel: TcxDBLabel
      Left = 662
      Top = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'SERNUM2_REM_Z'
      Height = 17
      Width = 145
    end
    object NameKlientcxDBLabel: TcxDBLabel
      Left = 376
      Top = 34
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      AutoSize = True
      DataBinding.DataField = 'KLIENT_NAME_REM_Z'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
    end
    object NameDilercxDBLabel: TcxDBLabel
      Left = 376
      Top = 48
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      AutoSize = True
      DataBinding.DataField = 'NAMEDILER'
    end
    object SostcxDBLabel: TcxDBLabel
      Left = 14
      Top = 71
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'NAME_REMSSOST'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -15
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
      Height = 22
      Width = 357
    end
    object NeisprcxDBLabel: TcxDBLabel
      Left = 376
      Top = 68
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      AutoSize = True
      DataBinding.DataField = 'NEISPR_REM_Z'
    end
    object TypeRemontcxDBLabel: TcxDBLabel
      Left = 10
      Top = 20
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      DataBinding.DataField = 'NAME_STREMONT'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -11
      Style.Font.Name = 'MS Sans Serif'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
      Height = 17
      Width = 136
    end
    object SostDevicecxDBLabel: TcxDBLabel
      Left = 376
      Top = 81
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      AutoSize = True
      DataBinding.DataField = 'SOST_REM_Z'
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 56
    Top = 256
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
      OnExecute = ActionAddNewKomplExecute
    end
    object ActionEditKompl: TAction
      Caption = 'ActionEditKompl'
      ImageIndex = 1
      OnExecute = ActionEditKomplExecute
    end
    object ActionAddNeispr: TAction
      Caption = 'ActionAddNeispr'
      ImageIndex = 0
      OnExecute = ActionAddNeisprExecute
    end
    object ActionEditNeispr: TAction
      Caption = 'ActionEditNeispr'
      ImageIndex = 1
      OnExecute = ActionEditNeisprExecute
    end
    object ActionDeleteKompl: TAction
      Caption = 'ActionDeleteKompl'
      ImageIndex = 2
      OnExecute = ActionDeleteKomplExecute
    end
    object ActionDeleteNeispr: TAction
      Caption = 'ActionDeleteNeispr'
      ImageIndex = 2
      OnExecute = ActionDeleteNeisprExecute
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
      OnExecute = ActionAddNewDopUslExecute
    end
    object ActionDeleteDopUsl: TAction
      Caption = 'ActionDeleteDopUsl'
      ImageIndex = 2
      OnExecute = ActionDeleteDopUslExecute
    end
    object ActionEditNomDopUsl: TAction
      Caption = 'ActionEditNomDopUsl'
      ImageIndex = 1
    end
    object ActionAddPerformedWork: TAction
      Caption = 'ActionAddPerformedWork'
      ImageIndex = 0
      OnExecute = ActionAddPerformedWorkExecute
    end
    object ActionDeletePerformedWork: TAction
      Caption = 'ActionDeletePerformedWork'
      ImageIndex = 2
      OnExecute = ActionDeletePerformedWorkExecute
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
  object PopupMenuAddKompl: TPopupMenu
    Left = 104
    Top = 256
    object N1: TMenuItem
      Caption = 
        #1058#1077#1083#1077#1092#1086#1085', '#1079#1072#1076#1085#1103#1103' '#1082#1088#1099#1096#1082#1072', '#1043#1058','#1095#1077#1082', '#1047#1059', '#1082#1072#1073#1077#1083#1100', '#1075#1072#1088#1085#1080#1090#1091#1088#1072', '#1088#1091#1082#1086#1074#1086#1076#1089#1090 +
        #1074#1086', '#1082#1086#1088#1086#1073#1082#1072', '#1072#1082#1073
      OnClick = AddComplClick
    end
    object N2: TMenuItem
      Caption = #1058#1077#1083#1077#1092#1086#1085', '#1079#1072#1076#1085#1103#1103' '#1082#1088#1099#1096#1082#1072', '#1043#1058','#1095#1077#1082', '#1047#1059', '#1082#1072#1073#1077#1083#1100', '#1072#1082#1073
      OnClick = AddComplClick
    end
    object N3: TMenuItem
      Caption = #1058#1077#1083#1077#1092#1086#1085', '#1079#1072#1076#1085#1103#1103' '#1082#1088#1099#1096#1082#1072', '#1043#1058','#1095#1077#1082', '#1072#1082#1073
      OnClick = AddComplClick
    end
    object N4: TMenuItem
      Caption = #1058#1077#1083#1077#1092#1086#1085', '#1079#1072#1076#1085#1103#1103' '#1082#1088#1099#1096#1082#1072', '#1043#1058', '#1072#1082#1073
      OnClick = AddComplClick
    end
    object N5: TMenuItem
      Caption = #1058#1077#1083#1077#1092#1086#1085', '#1041#1045#1047' '#1079#1072#1076#1085#1077#1081' '#1082#1088#1099#1096#1082#1080', '#1043#1058','#1095#1077#1082', '#1072#1082#1073
      OnClick = AddComplClick
    end
    object N6: TMenuItem
      Caption = #1058#1077#1083#1077#1092#1086#1085', '#1041#1045#1047' '#1079#1072#1076#1085#1077#1081' '#1082#1088#1099#1096#1082#1080', '#1043#1058', '#1072#1082#1073
      OnClick = AddComplClick
    end
    object N7: TMenuItem
      Caption = #1058#1077#1083#1077#1092#1086#1085', '#1079#1072#1076#1085#1103#1103' '#1082#1088#1099#1096#1082#1072', '#1072#1082#1073
      OnClick = AddComplClick
    end
    object N8: TMenuItem
      Caption = #1058#1077#1083#1077#1092#1086#1085', '#1079#1072#1076#1085#1103#1103' '#1082#1088#1099#1096#1082#1072', '#1047#1059', '#1082#1072#1073#1077#1083#1100', '#1072#1082#1073
      OnClick = AddComplClick
    end
    object N9: TMenuItem
      Caption = #1058#1077#1083#1077#1092#1086#1085', '#1041#1045#1047' '#1079#1072#1076#1085#1077#1081' '#1082#1088#1099#1096#1082#1080', '#1072#1082#1073
      OnClick = AddComplClick
    end
  end
end
