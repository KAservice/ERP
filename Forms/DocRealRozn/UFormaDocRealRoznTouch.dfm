object FormaDocRealRoznTouch: TFormaDocRealRoznTouch
  Left = 188
  Top = 123
  Caption = #1040#1082#1090' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080' '#1088#1077#1089#1090#1086#1088#1072#1085#1072
  ClientHeight = 532
  ClientWidth = 752
  Color = clBtnFace
  Constraints.MinWidth = 760
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
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 209
    Width = 5
    Height = 214
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 0
  end
  object Panel3: TPanel
    Left = 0
    Top = 423
    Width = 752
    Height = 109
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object FSummaCheck: TLabel
      Left = 520
      Top = 16
      Width = 70
      Height = 24
      Caption = #1057#1091#1084#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBTextFNameUser: TDBText
      Left = 8
      Top = 88
      Width = 119
      Height = 16
      AutoSize = True
      DataField = 'FNAME_USER'
      DataSource = DMDocRealRozn.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object SumDocDBText: TDBText
      Left = 592
      Top = 16
      Width = 135
      Height = 24
      AutoSize = True
      DataField = 'SUMDOC'
      DataSource = DMDocRealRozn.DataSourceDocAll
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ButtonClose: TButton
      Left = 656
      Top = 48
      Width = 75
      Height = 57
      Caption = #1047#1072#1082#1088#1099#1090#1100
      TabOrder = 0
      OnClick = ButtonCloseClick
    end
    object ButtonOK: TButton
      Left = 576
      Top = 48
      Width = 75
      Height = 57
      Caption = 'OK'
      TabOrder = 1
      OnClick = ButtonOKClick
    end
    object ButtonPrint: TButton
      Left = 496
      Top = 48
      Width = 75
      Height = 57
      Caption = #1055#1077#1095#1072#1090#1100
      TabOrder = 2
      OnClick = ButtonPrintClick
    end
  end
  object Panel4: TPanel
    Left = 743
    Top = 209
    Width = 9
    Height = 214
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 2
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 752
    Height = 209
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 3
    object LabelNameDoc: TLabel
      Left = 8
      Top = 72
      Width = 207
      Height = 26
      Caption = #1040#1082#1090' '#1088#1077#1072#1083#1080#1079#1072#1094#1080#1080' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -23
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelPrim: TLabel
      Left = 16
      Top = 168
      Width = 66
      Height = 13
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
    end
    object LabelFirm: TLabel
      Left = 8
      Top = 13
      Width = 54
      Height = 16
      Caption = #1060#1080#1088#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelSklad: TLabel
      Left = 368
      Top = 13
      Width = 50
      Height = 16
      Caption = #1057#1082#1083#1072#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabelKlient: TLabel
      Left = 8
      Top = 120
      Width = 68
      Height = 20
      Caption = #1050#1083#1080#1077#1085#1090':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object NameFirmDBText: TDBText
      Left = 68
      Top = 7
      Width = 266
      Height = 33
      DataField = 'NAMEFIRM'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object NameSkladDBText: TDBText
      Left = 424
      Top = 7
      Width = 273
      Height = 30
      DataField = 'NAMESKLAD'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object NameKlientDBText: TDBText
      Left = 96
      Top = 113
      Width = 617
      Height = 37
      DataField = 'NAMEKLIENT'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object PrimDBText: TDBText
      Left = 96
      Top = 160
      Width = 417
      Height = 29
      DataField = 'PRIM_DREALROZN'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object NumDocDBText: TDBText
      Left = 232
      Top = 71
      Width = 129
      Height = 27
      DataField = 'NUMDOC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object DateDocDBText: TDBText
      Left = 392
      Top = 71
      Width = 217
      Height = 27
      DataField = 'POSDOC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
  object cxGrid1: TcxGrid
    Left = 5
    Top = 209
    Width = 738
    Height = 214
    Align = alClient
    TabOrder = 4
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DMDocRealRozn.DataSourceDocT
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <
        item
          Kind = skSum
          FieldName = 'SUM_DREALROZNT'
          Column = cxGrid1DBTableView1SUM_DREALROZNT
        end
        item
          Kind = skSum
          FieldName = 'SUMSK_DREALROZNT'
          Column = cxGrid1DBTableView1SUMSK_DREALROZNT
        end>
      DataController.Summary.SummaryGroups = <>
      OptionsView.ColumnAutoWidth = True
      OptionsView.Footer = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        Caption = #8470
        DataBinding.FieldName = 'RECNO'
        Width = 45
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        Caption = #1053#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1072
        DataBinding.FieldName = 'NAMENOM'
        Width = 227
      end
      object cxGrid1DBTableView1KOL_DREALROZNT: TcxGridDBColumn
        Caption = #1050#1086#1083'.'
        DataBinding.FieldName = 'KOL_DREALROZNT'
        Width = 53
      end
      object cxGrid1DBTableView1NAMEED: TcxGridDBColumn
        Caption = #1045#1076#1080#1085#1080#1094#1072
        DataBinding.FieldName = 'NAMEED'
        Width = 80
      end
      object cxGrid1DBTableView1KF_DREALROZNT: TcxGridDBColumn
        Caption = #1050#1060
        DataBinding.FieldName = 'KF_DREALROZNT'
        Width = 66
      end
      object cxGrid1DBTableView1PRICE_DREALROZNT: TcxGridDBColumn
        Caption = #1062#1077#1085#1072
        DataBinding.FieldName = 'PRICE_DREALROZNT'
        Width = 67
      end
      object cxGrid1DBTableView1SUM_DREALROZNT: TcxGridDBColumn
        Caption = #1057#1091#1084#1084#1072
        DataBinding.FieldName = 'SUM_DREALROZNT'
        Styles.Content = DM.cxStyleFooterSum
        Width = 82
      end
      object cxGrid1DBTableView1PRSK_DREALROZNT: TcxGridDBColumn
        Caption = '-%'
        DataBinding.FieldName = 'PRSK_DREALROZNT'
        Width = 31
      end
      object cxGrid1DBTableView1SUMSK_DREALROZNT: TcxGridDBColumn
        Caption = #1057#1082#1080#1076#1082#1072
        DataBinding.FieldName = 'SUMSK_DREALROZNT'
        Width = 85
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
end
