object FormaKladrViborRegion: TFormaKladrViborRegion
  Left = 0
  Top = 0
  Caption = #1050#1083#1072#1089#1089#1080#1092#1080#1082#1072#1090#1086#1088' '#1072#1076#1088#1077#1089#1086#1074
  ClientHeight = 401
  ClientWidth = 541
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 17
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 541
    Height = 33
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object NameObjectcxLabel: TcxLabel
      Left = 10
      Top = 3
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Caption = 'NameObjectcxLabel'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -17
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 353
    Width = 541
    Height = 48
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object cxButtonClose: TcxButton
      Left = 429
      Top = 8
      Width = 98
      Height = 33
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Action = ActionClose
      TabOrder = 0
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 33
    Width = 541
    Height = 320
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 2
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      OnCellDblClick = cxGrid1DBTableView1CellDblClick
      DataController.DataSource = DataSource1
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.IncSearch = True
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.DeletingConfirmation = False
      OptionsData.Editing = False
      OptionsData.Inserting = False
      OptionsSelection.InvertSelect = False
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      Styles.Header = DM.cxStyleHeaderTable
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        DataBinding.FieldName = 'RECNO'
        Width = 40
      end
      object cxGrid1DBTableView1NAME: TcxGridDBColumn
        DataBinding.FieldName = 'NAME'
        Width = 151
      end
      object cxGrid1DBTableView1SOCR: TcxGridDBColumn
        DataBinding.FieldName = 'SOCR'
        Width = 40
      end
      object cxGrid1DBTableView1CODE: TcxGridDBColumn
        DataBinding.FieldName = 'CODE'
        Width = 81
      end
      object cxGrid1DBTableView1INDEX: TcxGridDBColumn
        DataBinding.FieldName = 'INDEX'
        Width = 20
      end
      object cxGrid1DBTableView1GNINMB: TcxGridDBColumn
        DataBinding.FieldName = 'GNINMB'
        Width = 20
      end
      object cxGrid1DBTableView1UNO: TcxGridDBColumn
        DataBinding.FieldName = 'UNO'
        Width = 20
      end
      object cxGrid1DBTableView1OCATD: TcxGridDBColumn
        DataBinding.FieldName = 'OCATD'
        Width = 20
      end
      object cxGrid1DBTableView1STATUS: TcxGridDBColumn
        DataBinding.FieldName = 'STATUS'
        Width = 20
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object DataSource1: TDataSource
    DataSet = Table
    Left = 280
  end
  object Table: TADODataSet
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Data Source='#1060#1072#1081#1083#1099 +
      ' dBASE;Mode=Read;Initial Catalog=C:\Kladr'
    CursorType = ctStatic
    OnCalcFields = TableCalcFields
    CommandText = 
      ' select * from KLADR'#13#10'where CODE LIKE '#39'%%00000000000'#39#13#10'order by ' +
      'NAME'
    Parameters = <>
    Left = 232
    object TableNAME: TStringField
      FieldName = 'NAME'
      Size = 40
    end
    object TableSOCR: TStringField
      FieldName = 'SOCR'
      Size = 10
    end
    object TableCODE: TStringField
      FieldName = 'CODE'
      Size = 13
    end
    object TableINDEX: TStringField
      FieldName = 'INDEX'
      Size = 6
    end
    object TableGNINMB: TStringField
      FieldName = 'GNINMB'
      Size = 4
    end
    object TableUNO: TStringField
      FieldName = 'UNO'
      Size = 4
    end
    object TableOCATD: TStringField
      FieldName = 'OCATD'
      Size = 11
    end
    object TableSTATUS: TStringField
      FieldName = 'STATUS'
      Size = 1
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
  end
  object ADODataSet1: TADODataSet
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Data Source='#1060#1072#1081#1083#1099 +
      ' dBASE;Initial Catalog=C:\Kladr'
    CursorType = ctStatic
    CommandText = 'select CODE from KLADR'
    Parameters = <>
    Left = 152
    object ADODataSet1CODE: TStringField
      FieldName = 'CODE'
      Size = 13
    end
  end
  object ActionList: TActionList
    Images = DM.ImageList1
    Left = 360
    Top = 112
    object ActionClose: TAction
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ImageIndex = 53
      OnExecute = ActionCloseExecute
    end
  end
end
