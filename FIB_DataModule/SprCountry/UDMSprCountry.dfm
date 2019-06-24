object DMSprCountry: TDMSprCountry
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
      'select  * from SCOUNTRY')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 136
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SCOUNTRY: TFIBBCDField
      FieldName = 'ID_SCOUNTRY'
      Size = 0
      RoundByScale = True
    end
    object TableCODE_SCOUNTRY: TFIBWideStringField
      FieldName = 'CODE_SCOUNTRY'
      Size = 10
    end
    object TableGID_SCOUNTRY: TFIBWideStringField
      FieldName = 'GID_SCOUNTRY'
      Size = 10
    end
    object TableNAME_SCOUNTRY: TFIBWideStringField
      FieldName = 'NAME_SCOUNTRY'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SCOUNTRY'
      'SET '
      '    CODE_SCOUNTRY = :CODE_SCOUNTRY,'
      '    GID_SCOUNTRY = :GID_SCOUNTRY,'
      '    NAME_SCOUNTRY = :NAME_SCOUNTRY'
      'WHERE'
      '    ID_SCOUNTRY = :OLD_ID_SCOUNTRY'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SCOUNTRY'
      'WHERE'
      '        ID_SCOUNTRY = :OLD_ID_SCOUNTRY'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SCOUNTRY('
      '    ID_SCOUNTRY,'
      '    CODE_SCOUNTRY,'
      '    GID_SCOUNTRY,'
      '    NAME_SCOUNTRY'
      ')'
      'VALUES('
      '    :ID_SCOUNTRY,'
      '    :CODE_SCOUNTRY,'
      '    :GID_SCOUNTRY,'
      '    :NAME_SCOUNTRY'
      ')')
    RefreshSQL.Strings = (
      'select * from SCOUNTRY where(  ID_SCOUNTRY=:PARAM_ID'
      '     ) and (     SCOUNTRY.ID_SCOUNTRY = :OLD_ID_SCOUNTRY'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SCOUNTRY where ID_SCOUNTRY=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SCOUNTRY'
    AutoUpdateOptions.KeyFields = 'ID_SCOUNTRY'
    AutoUpdateOptions.GeneratorName = 'GEN_SCOUNTRY_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 96
    object ElementID_SCOUNTRY: TFIBBCDField
      FieldName = 'ID_SCOUNTRY'
      Size = 0
      RoundByScale = True
    end
    object ElementCODE_SCOUNTRY: TFIBWideStringField
      FieldName = 'CODE_SCOUNTRY'
      Size = 10
    end
    object ElementGID_SCOUNTRY: TFIBWideStringField
      FieldName = 'GID_SCOUNTRY'
      Size = 10
    end
    object ElementNAME_SCOUNTRY: TFIBWideStringField
      FieldName = 'NAME_SCOUNTRY'
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
