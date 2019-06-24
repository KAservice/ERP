object DMSprProduce: TDMSprProduce
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 189
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
      'from sproduce'
      'ORDER BY sproduce.name_sproduce')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_SPRODUCE: TFIBLargeIntField
      FieldName = 'ID_SPRODUCE'
    end
    object TableGID_SPRODUCE: TFIBWideStringField
      FieldName = 'GID_SPRODUCE'
      Size = 10
    end
    object TableIDBASE_SPRODUCE: TFIBLargeIntField
      FieldName = 'IDBASE_SPRODUCE'
    end
    object TableIDGRP_SPRODUCE: TFIBLargeIntField
      FieldName = 'IDGRP_SPRODUCE'
    end
    object TableNAME_SPRODUCE: TFIBWideStringField
      FieldName = 'NAME_SPRODUCE'
      Size = 200
    end
    object TableCODE_SPRODUCE: TFIBWideStringField
      FieldName = 'CODE_SPRODUCE'
      Size = 10
    end
    object TableBELKI_SPRODUCE: TFIBBCDField
      FieldName = 'BELKI_SPRODUCE'
      Size = 3
      RoundByScale = True
    end
    object TableGIRI_SPRODUCE: TFIBBCDField
      FieldName = 'GIRI_SPRODUCE'
      Size = 3
      RoundByScale = True
    end
    object TableUGL_SPRODUCE: TFIBBCDField
      FieldName = 'UGL_SPRODUCE'
      Size = 3
      RoundByScale = True
    end
    object TableCOMMENT_SPRODUCE: TFIBWideStringField
      FieldName = 'COMMENT_SPRODUCE'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SPRODUCE'
      'SET '
      '    GID_SPRODUCE = :GID_SPRODUCE,'
      '    IDBASE_SPRODUCE = :IDBASE_SPRODUCE,'
      '    IDGRP_SPRODUCE = :IDGRP_SPRODUCE,'
      '    NAME_SPRODUCE = :NAME_SPRODUCE,'
      '    CODE_SPRODUCE = :CODE_SPRODUCE,'
      '    BELKI_SPRODUCE = :BELKI_SPRODUCE,'
      '    GIRI_SPRODUCE = :GIRI_SPRODUCE,'
      '    UGL_SPRODUCE = :UGL_SPRODUCE,'
      '    COMMENT_SPRODUCE = :COMMENT_SPRODUCE'
      'WHERE'
      '    ID_SPRODUCE = :OLD_ID_SPRODUCE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SPRODUCE'
      'WHERE'
      '        ID_SPRODUCE = :OLD_ID_SPRODUCE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SPRODUCE('
      '    ID_SPRODUCE,'
      '    GID_SPRODUCE,'
      '    IDBASE_SPRODUCE,'
      '    IDGRP_SPRODUCE,'
      '    NAME_SPRODUCE,'
      '    CODE_SPRODUCE,'
      '    BELKI_SPRODUCE,'
      '    GIRI_SPRODUCE,'
      '    UGL_SPRODUCE,'
      '    COMMENT_SPRODUCE'
      ')'
      'VALUES('
      '    :ID_SPRODUCE,'
      '    :GID_SPRODUCE,'
      '    :IDBASE_SPRODUCE,'
      '    :IDGRP_SPRODUCE,'
      '    :NAME_SPRODUCE,'
      '    :CODE_SPRODUCE,'
      '    :BELKI_SPRODUCE,'
      '    :GIRI_SPRODUCE,'
      '    :UGL_SPRODUCE,'
      '    :COMMENT_SPRODUCE'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from sproduce'
      'where(  sproduce.id_sproduce=:PARAM_ID'
      '     ) and (     SPRODUCE.ID_SPRODUCE = :OLD_ID_SPRODUCE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from sproduce'
      'where sproduce.id_sproduce=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SPRODUCE'
    AutoUpdateOptions.KeyFields = 'ID_SPRODUCE'
    AutoUpdateOptions.GeneratorName = 'GEN_SPRODUCE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_SPRODUCE: TFIBLargeIntField
      FieldName = 'ID_SPRODUCE'
    end
    object ElementGID_SPRODUCE: TFIBWideStringField
      FieldName = 'GID_SPRODUCE'
      Size = 10
    end
    object ElementIDBASE_SPRODUCE: TFIBLargeIntField
      FieldName = 'IDBASE_SPRODUCE'
    end
    object ElementIDGRP_SPRODUCE: TFIBLargeIntField
      FieldName = 'IDGRP_SPRODUCE'
    end
    object ElementNAME_SPRODUCE: TFIBWideStringField
      FieldName = 'NAME_SPRODUCE'
      Size = 200
    end
    object ElementCODE_SPRODUCE: TFIBWideStringField
      FieldName = 'CODE_SPRODUCE'
      Size = 10
    end
    object ElementBELKI_SPRODUCE: TFIBBCDField
      FieldName = 'BELKI_SPRODUCE'
      Size = 3
      RoundByScale = True
    end
    object ElementGIRI_SPRODUCE: TFIBBCDField
      FieldName = 'GIRI_SPRODUCE'
      Size = 3
      RoundByScale = True
    end
    object ElementUGL_SPRODUCE: TFIBBCDField
      FieldName = 'UGL_SPRODUCE'
      Size = 3
      RoundByScale = True
    end
    object ElementCOMMENT_SPRODUCE: TFIBWideStringField
      FieldName = 'COMMENT_SPRODUCE'
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
  object Query: TpFIBQuery
    Transaction = IBTr
    Left = 256
    Top = 128
    qoStartTransaction = True
  end
end
