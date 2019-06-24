object DMSprImportSet: TDMSprImportSet
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 231
  Width = 363
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 40
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 40
    Top = 96
  end
  object Table: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SIMPORTSET'
      'SET '
      '    IDBASE_SIMPORTSET = :IDBASE_SIMPORTSET,'
      '    NAME_SIMPORTSET = :NAME_SIMPORTSET,'
      '    TYPE_SEARCH_SIMPORTSET = :TYPE_SEARCH_SIMPORTSET,'
      '    TYPE_OBR_SIMPORTSET = :TYPE_OBR_SIMPORTSET,'
      '    STRPAR_SIMPORTSET = :STRPAR_SIMPORTSET,'
      '    DIR_SIMPORTSET = :DIR_SIMPORTSET'
      'WHERE'
      '    ID_SIMPORTSET = :OLD_ID_SIMPORTSET'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SIMPORTSET'
      'WHERE'
      '        ID_SIMPORTSET = :OLD_ID_SIMPORTSET'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SIMPORTSET('
      '    ID_SIMPORTSET,'
      '    IDBASE_SIMPORTSET,'
      '    NAME_SIMPORTSET,'
      '    TYPE_SEARCH_SIMPORTSET,'
      '    TYPE_OBR_SIMPORTSET,'
      '    STRPAR_SIMPORTSET,'
      '    DIR_SIMPORTSET'
      ')'
      'VALUES('
      '    :ID_SIMPORTSET,'
      '    :IDBASE_SIMPORTSET,'
      '    :NAME_SIMPORTSET,'
      '    :TYPE_SEARCH_SIMPORTSET,'
      '    :TYPE_OBR_SIMPORTSET,'
      '    :STRPAR_SIMPORTSET,'
      '    :DIR_SIMPORTSET'
      ')')
    RefreshSQL.Strings = (
      'select  * from SIMPORTSET'
      ''
      ' WHERE '
      '        SIMPORTSET.ID_SIMPORTSET = :OLD_ID_SIMPORTSET'
      '    ')
    SelectSQL.Strings = (
      'select  * from SIMPORTSET')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 152
    Top = 16
    object TableID_SIMPORTSET: TFIBBCDField
      FieldName = 'ID_SIMPORTSET'
      Size = 0
      RoundByScale = True
    end
    object TableIDBASE_SIMPORTSET: TFIBBCDField
      FieldName = 'IDBASE_SIMPORTSET'
      Size = 0
      RoundByScale = True
    end
    object TableTYPE_SEARCH_SIMPORTSET: TFIBSmallIntField
      FieldName = 'TYPE_SEARCH_SIMPORTSET'
    end
    object TableTYPE_OBR_SIMPORTSET: TFIBSmallIntField
      FieldName = 'TYPE_OBR_SIMPORTSET'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableNAME_SIMPORTSET: TFIBWideStringField
      FieldName = 'NAME_SIMPORTSET'
      Size = 100
    end
    object TableSTRPAR_SIMPORTSET: TFIBWideStringField
      FieldName = 'STRPAR_SIMPORTSET'
      Size = 1000
    end
    object TableDIR_SIMPORTSET: TFIBWideStringField
      FieldName = 'DIR_SIMPORTSET'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SIMPORTSET'
      'SET '
      '    IDBASE_SIMPORTSET = :IDBASE_SIMPORTSET,'
      '    NAME_SIMPORTSET = :NAME_SIMPORTSET,'
      '    TYPE_SEARCH_SIMPORTSET = :TYPE_SEARCH_SIMPORTSET,'
      '    TYPE_OBR_SIMPORTSET = :TYPE_OBR_SIMPORTSET,'
      '    STRPAR_SIMPORTSET = :STRPAR_SIMPORTSET,'
      '    DIR_SIMPORTSET = :DIR_SIMPORTSET'
      'WHERE'
      '    ID_SIMPORTSET = :OLD_ID_SIMPORTSET'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SIMPORTSET'
      'WHERE'
      '        ID_SIMPORTSET = :OLD_ID_SIMPORTSET'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SIMPORTSET('
      '    ID_SIMPORTSET,'
      '    IDBASE_SIMPORTSET,'
      '    NAME_SIMPORTSET,'
      '    TYPE_SEARCH_SIMPORTSET,'
      '    TYPE_OBR_SIMPORTSET,'
      '    STRPAR_SIMPORTSET,'
      '    DIR_SIMPORTSET'
      ')'
      'VALUES('
      '    :ID_SIMPORTSET,'
      '    :IDBASE_SIMPORTSET,'
      '    :NAME_SIMPORTSET,'
      '    :TYPE_SEARCH_SIMPORTSET,'
      '    :TYPE_OBR_SIMPORTSET,'
      '    :STRPAR_SIMPORTSET,'
      '    :DIR_SIMPORTSET'
      ')')
    RefreshSQL.Strings = (
      'select * from SIMPORTSET where(  ID_SIMPORTSET=:ID'
      '     ) and (     SIMPORTSET.ID_SIMPORTSET = :OLD_ID_SIMPORTSET'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SIMPORTSET where ID_SIMPORTSET=:ID')
    AutoUpdateOptions.UpdateTableName = 'SIMPORTSET'
    AutoUpdateOptions.KeyFields = 'ID_SIMPORTSET'
    AutoUpdateOptions.GeneratorName = 'GEN_SIMPORTSET_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 152
    Top = 96
    object ElementID_SIMPORTSET: TFIBBCDField
      FieldName = 'ID_SIMPORTSET'
      Size = 0
      RoundByScale = True
    end
    object ElementIDBASE_SIMPORTSET: TFIBBCDField
      FieldName = 'IDBASE_SIMPORTSET'
      Size = 0
      RoundByScale = True
    end
    object ElementTYPE_SEARCH_SIMPORTSET: TFIBSmallIntField
      FieldName = 'TYPE_SEARCH_SIMPORTSET'
    end
    object ElementTYPE_OBR_SIMPORTSET: TFIBSmallIntField
      FieldName = 'TYPE_OBR_SIMPORTSET'
    end
    object ElementNAME_SIMPORTSET: TFIBWideStringField
      FieldName = 'NAME_SIMPORTSET'
      Size = 100
    end
    object ElementSTRPAR_SIMPORTSET: TFIBWideStringField
      FieldName = 'STRPAR_SIMPORTSET'
      Size = 1000
    end
    object ElementDIR_SIMPORTSET: TFIBWideStringField
      FieldName = 'DIR_SIMPORTSET'
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
    Top = 96
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 152
    Top = 160
    qoStartTransaction = True
  end
end
