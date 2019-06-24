object DMSprProducerNom: TDMSprProducerNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 276
  Width = 541
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    SelectSQL.Strings = (
      'select  sprnom.id_sprnom,'
      '        sprnom.idgrp_sprnom,'
      '        sprnom.idprod_sprnom,'
      '        sprnom.code_sprnom,'
      '        sprnom.art_sprnom,'
      'sprnom.art2_sprnom,'
      '        sprnom.name_sprnom,'
      '        sprnom.model_str_sprnom,'
      '        sprnom.code_analog_str_sprnom,'
      '        sprnom.fl_dostupno_sprnom,'
      '        sprnom.price_zakup_sprnom,'
      '        sprnom.price_sprnom,'
      'sprnom.ism_sprnom,'
      '        snom.codenom,'
      '        snom.artnom,'
      '        snom.namenom,'
      '        sed.shed,'
      '        sed.nameed,'
      '        spred.name_spred,'
      '        spred.barcode_spred,'
      '        sprprice.value_sprprice,'
      'sprnom.repaircode_sprnom,'
      'sprnom.location_sprnom'
      'from sprnom'
      
        'left outer join sprprice on sprprice.idprnom_sprprice=sprnom.id_' +
        'sprnom'
      
        '                AND sprprice.idprtprice_sprprice=:PARAM_IDTYPE_P' +
        'RICE'
      'left outer join spred on  sprnom.idbased_sprnom=spred.id_spred'
      'left outer join snom on sprnom.idnom_sprnom=snom.idnom'
      'left outer join sed  on snom.idbasednom=sed.ided'
      'where '
      
        '    sprnom.idprod_sprnom=:PARAM_IDPRODUCER and sprnom.idgrp_sprn' +
        'om=:PARAM_IDGRP'
      'order by sprnom.name_sprnom')
    AutoUpdateOptions.GeneratorName = 'GEN__ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 136
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SPRNOM: TFIBLargeIntField
      FieldName = 'ID_SPRNOM'
    end
    object TableIDGRP_SPRNOM: TFIBLargeIntField
      FieldName = 'IDGRP_SPRNOM'
    end
    object TableIDPROD_SPRNOM: TFIBLargeIntField
      FieldName = 'IDPROD_SPRNOM'
    end
    object TableCODE_SPRNOM: TFIBIntegerField
      FieldName = 'CODE_SPRNOM'
    end
    object TableART_SPRNOM: TFIBWideStringField
      FieldName = 'ART_SPRNOM'
      Size = 40
    end
    object TableNAME_SPRNOM: TFIBWideStringField
      FieldName = 'NAME_SPRNOM'
      Size = 200
    end
    object TableNAME_SPRED: TFIBWideStringField
      FieldName = 'NAME_SPRED'
      Size = 200
    end
    object TableBARCODE_SPRED: TFIBWideStringField
      FieldName = 'BARCODE_SPRED'
      Size = 13
    end
    object TableVALUE_SPRPRICE: TFIBBCDField
      FieldName = 'VALUE_SPRPRICE'
      Size = 2
      RoundByScale = True
    end
    object TableMODEL_STR_SPRNOM: TFIBWideStringField
      FieldName = 'MODEL_STR_SPRNOM'
      Size = 30
    end
    object TableCODE_ANALOG_STR_SPRNOM: TFIBWideStringField
      FieldName = 'CODE_ANALOG_STR_SPRNOM'
      Size = 200
    end
    object TableFL_DOSTUPNO_SPRNOM: TFIBSmallIntField
      FieldName = 'FL_DOSTUPNO_SPRNOM'
    end
    object TablePRICE_ZAKUP_SPRNOM: TFIBBCDField
      FieldName = 'PRICE_ZAKUP_SPRNOM'
      Size = 2
      RoundByScale = True
    end
    object TablePRICE_SPRNOM: TFIBBCDField
      FieldName = 'PRICE_SPRNOM'
      Size = 2
      RoundByScale = True
    end
    object TableCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object TableARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object TableSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
    object TableNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object TableISM_SPRNOM: TFIBDateTimeField
      FieldName = 'ISM_SPRNOM'
      DisplayFormat = 'c'
    end
    object TableART2_SPRNOM: TFIBWideStringField
      FieldName = 'ART2_SPRNOM'
      Size = 40
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
  object Element: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SPRNOM'
      'SET '
      '    IDBASE_SPRNOM = :IDBASE_SPRNOM,'
      '    GID_SPRNOM = :GID_SPRNOM,'
      '    IDPROD_SPRNOM = :IDPROD_SPRNOM,'
      '    IDGRP_SPRNOM = :IDGRP_SPRNOM,'
      '    CODE_SPRNOM = :CODE_SPRNOM,'
      '    ART_SPRNOM = :ART_SPRNOM,'
      '    NAME_SPRNOM = :NAME_SPRNOM,'
      '    KRNAME_SPRNOM = :KRNAME_SPRNOM,'
      '    FNAME_SPRNOM = :FNAME_SPRNOM,'
      '    TYPE_SPRNOM = :TYPE_SPRNOM,'
      '    IDBASED_SPRNOM = :IDBASED_SPRNOM,'
      '    MODEL_STR_SPRNOM = :MODEL_STR_SPRNOM,'
      '    CODE_ANALOG_STR_SPRNOM = :CODE_ANALOG_STR_SPRNOM,'
      '    FL_DOSTUPNO_SPRNOM = :FL_DOSTUPNO_SPRNOM,'
      '    PRICE_ZAKUP_SPRNOM = :PRICE_ZAKUP_SPRNOM,'
      '    PRICE_SPRNOM = :PRICE_SPRNOM,'
      '    IDNOM_SPRNOM = :IDNOM_SPRNOM,'
      '    ISM_SPRNOM = :ISM_SPRNOM,'
      '    REPAIRCODE_SPRNOM = :REPAIRCODE_SPRNOM,'
      '    LOCATION_SPRNOM = :LOCATION_SPRNOM,'
      '    ART2_SPRNOM = :ART2_SPRNOM,'
      '    ANGL_NAME_SPRNOM = :ANGL_NAME_SPRNOM'
      'WHERE'
      '    ID_SPRNOM = :OLD_ID_SPRNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRNOM'
      'WHERE'
      '        ID_SPRNOM = :OLD_ID_SPRNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRNOM('
      '    ID_SPRNOM,'
      '    IDBASE_SPRNOM,'
      '    GID_SPRNOM,'
      '    IDPROD_SPRNOM,'
      '    IDGRP_SPRNOM,'
      '    CODE_SPRNOM,'
      '    ART_SPRNOM,'
      '    NAME_SPRNOM,'
      '    KRNAME_SPRNOM,'
      '    FNAME_SPRNOM,'
      '    TYPE_SPRNOM,'
      '    IDBASED_SPRNOM,'
      '    MODEL_STR_SPRNOM,'
      '    CODE_ANALOG_STR_SPRNOM,'
      '    FL_DOSTUPNO_SPRNOM,'
      '    PRICE_ZAKUP_SPRNOM,'
      '    PRICE_SPRNOM,'
      '    IDNOM_SPRNOM,'
      '    ISM_SPRNOM,'
      '    REPAIRCODE_SPRNOM,'
      '    LOCATION_SPRNOM,'
      '    ART2_SPRNOM,'
      '    ANGL_NAME_SPRNOM'
      ')'
      'VALUES('
      '    :ID_SPRNOM,'
      '    :IDBASE_SPRNOM,'
      '    :GID_SPRNOM,'
      '    :IDPROD_SPRNOM,'
      '    :IDGRP_SPRNOM,'
      '    :CODE_SPRNOM,'
      '    :ART_SPRNOM,'
      '    :NAME_SPRNOM,'
      '    :KRNAME_SPRNOM,'
      '    :FNAME_SPRNOM,'
      '    :TYPE_SPRNOM,'
      '    :IDBASED_SPRNOM,'
      '    :MODEL_STR_SPRNOM,'
      '    :CODE_ANALOG_STR_SPRNOM,'
      '    :FL_DOSTUPNO_SPRNOM,'
      '    :PRICE_ZAKUP_SPRNOM,'
      '    :PRICE_SPRNOM,'
      '    :IDNOM_SPRNOM,'
      '    :ISM_SPRNOM,'
      '    :REPAIRCODE_SPRNOM,'
      '    :LOCATION_SPRNOM,'
      '    :ART2_SPRNOM,'
      '    :ANGL_NAME_SPRNOM'
      ')')
    RefreshSQL.Strings = (
      'select sprnom.*, '
      '    snom.codenom,'
      '    snom.artnom,'
      '    snom.namenom,'
      '    sed.shed,'
      '    sed.nameed'
      'from sprnom'
      'left outer join snom on sprnom.idnom_sprnom=snom.idnom'
      'left outer join sed  on snom.idbasednom=sed.ided'
      'where(  sprnom.id_sprnom=:PARAM_ID'
      '     ) and (     SPRNOM.ID_SPRNOM = :OLD_ID_SPRNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select sprnom.*, '
      '    snom.codenom,'
      '    snom.artnom,'
      '    snom.namenom,'
      '    sed.shed,'
      '    sed.nameed'
      'from sprnom'
      'left outer join snom on sprnom.idnom_sprnom=snom.idnom'
      'left outer join sed  on snom.idbasednom=sed.ided'
      'where sprnom.id_sprnom=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPRNOM'
    AutoUpdateOptions.KeyFields = 'ID_SPRNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 136
    Top = 80
    poUseLargeIntField = True
    object ElementID_SPRNOM: TFIBLargeIntField
      FieldName = 'ID_SPRNOM'
    end
    object ElementIDBASE_SPRNOM: TFIBLargeIntField
      FieldName = 'IDBASE_SPRNOM'
    end
    object ElementGID_SPRNOM: TFIBWideStringField
      FieldName = 'GID_SPRNOM'
      Size = 10
    end
    object ElementIDPROD_SPRNOM: TFIBLargeIntField
      FieldName = 'IDPROD_SPRNOM'
    end
    object ElementIDGRP_SPRNOM: TFIBLargeIntField
      FieldName = 'IDGRP_SPRNOM'
    end
    object ElementCODE_SPRNOM: TFIBIntegerField
      FieldName = 'CODE_SPRNOM'
    end
    object ElementART_SPRNOM: TFIBWideStringField
      FieldName = 'ART_SPRNOM'
      Size = 40
    end
    object ElementNAME_SPRNOM: TFIBWideStringField
      FieldName = 'NAME_SPRNOM'
      Size = 200
    end
    object ElementKRNAME_SPRNOM: TFIBWideStringField
      FieldName = 'KRNAME_SPRNOM'
      Size = 40
    end
    object ElementFNAME_SPRNOM: TFIBWideStringField
      FieldName = 'FNAME_SPRNOM'
      Size = 200
    end
    object ElementTYPE_SPRNOM: TFIBIntegerField
      FieldName = 'TYPE_SPRNOM'
    end
    object ElementIDBASED_SPRNOM: TFIBLargeIntField
      FieldName = 'IDBASED_SPRNOM'
    end
    object ElementMODEL_STR_SPRNOM: TFIBWideStringField
      FieldName = 'MODEL_STR_SPRNOM'
      Size = 30
    end
    object ElementCODE_ANALOG_STR_SPRNOM: TFIBWideStringField
      FieldName = 'CODE_ANALOG_STR_SPRNOM'
      Size = 200
    end
    object ElementFL_DOSTUPNO_SPRNOM: TFIBSmallIntField
      FieldName = 'FL_DOSTUPNO_SPRNOM'
    end
    object ElementPRICE_ZAKUP_SPRNOM: TFIBBCDField
      FieldName = 'PRICE_ZAKUP_SPRNOM'
      Size = 2
      RoundByScale = True
    end
    object ElementPRICE_SPRNOM: TFIBBCDField
      FieldName = 'PRICE_SPRNOM'
      Size = 2
      RoundByScale = True
    end
    object ElementIDNOM_SPRNOM: TFIBLargeIntField
      FieldName = 'IDNOM_SPRNOM'
    end
    object ElementCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object ElementARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
      Size = 40
    end
    object ElementNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object ElementSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
    object ElementNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object ElementISM_SPRNOM: TFIBDateTimeField
      FieldName = 'ISM_SPRNOM'
      DisplayFormat = 'c'
    end
    object ElementREPAIRCODE_SPRNOM: TFIBWideStringField
      FieldName = 'REPAIRCODE_SPRNOM'
      Size = 10
    end
    object ElementLOCATION_SPRNOM: TFIBWideStringField
      FieldName = 'LOCATION_SPRNOM'
      Size = 10
    end
    object ElementART2_SPRNOM: TFIBWideStringField
      FieldName = 'ART2_SPRNOM'
      Size = 40
    end
    object ElementANGL_NAME_SPRNOM: TFIBWideStringField
      FieldName = 'ANGL_NAME_SPRNOM'
      Size = 200
    end
  end
  object SpTPrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from sprtype_price')
    Transaction = IBTr
    Left = 32
    Top = 160
    poUseLargeIntField = True
    object SpTPriceID_SPRTYPE_PRICE: TFIBLargeIntField
      FieldName = 'ID_SPRTYPE_PRICE'
    end
    object SpTPriceNAME_SPRTYPE_PRICE: TFIBWideStringField
      FieldName = 'NAME_SPRTYPE_PRICE'
      Size = 200
    end
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 80
  end
  object pFIBQuery: TpFIBQuery
    Transaction = IBTr
    Left = 328
    Top = 120
    qoStartTransaction = True
  end
end
