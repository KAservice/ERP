object DMSprTypeNom: TDMSprTypeNom
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
      'select stnom.*'
      'from stnom')
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_STNOM: TFIBLargeIntField
      FieldName = 'ID_STNOM'
    end
    object TableIDBASE_STNOM: TFIBLargeIntField
      FieldName = 'IDBASE_STNOM'
    end
    object TableNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE STNOM'
      'SET '
      '    IDBASE_STNOM = :IDBASE_STNOM,'
      '    NAME_STNOM = :NAME_STNOM'
      'WHERE'
      '    ID_STNOM = :OLD_ID_STNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    STNOM'
      'WHERE'
      '        ID_STNOM = :OLD_ID_STNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO STNOM('
      '    ID_STNOM,'
      '    IDBASE_STNOM,'
      '    NAME_STNOM'
      ')'
      'VALUES('
      '    :ID_STNOM,'
      '    :IDBASE_STNOM,'
      '    :NAME_STNOM'
      ')')
    RefreshSQL.Strings = (
      'select stnom.*'
      'from stnom'
      'where(  stnom.id_stnom=:PARAM_ID'
      '     ) and (     STNOM.ID_STNOM = :OLD_ID_STNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select stnom.*'
      'from stnom'
      'where stnom.id_stnom=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'STNOM'
    AutoUpdateOptions.KeyFields = 'ID_STNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_STNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_STNOM: TFIBLargeIntField
      FieldName = 'ID_STNOM'
    end
    object ElementIDBASE_STNOM: TFIBLargeIntField
      FieldName = 'IDBASE_STNOM'
    end
    object ElementNAME_STNOM: TFIBWideStringField
      FieldName = 'NAME_STNOM'
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
    Left = 280
    Top = 56
    qoStartTransaction = True
  end
end
