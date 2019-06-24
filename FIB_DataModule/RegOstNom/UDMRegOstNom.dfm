object DMRegOstNom: TDMRegOstNom
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 240
  Width = 243
  object DvRegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGOSTNOM_DV'
      'SET '
      '    POSDOC_OSTNOMDV = :POSDOC_OSTNOMDV,'
      '    IDDOC_OSTNOMDV = :IDDOC_OSTNOMDV,'
      '    IDFIRM_OSTNOMDV = :IDFIRM_OSTNOMDV,'
      '    IDSKL_OSTNOMDV = :IDSKL_OSTNOMDV,'
      '    IDNOM_OSTNOMDV = :IDNOM_OSTNOMDV,'
      '    IDPART_OSTNOMDV = :IDPART_OSTNOMDV,'
      '    TDV_OSTNOMDV = :TDV_OSTNOMDV,'
      '    SUM_OSTNOMDV = :SUM_OSTNOMDV,'
      '    KOL_OSTNOMDV = :KOL_OSTNOMDV,'
      '    IDSTRDOC_OSTNOMDV = :IDSTRDOC_OSTNOMDV,'
      '    OPER_OSTNOMDV = :OPER_OSTNOMDV,'
      '    SUM2_OSTNOMDV = :SUM2_OSTNOMDV'
      'WHERE'
      '    ID_OSTNOMDV = :OLD_ID_OSTNOMDV'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGOSTNOM_DV'
      'WHERE'
      '        ID_OSTNOMDV = :OLD_ID_OSTNOMDV'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGOSTNOM_DV('
      '    ID_OSTNOMDV,'
      '    POSDOC_OSTNOMDV,'
      '    IDDOC_OSTNOMDV,'
      '    IDFIRM_OSTNOMDV,'
      '    IDSKL_OSTNOMDV,'
      '    IDNOM_OSTNOMDV,'
      '    IDPART_OSTNOMDV,'
      '    TDV_OSTNOMDV,'
      '    SUM_OSTNOMDV,'
      '    KOL_OSTNOMDV,'
      '    IDSTRDOC_OSTNOMDV,'
      '    OPER_OSTNOMDV,'
      '    SUM2_OSTNOMDV'
      ')'
      'VALUES('
      '    :ID_OSTNOMDV,'
      '    :POSDOC_OSTNOMDV,'
      '    :IDDOC_OSTNOMDV,'
      '    :IDFIRM_OSTNOMDV,'
      '    :IDSKL_OSTNOMDV,'
      '    :IDNOM_OSTNOMDV,'
      '    :IDPART_OSTNOMDV,'
      '    :TDV_OSTNOMDV,'
      '    :SUM_OSTNOMDV,'
      '    :KOL_OSTNOMDV,'
      '    :IDSTRDOC_OSTNOMDV,'
      '    :OPER_OSTNOMDV,'
      '    :SUM2_OSTNOMDV'
      ')')
    RefreshSQL.Strings = (
      'select * from  RGOSTNOM_DV'
      'where(  IDDOC_OSTNOMDV=:IDDOC'
      '     ) and (     RGOSTNOM_DV.ID_OSTNOMDV = :OLD_ID_OSTNOMDV'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from  RGOSTNOM_DV'
      'where IDDOC_OSTNOMDV=:IDDOC')
    AutoUpdateOptions.UpdateTableName = 'RGOSTNOM_DV'
    AutoUpdateOptions.KeyFields = 'ID_OSTNOMDV'
    AutoUpdateOptions.GeneratorName = 'GEN_RGOSTNOM_DV_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 32
    Top = 16
    object DvRegOstPOSDOC_OSTNOMDV: TFIBDateTimeField
      FieldName = 'POSDOC_OSTNOMDV'
    end
    object DvRegOstTDV_OSTNOMDV: TFIBSmallIntField
      FieldName = 'TDV_OSTNOMDV'
    end
    object DvRegOstSUM_OSTNOMDV: TFIBBCDField
      FieldName = 'SUM_OSTNOMDV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstKOL_OSTNOMDV: TFIBBCDField
      FieldName = 'KOL_OSTNOMDV'
      Size = 3
      RoundByScale = True
    end
    object DvRegOstOPER_OSTNOMDV: TFIBIntegerField
      FieldName = 'OPER_OSTNOMDV'
    end
    object DvRegOstSUM2_OSTNOMDV: TFIBBCDField
      FieldName = 'SUM2_OSTNOMDV'
      Size = 2
      RoundByScale = True
    end
    object DvRegOstID_OSTNOMDV: TFIBBCDField
      FieldName = 'ID_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDDOC_OSTNOMDV: TFIBBCDField
      FieldName = 'IDDOC_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDFIRM_OSTNOMDV: TFIBBCDField
      FieldName = 'IDFIRM_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDSKL_OSTNOMDV: TFIBBCDField
      FieldName = 'IDSKL_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDNOM_OSTNOMDV: TFIBBCDField
      FieldName = 'IDNOM_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDPART_OSTNOMDV: TFIBBCDField
      FieldName = 'IDPART_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
    object DvRegOstIDSTRDOC_OSTNOMDV: TFIBBCDField
      FieldName = 'IDSTRDOC_OSTNOMDV'
      Size = 0
      RoundByScale = True
    end
  end
  object RegOst: TpFIBDataSet
    UpdateSQL.Strings = (
      'UPDATE RGOSTNOM'
      'SET '
      '    IDFIRMOSTNOM = :IDFIRMOSTNOM,'
      '    IDSKLOSTNOM = :IDSKLOSTNOM,'
      '    IDNOMOSTNOM = :IDNOMOSTNOM,'
      '    IDPARTOSTNOM = :IDPARTOSTNOM,'
      '    SUMOSTNOM = :SUMOSTNOM,'
      '    KOLOSTNOM = :KOLOSTNOM'
      'WHERE'
      '    IDOSTNOM = :OLD_IDOSTNOM'
      '    ')
    DeleteSQL.Strings = (
      'DELETE FROM'
      '    RGOSTNOM'
      'WHERE'
      '        IDOSTNOM = :OLD_IDOSTNOM'
      '    ')
    InsertSQL.Strings = (
      'INSERT INTO RGOSTNOM('
      '    IDOSTNOM,'
      '    IDFIRMOSTNOM,'
      '    IDSKLOSTNOM,'
      '    IDNOMOSTNOM,'
      '    IDPARTOSTNOM,'
      '    SUMOSTNOM,'
      '    KOLOSTNOM'
      ')'
      'VALUES('
      '    :IDOSTNOM,'
      '    :IDFIRMOSTNOM,'
      '    :IDSKLOSTNOM,'
      '    :IDNOMOSTNOM,'
      '    :IDPARTOSTNOM,'
      '    :SUMOSTNOM,'
      '    :KOLOSTNOM'
      ')')
    RefreshSQL.Strings = (
      'select * from RGOSTNOM'
      'where( '
      'IDFIRMOSTNOM=:IDFIRM  and'
      'IDSKLOSTNOM=:IDSKL  and'
      'IDNOMOSTNOM=:IDNOM and'
      'IDPARTOSTNOM=:IDPART'
      '     ) and (     RGOSTNOM.IDOSTNOM = :OLD_IDOSTNOM'
      '     )'
      '    ')
    SelectSQL.Strings = (
      'select * from RGOSTNOM'
      'where'
      'IDFIRMOSTNOM=:IDFIRM  and'
      'IDSKLOSTNOM=:IDSKL  and'
      'IDNOMOSTNOM=:IDNOM and'
      'IDPARTOSTNOM=:IDPART')
    AutoUpdateOptions.UpdateTableName = 'RGOSTNOM'
    AutoUpdateOptions.KeyFields = 'IDOSTNOM'
    AutoUpdateOptions.GeneratorName = 'GEN_RGOSTNOM_ID'
    AutoUpdateOptions.WhenGetGenID = wgOnNewRecord
    Transaction = IBTrUpdate
    Left = 32
    Top = 72
    object RegOstSUMOSTNOM: TFIBBCDField
      FieldName = 'SUMOSTNOM'
      Size = 2
      RoundByScale = True
    end
    object RegOstKOLOSTNOM: TFIBBCDField
      FieldName = 'KOLOSTNOM'
      Size = 3
      RoundByScale = True
    end
    object RegOstIDOSTNOM: TFIBBCDField
      FieldName = 'IDOSTNOM'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDFIRMOSTNOM: TFIBBCDField
      FieldName = 'IDFIRMOSTNOM'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDSKLOSTNOM: TFIBBCDField
      FieldName = 'IDSKLOSTNOM'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDNOMOSTNOM: TFIBBCDField
      FieldName = 'IDNOMOSTNOM'
      Size = 0
      RoundByScale = True
    end
    object RegOstIDPARTOSTNOM: TFIBBCDField
      FieldName = 'IDPARTOSTNOM'
      Size = 0
      RoundByScale = True
    end
  end
  object DvNom: TpFIBDataSet
    SelectSQL.Strings = (
      'select SUM(KOL_OSTNOMDV) AS KOLDV, SUM(SUM_OSTNOMDV) AS SUMDV'
      'from RGOSTNOM_DV'
      ' where '
      'POSDOC_OSTNOMDV > :PARAM_POS and'
      'IDNOM_OSTNOMDV=:PARAM_IDNOM  and'
      'IDSKL_OSTNOMDV=:PARAM_IDSKLAD  and'
      'IDFIRM_OSTNOMDV=:PARAM_IDFIRM  and'
      'TDV_OSTNOMDV = :PARAM_TDV'
      'group by IDNOM_OSTNOMDV')
    Transaction = IBTr
    Left = 32
    Top = 120
    object DvNomKOLDV: TFIBBCDField
      FieldName = 'KOLDV'
      Size = 3
      RoundByScale = True
    end
    object DvNomSUMDV: TFIBBCDField
      FieldName = 'SUMDV'
      Size = 2
      RoundByScale = True
    end
  end
  object Ostatok: TpFIBDataSet
    SelectSQL.Strings = (
      'select SUM(KOLOSTNOM) AS KOLOST, SUM(SUMOSTNOM) AS SUMOST'
      'from RGOSTNOM'
      ' where IDNOMOSTNOM=:PARAM_IDNOM  and'
      'IDSKLOSTNOM=:PARAM_IDSKLAD and'
      'IDFIRMOSTNOM=:PARAM_IDFIRM'
      'group by IDNOMOSTNOM')
    Transaction = IBTr
    Left = 32
    Top = 176
    object OstatokKOLOST: TFIBBCDField
      FieldName = 'KOLOST'
      Size = 3
      RoundByScale = True
    end
    object OstatokSUMOST: TFIBBCDField
      FieldName = 'SUMOST'
      Size = 2
      RoundByScale = True
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
    Left = 160
    Top = 24
  end
  object IBTrUpdate: TpFIBTransaction
    TimeoutAction = TARollback
    TRParams.Strings = (
      'write'
      'nowait'
      'read_committed'
      'rec_version')
    TPBMode = tpbDefault
    Left = 160
    Top = 88
  end
end
