object DMSprProducerPrice: TDMSprProducerPrice
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 345
  Width = 669
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPRPRICE'
      'SET '
      '    IDBASE_SPRPRICE = :IDBASE_SPRPRICE,'
      '    IDEXT_BASE_SPRPRICE = :IDEXT_BASE_SPRPRICE,'
      '    IDEXT_DOUT_SPRPRICE = :IDEXT_DOUT_SPRPRICE,'
      '    GID_SPRPRICE = :GID_SPRPRICE,'
      '    IDPRNOM_SPRPRICE = :IDPRNOM_SPRPRICE,'
      '    IDPRTPRICE_SPRPRICE = :IDPRTPRICE_SPRPRICE,'
      '    VALUE_SPRPRICE = :VALUE_SPRPRICE,'
      '    TYPE_TBL_SPRPRICE = :TYPE_TBL_SPRPRICE'
      'WHERE'
      '    ID_SPRPRICE = :OLD_ID_SPRPRICE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRPRICE'
      'WHERE'
      '        ID_SPRPRICE = :OLD_ID_SPRPRICE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRPRICE('
      '    ID_SPRPRICE,'
      '    IDBASE_SPRPRICE,'
      '    IDEXT_BASE_SPRPRICE,'
      '    IDEXT_DOUT_SPRPRICE,'
      '    GID_SPRPRICE,'
      '    IDPRNOM_SPRPRICE,'
      '    IDPRTPRICE_SPRPRICE,'
      '    VALUE_SPRPRICE,'
      '    TYPE_TBL_SPRPRICE'
      ')'
      'VALUES('
      '    :ID_SPRPRICE,'
      '    :IDBASE_SPRPRICE,'
      '    :IDEXT_BASE_SPRPRICE,'
      '    :IDEXT_DOUT_SPRPRICE,'
      '    :GID_SPRPRICE,'
      '    :IDPRNOM_SPRPRICE,'
      '    :IDPRTPRICE_SPRPRICE,'
      '    :VALUE_SPRPRICE,'
      '    :TYPE_TBL_SPRPRICE'
      ')')
    RefreshSQL.Strings = (
      'select        sprprice.*,'
      '        sprtype_price.name_sprtype_price'
      'from '
      '  sprprice'
      
        'left outer join sprtype_price on sprprice.idprtprice_sprprice=sp' +
        'rtype_price.id_sprtype_price'
      'where(  '
      '  sprprice.idprnom_sprprice=:PARAM_IDPRNOM'
      '     ) and (     SPRPRICE.ID_SPRPRICE = :OLD_ID_SPRPRICE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select        sprprice.*,'
      '        sprtype_price.name_sprtype_price'
      'from '
      '  sprprice'
      
        'left outer join sprtype_price on sprprice.idprtprice_sprprice=sp' +
        'rtype_price.id_sprtype_price'
      'where '
      '  sprprice.idprnom_sprprice=:PARAM_IDPRNOM'
      'order by sprtype_price.name_sprtype_price'
      '')
    AutoUpdateOptions.UpdateTableName = 'SPRPRICE'
    AutoUpdateOptions.KeyFields = 'ID_SPRPRICE'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRPRICE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = TableNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 16
    poUseLargeIntField = True
    object TableID_SPRPRICE: TFIBLargeIntField
      FieldName = 'ID_SPRPRICE'
    end
    object TableIDBASE_SPRPRICE: TFIBLargeIntField
      FieldName = 'IDBASE_SPRPRICE'
    end
    object TableGID_SPRPRICE: TFIBWideStringField
      FieldName = 'GID_SPRPRICE'
      Size = 10
    end
    object TableIDPRNOM_SPRPRICE: TFIBLargeIntField
      FieldName = 'IDPRNOM_SPRPRICE'
    end
    object TableIDPRTPRICE_SPRPRICE: TFIBLargeIntField
      FieldName = 'IDPRTPRICE_SPRPRICE'
    end
    object TableVALUE_SPRPRICE: TFIBBCDField
      FieldName = 'VALUE_SPRPRICE'
      Size = 2
      RoundByScale = True
    end
    object TableNAME_SPRTYPE_PRICE: TFIBWideStringField
      FieldName = 'NAME_SPRTYPE_PRICE'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPRPRICE'
      'SET '
      '    IDBASE_SPRPRICE = :IDBASE_SPRPRICE,'
      '    IDEXT_BASE_SPRPRICE = :IDEXT_BASE_SPRPRICE,'
      '    IDEXT_DOUT_SPRPRICE = :IDEXT_DOUT_SPRPRICE,'
      '    GID_SPRPRICE = :GID_SPRPRICE,'
      '    IDPRNOM_SPRPRICE = :IDPRNOM_SPRPRICE,'
      '    IDPRTPRICE_SPRPRICE = :IDPRTPRICE_SPRPRICE,'
      '    VALUE_SPRPRICE = :VALUE_SPRPRICE,'
      '    TYPE_TBL_SPRPRICE = :TYPE_TBL_SPRPRICE'
      'WHERE'
      '    ID_SPRPRICE = :OLD_ID_SPRPRICE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRPRICE'
      'WHERE'
      '        ID_SPRPRICE = :OLD_ID_SPRPRICE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRPRICE('
      '    ID_SPRPRICE,'
      '    IDBASE_SPRPRICE,'
      '    IDEXT_BASE_SPRPRICE,'
      '    IDEXT_DOUT_SPRPRICE,'
      '    GID_SPRPRICE,'
      '    IDPRNOM_SPRPRICE,'
      '    IDPRTPRICE_SPRPRICE,'
      '    VALUE_SPRPRICE,'
      '    TYPE_TBL_SPRPRICE'
      ')'
      'VALUES('
      '    :ID_SPRPRICE,'
      '    :IDBASE_SPRPRICE,'
      '    :IDEXT_BASE_SPRPRICE,'
      '    :IDEXT_DOUT_SPRPRICE,'
      '    :GID_SPRPRICE,'
      '    :IDPRNOM_SPRPRICE,'
      '    :IDPRTPRICE_SPRPRICE,'
      '    :VALUE_SPRPRICE,'
      '    :TYPE_TBL_SPRPRICE'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  sprprice'
      'where(  sprprice.id_sprprice=:PARAM_ID'
      '     ) and (     SPRPRICE.ID_SPRPRICE = :OLD_ID_SPRPRICE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  sprprice'
      'where sprprice.id_sprprice=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPRPRICE'
    AutoUpdateOptions.KeyFields = 'ID_SPRPRICE'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRPRICE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    object ElementID_SPRPRICE: TFIBBCDField
      FieldName = 'ID_SPRPRICE'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_SPRPRICE: TFIBBCDField
      FieldName = 'IDBASE_SPRPRICE'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SPRPRICE: TFIBWideStringField
      FieldName = 'GID_SPRPRICE'
      Size = 10
    end
    object ElementIDPRNOM_SPRPRICE: TFIBBCDField
      FieldName = 'IDPRNOM_SPRPRICE'
      Size = 0
      RoundByScale = True
    end
    object ElementIDPRTPRICE_SPRPRICE: TFIBBCDField
      FieldName = 'IDPRTPRICE_SPRPRICE'
      Size = 0
      RoundByScale = True
    end
    object ElementVALUE_SPRPRICE: TFIBBCDField
      FieldName = 'VALUE_SPRPRICE'
      Size = 2
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
    Left = 232
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
    Left = 232
    Top = 72
  end
  object TPrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select sprtype_price.id_sprtype_price,'
      '       sprtype_price.name_sprtype_price'
      'from sprtype_price'
      '')
    Transaction = IBTr
    Left = 152
    Top = 136
    poUseLargeIntField = True
    object TPriceID_SPRTYPE_PRICE: TFIBLargeIntField
      FieldName = 'ID_SPRTYPE_PRICE'
    end
    object TPriceNAME_SPRTYPE_PRICE: TFIBWideStringField
      FieldName = 'NAME_SPRTYPE_PRICE'
      Size = 200
    end
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 240
    Top = 136
    qoStartTransaction = True
  end
end
