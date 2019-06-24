object DMSprImportEd: TDMSprImportEd
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
      'select * from SIMPORTED where IDED_SIMPORTED=:IDED')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 8
    object TableID_SIMPORTED: TFIBBCDField
      FieldName = 'ID_SIMPORTED'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_SIMPORTED: TFIBBCDField
      FieldName = 'IDBASE_SIMPORTED'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOM_SIMPORTED: TFIBBCDField
      FieldName = 'IDNOM_SIMPORTED'
      Size = 0
      RoundByScale = True
    end
    object TableIDKLIENT_SIMPORTED: TFIBBCDField
      FieldName = 'IDKLIENT_SIMPORTED'
      Size = 0
      RoundByScale = True
    end
    object TableIDED_SIMPORTED: TFIBBCDField
      FieldName = 'IDED_SIMPORTED'
      Size = 0
      RoundByScale = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableBARCODE_SIMPORTED: TFIBWideStringField
      FieldName = 'BARCODE_SIMPORTED'
      Size = 13
    end
    object TableCODE_SIMPORTED: TFIBWideStringField
      FieldName = 'CODE_SIMPORTED'
      Size = 10
    end
    object TableNAME_SIMPORTED: TFIBWideStringField
      FieldName = 'NAME_SIMPORTED'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SIMPORTED'
      'SET '
      '    IDBASE_SIMPORTED = :IDBASE_SIMPORTED,'
      '    IDNOM_SIMPORTED = :IDNOM_SIMPORTED,'
      '    IDKLIENT_SIMPORTED = :IDKLIENT_SIMPORTED,'
      '    IDED_SIMPORTED = :IDED_SIMPORTED,'
      '    BARCODE_SIMPORTED = :BARCODE_SIMPORTED,'
      '    CODE_SIMPORTED = :CODE_SIMPORTED,'
      '    NAME_SIMPORTED = :NAME_SIMPORTED'
      'WHERE'
      '    ID_SIMPORTED = :OLD_ID_SIMPORTED'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SIMPORTED'
      'WHERE'
      '        ID_SIMPORTED = :OLD_ID_SIMPORTED'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SIMPORTED('
      '    ID_SIMPORTED,'
      '    IDBASE_SIMPORTED,'
      '    IDNOM_SIMPORTED,'
      '    IDKLIENT_SIMPORTED,'
      '    IDED_SIMPORTED,'
      '    BARCODE_SIMPORTED,'
      '    CODE_SIMPORTED,'
      '    NAME_SIMPORTED'
      ')'
      'VALUES('
      '    :ID_SIMPORTED,'
      '    :IDBASE_SIMPORTED,'
      '    :IDNOM_SIMPORTED,'
      '    :IDKLIENT_SIMPORTED,'
      '    :IDED_SIMPORTED,'
      '    :BARCODE_SIMPORTED,'
      '    :CODE_SIMPORTED,'
      '    :NAME_SIMPORTED'
      ')')
    RefreshSQL.Strings = (
      'select SIMPORTED.*,'
      '  NAMEKLIENT'
      ' from SIMPORTED'
      'left outer join SKLIENT on IDKLIENT_SIMPORTED=IDKLIENT'
      ' where(  ID_SIMPORTED=:ID'
      '     ) and (     SIMPORTED.ID_SIMPORTED = :OLD_ID_SIMPORTED'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select SIMPORTED.*,'
      '  NAMEKLIENT'
      ' from SIMPORTED'
      'left outer join SKLIENT on IDKLIENT_SIMPORTED=IDKLIENT'
      ' where ID_SIMPORTED=:ID')
    AutoUpdateOptions.UpdateTableName = 'SED'
    AutoUpdateOptions.KeyFields = 'IDED'
    AutoUpdateOptions.GeneratorName = 'GEN_SED_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 88
    object ElementID_SIMPORTED: TFIBBCDField
      FieldName = 'ID_SIMPORTED'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_SIMPORTED: TFIBBCDField
      FieldName = 'IDBASE_SIMPORTED'
      Size = 0
      RoundByScale = True
    end
    object ElementIDNOM_SIMPORTED: TFIBBCDField
      FieldName = 'IDNOM_SIMPORTED'
      Size = 0
      RoundByScale = True
    end
    object ElementIDKLIENT_SIMPORTED: TFIBBCDField
      FieldName = 'IDKLIENT_SIMPORTED'
      Size = 0
      RoundByScale = True
    end
    object ElementIDED_SIMPORTED: TFIBBCDField
      FieldName = 'IDED_SIMPORTED'
      Size = 0
      RoundByScale = True
    end
    object ElementBARCODE_SIMPORTED: TFIBWideStringField
      FieldName = 'BARCODE_SIMPORTED'
      Size = 13
    end
    object ElementCODE_SIMPORTED: TFIBWideStringField
      FieldName = 'CODE_SIMPORTED'
      Size = 10
    end
    object ElementNAME_SIMPORTED: TFIBWideStringField
      FieldName = 'NAME_SIMPORTED'
      Size = 100
    end
    object ElementNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
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
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 344
    Top = 88
    qoStartTransaction = True
  end
end
