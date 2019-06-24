object DMSprDogovor: TDMSprDogovor
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 155
  Width = 334
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
      'select * from SDOG where IDKLIENT_SDOG=:PARAM_IDKLIENT')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 152
    Top = 8
    object TableDO_SDOG: TFIBDateField
      FieldName = 'DO_SDOG'
    end
    object TableWAYPAY_SDOG: TFIBIntegerField
      FieldName = 'WAYPAY_SDOG'
    end
    object TableMAXSUMCREDIT_SDOG: TFIBBCDField
      FieldName = 'MAXSUMCREDIT_SDOG'
      Size = 2
      RoundByScale = True
    end
    object TableSROK_SDOG: TFIBIntegerField
      FieldName = 'SROK_SDOG'
    end
    object TableDATE_SDOG: TFIBDateField
      FieldName = 'DATE_SDOG'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SDOG: TFIBBCDField
      FieldName = 'ID_SDOG'
      Size = 0
      RoundByScale = True
    end
    object TableIDKLIENT_SDOG: TFIBBCDField
      FieldName = 'IDKLIENT_SDOG'
      Size = 0
      RoundByScale = True
    end
    object TableIDTPRICE_SDOG: TFIBBCDField
      FieldName = 'IDTPRICE_SDOG'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_SDOG: TFIBWideStringField
      FieldName = 'NAME_SDOG'
      Size = 100
    end
    object TableGID_SDOG: TFIBWideStringField
      FieldName = 'GID_SDOG'
      Size = 10
    end
    object TableNUMBER_SDOG: TFIBWideStringField
      FieldName = 'NUMBER_SDOG'
      Size = 10
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SDOG'
      'SET '
      '    IDKLIENT_SDOG = :IDKLIENT_SDOG,'
      '    NAME_SDOG = :NAME_SDOG,'
      '    DO_SDOG = :DO_SDOG,'
      '    GID_SDOG = :GID_SDOG,'
      '    WAYPAY_SDOG = :WAYPAY_SDOG,'
      '    MAXSUMCREDIT_SDOG = :MAXSUMCREDIT_SDOG,'
      '    SROK_SDOG = :SROK_SDOG,'
      '    IDTPRICE_SDOG = :IDTPRICE_SDOG,'
      '    DATE_SDOG = :DATE_SDOG,'
      '    NUMBER_SDOG = :NUMBER_SDOG'
      'WHERE'
      '    ID_SDOG = :OLD_ID_SDOG'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SDOG'
      'WHERE'
      '        ID_SDOG = :OLD_ID_SDOG'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SDOG('
      '    ID_SDOG,'
      '    IDKLIENT_SDOG,'
      '    NAME_SDOG,'
      '    DO_SDOG,'
      '    GID_SDOG,'
      '    WAYPAY_SDOG,'
      '    MAXSUMCREDIT_SDOG,'
      '    SROK_SDOG,'
      '    IDTPRICE_SDOG,'
      '    DATE_SDOG,'
      '    NUMBER_SDOG'
      ')'
      'VALUES('
      '    :ID_SDOG,'
      '    :IDKLIENT_SDOG,'
      '    :NAME_SDOG,'
      '    :DO_SDOG,'
      '    :GID_SDOG,'
      '    :WAYPAY_SDOG,'
      '    :MAXSUMCREDIT_SDOG,'
      '    :SROK_SDOG,'
      '    :IDTPRICE_SDOG,'
      '    :DATE_SDOG,'
      '    :NUMBER_SDOG'
      ')')
    RefreshSQL.Strings = (
      'select * from SDOG where(  ID_SDOG=:PARAM_ID'
      '     ) and (     SDOG.ID_SDOG = :OLD_ID_SDOG'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SDOG where ID_SDOG=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SDOG'
    AutoUpdateOptions.KeyFields = 'ID_SDOG'
    AutoUpdateOptions.GeneratorName = 'GEN_SDOG_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 72
    object ElementDO_SDOG: TFIBDateField
      FieldName = 'DO_SDOG'
    end
    object ElementWAYPAY_SDOG: TFIBIntegerField
      FieldName = 'WAYPAY_SDOG'
    end
    object ElementMAXSUMCREDIT_SDOG: TFIBBCDField
      FieldName = 'MAXSUMCREDIT_SDOG'
      Size = 2
      RoundByScale = True
    end
    object ElementSROK_SDOG: TFIBIntegerField
      FieldName = 'SROK_SDOG'
    end
    object ElementDATE_SDOG: TFIBDateField
      FieldName = 'DATE_SDOG'
    end
    object ElementID_SDOG: TFIBBCDField
      FieldName = 'ID_SDOG'
      Size = 0
      RoundByScale = True
    end
    object ElementIDKLIENT_SDOG: TFIBBCDField
      FieldName = 'IDKLIENT_SDOG'
      Size = 0
      RoundByScale = True
    end
    object ElementIDTPRICE_SDOG: TFIBBCDField
      FieldName = 'IDTPRICE_SDOG'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_SDOG: TFIBWideStringField
      FieldName = 'NAME_SDOG'
      Size = 100
    end
    object ElementGID_SDOG: TFIBWideStringField
      FieldName = 'GID_SDOG'
      Size = 10
    end
    object ElementNUMBER_SDOG: TFIBWideStringField
      FieldName = 'NUMBER_SDOG'
      Size = 10
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
    Left = 248
    Top = 8
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 248
    Top = 72
  end
end
