object DMSprProperties: TDMSprProperties
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
      'select sprop.*'
      'from sprop'
      'where sprop.idgrp_sprop=:PARAM_IDGRP'
      'ORDER BY sprop.name_sprop')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_SPROP: TFIBLargeIntField
      FieldName = 'ID_SPROP'
    end
    object TableIDBASE_SPROP: TFIBLargeIntField
      FieldName = 'IDBASE_SPROP'
    end
    object TableGID_SPROP: TFIBWideStringField
      FieldName = 'GID_SPROP'
      Size = 10
    end
    object TableIDGRP_SPROP: TFIBLargeIntField
      FieldName = 'IDGRP_SPROP'
    end
    object TableNAME_SPROP: TFIBWideStringField
      FieldName = 'NAME_SPROP'
      Size = 200
    end
    object TableFL_TYPE_SPROP: TFIBSmallIntField
      FieldName = 'FL_TYPE_SPROP'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableNAME_FOR_PRINT_SPROP: TFIBWideStringField
      FieldName = 'NAME_FOR_PRINT_SPROP'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPROP'
      'SET '
      '    IDBASE_SPROP = :IDBASE_SPROP,'
      '    GID_SPROP = :GID_SPROP,'
      '    IDGRP_SPROP = :IDGRP_SPROP,'
      '    NAME_SPROP = :NAME_SPROP,'
      '    FL_TYPE_SPROP = :FL_TYPE_SPROP,'
      '    NAME_FOR_PRINT_SPROP = :NAME_FOR_PRINT_SPROP'
      'WHERE'
      '    ID_SPROP = :OLD_ID_SPROP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPROP'
      'WHERE'
      '        ID_SPROP = :OLD_ID_SPROP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPROP('
      '    ID_SPROP,'
      '    IDBASE_SPROP,'
      '    GID_SPROP,'
      '    IDGRP_SPROP,'
      '    NAME_SPROP,'
      '    FL_TYPE_SPROP,'
      '    NAME_FOR_PRINT_SPROP'
      ')'
      'VALUES('
      '    :ID_SPROP,'
      '    :IDBASE_SPROP,'
      '    :GID_SPROP,'
      '    :IDGRP_SPROP,'
      '    :NAME_SPROP,'
      '    :FL_TYPE_SPROP,'
      '    :NAME_FOR_PRINT_SPROP'
      ')')
    RefreshSQL.Strings = (
      'select sprop.*'
      'from sprop'
      'where(  sprop.id_sprop=:PARAM_ID'
      '     ) and (     SPROP.ID_SPROP = :OLD_ID_SPROP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select sprop.*'
      'from sprop'
      'where sprop.id_sprop=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPROP'
    AutoUpdateOptions.KeyFields = 'ID_SPROP'
    AutoUpdateOptions.GeneratorName = 'GEN_SPROP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_SPROP: TFIBLargeIntField
      FieldName = 'ID_SPROP'
    end
    object ElementIDBASE_SPROP: TFIBLargeIntField
      FieldName = 'IDBASE_SPROP'
    end
    object ElementGID_SPROP: TFIBWideStringField
      FieldName = 'GID_SPROP'
      Size = 10
    end
    object ElementIDGRP_SPROP: TFIBLargeIntField
      FieldName = 'IDGRP_SPROP'
    end
    object ElementNAME_SPROP: TFIBWideStringField
      FieldName = 'NAME_SPROP'
      Size = 200
    end
    object ElementFL_TYPE_SPROP: TFIBSmallIntField
      FieldName = 'FL_TYPE_SPROP'
    end
    object ElementNAME_FOR_PRINT_SPROP: TFIBWideStringField
      FieldName = 'NAME_FOR_PRINT_SPROP'
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
