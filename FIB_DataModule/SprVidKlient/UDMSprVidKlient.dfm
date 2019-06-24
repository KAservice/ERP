object DMSprVidKlient: TDMSprVidKlient
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 231
  Width = 363
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 40
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 40
    Top = 96
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SVIDKLIENT'
      'SET '
      '    GID_SVIDKLIENT = :GID_SVIDKLIENT,'
      '    NAME_SVIDKLIENT = :NAME_SVIDKLIENT'
      'WHERE'
      '    ID_SVIDKLIENT = :OLD_ID_SVIDKLIENT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SVIDKLIENT'
      'WHERE'
      '        ID_SVIDKLIENT = :OLD_ID_SVIDKLIENT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SVIDKLIENT('
      '    ID_SVIDKLIENT,'
      '    GID_SVIDKLIENT,'
      '    NAME_SVIDKLIENT'
      ')'
      'VALUES('
      '    :ID_SVIDKLIENT,'
      '    :GID_SVIDKLIENT,'
      '    :NAME_SVIDKLIENT'
      ')')
    RefreshSQL.Strings = (
      'select  * from SVIDKLIENT'
      ''
      ' WHERE '
      '        SVIDKLIENT.ID_SVIDKLIENT = :OLD_ID_SVIDKLIENT'
      '    ')
    SelectSQL.Strings = (
      'select  * from SVIDKLIENT')
    AutoUpdateOptions.UpdateTableName = 'SVIDKLIENT'
    AutoUpdateOptions.KeyFields = 'ID_SVIDKLIENT'
    AutoUpdateOptions.GeneratorName = 'GEN_SVIDKLIENT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SVIDKLIENT: TFIBBCDField
      FieldName = 'ID_SVIDKLIENT'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SVIDKLIENT: TFIBWideStringField
      FieldName = 'GID_SVIDKLIENT'
      Size = 10
    end
    object TableNAME_SVIDKLIENT: TFIBWideStringField
      FieldName = 'NAME_SVIDKLIENT'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SVIDKLIENT'
      'SET '
      '    GID_SVIDKLIENT = :GID_SVIDKLIENT,'
      '    NAME_SVIDKLIENT = :NAME_SVIDKLIENT'
      'WHERE'
      '    ID_SVIDKLIENT = :OLD_ID_SVIDKLIENT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SVIDKLIENT'
      'WHERE'
      '        ID_SVIDKLIENT = :OLD_ID_SVIDKLIENT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SVIDKLIENT('
      '    ID_SVIDKLIENT,'
      '    GID_SVIDKLIENT,'
      '    NAME_SVIDKLIENT'
      ')'
      'VALUES('
      '    :ID_SVIDKLIENT,'
      '    :GID_SVIDKLIENT,'
      '    :NAME_SVIDKLIENT'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from SVIDKLIENT'
      'where(  ID_SVIDKLIENT=:PARAM_ID'
      '     ) and (     SVIDKLIENT.ID_SVIDKLIENT = :OLD_ID_SVIDKLIENT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from SVIDKLIENT'
      'where ID_SVIDKLIENT=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SVIDKLIENT'
    AutoUpdateOptions.KeyFields = 'ID_SVIDKLIENT'
    AutoUpdateOptions.GeneratorName = 'GEN_SVIDKLIENT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 96
    object ElementID_SVIDKLIENT: TFIBBCDField
      FieldName = 'ID_SVIDKLIENT'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SVIDKLIENT: TFIBWideStringField
      FieldName = 'GID_SVIDKLIENT'
      Size = 10
    end
    object ElementNAME_SVIDKLIENT: TFIBWideStringField
      FieldName = 'NAME_SVIDKLIENT'
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
    Left = 264
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
    Left = 264
    Top = 96
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 152
    Top = 160
    qoStartTransaction = True
  end
end
