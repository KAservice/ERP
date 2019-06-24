object REM_DMSprNeispr: TREM_DMSprNeispr
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 403
  Width = 527
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
      'select *'
      'from REM_SNEISPR'
      'ORDER BY NAME_REM_SNEISPR')
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
    object TableID_REM_SNEISPR: TFIBLargeIntField
      FieldName = 'ID_REM_SNEISPR'
    end
    object TableGID_REM_SNEISPR: TFIBWideStringField
      FieldName = 'GID_REM_SNEISPR'
      Size = 10
    end
    object TableIDGRP_REM_SNEISPR: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SNEISPR'
    end
    object TableNAME_REM_SNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SNEISPR'
      Size = 200
    end
    object TableIDBASE_REM_SNEISPR: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SNEISPR'
    end
    object TableNAME_ENG_REM_SNEISPR: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SNEISPR'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SNEISPR'
      'SET '
      '    GID_REM_SNEISPR = :GID_REM_SNEISPR,'
      '    IDGRP_REM_SNEISPR = :IDGRP_REM_SNEISPR,'
      '    NAME_REM_SNEISPR = :NAME_REM_SNEISPR,'
      '    IDBASE_REM_SNEISPR = :IDBASE_REM_SNEISPR,'
      '    NAME_ENG_REM_SNEISPR = :NAME_ENG_REM_SNEISPR'
      'WHERE'
      '    ID_REM_SNEISPR = :OLD_ID_REM_SNEISPR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SNEISPR'
      'WHERE'
      '        ID_REM_SNEISPR = :OLD_ID_REM_SNEISPR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SNEISPR('
      '    ID_REM_SNEISPR,'
      '    GID_REM_SNEISPR,'
      '    IDGRP_REM_SNEISPR,'
      '    NAME_REM_SNEISPR,'
      '    IDBASE_REM_SNEISPR,'
      '    NAME_ENG_REM_SNEISPR'
      ')'
      'VALUES('
      '    :ID_REM_SNEISPR,'
      '    :GID_REM_SNEISPR,'
      '    :IDGRP_REM_SNEISPR,'
      '    :NAME_REM_SNEISPR,'
      '    :IDBASE_REM_SNEISPR,'
      '    :NAME_ENG_REM_SNEISPR'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from REM_SNEISPR'
      ''
      'where(  ID_REM_SNEISPR=:PARAM_ID'
      
        '     ) and (     REM_SNEISPR.ID_REM_SNEISPR = :OLD_ID_REM_SNEISP' +
        'R'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from REM_SNEISPR'
      ''
      'where ID_REM_SNEISPR=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SNEISPR'
    AutoUpdateOptions.KeyFields = 'ID_REM_SNEISPR'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SNEISPR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_REM_SNEISPR: TFIBLargeIntField
      FieldName = 'ID_REM_SNEISPR'
    end
    object ElementGID_REM_SNEISPR: TFIBWideStringField
      FieldName = 'GID_REM_SNEISPR'
      Size = 10
    end
    object ElementIDGRP_REM_SNEISPR: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SNEISPR'
    end
    object ElementNAME_REM_SNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SNEISPR'
      Size = 200
    end
    object ElementIDBASE_REM_SNEISPR: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SNEISPR'
    end
    object ElementNAME_ENG_REM_SNEISPR: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SNEISPR'
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
