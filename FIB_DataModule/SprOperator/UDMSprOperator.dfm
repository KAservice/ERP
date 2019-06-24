object DMSprOperator: TDMSprOperator
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
      'select sproducer.*,'
      '    sklient.nameklient,'
      '    sklient.innklient'
      'from sproducer'
      
        'left outer join sklient on sproducer.idklient_sproducer=sklient.' +
        'idklient')
    Transaction = IBTr
    Left = 144
    Top = 16
    poUseLargeIntField = True
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_SPRODUCER: TFIBLargeIntField
      FieldName = 'ID_SPRODUCER'
    end
    object TableIDBASE_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDBASE_SPRODUCER'
    end
    object TableGID_SPRODUCER: TFIBWideStringField
      FieldName = 'GID_SPRODUCER'
      Size = 10
    end
    object TableNAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
      Size = 200
    end
    object TableIDKLIENT_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDKLIENT_SPRODUCER'
    end
    object TableNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object TableINNKLIENT: TFIBWideStringField
      FieldName = 'INNKLIENT'
      Size = 12
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPRODUCER'
      'SET '
      '    IDBASE_SPRODUCER = :IDBASE_SPRODUCER,'
      '    GID_SPRODUCER = :GID_SPRODUCER,'
      '    NAME_SPRODUCER = :NAME_SPRODUCER,'
      '    IDKLIENT_SPRODUCER = :IDKLIENT_SPRODUCER,'
      '    IDPOST_ZIP_SPRODUCER = :IDPOST_ZIP_SPRODUCER'
      'WHERE'
      '    ID_SPRODUCER = :OLD_ID_SPRODUCER'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRODUCER'
      'WHERE'
      '        ID_SPRODUCER = :OLD_ID_SPRODUCER'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRODUCER('
      '    ID_SPRODUCER,'
      '    IDBASE_SPRODUCER,'
      '    GID_SPRODUCER,'
      '    NAME_SPRODUCER,'
      '    IDKLIENT_SPRODUCER,'
      '    IDPOST_ZIP_SPRODUCER'
      ')'
      'VALUES('
      '    :ID_SPRODUCER,'
      '    :IDBASE_SPRODUCER,'
      '    :GID_SPRODUCER,'
      '    :NAME_SPRODUCER,'
      '    :IDKLIENT_SPRODUCER,'
      '    :IDPOST_ZIP_SPRODUCER'
      ')')
    RefreshSQL.Strings = (
      'select sproducer.*,'
      '       sklient.nameklient,'
      '       post_zip.nameklient  as post_zip_name'
      'from sproducer'
      
        'left outer join sklient on sproducer.idklient_sproducer=sklient.' +
        'idklient'
      
        'left outer join sklient as post_zip on sproducer.idpost_zip_spro' +
        'ducer=post_zip.idklient'
      'where(  sproducer.id_sproducer=:PARAM_ID'
      '     ) and (     SPRODUCER.ID_SPRODUCER = :OLD_ID_SPRODUCER'
      '     )'
      '    '
      '')
    SelectSQL.Strings = (
      'select sproducer.*,'
      '       sklient.nameklient,'
      '       post_zip.nameklient  as post_zip_name'
      'from sproducer'
      
        'left outer join sklient on sproducer.idklient_sproducer=sklient.' +
        'idklient'
      
        'left outer join sklient as post_zip on sproducer.idpost_zip_spro' +
        'ducer=post_zip.idklient'
      'where sproducer.id_sproducer=:PARAM_ID'
      '')
    AutoUpdateOptions.UpdateTableName = 'SPRODUCER'
    AutoUpdateOptions.KeyFields = 'ID_SPRODUCER'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRODUCER_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    poUseLargeIntField = True
    object ElementID_SPRODUCER: TFIBLargeIntField
      FieldName = 'ID_SPRODUCER'
    end
    object ElementIDBASE_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDBASE_SPRODUCER'
    end
    object ElementGID_SPRODUCER: TFIBWideStringField
      FieldName = 'GID_SPRODUCER'
      Size = 10
    end
    object ElementNAME_SPRODUCER: TFIBWideStringField
      FieldName = 'NAME_SPRODUCER'
      Size = 200
    end
    object ElementIDKLIENT_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDKLIENT_SPRODUCER'
    end
    object ElementNAMEKLIENT: TFIBWideStringField
      FieldName = 'NAMEKLIENT'
      Size = 200
    end
    object ElementIDPOST_ZIP_SPRODUCER: TFIBLargeIntField
      FieldName = 'IDPOST_ZIP_SPRODUCER'
    end
    object ElementPOST_ZIP_NAME: TFIBWideStringField
      FieldName = 'POST_ZIP_NAME'
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
