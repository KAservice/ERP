object REM_DMSprActCategory: TREM_DMSprActCategory
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 305
  Width = 596
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 88
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '  rem_sactcategory.*'
      'from '
      '  rem_sactcategory')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_REM_SACTCATEGORY: TFIBLargeIntField
      FieldName = 'ID_REM_SACTCATEGORY'
    end
    object TableIDBASE_REM_SACTCATEGORY: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SACTCATEGORY'
    end
    object TableGID_REM_SACTCATEGORY: TFIBWideStringField
      FieldName = 'GID_REM_SACTCATEGORY'
      Size = 10
    end
    object TableNAME_REM_SACTCATEGORY: TFIBWideStringField
      FieldName = 'NAME_REM_SACTCATEGORY'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SACTCATEGORY'
      'SET '
      '    IDBASE_REM_SACTCATEGORY = :IDBASE_REM_SACTCATEGORY,'
      '    GID_REM_SACTCATEGORY = :GID_REM_SACTCATEGORY,'
      '    NAME_REM_SACTCATEGORY = :NAME_REM_SACTCATEGORY'
      'WHERE'
      '    ID_REM_SACTCATEGORY = :OLD_ID_REM_SACTCATEGORY'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SACTCATEGORY'
      'WHERE'
      '        ID_REM_SACTCATEGORY = :OLD_ID_REM_SACTCATEGORY'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SACTCATEGORY('
      '    ID_REM_SACTCATEGORY,'
      '    IDBASE_REM_SACTCATEGORY,'
      '    GID_REM_SACTCATEGORY,'
      '    NAME_REM_SACTCATEGORY'
      ')'
      'VALUES('
      '    :ID_REM_SACTCATEGORY,'
      '    :IDBASE_REM_SACTCATEGORY,'
      '    :GID_REM_SACTCATEGORY,'
      '    :NAME_REM_SACTCATEGORY'
      ')')
    RefreshSQL.Strings = (
      'select '
      '  rem_sactcategory.*'
      'from '
      '  rem_sactcategory'
      'where(  '
      '  rem_sactcategory.id_rem_sactcategory=:PARAM_ID'
      
        '     ) and (     REM_SACTCATEGORY.ID_REM_SACTCATEGORY = :OLD_ID_' +
        'REM_SACTCATEGORY'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select '
      '  rem_sactcategory.*'
      'from '
      '  rem_sactcategory'
      'where '
      '  rem_sactcategory.id_rem_sactcategory=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SACTCATEGORY'
    AutoUpdateOptions.KeyFields = 'ID_REM_SACTCATEGORY'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SACTCATEGORY_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 88
    poUseLargeIntField = True
    object ElementID_REM_SACTCATEGORY: TFIBLargeIntField
      FieldName = 'ID_REM_SACTCATEGORY'
    end
    object ElementIDBASE_REM_SACTCATEGORY: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SACTCATEGORY'
    end
    object ElementGID_REM_SACTCATEGORY: TFIBWideStringField
      FieldName = 'GID_REM_SACTCATEGORY'
      Size = 10
    end
    object ElementNAME_REM_SACTCATEGORY: TFIBWideStringField
      FieldName = 'NAME_REM_SACTCATEGORY'
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
    Top = 88
  end
end
