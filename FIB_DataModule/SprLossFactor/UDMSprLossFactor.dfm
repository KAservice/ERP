object DMSprLossFactor: TDMSprLossFactor
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 302
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
      'from sloss_factor'
      'ORDER BY sloss_factor.name_sloss_factor')
    Transaction = IBTr
    Left = 160
    Top = 16
    poUseLargeIntField = True
    object TableID_SLOSS_FACTOR: TFIBLargeIntField
      FieldName = 'ID_SLOSS_FACTOR'
    end
    object TableGID_SLOSS_FACTOR: TFIBWideStringField
      FieldName = 'GID_SLOSS_FACTOR'
      Size = 10
    end
    object TableIDBASE_SLOSS_FACTOR: TFIBLargeIntField
      FieldName = 'IDBASE_SLOSS_FACTOR'
    end
    object TableNAME_SLOSS_FACTOR: TFIBWideStringField
      FieldName = 'NAME_SLOSS_FACTOR'
      Size = 200
    end
    object TableCOMMENT_SLOSS_FACTOR: TFIBWideStringField
      FieldName = 'COMMENT_SLOSS_FACTOR'
      Size = 100
    end
    object TableENCEN_SLOSS_FACTOR: TFIBBCDField
      FieldName = 'ENCEN_SLOSS_FACTOR'
      Size = 3
      RoundByScale = True
    end
    object TableBELKI_SLOSS_FACTOR: TFIBBCDField
      FieldName = 'BELKI_SLOSS_FACTOR'
      Size = 3
      RoundByScale = True
    end
    object TableGIRI_SLOSS_FACTOR: TFIBBCDField
      FieldName = 'GIRI_SLOSS_FACTOR'
      Size = 3
      RoundByScale = True
    end
    object TableUGL_SLOSS_FACTOR: TFIBBCDField
      FieldName = 'UGL_SLOSS_FACTOR'
      Size = 3
      RoundByScale = True
    end
    object TableCODE_SLOSS_FACTOR: TFIBWideStringField
      FieldName = 'CODE_SLOSS_FACTOR'
      Size = 10
    end
    object TableIDGRP_SLOSS_FACTOR: TFIBLargeIntField
      FieldName = 'IDGRP_SLOSS_FACTOR'
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SLOSS_FACTOR'
      'SET '
      '    GID_SLOSS_FACTOR = :GID_SLOSS_FACTOR,'
      '    IDBASE_SLOSS_FACTOR = :IDBASE_SLOSS_FACTOR,'
      '    NAME_SLOSS_FACTOR = :NAME_SLOSS_FACTOR,'
      '    COMMENT_SLOSS_FACTOR = :COMMENT_SLOSS_FACTOR,'
      '    ENCEN_SLOSS_FACTOR = :ENCEN_SLOSS_FACTOR,'
      '    BELKI_SLOSS_FACTOR = :BELKI_SLOSS_FACTOR,'
      '    GIRI_SLOSS_FACTOR = :GIRI_SLOSS_FACTOR,'
      '    UGL_SLOSS_FACTOR = :UGL_SLOSS_FACTOR,'
      '    CODE_SLOSS_FACTOR = :CODE_SLOSS_FACTOR,'
      '    IDGRP_SLOSS_FACTOR = :IDGRP_SLOSS_FACTOR'
      'WHERE'
      '    ID_SLOSS_FACTOR = :OLD_ID_SLOSS_FACTOR'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SLOSS_FACTOR'
      'WHERE'
      '        ID_SLOSS_FACTOR = :OLD_ID_SLOSS_FACTOR'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SLOSS_FACTOR('
      '    ID_SLOSS_FACTOR,'
      '    GID_SLOSS_FACTOR,'
      '    IDBASE_SLOSS_FACTOR,'
      '    NAME_SLOSS_FACTOR,'
      '    COMMENT_SLOSS_FACTOR,'
      '    ENCEN_SLOSS_FACTOR,'
      '    BELKI_SLOSS_FACTOR,'
      '    GIRI_SLOSS_FACTOR,'
      '    UGL_SLOSS_FACTOR,'
      '    CODE_SLOSS_FACTOR,'
      '    IDGRP_SLOSS_FACTOR'
      ')'
      'VALUES('
      '    :ID_SLOSS_FACTOR,'
      '    :GID_SLOSS_FACTOR,'
      '    :IDBASE_SLOSS_FACTOR,'
      '    :NAME_SLOSS_FACTOR,'
      '    :COMMENT_SLOSS_FACTOR,'
      '    :ENCEN_SLOSS_FACTOR,'
      '    :BELKI_SLOSS_FACTOR,'
      '    :GIRI_SLOSS_FACTOR,'
      '    :UGL_SLOSS_FACTOR,'
      '    :CODE_SLOSS_FACTOR,'
      '    :IDGRP_SLOSS_FACTOR'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from sloss_factor'
      'where(  sloss_factor.id_sloss_factor=:PARAM_ID'
      
        '     ) and (     SLOSS_FACTOR.ID_SLOSS_FACTOR = :OLD_ID_SLOSS_FA' +
        'CTOR'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from sloss_factor'
      'where sloss_factor.id_sloss_factor=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SLOSS_FACTOR'
    AutoUpdateOptions.KeyFields = 'ID_SLOSS_FACTOR'
    AutoUpdateOptions.GeneratorName = 'GEN_SLOSS_FACTOR_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    poUseLargeIntField = True
    object ElementID_SLOSS_FACTOR: TFIBLargeIntField
      FieldName = 'ID_SLOSS_FACTOR'
    end
    object ElementGID_SLOSS_FACTOR: TFIBWideStringField
      FieldName = 'GID_SLOSS_FACTOR'
      Size = 10
    end
    object ElementIDBASE_SLOSS_FACTOR: TFIBLargeIntField
      FieldName = 'IDBASE_SLOSS_FACTOR'
    end
    object ElementNAME_SLOSS_FACTOR: TFIBWideStringField
      FieldName = 'NAME_SLOSS_FACTOR'
      Size = 200
    end
    object ElementCOMMENT_SLOSS_FACTOR: TFIBWideStringField
      FieldName = 'COMMENT_SLOSS_FACTOR'
      Size = 100
    end
    object ElementENCEN_SLOSS_FACTOR: TFIBBCDField
      FieldName = 'ENCEN_SLOSS_FACTOR'
      Size = 3
      RoundByScale = True
    end
    object ElementBELKI_SLOSS_FACTOR: TFIBBCDField
      FieldName = 'BELKI_SLOSS_FACTOR'
      Size = 3
      RoundByScale = True
    end
    object ElementGIRI_SLOSS_FACTOR: TFIBBCDField
      FieldName = 'GIRI_SLOSS_FACTOR'
      Size = 3
      RoundByScale = True
    end
    object ElementUGL_SLOSS_FACTOR: TFIBBCDField
      FieldName = 'UGL_SLOSS_FACTOR'
      Size = 3
      RoundByScale = True
    end
    object ElementCODE_SLOSS_FACTOR: TFIBWideStringField
      FieldName = 'CODE_SLOSS_FACTOR'
      Size = 10
    end
    object ElementIDGRP_SLOSS_FACTOR: TFIBLargeIntField
      FieldName = 'IDGRP_SLOSS_FACTOR'
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
