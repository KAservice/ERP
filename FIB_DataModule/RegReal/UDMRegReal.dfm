object DMRegReal: TDMRegReal
  OldCreateOrder = False
  OnDestroy = DataModuleDestroy
  Height = 138
  Width = 200
  object DvRegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGREAL_DV'
      'SET '
      '    POSDOC_RGREAL_DV = :POSDOC_RGREAL_DV,'
      '    IDDOC_RGREAL_DV = :IDDOC_RGREAL_DV,'
      '    TDV_RGREAL_DV = :TDV_RGREAL_DV,'
      '    IDFIRM_RGREAL_DV = :IDFIRM_RGREAL_DV,'
      '    IDSKLAD_RGREAL_DV = :IDSKLAD_RGREAL_DV,'
      '    IDNOM_RGREAL_DV = :IDNOM_RGREAL_DV,'
      '    SUMREAL_RGREAL_DV = :SUMREAL_RGREAL_DV,'
      '    SEBREAL_RGREAL_DV = :SEBREAL_RGREAL_DV,'
      '    RESREAL_RGREAL_DV = :RESREAL_RGREAL_DV,'
      '    KOL_RGREAL_DV = :KOL_RGREAL_DV,'
      '    KOLOTR_RGREAL_DV = :KOLOTR_RGREAL_DV,'
      '    OPER_RGREAL_DV = :OPER_RGREAL_DV'
      'WHERE'
      '    ID_RGREAL_DV = :OLD_ID_RGREAL_DV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGREAL_DV'
      'WHERE'
      '        ID_RGREAL_DV = :OLD_ID_RGREAL_DV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGREAL_DV('
      '    ID_RGREAL_DV,'
      '    POSDOC_RGREAL_DV,'
      '    IDDOC_RGREAL_DV,'
      '    TDV_RGREAL_DV,'
      '    IDFIRM_RGREAL_DV,'
      '    IDSKLAD_RGREAL_DV,'
      '    IDNOM_RGREAL_DV,'
      '    SUMREAL_RGREAL_DV,'
      '    SEBREAL_RGREAL_DV,'
      '    RESREAL_RGREAL_DV,'
      '    KOL_RGREAL_DV,'
      '    KOLOTR_RGREAL_DV,'
      '    OPER_RGREAL_DV'
      ')'
      'VALUES('
      '    :ID_RGREAL_DV,'
      '    :POSDOC_RGREAL_DV,'
      '    :IDDOC_RGREAL_DV,'
      '    :TDV_RGREAL_DV,'
      '    :IDFIRM_RGREAL_DV,'
      '    :IDSKLAD_RGREAL_DV,'
      '    :IDNOM_RGREAL_DV,'
      '    :SUMREAL_RGREAL_DV,'
      '    :SEBREAL_RGREAL_DV,'
      '    :RESREAL_RGREAL_DV,'
      '    :KOL_RGREAL_DV,'
      '    :KOLOTR_RGREAL_DV,'
      '    :OPER_RGREAL_DV'
      ')')
    RefreshSQL.Strings = (
      'select * '
      'from '
      '  RGREAL_DV'
      'where( '
      ' IDDOC_RGREAL_DV=:PARAM_IDDOC'
      '     ) and (     RGREAL_DV.ID_RGREAL_DV = :OLD_ID_RGREAL_DV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * '
      'from '
      '  RGREAL_DV'
      'where'
      ' IDDOC_RGREAL_DV=:PARAM_IDDOC')
    AutoUpdateOptions.UpdateTableName = 'RGREAL_DV'
    AutoUpdateOptions.KeyFields = 'ID_RGREAL_DV'
    AutoUpdateOptions.GeneratorName = 'GEN_RGREAL_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 48
    Top = 72
    object DvRegOstPOSDOC_RGREAL_DV: TFIBDateTimeField
      FieldName = 'POSDOC_RGREAL_DV'
    end
    object DvRegOstTDV_RGREAL_DV: TFIBSmallIntField
      FieldName = 'TDV_RGREAL_DV'
    end
    object DvRegOstSUMREAL_RGREAL_DV: TFIBBCDField
      FieldName = 'SUMREAL_RGREAL_DV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstSEBREAL_RGREAL_DV: TFIBBCDField
      FieldName = 'SEBREAL_RGREAL_DV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstRESREAL_RGREAL_DV: TFIBBCDField
      FieldName = 'RESREAL_RGREAL_DV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstKOL_RGREAL_DV: TFIBBCDField
      FieldName = 'KOL_RGREAL_DV'
      Size = 3
      RoundByScale = True
    end
    object DvRegOstKOLOTR_RGREAL_DV: TFIBBCDField
      FieldName = 'KOLOTR_RGREAL_DV'
      Size = 3
      RoundByScale = True
    end
    object DvRegOstOPER_RGREAL_DV: TFIBIntegerField
      FieldName = 'OPER_RGREAL_DV'
    end
    object DvRegOstID_RGREAL_DV: TFIBBCDField
      FieldName = 'ID_RGREAL_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOC_RGREAL_DV: TFIBBCDField
      FieldName = 'IDDOC_RGREAL_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDFIRM_RGREAL_DV: TFIBBCDField
      FieldName = 'IDFIRM_RGREAL_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDSKLAD_RGREAL_DV: TFIBBCDField
      FieldName = 'IDSKLAD_RGREAL_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDNOM_RGREAL_DV: TFIBBCDField
      FieldName = 'IDNOM_RGREAL_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDPART_RGREAL_DV: TFIBBCDField
      FieldName = 'IDPART_RGREAL_DV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDPOK_RGREAL_DV: TFIBBCDField
      FieldName = 'IDPOK_RGREAL_DV'
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
    Left = 136
    Top = 72
  end
end
