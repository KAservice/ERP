object DMObjectBaseGrp: TDMObjectBaseGrp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 215
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
      'from  object_base_grp'
      'where object_base_grp.idgrp_object_base_grp=:PARAM_IDGRP'
      'order by object_base_grp.idgrp_object_base_grp')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 168
    Top = 24
    poUseLargeIntField = True
    object TableID_OBJECT_BASE_GRP: TFIBLargeIntField
      FieldName = 'ID_OBJECT_BASE_GRP'
    end
    object TableIDBASE_OBJECT_BASE_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_OBJECT_BASE_GRP'
    end
    object TableNAME_OBJECT_BASE_GRP: TFIBWideStringField
      FieldName = 'NAME_OBJECT_BASE_GRP'
      Size = 100
    end
    object TableIDGRP_OBJECT_BASE_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_OBJECT_BASE_GRP'
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
      'UPDATE OBJECT_BASE_GRP'
      'SET '
      '    IDBASE_OBJECT_BASE_GRP = :IDBASE_OBJECT_BASE_GRP,'
      '    NAME_OBJECT_BASE_GRP = :NAME_OBJECT_BASE_GRP,'
      '    IDGRP_OBJECT_BASE_GRP = :IDGRP_OBJECT_BASE_GRP'
      'WHERE'
      '    ID_OBJECT_BASE_GRP = :OLD_ID_OBJECT_BASE_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    OBJECT_BASE_GRP'
      'WHERE'
      '        ID_OBJECT_BASE_GRP = :OLD_ID_OBJECT_BASE_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO OBJECT_BASE_GRP('
      '    ID_OBJECT_BASE_GRP,'
      '    IDBASE_OBJECT_BASE_GRP,'
      '    NAME_OBJECT_BASE_GRP,'
      '    IDGRP_OBJECT_BASE_GRP'
      ')'
      'VALUES('
      '    :ID_OBJECT_BASE_GRP,'
      '    :IDBASE_OBJECT_BASE_GRP,'
      '    :NAME_OBJECT_BASE_GRP,'
      '    :IDGRP_OBJECT_BASE_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from  object_base_grp'
      'where(  object_base_grp.id_object_base_grp=:PARAM_ID'
      
        '     ) and (     OBJECT_BASE_GRP.ID_OBJECT_BASE_GRP = :OLD_ID_OB' +
        'JECT_BASE_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from  object_base_grp'
      'where object_base_grp.id_object_base_grp=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'OBJECT_BASE_GRP'
    AutoUpdateOptions.KeyFields = 'ID_OBJECT_BASE_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_OBJECT_BASE_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 80
    poUseLargeIntField = True
    object ElementID_OBJECT_BASE_GRP: TFIBLargeIntField
      FieldName = 'ID_OBJECT_BASE_GRP'
    end
    object ElementIDBASE_OBJECT_BASE_GRP: TFIBLargeIntField
      FieldName = 'IDBASE_OBJECT_BASE_GRP'
    end
    object ElementNAME_OBJECT_BASE_GRP: TFIBWideStringField
      FieldName = 'NAME_OBJECT_BASE_GRP'
      Size = 100
    end
    object ElementIDGRP_OBJECT_BASE_GRP: TFIBLargeIntField
      FieldName = 'IDGRP_OBJECT_BASE_GRP'
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
