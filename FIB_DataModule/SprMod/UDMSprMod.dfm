object DMSprMod: TDMSprMod
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 125
  Width = 305
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SMOD'
      'SET '
      '    IDNOM_MOD = :IDNOM_MOD,'
      '    NAME_MOD = :NAME_MOD,'
      '    GID_SMOD = :GID_SMOD'
      'WHERE'
      '    ID_MOD = :OLD_ID_MOD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SMOD'
      'WHERE'
      '        ID_MOD = :OLD_ID_MOD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SMOD('
      '    ID_MOD,'
      '    IDNOM_MOD,'
      '    NAME_MOD,'
      '    GID_SMOD'
      ')'
      'VALUES('
      '    :ID_MOD,'
      '    :IDNOM_MOD,'
      '    :NAME_MOD,'
      '    :GID_SMOD'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  SMOD'
      'where(  '
      '  IDNOM_MOD=:PARAM_IDNOM'
      '     ) and (     SMOD.ID_MOD = :OLD_ID_MOD'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  SMOD'
      'where '
      '  IDNOM_MOD=:PARAM_IDNOM')
    AutoUpdateOptions.UpdateTableName = 'SMOD'
    AutoUpdateOptions.KeyFields = 'ID_MOD'
    AutoUpdateOptions.GeneratorName = 'GEN_SMOD_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 128
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_MOD: TFIBBCDField
      FieldName = 'ID_MOD'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOM_MOD: TFIBBCDField
      FieldName = 'IDNOM_MOD'
      Size = 0
      RoundByScale = True
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
    Left = 200
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
    Left = 200
    Top = 64
  end
end
