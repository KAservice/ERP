object DMSprGrpProduce: TDMSprGrpProduce
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
      '  SPRODUCE_GRP'
      'order by IDGRP_SPRODUCE_GRP')
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
    object TableID_SPRODUCE_GRP: TFIBLargeIntField
      FieldName = 'ID_SPRODUCE_GRP'
    end
    object TableGID_SPRODUCE_GRP: TFIBWideStringField
      FieldName = 'GID_SPRODUCE_GRP'
      Size = 10
    end
    object TableIDBASE_SPRODUCE_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SPRODUCE_GRP'
    end
    object TableNAME_SPRODUCE_GRP: TFIBWideStringField
      FieldName = 'NAME_SPRODUCE_GRP'
      Size = 200
    end
    object TableIDGRP_SPRODUCE_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SPRODUCE_GRP'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPRODUCE_GRP'
      'SET '
      '    GID_SPRODUCE_GRP = :GID_SPRODUCE_GRP,'
      '    IDBASE_SPRODUCE_GRP = :IDBASE_SPRODUCE_GRP,'
      '    NAME_SPRODUCE_GRP = :NAME_SPRODUCE_GRP,'
      '    IDGRP_SPRODUCE_GRP = :IDGRP_SPRODUCE_GRP'
      'WHERE'
      '    ID_SPRODUCE_GRP = :OLD_ID_SPRODUCE_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRODUCE_GRP'
      'WHERE'
      '        ID_SPRODUCE_GRP = :OLD_ID_SPRODUCE_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRODUCE_GRP('
      '    ID_SPRODUCE_GRP,'
      '    GID_SPRODUCE_GRP,'
      '    IDBASE_SPRODUCE_GRP,'
      '    NAME_SPRODUCE_GRP,'
      '    IDGRP_SPRODUCE_GRP'
      ')'
      'VALUES('
      '    :ID_SPRODUCE_GRP,'
      '    :GID_SPRODUCE_GRP,'
      '    :IDBASE_SPRODUCE_GRP,'
      '    :NAME_SPRODUCE_GRP,'
      '    :IDGRP_SPRODUCE_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * from SPRODUCE_GRP'
      ' where(  ID_SPRODUCE_GRP=:ID'
      
        '     ) and (     SPRODUCE_GRP.ID_SPRODUCE_GRP = :OLD_ID_SPRODUCE' +
        '_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SPRODUCE_GRP'
      ' where ID_SPRODUCE_GRP=:ID')
    AutoUpdateOptions.UpdateTableName = 'SPRODUCE_GRP'
    AutoUpdateOptions.KeyFields = 'ID_SPRODUCE_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRODUCE_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_SPRODUCE_GRP: TFIBLargeIntField
      FieldName = 'ID_SPRODUCE_GRP'
    end
    object ElementGID_SPRODUCE_GRP: TFIBWideStringField
      FieldName = 'GID_SPRODUCE_GRP'
      Size = 10
    end
    object ElementIDBASE_SPRODUCE_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SPRODUCE_GRP'
    end
    object ElementNAME_SPRODUCE_GRP: TFIBWideStringField
      FieldName = 'NAME_SPRODUCE_GRP'
      Size = 200
    end
    object ElementIDGRP_SPRODUCE_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SPRODUCE_GRP'
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
