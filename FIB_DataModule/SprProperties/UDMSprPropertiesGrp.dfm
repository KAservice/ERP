object DMSprPropertiesGrp: TDMSprPropertiesGrp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 332
  Width = 372
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
      '  sprop_grp'
      'order by sprop_grp.idgrp_sprop_grp')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 24
    poUseLargeIntField = True
    object TableID_SPROP_GRP: TFIBLargeIntField
      FieldName = 'ID_SPROP_GRP'
    end
    object TableIDBASE_SPROP_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SPROP_GRP'
    end
    object TableGID_SPROP_GRP: TFIBWideStringField
      FieldName = 'GID_SPROP_GRP'
      Size = 10
    end
    object TableIDGRP_SPROP_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SPROP_GRP'
    end
    object TableNAME_SPROP_GRP: TFIBWideStringField
      FieldName = 'NAME_SPROP_GRP'
      Size = 200
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPROP_GRP'
      'SET '
      '    IDBASE_SPROP_GRP = :IDBASE_SPROP_GRP,'
      '    GID_SPROP_GRP = :GID_SPROP_GRP,'
      '    IDGRP_SPROP_GRP = :IDGRP_SPROP_GRP,'
      '    NAME_SPROP_GRP = :NAME_SPROP_GRP,'
      '    NAME_FOR_PRINT_SPROP_GRP = :NAME_FOR_PRINT_SPROP_GRP'
      'WHERE'
      '    ID_SPROP_GRP = :OLD_ID_SPROP_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPROP_GRP'
      'WHERE'
      '        ID_SPROP_GRP = :OLD_ID_SPROP_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPROP_GRP('
      '    ID_SPROP_GRP,'
      '    IDBASE_SPROP_GRP,'
      '    GID_SPROP_GRP,'
      '    IDGRP_SPROP_GRP,'
      '    NAME_SPROP_GRP,'
      '    NAME_FOR_PRINT_SPROP_GRP'
      ')'
      'VALUES('
      '    :ID_SPROP_GRP,'
      '    :IDBASE_SPROP_GRP,'
      '    :GID_SPROP_GRP,'
      '    :IDGRP_SPROP_GRP,'
      '    :NAME_SPROP_GRP,'
      '    :NAME_FOR_PRINT_SPROP_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  sprop_grp'
      'where(  sprop_grp.id_sprop_grp=:PARAM_ID'
      '     ) and (     SPROP_GRP.ID_SPROP_GRP = :OLD_ID_SPROP_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  sprop_grp'
      'where sprop_grp.id_sprop_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPROP_GRP'
    AutoUpdateOptions.KeyFields = 'ID_SPROP_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_SPROP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_SPROP_GRP: TFIBLargeIntField
      FieldName = 'ID_SPROP_GRP'
    end
    object ElementIDBASE_SPROP_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_SPROP_GRP'
    end
    object ElementGID_SPROP_GRP: TFIBWideStringField
      FieldName = 'GID_SPROP_GRP'
      Size = 10
    end
    object ElementIDGRP_SPROP_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_SPROP_GRP'
    end
    object ElementNAME_SPROP_GRP: TFIBWideStringField
      FieldName = 'NAME_SPROP_GRP'
      Size = 200
    end
    object ElementNAME_FOR_PRINT_SPROP_GRP: TFIBWideStringField
      FieldName = 'NAME_FOR_PRINT_SPROP_GRP'
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
