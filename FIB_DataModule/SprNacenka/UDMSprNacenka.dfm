object DMSprNacenka: TDMSprNacenka
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 213
  Width = 302
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SNACENKA'
      'SET '
      '    GID_SNACENKA = :GID_SNACENKA,'
      '    IDGRPNOM_SNACENKA = :IDGRPNOM_SNACENKA,'
      '    IDTPRICE_SNACENKA = :IDTPRICE_SNACENKA,'
      '    VALUE_SNACENKA = :VALUE_SNACENKA,'
      '    OKR_SNACENKA = :OKR_SNACENKA'
      'WHERE'
      '    ID_SNACENKA = :OLD_ID_SNACENKA'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNACENKA'
      'WHERE'
      '        ID_SNACENKA = :OLD_ID_SNACENKA'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNACENKA('
      '    ID_SNACENKA,'
      '    GID_SNACENKA,'
      '    IDGRPNOM_SNACENKA,'
      '    IDTPRICE_SNACENKA,'
      '    VALUE_SNACENKA,'
      '    OKR_SNACENKA'
      ')'
      'VALUES('
      '    :ID_SNACENKA,'
      '    :GID_SNACENKA,'
      '    :IDGRPNOM_SNACENKA,'
      '    :IDTPRICE_SNACENKA,'
      '    :VALUE_SNACENKA,'
      '    :OKR_SNACENKA'
      ')')
    RefreshSQL.Strings = (
      'select SNACENKA.*,  NAME_TPRICE'
      'from '
      '  SNACENKA '
      'left outer join STPRICE on IDTPRICE_SNACENKA=ID_TPRICE'
      'where(  '
      '  IDGRPNOM_SNACENKA=:IDGRPNOM'
      '     ) and (     SNACENKA.ID_SNACENKA = :OLD_ID_SNACENKA'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select SNACENKA.*,  NAME_TPRICE'
      'from '
      '  SNACENKA '
      'left outer join STPRICE on IDTPRICE_SNACENKA=ID_TPRICE'
      'where '
      '  IDGRPNOM_SNACENKA=:IDGRPNOM')
    AutoUpdateOptions.UpdateTableName = 'SNACENKA'
    AutoUpdateOptions.KeyFields = 'ID_SNACENKA'
    AutoUpdateOptions.GeneratorName = 'GEN_SNACENKA_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterInsert = TableAfterInsert
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 16
    object TableVALUE_SNACENKA: TFIBBCDField
      FieldName = 'VALUE_SNACENKA'
      Size = 2
      RoundByScale = True
    end
    object TableOKR_SNACENKA: TFIBIntegerField
      FieldName = 'OKR_SNACENKA'
    end
    object TableID_SNACENKA: TFIBBCDField
      FieldName = 'ID_SNACENKA'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRPNOM_SNACENKA: TFIBBCDField
      FieldName = 'IDGRPNOM_SNACENKA'
      Size = 0
      RoundByScale = True
    end
    object TableIDTPRICE_SNACENKA: TFIBBCDField
      FieldName = 'IDTPRICE_SNACENKA'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SNACENKA: TFIBWideStringField
      FieldName = 'GID_SNACENKA'
      Size = 10
    end
    object TableIDBASE_SNACENKA: TFIBBCDField
      FieldName = 'IDBASE_SNACENKA'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SNACENKA'
      'SET '
      '    GID_SNACENKA = :GID_SNACENKA,'
      '    IDGRPNOM_SNACENKA = :IDGRPNOM_SNACENKA,'
      '    IDTPRICE_SNACENKA = :IDTPRICE_SNACENKA,'
      '    VALUE_SNACENKA = :VALUE_SNACENKA,'
      '    OKR_SNACENKA = :OKR_SNACENKA'
      'WHERE'
      '    ID_SNACENKA = :OLD_ID_SNACENKA'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNACENKA'
      'WHERE'
      '        ID_SNACENKA = :OLD_ID_SNACENKA'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNACENKA('
      '    ID_SNACENKA,'
      '    GID_SNACENKA,'
      '    IDGRPNOM_SNACENKA,'
      '    IDTPRICE_SNACENKA,'
      '    VALUE_SNACENKA,'
      '    OKR_SNACENKA'
      ')'
      'VALUES('
      '    :ID_SNACENKA,'
      '    :GID_SNACENKA,'
      '    :IDGRPNOM_SNACENKA,'
      '    :IDTPRICE_SNACENKA,'
      '    :VALUE_SNACENKA,'
      '    :OKR_SNACENKA'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  SNACENKA'
      'where(  ID_SNACENKA=:PARAM_ID'
      '     ) and (     SNACENKA.ID_SNACENKA = :OLD_ID_SNACENKA'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  SNACENKA'
      'where ID_SNACENKA=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SNACENKA'
    AutoUpdateOptions.KeyFields = 'ID_SNACENKA'
    AutoUpdateOptions.GeneratorName = 'GEN_SNACENKA_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    object ElementVALUE_SNACENKA: TFIBBCDField
      FieldName = 'VALUE_SNACENKA'
      Size = 2
      RoundByScale = True
    end
    object ElementOKR_SNACENKA: TFIBIntegerField
      FieldName = 'OKR_SNACENKA'
    end
    object ElementID_SNACENKA: TFIBBCDField
      FieldName = 'ID_SNACENKA'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRPNOM_SNACENKA: TFIBBCDField
      FieldName = 'IDGRPNOM_SNACENKA'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTPRICE_SNACENKA: TFIBBCDField
      FieldName = 'IDTPRICE_SNACENKA'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SNACENKA: TFIBWideStringField
      FieldName = 'GID_SNACENKA'
      Size = 10
    end
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 232
    Top = 16
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 232
    Top = 72
  end
  object TPrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Left = 152
    Top = 128
  end
end
