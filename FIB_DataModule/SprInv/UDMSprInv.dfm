object DMSprInv: TDMSprInv
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
      'select  * from SINV')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 136
    Top = 16
    object TableDATE_SINV: TFIBDateField
      FieldName = 'DATE_SINV'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SINV: TFIBBCDField
      FieldName = 'ID_SINV'
      Size = 0
      RoundByScale = True
    end
    object TableGID_SINV: TFIBWideStringField
      FieldName = 'GID_SINV'
      Size = 10
    end
    object TableNAME_SINV: TFIBWideStringField
      FieldName = 'NAME_SINV'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SINV'
      'SET '
      '    GID_SINV = :GID_SINV,'
      '    NAME_SINV = :NAME_SINV,'
      '    DATE_SINV = :DATE_SINV'
      'WHERE'
      '    ID_SINV = :OLD_ID_SINV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SINV'
      'WHERE'
      '        ID_SINV = :OLD_ID_SINV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SINV('
      '    ID_SINV,'
      '    GID_SINV,'
      '    NAME_SINV,'
      '    DATE_SINV'
      ')'
      'VALUES('
      '    :ID_SINV,'
      '    :GID_SINV,'
      '    :NAME_SINV,'
      '    :DATE_SINV'
      ')')
    RefreshSQL.Strings = (
      'select * from SINV where(  ID_SINV=:PARAM_ID'
      '     ) and (     SINV.ID_SINV = :OLD_ID_SINV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SINV where ID_SINV=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SCOUNTRY'
    AutoUpdateOptions.KeyFields = 'ID_SCOUNTRY'
    AutoUpdateOptions.GeneratorName = 'GEN_SCOUNTRY_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 96
    object ElementDATE_SINV: TFIBDateField
      FieldName = 'DATE_SINV'
    end
    object ElementID_SINV: TFIBBCDField
      FieldName = 'ID_SINV'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SINV: TFIBWideStringField
      FieldName = 'GID_SINV'
      Size = 10
    end
    object ElementNAME_SINV: TFIBWideStringField
      FieldName = 'NAME_SINV'
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
