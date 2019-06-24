object FormaDocPKORozn: TFormaDocPKORozn
  Left = 264
  Top = 122
  Caption = #1055#1088#1080#1093#1086#1076' '#1085#1072#1083'.'
  ClientHeight = 572
  ClientWidth = 581
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
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 30
    Width = 581
    Height = 464
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    ActivePage = cxTabSheet1
    Align = alClient
    TabOrder = 0
    ClientRectBottom = 464
    ClientRectRight = 581
    ClientRectTop = 27
    object cxTabSheet1: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 0
      object Label12: TLabel
        Left = 86
        Top = 32
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
      object Label15: TLabel
        Left = 92
        Top = 56
        Width = 41
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1072#1089#1089#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 384
        Top = 136
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
      object Label3: TLabel
        Left = 39
        Top = 111
        Width = 150
        Height = 26
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1080#1093#1086#1076' '#1085#1072#1083'. '#8470
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -23
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label14: TLabel
        Left = 10
        Top = 180
        Width = 110
        Height = 24
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1086#1082#1091#1087#1072#1090#1077#1083#1100':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -18
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label1: TLabel
        Left = 49
        Top = 219
        Width = 55
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1044#1086#1075#1086#1074#1086#1088
      end
      object Label7: TLabel
        Left = 375
        Top = 399
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
      object Label4: TLabel
        Left = 30
        Top = 289
        Width = 74
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1080#1085#1103#1090#1086' '#1086#1090
      end
      object Label5: TLabel
        Left = 30
        Top = 325
        Width = 76
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1054#1089#1085#1086#1074#1072#1085#1080#1077':'
      end
      object Label6: TLabel
        Left = 30
        Top = 354
        Width = 86
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
      end
      object Label9: TLabel
        Left = 39
        Top = 398
        Width = 68
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1054#1087#1077#1088#1072#1094#1080#1103':'
      end
      object Label8: TLabel
        Left = 63
        Top = 255
        Width = 42
        Height = 16
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1050#1072#1088#1090#1072':'
      end
      object SumDoccxDBCalcEdit: TcxDBCalcEdit
        Left = 439
        Top = 394
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'SUMDOC'
        TabOrder = 14
        OnKeyDown = SumDoccxDBCalcEditKeyDown
        Width = 114
      end
      object PrimcxDBTextEdit: TcxDBTextEdit
        Left = 118
        Top = 354
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'PRIM_DPKOROZN'
        TabOrder = 13
        OnKeyDown = PrimcxDBTextEditKeyDown
        Width = 435
      end
      object OsncxDBTextEdit: TcxDBTextEdit
        Left = 118
        Top = 321
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'OSN_DPKOROZN'
        TabOrder = 12
        OnKeyDown = OsncxDBTextEditKeyDown
        Width = 432
      end
      object PrOtcxDBTextEdit: TcxDBTextEdit
        Left = 118
        Top = 288
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'PROT_DPKOROZN'
        TabOrder = 11
        OnKeyDown = PrOtcxDBTextEditKeyDown
        Width = 432
      end
      object NameDogovorcxDBButtonEdit: TcxDBButtonEdit
        Left = 118
        Top = 215
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
        Properties.OnButtonClick = nameDogovorcxDBButtonEditPropertiesButtonClick
        TabOrder = 9
        Width = 430
      end
      object NameKlientcxDBButtonEdit: TcxDBButtonEdit
        Left = 118
        Top = 182
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
        Width = 430
      end
      object NumDoccxDBTextEdit: TcxDBTextEdit
        Left = 227
        Top = 141
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NUMDOC'
        TabOrder = 6
        OnKeyDown = NumDoccxDBTextEditKeyDown
        Width = 149
      end
      object PosDoccxDBDateEdit: TcxDBDateEdit
        Left = 418
        Top = 141
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'POSDOC'
        Properties.Kind = ckDateTime
        TabOrder = 7
        OnKeyDown = PosDoccxDBDateEditKeyDown
        Width = 148
      end
      object NameKKMcxDBButtonEdit: TcxDBButtonEdit
        Left = 141
        Top = 53
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAMEKKM'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ClickKey = 13
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameKKMcxDBButtonEditPropertiesButtonClick
        TabOrder = 2
        Width = 404
      end
      object NameFirmcxDBButtonEdit: TcxDBButtonEdit
        Left = 141
        Top = 28
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
        Width = 404
      end
      object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
        Left = 141
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
        Width = 404
      end
      object cxLabel6: TcxLabel
        Left = 59
        Top = 4
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
      end
      object OpercxDBImageComboBox: TcxDBImageComboBox
        Left = 118
        Top = 394
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItemKassaOperation
        DataBinding.DataField = 'OPERATION_DPKOROZN'
        Properties.Items = <>
        TabOrder = 16
        Width = 195
      end
      object NameCardcxDBButtonEdit: TcxDBButtonEdit
        Left = 118
        Top = 249
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NAME_SDISCOUNT_CARD'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = NameCardcxDBButtonEditPropertiesButtonClick
        TabOrder = 10
        Width = 430
      end
      object cxLabel9: TcxLabel
        Left = 151
        Top = 83
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
      end
      object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
        Left = 273
        Top = 82
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
        Left = 273
        Top = 108
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
      object cxLabel7: TcxLabel
        Left = 217
        Top = 109
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1055#1088#1086#1077#1082#1090':'
      end
      object PrefiksNumcxDBTextEdit: TcxDBTextEdit
        Left = 74
        Top = 141
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'PREFIKS_NUM_GALLDOC'
        TabOrder = 5
        Width = 145
      end
    end
    object cxTabSheet2: TcxTabSheet
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1050#1050#1052
      ImageIndex = 1
      object cxButtonprintCheckNaFR: TcxButton
        Left = 17
        Top = 23
        Width = 93
        Height = 31
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1063#1077#1082' '#1085#1072' '#1060#1056
        TabOrder = 0
        OnClick = cxButtonprintCheckNaFRClick
      end
      object cxLabel1: TcxLabel
        Left = 315
        Top = 27
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1052#1086#1076#1077#1083#1100':'
      end
      object cxLabel2: TcxLabel
        Left = 252
        Top = 60
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1047#1072#1074#1086#1076#1089#1082#1086#1081' '#1085#1086#1084#1077#1088':'
      end
      object cxLabel3: TcxLabel
        Left = 294
        Top = 94
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1056#1077#1075'. '#1085#1086#1084#1077#1088':'
      end
      object cxLabel4: TcxLabel
        Left = 299
        Top = 127
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1086#1084#1077#1088' '#1050#1051':'
      end
      object cxLabel5: TcxLabel
        Left = 289
        Top = 160
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        Caption = #1053#1086#1084#1077#1088' '#1095#1077#1082#1072':'
      end
      object NCheckcxDBTextEdit: TcxDBTextEdit
        Left = 394
        Top = 159
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NCHECK_DPKOROZN'
        TabOrder = 6
        Width = 149
      end
      object NKLcxDBTextEdit: TcxDBTextEdit
        Left = 394
        Top = 126
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'NKL_DPKOROZN'
        TabOrder = 7
        Width = 149
      end
      object RegNumcxDBTextEdit: TcxDBTextEdit
        Left = 394
        Top = 92
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'REGNUM_DPKOROZN'
        TabOrder = 8
        Width = 149
      end
      object SavNumcxDBTextEdit: TcxDBTextEdit
        Left = 394
        Top = 59
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'SAVNUM_DPKOROZN'
        TabOrder = 9
        Width = 149
      end
      object ModelcxDBTextEdit: TcxDBTextEdit
        Left = 394
        Top = 26
        Margins.Left = 4
        Margins.Top = 4
        Margins.Right = 4
        Margins.Bottom = 4
        DataBinding.DataField = 'MODEL_DPKOROZN'
        TabOrder = 10
        Width = 149
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 494
    Width = 581
    Height = 78
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object DBTextFNameUser: TDBText
      Left = 0
      Top = 60
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
      Left = 414
      Top = 60
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
    object cxButtonPrint: TcxButton
      Left = 59
      Top = 25
      Width = 92
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionPrint
      TabOrder = 0
    end
    object cxButtonSave: TcxButton
      Left = 159
      Top = 25
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
      Left = 266
      Top = 25
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
      Left = 366
      Top = 25
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
      Left = 465
      Top = 25
      Width = 93
      Height = 30
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 4
    end
  end
  object ToolBar2: TToolBar
    Left = 0
    Top = 0
    Width = 581
    Height = 30
    Color = clBtnFace
    EdgeBorders = [ebTop, ebRight, ebBottom]
    Images = DM.ImageList1
    ParentColor = False
    TabOrder = 2
    object ToolButton1: TToolButton
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
    Left = 8
    Top = 48
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
  object PopupMenuExtModule: TPopupMenu
    Left = 56
    Top = 16
  end
end
