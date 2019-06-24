object DMXDataOut: TDMXDataOut
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 254
  Width = 352
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
      'select * from  XDATA_OUT where IDBASE_XDATA_OUT=:PARAM_IDBASE')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Database = DM.Database
    Left = 168
    Top = 24
    object TableID_XDATA_OUT: TFIBBCDField
      FieldName = 'ID_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object TableIDTISM_XDATA_OUT: TFIBBCDField
      FieldName = 'IDTISM_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_XDATA_OUT: TFIBBCDField
      FieldName = 'IDBASE_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object TableTYPE_XDATA_OUT: TFIBSmallIntField
      FieldName = 'TYPE_XDATA_OUT'
    end
    object TableRESULT_XDATA_OUT: TFIBSmallIntField
      FieldName = 'RESULT_XDATA_OUT'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableGID_XDATA_OUT: TFIBWideStringField
      FieldName = 'GID_XDATA_OUT'
      Size = 10
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE XDATA_OUT'
      'SET '
      '    GID_XDATA_OUT = :GID_XDATA_OUT,'
      '    IDTISM_XDATA_OUT = :IDTISM_XDATA_OUT,'
      '    IDBASE_XDATA_OUT = :IDBASE_XDATA_OUT,'
      '    TYPE_XDATA_OUT = :TYPE_XDATA_OUT,'
      '    RESULT_XDATA_OUT = :RESULT_XDATA_OUT'
      'WHERE'
      '    ID_XDATA_OUT = :OLD_ID_XDATA_OUT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    XDATA_OUT'
      'WHERE'
      '        ID_XDATA_OUT = :OLD_ID_XDATA_OUT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO XDATA_OUT('
      '    ID_XDATA_OUT,'
      '    GID_XDATA_OUT,'
      '    IDTISM_XDATA_OUT,'
      '    IDBASE_XDATA_OUT,'
      '    TYPE_XDATA_OUT,'
      '    RESULT_XDATA_OUT'
      ')'
      'VALUES('
      '    :ID_XDATA_OUT,'
      '    :GID_XDATA_OUT,'
      '    :IDTISM_XDATA_OUT,'
      '    :IDBASE_XDATA_OUT,'
      '    :TYPE_XDATA_OUT,'
      '    :RESULT_XDATA_OUT'
      ')')
    RefreshSQL.Strings = (
      'select * from XDATA_OUT where(  ID_XDATA_OUT=:PARAM_ID'
      '     ) and (     XDATA_OUT.ID_XDATA_OUT = :OLD_ID_XDATA_OUT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from XDATA_OUT where ID_XDATA_OUT=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'XDATA_OUT'
    AutoUpdateOptions.KeyFields = 'ID_XDATA_OUT'
    AutoUpdateOptions.GeneratorName = 'GEN_XDATA_OUT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    Database = DM.Database
    UpdateTransaction = IBTrUpdate
    Left = 168
    Top = 80
    object ElementID_XDATA_OUT: TFIBBCDField
      FieldName = 'ID_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTISM_XDATA_OUT: TFIBBCDField
      FieldName = 'IDTISM_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_XDATA_OUT: TFIBBCDField
      FieldName = 'IDBASE_XDATA_OUT'
      Size = 0
      RoundByScale = True
    end
    object ElementTYPE_XDATA_OUT: TFIBSmallIntField
      FieldName = 'TYPE_XDATA_OUT'
    end
    object ElementRESULT_XDATA_OUT: TFIBSmallIntField
      FieldName = 'RESULT_XDATA_OUT'
    end
    object ElementGID_XDATA_OUT: TFIBWideStringField
      FieldName = 'GID_XDATA_OUT'
      Size = 10
    end
  end
  object IBTr: TpFIBTransaction
    Active = True
    DefaultDatabase = DM.Database
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
    DefaultDatabase = DM.Database
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
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Database = DM.Database
    Left = 176
    Top = 144
    qoStartTransaction = True
  end
end
