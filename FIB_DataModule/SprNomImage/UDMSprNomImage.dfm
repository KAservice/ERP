object DMSprNomImage: TDMSprNomImage
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 327
  Width = 371
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 56
    Top = 8
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 56
    Top = 64
  end
  object Table: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE SNOMIMAGE'
      'SET '
      '    IDBASE_SNOMIMAGE = :IDBASE_SNOMIMAGE,'
      '    GID_SNOMIMAGE = :GID_SNOMIMAGE,'
      '    IDVIDIMAGE_SNOMIMAGE = :IDVIDIMAGE_SNOMIMAGE,'
      '    IDNOM_SNOMIMAGE = :IDNOM_SNOMIMAGE,'
      '    NAME_SNOMIMAGE = :NAME_SNOMIMAGE,'
      '    BODY_SNOMIMAGE = :BODY_SNOMIMAGE,'
      '    BODY_SMALL_SNOMIMAGE = :BODY_SMALL_SNOMIMAGE,'
      '    INDEX_SNOMIMAGE = :INDEX_SNOMIMAGE'
      'WHERE'
      '    ID_SNOMIMAGE = :OLD_ID_SNOMIMAGE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNOMIMAGE'
      'WHERE'
      '        ID_SNOMIMAGE = :OLD_ID_SNOMIMAGE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNOMIMAGE('
      '    ID_SNOMIMAGE,'
      '    IDBASE_SNOMIMAGE,'
      '    GID_SNOMIMAGE,'
      '    IDVIDIMAGE_SNOMIMAGE,'
      '    IDNOM_SNOMIMAGE,'
      '    NAME_SNOMIMAGE,'
      '    BODY_SNOMIMAGE,'
      '    BODY_SMALL_SNOMIMAGE,'
      '    INDEX_SNOMIMAGE'
      ')'
      'VALUES('
      '    :ID_SNOMIMAGE,'
      '    :IDBASE_SNOMIMAGE,'
      '    :GID_SNOMIMAGE,'
      '    :IDVIDIMAGE_SNOMIMAGE,'
      '    :IDNOM_SNOMIMAGE,'
      '    :NAME_SNOMIMAGE,'
      '    :BODY_SNOMIMAGE,'
      '    :BODY_SMALL_SNOMIMAGE,'
      '    :INDEX_SNOMIMAGE'
      ')')
    RefreshSQL.Strings = (
      'select snomimage.*,'
      '    svidimage.name_svidimage'
      'from snomimage'
      
        'left outer join svidimage on svidimage.id_svidimage=snomimage.id' +
        'vidimage_snomimage'
      'where(  snomimage.idnom_snomimage=:PARAM_IDNOM'
      '     ) and (     SNOMIMAGE.ID_SNOMIMAGE = :OLD_ID_SNOMIMAGE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select snomimage.*,'
      '    svidimage.name_svidimage'
      'from snomimage'
      
        'left outer join svidimage on svidimage.id_svidimage=snomimage.id' +
        'vidimage_snomimage'
      'where snomimage.idnom_snomimage=:PARAM_IDNOM'
      'order by snomimage.index_snomimage')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_SNOMIMAGE: TFIBLargeIntField
      FieldName = 'ID_SNOMIMAGE'
    end
    object TableIDBASE_SNOMIMAGE: TFIBLargeIntField
      FieldName = 'IDBASE_SNOMIMAGE'
    end
    object TableGID_SNOMIMAGE: TFIBWideStringField
      FieldName = 'GID_SNOMIMAGE'
      Size = 10
    end
    object TableIDVIDIMAGE_SNOMIMAGE: TFIBLargeIntField
      FieldName = 'IDVIDIMAGE_SNOMIMAGE'
    end
    object TableIDNOM_SNOMIMAGE: TFIBLargeIntField
      FieldName = 'IDNOM_SNOMIMAGE'
    end
    object TableNAME_SNOMIMAGE: TFIBWideStringField
      FieldName = 'NAME_SNOMIMAGE'
      Size = 200
    end
    object TableBODY_SNOMIMAGE: TFIBBlobField
      FieldName = 'BODY_SNOMIMAGE'
      Size = 8
    end
    object TableBODY_SMALL_SNOMIMAGE: TFIBBlobField
      FieldName = 'BODY_SMALL_SNOMIMAGE'
      Size = 8
    end
    object TableNAME_SVIDIMAGE: TFIBWideStringField
      FieldName = 'NAME_SVIDIMAGE'
      Size = 200
    end
    object TableINDEX_SNOMIMAGE: TFIBIntegerField
      FieldName = 'INDEX_SNOMIMAGE'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SNOMIMAGE'
      'SET '
      '    IDBASE_SNOMIMAGE = :IDBASE_SNOMIMAGE,'
      '    GID_SNOMIMAGE = :GID_SNOMIMAGE,'
      '    IDVIDIMAGE_SNOMIMAGE = :IDVIDIMAGE_SNOMIMAGE,'
      '    IDNOM_SNOMIMAGE = :IDNOM_SNOMIMAGE,'
      '    NAME_SNOMIMAGE = :NAME_SNOMIMAGE,'
      '    BODY_SNOMIMAGE = :BODY_SNOMIMAGE,'
      '    BODY_SMALL_SNOMIMAGE = :BODY_SMALL_SNOMIMAGE,'
      '    INDEX_SNOMIMAGE = :INDEX_SNOMIMAGE'
      'WHERE'
      '    ID_SNOMIMAGE = :OLD_ID_SNOMIMAGE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNOMIMAGE'
      'WHERE'
      '        ID_SNOMIMAGE = :OLD_ID_SNOMIMAGE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNOMIMAGE('
      '    ID_SNOMIMAGE,'
      '    IDBASE_SNOMIMAGE,'
      '    GID_SNOMIMAGE,'
      '    IDVIDIMAGE_SNOMIMAGE,'
      '    IDNOM_SNOMIMAGE,'
      '    NAME_SNOMIMAGE,'
      '    BODY_SNOMIMAGE,'
      '    BODY_SMALL_SNOMIMAGE,'
      '    INDEX_SNOMIMAGE'
      ')'
      'VALUES('
      '    :ID_SNOMIMAGE,'
      '    :IDBASE_SNOMIMAGE,'
      '    :GID_SNOMIMAGE,'
      '    :IDVIDIMAGE_SNOMIMAGE,'
      '    :IDNOM_SNOMIMAGE,'
      '    :NAME_SNOMIMAGE,'
      '    :BODY_SNOMIMAGE,'
      '    :BODY_SMALL_SNOMIMAGE,'
      '    :INDEX_SNOMIMAGE'
      ')')
    RefreshSQL.Strings = (
      'select snomimage.*,'
      '    svidimage.name_svidimage'
      'from snomimage'
      
        'left outer join svidimage on svidimage.id_svidimage=snomimage.id' +
        'vidimage_snomimage'
      'where(  snomimage.id_snomimage=:PARAM_ID'
      '     ) and (     SNOMIMAGE.ID_SNOMIMAGE = :OLD_ID_SNOMIMAGE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select snomimage.*,'
      '    svidimage.name_svidimage'
      'from snomimage'
      
        'left outer join svidimage on svidimage.id_svidimage=snomimage.id' +
        'vidimage_snomimage'
      'where snomimage.id_snomimage=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SNOMIMAGE'
    AutoUpdateOptions.KeyFields = 'ID_SNOMIMAGE'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOMIMAGE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_SNOMIMAGE: TFIBLargeIntField
      FieldName = 'ID_SNOMIMAGE'
    end
    object ElementIDBASE_SNOMIMAGE: TFIBLargeIntField
      FieldName = 'IDBASE_SNOMIMAGE'
    end
    object ElementGID_SNOMIMAGE: TFIBWideStringField
      FieldName = 'GID_SNOMIMAGE'
      Size = 10
    end
    object ElementIDVIDIMAGE_SNOMIMAGE: TFIBLargeIntField
      FieldName = 'IDVIDIMAGE_SNOMIMAGE'
    end
    object ElementIDNOM_SNOMIMAGE: TFIBLargeIntField
      FieldName = 'IDNOM_SNOMIMAGE'
    end
    object ElementNAME_SNOMIMAGE: TFIBWideStringField
      FieldName = 'NAME_SNOMIMAGE'
      Size = 200
    end
    object ElementBODY_SNOMIMAGE: TFIBBlobField
      FieldName = 'BODY_SNOMIMAGE'
      Size = 8
    end
    object ElementBODY_SMALL_SNOMIMAGE: TFIBBlobField
      FieldName = 'BODY_SMALL_SNOMIMAGE'
      Size = 8
    end
    object ElementNAME_SVIDIMAGE: TFIBWideStringField
      FieldName = 'NAME_SVIDIMAGE'
      Size = 200
    end
    object ElementINDEX_SNOMIMAGE: TFIBIntegerField
      FieldName = 'INDEX_SNOMIMAGE'
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
    Left = 256
    Top = 64
  end
end
