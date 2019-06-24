object HOT_DMSprCelPriesda: THOT_DMSprCelPriesda
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
      'UPDATE HOT_SCELPR'
      'SET '
      '    GID_HOT_SCELPR = :GID_HOT_SCELPR,'
      '    NAME_HOT_SCELPR = :NAME_HOT_SCELPR'
      'WHERE'
      '    ID_HOT_SCELPR = :OLD_ID_HOT_SCELPR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_SCELPR'
      'WHERE'
      '        ID_HOT_SCELPR = :OLD_ID_HOT_SCELPR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_SCELPR('
      '    ID_HOT_SCELPR,'
      '    GID_HOT_SCELPR,'
      '    NAME_HOT_SCELPR'
      ')'
      'VALUES('
      '    :ID_HOT_SCELPR,'
      '    :GID_HOT_SCELPR,'
      '    :NAME_HOT_SCELPR'
      ')')
    RefreshSQL.Strings = (
      'select  * from HOT_SCELPR'
      ''
      ' WHERE '
      '        HOT_SCELPR.ID_HOT_SCELPR = :OLD_ID_HOT_SCELPR'
      '    ')
    SelectSQL.Strings = (
      'select  * from HOT_SCELPR')
    AutoUpdateOptions.UpdateTableName = 'HOT_SCELPR'
    AutoUpdateOptions.KeyFields = 'ID_HOT_SCELPR'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_SCELPR_ID'
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
    object TableID_HOT_SCELPR: TFIBBCDField
      FieldName = 'ID_HOT_SCELPR'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_HOT_SCELPR: TFIBWideStringField
      FieldName = 'NAME_HOT_SCELPR'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HOT_SCELPR'
      'SET '
      '    GID_HOT_SCELPR = :GID_HOT_SCELPR,'
      '    NAME_HOT_SCELPR = :NAME_HOT_SCELPR'
      'WHERE'
      '    ID_HOT_SCELPR = :OLD_ID_HOT_SCELPR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_SCELPR'
      'WHERE'
      '        ID_HOT_SCELPR = :OLD_ID_HOT_SCELPR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_SCELPR('
      '    ID_HOT_SCELPR,'
      '    GID_HOT_SCELPR,'
      '    NAME_HOT_SCELPR'
      ')'
      'VALUES('
      '    :ID_HOT_SCELPR,'
      '    :GID_HOT_SCELPR,'
      '    :NAME_HOT_SCELPR'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from HOT_SCELPR'
      'where(  ID_HOT_SCELPR=:PARAM_ID'
      '     ) and (     HOT_SCELPR.ID_HOT_SCELPR = :OLD_ID_HOT_SCELPR'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from HOT_SCELPR'
      'where ID_HOT_SCELPR=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HOT_SCELPR'
    AutoUpdateOptions.KeyFields = 'ID_HOT_SCELPR'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_SCELPR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 96
    object ElementID_HOT_SCELPR: TFIBBCDField
      FieldName = 'ID_HOT_SCELPR'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_HOT_SCELPR: TFIBWideStringField
      FieldName = 'NAME_HOT_SCELPR'
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
