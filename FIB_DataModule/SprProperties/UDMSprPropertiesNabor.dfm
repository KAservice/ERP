object DMSprPropertiesNabor: TDMSprPropertiesNabor
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 403
  Width = 371
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
      'select spropnabor.*'
      'from spropnabor'
      'where spropnabor.idgrp_spropnabor=:PARAM_IDGRP'
      'ORDER BY spropnabor.name_spropnabor')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SPROPNABOR: TFIBLargeIntField
      FieldName = 'ID_SPROPNABOR'
    end
    object TableIDBASE_SPROPNABOR: TFIBLargeIntField
      FieldName = 'IDBASE_SPROPNABOR'
    end
    object TableGID_SPROPNABOR: TFIBWideStringField
      FieldName = 'GID_SPROPNABOR'
      Size = 10
    end
    object TableIDGRP_SPROPNABOR: TFIBLargeIntField
      FieldName = 'IDGRP_SPROPNABOR'
    end
    object TableNAME_SPROPNABOR: TFIBWideStringField
      FieldName = 'NAME_SPROPNABOR'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPROPNABOR'
      'SET '
      '    IDBASE_SPROPNABOR = :IDBASE_SPROPNABOR,'
      '    GID_SPROPNABOR = :GID_SPROPNABOR,'
      '    IDGRP_SPROPNABOR = :IDGRP_SPROPNABOR,'
      '    NAME_SPROPNABOR = :NAME_SPROPNABOR'
      'WHERE'
      '    ID_SPROPNABOR = :OLD_ID_SPROPNABOR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPROPNABOR'
      'WHERE'
      '        ID_SPROPNABOR = :OLD_ID_SPROPNABOR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPROPNABOR('
      '    ID_SPROPNABOR,'
      '    IDBASE_SPROPNABOR,'
      '    GID_SPROPNABOR,'
      '    IDGRP_SPROPNABOR,'
      '    NAME_SPROPNABOR'
      ')'
      'VALUES('
      '    :ID_SPROPNABOR,'
      '    :IDBASE_SPROPNABOR,'
      '    :GID_SPROPNABOR,'
      '    :IDGRP_SPROPNABOR,'
      '    :NAME_SPROPNABOR'
      ')')
    RefreshSQL.Strings = (
      'select spropnabor.*'
      'from spropnabor'
      'where(  spropnabor.id_spropnabor=:PARAM_ID'
      '     ) and (     SPROPNABOR.ID_SPROPNABOR = :OLD_ID_SPROPNABOR'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select spropnabor.*'
      'from spropnabor'
      'where spropnabor.id_spropnabor=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPROPNABOR'
    AutoUpdateOptions.KeyFields = 'ID_SPROPNABOR'
    AutoUpdateOptions.GeneratorName = 'GEN_SPROPNABOR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_SPROPNABOR: TFIBLargeIntField
      FieldName = 'ID_SPROPNABOR'
    end
    object ElementIDBASE_SPROPNABOR: TFIBLargeIntField
      FieldName = 'IDBASE_SPROPNABOR'
    end
    object ElementGID_SPROPNABOR: TFIBWideStringField
      FieldName = 'GID_SPROPNABOR'
      Size = 10
    end
    object ElementIDGRP_SPROPNABOR: TFIBLargeIntField
      FieldName = 'IDGRP_SPROPNABOR'
    end
    object ElementNAME_SPROPNABOR: TFIBWideStringField
      FieldName = 'NAME_SPROPNABOR'
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
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 152
    Top = 144
    qoStartTransaction = True
  end
end
