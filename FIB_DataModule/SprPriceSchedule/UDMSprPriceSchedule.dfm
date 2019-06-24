object DMSprPriceSchedule: TDMSprPriceSchedule
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 345
  Width = 302
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPRICE_SCHEDULE'
      'SET '
      '    IDBASE_SPRICE_SCHEDULE = :IDBASE_SPRICE_SCHEDULE,'
      '    IDNOM_SPRICE_SCHEDULE = :IDNOM_SPRICE_SCHEDULE,'
      '    IDTYPE_SPRICE_SCHEDULE = :IDTYPE_SPRICE_SCHEDULE,'
      '    IDED_SPRICE_SCHEDULE = :IDED_SPRICE_SCHEDULE,'
      '    VALUE_SPRICE_SCHEDULE = :VALUE_SPRICE_SCHEDULE,'
      '    POS_SPRICE_SCHEDULE = :POS_SPRICE_SCHEDULE'
      'WHERE'
      '    ID_SPRICE_SCHEDULE = :OLD_ID_SPRICE_SCHEDULE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRICE_SCHEDULE'
      'WHERE'
      '        ID_SPRICE_SCHEDULE = :OLD_ID_SPRICE_SCHEDULE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRICE_SCHEDULE('
      '    ID_SPRICE_SCHEDULE,'
      '    IDBASE_SPRICE_SCHEDULE,'
      '    IDNOM_SPRICE_SCHEDULE,'
      '    IDTYPE_SPRICE_SCHEDULE,'
      '    IDED_SPRICE_SCHEDULE,'
      '    VALUE_SPRICE_SCHEDULE,'
      '    POS_SPRICE_SCHEDULE'
      ')'
      'VALUES('
      '    :ID_SPRICE_SCHEDULE,'
      '    :IDBASE_SPRICE_SCHEDULE,'
      '    :IDNOM_SPRICE_SCHEDULE,'
      '    :IDTYPE_SPRICE_SCHEDULE,'
      '    :IDED_SPRICE_SCHEDULE,'
      '    :VALUE_SPRICE_SCHEDULE,'
      '    :POS_SPRICE_SCHEDULE'
      ')')
    RefreshSQL.Strings = (
      'select SPRICE_SCHEDULE.*,  NAME_TPRICE'
      'from '
      '  SPRICE_SCHEDULE '
      'left outer join STPRICE on IDTYPE_SPRICE_SCHEDULE = ID_TPRICE'
      'where(  '
      '  IDNOM_SPRICE_SCHEDULE = :IDNOM'
      
        '     ) and (     SPRICE_SCHEDULE.ID_SPRICE_SCHEDULE = :OLD_ID_SP' +
        'RICE_SCHEDULE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select SPRICE_SCHEDULE.*,  NAME_TPRICE'
      'from '
      '  SPRICE_SCHEDULE '
      'left outer join STPRICE on IDTYPE_SPRICE_SCHEDULE = ID_TPRICE'
      'where '
      '  IDNOM_SPRICE_SCHEDULE = :PARAM_IDNOM'
      'order by NAME_TPRICE')
    AutoUpdateOptions.UpdateTableName = 'SPRICE_SCHEDULE'
    AutoUpdateOptions.KeyFields = 'ID_SPRICE_SCHEDULE'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRICE_SCHEDULE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterInsert = TableAfterInsert
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 16
    object TableID_SPRICE_SCHEDULE: TFIBBCDField
      FieldName = 'ID_SPRICE_SCHEDULE'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_SPRICE_SCHEDULE: TFIBBCDField
      FieldName = 'IDBASE_SPRICE_SCHEDULE'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOM_SPRICE_SCHEDULE: TFIBBCDField
      FieldName = 'IDNOM_SPRICE_SCHEDULE'
      Size = 0
      RoundByScale = True
    end
    object TableIDTYPE_SPRICE_SCHEDULE: TFIBBCDField
      FieldName = 'IDTYPE_SPRICE_SCHEDULE'
      Size = 0
      RoundByScale = True
    end
    object TableIDED_SPRICE_SCHEDULE: TFIBBCDField
      FieldName = 'IDED_SPRICE_SCHEDULE'
      Size = 0
      RoundByScale = True
    end
    object TableVALUE_SPRICE_SCHEDULE: TFIBBCDField
      FieldName = 'VALUE_SPRICE_SCHEDULE'
      Size = 2
      RoundByScale = True
    end
    object TablePOS_SPRICE_SCHEDULE: TFIBDateTimeField
      FieldName = 'POS_SPRICE_SCHEDULE'
      DisplayFormat = 'c'
    end
    object TableNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPRICE_SCHEDULE'
      'SET '
      '    IDBASE_SPRICE_SCHEDULE = :IDBASE_SPRICE_SCHEDULE,'
      '    IDNOM_SPRICE_SCHEDULE = :IDNOM_SPRICE_SCHEDULE,'
      '    IDTYPE_SPRICE_SCHEDULE = :IDTYPE_SPRICE_SCHEDULE,'
      '    IDED_SPRICE_SCHEDULE = :IDED_SPRICE_SCHEDULE,'
      '    VALUE_SPRICE_SCHEDULE = :VALUE_SPRICE_SCHEDULE,'
      '    POS_SPRICE_SCHEDULE = :POS_SPRICE_SCHEDULE'
      'WHERE'
      '    ID_SPRICE_SCHEDULE = :OLD_ID_SPRICE_SCHEDULE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRICE_SCHEDULE'
      'WHERE'
      '        ID_SPRICE_SCHEDULE = :OLD_ID_SPRICE_SCHEDULE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRICE_SCHEDULE('
      '    ID_SPRICE_SCHEDULE,'
      '    IDBASE_SPRICE_SCHEDULE,'
      '    IDNOM_SPRICE_SCHEDULE,'
      '    IDTYPE_SPRICE_SCHEDULE,'
      '    IDED_SPRICE_SCHEDULE,'
      '    VALUE_SPRICE_SCHEDULE,'
      '    POS_SPRICE_SCHEDULE'
      ')'
      'VALUES('
      '    :ID_SPRICE_SCHEDULE,'
      '    :IDBASE_SPRICE_SCHEDULE,'
      '    :IDNOM_SPRICE_SCHEDULE,'
      '    :IDTYPE_SPRICE_SCHEDULE,'
      '    :IDED_SPRICE_SCHEDULE,'
      '    :VALUE_SPRICE_SCHEDULE,'
      '    :POS_SPRICE_SCHEDULE'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  SPRICE_SCHEDULE'
      'where(  ID_SPRICE_SCHEDULE=:PARAM_ID'
      
        '     ) and (     SPRICE_SCHEDULE.ID_SPRICE_SCHEDULE = :OLD_ID_SP' +
        'RICE_SCHEDULE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  SPRICE_SCHEDULE'
      'where ID_SPRICE_SCHEDULE=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPRICE_SCHEDULE'
    AutoUpdateOptions.KeyFields = 'ID_SPRICE_SCHEDULE'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRICE_SCHEDULE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    object ElementID_SPRICE_SCHEDULE: TFIBBCDField
      FieldName = 'ID_SPRICE_SCHEDULE'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_SPRICE_SCHEDULE: TFIBBCDField
      FieldName = 'IDBASE_SPRICE_SCHEDULE'
      Size = 0
      RoundByScale = True
    end
    object ElementIDNOM_SPRICE_SCHEDULE: TFIBBCDField
      FieldName = 'IDNOM_SPRICE_SCHEDULE'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTYPE_SPRICE_SCHEDULE: TFIBBCDField
      FieldName = 'IDTYPE_SPRICE_SCHEDULE'
      Size = 0
      RoundByScale = True
    end
    object ElementIDED_SPRICE_SCHEDULE: TFIBBCDField
      FieldName = 'IDED_SPRICE_SCHEDULE'
      Size = 0
      RoundByScale = True
    end
    object ElementVALUE_SPRICE_SCHEDULE: TFIBBCDField
      FieldName = 'VALUE_SPRICE_SCHEDULE'
      Size = 2
      RoundByScale = True
    end
    object ElementPOS_SPRICE_SCHEDULE: TFIBDateTimeField
      FieldName = 'POS_SPRICE_SCHEDULE'
      DisplayFormat = 'c'
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
    Left = 144
    Top = 216
  end
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 248
    Top = 144
    qoStartTransaction = True
  end
  object SpisokEd: TpFIBDataSet
    SelectSQL.Strings = (
      'select IDED, NAMEED, KFED'
      'from SED'
      'where IDNOMED=:PARAM_IDNOM')
    Transaction = IBTr
    Left = 144
    Top = 264
    object SpisokEdIDED: TFIBBCDField
      FieldName = 'IDED'
      Size = 0
      RoundByScale = True
    end
    object SpisokEdKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object SpisokEdNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
  end
  object DataSourceSpisokEd: TDataSource
    DataSet = SpisokEd
    Left = 48
    Top = 264
  end
  object DataSourceTypePrice: TDataSource
    DataSet = TPrice
    Left = 48
    Top = 216
  end
end
