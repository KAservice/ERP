object DMSprOborud: TDMSprOborud
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 168
  Width = 366
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 88
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '  SOBORUD.*'
      'from '
      '  SOBORUD'
      'where IDARM_SOBORUD=:PARAM_IDARM')
    Transaction = IBTr
    Database = DM.pFIBData
    Left = 144
    Top = 16
    object TableON_START_SOBORUD: TFIBSmallIntField
      FieldName = 'ON_START_SOBORUD'
    end
    object TableID_OBORUD: TFIBBCDField
      FieldName = 'ID_OBORUD'
      Size = 0
      RoundByScale = True
    end
    object TableIDARM_SOBORUD: TFIBBCDField
      FieldName = 'IDARM_SOBORUD'
      Size = 0
      RoundByScale = True
    end
    object TableNAME_OBORUD: TFIBWideStringField
      FieldName = 'NAME_OBORUD'
      Size = 100
    end
    object TableCOMPNAME_OBORUD: TFIBWideStringField
      FieldName = 'COMPNAME_OBORUD'
      Size = 10
    end
    object TableCOMNAME_OBORUD: TFIBWideStringField
      FieldName = 'COMNAME_OBORUD'
      Size = 5
    end
    object TableBAUDRATE_OBORUD: TFIBWideStringField
      FieldName = 'BAUDRATE_OBORUD'
      Size = 10
    end
    object TableMODEL_OBORUD: TFIBWideStringField
      FieldName = 'MODEL_OBORUD'
    end
    object TableGID_SOBORUD: TFIBWideStringField
      FieldName = 'GID_SOBORUD'
      Size = 10
    end
    object TableSTRPAR_SOBORUD: TFIBWideStringField
      FieldName = 'STRPAR_SOBORUD'
      Size = 1000
    end
    object TableMODUL_SOBORUD: TFIBWideStringField
      FieldName = 'MODUL_SOBORUD'
    end
    object TableIDBASE_SOBORUD: TFIBBCDField
      FieldName = 'IDBASE_SOBORUD'
      Size = 0
      RoundByScale = True
    end
    object TableTYPE_OBORUD: TFIBWideStringField
      FieldName = 'TYPE_OBORUD'
      Size = 10
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SOBORUD'
      'SET '
      '    IDARM_SOBORUD = :IDARM_SOBORUD,'
      '    NAME_OBORUD = :NAME_OBORUD,'
      '    COMPNAME_OBORUD = :COMPNAME_OBORUD,'
      '    COMNAME_OBORUD = :COMNAME_OBORUD,'
      '    BAUDRATE_OBORUD = :BAUDRATE_OBORUD,'
      '    TYPE_OBORUD = :TYPE_OBORUD,'
      '    MODEL_OBORUD = :MODEL_OBORUD,'
      '    GID_SOBORUD = :GID_SOBORUD,'
      '    STRPAR_SOBORUD = :STRPAR_SOBORUD,'
      '    MODUL_SOBORUD = :MODUL_SOBORUD,'
      '    ON_START_SOBORUD = :ON_START_SOBORUD'
      'WHERE'
      '    ID_OBORUD = :OLD_ID_OBORUD'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SOBORUD'
      'WHERE'
      '        ID_OBORUD = :OLD_ID_OBORUD'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SOBORUD('
      '    ID_OBORUD,'
      '    IDARM_SOBORUD,'
      '    NAME_OBORUD,'
      '    COMPNAME_OBORUD,'
      '    COMNAME_OBORUD,'
      '    BAUDRATE_OBORUD,'
      '    TYPE_OBORUD,'
      '    MODEL_OBORUD,'
      '    GID_SOBORUD,'
      '    STRPAR_SOBORUD,'
      '    MODUL_SOBORUD,'
      '    ON_START_SOBORUD'
      ')'
      'VALUES('
      '    :ID_OBORUD,'
      '    :IDARM_SOBORUD,'
      '    :NAME_OBORUD,'
      '    :COMPNAME_OBORUD,'
      '    :COMNAME_OBORUD,'
      '    :BAUDRATE_OBORUD,'
      '    :TYPE_OBORUD,'
      '    :MODEL_OBORUD,'
      '    :GID_SOBORUD,'
      '    :STRPAR_SOBORUD,'
      '    :MODUL_SOBORUD,'
      '    :ON_START_SOBORUD'
      ')')
    RefreshSQL.Strings = (
      'select '
      '  SOBORUD.*'
      'from '
      '  SOBORUD'
      'where(  '
      '  ID_OBORUD=:PARAM_ID_OBORUD'
      '     ) and (     SOBORUD.ID_OBORUD = :OLD_ID_OBORUD'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select '
      '  SOBORUD.*'
      'from '
      '  SOBORUD'
      'where '
      '  ID_OBORUD=:PARAM_ID_OBORUD')
    AutoUpdateOptions.UpdateTableName = 'SOBORUD'
    AutoUpdateOptions.KeyFields = 'ID_OBORUD'
    AutoUpdateOptions.GeneratorName = 'GEN_SOBORUD_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    Left = 144
    Top = 88
    object ElementON_START_SOBORUD: TFIBSmallIntField
      FieldName = 'ON_START_SOBORUD'
    end
    object ElementID_OBORUD: TFIBBCDField
      FieldName = 'ID_OBORUD'
      Size = 0
      RoundByScale = True
    end
    object ElementIDARM_SOBORUD: TFIBBCDField
      FieldName = 'IDARM_SOBORUD'
      Size = 0
      RoundByScale = True
    end
    object ElementNAME_OBORUD: TFIBWideStringField
      FieldName = 'NAME_OBORUD'
      Size = 100
    end
    object ElementCOMPNAME_OBORUD: TFIBWideStringField
      FieldName = 'COMPNAME_OBORUD'
      Size = 10
    end
    object ElementCOMNAME_OBORUD: TFIBWideStringField
      FieldName = 'COMNAME_OBORUD'
      Size = 5
    end
    object ElementTYPE_OBORUD: TFIBWideStringField
      FieldName = 'TYPE_OBORUD'
      Size = 10
    end
    object ElementMODEL_OBORUD: TFIBWideStringField
      FieldName = 'MODEL_OBORUD'
    end
    object ElementGID_SOBORUD: TFIBWideStringField
      FieldName = 'GID_SOBORUD'
      Size = 10
    end
    object ElementSTRPAR_SOBORUD: TFIBWideStringField
      FieldName = 'STRPAR_SOBORUD'
      Size = 1000
    end
    object ElementMODUL_SOBORUD: TFIBWideStringField
      FieldName = 'MODUL_SOBORUD'
    end
    object ElementIDBASE_SOBORUD: TFIBBCDField
      FieldName = 'IDBASE_SOBORUD'
      Size = 0
      RoundByScale = True
    end
    object ElementBAUDRATE_OBORUD: TFIBWideStringField
      FieldName = 'BAUDRATE_OBORUD'
      Size = 10
    end
  end
  object IBTr: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
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
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 232
    Top = 88
  end
end
