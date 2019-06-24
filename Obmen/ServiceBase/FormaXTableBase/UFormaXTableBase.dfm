object FormaXTableBase: TFormaXTableBase
  Left = 0
  Top = 0
  Caption = #1058#1072#1073#1083#1080#1094#1099' '#1073#1072#1079#1099' '#1076#1072#1085#1085#1099#1093
  ClientHeight = 666
  ClientWidth = 945
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 17
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 945
    Height = 41
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 17
      Width = 246
      Height = 17
      Caption = '1-'#1089#1087#1088#1072#1074#1086#1095#1085#1080#1082', 2-'#1076#1086#1082#1091#1084#1077#1085#1090', 3-'#1088#1077#1075#1080#1089#1090#1088
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 616
    Width = 945
    Height = 50
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object cxButtonSaveIsm: TcxButton
      Left = 640
      Top = 7
      Width = 131
      Height = 33
      Caption = #1047#1072#1087#1080#1089#1072#1090#1100
      TabOrder = 0
      OnClick = cxButtonSaveIsmClick
    end
    object cxButtonCancel: TcxButton
      Left = 800
      Top = 7
      Width = 129
      Height = 33
      Caption = #1054#1090#1084#1077#1085#1080#1090#1100
      TabOrder = 1
      OnClick = cxButtonCancelClick
    end
    object cxButton1: TcxButton
      Left = 488
      Top = 7
      Width = 131
      Height = 33
      Caption = #1042' Excel'
      TabOrder = 2
      OnClick = cxButton1Click
    end
  end
  object cxGrid1: TcxGrid
    Left = 0
    Top = 41
    Width = 945
    Height = 575
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Align = alClient
    TabOrder = 2
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DataSourceTable
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      object cxGrid1DBTableView1RECNO: TcxGridDBColumn
        DataBinding.FieldName = 'RECNO'
      end
      object cxGrid1DBTableView1ID_XTABLE_BASE: TcxGridDBColumn
        DataBinding.FieldName = 'ID_XTABLE_BASE'
        Width = 116
      end
      object cxGrid1DBTableView1NAMETAB_XTABLE_BASE: TcxGridDBColumn
        DataBinding.FieldName = 'NAMETAB_XTABLE_BASE'
      end
      object cxGrid1DBTableView1DESCR_XTABLE_BASE: TcxGridDBColumn
        DataBinding.FieldName = 'DESCR_XTABLE_BASE'
        Width = 379
      end
      object cxGrid1DBTableView1TYPE_OBJECT_XTABLE_BASE: TcxGridDBColumn
        DataBinding.FieldName = 'TYPE_OBJECT_XTABLE_BASE'
      end
      object cxGrid1DBTableView1GID_XTABLE_BASE: TcxGridDBColumn
        DataBinding.FieldName = 'GID_XTABLE_BASE'
      end
      object cxGrid1DBTableView1NAMEPK_XTABLE_BASE: TcxGridDBColumn
        DataBinding.FieldName = 'NAMEPK_XTABLE_BASE'
      end
      object cxGrid1DBTableView1NAMEGID_XTABLE_BASE: TcxGridDBColumn
        DataBinding.FieldName = 'NAMEGID_XTABLE_BASE'
      end
      object cxGrid1DBTableView1NAMEIDDOC_XTABLE_BASE: TcxGridDBColumn
        DataBinding.FieldName = 'NAMEIDDOC_XTABLE_BASE'
      end
      object cxGrid1DBTableView1NAMEPREFIKS_XTABLE_BASE: TcxGridDBColumn
        DataBinding.FieldName = 'NAMEPREFIKS_XTABLE_BASE'
      end
      object cxGrid1DBTableView1IDBASE_XTABLE_BASE: TcxGridDBColumn
        DataBinding.FieldName = 'IDBASE_XTABLE_BASE'
      end
      object cxGrid1DBTableView1IDEXT_DOUT_XTABLE_BASE: TcxGridDBColumn
        DataBinding.FieldName = 'IDEXT_DOUT_XTABLE_BASE'
      end
      object cxGrid1DBTableView1IDEXT_BASE_XTABLE_BASE: TcxGridDBColumn
        DataBinding.FieldName = 'IDEXT_BASE_XTABLE_BASE'
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE XTABLE_BASE'
      'SET '
      '    NAMETAB_XTABLE_BASE = :NAMETAB_XTABLE_BASE,'
      '    DESCR_XTABLE_BASE = :DESCR_XTABLE_BASE,'
      '    TYPE_OBJECT_XTABLE_BASE = :TYPE_OBJECT_XTABLE_BASE,'
      '    GID_XTABLE_BASE = :GID_XTABLE_BASE,'
      '    NAMEPK_XTABLE_BASE = :NAMEPK_XTABLE_BASE,'
      '    NAMEGID_XTABLE_BASE = :NAMEGID_XTABLE_BASE,'
      '    NAMEIDDOC_XTABLE_BASE = :NAMEIDDOC_XTABLE_BASE,'
      '    NAMEPREFIKS_XTABLE_BASE = :NAMEPREFIKS_XTABLE_BASE,'
      '    IDBASE_XTABLE_BASE = :IDBASE_XTABLE_BASE'
      'WHERE'
      '    ID_XTABLE_BASE = :OLD_ID_XTABLE_BASE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    XTABLE_BASE'
      'WHERE'
      '        ID_XTABLE_BASE = :OLD_ID_XTABLE_BASE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO XTABLE_BASE('
      '    ID_XTABLE_BASE,'
      '    NAMETAB_XTABLE_BASE,'
      '    DESCR_XTABLE_BASE,'
      '    TYPE_OBJECT_XTABLE_BASE,'
      '    GID_XTABLE_BASE,'
      '    NAMEPK_XTABLE_BASE,'
      '    NAMEGID_XTABLE_BASE,'
      '    NAMEIDDOC_XTABLE_BASE,'
      '    NAMEPREFIKS_XTABLE_BASE,'
      '    IDBASE_XTABLE_BASE'
      ')'
      'VALUES('
      '    :ID_XTABLE_BASE,'
      '    :NAMETAB_XTABLE_BASE,'
      '    :DESCR_XTABLE_BASE,'
      '    :TYPE_OBJECT_XTABLE_BASE,'
      '    :GID_XTABLE_BASE,'
      '    :NAMEPK_XTABLE_BASE,'
      '    :NAMEGID_XTABLE_BASE,'
      '    :NAMEIDDOC_XTABLE_BASE,'
      '    :NAMEPREFIKS_XTABLE_BASE,'
      '    :IDBASE_XTABLE_BASE'
      ')')
    RefreshSQL.Strings = (
      'select * from xtable_base'
      ''
      ' WHERE '
      '        XTABLE_BASE.ID_XTABLE_BASE = :OLD_ID_XTABLE_BASE'
      '    ')
    SelectSQL.Strings = (
      'select * from xtable_base')
    AutoUpdateOptions.UpdateTableName = 'XTABLE_BASE'
    AutoUpdateOptions.KeyFields = 'ID_XTABLE_BASE'
    AutoUpdateOptions.GeneratorName = 'GEN_XTABLE_BASE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    Transaction = pFIBTransaction1
    Database = DataModuleMain.pFIBDatabase
    UpdateTransaction = pFIBTransactionUpdate
    Left = 384
    Top = 176
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_XTABLE_BASE: TFIBBCDField
      FieldName = 'ID_XTABLE_BASE'
      Size = 0
      RoundByScale = True
    end
    object TableNAMETAB_XTABLE_BASE: TFIBWideStringField
      FieldName = 'NAMETAB_XTABLE_BASE'
    end
    object TableDESCR_XTABLE_BASE: TFIBWideStringField
      FieldName = 'DESCR_XTABLE_BASE'
      Size = 100
    end
    object TableTYPE_OBJECT_XTABLE_BASE: TFIBSmallIntField
      FieldName = 'TYPE_OBJECT_XTABLE_BASE'
    end
    object TableGID_XTABLE_BASE: TFIBWideStringField
      FieldName = 'GID_XTABLE_BASE'
      Size = 10
    end
    object TableNAMEPK_XTABLE_BASE: TFIBWideStringField
      FieldName = 'NAMEPK_XTABLE_BASE'
      Size = 40
    end
    object TableNAMEGID_XTABLE_BASE: TFIBWideStringField
      FieldName = 'NAMEGID_XTABLE_BASE'
      Size = 40
    end
    object TableNAMEIDDOC_XTABLE_BASE: TFIBWideStringField
      FieldName = 'NAMEIDDOC_XTABLE_BASE'
      Size = 40
    end
    object TableNAMEPREFIKS_XTABLE_BASE: TFIBWideStringField
      FieldName = 'NAMEPREFIKS_XTABLE_BASE'
      Size = 40
    end
    object TableIDBASE_XTABLE_BASE: TFIBBCDField
      FieldName = 'IDBASE_XTABLE_BASE'
      Size = 0
      RoundByScale = True
    end
    object TableIDEXT_DOUT_XTABLE_BASE: TFIBBCDField
      FieldName = 'IDEXT_DOUT_XTABLE_BASE'
      Size = 0
      RoundByScale = True
    end
    object TableIDEXT_BASE_XTABLE_BASE: TFIBBCDField
      FieldName = 'IDEXT_BASE_XTABLE_BASE'
      Size = 0
      RoundByScale = True
    end
  end
  object pFIBTransaction1: TpFIBTransaction
    DefaultDatabase = DataModuleMain.pFIBDatabase
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 520
    Top = 168
  end
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 272
    Top = 200
  end
  object pFIBTransactionUpdate: TpFIBTransaction
    DefaultDatabase = DataModuleMain.pFIBDatabase
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 520
    Top = 248
  end
  object SaveDialog1: TSaveDialog
    Left = 136
    Top = 408
  end
end
