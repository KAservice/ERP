object DMSprLossFactorValue: TDMSprLossFactorValue
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
      'UPDATE SLOSS_FACTOR_VAL'
      'SET '
      '    GID_SLOSS_FACTOR_VAL = :GID_SLOSS_FACTOR_VAL,'
      '    IDBASE_SLOSS_FACTOR_VAL = :IDBASE_SLOSS_FACTOR_VAL,'
      '    IDFACTOR_SLOSS_FACTOR_VAL = :IDFACTOR_SLOSS_FACTOR_VAL,'
      
        '    IDLOSS_FACTOR_SLOSS_FACTOR_VAL = :IDLOSS_FACTOR_SLOSS_FACTOR' +
        '_VAL,'
      '    VAL_SLOSS_FACTOR_VAL = :VAL_SLOSS_FACTOR_VAL'
      'WHERE'
      '    ID_SLOSS_FACTOR_VAL = :OLD_ID_SLOSS_FACTOR_VAL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SLOSS_FACTOR_VAL'
      'WHERE'
      '        ID_SLOSS_FACTOR_VAL = :OLD_ID_SLOSS_FACTOR_VAL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SLOSS_FACTOR_VAL('
      '    ID_SLOSS_FACTOR_VAL,'
      '    GID_SLOSS_FACTOR_VAL,'
      '    IDBASE_SLOSS_FACTOR_VAL,'
      '    IDFACTOR_SLOSS_FACTOR_VAL,'
      '    IDLOSS_FACTOR_SLOSS_FACTOR_VAL,'
      '    VAL_SLOSS_FACTOR_VAL'
      ')'
      'VALUES('
      '    :ID_SLOSS_FACTOR_VAL,'
      '    :GID_SLOSS_FACTOR_VAL,'
      '    :IDBASE_SLOSS_FACTOR_VAL,'
      '    :IDFACTOR_SLOSS_FACTOR_VAL,'
      '    :IDLOSS_FACTOR_SLOSS_FACTOR_VAL,'
      '    :VAL_SLOSS_FACTOR_VAL'
      ')')
    RefreshSQL.Strings = (
      'select  sloss_factor_val.*'
      'from  sloss_factor_val'
      
        'left  outer join sfactor on sloss_factor_val.id_sloss_factor_val' +
        '=sfactor.id_sfactor'
      
        'where(   sloss_factor_val.idloss_factor_sloss_factor_val=:PARAM_' +
        'IDLOSS_FACTOR'
      
        '     ) and (     SLOSS_FACTOR_VAL.ID_SLOSS_FACTOR_VAL = :OLD_ID_' +
        'SLOSS_FACTOR_VAL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select  sloss_factor_val.*'
      'from  sloss_factor_val'
      
        'left  outer join sfactor on sloss_factor_val.id_sloss_factor_val' +
        '=sfactor.id_sfactor'
      
        'where  sloss_factor_val.idloss_factor_sloss_factor_val=:PARAM_ID' +
        'LOSS_FACTOR'
      'order by sfactor.index_sfactor'
      '')
    AutoUpdateOptions.UpdateTableName = 'SLOSS_FACTOR_VAL'
    AutoUpdateOptions.KeyFields = 'ID_SLOSS_FACTOR_VAL'
    AutoUpdateOptions.GeneratorName = 'GEN_SLOSS_FACTOR_VAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    AfterInsert = TableAfterInsert
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 16
    poUseLargeIntField = True
    object TableID_SLOSS_FACTOR_VAL: TFIBLargeIntField
      FieldName = 'ID_SLOSS_FACTOR_VAL'
    end
    object TableGID_SLOSS_FACTOR_VAL: TFIBWideStringField
      FieldName = 'GID_SLOSS_FACTOR_VAL'
      Size = 10
    end
    object TableIDBASE_SLOSS_FACTOR_VAL: TFIBLargeIntField
      FieldName = 'IDBASE_SLOSS_FACTOR_VAL'
    end
    object TableIDFACTOR_SLOSS_FACTOR_VAL: TFIBLargeIntField
      FieldName = 'IDFACTOR_SLOSS_FACTOR_VAL'
    end
    object TableIDLOSS_FACTOR_SLOSS_FACTOR_VAL: TFIBLargeIntField
      FieldName = 'IDLOSS_FACTOR_SLOSS_FACTOR_VAL'
    end
    object TableVAL_SLOSS_FACTOR_VAL: TFIBBCDField
      FieldName = 'VAL_SLOSS_FACTOR_VAL'
      Size = 3
      RoundByScale = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SLOSS_FACTOR_VAL'
      'SET '
      '    GID_SLOSS_FACTOR_VAL = :GID_SLOSS_FACTOR_VAL,'
      '    IDBASE_SLOSS_FACTOR_VAL = :IDBASE_SLOSS_FACTOR_VAL,'
      '    IDFACTOR_SLOSS_FACTOR_VAL = :IDFACTOR_SLOSS_FACTOR_VAL,'
      
        '    IDLOSS_FACTOR_SLOSS_FACTOR_VAL = :IDLOSS_FACTOR_SLOSS_FACTOR' +
        '_VAL,'
      '    VAL_SLOSS_FACTOR_VAL = :VAL_SLOSS_FACTOR_VAL'
      'WHERE'
      '    ID_SLOSS_FACTOR_VAL = :OLD_ID_SLOSS_FACTOR_VAL'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SLOSS_FACTOR_VAL'
      'WHERE'
      '        ID_SLOSS_FACTOR_VAL = :OLD_ID_SLOSS_FACTOR_VAL'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SLOSS_FACTOR_VAL('
      '    ID_SLOSS_FACTOR_VAL,'
      '    GID_SLOSS_FACTOR_VAL,'
      '    IDBASE_SLOSS_FACTOR_VAL,'
      '    IDFACTOR_SLOSS_FACTOR_VAL,'
      '    IDLOSS_FACTOR_SLOSS_FACTOR_VAL,'
      '    VAL_SLOSS_FACTOR_VAL'
      ')'
      'VALUES('
      '    :ID_SLOSS_FACTOR_VAL,'
      '    :GID_SLOSS_FACTOR_VAL,'
      '    :IDBASE_SLOSS_FACTOR_VAL,'
      '    :IDFACTOR_SLOSS_FACTOR_VAL,'
      '    :IDLOSS_FACTOR_SLOSS_FACTOR_VAL,'
      '    :VAL_SLOSS_FACTOR_VAL'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from sloss_factor_val'
      'where(  sloss_factor_val.id_sloss_factor_val=:PARAM_ID'
      
        '     ) and (     SLOSS_FACTOR_VAL.ID_SLOSS_FACTOR_VAL = :OLD_ID_' +
        'SLOSS_FACTOR_VAL'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from sloss_factor_val'
      'where sloss_factor_val.id_sloss_factor_val=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SLOSS_FACTOR_VAL'
    AutoUpdateOptions.KeyFields = 'ID_SLOSS_FACTOR_VAL'
    AutoUpdateOptions.GeneratorName = 'GEN_SLOSS_FACTOR_VAL_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    poUseLargeIntField = True
    object ElementID_SLOSS_FACTOR_VAL: TFIBLargeIntField
      FieldName = 'ID_SLOSS_FACTOR_VAL'
    end
    object ElementGID_SLOSS_FACTOR_VAL: TFIBWideStringField
      FieldName = 'GID_SLOSS_FACTOR_VAL'
      Size = 10
    end
    object ElementIDBASE_SLOSS_FACTOR_VAL: TFIBLargeIntField
      FieldName = 'IDBASE_SLOSS_FACTOR_VAL'
    end
    object ElementIDFACTOR_SLOSS_FACTOR_VAL: TFIBLargeIntField
      FieldName = 'IDFACTOR_SLOSS_FACTOR_VAL'
    end
    object ElementIDLOSS_FACTOR_SLOSS_FACTOR_VAL: TFIBLargeIntField
      FieldName = 'IDLOSS_FACTOR_SLOSS_FACTOR_VAL'
    end
    object ElementVAL_SLOSS_FACTOR_VAL: TFIBBCDField
      FieldName = 'VAL_SLOSS_FACTOR_VAL'
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
