object DMSprImportNom: TDMSprImportNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 276
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
      'select * from SIMPORTNOM where IDNOM_SIMPORTNOM=:IDNOM')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 8
    object TableID_SIMPORTNOM: TFIBBCDField
      FieldName = 'ID_SIMPORTNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_SIMPORTNOM: TFIBBCDField
      FieldName = 'IDBASE_SIMPORTNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOM_SIMPORTNOM: TFIBBCDField
      FieldName = 'IDNOM_SIMPORTNOM'
      Size = 0
      RoundByScale = True
    end
    object TableIDKLIENT_SIMPORTNOM: TFIBBCDField
      FieldName = 'IDKLIENT_SIMPORTNOM'
      Size = 0
      RoundByScale = True
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableCODE_SIMPORTNOM: TFIBWideStringField
      FieldName = 'CODE_SIMPORTNOM'
      Size = 10
    end
    object TableART_SIMPORTNOM: TFIBWideStringField
      FieldName = 'ART_SIMPORTNOM'
    end
    object TableNAME_SIMPORTNOM: TFIBWideStringField
      FieldName = 'NAME_SIMPORTNOM'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SIMPORTNOM'
      'SET '
      '    IDBASE_SIMPORTNOM = :IDBASE_SIMPORTNOM,'
      '    IDNOM_SIMPORTNOM = :IDNOM_SIMPORTNOM,'
      '    IDKLIENT_SIMPORTNOM = :IDKLIENT_SIMPORTNOM,'
      '    CODE_SIMPORTNOM = :CODE_SIMPORTNOM,'
      '    ART_SIMPORTNOM = :ART_SIMPORTNOM,'
      '    NAME_SIMPORTNOM = :NAME_SIMPORTNOM'
      'WHERE'
      '    ID_SIMPORTNOM = :OLD_ID_SIMPORTNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SIMPORTNOM'
      'WHERE'
      '        ID_SIMPORTNOM = :OLD_ID_SIMPORTNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SIMPORTNOM('
      '    ID_SIMPORTNOM,'
      '    IDBASE_SIMPORTNOM,'
      '    IDNOM_SIMPORTNOM,'
      '    IDKLIENT_SIMPORTNOM,'
      '    CODE_SIMPORTNOM,'
      '    ART_SIMPORTNOM,'
      '    NAME_SIMPORTNOM'
      ')'
      'VALUES('
      '    :ID_SIMPORTNOM,'
      '    :IDBASE_SIMPORTNOM,'
      '    :IDNOM_SIMPORTNOM,'
      '    :IDKLIENT_SIMPORTNOM,'
      '    :CODE_SIMPORTNOM,'
      '    :ART_SIMPORTNOM,'
      '    :NAME_SIMPORTNOM'
      ')')
    RefreshSQL.Strings = (
      'select SIMPORTNOM.*,'
      '  NAMEKLIENT'
      ' from SIMPORTNOM'
      'left outer join SKLIENT on IDKLIENT_SIMPORTNOM=IDKLIENT'
      ' where(  ID_SIMPORTNOM=:ID'
      '     ) and (     SIMPORTNOM.ID_SIMPORTNOM = :OLD_ID_SIMPORTNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select SIMPORTNOM.*,'
      '  NAMEKLIENT'
      ' from SIMPORTNOM'
      'left outer join SKLIENT on IDKLIENT_SIMPORTNOM=IDKLIENT'
      ' where ID_SIMPORTNOM=:ID')
    AutoUpdateOptions.UpdateTableName = 'SIMPORTNOM'
    AutoUpdateOptions.KeyFields = 'ID_SIMPORTNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_SIMPORTNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 88
    poCanEditComputedFields = True
    object ElementID_SIMPORTNOM: TFIBBCDField
      FieldName = 'ID_SIMPORTNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_SIMPORTNOM: TFIBBCDField
      FieldName = 'IDBASE_SIMPORTNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDNOM_SIMPORTNOM: TFIBBCDField
      FieldName = 'IDNOM_SIMPORTNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementIDKLIENT_SIMPORTNOM: TFIBBCDField
      FieldName = 'IDKLIENT_SIMPORTNOM'
      Size = 0
      RoundByScale = True
    end
    object ElementCODE_SIMPORTNOM: TFIBWideStringField
      FieldName = 'CODE_SIMPORTNOM'
      Size = 10
    end
    object ElementART_SIMPORTNOM: TFIBWideStringField
      FieldName = 'ART_SIMPORTNOM'
    end
    object ElementNAME_SIMPORTNOM: TFIBWideStringField
      FieldName = 'NAME_SIMPORTNOM'
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
    qoTrimCharFields = True
  end
  object pFIBDataSet1: TpFIBDataSet
    Transaction = IBTr
    Left = 160
    Top = 168
  end
end
