object DMRegOtrSpisNom: TDMRegOtrSpisNom
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 253
  Width = 207
  object DvRegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGOTRSPIS_DV'
      'SET '
      '    POSDOC_RGOTRSPIS_DV = :POSDOC_RGOTRSPIS_DV,'
      '    TDV_RGOTRSPIS_DV = :TDV_RGOTRSPIS_DV,'
      '    IDDOC_RGOTRSPIS_DV = :IDDOC_RGOTRSPIS_DV,'
      '    IDFIRM_RGOTRSPIS_DV = :IDFIRM_RGOTRSPIS_DV,'
      '    IDSKL_RGOTRSPIS_DV = :IDSKL_RGOTRSPIS_DV,'
      '    IDNOM_RGOTRSPIS_DV = :IDNOM_RGOTRSPIS_DV,'
      '    IDSTRDOC_RGOTRSPIS_DV = :IDSTRDOC_RGOTRSPIS_DV,'
      '    KOL_RGOTRSPIS_DV = :KOL_RGOTRSPIS_DV'
      'WHERE'
      '    ID_RGOTRSPIS_DV = :OLD_ID_RGOTRSPIS_DV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGOTRSPIS_DV'
      'WHERE'
      '        ID_RGOTRSPIS_DV = :OLD_ID_RGOTRSPIS_DV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGOTRSPIS_DV('
      '    ID_RGOTRSPIS_DV,'
      '    POSDOC_RGOTRSPIS_DV,'
      '    TDV_RGOTRSPIS_DV,'
      '    IDDOC_RGOTRSPIS_DV,'
      '    IDFIRM_RGOTRSPIS_DV,'
      '    IDSKL_RGOTRSPIS_DV,'
      '    IDNOM_RGOTRSPIS_DV,'
      '    IDSTRDOC_RGOTRSPIS_DV,'
      '    KOL_RGOTRSPIS_DV'
      ')'
      'VALUES('
      '    :ID_RGOTRSPIS_DV,'
      '    :POSDOC_RGOTRSPIS_DV,'
      '    :TDV_RGOTRSPIS_DV,'
      '    :IDDOC_RGOTRSPIS_DV,'
      '    :IDFIRM_RGOTRSPIS_DV,'
      '    :IDSKL_RGOTRSPIS_DV,'
      '    :IDNOM_RGOTRSPIS_DV,'
      '    :IDSTRDOC_RGOTRSPIS_DV,'
      '    :KOL_RGOTRSPIS_DV'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  RGOTRSPIS_DV'
      'where( '
      ' IDDOC_RGOTRSPIS_DV=:PARAM_IDDOC'
      
        '     ) and (     RGOTRSPIS_DV.ID_RGOTRSPIS_DV = :OLD_ID_RGOTRSPI' +
        'S_DV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  RGOTRSPIS_DV'
      'where'
      ' IDDOC_RGOTRSPIS_DV=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'RGOTRSPIS_DV'
    AutoUpdateOptions.KeyFields = 'ID_RGOTRSPIS_DV'
    AutoUpdateOptions.GeneratorName = 'GEN_RGOTRSPIS_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Database = DM.pFIBData
    CSMonitorSupport.Enabled = csmeTransactionDriven
    Left = 24
    Top = 16
    object DvRegOstPOSDOC_RGOTRSPIS_DV: TFIBDateTimeField
      FieldName = 'POSDOC_RGOTRSPIS_DV'
    end
    object DvRegOstTDV_RGOTRSPIS_DV: TFIBSmallIntField
      FieldName = 'TDV_RGOTRSPIS_DV'
    end
    object DvRegOstKOL_RGOTRSPIS_DV: TFIBBCDField
      FieldName = 'KOL_RGOTRSPIS_DV'
      Size = 3
      RoundByScale = True
    end
    object DvRegOstID_RGOTRSPIS_DV: TFIBBCDField
      FieldName = 'ID_RGOTRSPIS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOC_RGOTRSPIS_DV: TFIBBCDField
      FieldName = 'IDDOC_RGOTRSPIS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDFIRM_RGOTRSPIS_DV: TFIBBCDField
      FieldName = 'IDFIRM_RGOTRSPIS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDSKL_RGOTRSPIS_DV: TFIBBCDField
      FieldName = 'IDSKL_RGOTRSPIS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDNOM_RGOTRSPIS_DV: TFIBBCDField
      FieldName = 'IDNOM_RGOTRSPIS_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDSTRDOC_RGOTRSPIS_DV: TFIBBCDField
      FieldName = 'IDSTRDOC_RGOTRSPIS_DV'
      Size = 0
      RoundByScale = True
    end
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
    Left = 96
    Top = 16
  end
end
