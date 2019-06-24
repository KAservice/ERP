object FormaExportSale: TFormaExportSale
  Left = 0
  Top = 0
  Caption = #1069#1082#1089#1087#1086#1088#1090' '#1087#1088#1086#1076#1072#1078' ('#1087#1086' '#1095#1077#1082#1072#1084' '#1050#1050#1052')'
  ClientHeight = 443
  ClientWidth = 704
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
    Width = 704
    Height = 137
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 340
      Height = 23
      Caption = #1069#1082#1089#1087#1086#1088#1090' '#1087#1088#1086#1076#1072#1078' ('#1087#1086' '#1095#1077#1082#1072#1084' '#1050#1050#1052') '#1089
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 40
      Top = 86
      Width = 26
      Height = 13
      Caption = #1050#1050#1052':'
    end
    object Label3: TLabel
      Left = 40
      Top = 113
      Width = 36
      Height = 13
      Caption = #1057#1082#1083#1072#1076':'
    end
    object Label4: TLabel
      Left = 503
      Top = 16
      Width = 24
      Height = 23
      Caption = #1087#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 32
      Top = 56
      Width = 36
      Height = 13
      Caption = #1060#1080#1088#1084#1072':'
    end
    object Label6: TLabel
      Left = 302
      Top = 113
      Width = 85
      Height = 13
      Caption = #1050#1072#1090#1072#1083#1086#1075' '#1086#1073#1084#1077#1085#1072':'
    end
    object NameKassacxButtonEdit: TcxButtonEdit
      Left = 96
      Top = 83
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.MaxLength = 0
      Properties.OnButtonClick = NameKassacxButtonEditPropertiesButtonClick
      TabOrder = 0
      Text = 'NameKassacxButtonEdit'
      Width = 193
    end
    object NameSkladcxButtonEdit: TcxButtonEdit
      Left = 96
      Top = 110
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.MaxLength = 0
      Properties.OnButtonClick = NameSkladcxButtonEditPropertiesButtonClick
      TabOrder = 1
      Text = 'NameSkladcxButtonEdit'
      Width = 193
    end
    object NachcxDateEdit: TcxDateEdit
      Left = 368
      Top = 21
      Properties.Kind = ckDateTime
      TabOrder = 2
      Width = 121
    end
    object ConcxDateEdit: TcxDateEdit
      Left = 552
      Top = 21
      Properties.Kind = ckDateTime
      TabOrder = 3
      Width = 121
    end
    object PoDatecxCheckBox: TcxCheckBox
      Left = 406
      Top = 56
      Caption = #1087#1086' '#1076#1072#1090#1072#1084
      TabOrder = 4
      Width = 121
    end
    object SalecxRadioButton: TcxRadioButton
      Left = 552
      Top = 55
      Width = 113
      Height = 17
      Caption = #1087#1088#1086#1076#1072#1078#1080
      TabOrder = 5
    end
    object ReturnSalecxRadioButton: TcxRadioButton
      Left = 552
      Top = 78
      Width = 113
      Height = 19
      Caption = #1074#1086#1079#1074#1088#1072#1090#1099' '#1087#1088#1086#1076#1072#1078
      TabOrder = 6
    end
    object NameFirmcxButtonEdit: TcxButtonEdit
      Left = 96
      Top = 56
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.ClickKey = 13
      Properties.MaxLength = 0
      Properties.ReadOnly = True
      Properties.OnButtonClick = NameFirmcxButtonEditPropertiesButtonClick
      TabOrder = 7
      Text = 'NameFirmcxButtonEdit'
      Width = 193
    end
    object PatchcxButtonEdit: TcxButtonEdit
      Left = 406
      Top = 110
      Properties.Buttons = <
        item
          Default = True
          Kind = bkEllipsis
        end>
      Properties.OnButtonClick = PatchcxButtonEditPropertiesButtonClick
      TabOrder = 8
      Text = 'PatchcxButtonEdit'
      Width = 248
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 361
    Width = 704
    Height = 82
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object cxButtonClose: TcxButton
      Left = 598
      Top = 24
      Width = 75
      Height = 25
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = cxButtonCloseClick
    end
    object cxButtonCreate: TcxButton
      Left = 478
      Top = 24
      Width = 107
      Height = 25
      Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100
      TabOrder = 1
      OnClick = cxButtonCreateClick
    end
    object cxButtonExportText: TcxButton
      Left = 56
      Top = 24
      Width = 75
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 2
      OnClick = cxButtonExportTextClick
    end
    object cxButtonExportExcel: TcxButton
      Left = 152
      Top = 24
      Width = 75
      Height = 25
      Caption = 'Excel'
      TabOrder = 3
      OnClick = cxButtonExportExcelClick
    end
    object cxButtonExportHtml: TcxButton
      Left = 248
      Top = 24
      Width = 75
      Height = 25
      Caption = 'HTML'
      TabOrder = 4
      OnClick = cxButtonExportHtmlClick
    end
    object cxButtonExportXML: TcxButton
      Left = 344
      Top = 24
      Width = 75
      Height = 25
      Caption = 'XML'
      TabOrder = 5
      OnClick = cxButtonExportXMLClick
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 137
    Width = 704
    Height = 224
    Align = alClient
    TabOrder = 2
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DMExportSale.DataSourceReport
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          Column = cxGrid1DBTableView1SUM_SALE
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1OPERATION: TcxGridDBColumn
        Caption = #1054#1087#1077#1088'.'
        DataBinding.FieldName = 'OPERCHK'
        Width = 41
      end
      object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
        Caption = #1050#1086#1076
        DataBinding.FieldName = 'CODENOM'
        Width = 42
      end
      object cxGrid1DBTableView1ARTNOM: TcxGridDBColumn
        Caption = #1040#1088#1090#1080#1082#1091#1083
        DataBinding.FieldName = 'ARTNOM'
        Width = 71
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        DataBinding.FieldName = 'NAMENOM'
        Width = 177
      end
      object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
        Caption = #1045#1076#1080#1085#1080#1094#1072
        DataBinding.FieldName = 'NAMEED'
        Width = 74
      end
      object cxGrid1DBTableView1CODE_SED: TcxGridDBColumn
        Caption = #1050#1086#1076' '#1077#1076'.'
        DataBinding.FieldName = 'CODE_SED'
        Width = 55
      end
      object cxGrid1DBTableView1SHED: TcxGridDBColumn
        Caption = #1064#1050' '#1077#1076'.'
        DataBinding.FieldName = 'SHED'
        Width = 72
      end
      object cxGrid1DBTableView1KFED: TcxGridDBColumn
        Caption = #1050#1060
        DataBinding.FieldName = 'KFED'
        Width = 58
      end
      object cxGrid1DBTableView1KOL_SALE: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOL_SALE'
        Width = 54
      end
      object cxGrid1DBTableView1SUM_SALE: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_SALE'
        Width = 58
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 304
    Top = 56
  end
end
