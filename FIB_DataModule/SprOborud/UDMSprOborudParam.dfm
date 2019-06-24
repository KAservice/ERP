object DMSprOborudParam: TDMSprOborudParam
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 341
  Width = 435
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SOBORUD_PAR'
      'SET '
      '    IDBASE_SOBORUD_PAR = :IDBASE_SOBORUD_PAR,'
      '    GID_SOBORUD_PAR = :GID_SOBORUD_PAR,'
      '    IDOBORUD_SOBORUD_PAR = :IDOBORUD_SOBORUD_PAR,'
      '    NAME_SOBORUD_PAR = :NAME_SOBORUD_PAR,'
      '    VALUE_SOBORUD_PAR = :VALUE_SOBORUD_PAR,'
      '    VALUE_TIMESTAMP_SOBORUD_PAR = :VALUE_TIMESTAMP_SOBORUD_PAR,'
      '    INDEX_SOBORUD_PAR = :INDEX_SOBORUD_PAR,'
      '    BEFORE_CONNECT_SOBORUD_PAR = :BEFORE_CONNECT_SOBORUD_PAR,'
      '    AFTER_CONNECT_SOBORUD_PAR = :AFTER_CONNECT_SOBORUD_PAR,'
      '    ON_CONNECT_SOBORUD_PAR = :ON_CONNECT_SOBORUD_PAR,'
      '    NAME_GRP_SOBORUD_PAR = :NAME_GRP_SOBORUD_PAR,'
      '    TYPE_PARAMETER_SOBORUD_PAR = :TYPE_PARAMETER_SOBORUD_PAR'
      'WHERE'
      '    ID_SOBORUD_PAR = :OLD_ID_SOBORUD_PAR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SOBORUD_PAR'
      'WHERE'
      '        ID_SOBORUD_PAR = :OLD_ID_SOBORUD_PAR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SOBORUD_PAR('
      '    ID_SOBORUD_PAR,'
      '    IDBASE_SOBORUD_PAR,'
      '    GID_SOBORUD_PAR,'
      '    IDOBORUD_SOBORUD_PAR,'
      '    NAME_SOBORUD_PAR,'
      '    VALUE_SOBORUD_PAR,'
      '    VALUE_TIMESTAMP_SOBORUD_PAR,'
      '    INDEX_SOBORUD_PAR,'
      '    BEFORE_CONNECT_SOBORUD_PAR,'
      '    AFTER_CONNECT_SOBORUD_PAR,'
      '    ON_CONNECT_SOBORUD_PAR,'
      '    NAME_GRP_SOBORUD_PAR,'
      '    TYPE_PARAMETER_SOBORUD_PAR'
      ')'
      'VALUES('
      '    :ID_SOBORUD_PAR,'
      '    :IDBASE_SOBORUD_PAR,'
      '    :GID_SOBORUD_PAR,'
      '    :IDOBORUD_SOBORUD_PAR,'
      '    :NAME_SOBORUD_PAR,'
      '    :VALUE_SOBORUD_PAR,'
      '    :VALUE_TIMESTAMP_SOBORUD_PAR,'
      '    :INDEX_SOBORUD_PAR,'
      '    :BEFORE_CONNECT_SOBORUD_PAR,'
      '    :AFTER_CONNECT_SOBORUD_PAR,'
      '    :ON_CONNECT_SOBORUD_PAR,'
      '    :NAME_GRP_SOBORUD_PAR,'
      '    :TYPE_PARAMETER_SOBORUD_PAR'
      ')')
    RefreshSQL.Strings = (
      'select soborud_par.*'
      'from soborud_par'
      'where(  soborud_par.idoborud_soborud_par=:PARAM_IDOWNER'
      
        '     ) and (     SOBORUD_PAR.ID_SOBORUD_PAR = :OLD_ID_SOBORUD_PA' +
        'R'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select soborud_par.*'
      'from soborud_par'
      'where soborud_par.idoborud_soborud_par=:PARAM_IDOWNER'
      'order by soborud_par.index_soborud_par')
    AutoUpdateOptions.UpdateTableName = 'SOBORUD_PAR'
    AutoUpdateOptions.KeyFields = 'ID_SOBORUD_PAR'
    AutoUpdateOptions.GeneratorName = 'GEN_SOBORUD_PAR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_SOBORUD_PAR: TFIBLargeIntField
      FieldName = 'ID_SOBORUD_PAR'
    end
    object TableIDBASE_SOBORUD_PAR: TFIBLargeIntField
      FieldName = 'IDBASE_SOBORUD_PAR'
    end
    object TableGID_SOBORUD_PAR: TFIBWideStringField
      FieldName = 'GID_SOBORUD_PAR'
      Size = 10
    end
    object TableIDOBORUD_SOBORUD_PAR: TFIBLargeIntField
      FieldName = 'IDOBORUD_SOBORUD_PAR'
    end
    object TableNAME_SOBORUD_PAR: TFIBWideStringField
      FieldName = 'NAME_SOBORUD_PAR'
      Size = 30
    end
    object TableVALUE_SOBORUD_PAR: TFIBWideStringField
      FieldName = 'VALUE_SOBORUD_PAR'
      Size = 200
    end
    object TableVALUE_TIMESTAMP_SOBORUD_PAR: TFIBDateTimeField
      FieldName = 'VALUE_TIMESTAMP_SOBORUD_PAR'
    end
    object TableINDEX_SOBORUD_PAR: TFIBIntegerField
      FieldName = 'INDEX_SOBORUD_PAR'
    end
    object TableBEFORE_CONNECT_SOBORUD_PAR: TFIBSmallIntField
      FieldName = 'BEFORE_CONNECT_SOBORUD_PAR'
    end
    object TableAFTER_CONNECT_SOBORUD_PAR: TFIBSmallIntField
      FieldName = 'AFTER_CONNECT_SOBORUD_PAR'
    end
    object TableON_CONNECT_SOBORUD_PAR: TFIBSmallIntField
      FieldName = 'ON_CONNECT_SOBORUD_PAR'
    end
    object TableNAME_GRP_SOBORUD_PAR: TFIBWideStringField
      FieldName = 'NAME_GRP_SOBORUD_PAR'
      Size = 200
    end
    object TableTYPE_PARAMETER_SOBORUD_PAR: TFIBIntegerField
      FieldName = 'TYPE_PARAMETER_SOBORUD_PAR'
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
    Left = 240
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 240
    Top = 80
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SOBORUD_PAR'
      'SET '
      '    IDBASE_SOBORUD_PAR = :IDBASE_SOBORUD_PAR,'
      '    GID_SOBORUD_PAR = :GID_SOBORUD_PAR,'
      '    IDOBORUD_SOBORUD_PAR = :IDOBORUD_SOBORUD_PAR,'
      '    NAME_SOBORUD_PAR = :NAME_SOBORUD_PAR,'
      '    VALUE_SOBORUD_PAR = :VALUE_SOBORUD_PAR,'
      '    VALUE_TIMESTAMP_SOBORUD_PAR = :VALUE_TIMESTAMP_SOBORUD_PAR,'
      '    INDEX_SOBORUD_PAR = :INDEX_SOBORUD_PAR,'
      '    BEFORE_CONNECT_SOBORUD_PAR = :BEFORE_CONNECT_SOBORUD_PAR,'
      '    AFTER_CONNECT_SOBORUD_PAR = :AFTER_CONNECT_SOBORUD_PAR,'
      '    ON_CONNECT_SOBORUD_PAR = :ON_CONNECT_SOBORUD_PAR,'
      '    NAME_GRP_SOBORUD_PAR = :NAME_GRP_SOBORUD_PAR,'
      '    TYPE_PARAMETER_SOBORUD_PAR = :TYPE_PARAMETER_SOBORUD_PAR'
      'WHERE'
      '    ID_SOBORUD_PAR = :OLD_ID_SOBORUD_PAR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SOBORUD_PAR'
      'WHERE'
      '        ID_SOBORUD_PAR = :OLD_ID_SOBORUD_PAR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SOBORUD_PAR('
      '    ID_SOBORUD_PAR,'
      '    IDBASE_SOBORUD_PAR,'
      '    GID_SOBORUD_PAR,'
      '    IDOBORUD_SOBORUD_PAR,'
      '    NAME_SOBORUD_PAR,'
      '    VALUE_SOBORUD_PAR,'
      '    VALUE_TIMESTAMP_SOBORUD_PAR,'
      '    INDEX_SOBORUD_PAR,'
      '    BEFORE_CONNECT_SOBORUD_PAR,'
      '    AFTER_CONNECT_SOBORUD_PAR,'
      '    ON_CONNECT_SOBORUD_PAR,'
      '    NAME_GRP_SOBORUD_PAR,'
      '    TYPE_PARAMETER_SOBORUD_PAR'
      ')'
      'VALUES('
      '    :ID_SOBORUD_PAR,'
      '    :IDBASE_SOBORUD_PAR,'
      '    :GID_SOBORUD_PAR,'
      '    :IDOBORUD_SOBORUD_PAR,'
      '    :NAME_SOBORUD_PAR,'
      '    :VALUE_SOBORUD_PAR,'
      '    :VALUE_TIMESTAMP_SOBORUD_PAR,'
      '    :INDEX_SOBORUD_PAR,'
      '    :BEFORE_CONNECT_SOBORUD_PAR,'
      '    :AFTER_CONNECT_SOBORUD_PAR,'
      '    :ON_CONNECT_SOBORUD_PAR,'
      '    :NAME_GRP_SOBORUD_PAR,'
      '    :TYPE_PARAMETER_SOBORUD_PAR'
      ')')
    RefreshSQL.Strings = (
      'select soborud_par.*'
      'from soborud_par'
      'where(  soborud_par.id_soborud_par=:PARAM_ID'
      
        '     ) and (     SOBORUD_PAR.ID_SOBORUD_PAR = :OLD_ID_SOBORUD_PA' +
        'R'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select soborud_par.*'
      'from soborud_par'
      'where soborud_par.id_soborud_par=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SOBORUD_PAR'
    AutoUpdateOptions.KeyFields = 'ID_SOBORUD_PAR'
    AutoUpdateOptions.GeneratorName = 'GEN_SOBORUD_PAR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_SOBORUD_PAR: TFIBLargeIntField
      FieldName = 'ID_SOBORUD_PAR'
    end
    object ElementIDBASE_SOBORUD_PAR: TFIBLargeIntField
      FieldName = 'IDBASE_SOBORUD_PAR'
    end
    object ElementGID_SOBORUD_PAR: TFIBWideStringField
      FieldName = 'GID_SOBORUD_PAR'
      Size = 10
    end
    object ElementIDOBORUD_SOBORUD_PAR: TFIBLargeIntField
      FieldName = 'IDOBORUD_SOBORUD_PAR'
    end
    object ElementNAME_SOBORUD_PAR: TFIBWideStringField
      FieldName = 'NAME_SOBORUD_PAR'
      Size = 30
    end
    object ElementVALUE_SOBORUD_PAR: TFIBWideStringField
      FieldName = 'VALUE_SOBORUD_PAR'
      Size = 200
    end
    object ElementVALUE_TIMESTAMP_SOBORUD_PAR: TFIBDateTimeField
      FieldName = 'VALUE_TIMESTAMP_SOBORUD_PAR'
    end
    object ElementINDEX_SOBORUD_PAR: TFIBIntegerField
      FieldName = 'INDEX_SOBORUD_PAR'
    end
    object ElementBEFORE_CONNECT_SOBORUD_PAR: TFIBSmallIntField
      FieldName = 'BEFORE_CONNECT_SOBORUD_PAR'
    end
    object ElementAFTER_CONNECT_SOBORUD_PAR: TFIBSmallIntField
      FieldName = 'AFTER_CONNECT_SOBORUD_PAR'
    end
    object ElementON_CONNECT_SOBORUD_PAR: TFIBSmallIntField
      FieldName = 'ON_CONNECT_SOBORUD_PAR'
    end
    object ElementNAME_GRP_SOBORUD_PAR: TFIBWideStringField
      FieldName = 'NAME_GRP_SOBORUD_PAR'
      Size = 200
    end
    object ElementTYPE_PARAMETER_SOBORUD_PAR: TFIBIntegerField
      FieldName = 'TYPE_PARAMETER_SOBORUD_PAR'
    end
  end
end
