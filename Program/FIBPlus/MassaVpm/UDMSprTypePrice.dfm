object DMSprTypePrice: TDMSprTypePrice
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 156
  Width = 319
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 40
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 40
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 144
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_TPRICE: TFIBBCDField
      FieldName = 'ID_TPRICE'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object TableGID_STPRICE: TFIBWideStringField
      FieldName = 'GID_STPRICE'
      Size = 10
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE STPRICE'
      'SET '
      '    NAME_TPRICE = :NAME_TPRICE,'
      '    GID_STPRICE = :GID_STPRICE'
      'WHERE'
      '    ID_TPRICE = :OLD_ID_TPRICE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    STPRICE'
      'WHERE'
      '        ID_TPRICE = :OLD_ID_TPRICE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO STPRICE('
      '    ID_TPRICE,'
      '    NAME_TPRICE,'
      '    GID_STPRICE'
      ')'
      'VALUES('
      '    :ID_TPRICE,'
      '    :NAME_TPRICE,'
      '    :GID_STPRICE'
      ')')
    RefreshSQL.Strings = (
      'select * from STPRICE where(  ID_TPRICE=:ID'
      '     ) and (     STPRICE.ID_TPRICE = :OLD_ID_TPRICE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from STPRICE where ID_TPRICE=:ID')
    AutoUpdateOptions.UpdateTableName = 'STPRICE'
    AutoUpdateOptions.KeyFields = 'ID_TPRICE'
    AutoUpdateOptions.GeneratorName = 'GEN_STPRICE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    object ElementID_TPRICE: TFIBBCDField
      FieldName = 'ID_TPRICE'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
    object ElementGID_STPRICE: TFIBWideStringField
      FieldName = 'GID_STPRICE'
      Size = 10
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
    Left = 224
    Top = 16
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
    Left = 224
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 280
    Top = 56
    qoStartTransaction = True
  end
end
