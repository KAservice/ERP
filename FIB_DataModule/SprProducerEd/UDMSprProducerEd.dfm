object DMSprProducerEd: TDMSprProducerEd
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 216
  Width = 836
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
      'select * from spred where spred.idprnom_spred=:PARAM_IDPRNOM')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 8
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SPRED: TFIBLargeIntField
      FieldName = 'ID_SPRED'
    end
    object TableIDBASE_SPRED: TFIBLargeIntField
      FieldName = 'IDBASE_SPRED'
    end
    object TableGID_SPRED: TFIBWideStringField
      FieldName = 'GID_SPRED'
      Size = 10
    end
    object TableIDPRNOM_SPRED: TFIBLargeIntField
      FieldName = 'IDPRNOM_SPRED'
    end
    object TableCODE_SPRED: TFIBIntegerField
      FieldName = 'CODE_SPRED'
    end
    object TableBARCODE_SPRED: TFIBWideStringField
      FieldName = 'BARCODE_SPRED'
      Size = 13
    end
    object TableKF_SPRED: TFIBBCDField
      FieldName = 'KF_SPRED'
      Size = 3
      RoundByScale = True
    end
    object TableNAME_SPRED: TFIBWideStringField
      FieldName = 'NAME_SPRED'
      Size = 200
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPRED'
      'SET '
      '    IDBASE_SPRED = :IDBASE_SPRED,'
      '    GID_SPRED = :GID_SPRED,'
      '    IDPRNOM_SPRED = :IDPRNOM_SPRED,'
      '    CODE_SPRED = :CODE_SPRED,'
      '    BARCODE_SPRED = :BARCODE_SPRED,'
      '    KF_SPRED = :KF_SPRED,'
      '    NAME_SPRED = :NAME_SPRED'
      'WHERE'
      '    ID_SPRED = :OLD_ID_SPRED'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRED'
      'WHERE'
      '        ID_SPRED = :OLD_ID_SPRED'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRED('
      '    ID_SPRED,'
      '    IDBASE_SPRED,'
      '    GID_SPRED,'
      '    IDPRNOM_SPRED,'
      '    CODE_SPRED,'
      '    BARCODE_SPRED,'
      '    KF_SPRED,'
      '    NAME_SPRED'
      ')'
      'VALUES('
      '    :ID_SPRED,'
      '    :IDBASE_SPRED,'
      '    :GID_SPRED,'
      '    :IDPRNOM_SPRED,'
      '    :CODE_SPRED,'
      '    :BARCODE_SPRED,'
      '    :KF_SPRED,'
      '    :NAME_SPRED'
      ')')
    RefreshSQL.Strings = (
      'select spred.*'
      ' from spred'
      ' where(  spred.id_spred=:PARAM_ID'
      '     ) and (     SPRED.ID_SPRED = :OLD_ID_SPRED'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select spred.*'
      ' from spred'
      ' where spred.id_spred=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPRED'
    AutoUpdateOptions.KeyFields = 'ID_SPRED'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRED_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 88
    poUseLargeIntField = True
    object ElementID_SPRED: TFIBLargeIntField
      FieldName = 'ID_SPRED'
    end
    object ElementIDBASE_SPRED: TFIBLargeIntField
      FieldName = 'IDBASE_SPRED'
    end
    object ElementGID_SPRED: TFIBWideStringField
      FieldName = 'GID_SPRED'
      Size = 10
    end
    object ElementIDPRNOM_SPRED: TFIBLargeIntField
      FieldName = 'IDPRNOM_SPRED'
    end
    object ElementCODE_SPRED: TFIBIntegerField
      FieldName = 'CODE_SPRED'
    end
    object ElementBARCODE_SPRED: TFIBWideStringField
      FieldName = 'BARCODE_SPRED'
      Size = 13
    end
    object ElementKF_SPRED: TFIBBCDField
      FieldName = 'KF_SPRED'
      Size = 3
      RoundByScale = True
    end
    object ElementNAME_SPRED: TFIBWideStringField
      FieldName = 'NAME_SPRED'
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
