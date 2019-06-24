object DMSprEd: TDMSprEd
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 155
  Width = 412
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SED where IDNOMED=:IDNOM')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 8
    poUseLargeIntField = True
    object TableKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object TableTSHED: TFIBIntegerField
      FieldName = 'TSHED'
    end
    object TableNEISPED: TFIBSmallIntField
      FieldName = 'NEISPED'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object TableKF2_SED: TFIBBCDField
      FieldName = 'KF2_SED'
      Size = 3
      RoundByScale = True
    end
    object TableVES_SED: TFIBBCDField
      FieldName = 'VES_SED'
      Size = 3
      RoundByScale = True
    end
    object TableIDED: TFIBLargeIntField
      FieldName = 'IDED'
    end
    object TableIDNOMED: TFIBLargeIntField
      FieldName = 'IDNOMED'
    end
    object TableIDOKEIED: TFIBLargeIntField
      FieldName = 'IDOKEIED'
    end
    object TableNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object TableSHED: TFIBWideStringField
      FieldName = 'SHED'
      Size = 13
    end
    object TableGID_SED: TFIBWideStringField
      FieldName = 'GID_SED'
      Size = 10
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SED'
      'SET '
      '    NAMEED = :NAMEED,'
      '    KFED = :KFED,'
      '    TSHED = :TSHED,'
      '    SHED = :SHED,'
      '    IDNOMED = :IDNOMED,'
      '    IDOKEIED = :IDOKEIED,'
      '    NEISPED = :NEISPED,'
      '    GID_SED = :GID_SED,'
      '    IDBASE_SED = :IDBASE_SED,'
      '    CODE_SED = :CODE_SED,'
      '    KF2_SED = :KF2_SED,'
      '    VES_SED = :VES_SED'
      'WHERE'
      '    IDED = :OLD_IDED'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SED'
      'WHERE'
      '        IDED = :OLD_IDED'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SED('
      '    IDED,'
      '    NAMEED,'
      '    KFED,'
      '    TSHED,'
      '    SHED,'
      '    IDNOMED,'
      '    IDOKEIED,'
      '    NEISPED,'
      '    GID_SED,'
      '    IDBASE_SED,'
      '    CODE_SED,'
      '    KF2_SED,'
      '    VES_SED'
      ')'
      'VALUES('
      '    :IDED,'
      '    :NAMEED,'
      '    :KFED,'
      '    :TSHED,'
      '    :SHED,'
      '    :IDNOMED,'
      '    :IDOKEIED,'
      '    :NEISPED,'
      '    :GID_SED,'
      '    :IDBASE_SED,'
      '    :CODE_SED,'
      '    :KF2_SED,'
      '    :VES_SED'
      ')')
    RefreshSQL.Strings = (
      'select SED.*,'
      '  NAMEOKEI'
      ' from SED'
      'left outer join SOKEI on IDOKEIED=IDOKEI'
      ' where(  IDED=:ID'
      '     ) and (     SED.IDED = :OLD_IDED'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select SED.*,'
      '  NAMEOKEI'
      ' from SED'
      'left outer join SOKEI on IDOKEIED=IDOKEI'
      ' where IDED=:ID')
    AutoUpdateOptions.UpdateTableName = 'SED'
    AutoUpdateOptions.KeyFields = 'IDED'
    AutoUpdateOptions.GeneratorName = 'GEN_SED_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 88
    object ElementKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object ElementTSHED: TFIBIntegerField
      FieldName = 'TSHED'
    end
    object ElementNEISPED: TFIBSmallIntField
      FieldName = 'NEISPED'
    end
    object ElementIDED: TFIBBCDField
      FieldName = 'IDED'
      Size = 0
      RoundByScale = True
    end
    object ElementIDNOMED: TFIBBCDField
      FieldName = 'IDNOMED'
      Size = 0
      RoundByScale = True
    end
    object ElementIDOKEIED: TFIBBCDField
      FieldName = 'IDOKEIED'
      Size = 0
      RoundByScale = True
    end
    object ElementCODE_SED: TFIBIntegerField
      FieldName = 'CODE_SED'
    end
    object ElementKF2_SED: TFIBBCDField
      FieldName = 'KF2_SED'
      Precision = 3
      Size = 3
      RoundByScale = True
    end
    object ElementVES_SED: TFIBBCDField
      FieldName = 'VES_SED'
      Precision = 3
      Size = 3
      RoundByScale = True
    end
    object ElementNAMEED: TFIBWideStringField
      FieldName = 'NAMEED'
      Size = 100
    end
    object ElementSHED: TFIBWideStringField
      FieldName = 'SHED'
      OnSetText = ElementSHEDSetText
      Size = 13
    end
    object ElementGID_SED: TFIBWideStringField
      FieldName = 'GID_SED'
      Size = 10
    end
    object ElementNAMEOKEI: TFIBWideStringField
      FieldName = 'NAMEOKEI'
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
    Top = 88
  end
  object OKEI: TpFIBDataSet
    SelectSQL.Strings = (
      'select * from SOKEI where IDOKEI=:ID')
    Transaction = IBTr
    Left = 344
    Top = 16
    object OKEICODEOKEI: TFIBIntegerField
      FieldName = 'CODEOKEI'
    end
    object OKEIIDOKEI: TFIBBCDField
      FieldName = 'IDOKEI'
      Size = 0
      RoundByScale = True
    end
    object OKEINAMEOKEI: TFIBWideStringField
      FieldName = 'NAMEOKEI'
      Size = 100
    end
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 344
    Top = 88
    qoStartTransaction = True
  end
end
