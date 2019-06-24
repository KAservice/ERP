object DMSprPropertiesValuesList: TDMSprPropertiesValuesList
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 283
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
      
        'select * from spropvaluelist where spropvaluelist.idprop_spropva' +
        'luelist=:PARAM_IDPROP')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 8
    poUseLargeIntField = True
    object TableID_SPROPVALUELIST: TFIBLargeIntField
      FieldName = 'ID_SPROPVALUELIST'
    end
    object TableIDBASE_SPROPVALUELIST: TFIBLargeIntField
      FieldName = 'IDBASE_SPROPVALUELIST'
    end
    object TableGID_SPROPVALUELIST: TFIBWideStringField
      FieldName = 'GID_SPROPVALUELIST'
      Size = 10
    end
    object TableIDPROP_SPROPVALUELIST: TFIBLargeIntField
      FieldName = 'IDPROP_SPROPVALUELIST'
    end
    object TableNAME_SPROPVALUELIST: TFIBWideStringField
      FieldName = 'NAME_SPROPVALUELIST'
      Size = 200
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPROPVALUELIST'
      'SET '
      '    IDBASE_SPROPVALUELIST = :IDBASE_SPROPVALUELIST,'
      '    GID_SPROPVALUELIST = :GID_SPROPVALUELIST,'
      '    IDPROP_SPROPVALUELIST = :IDPROP_SPROPVALUELIST,'
      '    NAME_SPROPVALUELIST = :NAME_SPROPVALUELIST'
      'WHERE'
      '    ID_SPROPVALUELIST = :OLD_ID_SPROPVALUELIST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPROPVALUELIST'
      'WHERE'
      '        ID_SPROPVALUELIST = :OLD_ID_SPROPVALUELIST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPROPVALUELIST('
      '    ID_SPROPVALUELIST,'
      '    IDBASE_SPROPVALUELIST,'
      '    GID_SPROPVALUELIST,'
      '    IDPROP_SPROPVALUELIST,'
      '    NAME_SPROPVALUELIST'
      ')'
      'VALUES('
      '    :ID_SPROPVALUELIST,'
      '    :IDBASE_SPROPVALUELIST,'
      '    :GID_SPROPVALUELIST,'
      '    :IDPROP_SPROPVALUELIST,'
      '    :NAME_SPROPVALUELIST'
      ')')
    RefreshSQL.Strings = (
      'select spropvaluelist.*'
      ' from spropvaluelist'
      ' where(  spropvaluelist.id_spropvaluelist=:PARAM_ID'
      
        '     ) and (     SPROPVALUELIST.ID_SPROPVALUELIST = :OLD_ID_SPRO' +
        'PVALUELIST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select spropvaluelist.*'
      ' from spropvaluelist'
      ' where spropvaluelist.id_spropvaluelist=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPROPVALUELIST'
    AutoUpdateOptions.KeyFields = 'ID_SPROPVALUELIST'
    AutoUpdateOptions.GeneratorName = 'GEN_SPROPVALUELIST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 88
    poUseLargeIntField = True
    object ElementID_SPROPVALUELIST: TFIBLargeIntField
      FieldName = 'ID_SPROPVALUELIST'
    end
    object ElementIDBASE_SPROPVALUELIST: TFIBLargeIntField
      FieldName = 'IDBASE_SPROPVALUELIST'
    end
    object ElementGID_SPROPVALUELIST: TFIBWideStringField
      FieldName = 'GID_SPROPVALUELIST'
      Size = 10
    end
    object ElementIDPROP_SPROPVALUELIST: TFIBLargeIntField
      FieldName = 'IDPROP_SPROPVALUELIST'
    end
    object ElementNAME_SPROPVALUELIST: TFIBWideStringField
      FieldName = 'NAME_SPROPVALUELIST'
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
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 344
    Top = 88
    qoStartTransaction = True
  end
end
