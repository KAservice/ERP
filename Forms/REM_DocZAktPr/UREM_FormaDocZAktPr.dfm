object REM_FormaDocZAktPr: TREM_FormaDocZAktPr
  Left = 146
  Top = -55
  Caption = #1044#1086#1082#1091#1084#1077#1085#1090' "'#1040#1082#1090' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1102'"'
  ClientHeight = 578
  ClientWidth = 892
  Color = clBtnFace
  Constraints.MinWidth = 689
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDesigned
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 526
    Width = 892
    Height = 52
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object DBTextFNameUser: TDBText
      Left = 33
      Top = 8
      Width = 119
      Height = 16
      AutoSize = True
      DataField = 'FNAME_USER'
      DataSource = REM_DMDocRemont.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ProsmotrLabel: TLabel
      Left = 34
      Top = 31
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
    object DBTextSUM_REM_GALLDOC: TDBText
      Left = 634
      Top = 15
      Width = 181
      Height = 16
      AutoSize = True
      DataField = 'SUM_REM_GALLDOC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object cxButtonPrint: TcxButton
      Left = 210
      Top = 20
      Width = 74
      Height = 26
      Action = ActionPrint
      TabOrder = 0
    end
    object cxButtonSave: TcxButton
      Left = 291
      Top = 20
      Width = 75
      Height = 26
      Action = ActionSave
      TabOrder = 1
    end
    object cxButtonDvReg: TcxButton
      Left = 372
      Top = 20
      Width = 75
      Height = 26
      Action = ActionDvReg
      TabOrder = 2
    end
    object cxButtonOK: TcxButton
      Left = 453
      Top = 20
      Width = 75
      Height = 26
      Action = ActionOK
      TabOrder = 3
    end
    object cxButtonClose: TcxButton
      Left = 534
      Top = 20
      Width = 75
      Height = 26
      Action = ActionClose
      TabOrder = 4
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 300
    Width = 0
    Height = 226
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 891
    Top = 300
    Width = 1
    Height = 226
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 3
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 892
    Height = 111
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 33
      Top = 79
      Width = 232
      Height = 24
      Caption = #1040#1082#1090' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1102'  '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 340
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
      Left = 10
      Top = 56
      Width = 40
      Height = 13
      Caption = #1060#1080#1088#1084#1072':'
    end
    object Label6: TLabel
      Left = 234
      Top = 30
      Width = 34
      Height = 13
      Caption = #1057#1082#1083#1072#1076':'
    end
    object Label12: TLabel
      Left = 222
      Top = 59
      Width = 68
      Height = 13
      Caption = #1058#1080#1087' '#1088#1077#1084#1086#1085#1090#1072':'
    end
    object ToolBar2: TToolBar
      Left = 0
      Top = 0
      Width = 892
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
      object ToolButtonAddStrin: TToolButton
        Left = 40
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1090#1088#1086#1082#1091
        Caption = 'ToolButtonAddStrin'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddStrinClick
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
        Width = 43
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 129
        Top = 0
        Width = 8
        Caption = 'ToolButton3'
        ImageIndex = 4
        Style = tbsSeparator
      end
      object ToolButtonOpenExtModule: TToolButton
        Left = 137
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonOpenExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateCheck: TToolButton
        Left = 160
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1063#1077#1082' '#1050#1050#1052
        Caption = 'ToolButtonCreateCheck'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateRealRozn: TToolButton
        Left = 183
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' "'#1056#1077#1072#1083#1080#1079#1072#1094#1080#1103' '#1088#1086#1079#1085'."'
        Caption = 'ToolButtonCreateRealRozn'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateReal: TToolButton
        Left = 206
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' "'#1056#1077#1072#1083#1080#1079#1072#1094#1080#1103'"'
        Caption = 'ToolButtonCreateReal'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonOpenGarTalon: TToolButton
        Left = 229
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1103' '#1080#1079' '#1082#1072#1090#1072#1083#1086#1075#1072' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1081
        Caption = 'ToolButtonOpenGarTalon'
        ImageIndex = 82
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenGarTalonClick
      end
      object ToolButtonZapolnit: TToolButton
        Left = 252
        Top = 0
        Hint = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1087#1086' '#1079#1072#1076#1072#1085#1085#1099#1084' '#1087#1072#1088#1072#1084#1077#1090#1088#1072#1084
        Caption = 'ToolButtonZapolnit'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonZapolnitClick
      end
      object ToolButtonOpenZayavka: TToolButton
        Left = 275
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1079#1072#1103#1074#1082#1091
        Caption = 'ToolButtonOpenZayavka'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenZayavkaClick
      end
      object ToolButtonCopyPrimkaGarant: TToolButton
        Left = 298
        Top = 0
        Hint = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077' '#1080#1079' '#1082#1072#1090#1072#1083#1086#1075#1072' '#1087#1088#1080#1077#1084#1082#1080' '#1074' '#1082#1072#1090#1072#1083#1086#1075' '#1089' '#1075#1072#1088#1072#1085#1090#1080#1077#1081
        Caption = 'ToolButtonCopyPrimkaGarant'
        ImageIndex = 82
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCopyPrimkaGarantClick
      end
      object ToolButtonSetOtchitanZayvka: TToolButton
        Left = 321
        Top = 0
        Hint = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100' '#1092#1083#1072#1075' '#1086#1090#1095#1080#1090#1072#1085' '#1074' '#1079#1072#1103#1074#1082#1077
        Caption = 'ToolButtonSetOtchitanZayvka'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonSetOtchitanZayvkaClick
      end
      object ToolButtonCreateDocRemont: TToolButton
        Left = 344
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1044#1086#1082#1091#1084#1077#1085#1090' '#1056#1077#1084#1086#1085#1090
        Caption = 'ToolButtonCreateDocRemont'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateDocRemontClick
      end
      object ToolButtonAddDataIsZayavki: TToolButton
        Left = 367
        Top = 0
        Hint = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1076#1072#1085#1085#1099#1084#1080' '#1080#1079' '#1079#1072#1103#1074#1082#1080
        Caption = 'ToolButtonAddDataIsZayavki'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddDataIsZayavkiClick
      end
      object ToolButton4: TToolButton
        Left = 390
        Top = 0
        Width = 82
        Caption = 'ToolButton4'
        ImageIndex = 46
        Style = tbsSeparator
      end
      object ToolButtonOpenFormNewHW: TToolButton
        Left = 472
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1086#1088#1084#1091' '#1101#1083#1077#1084#1077#1085#1090#1072' '#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077' ('#1085#1086#1074#1091#1102')'
        Caption = 'ToolButtonOpenFormNewHW'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenFormNewHWClick
      end
      object ToolButtonOpenFormOldHW: TToolButton
        Left = 495
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1086#1088#1084#1091' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103' '#1089#1090#1072#1088#1091#1102
        Caption = 'ToolButtonOpenFormOldHW'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenFormOldHWClick
      end
      object ToolButtonNewOldHW: TToolButton
        Left = 518
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1085#1086#1074#1099#1081' '#1101#1083#1077#1084#1077#1085#1090' '#1089#1090#1072#1088#1086#1086' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103' '
        Caption = 'ToolButtonNewOldHW'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonNewOldHWClick
      end
      object ToolButton5: TToolButton
        Left = 541
        Top = 0
        Width = 24
        Caption = 'ToolButton5'
        ImageIndex = 46
        Style = tbsSeparator
      end
      object ToolButtonAddPoCodHW: TToolButton
        Left = 565
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1086' '#1082#1086#1076#1091' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
        Caption = 'ToolButtonAddPoCodHW'
        ImageIndex = 45
        OnClick = ToolButtonAddPoCodHWClick
      end
      object ToolButtonAddPoIdHW: TToolButton
        Left = 588
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1086' ID  '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
        Caption = 'ToolButtonAddPoIdHW'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddPoIdHWClick
      end
      object ToolButton6: TToolButton
        Left = 611
        Top = 0
        Width = 18
        Caption = 'ToolButton6'
        ImageIndex = 46
        Style = tbsSeparator
      end
      object ToolButtonAddOldPoCoduHW: TToolButton
        Left = 629
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1090#1072#1088#1086#1077' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077' '#1087#1086' '#1082#1086#1076#1091
        Caption = 'ToolButtonAddOldPoCoduHW'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddOldPoCoduHWClick
      end
      object ToolButtonAddOldHWPoID: TToolButton
        Left = 652
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1090#1072#1088#1086#1077' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077' '#1087#1086' ID'
        Caption = 'ToolButtonAddOldHWPoID'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddOldHWPoIDClick
      end
      object ToolButton7: TToolButton
        Left = 675
        Top = 0
        Width = 37
        Caption = 'ToolButton7'
        ImageIndex = 46
        Style = tbsSeparator
      end
      object ToolButtonAddPoCoduNom: TToolButton
        Left = 712
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1086' '#1082#1086#1076#1091' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
        Caption = 'ToolButtonAddPoCoduNom'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAddPoCoduNomClick
      end
      object ToolButton8: TToolButton
        Left = 735
        Top = 0
        Width = 50
        Caption = 'ToolButton8'
        ImageIndex = 46
        Style = tbsSeparator
      end
      object ToolButton9: TToolButton
        Left = 785
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1079#1072#1087#1095#1072#1089#1090#1080' ('#1087#1086' '#1079#1072#1082#1072#1079#1072#1084')'
        Caption = 'ToolButtonAddZipPoZak'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton9Click
      end
      object ToolButtonOpenGarTalonIsZayavkiPoNumGarTalona: TToolButton
        Left = 808
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1075#1072#1088' '#1090#1072#1083#1086#1085#1072' '#1087#1086' '#1076#1072#1090#1077' '#1079#1072#1103#1074#1082#1080' '#1087#1086' '#1085#1086#1084#1077#1088#1091' '#1075#1072#1088'. '#1090#1072#1083#1086#1085#1072
        Caption = 'ToolButtonOpenGarTalonIsZayavkiPoNumGarTalona'
        ImageIndex = 82
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenGarTalonIsZayavkiPoNumGarTalonaClick
      end
      object ToolButtonOpenFilePoZayavkePoSerNum1: TToolButton
        Left = 831
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1087#1086' '#1076#1072#1090#1077' '#1079#1072#1103#1074#1082#1080' '#1087#1086' '#1079#1072#1074#1086#1076#1089#1082#1086#1084#1091' '#1085#1086#1084#1077#1088#1091' 1'
        Caption = 'ToolButtonOpenFilePoZayavkePoSerNum1'
        ImageIndex = 82
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenFilePoZayavkePoSerNum1Click
      end
      object ToolButtonCreateDocVzip: TToolButton
        Left = 854
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' "'#1042#1086#1079#1074#1088#1072#1090' '#1047#1048#1055'"'
        Caption = 'ToolButtonCreateDocVzip'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateDocVzipClick
      end
    end
    object NumDoccxDBTextEdit: TcxDBTextEdit
      Left = 253
      Top = 84
      DataBinding.DataField = 'NUM_REM_GALLDOC'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
      TabOrder = 4
      OnKeyDown = NumDoccxDBTextEditKeyDown
      Width = 81
    end
    object PosDoccxDBDateEdit: TcxDBDateEdit
      Left = 369
      Top = 84
      DataBinding.DataField = 'POS_REM_GALLDOC'
      Properties.Kind = ckDateTime
      Properties.OnChange = PosDoccxDBDateEditPropertiesChange
      TabOrder = 5
      OnKeyDown = PosDoccxDBDateEditKeyDown
      Width = 159
    end
    object NameFirmcxDBButtonEdit: TcxDBButtonEdit
      Left = 59
      Top = 53
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
      Width = 156
    end
    object NameInfBasecxDBButtonEdit: TcxDBButtonEdit
      Left = 60
      Top = 31
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
      Width = 155
    end
    object cxLabel1: TcxLabel
      Left = 1
      Top = 32
      Caption = #1048#1085#1092'. '#1073#1072#1079#1072':'
    end
    object NameSkladcxDBButtonEdit: TcxDBButtonEdit
      Left = 297
      Top = 30
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
      Width = 204
    end
    object TypeRemontcxDBImageComboBox: TcxDBImageComboBox
      Left = 297
      Top = 55
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      RepositoryItem = DM.cxEditRepository1ImageComboBoxTypeRemont
      DataBinding.DataField = 'TYPE_REMONT_REM_DZAKTPR'
      Properties.Items = <>
      TabOrder = 3
      Width = 204
    end
    object cxLabel9: TcxLabel
      Left = 497
      Top = 31
      Caption = #1041#1080#1079#1085#1077#1089' '#1086#1087#1077#1088#1072#1094#1080#1103':'
    end
    object NameBusinessOpercxDBButtonEdit: TcxDBButtonEdit
      Left = 596
      Top = 30
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
      TabOrder = 9
      Width = 221
    end
    object NameProjectcxDBButtonEdit: TcxDBButtonEdit
      Left = 596
      Top = 56
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
      TabOrder = 10
      Width = 221
    end
    object cxLabel4: TcxLabel
      Left = 525
      Top = 56
      Caption = #1055#1088#1086#1077#1082#1090':'
    end
    object cxDBButtonEdit1: TcxDBButtonEdit
      Left = 596
      Top = 82
      DataBinding.DataField = 'NAMEKLIENT'
      DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
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
      Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
      TabOrder = 12
      Width = 221
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 300
    Width = 891
    Height = 226
    Align = alClient
    TabOrder = 4
    object cxGrid1DBBandedTableView1: TcxGridDBBandedTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          Column = cxGrid1DBBandedTableView1SUM_REM_DZAKTPRT
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsSelection.InvertSelect = False
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      OptionsView.RowSeparatorWidth = 4
      Styles.Header = DM.cxStyleHeaderTable
      Bands = <
        item
          Width = 1205
        end>
      object cxGrid1DBBandedTableView1NAME_REM_SPRCOND_GRP: TcxGridDBBandedColumn
        Caption = #1043#1088#1091#1087#1087#1072
        DataBinding.FieldName = 'NAME_REM_SPRCOND_GRP'
        Width = 151
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAME_REM_SPRCONDITION: TcxGridDBBandedColumn
        Caption = #1059#1089#1083#1086#1074#1080#1103' '#1087#1088#1086#1103#1074#1083#1077#1085#1080#1103', condition'
        DataBinding.FieldName = 'NAME_REM_SPRCONDITION'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_REM_SPRCONDITIONPropertiesButtonClick
        Width = 244
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAME_REM_SPRNEISPR: TcxGridDBBandedColumn
        Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100', '#1089#1080#1084#1087#1090#1086#1084
        DataBinding.FieldName = 'NAME_REM_SPRNEISPR'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_REM_SPRNEISPRPropertiesButtonClick
        Width = 318
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAME_REM_SPRSECTION_GRP: TcxGridDBBandedColumn
        Caption = #1043#1088#1091#1087#1087#1072
        DataBinding.FieldName = 'NAME_REM_SPRSECTION_GRP'
        Width = 151
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1NAME_REM_SPRSECTION: TcxGridDBBandedColumn
        Caption = #1052#1077#1089#1090#1086' '#1074#1086#1079#1085#1080#1082#1085#1086#1074#1077#1085#1080#1103', section'
        DataBinding.FieldName = 'NAME_REM_SPRSECTION'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_REM_SPRSECTIONPropertiesButtonClick
        Width = 244
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1NAME_REM_SPRDEFECT: TcxGridDBBandedColumn
        Caption = #1044#1077#1092#1077#1082#1090
        DataBinding.FieldName = 'NAME_REM_SPRDEFECT'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_REM_SPRDEFECTPropertiesButtonClick
        Width = 318
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1NAME_REM_SPRRABOTA: TcxGridDBBandedColumn
        Caption = #1056#1072#1073#1086#1090#1072', repair'
        DataBinding.FieldName = 'NAME_REM_SPRRABOTA'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_REM_SPRRABOTAPropertiesButtonClick
        Styles.Content = DM.cxStyleclMoneyGreen
        Width = 206
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1NAMENOM: TcxGridDBBandedColumn
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        DataBinding.FieldName = 'NAMENOM'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAMENOMPropertiesButtonClick
        Styles.Content = DM.cxStyleclMoneyGreen
        Width = 184
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1NAME_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077', '#1073#1083#1086#1082', '#1076#1077#1090#1072#1083#1100' ('#1085#1086#1074#1072#1103')'
        DataBinding.FieldName = 'NAME_REM_SHARDWARE'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_REM_SHARDWAREPropertiesButtonClick
        Width = 86
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 3
      end
      object cxGrid1DBBandedTableView1CODE_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_REM_SHARDWARE'
        Width = 20
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 3
      end
      object cxGrid1DBBandedTableView1SERNUM_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #8470
        DataBinding.FieldName = 'SERNUM_REM_SHARDWARE'
        Width = 72
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 3
      end
      object cxGrid1DBBandedTableView1OLD_CODE_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'OLD_CODE_REM_SHARDWARE'
        Width = 29
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 3
      end
      object cxGrid1DBBandedTableView1OLD_NAME_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077', '#1073#1083#1086#1082' ('#1089#1090#1072#1088#1099#1081')'
        DataBinding.FieldName = 'OLD_NAME_REM_SHARDWARE'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1OLD_NAME_REM_SHARDWAREPropertiesButtonClick
        Width = 78
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 3
      end
      object cxGrid1DBBandedTableView1OLD_SERNUM_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #8470
        DataBinding.FieldName = 'OLD_SERNUM_REM_SHARDWARE'
        Width = 76
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 3
      end
      object cxGrid1DBBandedTableView1KOL_REM_DZAKTPRT: TcxGridDBBandedColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOL_REM_DZAKTPRT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Content = DM.cxStyleclMoneyGreen
        Width = 34
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1KF_REM_DZAKTPRT: TcxGridDBBandedColumn
        Caption = #1050#1060
        DataBinding.FieldName = 'KF_REM_DZAKTPRT'
        Styles.Content = DM.cxStyleclMoneyGreen
        Width = 22
        Position.BandIndex = 0
        Position.ColIndex = 7
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1PRICE_REM_DZAKTPRT: TcxGridDBBandedColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'PRICE_REM_DZAKTPRT'
        PropertiesClassName = 'TcxCalcEditProperties'
        Styles.Content = DM.cxStyleclMoneyGreen
        Width = 46
        Position.BandIndex = 0
        Position.ColIndex = 8
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1SUM_REM_DZAKTPRT: TcxGridDBBandedColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_REM_DZAKTPRT'
        Styles.Content = DM.cxStyleclMoneyGreen
        Width = 50
        Position.BandIndex = 0
        Position.ColIndex = 9
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1DVREG_REM_DZAKTPRT: TcxGridDBBandedColumn
        Caption = #1044#1074'.'
        DataBinding.FieldName = 'DVREG_REM_DZAKTPRT'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Styles.Content = DM.cxStyleclMoneyGreen
        Width = 37
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1FL_VOSVRAT_ZIP_REM_DZAKTPRT: TcxGridDBBandedColumn
        Caption = #1042#1086#1079#1074#1088'.'
        DataBinding.FieldName = 'FL_VOSVRAT_ZIP_REM_DZAKTPRT'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Styles.Content = DM.cxStyleclMoneyGreen
        Width = 28
        Position.BandIndex = 0
        Position.ColIndex = 10
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1FL_ISP_REM_DZAKTPRT: TcxGridDBBandedColumn
        Caption = #1048#1089#1087#1086#1083#1100#1079#1086#1074#1072#1085#1086
        DataBinding.FieldName = 'FL_ISP_REM_DZAKTPRT'
        RepositoryItem = DM.cxEditRepository1ImageComboBoxItemFlagIspZip
        Styles.Content = DM.cxStyleclMoneyGreen
        Width = 43
        Position.BandIndex = 0
        Position.ColIndex = 11
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1CODE_REM_SPRCOND_GRP: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_REM_SPRCOND_GRP'
        Width = 42
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1CODE_REM_SPRCONDITION: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_REM_SPRCONDITION'
        Width = 40
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1CODE_REM_SPRNEISPR: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_REM_SPRNEISPR'
        Width = 39
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1NAME_REM_SPRNEISPR_GRP: TcxGridDBBandedColumn
        Caption = #1043#1088#1091#1087#1087#1072
        DataBinding.FieldName = 'NAME_REM_SPRNEISPR_GRP'
        Width = 135
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1CODE_REM_SPRSECTION: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_REM_SPRSECTION'
        Width = 40
        Position.BandIndex = 0
        Position.ColIndex = 2
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1CODE_REM_SPRDEFECT: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_REM_SPRDEFECT'
        Width = 39
        Position.BandIndex = 0
        Position.ColIndex = 6
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1CODE_REM_SPRRABOTA: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_REM_SPRRABOTA'
        Styles.Content = DM.cxStyleclMoneyGreen
        Width = 62
        Position.BandIndex = 0
        Position.ColIndex = 1
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1IDHW_REM_DZAKTPRT: TcxGridDBBandedColumn
        Caption = 'ID'
        DataBinding.FieldName = 'IDHW_REM_DZAKTPRT'
        Options.Editing = False
        Width = 34
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 3
      end
      object cxGrid1DBBandedTableView1IDHWOLD_REM_DZAKTPRT: TcxGridDBBandedColumn
        Caption = 'ID'
        DataBinding.FieldName = 'IDHWOLD_REM_DZAKTPRT'
        Options.Editing = False
        Width = 20
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 3
      end
      object cxGrid1DBBandedTableView1Column1: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        Width = 43
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 0
      end
      object cxGrid1DBBandedTableView1CODE_REM_SPRSECTION_GRP: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODE_REM_SPRSECTION_GRP'
        Width = 42
        Position.BandIndex = 0
        Position.ColIndex = 0
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1Column2: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        Width = 43
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1NAME_REM_SPRDEFECT_GRP: TcxGridDBBandedColumn
        Caption = #1043#1088#1091#1087#1087#1072
        DataBinding.FieldName = 'NAME_REM_SPRDEFECT_GRP'
        Width = 135
        Position.BandIndex = 0
        Position.ColIndex = 5
        Position.RowIndex = 1
      end
      object cxGrid1DBBandedTableView1ARTNOM: TcxGridDBBandedColumn
        Caption = #1040#1088#1090#1080#1082#1091#1083
        DataBinding.FieldName = 'ARTNOM'
        Styles.Content = DM.cxStyleclMoneyGreen
        Width = 48
        Position.BandIndex = 0
        Position.ColIndex = 4
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1NAME_TYPE_NOM_LOOCUP: TcxGridDBBandedColumn
        Caption = #1058#1080#1087' '#1085#1086#1084'.'
        DataBinding.FieldName = 'NAME_TYPE_NOM_LOOCUP'
        Styles.Content = DM.cxStyleclMoneyGreen
        Width = 39
        Position.BandIndex = 0
        Position.ColIndex = 3
        Position.RowIndex = 2
      end
      object cxGrid1DBBandedTableView1NAME_REM_STYPUSLOV: TcxGridDBBandedColumn
        Caption = #1058#1080#1087' '#1091#1079#1077#1083
        DataBinding.FieldName = 'NAME_REM_STYPUSLOV'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_REM_STYPUSLOVPropertiesButtonClick
        Width = 80
        Position.BandIndex = 0
        Position.ColIndex = 8
        Position.RowIndex = 3
      end
      object cxGrid1DBBandedTableView1DESCR_REM_DZAKTPRT: TcxGridDBBandedColumn
        Caption = #1054#1087#1080#1089#1072#1085#1080#1077
        DataBinding.FieldName = 'DESCR_REM_DZAKTPRT'
        Width = 112
        Position.BandIndex = 0
        Position.ColIndex = 9
        Position.RowIndex = 3
      end
      object cxGrid1DBBandedTableView1DONOR_NAME_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #1044#1086#1085#1086#1088
        DataBinding.FieldName = 'DONOR_NAME_REM_SHARDWARE'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1DONOR_NAME_REM_SHARDWAREPropertiesButtonClick
        Width = 80
        Position.BandIndex = 0
        Position.ColIndex = 12
        Position.RowIndex = 3
      end
      object cxGrid1DBBandedTableView1DONOR_CODE_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'DONOR_CODE_REM_SHARDWARE'
        Width = 32
        Position.BandIndex = 0
        Position.ColIndex = 11
        Position.RowIndex = 3
      end
      object cxGrid1DBBandedTableView1DONOR_SERNUM_REM_SHARDWARE: TcxGridDBBandedColumn
        Caption = #8470
        DataBinding.FieldName = 'DONOR_SERNUM_REM_SHARDWARE'
        Width = 83
        Position.BandIndex = 0
        Position.ColIndex = 13
        Position.RowIndex = 3
      end
      object cxGrid1DBBandedTableView1IDHW_DONOR_REM_DZAKTPRT: TcxGridDBBandedColumn
        Caption = 'ID '#1076#1086#1085#1086#1088#1072
        DataBinding.FieldName = 'IDHW_DONOR_REM_DZAKTPRT'
        Options.Editing = False
        Width = 20
        Position.BandIndex = 0
        Position.ColIndex = 10
        Position.RowIndex = 3
      end
      object cxGrid1DBBandedTableView1NAME_SMHRAN: TcxGridDBBandedColumn
        Caption = #1052#1077#1089#1090#1086' '#1093#1088#1072#1085'.'
        DataBinding.FieldName = 'NAME_SMHRAN'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = cxGrid1DBBandedTableView1NAME_SMHRANPropertiesButtonClick
        Width = 90
        Position.BandIndex = 0
        Position.ColIndex = 12
        Position.RowIndex = 2
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBBandedTableView1
    end
  end
  object cxPageControl1: TcxPageControl
    Left = 0
    Top = 111
    Width = 892
    Height = 189
    Margins.Left = 2
    Margins.Top = 2
    Margins.Right = 2
    Margins.Bottom = 2
    ActivePage = cxTabSheet1
    Align = alTop
    TabOrder = 5
    ClientRectBottom = 189
    ClientRectRight = 892
    ClientRectTop = 24
    object cxTabSheet1: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1054#1089#1085#1086#1074#1085#1072#1103
      ImageIndex = 0
      object Label27: TLabel
        Left = 14
        Top = 30
        Width = 56
        Height = 13
        Caption = #1055#1088#1086#1080#1079#1074'-'#1083#1100':'
      end
      object Label4: TLabel
        Left = 20
        Top = 6
        Width = 39
        Height = 13
        Caption = #1050#1083#1080#1077#1085#1090':'
      end
      object Label34: TLabel
        Left = 14
        Top = 50
        Width = 58
        Height = 26
        Caption = #1055#1086#1089#1090#1072#1074#1097#1080#1082' '#1047#1048#1055':'
        WordWrap = True
      end
      object Label3: TLabel
        Left = 3
        Top = 113
        Width = 66
        Height = 13
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
      end
      object RTPriceLabel: TLabel
        Left = 353
        Top = 50
        Width = 106
        Height = 13
        Caption = #1058#1080#1087' '#1094#1077#1085' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080':'
      end
      object Label13: TLabel
        Left = 402
        Top = 26
        Width = 57
        Height = 13
        Caption = #1050#1077#1084' '#1089#1076#1072#1085#1086':'
      end
      object Label18: TLabel
        Left = 14
        Top = 82
        Width = 57
        Height = 13
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077':'
      end
      object Label19: TLabel
        Left = 3
        Top = 132
        Width = 65
        Height = 13
        Caption = #1050#1086#1084#1077#1085#1090#1072#1088#1080#1081':'
      end
      object Label36: TLabel
        Left = 395
        Top = 7
        Width = 70
        Height = 13
        Caption = #1044#1072#1090#1072' '#1087#1088#1080#1077#1084#1072':'
      end
      object ProducercxDBButtonEdit: TcxDBButtonEdit
        Left = 89
        Top = 28
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
        Properties.OnButtonClick = ProducercxDBButtonEditPropertiesButtonClick
        TabOrder = 0
        Width = 258
      end
      object NamePostZipcxDBButtonEdit: TcxDBButtonEdit
        Left = 90
        Top = 52
        DataBinding.DataField = 'POST_ZIP_NAME'
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
        Properties.OnButtonClick = NamePostZipcxDBButtonEditPropertiesButtonClick
        TabOrder = 1
        Width = 257
      end
      object NameKlientcxDBButtonEdit: TcxDBButtonEdit
        Left = 89
        Top = 3
        DataBinding.DataField = 'NAMEKLIENT'
        DataBinding.DataSource = REM_DMDocRemont.DataSourceDocAll
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
        Properties.OnButtonClick = NameKlientcxDBButtonEditPropertiesButtonClick
        TabOrder = 2
        Width = 257
      end
      object PrimcxDBTextEdit: TcxDBTextEdit
        Left = 90
        Top = 106
        DataBinding.DataField = 'PRIM_REM_DZAKTPR'
        TabOrder = 3
        OnKeyDown = PrimcxDBTextEditKeyDown
        Width = 458
      end
      object OtchetPostcxDBCheckBox: TcxDBCheckBox
        Left = 668
        Top = 75
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1086#1090#1095#1077#1090' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1091' '#1047#1048#1055
        DataBinding.DataField = 'FL_OTCHET_POST_REM_DZAKTPR'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 4
        Width = 158
      end
      object PrigKGarRemontucxDBCheckBox: TcxDBCheckBox
        Left = 567
        Top = 132
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1087#1088#1080#1075#1086#1076#1077#1085' '#1082' '#1075#1072#1088'. '#1088#1077#1084#1086#1085#1090#1091
        DataBinding.DataField = 'FL_PRIG_KREM_REM_DZAKTPR'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 5
        Width = 156
      end
      object TypePricecxDBLookupComboBox: TcxDBLookupComboBox
        Left = 472
        Top = 49
        DataBinding.DataField = 'IDTPRICE_REM_DZAKTPR'
        Properties.ImmediatePost = True
        Properties.KeyFieldNames = 'ID_TPRICE'
        Properties.ListColumns = <
          item
            FieldName = 'NAME_TPRICE'
          end>
        Properties.ListSource = DMSprTypePrice.DataSourceTable
        TabOrder = 6
        Width = 181
      end
      object KEM_SDANOcxDBImageComboBox: TcxDBImageComboBox
        Left = 472
        Top = 24
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        RepositoryItem = DM.cxEditRepository1ImageComboBoxREM_KemSdano
        DataBinding.DataField = 'KEM_SDANO_REM_DZAKTPR'
        Properties.Items = <>
        TabOrder = 7
        Width = 181
      end
      object DescrcxDBTextEdit: TcxDBTextEdit
        Left = 90
        Top = 131
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'DESCR_REM_DZAKTPR'
        TabOrder = 8
        Width = 458
      end
      object SOSTcxDBTextEdit: TcxDBTextEdit
        Left = 89
        Top = 82
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'SOST_REM_DZAKTPR'
        TabOrder = 9
        Width = 459
      end
      object FictivcxDBCheckBox: TcxDBCheckBox
        Left = 566
        Top = 75
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1092#1080#1082#1090#1080#1074#1085#1099#1081
        DataBinding.DataField = 'FL_FICTIV_REM_DZAKTPR'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 10
        Width = 98
      end
      object flNeOtchcxDBCheckBox: TcxDBCheckBox
        Left = 567
        Top = 93
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1085#1077' '#1086#1090#1095#1080#1090#1099#1074#1072#1090#1100
        DataBinding.DataField = 'FL_NE_OTCH_REM_DZAKTPR'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 11
        Width = 105
      end
      object flNadoOtchcxDBCheckBox: TcxDBCheckBox
        Left = 567
        Top = 111
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1085#1072#1076#1086' '#1086#1090#1095#1080#1090#1072#1090#1100
        DataBinding.DataField = 'FL_NADO_OTCH_REM_DZAKTPR'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 12
        Width = 119
      end
      object PosPriemacxDBDateEdit: TcxDBDateEdit
        Left = 472
        Top = 0
        DataBinding.DataField = 'POSPRIEMA_REM_DZAKTPR'
        Properties.Kind = ckDateTime
        Properties.OnChange = PosDoccxDBDateEditPropertiesChange
        TabOrder = 13
        OnKeyDown = PosDoccxDBDateEditKeyDown
        Width = 174
      end
      object cxDBCheckBoxFL_OST_NA_OTV_XRAN_REM_DZAKTPR: TcxDBCheckBox
        Left = 668
        Top = 99
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1086#1089#1090#1072#1074#1083#1077#1085#1086' '#1085#1072' '#1086#1090#1074'. '#1093#1088#1072#1085#1077#1085#1080#1077
        DataBinding.DataField = 'FL_OST_NA_OTV_XRAN_REM_DZAKTPR'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        TabOrder = 14
        Width = 156
      end
    end
    object cxTabSheet2: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100
      ImageIndex = 1
      object Label29: TLabel
        Left = 574
        Top = 75
        Width = 126
        Height = 13
        Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100' '#1082#1083#1080#1077#1085#1090#1072':'
      end
      object Label30: TLabel
        Left = 14
        Top = 55
        Width = 67
        Height = 13
        Caption = #1053#1077#1080#1089#1087#1088#1072#1074'-'#1090#1100':'
      end
      object Label14: TLabel
        Left = 20
        Top = 104
        Width = 155
        Height = 13
        Caption = #1053#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100' '#1082#1083#1080#1077#1085#1090#1072' (CFC):'
      end
      object Label15: TLabel
        Left = 28
        Top = 137
        Width = 165
        Height = 13
        Caption = #1044#1080#1072#1075#1085#1086#1089#1090'. '#1085#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1100' (DFC):'
      end
      object NeisprZcxDBLabel: TcxDBLabel
        Left = 11
        Top = 22
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NEISPR_REM_Z'
        ParentFont = False
        Properties.WordWrap = True
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clNavy
        Style.Font.Height = -12
        Style.Font.Name = 'MS Sans Serif'
        Style.Font.Style = [fsBold]
        Style.IsFontAssigned = True
        Height = 28
        Width = 458
      end
      object NeisprcxDBTextEdit: TcxDBTextEdit
        Left = 90
        Top = 55
        DataBinding.DataField = 'NEISPR_REM_DZAKTPR'
        TabOrder = 1
        OnKeyDown = PrimcxDBTextEditKeyDown
        Width = 458
      end
      object cxButtonCopyNeispr: TcxButton
        Left = 555
        Top = 21
        Width = 61
        Height = 20
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1050#1086#1087#1080#1088'.'
        TabOrder = 2
        OnClick = cxButtonCopyNeisprClick
      end
      object CodeNeisprPrcxDBLabel: TcxDBLabel
        Left = 488
        Top = 80
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'CFC_CODE'
        Height = 17
        Width = 62
      end
      object NameGrpCFCcxDBLabel: TcxDBLabel
        Left = 90
        Top = 86
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NAME_REM_SPRNEISPR_GRP'
        Height = 17
        Width = 190
      end
      object CFCcxDBButtonEdit: TcxDBButtonEdit
        Left = 204
        Top = 99
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'CFC_NAME'
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
        TabOrder = 5
        Width = 344
      end
      object DFCcxDBButtonEdit: TcxDBButtonEdit
        Left = 202
        Top = 132
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'DFC_NAME'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = DFCcxDBButtonEditPropertiesButtonClick
        TabOrder = 6
        Width = 343
      end
    end
    object cxTabSheet3: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1059#1089#1090#1088#1086#1081#1089#1090#1074#1086
      ImageIndex = 2
      object Label28: TLabel
        Left = 14
        Top = 11
        Width = 122
        Height = 13
        Caption = #1052#1086#1076#1077#1083#1100' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1103':'
      end
      object Label35: TLabel
        Left = 417
        Top = 11
        Width = 63
        Height = 13
        Caption = #1050#1086#1076' '#1084#1086#1076#1077#1083#1080':'
      end
      object Label23: TLabel
        Left = 89
        Top = 40
        Width = 53
        Height = 13
        Caption = #1053#1086#1084#1077#1088' '#1043#1058':'
      end
      object Label24: TLabel
        Left = 80
        Top = 137
        Width = 61
        Height = 13
        Caption = #1053#1086#1084#1077#1088' '#1040#1050#1041':'
      end
      object Label26: TLabel
        Left = 96
        Top = 117
        Width = 45
        Height = 13
        Caption = #1057#1077#1088' '#8470' 4:'
      end
      object Label25: TLabel
        Left = 96
        Top = 98
        Width = 45
        Height = 13
        Caption = #1057#1077#1088' '#8470' 3:'
      end
      object Label11: TLabel
        Left = 119
        Top = 74
        Width = 17
        Height = 13
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = '2'#8470
      end
      object Label10: TLabel
        Left = 119
        Top = 58
        Width = 17
        Height = 13
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = '1'#8470
      end
      object Label20: TLabel
        Left = 371
        Top = 80
        Width = 75
        Height = 13
        Caption = #1044#1072#1090#1072' '#1074#1099#1087#1091#1089#1082#1072':'
      end
      object Label21: TLabel
        Left = 555
        Top = 82
        Width = 76
        Height = 13
        Caption = #1044#1072#1090#1072' '#1087#1088#1086#1076#1072#1078#1080':'
      end
      object Label22: TLabel
        Left = 391
        Top = 33
        Width = 53
        Height = 13
        Caption = #1055#1088#1086#1076#1072#1074#1077#1094':'
      end
      object Label16: TLabel
        Left = 365
        Top = 107
        Width = 80
        Height = 13
        Caption = #1055#1054' '#1076#1086' '#1088#1077#1084#1086#1085#1090#1072':'
      end
      object Label40: TLabel
        Left = 391
        Top = 60
        Width = 53
        Height = 13
        Caption = #1055#1088#1086#1076#1072#1074#1077#1094':'
      end
      object Label42: TLabel
        Left = 346
        Top = 128
        Width = 98
        Height = 13
        Caption = #1055#1054' '#1087#1086#1089#1083#1077' '#1088#1077#1084#1086#1085#1090#1072':'
      end
      object ProducerModelcxDBButtonEdit: TcxDBButtonEdit
        Left = 147
        Top = 9
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NAME_REM_SPRMODEL'
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.OnButtonClick = ProducerModelcxDBButtonEditPropertiesButtonClick
        TabOrder = 0
        Width = 265
      end
      object CodePrModelcxDBTextEdit: TcxDBTextEdit
        Left = 496
        Top = 6
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'CODE_REM_SPRMODEL'
        Properties.ReadOnly = True
        TabOrder = 1
        Width = 157
      end
      object NumGTcxDBTextEdit: TcxDBTextEdit
        Left = 145
        Top = 35
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NUMGARTALON_REM_DZAKTPR'
        TabOrder = 2
        Width = 183
      end
      object cxButtonCopyNemGT: TcxButton
        Left = 332
        Top = 32
        Width = 43
        Height = 20
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1050#1086#1087#1080#1088'.'
        TabOrder = 3
        OnClick = cxButtonCopyNemGTClick
      end
      object SerNumcxDBTextEdit: TcxDBTextEdit
        Left = 145
        Top = 54
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'SERNUM_REM_Z'
        TabOrder = 4
        Width = 183
      end
      object SerNum2cxDBTextEdit: TcxDBTextEdit
        Left = 145
        Top = 75
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'SERNUM2_REM_Z'
        TabOrder = 5
        Width = 183
      end
      object SerNum3cxDBTextEdit: TcxDBTextEdit
        Left = 145
        Top = 95
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'SERNUM3_REM_DZAKTPR'
        TabOrder = 6
        Width = 183
      end
      object SerNum4cxDBTextEdit: TcxDBTextEdit
        Left = 145
        Top = 115
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'SERNUM4_REM_DZAKTPR'
        TabOrder = 7
        Width = 183
      end
      object NumBatcxDBTextEdit: TcxDBTextEdit
        Left = 145
        Top = 136
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NUMBAT_REM_DZAKTPR'
        TabOrder = 8
        Width = 183
      end
      object DateVipuskcxDBDateEdit: TcxDBDateEdit
        Left = 452
        Top = 80
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'DATEVIPUSK_REM_DZAKTPR'
        TabOrder = 9
        Width = 98
      end
      object DateProdagicxDBDateEdit: TcxDBDateEdit
        Left = 647
        Top = 80
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'DATE_PRODAGI_REM_DZAKTPR'
        TabOrder = 10
        Width = 97
      end
      object ProdaveccxDBTextEdit: TcxDBTextEdit
        Left = 452
        Top = 58
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'PRODAVEC_REM_DZAKTPR'
        TabOrder = 11
        Width = 265
      end
      object PODOcxDBTextEdit: TcxDBTextEdit
        Left = 452
        Top = 103
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'PODO_REM_DZAKTPR'
        TabOrder = 12
        Width = 265
      end
      object POPOSLEcxDBTextEdit: TcxDBTextEdit
        Left = 452
        Top = 126
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'POPOSLE_REM_DZAKTPR'
        TabOrder = 13
        Width = 265
      end
      object NameSSellercxDBButtonEdit: TcxDBButtonEdit
        Left = 452
        Top = 35
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
        Properties.OnButtonClick = NameSSellercxDBButtonEditPropertiesButtonClick
        TabOrder = 14
        Width = 265
      end
    end
    object cxTabSheet4: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1050#1083#1080#1077#1085#1090
      ImageIndex = 3
      object Label33: TLabel
        Left = 14
        Top = 56
        Width = 48
        Height = 13
        Caption = #1058#1077#1083#1077#1092#1086#1085':'
      end
      object Label32: TLabel
        Left = 30
        Top = 95
        Width = 34
        Height = 13
        Caption = #1040#1076#1088#1077#1089':'
      end
      object Label31: TLabel
        Left = 20
        Top = 26
        Width = 39
        Height = 13
        Caption = #1050#1083#1080#1077#1085#1090':'
      end
      object KlientPhonecxDBTextEdit: TcxDBTextEdit
        Left = 79
        Top = 56
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'KLIENT_PHONE_REM_DZAKTPR'
        TabOrder = 0
        Width = 183
      end
      object ClientAdrcxDBMemo: TcxDBMemo
        Left = 79
        Top = 79
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'KLIENT_ADR_REM_DZAKTPR'
        TabOrder = 1
        Height = 72
        Width = 183
      end
      object KlientNаmecxDBTextEdit: TcxDBTextEdit
        Left = 79
        Top = 24
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'KLIENT_NAME_REM_DZAKTPR'
        TabOrder = 2
        Width = 183
      end
      object cxButtonZapolnIsZayvki: TcxButton
        Left = 291
        Top = 47
        Width = 127
        Height = 20
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1080#1079' '#1079#1072#1103#1074#1082#1080
        TabOrder = 3
        OnClick = cxButtonZapolnIsZayvkiClick
      end
      object cxButtonViborIsSpr: TcxButton
        Left = 290
        Top = 24
        Width = 128
        Height = 20
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1042#1099#1073#1088#1072#1090#1100' '#1080#1079' '#1089#1087#1088'.'
        TabOrder = 4
        OnClick = cxButtonViborIsSprClick
      end
    end
    object cxTabSheet5: TcxTabSheet
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Caption = #1047#1072#1103#1074#1082#1072
      ImageIndex = 4
      object Label7: TLabel
        Left = 34
        Top = 27
        Width = 40
        Height = 13
        Caption = #1047#1072#1103#1074#1082#1072':'
      end
      object Label8: TLabel
        Left = 537
        Top = 55
        Width = 11
        Height = 13
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #8470
      end
      object Label9: TLabel
        Left = 660
        Top = 50
        Width = 11
        Height = 13
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1086#1090
      end
      object NameZcxDBButtonEdit: TcxDBButtonEdit
        Left = 90
        Top = 25
        DataBinding.DataField = 'NAME_REM_Z'
        DataBinding.DataSource = REM_DMDocRemont.DataSourceDoc
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end>
        Properties.ReadOnly = True
        Properties.OnButtonClick = NameZcxDBButtonEditPropertiesButtonClick
        TabOrder = 0
        Width = 224
      end
      object NumZcxDBLabel: TcxDBLabel
        Left = 555
        Top = 51
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'NUM_REM_Z'
        Height = 17
        Width = 98
      end
      object NameKlientcxDBLabel: TcxDBLabel
        Left = 537
        Top = 69
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'KLIENT_NAME_REM_Z'
        Height = 17
        Width = 271
      end
      object ModelcxDBLabel: TcxDBLabel
        Left = 537
        Top = 84
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'MODEL_REM_Z'
        Height = 17
        Width = 271
      end
      object PosZcxDBLabel: TcxDBLabel
        Left = 691
        Top = 51
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        DataBinding.DataField = 'POS_REM_Z'
        Height = 17
        Width = 117
      end
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 8
    Top = 80
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
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 352
    Top = 24
  end
end
