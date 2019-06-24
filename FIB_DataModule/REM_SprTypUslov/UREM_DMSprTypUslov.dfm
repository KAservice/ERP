object REM_DMSprTypUslov: TREM_DMSprTypUslov
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 421
  Width = 507
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 64
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select'
      '    rem_stypuslov.*'
      'from rem_stypuslov'
      'ORDER BY rem_stypuslov.name_rem_stypuslov')
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
    object TableID_REM_STYPUSLOV: TFIBLargeIntField
      FieldName = 'ID_REM_STYPUSLOV'
    end
    object TableGID_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'GID_REM_STYPUSLOV'
      Size = 10
    end
    object TableIDGRP_REM_STYPUSLOV: TFIBLargeIntField
      FieldName = 'IDGRP_REM_STYPUSLOV'
    end
    object TableNAME_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'NAME_REM_STYPUSLOV'
      Size = 200
    end
    object TableDESCR_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'DESCR_REM_STYPUSLOV'
      Size = 150
    end
    object TableNAME_ENG_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_STYPUSLOV'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_STYPUSLOV'
      'SET '
      '    GID_REM_STYPUSLOV = :GID_REM_STYPUSLOV,'
      '    IDBASE_REM_STYPUSLOV = :IDBASE_REM_STYPUSLOV,'
      '    IDGRP_REM_STYPUSLOV = :IDGRP_REM_STYPUSLOV,'
      '    NAME_REM_STYPUSLOV = :NAME_REM_STYPUSLOV,'
      '    DESCR_REM_STYPUSLOV = :DESCR_REM_STYPUSLOV,'
      '    NAME_ENG_REM_STYPUSLOV = :NAME_ENG_REM_STYPUSLOV'
      'WHERE'
      '    ID_REM_STYPUSLOV = :OLD_ID_REM_STYPUSLOV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_STYPUSLOV'
      'WHERE'
      '        ID_REM_STYPUSLOV = :OLD_ID_REM_STYPUSLOV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_STYPUSLOV('
      '    ID_REM_STYPUSLOV,'
      '    GID_REM_STYPUSLOV,'
      '    IDBASE_REM_STYPUSLOV,'
      '    IDGRP_REM_STYPUSLOV,'
      '    NAME_REM_STYPUSLOV,'
      '    DESCR_REM_STYPUSLOV,'
      '    NAME_ENG_REM_STYPUSLOV'
      ')'
      'VALUES('
      '    :ID_REM_STYPUSLOV,'
      '    :GID_REM_STYPUSLOV,'
      '    :IDBASE_REM_STYPUSLOV,'
      '    :IDGRP_REM_STYPUSLOV,'
      '    :NAME_REM_STYPUSLOV,'
      '    :DESCR_REM_STYPUSLOV,'
      '    :NAME_ENG_REM_STYPUSLOV'
      ')')
    RefreshSQL.Strings = (
      'select rem_stypuslov.*'
      'from rem_stypuslov'
      'where(  rem_stypuslov.id_rem_stypuslov=:PARAM_ID'
      
        '     ) and (     REM_STYPUSLOV.ID_REM_STYPUSLOV = :OLD_ID_REM_ST' +
        'YPUSLOV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_stypuslov.*'
      'from rem_stypuslov'
      'where rem_stypuslov.id_rem_stypuslov=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_STYPUSLOV'
    AutoUpdateOptions.KeyFields = 'ID_REM_STYPUSLOV'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_STYPUSLOV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_REM_STYPUSLOV: TFIBLargeIntField
      FieldName = 'ID_REM_STYPUSLOV'
    end
    object ElementGID_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'GID_REM_STYPUSLOV'
      Size = 10
    end
    object ElementIDBASE_REM_STYPUSLOV: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STYPUSLOV'
    end
    object ElementIDGRP_REM_STYPUSLOV: TFIBLargeIntField
      FieldName = 'IDGRP_REM_STYPUSLOV'
    end
    object ElementNAME_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'NAME_REM_STYPUSLOV'
      Size = 200
    end
    object ElementDESCR_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'DESCR_REM_STYPUSLOV'
      Size = 150
    end
    object ElementNAME_ENG_REM_STYPUSLOV: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_STYPUSLOV'
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
    Left = 256
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
    Left = 256
    Top = 64
  end
  object pFIBQuery: TpFIBQuery
    Transaction = IBTr
    Left = 256
    Top = 128
    qoStartTransaction = True
  end
end
