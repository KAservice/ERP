object DMViborFR: TDMViborFR
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 81
  Width = 300
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 16
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select '
      '  SOBORUD.*'
      'from '
      '  SOBORUD'
      'where IDARM_SOBORUD=:PARAM_IDARM and TYPE_OBORUD='#39'fr'#39)
    Transaction = IBTr
    Left = 144
    Top = 16
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
    object TableON_START_SOBORUD: TFIBSmallIntField
      FieldName = 'ON_START_SOBORUD'
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
    object TableTYPE_OBORUD: TFIBWideStringField
      FieldName = 'TYPE_OBORUD'
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
    object TableBAUDRATE_OBORUD: TFIBWideStringField
      FieldName = 'BAUDRATE_OBORUD'
      Size = 10
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
end
