object FormaDialog: TFormaDialog
  Left = 0
  Top = 0
  Caption = 'FormaDialog'
  ClientHeight = 372
  ClientWidth = 468
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 48
    Top = 8
    Width = 168
    Height = 13
    Caption = #1054#1090#1095#1077#1090' '#1087#1086' '#1075#1088#1091#1087#1087#1072#1084' '#1085#1086#1084#1077#1085#1082#1083#1072#1090#1091#1088#1099
  end
  object cxGrid1: TcxGrid
    Left = 8
    Top = 112
    Width = 452
    Height = 233
    TabOrder = 0
    object cxGrid1DBTableView1: TcxGridDBTableView
      NavigatorButtons.ConfirmDelete = False
      DataController.DataSource = DataSource1
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      object cxGrid1DBTableView1IDNOM: TcxGridDBColumn
        DataBinding.FieldName = 'IDNOM'
      end
      object cxGrid1DBTableView1TNOM: TcxGridDBColumn
        DataBinding.FieldName = 'TNOM'
      end
      object cxGrid1DBTableView1CODENOM: TcxGridDBColumn
        DataBinding.FieldName = 'CODENOM'
      end
      object cxGrid1DBTableView1NAMENOM: TcxGridDBColumn
        DataBinding.FieldName = 'NAMENOM'
      end
      object cxGrid1DBTableView1FNAMENOM: TcxGridDBColumn
        DataBinding.FieldName = 'FNAMENOM'
      end
      object cxGrid1DBTableView1KRNAMENOM: TcxGridDBColumn
        DataBinding.FieldName = 'KRNAMENOM'
      end
      object cxGrid1DBTableView1IDBASEDNOM: TcxGridDBColumn
        DataBinding.FieldName = 'IDBASEDNOM'
      end
      object cxGrid1DBTableView1IDOSNEDNOM: TcxGridDBColumn
        DataBinding.FieldName = 'IDOSNEDNOM'
      end
      object cxGrid1DBTableView1IDFISED_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'IDFISED_SNOM'
      end
      object cxGrid1DBTableView1IDGRPNOM: TcxGridDBColumn
        DataBinding.FieldName = 'IDGRPNOM'
      end
      object cxGrid1DBTableView1ARTNOM: TcxGridDBColumn
        DataBinding.FieldName = 'ARTNOM'
      end
      object cxGrid1DBTableView1GID_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'GID_SNOM'
      end
      object cxGrid1DBTableView1DESCR_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'DESCR_SNOM'
      end
      object cxGrid1DBTableView1IDFIRMNOM: TcxGridDBColumn
        DataBinding.FieldName = 'IDFIRMNOM'
      end
      object cxGrid1DBTableView1STNDSNOM: TcxGridDBColumn
        DataBinding.FieldName = 'STNDSNOM'
      end
      object cxGrid1DBTableView1GTDNOM: TcxGridDBColumn
        DataBinding.FieldName = 'GTDNOM'
      end
      object cxGrid1DBTableView1IDCOUNTRYNOM: TcxGridDBColumn
        DataBinding.FieldName = 'IDCOUNTRYNOM'
      end
      object cxGrid1DBTableView1FL_CHANGE_NOM: TcxGridDBColumn
        DataBinding.FieldName = 'FL_CHANGE_NOM'
      end
      object cxGrid1DBTableView1MINOSTNOM: TcxGridDBColumn
        DataBinding.FieldName = 'MINOSTNOM'
      end
      object cxGrid1DBTableView1IDBASE_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'IDBASE_SNOM'
      end
      object cxGrid1DBTableView1IDEXT_DOUT_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'IDEXT_DOUT_SNOM'
      end
      object cxGrid1DBTableView1IDEXT_BASE_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'IDEXT_BASE_SNOM'
      end
      object cxGrid1DBTableView1SKIDKA1_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'SKIDKA1_SNOM'
      end
      object cxGrid1DBTableView1SKIDKA2_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'SKIDKA2_SNOM'
      end
      object cxGrid1DBTableView1SKIDKA3_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'SKIDKA3_SNOM'
      end
      object cxGrid1DBTableView1IDVID_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'IDVID_SNOM'
      end
      object cxGrid1DBTableView1TYPESRGODN_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'TYPESRGODN_SNOM'
      end
      object cxGrid1DBTableView1SRGODN_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'SRGODN_SNOM'
      end
      object cxGrid1DBTableView1GODEN_DO_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'GODEN_DO_SNOM'
      end
      object cxGrid1DBTableView1IDSUPPLIER_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'IDSUPPLIER_SNOM'
      end
      object cxGrid1DBTableView1IDPRODUCER_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'IDPRODUCER_SNOM'
      end
      object cxGrid1DBTableView1POGR_SNOM: TcxGridDBColumn
        DataBinding.FieldName = 'POGR_SNOM'
      end
    end
    object cxGrid1Level1: TcxGridLevel
      GridView = cxGrid1DBTableView1
    end
  end
  object pFIBDataSet1: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SNOM')
    Transaction = pFIBTransaction1
    Database = pFIBDatabase1
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 208
    Top = 56
    object pFIBDataSet1IDNOM: TFIBBCDField
      FieldName = 'IDNOM'
      Size = 0
      RoundByScale = True
    end
    object pFIBDataSet1TNOM: TFIBIntegerField
      FieldName = 'TNOM'
    end
    object pFIBDataSet1CODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object pFIBDataSet1NAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 100
      EmptyStrToNull = True
    end
    object pFIBDataSet1FNAMENOM: TFIBStringField
      FieldName = 'FNAMENOM'
      Size = 100
      EmptyStrToNull = True
    end
    object pFIBDataSet1KRNAMENOM: TFIBStringField
      FieldName = 'KRNAMENOM'
      Size = 40
      EmptyStrToNull = True
    end
    object pFIBDataSet1IDBASEDNOM: TFIBBCDField
      FieldName = 'IDBASEDNOM'
      Size = 0
      RoundByScale = True
    end
    object pFIBDataSet1IDOSNEDNOM: TFIBBCDField
      FieldName = 'IDOSNEDNOM'
      Size = 0
      RoundByScale = True
    end
    object pFIBDataSet1IDFISED_SNOM: TFIBBCDField
      FieldName = 'IDFISED_SNOM'
      Size = 0
      RoundByScale = True
    end
    object pFIBDataSet1IDGRPNOM: TFIBBCDField
      FieldName = 'IDGRPNOM'
      Size = 0
      RoundByScale = True
    end
    object pFIBDataSet1ARTNOM: TFIBStringField
      FieldName = 'ARTNOM'
      EmptyStrToNull = True
    end
    object pFIBDataSet1GID_SNOM: TFIBStringField
      FieldName = 'GID_SNOM'
      Size = 10
      EmptyStrToNull = True
    end
    object pFIBDataSet1DESCR_SNOM: TFIBStringField
      FieldName = 'DESCR_SNOM'
      Size = 1000
      EmptyStrToNull = True
    end
    object pFIBDataSet1IDFIRMNOM: TFIBBCDField
      FieldName = 'IDFIRMNOM'
      Size = 0
      RoundByScale = True
    end
    object pFIBDataSet1STNDSNOM: TFIBIntegerField
      FieldName = 'STNDSNOM'
    end
    object pFIBDataSet1GTDNOM: TFIBStringField
      FieldName = 'GTDNOM'
      Size = 30
      EmptyStrToNull = True
    end
    object pFIBDataSet1IDCOUNTRYNOM: TFIBBCDField
      FieldName = 'IDCOUNTRYNOM'
      Size = 0
      RoundByScale = True
    end
    object pFIBDataSet1FL_CHANGE_NOM: TFIBSmallIntField
      FieldName = 'FL_CHANGE_NOM'
    end
    object pFIBDataSet1MINOSTNOM: TFIBBCDField
      FieldName = 'MINOSTNOM'
      Size = 3
      RoundByScale = True
    end
    object pFIBDataSet1IDBASE_SNOM: TFIBBCDField
      FieldName = 'IDBASE_SNOM'
      Size = 0
      RoundByScale = True
    end
    object pFIBDataSet1IDEXT_DOUT_SNOM: TFIBBCDField
      FieldName = 'IDEXT_DOUT_SNOM'
      Size = 0
      RoundByScale = True
    end
    object pFIBDataSet1IDEXT_BASE_SNOM: TFIBBCDField
      FieldName = 'IDEXT_BASE_SNOM'
      Size = 0
      RoundByScale = True
    end
    object pFIBDataSet1SKIDKA1_SNOM: TFIBBCDField
      FieldName = 'SKIDKA1_SNOM'
      Size = 2
      RoundByScale = True
    end
    object pFIBDataSet1SKIDKA2_SNOM: TFIBBCDField
      FieldName = 'SKIDKA2_SNOM'
      Size = 2
      RoundByScale = True
    end
    object pFIBDataSet1SKIDKA3_SNOM: TFIBBCDField
      FieldName = 'SKIDKA3_SNOM'
      Size = 2
      RoundByScale = True
    end
    object pFIBDataSet1IDVID_SNOM: TFIBBCDField
      FieldName = 'IDVID_SNOM'
      Size = 0
      RoundByScale = True
    end
    object pFIBDataSet1TYPESRGODN_SNOM: TFIBSmallIntField
      FieldName = 'TYPESRGODN_SNOM'
    end
    object pFIBDataSet1SRGODN_SNOM: TFIBSmallIntField
      FieldName = 'SRGODN_SNOM'
    end
    object pFIBDataSet1GODEN_DO_SNOM: TFIBDateTimeField
      FieldName = 'GODEN_DO_SNOM'
    end
    object pFIBDataSet1IDSUPPLIER_SNOM: TFIBBCDField
      FieldName = 'IDSUPPLIER_SNOM'
      Size = 0
      RoundByScale = True
    end
    object pFIBDataSet1IDPRODUCER_SNOM: TFIBBCDField
      FieldName = 'IDPRODUCER_SNOM'
      Size = 0
      RoundByScale = True
    end
    object pFIBDataSet1POGR_SNOM: TFIBBCDField
      FieldName = 'POGR_SNOM'
      Size = 3
      RoundByScale = True
    end
  end
  object pFIBTransaction1: TpFIBTransaction
    DefaultDatabase = pFIBDatabase1
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 264
    Top = 56
  end
  object DataSource1: TDataSource
    DataSet = pFIBDataSet1
    Left = 320
    Top = 56
  end
  object pFIBDatabase1: TpFIBDatabase
    DefaultTransaction = pFIBTransaction1
    DefaultUpdateTransaction = pFIBTransaction1
    SQLDialect = 3
    Timeout = 0
    LibraryName = 'fbclient.dll'
    WaitForRestoreConnect = 0
    Left = 168
    Top = 56
  end
end
