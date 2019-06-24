object DMSprGrpLossFactor: TDMSprGrpLossFactor
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
      '  SLOSS_FACTOR_GRP'
      'order by IDGRP_SLOSS_FACTOR_GRP')
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
    object TableID_SLOSS_FACTOR_GRP: TFIBLargeIntField
      FieldName = 'ID_SLOSS_FACTOR_GRP'
    end
    object TableGID_SLOSS_FACTOR_GRP: TFIBWideStringField
      FieldName = 'GID_SLOSS_FACTOR_GRP'
      Size = 10
    end
    object TableIDBASE_SLOSS_FACTOR_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SLOSS_FACTOR_GRP'
    end
    object TableIDGRP_SLOSS_FACTOR_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SLOSS_FACTOR_GRP'
    end
    object TableNAME_SLOSS_FACTOR_GRP: TFIBWideStringField
      FieldName = 'NAME_SLOSS_FACTOR_GRP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SLOSS_FACTOR_GRP'
      'SET '
      '    GID_SLOSS_FACTOR_GRP = :GID_SLOSS_FACTOR_GRP,'
      '    IDBASE_SLOSS_FACTOR_GRP = :IDBASE_SLOSS_FACTOR_GRP,'
      '    IDGRP_SLOSS_FACTOR_GRP = :IDGRP_SLOSS_FACTOR_GRP,'
      '    NAME_SLOSS_FACTOR_GRP = :NAME_SLOSS_FACTOR_GRP'
      'WHERE'
      '    ID_SLOSS_FACTOR_GRP = :OLD_ID_SLOSS_FACTOR_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SLOSS_FACTOR_GRP'
      'WHERE'
      '        ID_SLOSS_FACTOR_GRP = :OLD_ID_SLOSS_FACTOR_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SLOSS_FACTOR_GRP('
      '    ID_SLOSS_FACTOR_GRP,'
      '    GID_SLOSS_FACTOR_GRP,'
      '    IDBASE_SLOSS_FACTOR_GRP,'
      '    IDGRP_SLOSS_FACTOR_GRP,'
      '    NAME_SLOSS_FACTOR_GRP'
      ')'
      'VALUES('
      '    :ID_SLOSS_FACTOR_GRP,'
      '    :GID_SLOSS_FACTOR_GRP,'
      '    :IDBASE_SLOSS_FACTOR_GRP,'
      '    :IDGRP_SLOSS_FACTOR_GRP,'
      '    :NAME_SLOSS_FACTOR_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * from SLOSS_FACTOR_GRP'
      ' where(  ID_SLOSS_FACTOR_GRP=:ID'
      
        '     ) and (     SLOSS_FACTOR_GRP.ID_SLOSS_FACTOR_GRP = :OLD_ID_' +
        'SLOSS_FACTOR_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SLOSS_FACTOR_GRP'
      ' where ID_SLOSS_FACTOR_GRP=:ID')
    AutoUpdateOptions.UpdateTableName = 'SLOSS_FACTOR_GRP'
    AutoUpdateOptions.KeyFields = 'ID_SLOSS_FACTOR_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_SLOSS_FACTOR_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_SLOSS_FACTOR_GRP: TFIBLargeIntField
      FieldName = 'ID_SLOSS_FACTOR_GRP'
    end
    object ElementGID_SLOSS_FACTOR_GRP: TFIBWideStringField
      FieldName = 'GID_SLOSS_FACTOR_GRP'
      Size = 10
    end
    object ElementIDBASE_SLOSS_FACTOR_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SLOSS_FACTOR_GRP'
    end
    object ElementIDGRP_SLOSS_FACTOR_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SLOSS_FACTOR_GRP'
    end
    object ElementNAME_SLOSS_FACTOR_GRP: TFIBWideStringField
      FieldName = 'NAME_SLOSS_FACTOR_GRP'
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
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 272
    Top = 56
    qoStartTransaction = True
  end
end
