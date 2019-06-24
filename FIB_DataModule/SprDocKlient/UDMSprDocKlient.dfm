object DMSprDocKlient: TDMSprDocKlient
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 158
  Width = 328
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
      
        'select * from SDOCKLIENT where IDKLIENT_SDOCKLIENT=:PARAM_IDKLIE' +
        'NT')
    OnCalcFields = TableCalcFields
    Transaction = IBTr
    Left = 160
    Top = 8
    object TableDATEVID_SDOCKLIENT: TFIBDateField
      FieldName = 'DATEVID_SDOCKLIENT'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SDOCKLIENT: TFIBBCDField
      FieldName = 'ID_SDOCKLIENT'
      Size = 0
      RoundByScale = True
    end
    object TableIDKLIENT_SDOCKLIENT: TFIBBCDField
      FieldName = 'IDKLIENT_SDOCKLIENT'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_SDOCKLIENT: TFIBWideStringField
      FieldName = 'NAME_SDOCKLIENT'
      Size = 100
    end
    object TableSER_SDOCKLIENT: TFIBWideStringField
      FieldName = 'SER_SDOCKLIENT'
      Size = 10
    end
    object TableNUM_SDOCKLIENT: TFIBWideStringField
      FieldName = 'NUM_SDOCKLIENT'
      Size = 10
    end
    object TableVID_SDOCKLIENT: TFIBWideStringField
      FieldName = 'VID_SDOCKLIENT'
      Size = 100
    end
    object TableGID_SDOCKLIENT: TFIBWideStringField
      FieldName = 'GID_SDOCKLIENT'
      Size = 10
    end
    object TableIDBASE_SDOCKLIENT: TFIBBCDField
      FieldName = 'IDBASE_SDOCKLIENT'
      Size = 0
      RoundByScale = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SDOCKLIENT'
      'SET '
      '    IDKLIENT_SDOCKLIENT = :IDKLIENT_SDOCKLIENT,'
      '    NAME_SDOCKLIENT = :NAME_SDOCKLIENT,'
      '    SER_SDOCKLIENT = :SER_SDOCKLIENT,'
      '    NUM_SDOCKLIENT = :NUM_SDOCKLIENT,'
      '    DATEVID_SDOCKLIENT = :DATEVID_SDOCKLIENT,'
      '    VID_SDOCKLIENT = :VID_SDOCKLIENT,'
      '    GID_SDOCKLIENT = :GID_SDOCKLIENT'
      'WHERE'
      '    ID_SDOCKLIENT = :OLD_ID_SDOCKLIENT'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SDOCKLIENT'
      'WHERE'
      '        ID_SDOCKLIENT = :OLD_ID_SDOCKLIENT'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SDOCKLIENT('
      '    ID_SDOCKLIENT,'
      '    IDKLIENT_SDOCKLIENT,'
      '    NAME_SDOCKLIENT,'
      '    SER_SDOCKLIENT,'
      '    NUM_SDOCKLIENT,'
      '    DATEVID_SDOCKLIENT,'
      '    VID_SDOCKLIENT,'
      '    GID_SDOCKLIENT'
      ')'
      'VALUES('
      '    :ID_SDOCKLIENT,'
      '    :IDKLIENT_SDOCKLIENT,'
      '    :NAME_SDOCKLIENT,'
      '    :SER_SDOCKLIENT,'
      '    :NUM_SDOCKLIENT,'
      '    :DATEVID_SDOCKLIENT,'
      '    :VID_SDOCKLIENT,'
      '    :GID_SDOCKLIENT'
      ')')
    RefreshSQL.Strings = (
      'select * from SDOCKLIENT where(  ID_SDOCKLIENT=:PARAM_ID'
      '     ) and (     SDOCKLIENT.ID_SDOCKLIENT = :OLD_ID_SDOCKLIENT'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from SDOCKLIENT where ID_SDOCKLIENT=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SDOCKLIENT'
    AutoUpdateOptions.KeyFields = 'ID_SDOCKLIENT'
    AutoUpdateOptions.GeneratorName = 'GEN_SDOCKLIENT_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 80
    object ElementDATEVID_SDOCKLIENT: TFIBDateField
      FieldName = 'DATEVID_SDOCKLIENT'
    end
    object ElementID_SDOCKLIENT: TFIBBCDField
      FieldName = 'ID_SDOCKLIENT'
      Size = 0
      RoundByScale = True
    end
    object ElementIDKLIENT_SDOCKLIENT: TFIBBCDField
      FieldName = 'IDKLIENT_SDOCKLIENT'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_SDOCKLIENT: TFIBWideStringField
      FieldName = 'NAME_SDOCKLIENT'
      Size = 100
    end
    object ElementSER_SDOCKLIENT: TFIBWideStringField
      FieldName = 'SER_SDOCKLIENT'
      Size = 10
    end
    object ElementNUM_SDOCKLIENT: TFIBWideStringField
      FieldName = 'NUM_SDOCKLIENT'
      Size = 10
    end
    object ElementVID_SDOCKLIENT: TFIBWideStringField
      FieldName = 'VID_SDOCKLIENT'
      Size = 100
    end
    object ElementGID_SDOCKLIENT: TFIBWideStringField
      FieldName = 'GID_SDOCKLIENT'
      Size = 10
    end
    object ElementIDBASE_SDOCKLIENT: TFIBBCDField
      FieldName = 'IDBASE_SDOCKLIENT'
      Size = 0
      RoundByScale = True
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
    Left = 256
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
    Left = 256
    Top = 80
  end
end
