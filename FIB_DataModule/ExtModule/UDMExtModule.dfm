object DMExtModule: TDMExtModule
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
      'from EXT_MODULE'
      'where IDGRP_EXT_MODULE=:PARAM_IDGRP')
    Transaction = IBTr
    Left = 160
    Top = 16
    object TableID_EXT_MODULE: TFIBBCDField
      FieldName = 'ID_EXT_MODULE'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRP_EXT_MODULE: TFIBBCDField
      FieldName = 'IDGRP_EXT_MODULE'
      Size = 0
      RoundByScale = True
    end
    object TableTYPE_EXT_MODULE: TFIBSmallIntField
      FieldName = 'TYPE_EXT_MODULE'
    end
    object TableISP_EXT_MODULE: TFIBSmallIntField
      FieldName = 'ISP_EXT_MODULE'
    end
    object TableNAME_EXT_MODULE: TFIBWideStringField
      FieldName = 'NAME_EXT_MODULE'
      Size = 100
    end
    object TableFILE_NAME_EXT_MODULE: TFIBWideStringField
      FieldName = 'FILE_NAME_EXT_MODULE'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE EXT_MODULE'
      'SET '
      '    IDBASE_EXT_MODULE = :IDBASE_EXT_MODULE,'
      '    IDGRP_EXT_MODULE = :IDGRP_EXT_MODULE,'
      '    NAME_EXT_MODULE = :NAME_EXT_MODULE,'
      '    TYPE_EXT_MODULE = :TYPE_EXT_MODULE,'
      '    ISP_EXT_MODULE = :ISP_EXT_MODULE,'
      '    FILE_NAME_EXT_MODULE = :FILE_NAME_EXT_MODULE,'
      '    BODY_EXT_MODULE = :BODY_EXT_MODULE,'
      '    RESIDENCE_EXT_MODULE = :RESIDENCE_EXT_MODULE'
      'WHERE'
      '    ID_EXT_MODULE = :OLD_ID_EXT_MODULE'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    EXT_MODULE'
      'WHERE'
      '        ID_EXT_MODULE = :OLD_ID_EXT_MODULE'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO EXT_MODULE('
      '    ID_EXT_MODULE,'
      '    IDBASE_EXT_MODULE,'
      '    IDGRP_EXT_MODULE,'
      '    NAME_EXT_MODULE,'
      '    TYPE_EXT_MODULE,'
      '    ISP_EXT_MODULE,'
      '    FILE_NAME_EXT_MODULE,'
      '    BODY_EXT_MODULE,'
      '    RESIDENCE_EXT_MODULE'
      ')'
      'VALUES('
      '    :ID_EXT_MODULE,'
      '    :IDBASE_EXT_MODULE,'
      '    :IDGRP_EXT_MODULE,'
      '    :NAME_EXT_MODULE,'
      '    :TYPE_EXT_MODULE,'
      '    :ISP_EXT_MODULE,'
      '    :FILE_NAME_EXT_MODULE,'
      '    :BODY_EXT_MODULE,'
      '    :RESIDENCE_EXT_MODULE'
      ')')
    RefreshSQL.Strings = (
      'select *'
      'from EXT_MODULE'
      'where(  ID_EXT_MODULE=:PARAM_ID'
      '     ) and (     EXT_MODULE.ID_EXT_MODULE = :OLD_ID_EXT_MODULE'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select *'
      'from EXT_MODULE'
      'where ID_EXT_MODULE=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'EXT_MODULE'
    AutoUpdateOptions.KeyFields = 'ID_EXT_MODULE'
    AutoUpdateOptions.GeneratorName = 'GEN_EXT_MODULE_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 160
    Top = 64
    object ElementID_EXT_MODULE: TFIBBCDField
      FieldName = 'ID_EXT_MODULE'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRP_EXT_MODULE: TFIBBCDField
      FieldName = 'IDGRP_EXT_MODULE'
      Size = 0
      RoundByScale = True
    end
    object ElementTYPE_EXT_MODULE: TFIBSmallIntField
      FieldName = 'TYPE_EXT_MODULE'
    end
    object ElementISP_EXT_MODULE: TFIBSmallIntField
      FieldName = 'ISP_EXT_MODULE'
    end
    object ElementBODY_EXT_MODULE: TFIBBlobField
      FieldName = 'BODY_EXT_MODULE'
      Size = 8
    end
    object ElementRESIDENCE_EXT_MODULE: TFIBIntegerField
      FieldName = 'RESIDENCE_EXT_MODULE'
    end
    object ElementNAME_EXT_MODULE: TFIBWideStringField
      FieldName = 'NAME_EXT_MODULE'
      Size = 100
    end
    object ElementFILE_NAME_EXT_MODULE: TFIBWideStringField
      FieldName = 'FILE_NAME_EXT_MODULE'
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
end
