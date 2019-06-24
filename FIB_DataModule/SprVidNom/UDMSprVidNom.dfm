object DMSprVidNom: TDMSprVidNom
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
      'UPDATE SVIDNOM'
      'SET '
      '    GID_SVIDNOM = :GID_SVIDNOM,'
      '    NAME_SVIDNOM = :NAME_SVIDNOM'
      'WHERE'
      '    ID_SVIDNOM = :OLD_ID_SVIDNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SVIDNOM'
      'WHERE'
      '        ID_SVIDNOM = :OLD_ID_SVIDNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SVIDNOM('
      '    ID_SVIDNOM,'
      '    GID_SVIDNOM,'
      '    NAME_SVIDNOM'
      ')'
      'VALUES('
      '    :ID_SVIDNOM,'
      '    :GID_SVIDNOM,'
      '    :NAME_SVIDNOM'
      ')')
    RefreshSQL.Strings = (
      'select  * from SVIDNOM'
      ''
      ' WHERE '
      '        SVIDNOM.ID_SVIDNOM = :OLD_ID_SVIDNOM'
      '    ')
    SelectSQL.Strings = (
      'select  * from SVIDNOM')
    AutoUpdateOptions.UpdateTableName = 'SVIDNOM'
    AutoUpdateOptions.KeyFields = 'ID_SVIDKLIENT'
    AutoUpdateOptions.GeneratorName = 'GEN_SVIDNOM_ID'
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
    object TableID_SVIDNOM: TFIBBCDField
      FieldName = 'ID_SVIDNOM'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SVIDNOM: TFIBWideStringField
      FieldName = 'GID_SVIDNOM'
      Size = 10
    end
    object TableNAME_SVIDNOM: TFIBWideStringField
      FieldName = 'NAME_SVIDNOM'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SVIDNOM'
      'SET '
      '    GID_SVIDNOM = :GID_SVIDNOM,'
      '    NAME_SVIDNOM = :NAME_SVIDNOM'
      'WHERE'
      '    ID_SVIDNOM = :OLD_ID_SVIDNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SVIDNOM'
      'WHERE'
      '        ID_SVIDNOM = :OLD_ID_SVIDNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SVIDNOM('
      '    ID_SVIDNOM,'
      '    GID_SVIDNOM,'
      '    NAME_SVIDNOM'
      ')'
      'VALUES('
      '    :ID_SVIDNOM,'
      '    :GID_SVIDNOM,'
      '    :NAME_SVIDNOM'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from SVIDNOM'
      'where(  ID_SVIDNOM=:PARAM_ID'
      '     ) and (     SVIDNOM.ID_SVIDNOM = :OLD_ID_SVIDNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from SVIDNOM'
      'where ID_SVIDNOM=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SVIDNOM'
    AutoUpdateOptions.KeyFields = 'ID_SVIDNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_SVIDNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 96
    object ElementID_SVIDNOM: TFIBBCDField
      FieldName = 'ID_SVIDNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_SVIDNOM: TFIBWideStringField
      FieldName = 'NAME_SVIDNOM'
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
