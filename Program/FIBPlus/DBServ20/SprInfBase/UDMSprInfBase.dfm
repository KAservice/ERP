object DMSprInfBase: TDMSprInfBase
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 225
  Width = 319
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SINFBASE_OBMEN')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 136
    Top = 16
    object TableNAME_SINFBASE_OBMEN: TFIBStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
      EmptyStrToNull = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SINFBASE_OBMEN: TFIBBCDField
      FieldName = 'ID_SINFBASE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableIDTIZM_SINFBASE_OBMEN: TFIBIntegerField
      FieldName = 'IDTIZM_SINFBASE_OBMEN'
    end
    object TableGID_SINFBASE_OBMEN: TFIBStringField
      FieldName = 'GID_SINFBASE_OBMEN'
      Size = 10
      EmptyStrToNull = True
    end
    object TableNOACT_SINFBASE_OBMEN: TFIBSmallIntField
      FieldName = 'NOACT_SINFBASE_OBMEN'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SINFBASE_OBMEN'
      'SET '
      '    GID_SINFBASE_OBMEN = :GID_SINFBASE_OBMEN,'
      '    NAME_SINFBASE_OBMEN = :NAME_SINFBASE_OBMEN,'
      '    PREFIKS_SINFBASE_OBMEN = :PREFIKS_SINFBASE_OBMEN,'
      '    IDTIZM_SINFBASE_OBMEN = :IDTIZM_SINFBASE_OBMEN,'
      '    IDBASE_SINFBASE_OBMEN = :IDBASE_SINFBASE_OBMEN,'
      '    NOACT_SINFBASE_OBMEN = :NOACT_SINFBASE_OBMEN'
      'WHERE'
      '    ID_SINFBASE_OBMEN = :OLD_ID_SINFBASE_OBMEN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SINFBASE_OBMEN'
      'WHERE'
      '        ID_SINFBASE_OBMEN = :OLD_ID_SINFBASE_OBMEN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SINFBASE_OBMEN('
      '    ID_SINFBASE_OBMEN,'
      '    GID_SINFBASE_OBMEN,'
      '    NAME_SINFBASE_OBMEN,'
      '    PREFIKS_SINFBASE_OBMEN,'
      '    IDTIZM_SINFBASE_OBMEN,'
      '    IDBASE_SINFBASE_OBMEN,'
      '    NOACT_SINFBASE_OBMEN'
      ')'
      'VALUES('
      '    :ID_SINFBASE_OBMEN,'
      '    :GID_SINFBASE_OBMEN,'
      '    :NAME_SINFBASE_OBMEN,'
      '    :PREFIKS_SINFBASE_OBMEN,'
      '    :IDTIZM_SINFBASE_OBMEN,'
      '    :IDBASE_SINFBASE_OBMEN,'
      '    :NOACT_SINFBASE_OBMEN'
      ')')
    RefreshSQL.Strings = (
      'select * from SINFBASE_OBMEN where(  ID_SINFBASE_OBMEN=:PARAM_ID'
      
        '     ) and (     SINFBASE_OBMEN.ID_SINFBASE_OBMEN = :OLD_ID_SINF' +
        'BASE_OBMEN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SINFBASE_OBMEN where ID_SINFBASE_OBMEN=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SINFBASE_OBMEN'
    AutoUpdateOptions.KeyFields = 'ID_SINFBASE_OBMEN'
    AutoUpdateOptions.GeneratorName = 'GEN_SINFBASE_OBMEN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 136
    Top = 80
    object ElementNAME_SINFBASE_OBMEN: TFIBStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
      EmptyStrToNull = True
    end
    object ElementID_SINFBASE_OBMEN: TFIBBCDField
      FieldName = 'ID_SINFBASE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTIZM_SINFBASE_OBMEN: TFIBIntegerField
      FieldName = 'IDTIZM_SINFBASE_OBMEN'
    end
    object ElementGID_SINFBASE_OBMEN: TFIBStringField
      FieldName = 'GID_SINFBASE_OBMEN'
      Size = 10
      EmptyStrToNull = True
    end
    object ElementNOACT_SINFBASE_OBMEN: TFIBSmallIntField
      FieldName = 'NOACT_SINFBASE_OBMEN'
    end
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 200
    Top = 16
  end
  object IBTrUpdate: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 200
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 264
    Top = 56
    qoStartTransaction = True
  end
  object BaseForObmen: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SBASE_FOR_OBMEN'
      'SET '
      '    IDBASE_SBASE_FOR_OBMEN = :IDBASE_SBASE_FOR_OBMEN,'
      '    IDBASEROD_SBASE_FOR_OBMEN = :IDBASEROD_SBASE_FOR_OBMEN,'
      '    IDBASEOBMEN_SBASE_FOR_OBMEN = :IDBASEOBMEN_SBASE_FOR_OBMEN'
      'WHERE'
      '    ID_SBASE_FOR_OBMEN = :OLD_ID_SBASE_FOR_OBMEN'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SBASE_FOR_OBMEN'
      'WHERE'
      '        ID_SBASE_FOR_OBMEN = :OLD_ID_SBASE_FOR_OBMEN'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SBASE_FOR_OBMEN('
      '    ID_SBASE_FOR_OBMEN,'
      '    IDBASE_SBASE_FOR_OBMEN,'
      '    IDBASEROD_SBASE_FOR_OBMEN,'
      '    IDBASEOBMEN_SBASE_FOR_OBMEN'
      ')'
      'VALUES('
      '    :ID_SBASE_FOR_OBMEN,'
      '    :IDBASE_SBASE_FOR_OBMEN,'
      '    :IDBASEROD_SBASE_FOR_OBMEN,'
      '    :IDBASEOBMEN_SBASE_FOR_OBMEN'
      ')')
    RefreshSQL.Strings = (
      'select  SBASE_FOR_OBMEN.*, NAME_SINFBASE_OBMEN'
      'from SBASE_FOR_OBMEN'
      
        'left outer join SINFBASE_OBMEN on IDBASEOBMEN_SBASE_FOR_OBMEN=ID' +
        '_SINFBASE_OBMEN '
      'where(  IDBASEROD_SBASE_FOR_OBMEN=:PARAM_IDBASE'
      
        '     ) and (     SBASE_FOR_OBMEN.ID_SBASE_FOR_OBMEN = :OLD_ID_SB' +
        'ASE_FOR_OBMEN'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select  SBASE_FOR_OBMEN.*, NAME_SINFBASE_OBMEN'
      'from SBASE_FOR_OBMEN'
      
        'left outer join SINFBASE_OBMEN on IDBASEOBMEN_SBASE_FOR_OBMEN=ID' +
        '_SINFBASE_OBMEN '
      'where IDBASEROD_SBASE_FOR_OBMEN=:PARAM_IDBASE')
    AutoUpdateOptions.UpdateTableName = 'STYPEPRICE_OBMEN'
    AutoUpdateOptions.KeyFields = 'ID_STYPEPRICE_OBMEN'
    AutoUpdateOptions.GeneratorName = 'GEN_STYPEPRICE_OBMEN_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 200
    Top = 144
    object TableID_SBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'ID_SBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_SBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASE_SBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASEROD_SBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASEROD_SBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASEOBMEN_SBASE_FOR_OBMEN: TFIBBCDField
      FieldName = 'IDBASEOBMEN_SBASE_FOR_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object FIBStringField1: TFIBStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 50
      EmptyStrToNull = True
    end
    object IntegerField1: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
  end
  object DataSourceBaseForObmen: TDataSource
    DataSet = BaseForObmen
    Left = 48
    Top = 144
  end
end
