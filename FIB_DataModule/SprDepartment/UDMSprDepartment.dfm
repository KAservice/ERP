object DMSprDepartment: TDMSprDepartment
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
      'select sdepartment.*'
      'from sdepartment'
      'order by sdepartment.numotdkkt_sdepartment')
    AutoUpdateOptions.UpdateTableName = 'SOBORUD_PAR'
    AutoUpdateOptions.KeyFields = 'ID_SOBORUD_PAR'
    AutoUpdateOptions.GeneratorName = 'GEN_SOBORUD_PAR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Left = 152
    Top = 24
    poUseLargeIntField = True
    object TableID_SDEPARTMENT: TFIBLargeIntField
      FieldName = 'ID_SDEPARTMENT'
    end
    object TableIDBASE_SDEPARTMENT: TFIBLargeIntField
      FieldName = 'IDBASE_SDEPARTMENT'
    end
    object TableNAME_SDEPARTMENT: TFIBWideStringField
      FieldName = 'NAME_SDEPARTMENT'
      Size = 200
    end
    object TableNUMOTDKKT_SDEPARTMENT: TFIBIntegerField
      FieldName = 'NUMOTDKKT_SDEPARTMENT'
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
      'UPDATE SDEPARTMENT'
      'SET '
      '    IDBASE_SDEPARTMENT = :IDBASE_SDEPARTMENT,'
      '    NAME_SDEPARTMENT = :NAME_SDEPARTMENT,'
      '    NUMOTDKKT_SDEPARTMENT = :NUMOTDKKT_SDEPARTMENT'
      'WHERE'
      '    ID_SDEPARTMENT = :OLD_ID_SDEPARTMENT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SDEPARTMENT'
      'WHERE'
      '        ID_SDEPARTMENT = :OLD_ID_SDEPARTMENT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SDEPARTMENT('
      '    ID_SDEPARTMENT,'
      '    IDBASE_SDEPARTMENT,'
      '    NAME_SDEPARTMENT,'
      '    NUMOTDKKT_SDEPARTMENT'
      ')'
      'VALUES('
      '    :ID_SDEPARTMENT,'
      '    :IDBASE_SDEPARTMENT,'
      '    :NAME_SDEPARTMENT,'
      '    :NUMOTDKKT_SDEPARTMENT'
      ')')
    RefreshSQL.Strings = (
      'select sdepartment.*'
      'from sdepartment'
      'where(  sdepartment.id_sdepartment=:PARAM_ID'
      
        '     ) and (     SDEPARTMENT.ID_SDEPARTMENT = :OLD_ID_SDEPARTMEN' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select sdepartment.*'
      'from sdepartment'
      'where sdepartment.id_sdepartment=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SDEPARTMENT'
    AutoUpdateOptions.KeyFields = 'ID_SDEPARTMENT'
    AutoUpdateOptions.GeneratorName = 'GEN_SDEPARTMENT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 80
    poUseLargeIntField = True
    object ElementID_SDEPARTMENT: TFIBLargeIntField
      FieldName = 'ID_SDEPARTMENT'
    end
    object ElementIDBASE_SDEPARTMENT: TFIBLargeIntField
      FieldName = 'IDBASE_SDEPARTMENT'
    end
    object ElementNAME_SDEPARTMENT: TFIBWideStringField
      FieldName = 'NAME_SDEPARTMENT'
      Size = 200
    end
    object ElementNUMOTDKKT_SDEPARTMENT: TFIBIntegerField
      FieldName = 'NUMOTDKKT_SDEPARTMENT'
    end
  end
end
