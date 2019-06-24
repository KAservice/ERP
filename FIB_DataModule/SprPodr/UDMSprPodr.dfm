object DMSprPodr: TDMSprPodr
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 161
  Width = 301
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 88
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '  SPOD.*,  NAME_TPRICE '
      'from '
      '  SPOD'
      'left outer join   STPRICE on IDTPRICEPOD=ID_TPRICE')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 144
    Top = 16
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableIDPOD: TFIBBCDField
      FieldName = 'IDPOD'
      Size = 0
      RoundByScale = True
    end
    object TableIDTPRICEPOD: TFIBBCDField
      FieldName = 'IDTPRICEPOD'
      Size = 0
      RoundByScale = True
    end
    object TableNAMEPOD: TFIBWideStringField
      FieldName = 'NAMEPOD'
      Size = 100
    end
    object TableGID_SPOD: TFIBWideStringField
      FieldName = 'GID_SPOD'
      Size = 10
    end
    object TableIDBASE_SPOD: TFIBBCDField
      FieldName = 'IDBASE_SPOD'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPOD'
      'SET '
      '    NAMEPOD = :NAMEPOD,'
      '    IDTPRICEPOD = :IDTPRICEPOD,'
      '    GID_SPOD = :GID_SPOD'
      'WHERE'
      '    IDPOD = :OLD_IDPOD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPOD'
      'WHERE'
      '        IDPOD = :OLD_IDPOD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPOD('
      '    IDPOD,'
      '    NAMEPOD,'
      '    IDTPRICEPOD,'
      '    GID_SPOD'
      ')'
      'VALUES('
      '    :IDPOD,'
      '    :NAMEPOD,'
      '    :IDTPRICEPOD,'
      '    :GID_SPOD'
      ')')
    RefreshSQL.Strings = (
      'select '
      '  SPOD.*,  NAME_TPRICE '
      'from '
      '  SPOD'
      'left outer join   STPRICE on IDTPRICEPOD=ID_TPRICE'
      'where(  '
      '  IDPOD=:PARAM_IDPOD'
      '     ) and (     SPOD.IDPOD = :OLD_IDPOD'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select '
      '  SPOD.*,  NAME_TPRICE '
      'from '
      '  SPOD'
      'left outer join   STPRICE on IDTPRICEPOD=ID_TPRICE'
      'where '
      '  IDPOD=:PARAM_IDPOD')
    AutoUpdateOptions.UpdateTableName = 'SPOD'
    AutoUpdateOptions.KeyFields = 'IDPOD'
    AutoUpdateOptions.GeneratorName = 'GEN_SPOD_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 88
    object ElementIDPOD: TFIBBCDField
      FieldName = 'IDPOD'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTPRICEPOD: TFIBBCDField
      FieldName = 'IDTPRICEPOD'
      Size = 0
      RoundByScale = True
    end
    object ElementNAMEPOD: TFIBWideStringField
      FieldName = 'NAMEPOD'
      Size = 100
    end
    object ElementGID_SPOD: TFIBWideStringField
      FieldName = 'GID_SPOD'
      Size = 10
    end
    object ElementIDBASE_SPOD: TFIBBCDField
      FieldName = 'IDBASE_SPOD'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_TPRICE: TFIBWideStringField
      FieldName = 'NAME_TPRICE'
      Size = 30
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
    Top = 88
  end
end
