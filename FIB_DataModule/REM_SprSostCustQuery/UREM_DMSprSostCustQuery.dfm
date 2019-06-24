object REM_DMSprSostCustQuery: TREM_DMSprSostCustQuery
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 231
  Width = 363
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 40
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 40
    Top = 96
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select  * from rem_ssost_cquery')
    AutoUpdateOptions.UpdateTableName = 'REM_SSOST_CQUERY'
    AutoUpdateOptions.KeyFields = 'ID_REM_SSOST_CQUERY'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SSOST_CQUERY_ID'
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_REM_SSOST_CQUERY: TFIBLargeIntField
      FieldName = 'ID_REM_SSOST_CQUERY'
    end
    object TableGID_REM_SSOST_CQUERY: TFIBWideStringField
      FieldName = 'GID_REM_SSOST_CQUERY'
      Size = 10
    end
    object TableIDBASE_REM_SSOST_CQUERY: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SSOST_CQUERY'
    end
    object TableNAME_REM_SSOST_CQUERY: TFIBWideStringField
      FieldName = 'NAME_REM_SSOST_CQUERY'
      Size = 200
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SSOST_CQUERY'
      'SET '
      '    GID_REM_SSOST_CQUERY = :GID_REM_SSOST_CQUERY,'
      '    IDBASE_REM_SSOST_CQUERY = :IDBASE_REM_SSOST_CQUERY,'
      '    NAME_REM_SSOST_CQUERY = :NAME_REM_SSOST_CQUERY'
      'WHERE'
      '    ID_REM_SSOST_CQUERY = :OLD_ID_REM_SSOST_CQUERY'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SSOST_CQUERY'
      'WHERE'
      '        ID_REM_SSOST_CQUERY = :OLD_ID_REM_SSOST_CQUERY'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SSOST_CQUERY('
      '    ID_REM_SSOST_CQUERY,'
      '    GID_REM_SSOST_CQUERY,'
      '    IDBASE_REM_SSOST_CQUERY,'
      '    NAME_REM_SSOST_CQUERY'
      ')'
      'VALUES('
      '    :ID_REM_SSOST_CQUERY,'
      '    :GID_REM_SSOST_CQUERY,'
      '    :IDBASE_REM_SSOST_CQUERY,'
      '    :NAME_REM_SSOST_CQUERY'
      ')')
    RefreshSQL.Strings = (
      'select  * from rem_ssost_cquery'
      'where(  rem_ssost_cquery.id_rem_ssost_cquery=:PARAM_ID'
      
        '     ) and (     REM_SSOST_CQUERY.ID_REM_SSOST_CQUERY = :OLD_ID_' +
        'REM_SSOST_CQUERY'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select  * from rem_ssost_cquery'
      'where rem_ssost_cquery.id_rem_ssost_cquery=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SSOST_CQUERY'
    AutoUpdateOptions.KeyFields = 'ID_REM_SSOST_CQUERY'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SSOST_CQUERY_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 96
    poUseLargeIntField = True
    object ElementID_REM_SSOST_CQUERY: TFIBLargeIntField
      FieldName = 'ID_REM_SSOST_CQUERY'
    end
    object ElementGID_REM_SSOST_CQUERY: TFIBWideStringField
      FieldName = 'GID_REM_SSOST_CQUERY'
      Size = 10
    end
    object ElementIDBASE_REM_SSOST_CQUERY: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SSOST_CQUERY'
    end
    object ElementNAME_REM_SSOST_CQUERY: TFIBWideStringField
      FieldName = 'NAME_REM_SSOST_CQUERY'
      Size = 200
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
    Left = 264
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
    Left = 264
    Top = 96
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 152
    Top = 160
    qoStartTransaction = True
  end
end
