object DMSprNomFind: TDMSprNomFind
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 188
  Width = 371
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object Table: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SNOM'
      'SET '
      '    ARTNOM = :ARTNOM,'
      '    CODENOM = :CODENOM,'
      '    TNOM = :TNOM,'
      '    NAMENOM = :NAMENOM,'
      '    IDGRPNOM = :IDGRPNOM'
      'WHERE'
      '    IDNOM = :OLD_IDNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNOM'
      'WHERE'
      '        IDNOM = :OLD_IDNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNOM('
      '    IDNOM,'
      '    ARTNOM,'
      '    CODENOM,'
      '    TNOM,'
      '    NAMENOM,'
      '    IDGRPNOM'
      ')'
      'VALUES('
      '    :IDNOM,'
      '    :ARTNOM,'
      '    :CODENOM,'
      '    :TNOM,'
      '    :NAMENOM,'
      '    :IDGRPNOM'
      ')')
    RefreshSQL.Strings = (
      'select'
      '    snom.idnom,'
      '    snom.artnom,'
      '    snom.codenom,'
      '    snom.tnom,'
      '    snom.namenom,'
      '    sed.nameed,'
      '    sprice.znach_price,'
      '    snom.idgrpnom,'
      '    sgrpnom.namegn,'
      '    0.000 AS SUMKOL'
      'from SNOM'
      
        'left outer join SPRICE on sprice.idnom_price=snom.idnom and spri' +
        'ce.idtype_price=:PARAM_IDTYPEPRICE'
      'left outer join SED on snom.idbasednom=sed.ided'
      'left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn'
      'where(  upper(snom.namenom) like upper(:PARAM_WORD)'
      '     ) and (     SNOM.IDNOM = :OLD_IDNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select'
      '    snom.idnom,'
      '    snom.artnom,'
      '    snom.codenom,'
      '    snom.tnom,'
      '    snom.namenom,'
      '    sed.nameed,'
      '    sed.shed,'
      '    sprice.znach_price,'
      '    snom.idgrpnom,'
      '    sgrpnom.namegn,'
      '    0.000 AS SUMKOL,'
      '    0.000 AS REM_OST'
      'from SNOM'
      
        'left outer join SPRICE on sprice.idnom_price=snom.idnom and spri' +
        'ce.idtype_price=:PARAM_IDTYPEPRICE'
      'left outer join SED on snom.idbasednom=sed.ided'
      'left outer join sgrpnom on snom.idgrpnom=sgrpnom.idgn'
      'where upper(snom.namenom) like upper(:PARAM_WORD)'
      'ORDER BY NAMENOM')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableIDNOM: TFIBLargeIntField
      FieldName = 'IDNOM'
    end
    object TableARTNOM: TFIBWideStringField
      FieldName = 'ARTNOM'
    end
    object TableCODENOM: TFIBIntegerField
      FieldName = 'CODENOM'
    end
    object TableTNOM: TFIBSmallIntField
      FieldName = 'TNOM'
    end
    object TableNAMENOM: TFIBWideStringField
      FieldName = 'NAMENOM'
      Size = 200
    end
    object TableNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 200
    end
    object TableZNACH_PRICE: TFIBBCDField
      FieldName = 'ZNACH_PRICE'
      Size = 2
      RoundByScale = True
    end
    object TableIDGRPNOM: TFIBLargeIntField
      FieldName = 'IDGRPNOM'
    end
    object TableSUMKOL: TFIBBCDField
      FieldName = 'SUMKOL'
      Size = 3
      RoundByScale = True
    end
    object TableNAMEGN: TFIBWideStringField
      FieldName = 'NAMEGN'
      Size = 200
    end
    object TableSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
    object TableREM_OST: TFIBBCDField
      FieldName = 'REM_OST'
      Size = 3
      RoundByScale = True
    end
  end
  object IBTr: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'rec_version'
      'read_committed')
    TPBMode = tpbDefault
    Left = 256
    Top = 16
  end
  object SpTPrice: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from STPRICE')
    Transaction = IBTr
    Left = 160
    Top = 80
    poUseLargeIntField = True
    object SpTPriceID_TPRICE: TFIBLargeIntField
      FieldName = 'ID_TPRICE'
    end
    object SpTPriceNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object DataSourceTPrice: TDataSource
    DataSet = SpTPrice
    Left = 56
    Top = 80
  end
end
