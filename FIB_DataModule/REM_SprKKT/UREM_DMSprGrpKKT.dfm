object REM_DMSprGrpKKT: TREM_DMSprGrpKKT
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 224
  Width = 345
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
    SelectSQL.Strings = (
      'select * '
      'from '
      '  rem_sgrpkkt'
      'order by rem_sgrpkkt.idgrp_rem_sgrpkkt')
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
    object TableID_REM_SGRPKKT: TFIBLargeIntField
      FieldName = 'ID_REM_SGRPKKT'
    end
    object TableIDBASE_REM_SGRPKKT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SGRPKKT'
    end
    object TableNAME_REM_SGRPKKT: TFIBWideStringField
      FieldName = 'NAME_REM_SGRPKKT'
      Size = 100
    end
    object TableIDGRP_REM_SGRPKKT: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SGRPKKT'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_SGRPKKT'
      'SET '
      '    NAME_REM_SGRPKKT = :NAME_REM_SGRPKKT,'
      '    IDGRP_REM_SGRPKKT = :IDGRP_REM_SGRPKKT'
      'WHERE'
      '    ID_REM_SGRPKKT = :OLD_ID_REM_SGRPKKT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_SGRPKKT'
      'WHERE'
      '        ID_REM_SGRPKKT = :OLD_ID_REM_SGRPKKT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_SGRPKKT('
      '    ID_REM_SGRPKKT,'
      '    NAME_REM_SGRPKKT,'
      '    IDGRP_REM_SGRPKKT'
      ')'
      'VALUES('
      '    :ID_REM_SGRPKKT,'
      '    :NAME_REM_SGRPKKT,'
      '    :IDGRP_REM_SGRPKKT'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from rem_sgrpkkt'
      'where(  rem_sgrpkkt.id_rem_sgrpkkt=:PARAM_ID'
      
        '     ) and (     REM_SGRPKKT.ID_REM_SGRPKKT = :OLD_ID_REM_SGRPKK' +
        'T'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from rem_sgrpkkt'
      'where rem_sgrpkkt.id_rem_sgrpkkt=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_SGRPKKT'
    AutoUpdateOptions.KeyFields = 'ID_REM_SGRPKKT'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_SGRPKKT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_REM_SGRPKKT: TFIBLargeIntField
      FieldName = 'ID_REM_SGRPKKT'
    end
    object ElementIDBASE_REM_SGRPKKT: TFIBLargeIntField
      FieldName = 'IDBASE_REM_SGRPKKT'
    end
    object ElementNAME_REM_SGRPKKT: TFIBWideStringField
      FieldName = 'NAME_REM_SGRPKKT'
      Size = 100
    end
    object ElementIDGRP_REM_SGRPKKT: TFIBLargeIntField
      FieldName = 'IDGRP_REM_SGRPKKT'
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
