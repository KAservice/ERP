object DMExtModuleGrp: TDMExtModuleGrp
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 224
  Width = 345
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 64
    Top = 24
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 64
    Top = 80
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select * '
      'from '
      '  EXT_MODULE_GRP'
      'order by IDGRP_EXT_MODULE_GRP')
    Transaction = IBTr
    Left = 144
    Top = 24
    object TableID_EXT_MODULE_GRP: TFIBBCDField
      FieldName = 'ID_EXT_MODULE_GRP'
      Size = 0
      RoundByScale = True
    end
    object TableIDGRP_EXT_MODULE_GRP: TFIBBCDField
      FieldName = 'IDGRP_EXT_MODULE_GRP'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_EXT_MODULE_GRP: TFIBWideStringField
      FieldName = 'NAME_EXT_MODULE_GRP'
      Size = 100
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE EXT_MODULE_GRP'
      'SET '
      '    IDGRP_EXT_MODULE_GRP = :IDGRP_EXT_MODULE_GRP,'
      '    NAME_EXT_MODULE_GRP = :NAME_EXT_MODULE_GRP'
      'WHERE'
      '    ID_EXT_MODULE_GRP = :OLD_ID_EXT_MODULE_GRP'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    EXT_MODULE_GRP'
      'WHERE'
      '        ID_EXT_MODULE_GRP = :OLD_ID_EXT_MODULE_GRP'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO EXT_MODULE_GRP('
      '    ID_EXT_MODULE_GRP,'
      '    IDGRP_EXT_MODULE_GRP,'
      '    NAME_EXT_MODULE_GRP'
      ')'
      'VALUES('
      '    :ID_EXT_MODULE_GRP,'
      '    :IDGRP_EXT_MODULE_GRP,'
      '    :NAME_EXT_MODULE_GRP'
      ')')
    RefreshSQL.Strings = (
      'select * from EXT_MODULE_GRP'
      'where(  ID_EXT_MODULE_GRP=:PARAM_ID'
      
        '     ) and (     EXT_MODULE_GRP.ID_EXT_MODULE_GRP = :OLD_ID_EXT_' +
        'MODULE_GRP'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from EXT_MODULE_GRP'
      'where ID_EXT_MODULE_GRP=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'EXT_MODULE_GRP'
    AutoUpdateOptions.KeyFields = 'ID_EXT_MODULE_GRP'
    AutoUpdateOptions.GeneratorName = 'GEN_EXT_MODULE_GRP_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTr
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 80
    object ElementID_EXT_MODULE_GRP: TFIBBCDField
      FieldName = 'ID_EXT_MODULE_GRP'
      Size = 0
      RoundByScale = True
    end
    object ElementIDGRP_EXT_MODULE_GRP: TFIBBCDField
      FieldName = 'IDGRP_EXT_MODULE_GRP'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_EXT_MODULE_GRP: TFIBWideStringField
      FieldName = 'NAME_EXT_MODULE_GRP'
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
    Left = 216
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    Left = 216
    Top = 80
  end
  object pFIBQ: TpFIBQuery
    Transaction = IBTr
    Left = 272
    Top = 56
    qoStartTransaction = True
  end
end
