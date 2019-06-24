object REM_FormaGurZAktPr: TREM_FormaGurZAktPr
  Left = 268
  Top = 221
  Caption = #1046#1091#1088#1085#1072#1083' '#1072#1082#1090#1086#1074' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1102':'
  ClientHeight = 511
  ClientWidth = 1003
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
  WindowState = wsMaximized
  OnClose = FormClose
  OnResize = FormResize
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1003
    Height = 185
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 0
    object LabelInterval: TLabel
      Left = 290
      Top = 39
      Width = 71
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1055#1077#1088#1080#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 16
      Top = 39
      Width = 266
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = #1046#1091#1088#1085#1072#1083' '#1072#1082#1090#1086#1074' '#1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1102':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object StrOtborLabel: TLabel
      Left = 677
      Top = 49
      Width = 192
      Height = 20
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Alignment = taRightJustify
      Caption = #1050#1086#1085#1090#1088#1072#1075#1077#1085#1090' '#1085#1077' '#1074#1099#1073#1088#1072#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ToolBar1: TToolBar
      Left = 0
      Top = 0
      Width = 1003
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
      object ToolButton4: TToolButton
        Left = 412
        Top = 0
        Width = 64
        Caption = 'ToolButton4'
        ImageIndex = 0
        Style = tbsSeparator
      end
      object ToolButtonRefresh: TToolButton
        Left = 476
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100
        Caption = 'ToolButtonRefresh'
        ImageIndex = 48
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButtonRefreshClick
      end
      object ToolButtonOpenExtModule: TToolButton
        Left = 499
        Top = 0
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1074#1085#1077#1096#1085#1080#1081' '#1084#1086#1076#1091#1083#1100
        Caption = 'ToolButtonOpenExtModule'
        DropdownMenu = PopupMenuExtModule
        ImageIndex = 51
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCopyDoc: TToolButton
        Left = 522
        Top = 0
        Hint = #1057#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1074' '#1085#1086#1074#1099#1081
        Caption = 'ToolButtonCopyDoc'
        DropdownMenu = PopupMenuCopyDoc
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
      object ToolButtonCreateNaOsn: TToolButton
        Left = 545
        Top = 0
        Hint = #1057#1086#1079#1076#1072#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1085#1072' '#1086#1089#1085#1086#1074#1072#1085#1080#1080
        Caption = 'ToolButtonCreateNaOsn'
        DropdownMenu = PopupMenuCreateNaOsn
        ImageIndex = 45
        ParentShowHint = False
        ShowHint = True
      end
    end
    object Panel5: TPanel
      Left = 0
      Top = 66
      Width = 1003
      Height = 119
      Align = alBottom
      BevelEdges = []
      BevelOuter = bvNone
      TabOrder = 1
      object NameZayavkacxButtonEdit: TcxButtonEdit
        Left = 146
        Top = 15
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
        Width = 274
      end
      object NameHardwarecxButtonEdit: TcxButtonEdit
        Left = 610
        Top = 15
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
        Width = 311
      end
      object cxButtonOtborPoZayavka: TcxButton
        Left = 309
        Top = 89
        Width = 167
        Height = 25
        Caption = #1055#1086' '#1079#1072#1103#1074#1082#1077
        TabOrder = 2
        OnClick = cxButtonOtborPoZayavkaClick
      end
      object cxButtonOtborPoHardware: TcxButton
        Left = 834
        Top = 89
        Width = 154
        Height = 25
        Caption = #1055#1086' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1102
        TabOrder = 3
        OnClick = cxButtonOtborPoHardwareClick
      end
      object cxLabel1: TcxLabel
        Left = 499
        Top = 22
        Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077':'
      end
      object cxLabel2: TcxLabel
        Left = 11
        Top = 16
        Caption = #1047#1072#1103#1074#1082#1072' '#1085#1072' '#1088#1077#1084#1086#1085#1090':'
      end
      object NameKlientcxLabel: TcxLabel
        Left = 15
        Top = 42
        Caption = 'NameKlientcxLabel'
      end
      object NameModelcxLabel: TcxLabel
        Left = 16
        Top = 58
        Caption = 'NameModelcxLabel'
      end
      object SerNumcxLabel: TcxLabel
        Left = 16
        Top = 72
        Caption = 'SerNumcxLabel'
      end
      object SerNum2cxLabel: TcxLabel
        Left = 196
        Top = 72
        Caption = 'SerNum2cxLabel'
      end
      object NameModelHwcxLabel: TcxLabel
        Left = 499
        Top = 45
        Caption = 'NameModelHwcxLabel'
      end
      object SerNumHwcxLabel: TcxLabel
        Left = 499
        Top = 64
        Caption = 'SerNumHwcxLabel'
      end
      object SerNum2HwcxLabel: TcxLabel
        Left = 760
        Top = 64
        Caption = 'SerNum2HwcxLabel'
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 185
    Width = 11
    Height = 256
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alLeft
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 441
    Width = 1003
    Height = 70
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 2
  end
  object Panel4: TPanel
    Left = 988
    Top = 185
    Width = 15
    Height = 256
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alRight
    BevelOuter = bvNone
    Caption = ' '
    TabOrder = 3
  end
  object cxGrid1: TcxGrid
    Left = 11
    Top = 185
    Width = 977
    Height = 256
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
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
          Kind = skCount
          FieldName = 'ID_REM_GALLDOC'
          Column = cxGrid1DBTableView1KLIENT_NAME_REM_DZAKTPR
        end
        item
          Kind = skSum
          FieldName = 'SUM_REM_GALLDOC'
          Column = cxGrid1DBTableView1SUMDOC
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsCustomize.ColumnsQuickCustomization = True
      OptionsData.Editing = False
      OptionsView.NoDataToDisplayInfoText = '<'#1053#1077#1090' '#1076#1072#1085#1085#1099#1093'>'
      OptionsView.CellAutoHeight = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1PRDOC: TcxGridDBColumn
        Caption = #1055#1088'.'
        DataBinding.FieldName = 'PR_REM_GALLDOC'
        OnCustomDrawCell = cxGrid1DBTableView1PRDOCCustomDrawCell
        Width = 21
      end
      object cxGrid1DBTableView1NAME_SINFBASE_OBMEN: TcxGridDBColumn
        Caption = #1041#1072#1079#1072
        DataBinding.FieldName = 'NAME_SINFBASE_OBMEN'
        Visible = False
        Width = 39
      end
      object cxGrid1DBTableView1NAMEFIRM: TcxGridDBColumn
        Caption = #1060#1080#1088#1084#1072
        DataBinding.FieldName = 'NAMEFIRM'
        Visible = False
        Width = 53
      end
      object cxGrid1DBTableView1FL_ADDREPORT_REM_Z: TcxGridDBColumn
        Caption = #1054#1090#1095#1080#1090#1072#1085
        DataBinding.FieldName = 'FL_ADDREPORT_REM_Z'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Styles.Content = DM.cxStyleclSilver
        Width = 21
      end
      object cxGrid1DBTableView1FL_POVTOR_REM_Z: TcxGridDBColumn
        Caption = #1055#1086#1074#1090#1086#1088
        DataBinding.FieldName = 'FL_POVTOR_REM_Z'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 29
      end
      object cxGrid1DBTableView1FL_NADO_OTCH_REM_Z: TcxGridDBColumn
        Caption = #1053#1072#1076#1086' '#1086#1090#1095#1080#1090#1072#1090#1100' '#1079#1072#1103#1074#1082#1091
        DataBinding.FieldName = 'FL_NADO_OTCH_REM_Z'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Styles.Content = DM.cxStyleclMoneyGreen
        Width = 26
      end
      object cxGrid1DBTableView1FL_NADO_OTCH_DZAKTPR: TcxGridDBColumn
        Caption = #1053#1072#1076#1086' '#1086#1090#1095#1080#1090#1072#1090#1100' '#1072#1082#1090
        DataBinding.FieldName = 'FL_NADO_OTCH_REM_DZAKTPR'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Styles.Content = DM.cxStyleclMoneyGreen
        Width = 25
      end
      object cxGrid1DBTableView1FL_NE_OTCH_REM_Z: TcxGridDBColumn
        Caption = #1053#1077' '#1086#1090#1095#1080#1090#1099#1074#1072#1090#1100' '#1079#1072#1103#1074#1082#1091
        DataBinding.FieldName = 'FL_NE_OTCH_REM_Z'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Styles.Content = DM.cxStyleclSkyBlue
        Width = 24
      end
      object cxGrid1DBTableView1FL_NE_OTCH_DZAKTPR: TcxGridDBColumn
        Caption = #1053#1077' '#1086#1090#1095#1080#1090#1099#1074#1072#1090#1100' '#1072#1082#1090
        DataBinding.FieldName = 'FL_NE_OTCH_REM_DZAKTPR'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Styles.Content = DM.cxStyleclSkyBlue
        Width = 30
      end
      object cxGrid1DBTableView1POS_REM_Z: TcxGridDBColumn
        Caption = #1055#1088#1080#1085#1103#1090#1086
        DataBinding.FieldName = 'POS_REM_Z'
        Width = 38
      end
      object cxGrid1DBTableView1POSPRIEMA_REM_DZAKTPR: TcxGridDBColumn
        Caption = #1055#1088#1080#1085#1103#1090#1086' '#1080#1079' '#1076#1086#1082'.'
        DataBinding.FieldName = 'POSPRIEMA_REM_DZAKTPR'
        Width = 38
      end
      object cxGrid1DBTableView1POSDOC: TcxGridDBColumn
        Caption = #1044#1072#1090#1072' '#1076#1086#1082'.'
        DataBinding.FieldName = 'POS_REM_GALLDOC'
        Width = 46
      end
      object cxGrid1DBTableView1PREFIKS_NUM_REM_GALLDOC: TcxGridDBColumn
        DataBinding.FieldName = 'PREFIKS_NUM_REM_GALLDOC'
        Width = 21
        IsCaptionAssigned = True
      end
      object cxGrid1DBTableView1NUMDOC: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NUM_REM_GALLDOC'
        Width = 25
      end
      object cxGrid1DBTableView1NAMESKLAD: TcxGridDBColumn
        Caption = #1057#1082#1083#1072#1076
        DataBinding.FieldName = 'NAMESKLAD'
        Width = 38
      end
      object cxGrid1DBTableView1NAMEKLIENT: TcxGridDBColumn
        Caption = #1055#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100
        DataBinding.FieldName = 'NAMEKLIENT'
        Width = 29
      end
      object cxGrid1DBTableView1NAME_USER: TcxGridDBColumn
        Caption = #1040#1074#1090#1086#1088
        DataBinding.FieldName = 'NAME_USER'
        Visible = False
        Width = 51
      end
      object cxGrid1DBTableView1KLIENT_NAME_REM_DZAKTPR: TcxGridDBColumn
        Caption = #1050#1083#1080#1077#1085#1090
        DataBinding.FieldName = 'KLIENT_NAME_REM_DZAKTPR'
        Width = 77
      end
      object cxGrid1DBTableView1KLIENT_ADR_REM_DZAKTPR: TcxGridDBColumn
        Caption = #1040#1076#1088#1077#1089
        DataBinding.FieldName = 'KLIENT_ADR_REM_DZAKTPR'
        Width = 74
      end
      object cxGrid1DBTableViewKLIENT_PHONE_REM_DZAKTPR: TcxGridDBColumn
        Caption = #1058#1077#1083#1077#1092#1086#1085
        DataBinding.FieldName = 'KLIENT_PHONE_REM_DZAKTPR'
        Width = 44
      end
      object cxGrid1DBTableView1NAME_REM_SPRMODEL: TcxGridDBColumn
        Caption = #1052#1086#1076#1077#1083#1100
        DataBinding.FieldName = 'NAME_REM_SPRMODEL'
        Width = 45
      end
      object cxGrid1DBTableView1NUM_GAR_DOC_REM_Z: TcxGridDBColumn
        Caption = #8470' '#1075#1072#1088'. '#1076#1086#1082'.'
        DataBinding.FieldName = 'numgartalon_rem_dzaktpr'
        Width = 51
      end
      object cxGrid1DBTableView1SERNUM_REM_Z: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'SERNUM_REM_Z'
        Width = 59
      end
      object cxGrid1DBTableView1SERNUM2_REM_Z: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088' 2'
        DataBinding.FieldName = 'SERNUM2_REM_Z'
        Width = 53
      end
      object cxGrid1DBTableView1SUMDOC: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_REM_GALLDOC'
        Styles.Content = DM.cxStyleFooterSum
        Width = 33
      end
      object cxGrid1DBTableView1FL_FICTIV_REM_DZAKTPR: TcxGridDBColumn
        Caption = #1060#1080#1082#1090'.'
        DataBinding.FieldName = 'FL_FICTIV_REM_DZAKTPR'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 21
      end
      object cxGrid1DBTableView1FL_FICTIV_REM_Z: TcxGridDBColumn
        Caption = #1060#1080#1082#1090'. '#1079#1072#1103#1074#1082#1072
        DataBinding.FieldName = 'FL_FICTIV_REM_Z'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.ValueChecked = 1
        Properties.ValueUnchecked = 0
        Width = 21
      end
      object cxGrid1DBTableView1ID_REM_GALLDOC: TcxGridDBColumn
        DataBinding.FieldName = 'ID_REM_GALLDOC'
        Visible = False
        Width = 64
      end
      object cxGrid1DBTableView1SROK_REMONTA: TcxGridDBColumn
        Caption = #1057#1088#1086#1082' '#1088#1077#1084#1086#1085#1090#1072
        DataBinding.FieldName = 'SROK_REMONTA'
        Width = 23
      end
      object cxGrid1DBTableView1SROK_REMONTA_IS_DOC: TcxGridDBColumn
        Caption = #1057#1088#1086#1082' '#1088#1077#1084#1086#1085#1090#1072' '#1080#1079' '#1076#1086#1082'.'
        DataBinding.FieldName = 'SROK_REMONTA_IS_DOC'
        Width = 24
      end
      object cxGrid1DBTableView1SROK_REMONTA_NOW: TcxGridDBColumn
        Caption = #1057#1088#1086#1082' '#1088#1077#1084#1086#1085#1090#1072' '#1090#1077#1082'.'
        DataBinding.FieldName = 'SROK_REMONTA_NOW'
        Width = 27
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
    end
    object NewDocReal: TMenuItem
      Caption = #1056#1077#1072#1083#1080#1079#1072#1094#1080#1103
    end
    object NewDocOstNom: TMenuItem
      Caption = #1042#1074#1086#1076' '#1086#1089#1090#1072#1090#1082#1086#1074
    end
    object NewDocSborkaKompl: TMenuItem
      Caption = #1057#1073#1086#1088#1082#1072' '#1082#1086#1084#1087#1083#1077#1082#1090#1072
    end
    object NewDocPostOtDilera: TMenuItem
      Caption = #1055#1086#1089#1090#1091#1087#1083#1077#1085#1080#1077' '#1086#1090' '#1076#1080#1083#1077#1088#1072
    end
    object NewDocVosvratDileru: TMenuItem
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1076#1080#1083#1077#1088#1091
    end
    object NewDocPerServCentr: TMenuItem
      Caption = #1055#1077#1088#1077#1076#1072#1095#1072' '#1074' '#1057#1062
    end
    object NewDocVosvrstIsSC: TMenuItem
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1080#1079' '#1057#1062
    end
    object NewDocVosvratPok: TMenuItem
      Caption = #1042#1086#1079#1074#1088#1072#1090' '#1086#1090' '#1087#1086#1082#1091#1087#1072#1090#1077#1083#1103
    end
    object CreateNewDocAktPopupMenu: TMenuItem
      Caption = #1040#1082#1090
    end
    object CreateNewDocPerPopupMenu: TMenuItem
      Caption = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077
    end
    object CreateNewDocSpisNomPopupMenu: TMenuItem
      Caption = #1057#1087#1080#1089#1072#1085#1080#1077' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
    end
  end
  object PopupMenuCopyDoc: TPopupMenu
    Left = 664
    Top = 32
    object PMCopyDocPer: TMenuItem
      Caption = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077
    end
  end
  object PopupMenuCreateNaOsn: TPopupMenu
    Left = 728
    Top = 40
    object PopupMenuCreateNaOsnDocPer: TMenuItem
      Caption = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077
    end
    object PopupMenuCreateNaOsnDocOstNom: TMenuItem
      Caption = #1042#1074#1086#1076' '#1086#1089#1090#1072#1090#1082#1086#1074
    end
  end
end
