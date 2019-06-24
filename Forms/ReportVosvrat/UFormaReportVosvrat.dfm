object FormaReportVosvrat: TFormaReportVosvrat
  Left = 0
  Top = 0
  Caption = #1042#1086#1079#1074#1088#1072#1090#1099' '#1088#1077#1072#1083#1080#1079#1086#1074#1072#1085#1085#1099#1093' '#1090#1086#1074#1072#1088#1086#1074' '#1080' '#1091#1089#1083#1091#1075
  ClientHeight = 372
  ClientWidth = 674
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 674
    Height = 91
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object cxLabel1: TcxLabel
      Left = 10
      Top = 0
      Caption = #1042#1086#1079#1074#1088#1072#1090#1099' '#1087#1088#1086#1076#1072#1078' '#1089
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -19
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object PosNachcxDateEdit: TcxDateEdit
      Left = 191
      Top = 7
      TabOrder = 1
      Width = 151
    end
    object PosConcxDateEdit: TcxDateEdit
      Left = 392
      Top = 7
      TabOrder = 2
      Width = 158
    end
    object NameKassacxButtonEdit: TcxButtonEdit
      Left = 56
      Top = 64
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
      Properties.OnButtonClick = NameKassacxButtonEditPropertiesButtonClick
      TabOrder = 3
      Text = 'NameKassacxButtonEdit'
      Width = 242
    end
    object cxLabel3: TcxLabel
      Left = 348
      Top = 7
      Caption = #1087#1086
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -19
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object cxLabel4: TcxLabel
      Left = 13
      Top = 68
      Caption = #1050#1072#1089#1089#1072':'
    end
    object NameFirmcxButtonEdit: TcxButtonEdit
      Left = 56
      Top = 41
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
      Properties.OnButtonClick = NameFirmcxButtonEditPropertiesButtonClick
      TabOrder = 6
      Text = 'NameFirmcxButtonEdit'
      Width = 242
    end
    object cxLabel2: TcxLabel
      Left = 10
      Top = 45
      Caption = #1060#1080#1088#1084#1072':'
    end
    object cxButtonCreate: TcxButton
      Left = 316
      Top = 60
      Width = 98
      Height = 25
      Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
      TabOrder = 8
      OnClick = cxButtonCreateClick
    end
    object cxButtonPrintKM3: TcxButton
      Left = 428
      Top = 60
      Width = 75
      Height = 25
      Caption = #1050#1052'-3'
      TabOrder = 9
      OnClick = cxButtonPrintKM3Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 331
    Width = 674
    Height = 41
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object cxButtonClose: TcxButton
      Left = 565
      Top = 6
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = cxButtonCloseClick
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 91
    Width = 674
    Height = 240
    Align = alClient
    TabOrder = 2
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DMReportVosvrat.DataSourceNal
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          Column = cxGrid1DBTableView1SUMDOC
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      Styles.Footer = DM.cxStyleHeaderTable
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1POSDOC: TcxGridDBColumn
        Caption = #1044#1072#1090#1072
        DataBinding.FieldName = 'POSDOC'
        Width = 94
      end
      object cxGrid1DBTableView1NUMDOC: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1088
        DataBinding.FieldName = 'NUMDOC'
        Width = 53
      end
      object cxGrid1DBTableView1NAMEKKM: TcxGridDBColumn
        Caption = #1050#1072#1089#1089#1072
        DataBinding.FieldName = 'NAMEKKM'
      end
      object cxGrid1DBTableView1SUMDOC: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUMDOC'
        Width = 69
      end
      object cxGrid1DBTableView1OPERATION_DRKOROZN: TcxGridDBColumn
        Caption = #1054#1087#1077#1088'.'
        DataBinding.FieldName = 'OPERATION_DRKOROZN'
        Width = 54
      end
      object cxGrid1DBTableView1NKL_DRKOROZN: TcxGridDBColumn
        Caption = #8470' '#1050#1051
        DataBinding.FieldName = 'NKL_DRKOROZN'
        Width = 53
      end
      object cxGrid1DBTableView1NCHECK_DRKOROZN: TcxGridDBColumn
        Caption = #8470' '#1095#1077#1082#1072
        DataBinding.FieldName = 'NCHECK_DRKOROZN'
        Width = 54
      end
      object cxGrid1DBTableView1MODEL_DRKOROZN: TcxGridDBColumn
        Caption = #1050#1050#1052
        DataBinding.FieldName = 'MODEL_DRKOROZN'
        Width = 103
      end
      object cxGrid1DBTableView1REGNUM_DRKOROZN: TcxGridDBColumn
        Caption = #1056#1077#1075'. '#1085#1086#1084#1077#1088
        DataBinding.FieldName = 'REGNUM_DRKOROZN'
        Width = 104
      end
      object cxGrid1DBTableView1SAVNUM_DRKOROZN: TcxGridDBColumn
        Caption = #1047#1072#1074#1086#1076'. '#1085#1086#1084#1077#1088
        DataBinding.FieldName = 'SAVNUM_DRKOROZN'
        Width = 88
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
end
