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
    Left = 136
    Top = 16
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
    object TableNOACT_SINFBASE_OBMEN: TFIBSmallIntField
      FieldName = 'NOACT_SINFBASE_OBMEN'
    end
    object TableGID_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'GID_SINFBASE_OBMEN'
      Size = 10
    end
    object TableNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 100
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
      '    NOACT_SINFBASE_OBMEN = :NOACT_SINFBASE_OBMEN,'
      '    PREF_NUM_SINFBASE_OBMEN = :PREF_NUM_SINFBASE_OBMEN'
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
      '    NOACT_SINFBASE_OBMEN,'
      '    PREF_NUM_SINFBASE_OBMEN'
      ')'
      'VALUES('
      '    :ID_SINFBASE_OBMEN,'
      '    :GID_SINFBASE_OBMEN,'
      '    :NAME_SINFBASE_OBMEN,'
      '    :PREFIKS_SINFBASE_OBMEN,'
      '    :IDTIZM_SINFBASE_OBMEN,'
      '    :IDBASE_SINFBASE_OBMEN,'
      '    :NOACT_SINFBASE_OBMEN,'
      '    :PREF_NUM_SINFBASE_OBMEN'
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
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 80
    object ElementID_SINFBASE_OBMEN: TFIBBCDField
      FieldName = 'ID_SINFBASE_OBMEN'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTIZM_SINFBASE_OBMEN: TFIBIntegerField
      FieldName = 'IDTIZM_SINFBASE_OBMEN'
    end
    object ElementNOACT_SINFBASE_OBMEN: TFIBSmallIntField
      FieldName = 'NOACT_SINFBASE_OBMEN'
    end
    object ElementGID_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'GID_SINFBASE_OBMEN'
      Size = 10
    end
    object ElementNAME_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'NAME_SINFBASE_OBMEN'
      Size = 200
    end
    object ElementPREF_NUM_SINFBASE_OBMEN: TFIBWideStringField
      FieldName = 'PREF_NUM_SINFBASE_OBMEN'
      Size = 3
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
    Left = 200
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
    Left = 200
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 264
    Top = 56
    qoStartTransaction = True
  end
end
