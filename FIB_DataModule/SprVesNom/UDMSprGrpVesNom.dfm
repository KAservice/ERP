object DMSprGrpVesNom: TDMSprGrpVesNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 150
  Width = 329
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
      'from  SGRPVESNOM'
      'where IDSCALE_SGRPVESNOM=:PARAM_IDSCALE'
      'order by IDGRP_SGRPVESNOM')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 184
    Top = 24
    object TableID_SGRPVESNOM: TFIBBCDField
      FieldName = 'ID_SGRPVESNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRP_SGRPVESNOM: TFIBBCDField
      FieldName = 'IDGRP_SGRPVESNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_SGRPVESNOM: TFIBBCDField
      FieldName = 'IDBASE_SGRPVESNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDSCALE_SGRPVESNOM: TFIBBCDField
      FieldName = 'IDSCALE_SGRPVESNOM'
      Size = 0
      RoundByScale = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableNAME_SGRPVESNOM: TFIBWideStringField
      FieldName = 'NAME_SGRPVESNOM'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SGRPVESNOM'
      'SET '
      '    IDGRP_SGRPVESNOM = :IDGRP_SGRPVESNOM,'
      '    NAME_SGRPVESNOM = :NAME_SGRPVESNOM,'
      '    IDBASE_SGRPVESNOM = :IDBASE_SGRPVESNOM,'
      '    IDSCALE_SGRPVESNOM = :IDSCALE_SGRPVESNOM'
      'WHERE'
      '    ID_SGRPVESNOM = :OLD_ID_SGRPVESNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SGRPVESNOM'
      'WHERE'
      '        ID_SGRPVESNOM = :OLD_ID_SGRPVESNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SGRPVESNOM('
      '    ID_SGRPVESNOM,'
      '    IDGRP_SGRPVESNOM,'
      '    NAME_SGRPVESNOM,'
      '    IDBASE_SGRPVESNOM,'
      '    IDSCALE_SGRPVESNOM'
      ')'
      'VALUES('
      '    :ID_SGRPVESNOM,'
      '    :IDGRP_SGRPVESNOM,'
      '    :NAME_SGRPVESNOM,'
      '    :IDBASE_SGRPVESNOM,'
      '    :IDSCALE_SGRPVESNOM'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  SGRPVESNOM'
      'where(  ID_SGRPVESNOM=:PARAM_ID'
      '     ) and (     SGRPVESNOM.ID_SGRPVESNOM = :OLD_ID_SGRPVESNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  SGRPVESNOM'
      'where ID_SGRPVESNOM=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SGBVNOM'
    AutoUpdateOptions.KeyFields = 'ID_GBVNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_SGBVNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 184
    Top = 80
    object ElementID_SGRPVESNOM: TFIBBCDField
      FieldName = 'ID_SGRPVESNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRP_SGRPVESNOM: TFIBBCDField
      FieldName = 'IDGRP_SGRPVESNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_SGRPVESNOM: TFIBBCDField
      FieldName = 'IDBASE_SGRPVESNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDSCALE_SGRPVESNOM: TFIBBCDField
      FieldName = 'IDSCALE_SGRPVESNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_SGRPVESNOM: TFIBWideStringField
      FieldName = 'NAME_SGRPVESNOM'
      Size = 100
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
    Left = 248
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 248
    Top = 80
  end
end
