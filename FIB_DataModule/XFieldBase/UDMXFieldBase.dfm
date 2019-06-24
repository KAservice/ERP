object DMXFieldBase: TDMXFieldBase
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 158
  Width = 336
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      
        'select * from  XFIELD_BASE where IDTABLE_XFIELD_BASE=:PARAM_IDTA' +
        'BLE')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 160
    Top = 24
    object TableID_XFIELD_BASE: TFIBIntegerField
      FieldName = 'ID_XFIELD_BASE'
    end
    object TableGID_XFIELD_BASE: TFIBStringField
      FieldName = 'GID_XFIELD_BASE'
      Size = 10
      EmptyStrToNull = True
    end
    object TableIDTABLE_XFIELD_BASE: TFIBIntegerField
      FieldName = 'IDTABLE_XFIELD_BASE'
    end
    object TableNAME_XFIELD_BASE: TFIBStringField
      FieldName = 'NAME_XFIELD_BASE'
      Size = 40
      EmptyStrToNull = True
    end
    object TableTYPE_XFIELD_BASE: TFIBIntegerField
      FieldName = 'TYPE_XFIELD_BASE'
    end
    object TableFIELDFK_XFIELD_BASE: TFIBStringField
      FieldName = 'FIELDFK_XFIELD_BASE'
      Size = 40
      EmptyStrToNull = True
    end
    object TableTABLEFK_XFIELD_BASE: TFIBStringField
      FieldName = 'TABLEFK_XFIELD_BASE'
      EmptyStrToNull = True
    end
    object TableGIDFK_XFIELD_BASE: TFIBStringField
      FieldName = 'GIDFK_XFIELD_BASE'
      Size = 40
      EmptyStrToNull = True
    end
    object TableFK_XFIELD_BASE: TFIBIntegerField
      FieldName = 'FK_XFIELD_BASE'
    end
    object TableSCALE_XFIELD_BASE: TFIBSmallIntField
      FieldName = 'SCALE_XFIELD_BASE'
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
      'UPDATE XFIELD_BASE'
      'SET '
      '    GID_XFIELD_BASE = :GID_XFIELD_BASE,'
      '    IDTABLE_XFIELD_BASE = :IDTABLE_XFIELD_BASE,'
      '    NAME_XFIELD_BASE = :NAME_XFIELD_BASE,'
      '    TYPE_XFIELD_BASE = :TYPE_XFIELD_BASE,'
      '    FIELDFK_XFIELD_BASE = :FIELDFK_XFIELD_BASE,'
      '    TABLEFK_XFIELD_BASE = :TABLEFK_XFIELD_BASE,'
      '    GIDFK_XFIELD_BASE = :GIDFK_XFIELD_BASE,'
      '    FK_XFIELD_BASE = :FK_XFIELD_BASE,'
      '    SCALE_XFIELD_BASE = :SCALE_XFIELD_BASE'
      'WHERE'
      '    ID_XFIELD_BASE = :OLD_ID_XFIELD_BASE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    XFIELD_BASE'
      'WHERE'
      '        ID_XFIELD_BASE = :OLD_ID_XFIELD_BASE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO XFIELD_BASE('
      '    ID_XFIELD_BASE,'
      '    GID_XFIELD_BASE,'
      '    IDTABLE_XFIELD_BASE,'
      '    NAME_XFIELD_BASE,'
      '    TYPE_XFIELD_BASE,'
      '    FIELDFK_XFIELD_BASE,'
      '    TABLEFK_XFIELD_BASE,'
      '    GIDFK_XFIELD_BASE,'
      '    FK_XFIELD_BASE,'
      '    SCALE_XFIELD_BASE'
      ')'
      'VALUES('
      '    :ID_XFIELD_BASE,'
      '    :GID_XFIELD_BASE,'
      '    :IDTABLE_XFIELD_BASE,'
      '    :NAME_XFIELD_BASE,'
      '    :TYPE_XFIELD_BASE,'
      '    :FIELDFK_XFIELD_BASE,'
      '    :TABLEFK_XFIELD_BASE,'
      '    :GIDFK_XFIELD_BASE,'
      '    :FK_XFIELD_BASE,'
      '    :SCALE_XFIELD_BASE'
      ')')
    RefreshSQL.Strings = (
      'select * from XFIELD_BASE where(  ID_XFIELD_BASE=:PARAM_ID'
      
        '     ) and (     XFIELD_BASE.ID_XFIELD_BASE = :OLD_ID_XFIELD_BAS' +
        'E'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from XFIELD_BASE where ID_XFIELD_BASE=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'XFIELD_BASE'
    AutoUpdateOptions.KeyFields = 'ID_XFIELD_BASE'
    AutoUpdateOptions.GeneratorName = 'GEN_XFIELD_BASE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    object ElementID_XFIELD_BASE: TFIBIntegerField
      FieldName = 'ID_XFIELD_BASE'
    end
    object ElementGID_XFIELD_BASE: TFIBStringField
      FieldName = 'GID_XFIELD_BASE'
      Size = 10
      EmptyStrToNull = True
    end
    object ElementIDTABLE_XFIELD_BASE: TFIBIntegerField
      FieldName = 'IDTABLE_XFIELD_BASE'
    end
    object ElementNAME_XFIELD_BASE: TFIBStringField
      FieldName = 'NAME_XFIELD_BASE'
      Size = 40
      EmptyStrToNull = True
    end
    object ElementTYPE_XFIELD_BASE: TFIBIntegerField
      FieldName = 'TYPE_XFIELD_BASE'
    end
    object ElementFIELDFK_XFIELD_BASE: TFIBStringField
      FieldName = 'FIELDFK_XFIELD_BASE'
      Size = 40
      EmptyStrToNull = True
    end
    object ElementTABLEFK_XFIELD_BASE: TFIBStringField
      FieldName = 'TABLEFK_XFIELD_BASE'
      EmptyStrToNull = True
    end
    object ElementGIDFK_XFIELD_BASE: TFIBStringField
      FieldName = 'GIDFK_XFIELD_BASE'
      Size = 40
      EmptyStrToNull = True
    end
    object ElementFK_XFIELD_BASE: TFIBIntegerField
      FieldName = 'FK_XFIELD_BASE'
    end
    object ElementSCALE_XFIELD_BASE: TFIBSmallIntField
      FieldName = 'SCALE_XFIELD_BASE'
    end
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'read'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 256
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 256
    Top = 80
  end
end
