object FormaDocPlatPor: TFormaDocPlatPor
  Left = 392
  Top = 109
  Caption = #1055#1083#1072#1090#1077#1078#1085#1086#1077' '#1087#1086#1088#1091#1095#1077#1085#1080#1077
  ClientHeight = 606
  ClientWidth = 564
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
    Top = 528
    Width = 564
    Height = 78
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object DBTextFNameUser: TDBText
      Left = 10
      Top = 58
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
      Left = 404
      Top = 58
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
    object cxButtonSave: TcxButton
      Left = 155
      Top = 20
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionSave
      TabOrder = 0
    end
    object cxButtonOK: TcxButton
      Left = 354
      Top = 20
      Width = 93
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionOK
      TabOrder = 1
    end
    object cxButtonClose: TcxButton
      Left = 454
      Top = 20
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 2
    end
    object cxButtonDvReg: TcxButton
      Left = 255
      Top = 20
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionDvReg
      TabOrder = 3
    end
    object cxButtonPrint: TcxButton
      Left = 55
      Top = 20
      Width = 93
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 4
    end
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 30
    Width = 564
    Height = 498
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = TabSheet1
    Align = alClient
    Style = tsFlatButtons
    TabOrder = 1
    object TabSheet1: TTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      object Label17: TLabel
        Left = 178
        Top = 128
        Width = 132
        Height = 26
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1087#1086#1088#1091#1095#1077#1085#1080#1077' '#8470
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -23
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label11: TLabel
        Left = 75
        Top = 33
        Width = 47
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1060#1080#1088#1084#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label16: TLabel
        Left = 91
        Top = 57
        Width = 35
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1095#1077#1090':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label10: TLabel
        Left = 342
        Top = 154
        Width = 28
        Height = 26
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1086#1090' '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -23
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label9: TLabel
        Left = 56
        Top = 128
        Width = 114
        Height = 26
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1083#1072#1090#1077#1078#1085#1086#1077
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -23
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label13: TLabel
        Left = 8
        Top = 191
        Width = 111
        Height = 24
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -18
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label18: TLabel
        Left = 25
        Top = 228
        Width = 35
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1095#1077#1090':'
      end
      object Label20: TLabel
        Left = 4
        Top = 303
        Width = 87
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1042#1080#1076' '#1087#1083#1072#1090#1077#1078#1072':'
      end
      object Label19: TLabel
        Left = 291
        Top = 322
        Width = 94
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1088#1086#1082' '#1087#1083#1072#1090#1077#1078#1072':'
      end
      object Label24: TLabel
        Left = 19
        Top = 378
        Width = 149
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1054#1095#1077#1088#1077#1076#1085#1086#1089#1090#1100' '#1087#1083#1072#1090#1077#1078#1072':'
      end
      object Label23: TLabel
        Left = 21
        Top = 406
        Width = 144
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1072#1079#1085#1072#1095#1077#1085#1080#1077' '#1087#1083#1072#1090#1077#1078#1072':'
      end
      object Label21: TLabel
        Left = 319
        Top = 376
        Width = 63
        Height = 24
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1057#1091#1084#1084#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -18
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 184
        Top = 266
        Width = 68
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1054#1087#1077#1088#1072#1094#1080#1103':'
      end
      object ToolBar1: TToolBar
        Left = 357
        Top = 320
        Width = 236
        Height = 22
        Align = alNone
        ButtonWidth = 75
        Caption = 'ToolBar1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        List = True
        ParentFont = False
        ShowCaptions = True
        TabOrder = 15
        TabStop = True
        Transparent = False
        object ToolButton1: TToolButton
          Left = 0
          Top = 0
          Caption = #1044#1086#1073#1072#1074#1080#1090#1100
          DropdownMenu = PopupMenu1
          ImageIndex = 0
        end
      end
      object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
        Left = 134
        Top = 4
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
        Width = 393
      end
      object NameFirmcxDBButtonEdit: TcxDBButtonEdit
        Left = 134
        Top = 30
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
        Width = 393
      end
      object NameBSchetcxDBButtonEdit: TcxDBButtonEdit
        Left = 134
        Top = 56
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMEBSCHET'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameBSchetcxDBButtonEditPropertiesButtonClick
        TabOrder = 2
        Width = 393
      end
      object cxLabel1: TcxLabel
        Left = 52
        Top = 4
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
      end
      object PosDoccxDBDateEdit: TcxDBDateEdit
        Left = 382
        Top = 158
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'POSDOC'
        Properties.Kind = ckDateTime
        TabOrder = 7
        OnKeyDown = PosDoccxDBDateEditKeyDown
        Width = 149
      end
      object NumDoccxDBTextEdit: TcxDBTextEdit
        Left = 240
        Top = 158
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NUMDOC'
        TabOrder = 6
        OnKeyDown = NumDoccxDBTextEditKeyDown
        Width = 95
      end
      object NameKlientcxDBButtonEdit: TcxDBButtonEdit
        Left = 134
        Top = 191
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
        TabOrder = 8
        Width = 393
      end
      object NameRSchetcxDBButtonEdit: TcxDBButtonEdit
        Left = 134
        Top = 225
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMERSCHET'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = cxDBButtonEdit1PropertiesButtonClick
        TabOrder = 9
        Width = 393
      end
      object VidPlat: TcxComboBox
        Left = 134
        Top = 316
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Properties.Items.Strings = (
          #1069#1083#1077#1082#1090#1088#1086#1085#1085#1086
          #1058#1077#1083#1077#1075#1088#1072#1092#1086#1084
          #1055#1086#1095#1090#1086#1081)
        Properties.OnChange = VidPlatPropertiesChange
        TabOrder = 11
        Text = 'VidPlat'
        Width = 149
      end
      object SrokPlatcxDBDateEdit: TcxDBDateEdit
        Left = 382
        Top = 316
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'SROKPLP'
        TabOrder = 12
        OnKeyDown = SrokPlatcxDBDateEditKeyDown
        Width = 144
      end
      object SumDoccxDBCalcEdit: TcxDBCalcEdit
        Left = 383
        Top = 375
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'SUMDOC'
        TabOrder = 14
        OnKeyDown = SumDoccxDBCalcEditKeyDown
        Width = 144
      end
      object OchercxDBTextEdit: TcxDBTextEdit
        Left = 168
        Top = 375
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'OCHPLP'
        TabOrder = 13
        OnKeyDown = OchercxDBTextEditKeyDown
        Width = 51
      end
      object NasnPlatcxDBTextEdit: TcxDBTextEdit
        Left = 24
        Top = 430
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NASNPLP'
        TabOrder = 17
        OnKeyDown = NasnPlatcxDBTextEditKeyDown
        Width = 503
      end
      object OperationcxDBImageComboBox: TcxDBImageComboBox
        Left = 260
        Top = 263
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItemBankOperation
        DataBinding.DataField = 'OPERATIONPLP'
        Properties.Items = <>
        TabOrder = 10
        Width = 267
      end
      object cxLabel9: TcxLabel
        Left = 125
        Top = 86
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
      end
      object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
        Left = 255
        Top = 108
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
      object NameProjectcxDBButtonEdit: TcxDBButtonEdit
        Left = 255
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
      object cxLabel3: TcxLabel
        Left = 191
        Top = 109
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1086#1077#1082#1090':'
      end
      object PrefiksNumcxDBTextEdit: TcxDBTextEdit
        Left = 87
        Top = 158
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'PREFIKS_NUM_GALLDOC'
        TabOrder = 5
        Width = 145
      end
    end
    object TabSheet2: TTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1077#1088#1077#1095#1080#1089#1083#1077#1085#1080#1077' '#1085#1072#1083#1086#1075#1072
      ImageIndex = 1
      object Label3: TLabel
        Left = 14
        Top = 38
        Width = 401
        Height = 42
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        AutoSize = False
        Caption = 
          #1057#1090#1072#1090#1091#1089' '#1089#1086#1089#1090#1072#1074#1080#1090#1077#1083#1103' '#1087#1083#1072#1090#1077#1078#1085#1086#1075#1086' '#1076#1086#1082#1091#1084#1077#1085#1090#1072' '#1085#1072' '#1087#1077#1088#1077#1095#1080#1089#1083#1077#1085#1080#1077' '#1085#1072#1083#1086#1075#1086#1074',' +
          ' '#1089#1073#1086#1088#1086#1074' '#1080' '#1080#1085#1099#1093' '#1086#1073#1103#1079#1072#1090#1077#1083#1100#1085#1099#1093' '#1087#1083#1072#1090#1077#1078#1077#1081':'
        WordWrap = True
      end
      object Label4: TLabel
        Left = 14
        Top = 87
        Width = 369
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1059#1089#1083#1086#1074#1085#1086#1077' '#1086#1073#1086#1079#1085#1072#1095#1077#1085#1080#1077' '#1086#1089#1085#1086#1074#1072#1085#1080#1103' '#1085#1072#1083#1086#1075#1086#1074#1086#1075#1086' '#1087#1083#1072#1090#1077#1078#1072':'
      end
      object Label5: TLabel
        Left = 14
        Top = 129
        Width = 204
        Height = 58
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        AutoSize = False
        Caption = 
          #1053#1086#1084#1077#1088' '#1076#1086#1082#1091#1084#1077#1085#1090#1072' - '#1086#1089#1085#1086#1074#1072#1085#1080#1103' '#1087#1077#1088#1077#1095#1080#1089#1083#1077#1085#1080#1103'  '#1085#1072#1083#1086#1075#1072', '#1089#1073#1086#1088#1072' '#1080#1083#1080' '#1080#1085#1086#1075 +
          #1086' '#1087#1083#1072#1090#1077#1078#1072':'
        WordWrap = True
      end
      object Label6: TLabel
        Left = 14
        Top = 210
        Width = 330
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1059#1089#1083#1086#1074#1085#1086#1077' '#1086#1073#1086#1079#1085#1072#1095#1077#1085#1080#1077' '#1090#1080#1087#1072' '#1085#1072#1083#1086#1075#1086#1074#1086#1075#1086' '#1087#1083#1072#1090#1077#1078#1072':'
      end
      object Label7: TLabel
        Left = 14
        Top = 260
        Width = 290
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1076' '#1073#1102#1076#1078#1077#1090#1085#1086#1081' '#1082#1083#1072#1089#1089#1080#1092#1080#1082#1072#1094#1080#1080' '#1076#1086#1093#1086#1076#1086#1074' '#1056#1060':'
      end
      object Label8: TLabel
        Left = 14
        Top = 303
        Width = 209
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1086#1076' '#1054#1050#1040#1058#1054' '#1089#1073#1086#1088#1097#1080#1082#1072' '#1087#1083#1072#1090#1077#1078#1077#1081':'
      end
      object Label15: TLabel
        Left = 14
        Top = 332
        Width = 339
        Height = 34
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        AutoSize = False
        Caption = #1059#1089#1083#1086#1074#1085#1086#1077' '#1086#1073#1086#1079#1085#1072#1095#1077#1085#1080#1077' '#1087#1077#1088#1080#1086#1076#1072', '#1079#1072' '#1082#1086#1090#1086#1088#1099#1081' '#1087#1077#1088#1077#1095#1080#1089#1083#1103#1077#1090#1089#1103' '#1085#1072#1083#1086#1075':'
        WordWrap = True
      end
      object Label12: TLabel
        Left = 14
        Top = 384
        Width = 339
        Height = 41
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        AutoSize = False
        Caption = 
          #1044#1072#1090#1072' '#1076#1086#1082#1091#1084#1077#1085#1090#1072' - '#1086#1089#1085#1086#1074#1072#1085#1080#1103' '#1087#1077#1088#1077#1095#1080#1089#1083#1077#1085#1080#1103'  '#1085#1072#1083#1086#1075#1072', '#1089#1073#1086#1088#1072' '#1080#1083#1080' '#1080#1085#1086#1075#1086 +
          ' '#1087#1083#1072#1090#1077#1078#1072':'
        WordWrap = True
      end
      object NalStatuscxDBTextEdit: TcxDBTextEdit
        Left = 441
        Top = 34
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NALOG_STATUS_PLP'
        TabOrder = 0
        OnKeyDown = NalStatuscxDBTextEditKeyDown
        Width = 67
      end
      object NalOsncxDBTextEdit: TcxDBTextEdit
        Left = 441
        Top = 84
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NALOG_OSN_PLP'
        TabOrder = 1
        OnKeyDown = NalOsncxDBTextEditKeyDown
        Width = 67
      end
      object NalNumcxDBTextEdit: TcxDBTextEdit
        Left = 217
        Top = 148
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NALOG_NUM_PLP'
        TabOrder = 2
        OnKeyDown = NalNumcxDBTextEditKeyDown
        Width = 291
      end
      object NalTPlatcxDBTextEdit: TcxDBTextEdit
        Left = 468
        Top = 207
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NALOG_TPLAT_PLP'
        TabOrder = 3
        OnKeyDown = NalTPlatcxDBTextEditKeyDown
        Width = 40
      end
      object NalKBKcxDBTextEdit: TcxDBTextEdit
        Left = 389
        Top = 256
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NALOG_KBK_PLP'
        TabOrder = 4
        OnKeyDown = NalKBKcxDBTextEditKeyDown
        Width = 119
      end
      object NalOKATOcxDBTextEdit: TcxDBTextEdit
        Left = 361
        Top = 303
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NALOG_OKATO_PLP'
        TabOrder = 5
        OnKeyDown = NalOKATOcxDBTextEditKeyDown
        Width = 147
      end
      object NalPeriodcxDBTextEdit: TcxDBTextEdit
        Left = 361
        Top = 354
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NALOG_PERIOD_PLP'
        TabOrder = 6
        OnKeyDown = NalPeriodcxDBTextEditKeyDown
        Width = 147
      end
      object NalDatecxDBDateEdit: TcxDBDateEdit
        Left = 361
        Top = 401
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NALOG_DATE_PLP'
        TabOrder = 7
        OnKeyDown = NalDatecxDBDateEditKeyDown
        Width = 149
      end
    end
  end
  object ToolBar2: TToolBar
    Left = 0
    Top = 0
    Width = 564
    Height = 30
    Color = clBtnFace
    EdgeBorders = [ebTop, ebRight, ebBottom]
    Images = DM.ImageList1
    ParentColor = False
    TabOrder = 2
    object ToolButton2: TToolButton
      Left = 0
      Top = 0
      Width = 17
      Caption = 'ToolButton1'
      Style = tbsSeparator
    end
    object ToolButton3: TToolButton
      Left = 17
      Top = 0
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 0
      Style = tbsSeparator
    end
    object ToolButtonExtModule: TToolButton
      Left = 25
      Top = 0
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
      Caption = 'ToolButtonExtModule'
      DropdownMenu = PopupMenuExtModule
      ImageIndex = 51
      ParentShowHint = False
      ShowHint = True
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 232
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
  object PopupMenu1: TPopupMenu
    Left = 272
    Top = 424
    object N1: TMenuItem
      Caption = #1089#1091#1084#1084#1091
      OnClick = N1Click
    end
    object N181: TMenuItem
      Caption = #1089#1091#1084#1084#1091' '#1080' '#1053#1044#1057' 18%'
      OnClick = N181Click
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 56
    Top = 16
  end
end
