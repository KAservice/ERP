object REM_DMSprGrpNeispr: TREM_DMSprGrpNeispr
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 408
  Width = 519
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 64
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 64
    Top = 80
  end
  object Table: TpFIBDataSet
    UpdateSQL.Strings = (
      ''
      '    ')
    DeleteSQL.Strings = (
      ''
      '    ')
    InsertSQL.Strings = (
      '')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  REM_SGRPNEISPR'
      ''
      ' WHERE '
      
        '        REM_SGRPNEISPR.ID_REM_SGRPNEISPR = :OLD_ID_REM_SGRPNEISP' +
        'R'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  REM_SGRPNEISPR'
      'order by ID_REM_SGRPNEISPR')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 24
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_REM_SGRPNEISPR: TFIBLargeIntField
      FieldName = 'ID_REM_SGRPNEISPR'
    end
    object TableGID_REM_SGRPNEISPR: TFIBWideStringField
      FieldName = 'GID_REM_SGRPNEISPR'
      Size = 10
    end
    object TableIDGRP_REM_SGRPNEISPR: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SGRPNEISPR'
    end
    object TableNAME_REM_SGRPNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SGRPNEISPR'
      Size = 100
    end
    object TableIDBASE_REM_SGRPNEISPR: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SGRPNEISPR'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SGRPNEISPR'
      'SET '
      '    GID_REM_SGRPNEISPR = :GID_REM_SGRPNEISPR,'
      '    IDGRP_REM_SGRPNEISPR = :IDGRP_REM_SGRPNEISPR,'
      '    NAME_REM_SGRPNEISPR = :NAME_REM_SGRPNEISPR,'
      '    IDBASE_REM_SGRPNEISPR = :IDBASE_REM_SGRPNEISPR,'
      '    NAME_ENG_REM_SGRPNEISPR = :NAME_ENG_REM_SGRPNEISPR'
      'WHERE'
      '    ID_REM_SGRPNEISPR = :OLD_ID_REM_SGRPNEISPR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SGRPNEISPR'
      'WHERE'
      '        ID_REM_SGRPNEISPR = :OLD_ID_REM_SGRPNEISPR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SGRPNEISPR('
      '    ID_REM_SGRPNEISPR,'
      '    GID_REM_SGRPNEISPR,'
      '    IDGRP_REM_SGRPNEISPR,'
      '    NAME_REM_SGRPNEISPR,'
      '    IDBASE_REM_SGRPNEISPR,'
      '    NAME_ENG_REM_SGRPNEISPR'
      ')'
      'VALUES('
      '    :ID_REM_SGRPNEISPR,'
      '    :GID_REM_SGRPNEISPR,'
      '    :IDGRP_REM_SGRPNEISPR,'
      '    :NAME_REM_SGRPNEISPR,'
      '    :IDBASE_REM_SGRPNEISPR,'
      '    :NAME_ENG_REM_SGRPNEISPR'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from REM_SGRPNEISPR '
      'where(  ID_REM_SGRPNEISPR=:PARAM_ID'
      
        '     ) and (     REM_SGRPNEISPR.ID_REM_SGRPNEISPR = :OLD_ID_REM_' +
        'SGRPNEISPR'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from REM_SGRPNEISPR '
      'where ID_REM_SGRPNEISPR=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SGRPNEISPR'
    AutoUpdateOptions.KeyFields = 'ID_REM_SGRPNEISPR'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SGRPNEISPR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SGRPNEISPR: TFIBLargeIntField
      FieldName = 'ID_REM_SGRPNEISPR'
    end
    object ElementGID_REM_SGRPNEISPR: TFIBWideStringField
      FieldName = 'GID_REM_SGRPNEISPR'
      Size = 10
    end
    object ElementIDGRP_REM_SGRPNEISPR: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SGRPNEISPR'
    end
    object ElementNAME_REM_SGRPNEISPR: TFIBWideStringField
      FieldName = 'NAME_REM_SGRPNEISPR'
      Size = 200
    end
    object ElementIDBASE_REM_SGRPNEISPR: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SGRPNEISPR'
    end
    object ElementNAME_ENG_REM_SGRPNEISPR: TFIBWideStringField
      FieldName = 'NAME_ENG_REM_SGRPNEISPR'
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
    Left = 216
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 216
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 272
    Top = 56
    qoStartTransaction = True
  end
end
