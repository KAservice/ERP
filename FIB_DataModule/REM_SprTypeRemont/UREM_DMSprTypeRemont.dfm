object REM_DMSprTypeRemont: TREM_DMSprTypeRemont
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
      'select  * from REM_STREMONT')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_STREMONT: TFIBLargeIntField
      FieldName = 'ID_STREMONT'
    end
    object TableGID_STREMONT: TFIBWideStringField
      FieldName = 'GID_STREMONT'
      Size = 10
    end
    object TableNAME_STREMONT: TFIBWideStringField
      FieldName = 'NAME_STREMONT'
      Size = 200
    end
    object TableIDBASE_REM_STREMONT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STREMONT'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_STREMONT'
      'SET '
      '    GID_STREMONT = :GID_STREMONT,'
      '    NAME_STREMONT = :NAME_STREMONT'
      'WHERE'
      '    ID_STREMONT = :OLD_ID_STREMONT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_STREMONT'
      'WHERE'
      '        ID_STREMONT = :OLD_ID_STREMONT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_STREMONT('
      '    ID_STREMONT,'
      '    GID_STREMONT,'
      '    NAME_STREMONT'
      ')'
      'VALUES('
      '    :ID_STREMONT,'
      '    :GID_STREMONT,'
      '    :NAME_STREMONT'
      ')')
    RefreshSQL.Strings = (
      'select * from REM_STREMONT '
      'where(  ID_STREMONT=:PARAM_ID'
      '     ) and (     REM_STREMONT.ID_STREMONT = :OLD_ID_STREMONT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from REM_STREMONT '
      'where ID_STREMONT=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_STREMONT'
    AutoUpdateOptions.KeyFields = 'ID_STREMONT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_STREMONT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 96
    poUseLargeIntField = True
    object ElementGID_STREMONT: TFIBWideStringField
      FieldName = 'GID_STREMONT'
      Size = 10
    end
    object ElementNAME_STREMONT: TFIBWideStringField
      FieldName = 'NAME_STREMONT'
      Size = 200
    end
    object ElementIDBASE_REM_STREMONT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STREMONT'
    end
    object ElementID_STREMONT: TFIBLargeIntField
      FieldName = 'ID_STREMONT'
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
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 160
    Top = 160
    qoStartTransaction = True
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 264
    Top = 96
  end
end
