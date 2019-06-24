object REM_DMZayavkaImage: TREM_DMZayavkaImage
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
    SelectSQL.Strings = (
      'select *'
      'from rem_zimage'
      'where rem_zimage.idz_rem_zimage=:PARAM_IDZ')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_REM_ZIMAGE: TFIBLargeIntField
      FieldName = 'ID_REM_ZIMAGE'
    end
    object TableIDBASE_REM_ZIMAGE: TFIBLargeIntField
      FieldName = 'IDBASE_REM_ZIMAGE'
    end
    object TableIDZ_REM_ZIMAGE: TFIBLargeIntField
      FieldName = 'IDZ_REM_ZIMAGE'
    end
    object TableNAME_REM_ZIMAGE: TFIBWideStringField
      FieldName = 'NAME_REM_ZIMAGE'
      Size = 200
    end
    object TableSHOWUSER_REM_ZIMAGE: TFIBSmallIntField
      FieldName = 'SHOWUSER_REM_ZIMAGE'
    end
    object TableIMAGE_REM_ZIMAGE: TFIBBlobField
      FieldName = 'IMAGE_REM_ZIMAGE'
      Size = 8
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE REM_ZIMAGE'
      'SET '
      '    IDBASE_REM_ZIMAGE = :IDBASE_REM_ZIMAGE,'
      '    IDZ_REM_ZIMAGE = :IDZ_REM_ZIMAGE,'
      '    NAME_REM_ZIMAGE = :NAME_REM_ZIMAGE,'
      '    SHOWUSER_REM_ZIMAGE = :SHOWUSER_REM_ZIMAGE,'
      '    IMAGE_REM_ZIMAGE = :IMAGE_REM_ZIMAGE'
      'WHERE'
      '    ID_REM_ZIMAGE = :OLD_ID_REM_ZIMAGE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    REM_ZIMAGE'
      'WHERE'
      '        ID_REM_ZIMAGE = :OLD_ID_REM_ZIMAGE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO REM_ZIMAGE('
      '    ID_REM_ZIMAGE,'
      '    IDBASE_REM_ZIMAGE,'
      '    IDZ_REM_ZIMAGE,'
      '    NAME_REM_ZIMAGE,'
      '    SHOWUSER_REM_ZIMAGE,'
      '    IMAGE_REM_ZIMAGE'
      ')'
      'VALUES('
      '    :ID_REM_ZIMAGE,'
      '    :IDBASE_REM_ZIMAGE,'
      '    :IDZ_REM_ZIMAGE,'
      '    :NAME_REM_ZIMAGE,'
      '    :SHOWUSER_REM_ZIMAGE,'
      '    :IMAGE_REM_ZIMAGE'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from rem_zimage'
      'where(  rem_zimage.id_rem_zimage=:PARAM_ID'
      '     ) and (     REM_ZIMAGE.ID_REM_ZIMAGE = :OLD_ID_REM_ZIMAGE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from rem_zimage'
      'where rem_zimage.id_rem_zimage=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'REM_ZIMAGE'
    AutoUpdateOptions.KeyFields = 'ID_REM_ZIMAGE'
    AutoUpdateOptions.GeneratorName = 'GEN_REM_ZIMAGE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_REM_ZIMAGE: TFIBLargeIntField
      FieldName = 'ID_REM_ZIMAGE'
    end
    object ElementIDBASE_REM_ZIMAGE: TFIBLargeIntField
      FieldName = 'IDBASE_REM_ZIMAGE'
    end
    object ElementIDZ_REM_ZIMAGE: TFIBLargeIntField
      FieldName = 'IDZ_REM_ZIMAGE'
    end
    object ElementNAME_REM_ZIMAGE: TFIBWideStringField
      FieldName = 'NAME_REM_ZIMAGE'
      Size = 200
    end
    object ElementSHOWUSER_REM_ZIMAGE: TFIBSmallIntField
      FieldName = 'SHOWUSER_REM_ZIMAGE'
    end
    object ElementIMAGE_REM_ZIMAGE: TFIBBlobField
      FieldName = 'IMAGE_REM_ZIMAGE'
      Size = 8
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
