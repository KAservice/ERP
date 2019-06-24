object DMSprBrand: TDMSprBrand
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 156
  Width = 314
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
    SelectSQL.Strings = (
      'select  * from SBRAND'
      'order by NAME_SBRAND')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 136
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SBRAND: TFIBBCDField
      FieldName = 'ID_SBRAND'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_SBRAND: TFIBBCDField
      FieldName = 'IDBASE_SBRAND'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SBRAND'
      'SET '
      '    IDBASE_SBRAND = :IDBASE_SBRAND,'
      '    NAME_SBRAND = :NAME_SBRAND'
      'WHERE'
      '    ID_SBRAND = :OLD_ID_SBRAND'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SBRAND'
      'WHERE'
      '        ID_SBRAND = :OLD_ID_SBRAND'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SBRAND('
      '    ID_SBRAND,'
      '    IDBASE_SBRAND,'
      '    NAME_SBRAND'
      ')'
      'VALUES('
      '    :ID_SBRAND,'
      '    :IDBASE_SBRAND,'
      '    :NAME_SBRAND'
      ')')
    RefreshSQL.Strings = (
      'select * from SBRAND where(  ID_SBRAND=:PARAM_ID'
      '     ) and (     SBRAND.ID_SBRAND = :OLD_ID_SBRAND'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SBRAND where ID_SBRAND=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SBRAND'
    AutoUpdateOptions.KeyFields = 'ID_SBRAND'
    AutoUpdateOptions.GeneratorName = 'GEN_SBRAND_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 96
    object ElementID_SBRAND: TFIBBCDField
      FieldName = 'ID_SBRAND'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_SBRAND: TFIBBCDField
      FieldName = 'IDBASE_SBRAND'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_SBRAND: TFIBWideStringField
      FieldName = 'NAME_SBRAND'
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
    Left = 216
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
    Left = 216
    Top = 96
  end
end
