object HOT_DMSprCatNom: THOT_DMSprCatNom
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
    SelectSQL.Strings = (
      'select  * from HOT_SCATNOM')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_HOT_SCATNOM: TFIBBCDField
      FieldName = 'ID_HOT_SCATNOM'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_HOT_SCATNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SCATNOM'
      Size = 100
    end
    object TableDESCR_HOT_SCATNOM: TFIBWideStringField
      FieldName = 'DESCR_HOT_SCATNOM'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE HOT_SCATNOM'
      'SET '
      '    GID_HOT_SCATNOM = :GID_HOT_SCATNOM,'
      '    NAME_HOT_SCATNOM = :NAME_HOT_SCATNOM,'
      '    DESCR_HOT_SCATNOM = :DESCR_HOT_SCATNOM'
      'WHERE'
      '    ID_HOT_SCATNOM = :OLD_ID_HOT_SCATNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    HOT_SCATNOM'
      'WHERE'
      '        ID_HOT_SCATNOM = :OLD_ID_HOT_SCATNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO HOT_SCATNOM('
      '    ID_HOT_SCATNOM,'
      '    GID_HOT_SCATNOM,'
      '    NAME_HOT_SCATNOM,'
      '    DESCR_HOT_SCATNOM'
      ')'
      'VALUES('
      '    :ID_HOT_SCATNOM,'
      '    :GID_HOT_SCATNOM,'
      '    :NAME_HOT_SCATNOM,'
      '    :DESCR_HOT_SCATNOM'
      ')')
    RefreshSQL.Strings = (
      'select * from HOT_SCATNOM where(  ID_HOT_SCATNOM=:PARAM_ID'
      
        '     ) and (     HOT_SCATNOM.ID_HOT_SCATNOM = :OLD_ID_HOT_SCATNO' +
        'M'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from HOT_SCATNOM where ID_HOT_SCATNOM=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'HOT_SCATNOM'
    AutoUpdateOptions.KeyFields = 'ID_HOT_SCATNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_HOT_SCATNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 96
    object ElementID_HOT_SCATNOM: TFIBBCDField
      FieldName = 'ID_HOT_SCATNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_HOT_SCATNOM: TFIBWideStringField
      FieldName = 'NAME_HOT_SCATNOM'
      Size = 100
    end
    object ElementDESCR_HOT_SCATNOM: TFIBWideStringField
      FieldName = 'DESCR_HOT_SCATNOM'
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
