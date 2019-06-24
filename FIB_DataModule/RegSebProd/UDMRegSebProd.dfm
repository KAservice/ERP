object DMRegSebProd: TDMRegSebProd
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 138
  Width = 200
  object DvRegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGSEBPROD_DV'
      'SET '
      '    POSDOC_RGSEBPROD_DV = :POSDOC_RGSEBPROD_DV,'
      '    IDDOC_RGSEBPROD_DV = :IDDOC_RGSEBPROD_DV,'
      '    TDV_RGSEBPROD_DV = :TDV_RGSEBPROD_DV,'
      '    IDVIPPROD_RGSEBPROD_DV = :IDVIPPROD_RGSEBPROD_DV,'
      '    IDFIRM_RGSEBPROD_DV = :IDFIRM_RGSEBPROD_DV,'
      '    IDSKLAD_RGSEBPROD_DV = :IDSKLAD_RGSEBPROD_DV,'
      '    IDNOM_RGSEBPROD_DV = :IDNOM_RGSEBPROD_DV,'
      '    KOL_RGSEBPROD_DV = :KOL_RGSEBPROD_DV,'
      '    KOLOTR_RGSEBPROD_DV = :KOLOTR_RGSEBPROD_DV,'
      '    SUM_RGSEBPROD_DV = :SUM_RGSEBPROD_DV'
      'WHERE'
      '    ID_RGSEBPROD_DV = :OLD_ID_RGSEBPROD_DV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGSEBPROD_DV'
      'WHERE'
      '        ID_RGSEBPROD_DV = :OLD_ID_RGSEBPROD_DV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGSEBPROD_DV('
      '    ID_RGSEBPROD_DV,'
      '    POSDOC_RGSEBPROD_DV,'
      '    IDDOC_RGSEBPROD_DV,'
      '    TDV_RGSEBPROD_DV,'
      '    IDVIPPROD_RGSEBPROD_DV,'
      '    IDFIRM_RGSEBPROD_DV,'
      '    IDSKLAD_RGSEBPROD_DV,'
      '    IDNOM_RGSEBPROD_DV,'
      '    KOL_RGSEBPROD_DV,'
      '    KOLOTR_RGSEBPROD_DV,'
      '    SUM_RGSEBPROD_DV'
      ')'
      'VALUES('
      '    :ID_RGSEBPROD_DV,'
      '    :POSDOC_RGSEBPROD_DV,'
      '    :IDDOC_RGSEBPROD_DV,'
      '    :TDV_RGSEBPROD_DV,'
      '    :IDVIPPROD_RGSEBPROD_DV,'
      '    :IDFIRM_RGSEBPROD_DV,'
      '    :IDSKLAD_RGSEBPROD_DV,'
      '    :IDNOM_RGSEBPROD_DV,'
      '    :KOL_RGSEBPROD_DV,'
      '    :KOLOTR_RGSEBPROD_DV,'
      '    :SUM_RGSEBPROD_DV'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  RGSEBPROD_DV'
      'where( '
      '  IDDOC_RGSEBPROD_DV=:PARAM_IDDOC'
      
        '     ) and (     RGSEBPROD_DV.ID_RGSEBPROD_DV = :OLD_ID_RGSEBPRO' +
        'D_DV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  RGSEBPROD_DV'
      'where'
      '  IDDOC_RGSEBPROD_DV=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'RGSEBPROD_DV'
    AutoUpdateOptions.KeyFields = 'ID_RGSEBPROD_DV'
    AutoUpdateOptions.GeneratorName = 'GEN_RGSEBPROD_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 48
    Top = 40
    object DvRegOstPOSDOC_RGSEBPROD_DV: TFIBDateTimeField
      FieldName = 'POSDOC_RGSEBPROD_DV'
    end
    object DvRegOstTDV_RGSEBPROD_DV: TFIBSmallIntField
      FieldName = 'TDV_RGSEBPROD_DV'
    end
    object DvRegOstKOL_RGSEBPROD_DV: TFIBBCDField
      FieldName = 'KOL_RGSEBPROD_DV'
      Size = 3
      RoundByScale = True
    end
    object DvRegOstKOLOTR_RGSEBPROD_DV: TFIBBCDField
      FieldName = 'KOLOTR_RGSEBPROD_DV'
      Size = 3
      RoundByScale = True
    end
    object DvRegOstSUM_RGSEBPROD_DV: TFIBBCDField
      FieldName = 'SUM_RGSEBPROD_DV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstID_RGSEBPROD_DV: TFIBBCDField
      FieldName = 'ID_RGSEBPROD_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOC_RGSEBPROD_DV: TFIBBCDField
      FieldName = 'IDDOC_RGSEBPROD_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDVIPPROD_RGSEBPROD_DV: TFIBBCDField
      FieldName = 'IDVIPPROD_RGSEBPROD_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDFIRM_RGSEBPROD_DV: TFIBBCDField
      FieldName = 'IDFIRM_RGSEBPROD_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDSKLAD_RGSEBPROD_DV: TFIBBCDField
      FieldName = 'IDSKLAD_RGSEBPROD_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDNOM_RGSEBPROD_DV: TFIBBCDField
      FieldName = 'IDNOM_RGSEBPROD_DV'
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
    Left = 128
    Top = 40
  end
end
