object DMSprProducerTypePrice: TDMSprProducerTypePrice
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 200
  Width = 675
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
      'select * from sprtype_price')
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SPRTYPE_PRICE: TFIBLargeIntField
      FieldName = 'ID_SPRTYPE_PRICE'
    end
    object TableIDBASE_SPRTYPE_PRICE: TFIBLargeIntField
      FieldName = 'IDBASE_SPRTYPE_PRICE'
    end
    object TableGID_SPRTYPE_PRICE: TFIBWideStringField
      FieldName = 'GID_SPRTYPE_PRICE'
      Size = 10
    end
    object TableNAME_SPRTYPE_PRICE: TFIBWideStringField
      FieldName = 'NAME_SPRTYPE_PRICE'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPRTYPE_PRICE'
      'SET '
      '    IDBASE_SPRTYPE_PRICE = :IDBASE_SPRTYPE_PRICE,'
      '    GID_SPRTYPE_PRICE = :GID_SPRTYPE_PRICE,'
      '    NAME_SPRTYPE_PRICE = :NAME_SPRTYPE_PRICE'
      'WHERE'
      '    ID_SPRTYPE_PRICE = :OLD_ID_SPRTYPE_PRICE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRTYPE_PRICE'
      'WHERE'
      '        ID_SPRTYPE_PRICE = :OLD_ID_SPRTYPE_PRICE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRTYPE_PRICE('
      '    ID_SPRTYPE_PRICE,'
      '    IDBASE_SPRTYPE_PRICE,'
      '    GID_SPRTYPE_PRICE,'
      '    NAME_SPRTYPE_PRICE'
      ')'
      'VALUES('
      '    :ID_SPRTYPE_PRICE,'
      '    :IDBASE_SPRTYPE_PRICE,'
      '    :GID_SPRTYPE_PRICE,'
      '    :NAME_SPRTYPE_PRICE'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from sprtype_price'
      'where(  sprtype_price.id_sprtype_price=:PARAM_ID'
      
        '     ) and (     SPRTYPE_PRICE.ID_SPRTYPE_PRICE = :OLD_ID_SPRTYP' +
        'E_PRICE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from sprtype_price'
      'where sprtype_price.id_sprtype_price=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPRTYPE_PRICE'
    AutoUpdateOptions.KeyFields = 'ID_SPRTYPE_PRICE'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRTYPE_PRICE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_SPRTYPE_PRICE: TFIBLargeIntField
      FieldName = 'ID_SPRTYPE_PRICE'
    end
    object ElementIDBASE_SPRTYPE_PRICE: TFIBLargeIntField
      FieldName = 'IDBASE_SPRTYPE_PRICE'
    end
    object ElementGID_SPRTYPE_PRICE: TFIBWideStringField
      FieldName = 'GID_SPRTYPE_PRICE'
      Size = 10
    end
    object ElementNAME_SPRTYPE_PRICE: TFIBWideStringField
      FieldName = 'NAME_SPRTYPE_PRICE'
      Size = 200
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
    Left = 224
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
    Left = 224
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 280
    Top = 56
    qoStartTransaction = True
  end
end
