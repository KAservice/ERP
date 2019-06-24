object REM_FormaGurAllDoc: TREM_FormaGurAllDoc
  Left = 268
  Top = 221
  Caption = #1055#1086#1083#1085#1099#1081' '#1078#1091#1088#1085#1072#1083' ('#1056#1077#1084#1086#1085#1090'):'
  ClientHeight = 415
  ClientWidth = 815
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
  WindowState = wsMaximized
  OnClose = FormClose
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 815
    Height = 150
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object LabelInterval: TLabel
      Left = 136
      Top = 32
      Width = 61
      Height = 16
      Caption = #1055#1077#1088#1080#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 8
      Top = 32
      Width = 121
      Height = 16
      Caption = #1055#1086#1083#1085#1099#1081' '#1078#1091#1088#1085#1072#1083':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object StrOtborLabel: TLabel
      Left = 538
      Top = 40
      Width = 168
      Height = 16
      Alignment = taRightJustify
      Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090' '#1085#1077' '#1074#1099#1073#1088#1072#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 815
      Height = 26
      Caption = 'ToolBar1'
      EdgeBorders = [ebTop, ebBottom]
      Images = DM.ImageList1
      TabOrder = 0
      object ToolButton6: TToolButton
        Left = 0
        Top = 0
        Caption = 'ToolButton6'
        DropdownMenu = PopupMenuDoc
        ImageIndex = 0
      end
      object ToolButton1: TToolButton
        Left = 23
        Top = 0
        Width = 8
        Caption = 'ToolButton1'
        Style = tbsSeparator
      end
      object ToolButtonOpenDoc: TToolButton
        Left = 31
        Top = 0
        Caption = 'ToolButtonOpenDoc'
        ImageIndex = 1
        OnClick = ToolButtonOpenDocClick
      end
      object ToolButtonViborPerioda: TToolButton
        Left = 54
        Top = 0
        Caption = 'ToolButtonViborPerioda'
        ImageIndex = 3
        OnClick = ToolButtonViborPeriodaClick
      end
      object ToolButtonOpenDvDoc: TToolButton
        Left = 77
        Top = 0
        Hint = #1044#1074#1080#1078#1077#1085#1080#1103' '#1076#1086#1082#1091#1084#1077#1085#1090#1072
        Caption = 'ToolButtonOpenDvDoc'
        ImageIndex = 13
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonOpenDvDocClick
      end
      object ToolButtonParamOtbor: TToolButton
        Left = 100
        Top = 0
        Hint = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1086#1090#1073#1086#1088#1072
        ImageIndex = 33
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonParamOtborClick
      end
      object ToolButtonOtbor: TToolButton
        Left = 123
        Top = 0
        Hint = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1086#1090#1073#1086#1088#1086#1084
        Caption = 'ToolButtonOtbor'
        ImageIndex = 30
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
        OnClick = ToolButtonOtborClick
      end
      object ToolButtonNoCheck: TToolButton
        Left = 146
        Top = 0
        Hint = #1041#1077#1079' '#1095#1077#1082#1086#1074
        Caption = 'ToolButtonNoCheck'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        Style = tbsCheck
      end
      object ToolButton5: TToolButton
        Left = 169
        Top = 0
        Hint = #1055#1077#1095#1072#1090#1100' '#1088#1077#1077#1089#1090#1088#1072
        Caption = 'ToolButtonPrintReestr'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton5Click
      end
      object ToolButton2: TToolButton
        Left = 192
        Top = 0
        Width = 82
        Caption = 'ToolButton2'
        ImageIndex = 3
        Style = tbsSeparator
      end
      object ToolButton3: TToolButton
        Left = 274
        Top = 0
        Hint = #1054#1090#1084#1077#1085#1080#1090#1100' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1077
        Caption = 'ToolButton3'
        ImageIndex = 12
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton3Click
      end
      object ToolButtonDelete: TToolButton
        Left = 297
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100
        Caption = 'ToolButtonDelete'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDeleteClick
      end
      object ToolButtonAllCancelDvReg: TToolButton
        Left = 320
        Top = 0
        Hint = #1054#1090#1084#1077#1085#1080#1090#1100' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1077' '#1074#1089#1077#1093' '#1076#1086#1082#1091#1084#1077#1085#1090#1086#1074
        Caption = 'ToolButtonAllCancelDvReg'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonAllCancelDvRegClick
      end
      object ToolButtonDvRegDoc: TToolButton
        Left = 343
        Top = 0
        Hint = #1055#1088#1086#1074#1077#1089#1090#1080' '#1074#1089#1077' '#1076#1086#1082#1091#1084#1077#1085#1090#1099
        Caption = 'ToolButtonDvRegDoc'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDvRegDocClick
      end
      object ToolButtonReportOtrSpis: TToolButton
        Left = 366
        Top = 0
        Hint = #1054#1090#1088#1080#1094'. '#1089#1087#1080#1089#1072#1085#1080#1077
        Caption = 'ToolButtonReportOtrSpis'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonDelAllDoc: TToolButton
        Left = 389
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1074#1089#1077' '#1076#1086#1082#1091#1084#1077#1085#1090#1099
        Caption = '---'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonDelAllDocClick
      end
      object ToolButtonZapolnPoNZ: TToolButton
        Left = 412
        Top = 0
        Hint = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090#1072#1084#1080' '#1089' '#1085' '#1079#1072#1103#1074#1082#1072#1084#1080
        Caption = 'ToolButtonZapolnPoNZ'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonZapolnPoNZClick
      end
      object ToolButton4: TToolButton
        Left = 435
        Top = 0
        Width = 64
        Caption = 'ToolButton4'
        ImageIndex = 0
        Style = tbsSeparator
      end
      object ToolButtonRefresh: TToolButton
        Left = 499
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100
        Caption = 'ToolButtonRefresh'
        ImageIndex = 48
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonRefreshClick
      end
      object ToolButtonOpenExtModule: TToolButton
        Left = 522
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonOpenExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCopyDoc: TToolButton
        Left = 545
        Top = 0
        Hint = #1057#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1074' '#1085#1086#1074#1099#1081
        Caption = 'ToolButtonCopyDoc'
        DropdownMenu = PopupMenuCopyDoc
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateNaOsn: TToolButton
        Left = 568
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1085#1072' '#1086#1089#1085#1086#1074#1072#1085#1080#1080
        Caption = 'ToolButtonCreateNaOsn'
        DropdownMenu = PopupMenuCreateNaOsn
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButton7: TToolButton
        Left = 591
        Top = 0
        Width = 161
        Caption = 'ToolButton7'
        ImageIndex = 46
        Style = tbsSeparator
      end
      object ToolButtonCreateDocProverka: TToolButton
        Left = 752
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1087#1088#1086#1074#1077#1088#1082#1072
        Caption = 'ToolButtonCreateDocProverka'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateDocProverkaClick
      end
      object ToolButtonCreateDocVigr: TToolButton
        Left = 775
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1074#1099#1075#1088#1091#1079#1082#1072
        Caption = 'ToolButtonCreateDocVigr'
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonCreateDocVigrClick
      end
    end
    object Panel5: TPanel
      Left = 0
      Top = 54
      Width = 815
      Height = 96
      Margins.Left = 2
      Margins.Top = 2
      Margins.Right = 2
      Margins.Bottom = 2
      Align = alBottom
      BevelEdges = []
      BevelOuter = bvNone
      TabOrder = 1
      object NameZayavkacxButtonEdit: TcxButtonEdit
        Left = 119
        Top = 12
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = NameZayavkacxButtonEditPropertiesButtonClick
        TabOrder = 0
        Text = 'NameZayavkacxButtonEdit'
        Width = 222
      end
      object NameHardwarecxButtonEdit: TcxButtonEdit
        Left = 496
        Top = 12
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Properties.Buttons = <
          item
            Default = True
            Kind = bkEllipsis
          end
          item
            Caption = 'X'
            Kind = bkText
          end>
        Properties.OnButtonClick = NameHardwarecxButtonEditPropertiesButtonClick
        TabOrder = 1
        Text = 'NameHardwarecxButtonEdit'
        Width = 252
      end
      object cxButtonOtborPoZayavka: TcxButton
        Left = 251
        Top = 72
        Width = 136
        Height = 21
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1055#1086' '#1079#1072#1103#1074#1082#1077
        TabOrder = 2
        OnClick = cxButtonOtborPoZayavkaClick
      end
      object cxButtonOtborPoHardware: TcxButton
        Left = 678
        Top = 72
        Width = 125
        Height = 21
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1055#1086' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1102
        TabOrder = 3
        OnClick = cxButtonOtborPoHardwareClick
      end
      object cxLabel1: TcxLabel
        Left = 405
        Top = 18
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077':'
      end
      object cxLabel2: TcxLabel
        Left = 9
        Top = 13
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = #1047#1072#1103#1074#1082#1072' '#1085#1072' '#1088#1077#1084#1086#1085#1090':'
      end
      object NameKlientcxLabel: TcxLabel
        Left = 12
        Top = 34
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = 'NameKlientcxLabel'
      end
      object NameModelcxLabel: TcxLabel
        Left = 13
        Top = 47
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = 'NameModelcxLabel'
      end
      object SerNumcxLabel: TcxLabel
        Left = 13
        Top = 59
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = 'SerNumcxLabel'
      end
      object SerNum2cxLabel: TcxLabel
        Left = 159
        Top = 59
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = 'SerNum2cxLabel'
      end
      object NameModelHwcxLabel: TcxLabel
        Left = 405
        Top = 37
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = 'NameModelHwcxLabel'
      end
      object SerNumHwcxLabel: TcxLabel
        Left = 405
        Top = 52
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = 'SerNumHwcxLabel'
      end
      object SerNum2HwcxLabel: TcxLabel
        Left = 618
        Top = 52
        Margins.Left = 2
        Margins.Top = 2
        Margins.Right = 2
        Margins.Bottom = 2
        Caption = 'SerNum2HwcxLabel'
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 150
    Width = 9
    Height = 208
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 358
    Width = 815
    Height = 57
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 803
    Top = 150
    Width = 12
    Height = 208
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object cxGrid1: TcxGrid
    Left = 9
    Top = 150
    Width = 794
    Height = 208
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
      OnDblClick = cxGrid1DBTableView1DblClick
      OnKeyPress = cxGrid1DBTableView1KeyPress
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = REM_DMGurAllDoc.DataSourceTable
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          Column = cxGrid1DBTableView1SUMDOC
        end
        item
          Kind = skCount
          Column = cxGrid1DBTableView1TDOC
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsCustomize.ColumnsQuickCustomization = True
      OptionsData.Editing = False
      OptionsView.NoDataToDisplayInfoText = '<'#1053#1077#1090' '#1076#1072#1085#1085#1099#1093'>'
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1PRDOC: TcxGridDBColumn
        Caption = #1055#1088'.'
        DataBinding.FieldName = 'PR_REM_GALLDOC'
        OnCustomDrawCell = cxGrid1DBTableView1PRDOCCustomDrawCell
        Width = 41
      end
      object cxGrid1DBTableView1NAME_SINFBASE_OBMEN: TcxGridDBColumn
        Caption = #1041#1072#1079#1072
        DataBinding.FieldName = 'NAME_SINFBASE_OBMEN'
        Width = 55
      end
      object cxGrid1DBTableView1NAMEFIRM: TcxGridDBColumn
        Caption = #1060#1080#1088#1084#1072
        DataBinding.FieldName = 'NAMEFIRM'
        Width = 79
      end
      object cxGrid1DBTableView1POSDOC: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POS_REM_GALLDOC'
        Width = 90
      end
      object cxGrid1DBTableView1TDOC: TcxGridDBColumn
        Caption = #1044#1086#1082#1091#1084#1077#1085#1090
        DataBinding.FieldName = 'TDOC_REM_GALLDOC'
        Width = 95
      end
      object cxGrid1DBTableView1PREFIKS_NUM_REM_GALLDOC: TcxGridDBColumn
        DataBinding.FieldName = 'PREFIKS_NUM_REM_GALLDOC'
        Width = 25
        IsCaptionAssigned = True
      end
      object cxGrid1DBTableView1NUMDOC: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NUM_REM_GALLDOC'
        Width = 46
      end
      object cxGrid1DBTableView1NAMESKLAD: TcxGridDBColumn
        Caption = #1057#1082#1083#1072#1076
        DataBinding.FieldName = 'NAMESKLAD'
        Width = 163
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 161
      end
      object cxGrid1DBTableView1SUMDOC: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_REM_GALLDOC'
        Styles.Content = DM.cxStyleFooterSum
        Width = 62
      end
      object cxGrid1DBTableView1NAME_USER: TcxGridDBColumn
        Caption = #1040#1074#1090#1086#1088
        DataBinding.FieldName = 'NAME_USER'
        Width = 64
      end
      object cxGrid1DBTableView1RES_REM_GUR_PROV: TcxGridDBColumn
        DataBinding.FieldName = 'RES_REM_GUR_PROV'
        OnCustomDrawCell = cxGrid1DBTableView1RES_REM_GUR_PROVCustomDrawCell
        Width = 30
      end
      object cxGrid1DBTableView1IDDOC_REM_GUR_VIGRT: TcxGridDBColumn
        DataBinding.FieldName = 'IDDOC_REM_GUR_VIGRT'
        OnCustomDrawCell = cxGrid1DBTableView1IDDOC_REM_GUR_VIGRTCustomDrawCell
        Width = 24
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object ActionList: TActionList
    Left = 184
    Top = 40
    object ActionOpenHelp: TAction
      Caption = 'ActionOpenHelp'
      ShortCut = 112
      OnExecute = ActionOpenHelpExecute
    end
  end
  object PopupMenuExtModule: TPopupMenu
    Left = 440
    Top = 24
  end
  object PopupMenuDoc: TPopupMenu
    Left = 568
    Top = 32
    object NewDocPrihNakl: TMenuItem
      Caption = #1055#1088#1080#1093#1086#1076#1085#1072#1103' '#1085#1072#1082#1083#1072#1076#1085#1072#1103' ('#1088#1077#1084#1086#1085#1090')'
      OnClick = NewDocPrihNaklClick
    end
    object NewDocReal: TMenuItem
      Caption = #1056#1077#1072#1083#1080#1079#1072#1094#1080#1103
      OnClick = NewDocRealClick
    end
    object NewDocOstNom: TMenuItem
      Caption = #1042#1074#1086#1076' '#1086#1089#1090#1072#1090#1082#1086#1074
      OnClick = NewDocOstNomClick
    end
    object NewDocSborkaKompl: TMenuItem
      Caption = #1057#1073#1086#1088#1082#1072' '#1082#1086#1084#1087#1083#1077#1082#1090#1072
      OnClick = NewDocSborkaKomplClick
    end
    object NewDocPostOtDilera: TMenuItem
      Caption = #1055#1086#1089#1090#1091#1087#1083#1077#1085#1080#1077' '#1086#1090' '#1076#1080#1083#1077#1088#1072
      OnClick = NewDocPostOtDileraClick
    end
    object NewDocVosvratDileru: TMenuItem
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1076#1080#1083#1077#1088#1091
      OnClick = NewDocVosvratDileruClick
    end
    object NewDocPerServCentr: TMenuItem
      Caption = #1055#1077#1088#1077#1076#1072#1095#1072' '#1074' '#1057#1062
      OnClick = NewDocPerServCentrClick
    end
    object NewDocVosvrstIsSC: TMenuItem
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1080#1079' '#1057#1062
      OnClick = NewDocVosvrstIsSCClick
    end
    object NewDocVosvratPok: TMenuItem
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1086#1090' '#1087#1086#1082#1091#1087#1072#1090#1077#1083#1103
      OnClick = NewDocVosvratPokClick
    end
    object CreateNewDocAktPopupMenu: TMenuItem
      Caption = #1040#1082#1090
      OnClick = CreateNewDocAktPopupMenuClick
    end
    object CreateNewDocPerPopupMenu: TMenuItem
      Caption = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077
      OnClick = CreateNewDocPerPopupMenuClick
    end
    object CreateNewDocSpisNomPopupMenu: TMenuItem
      Caption = #1057#1087#1080#1089#1072#1085#1080#1077' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
      OnClick = CreateNewDocSpisNomPopupMenuClick
    end
    object CreateNewDocRegOtchetPostPopupMenu: TMenuItem
      Caption = #1044#1074'. '#1088#1077#1075#1080#1089#1090#1088#1072' '#1054#1090#1095#1077#1090' '#1087#1086#1089#1090#1072#1074#1097#1080#1082#1091
      OnClick = CreateNewDocRegOtchetPostPopupMenuClick
    end
    object CreateNewDocVidachaHWPopupMenu: TMenuItem
      Caption = #1042#1099#1076#1072#1095#1072' '#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
      OnClick = CreateNewDocVidachaHWPopupMenuClick
    end
    object CreateNewDocVosvratHWPopupMenu: TMenuItem
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
      OnClick = CreateNewDocVosvratHWPopupMenuClick
    end
    object CreateDocZakazPost: TMenuItem
      Caption = #1047#1072#1082#1072#1079' '#1055#1086#1089#1090#1072#1074#1097#1080#1082#1091
      OnClick = CreateDocZakazPostClick
    end
    object N1: TMenuItem
      Caption = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077' '#1074#1086#1079#1074#1088'. '#1047#1048#1055
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1080#1089#1087'. '#1047#1048#1055' '#1055#1086#1089#1090#1072#1074#1097#1080#1082#1091
      OnClick = N2Click
    end
  end
  object PopupMenuCopyDoc: TPopupMenu
    Left = 664
    Top = 32
    object PMCopyDocPer: TMenuItem
      Caption = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077
      OnClick = PMCopyDocPerClick
    end
    object PMCopyAktInAkt: TMenuItem
      Caption = #1040#1082#1090' - '#1040#1082#1090
      OnClick = PMCopyAktInAktClick
    end
  end
  object PopupMenuCreateNaOsn: TPopupMenu
    Left = 728
    Top = 40
    object PopupMenuCreateNaOsnDocPer: TMenuItem
      Caption = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077
      OnClick = PopupMenuCreateNaOsnDocPerClick
    end
    object PopupMenuCreateNaOsnDocOstNom: TMenuItem
      Caption = #1042#1074#1086#1076' '#1086#1089#1090#1072#1090#1082#1086#1074
      OnClick = PopupMenuCreateNaOsnDocOstNomClick
    end
  end
end
