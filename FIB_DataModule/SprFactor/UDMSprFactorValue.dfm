object DMSprFactorValue: TDMSprFactorValue
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
      'UPDATE SFACTOR_VAL'
      'SET '
      '    GID_SFACTOR_VAL = :GID_SFACTOR_VAL,'
      '    IDBASE_SFACTOR_VAL = :IDBASE_SFACTOR_VAL,'
      '    IDPRODUCE_SFACTOR_VAL = :IDPRODUCE_SFACTOR_VAL,'
      '    IDFACTOR_SFACTOR_VAL = :IDFACTOR_SFACTOR_VAL,'
      '    VALUE_SFACTOR_VAL = :VALUE_SFACTOR_VAL'
      'WHERE'
      '    ID_SFACTOR_VAL = :OLD_ID_SFACTOR_VAL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SFACTOR_VAL'
      'WHERE'
      '        ID_SFACTOR_VAL = :OLD_ID_SFACTOR_VAL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SFACTOR_VAL('
      '    ID_SFACTOR_VAL,'
      '    GID_SFACTOR_VAL,'
      '    IDBASE_SFACTOR_VAL,'
      '    IDPRODUCE_SFACTOR_VAL,'
      '    IDFACTOR_SFACTOR_VAL,'
      '    VALUE_SFACTOR_VAL'
      ')'
      'VALUES('
      '    :ID_SFACTOR_VAL,'
      '    :GID_SFACTOR_VAL,'
      '    :IDBASE_SFACTOR_VAL,'
      '    :IDPRODUCE_SFACTOR_VAL,'
      '    :IDFACTOR_SFACTOR_VAL,'
      '    :VALUE_SFACTOR_VAL'
      ')')
    RefreshSQL.Strings = (
      'select  sfactor_val.*'
      'from  sfactor_val'
      
        'left  outer join sfactor on sfactor_val.idfactor_sfactor_val=sfa' +
        'ctor.id_sfactor'
      'where(   sfactor_val.idproduce_sfactor_val=:PARAM_IDPRODUCE'
      
        '     ) and (     SFACTOR_VAL.ID_SFACTOR_VAL = :OLD_ID_SFACTOR_VA' +
        'L'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select  sfactor_val.*'
      'from  sfactor_val'
      
        'left  outer join sfactor on sfactor_val.idfactor_sfactor_val=sfa' +
        'ctor.id_sfactor'
      'where  sfactor_val.idproduce_sfactor_val=:PARAM_IDPRODUCE'
      'order by sfactor.index_sfactor'
      '')
    AutoUpdateOptions.UpdateTableName = 'SFACTOR_VAL'
    AutoUpdateOptions.KeyFields = 'ID_SFACTOR_VAL'
    AutoUpdateOptions.GeneratorName = 'GEN_SFACTOR_VAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 16
    poUseLargeIntField = True
    object TableID_SFACTOR_VAL: TFIBLargeIntField
      FieldName = 'ID_SFACTOR_VAL'
    end
    object TableGID_SFACTOR_VAL: TFIBWideStringField
      FieldName = 'GID_SFACTOR_VAL'
      Size = 10
    end
    object TableIDBASE_SFACTOR_VAL: TFIBLargeIntField
      FieldName = 'IDBASE_SFACTOR_VAL'
    end
    object TableIDPRODUCE_SFACTOR_VAL: TFIBLargeIntField
      FieldName = 'IDPRODUCE_SFACTOR_VAL'
    end
    object TableIDFACTOR_SFACTOR_VAL: TFIBLargeIntField
      FieldName = 'IDFACTOR_SFACTOR_VAL'
    end
    object TableVALUE_SFACTOR_VAL: TFIBBCDField
      FieldName = 'VALUE_SFACTOR_VAL'
      Size = 3
      RoundByScale = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SFACTOR_VAL'
      'SET '
      '    GID_SFACTOR_VAL = :GID_SFACTOR_VAL,'
      '    IDBASE_SFACTOR_VAL = :IDBASE_SFACTOR_VAL,'
      '    IDPRODUCE_SFACTOR_VAL = :IDPRODUCE_SFACTOR_VAL,'
      '    IDFACTOR_SFACTOR_VAL = :IDFACTOR_SFACTOR_VAL,'
      '    VALUE_SFACTOR_VAL = :VALUE_SFACTOR_VAL'
      'WHERE'
      '    ID_SFACTOR_VAL = :OLD_ID_SFACTOR_VAL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SFACTOR_VAL'
      'WHERE'
      '        ID_SFACTOR_VAL = :OLD_ID_SFACTOR_VAL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SFACTOR_VAL('
      '    ID_SFACTOR_VAL,'
      '    GID_SFACTOR_VAL,'
      '    IDBASE_SFACTOR_VAL,'
      '    IDPRODUCE_SFACTOR_VAL,'
      '    IDFACTOR_SFACTOR_VAL,'
      '    VALUE_SFACTOR_VAL'
      ')'
      'VALUES('
      '    :ID_SFACTOR_VAL,'
      '    :GID_SFACTOR_VAL,'
      '    :IDBASE_SFACTOR_VAL,'
      '    :IDPRODUCE_SFACTOR_VAL,'
      '    :IDFACTOR_SFACTOR_VAL,'
      '    :VALUE_SFACTOR_VAL'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from sfactor_val'
      'where(  sfactor_val.id_sfactor_val=:PARAM_ID'
      
        '     ) and (     SFACTOR_VAL.ID_SFACTOR_VAL = :OLD_ID_SFACTOR_VA' +
        'L'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from sfactor_val'
      'where sfactor_val.id_sfactor_val=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SFACTOR_VAL'
    AutoUpdateOptions.KeyFields = 'ID_SFACTOR_VAL'
    AutoUpdateOptions.GeneratorName = 'GEN_SFACTOR_VAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    poUseLargeIntField = True
    object ElementID_SFACTOR_VAL: TFIBLargeIntField
      FieldName = 'ID_SFACTOR_VAL'
    end
    object ElementGID_SFACTOR_VAL: TFIBWideStringField
      FieldName = 'GID_SFACTOR_VAL'
      Size = 10
    end
    object ElementIDBASE_SFACTOR_VAL: TFIBLargeIntField
      FieldName = 'IDBASE_SFACTOR_VAL'
    end
    object ElementIDPRODUCE_SFACTOR_VAL: TFIBLargeIntField
      FieldName = 'IDPRODUCE_SFACTOR_VAL'
    end
    object ElementIDFACTOR_SFACTOR_VAL: TFIBLargeIntField
      FieldName = 'IDFACTOR_SFACTOR_VAL'
    end
    object ElementVALUE_SFACTOR_VAL: TFIBBCDField
      FieldName = 'VALUE_SFACTOR_VAL'
      Size = 3
      RoundByScale = True
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
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 248
    Top = 144
    qoStartTransaction = True
  end
  object FactorList: TpFIBDataSet
    SelectSQL.Strings = (
      'select sfactor.id_sfactor,'
      '        sfactor.name_sfactor'
      'from sfactor')
    Transaction = IBTr
    Left = 160
    Top = 200
    poUseLargeIntField = True
    object FactorListID_SFACTOR: TFIBLargeIntField
      FieldName = 'ID_SFACTOR'
    end
    object FactorListNAME_SFACTOR: TFIBWideStringField
      FieldName = 'NAME_SFACTOR'
      Size = 200
    end
  end
  object DataSourceFactorList: TDataSource
    DataSet = FactorList
    Left = 56
    Top = 200
  end
end
