object DMRegVipuskProd: TDMRegVipuskProd
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 138
  Width = 200
  object DvRegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGVIPPROD_DV'
      'SET '
      '    POSDOC_RGVIPPROD_DV = :POSDOC_RGVIPPROD_DV,'
      '    IDDOC_RGVIPPROD_DV = :IDDOC_RGVIPPROD_DV,'
      '    TDV_RGVIPPROD_DV = :TDV_RGVIPPROD_DV,'
      '    IDFIRM_RGVIPPROD_DV = :IDFIRM_RGVIPPROD_DV,'
      '    IDSKLAD_RGVIPPROD_DV = :IDSKLAD_RGVIPPROD_DV,'
      '    IDNOM_RGVIPPROD_DV = :IDNOM_RGVIPPROD_DV,'
      '    KOL_RGVIPPROD_DV = :KOL_RGVIPPROD_DV,'
      '    SEB_RGVIPPROD_DV = :SEB_RGVIPPROD_DV'
      'WHERE'
      '    ID_RGVIPPROD_DV = :OLD_ID_RGVIPPROD_DV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGVIPPROD_DV'
      'WHERE'
      '        ID_RGVIPPROD_DV = :OLD_ID_RGVIPPROD_DV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGVIPPROD_DV('
      '    ID_RGVIPPROD_DV,'
      '    POSDOC_RGVIPPROD_DV,'
      '    IDDOC_RGVIPPROD_DV,'
      '    TDV_RGVIPPROD_DV,'
      '    IDFIRM_RGVIPPROD_DV,'
      '    IDSKLAD_RGVIPPROD_DV,'
      '    IDNOM_RGVIPPROD_DV,'
      '    KOL_RGVIPPROD_DV,'
      '    SEB_RGVIPPROD_DV'
      ')'
      'VALUES('
      '    :ID_RGVIPPROD_DV,'
      '    :POSDOC_RGVIPPROD_DV,'
      '    :IDDOC_RGVIPPROD_DV,'
      '    :TDV_RGVIPPROD_DV,'
      '    :IDFIRM_RGVIPPROD_DV,'
      '    :IDSKLAD_RGVIPPROD_DV,'
      '    :IDNOM_RGVIPPROD_DV,'
      '    :KOL_RGVIPPROD_DV,'
      '    :SEB_RGVIPPROD_DV'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '   RGVIPPROD_DV'
      'where( '
      '   IDDOC_RGVIPPROD_DV=:PARAM_IDDOC'
      
        '     ) and (     RGVIPPROD_DV.ID_RGVIPPROD_DV = :OLD_ID_RGVIPPRO' +
        'D_DV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '   RGVIPPROD_DV'
      'where'
      '   IDDOC_RGVIPPROD_DV=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'RGVIPPROD_DV'
    AutoUpdateOptions.KeyFields = 'ID_RGVIPPROD_DV'
    AutoUpdateOptions.GeneratorName = 'GEN_RGVIPPROD_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 24
    Top = 80
    object DvRegOstPOSDOC_RGVIPPROD_DV: TFIBDateTimeField
      FieldName = 'POSDOC_RGVIPPROD_DV'
    end
    object DvRegOstTDV_RGVIPPROD_DV: TFIBSmallIntField
      FieldName = 'TDV_RGVIPPROD_DV'
    end
    object DvRegOstKOL_RGVIPPROD_DV: TFIBBCDField
      FieldName = 'KOL_RGVIPPROD_DV'
      Size = 3
      RoundByScale = True
    end
    object DvRegOstSEB_RGVIPPROD_DV: TFIBBCDField
      FieldName = 'SEB_RGVIPPROD_DV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstID_RGVIPPROD_DV: TFIBBCDField
      FieldName = 'ID_RGVIPPROD_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOC_RGVIPPROD_DV: TFIBBCDField
      FieldName = 'IDDOC_RGVIPPROD_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDFIRM_RGVIPPROD_DV: TFIBBCDField
      FieldName = 'IDFIRM_RGVIPPROD_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDSKLAD_RGVIPPROD_DV: TFIBBCDField
      FieldName = 'IDSKLAD_RGVIPPROD_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDNOM_RGVIPPROD_DV: TFIBBCDField
      FieldName = 'IDNOM_RGVIPPROD_DV'
      Size = 0
      RoundByScale = True
    end
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 112
    Top = 80
  end
end
