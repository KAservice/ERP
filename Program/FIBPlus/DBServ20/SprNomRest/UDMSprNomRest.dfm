object DMSprNomRest: TDMSprNomRest
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 213
  Width = 375
  object DataSourceElement: TDataSource
    DataSet = Element
    Left = 48
    Top = 72
  end
  object DataSourceTable: TDataSource
    DataSet = Table
    Left = 48
    Top = 24
  end
  object Table: TpFIBDataSet
    SelectSQL.Strings = (
      'select ID_NOMREST, NAME_NOMREST, POS_NOMREST , IDNOM_NOMREST'
      'from SNOMREST'
      'where IDNOM_NOMREST=:PARAM_IDNOM'
      'order by POS_NOMREST')
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 168
    Top = 24
    object TableNAME_NOMREST: TFIBStringField
      FieldName = 'NAME_NOMREST'
      OnGetText = TableNAME_NOMRESTGetText
      Size = 50
      EmptyStrToNull = True
    end
    object TablePOS_NOMREST: TFIBDateTimeField
      FieldName = 'POS_NOMREST'
    end
    object TableRECNO: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'RECNO'
      Calculated = True
    end
    object TableID_NOMREST: TFIBBCDField
      FieldName = 'ID_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object TableIDNOM_NOMREST: TFIBBCDField
      FieldName = 'IDNOM_NOMREST'
      Size = 0
      RoundByScale = True
    end
  end
  object Element: TpFIBDataSet
    CachedUpdates = True
    UpdateSQL.Strings = (
      'UPDATE SNOMREST'
      'SET '
      '    IDNOM_NOMREST = :IDNOM_NOMREST,'
      '    IDMPRIG_NOMREST = :IDMPRIG_NOMREST,'
      '    SOST_NOMREST = :SOST_NOMREST,'
      '    TEHN_NOMREST = :TEHN_NOMREST,'
      '    VIH_NOMREST = :VIH_NOMREST,'
      '    SROK_NOMREST = :SROK_NOMREST,'
      '    NOMER_NOMREST = :NOMER_NOMREST,'
      '    NAME_NOMREST = :NAME_NOMREST,'
      '    POS_NOMREST = :POS_NOMREST,'
      '    IDEDPROD_NOMREST = :IDEDPROD_NOMREST,'
      '    KOLEDPROD_NOMREST = :KOLEDPROD_NOMREST,'
      '    GID_SNOMREST = :GID_SNOMREST'
      'WHERE'
      '    ID_NOMREST = :OLD_ID_NOMREST'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    SNOMREST'
      'WHERE'
      '        ID_NOMREST = :OLD_ID_NOMREST'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO SNOMREST('
      '    ID_NOMREST,'
      '    IDNOM_NOMREST,'
      '    IDMPRIG_NOMREST,'
      '    SOST_NOMREST,'
      '    TEHN_NOMREST,'
      '    VIH_NOMREST,'
      '    SROK_NOMREST,'
      '    NOMER_NOMREST,'
      '    NAME_NOMREST,'
      '    POS_NOMREST,'
      '    IDEDPROD_NOMREST,'
      '    KOLEDPROD_NOMREST,'
      '    GID_SNOMREST'
      ')'
      'VALUES('
      '    :ID_NOMREST,'
      '    :IDNOM_NOMREST,'
      '    :IDMPRIG_NOMREST,'
      '    :SOST_NOMREST,'
      '    :TEHN_NOMREST,'
      '    :VIH_NOMREST,'
      '    :SROK_NOMREST,'
      '    :NOMER_NOMREST,'
      '    :NAME_NOMREST,'
      '    :POS_NOMREST,'
      '    :IDEDPROD_NOMREST,'
      '    :KOLEDPROD_NOMREST,'
      '    :GID_SNOMREST'
      ')')
    RefreshSQL.Strings = (
      'select'
      '  SNOMREST.*, NAME_MPRIG, NAMENOM, IDSKLAD_MPRIG, NAMEED, KFED'
      'from '
      '  SNOMREST'
      'left outer join SMPRIG on  IDMPRIG_NOMREST=ID_MPRIG'
      'left outer join SNOM on  IDNOM=IDNOM_NOMREST'
      'left outer join SED on IDED=IDEDPROD_NOMREST'
      'where( '
      '  ID_NOMREST=:PARAM_ID'
      '     ) and (     SNOMREST.ID_NOMREST = :OLD_ID_NOMREST'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select'
      '  SNOMREST.*, NAME_MPRIG, NAMENOM, IDSKLAD_MPRIG, NAMEED, KFED'
      'from '
      '  SNOMREST'
      'left outer join SMPRIG on  IDMPRIG_NOMREST=ID_MPRIG'
      'left outer join SNOM on  IDNOM=IDNOM_NOMREST'
      'left outer join SED on IDED=IDEDPROD_NOMREST'
      'where'
      '  ID_NOMREST=:PARAM_ID')
    AutoUpdateOptions.UpdateTableName = 'SNOMREST'
    AutoUpdateOptions.KeyFields = 'ID_NOMREST'
    AutoUpdateOptions.GeneratorName = 'GEN_SNOMREST_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    OnNewRecord = ElementNewRecord
    Transaction = IBTr
    Database = DM.pFIBData
    UpdateTransaction = IBTrUpdate
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 168
    Top = 80
    object ElementSOST_NOMREST: TFIBStringField
      FieldName = 'SOST_NOMREST'
      Size = 200
      EmptyStrToNull = True
    end
    object ElementTEHN_NOMREST: TFIBStringField
      FieldName = 'TEHN_NOMREST'
      Size = 1500
      EmptyStrToNull = True
    end
    object ElementVIH_NOMREST: TFIBStringField
      FieldName = 'VIH_NOMREST'
      Size = 30
      EmptyStrToNull = True
    end
    object ElementSROK_NOMREST: TFIBStringField
      FieldName = 'SROK_NOMREST'
      Size = 10
      EmptyStrToNull = True
    end
    object ElementNOMER_NOMREST: TFIBStringField
      FieldName = 'NOMER_NOMREST'
      Size = 30
      EmptyStrToNull = True
    end
    object ElementNAME_NOMREST: TFIBStringField
      FieldName = 'NAME_NOMREST'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementPOS_NOMREST: TFIBDateTimeField
      FieldName = 'POS_NOMREST'
    end
    object ElementKOLEDPROD_NOMREST: TFIBBCDField
      FieldName = 'KOLEDPROD_NOMREST'
      Size = 3
      RoundByScale = True
    end
    object ElementKFED: TFIBBCDField
      FieldName = 'KFED'
      Size = 3
      RoundByScale = True
    end
    object ElementNAME_MPRIG: TFIBStringField
      FieldName = 'NAME_MPRIG'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementNAMEED: TFIBStringField
      FieldName = 'NAMEED'
      Size = 50
      EmptyStrToNull = True
    end
    object ElementID_NOMREST: TFIBBCDField
      FieldName = 'ID_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object ElementIDNOM_NOMREST: TFIBBCDField
      FieldName = 'IDNOM_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object ElementIDMPRIG_NOMREST: TFIBBCDField
      FieldName = 'IDMPRIG_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object ElementIDEDPROD_NOMREST: TFIBBCDField
      FieldName = 'IDEDPROD_NOMREST'
      Size = 0
      RoundByScale = True
    end
    object ElementIDSKLAD_MPRIG: TFIBBCDField
      FieldName = 'IDSKLAD_MPRIG'
      Size = 0
      RoundByScale = True
    end
    object ElementGID_SNOMREST: TFIBStringField
      FieldName = 'GID_SNOMREST'
      Size = 10
      EmptyStrToNull = True
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
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 272
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    DefaultDatabase = DM.pFIBData
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    CSMonitorSupport.Enabled = csmeDatabaseDriven
    TPBMode = tpbDefault
    Left = 272
    Top = 80
  end
  object IBQ: TpFIBDataSet
    SelectSQL.Strings = (
      'select SSPROD.*,  NAMENOM, VALUE_SSEZKF, VALUE_SSEZKF_SPROD'
      '   from SSPROD'
      'left outer join SNOM on IDKOMPL_SPROD=IDNOM'
      'left outer join SSEZKF on IDNOM_SSEZKF=IDKOMPL_SPROD and '
      'MONTH_SSEZKF=:PARAM_MONTH'
      ''
      
        'left outer join SSEZKF_SPROD on IDSSPROD_SSEZKF_SPROD= ID_SPROD ' +
        'and '
      'MONTH_SSEZKF_SPROD=:PARAM_MONTH'
      ''
      'where IDNOMREST_SPROD=:PARAM_IDNOMREST')
    OnCalcFields = IBQCalcFields
    Transaction = IBTr
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 168
    Top = 136
    object IBQNKOL_SPROD: TFIBBCDField
      FieldName = 'NKOL_SPROD'
      Size = 3
      RoundByScale = True
    end
    object IBQBKOL_SPROD: TFIBBCDField
      FieldName = 'BKOL_SPROD'
      Size = 3
      RoundByScale = True
    end
    object IBQKFPRICE_SPROD: TFIBBCDField
      FieldName = 'KFPRICE_SPROD'
      Size = 3
      RoundByScale = True
    end
    object IBQSPIS_SPROD: TFIBSmallIntField
      FieldName = 'SPIS_SPROD'
    end
    object IBQNAMENOM: TFIBStringField
      FieldName = 'NAMENOM'
      Size = 50
      EmptyStrToNull = True
    end
    object IBQVALUE_SSEZKF: TFIBBCDField
      FieldName = 'VALUE_SSEZKF'
      Size = 3
      RoundByScale = True
    end
    object IBQSEZKF: TFloatField
      FieldKind = fkCalculated
      FieldName = 'SEZKF'
      Calculated = True
    end
    object IBQSEZKF_SPROD: TFloatField
      FieldKind = fkCalculated
      FieldName = 'SEZKF_SPROD'
      Calculated = True
    end
    object IBQVALUE_SSEZKF_SPROD: TFIBBCDField
      FieldName = 'VALUE_SSEZKF_SPROD'
      Size = 3
      RoundByScale = True
    end
    object IBQID_SPROD: TFIBBCDField
      FieldName = 'ID_SPROD'
      Size = 0
      RoundByScale = True
    end
    object IBQIDKOMPL_SPROD: TFIBBCDField
      FieldName = 'IDKOMPL_SPROD'
      Size = 0
      RoundByScale = True
    end
  end
end
