object REM_DMSprTypDefect: TREM_DMSprTypDefect
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 400
  Width = 453
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
      '    rem_stypdefect.*'
      'from rem_stypdefect'
      'ORDER BY rem_stypdefect.name_rem_stypdefect')
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
    object TableID_REM_STYPDEFECT: TFIBLargeIntField
      FieldName = 'ID_REM_STYPDEFECT'
    end
    object TableGID_REM_STYPDEFECT: TFIBWideStringField
      FieldName = 'GID_REM_STYPDEFECT'
      Size = 10
    end
    object TableNAME_REM_STYPDEFECT: TFIBWideStringField
      FieldName = 'NAME_REM_STYPDEFECT'
      Size = 200
    end
    object TableCODE_REM_STYPDEFECT: TFIBWideStringField
      FieldName = 'CODE_REM_STYPDEFECT'
    end
    object TableDESCR_REM_STYPDEFECT: TFIBWideStringField
      FieldName = 'DESCR_REM_STYPDEFECT'
      Size = 150
    end
    object TableIDGRP_REM_STYPDEFECT: TFIBLargeIntField
      FieldName = 'IDGRP_REM_STYPDEFECT'
    end
    object TableNAME_ENG_REM_STYPDEFECT: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_STYPDEFECT'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_STYPDEFECT'
      'SET '
      '    GID_REM_STYPDEFECT = :GID_REM_STYPDEFECT,'
      '    IDBASE_REM_STYPDEFECT = :IDBASE_REM_STYPDEFECT,'
      '    NAME_REM_STYPDEFECT = :NAME_REM_STYPDEFECT,'
      '    CODE_REM_STYPDEFECT = :CODE_REM_STYPDEFECT,'
      '    DESCR_REM_STYPDEFECT = :DESCR_REM_STYPDEFECT,'
      '    IDGRP_REM_STYPDEFECT = :IDGRP_REM_STYPDEFECT,'
      '    NAME_ENG_REM_STYPDEFECT = :NAME_ENG_REM_STYPDEFECT'
      'WHERE'
      '    ID_REM_STYPDEFECT = :OLD_ID_REM_STYPDEFECT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_STYPDEFECT'
      'WHERE'
      '        ID_REM_STYPDEFECT = :OLD_ID_REM_STYPDEFECT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_STYPDEFECT('
      '    ID_REM_STYPDEFECT,'
      '    GID_REM_STYPDEFECT,'
      '    IDBASE_REM_STYPDEFECT,'
      '    NAME_REM_STYPDEFECT,'
      '    CODE_REM_STYPDEFECT,'
      '    DESCR_REM_STYPDEFECT,'
      '    IDGRP_REM_STYPDEFECT,'
      '    NAME_ENG_REM_STYPDEFECT'
      ')'
      'VALUES('
      '    :ID_REM_STYPDEFECT,'
      '    :GID_REM_STYPDEFECT,'
      '    :IDBASE_REM_STYPDEFECT,'
      '    :NAME_REM_STYPDEFECT,'
      '    :CODE_REM_STYPDEFECT,'
      '    :DESCR_REM_STYPDEFECT,'
      '    :IDGRP_REM_STYPDEFECT,'
      '    :NAME_ENG_REM_STYPDEFECT'
      ')')
    RefreshSQL.Strings = (
      'select rem_stypdefect.*'
      'from rem_stypdefect'
      'where(  rem_stypdefect.id_rem_stypdefect=:PARAM_ID'
      
        '     ) and (     REM_STYPDEFECT.ID_REM_STYPDEFECT = :OLD_ID_REM_' +
        'STYPDEFECT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select rem_stypdefect.*'
      'from rem_stypdefect'
      'where rem_stypdefect.id_rem_stypdefect=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_STYPDEFECT'
    AutoUpdateOptions.KeyFields = 'ID_REM_STYPDEFECT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_STYPDEFECT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_REM_STYPDEFECT: TFIBLargeIntField
      FieldName = 'ID_REM_STYPDEFECT'
    end
    object ElementGID_REM_STYPDEFECT: TFIBWideStringField
      FieldName = 'GID_REM_STYPDEFECT'
      Size = 10
    end
    object ElementIDBASE_REM_STYPDEFECT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_STYPDEFECT'
    end
    object ElementNAME_REM_STYPDEFECT: TFIBWideStringField
      FieldName = 'NAME_REM_STYPDEFECT'
      Size = 200
    end
    object ElementCODE_REM_STYPDEFECT: TFIBWideStringField
      FieldName = 'CODE_REM_STYPDEFECT'
    end
    object ElementDESCR_REM_STYPDEFECT: TFIBWideStringField
      FieldName = 'DESCR_REM_STYPDEFECT'
      Size = 150
    end
    object ElementIDGRP_REM_STYPDEFECT: TFIBLargeIntField
      FieldName = 'IDGRP_REM_STYPDEFECT'
    end
    object ElementNAME_ENG_REM_STYPDEFECT: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_STYPDEFECT'
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
    Left = 256
    Top = 128
    qoStartTransaction = True
  end
end
